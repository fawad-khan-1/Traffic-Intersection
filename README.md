# TM4C123G Traffic Intersection Controller

This project implements a traffic intersection controller using the Texas Instruments TM4C123G LaunchPad.

The project is a port of an earlier Arduino Uno traffic intersection controller that I originally developed as part of a university embedded systems course. The original traffic-control behavior was preserved while the hardware interface was rewritten for the TM4C123G platform.

The completed controller was compiled, programmed onto the TM4C123G, and tested successfully on physical hardware.

## Project Features

- TM4C123G ARM Cortex-M4F microcontroller
- Embedded C programming
- TivaWare Driver Library
- GPIO input and output control
- North-south traffic-light sequence
- East-west traffic-light sequence
- Pedestrian crossing sequence
- Push-button traffic and pedestrian inputs
- LED traffic-light outputs
- Physical breadboard implementation
- Hardware testing and debugging

## System Operation

The controller monitors push-button inputs representing traffic and pedestrian requests.

The system supports three primary operating sequences:

- North-south traffic
- East-west traffic
- Pedestrian crossing

Based on the detected input, the program executes the appropriate traffic sequence and controls the corresponding LEDs connected to the TM4C123G.

The traffic-control logic is organized around three primary functions:

- `NSTraffic()` – controls the north-south traffic sequence
- `EWTraffic()` – controls the east-west traffic sequence
- `PedCrossWalk()` – controls the pedestrian crossing sequence

## Hardware

The physical implementation uses:

- Texas Instruments TM4C123G LaunchPad
- Breadboard
- LEDs
- Push buttons
- Resistors
- Jumper wires

The completed circuit was assembled and tested on physical hardware.

## Software and Tools

- Embedded C
- TM4C123G / Tiva C Series
- TivaWare Driver Library
- Keil MDK
- UniFlash

Keil MDK was used to build the embedded application, and Texas Instruments UniFlash was used to program the compiled application onto the TM4C123G LaunchPad.

## GPIO Implementation

The TM4C123G version replaces the Arduino-specific hardware interface with GPIO control appropriate for the TM4C123G.

The program uses the TivaWare Driver Library to configure and interact with the microcontroller's GPIO peripherals.

The traffic-light LEDs are controlled through GPIO outputs, while the traffic and pedestrian push buttons are monitored through GPIO inputs.

## Original Arduino Version

This project is a port of an earlier traffic intersection controller that I originally developed for the Arduino Uno as part of a university embedded systems course.

The original Arduino implementation controls north-south traffic, east-west traffic, and a pedestrian crossing using LEDs and push-button inputs.

For this project, I ported the original design to the Texas Instruments TM4C123G LaunchPad. The traffic-control behavior was preserved while the Arduino-specific I/O was replaced with TM4C123G GPIO control using the TivaWare Driver Library.

Both versions were implemented and tested on physical hardware.

Original Arduino version:

[Arduino Traffic Intersection](https://github.com/fawad-khan-1/TrafficLightEET3350)

## Hardware Demonstration

A video demonstration of the completed TM4C123G implementation is included in this repository.

The video shows the traffic intersection controller operating on the physical TM4C123G LaunchPad and breadboard hardware, including the traffic-light sequences and response to the input buttons.

[Open the TM4C123G Traffic Intersection Demonstration](demo/Tm4c123gtrafficcontroller-Demo3.mp4)

> If GitHub does not display the video in its file preview, select **View raw** to open the video file. 

## Project Background

The original traffic intersection controller was developed using an Arduino Uno.

I later revisited the project and ported the design to the TM4C123G LaunchPad. This required adapting the hardware interface and GPIO implementation to a different microcontroller platform while preserving the original traffic-control behavior.

The completed TM4C123G version was compiled, flashed to the microcontroller, and tested repeatedly on physical hardware.

## Project Purpose

This project demonstrates experience with:

- Embedded C programming
- ARM-based microcontrollers
- GPIO configuration and control
- Embedded hardware/software integration
- Microcontroller peripheral libraries
- Breadboard prototyping
- Hardware testing
- Debugging embedded systems
- Porting an embedded application between microcontroller platforms
## Original Arduino Version

This project is a port of an earlier traffic intersection controller that I originally developed for the Arduino Uno as part of a university embedded systems course.

The original Arduino implementation controls north-south traffic, east-west traffic, and a pedestrian crossing using LEDs and push-button inputs.

For this project, I ported the original design to the Texas Instruments TM4C123G LaunchPad. The traffic-control behavior was preserved while the Arduino-specific I/O was replaced with TM4C123G GPIO control using the TivaWare Driver Library.

Both versions were implemented and tested on physical hardware.

Original Arduino version:

[Arduino Traffic Intersection](https://github.com/fawad-khan-1/TrafficLightEET3350)

## Screenshots and Hardware

Screenshots of the source code and photographs of the physical TM4C123G traffic intersection setup will be included in the `screenshots` directory.