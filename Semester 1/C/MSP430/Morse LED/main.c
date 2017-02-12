#include <msp430.h> 

/*
 * main.c
 */
static void init(void);
static void startMsTimer();
static void stopMsTimer();

typedef enum {Error, Dit, Dah} Symbol; // TODO pause symbol
static Symbol getSymbolFromMilliSeconds();

#define DIT_LENGTH_MS 60
#define DAH_LENGTH_MS 3*DIT_LENGTH_MS
#define BUTTON BIT1
#define LED_RED BIT0
#define LED_GREEN BIT7

static int secondsPassed = 0;
static long milliSecondsPassed = 0;
static int symbolsIndex = 0;
static Symbol exercise[] = {Dit, Dah, Dit, Dit, Dah, Dit, Dit, Dit, Dah, Dit, Dit}; // = AFFE

int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;

    init();

    while(1){
    		// everything will work with interrupts
    }
}

void init(void){
	// enable interrupt on P1.1
	P1IE |= BUTTON; // enable interrupt
	P1IES |= BUTTON; // interrupt edge select (falling edge)
	P1IFG &= ~BUTTON; // reset interrupt flag
	_enable_interrupts();

	// set pullup-resistor P1.1
	P1REN |= BUTTON;
	P1OUT |= BUTTON;

	// turn red LED off
	P1DIR |= LED_RED;
	P1OUT &= ~LED_RED;

	// turn green LED off
	P9DIR |= LED_GREEN;
	P9OUT &= ~LED_GREEN;

	// timer count every second
	TA0CCR0 = 10^6 / 8 / 5; // 1MHz and two /8 divider -> 1s
	TA0CCTL0 = CCIE;
	TA0CTL = TASSEL_2 | ID_3 | MC_1 | TACLR;
	TA0EX0 = TAIDEX_4;
}

#pragma vector = PORT1_VECTOR
__interrupt void port1_isr(){
	P1IFG &= ~BUTTON; // reset interrupt flag

	// toggle red LED and interrupt edge select
	P1OUT ^= LED_RED;
	P1IES ^= BUTTON;

	// start timer if button pressed, stop if released
	if(P1OUT&LED_RED){
		startMsTimer();
	} else {
		stopMsTimer();
		if(exercise[symbolsIndex] == getSymbolFromMilliSeconds()){
			// green LED
			symbolsIndex++;
			P9OUT |= LED_GREEN;
		} else {
			symbolsIndex = 0;
			P9OUT &= ~LED_GREEN;
		}
	}

	// clear pause timer
	secondsPassed = 0;
	P9OUT &= ~LED_GREEN;
}

#pragma vector = TIMER0_A0_VECTOR
__interrupt void timerA0_isr(){
	secondsPassed++;
	if(secondsPassed >= 10){
		symbolsIndex = 0;
		P9OUT ^= LED_GREEN;
	}
}

#pragma vector = TIMER0_A1_VECTOR
__interrupt void timerA1_isr(){
	milliSecondsPassed++;
}

static void startMsTimer(){
	// timer count every second
	milliSecondsPassed = 0;
	TA1CCR0 = 10^3; // 1kHz -> 1ms
	TA1CCTL0 = CCIE;
	TA1CTL = TASSEL_2 | ID_0 | MC_1 | TACLR;
}

static void stopMsTimer(){
	TA1CTL = MC_1;
}

static Symbol getSymbolFromMilliSeconds(){
	int dits = milliSecondsPassed/(double)DIT_LENGTH_MS;
	int dahs = milliSecondsPassed/(double)DAH_LENGTH_MS;

	if(dits >= 0.9 && dits <= 1.1){
		return Dit;
	} else if (dahs >= 0.9 && dahs <= 1.1) {
		return Dah;
	} else {
		return Error;
	}
}
