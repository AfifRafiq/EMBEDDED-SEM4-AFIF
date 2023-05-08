#include <xc.h>

// Configuration bits
#pragma config OSC = INTIO67   // Set internal oscillator frequency to 6-7 MHz
#pragma config WDT = OFF       // Disable watchdog timer
#pragma config LVP = OFF       // Disable low-voltage programming

void TMR0_ISR() {
    if (TMR0IF) {             // If Timer0 interrupt flag is set
        TMR0IF = 0;           // Clear Timer0 interrupt flag
        TMR0 = 3036;          // Load Timer0 to count for 50ms (3036 = 65536 - 50000/4)
        LATCbits.LATC0 ^= 1;  // Toggle RC0 bit
    }
}

void main() {
    TRISCbits.TRISC0 = 0;     // Set RC0 as output
    T0CONbits.T08BIT = 0;      // Set Timer0 to 16-bit mode
    T0CONbits.T0CS = 0;        // Set Timer0 to use internal clock
    T0CONbits.PSA = 0;         // Set Timer0 to use prescaler
    T0CONbits.T0PS = 0b001;    // Set Timer0 prescaler to 1:4
    TMR0 = 3036;              // Initialize Timer0 to count for 50ms (3036 = 65536 - 50000/4)
    INTCONbits.TMR0IF = 0;     // Clear Timer0 interrupt flag
    INTCONbits.TMR0IE = 1;     // Enable Timer0 interrupt
    INTCONbits.GIE = 1;        // Enable global interrupt
    while (1) {
        // Main program loop, interrupt will handle the toggling of RC0
    }
}
