#include<reg51.h>

#define lcd_data P2

sbit RS = P3^0;
sbit RW = P3^1;
sbit EN = P3^2;

// ADC0808 pins
sbit ADDR_A = P1^0;
sbit ADDR_B = P1^1;
sbit ADDR_C = P1^2;
sbit ALE    = P1^3;
sbit SOC    = P1^4;
sbit EOC    = P1^5;
sbit OE     = P1^6;

void delay() {
    unsigned int i,j;
    for(i=0;i<100;i++) {
        for(j=0;j<1275;j++) {  
        }
    }
}

void lcd_cmd(unsigned char cmd) {
    lcd_data = cmd;
    RS = 0;
    RW = 0;
    EN = 1;         
    delay();
    EN = 0;
}

void lcd_dat(unsigned char dat) {
    lcd_data = dat;
    RS = 1;
    RW = 0;
    EN = 1;         
    delay();
    EN = 0;
}

void lcd_init() {
    lcd_cmd(0x38);  
    lcd_cmd(0x0E);
    lcd_cmd(0x01);
    lcd_cmd(0x06);
    lcd_cmd(0x0C);
    lcd_cmd(0x80);
}

void lcd_print(unsigned char *str) {
    while(*str) {
        lcd_dat(*str++);  
    }
}

unsigned char adc_value() {
    ADDR_A=0; ADDR_B=0; ADDR_C=0;  
    ALE=1; SOC=1;       
    delay();
    ALE=0; SOC=0;
    while(EOC==0);      
    OE=1;
    delay();           
    OE=0;
    return P0;          
}

void main() {
    unsigned char adc;
    unsigned int voltage;
    unsigned char d1,d2,d3;

    lcd_init();
    lcd_print("ADC Value:");  

    while(1) {
        adc     = adc_value();
        voltage = (adc * 500) / 255;  
        d1 = (voltage/100) + 48;       // ? hundreds
        d2 = (voltage%100/10) + 48;    // ? tens
        d3 = (voltage%10) + 48;        // ? units
        lcd_cmd(0x80);      
        lcd_print("ADC Value:");
        lcd_cmd(0xC0);      // Line 2 start
        lcd_dat(d1);        // display digits
        lcd_dat('.');
        lcd_dat(d2);
        lcd_dat(d3);
        lcd_dat('V');
        delay();
    }
}
