# 8051 Microcontroller DC Motor Control using DRV8871 Driver

An embedded systems project demonstrating directional control (Forward, Reverse, and Stop) of a DC Motor using an **8051 Microcontroller (80C51)** and a **DRV8871 Motor Driver**, simulated using **Proteus VSM** and programmed in **C (Keil C51)**.

---

## 🛠️ Components & Tools Used

| Component / Tool | Details |
| :--- | :--- |
| **Microcontroller** | AT89C51 / 80C51 |
| **Motor Driver** | DRV8871 H-Bridge Driver |
| **Actuator** | DC Motor |
| **IDE** | Keil uVision (C51 Compiler) |
| **Simulation Tool** | Proteus 8 Professional |

---

## 🔌 Circuit Connection Pinout

### 1. 8051 Microcontroller to DRV8871
* **P2.0** $\rightarrow$ `IN1` (Driver Input 1)
* **P2.1** $\rightarrow$ `IN2` (Driver Input 2)

### 2. 8051 Essential Connections
* **Pin 31 ($\text{EA}/\text{VPP}$)** $\rightarrow$ **`VCC` (+5V)** *(Mandatory for executing internal code)*
* **Pin 9 ($\text{RST}$)** $\rightarrow$ **`GND`**

### 3. DRV8871 Motor Driver & Motor
* **Pin 5 (`VM`)** $\rightarrow$ **`VCC` (+5V / +12V)** Power Supply
* **Pin 1 (`GND`)** $\rightarrow$ **`GND`**
* **`OUT1` & `OUT2`** $\rightarrow$ Connected to **DC Motor Pins**

---

## ⚙️ How It Works (Motor Logic)

The 8051 outputs logic levels from Port 2 to drive the H-Bridge motor driver:

| P2.0 (`IN1`) | P2.1 (`IN2`) | Motor State | Action |
| :---: | :---: | :---: | :--- |
| `1` | `0` | **Forward** | Motor rotates Clockwise |
| `0` | `1` | **Reverse** | Motor rotates Counter-Clockwise |
| `0` | `0` | **Stop** | Motor stops spinning |

---

