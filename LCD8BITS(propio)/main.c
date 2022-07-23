#include "LCDMODE8BITS.h"

//MODO DE 8 BIT
/*
 * D0 P1.0
 * D1 P1.3
 * D2 P1.4
 * D3 P1.5
 * D4 P1.6
 * D5 P1.7
 * D6 P2.0
 * D7       AÑADIR SI SE CONFIGURA P2.7
 *
 * EN P2.4
 * RS P2.2
 */


void main(void)
{
    P1OUT = 0; P2OUT = 0;
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
    DCOCTL = 0;
    BCSCTL1 = CALBC1_1MHZ;
    DCOCTL = CALDCO_1MHZ;


    P1DIR |= (D0 + D1 + D2 + D3 + D4 + D5);
    P2DIR |= (D6| D7 | EN | RS);

    functionset();
    LCD_ON();
    CLEAR();
    P2OUT |= RS;
    WRITE('A');
    WRITE('L');
    WRITE('O');
    WRITE('H');
    WRITE('A');
    WRITE('1');
    WRITE('1');
    P2OUT &= ~RS;
}
