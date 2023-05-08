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

void main (void)
{
	TRISAbits.RA1 = 0;
	TRISBbits.RB0 = 0;
	TRISBbits.RB1 = 0;
	TRISCbits.RC0 = 0;
	TRISCbits.RC1 = 0;
	
	PORTAbits.RA1 = 0;
	PORTBbits.RB0 = 0;
	PORTBbits.RB1 = 0;
	PORTCbits.RC0 = 0;
	PORTCbits.RC1 = 0;
	
	
	  while(1)
	  {
		  PORTAbits.RA1 = 1;
		  PORTBbits.RB0 = 1;
		  PORTBbits.RB1 = 1;
		  PORTCbits.RC0 = 1;
		  PORTCbits.RC1 = 1;		  
	  }
}