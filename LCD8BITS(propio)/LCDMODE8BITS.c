#include "LCDMODE8BITS.h"
/*
 * LCDMODE8BITS.c
 *
 *  Created on: 14 sep. 2021
 *      Author: gerard
 */

void EN_H_L()
{
    TSET;
    P2OUT ^= EN;
    TSET;
    P2OUT ^= EN;
}

void functionset()
{

    P1OUT |= (D5 + D4 + D3);
    TFUNCTION;
    EN_H_L();
    P1OUT &= ~(D5 + D4 + D3);
    TFUNCTION;

}
void LCD_ON()
{
    TLCDON;
    P1OUT |= (D0 + D1 + D2+ D3);
    TLCDON;
    EN_H_L();
    TFUNCTION;
    TFUNCTION;
    TFUNCTION;
    P1OUT &= ~(D0 + D1 + D2+ D3);

}
void CLEAR()
{
    TFUNCTION;
    P1OUT |= D0;
    TFUNCTION;
    EN_H_L();
    P1OUT &= ~D0;
    TFUNCTION;
}

void WRITE(char letra)
{
    TFUNCTION;
    switch(letra)
    {
    case '0':
        P1OUT ^= (D4 + D5);
        EN_H_L();
        P1OUT ^= (D4 + D5);
        break;
    case 'A':
        P1OUT ^= (D0);
        P2OUT ^= (D6);
        EN_H_L();
        P1OUT ^= (D0);
        P1OUT ^= (D6);
        break;
    case 'B':
        P1OUT ^= (D1);
        P1OUT ^= (D6);
        EN_H_L();
        P1OUT ^= (D1);
        P1OUT ^= (D6);
        break;
    case 'C':
        P1OUT ^= (D0 + D1);
        P1OUT ^= (D6);
        EN_H_L();
        P1OUT ^= (D0 + D1);
        P1OUT ^= (D6);
        break;
    case 'D':
        P1OUT ^= (D2);
        P1OUT ^= (D6);
        EN_H_L();
        P1OUT ^= (D2);
        P1OUT ^= (D6);
        break;
    case 'E':
        P1OUT ^= (D0 + D2);
        P1OUT ^= (D6);
        EN_H_L();
        P1OUT ^= (D0 + D2);
        P1OUT ^= (D6);
        break;
    case 'F':
        P1OUT ^= (D1 + D2);
        P1OUT ^= (D6);
        EN_H_L();
        P1OUT ^= (D1 + D2);
        P1OUT ^= (D6);
        break;
    case 'G':
        P1OUT ^= (D0 + D1 + D2);
        P1OUT ^= (D6);
        EN_H_L();
        P1OUT ^= (D0 + D1 + D2);
        P1OUT ^= (D6);
        break;
    case 'H':
        P1OUT ^= (D3);
        P1OUT ^= (D6);
        EN_H_L();
        P1OUT ^= (D3);
        P1OUT ^= (D6);
        break;
    case 'I':
        P1OUT ^= (D0 + D3);
        P1OUT ^= (D6);
        EN_H_L();
        P1OUT ^= (D0 + D3);
        P1OUT ^= (D6);
        break;
    case 'J':
        P1OUT ^= (D1 + D3);
        P1OUT ^= (D6);
        EN_H_L();
        P1OUT ^= (D1 + D3);
        P1OUT ^= (D6);
        break;
    case 'K':
        P1OUT ^= (D0 + D1 + D3);
        P1OUT ^= (D6);
        EN_H_L();
        P1OUT ^= (D0 + D1 + D3);
        P1OUT ^= (D6);
        break;
    case 'L':
        P1OUT ^= (D3 + D2);
        P1OUT ^= (D6);
        EN_H_L();
        P1OUT ^= (D3 + D2);
        P1OUT ^= (D6);
        break;
    case 'M':
        P1OUT ^= (D3 + D2 + D0);
        P1OUT ^= (D6);
        EN_H_L();
        P1OUT ^= (D3 + D2 + D0);
        P1OUT ^= (D6);
        break;
    case 'N':
        P1OUT ^= (D3 + D2 + D1);
        P1OUT ^= (D6);
        EN_H_L();
        P1OUT ^= (D3 + D2 + D1);
        P1OUT ^= (D6);
        break;
    case 'O':
        P1OUT ^= (D3 + D2 + D1 + D0);
        P1OUT ^= (D6);
        EN_H_L();
        P1OUT ^= (D3 + D2 + D1 + D0);
        P1OUT ^= (D6);
        break;
    case 'P':
        P2OUT ^= (D6);
        P1OUT ^= D4;
        EN_H_L();
        P1OUT ^= D4;
        P2OUT ^= (D6);
        break;
    case 'Q':
        P1OUT ^= (D0 + D4);
        P2OUT ^= (D6);
        EN_H_L();
        P1OUT ^= (D0 + D4);
        P2OUT ^= (D6);
        break;
    case 'R':
        P1OUT ^= (D1 + D4);
        P2OUT ^= (D6);
        EN_H_L();
        P1OUT ^= (D1 + D4);
        P2OUT ^= (D6);
        break;
    case 'S':
        P1OUT ^= (D0 + D1 + D4);
        P2OUT ^= (D6);
        EN_H_L();
        P1OUT ^= (D0 + D1 + D4);
        P2OUT ^= (D6);
        break;
    case 'T':
        P1OUT ^= (D2 + D4);
        P2OUT ^= (D6);
        EN_H_L();
        P1OUT ^= (D2 + D4);
        P2OUT ^= (D6);
        break;
    case 'U':
        P1OUT ^= (D0 + D2 + D4);
        P2OUT ^= (D6);
        EN_H_L();
        P1OUT ^= (D0 + D2 + D4);
        P2OUT ^= (D6);
        break;
    case 'V':
        P1OUT ^= (D1 + D2 + D4);
        P2OUT ^= (D6);
        EN_H_L();
        P1OUT ^= (D1 + D2 + D4);
        P2OUT ^= (D6);
        break;
    case 'W':
        P1OUT ^= (D0 + D1 + D2 + D4);
        P2OUT ^= (D6);
        EN_H_L();
        P1OUT ^= (D0 + D1 + D2 + D4);
        P2OUT ^= (D6);
        break;
    case 'X':
        P1OUT ^= (D3 + D4);
        P2OUT ^= (D6);
        EN_H_L();
        P1OUT ^= (D3+ D4);
        P2OUT ^= (D6);
        break;
    case 'Y':
        P1OUT ^= (D0 + D3 + D4);
        P2OUT ^= (D6);
        EN_H_L();
        P1OUT ^= (D0 + D3 + D4);
        P2OUT ^= (D6);
        break;
    case 'Z':
        P1OUT ^= (D1 + D3 + D4);
        P2OUT ^= (D6);
        EN_H_L();
        P1OUT ^= (D1 + D3 + D4);
        P2OUT ^= (D6);
        break;
    default:

        break;
    }
}



