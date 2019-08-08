#ifndef _XTAL_FREQ
#define _XTAL_FREQ 20000000
#endif

#include <xc.h>

void SPI_Master_Init(){
    TRISC3=0;
    TRISC4=1;
    TRISC5=0;
    SSPSTAT=0b00000000;
    SSPCON=0b00100000;
}

void SPI_Slave_Init(){
    TRISC3=1;
    TRISC4=1;
    TRISC5=0;
    SSPSTAT=0b00000000;
    SSPCON=0b00100101;
}

void SPI_Write(unsigned char data){
    SSPBUF=data;
}

unsigned char SPI_Read(){
    while(!BF);
    return SSPBUF;
}