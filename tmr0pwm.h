<<<<<<< HEAD
#ifndef _TMR0PWM_H_
#define _TMR0PWM_H_

#ifndef _XTAL_FREQ
#define _XTAL_FREQ 20000000
#endif

#include <xc.h>

#define MAX_FREQ 39370

#ifndef PWMpin 
 #define PWMpin RB0
#endif

unsigned int cycles;
unsigned short timer=0;
float dutyCycle;
char flag=1;
unsigned int cyclesOn;
unsigned int cyclesOff;


void TMR0PWM_Init(unsigned int freq, unsigned char dutyCycleP){
    cycles=(float)MAX_FREQ/freq;
    dutyCycle=(float)dutyCycleP/100;
    cyclesOn=(float)cycles*dutyCycle;
    cyclesOff=cycles-cyclesOn;
    INTCON=0b10100000;
    T0CS=0;
    TMR0=127;
}


void __interrupt() ISR(void){
    if(T0IF){
        TMR0=127;
        timer++;
        if(flag && timer>=cyclesOn+3){ //aggiustato
            PWMpin=0;
            timer=0;
            flag=0;
        }
        if(!flag && timer>=cyclesOff){
            PWMpin=1;
            timer=0;
            flag=1;
        }
        T0IF=0;
    }
}

=======
#ifndef _TMR0PWM_H_
#define _TMR0PWM_H_

#ifndef _XTAL_FREQ
#define _XTAL_FREQ 20000000
#endif

#include <xc.h>

#define MAX_FREQ 39370

#ifndef PWMpin 
 #define PWMpin RB0
#endif

unsigned int cycles;
unsigned short timer=0;
float dutyCycle;
char flag=1;
unsigned int cyclesOn;
unsigned int cyclesOff;


void TMR0PWM_Init(unsigned int freq, unsigned char dutyCycleP){
    cycles=(float)MAX_FREQ/freq;
    dutyCycle=(float)dutyCycleP/100;
    cyclesOn=(float)cycles*dutyCycle;
    cyclesOff=cycles-cyclesOn;
    INTCON=0b10100000;
    T0CS=0;
    TMR0=127;
}


void __interrupt() ISR(void){
    if(T0IF){
        TMR0=127;
        timer++;
        if(flag && timer>=cyclesOn+3){ //aggiustato
            PWMpin=0;
            timer=0;
            flag=0;
        }
        if(!flag && timer>=cyclesOff){
            PWMpin=1;
            timer=0;
            flag=1;
        }
        T0IF=0;
    }
}

>>>>>>> 70e902ef07ae7b6138cdf5acc7966ae593a5ac45
#endif //_TMR0PWM_H_