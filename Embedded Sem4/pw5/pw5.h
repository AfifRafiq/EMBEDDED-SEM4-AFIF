#include <p18f4580.h>

#define _XTAL_FREQ 10000000

void interrupt ISR()
{
    if (INTCONbits.TMR0IF == 1)
    {
        PORTCbits.RC0 ^= 1; // Toggle RC0 bit
        TMR0H = 0x3C; // Reload TMR0H with initial value
        TMR0L = 0xAF; // Reload TMR0L with initial value
        INTCONbits.TMR0IF = 0; // Clear Timer0 interrupt flag
    }
}

void main()
{
    TRISC = 0b11111110; // Set RC0 as output
    T0CON = 0b00001000; // Timer0, 16-bit mode, 1:4 prescaler value
    TMR0H = 0x3C; // Load TMR0H with initial value
    TMR0L = 0xAF; // Load TMR0L with initial value
    INTCONbits.TMR0IF = 0; // Clear Timer0 interrupt flag
    INTCONbits.TMR0IE = 1; // Enable Timer0 interrupt
    INTCONbits.GIE = 1; // Enable global interrupt

    while (1)
    {
        // Do nothing in the main loop
    }
}
