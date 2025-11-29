# EG1311 Autonomous Obstacle-Navigating Robot (Team 04)

## 📖 Project Overview
[cite_start]This repository documents the design and development of a self-powered robot built for the EG1311 course at the National University of Singapore[cite: 1, 4]. [cite_start]The primary objective was to engineer a robot capable of navigating a specific obstacle course—comprising a bump, a ramp, and a wall—and autonomously launching a ping-pong ball over the wall[cite: 14].


## 🎯 Specifications & Constraints
The robot was engineered under strict design constraints to ensure competitive fairness and engineering ingenuity:
* [cite_start]**Dimensions:** The robot fits strictly within a $30 \times 30 \times 30$ cm cubic volume[cite: 36].
* [cite_start]**Power:** Powered solely by one 9V battery (logic) and four AA batteries (drive)[cite: 37].
* [cite_start]**Time Limit:** Must complete the course within 30 seconds[cite: 39].
* [cite_start]**Materials:** Constructed using specific provided materials, including corrugated plastic boards and acrylic[cite: 38, 47].

## ⚙️ Hardware Architecture

### 1. Chassis and Drive System
* [cite_start]**Body Material:** We utilized corrugated plastic board for the chassis due to its superior structural integrity compared to cardboard, while remaining lightweight[cite: 56].
* **4-Wheel Drive (4WD):** The robot employs a four-motor design. [cite_start]This ensures multiple contact points for stability and generates sufficient torque to overcome the 3cm bump and climb the ramp[cite: 42, 43].
* [cite_start]**Wheel Design:** Custom 90mm diameter wheels were laser-cut from acrylic to ensure consistency[cite: 47, 53]. [cite_start]To combat slippage, the wheels were wrapped in anti-slip mats to increase friction against the ground[cite: 175].

### 2. Electronics and Control
* **Microcontroller:** Arduino Uno.
* **Motor Drivers:** We utilized **two** L293D H-Bridge motor drivers. [cite_start]This configuration allows independent control of the motors, enabling the robot to move forward, stop, and reverse—a critical feature for the final stage of the course[cite: 126].
    * *Logic:* Input 1 High / Input 2 Low = Forward. [cite_start]Input 1 Low / Input 2 High = Reverse[cite: 127, 128].
* [cite_start]**Sensors:** An HC-SR04 Ultrasonic Sensor is used for obstacle detection and distance measurement to the wall[cite: 177].


### 3. Catapult Mechanism
[cite_start]Instead of a complex elastic latch system, we opted for a direct-drive catapult attached to a servo arm[cite: 92]. [cite_start]This converts the servo's electrical energy directly into the ball's kinetic energy[cite: 93].
* [cite_start]**Arm Length:** Optimized to 20.25 cm to fit within the dimensional constraints while maximizing trajectory height[cite: 195].

## 🧠 Software Logic

The robot operates on a closed-loop system using the ultrasonic sensor for feedback.

1.  **Initialize:** Setup motor pins and servo.
2.  **Move Forward:** All 4 motors drive the robot forward.
3.  **Scan:** The ultrasonic sensor measures the distance to the wall.
4.  **Decision Trigger:**
    * **IF** distance $< 10$ cm:
        1.  **Stop:** Cut power to motors.
        2.  **Launch:** Servo rotates to throw the ball.
        3.  [cite_start]**Reverse:** Robot backs away to the start[cite: 103, 111, 112].
    * [cite_start]**ELSE:** Continue moving forward[cite: 104].

## 📐 Design Challenges & Mathematical Solutions

### Ramp Clearance (Vehicle Length)
To ensure the robot did not get stuck at the peak of the ramp, we calculated the maximum allowable length using trigonometry.
[cite_start]Given a ramp incline of $\theta = 29.74^{\circ}$, the maximum length was determined to be approximately 250mm[cite: 58, 64].

### Sensor Height Calibration
[cite_start]During prototyping, the ultrasonic sensor falsely detected the ramp as the wall[cite: 165]. [cite_start]To fix this, we calculated the minimum height required for the sensor to "look over" the ramp using the sensor's $15^{\circ}$ angle of effect[cite: 178].

$$\tan(15^{\circ}) = \frac{h}{175}$$
$$h \approx 46.89 \text{ mm}$$

[cite_start]Adding the ramp height of 100mm, the sensor was mounted at **147mm** from the ground[cite: 185, 186].


## 📂 Repository Structure
* `/src`: Contains the final Arduino `.ino` code (see Appendix D of report).
* `/cad`: DXF and CAD files for the laser-cut acrylic wheels and chassis parts.
* `/docs`: Project report and circuit diagrams.

## 👥 Team
**NUS EG1311 Group B02 - Team 04**
* [cite_start]Project Report Authors [cite: 4]

---
*Note: All citations refer to the project report document included in this repository.*
