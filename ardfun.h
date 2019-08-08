#ifndef _ARDFUN_H_
#define _ARDFUN_H_

#include <xc.h>

#define INPUT 1
#define OUTPUT 0
#define HIGH 1
#define LOW 0

void digitalWrite(unsigned char port, unsigned char val){
    if(port>=1 && port<=6){
        if(port==1){
            PORTAbits.RA0=val;
        }
        else if(port==2){
            PORTAbits.RA1=val;
        }
        else if(port==3){
            PORTAbits.RA2=val;
        }
        else if(port==4){
            PORTAbits.RA3=val;
        }
        else if(port==5){
            PORTAbits.RA4=val;
        }
        else if(port==6){
            PORTAbits.RA5=val;
        }
    }
    else if(port>=7 && port<=14){
        if(port==7){
            PORTBbits.RB0=val;
        }
        else if(port==8){
            PORTBbits.RB1=val;
        }
        else if(port==9){
            PORTBbits.RB2=val;
        }
        else if(port==10){
            PORTBbits.RB3=val;
        }
        else if(port==11){
            PORTBbits.RB4=val;
        }
        else if(port==12){
            PORTBbits.RB5=val;
        }
        else if(port==13){
            PORTBbits.RB6=val;
        }
        else if(port==14){
            PORTBbits.RB7=val;
        }
    }
    else if(port>=15 && port<=22){
        if(port==15){
            PORTCbits.RC0=val;
        }
        else if(port==16){
            PORTCbits.RC1=val;
        }
        else if(port==17){
            PORTCbits.RC2=val;
        }
        else if(port==18){
            PORTCbits.RC3=val;
        }
        else if(port==19){
            PORTCbits.RC4=val;
        }
        else if(port==20){
            PORTCbits.RC5=val;
        }
        else if(port==21){
            PORTCbits.RC6=val;
        }
        else if(port==22){
            PORTCbits.RC7=val;
        }
    }
}

void pinMode(unsigned char port, unsigned char val){
    if(port>=1 && port<=6){
        if(port==1){
            TRISAbits.TRISA0=val;
        }
        else if(port==2){
            TRISAbits.TRISA1=val;
        }
        else if(port==3){
            TRISAbits.TRISA2=val;
        }
        else if(port==4){
            TRISAbits.TRISA3=val;
        }
        else if(port==5){
            TRISAbits.TRISA4=val;
        }
        else if(port==6){
            TRISAbits.TRISA5=val;
        }
    }
    else if(port>=7 && port<=14){
        if(port==7){
            TRISBbits.TRISB0=val;
        }
        else if(port==8){
            TRISBbits.TRISB1=val;
        }
        else if(port==9){
            TRISBbits.TRISB2=val;
        }
        else if(port==10){
            TRISBbits.TRISB3=val;
        }
        else if(port==11){
            TRISBbits.TRISB4=val;
        }
        else if(port==12){
            TRISBbits.TRISB5=val;
        }
        else if(port==13){
            TRISBbits.TRISB6=val;
        }
        else if(port==14){
            TRISBbits.TRISB7=val;
        }
    }
    else if(port>=15 && port<=22){
        if(port==15){
            TRISCbits.TRISC0=val;
        }
        else if(port==16){
            TRISCbits.TRISC1=val;
        }
        else if(port==17){
            TRISCbits.TRISC2=val;
        }
        else if(port==18){
            TRISCbits.TRISC3=val;
        }
        else if(port==19){
            TRISCbits.TRISC4=val;
        }
        else if(port==20){
            TRISCbits.TRISC5=val;
        }
        else if(port==21){
            TRISCbits.TRISC6=val;
        }
        else if(port==22){
            TRISCbits.TRISC7=val;
        }
    }
}

#endif //_ARDFUN_H_

/*
1: A0
2: A1
3: A2
4: A3
5: A4
6: A5
7: B0
8: B1
9: B2
10: B3
11: B4
12: B5
13: B6
14: B7
15: C0 
16: C1
17: C2
18: C3
19: C4
20: C5
21: C6
22: C7
*/