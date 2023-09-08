#include "secuencias.h"
#include "config.h"
#include <xc.h>


//desarrollo de los metodos
void secuencia_0() { // alterna entre 00001111 y 11110000
    LATD = 0x0F;
    __delay_ms(500);
    LATD = 0xF0;
    __delay_ms(500);
}

void secuencia_1() { //alterna entre 10101010 y 01010101
    LATD = 0b10101010;
    __delay_ms(1000);
    LATD = 0b01010101;
    __delay_ms(1000);
}

void secuencia_2() { // alternando entre los valores binarios 10101010 y 01010101
    LATD = 0b10000001;
    __delay_ms(500);
    LATD = 0b11000011;
    __delay_ms(500);
    LATD = 0b11100111;
    __delay_ms(500);
    LATD = 0b11111111;
    __delay_ms(500);
}

void secuencia_3(){ // repite el valor binario 1100110011 
    LATD = 0b1100110011;
    __delay_ms(500);
    LATD = 0b1100110011;
    __delay_ms(500);
}

void secuencia_4(){ //alterna entre todos los bits encendidos (0xFF) y todos los bits apagados (0x00)
    LATD = 0xFF;
    __delay_ms(500);
    LATD = 0x00;
    __delay_ms(500);
}

void secuencia_5(){ //secuencia en la que solo un bit se enciende
    LATD = 0b00000001;
    __delay_ms(500);
    LATD = 0b10000000;
    __delay_ms(500);
}

void secuencia_6(){ //enciende y se apaga en cuatro posiciones diferentes del puerto
    //11100000, 00000111, 00011000 y 10000001. 
     LATD = 0b11100000;
    __delay_ms(500);
    LATD = 0b00000111;
    __delay_ms(500);
     LATD = 0b00011000;
    __delay_ms(500);
    LATD = 0b10000001;
    __delay_ms(500);
}

void secuencia_7(){  
    //enciende un número creciente de bits en cada estado: 00000001, 00000011, 00000111 y 00001111
     LATD = 0b00000001;
    __delay_ms(500);
    LATD = 0b00000011;
    __delay_ms(500);
     LATD = 0b00000111;
    __delay_ms(500);
    LATD = 0b00001111;
    __delay_ms(500);
    
}

void secuencia_8(){ 
    //enciende todos los bits excepto el bit menos significativo 11111110 y 00000001
    //Luego, alterna entre los valores binarios 11110000 y 00001111
    LATD = 0b11111110;
    __delay_ms(500);
    LATD = 0b00000001;
    __delay_ms(500);
     LATD = 0b11110000;
    __delay_ms(500);
    LATD = 0b00001111;
    __delay_ms(500);  
}

