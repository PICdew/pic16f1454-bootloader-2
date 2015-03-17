Microchip already provides a sample CDC application in their USB Framework:

```
C:\microchip_solutions_v2013-02-15\USB\Device - CDC - Serial Emulator\
```

It only supports bit rates up to 115200 bps.

Please customize it to suit your application.  I've provided a pre-compiled version [here](https://code.google.com/p/pic16f1454-bootloader/source/browse/#hg%2Fcdcdemo).  There are distinct .hex file for the '1454/'1455 14-pin device and for the '1459 20-pin device.

For your convenience, I indicate the UART pinouts below, however, you must consult the PIC16F1454 [datasheet](http://www.microchip.com/wwwproducts/Devices.aspx?product=PIC16F1454) for specifics.

![https://pic16f1454-bootloader.googlecode.com/hg/wiki/images/picuartpins.png](https://pic16f1454-bootloader.googlecode.com/hg/wiki/images/picuartpins.png)