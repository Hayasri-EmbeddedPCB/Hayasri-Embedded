# 8051 ADC0808 + LCD Display

## Description
Reads analog voltage from potentiometer
using ADC0808 and displays value on
16x2 LCD using AT89C51 microcontroller.

## Components
| Component  | Purpose              |
|------------|----------------------|
| AT89C51    | Microcontroller      |
| ADC0808    | 8-channel ADC        |
| LM016L     | 16x2 LCD Display     |
| POT (RV1)  | Analog input (0-5V)  |

## Pin Configuration
### LCD (LM016L)
| LCD Pin | 8051 Port |
|---------|-----------|
| D0-D7   | P2.0-P2.7 |
| RS      | P3.0      |
| RW      | P3.1      |
| EN      | P3.2      |
