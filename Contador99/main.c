#include <msp430g2553.h>
#include "LCDMODE4BITS.h"

#define S0 BIT1
#define S1 BIT2

volatile unsigned char num[2],switcheo = 0,i=0;

void main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
    P1OUT = 0; P2OUT = 0;
    if (CALBC1_1MHZ==0xFF)
      {
          while(1);
      }
    DCOCTL = 0;
    BCSCTL1 = CALBC1_1MHZ;
    DCOCTL = CALDCO_1MHZ;

    //CONFIGURACION LCD
    P1DIR |= (D4 + D5 + D6 + D7 + EN + RS);
    functionset();
    //LCD_ON(); //SI SE QUIERE OBSERVAR EL BLINK DEL CURSOR
    LCDON_BLINKOFF(); //ENCIENDE EL LCD PERO SIN EL BLINK DEL CURSOR

    WRITE("LA FRECUENCIA ESDE 60 Hz");

    BCSCTL2 |= SELM_0;
    BCSCTL3 |= LFXT1S_2;
    IFG1 &= ~OFIFG;

    P1DIR = S0 + S1;
    P2DIR = BIT2 + BIT3 + BIT4 + BIT5;


    TA0CTL = TASSEL_2 + MC_1;
    TA0CCTL0 = CCIE;
    TA0CCR0 = 10000;


    TA1CTL = TASSEL_1 + MC_1;
    TA1CCTL0 = CCIE;
    TA1CCR0 |= 100;
    num[0]=0; num[1]=0;
    switcheo ^= BIT0;

    __bis_SR_register(LPM0_bits + GIE);
}

#pragma vector = TIMER0_A0_VECTOR
__interrupt void timerA0(void)
{
 if(i==100){
     if(num[0] < 9) num[0]++;
     else
     {
         num[0] = 0;
         if(num[1]<9) num[1]++;
         else num[1] = 0;
     }
     i=0;
 }
 else i++;
}

#pragma vector = TIMER1_A0_VECTOR
__interrupt void timerA1(void)
{
    switcheo ^= BIT0 + BIT1;
    P2OUT &= ~(0x3C);
    P1OUT &= ~(0x06);
    if(switcheo == BIT0)
    {
        P1OUT |= switcheo << 1;
        P2OUT |= (num[0] & 0x0F) << 2;
    }
    else
    {
        P1OUT |= switcheo << 1;
        P2OUT |= (num[1] & 0x0F) << 2;
    }
}
