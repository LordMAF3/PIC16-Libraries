#include <xc.h>

#ifndef _XTAL_FREQ
#define _XTAL_FREQ 20000000
#endif

char flag=1;
unsigned int timeOn, timeOff;
unsigned short counter=0; 
unsigned char servoPin;

void Servo_Write(unsigned char pin, unsigned char degree){
    servoPin=pin;
    timeOn=50+degree;
    timeOff=1000-timeOn;
    INTCON=0b10100000;
    T0CS=0;
    TMR0=221;
    digitalWrite(pin, 1);
}

void __interrupt() ISR(){
    if(T0IF){
        TMR0=221;
        counter++;
        if(flag==1 && counter==timeOn){ 
            digitalWrite(servoPin, 0);
            counter=0;
            flag=0;
        }
        if(flag==0 && counter==timeOff){ 
            digitalWrite(servoPin, 1);
            counter=0;
            flag=1;
        }
        T0IF=0;
    }
}