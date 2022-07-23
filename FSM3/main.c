#include "fsm.h"

typedef uint8_t inputs;
inputs sensores;

void eventos(inputs entradas);

void main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
    P1OUT = 0; P2OUT= 0;
    P1DIR |= izquierda | derecha;
    P2DIR |= avanza;

    P1REN |= (S1 + S2);
    P1OUT |= (S1 + S2);

    //INICIALIZAR MÁQUINA DE ESTADOS
    FSM_Init();
    for(;;)
    {

        sensores = (~P1IN & S1) | ((~P1IN & S2)>>3);
        eventos(sensores);

    }

}

void eventos(inputs entradas)
{
    switch(entradas)
    {
      case 0x00:
          FSM_S1_0_S2_0();
          break;
      case 0x01:
          FSM_S1_0_S2_1();
          break;
      case 0x02:
          FSM_S1_1_S2_0();
          break;
      case 0x03:
          FSM_S1_1_S2_1();
          break;
    }
}
