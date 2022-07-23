/*
 * UART.c
 *
 *  Created on: 17 sep. 2021
 *      Author: gerard
 */
#include "UART.h"
void initUART(void)
{
    //P1.1 <- RXD, P1.2 <- TXD
    P1SEL |= BIT1 + BIT2;
    P1SEL2 |= BIT1 + BIT2;


    //Seleccionamos como fuente de reloj el SMCLK para la USCI:
    UCA0CTL1 |= UCSSEL_2;


    // Baud rate de 9600


    /*
     *  1000000/9600 = 104.166666
     *
     *  round(0.16 * 8) = round(1.28) = 1 <- Modulación 1
     *
     *  104 <- 0b01101000
     */


    UCA0BR0 = 104;
    UCA0BR1 = 0;


    //Modulación UCBRS:
    UCA0MCTL = UCBRS0;
    //Inicializar la máquina de estados de la USCI A
    UCA0CTL1 &= ~UCSWRST;
    IE2 |= UCA0RXIE;
}

