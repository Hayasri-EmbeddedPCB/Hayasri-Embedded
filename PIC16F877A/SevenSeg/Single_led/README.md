# PIC Microcontroller 0–9 Seven Segment Counter

This project demonstrates a simple 0 to 9 single-digit counter using a PIC Microcontroller and a 7-Segment Display.
# Output



https://github.com/user-attachments/assets/69b896c3-4cc8-45c8-971e-ac8ea70a6b9b



## 🛠 Features

* **Sequential Counting:** Loops through numbers `0` to `9` continuously.
* **Common Cathode Mapping:** Uses a standard lookup array (`seg_code`) to output 7-segment hex values on `PORTB`.
* **Software Delay:** Employs nested loops to create time intervals between digits.

---

## 🔌 Hardware Connections

| Component Pin | PIC Microcontroller Pin | Description |
| :--- | :--- | :--- |
| **Segment A–G / DP** | `RB0` – `RB7` (`PORTB`) | Segment Data Bus |
| **Common Pin** | Ground (GND) | Common Cathode Connection |

---

## ⚙️ How It Works

1. **Seven Segment Lookup Array (`seg_code`):**
   * `0x3F` = `0`, `0x06` = `1`, `0x5B` = `2`, `0x4F` = `3`, `0x66` = `4`
   * `0x6D` = `5`, `0x7D` = `6`, `0x07` = `7`, `0x7F` = `8`, `0x6F` = `9`

2. **Main Execution:**
   * Configures `PORTB` as output (`TRISB = 0x00`).
   * Iterates through the array and writes each value to `PORTB` with a delay.

---

## 💡 Recommended Code Improvements

1. **Compiler Compatibility:** Replace `#include <pic.h>` with `#include <xc.h>` for modern MPLAB XC8 compilers.
2. **Accurate Timing:** Replace manual delay loops with builtin timing macros:
   ```c
   __delay_ms(500);
