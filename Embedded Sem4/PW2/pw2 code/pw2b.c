#include <p18f4580.h>

#pragma config OSC = HS
#pragma config FCMEN = OFF
#pragma config IESO = OFF
#pragma config PWRT = OFF
#pragma config WDT = OFF
#pragma config MCLRE = ON
#pragma config PBADEN = OFF
#pragma config LVP = OFF
#pragma config XINST = OFF

#define LED1 PORTBbits.RB0
#define LED2 PORTBbits.RB1
#define SW1 PORTCbits.RC0
#define SW2 PORTCbits.RC1

void MSDelay(unsigned int itime)
{
    unsigned int i;
    unsigned char j;

    for (i = 0; i < itime; i++);
    for (j = 0; j < 165; j++);
}

void main(void)
{
    int x;
    TRISBbits.RB0 = 0;
    TRISBbits.RB1 = 0;
    TRISCbits.RC0 = 1;
    TRISCbits.RC1 = 1;
    while (1)
    {
        if (SW1 == 0 && SW2 == 1)
        {
            LED1 = 1;
            LED2 = 0;
        }

        else if (SW1 == 1 && SW2 == 0)
        {
            LED1 = 0;
            LED2 = 1;
        }
        else if (SW1 == 1 && SW2 == 1)
        {
            LED1 = 1;
            LED2 = 1;
        }
    }
}