# 8051 External Interrupt - LED Toggle

## Description
LED toggles ON/OFF every time a switch 
is pressed using External Interrupt INT0
on AT89C51 microcontroller.

## Pin Configuration
| Pin  | Component | Port  |
|------|-----------|-------|
| LED  | LED       | P1^0  |
| S1   | Switch    | P3^2  |

## Interrupt Configuration
| Register | Value | Purpose          |
|----------|-------|------------------|
| EA       | 1     | Global Enable    |
| EX0      | 1     | INT0 Enable      |
| IT0      | 1     | Edge Triggered   |
| ISR      | 0     | interrupt 0      |

## How it Works
- Switch press → INT0 triggers
- ISR executes → LED toggles (~led)
- Main loop → empty while(1)

## Tools Used
- Keil uVision C51 (Compiler)
- Proteus 8 Professional (Simulation)

## Key Concept
Toggle = ~led
- LED OFF (0) → ~led → LED ON  (1)
- LED ON  (1) → ~led → LED OFF (0)
