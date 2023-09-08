#include <xc.h>
#include "config.h"
#include "secuencias.h"

//Variable para cargar el numero de la secuencia a utilizar
int secuencia;

void main(void){
    
    //configurar puerto C    
    TRISC = 0X0F; //entrada digital
    
    //configurar puerto D
    ANSELD = 0x00; //PUERTO D digital
    TRISD = 0x00;  //salidas digitales
    LATD = 0x00;   //iniciar en cero
    
    
    
    while(1){
        
       secuencia = (PORTC & 0x0F); //Lee los cuatro bits menos significativos (RC0 a RC3)
       //del puerto C y almacena el valor en la variable secuencia
       
       switch(secuencia){
           case 0: secuencia_0(); break; //Si secuencia es igual a 0, llama a la función secuencia_0
           case 1: secuencia_1(); break;
           case 2: secuencia_2(); break;
           case 3: secuencia_3(); break;
           case 4: secuencia_4(); break;
           case 5: secuencia_5(); break;
           case 6: secuencia_6(); break;
           case 7: secuencia_7(); break;
           case 8: secuencia_8(); break;
       }
       __delay_ms(500);
           
    }


    
    return;
}




