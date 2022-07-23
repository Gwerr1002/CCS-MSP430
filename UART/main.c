/*
#include <msp430g2553.h>

void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    P1OUT = 0; P2OUT = 0;

    DCOCTL = 0;
    BCSCTL1 = CALBC1_1MHZ;
    DCOCTL = CALDCO_1MHZ;

    //P1.1 <- RXD, P1.2 <- TXD
    P1SEL |= BIT1 + BIT2;
    P1SEL2 |= BIT1 + BIT2;

    //Seleccionamos fuente de reloj EL SMCLK para la usci:
    UCA0CTL1 |= UCSSEL_2; //ES EL RELOJ SUBMAIN

    //BAUS RATE DE 9600 BAUDIOS
*/
    /*
     * tenemos 1000000 de ciclos por segundo
     * y queremos una velocidad de 9600
     * 1000000/9600 = 104.1666
     * 104 <- 0b01101000
     * ya que cabe en un byte solo se usara un registro
     * con los decimales hacemos un redondeo:
     * round(0.16 * 8) = round(1.28) = 1 <- modulacion 1
     */
/*
    UCA0BR0 = 104;
    UCA0BR1 = 0;

    //modulacionUCBRS:
    UCA0MCTL = UCBRS0;
    //INICIAR UNA MAQUINA DE ESTADOS DE LA USCI A
    UCA0CTL1 &= ~UCSWRST;
    IE2 |= UCA0RXIE;
    __bis_SR_register(LPM0_bits + GIE);

}

#pragma vector = USCIAB0RX_VECTOR
__interrupt void USCIARX_ISR(void)
{
    while(!(IFG2 & UCA0TXIFG)); //CUANDO SE DESOCUPE EL DE TRANSMICION
    UCA0TXBUF = UCA0RXBUF; //SEASIGNA LO DEL BUFFER DE RECEPCION LO DE TRANSMICION PARA QUE EXISTA LA TRANSMICION

}
*/
#include "UART.h"


void main(void)
{
WDTCTL = WDTPW | WDTHOLD; // stop watchdog timer

    P1OUT = 0; P2OUT = 0;


    DCOCTL = 0;
    BCSCTL1 = CALBC1_1MHZ;
    DCOCTL = CALDCO_1MHZ;

    initUART();
    //serialprint("probando envío de mensajes");
    __bis_SR_register(GIE + LPM0_bits);

}


//Generar un "eco" de respuesta
#pragma vector = USCIAB0RX_VECTOR
__interrupt void USCIARX_ISR(void)
{

    while(!(IFG2 & UCA0TXIFG));
    UCA0TXBUF = UCA0RXBUF;
}
