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

#define sw1 PORTCbits.RC0
#define sw2 PORTCbits.RC1

void pic_init(void);

void main()
{
    pic_init();
    lcd_init();
    delay(1000);

    while(1)
    {
        if(PORTCbits.RC1 == 0 && PORTCbits.RC0 == 0) {
			lcd_clr();
            lcd_goto(0);
            send_string("MOTOR MOVE REVERSE");
        }
        else if(PORTCbits.RC1 == 0 && PORTCbits.RC0 == 1) {
            lcd_goto(0);
			lcd_clr();
            send_string("NONE");
        }
        else if(PORTCbits.RC1 == 1 && PORTCbits.RC0 == 0) {
            lcd_goto(0);
			lcd_clr();
            send_string("NONE");
        }
        else if(PORTCbits.RC1 == 1 && PORTCbits.RC0 == 1) {
            lcd_goto(0);
			lcd_clr();
            send_string("MOTOR MOVE FORWARD");
        }
    }
}

void pic_init(void)
{
    TRISD = 0;
    TRISB = 0;
    TRISC = 0b00000011; // configure RC0and RC1as inputs
}
