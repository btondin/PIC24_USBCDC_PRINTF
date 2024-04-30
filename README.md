# Printf Implementation for PIC24 (MPLABX MCC)

This repository provides an implementation of the `write()` function used by the `printf` function from the standard library `stdio.h` for PIC24 microcontrollers programmed using MPLABX's MCC (MPLAB Code Configurator). This implementation allows you to use `printf` and related functions for debugging and logging purposes in your PIC24 projects.

## Features

- Lightweight implementation of the `write()` function optimized for PIC24 microcontrollers.
- Compatible with MPLABX's MCC-generated code and standard library `stdio.h`.
- Supports basic formatted printing of strings, integers, and characters.

## Implementation Details

The implementation of the `write()` function in this repository is based on the Microchip article ["How to Configure printf"](https://microchip.my.site.com/s/article/How-to-Configure-printf). It provides a step-by-step guide on configuring the `printf` function to work with Microchip microcontrollers.

## Usage

To use this `write()` implementation in your PIC24 project with `printf`, follow these steps:

1. Clone or download this repository to your development environment.
2. Copy the `printf.c` and `printf.h` files into your MPLABX project directory.
3. Include the `printf.h` header file in your source code where you want to use `printf`.
4. Initialize the UART module in your MCC-generated code. Ensure that the UART settings (baud rate, data bits, parity, stop bits) match those in `printf.c`.
5. Call `printf` and related functions as needed in your code for debugging and logging.

```c
#include "mcc_generated_files/system.h"
#include "pin_manager.h"
#include "clock.h"
#include <stdio.h>
#define FCY _XTAL_FREQ/2 //Pois frequencia dos ciclos = fosc/2
#include <libpic30.h>
#include <myUSBCDC.h>
//#include "usb_device_cdc.h"



/*
                         Main application
 */
int main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    
    
    
    __delay_ms(1000);
    
    unsigned long i = 0;

    while (1)
    {
        __delay_ms(100);
        LED_Toggle();
        //MCC_USB_CDC_DemoTasks();        
        printf("Hello World!\n %ld \n\n", i);
        i++;
        
    }
    return 1;
}
