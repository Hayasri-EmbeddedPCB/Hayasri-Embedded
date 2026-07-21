# 8051 UART - LED Control

## Description
Control LED ON/OFF via serial communication.
8051 receives character from PC and 
turns LED ON or OFF accordingly.

## Pin Configuration
| Pin  | Component | Port |
|------|-----------|------|
| LED  | LED Array | P1   |
| TXD  | Transmit  | P3.1 |
| RXD  | Receive   | P3.0 |

## UART Configuration
| Register | Value | Purpose          |
|----------|-------|------------------|
| TMOD     | 0x20  | Timer1 Mode2     |
| TH1      | 0xFD  | 9600 Baud rate   |
| SCON     | 0x50  | Mode1 + REN=1    |
| TR1      | 1     | Timer start      |

## How it Works
- PC sends '1' → LED ON  (P1=0xFF)
- PC sends '0' → LED OFF (P1=0x00)
- 8051 echoes "Hi!" on startup

## Functions
| Function      | Purpose              |
|---------------|----------------------|
| uart_init()   | UART initialize      |
| uart_send()   | Single char send     |
| uart_print()  | String send          |
| uart_receive()| Data receive from PC |

## Tools Used
- Keil uVision C51 (Compiler)
- Proteus 8 Professional (Simulation)

## Key Learning
- "data" is reserved in Keil C51
- Use "dat" instead of "data"
- '' for char, "" for string
