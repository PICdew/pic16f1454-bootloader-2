/*
    example HID mouse using PIC16F1454 microcontroller

    originally written for Microchip USB Framework (aka MLA), but
    now based on M-Stack by Alan Ott, Signal 11 Software

    Copyright (C) 2014,2015 Peter Lawrence

    Permission is hereby granted, free of charge, to any person obtaining a 
    copy of this software and associated documentation files (the "Software"), 
    to deal in the Software without restriction, including without limitation 
    the rights to use, copy, modify, merge, publish, distribute, sublicense, 
    and/or sell copies of the Software, and to permit persons to whom the 
    Software is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in 
    all copies or substantial portions of the Software.

    The software is for use solely and exclusively on Microchip PIC 
    Microcontroller products. 

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL 
    THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER 
    DEALINGS IN THE SOFTWARE.
*/

#include "usb.h"
#include <xc.h>
#include <string.h>
#include "usb_config.h"
#include "usb_ch9.h"
#include "usb_hid.h"

/* 
since this is a downloaded app, configuration words (e.g. __CONFIG or #pragma config) are not relevant
*/

/* counter incremented by USB SOF (Start Of Frame) to track approximate time between reports */
static uint8_t tick_count;

/* arbitrary mouse movement pattern to play back */
const int8_t move_table[]=
{
	/* 
	X, Y, (at time 0)
	X, Y, (at time 1)
	X, Y, (at time 2)
	...
	*/
	6, -2,
	2, -6,
	-2, -6,
	-6, -2,
	-6, 2,
	-2, 6,
	2, 6,
	6, 2,
};

int main(void)
{
	uint8_t table_index = 0;
	uint8_t *hid_report_in;

#ifdef USB_USE_INTERRUPTS
	INTCONbits.PEIE = 1;
	INTCONbits.GIE = 1;
#endif

	usb_init();

	hid_report_in = usb_get_in_buffer(1);

	for (;;)
	{
#ifndef USB_USE_INTERRUPTS
		usb_service();
#endif

		/* if USB isn't configured, there is no point in proceeding further */
		if (!usb_is_configured())
			continue;

		/* proceed further only if it is possible to send more data */
		if (usb_in_endpoint_halted(1) || usb_in_endpoint_busy(1))
			continue;

		if (tick_count > 63) /* if more than 64 ms has passed since the last report... */
		{
			/* table_index modulus 16 *AND* make table_index an even number */
			table_index &= 0xE;

			/* build HID report */
			hid_report_in[0] = 0;
			hid_report_in[1] = move_table[table_index++];
			hid_report_in[2] = move_table[table_index++];

			/* transmit HID report */
			usb_send_in_buffer(1, 3);

			tick_count = 0;
		}
	}
}

/* Callbacks. These function names are set in usb_config.h. */
int8_t app_unknown_setup_request_callback(const struct setup_packet *setup)
{
	/* To use the HID device class, have a handler for unknown setup
	 * requests and call process_hid_setup_request() (as shown here),
	 * which will check if the setup request is HID-related, and will
	 * call the HID application callbacks defined in usb_hid.h. For
	 * composite devices containing other device classes, make sure
	 * MULTI_CLASS_DEVICE is defined in usb_config.h and call all
	 * appropriate device class setup request functions here.
	 */
	return process_hid_setup_request(setup);
}

void app_start_of_frame_callback(void)
{
	tick_count++;
}

void interrupt isr()
{
#ifdef USB_USE_INTERRUPTS
    usb_service();
#endif
}
