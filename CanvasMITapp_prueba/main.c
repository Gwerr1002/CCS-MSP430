#include "UART.h"
#include "LCDMODE4BITS.h"

unsigned char aux = 0;
unsigned int num;
void main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
    P1OUT = 0; P2OUT = 0;


    DCOCTL = 0;
    BCSCTL1 = CALBC1_1MHZ;
    DCOCTL = CALDCO_1MHZ;

    P1DIR |= (D4 + D5 + D6 + D7 + EN + RS);

    functionset();
    LCD_ON();

    initUART();
    __bis_SR_register(GIE + LPM0_bits);
    while(1)
    {
        if(aux == 1)
        {
            CLEAR();
            WRITE("HOLA");
            aux = 0;
        }
    }
}
#pragma vector = USCIAB0RX_VECTOR
__interrupt void USCIARX_ISR(void)
{

    while(!(IFG2 & UCA0TXIFG));
    num = UCA0RXBUF;
    aux = 1;
}
