The following figure shows the concept of the target hardware:

![https://pic16f1454-bootloader.googlecode.com/hg/wiki/images/concept.png](https://pic16f1454-bootloader.googlecode.com/hg/wiki/images/concept.png)

The configuration words are chosen to disable MCLR (shared function on pin 4).  A dedicated hardware pin seems superfluous since resets are already achieved by the power-on reset generator (or watchdogs or software resets).

Said pin is input-only and has a built-in optional pull-up.  As a result, a switch state can be read with a minimum of components.  (Said switch could even be also used for the user application.)

RC0 through RC5 plus RA4 and RA5 are available for custom applications.  These pins have various configuration functions, including SPI, I2C, UART, etc., etc.