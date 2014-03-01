# CV KEY

An endeavor to create a device that provides universal support for more efficient and ergonomic copy-paste functionality on computers.

## Running Updates

+ Primary code structure and circuit built and tested on Arduino Uno. The board is able to write copy-paste commands to serial monitor upon corresponding button presses. The code can be better optimized; unpredictable output at times.

+ Updated the Atmega16U2 on the Uno via DFU. Atmel FLIP used to push keyboard emulating capability on to the board. The circuit is now recognized as a HID keyboard when plugged into a computer. Copy-paste commands being correctly interpreted by the computer.
