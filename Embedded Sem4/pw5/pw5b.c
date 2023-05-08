#include <p18f4580.h>
void main (void)
{
TRISAbits.TRISA4=1;
TRISB=0;
T0CON=0X68;
TMR0L=0;

while (1)
{
do
	{
	T0CONbits.TMR0ON=1;
	PORTB=TMR0L;
	}
while (INTCONbits.TMR0IF == 0);
T0CONbits.TMR0ON = 0;
INTCONbits.TMR0IF = 0;
}
}