# PIC16F877A - LED Blink (PORTB)

## Description
Idhu oru basic LED blinking program, PIC16F877A microcontroller ku, HI-TECH C compiler use panni eழுதapatta code. PORTB full ah output ah set panni, LED ah ON/OFF toggle pandrathu, software delay loop use panni.

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

| Line | Ennanu Panuthu |
|---|---|
| `#include<pic.h>` | HI-TECH C ku PIC register definitions kudukkura header file |
| `#define led PORTB` | PORTB ku "led" nu oru easy-to-read name kudukkuthu |
| `TRISB=0x00;` | PORTB full ah **output** mode ku set pannuthu (0 = output, 1 = input) |
| `led=0;` | Start la PORTB ella pins um LOW (LED OFF) |
| `delay()` function | Nested for-loop use panni oru software delay create pannuthu — CPU cycles busy ah irundhu time waste pannuthu, athanaala delay varuthu |
| `while(1)` loop | Infinite loop — LED ON pannitu delay, appuram OFF pannitu delay, idha continuously repeat pannuthu |

## Delay Calculation 

`delay()` function la `i` 100 thadava, `j` 1275 thadava loop aaguthu — so total **100 × 1275 = 127,500 iterations**. 





- `_XTAL_FREQ` correct ah define panni, `__delay_ms()` built-in function use pannunga — more accurate & readable
- Single LED (`RB0`) mattum toggle panna try pannunga, `RB0 = 1;` / `RB0 = 0;` mari
- Timer0 interrupt use panni delay create pannunga — CPU busy-wait pannama
