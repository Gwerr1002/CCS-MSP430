/*
 * LCDMODE8BITS.h
 *
 *  Created on: 14 sep. 2021
 *      Author: gerard
 */

#ifndef LCDMODE8BITS_H_
#define LCDMODE8BITS_H_

#include <msp430g2553.h>

#define D0 BIT0  //DEL PUERTO P1
#define D1 BIT3
#define D2 BIT4
#define D3 BIT5
#define D4 BIT6
#define D5 BIT7
#define D6 BIT0 //DEL PUERTO P2
#define D7 BIT7 //SI SE CONFIGURA EL P2.7
#define EN BIT4
#define RS BIT2

#define TSET        __delay_cycles(100) //MAYOR A 39 us 1000
#define TFUNCTION   __delay_cycles(5000) //MAYOR A 4.1 ms 9000
#define TLCDON      __delay_cycles(100)


void EN_H_L();
void functionset();
void LCD_ON();
void CLEAR();
void WRITE(char letra);

#endif /* LCDMODE8BITS_H_ */
