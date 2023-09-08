#include <xc.h>
#include "config.h"
#include "sientesegmentos.h"





int val_sec = 0, contador = 0, contadordos = 0;

void ejercicio_7(void) {
    ANSELD = 0x00;
    ANSELB = 0x00;
    TRISB = 0x0F; 
    //pines TRISB como entradas (bits 0-3 son entradas,
    //bits 4-7 son salidas) para recibir señales de entrada.

    display_init();


    if (PORTBbits.RB0 == 1 && PORTBbits.RB1 == 0) { 
        //Si RB0 está alto (1) y RB1 está bajo (0), incrementa el contador 
        display_cc(contador);
        display_ccdos(contadordos);  
        contador++;
        if (contador > 9) { // El contador se reinicia a 0 cuando llega a 9,
            contador = 0;
            contadordos++; //y el segundo contador incrementa
        }

        if (contadordos > 9) {
            contador = 9;
            contadordos = 9;
        }

        if (contadordos == 9 && contador == 9) { 
            display_cc(9); //Si ambas condiciones se cumplen, esta línea llama 
            //a la función llamada display_cc y le pasa el valor 9 como argumento
            display_ccdos(9);//También llama a la función  display_ccdos y le pasa el valor 9 como argumento
        }
    }

    if (PORTBbits.RB0 == 0 && PORTBbits.RB1 == 1) { //Si RB0 está bajo (0) y RB1 está alto (1), 
        //decrementa el contador 
        display_cc(contador);
        display_ccdos(contadordos);
        contador--;

        if (contador < 0) {  //El contador se reinicia a 9 cuando llega a 0, y el segundo contador decrementa
            contador = 9;
            contadordos--;
        }
        if (contadordos < 0) {
            contador = 0;
            contadordos = 0;
        }

        if (contadordos == 0 && contador == 0) {
            display_cc(0);
            display_ccdos(0);
        }
    }


    if (PORTBbits.RB0 == 1 && PORTBbits.RB1 == 1) {
        //Si RB0 y RB1 están ambos altos (1), simplemente muestra el valor actual del contador en el display.
        display_cc(contador);
        display_ccdos(contadordos);
    }

    if (PORTBbits.RB0 == 0 && PORTBbits.RB1 == 0 && PORTBbits.RB2) {
//Si RB0 y RB1 están ambos bajos (0) y RB2 está alto (1), incrementa el contador en 2
        display_cc(contador);
        display_ccdos(contadordos);

        contador = contador + 2;

        if (contador > 9) {
            contadordos++; //Incrementa el valor de contadordos en 1
            if (contador == 10) {
                contador = 0;
            }
            if (contador == 11) { //Si contador es igual a 11, establece contador en 1.
                contador = 1;
            }
        }
        if (contadordos > 9) {
            contador = 9;
            contadordos = 9;
        }

        if (contadordos == 9 && contador >= 9) {
            display_cc(9);
            display_ccdos(9);
        }
    }

    if (PORTBbits.RB0 == 0 && PORTBbits.RB1 == 0 && PORTBbits.RB3) {
//Si RB0 y RB1 están ambos bajos (0) y RB3 está alto (1), decrementa el contador en 2 
        display_cc(contador);
        display_ccdos(contadordos);

        contador = contador - 2;

        if (contador < 0) {
            contadordos--;
            if (contador == -1) {
                contador = 9;
            }
            if (contador == -2) {
                contador = 8;
            }
        }
        if (contadordos < 0) {
            contador = 0;
            contadordos = 0;
        }

        if (contadordos == 0 && contador == 0) {
            display_cc(0);
            display_ccdos(0);
        }
    }




    __delay_ms(500);

}
void main(void){
    
    
     
    
    
    while(1){
      
        
        ejercicio_7();
        
        
    }
    
    return;
}

