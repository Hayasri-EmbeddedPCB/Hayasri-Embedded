# Smart Automation System using PIC16F877A

A temperature-controlled automation node built on the PIC16F877A. An LM35 sensor is sampled through the 10-bit ADC, a relay switches a 12 V load automatically using a hysteresis band, and an LED is controlled remotely over UART. Live status is streamed to a serial terminal. The design was built and verified in Proteus 8 using embedded C (HI-TECH C, MPLAB IDE v8.63).

## Objectives

- Read an analog sensor through the on-chip ADC and convert the reading to degrees Celsius
- Switch a high-power load safely using a transistor-driven relay with a flyback diode
- Avoid relay chatter near the set-point by using hysteresis control
- Implement a simple command protocol over the hardware USART
- Document the full design, including the bugs found while debugging
## Simulation Results



https://github.com/user-attachments/assets/250c9530-5514-494f-9f87-1db7936d1ca9


## Features

| Feature | Description |
|---|---|
| Temperature sensing | LM35 on RA0 (AN0), 10-bit ADC, right-justified result |
| Automatic relay control | ON above 30 C, OFF below 28 C (2 C hysteresis) |
| Remote LED control | Commands sent over UART |
| Telemetry | Temperature, LED state and relay state printed about once per second |
| UART error recovery | Receiver is re-enabled automatically after an overrun error |

## System Overview

```
 LM35 --(Vout)--> RA0/AN0 ----+
                              |
                         PIC16F877A ---- RB0 --[330R]--> LED
                          (4 MHz)   |
                                    +--- RB1 --[1k]--> BC547 --> Relay coil (+1N4007)
                                    |                              |
                                    |                              +--> Relay contact --> 12 V lamp
                                    +--- RC6 (TX) --> Terminal RXD
                                    +--- RC7 (RX) <-- Terminal TXD
```

## Pin Mapping

| PIC pin | Function | Connected to |
|---|---|---|
| RA0 / AN0 | Analog input | LM35 Vout |
| RB0 | Digital output | LED through a 330 ohm resistor |
| RB1 | Digital output | BC547 base through a 1 kohm resistor |
| RC6 / TX | UART transmit | Virtual Terminal RXD |
| RC7 / RX | UART receive | Virtual Terminal TXD |
| MCLR | Reset | 10 kohm pull-up to +5 V |

## Hardware Design Notes

- **Relay driver:** The relay coil needs more current than a PIC pin can supply, so RB1 drives a BC547 NPN transistor through a 1 kohm base resistor. A 1N4007 diode across the coil absorbs the voltage spike when the coil turns off.
- **Isolated load circuit:** The relay contacts switch a separate 12 V lamp. The contact side is kept electrically separate from the LED and logic circuits.
- **LED:** A 330 ohm series resistor limits the LED current.
- **Clock:** Processor clock is set to 4 MHz in the Proteus component properties. The firmware constants (`_XTAL_FREQ`, `SPBRG`) are calculated for 4 MHz.

## Firmware Design

### 1. ADC and temperature conversion

`ADCON1 = 0x80` selects a right-justified result with all pins analog, and `ADCON0 = 0x81` selects channel AN0, Fosc/32 conversion clock, ADC on. The LM35 outputs 10 mV per degree Celsius:

```
Temperature (C) = (ADC x 5.0 / 1023) x 100
```

Resolution is 5 V / 1023 = 4.89 mV per count, about 0.49 C per ADC step. This is why the PIC may read 27.3 C while the LM35 display shows 27.0 C.

### 2. Hysteresis control

```
if (temp > 30)       relay = ON
else if (temp < 28)  relay = OFF
(between 28 and 30: keep previous state)
```

The 2 C dead band stops the relay from switching rapidly when the temperature hovers around the set-point.

### 3. UART

With a 4 MHz clock, BRGH = 1 and `SPBRG = 25`:

```
Baud = Fosc / (16 x (SPBRG + 1)) = 4,000,000 / 416 = about 9615 baud (0.16 % error)
```

Settings: 9600 baud, 8 data bits, no parity, 1 stop bit.

### 4. Output handling

LED and relay states are stored in variables (`led_state`, `relay_state`) and written to PORTB once per loop through `update_outputs()`. This keeps the output logic in one place and avoids repeated single-bit read-modify-write operations on PORTB.

## UART Commands

| Command | Action |
|---|---|
| `1` | LED ON |
| `0` | LED OFF |
| `T` | Print the current temperature immediately |

Example output:

```
Smart Automation Ready
Temp: 27.3 C  LED:0 RELAY:0
Got: 1
Temp: 27.3 C  LED:1 RELAY:0
```


**Circuit (Proteus):**

![Circuit](schematic.png)

**Idle state, LED off and relay off (about 27 C):**

![Idle](terminal_idle.png)

**LED controlled by UART command:**

![LED command](terminal_led.png)

**Relay and lamp ON above 30 C:**

![Relay on](terminal_relay_on.png)

## Debugging Log

Problems found and fixed while building this project:

| Problem | Cause | Fix |
|---|---|---|
| `undefined identifier GO_DONE` | The HI-TECH C 9.80 header does not define a global `GO_DONE` name | Set and test the GO/DONE bit with a mask: `ADCON0 \| 0x04` |
| Wrong ADC value | Result format not set, left-justified by default | `ADCON1 = 0x80` for right-justified |
| UART produced no output | Proteus processor clock did not match the firmware clock and baud rate | Set U1 clock to 4 MHz and use `SPBRG = 25` for 9600 baud |
| Simulation failed: no power supply for net | Power net names were not defined for Proteus | Used `+5V` and `+12V` names, or defined them in Power Rail Configuration |
| LED did not light | Relay contact terminals were wired into the LED net | Separated the contact circuit and gave it its own 12 V lamp load |
| Logic contention warning | TX and RX wires were joined at a crossing | Re-routed so TX goes to RXD and RX goes to TXD without a junction |

## Project Files

```
SmartAutomationProject/
|-- smartAutomation.c
|-- README.md
|-- schematic.png
|-- terminal_idle.png
|-- terminal_led.png
`-- terminal_relay_on.png
```

## How to Run

1. Open the project in MPLAB IDE v8.63 and build with HI-TECH C (PICC 9.80).
2. Open the schematic in Proteus 8 and load the generated `.hex` file into U1.
3. Set U1 Processor Clock Frequency to 4 MHz.
4. Set the Virtual Terminal to 9600 baud, 8 data bits, no parity, 1 stop bit.
5. Run the simulation. Click inside the terminal window and type `1`, `0` or `T`. Change the LM35 value to test the relay thresholds.

## Limitations and Future Work

- Verified in simulation only; real hardware testing is the next step
- Replace the software delay with a Timer interrupt for fixed sampling intervals
- Add an LCD display and an I2C EEPROM for local logging of temperature values
- Add PWM-based fan speed control instead of simple on/off switching
- Port the same design to an ARM (LPC2148) for comparison with the 8-bit PIC version

## Tools

- **MCU:** PIC16F877A
- **IDE and compiler:** MPLAB IDE v8.63, HI-TECH C for PIC10/12/16 (PICC 9.80)
- **Simulation:** Proteus 8 Professional
- **Components:** LM35, BC547, 1N4007, G2R-14 relay (5 V coil), LED, 12 V lamp
- **Language:** Embedded C

