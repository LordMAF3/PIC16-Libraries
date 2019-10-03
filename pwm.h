<<<<<<< HEAD
#ifndef _PWM_H_
#define _PWM_H_

#ifndef _XTAL_FREQ
#define _XTAL_FREQ 20000000
#endif

#include <xc.h>

void PWM_Init(unsigned char pin, unsigned long frequenza, unsigned char dutyCycleP){
    unsigned char prescaler=1; 
    unsigned char i=0;
    unsigned int PR2val=((float)_XTAL_FREQ/(4*frequenza*prescaler))+1; //Frequenza (formula nel datasheet)
    while(PR2val>=255) { //se il valore della frequenza non è ancora di 8 bit (grandezza del registro)
        i++;
        prescaler*=4;
        PR2val=((float)_XTAL_FREQ/(4*frequenza*prescaler))+1;
    }
    PR2=PR2val;
    T2CON=4+i; //bit 2: TMR2ON 
    //bit 0-1: PRESCALER |00: 1 | |01:4| |1x: 16|
    
    if(pin==1){
        TRISCbits.TRISC2=0;
        CCPR1L=(float)PR2val/((float)100/dutyCycleP); //Duty cycle rispetto a PR2
        CCP1CON=0x00; //PWM OFF
    }
    if(pin==2){
        TRISCbits.TRISC1=0;
        CCPR2L=(float)PR2val/((float)100/dutyCycleP); //Duty cycle rispetto a PR2
        CCP2CON=0x00; //PWM OFF
    }
}

void PWM_Start(unsigned char pin){
    if(pin==1){
        CCP1CON=0x0F;
    }
    if(pin==2){
        CCP2CON=0x0F;
    }
}

void PWM_Stop(unsigned char pin){
    if(pin==1){
        CCP1CON=0x00;
    }
    if(pin==2){
        CCP2CON=0x00;
    }
}

=======
#ifndef _PWM_H_
#define _PWM_H_

#ifndef _XTAL_FREQ
#define _XTAL_FREQ 20000000
#endif

#include <xc.h>

void PWM_Init(unsigned char pin, unsigned long frequenza, unsigned char dutyCycleP){
    unsigned char prescaler=1; 
    unsigned char i=0;
    unsigned int PR2val=((float)_XTAL_FREQ/(4*frequenza*prescaler))+1; //Frequenza (formula nel datasheet)
    while(PR2val>=255) { //se il valore della frequenza non è ancora di 8 bit (grandezza del registro)
        i++;
        prescaler*=4;
        PR2val=((float)_XTAL_FREQ/(4*frequenza*prescaler))+1;
    }
    PR2=PR2val;
    T2CON=4+i; //bit 2: TMR2ON 
    //bit 0-1: PRESCALER |00: 1 | |01:4| |1x: 16|
    
    if(pin==1){
        TRISCbits.TRISC2=0;
        CCPR1L=(float)PR2val/((float)100/dutyCycleP); //Duty cycle rispetto a PR2
        CCP1CON=0x00; //PWM OFF
    }
    if(pin==2){
        TRISCbits.TRISC1=0;
        CCPR2L=(float)PR2val/((float)100/dutyCycleP); //Duty cycle rispetto a PR2
        CCP2CON=0x00; //PWM OFF
    }
}

void PWM_Start(unsigned char pin){
    if(pin==1){
        CCP1CON=0x0F;
    }
    if(pin==2){
        CCP2CON=0x0F;
    }
}

void PWM_Stop(unsigned char pin){
    if(pin==1){
        CCP1CON=0x00;
    }
    if(pin==2){
        CCP2CON=0x00;
    }
}

>>>>>>> 70e902ef07ae7b6138cdf5acc7966ae593a5ac45
#endif //_PWM_H_