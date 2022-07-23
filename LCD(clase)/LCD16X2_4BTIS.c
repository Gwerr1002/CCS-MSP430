/*
 * LCD16X2_4BTIS.c
 *
 *  Created on: 14 sep. 2021
 *      Author: gerard
 */
#include "LCD16X2_4BTIS.h"

void EN_HIGH_TO_LOW(void)
{
    //Para indicar en el bit de Enable (EN) que vamos a escribir:
    P1OUT |= EN;
    DELAY_INIT_2;
    P1OUT &= ~EN;
}

void sendLCD(unsigned char byte, unsigned char RS_flag)
{
    if (RS_flag == 0)
    {
        //Mandamos la instrucción al registro de comandos:
        COMM_REG;
        //Enmascaramos para poner en bajo los bits D4-D7:
        P1OUT &= 0xF0;
        //Corrimiento para mandar los 4 bits más significativos primero:
        P1OUT |= (byte >> 4) & 0x0F;
        EN_HIGH_TO_LOW();

        P1OUT &= 0xF0;
        //Mandamos los 4 bits menos significativos del comando:
        P1OUT |= byte & 0x0F;
        EN_HIGH_TO_LOW();

    }
    else
    {
        //Mandamos instrucción al registro de datos:
        DATA_REG;
        P1OUT &= 0xF0;
        P1OUT |= (byte >> 4) & 0x0F;
        EN_HIGH_TO_LOW();

        P1OUT &= 0xF0;
        P1OUT |= byte & 0x0F;
        EN_HIGH_TO_LOW();

    }
}

void init4bitmode(void)
{
    //Rutina de inicialización de acuerdo al diagrama de flujo:

    //Asegurando que hayan pasado más de 100ms para asegurar que el Vcc alcance los 5V:
    DELAY_INIT_0;

    //Escribiendo al registro de comandos:
    COMM_REG;

    P1OUT &= 0xF0;
    P1OUT |= D4 + D5;
    EN_HIGH_TO_LOW();
    DELAY_INIT_1;

    EN_HIGH_TO_LOW();
    DELAY_INIT_2;

    EN_HIGH_TO_LOW();
    DELAY_INIT_2;

    //Cambiar la interface a 4 bits:
    P1OUT = 0x02;
    EN_HIGH_TO_LOW();
    DELAY_INIT_2;
}

void initLCD(void)
{
    //Modo 4 bit 2 líneas:
    sendLCD(0x28, COMM);
    DELAY;

    //Limpiar LCD:
    sendLCD(0x01, COMM);
    DELAY_RH;

    //Dirección de la RAM (en 0x00):
    sendLCD(0x80, COMM);
    DELAY;

    //Display encendido y con el cursor haciendo blink:
    sendLCD(0x0F, COMM);
    DELAY;

    //Dirección del desplazamiento del cursor:
    sendLCD(0x06, COMM);
    DELAY;

}

void writeLCD(char *s)
{
    while(*s)
    {
        sendLCD(*(s++),DATA);
        DELAY_RH;
    }
}

void clear()
{
    sendLCD(0x01, COMM);
}

void positionLCD(unsigned char pos)
{
    //la posicion 16 es el inicio del segundo renglon
    //la direccion DDRAM empieza en el 0x40 el inicio del primer renglon es el hezadecimal 0x10
    if(pos > 0x0F) pos = 0x40 + (pos - 0x10); //el numero que recibimos

    //comando para escribir en la DDRAM 0x80:
    pos |= 0x80;
    sendLCD(pos, COMM);
}


