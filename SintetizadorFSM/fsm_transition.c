//****************************************************************************//
//  MSP430 state machine
//  fsm_transition.c
//
//  Describtion:
//    A simple state machine for the MSP430
//    You can add your own code in here!!!
//
//  Generated with Excel Table
//  Date:  10/17/2021        Time:  23:14:38
//
//****************************************************************************//

#include "fsm.h"

//****************************************************************************//
// Transition function "NoCambio"
//****************************************************************************//
void FSM_NoCambio (void)
{
  /*
   *DECODIFICACION HEX-DEC, MUESTRA EN LCD DE MODO CONTINUO/DISCRETO
   *MUESTRA EN LCD DE FRECUENCIA
   *MUESTRA EN LCD COLOR Y NOTA
   */
  pwm();
  FREC();
  RGB();
}


//****************************************************************************//
// Transition function "Cambio"
//****************************************************************************//
void FSM_Cambio (void)
{
  //CAMBIO DE NOTA
  aux = PERIODO;
  TACCR0 = PERIODO;
  TACCR1 = TACCR0 >> 1;
}


//****************************************************************************//
