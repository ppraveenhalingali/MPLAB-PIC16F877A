#include <xc.h>
#include "clcd.h"

/* Configuration Bits (Example for PIC16F877A) */
#pragma config FOSC = HS, WDTE = OFF, PWRTE = OFF, BOREN = OFF, LVP = OFF

void init_config(void)
{
    init_clcd();
}

void main(void)
{
    init_config();

    while (1)
    {
        clcd_print("HELLO WORLD", LINE1(0));
        clcd_print("LCD WORKING", LINE2(2));
    }
}