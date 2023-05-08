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
	TRISCbits.RC0 = 0;
	
	PORTCbits.RC0 = 0;
	
	  while(1)
	  {
		  PORTCbits.RC0 = 1;
 	  }
}