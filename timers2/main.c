
#include <msp430g2553.h>

#define LED_V BIT0
#define MHZ1 1000000
#define MHZ8 8000000
#define MHZ12 12000000
#define MHZ16 16000000

#define LED_FREQ 2//HZ

#define LED_CICLOS_1  (MHZ1/(2*LED_FREQ))
#define LED_CICLOS_8  (MHZ8/(2*LED_FREQ))
#define LED_CICLOS_12 (MHZ12/(2*LED_FREQ))
#define LED_CICLOS_16 (MHZ16/(2*LED_FREQ))

volatile unsigned char i=5;

void main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	if(CALBC1_1MHZ == 0xFF | CALBC1_8MHZ == 0xFF | CALBC1_12MHZ == 0xFF | CALBC1_16MHZ == 0xFF)while(1);

	DCOCTL = 0;
	BCSCTL1 = CALBC1_1MHZ;
	DCOCTL = CALDCO_1MHZ;

	P1OUT = 0; P2OUT = 0;
	P1DIR = LED_V;

	//CONFIGURACION DE INTERRUPCION DEL TIMMER
	TA1CCR0 = 50000;
	//HABILITAR INTERRUPCION
	TA1CCTL0 |= CCIE; //CAPTURE INTERRUPT ENABLE
	//SELECCIONAR MODO DE CONTEO Y FUENTE DE RELOJ:
	TA1CTL |= TASSEL_2 + MC_1;
	__bis_SR_register(GIE+LPM0_bits);

}
#pragma vector = TIMER1_A0_VECTOR
__interrupt void timerA1(void)
{
    i--;
    if(i == 1){
        P1OUT ^= LED_V;
        i=5;
    }
}


//CONTROL DEL REGISTRO VL0 (VERY LOW)

/*
#include <msp430g2553.h>

#define LED_V BIT0
#define MHZ1 1000000
#define MHZ8 8000000
#define MHZ12 12000000
#define MHZ16 16000000

#define LED_FREQ 2//HZ

#define LED_CICLOS_1  (MHZ1/(2*LED_FREQ))
#define LED_CICLOS_8  (MHZ8/(2*LED_FREQ))
#define LED_CICLOS_12 (MHZ12/(2*LED_FREQ))
#define LED_CICLOS_16 (MHZ16/(2*LED_FREQ))



void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

    if(CALBC1_1MHZ == 0xFF | CALBC1_8MHZ == 0xFF | CALBC1_12MHZ == 0xFF | CALBC1_16MHZ == 0xFF)while(1);

    DCOCTL = 0;
    BCSCTL1 = CALBC1_1MHZ;
    DCOCTL = CALDCO_1MHZ;

    BCSCTL3 = LFXT1S_2;//FUNCIONA A 12KHZ

    P1OUT = 0; P2OUT = 0;
    P1DIR = LED_V;

    //CONFIGURACION DE INTERRUPCION DEL TIMMER
    TA1CCR0 = 3000;
    //HABILITAR INTERRUPCION
    TA1CCTL0 |= CCIE; //CAPTURE INTERRUPT ENABLE
    //SELECCIONAR MODO DE CONTEO Y FUENTE DE RELOJ:
    TA1CTL |= TASSEL_1 + MC_1;
    __bis_SR_register(GIE+LPM0_bits);

}
#pragma vector = TIMER1_A0_VECTOR
__interrupt void timerA1(void)
{
    P1OUT ^= LED_V;

}
*/

//CONTROL DEL DIVISOR DE FRECUENCIA

/*
#include <msp430g2553.h>

#define LED_V BIT0
#define MHZ1 1000000
#define MHZ8 8000000
#define MHZ12 12000000
#define MHZ16 16000000

#define LED_FREQ 2//HZ

#define LED_CICLOS_1  (MHZ1/(2*LED_FREQ))
#define LED_CICLOS_8  (MHZ8/(2*LED_FREQ))
#define LED_CICLOS_12 (MHZ12/(2*LED_FREQ))
#define LED_CICLOS_16 (MHZ16/(2*LED_FREQ))



void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

    if(CALBC1_1MHZ == 0xFF | CALBC1_8MHZ == 0xFF | CALBC1_12MHZ == 0xFF | CALBC1_16MHZ == 0xFF)while(1);

    DCOCTL = 0;
    BCSCTL1 = CALBC1_1MHZ;
    DCOCTL = CALDCO_1MHZ;

    BCSCTL3 = LFXT1S_2;//FUNCIONA A 12KHZ

    P1OUT = 0; P2OUT = 0;
    P1DIR = LED_V;

    //CONFIGURACION DE INTERRUPCION DEL TIMMER
    TA1CCR0 = 0;
    //HABILITAR INTERRUPCION
    TA1CCTL0 |= CCIE; //CAPTURE INTERRUPT ENABLE
    //SELECCIONAR MODO DE CONTEO Y FUENTE DE RELOJ:
    TA1CTL |= TASSEL_1 + MC_1+ DIVA_1;
    __bis_SR_register(GIE+LPM0_bits);

}
#pragma vector = TIMER1_A0_VECTOR
__interrupt void timerA1(void)
{
    P1OUT ^= LED_V;

}
*/
