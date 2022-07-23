#include <msp430g2553.h>

#define izquierda BIT0
#define derecha   BIT6
#define avanza    BIT5
#define S1        BIT1
#define S2        BIT3

typedef enum{avanza_frente, gira_izq, gira_der} estado; //TIPO ENUMERATIVO: ETIQUETA
//              EDO0          EDO1      EDO2
estado estado_actual;

void fsm(char libre, char posObs);

void main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	P1OUT = 0; P2OUT= 0;
	P1DIR |= izquierda | derecha;
	P2DIR |= avanza;

	P1REN |= (S1 + S2);
	P1OUT |= (S1 + S2);

	estado_actual = avanza_frente;

	while(1){

	    fsm((P1IN & S1),(P1IN & S2));
	    switch(estado_actual)
	    {
	    case avanza_frente:
	        P2OUT |= avanza;
	        P1OUT &= ~(izquierda | derecha);
	        break;

	    case gira_izq:
	        P1OUT |= izquierda;
	        P2OUT &= ~avanza;
	        P1OUT &= ~derecha;
	        break;

	    case gira_der:
            P1OUT &= ~izquierda;
            P2OUT &= ~avanza;
            P1OUT |= derecha;
	        break;

	    default:

	        break;
	    }
	}

}

void fsm(char libre, char posObs)
{
    switch(estado_actual)
    {
    case avanza_frente:
        if(!libre)
            if(posObs) estado_actual = gira_izq;
            else estado_actual = gira_der;
        break;
    case gira_izq:
    case gira_der:
        if(libre) estado_actual = avanza_frente;
        break;
    default:

        break;
    }

}
