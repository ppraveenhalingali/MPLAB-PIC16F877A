/*
 * File:   main.c
 * Author: DELL
 *
 * Created on December 22, 2025, 10:54 AM
 */


#include <xc.h>
// turn of WDT
#pragma config WDTE = OFF

void init_config() {
    TRISB = 0X00;
}

void main(void) {
    init_config();
    while (1) {
        PORTB = 0xFF;
        for (unsigned int wait = 50000; wait--;);
        PORTB = 0x00;
        for (unsigned int wait = 50000; wait--;);
    }


    return;
}
