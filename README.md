# Firmware: Sensors, Actuators, and more!
Welcome to the embedded system lab. 

# Pre Requisites
- Read/watched the Embedded System Lecture
- Read/watched the Digital Design Lecture/Lab
- Do the prelab

## Firmware Engineering Background Information

## Systems Thinking

Firmware and low-level programming fall under "Systems Thinking" — balancing a holistic view of how components interconnect with deep knowledge of granular details. The biggest tech companies are fundamentally systems companies; their moat comes from selling complete, integrated solutions rather than individual parts. Cloud services are a prime example: users get an abstracted interface to endless compute, while underneath lies a deeply complex stack of hardware and software working in concert.

In systems engineering, the real challenge isn't building individual components — it's understanding how all the pieces fit together. When problems arise, everything is a suspect because everything is interconnected. What makes systems uniquely difficult is that complexity scales non-linearly; as systems grow, entirely new methodologies are needed just to manage them. Building individual components is relatively trivial today, with vast amounts of reusable code available, but designing a full system demands a much higher order of thinking — accounting for safety, security, and countless emergent interactions.

There is an inherent tension between attending to fine-grained details and maintaining a broader view of how individual components fit into a larger system. Focusing too narrowly risks losing sight of the overall picture, while thinking too broadly can cause critical details to be overlooked. The challenge lies in knowing when to shift between these two perspectives.

## Electronics and Firmware
Electronics are created through a mix of analog and digital circuit components. Firmware directly accesses mainly the digital circuit components through an interface. Often, this interface is through a microcontroller. Microcontrollers consist of registers that allow programs to directly access to control the behavior of the underlying circuit.

### Abstraction: Application Programming Interface (API)
An application programming interface (API) is a abstraction layer that programmers create to keep granular details a secret to keep complexity in check. Simply put, API's are libraries of code that has already been created to be reused. API's methods are either accessors or mutators. Accessors will read out information whereas mutators will modify objects. 

### High Level API Calls

High Level API is an abstraction layer that ultimately calls lower level programming API. 

In micropython, a simple example is blinking an LED. See: https://wokwi.com/projects/359801682833812481

```
from machine import Pin
from utime import sleep

led = Pin(15, Pin.OUT) # Instantiating the LED object 
while True:
  led.on()
  sleep(0.5)
  led.off()
  sleep(0.5)
```

By importing "machine", you get access to the "Pin" object. Underneath the hood, you are creating an object that has the declared pins ready to go for a specific microcontroller and then calling functions that have been already created to get the led to blink. Lower level details are abstracted away so you need to look at documentation to figure out how to use the "Pin" object. For more information, see: https://docs.micropython.org/en/latest/pyboard/tutorial/leds.html

### Low Level API Calls

Low level programming directly works with hardware using mechanisms like register level access and communication protocols. Low level APIs is the granular details that higher level APIs abstract away. Low level programming ties alot to digital design lectures because ultimately many of the details that you need to understand low level programming comes from the digital design space. 

Also in micropython, this is the same algorithm to blink an LED but with more granular details using register level access.
```
# Example 1: Lower Level API Access
from machine import mem32
import time

# ESP32 GPIO Register Base Address
GPIO_BASE_ADDR = 0x3FF44000

# Offsets from base
GPIO_OUT_OFFSET        = 0x04  # Read output level
GPIO_OUT_W1TS_OFFSET   = 0x08  # Set output (1 = HIGH)
GPIO_OUT_W1TC_OFFSET   = 0x0C  # Clear output (1 = LOW)
GPIO_ENABLE_OFFSET     = 0x20  # Output enable

# Functionality register address
GPIO_OUT_REG      = GPIO_BASE_ADDR + GPIO_OUT_OFFSET
GPIO_OUT_W1TS_REG = GPIO_BASE_ADDR + GPIO_OUT_W1TS_OFFSET
GPIO_OUT_W1TC_REG = GPIO_BASE_ADDR + GPIO_OUT_W1TC_OFFSET
GPIO_ENABLE_REG   = GPIO_BASE_ADDR + GPIO_ENABLE_OFFSET

# Choose the GPIO pin
GPIO_NUM = 15
PIN_MASK = 1 << GPIO_NUM #0b1 << GPIO_NUM = 0b1000...00 , numbers of zeros depende on the GPIO Num

# Set GPIO2 as output
mem32[GPIO_ENABLE_REG] |= PIN_MASK

# Blink loop
while True:
    print(f"Before ON: GPIO_OUT = {bin(mem32[GPIO_OUT_REG])}")
    mem32[GPIO_OUT_W1TS_REG] = PIN_MASK  # LED ON
    print(f"After ON:  GPIO_OUT = {bin(mem32[GPIO_OUT_REG])}")
    time.sleep(0.5)
    print(f"Before OFF: GPIO_OUT = {bin(mem32[GPIO_OUT_REG])}")
    mem32[GPIO_OUT_W1TC_REG] = PIN_MASK  # LED OFF
    print(f"After OFF: GPIO_OUT = {bin(mem32[GPIO_OUT_REG])}")
    time.sleep(0.5)
```
Link: https://wokwi.com/projects/438145871326704641

You may ask, where does these magic numbers come from? See Link: [ESP32 Technical Manual](https://www.mouser.com/pdfdocs/ESP32-Tech_Reference.pdf?srsltid=AfmBOopwrhod4EnESqcg54uDPF-MAuQZXA1Mrt7IrSkeaRs3pkWa2d7T&utm_source=chatgpt.com)

- On Page 59. Under 4.12 Register Summary

## Hardware 
Since we are doing all this in simulation, the hardware aspect is software defined. This means that the components exists as description that the simulation software reads to understand. In the real world, you do need to understand the hardware aspect of the system. 

## Wokwi: Interface 
- Play Button
- Components

## Prelab 
Follow Lab_Setup.md
 

# What's Next
Lab 1 - Open lab1/Lab1.md

Lab 2 - Open lab2/Lab2.md