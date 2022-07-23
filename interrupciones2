#include <msp430g2553.h>


#define LED_V BIT0
#define LED_R BIT6
#define BTN   BIT3


void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer


    volatile unsigned int i, j, k;


    P1OUT = 0;


    P1DIR |= BIT0 + BIT6;


    //Habilitamos la resistencia interna en pull-up:
    P1REN |= BTN;
    P1OUT |= BTN;




    //CONFIGURACION DE INTERRUPCIONES:
    P1IE |= BTN;
    P1IES |= BTN;


    P1IFG = 0;


    __bis_SR_register(GIE);
    while(1){
    while((P1IN & BTN) == BTN)
    {
        P1OUT &= ~LED_R;
        P1OUT ^= LED_V;
        __delay_cycles(100000);
    }
    }
}


#pragma vector = PORT1_VECTOR
__interrupt void ISRP1(void)
{
    P1OUT &= ~LED_V;
    P1IES ^= BTN;
    P1IFG &= ~BTN;
    P1OUT |= LED_R;
}
