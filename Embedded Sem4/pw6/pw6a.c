#include <p18f4580.h>

#pragma config WDT = OFF, OSC = HS, MCLRE = ON, LVP = OFF, BOREN = OFF, PBADEN = OFF

#define LED PORTCbits.RC0


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
	TRISBbits.RB0 = 1;
	TRISC = 0;
	PORTB = 0;
	PORTC = 0;
	
	INTCONbits.INT0IF = 0;
	INTCONbits.INT0IE = 1;
	INTCONbits.GIE = 1;
	
	while (1)
	{
		
	}
}

void isr (void)
{
	unsigned int i;
	
	if (INTCONbits.INT0IF==1)
	{
			LED=1;
			msdelay (10000);
			LED=0;
			msdelay (10000);
	}
	INTCONbits.INT0IF=0;
}

void msdelay(unsigned int itime)
{
	unsigned int i;
	unsigned char j;
	for (i=0;i<itime;i++);
	for(j=0;j<165;j++);
}
