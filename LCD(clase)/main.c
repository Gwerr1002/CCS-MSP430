#include "LCD16X2_4BTIS.h"

/*
 *
 * DISLPLAY LCD EN MODO DE 4 BITS
 * PINES 1,5,6 A GND JUNTO CON R/W
 * PIN15 CON RESISTENCIA DE 330
 *
 * MSP     LCD
 * P1.0    D4
 * P1.1    D5
 * P1.2    D6
 * P1.3    D7
 * P1.4    RS
 * P1.5    EN
 *
 */


void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

    if(CALBC1_1MHZ == 0xFF) while(1);

    //Configuración para que el MCLK trabaje a 1 MHz
    //Por default, el DCO ya está asignado al MCLK
    DCOCTL = 0;
    BCSCTL1 = CALBC1_1MHZ;
    DCOCTL = CALDCO_1MHZ;

    P1OUT = 0; P2OUT = 0;

    P1DIR |= D4 + D5 + D6 + D7 + RS + EN;

    init4bitmode();
    initLCD();

    writeLCD("HOLA MUNDO");
    positionLCD(3);
}
