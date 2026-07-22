#include<reg51.h>

sbit SDA = P2^0;
sbit SCL = P2^1;

void i2c_start() {
    SDA = 1;
    SCL = 1;
    SDA = 0;        
    SCL = 0;       
}

void i2c_stop() {
    SDA = 0;
    SCL = 1;        
    SDA = 1;        
}

void i2c_write(unsigned char dat) {
    unsigned char i;
    for(i=0; i<8; i++) {
        if(dat & 0x80)
            SDA = 1;
        else
            SDA = 0;
        SCL = 1;
        SCL = 0;
        dat <<= 1;
    }
    SDA = 1;   
    SCL = 1;
    SCL = 0;
}

unsigned char i2c_read() {
    unsigned char i, dat = 0;
    SDA = 1;
    for(i=0; i<8; i++) {
        SCL = 1;
        dat <<= 1;
        if(SDA) dat |= 0x01;
        SCL = 0;
    }
    return dat;
}

void main() {
    
    i2c_start();
    i2c_write(0xA0);    
    i2c_write(0x00);    
    i2c_write(0x55);    
    i2c_stop();

    while(1);
}
