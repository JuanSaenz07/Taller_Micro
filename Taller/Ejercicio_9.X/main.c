#include <xc.h>
#include "config.h"

#define DIR_boton1 TRISCbits.TRISC0 
//configura el pin RC0 (puerto C, bit 0) como entrada para el botón 1.
#define DIR_boton2 TRISCbits.TRISC1 
#define DIR_boton3 TRISCbits.TRISC2
#define DIR_boton4 TRISCbits.TRISC3

#define boton1 PORTCbits.RC0
//pines (lectura y escritura) permite leer el valor del pin RC0 en boton1
#define boton2 PORTCbits.RC1
#define boton3 PORTCbits.RC2
#define boton4 PORTCbits.RC3

#define DIR_led1 TRISDbits.TRISD0 
#define DIR_led2 TRISDbits.TRISD1
#define DIR_led3 TRISDbits.TRISD2

#define led1 LATDbits.LATD0
#define led2 LATDbits.LATD1
#define led3 LATDbits.LATD2


void main(void){
    
    //pines para botones como entrada 
    DIR_boton1 = 1;
    DIR_boton2 = 1;
    DIR_boton3 = 1;
    DIR_boton4 = 1;
    
    // pines para los LED como salidas
    DIR_led1 = 0;
    DIR_led2 = 0;
    DIR_led3 = 0;
    
    //Se inicializan los LED  en estado apagado 
    led1 = 0;
    led2 = 0;
    led3 = 0;
    
    
    while(1){ //bucle 
        while(led1==0 && led2==0 && led3==0){ // otro bucle que se ejecuta mientras los tres LED están apagados
            if (boton1==0) //Si alguno de los botones se presiona, el LED correspondiente se enciende
                led1=1;
            
            if (boton2==0)
                led2=1;
            
            if (boton3==0)
                led3=1;
            
            
        }
        if (boton4==0){
            led1 = 0;
            led2 = 0;
            led3 = 0;
        }
        
    }
    
    return;
}

