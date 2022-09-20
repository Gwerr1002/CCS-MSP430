//****************************************************************************//
//  MSP430 state machine
//  fsm.h
//
//  Describtion:
//    A simple state machine for the MSP430
//
//  Generated with Excel Table
//  Date:  10/04/2021        Time:  10:43:34
//
//****************************************************************************//

#ifndef FSM_H
#define FSM_H

#include <msp430g2553.h>
#include <LCDMODE4BITS.h>
#include <stdint.h>
#include <stdio.h>

//****************************************************************************//
// State table typedef
//****************************************************************************//
typedef struct
{
  void (*ptrFunct) (void);
  uint8_t NextState;
} FSM_STATE_TABLE;

extern uint8_t ActState;


#define NR_EVENTS 3
#define IN_100  0
#define IN_010  1
#define IN_001  2

#define NR_STATES 5
#define E0  0
#define E10  1
#define E20  2
#define E25_30  3
#define E35  4


//****************************************************************************//
// Function prototypes
//****************************************************************************//
// Initialize state machine
void FSM_Init (void);

// Event function "IN_100"
void FSM_IN_100 (void);

// Event function "IN_010"
void FSM_IN_010 (void);

// Event function "IN_001"
void FSM_IN_001 (void);

// Transition function "ingreso10"
void FSM_ingreso10 (void);

// Transition function "ingreso25"
void FSM_ingreso25 (void);

// Transition function "devolucion"
void FSM_devolucion (void);

// Transition function "dar_articulo"
void FSM_dar_articulo (void);


//****************************************************************************//

#endif /* FSM_H */

//****************************************************************************//
