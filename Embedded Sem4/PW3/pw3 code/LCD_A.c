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
		send_string("DEC40053");
		lcd_goto(20);
		send_string("EMBEDDED SYSTEM");
	}
}

void pic_init (void)
{
	TRISD = 0;
	TRISB = 0;
{