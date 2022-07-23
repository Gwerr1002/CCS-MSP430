#include <msp430g2553.h>

/**
 * LED.c
 */

//FUNCION QUE EJECUTA LOS 4 TIEMPOS, LA ENTRADA ES LA VARIBLE COLOR QUE INDICA QUE BITS DEBEN POSICIONARSE EN ALTO PARA ENCENDER EL RGB
void tiempos(volatile unsigned int COLOR){
    volatile unsigned i;
    //TIEMPO 1 RGB ENCENDIDO
    P2OUT |= COLOR;
    for(i=60000; i>0; i--);
    //TIEMPO 2 VERDE Y ROJO ENCENDIDO, RGB APAGADO
    P2OUT &= 0x00;
    P1OUT |= BIT0 | BIT6;
    for(i=60000; i>0; i--);
    //TIEMPO 3 TODOS ENCENDIDOS
    P2OUT |= COLOR;
    for(i=60000; i>0; i--);
    //TIEMPO 4 TODOS APAGADOS
    P2OUT &= 0x00;
    P1OUT &= 0x00;
    for(i=60000; i>0; i--);
}

void main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	P2DIR |= BIT1+BIT3+BIT5;
	P1DIR |= BIT0+BIT6;
	P1OUT &= 0x00;
	P2OUT &= 0x00;
	
	while(1)
	{
	    //AMARILLO: ENVIA A COLOR A ALTO EN BIT 1 Y 3
	    tiempos(BIT1 | BIT3);
	    //CIAN: ENVIA A COLOR A ALTO EN BIT 3 Y 5
	    tiempos(BIT3 | BIT5);
	    //MORADO: ENVIA A COLOR A ALTO EN BIT 1 Y 5
	    tiempos(BIT1 | BIT5);
	    //BLANCO: ENVIA A COLOR A ALTO EN BIT 1,3 Y 5
	    tiempos(BIT1 | BIT3 | BIT5);
	}
}
