#include <msp430g2553.h>

#define RED BIT1
#define BLUE BIT5
#define GREEN BIT3
#define LED_V BIT0

#define T 20000 //PERIODO
#define fCycle 18000/100 //CICLO DE TRABAJO SOBRE 100
#define frest T*.1 //10% DEL CICLO DE TRABAJO
volatile unsigned char R = 75, G = 23, B = 2;
volatile unsigned char edo=1;

void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

    if(CALBC1_1MHZ == 0xFF | CALBC1_8MHZ == 0xFF | CALBC1_12MHZ == 0xFF | CALBC1_16MHZ == 0xFF)while(1);

    DCOCTL = 0;
    BCSCTL1 = CALBC1_1MHZ;
    DCOCTL = CALDCO_1MHZ;

    P1OUT = 0; P2OUT = 0;
    P2DIR = RED + BLUE + GREEN;
    P1DIR = LED_V;

    //CONFIGURACION DE INTERRUPCION DEL TIMMER 1
    //HABILITAR INTERRUPCION
    TA1CCTL0 |= CCIE; //CAPTURE INTERRUPT ENABLE
    //SELECCIONAR MODO DE CONTEO Y FUENTE DE RELOJ:
    TA1CTL |= TASSEL_2 + MC_1;
    __bis_SR_register(GIE);
    if(edo == 1){
       TA1CCR0 = R*fCycle;
       P2OUT |= RED;
    }

    while(1){
        P1OUT ^= LED_V;
    }


}
#pragma vector = TIMER1_A0_VECTOR
__interrupt void timerA1(void)
{
    switch(edo){
    case 1:
        TA1CCR0 = R*fCycle;
        P2OUT |= RED;
        edo++;
        break;
    case 2:
        P2OUT &= ~RED;
        P2OUT |= GREEN;
        TA1CCR0 = G*fCycle;
        edo++;
        break;
    case 3:
        P2OUT &= ~GREEN;
        P2OUT |= BLUE;
        TA1CCR0 = B*fCycle;
        edo++;
        break;
    case 4:
        P2OUT &= ~BLUE;
        TA1CCR0 = frest;
        edo = 1;
        break;
    }
}

