# Traffic Intersection
Traffic intersection controller implemented in C on a TI TM4C123G microcontroller using TivaWare.
# TM4C123G Traffic Intersection Controller

## Overview

This project implements a traffic intersection control system on a Texas Instruments TM4C123G LaunchPad using C and the TivaWare Driver Library.

The system controls traffic lights for north-south and east-west traffic as well as a pedestrian crossing. Push buttons connected to the microcontroller are used to simulate traffic and pedestrian requests.

The project was implemented in Keil MDK and programmed onto a physical TM4C123G LaunchPad. LEDs connected on a breadboard were used to represent the traffic signals.

## Original Arduino Version

This project is a port of an earlier traffic intersection controller that I originally developed for the Arduino Uno as part of a university embedded systems course.

The original Arduino implementation controls north-south traffic, east-west traffic, and a pedestrian crossing using LEDs and push-button inputs.

For this project, I ported the original design to the Texas Instruments TM4C123G LaunchPad. The traffic-control behavior was preserved while the Arduino-specific I/O was replaced with TM4C123G GPIO control using the TivaWare Driver Library.

Both versions were implemented and tested on physical hardware.

Original Arduino version:

[Arduino Traffic Intersection](PASTE-ARDUINO-GITHUB-URL-HERE)

## System Operation

The intersection contains three controlled traffic paths:

- North-South traffic
- East-West traffic
- Pedestrian crossing

Three push-button inputs are used to request changes in the traffic signals:

- North-South traffic request
- East-West traffic request
- Pedestrian crossing request

The controller evaluates the input states and changes the traffic signals according to the programmed intersection sequence.

## Software Design

The program is written in C and separates the major traffic-control operations into functions:

- `NSTraffic()` – controls the North-South traffic sequence.
- `EWTraffic()` – controls the East-West traffic sequence.
- `PedCrossWalk()` – controls the pedestrian crossing sequence.

The main program continuously reads the three input signals and determines which traffic-control sequence should execute.

## Hardware and Software

- Texas Instruments TM4C123G LaunchPad
- ARM Cortex-M4F microcontroller
- C
- TivaWare Driver Library
- Keil MDK
- TI UniFlash
- Breadboard
- LEDs
- Push buttons

## GPIO Control

The project uses TivaWare GPIO functions rather than directly manipulating hardware registers. GPIO ports are configured for the traffic-light outputs and push-button inputs.

The software uses TivaWare functions for:

- Enabling GPIO peripherals
- Configuring GPIO pins as inputs and outputs
- Reading push-button states
- Controlling traffic-light LEDs

## Testing

The program was compiled in Keil MDK and programmed onto the TM4C123G using TI UniFlash.

The completed system was tested on physical hardware using LEDs to represent the traffic signals and push buttons to simulate traffic and pedestrian requests.

Multiple input sequences were tested to verify that signal transitions occurred in response to button inputs and that the traffic lights remained stable when no new request was present.

## Source Code

The primary application source code is contained in:

`main.c`

The repository also contains the Keil project configuration required to open and build the project.

## Screenshots and Hardware

Screenshots of the source code and photographs of the physical TM4C123G traffic intersection setup will be included in the `screenshots` directory.