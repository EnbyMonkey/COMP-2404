# COMP 2404 - Assignment 4
Emile Greer
100914184

## Table of contents
* [General info](#general-info)
* [Technologies](#technologies)
* [Setup](#setup)
* [Class summaries](#class-summaries)

## General info
A simple program to simulate management of aircraft and aircraft parts in an airline.

## Technologies
Project is created with:
* C++
* Makefile

## Setup
To compile and run this project, Type 'make' or 'make all', then ./a4.

```
../assignment4/$ make
.
.
.
../assignment4/$ ./a4
```

## Class Summaries
* View: Output to console, get user input from console
* Control: Initialize airline, aircraft (pl), parts, View. Install parts in aircraft. Test program via printAircraft(), printParts(),
  takeFlight(), inspectionReport()
* Airline: Responsible for installing parts in aircraft, keeping track of flights, inspecting aircraft to see if any parts
  need replacing
* Aircraft: A single aircraft. Keeps track of parts installed, flight hours.
* Part: Abstract class
* FH_Part: Inherits from Part. Inspection occurs after a certain number of flight hours
* IT_Part: Inherits from Part. Inspection occurs a certain number of days after installation
* FHIT_Part: Inherits from FH_Part and IT_Part. Inspection occurs after a certain number of flight hours or a certain number
  of days after installation, whichever is first
* Array: Basic template array.
