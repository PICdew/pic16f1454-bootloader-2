The PIC16F1454 microcontroller is an aggressively priced (under $1.50 in single quantity and under $1.00 in larger quantities) USB-enabled microcontroller from Microchip.  It is also able to discipline its internal RC oscillator using the USB interface, allowing the designer to forgo an external crystal (further enhancing the cost advantage over other vendors' microcontrollers).

No example bootloader source code is provided by Microchip for this device family.  I had to write my own, and this project shares that source code.

The bootloader operates as a vendor-defined HID USB device, meaning it is compatible with multiple OSes and requires no drivers.

![http://www.2x4logic.com/bootdot.gif](http://www.2x4logic.com/bootdot.gif)

**Updates:**

**20150307** My intent is to move the bootloader to the excellent M-Stack.  I've already replaced the existing mouseplay example with one based on M-Stack and updated the Wiki articles.  The bootloader is also working under M-Stack, but I'm going to do more testing before making it official.  End users should be completely indifferent as to whether the bootloader is based on Microchip MLA or M-Stack, as both should function the same.  **However**, end users should be **very** interested in the new example applications that use M-Stack as using it greatly simplifies the process of compiling code and taking advantage of the bootloader.

**20150303** An experimental variant of the bootloader using [Signal 11's open-source M-Stack](http://www.signal11.us/oss/m-stack/), rather than [Microchip's USB Framework](http://www.microchip.com/mla), has been checked into the source code repository.  M-Stack, unlike Microchip's stack, is not burdened with a convoluted license agreement that prohibits the entire source code from being made public directly.

**20140811** An observant user noticed that the download tool was using the Revision ID, rather than the Device ID, to vet the part before downloading.  This resulted in a "the PIC's Device ID is invalid" error message when using newer silicon.  The download tool has been updated to fix this.

**20140717** Do yourself a favor; please try using the provided prebuilt bootloader images.  Nearly all users do **NOT** need to build the code from source.  If you insist on building (and modifying) the code, you **MUST NOT** use the same VID:PID.  That value is reserved for use with the code as-is; you would be doing a disservice to users who rightfully should expect the bootloader to be consistent.

The prebuilt images are [here](https://code.google.com/p/pic16f1454-bootloader/source/browse/#hg%2Fprebuilt)

**20140410** I've had multiple inquiries in just the past few days about using the PIC16F1454 as a CDC serial adapter.  Microchip already provides sample source for this; please consult this.  Only as a convenience to users, I've compiled Microchip's sample code and provided .hex [files](https://code.google.com/p/pic16f1454-bootloader/source/browse/#hg%2Fcdcdemo) in the Source section.  Please compile Microchip's code yourself for your application.  I've also updated the Wiki to provide further information.

**20140301** The bootloader has been updated from v1.02 to v1.03 to add a feature that hopefully will be of utility to users.  If the PIC reboots due to a watchdog reset, the bootloader is loaded in preference to the user app.  I added this feature after developing some hardware too small to install a pushbutton/jumper.  The user app can deliberately initiate a watchdog event (see keyfob app source code for an example), thereby rebooting into the bootloader without having to even touch the hardware.

**20140210** Great news!  Openmoko has graciously provided a VID:PID.  This means we can have a known value to standardize on.  I've updated the source code to use this new value, and have provided some prebuilt images to try.  Navigate to "Source" and browse the directory, or use this [link](https://code.google.com/p/pic16f1454-bootloader/source/browse/#hg%2Fprebuilt).

**20140205** I've added another example demo app which emulates a keyboard and also demonstrates how the same button to boot into the bootloader can double as a user input.

**20140201** I've added an example demo app (an emulated mouse that runs the cursor in circles) to the source code.  Check out the Wiki for a complete list of demo apps.