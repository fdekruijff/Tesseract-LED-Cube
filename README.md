# Tesseract LED cube project

The 'Individual Propedeuse Assignment' project of the University of Applied Sciences in Utrecht was for me about controlling 512 LED lights in a 8x8x8 cube. This repository contains the code and schematics for that cube.

### But.. how does it work?

The cube is controlled by an Arduino Mega. Even with its large amount of I/O ports, 512 lights to control is still a little enthuisiastic. Using wiring tricks, the 64 connections per layer is brought down to 16. Then with shift registers the remaining connections are brought back to 10 data lines. Using software and multiplexing the eye into the fact that the lights are on when they are actually turning on and off really quickly.

![cube](https://preview.ibb.co/b3sfDd/IMG_20180628_132724.jpg)

### The wiring diagram
The complete wiring diagram shows all the connections from the Arduino to the registers and led lights. The PDF is also included in the repository.

![wiring-diagram](https://preview.ibb.co/jkU5eJ/Screenshot_1.png)

### The software diagram
This diagram shows how the abstraction of the cube is made and what classes interface with each other. There is a single function in the cube class that translates the virtual 3D cube to the physical cube.

![software-diagram](https://preview.ibb.co/hb6e6y/Screenshot_2.png)

## Built With

* [CodeLite](https://codelite.org/) - A Free, open source, cross platform C,C++,PHP and Node.js IDE
* [hwlib](https://github.com/wovo/hwlib) - C++ wrapper library to interface with Arduino.
* 512x blue LEDs.
* 9x SN74HC595 shift registers.
* 15  meters of galvanised iron wire.
* 5  metets of default wire.



