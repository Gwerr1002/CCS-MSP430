#include <msp430g2553.h>


#define LED_V BIT0
#define LED_R BIT6
#define BTN   BIT3
#define BTN_E BIT1
#define BLUE BIT5
#define GREEN BIT3
#define RED BIT1

volatile unsigned char ibtn=0, ibtne=0, a[2]; //CONTADOR DE LOS BOTONES
//LAS SIGUIENTES LINEAS SON PARA HACER TRANSICIONES DE COLOR
#define T 1000
#define DUTY 9 //EN PORCENTAJE (900/100)

volatile short C1[3], C2[3], C3[3]; //VARIABLES QUE GUARDAN UN COLOR, SE LES ASIGNA VALOR EN EL MAIN

void RGB(volatile short r,volatile short g,volatile short b); //PROCEDIMIENTO PARA LA MODULACION DE PULSO
void delay(volatile short ciclos);
void transicion(volatile short A[3], volatile short B[3]); //TRANSICION DE COLOR

void main(void)
{
    a[1] = 1;
    //SE ASIGNAN COLORES DESEADOS PARA REALIZAR TRANSICIÓN DE COLOR
    C1[0]=75; C1[1]=20; C1[2]=5; //NARANJA
    C2[0]=20; C2[1]=11; C2[2]=69; //LILA
    C3[0]=30; C3[1]=65; C3[2]=5; //VERDE AMARILLENTO

    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    if (CALBC1_1MHZ == 0xFF){
        while(1);
    }
    //CONFIGURACION DEL RELOJ PARA EL PWM
    DCOCTL = 0;
    BCSCTL1 = CALBC1_1MHZ;
    DCOCTL = CALDCO_1MHZ;

    P1OUT = 0;  P2OUT = 0;
    P1DIR |= LED_V | LED_R;
    P2DIR |= RED | GREEN | BLUE;

    //HABILITAMOS LOS BOTONES
    P1IE |= BTN | BTN_E; //IE INTERRUPT ENABLE

    // CONFIGURACION FLANCO DE SUBIDA
    P1IES &= ~(BTN | BTN_E);

    //RESISTENCIA PULL UP
    P1REN |= BTN | BTN_E;
    P1OUT |= BTN | BTN_E;

    //LIMPIAR LA BANDERA DE INTERRUPCION
    P1IFG &= ~(BTN | BTN_E);

    //GIE GLOBAL INTERRUPT ENABLE
    while((ibtn < 3) || ibtne < 3){
    __bis_SR_register(LPM4_bits + GIE);
    __delay_cycles(50000);
    P1OUT &= ~(LED_V | LED_R);
    __delay_cycles(50000);
    }

    P1IE &= ~(BTN | BTN_E);
    P1OUT &= ~(LED_V | LED_R);

    //PROCEDIMIENTO DE SALIDA: SE HACE UNA TRANSICION DE NARANJA-LILA-VERDE AMARILLENTO-NARANJA. SE REPITE LA SECUENCIA DE 3 SEG
    volatile short i;
    while(1){
    for(i=100;i>0;i--){RGB(C1[0],C1[1],C1[2]);}
    transicion(C1,C2);
    for(i=100;i>0;i--){RGB(C2[0],C2[1],C2[2]);}
    transicion(C2,C3);
    for(i=100;i>0;i--){RGB(C3[0],C3[1],C3[2]);}
    P2OUT &= ~(RED | GREEN | BLUE);
    transicion(C3,C2);
    transicion(C2,C1);
    }
}

#pragma vector = PORT1_VECTOR
__interrupt void secuencia(void)
{
    a[0] = a[1];
    switch (a[1]){
    case 0:
        if((P1IFG & BTN_E) == BTN_E){
            P1IFG &= ~BTN; a[1] = 1;
            if(a[0] != a[1]){ibtne++;}
        }
    break;

    case 1:
        if((P1IFG & BTN) == BTN){
            P1IFG &= ~BTN_E; a[1] = 0;
            if(a[0] != a[1]){ibtn++;}
        }
    break;
    }

    if((ibtn < 3) || (ibtne < 3)){
        if((P1IFG & BTN) == BTN){P1OUT |= LED_V;}
        if((P1IFG & BTN_E) == BTN_E){P1OUT |= LED_R;}
    }
    __bic_SR_register_on_exit(LPM4_bits + GIE);

}

void delay(volatile short ciclos){
    volatile short i;
    for(i=ciclos;i>0;i--) __delay_cycles(1);
}

void RGB(volatile short r,volatile short g,volatile short b){//LAS VARIABLES DECLARADAS SON LOS PORCENTAJES A LOS QUE DEBE ENCENDER CADA LED DEL RGB
    P2OUT ^= BLUE;
    delay(DUTY*(b));
    P2OUT ^= BLUE;
    P2OUT ^= RED;
    delay(DUTY*(r));
    P2OUT ^= RED;
    P2OUT ^= GREEN;
    delay(DUTY*(g));
    P2OUT ^= GREEN;
    delay(T-DUTY*100); //EL 10% DEL CICLO APROX
}

void transicion(volatile short A[3], volatile short B[3]){

    volatile short r, g, b, END = 0;
    r = A[0]; g = A[1]; b = A[2];

    if((A[0] > B[0]) && (A[1] > B[1])){
        while(END == 0){
            if(r > B[0]){r--;}
            if(g > B[1]){g--;}
            b = 100 - (r + g);
            if(b == B[2]){END = 1;}
            RGB(r,g,b);
        }
    }
    if((A[0] > B[0]) && (B[1] > A[1])){
        while(END == 0){
            if(r > B[0]){r--;}
            if(g < B[1]){g++;}
            b = 100 - (r + g);
            if(b == B[2]){END = 1;}
            RGB(r,g,b);
        }
    }
    if((B[0] > A[0]) && (A[1] > B[1])){
        while(END == 0){
            if(r < B[0]){r++;}
            if(g > B[1]){g--;}
            b = 100 - (r + g);
            if(b == B[2]){END = 1;}
            RGB(r,g,b);
        }
    }
    if((B[0] > A[0]) && (B[1] > A[1])){
        while(END == 0){
            if(r < B[0]){r++;}
            if(g < B[1]){g++;}
            b = 100 - (r + g);
            if(b == B[2]){END = 1;}
            RGB(r,g,b);
        }
    }

}
