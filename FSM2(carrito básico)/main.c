#include <msp430g2553.h>

#define izquierda BIT0
#define derecha   BIT6
#define avanza    BIT5
#define S1        BIT1
#define S2        BIT3

/*                           ESTADO      S1    S2
 * A (avanzar frente)          00         0    0
 * B (girar izquierda)         01         1    0
 * C (girar derecha)           10         1    1
 *                                        0    1
 */

#define avanza_frente 0b00000000
#define gira_izq      0b00000100
#define gira_der      0b00001000

typedef char estado;
estado estado_actual;

estado fsm(estado byte_control);

void main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
    P1OUT = 0; P2OUT= 0;
    P1DIR |= izquierda | derecha;
    P2DIR |= avanza;

    P1REN |= S1 + S2;
    P1OUT |= (S1 + S2);

    //ESTADO INICIAL DE LA MÁQUINA DE ESTADOS
    estado_actual = avanza_frente;

    while(1)
    {
        estado_actual |= (~P1IN & S1);
        estado_actual |= (P1IN & S2)>>3;
        estado_actual = fsm(estado_actual);
    }
}

estado fsm(estado byte_control)
{
    switch(byte_control)
    {
    case 0b00000000: //AVANZA FRENTE Y SENSORES 00
    case 0b00000001:
    case 0b00000100:
    case 0b00000101:
    case 0b00001000:
    case 0b00001001:
        //ACCIONES DE LA FUNCION DE TRANSICION
        P2OUT |= avanza;
        P1OUT &= ~(izquierda | derecha);
        //ACTUALIZACION DEL ESTADO:
        byte_control = avanza_frente;
        break;

    case 0b00000110:
    case 0b00000111:
    case 0b00000011:
        P1OUT |= izquierda;
        P2OUT &= ~avanza;
        P1OUT &= ~derecha;
        byte_control = gira_izq;
        break;

    case 0b00000010:
    case 0b00001011:
    case 0b00001010:
        P1OUT &= ~izquierda;
        P2OUT &= ~avanza;
        P1OUT |= derecha;
        byte_control = gira_der;
        break;

    default:
        break;
    }
    return byte_control;
}
