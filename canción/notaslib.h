/*
 * notaslib.h
 *
 *  Created on: 25 ago. 2021
 *      Author: gerard
 */

#ifndef NOTASLIB_H_
#define NOTASLIB_H_

void DO1(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
    P1OUT ^= BIT1;
    __delay_cycles(7645);
    P1OUT ^= BIT1;
    __delay_cycles(7645);}
}
void DO2(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
    P1OUT ^= BIT1;
    __delay_cycles(3822);
    P1OUT ^= BIT1;
    __delay_cycles(3822);}
}
void DO3(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
    P1OUT ^= BIT1;
    __delay_cycles(1911);
    P1OUT ^= BIT1;
    __delay_cycles(1911);}
}
void DO4(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
    P1OUT ^= BIT1;
    __delay_cycles(955);
    P1OUT ^= BIT1;
    __delay_cycles(955);}
}
void DO5(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
    P1OUT ^= BIT1;
    __delay_cycles(477);
    P1OUT ^= BIT1;
    __delay_cycles(477);}
}
void DO6(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
    P1OUT ^= BIT1;
    __delay_cycles(238);
    P1OUT ^= BIT1;
    __delay_cycles(238);}
}
void DO7(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
    P1OUT ^= BIT1;
    __delay_cycles(119);
    P1OUT ^= BIT1;
    __delay_cycles(119);}
}
void DO8(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
    P1OUT ^= BIT1;
    __delay_cycles(59);
    P1OUT ^= BIT1;
    __delay_cycles(59);}
}
void DOSOS1(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
    P1OUT ^= BIT1;
    __delay_cycles(7215);
    P1OUT ^= BIT1;
    __delay_cycles(7215);}
}
void DOSOS2(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
    P1OUT ^= BIT1;
    __delay_cycles(3607);
    P1OUT ^= BIT1;
    __delay_cycles(3607);}
}
void DOSOS3(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
    P1OUT ^= BIT1;
    __delay_cycles(1803);
    P1OUT ^= BIT1;
    __delay_cycles(1803);}
}
void DOSOS4(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
    P1OUT ^= BIT1;
    __delay_cycles(901);
    P1OUT ^= BIT1;
    __delay_cycles(901);}
}
void DOSOS5(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
    P1OUT ^= BIT1;
    __delay_cycles(451);
    P1OUT ^= BIT1;
    __delay_cycles(451);}
}
void DOSOS6(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
    P1OUT ^= BIT1;
    __delay_cycles(225);
    P1OUT ^= BIT1;
    __delay_cycles(225);}
}
void DOSOS7(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
    P1OUT ^= BIT1;
    __delay_cycles(113);
    P1OUT ^= BIT1;
    __delay_cycles(113);}
}
void DOSOS8(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
    P1OUT ^= BIT1;
    __delay_cycles(56);
    P1OUT ^= BIT1;
    __delay_cycles(56);}
}

void RE1(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
    P1OUT ^= BIT1;
    __delay_cycles(6810);
    P1OUT ^= BIT1;
    __delay_cycles(6810);}
}
void RE2(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
    P1OUT ^= BIT1;
    __delay_cycles(3405);
    P1OUT ^= BIT1;
    __delay_cycles(3405);}
}
void RE3(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
    P1OUT ^= BIT1;
    __delay_cycles(1703);
    P1OUT ^= BIT1;
    __delay_cycles(1703);}
}
void RE4(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
    P1OUT ^= BIT1;
    __delay_cycles(851);
    P1OUT ^= BIT1;
    __delay_cycles(851);}
}
void RE5(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
    P1OUT ^= BIT1;
    __delay_cycles(425);
    P1OUT ^= BIT1;
    __delay_cycles(425);}
}
void RE6(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
    P1OUT ^= BIT1;
    __delay_cycles(212);
    P1OUT ^= BIT1;
    __delay_cycles(212);}
}
void RE7(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
    P1OUT ^= BIT1;
    __delay_cycles(106);
    P1OUT ^= BIT1;
    __delay_cycles(106);}
}
void RE8(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
    P1OUT ^= BIT1;
    __delay_cycles(53);
    P1OUT ^= BIT1;
    __delay_cycles(53);}
}

void RESOS1(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
        P1OUT ^= BIT1;
    __delay_cycles(6428);
    P1OUT ^= BIT1;
    __delay_cycles(6428);}
}
void RESOS2(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
        P1OUT ^= BIT1;
    __delay_cycles(3214);
    P1OUT ^= BIT1;
    __delay_cycles(3214);}
}
void RESOS3(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
        P1OUT ^= BIT1;
    __delay_cycles(1607);
    P1OUT ^= BIT1;
    __delay_cycles(1607);}
}
void RESOS4(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
        P1OUT ^= BIT1;
    __delay_cycles(803);
    P1OUT ^= BIT1;
    __delay_cycles(803);}
}
void RESOS5(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
        P1OUT ^= BIT1;
    __delay_cycles(401);
    P1OUT ^= BIT1;
    __delay_cycles(401);}
}
void RESOS6(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
        P1OUT ^= BIT1;
    __delay_cycles(201);
    P1OUT ^= BIT1;
    __delay_cycles(201);}
}
void RESOS7(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
        P1OUT ^= BIT1;
    __delay_cycles(100);
    P1OUT ^= BIT1;
    __delay_cycles(100);}
}
void RESOS8(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
        P1OUT ^= BIT1;
    __delay_cycles(100);
    P1OUT ^= BIT1;
    __delay_cycles(100);}
}

void MI1(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
    P1OUT ^= BIT1;
    __delay_cycles(6067);
    P1OUT ^= BIT1;
    __delay_cycles(6067);}
}
void MI2(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
    P1OUT ^= BIT1;
    __delay_cycles(3033);
    P1OUT ^= BIT1;
    __delay_cycles(3033);}
}
void MI3(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
    P1OUT ^= BIT1;
    __delay_cycles(1516);
    P1OUT ^= BIT1;
    __delay_cycles(1516);}
}
void MI4(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
    P1OUT ^= BIT1;
    __delay_cycles(758);
    P1OUT ^= BIT1;
    __delay_cycles(758);}
}
void MI5(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
    P1OUT ^= BIT1;
    __delay_cycles(379);
    P1OUT ^= BIT1;
    __delay_cycles(379);}
}
void MI6(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
    P1OUT ^= BIT1;
    __delay_cycles(189);
    P1OUT ^= BIT1;
    __delay_cycles(189);}
}
void MI7(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
    P1OUT ^= BIT1;
    __delay_cycles(94);
    P1OUT ^= BIT1;
    __delay_cycles(94);}
}
void MI8(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
    P1OUT ^= BIT1;
    __delay_cycles(47);
    P1OUT ^= BIT1;
    __delay_cycles(47);}
}

void FA1(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
    P1OUT ^= BIT1;
    __delay_cycles(6067);
    P1OUT ^= BIT1;
    __delay_cycles(6067);}
}
void FA2(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
    P1OUT ^= BIT1;
    __delay_cycles(2863);
    P1OUT ^= BIT1;
    __delay_cycles(2863);}
}
void FA3(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
    P1OUT ^= BIT1;
    __delay_cycles(1431);
    P1OUT ^= BIT1;
    __delay_cycles(1431);}
}
void FA4(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
    P1OUT ^= BIT1;
    __delay_cycles(716);
    P1OUT ^= BIT1;
    __delay_cycles(716);}
}
void FA5(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
    P1OUT ^= BIT1;
    __delay_cycles(357);
    P1OUT ^= BIT1;
    __delay_cycles(357);}
}
void FA6(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
    P1OUT ^= BIT1;
    __delay_cycles(179);
    P1OUT ^= BIT1;
    __delay_cycles(179);}
}
void FA7(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
    P1OUT ^= BIT1;
    __delay_cycles(89);
    P1OUT ^= BIT1;
    __delay_cycles(89);}
}
void FA8(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
    P1OUT ^= BIT1;
    __delay_cycles(45);
    P1OUT ^= BIT1;
    __delay_cycles(45);}
}

void FASOS1(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
    P1OUT ^= BIT1;
    __delay_cycles(5405);
    P1OUT ^= BIT1;
    __delay_cycles(5405);}
}
void FASOS2(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
    P1OUT ^= BIT1;
    __delay_cycles(2702);
    P1OUT ^= BIT1;
    __delay_cycles(2702);}
}
void FASOS3(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
    P1OUT ^= BIT1;
    __delay_cycles(1351);
    P1OUT ^= BIT1;
    __delay_cycles(1351);}
}
void FASOS4(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
    P1OUT ^= BIT1;
    __delay_cycles(675);
    P1OUT ^= BIT1;
    __delay_cycles(675);}
}
void FASOS5(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
    P1OUT ^= BIT1;
    __delay_cycles(338);
    P1OUT ^= BIT1;
    __delay_cycles(338);}
}
void FASOS6(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
    P1OUT ^= BIT1;
    __delay_cycles(169);
    P1OUT ^= BIT1;
    __delay_cycles(169);}
}
void FASOS7(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
    P1OUT ^= BIT1;
    __delay_cycles(84);
    P1OUT ^= BIT1;
    __delay_cycles(84);}
}
void FASOS8(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
    P1OUT ^= BIT1;
    __delay_cycles(42);
    P1OUT ^= BIT1;
    __delay_cycles(42);}
}


void SOL1(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
        P1OUT ^= BIT1;
    __delay_cycles(5102);
    P1OUT ^= BIT1;
    __delay_cycles(5102);}
}
void SOL2(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
        P1OUT ^= BIT1;
    __delay_cycles(2551);
    P1OUT ^= BIT1;
    __delay_cycles(2551);}
}
void SOL3(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
        P1OUT ^= BIT1;
    __delay_cycles(1275);
    P1OUT ^= BIT1;
    __delay_cycles(1275);}
}
void SOL4(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
        P1OUT ^= BIT1;
    __delay_cycles(637);
    P1OUT ^= BIT1;
    __delay_cycles(637);}
}
void SOL5(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
        P1OUT ^= BIT1;
    __delay_cycles(318);
    P1OUT ^= BIT1;
    __delay_cycles(218);}
}
void SOL6(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
        P1OUT ^= BIT1;
    __delay_cycles(159);
    P1OUT ^= BIT1;
    __delay_cycles(159);}
}
void SOL7(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
        P1OUT ^= BIT1;
    __delay_cycles(80);
    P1OUT ^= BIT1;
    __delay_cycles(80);}
}
void SOL8(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
        P1OUT ^= BIT1;
    __delay_cycles(40);
    P1OUT ^= BIT1;
    __delay_cycles(40);}
}

void SOLSOS1(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
        P1OUT ^= BIT1;
    __delay_cycles(4815);
    P1OUT ^= BIT1;
    __delay_cycles(4815);}
}
void SOLSOS2(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
        P1OUT ^= BIT1;
    __delay_cycles(2407);
    P1OUT ^= BIT1;
    __delay_cycles(2407);}
}
void SOLSOS3(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
        P1OUT ^= BIT1;
    __delay_cycles(1203);
    P1OUT ^= BIT1;
    __delay_cycles(1203);}
}
void SOLSOS4(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
        P1OUT ^= BIT1;
    __delay_cycles(602);
    P1OUT ^= BIT1;
    __delay_cycles(602);}
}
void SOLSOS5(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
        P1OUT ^= BIT1;
    __delay_cycles(301);
    P1OUT ^= BIT1;
    __delay_cycles(301);}
}
void SOLSOS6(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
        P1OUT ^= BIT1;
    __delay_cycles(150);
    P1OUT ^= BIT1;
    __delay_cycles(150);}
}
void SOLSOS7(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
        P1OUT ^= BIT1;
    __delay_cycles(75);
    P1OUT ^= BIT1;
    __delay_cycles(75);}
}
void SOLSOS8(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
        P1OUT ^= BIT1;
    __delay_cycles(37);
    P1OUT ^= BIT1;
    __delay_cycles(37);}
}

void LA1(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
        P1OUT ^= BIT1;
    __delay_cycles(4545);
    P1OUT ^= BIT1;
    __delay_cycles(4545);}
}
void LA2(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
        P1OUT ^= BIT1;
    __delay_cycles(2272);
    P1OUT ^= BIT1;
    __delay_cycles(2272);}
}
void LA3(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
        P1OUT ^= BIT1;
    __delay_cycles(1136);
    P1OUT ^= BIT1;
    __delay_cycles(1136);}
}
void LA4(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
        P1OUT ^= BIT1;
    __delay_cycles(568);
    P1OUT ^= BIT1;
    __delay_cycles(568);}
}
void LA5(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
        P1OUT ^= BIT1;
    __delay_cycles(284);
    P1OUT ^= BIT1;
    __delay_cycles(284);}
}
void LA6(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
        P1OUT ^= BIT1;
    __delay_cycles(142);
    P1OUT ^= BIT1;
    __delay_cycles(142);}
}
void LA7(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
        P1OUT ^= BIT1;
    __delay_cycles(71);
    P1OUT ^= BIT1;
    __delay_cycles(71);}
}
void LA8(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
        P1OUT ^= BIT1;
    __delay_cycles(35);
    P1OUT ^= BIT1;
    __delay_cycles(35);}
}

void LASOS1(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
        P1OUT ^= BIT1;
    __delay_cycles(4290);
    P1OUT ^= BIT1;
    __delay_cycles(4290);}
}
void LASOS2(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
        P1OUT ^= BIT1;
    __delay_cycles(2145);
    P1OUT ^= BIT1;
    __delay_cycles(2145);}
}
void LASOS3(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
        P1OUT ^= BIT1;
    __delay_cycles(1072);
    P1OUT ^= BIT1;
    __delay_cycles(2072);}
}
void LASOS4(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
        P1OUT ^= BIT1;
    __delay_cycles(536);
    P1OUT ^= BIT1;
    __delay_cycles(536);}
}
void LASOS5(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
        P1OUT ^= BIT1;
    __delay_cycles(268);
    P1OUT ^= BIT1;
    __delay_cycles(268);}
}
void LASOS6(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
        P1OUT ^= BIT1;
    __delay_cycles(134);
    P1OUT ^= BIT1;
    __delay_cycles(134);}
}
void LASOS7(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
        P1OUT ^= BIT1;
    __delay_cycles(67);
    P1OUT ^= BIT1;
    __delay_cycles(67);}
}
void LASOS8(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
        P1OUT ^= BIT1;
    __delay_cycles(33);
    P1OUT ^= BIT1;
    __delay_cycles(33);}
}

void SI1(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
        P1OUT ^= BIT1;
    __delay_cycles(4049);
    P1OUT ^= BIT1;
    __delay_cycles(4049);}
}
void SI2(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
        P1OUT ^= BIT1;
    __delay_cycles(2024);
    P1OUT ^= BIT1;
    __delay_cycles(2024);}
}
void SI3(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
        P1OUT ^= BIT1;
    __delay_cycles(1012);
    P1OUT ^= BIT1;
    __delay_cycles(1012);}
}
void SI4(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
        P1OUT ^= BIT1;
    __delay_cycles(506);
    P1OUT ^= BIT1;
    __delay_cycles(506);}
}
void SI5(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
        P1OUT ^= BIT1;
    __delay_cycles(253);
    P1OUT ^= BIT1;
    __delay_cycles(253);}
}
void SI6(int tiempo){
    int i;
    for(i=tiempo;i>0;i--){
        P1OUT ^= BIT1;
    __delay_cycles(127);
    P1OUT ^= BIT1;
    __delay_cycles(127);}
}



#endif /* NOTASLIB_H_ */
