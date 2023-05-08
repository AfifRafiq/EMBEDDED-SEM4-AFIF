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
    TRISBbits.RB4 = 1;  // Set RB4 as input (SW1)
    TRISBbits.RB5 = 1;  // Set RB5 as input (SW2)
    TRISCbits.RC0 = 0;  // Set RC0 as output (LED1)
    TRISCbits.RC1 = 0;  // Set RC1 as output (LED2)
    PORTB = 0;          // Clear PORTB
    PORTC = 0;          // Clear PORTC
    
    INTCONbits.INT0IF = 0;  // Clear INT0 interrupt flag
    INTCONbits.INT0IE = 0;  // Disable INT0 interrupts
    INTCONbits.RBIF = 0;    // Clear RB interrupt flag
    INTCONbits.RBIE = 1;    // Enable RB interrupts
    INTCONbits.GIE = 1;     // Enable global interrupts
    
    while (1)
    {
        
    }
}

#pragma interrupt isr
void isr (void)
{
    unsigned int i;
    
    if (INTCONbits.RBIF == 1)
    {
        if (PORTBbits.RB4 == 0)  // SW1 is activated
        {
            LED1 = ~LED1;  // Toggle LED1
        }
        else if (PORTBbits.RB5 == 0)  // SW2 is activated
        {
            LED2 = ~LED2;  // Toggle LED2
        }
        
        msdelay(10000);
        
        INTCONbits.RBIF = 0;  // Clear RB interrupt flag
    }
}

void msdelay(unsigned int itime)
{
    unsigned int i;
    unsigned char j;
    for (i=0; i<itime; i++);
    for(j=0; j<165; j++);
}
