//****************************************************************************//
//  MSP430 state machine
//  fsm.c
//
//  Describtion:
//    A simple state machine for the MSP430
//    Do not change code in here!!!
//
//  Generated with Excel Table
//  Date:  10/01/2021        Time:  12:37:11
//
//****************************************************************************//

#include <stdint.h>
#include <stdio.h>
#include "fsm.h"

//****************************************************************************//
// Global variables
//****************************************************************************//
uint8_t  ActState;

const FSM_STATE_TABLE StateTable [NR_STATES][NR_EVENTS] =
{
  FSM_avanza_frente, A, FSM_avanza_frente, A, FSM_gira_derecha, C, FSM_gira_izquierda, B,
  FSM_avanza_frente, A, FSM_avanza_frente, A, FSM_gira_izquierda, B, FSM_gira_izquierda, B,
  FSM_avanza_frente, A, FSM_avanza_frente, A, FSM_gira_derecha, C, FSM_gira_derecha, C
};


//****************************************************************************//
// Initialize state machine
//****************************************************************************//
void FSM_Init (void)
{
  ActState = A;
}


//****************************************************************************//
// Event function "S1_0_S2_0"
//****************************************************************************//
void FSM_S1_0_S2_0 (void)
{
  if (StateTable[ActState][S1_0_S2_0].ptrFunct != NULL)
    StateTable[ActState][S1_0_S2_0].ptrFunct();

  ActState = StateTable[ActState][S1_0_S2_0].NextState;
}


//****************************************************************************//
// Event function "S1_0_S2_1"
//****************************************************************************//
void FSM_S1_0_S2_1 (void)
{
  if (StateTable[ActState][S1_0_S2_1].ptrFunct != NULL)
    StateTable[ActState][S1_0_S2_1].ptrFunct();

  ActState = StateTable[ActState][S1_0_S2_1].NextState;
}


//****************************************************************************//
// Event function "S1_1_S2_0"
//****************************************************************************//
void FSM_S1_1_S2_0 (void)
{
  if (StateTable[ActState][S1_1_S2_0].ptrFunct != NULL)
    StateTable[ActState][S1_1_S2_0].ptrFunct();

  ActState = StateTable[ActState][S1_1_S2_0].NextState;
}


//****************************************************************************//
// Event function "S1_1_S2_1"
//****************************************************************************//
void FSM_S1_1_S2_1 (void)
{
  if (StateTable[ActState][S1_1_S2_1].ptrFunct != NULL)
    StateTable[ActState][S1_1_S2_1].ptrFunct();

  ActState = StateTable[ActState][S1_1_S2_1].NextState;
}


//****************************************************************************//
