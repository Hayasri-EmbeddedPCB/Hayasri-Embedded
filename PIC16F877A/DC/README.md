# PIC Microcontroller DC Motor Control

This project demonstrates **DC motor control using a PIC microcontroller and a motor driver**. The program controls the motor in three different states:

1. **Forward Rotation**
2. **Stop**
3. **Reverse Rotation**

The control signals are generated through **RC0 and RC1** pins of the PIC microcontroller.

## 🔧 Components Required

* PIC Microcontroller
* DC Motor
* Motor Driver (L293D / L298N or equivalent)
* Power Supply
* Connecting Wires
* MPLAB / PIC C Compiler

## ⚙️ Pin Configuration

| PIC Pin | Function         |
| ------- | ---------------- |
| RC0     | Motor Driver IN1 |
| RC1     | Motor Driver IN2 |

### Motor Control Logic

| RC0 (IN1) | RC1 (IN2) | Motor Status |
| --------- | --------- | ------------ |
| 1         | 0         | Forward      |
| 0         | 0         | Stop         |
| 0         | 1         | Reverse      |

## 💻 Program

```c
#include <pic.h>

#define _XTAL_FREQ 2000000

#define IN1 RC0
#define IN2 RC1

void delay()
{
    unsigned int i, j;

    for(i = 0; i < 100; i++)
    {
        for(j = 0; j < 12000; j++)
        {
        }
    }
}

void main()
{
    TRISC = 0x00;

    while(1)
    {
        // Forward
        RC0 = 1;
        RC1 = 0;
        delay();

        // Stop
        RC0 = 0;
        RC1 = 0;
        delay();

        // Reverse
        RC0 = 0;
        RC1 = 1;
        delay();
    }
}
```

## 🔄 Working Principle

The PIC microcontroller sends digital control signals to the motor driver's **IN1** and **IN2** inputs.

* When **RC0 = 1** and **RC1 = 0**, the motor rotates in the forward direction.
* When **RC0 = 0** and **RC1 = 0**, the motor stops.
* When **RC0 = 0** and **RC1 = 1**, the motor rotates in the reverse direction.

The program continuously repeats this sequence using a software delay.

**Forward → Stop → Reverse → Repeat**

## 🧠 Key Concepts

* PIC Microcontroller GPIO
* Digital Output Control
* DC Motor Direction Control
* Motor Driver Interface
* Embedded C Programming
* Software Delay

## 📌 Note

The motor should **not be connected directly to the PIC microcontroller pins**. A suitable motor driver must be used because the microcontroller GPIO pins cannot provide the required motor current.

## 🚀 Future Improvements

* Add **PWM-based speed control**
* Add push-button control
* Control motor using Bluetooth
* Add automatic direction control
* Implement variable-speed motor control

## 📄 License

This project is created for **educational and embedded-systems learning purposes**.
##Output
<img width="568" height="353" alt="Screenshot 2026-08-27 191310" src="https://github.com/user-attachments/assets/a1b5e7a8-13eb-4ed4-adfd-80d6ebfe0609" />
