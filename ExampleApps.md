Browse the source code:

https://code.google.com/p/pic16f1454-bootloader/source/browse/example-apps

for examples.

Code that is ready-to-compile in MPLAB X (and based on the excellent [M-Stack](http://www.signal11.us/oss/m-stack/) written by Alan Ott of Signal 11 Software):

**mouseplay**: an emulated mouse that runs the cursor around in circles

**customHID**: a vendor-defined custom HID example that is compatible with [HIDAPI](http://www.signal11.us/oss/hidapi/)  This may be a starting point for a "driver-less" USB project.

**hid\_mouse**: this is an existing example M-Stack based implementation written by Alan Ott of Signal 11 Software.  If you compare this against the original hid\_mouse source code, you'll see that the build changes to load an application using the bootloader are minimal.

Legacy code based on MLA (which cannot be compiled as-is in MPLAB X):

**passfob**: an emulated keyboard that types out a string chosen at compile-time in response to a button press.  The button is the same as the one used entering the bootloader; see the Wiki article "Hardware" for a conceptual schematic.  The source code also demonstrates an optional way of monitoring the SCROLL-LOCK key to initiate a reboot into the bootloader without touching the hardware.

These apps are nothing fancy, but they demonstrate how the bootloader can be used and perhaps serve as a basis or inspiration for developing your own apps.

![http://www.2x4logic.com/appdot.gif](http://www.2x4logic.com/appdot.gif)

More elaborate apps are:

Dapper Miser (closed source CMSIS-DAP ARM debugger)
http://www.2x4logic.com/dapper.html

ANSI meter reader (CDC-based device under development)
https://code.google.com/p/typetwo/