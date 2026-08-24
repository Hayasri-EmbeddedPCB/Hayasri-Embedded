# PIC16F877A - LED Blink (PORTB)

A basic LED blinking program for the PIC16F877A microcontroller, written in C using the HI-TECH C compiler. PORTB is configured as output and toggled ON/OFF using a software delay loop.

## Code

```c
#include<pic.h>
#define _xtal_frequency 2000000
#define led PORTB

void delay(){
    unsigned int i,j;
    for(i=0;i<100;i++){
        for(j=0;j<1275;j++){
        }
    }
}

void main(){
    TRISB=0x00;
    led=0;
    while(1){
        led=1;
        delay();
        led=0;
        delay();
    }
}
```

## How It Works

| Line | What It Does |
|---|---|
| `#include<pic.h>` | Header file that provides PIC register definitions for HI-TECH C |
| `#define led PORTB` | Gives PORTB an easy-to-read alias, `led` |
| `TRISB=0x00;` | Sets PORTB as **output** (0 = output, 1 = input) |
| `led=0;` | Initializes all PORTB pins LOW (LEDs OFF) |
| `delay()` function | A nested for-loop that creates a software delay by keeping the CPU busy for a period of time |
| `while(1)` loop | Infinite loop — turns the LED ON, delays, turns it OFF, delays, and repeats |

## About the Delay

The `delay()` function loops `i` 100 times and `j` 1275 times per outer iteration — a total of **100 x 1275 = 127,500 iterations**. 

- It's a **software delay**, not based on a hardware timer
- Actual delay depends on the crystal frequency and compiler optimization level
- For precise timing, use the Timer0/Timer1 modules instead

