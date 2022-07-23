#include <msp430g2553.h>


#define RED BIT1
#define BLUE BIT5
#define GREEN BIT3
#define BTN   BIT3

volatile unsigned char j=1;

void main(void)
{

    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    if (CALBC1_1MHZ == 0xFF){ //PARA REVISAR QUE NO HAY DAÑOS EN EL REGISTRO, NO HAYA UNOS
        while(1);//PODEMOS PONER UN BLINK MEJOR
    }
    //CONFIGURACION DEL RELOJ PARA EL PWM
    DCOCTL = 0;
    BCSCTL1 = CALBC1_1MHZ; //control del modulo básico de reloj 1,2,3.
    DCOCTL = CALDCO_1MHZ;

    P1OUT = 0; P2OUT=0;

    P2DIR |= (RED | BLUE | GREEN);

    //Habilitamos la resistencia interna en pull-up:
    P1REN |= BTN;
    P1OUT |= BTN;

    //CONFIGURACION DE INTERRUPCIONES:
    P1IE |= (BTN);
    P1IES &= ~BTN; //FLANCO DE SUBIDA

    P1IFG &= ~BTN; //LIMPIAR BANDERA

    __bis_SR_register(GIE);
    while(1)
    {
        switch (j){
                    case 1:
                        P2OUT |= (BLUE);
                        __delay_cycles(100000);
                        P2OUT &= ~BLUE;
                        __delay_cycles(400000);
                        break;
                    case 2:
                        P2OUT |= (RED | BLUE);
                        __delay_cycles(800000);
                        P2OUT &= ~(RED| BLUE);
                        __delay_cycles(3200000);
                        break;
                    case 3:
                        P2OUT |= (BLUE | GREEN);
                        __delay_cycles(1200000);
                        P2OUT &= ~(BLUE | GREEN);
                        __delay_cycles(4800000);
                        break;
                    case 4:
                        P2OUT |= (BLUE | RED | GREEN);
                        __delay_cycles(1600000);
                        P2OUT &= ~(RED| BLUE | GREEN);
                        __delay_cycles(6400000);
                        break;
                    default:
                        j=0;
                        P1IFG |= BTN; //ACTIVA DENTRO DEL PROGRAMA EL FALNCO DE SUBIDA DE LA BANDERA
                        break;
        }
    }
}


#pragma vector = PORT1_VECTOR
__interrupt void ISRP1(void)
{
    j++;
    switch (j){
    case 1:
        DCOCTL = 0;
        BCSCTL1 = CALBC1_1MHZ; //control del modulo básico de reloj 1,2,3.
        DCOCTL = CALDCO_1MHZ;
        break;
    case 2:
        DCOCTL = 0;
        BCSCTL1 = CALBC1_8MHZ; //control del modulo básico de reloj 1,2,3.
        DCOCTL = CALDCO_8MHZ;
        break;
    case 3:
        DCOCTL = 0;
        BCSCTL1 = CALBC1_12MHZ; //control del modulo básico de reloj 1,2,3.
        DCOCTL = CALDCO_12MHZ;
        break;
    case 4:
        DCOCTL = 0;
        BCSCTL1 = CALBC1_16MHZ; //control del modulo básico de reloj 1,2,3.
        DCOCTL = CALDCO_16MHZ;
        break;
    }
    P1IFG &= ~BTN;
}
