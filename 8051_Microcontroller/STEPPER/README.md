# 8051 Stepper Motor - Half Step Control

## Description
Controls stepper motor in Half Step mode
using AT89C51 microcontroller.
Half step = 8 steps per cycle (smooth rotation!)

## Pin Configuration
| 8051 Pin | Stepper Coil |
|----------|--------------|
| P2.0     | Coil A       |
| P2.1     | Coil B       |
| P2.2     | Coil C       |
| P2.3     | Coil D       |

## Half Step Sequence (8 Steps)
| Step | P2 Value | Coil Status      |
|------|----------|------------------|
| 1    | 0x08     | A only           |
| 2    | 0x0C     | A + B            |
| 3    | 0x04     | B only           |
| 4    | 0x06     | B + C            |
| 5    | 0x02     | C only           |
| 6    | 0x03     | C + D            |
| 7    | 0x01     | D only           |
| 8    | 0x09     | D + A            |

## Half Step vs Full Step
| Feature      | Full Step  | Half Step    |
|--------------|------------|--------------|
| Steps/cycle  | 4 steps    | 8
