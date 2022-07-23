//****************************************************************************//
//  MSP430 state machine
//  fsm.c
//
//  Describtion:
//    A simple state machine for the MSP430
//    Do not change code in here!!!
//
//  Generated with Excel Table
//  Date:  10/17/2021        Time:  23:14:37
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
  FSM_NoCambio, NC, FSM_Cambio, CA,
  FSM_NoCambio, NC, FSM_Cambio, CA
};


//****************************************************************************//
// Initialize state machine
//****************************************************************************//
void FSM_Init (void)
{
  ActState = NC;
}


//****************************************************************************//
// Event function "AUXigP"
//****************************************************************************//
void FSM_AUXigP (void)
{
  if (StateTable[ActState][AUXIGP].ptrFunct != NULL)
    StateTable[ActState][AUXIGP].ptrFunct();

  ActState = StateTable[ActState][AUXIGP].NextState;
}


//****************************************************************************//
// Event function "AUXdifP"
//****************************************************************************//
void FSM_AUXdifP (void)
{
  if (StateTable[ActState][AUXDIFP].ptrFunct != NULL)
    StateTable[ActState][AUXDIFP].ptrFunct();

  ActState = StateTable[ActState][AUXDIFP].NextState;
}


//****************************************************************************//
