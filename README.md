# EG1311-Catapult-Launcher
The primary goal of this project is to build a self-powered robot that navigates an obstacle course consisting of a starting area, a bump, a ramp, and a wall and then delivers a ping-pong ball over the wall. Extra points are awarded based on the robot’s weight and its capability to reverse back to the starting point.

EG1311 Catapult Launcher Robot 🚗🏹

A self-powered autonomous robot capable of obstacle traversal and ping-pong ball launching
Based on the official project report. 

EG1311 Project Report

📖 Table of Contents

Project Overview

Features

Specifications

System Architecture

Mechanical Design

Electronics & Circuitry

Software Logic

Prototyping Challenges

Improvements

Lessons Learned

Gallery

Repository Structure

Contributors

📌 Project Overview

This project was developed for EG1311 (Design & Make).
The objective was to build an autonomous robot that:

Traverses an obstacle course (bump → ramp → wall)

Detects the wall using an ultrasonic sensor

Launches a ping-pong ball over the wall using a servo-powered catapult

Reverses back to the starting point for bonus points

Operates within strict size, time, and material constraints

⭐ Features

Four-motor drivetrain for high torque and stability

Laser-cut acrylic wheels wrapped with anti-slip material

Servo-driven catapult system (no rubber bands required)

Ultrasonic distance sensing for autonomous triggering

Bidirectional motor control using dual L293D drivers

Lightweight corrugated plastic chassis

Fully autonomous run based on programmed states

📏 Specifications
Project Constraints
Requirement	Description
Dimensions	≤ 30 × 30 × 30 cm
Power Supply	1 × 9V + 4 × AA batteries
Materials	Only materials provided in EG1311
Time Limit	30 seconds per run
Hardware Used

Arduino Uno

4 × DC motors

2 × L293D H-bridge drivers

HC-SR04 ultrasonic sensor

SG90 servo motor

Acrylic wheels + anti-slip mat

Corrugated plastic chassis

🧠 System Architecture
High-Level Flow
flowchart TD
    A[Start] --> B[Measure distance with ultrasonic sensor]
    B -->|Distance > 10 cm| C[Move Forward]
    B -->|Distance ≤ 10 cm| D[Stop & Launch Ball]
    D --> E[Reverse for preset duration]
    E --> F[End]

🔩 Mechanical Design
Wheels

Diameter: 90 mm

Material: Laser-cut acrylic

Triangular cutouts for weight reduction

Wrapped with anti-slip mat for increased friction
(Addressing the issue found in early prototype: wheels slipping on ramp/bump)

Chassis

Corrugated plastic chosen for its strength-to-weight ratio

Length optimized (~250 mm) to prevent getting stuck at top of ramp
(Calculation shown in project report Fig.2)

Catapult System

Initially rubber-band based → switched to servo-powered direct drive

Converts servo motion directly into ball kinetic energy

Final catapult arm length: 20.25 cm (fits project constraints)

Ultrasonic Sensor Height

Positioned ≥ 14.7 cm from ground
(Calculated using 15° sensor spread angle to avoid false ramp detection)

🔌 Electronics & Circuitry
Motor Control

Two L293D drivers

Each L293D controls 2 motors

Direction determined by input pairs:

IN1 = HIGH, IN2 = LOW → forward

IN1 = LOW, IN2 = HIGH → reverse

Both LOW → stop

Wiring Diagram

See full diagram in Appendix C (page 11).


EG1311 Project Report

💻 Software Logic
Core robot behaviors

Periodically measure distance

If wall detected ≤ 10 cm → stop, launch, reverse

Otherwise → keep driving forward

Snippet from Arduino Code

(Full code in Appendix D)


EG1311 Project Report

if (distance <= 10) {
    stopMotors();
    launchBall();
    reverseMotors();
} else {
    moveForward();
}

🧪 Prototyping Challenges
1. Low Wheel Friction

Early prototypes stalled at the bump

Solution: acrylic wheels + anti-slip mat

2. Misuse of L293D

Initially only forward motion worked

Fixed by switching to two H-bridges and wiring both motor terminals

3. Ultrasonic Sensor Triggering Too Early

Sensor detected ramp as an obstacle

Resolved by increasing sensor height

🔧 Improvements Implemented

Redesigned wheels with weight-optimized geometry

Adjusted sensor placement based on trigonometry

Optimized catapult length for maximum trajectory

Increased battery current by using 4 × AA instead of 9V for motors

Strengthened chassis using corrugated plastic + ice cream stick supports

🎓 Lessons Learned

Importance of iterative prototyping

Validating assumptions instead of jumping to conclusions

Open-mindedness when evaluating team ideas

Applying physics (torque, friction, angle) to practical engineering

Understanding limitations of materials and components

📸 Gallery
Final Robot

![Robot Photo](attachment:EG1311 Project Report.pdf#page=9)

CAD Renders & Drawings

![CAD](attachment:EG1311 Project Report.pdf#page=10)

Wiring Diagram

![Circuit](attachment:EG1311 Project Report.pdf#page=13)

(Images sourced from the project report)


EG1311 Project Report

📂 Repository Structure
.
├── /cad/                 # CAD drawings & renders
├── /hardware/            # Photos of prototypes and final robot
├── /circuit/             # TinkerCAD or wiring diagrams
├── /code/                # Arduino code (.ino)
├── README.md             # Documentation
└── EG1311_Project_Report.pdf

👥 Contributors

Team 04, EG1311 B02

Roles included: mechanical design, electronics, coding, CAD, documentation
