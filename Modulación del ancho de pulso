#include <msp430g2553.h>

#define T 1000 //PERIODO EN TERMINOS DE CICLOS DEL CPU
#define LED_R BIT6

void pwm(unsigned long duty_cycle);
void delay(unsigned long ciclos);

void main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	if (CALBC1_1MHZ == 0xFF){
	    while(1);
	}
	DCOCTL = 0;
	BCSCTL1 = CALBC1_1MHZ;
	DCOCTL = CALDCO_1MHZ;

	P1DIR |= LED_R;

	while(1){
	    pwm(500);
	}


}

void pwm(unsigned long duty_cycle){
    P1OUT |= LED_R;
    __delay_cycles(1136);
    //delay(duty_cycle);
    P1OUT &= ~LED_R;
    //delay(T - duty_cycle);
    __delay_cycles(1136);
}

void delay(unsigned long ciclos){
    volatile unsigned long i;
    for(i=ciclos;i>0;i--) __delay_cycles(1);
}
