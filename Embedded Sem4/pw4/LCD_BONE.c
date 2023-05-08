#define LDATA	PORTD
#define RS		PORTBbits.RB4
//#define RW		PORTBbits.RC6	//RW - connect to GND for always write
#define EN 		PORTBbits.RB5

void lcd_init(void);
void delay(unsigned int itime);
void e_pulse(void);
void send_config(unsigned char data);
void send_char(unsigned char data);
void lcd_goto(unsigned char data);
void send_string(const rom char*s);
void lcd_clr(void);
void lcd_bcd(unsigned char uc_digit, unsigned int ui_number);

//====================================
// Delay function
//====================================

void delay(unsigned int itime)
{
	unsigned int x,y;
	for(x=0;x<itime;x++);
	for(y=0;y<165;y++);
}

//====================================
// LCD Initialize
//====================================

void lcd_init(void)
{
	//LCD configuration
	send_config(0b00000001);
	send_config(0b00000010);
	send_config(0b00000110);
	send_config(0b00001100);
	send_config(0b00111000);
	
	delay(500);

	lcd_clr();
}

//====================================
// LCD function
//====================================

void e_pulse(void)
{
	EN=1;
	delay(500);
	EN=0;
	delay(500);
}

void send_config(unsigned char data)
{
	RS = 0;
	//RW = 0;
	LDATA = data;
	delay (500);
	e_pulse();
}

void send_char(unsigned char data)
{
	RS = 1;	
	//RW = 0;
	LDATA = data;
	delay(500);
	e_pulse();
}

void lcd_goto(unsigned char data)
{
	if (data<16)
	{
		send_config(0x80+data);
	}
	else
	{
		data=data-20;
		send_config(0xC0+data);
	}
}

void send_string(const rom char*s)
{
	RS = 1;
	while(*s)
	send_char(*s++);
}

void lcd_clr(void)
{
	RS = 0;
	send_config(0X01);
	delay(600);
}

//====================================
// BCD function
//====================================

void lcd_bcd(unsigned char uc_digit, unsigned int ui_number)
{
	unsigned int ui_decimal[5] ={ 0 };
	//extract 5 single digit from ui_number
		ui_decimal[4] = ui_number/10000;	// obtain the largest single digit, digit4 
		ui_decimal[3] = ui_number%10000;	// obtain the remainder 
		ui_decimal[2] = ui_decimal[3]%1000;			
		ui_decimal[3] = ui_decimal[3]/1000;			// obtain the 2nd largest single digit, digit3 
		ui_decimal[1] = ui_decimal[2]%100;
		ui_decimal[2] = ui_decimal[2]/100;			// obtain the 3rd largest single digit, digit2 
		ui_decimal[0] = ui_decimal[1]%10;			// obtain the smallest single digit, digit0 
		ui_decimal[1] = ui_decimal[1]/10;			// obtain the 4th largest single digit, digit1 
		
		if (uc_digit > 5) uc_digit = 5;			// limit to 5 digits only
		for( ; uc_digit > 0; uc_digit--)
		{
			send_char(ui_decimal[uc_digit - 1] + 0x30);			
		}
}
