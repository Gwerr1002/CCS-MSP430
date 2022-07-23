#include "fsm.h"

//CONTROL DE LAS NOTAS
unsigned volatile char hex[3],i=0;
unsigned volatile int PERIODO, aux;

//CONTROL DEL LOS COLORES
volatile unsigned char R = 33, G = 33, B = 34, cntrl=1;

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
    TA1CCR0 = R*fCycle;
    P2OUT |= RED;

    positionLCD(16);
    WRITE("Blanco");
    positionLCD(29);
    WRITE("No");

    hex[0] = '0'; hex[1] = '0'; hex[2] = '0'; //INICIO DEL DESPLIEGUE DE LA FRECUENCIA

    FSM_Init ();

    __bis_SR_register(GIE);

    while(1){
        FSM_AUXigP (); //EVENTO: SI NO HAY CAMBIOS EN LA APP SE MANTIENE EN EL ESTACO NC
        if(aux != PERIODO){
            FSM_AUXdifP (); //EVENTO: SI HAY CAMBIOS EN LA APP CAMBIA AL ESTADO C
        }
    }

}

#pragma vector = USCIAB0RX_VECTOR
__interrupt void USCIARX_ISR(void)
{
        while(!(IFG2 & UCA0TXIFG));
        hex[i] = UCA0RXBUF; //RECIBE NUMEROS EN FORMA DE TEXTO HEXADECIMAL
        i++;
        if(i == 3){i = 0;} //SÓLO 3 DÍGITOS HEXADECIMALES
}

#pragma vector = TIMER1_A0_VECTOR
__interrupt void timerA1(void)
{
    //CONTROL DEL LED RGB
    switch(cntrl){
    case 1:
        TA1CCR0 = R*fCycle; //ENCIENTE LA FRACCION DE CICLO SELLECCIONADA PARA ROJO
        P2OUT |= RED;
        cntrl++;
        break;
    case 2:
        P2OUT &= ~RED;
        P2OUT |= GREEN;
        TA1CCR0 = G*fCycle; //ENCIENTE LA FRACCION DE CICLO SELLECCIONADA PARA VERDE
        cntrl++;
        break;
    case 3:
        P2OUT &= ~GREEN;
        P2OUT |= BLUE;
        TA1CCR0 = B*fCycle; //ENCIENTE LA FRACCION DE CICLO SELLECCIONADA PARA AZUL
        cntrl++;
        break;
    case 4:
        P2OUT &= ~BLUE;
        TA1CCR0 = T-fCycle*(R+G+B); //APAGA TODOS LOS LED PARA UN CICLO DE TRABAJO DEL 90%
        cntrl = 1;
        break;
    }
}
