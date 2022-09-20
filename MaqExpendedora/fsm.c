//****************************************************************************//
//  MSP430 state machine
//  fsm.c
//
//  Describtion:
//    A simple state machine for the MSP430
//    Do not change code in here!!!
//
//  Generated with Excel Table
//  Date:  10/04/2021        Time:  10:43:33
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
  FSM_ingreso10, E10, FSM_ingreso25, E25_30, NULL, E0,
  FSM_ingreso10, E20, FSM_ingreso25, E35, FSM_devolucion, E0,
  FSM_ingreso10, E25_30, FSM_ingreso25, E35, FSM_devolucion, E0,
  FSM_ingreso10, E35, FSM_ingreso25, E35, FSM_devolucion, E0,
  FSM_ingreso10, E35, FSM_ingreso25, E35, FSM_dar_articulo, E0
};


//****************************************************************************//
// Initialize state machine
//****************************************************************************//
void FSM_Init (void)
{
  ActState = E0;
}


//****************************************************************************//
// Event function "IN_100"
//****************************************************************************//
void FSM_IN_100 (void)
{
  if (StateTable[ActState][IN_100].ptrFunct != NULL)
    StateTable[ActState][IN_100].ptrFunct();

  ActState = StateTable[ActState][IN_100].NextState;
}


//****************************************************************************//
// Event function "IN_010"
//****************************************************************************//
void FSM_IN_010 (void)
{
  if (StateTable[ActState][IN_010].ptrFunct != NULL)
    StateTable[ActState][IN_010].ptrFunct();

  ActState = StateTable[ActState][IN_010].NextState;
}


//****************************************************************************//
// Event function "IN_001"
//****************************************************************************//
void FSM_IN_001 (void)
{
  if (StateTable[ActState][IN_001].ptrFunct != NULL)
    StateTable[ActState][IN_001].ptrFunct();

  ActState = StateTable[ActState][IN_001].NextState;
}


//****************************************************************************//
