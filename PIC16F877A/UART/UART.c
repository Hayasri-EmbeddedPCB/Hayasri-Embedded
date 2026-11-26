#include<pic.h>
#define _XTAL_FREQ 5000000
#define RS RB0
#define RW RB1
#define EN RB2
#define lcd_data PORTD

void lcd_cmd(unsigned char x){
    lcd_data=x;
    RS=0;
    RW=0;
    EN=1;
    __delay_ms(2);
    EN=0;
    __delay_ms(2);
}

void lcd_dat(unsigned char y){
    lcd_data=y;
    RS=1;
    RW=0;
    EN=1;
    __delay_ms(2);
    EN=0;
    __delay_ms(2);
}

void lcd_init(){
    __delay_ms(20);
    lcd_cmd(0x38);
    lcd_cmd(0x0E);
    lcd_cmd(0x06);
    lcd_cmd(0x01);
    lcd_cmd(0x0C);
    lcd_cmd(0x80);
}

void lcd_show(const unsigned char *str){
    while(*str){
        lcd_dat(*str);
        str++;
    }
}

void uart_init(){
    TRISC6=0;
    TRISC7=1;
    SPBRG=32;
    TXSTA=0x24;
    RCSTA=0x90;
}

void uart_tx(unsigned char data){
    while(!TXIF);
    TXREG=data;
}

unsigned char uart_rx(){
    while(!RCIF){
        if(RCSTA & 0x02){        // overrun error aana receiver reset
            RCSTA &= 0xEF;
            RCSTA |= 0x10;
        }
    }
    return RCREG;
}

void main(){
    unsigned char rec_data;
    TRISB=0x00;
    TRISC=0x80;
    TRISD=0x00;
    lcd_init();
    uart_init();

    lcd_cmd(0x80);
    lcd_show("LCD OK");

    while(1){
        rec_data=uart_rx();
        uart_tx(rec_data);       // terminal ku echo
        lcd_cmd(0x01);
        lcd_cmd(0x80);
        if(rec_data=='a'){
            lcd_show("UART READY");
        }
        else{
            lcd_show("UART NOT READY");
        }
    }
}
