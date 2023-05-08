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

#define LED1 PORTCbits.RC0
#define LED2 PORTCbits.RC1
#define SW1 PORTBbits.RB0
#define SW2 PORTBbits.RB1

void MSDelay(unsigned int itime) // Delay function
{
    unsigned int i;
	unsigned char j;
    for(i=0;i<itime;i++);
    for(j=0;j<165;j++);
    
}

void main (void)
{
   TRISCbits.RC0 = 0; // Set LED1 as output
   TRISCbits.RC1 = 0; // Set LED2 as output
   TRISBbits.RB0 = 1; // Set SW1 as input
   TRISBbits.RB1 = 1; // Set SW2 as input
   LED1 = 0; // Turn off LED1
   LED2 = 0; // Turn off LED2

   while(1)
   {
      if(SW1&&SW2) // Both switches are active low
      {
         LED1 = 1; // Turn on LED1
         LED2 = 0; // Turn off LED2
      }
      else // Either switch is not activated
      {
         LED1 = 0; // Turn off LED1
         LED2 = 1; // Turn on LED2
         MSDelay(10000); // Delay 200ms
         LED2 = 0; // Turn off LED2
         MSDelay(10000); // Delay 200ms
      }
   }
}