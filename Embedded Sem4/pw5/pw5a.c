#include <p18f4580.h>
#define LED PORTBbits.RB0
void T0Delay (void);

void main (void)
{
 TRISC=0;
 while (1)
 {
   LED=1;
   T0Delay ();
   LED=0;
   T0Delay ();
 }
}


void T0Delay ()
{
 T0CON = 0X04;
 TMR0H = 0X85;
 TMR0L = 0XEE;
 T0CONbits.TMR0ON = 1;

 while (INTCONbits.TMR0IF == 0);
 T0CONbits.TMR0ON = 0;
 INTCONbits.TMR0IF = 0;
}
