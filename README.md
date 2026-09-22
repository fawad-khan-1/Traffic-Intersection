# TM4C123G Traffic Intersection Controller

This project implements a traffic intersection controller using the Texas Instruments TM4C123G LaunchPad.

The traffic intersection was originally developed as an assigned university embedded-systems laboratory project using the TM4C123G. The original implementation controlled the microcontroller hardware directly using registers and hexadecimal register values.

I later ported the traffic controller to an Arduino Uno.

I recently returned to the original TM4C123G project and reimplemented it using the TivaWare Driver Library instead of the direct register-level programming approach used in the original class project.

The completed TivaWare version was compiled, programmed onto the TM4C123G LaunchPad, and successfully tested on physical hardware.

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
- Texas Instruments UniFlash

Keil MDK was used to build the current implementation, and Texas Instruments UniFlash was used to program the application onto the TM4C123G LaunchPad.

## TivaWare Reimplementation

The original university version of this project used direct register-level programming and hexadecimal register values to configure and control the TM4C123G hardware.

For the current version, I returned to the original project and reimplemented the hardware interface using the TivaWare Driver Library.

TivaWare functions are used to configure and interact with the TM4C123G GPIO peripherals while preserving the traffic-control behavior of the original project.

This provided an opportunity to revisit an earlier embedded-systems project using a different programming approach and current development tools.

## Arduino Port

After completing the original register-based TM4C123G project, I later ported the traffic controller to an Arduino Uno.

The Arduino version implements the same general traffic-intersection concept using the Arduino platform.

Arduino version:

[Arduino Traffic Intersection](https://github.com/fawad-khan-1/TrafficLightEET3350)

## Hardware Demonstration

A video demonstration of the completed TivaWare implementation is included in this repository.

The video shows the traffic intersection controller operating on the physical TM4C123G LaunchPad and breadboard hardware, including the traffic-light sequences and response to the input buttons.

[Open the TM4C123G Traffic Intersection Demonstration](demo/Tm4c123gtrafficcontroller-Demo3.mp4)

> If GitHub does not display the video in its file preview, select **View raw** to open the video file.

## Project History

This project has gone through three major stages:

1. **Original TM4C123G implementation** – Developed as an assigned university embedded-systems laboratory project using direct register-level programming and hexadecimal register values.

2. **Arduino port** – The original traffic-controller concept was later ported to the Arduino Uno.

3. **TivaWare TM4C123G reimplementation** – I recently returned to the TM4C123G and rebuilt the project using the TivaWare Driver Library and current development tools.

The current repository contains the TivaWare-based TM4C123G implementation.

## Project Purpose

This project demonstrates experience with:

- Embedded C programming
- ARM-based microcontrollers
- GPIO configuration and control
- Embedded hardware/software integration
- TivaWare Driver Library
- Breadboard prototyping
- Hardware testing
- Debugging embedded systems
- Revisiting and modernizing an earlier embedded project
- Porting embedded control logic between microcontroller platforms