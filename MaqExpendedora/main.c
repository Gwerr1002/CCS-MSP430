#include "fsm.h"

#define BTN BIT6 //BOTON DESPACHAR - REGRESAR DINERO
#define C25 BIT0 //BOTON INGRESO DE MONEDA DE 25
#define C10 BIT1 //BOTON INGRESO DE MONEDA DE 10

typedef uint8_t inputs;
inputs entradas;

#define S0 BIT1 //CONTROL DE PRIMER DIGITO
#define S1 BIT2 //CONTROL SEGUNDO DIGITO

volatile unsigned char num[2],switcheo = 0,i=0; //CONTROL DEL DESPLIEGUE DE NUMEROS EN EL 7 SEGMENTOS

void eventos(inputs entradas);

void main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer

    DCOCTL = 0;
    BCSCTL1 = CALBC1_1MHZ;
    DCOCTL = CALDCO_1MHZ;

    //configuracion 7 segmentos

    BCSCTL2 |= SELM_0;
    BCSCTL3 |= LFXT1S_2;
    IFG1 &= ~OFIFG;

    P1DIR = S0 + S1;
    P2DIR = BIT2 + BIT3 + BIT4 + BIT5;
	
	P1OUT = 0; P2OUT = 0;
	P2REN |= BTN + C10 + C25;
	P2OUT |= BTN + C10 + C25;
	P2SEL &= ~BIT6;

    P2IE |= BTN + C10 + C25;
    P2IES &= ~(BTN + C10 + C25);
    P2IFG &= ~(BTN + C10 + C25);

    //CONFIGURACION DEL TIMER PARA EL DESPLIEGUE EN EL 7 SEGMENTOS
    TA1CTL = TASSEL_1 + MC_1;
    TA1CCTL0 = CCIE;
    TA1CCR0 |= 100;

    num[0] = 0; num[1] = 0; //INICIALIZAR EN CERO

    switcheo ^= BIT0; //INICIALIZAR EL DESPLIEGUE EN EL PRIMER DIGITO
    //fin conf 7 segmentos

    //CONFIGURACION LCD
    P1DIR |= (D4 + D5 + D6 + D7 + EN + RS);
    functionset();
    //LCD_ON(); //SI SE QUIERE OBSERVAR EL BLINK DEL CURSOR
    LCDON_BLINKOFF(); //ENCIENDE EL LCD PERO SIN EL BLINK DEL CURSOR

    positionLCD(5);
    WRITE("Hola!");
    positionLCD(17);
    WRITE("Solo 10 y 25 c");

    entradas = 0;
	FSM_Init();
    __bis_SR_register(GIE+LPM0_bits);

}

void eventos(inputs entradas)
{
    //CAMBIA DE ESTADO AL PRESIONAR LOS BOTONES Y SE SUMA LA CANTIDAD INGRESADA O SE REINICIA SI SE PRESIONA EL ÚLTIMO BOTON
    //LA SUMA SE EFECTUA CON LOGICA BCD
    switch(entradas)
    {
    case 0x02:
        FSM_IN_100();
        num[1]++;
        break;
    case 0x01:
        FSM_IN_010();
        num[0] += 5;
        num[1] += 2;
        break;
    case 0x40:
        FSM_IN_001();
        num[0] = 0;
        num[1] = 0;
        break;
    default:
        break;
    }
    if(num[0] > 9)
        {
        num[0] = (num[0] + 6) & 0x0F;
        num[1]++;
        }
    if(num[1] > 9)
    {
        num[1] = 0;
        num[0] = 0;
    }
}

#pragma vector = PORT2_VECTOR
__interrupt void _BTN(void)
{

    entradas = P2IFG & (BTN + C10 + C25);
    eventos(entradas);
    //LIMPIAR BANDER DE INTERRUPCIÓN Y DESHABILITAR INTERRUPCON DEL BOTON
    P2IFG &= ~(BTN + C10 + C25);
    P2IE &= ~(BTN + C10 + C25);

    //CONFIGURACION INTERUPCION DEL PERRO GUARDIAN
    WDTCTL = WDT_ADLY_250;
    IFG1 &= ~WDTIFG;
    IE1 |= WDTIE;
}

#pragma vector = WDT_VECTOR
__interrupt void WDT_debounce(void)
{
    //LIMPIAMOS BANDERA Y DESHABILITAMOS INTERRUPCION DEL PERRO
    IFG1 |= WDTIFG;
    IE1 &= ~WDTIE;
    WDTCTL = WDTPW | WDTHOLD;
    //HABILITAR INTERRUPCION DEL BOTON Y DEBOUNCE ESTÁ COMPLETO
    P2IE |= (BTN + C10 + C25);
}

#pragma vector = TIMER1_A0_VECTOR
__interrupt void timerA1(void)
{
    switcheo ^= BIT0 + BIT1; //ALTERNA EL DEPLIEGUE DEL DÍGITO (LOS TRANSISTORES)
    P2OUT &= ~(0x3C); //LIMPIA EL NUMERO ACTUAL
    P1OUT &= ~(0x06); //PONE EN BAJO LA ENTRADA A LOS TRANSISTORES
    if(switcheo == BIT0)
    {
        P1OUT |= switcheo << 1; //ACTIVA EL DIGITO QUE SE VA A DESPLEGAR
        P2OUT |= (num[0] & 0x0F) << 2; //INGRESA EL NUMERO
    }
    else
    {
        P1OUT |= switcheo << 1;
        P2OUT |= (num[1] & 0x0F) << 2;
    }
}
