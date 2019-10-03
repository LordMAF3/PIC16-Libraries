<<<<<<< HEAD
#ifndef _USART_H_
#define _USART_H_

#ifndef _XTAL_FREQ
#define _XTAL_FREQ 20000000
#endif

#include <xc.h>

//char recivedByte;
//int interruptRaised=0;

void TXInit(){
    TRISCbits.TRISC6=1;
    TRISCbits.TRISC7=1;
    SPEN=1;
    SYNC=0;
    BRGH=1;
    SPBRG=129; //<- baudrate 9600 (datasheet)
    TXEN=1;
    TX9=0;
}

void TXWriteChar(char data){
    while(!TRMT);
    TXREG=data;
}

void TXWrite(char* string){
    int i=0;
    while(string[i]!='\0'){
        TXWriteChar(string[i]);
        i++;
    }
}

void RXInit(){
    TRISCbits.TRISC6=1;
    TRISCbits.TRISC7=1;
    SPEN=1;
    SYNC=0;
    BRGH=1;
    SPBRG=129; 
    GIE=1;
    PEIE=1;
    RCIE=1;
    CREN=1;
    RC9=0;
}

/*
void __interrupt() USART_ISR(){
    if(RCIF){
        interruptRaised=1;
        recivedByte=RCREG;
        RCIF=0;
    }
}
*/
#endif //_USART_H_

/*
TXSTA:
 CSRC(bit 7): non usato per trasmissione asincrona
 
 TX9(bit 6): 
        || 1: Imposta la trasmissione a 9 bit ||
        || 0: Imposta la trasmissione a 8 bit ||
 
 TXEN(bit 5):
        || 1: Abilita la trasmissione    ||
        || 0: Disabilita la trasmissione ||
 
 SYNC(bit 4): 
        || 1: Imposta la trasmissione sincrona  ||
        || 0: Imposta la trasmissione asincrona ||
 
 bit 3: unimplemented
 
 BRGH(bit 2):
        || 1: Baud Rate High Speed ||
        || 0: Baud Rate Low Speed  ||
 
 TRMT(bit 1):
        || 1: Trasmissione non in corso ||
        || 0: Trasmissione in corso     ||
 
 TX9D(bit 0): 9� bit TXREG

SPBRG: 
 bit 7-0: Imposta il baud rate
  Per BRGH (bit 2 di TXSTA) = 1,
  Baud Rate di 9600 e Fosc = 20MHz
        ---> SPBRG=129 <---

TXREG:
 bit 7-0: Byte da trasmettere

TXIF:
        || 1: TXREG vuoto ||
        || 0: TXREG pieno ||

RCSTA:
 SPEN(bit 7): 
        || 1: Abilita la porta seriale    ||
        || 0: Disabilita la porta seriale ||
 
 RX9(bit 6):
        || 1: Imposta la ricezione a 9 bit ||
        || 0: Imposta la ricezione a 8 bit ||
 
 SREN(bit 5): non usato per la trasmissione asincrona
  
 CREN(bit 4):  
        || 1: Imposta la ricezione ||
        || 0: Imposta la ricezione ||
 
 bit 3: unimplemented
 
 FERR(bit 2):
        || 1: Framing error occurred    ||
        || 0: No Framing error occurred ||
 
 OERR(bit 1):
        || 1: Overrun error occurred    ||
        || 0: No Overrun error occurred ||
 
 RX9D(bit 0): 9� bit RCREG

RCREG: 
 bit 7-0: Byte ricevuto
  
INTCON:
 GIE(bit 7): 
        || 1: Abilita gli interrupt    ||
        || 0: Disabilita gli interrupt ||
 
 PEIE(bit 6):  
        || 1: Abilita gli interrupt di periferica    ||
        || 0: Disabilita gli interrupt di periferica ||
 
 bit  5-0: non necessari

PIE1:
 RCIE(bit 5):
        || 1: Abilita l'interrupt su RX    ||
        || 0: Disabilita l'interrupt su RX ||
  
 TXIE(bit 4):
        || 1: Abilita l'interrupt su TX    ||
        || 0: Disabilita l'interrupt su TX ||
 

 
=======
#ifndef _USART_H_
#define _USART_H_

#ifndef _XTAL_FREQ
#define _XTAL_FREQ 20000000
#endif

#include <xc.h>

void TXInit(){
    TRISCbits.TRISC6=1;
    TRISCbits.TRISC7=1;
    SPEN=1;
    SYNC=0;
    BRGH=1;
    SPBRG=129; //<- baudrate 9600 (datasheet)
    TXEN=1;
    TX9=0;
}

void TXWriteChar(char data){
    while(!TRMT);
    TXREG=data;
}

void TXWrite(char* string){
    int i=0;
    while(string[i]!='\0'){
        TXWriteChar(string[i]);
        i++;
    }
}

void RXInit(){
    TRISCbits.TRISC6=1;
    TRISCbits.TRISC7=1;
    SPEN = 1;
    SYNC = 0;
    BRGH=1;
    SPBRG=129; 
    GIE=1;
    PEIE=1;
    RCIE=1;
    CREN=1;
    RC9=0;
}

void __interrupt() ISR(){
    if(RCIF){
        TXWriteChar(RCREG);
        RCIF=0;
    }
}

#endif //_USART_H_

/*
TXSTA:
 CSRC(bit 7): non usato per trasmissione asincrona
 
 TX9(bit 6): 
        || 1: Imposta la trasmissione a 9 bit ||
        || 0: Imposta la trasmissione a 8 bit ||
 
 TXEN(bit 5):
        || 1: Abilita la trasmissione    ||
        || 0: Disabilita la trasmissione ||
 
 SYNC(bit 4): 
        || 1: Imposta la trasmissione sincrona  ||
        || 0: Imposta la trasmissione asincrona ||
 
 bit 3: unimplemented
 
 BRGH(bit 2):
        || 1: Baud Rate High Speed ||
        || 0: Baud Rate Low Speed  ||
 
 TRMT(bit 1):
        || 1: Trasmissione non in corso ||
        || 0: Trasmissione in corso     ||
 
 TX9D(bit 0): 9� bit TXREG

SPBRG: 
 bit 7-0: Imposta il baud rate
  Per BRGH (bit 2 di TXSTA) = 1,
  Baud Rate di 9600 e Fosc = 20MHz
        ---> SPBRG=129 <---

TXREG:
 bit 7-0: Byte da trasmettere

TXIF:
        || 1: TXREG vuoto ||
        || 0: TXREG pieno ||

RCSTA:
 SPEN(bit 7): 
        || 1: Abilita la porta seriale    ||
        || 0: Disabilita la porta seriale ||
 
 RX9(bit 6):
        || 1: Imposta la ricezione a 9 bit ||
        || 0: Imposta la ricezione a 8 bit ||
 
 SREN(bit 5): non usato per la trasmissione asincrona
  
 CREN(bit 4):  
        || 1: Imposta la ricezione ||
        || 0: Imposta la ricezione ||
 
 bit 3: unimplemented
 
 FERR(bit 2):
        || 1: Framing error occurred    ||
        || 0: No Framing error occurred ||
 
 OERR(bit 1):
        || 1: Overrun error occurred    ||
        || 0: No Overrun error occurred ||
 
 RX9D(bit 0): 9� bit RCREG

RCREG: 
 bit 7-0: Byte ricevuto
  
INTCON:
 GIE(bit 7): 
        || 1: Abilita gli interrupt    ||
        || 0: Disabilita gli interrupt ||
 
 PEIE(bit 6):  
        || 1: Abilita gli interrupt di periferica    ||
        || 0: Disabilita gli interrupt di periferica ||
 
 bit  5-0: non necessari

PIE1:
 RCIE(bit 5):
        || 1: Abilita l'interrupt su RX    ||
        || 0: Disabilita l'interrupt su RX ||
  
 TXIE(bit 4):
        || 1: Abilita l'interrupt su TX    ||
        || 0: Disabilita l'interrupt su TX ||
 

 
>>>>>>> 70e902ef07ae7b6138cdf5acc7966ae593a5ac45
*/ 