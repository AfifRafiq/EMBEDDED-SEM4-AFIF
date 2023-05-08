#include <p18f4580.h>

#pragma config WDT = OFF, OSC = HS, MCLRE = ON, LVP = OFF, BOREN = OFF, PBADEN = OFF

#define LED1 PORTCbits.RC0
#define LED2 PORTCbits.RC1

void isr (void);
void msdelay(unsigned int itime);

#pragma code My_HiPrio_Int = 0x0008
void My_HiPrio_Int (void)
{
    _asm
    GOTO isr
    _endasm
}
#pragma code
#pragma interrupt isr

void main()
{
    TRISBbits.RB0 = 1;  // Set RB0 as input (switch)
    TRISCbits.RC0 = 0;  // Set RC0 as output (LED1)
    TRISCbits.RC1 = 0;  // Set RC1 as output (LED2)
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
    unsigned int i;
    
    if (INTCONbits.INT0IF==1)
    {
        LED1 = 1;                   // Toggle LED1
        msdelay (10000);
        LED1 = 0;
        
        for (i=0; i<10; i++)        // Toggle LED2 ten times
        {
            LED2 = 1;
            msdelay (5000);
            LED2 = 0;
            msdelay (5000);
        }
    }
    INTCONbits.INT0IF=0;
}

void msdelay(unsigned int itime)
{
    unsigned int i;
    unsigned char j;
    for (i=0; i<itime; i++);
    for(j=0; j<165; j++);
}
