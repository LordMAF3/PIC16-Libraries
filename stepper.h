#ifndef _STEPPER_H_
#define _STEPPER_H_

#ifndef _XTAL_FREQ
#define _XTAL_FREQ 20000000
#endif

#include <xc.h>
#include <ardfun.h>

#define STEPS_PER_ROUND 2048
#define clockwise 1
#define anticlockwise 0

typedef struct Stepper{
    unsigned char pin1; 
    unsigned char pin2; 
    unsigned char pin3; 
    unsigned char pin4; 
    char direction; 
    float rpm;
    unsigned int steps;
} Stepper;

void msDelay(int ms){
    int i;
    for(i=0; i<ms; i++){
        __delay_ms(1);
    }
}

void setSpeed(Stepper* stepper, float speed){
    stepper->rpm=speed;
}

void setDirection(Stepper* stepper, char dir){
    stepper->direction=dir;
}

void setStepsNum(Stepper* stepper, unsigned int step){
    stepper->steps=step;
}

void stepperGo(Stepper* mt){
    /* Step  Blue Pink Yellow Orange
       1	 1	  1    0	  0
       2	 0	  1	   1	  0
       3	 0	  0	   1	  1
       4	 1	  0	   0	  1 */
    int delayTime=(float)1000/((mt->rpm*STEPS_PER_ROUND)/60);
    if(mt->direction==clockwise){
        for(int i=0; i<mt->steps; i+=4){
            digitalWrite(mt->pin1, 1); 
            digitalWrite(mt->pin2, 1); 
            digitalWrite(mt->pin3, 0); 
            digitalWrite(mt->pin4, 0); 
            msDelay(delayTime);
            digitalWrite(mt->pin1, 0); 
            digitalWrite(mt->pin2, 1); 
            digitalWrite(mt->pin3, 1); 
            digitalWrite(mt->pin4, 0); 
            msDelay(delayTime);
            digitalWrite(mt->pin1, 0); 
            digitalWrite(mt->pin2, 0); 
            digitalWrite(mt->pin3, 1); 
            digitalWrite(mt->pin4, 1); 
            msDelay(delayTime);
            digitalWrite(mt->pin1, 1); 
            digitalWrite(mt->pin2, 0); 
            digitalWrite(mt->pin3, 0); 
            digitalWrite(mt->pin4, 1); 
            msDelay(delayTime);
        }
    }
    else if(mt->direction==anticlockwise){
        for(int i=0; i<mt->steps; i+=4){   
            digitalWrite(mt->pin1, 1); 
            digitalWrite(mt->pin2, 0);
            digitalWrite(mt->pin3, 0); 
            digitalWrite(mt->pin4, 1); 
            msDelay(delayTime);
            digitalWrite(mt->pin1, 0); 
            digitalWrite(mt->pin2, 0); 
            digitalWrite(mt->pin3, 1); 
            digitalWrite(mt->pin4, 1);
            msDelay(delayTime);
            digitalWrite(mt->pin1, 0); 
            digitalWrite(mt->pin2, 1); 
            digitalWrite(mt->pin3, 1); 
            digitalWrite(mt->pin4, 0);
            msDelay(delayTime);
            digitalWrite(mt->pin1, 1);
            digitalWrite(mt->pin2, 1); 
            digitalWrite(mt->pin3, 0); 
            digitalWrite(mt->pin4, 0);
            msDelay(delayTime);
        }
    }
}

#endif //_STEPPER_H_