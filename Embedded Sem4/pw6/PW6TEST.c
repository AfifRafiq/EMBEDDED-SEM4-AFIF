#include <p18f4580.h>

#pragma config WDT = OFF, OSC = HS, MCLRE = ON , LVP = OFF, BOREN = OFF, PBADEN = OFF

#define LED PORTCbits.RC0

void isr (void);

void main()
{
    TRISBbits.RB0 = 1;  // Set RB0 as input (INT0)
    TRISCbits.RC0 = 0;  // Set RC0 as output (LED)
    PORTB = 0;          // Clear PORTB
    PORTC = 0;          // Clear PORTC
    
    INTCONbits.INT0IF = 0;  // Clear INT0 interrupt flag
    INTCONbits.INT0IE = 1;  // Enable INT0 interrupts
    INTCONbits.GIE = 1;     // Enable global interrupts
    
    while (1)
    {
        
    }
}

#pragma interrupt isr
void isr (void)
{
    LED ^= 1;           // Toggle LED
    INTCONbits.INT0IF = 0;  // Clear INT0 interrupt flag
}
