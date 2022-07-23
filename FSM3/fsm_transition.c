//****************************************************************************//
//  MSP430 state machine
//  fsm_transition.c
//
//  Describtion:
//    A simple state machine for the MSP430
//    You can add your own code in here!!!
//
//  Generated with Excel Table
//  Date:  10/01/2021        Time:  12:37:11
//
//****************************************************************************//

#include "fsm.h"

//****************************************************************************//
// Transition function "gira_derecha"
//****************************************************************************//
void FSM_gira_derecha (void)
{
    P1OUT &= ~izquierda;
    P2OUT &= ~avanza;
    P1OUT |= derecha;
}


//****************************************************************************//
// Transition function "gira_izquierda"
//****************************************************************************//
void FSM_gira_izquierda (void)
{
    P1OUT |= izquierda;
    P2OUT &= ~avanza;
    P1OUT &= ~derecha;
}


//****************************************************************************//
// Transition function "avanza_frente"
//****************************************************************************//
void FSM_avanza_frente (void)
{
    P2OUT |= avanza;
    P1OUT &= ~(izquierda | derecha);
}


//****************************************************************************//
