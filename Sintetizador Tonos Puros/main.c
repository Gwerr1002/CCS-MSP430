#include "Control.h"

//CONTROL DE LAS NOTAS
unsigned volatile char hex[3],i=0;
unsigned volatile int PERIODO = 0, aux=0;

//CONTROL DEL LOS COLORES
volatile unsigned char R = 33, G = 33, B = 34, edo=1;

void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

    P1OUT = 0; P2OUT = 0;

    DCOCTL = 0;
    BCSCTL1 = CALBC1_1MHZ;
    DCOCTL = CALDCO_1MHZ;

    //CONFIGURACION LCD
    P1DIR |= (D4 + D5 + D6 + D7 + EN + RS);
    functionset();
    //LCD_ON(); //SI SE QUIERE OBSERVAR EL BLINK DEL CURSOR
    LCDON_BLINKOFF(); //ENCIENDE EL LCD PERO SIN EL BLINK DEL CURSOR
    WRITE("Discreto");

    //CONFIGURACION PARA EL RGB
    P2DIR = RED + BLUE + GREEN;

    //CONFIGURACION UART
    initUART();

    //CONFIGURAR COMO SALIDA DE TIMER 0 A LA BOCINA
    P2DIR |= BOCINA;
    P2SEL |= BOCINA;
    P2SEL &= ~BIT7;
    P2SEL2 &= ~(BOCINA | BIT7);
    TACCTL1 |= OUTMOD_7;
    //SELECCIONAR FUENTE DE RELOJ Y MODO DE CONTEO (ASCENDENTE)
    TA0CTL |= TASSEL_2 + MC_1;

    //CONFIGURAR TIMER A1 PARA CONTROL DEL RGB
    //HABILITAR INTERRUPCION
    TA1CCTL0 |= CCIE; //CAPTURE INTERRUPT ENABLE
    //SELECCIONAR MODO DE CONTEO Y FUENTE DE RELOJ:
    TA1CTL |= TASSEL_2 + MC_1;

    //INICIAR CONTEO DEL TIMER A1, ENCIENDE BLANCO
    if(edo == 1){
       TA1CCR0 = R*fCycle;
       P2OUT |= RED;
    }
    positionLCD(16);
    WRITE("Blanco");
    positionLCD(29);
    WRITE("No");

    hex[0] = '0'; hex[1] = '0'; hex[2] = '0';
    __bis_SR_register(GIE);

    while(1){
        pwm(hex,&PERIODO);
        FREC(PERIODO);
        RGB(&R,&G,&B,PERIODO);
        if(aux != PERIODO){
            TACCR0 = PERIODO;
            TACCR1 = TACCR0 >> 1;
            aux = PERIODO;
        }
    }

}

#pragma vector = USCIAB0RX_VECTOR
__interrupt void USCIARX_ISR(void)
{
        while(!(IFG2 & UCA0TXIFG));
        hex[i] = UCA0RXBUF;
        i++;
        if(i == 3){i = 0;}
}

#pragma vector = TIMER1_A0_VECTOR
__interrupt void timerA1(void)
{
    switch(edo){
    case 1:
        TA1CCR0 = R*fCycle;
        P2OUT |= RED;
        edo++;
        break;
    case 2:
        P2OUT &= ~RED;
        P2OUT |= GREEN;
        TA1CCR0 = G*fCycle;
        edo++;
        break;
    case 3:
        P2OUT &= ~GREEN;
        P2OUT |= BLUE;
        TA1CCR0 = B*fCycle;
        edo++;
        break;
    case 4:
        P2OUT &= ~BLUE;
        TA1CCR0 = T-fCycle*(R+G+B);
        edo = 1;
        break;
    }
}
