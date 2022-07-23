#include "LCDMODE4BITS.h"
#include "UART.h"

unsigned char txt[33], termino = 0, x = 0;


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
    //LCD_ON();
    LCDON_BLINKOFF();

    initUART();
    __bis_SR_register(GIE+LPM0_bits);

}
#pragma vector = USCIAB0RX_VECTOR
__interrupt void USCIARX_ISR(void)
{

    if(termino == 0){
        while(!(IFG2 & UCA0TXIFG));
        txt[x] = UCA0RXBUF;
        if(txt[x] == 0){ termino = 1; }
        if(x<32)x++;
    }
    if(termino == 1){
        CLEAR();
        WRITE(txt);
        x = 0;
        while(txt[x] != 0){
            txt[x] = 0;
            x++;
        }
        x = 0; termino = 0;
    }
}
