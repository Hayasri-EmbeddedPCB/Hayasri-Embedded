#include<pic.h>
#define _XTAL_FREQ 2000000
#define RS RB0
#define RW RB1
#define EN RB2
#define lcd_data PORTC
void delay(){
unsigned int i,j;
for(i=0;i<100;i++){
for(j=0;j<1275;j++){
}
}
}
void lcd_cmd(unsigned char x){
					        PORTC=x;
							RS=0;
							RW=0;
							EN=1;
							delay();
							EN=0;
							}
							void lcd_dat(unsigned char y){
			                PORTC=y;
							RS=1;
							RW=0;
							EN=1;
							delay();
							EN=0;
							}
void lcd_init(){
	lcd_cmd(0x38);
		lcd_cmd(0x0E);
			lcd_cmd(0x06);
				lcd_cmd(0x01);
					lcd_cmd(0x0C);
						lcd_cmd(0x80);
						}
							void lcd_show(unsigned char *str){
								while(*str){
									lcd_dat(*str++);
									}
									}
									void main(){
										TRISB=0x00;
										TRISC=0x00;
										lcd_init();
										while(1){
											lcd_cmd(0x80);
											lcd_show("Hayasri TV");
											lcd_cmd(0xC0);
											lcd_show("Embedded Student");
											delay();
										}
	}
											
											
											
