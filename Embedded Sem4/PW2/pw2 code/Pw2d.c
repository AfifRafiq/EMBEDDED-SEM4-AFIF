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
#define SENSOR_A PORTBbits.RB0
#define SENSOR_B PORTBbits.RB1

void main (void)
{
   TRISCbits.RC0 = 0;
   TRISBbits.RB0 = 1;
   TRISBbits.RB1 = 1;
   LED = 0;
   while (1)
   {
      if(SENSOR_A == 1 || SENSOR_B == 1)
      {
         LED = 1;
      }
      else if (SENSOR_A == 0 || SENSOR_B == 0)
      {
         LED = 0;
      }
   }
}