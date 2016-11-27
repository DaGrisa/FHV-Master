#include <msp430.h>
/*---------------------------------
 * define components
 —----------------------------------*/
#define LED_RED BIT0  //P1.0
#define LED_GREEN BIT7  //P9.7
#define BUTTON_RED_LED BIT1    //P1.1
#define BUTTON_GREEN_LED BIT2    //P1.1

/*----------------------------------
 * define OUTPUT
 —----------------------------------*/
#define OUTPUT1 P1OUT    //define general Output for P1
#define OUTPUT1_DIRECTION P1DIR   //****

#define OUTPUT9 P9OUT
#define OUTPUT9_DIRECTION P9DIR
/*------------------------------------
 * define Buttons In and Flags
 —------------------------------------*/
#define BUTTON_RESISTOR_ENABLE P1REN  //Resistor for Button
#define BUTTON_INTERRUPT_ENABLE P1IE    //enables or disables interrupts for that pin
#define BUTTON_INTERRUPT_FLAG P1IFG  //Flag if interrupt is set (0,1)
#define BUTTON_INTERRUPT_EDGE_DIRECTION P1IES  //sets the direction of the interrupt edge
/*
 * Variables
 */
static int counter = 0;
static int buttonClicked = 0;

int main(void) {
	/*
	 * general
	 */
	WDTCTL = WDTPW | WDTHOLD;   // Stop watchdog timer

	/*
	 * Enable LED and apply settings
	 */
	OUTPUT1_DIRECTION |= LED_RED;      // set P1.0 as output(1) dir
	OUTPUT1 &= ~LED_RED;       // enable P1.0(Red Led)

	OUTPUT9_DIRECTION |= LED_GREEN;
	OUTPUT9 &= ~LED_GREEN;

	PM5CTL0 &= ~LOCKLPM5; // Disable the GPIO power-on default high-impedance mode to activate previously configured port settings

	/*
	 * Enable Button, set Flags, add Resistor
	 */
	OUTPUT1_DIRECTION &= ~(BUTTON_RED_LED + BUTTON_GREEN_LED);                     // button is an input
	OUTPUT1 |= (BUTTON_RED_LED + BUTTON_GREEN_LED);                         // pull-up resistor
	BUTTON_RESISTOR_ENABLE |= (BUTTON_RED_LED + BUTTON_GREEN_LED);                        // resistor enabled
	BUTTON_INTERRUPT_EDGE_DIRECTION |= (BUTTON_RED_LED + BUTTON_GREEN_LED); // interrupt on low-to-high transition
	BUTTON_INTERRUPT_ENABLE |= (BUTTON_RED_LED + BUTTON_GREEN_LED);                       // interrupt enable
	BUTTON_INTERRUPT_FLAG &= ~(BUTTON_RED_LED + BUTTON_GREEN_LED);            // set interrupt flag 0

	/*
	 * Lets get the Timer working
	 */
	TA0CCTL0 = CCIE;                        // TACCR0 interrupt enabled
	TA0CCR0 = 1000;            //16-Bit max. 65536 (1000 = 1ms@1MHz)
	TA0CTL = TASSEL__SMCLK | MC__CONTINUOUS; //Continous -> trigger interrupt every time, timer reaches defined number

	_enable_interrupt();

	for (;;) {

	}
}

#pragma vector = TIMER0_A0_VECTOR
__interrupt void timer_interrupt(void) {
	if (buttonClicked) {
		if (counter >= 3) {
			counter = 0;
			BUTTON_INTERRUPT_ENABLE |= (BUTTON_RED_LED + BUTTON_GREEN_LED);
			BUTTON_INTERRUPT_FLAG &= ~(BUTTON_RED_LED + BUTTON_GREEN_LED);
			buttonClicked = 0;
		} else {
			counter++;
		}
	}
}

// Port 1 interrupt service routine
#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void) {
	P1OUT ^= LED_RED; // P1.0 = toggle
	P9OUT ^= LED_GREEN;
	BUTTON_INTERRUPT_ENABLE &= ~(BUTTON_RED_LED + BUTTON_GREEN_LED);
	buttonClicked = 1;
	TA0CTL |= TACLR;
}
