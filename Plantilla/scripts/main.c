/*
 *
 * leds: D2, D3, C6, C7
 * pulsadores: D4, D5, D6, D7
 * datos display: nibble bajo del puerto A
 * habilitacion display: A4, A5, E1, E0
 * 
 *
 */

#include <xc.h>
#include "confbits.h"   //no se debe de modificar este archivo para
                        //garantizar el funcionamiento del BOOTLOADER
#include"Ap_Puertos.h"  

# define _XTAL_FREQ  20000000

void main(void) {
    timer_ini13();                 //inicializa el timer para interrupcion
    INTCONbits.GIE = 1;    //comente esta linea para inhabilitar todas las int
    ei();
//alternativa para habilitar interrupciones
    T0CONbits.TMR0ON = 1;  //enciendo el timer0
    while(1)
    {
        
    }
}

void __interrupt() myISR(void){
    isrbit=~isrbit;
    if(TMR0IF){
        INTCONbits.TMR0IF = 0;  //borra el flag de la interrupcion de timer
        TMR0L = 0x43;//0x64;           //reinicia el time
        TMR0H = 0xFF;

        
        
    }
    return;                     //termina el codigo de interrupcion
}
           
