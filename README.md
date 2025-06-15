# Firmware: Sensors, Actuators, and more!
Welcome to the embedded system lab. 

# Pre Requisites
- Read the prelab about MicroPython
- Do the prelab

## Prelab 
- Setup Hosted Wokwi Development
    - Register for an account by going to https://wokwi.com then click on the "Sign Up" Button on the top right. 
    - After registering, Click on your profile picture on the top right and goto "My Projects". https://wokwi.com/dashboard/projects
    - Afterwards, Create a "New Project" by clicking on the new project button.  
    - In this example, we use a ESP32-C3. Find the ESP32-C3 microcontroller under ESP32. *Please note: The microcontroller may change throughout the lab.*
    - After selecting the microcontroller, select "Micropython" Beginner Templates.
    -  You should now see a development environment with files like main.py and diagram.json. You should also see a simulation environment with the ESP32-C3-MINI-1. 
        - If you can't, you may be zoomed out or zoomed in too much. 

### Micropython
Micropython is a programming language specifically designed for microcontrollers that often have very little memory to store programs. Micropython is based on python 3 so most of the syntax follows python 3. The difference between Micropython and Python 3 is that micropython is specifically designed for microcontrollers so there are **less** general purpose libraries for micropython. 

**If you haven't ever coded before, please take a short tutorial on learning python:** https://www.w3schools.com/python/ 

Before the lab, please take a look at documentation and become familiar with Micropython. 

Here are some reference documentation for Micropython:
- https://docs.micropython.org/en/latest/


## Low level Programming
- High Level API Calls
- Register Access
- 

## Hardware 
Since we are doing all this in simulation, the hardware aspect of this is software defined. This means that the components exists as description that the simulation software reads to understand. 

# Background 
- In this lab, you will go over how electronics are developed at the software layer using a simulation software called Wokwi. 

## Wokwi: Interface 
- Play Button
- Components 
### Wokwi: Python Interactive Console (REPL)
Micropython also gives you an interactive REPL so you can run python commands in a live environment. The python interactive console allows you to experience, test, and debug code without a file. Instead of writing code in the "text file" environment, you can write that same code in the REPL and it will do the same thing. 

# Sample 1: Blinking LED. 
Blinks a LED. 

Board: ESP32-C3
Link: https://wokwi.com/projects/433782979021457409

main.py
```
1 from machine import Pin
2 from utime import sleep
3 # Comment: Blinks a LED
4 counter = 0 
5 print("DEBUG: Starting Program")
6 
7 led = Pin(5, Pin.OUT)
8 while True:
9  led.on()
10 sleep(0.5)
11 counter += 1
12 print("%d) DEBUG: Checking LED Status: %d" % (counter, led.value()))
13 led.off()
14 counter += 1
15 print(f"{counter}) DEBUG: Checking LED Status: {led.value()}")
16 sleep(0.5)
```
<br>Line 1,2: Importing libraries. Code that are accessed.
<br>Line 4: This counter shows that the program runs sequentially. 
<br>Line 5: Example of using Print statements
<br>Line 7: The Pin object exists in the "machine" library. Instantiating an Object of type "PIN" to be used as an output pin.
<br>Line 8: while True: keeps the loop and program running infinitely long. 
<br>Line 9: led.on() turns the pin to be high. So the voltage at that pin is HIGH. 
<br>Line 10, 16: sleep(0.5) makes the 
<br>Line 11, 14: Increments the counter to show the program running sequentially. 
<br>Line 12, 15: Print statements that shows various ways to show variables along with a string. 
<br> Line 13: led.off() turns the pin to be low. So the voltage at that pin is LOW.  

diagram.json
```
{
  "version": 1,
  "author": "Sci-Mi",
  "editor": "wokwi",
  "parts": [
    {
      "type": "board-esp32-c3-devkitm-1",
      "id": "esp",
      "top": 0,
      "left": 0,
      "attrs": { "env": "micropython-20231227-v1.22.0" }
    },
    { "type": "wokwi-led", "id": "led1", "top": 25.2, "left": 157.4, "attrs": { "color": "red" } }
  ],
  "connections": [
    [ "esp:TX", "$serialMonitor:RX", "", [] ],
    [ "esp:RX", "$serialMonitor:TX", "", [] ],
    [ "esp:GND.7", "led1:C", "black", [ "h0" ] ],
    [ "esp:5", "led1:A", "green", [ "h0" ] ]
  ],
  "dependencies": {}
}
```
Simulation: 
![Micropython Blinking LED Example](/assets/image/sample1_blinkingled_simulation.png)

# Sample 2: Acceleration Sensor Reading
Reads acceleration readings

Board: ESP32-DevKit-C-V4
Link: https://wokwi.com/projects/433793637802253313



# Sample 3: Controlling a servo 
Controls a Servo

main.py


# Exercise 1: Making a simple robot
Exercise 1 integrates all the samples to make an entire robot. 

# Exercise 2: Complex Robotics 
Exercise 2 will take that simple robot that you previously built in exercise 1 and expand it more to use multiple sensors and multiple actuators. 


