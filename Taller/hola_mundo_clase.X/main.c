 #include <xc.h>
#include "config.h"

#define espera 100 //en cualquier lugar del código donde este la palabra "espera", se reemplazará automáticamente por el valor 100 antes

void prendase(void){
        LATD = 0b00000001; 
        __delay_ms(espera);
       //LATD = 0b00000001;: Establece el primer bit del puerto LATD en 1
        //y los demás en 0. Esto activa una de las salidas del puerto
        
        
        LATD = 0b00000010;
        __delay_ms(espera);
        
        
        LATD = 0b00000100;
        __delay_ms(espera);
        
        LATD = 0b00001000;
        __delay_ms(espera);
        
        LATD = 0b00010000;
        __delay_ms(espera);
        
        LATD = 0b00100000;
        __delay_ms(espera);
        
        LATD = 0b01000000;
        __delay_ms(espera);
        
        LATD = 0b10000000;
        __delay_ms(espera);
        
        LATD = 0b01000000;
        __delay_ms(espera);
        LATD = 0b00100000;
        __delay_ms(espera);
        LATD = 0b00010000;
        __delay_ms(espera);
        LATD = 0b00001000;
        __delay_ms(espera);
        LATD = 0b00000100;
        __delay_ms(espera);
        LATD = 0b00000010;
        __delay_ms(espera);
        LATD = 0b00000001;
        __delay_ms(espera);
}// este método parece ser una función que realiza una secuencia de encendido
//y apagado de salidas en un puerto

void efor(void ){
    
    LATD = 0x00; //todos los bits en 0
    char i=0; 
    for(i=0;      i<8;        i++){ //Este bucle se ejecutará mientras i sea menor que 8.
        LATD |=(1<<i);  //enciende el bit correspondiente en el puerto LATD. 
        LATD &=~(1<<i-1);  //apaga el bit anterior al bit encendido en la iteración actual.
        __delay_ms(espera);
        
        
        
    }
    LATD= 0X00;
    for(i=8; i>1; i--){  //se ejecutará mientras i sea mayor que 1.
        //Inicialmente, i es 8 y se decrementa en cada iteración.
        LATD |=(1<<i); //pone el bit en posición i en 1 sin afectar los otros bits del registro.
        LATD &=~(1<<i+1); //Esta línea apaga el bit en la posición i+1 del registro LATD. 
        __delay_ms(espera);
        
        
        //en lo personal lo mas facil es hacerlo por mascaras de bits,porque el for es una enredadera ni la hp
        
        
    }
}


    
    
    // 4 ANALOGICOS 
    // ANSEL PARA QUITAR LA PARTE ANALOGICA 
    void motor(void) {

    TRISAbits.TRISA0 = 1; //RA0 como entrada
    ANSELAbits.ANSA0 = 0; //Deshabilita la funcionalidad analógica 
    TRISAbits.TRISA1 = 1; // RA1 como entrada.
    ANSELAbits.ANSA1 = 0;
    TRISAbits.TRISA2 = 0; //RA2 se configurará para enviar señales de salida.
    ANSELAbits.ANSA2 = 0;
    TRISAbits.TRISA3 = 0;
    ANSELAbits.ANSA3 = 0;


    if ((PORTAbits.RA0 == 1 && PORTAbits.RA1 == 1) || (PORTAbits.RA0 == 0 && PORTAbits.RA1 == 0)) {
//ya sea ambos como entrada o ambos como salida y en el mismo estado, alto o bajo
        LATAbits.LATA2 = 0;
        LATAbits.LATA3 = 0;
//Si ambos pines RA0 y RA1 son iguales se apagan los pines de salida LATA2 y LATA3.
        
    }

    if (PORTAbits.RA0 == 0 && PORTAbits.RA1 == 1) {

        LATAbits.LATA2 = 0;
        LATAbits.LATA3 = 1;
//Si RA0 es bajo (0) y RA1 es alto (1), se apaga LATA2 y se enciende LATA3.
    }
    if (PORTAbits.RA0 == 1 && PORTAbits.RA1 == 0) {

        LATAbits.LATA2 = 1;
        LATAbits.LATA3 = 0;
//Si RA0 es alto (1) y RA1 es bajo (0), se enciende LATA2 y se apaga LATA3.
    }


}


void main(void){
    
    
    TRISD = 0x00; 
    
    //LOOP INFINITO
    while(1){
      //  prendase();
        motor();
        
        
    }
    
    return;
}




