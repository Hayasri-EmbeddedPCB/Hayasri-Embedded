# PIC16F877A - Seven Segment 0-9 Counter

Displaying a continuous 0-9 count on a single 7-segment display using the PIC16F877A, written in C using the HI-TECH C compiler. PORTB cycles through a lookup array of segment patterns for each digit.

## Output

Single 7-segment display counts **0 → 1 → 2 → ... → 9** continuously, looping back to 0 after 9.


https://github.com/user-attachments/assets/2fd552c6-856e-490e-9c5a-c519f61142c5



## How It Works

| Line | What It Does |
|---|---|
| `unsigned char seg_code[]` | A lookup array holding the segment pattern for each digit 0-9, in order — index `0` holds the pattern for digit "0", index `9` holds the pattern for digit "9" |
| `TRISB=0x00;` | Sets PORTB as **output** to drive the display segments |
| `for(i=0;i<10;i++)` | Walks through the array index by index, sending each digit's pattern to PORTB with a delay in between |
| `while(1)` loop | Repeats the full 0-9 count endlessly |

## Segment Pattern Table

| Index | Value | Digit |
|---|---|---|
| 0 | `0x3F` | 0 |
| 1 | `0x06` | 1 |
| 2 | `0x5B` | 2 |
| 3 | `0x4F` | 3 |
| 4 | `0x66` | 4 |
| 5 | `0x6D` | 5 |
| 6 | `0x7D` | 6 |
| 7 | `0x07` | 7 |
| 8 | `0x7F` | 8 |
| 9 | `0x6F` | 9 |

These values assume a specific segment wiring order (PORTB pins to a-g). If wired differently, the same values would display different characters — verify against your own circuit if patterns look wrong.

## Hardware Setup (Proteus / Real Circuit)

- **PORTB (RB0-RB7)** — connects directly to the 7-segment display's segment pins (a-g), each through a current-limiting resistor (~330Ω)
- Single display, no multiplexing needed — this circuit drives just one 7-segment display directly from PORTB
- Common cathode or common anode wiring must match the segment pattern values used (this table assumes common cathode; common anode would need inverted values)

## Possible Improvements

- Use `_XTAL_FREQ` with `__delay_ms()` for precise, readable timing instead of the manual busy-wait loop
- Add a switch input to pause/reset the count instead of running automatically
- Extend to two digits (00-99) using multiplexing with transistors — see the multiplexed Seven Segment project for that pattern

## Tools Used

- **IDE:** MPLAB IDE v8.63
- **Compiler:** HI-TECH C for PIC10/12/16
- **MCU:** PIC16F877A
