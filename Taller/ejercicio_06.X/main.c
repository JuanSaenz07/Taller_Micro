#include <xc.h>
#include "config.h"


void semaforo(void) {
    TRISA = 0x00; //todos los pines del puerto A como salidas digitales.
    ANSELA = 0x00;

    LATAbits.LATA0 = 0; //Apaga el LED asociado al pin RA0
    LATAbits.LATA1 = 1;//Enciende el LED asociado al pin RA1 

    LATAbits.LATA2 = 1;//Enciende el LED asociado al pin RA2 
    LATAbits.LATA3 = 0;//Apaga el LED asociado al pin RA3 

    LATAbits.LATA4 = 1;
    LATAbits.LATA5 = 0;

    __delay_ms(2000);

    LATAbits.LATA0 = 1; //Apaga el LED verde (RA1) y enciende el LED rojo (RA0) 
    LATAbits.LATA1 = 0;

    LATAbits.LATA2 = 0;////Apaga el LED amarillo (RA2) y enciende el LED rojo (RA3) 
    LATAbits.LATA3 = 1;

    LATAbits.LATA4 = 1;//Apaga el LED amarillo (RA4) y enciende el LED verde (RA5)
    LATAbits.LATA5 = 0;

    __delay_ms(2000);
 
    //Repite el proceso anterior dos veces
    LATAbits.LATA0 = 1;
    LATAbits.LATA1 = 0;

    LATAbits.LATA2 = 1;
    LATAbits.LATA3 = 0;

    LATAbits.LATA4 = 0;
    LATAbits.LATA5 = 1;

    __delay_ms (2000);



}

void main(void){
    
    
    TRISD = 0x00; 
    
    //LOOP INFINITO
    while(1){
      //  prendase();
        semaforo();
        
        
    }
    
    return;
}

