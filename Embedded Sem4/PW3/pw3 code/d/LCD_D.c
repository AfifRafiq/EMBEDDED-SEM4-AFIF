#include<p18f4580.h>
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

#define sw1 PORTAbits.RA0
#define sw2 PORTAbits.RA1

void pic_init(void);

void main()
{
    pic_init();
    lcd_init();
    delay(10);

    while(1)
    {
        if(PORTAbits.RA1 == 0 && PORTAbits.RA0 == 0) {
            lcd_goto(0);
            send_string("MOTOR MOVE REVERSE");
        }
        else if(PORTAbits.RA1 == 0 && PORTAbits.RA0 == 1) {
            lcd_goto(0);
            send_string("NONE");
        }
        else if(PORTAbits.RA1 == 1 && PORTAbits.RA0 == 0) {
            lcd_goto(0);
            send_string("NONE");
        }
        else if(PORTAbits.RA1 == 1 && PORTCbits.RA0 == 1) {
            lcd_goto(0);
            send_string("MOTOR MOVE FORWARD");
        }
    }
}

void pic_init(void)
{
    TRISD = 0;
    TRISB = 0;
    TRISA = 0b00000011; // configure RA0 and RA1 as inputs
}
