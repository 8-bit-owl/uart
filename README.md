# A Pseudo uart driver

## Intro
UART stands for Universal Asynchronous Receive Transmit. The way it works on a software level is, whenever an received buffers in the uart module are filled, there is an inerrupt generated, and the context is switched to the UART ISR by the CPU. The usual implmentation of the ISR is to copy data into the required buffers in the code and clear the UART buffers. This way, the uart buffers can accept data when ever there is a data transmission.

## Considerations for implementation
Since we dont have a hardware, we have to make some assumtions and some tweaks to implement UART in a linux machine. One of the main challanges is to generate an interrupt. Since we cannot actually have a way to generate an interrupt, we have to manually call the ISR to copy the data from the UART registers into the respective buffers.
This impementation is present in 
```
uart.c  & test_uart.c
```

### uart.c
uart.c has 2 functions. The ISR `uart_isr(uint8_t *data)` has the implementation to copy buffers and clear the uart buffers. This isr will ideally be called whenever there is an interrrupt.
There's also another method in uart.c `sequence_count(uint8_t *rx_buffer)`. This method returns the number of valid sequences present in the received uart buffer. A sequence is said to be valid if it has `0xa5` and `0x5a` consecutively. This method loops through all the 16 bytes and increments the counter everytime it encounters a `0xa5` and `0x5a` consicutively and returns the sequence count.

### test_uart.c
This is a c file to test if our driver is working correctly. we will pass various test cases to the uart isr and check the sequence count for each test case. 
There is a `DEBUG` option in `test_uart.c` which enables debug in our code, which prints all the data in the test cases.

## Build System
The project was built using CMake. The shell script absracts the CMake by running CMake commands as a part of `run.sh`, The shell script is present on top of CMake to move the executables and ensure the proper generation of executables.The build directory is not present in the repository but it can be generated using the command below.
```
sh run.sh
```

## Final executables
```
test_uart
```
This is the final executable and it is present at the root directory of this project. This repository can be cloned and the executable can be run. Ideally, it shouldnt be included and it should be a part of build directory. I just want to provide a convinient way to a user to have the executable without having a hassle of building the code and keeping the code footprint low.
