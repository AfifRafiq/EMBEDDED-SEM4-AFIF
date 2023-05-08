#include <p18f4580.h>
#include "LCD_BONE.c"

#pragma config OSC = HS
#pragma config FCMEN = OFF
#pragma config IESO = OFF
#pragma config PWRT = ON
#pragma config BOREN = OFF
#pragma config BORV = 0
#pragma config WDT = OFF
#pragma config PBADEN = OFF
#pragma config LPT1OSC = OFF
#pragma config MCLRE = ON
#pragma config STVREN = OFF
#pragma config LVP = OFF
#pragma config DEBUG = OFF

void pic_init(void);

void main()
{
    pic_init();
    lcd_init();
    delay(10);

    while(1)
    {
        lcd_clear();  // clear the display before writing new message

        // Check the state of the switches and display appropriate message
        if (PORTAbits.RA1 == 0 && PORTAbits.RA0 == 0)
        {
            send_string("MOTOR MOVE REVERSE");
        }
        else if (PORTAbits.RA1 == 0 && PORTAbits.RA0 == 1)
        {
            send_string("NONE");
        }
        else if (PORTAbits.RA1 == 1 && PORTAbits.RA0 == 0)
        {
            send_string("NONE");
        }
        else if (PORTAbits.RA1 == 1 && PORTAbits.RA0 == 1)
        {
            send_string("MOTOR MOVE FORWARD");
        }

        delay(100); // wait for 100ms before checking switches again
    }
}

void pic_init(void)
{
    TRISD = 0;
    TRISB = 0;
    TRISA = 0xFF; // Set PORTA as input
}
