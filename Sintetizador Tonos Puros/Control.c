/*
 * Control.c
 *
 *  Created on: 10 oct. 2021
 *      Author: gerard
 */
#include "Control.h"

void pwm(unsigned volatile char hex[3], unsigned volatile int *PERIODO)
{
    switch(hex[0]){
    case 'x':
        positionLCD(0);
        WRITE("Continuo");
        *PERIODO = 0;
        break;
    case 'y':
        positionLCD(0);
        WRITE("Discreto");
        *PERIODO = 0;
        break;
    default:
        *PERIODO = (char_hex(hex[0]) << 8) | (char_hex(hex[1]) << 4) | char_hex(hex[2]);
        break;
    }
}

int char_hex(char u)
{
    int dec;
    if((u >= 48) && (u <= 57)) dec = u-48;
    if((u >= 65) && (u <= 70)) dec = u-55;
    return dec;
}

void FREC(unsigned volatile int PERIODO)
{
    unsigned char F[6];
    unsigned int frec;
    if(PERIODO != 0){
        frec = 1000000/(PERIODO);
        F[0] = '0' + (frec)/1000;
        F[1] = '0' + (frec % 1000)/100;
        F[2] = '0' + (frec % 100)/10;
        F[3] = '0' + (frec % 10);
        F[4] = 'H';
        F[5] = 'z';
        positionLCD(10);
        WRITE(F);
    }
    else
    {
        F[0]='0'; F[1]= '0'; F[2]='0'; F[3]= '0';
        F[4] = 'H';
        F[5] = 'z';
        positionLCD(10);
        WRITE(F);
    }
}

void RGB (volatile unsigned char *R,volatile unsigned char *G,volatile unsigned char*B,unsigned volatile int PERIODO)
{
    if(PERIODO == 0)
    {
        *R = 33; *G = 33; *B = 34;
        positionLCD(16);
        WRITE("Blanco       No ");
    }
    else
    {
        if(((PERIODO >= 520) && (PERIODO <= 552)) || ((PERIODO >= 1044) && (PERIODO <= 1105)) || ((PERIODO >= 2086) && (PERIODO <= 2209)) || ((PERIODO >= 4171) && (PERIODO <= 4418)))
        {
            *R = 0; *G = 80; *B = 20;
            positionLCD(16);
            WRITE("Verde Sapo   LA#");
        }
        if(((PERIODO >= 493) && (PERIODO <= 521)) || ((PERIODO >= 985) && (PERIODO <= 1043)) || ((PERIODO >= 1969) && (PERIODO <= 2085)) || ((PERIODO >= 3937) && (PERIODO <= 4170)))
        {
            *R = 23; *G = 75; *B = 2;
            positionLCD(16);
            WRITE("Verde claro   SI");
        }
        if(((PERIODO >= 466) && (PERIODO <= 492)) || ((PERIODO >= 930) && (PERIODO <= 984)) || ((PERIODO >= 1859) && (PERIODO <= 1968)) || ((PERIODO >= 3716) && (PERIODO <= 3936)))
        {
            *R = 45; *G = 45; *B = 10;
            positionLCD(16);
            WRITE("AmarilloClaro DO");
        }
        if(((PERIODO >= 440) && (PERIODO <= 465)) || ((PERIODO >= 878) && (PERIODO <= 929)) || ((PERIODO >= 1755) && (PERIODO <= 1858)) || ((PERIODO >= 3508) && (PERIODO <= 3715)))
        {
            *R = 55; *G = 40; *B = 0;
            positionLCD(16);
            WRITE("Amarillo     DO#");
        }
        if(((PERIODO >= 415) && (PERIODO <= 439)) || ((PERIODO >= 829) && (PERIODO <= 877)) || ((PERIODO >= 1656) && (PERIODO <= 1754)) || ((PERIODO >= 3311) && (PERIODO <= 3507)))
        {
            *R = 70; *G = 20; *B = 10;
            positionLCD(16);
            WRITE("Naranja claro RE");
        }
        if(((PERIODO >= 392) && (PERIODO <= 414)) || ((PERIODO >= 782) && (PERIODO <= 828)) || ((PERIODO >= 1563) && (PERIODO <= 1655)) || ((PERIODO >= 3125) && (PERIODO <= 3310)))
        {
            *R = 80; *G = 20; *B = 0;
            positionLCD(16);
            WRITE("Naranja      RE#");
        }
        if(((PERIODO >= 370) && (PERIODO <= 391)) || ((PERIODO >= 738) && (PERIODO <= 781)) || ((PERIODO >= 1476) && (PERIODO <= 1562)) || ((PERIODO >= 2950) && (PERIODO <= 3124)))
        {
            *R = 90; *G = 5; *B = 5;
            positionLCD(16);
            WRITE("Carmesi       MI");
        }
        if(((PERIODO >= 349) && (PERIODO <= 369)) || ((PERIODO >= 697) && (PERIODO <= 737)) || ((PERIODO >= 1393) && (PERIODO <= 1475)) || ((PERIODO >= 2784) && (PERIODO <= 2949)))
        {
            *R = 65; *G = 10; *B = 25;
            positionLCD(16);
            WRITE("Rosa          FA");
        }
        if(((PERIODO >= 330) && (PERIODO <= 348)) || ((PERIODO >= 658) && (PERIODO <= 696)) || ((PERIODO >= 1315) && (PERIODO <= 1392)) || ((PERIODO >= 2628) && (PERIODO <= 2783)))
        {
            *R = 15; *G = 0; *B = 85;
            positionLCD(16);
            WRITE("Morado       FA#");
        }
        if(((PERIODO >= 312) && (PERIODO <= 329)) || ((PERIODO >= 621) && (PERIODO <= 657)) || ((PERIODO >= 1241) && (PERIODO <= 1314)) || ((PERIODO >= 2481) && (PERIODO <= 2627)))
        {
            *R = 7; *G = 0; *B = 93;
            positionLCD(16);
            WRITE("Azul rey     SOL");
        }
        if(((PERIODO >= 586) && (PERIODO <= 620)) || ((PERIODO >= 1171) && (PERIODO <= 1240)) || ((PERIODO >= 2342) && (PERIODO <= 2480)))
        {
            *R = 10; *G = 10; *B = 80;
            positionLCD(16);
            WRITE("Azul        SOL#");
        }
        if(((PERIODO >= 553) && (PERIODO <= 585)) || ((PERIODO >= 1106) && (PERIODO <= 1170)) || ((PERIODO >= 2210) && (PERIODO <= 2341)))
        {
            *R = 5; *G = 55; *B = 40;
            positionLCD(16);
            WRITE("Azul claro    LA");
        }
    }
}
