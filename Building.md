For 99.9% of people reading this, you are probably looking in the wrong place.

Nearly all users should download the provided prebuilt image for the pic16f1454-bootloader.  You don't need to compile it, and that programming step should only need to be done once.  (You might even be able to get someone else to pre-program the PIC chip on your behalf.)

For 99.9% of users, what you are likely really interested in is how to compile application to download to the PIC chip using the bootloader.

For this, consult the wiki pages on the example code provided and/or the MPLAB X settings for converting an existing application.

Please don't waste time building the code if you don't need to (which is nearly every user).  Instead, download the prebuilt images available here:

https://code.google.com/p/pic16f1454-bootloader/source/browse/#hg%2Fprebuilt

Your time is better spent writing applications to download using this bootloader, not building the bootloader itself.

If you insist on changing the bootloader, you **MUST NOT** use the VID:PID assigned to this project.  Otherwise, you are doing a disservice to normal users who expect the bootloader to be the pre-built one.

The building process is artificially complicated by the need to download the Microchip USB library separate from the actual bootloader code (in order to comply with Microchip's MLA license terms).  To make things even more difficult, Microchip periodically changes the MLA to make it incompatible with previous releases.  (Gee, thanks Microchip.)

Prerequisite skills:

  * familiar with using a Makefile

  * familiar with using a cross-compiler for an embedded microcontroller

I presume that users already familiar with use of a Makefile have "make" installed on their computer.

Three pieces of software need to be downloaded:

#1 XC8 compiler (171MB at last check)

http://www.microchip.com/pagehandler/en_us/devtools/mplabxc/

The XC8 Compiler install is straightforward.  I used v1.21.

#2 The source code for this project (a few kilobytes)

The source code for this project is available for download on these web pages.  Place it in a subdirectory of your choosing.

#3 USB Framework from Microchip Libraries for Applications (277MB at last check)

Go to the following page, scroll down to the bottom, and pick the "Archives" tab.  Then, pick version "v2013-02-15":

http://www.microchip.com/pagehandler/en-us/devtools/mla/legacy-mla.html

The Microchip Libraries for Applications install is less straightforward unfortunately.  Several hundred MBs of stuff needs to be downloaded (of which only a few kilobytes is relevant).

Of all the installation options, only the USB one is relevant to this project.  Even if only the USB checkbox is selected, it still installs lots of extra junk.

Much to my profound irritation, the Windows installer attempts to download the .NET Framework and Java.  These are quite superfluous and can be omitted in my experience.

After the Microchip Libraries for Applications install, copy the following files (preserving the indicated path) into the same subdirectory as the project source code:

```
.\Include\Compiler.h
.\Include\USB
.\Include\USB\usb.h
.\Include\USB\usb_ch9.h
.\Include\USB\usb_common.h
.\Include\USB\usb_device.h
.\Include\USB\usb_device_local.h
.\Include\USB\usb_function_cdc.h
.\Include\USB\usb_function_hid.h
.\Include\USB\usb_hal.h
.\Include\USB\usb_hal_pic16f1.h
```

Copy the following into the same subdirectory as the project source code:
```
C:\microchip_solutions_v2013-02-15\Microchip\USB\usb_device.c
C:\microchip_solutions_v2013-02-15\Microchip\USB\HID Device Driver\usb_function_hid.c
C:\microchip_solutions_v2013-02-15\Microchip\USB\CDC Device Driver\usb_function_cdc.c
```

Apply the patches to these three files.

Adjust the paths as needed in the Makefile.

Make the project.