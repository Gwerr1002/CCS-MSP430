//****************************************************************************//
//  MSP430 state machine
//  fsm_transition.c
//
//  Describtion:
//    A simple state machine for the MSP430
//    You can add your own code in here!!!
//
//  Generated with Excel Table
//  Date:  10/04/2021        Time:  10:43:34
//
//****************************************************************************//

#include "fsm.h"
unsigned volatile char num1=0,num2=0;

//****************************************************************************//
// Transition function "ingreso10"
//****************************************************************************//
void FSM_ingreso10 (void)
{
  CLEAR();
  WRITE("HA INGRESADO 10 CENTAVOS");
}


//****************************************************************************//
// Transition function "ingreso25"
//****************************************************************************//
void FSM_ingreso25 (void)
{
    CLEAR();
    WRITE("HA INGRESADO 25 CENTAVOS");
    if((num1 + 5) <= 9) num1= num1+5;
}


//****************************************************************************//
// Transition function "devolucion"
//****************************************************************************//
void FSM_devolucion (void)
{
    CLEAR();
    WRITE("REGRESANDO DINERO...");
    __delay_cycles(1000000);
    CLEAR();
    positionLCD(5);
    WRITE("Hola!");
    positionLCD(17);
    WRITE("Solo 10 y 25 c");
}


//****************************************************************************//
// Transition function "dar_articulo"
//****************************************************************************//
void FSM_dar_articulo (void)
{
    CLEAR();
    WRITE("DESPACHANDO...");
    __delay_cycles(1000000);
    CLEAR();
    WRITE("VUELVA PRONTO :)");
    __delay_cycles(1000000);
    CLEAR();
    positionLCD(5);
    positionLCD(5);
    WRITE("Hola!");
    positionLCD(17);
    WRITE("Solo 10 y 25 c");

}


//****************************************************************************//
