//This is Header.h program

//----PIC Setup----
//----LCD Setup----

extern void lcd_init(void);
extern void delay(unsigned int itime);
extern void e_pulse(void);
extern void send_config(unsigned char data);
extern void send_char(unsigned char data);
extern void lcd_goto(unsigned char data);
extern void send_string(const rom char*s);
extern void lcd_clr(void);