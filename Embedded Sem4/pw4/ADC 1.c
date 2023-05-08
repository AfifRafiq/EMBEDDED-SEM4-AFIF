#include <p18f4580.h>
#include "LCD_BONE.c"
#include "ADC_BONE.c"

#pragma config OSC = HS
#pragma config FCMEN = OFF
#pragma config IESO = OFF
#pragma config PWRT = OFF
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

#define	 LED1 PORTEbits.RE0

void main(void)
{
    pic_init();
    lcd_init();
    adc_init();
    lcd_goto(0x00);
    send_string("ADC:            ");

    while (1)
    {
        unsigned long adc_value = 0;
        unsigned vin;
        int temp;
        unsigned char j;

        adc_on();

        for (j = 0; j < 100; j++)
        {
            adc_value = adc_value + ui_adc_read();
        }
        adc_value = adc_value / 100;

        lcd_goto(0x06);
        lcd_bcd(4, adc_value);
    }
}

void pic_init(void)
{
    TRISA = 0xFF;
    TRISB = 0x00;
    TRISD = 0x00;
}
