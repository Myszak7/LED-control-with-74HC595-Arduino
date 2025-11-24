# LED control with 74HC595 and Serial Monitor - Arduino

A C++ program intended to be run in the Arduino IDE which uses the 74HC595 shift register to control eight digital outputs. Takes input through the serial monitor in order
to control LEDs. Takes int values from 0-7 and "x" to update the shift register and turn off all LEDs.

Modeled after the code from Elegoo, except I added an additional condition which allows for the user to turn off LEDs which are already on.

Below I have included a picture of the circuit. A wiring diagram can be found under Lesson 17 for the Super Starter Kit Guide under Elegoo.




![74HC595_sm_circuit](https://github.com/user-attachments/assets/3e7cdc20-8406-4833-999e-20dd4a711c55)
