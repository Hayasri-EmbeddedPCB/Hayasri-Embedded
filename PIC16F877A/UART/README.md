# PIC16F877A - UART Receive with 16x2 LCD Status Display

Receives a character from a serial terminal through the PIC16F877A hardware USART and shows a status message on a 16x2 LCD. Written in embedded C (HI-TECH C, MPLAB IDE v8.63) and tested in Proteus with a Virtual Terminal.

## What It Does

| Character sent from terminal | LCD shows (line 1) |
|---|---|
| `a` | `UART READY` |
| any other character | `UART IS NOT READY` |

The program waits for one character, checks it, updates the LCD, and waits for the next one.

## Pin Mapping

| PIC pin | Function | Connected to |
|---|---|---|
| RB0 | LCD RS | LCD pin 4 |
| RB1 | LCD RW | LCD pin 5 |
| RB2 | LCD EN | LCD pin 6 |
| RD0 - RD7 | LCD data D0 - D7 | LCD pins 7 - 14 |
| RC6 / TX | UART transmit | Virtual Terminal RXD |
| RC7 / RX | UART receive | Virtual Terminal TXD |
| MCLR | Reset | Pull-up to +5 V |

LCD data is on PORTD so that RC6 and RC7 stay free for the USART. If the LCD data bus shared PORTC with the UART pins, RC7 would conflict.

## UART Configuration

Clock: 5 MHz, BRGH = 1 (high speed), `SPBRG = 32`

```
Baud = Fosc / (16 x (SPBRG + 1)) = 5,000,000 / (16 x 33) = about 9470 baud
```

This is about 1.4 % away from 9600, which is within the tolerance of the Virtual Terminal.

| Register | Value | Meaning |
|---|---|---|
| `SPBRG` | 32 | Baud rate generator |
| `TXSTA` | `0x24` | TXEN = 1 (transmit enabled), BRGH = 1 |
| `RCSTA` | `0x90` | SPEN = 1 (serial port on), CREN = 1 (continuous receive) |
| `TRISC` | `0x80` | RC7 (RX) input, RC6 (TX) and the rest output |

Terminal settings: 9600 baud, 8 data bits, no parity, 1 stop bit.

## How It Works

1. `lcd_init()` sets the LCD to 8-bit, 2-line mode, display on, cursor off, and clears it.
2. `uart_init()` turns on the USART with continuous receive.
3. `uart_rx()` blocks until the receive flag `RCIF` is set, then returns the byte from `RCREG`. Reading `RCREG` clears the flag automatically.
4. `main()` moves the cursor to line 1 (`0x80`), compares the byte with `'a'` and prints the matching message through `lcd_show()`.

LCD writes use the standard HD44780 sequence: put the byte on the data bus, set RS (0 for command, 1 for data), pulse EN high then low.

## How to Test (Proteus)

1. Build in MPLAB and load the `.hex` file into U1.
2. Set the U1 Processor Clock Frequency to 5 MHz.
3. Set the Virtual Terminal to 9600 baud, 8 data bits, no parity, 1 stop bit.
4. Wire RC6 to RXD and RC7 to TXD (crossed), with no junction dot where the wires cross.
5. Run the simulation, click inside the terminal window and type `a`, then any other key.

## Output






https://github.com/user-attachments/assets/3c336489-c0a1-4c4e-887d-f61f90a65b50






## Known Limitations

- **Leftover characters on the LCD.** `UART IS NOT READY` (17 characters) is longer than `UART READY` (10 characters). Writing the short message over the long one leaves old characters behind, so the display can show text such as `UART READYT READY`. Clearing the display (`lcd_cmd(0x01)`) before each message, or padding the short message with spaces, fixes this.
- **Message longer than one line.** A 16x2 LCD shows 16 characters per line, and `UART IS NOT READY` is 17, so the last character falls outside the visible area. A shorter text such as `UART NOT READY` fits.
- **Blocking receive.** `uart_rx()` waits forever, so the program cannot do anything else while waiting for a character. An interrupt-driven receive would remove this limit.
- **No framing or overrun handling.** If the receiver overruns, CREN must be toggled to recover.
- `uart_tx()` is defined but not used in this version; it can be used to echo the received character back to the terminal.

## Possible Improvements

- Clear the LCD before each message and use shorter text
- Echo the received character with `uart_tx()` and show it on line 2
- Use the receive interrupt (`RCIE`, `PEIE`, `GIE`) instead of polling
- Add overrun error recovery (`OERR` check)
- Accept whole strings (for example a command ending in carriage return) instead of single characters

## Tools Used

- **MCU:** PIC16F877A
- **IDE and compiler:** MPLAB IDE v8.63, HI-TECH C for PIC10/12/16
- **Simulation:** Proteus 8 (Virtual Terminal, LM016L LCD)
- **Language:** Embedded C
