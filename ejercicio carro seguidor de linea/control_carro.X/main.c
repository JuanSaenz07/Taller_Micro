#include <xc.h>
#include "config.h"

#define MA1 LATDbits.LATD0
#define MA2 LATDbits.LATD1
#define MB1 LATDbits.LATD2
#define MB2 LATDbits.LATD3

#define MA1_DIR TRISDbits.TRISD0 //para direccionar si es entrada o salida
#define MA2_DIR TRISDbits.TRISD1
#define MB1_DIR TRISDbits.TRISD2
#define MB2_DIR TRISDbits.TRISD3

#define BTN_UP PORTBbits.RB0
#define BTN_IZ PORTBbits.RB1
#define BTN_DR PORTBbits.RB2
#define BTN_AB PORTBbits.RB3

#define BTN_UP_DIR TRISBbits.TRISB0
#define BTN_IZ_DIR TRISBbits.TRISB1
#define BTN_DR_DIR TRISBbits.TRISB2
#define BTN_AB_DIR TRISBbits.TRISB3

#define SENSOR_IZ_DIR TRISAbits.TRISA0
#define SENSOR_CEN_DIR TRISAbits.TRISA1
#define SENSOR_DER_DIR TRISAbits.TRISA2

#define SENSOR_IZ PORTAbits.RA0
#define SENSOR_CEN PORTAbits.RA1
#define SENSOR_DER PORTAbits.RA2

void girar_derecha();
void girar_izquierda();
void avanzar();
void atras();

void main(void) {
    ANSELB = 0x00; //todo digital
    ANSELA = 0x00;
    //Salidas
    MA1_DIR = 0;
    MA2_DIR = 0;
    MB1_DIR = 0;
    MB2_DIR = 0;

    OPTION_REGbits.nWPUEN = 0; //Habiliamos resistencias de pull up internas
    WPUB = 0x0F;//Esta colocando 1 los 4 primeros
    
    //habilitar las entradas
    BTN_AB_DIR = 1;
    BTN_DR_DIR = 1;
    BTN_IZ_DIR = 1;
    BTN_UP_DIR = 1;
    
    while (1) {
        
        if(SENSOR_IZ == 1){
            girar_izquierda();
        }
        if(SENSOR_CEN == 1){
            avanzar();
        }
        if(SENSOR_DER == 1){
            girar_derecha();
        }
        if(SENSOR_IZ == 0 && SENSOR_CEN == 0 && SENSOR_DER ==0){
            atras();
        }
        
        if(BTN_UP == 0){
           avanzar(); 
        }
        if(BTN_AB == 0){
           atras(); 
        }
        if(BTN_DR == 0){
           girar_derecha();  
        }
        if(BTN_IZ == 0){
           girar_izquierda(); 
        }
        if((PORTB & 0x0F)==15){
            MA1 = 0;
            MA2 = 0;
            MB1 = 0; 
            MB2 = 0;
        }
        
    }
    return;
}

void girar_derecha() {
    MA1 = 0;
    MA2 = 1;
    MB1 = 0;
    MB2 = 0;
}

void girar_izquierda() {
    MA1 = 0;
    MA2 = 0;
    MB1 = 1;
    MB2 = 0;
}

void avanzar() {
    MA1 = 0;
    MA2 = 1;
    MB1 = 1;
    MB2 = 0;
}

void atras() {
    MA1 = 1;
    MA2 = 0;
    MB1 = 0;
    MB2 = 1;
}