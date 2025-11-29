# EG1311-Catapult-Launcher
The primary goal of this project is to build a self-powered robot that navigates an obstacle course consisting of a starting area, a bump, a ramp, and a wall and then delivers a ping-pong ball over the wall. Extra points are awarded based on the robot’s weight and its capability to reverse back to the starting point.

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

```mermaid
flowchart TD
    A[Start] --> B[Measure distance with ultrasonic sensor]
    B -->|Distance > 10 cm| C[Move Forward]
    B -->|Distance ≤ 10 cm| D[Stop & Launch Ball]
    D --> E[Reverse for preset duration]
    E --> F[End]

