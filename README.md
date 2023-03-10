# Traffic Light Controller

## Introduction
This project implements a traffic light controller system using ATmega32 microcontroller. The system has one push button connected to INT0 pin for pedestrian, and three LEDs for cars (Green, Yellow, and Red) connected on port A, pins 0, 1, and 2. The system also has three LEDs for pedestrians (Green, Yellow, and Red) connected on port B, pins 0, 1, and 2.

## Normal Mode
In normal mode, the cars' LEDs will change every five seconds starting from Green then yellow then red then yellow then Green. The Yellow LED will blink for five seconds before moving to Green or Red LEDs.

## Pedestrian Mode
In pedestrian mode, the system changes from normal mode to pedestrian mode when the pedestrian button is pressed. If the button is pressed when the cars' Red LED is on, the pedestrian's Green LED and the cars' Red LEDs will be on for five seconds, allowing pedestrians to cross the street while the pedestrian's Green LED is on. If the button is pressed when the cars' Green LED is on or the cars' Yellow LED is blinking, the pedestrian Red LED will be on, then both Yellow LEDs start to blink for five seconds, then the cars' Red LED and pedestrian Green LEDs are on for five seconds, indicating that the pedestrian must wait until the Green LED is on. At the end of the two states, the cars' Red LED will be off and both Yellow LEDs start blinking for 5 seconds, and the pedestrian's Green LED is still on. After five seconds, the pedestrian Green LED will be off and both the pedestrian Red LED and the cars' Green LED will be on, returning the traffic lights to normal mode.

## User Stories

| User Action | System Behavior |
|-------------|-----------------|
| Pedestrian presses crosswalk button while cars green light is on and pedestrian red light is off | Wait for the yellow lights to blink for five seconds, then the cars red light is on and pedestrian green light is on for five seconds, so that pedestrian can cross the street |
| Pedestrian presses crosswalk button while cars yellow light is blinking and pedestrian red light is on | Wait for all yellow lights to blink for five seconds, then the cars red light is on and pedestrian green light is on for five seconds, so that pedestrian can cross the street |
| Pedestrian presses crosswalk button while cars red light is on and pedestrian green light is on | Nothing is done |
| Pedestrian makes a long press on crosswalk button | Nothing is done |
| Pedestrian makes a double press on crosswalk button | First press will do the action, and nothing is done after the second press |

## Hardware Requirements

| Component | Description |
|-----------|-------------|
| ATmega32 microcontroller | Main component of the system |
| Push button | Connected to INT0 pin for pedestrian mode |
| Cars LEDs | Three LEDs for cars (Green, Yellow, and Red) connected on port A, pins 0, 1, and 2 |
| Pedestrian LEDs | Three LEDs for pedestrians (Green, Yellow, and Red) connected on port B, pins 0, 1, and 2 |


## Requirements
- AVR compiler
- Microcontroller programmer

## Usage
1. Clone or download the repository to your local machine.
2. Open the project in an AVR compiler.
3. Connect the hardware as described in the "Hardware" section above.
4. Upload the code to the microcontroller.
5. Observe the traffic light behavior in both normal and pedestrian modes.
