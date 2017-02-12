#include <msp430.h>

#define LED_RED BIT0
#define LED_GREEN BIT7
#define BUTTON BIT1 //((1<<1)|(1<<2))

void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   		 // Stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;     			  // Disable the GPIO power-on default high-impedance mode
                                      	// to activate previously configured port settings

    //LED
    P1DIR |= LED_RED;    				 // Set to output direction
    P9DIR |= LED_GREEN,
    P1OUT = LED_RED;
    P9OUT  &= ~LED_GREEN;

    //BUTTON
    P1REN |= BUTTON;    			 //Enables a puller-Resistor on the button-pin
    P1OUT |= BUTTON;    			 //Writes a "1" to the portpin, telling the resistor to pullup

    P1IE |= BUTTON;   				 //Interrupt Enabled --> Enables the selector-mask for generating interrupts on the relevant pin
    P1IES |= BUTTON;    			 //Triggers when you PRESS the button :: Pick one...
   		 //P1IES &= ~BUTTON;   	 // Triggers when you RELEASE the button :: ...or pick the other

    P1IFG &= ~BUTTON;   			 //Interrupt Flag --> clear it

    __enable_interrupt(); // Interrupts get enabled *here* - they were disabled thus far..

    volatile int i;
    for(;;) {
   	 P9OUT ^= LED_GREEN;
   	 P1OUT ^= LED_RED;
   	 for(i = 0; i < 10000;++i);
    }
}

// Port 1 interrupt service routine
#pragma vector=PORT1_VECTOR
__interrupt void port1_isr(void)
{
    //remove bouncing (prellen): = debounce TODO


    volatile int i, j;
    P1IFG &= ~BUTTON; // P1.3 IFG cleared

    P9OUT = 0;
    P1OUT = (LED_RED | BUTTON); // Clear the LEDs so they start in OFF state do not forget also set to interrupt otherwise it is disabled

    for(j = 0; j < 10;++j){
   	 P1OUT ^= (LED_RED);
   	 for(i = 0; i < 10000;++i);
    }
}
