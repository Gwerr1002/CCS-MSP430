#include <msp430g2553.h>

#define LED_R BIT6
#define LED_V BIT0
#define BTN BIT3
#define GREEN BIT3
#define RED BIT1
#define BLUE BIT5

void ciclo(volatile unsigned COLOR)
{
    //ESPERA QUE SE PRESIONE BTN
            while((P1IN & BTN ) == BTN);
            while((P1IN & BTN ) != BTN);
            P1OUT &= ~(LED_R);
            P1OUT |= LED_V;
            while((P1IN & BTN ) == BTN);
            while((P1IN & BTN ) != BTN);
            P1OUT ^= LED_V;
            P2OUT |= COLOR;
            while((P1IN & BTN ) == BTN);
            while((P1IN & BTN ) != BTN);
            P2OUT ^= COLOR;
            P1OUT |= LED_R;
        }

void main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	P1OUT = 0; P2OUT = 0;
	P1DIR |= LED_R + LED_V;
	P2DIR |= GREEN + BLUE + RED;

	//HABILITAR RESISTENCIA PULLUP/PULLDOWN
	P1REN |= BTN;
	//CONFIGURADO EN MODO PULLUP
	P1OUT = BTN;
	while(1){
	    ciclo(RED | GREEN);
	    ciclo(BLUE | GREEN);
	    ciclo(BLUE | RED);
	    ciclo(BLUE | RED | GREEN);
	}


}
