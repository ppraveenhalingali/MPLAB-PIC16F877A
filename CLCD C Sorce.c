#include "clcd.h"

void clcd_write(unsigned char byte, unsigned char mode)
{
    CLCD_RS = mode;            // Set for Instruction or Data
    CLCD_DATA_PORT = byte;     // Put data on Port D
    
    /* Enable Pulse */
    CLCD_EN = HI;
    __delay_us(100);
    CLCD_EN = LOW;
    __delay_ms(2);             // Execution time for most commands
}

void init_clcd(void)
{
    /* Set Pins as Output */
    CLCD_DATA_PORT_DDR = 0x00;
    CLCD_RS_DDR = 0;
    CLCD_EN_DDR = 0;

    __delay_ms(30);            // LCD Power-on delay
    
    clcd_write(EIGHT_BIT_MODE, INST_MODE);
    __delay_ms(5);
    clcd_write(TWO_LINES_5x8_8_BIT_MODE, INST_MODE);
    __delay_ms(1);
    clcd_write(DISP_ON_AND_CURSOR_OFF, INST_MODE);
    __delay_ms(1);
    clcd_write(CLEAR_DISP_SCREEN, INST_MODE);
    __delay_ms(2);
}

void clcd_putch(const char data, unsigned char addr)
{
    clcd_write(addr, INST_MODE);
    clcd_write(data, DATA_MODE);
}

void clcd_print(const char *str, unsigned char addr)
{
    clcd_write(addr, INST_MODE);
    while (*str)
    {
        clcd_write(*str++, DATA_MODE);
    }
}