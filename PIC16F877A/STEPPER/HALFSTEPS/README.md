

https://github.com/user-attachments/assets/e3062b1d-5270-41a4-805a-463ba70da387

# PIC16F877A - Stepper Motor Control (Half Step)

Smoother stepper motor rotation using the PIC16F877A, written in C using the HI-TECH C compiler. Uses an 8-step half-step sequence on PORTB — double the resolution of wave drive, with smoother, more precise rotation.
## How It Works

| Line | What It Does |
|---|---|
| `unsigned char half_steps[]` | 8-step sequence array — alternates between single-coil and dual-coil energizing |
| `for(i=0;i<8;i++)` loop | Cycles through all 8 steps in order, applying each to PORTB with a delay in between |
| `while(1)` loop | Repeats the 8-step sequence continuously for continuous rotation |

## Wave Drive vs Half Step

| | Wave Drive (4 steps) | Half Step (8 steps) |
|---|---|---|
| Steps per cycle | 4 | 8 |
| Coils energized | 1 at a time | Alternates 1 then 2 |
| Resolution | Standard (e.g. 1.8° per step) | Double (e.g. 0.9° per step) |
| Torque | Lower | Higher on the 2-coil steps, more consistent overall |
| Smoothness | More vibration | Smoother rotation |

The half-step sequence is built by interleaving the single-phase steps (`0x80, 0x04, 0x02, 0x01`) with the two-phase steps (`0x84, 0x06, 0x03, 0x81`), so each intermediate position energizes both adjacent coils together before moving to the next single coil.

## Hardware Setup (Proteus / Real Circuit)

- **PORTB (RB0-RB7)** connects to a motor driver IC (e.g. ULN2003 or L293D) — never connect the stepper coils directly to MCU pins
- Driver IC outputs connect to the 4 stepper motor coil leads
- Motor's separate power supply (driver Vcc) should match the stepper's rated voltage — keep it separate from the PIC's 5V logic supply where possible
- Common ground between the PIC, driver IC, and motor supply

## Possible Improvements

- Add a direction control (reverse the array traversal for CCW rotation)
- Add a speed control input (potentiometer via ADC) to vary the delay dynamically
- Replace the busy-wait `delay()` with a Timer interrupt for more consistent step timing
- Try microstepping (PWM-based) for even finer resolution, if the driver supports it

## Demo
#[HalfSteps.mp4]

## Tools Used

- **IDE:** MPLAB IDE v8.63
- **Compiler:** HI-TECH C for PIC10/12/16
- **MCU:** PIC16F877A
- **Motor Driver:** ULN2003 (or equivalent)
