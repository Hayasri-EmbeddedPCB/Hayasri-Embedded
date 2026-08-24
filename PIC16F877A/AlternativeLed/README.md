# PIC16F877A - LED Chaser / Running Light (PORTC)

An LED chaser (Knight Rider style) pattern for the PIC16F877A, written in C using the HI-TECH C compiler. A single lit bit shifts left across PORTC, then shifts back right, creating a back-and-forth running light effect.

## Code

```c
#include<pic.h>
#define _xtal_frequency 200000
#define led PORTC

void delay(){
    unsigned int i,j;
    for(i=0;i<100;i++){
        for(j=0;j<1275;j++){
        }
    }
}

void main(){
    unsigned char k;
    TRISC=0x00;
    led=0;
    while(1){
        for(k=0x01;k<=0x80;k<<=1){
            led=k;
            delay();
        }
        for(k=0x80;k>=0x01;k>>=1){
            led=k;
            delay();
        }
    }
}
```

## How It Works

| Line | What It Does |
|---|---|
| `#define led PORTC` | Alias for PORTC, this time instead of PORTB |
| `TRISC=0x00;` | Sets PORTC as **output** |
| `unsigned char k;` | 8-bit variable used as a shifting bitmask, one for each PORTC pin (RC0-RC7) |
| First `for` loop | `k` starts at `0x01` (binary `00000001`) and left-shifts (`k<<=1`) each time — `0x01 -> 0x02 -> 0x04 ... -> 0x80`. This lights up one LED at a time, moving from RC0 towards RC7 |
| Second `for` loop | `k` starts at `0x80` and right-shifts (`k>>=1`) back down to `0x01` — the lit LED moves from RC7 back to RC0 |
| `while(1)` loop | Repeats the left-to-right, right-to-left sweep forever |

This gives the classic "Knight Rider" back-and-forth LED chaser effect across 8 LEDs.

## About the Delay

Same software delay loop as before: **100 x 1275 = 127,500 iterations** per call. This is an approximate delay, not based on a hardware timer, so the actual blink speed depends on the crystal frequency and compiler optimization level.

## Note: Typo in Macro Name

ck this matches your actual crystal.

## Hardware Setup (Proteus / Real Circuit)

- Connect 8 LEDs to **PORTC (RC0-RC7)**, each with a 330 ohm current-limiting resistor
- Connect a crystal oscillator matching your config bit frequency setting
- Add a 10k ohm pull-up resistor on the `MCLR` pin

## Possible Improvements

- Fix `_XTAL_FREQ` and use `__delay_ms()` for accurate, adjustable timing
- Add a second byte/loop for a dual-LED chaser effect
- Make the pattern direction/speed configurable via a switch input

## Tools Used

- **IDE:** MPLAB IDE v8.63
- **Compiler:** HI-TECH C for PIC10/12/16
- **MCU:** PIC16F877A
