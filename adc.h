#ifndef _ADC_H_
#define _ADC_H_

#ifndef _XTAL_FREQ
 #define _XTAL_FREQ 20000000
#endif

#include <xc.h>

char voltageReference=0;

void ADC_Reference(){
    voltageReference=1;
}

void ADC_Init(){
    ADCON1=voltageReference;
    ADCON0bits.ADCS=0b10;
    ADON=1;
}

unsigned char ADC_Read(unsigned char pin){
    ADCON0bits.CHS=pin;
    __delay_ms(5);
    GO_nDONE=1;
    while(GO_nDONE==1);
    return ADRES;
}

#endif //_ADC_H_
/*
ADCON0:
 bit 7-6: 
          || 00: Fosc/2  ||
          || 01: Fosc/8  ||
          || 10: Fosc/32 || <- questa per il quarzo a 20MHz
          || 11: FRC     ||

 bit 5-3: 
          || 000: Channel 0 ||
          || 001: Channel 1 ||
          || 010: Channel 2 ||
          || 011: Channel 3 ||
          || 100: Channel 4 ||
 
 bit 2: GO/DONE
 
 bit 1: unimplemented

 bit 0: ADON

ADCON1:
 bit 7-3: unimplemented
 bit 2-0: 
                  0 1 2 4 3     Vref 
          || 0x0: A A A A A     VDD  ||
          || 0x1: A A A A Vref  RA3  ||   
          || 100: A A D D A     VDD  ||
          || 101: A A D D Vref  RA3  ||
          || 11x: D D D D D     VDD  ||

ADRES:
 bit 7-0: risultato conversione ADC
*/