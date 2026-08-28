# PIC16F877A - Seven Segment Display Multiplexing

Displaying two digits on two 7-segment displays using time-division multiplexing on the PIC16F877A, written in C using the HI-TECH C compiler. NPN transistors switch each display's common pin ON/OFF while PORTC drives the shared segment lines.

## Output

Displays **"0"** and **"9"** — confirmed correct on the two 7-segment displays.


https://github.com/user-attachments/assets/e3a7050a-91a1-40cb-85f8-b3e73d3589d0



## How It Works

| Line | What It Does |
|---|---|
| `#define digital_control1 RB0`, `#define digital_control2 RB1` | Control pins driving the base of two NPN transistors (Q1, Q2), each switching one display's common pin |
| `#define led PORTC` | Alias for the shared segment data bus (a-g) connected to both displays |
| `TRISC=0x00; TRISB=0x00;` | Sets PORTC (segment data) and PORTB (transistor control) as output |
| `digital_control1=1; led=0x3F; digital_control2=0;` | Turns Display 1 ON (via Q1), sends the "0" segment pattern, keeps Display 2 OFF |
| `digital_control1=0; led=0x6F; digital_control2=1;` | Turns Display 1 OFF, sends the "9" segment pattern, turns Display 2 ON (via Q2) |
| `while(1)` loop | Repeats the two-display cycle continuously |

## Multiplexing Concept

Both displays share the same 8 segment lines (PORTC), but only one display is actually powered at a time — controlled by its transistor. By switching between displays fast enough, the human eye perceives both digits as being lit simultaneously (persistence of vision).

**Key point:** if the delay between switches is too short, the eye may perceive overlapping segments (looks like "8" on both). If it's too long, visible flickering occurs. The current `j<1000` delay gives clean, correctly separated digits.

## Segment Values Used

| Value | Character | Segments ON (a-g) |
|---|---|---|
| `0x3F` | 0 | a, b, c, d, e, f |
| `0x6F` | 9 | a, b, c, d, f, g |

These values are specific to this circuit's exact wiring (RC0→a, RC1→b, RC2→c, RC3→d, RC4→e, RC5→f, RC6→g). If segments were wired in a different order, the same hex values would produce different characters.

## Hardware Setup (Proteus / Real Circuit)

- **PORTC (RC0-RC6)** — shared segment lines, connected to both displays' a-g pins (with current-limiting resistors)
- **RB0, RB1** — connect through a base resistor (10kΩ used here) to the base of Q1 and Q2 (NPN transistors, e.g. BC547/2N2222)
- **Transistor collector** — connects to the display's common pin
- **Transistor emitter** — connects to GND (common cathode displays)

## Common Mistakes to Avoid

- **Connecting a display's common pin directly to an MCU pin** (via a switch, not a transistor) — the transistor is what allows the MCU to safely switch the higher current the display draws
- **Assuming standard hex values always mean the same digit** — segment wiring order must match, or `0x3F` might display something other than "0"
- **Delay too short or too long** — tune it so multiplexed digits look clean and steady, not overlapping or flickering

## Possible Improvements

- Extend to more digits (3-4 displays) using the same multiplexing pattern with additional transistors
- Use a lookup table/array of segment patterns for all digits 0-9 instead of hardcoding two values
- Replace the busy-wait `delay()` with a Timer interrupt for more precise, consistent refresh timing

## Tools Used

- **IDE:** MPLAB IDE v8.63
- **Compiler:** HI-TECH C for PIC10/12/16
- **MCU:** PIC16F877A
- **Transistors:** NPN (e.g. BC547 / 2N2222)
