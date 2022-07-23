#include "LCDMODE4BITS.h"
/*
 * LCDMODE4BITS.c
 *
 *  Created on: 15 sep. 2021
 *      Author: gerard
 */

void EN_H_L(void) //CREA FLANCO DE BAJADA PARA INGRESAR INSTRUCCION
{
    TSET;
    P1OUT ^= EN;
    TSET;
    P1OUT ^= EN;
}

void sendLCD(unsigned char byte)
{
    TWRITE;
    P1OUT ^= (byte & 0xF0); //SE ESTABLECE EL NIBLE ALTO PRIMERO
    TWRITE;
    EN_H_L();
    P1OUT ^= (byte & 0xF0);

    TWRITE;
    P1OUT ^= (byte << 4) & 0xF0; //SE ESTABLECE EL NIBLE BAJO
    TWRITE;
    EN_H_L();
    P1OUT ^= (byte << 4) & 0xF0;
}
void funcLCD(unsigned char byte)
{
    EN_H_L();
    TFUNCTION;
    P1OUT ^= byte;
    TFUNCTION;
    EN_H_L();
    P1OUT ^= byte;
    TFUNCTION;
}

void functionset(void) // RUTINA DE ENCENDIDO DEL LCD
{
    //SET
    P1OUT ^= D4 + D5;
    TFUNCTION;
    EN_H_L();
    TFUNCTION;
    EN_H_L();
    TFUNCTION;
    EN_H_L();
    TFUNCTION;
    P1OUT ^= D4 + D5;

    //CAMBIAR LA INTERFASE A 4 BITS
    P1OUT ^= D5;
    TFUNCTION;
    EN_H_L();
    TFUNCTION;
    EN_H_L();
    TFUNCTION;
    P1OUT ^= D5;

    //ACTIVAR A DOS LINEAS
    P1OUT ^= D7;
    TFUNCTION;
    EN_H_L();
    TFUNCTION;
    P1OUT ^= D7;
    TFUNCTION;

    //DISPLAY OFF
    EN_H_L();
    P1OUT ^= D7;
    TFUNCTION;
    EN_H_L();
    TFUNCTION;
    P1OUT ^= D7;
    TFUNCTION;

    //DISPLAY CLEAR
    EN_H_L();
    P1OUT ^= D4;
    TFUNCTION;
    EN_H_L();
    TFUNCTION;
    P1OUT ^= D4;
    TFUNCTION;

    //ENTRY MODE SET
    EN_H_L();
    TFUNCTION;
    P1OUT ^= D5;
    TFUNCTION;
    EN_H_L();
    P1OUT ^= D5;
    TFUNCTION;
}

void LCD_ON(void) //LCD ENCENDIDO CON BLINK Y CURSOR ACTIVO
{
    funcLCD(D7 + D6 + D5 + D4);
}

void LCDON_BLINKOFF(void) //LCD ENCENDIDO SIN BLINK NI CURSOR ACTIVO
{
    funcLCD(D7 + D6);
}

//PARA ESCRIBIR
void WRITE(unsigned char *w)
{
    unsigned char cuenta = 0;
    P1OUT ^= RS;
    while(*w)
    {
     sendLCD(*(w++));
     cuenta++;
     if(cuenta == 16){
         P1OUT ^= RS;
         //TFUNCTION;
         positionLCD(16);
         P1OUT ^= RS;
         //TFUNCTION;
     }
    }
    P1OUT ^= RS;
}

void HOME(void)
{
    funcLCD(D5);
}

void CLEAR(void)
{
    funcLCD(D4);
}

void positionLCD(unsigned char pos)
{
    //la posicion 16 es el inicio del segundo renglon
    //la direccion DDRAM empieza en el 0x40 el inicio del primer renglon es el hezadecimal 0x10
    if(pos > 0x0F) pos = 0x40 + (pos - 0x10); //el numero que recibimos

    //comando para escribir en la DDRAM 0x80:
    pos |= 0x80;
    sendLCD(pos);
}

