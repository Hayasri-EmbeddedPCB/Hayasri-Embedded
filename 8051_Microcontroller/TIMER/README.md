# 8051 Timer - LED Blink

## Description
LED blinks every 500ms using 8051 
hardware Timer0 (Mode1 - 16-bit).

## Pin Configuration
- LEDs → P1 (P1.0 to P1.7)

## Timer Configuration
- Timer0, Mode1 (16-bit)
- TMOD = 0x01
- TH0 = 0xEE, TL0 = 0x00 (~5ms)
- delay_ms(5000) → 5ms blink

## Tools
- Keil uVision C51
- Proteus 8 Professional

## Registers Used
| Register | Value | Purpose |
|----------|-------|---------|
| TMOD | 0x01 | Timer0 Mode1 |
| TH0 | 0xEE | High byte |
| TL0 | 0x00 | Low byte |
| TR0 | 1/0 | Start/Stop |
| TF0 | flag | Overflow check |
