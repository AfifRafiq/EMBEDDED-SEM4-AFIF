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

void pic_init(void);

void main()
{
    float a,b,c;
    unsigned int addition_value = 0;
    unsigned int division_value = 0;
    
    pic_init();
    lcd_init();
    delay(10);
    
    lcd_goto(0X00);
    send_string ("7+3=");
    lcd_goto(0x14);
    send_string ("7/3=0 00");
    lcd_goto(0x19);
    send_char(0b00101110);
    
    while(1)
    {
        addition_value = 7+3;
        lcd_goto(0x04);
        lcd_bcd (2, addition_value);
        
        division_value = 7/3;
        a=7/3;
        lcd_goto(0x18);
        lcd_bcd (1,a);
        
        b = ((7%3)*10)/3;
        lcd_goto(0x1A);
        lcd_bcd (1,b);
        
        c = ((((7%3)*10)%3)*10/3);
        lcd_goto(0x1B);
        lcd_bcd (1,c);
    }
}

void pic_init(void)
{
    TRISD = 0;
    TRISB = 0;
}
