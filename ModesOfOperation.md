# BOOTLOADER #

Upon power-up, the firmware goes into BOOTLOADER mode if either:

  * it is detected that the user has pressed the recovery switch
  * the user code image fails a CRC check

In BOOTLOADER mode, the device enumerates as a vendor-defined HID device (multi-OS compatible)

# USERIMAGE #

Upon power-up, the firmware goes into USERIMAGE mode if the following conditions are true:

  * it has not been detected that the user has pressed the recovery switch
  * the user code passes a CRC check

Code branches directly to the user code at 0x1000.  This is compatible with the XC8 compiler option "--CODEOFFSET".

4096 of 8192 words are used by the bootloader.  4095 of 8192 words are available for use by the user in this mode.  1 of 8192 words are used as a CRC.

4095 words, although only half the flash memory, is enough to compile the Microchip example code projects for HID, CDC, etc., etc.

![https://pic16f1454-bootloader.googlecode.com/hg/wiki/images/memmap.png](https://pic16f1454-bootloader.googlecode.com/hg/wiki/images/memmap.png)