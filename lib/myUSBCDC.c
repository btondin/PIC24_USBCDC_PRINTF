#include <stdio.h>
#include "usb_device_cdc.h"


#include "usb.h"

int write(int handle, void *buffer, unsigned int len) {
    // Convert the buffer to an unsigned 8-bit integer pointer
    uint8_t *data = (uint8_t *)buffer;
    
    // Variable to store the number of bytes actually written
    unsigned int bytes_written = 0;
    
    // Send the data to the USB port using putUSBUSART
    while (bytes_written < len) {
        // Check if the USB transfer is ready to send more data
        if(USBUSARTIsTxTrfReady()) {
            // Calculate the number of bytes to be sent in this transmission
            unsigned int bytes_to_send = len - bytes_written;
            
            // Call putUSBUSART to send the data
            putUSBUSART(data + bytes_written, bytes_to_send);
            
            // Update the total number of bytes written
            bytes_written += bytes_to_send;
        }
        
        // Execute the CDC transmission service to send the data immediately
        CDCTxService();
    }
    
    // Return the number of bytes written
    return bytes_written;
}

static uint8_t readBuffer[64];
static uint8_t writeBuffer[64];



/*
    MCC USB CDC Demo Usage:
 
    Call the MCC_USB_CDC_DemoTasks() function from your main loop.
    It will read data sent from the host and echo it back +1.  If you open
    up a terminal window and type 'a' then 'b' will be echoed back.
 */

void MCC_USB_CDC_DemoTasks(void)
{
    if( USBGetDeviceState() < CONFIGURED_STATE )
    {
        return;
    }

    if( USBIsDeviceSuspended()== true )
    {
        return;
    }

    if( USBUSARTIsTxTrfReady() == true)
    {
        uint8_t i;
        uint8_t numBytesRead;

        numBytesRead = getsUSBUSART(readBuffer, sizeof(readBuffer));

        for(i=0; i<numBytesRead; i++)
        {
            switch(readBuffer[i])
            {
                /* echo line feeds and returns without modification. */
                case 0x0A:
                case 0x0D:
                    writeBuffer[i] = readBuffer[i];
                    break;

                /* all other characters get +1 (e.g. 'a' -> 'b') */
                default:
                    writeBuffer[i] = readBuffer[i] + 1;
                    break;
            }
        }

        if(numBytesRead > 0)
        {
            putUSBUSART(writeBuffer,numBytesRead);
        }
    }

    CDCTxService();
}