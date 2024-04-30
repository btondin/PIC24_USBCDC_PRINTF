/*****************************************************************************
 * File:    myUSDCDC.h
 * Author:  Bruno Rodriguez tondin
 * Comments: 
 * Revision history: 1.01
 * Date: 30/04/2024
 *****************************************************************************/

#ifndef MYUSBCDC_H
#define	MYUSBCDC_H


/*
    MCC USB CDC Demo Usage:
 
    Call the MCC_USB_CDC_DemoTasks() function from your main loop.
    It will read data sent from the host and echo it back +1.  If you open
    up a terminal window and type 'a' then 'b' will be echoed back.
 */
void MCC_USB_CDC_DemoTasks(void); // Copy from MCC CDC Example from Microchip


#endif	/* MYUSBCDC_H */

