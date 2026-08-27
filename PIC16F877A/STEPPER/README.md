# PIC16F877A - Stepper Motor Control (Wave Drive)

Basic stepper motor rotation using the PIC16F877A, written in C using the HI-TECH C compiler. PORTB drives a ULN2003 (or similar) driver connected to the stepper motor coils, cycling through a 4-step wave drive sequence.

## How It Works

| Line | What It Does |
|---|---|
| `#define motor PORTB` | Alias for PORTB, which drives the motor coils |
| `unsigned char full_steps[]` | An array holding the 4-step wave drive sequence — each value energizes one coil at a time |
| `TRISB=0x00;` | Sets PORTB as **output** so it can drive the motor driver IC |
| `for(i=0;i<4;i++)` loop | Cycles through the 4 step values in order, applying each to PORTB with a delay in between |
| `while(1)` loop | Repeats the 4-step sequence continuously, producing continuous rotation |

## About the Step Sequence

```c
unsigned char full_steps[]={0x80,0x04,0x02,0x01};
```

This is a **wave drive (single-phase)** sequence — only one coil is energized at a time (RB7 → RB2 → RB1 → RB0). It's simple and low-power, but produces less torque than other drive modes.

**Alternative — two-phase full step** (stronger torque, two coils energized together):
```c
unsigned char full_steps[]={0xC0,0x60,0x30,0x90};
```

**Half-step** (smoother rotation, double the resolution) combines both patterns into an 8-step sequence.

## Hardware Setup (Proteus / Real Circuit)

- **PORTB (RB0-RB7)** connects to a motor driver IC (e.g. ULN2003 or L293D) — never connect the stepper coils directly to MCU pins, they draw more current than a PIC pin can safely supply
- Driver IC outputs connect to the 4 stepper motor coil leads
- Motor's separate power supply (driver Vcc) should match the stepper's rated voltage — keep it separate from the PIC's 5V logic supply where possible
- Common ground between the PIC, driver IC, and motor supply

## Possible Improvements

- Switch to two-phase full step or half-step sequence for smoother, stronger rotation
- Add a direction control (reverse the array traversal for CCW rotation)
- Add a speed control input (potentiometer via ADC) to vary the delay dynamically
- Replace the busy-wait `delay()` with a Timer interrupt for more consistent step timing

## Demo


https://github.com/user-attachments/assets/81586276-f8b6-4c80-8911-e2b41cfda1e9




## Tools Used

- **IDE:** MPLAB IDE v8.63
- **Compiler:** HI-TECH C for PIC10/12/16
- **MCU:** PIC16F877A
- **Motor Driver:** ULN2003 (or equivalent)
