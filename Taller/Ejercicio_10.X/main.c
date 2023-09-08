#include <xc.h>
#include "config.h"

void ejercicio10(void) {

    TRISC = 0x00; //todo el puesrto c son salidas 
    TRISD = 0x0F;//los primero 4 son entradas 
    ANSELD = 0x00;// quitar analogico del puerto 

    if (PORTDbits.RD0 == 0) { //pasa bajo, el boton siempre esta en 1
        LATCbits.LATC0 = ~PORTCbits.RC0; // esto indica si quiero encender o apagar un led, la negacion de lo que tiene el puerto c en el bit0
        __delay_ms(100); 
    }
    if (PORTDbits.RD1 == 0) {  // si se activa el otro boton niega lo del puerto 
        LATCbits.LATC0 = ~PORTCbits.RC0;
        __delay_ms(100);
    }



}
void main(void){
    
    
     
    
    
    while(1){
      
        ejercicio10(); 
        
        
        
    }
    
    return;
}

