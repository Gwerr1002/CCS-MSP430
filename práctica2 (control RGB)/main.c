#include <msp430g2553.h>

#define LED_R BIT6
#define BLUE BIT5
#define GREEN BIT3
#define RED BIT1
#define BTN BIT3
#define BTN_E BIT1
#define T 1000
#define DUTY 9 //EN PORCENTAJE (900/100)

void trc(unsigned long b,unsigned long r,unsigned long g);
void delay(unsigned long ciclos);

void main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer

    if (CALBC1_1MHZ == 0xFF){
        while(1);
    }
    DCOCTL = 0;
    BCSCTL1 = CALBC1_1MHZ;
    DCOCTL = CALDCO_1MHZ;

	P1OUT = 0; P2OUT = 0;
	P1DIR = LED_R;
	P2DIR = GREEN | RED | BLUE;
	//CONFIGURANDO BOTON EN MODO PULL UP
	P1REN |= BTN | BTN_E;
	P1OUT |= BTN | BTN_E;
	//ENCIENDE LED ROJO
	P1OUT ^= LED_R;
	//APAGANDO AL PRESIONAR P1.3
	while((P1IN & BTN ) == BTN);
	while((P1IN & BTN ) != BTN);
	P1OUT ^= LED_R;

  while(1){

	unsigned long B = 1, R = 80, G = 19; //FORMA COLOR NARANJA
	while((P1IN & BTN_E ) == BTN_E){
	    trc(B,R,G);
	}
	while((P1IN & BTN_E) != BTN_E){
	 trc(B,R,G);
	}
	//TRANCICION DE NARANJA A LILA AL PRESIONAR EL BOTON EXTERNO (P1.1)
	unsigned int end = 0;
	trc(B,R,G);
	while(end == 0){
	    if(B < 70){B = B+1;}
	    if((G > 10) && (B >= 60)){G = G-1;}
	    if((R > 20) && (B >= 10)){R = R-1;}
	    if(G == 10){end = 1;}
	    trc(B,R,G);
	}

	while((P1IN & BTN ) == BTN){
	    trc(B,R,G);
	 }
	while((P1IN & BTN ) != BTN){
	    trc(B,R,G);
	}
	trc(B,R,G);
	//TRANSICION DE LILA A NARANJA AL PRESIONAR P1.3
	end=0;
	while(end == 0){
	     if(B > 1){B = B-1;}
	     if((G < 19) && (B <= 10)){G = G+1;}
	     if((R < 80) && (B <= 61)){R = R+1;}
	     if(G == 19){end = 1;}
	     trc(B,R,G);
	 }
  }
}

void delay(unsigned long ciclos){
    volatile unsigned long i;
    for(i=ciclos;i>0;i--) __delay_cycles(1);
}

void trc(unsigned long b,unsigned long r,unsigned long g){//LAS VARIABLES DECLARADAS SON LOS PORCENTAJES A LOS QUE DEBE ENCENDER CADA LED DEL RGB
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
