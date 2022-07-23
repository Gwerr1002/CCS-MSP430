//****************************************************************************//
//  MSP430 state machine
//  fsm.h
//
//  Describtion:
//    A simple state machine for the MSP430
//
//  Generated with Excel Table
//  Date:  10/17/2021        Time:  23:14:38
//
//****************************************************************************//

#ifndef FSM_H
#define FSM_H

#include <stdint.h>
#include <stdio.h>
#include "Control.h" //CARGA DE PROCEDIMIENTOS A UTILIZAR

//****************************************************************************//
// State table typedef
//****************************************************************************//
typedef struct
{
  void (*ptrFunct) (void);
  uint8_t NextState;
} FSM_STATE_TABLE;

extern uint8_t ActState;


#define NR_EVENTS 2
#define AUXIGP  0
#define AUXDIFP  1

#define NR_STATES 2
#define NC  0
#define CA  1


//****************************************************************************//
// Function prototypes
//****************************************************************************//
// Initialize state machine
void FSM_Init (void);

// Event function "AUXigP"
void FSM_AUXigP (void);

// Event function "AUXdifP"
void FSM_AUXdifP (void);

// Transition function "NoCambio"
void FSM_NoCambio (void);

// Transition function "Cambio"
void FSM_Cambio (void);


//****************************************************************************//

#endif /* FSM_H */

//****************************************************************************//
