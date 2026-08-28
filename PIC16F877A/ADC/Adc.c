#include<pic.h>
#define _XTAL_FREQ 2000000
#define meter PORTA
#define RS RB0
#define RW RB1
#define EN RB2
#define lcd_data PORTC
	void delay(){
unsigned int i,j;
	for(i=0;i<100;i++){
		for(j=0;j<1245;j++){
			}
			}
			}
void lcd_cmd(unsigned char x){
	lcd_data=x;
	RS=0;
	RW=0;
	EN=1;
	delay();
	EN=0;
	}
	void lcd_dat(unsigned char y){
	lcd_data=y;
	RS=1;
	RW=0;
	EN=1;
	delay();
	EN=0;
	}
void lcd_init(){
	lcd_cmd(0x38);
		lcd_cmd(0x0E);
			lcd_cmd(0x01);
				lcd_cmd(0x06);
					lcd_cmd(0xC0);
						lcd_cmd(0x80);
						}
unsigned adc_result(){
ADCON0=0x81;
ADCON1=0x80;
ADCON0 = ADCON0 | 0x04;
while(ADCON0 & 0x04);
return ((unsigned int)ADRESH << 8) | ADRESL;
	}
	void lcd_show(const unsigned char *str)
{
		while(*str)
{
			lcd_dat(*str);
            str++;
			}
			}
			void main(){
            TRISB=0x00;
            TRISC=0x00;
            TRISA=0xFF;
lcd_init();
			unsigned int adc_value,voltage;
			unsigned char d1,d2,d3;
		
			while(1){
adc_value=adc_result();
				voltage=(adc_value*500/1023);
				d1=(voltage/100)+48;
				d2=((voltage/10)%10)+48;
				d3=(voltage%10)+48;
				lcd_cmd(0x80);
				 lcd_dat('A');
        lcd_dat('D');
        lcd_dat('C');
        lcd_dat(' ');
        lcd_dat('V');
        lcd_dat('a');
        lcd_dat('l');
        lcd_dat('u');
        lcd_dat('e');
				lcd_cmd(0xC0);
					lcd_dat(d1);
						lcd_dat('.');
							lcd_dat(d2);
								lcd_dat(d3);
									lcd_show('v');
									delay();
									}
									}
									
									
				
	
	
	
