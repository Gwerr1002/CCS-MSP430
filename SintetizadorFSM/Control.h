/*
 * Control.h
 *
 *  Created on: 10 oct. 2021
 *      Author: gerard
 */

#ifndef CONTROL_H_
#define CONTROL_H_

#include <msp430g2553.h>
#include "UART.h"
#include "LCDMODE4BITS.h"

extern unsigned volatile char hex[3];
extern unsigned volatile int PERIODO,aux;
extern volatile unsigned char R, G, B;

#define BOCINA BIT6

//PARA CONTROL DEL RGB
#define RED BIT1
#define BLUE BIT5
#define GREEN BIT3
#define T 16000 //PERIODO A 62.5 HZ
#define fCycle 14400/100 //CICLO DE TRABAJO AL 90% SOBRE 100

void pwm(void); //DA EL PWM QUE SE ENVÍA DE LA APP

int char_hex(char u); //DECODIFICACIÓN CHAR A DECIMAL

void FREC(void); //ESCRIBE LA FRECUENCIA ACTUAL EN EL LCD

void RGB (void); //CONTROL DEL RGB Y IMPRESIÓN EN LCD DEL COLOR

#endif /* CONTROL_H_ */
