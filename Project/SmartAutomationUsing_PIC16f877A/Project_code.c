
#include <pic.h>

#define _XTAL_FREQ 4000000

#define TEMP_ON  30
#define TEMP_OFF 28

unsigned char led_state = 0;
unsigned char relay_state = 0;

void update_outputs(void)
{
    PORTB = (unsigned char)((relay_state << 1) | led_state);
}

void uart_init(void)
{
    TRISC6 = 0;
    TRISC7 = 1;
    SPBRG = 25;
    TXSTA = 0x24;
    RCSTA = 0x90;
}

void uart_write(char c)
{
    while(!TXIF);
    TXREG = c;
}

void uart_text(const char *s)
{
    while(*s)
    {
        uart_write(*s);
        s++;
    }
}

char uart_read(void)
{
    while(!RCIF);
    return RCREG;
}

unsigned int adc_read(void)
{
    ADCON1 = 0x80;
    ADCON0 = 0x81;
    __delay_us(20);
    ADCON0 = ADCON0 | 0x04;
    while(ADCON0 & 0x04);
    return ((ADRESH << 8) | ADRESL);
}

float temperature(void)
{
    unsigned int adc = adc_read();
    return ((adc * 5.0) / 1023.0) * 100.0;
}

void print_temp(unsigned int t10)
{
    uart_text("Temp: ");
    if(t10 >= 1000) uart_write('0' + t10 / 1000);
    uart_write('0' + (t10 / 100) % 10);
    uart_write('0' + (t10 / 10) % 10);
    uart_write('.');
    uart_write('0' + t10 % 10);
    uart_text(" C  LED:");
    uart_write(led_state ? '1' : '0');
    uart_text(" RELAY:");
    uart_write(relay_state ? '1' : '0');
    uart_text("\r\n");
}

void main(void)
{
    float temp;
    unsigned int t10;
    unsigned char count = 0;
    char cmd;

    TRISB = 0x00;
    update_outputs();

    uart_init();
    uart_text("Smart Automation Ready\r\n");

    while(1)
    {
        temp = temperature();
        t10 = (unsigned int)(temp * 10);

        if(temp > TEMP_ON)
            relay_state = 1;
        else if(temp < TEMP_OFF)
            relay_state = 0;

        if(RCIF)
        {
            cmd = uart_read();
            uart_text("Got: ");
            uart_write(cmd);
            uart_text("\r\n");
            if(cmd == '1') led_state = 1;
            if(cmd == '0') led_state = 0;
            if(cmd == 'T') print_temp(t10);
        }

        update_outputs();

        if(RCSTA & 0x02)
        {
            RCSTA &= 0xEF;
            RCSTA |= 0x10;
        }

        count++;
        if(count >= 10)
        {
            count = 0;
            print_temp(t10);
        }

        __delay_ms(100);
    }
}
