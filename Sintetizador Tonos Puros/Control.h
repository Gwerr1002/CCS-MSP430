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

#define BOCINA BIT6

//PARA CONTROL DEL RGB
#define RED BIT1
#define BLUE BIT5
#define GREEN BIT3
#define T 16000 //PERIODO A 62.5 HZ
#define fCycle 14400/100 //CICLO DE TRABAJO AL 90% SOBRE 100

void pwm(unsigned volatile char hex[3], unsigned volatile int *PERIODO); //DA EL PWM QUE SE ENVÍA DE LA APP

int char_hex(char u); //DECODIFICACIÓN CHAR A DECIMAL

void FREC(unsigned volatile int PERIODO); //ESCRIBE LA FRECUENCIA EN EL LCD

void RGB (volatile unsigned char *R,volatile unsigned char *G,volatile unsigned char*B,unsigned volatile int PERIODO);

#endif /* CONTROL_H_ */
