#include <xc.h>

// turn off WDT
#pragma config WDTE = OFF

void init_config()
{
    TRISDbits.TRISD0 = 0;   // OUTPUT PIN
    TRISBbits.TRISB0 = 1;   // RB0 IS INPUT PIN
}

void main(void)
{
    init_config();

    while(1)
    {
        if(PORTBbits.RB0 == 0)
        {
            PORTDbits.RD0 = !PORTDbits.RD0;
            for(unsigned int wait = 50000; wait--;);
        }
    }

    return;
}
