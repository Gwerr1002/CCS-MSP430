/*
 * LCD16X2_4BTIS.h
 *
 *  Created on: 14 sep. 2021
 *      Author: gerard
 */

#ifndef LCD16X2_4BTIS_H_
#define LCD16X2_4BTIS_H_
#include <msp430g2553.h>

#define D4 BIT0
#define D5 BIT1
#define D6 BIT2
#define D7 BIT3
#define RS BIT4
#define EN BIT5

/*
 * Para escribir al registro de comandos o de datos:
 * RS = 1 --> REGISTRO DE DATOS
 * RS = 0 --> REGISTRO DE CÓDIGOS DE COMANDOS
 *
 */

#define COMM_REG P1OUT &= ~RS
#define DATA_REG P1OUT |= RS
#define COMM 0
#define DATA 1

#define DELAY __delay_cycles(60) //tiempo para instrucciones en general
#define DELAY_RH __delay_cycles(1550) //Tiempo para ejecutar la instrucción Return Home/Clear Display

//Para la secuencia de inicialización en 4 bits (siguiendo el diagrama de flujo del PDF)
#define DELAY_INIT_0    __delay_cycles(60000)
#define DELAY_INIT_1    __delay_cycles(4100)
#define DELAY_INIT_2    __delay_cycles(250)

void EN_HIGH_TO_LOW(void);
void init4bitmode(void);
void initLCD(void);
void sendLCD(unsigned char byte, unsigned char RS_flag);
void writeLCD(char *s);
void clear();
void positionLCD(unsigned char pos);

#endif /* LCD16X2_4BTIS_H_ */
