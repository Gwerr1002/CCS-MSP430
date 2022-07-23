/*
 * LCDMODE4BITS.h
 *
 *  Created on: 15 sep. 2021
 *      Author: gerard
 */

#ifndef LCDMODE4BITS_H_
#define LCDMODE4BITS_H_

#include <msp430g2553.h>

#define D4 BIT4
#define D5 BIT5
#define D6 BIT6
#define D7 BIT7
#define EN BIT0
#define RS BIT3

#define TSET        __delay_cycles(100) //MAYOR A 39 us
#define TFUNCTION   __delay_cycles(1000) //MAYOR A 4.1 ms, AQUI SE HA DEJADO A a 1 ms
#define TWRITE      __delay_cycles(200)


void EN_H_L(void); //ACTIVA ENABLE DE ALTO A BAJO

//INUSUALMENTE SE USAN LOS SIGUIENTES DOS EN EL MAIN. SON PROCEDIMIENTOS AUXILIARES DE LOS DEMÁS
void sendLCD(unsigned char byte); //ENVIA INFORMACION AL LCD ESPECIFICAMENTE COMANDOS DE ESCRITURA Y POSICION DEL CURSOR
void funcLCD(unsigned char byte); //ENVIA COMANDOS DE FUNCIONES GENERALES AL LCD

void functionset(void); //RUTINA DE INICIO DEL LCD


void LCD_ON(void); //ENCIENDE LCD CON CURSOR Y BLINK
void LCDON_BLINKOFF(void); //ENCIENDE LCD SIN BLINK NI CURSOR

void WRITE(unsigned char w[]); //ESCRIBE UNA CADENA DE CARACTERES

void HOME(void); //REGRESA AL INICIO

void CLEAR(void); //LIMPIAR PANTALLA

void positionLCD(unsigned char pos);

#endif /* LCDMODE4BITS_H_ */
