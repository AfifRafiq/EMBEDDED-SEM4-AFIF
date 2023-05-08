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

#define LED PORTCbits.RC0
#define SW1 PORTBbits.RB6

void main (void)
{
	TRISCbits.RC0 = 0;
	TRISBbits.RB6 = 1;
	LED = 0;
	SW1 = 0;
	
		while(1)
		{
			if (SW1 == 0)
			{
				LED = 1;
			}
			else	
			{
				LED = 0;
			}
		}
}