#include <xc.h>
#include "config.h"

char marca=0; //variable 

void main(void){
    
    ANSELB = 0x00; //todos los pines del puerto B como pines digitales deshabilitando la funcionalidad anal�gi.
    TRISBbits.TRISB0 = 1; //RB0 como entrada.
    TRISBbits.TRISB7 = 0; //RB7 como salida.
    
    while(1){
        
        if(PORTBbits.RB0 == 0){ //indica que un bot�n ha sido presionado
            while(PORTBbits.RB0 == 0);//este bucle se ejecutar� mientras el bot�n est� presionado 
            //y permanecer� en espera hasta que el bot�n sea liberado.
            marca++; // cada vez que se detecta una pulsaci�n del bot�n.
        }
        if(marca==3){ //marca ha alcanzado el valor de 3.
            LATBbits.LATB7 ^= 1;
            marca=0;
        }
        __delay_ms(100);
    }
    
    return;
}