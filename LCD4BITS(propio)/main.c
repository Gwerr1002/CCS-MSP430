#include "LCDMODE4BITS.h"

/*
 * MODO DE 4 BIT
 *
 * D7 P1.7
 * D6 P1.6
 * D5 P1.5
 * D4 P1.4
 *
 * EN P2.0
 * RS P2.2
 *
 */

void main(void)
{
    P1OUT = 0; P2OUT = 0;
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    DCOCTL = 0;
    BCSCTL1 = CALBC1_1MHZ;
    DCOCTL = CALDCO_1MHZ;

    P1DIR |= (D4 + D5 + D6 + D7);
    P2DIR |= (EN + RS);

    functionset();
    LCD_ON();
    //LCDON_BLINKOFF();

    unsigned char s[15];
    s[0]='c';
    s[1]= 0;
    WRITE(s);

}
