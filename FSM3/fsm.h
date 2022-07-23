//****************************************************************************//
//  MSP430 state machine
//  fsm.h
//
//  Describtion:
//    A simple state machine for the MSP430
//
//  Generated with Excel Table
//  Date:  10/01/2021        Time:  12:37:12
//
//****************************************************************************//

#ifndef FSM_H
#define FSM_H

#include <msp430g2553.h>
#include <stdint.h>
#include <stdio.h>

#define izquierda BIT6
#define derecha   BIT0
#define avanza    BIT5
#define S1        BIT1
#define S2        BIT3

//****************************************************************************//
// State table typedef
//****************************************************************************//
typedef struct
{
  void (*ptrFunct) (void);
  uint8_t NextState;
} FSM_STATE_TABLE;

extern uint8_t ActState;


#define NR_EVENTS 4
#define S1_0_S2_0  0
#define S1_0_S2_1  1
#define S1_1_S2_0  2
#define S1_1_S2_1  3

#define NR_STATES 3
#define A  0
#define B  1
#define C  2


//****************************************************************************//
// Function prototypes
//****************************************************************************//
// Initialize state machine
void FSM_Init (void);

// Event function "S1_0_S2_0"
void FSM_S1_0_S2_0 (void);

// Event function "S1_0_S2_1"
void FSM_S1_0_S2_1 (void);

// Event function "S1_1_S2_0"
void FSM_S1_1_S2_0 (void);

// Event function "S1_1_S2_1"
void FSM_S1_1_S2_1 (void);

// Transition function "gira_derecha"
void FSM_gira_derecha (void);

// Transition function "gira_izquierda"
void FSM_gira_izquierda (void);

// Transition function "avanza_frente"
void FSM_avanza_frente (void);


//****************************************************************************//

#endif /* FSM_H */

//****************************************************************************//
