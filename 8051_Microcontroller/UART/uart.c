#include<reg51.h>

#define led P1

void uart_init() {
    TMOD = 0x20;
    TH1  = 0xFD;
    SCON = 0x50;
    TR1  = 1;
}

void uart_send(unsigned char dat) {
    SBUF = dat;
    while(TI == 0);
    TI = 0;
}

unsigned char uart_receive() {      
    while(RI == 0);
    RI = 0;
    return SBUF;
}

void uart_print(unsigned char *str) {
    while(*str != '\0') {
        uart_send(*str);
        str++;                      
    }
}

void main() {
    unsigned char received;         
    uart_init();
    uart_print("Hi!");            

    while(1) {
        received = uart_receive();

        if(received == '1') {       
            led = 0xFF;             
        }
        if(received == '0') {       
            led = 0x00;             
        }
    }
}
