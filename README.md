# EG1311 Catapult Launcher Robot 🚗🏹  
*A self-powered autonomous robot capable of obstacle traversal and ping-pong ball launching*

---

## 📖 Table of Contents
- [Project Overview](#project-overview)
- [Features](#features)
- [Specifications](#specifications)
- [System Architecture](#system-architecture)
- [Mechanical Design](#mechanical-design)
- [Electronics & Circuitry](#electronics--circuitry)
- [Software Logic](#software-logic)
- [Prototyping Challenges](#prototyping-challenges)
- [Improvements](#improvements)
- [Lessons Learned](#lessons-learned)
- [Gallery](#gallery)
- [Repository Structure](#repository-structure)
- [Contributors](#contributors)

---

## 📌 Project Overview
This project was developed for **EG1311 (Design & Make)**.  
The goal was to build an autonomous robot capable of:

- Traversing an obstacle course (bump → ramp → wall)
- Detecting the wall using an ultrasonic sensor
- Launching a ping-pong ball over the wall using a servo-powered catapult
- Reversing back to the starting point for extra points
- Operating within strict size, time, and material constraints

---

## ⭐ Features
- Four-motor drivetrain for high torque and stability  
- Laser-cut acrylic wheels wrapped with anti-slip material  
- Servo-driven catapult system (no rubber bands required)  
- Ultrasonic distance sensing for autonomous triggering  
- Bidirectional motor control using dual L293D drivers  
- Lightweight corrugated plastic chassis  
- Fully autonomous run based on programmed states  

---

## 📏 Specifications

### **Project Constraints**

| Requirement      | Description |
|------------------|-------------|
| Dimensions       | ≤ 30 × 30 × 30 cm |
| Power Supply     | 1 × 9V + 4 × AA batteries |
| Materials        | Only materials provided in EG1311 |
| Time Limit       | 30 seconds per run |

### **Hardware Used**
- Arduino Uno  
- 4 × DC motors  
- 2 × L293D H-bridge drivers  
- HC-SR04 ultrasonic sensor  
- SG90 servo motor  
- Acrylic wheels + anti-slip mat  
- Corrugated plastic chassis  

---

## 🧠 System Architecture

### **High-Level Flowchart**
<p align = "center">
```mermaid
flowchart TD
    A[Start] --> B[Measure distance with ultrasonic sensor]
    B -->|Distance > 10 cm| C[Move Forward]
    B -->|Distance ≤ 10 cm| D[Stop & Launch Ball]
    D --> E[Reverse for preset duration]
    E --> F[End]
</p>
## 🔩 Mechanical Design

### **Wheels**
- Diameter: **90 mm**
- Material: **Laser-cut acrylic**
- Triangular cutouts to reduce weight
- Wrapped with anti-slip mat to increase traction
- Improvement implemented to solve wheel slippage on bump/ramp

### **Chassis**
- Built using lightweight corrugated plastic board
- Stronger than cardboard while keeping overall mass low
- Car length optimized to approximately **250 mm**
  - Ensures the robot does not get stuck at the peak of the ramp
  - Calculated using trigonometry in the project’s design stage

### **Catapult System**
- Initial design used a rubber-band slingshot mechanism  
  - Rejected due to structural stress and unreliable release timing
- Final mechanism uses **direct servo-driven launching**
  - Converts servo rotation directly into ball kinetic energy
  - Offers consistent release angle and timing
- Catapult arm length selected as **20.25 cm**
  - Complies with the ≤ 30 cm robot dimension constraint

### **Ultrasonic Sensor Height**
- Sensor used: **HC-SR04**
- Has a **15° angle-of-effect** (cone spread)
- If placed too low, the sensor falsely detects the ramp surface as an obstacle
- Calculations show the sensor must be **≥ 14.7 cm** above ground
- Final position prevents premature reversing behavior

---

## 🔌 Electronics & Circuitry

### **Motor Control**
- **Two L293D H-bridge drivers** used
- Each driver controls **2 DC motors**
- Enables forward and reverse motion via bidirectional current control

Motor direction logic:


