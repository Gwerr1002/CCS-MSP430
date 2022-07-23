#include <msp430g2553.h>

#define BTN BIT3
#define BTN_E BIT1
#define LED_V BIT0
#define LED_R BIT6

volatile short press=0;
void main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	P1OUT = 0;  P2OUT = 0;
	P1DIR |= LED_V | LED_R;

	//HABILITAMOS EL BOTON BTN
	P1IE |= BTN | BTN_E; //IE INTERRUPT ENABLE

	// CONFIGURACION FLANCO DE SUBIDA
	P1IES &= ~(BTN | BTN_E);

	//CONFIGUTACION DEL FLANCO DE BAJADA
	//P1IES |= BTN;

	//RESISTENCIA PULL UP
	P1REN |= BTN | BTN_E;
	P1OUT |= BTN | BTN_E;

	//LIMPIAR LA BANDERA DE INTERRUPCION
	P1IFG &= ~(BTN | BTN_E);

	//GIE GLOBAL INTERRUPT ENABLE

	//BIT "SET" (BIS) SR (STATUS REGISTER)
	//__bis_SR_register(GIE); //EL QUE ACTIVA LA ENTRADA DE LA INTERRUPCION

	__bis_SR_register(LPM4_bits + GIE); //MODO DE BAJO CONSUMO (MENOR CONSUMO), YA NO EJECUTA LA LINEA 38

	//POLLING
	/*
	while(1){
	    while((P1IN && BTN) == BTN);
	    while((P1IN && BTN) == !BTN);
	    P1OUT ^= LED_R;
	}
	*/


}

//ISR INTERRUPT SERVICE ROUTINE

#pragma vector = PORT1_VECTOR
__interrupt void isrp1(void) //no devuelve nada
{
  /*  switch(P1IFG){

    case BTN_E:
        P1OUT |= LED_V;
        P1OUT &= ~LED_R;
        break;

    case BTN:
        P1OUT &= ~LED_V;
        P1OUT |= LED_R;

        break;

    }
     //LIMPIAR LA BANDERA
    P1IFG &= ~(BTN_E | BTN | LED_V | LED_R);
    */
    //__bic_SR_register_on_exit(LPM4_bits); //DESACTIVAR EL MODO DE BAJO CONSUMO

    if((P1IFG & BTN) == BTN){
        P1OUT &= ~LED_R;
        P1OUT |= LED_V;
        P1IFG &= ~(BTN);
    }

    if((P1IFG & BTN_E) == BTN_E){
        P1OUT &= ~LED_V;
        P1OUT |= LED_R;
        P1IFG &= ~(BTN_E);
    }

}
