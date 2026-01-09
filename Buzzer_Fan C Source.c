#include <xc.h>
#include "main.h"

#define _XTAL_FREQ 20000000
#pragma config WDTE = OFF

static void init_config(void) {
    // Configure RC1 and RC2 as output
    BUZZER_DDR = 0;
    FAN_DDR = 0;

    // Turn off buzzer and fan initially
    BUZZER = 0;
    FAN = 0;
}

void main(void) {
    init_config();

    while(1)   // Infinite loop
    {
        BUZZER = 1;   // ON
        FAN = 1;      // ON
        __delay_ms(2000);

        BUZZER = 0;   // OFF
        FAN = 0;      // OFF
        __delay_ms(2000);
    }
}
