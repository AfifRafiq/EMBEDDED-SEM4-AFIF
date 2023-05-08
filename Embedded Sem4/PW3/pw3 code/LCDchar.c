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
		lcd_goto(0);
		send_char ('D');
		send_char ('E');
		send_char ('C');
		send_char ('4');
		send_char ('0');
		send_char ('0');
		send_char ('5');
		send_char ('3');
		
		lcd_goto(20);
		send_char ('E');
		send_char ('M');
		send_char ('B');
		send_char ('E');
		send_char ('D');
		send_char ('D');
		send_char ('E');
		send_char ('D');
		send_char (' ');
		send_char ('S');
		send_char ('Y');
		send_char ('S');
		send_char ('T');
		send_char ('E');
		send_char ('M');
	}
}

void pic_init(void)
{
	TRISD = 0;
	TRISB = 0;
}