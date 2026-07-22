# 8051 Microcontroller I2C Communication 

An embedded systems project demonstrating **Software Bit-Banged I2C Communication** (EEPROM Interface) and *, programmed in **C (Keil C51)** and simulated in **Proteus VSM**.

---

## 🛠️ Hardware & Software Tools

| Tool / Component | Description |
| :--- | :--- |
| **Microcontroller** | AT89C51 / 80C51 |
| **I2C Device** | AT24C Series EEPROM (Slave) |
| **Motor Driver** | DRV8871 H-Bridge Driver |
| **Compiler** | Keil uVision (C51) |
| **Simulation** | Proteus 8 Professional |

---

## 🔌 Pin Mapping

### 1. I2C Bus Pins (Software Bit-Banging)
* **P2.0** $\rightarrow$ `SDA` (Serial Data)
* **P2.1** $\rightarrow$ `SCL` (Serial Clock)

> **Note:** 8051 I/O ports are open-drain, so external **4.7kΩ Pull-up Resistors** to `VCC` (+5V) are recommended for both `SDA` and `SCL` lines.

### 2. Microcontroller Power & Control
* **Pin 31 ($\text{EA}/\text{VPP}$)** $\rightarrow$ **`VCC` (+5V)** *(Mandatory for code execution)*
* **Pin 9 ($\text{RST}$)** $\rightarrow$ **`GND`**

---

## 🛰️ I2C Protocol Implementation Details

Since standard 8051 chips don't have built-in hardware I2C peripherals, **Bit-Banging** is used to emulate I2C timing through software GPIO manipulation:

1. **Start Condition (`i2c_start`)**: `SDA` goes `LOW` while `SCL` is `HIGH`.
2. **Stop Condition (`i2c_stop`)**: `SDA` goes `HIGH` while `SCL` is `HIGH`.
3. **Data Write (`i2c_write`)**: MSB-first bit shifts with clock pulse generation. Includes ACK clock cycle handling.
4. **Data Read (`i2c_read`)**: Reads bits on every clock pulse and reconstructs the 8-bit data.

---



    while(1); // Infinite loop
}
