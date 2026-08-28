# PIC Microcontroller Digital Voltmeter with LCD Display

This project measures an analog input voltage (0V to 5V) using the built-in 10-bit ADC (Analog-to-Digital Converter) of a PIC Microcontroller and displays the calculated voltage on a 16x2 LCD module.

#Output


https://github.com/user-attachments/assets/0807f326-08c8-437f-bd37-10fc93958ef4



## 🛠 Features

* **ADC Interfacing:** Reads analog signals from `PORTA` (Channel 0).
* **LCD Interfacing:** 8-bit mode operation using `PORTC` for data lines and `PORTB` for control lines.
* **Real-Time Voltage Calculation:** Converts 10-bit ADC values (0–1023) to corresponding voltage levels (0.00V – 5.00V).

---

## 🔌 Hardware Connections

| Component | PIC Pin / Port | Description |
| :--- | :--- | :--- |
| **Analog Input** | `PORTA` (AN0) | Input voltage source (0V - 5V) |
| **LCD Data Lines (D0-D7)** | `PORTC` | 8-bit Data Bus |
| **LCD RS** | `RB0` | Register Select |
| **LCD RW** | `RB1` | Read/Write control |
| **LCD EN** | `RB2` | Enable signal |

---

## ⚙️ How It Works

1. **ADC Configuration:**
   * `ADCON0` and `ADCON1` registers configure AN0 as an analog channel with right-justified 10-bit results.
   * Converts analog voltage into a digital range of `0 to 1023`.

2. **Voltage Conversion Formula:**
   $$\text{Voltage} = \frac{\text{ADC Value} \times 500}{1023}$$
   *(Scaled by 100 to extract digits without using heavy floating-point math).*

3. **Display Output:**
   * **Line 1 (`0x80`):** Displays `"ADC Value"`
   * **Line 2 (`0xC0`):** Displays formatted voltage (e.g., `4.98v`)

---

## 🚨 Code Fixes & Optimization Tips

If you encounter issues during compilation or hardware execution, consider these adjustments:

1. **Fix `lcd_show` Function Call:**
   In `main()`, `lcd_show('v');` passes a `char` instead of a string pointer. Change it to `lcd_show("v");` or directly use `lcd_dat('v');`.

2. **Delay Function Optimization:**
   The manual delay loop can be replaced with the compiler's built-in macro for accurate timing:
   ```c
   __delay_ms(100);
