**Q1: How do I compile your example programs under MPLAB X?**

Some of the example programs are now based on M-Stack and can be compiled under MPLAB X.  (However, I continue to provide a Makefile for users who know what they are doing and don't want a frustrating GUI.)

Don't ask me questions about using MPLAB X.  MPLAB X is an utter piece of garbage that I wouldn’t wish upon my worst enemies.  If I get hit with requests for supporting MPLAB X, I will pull the plug on this project.

Also, see Q2 below for legacy source code based on the Microchip USB Framework (aka MLA).  Since the USB Framework is separate from MPLAB X, and both are separate from your source code, it is highly problematic to create a re-distributable MPLAB X project with USB support that has the right directory paths.

If you have MPLAB X problems, contact Microchip.  In my experience, they won’t help you, but their tech support will be sure to aggravate you so much that you might forget about the problem that you originally contacted them about.

**Q2: Why do you provide patch files for the USB Framework instead of the USB Framework files themselves?**

Microchip has a license agreement with their USB Framework that prohibits distribution of those source code files.

This forces open source projects like this one into the painful situation of having to provide incomplete files, and then get questions about what to do about the missing files.

**Q3: Give me USB-to-serial CDC.**

The bootloader provides an optional built-in CDC, however this is strictly for advanced users.  If you don’t know enough about C and Makefiles to understand the source code, it is likely not for you.

However, do not worry.  You will hopefully like the pre-built image of Microchip’s sample CDC implementation available in the source files.  There is plenty of information on the Wiki on how to customize a Microchip sample USB project so as to be ready to be loaded by the bootloader.

I do not provide pre-built images with the CDC incorporated for three reasons:

a) There are multiple chip variants ('1454, '1455, and '1459), and they have different pins mapped to the UART (forcing multiple versions of firmware images).  Furthermore, as currently written, the bootloader CDC functionality is just for the '1454.

b) The CDC integrated into the bootloader is a fixed bit rate one.  I think most people assume that a CDC implementation allows them to change the bit rate (or are perhaps using some GUI and don't even know what bit rates are), and I didn't want lots of confused people emailing me.  (There is a way to set the bit rate, but the MPLAB X chip programmer is broken and won’t allow this bootloader feature to work.)

c) CDC can require drivers (depending on the host OS).  Without CDC, the bootloader is driver-less, which is a big advantage for doing a pain-free firmware update.

**Q4: I currently have a PCB with a PIC and then I additionally use an USB-to-TTL adapter to talk to the PIC whilst it is running my code.  I see "CDC" mentioned and think that this means the pic16f1454-bootloader could replace the USB-to-TTL adapter.  Can it?**

If you want to have a CDC adapter operate simultaneously whilst you are running your own code on the PIC, the answer is NO.

When the PIC16F145x is acting as a CDC adapter, the PIC is running an application that provides the CDC adapter.  It can't simultaneously be running your application.  The two are mutually exclusive.  You can either download firmware for a CDC or download your custom firmware.

However, if you are presently using a CDC adapter to download your application, you could use pic16f1454-bootloader to download the application directly via USB instead and not need a CDC adapter.

If your PIC16F145x has been previously programmed with pic16f1454-bootloader, it has the ability to reprogram itself with an application of your choice directly from a PC over USB without needing a serial adapter or a programmer.