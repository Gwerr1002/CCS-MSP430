#include <msp430g2553.h>

#define LED_R BIT6

volatile unsigned char i = 0;

void main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	P1OUT = 0; P2OUT = 0;

	DCOCTL = 0;
	BCSCTL1 = CALBC1_1MHZ;
	DCOCTL = CALDCO_1MHZ;

	BCSCTL3 |= LFXT1S_2;

	//CONFIGURAR COMO SALIDA DE TIMER
	P1DIR |= LED_R;
	P1SEL |= LED_R;


	//DEFINIMOS EL PERIODO DEL PWM: SE USA EL TIMMER A1
	TACCR0 = 1000;
	//DEFINIMOS EL CICLO DE TRABAJO
	//TACCR1 = TACCR0 >> 1; //CICLO DE TRABAJO AL 50%
    TACCR1 = 0;

	//MODO DE SALIDA DEL PWM (PATRÓN DE SALIDA)

	TACCTL1 |= OUTMOD_7;
	//SELECCIONAR FUENTE DE RELOJ Y MODO DE CONTEO (ASCENDENTE)
	TA0CTL |= TASSEL_2 + MC_1;

	//USANDO EL OTRO TIMMER:
	TA1CCR0 = 100;
	TA1CCTL0 |= CCIE;
	TA1CTL |= TASSEL_1 + MC_1;

	__bis_SR_register(LPM0_bits + GIE);

}

#pragma vector = TIMER1_A0_VECTOR
__interrupt void timerA1(void)
{
    if((TACCR1 < TACCR0) && (i == 0)) TA0CCR1 += 10;
    else i = 1;
    if((TACCR1 > 0) && (i ==1)) TA0CCR1 -= 10;
    else i=0;
}
