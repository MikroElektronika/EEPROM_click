![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# EEPROM Click

---

- **CIC Prefix**  : EEPROM
- **Author**      : Nenad Filipovic
- **Verison**     : 1.0.0
- **Date**        : Nov 2018.

---

### Software Support

We provide a library for the EEPROM Click on our [LibStock](https://libstock.mikroe.com/projects/view/388/eeprom-click-example) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

The library covers all the necessary functions to control EEPROM Click board.
EEPROM Click communicates with the target board via I2C.
This library contains drivers for write data to and read byte of data from register,
read sequential data, enable and disable write to register.

Key functions :

- ``` void eeprom_writeByte( uint8_t regAddress, uint8_t writeData ) ``` - Generic write byte of data function
- ``` uint8_t eeprom_readByte( uint8_t regAddress ) ``` - Generic read byte of data function
- ``` void eeprom_writeProtect() ``` - Disable ( protect ) write to register function

**Examples Description**

The application is composed of three sections :

- System Initialization - Initializes GPIO, I2C and LOG structures
     and set PWM pin as output.
- Application Initialization - Initialization driver enable's - I2C
     and start write log.
- Application Task - (code snippet) This is a example which demonstrates the use of EEPROM Click board.
     EEPROM Click communicates with register via I2C protocol
     by write data to and read data from memory of 24C08 chip on serial EEPROM.
     Results are being sent to the Usart Terminal where you can track their changes.


```.c

void applicationTask()
{
    mikrobus_logWrite( " Write to memory number from 0 to 255", _LOG_LINE );

    for ( counter = _EEPROM_START_NUMBER_0; counter < _EEPROM_END_NUMBER_255; counter++ )
    {
        eeprom_writeByte( counter, counter );
        Delay_10ms();
    }

    mikrobus_logWrite( " Write status: DONE", _LOG_LINE );
    mikrobus_logWrite( "------------------------------------------", _LOG_LINE );
    mikrobus_logWrite( " Reading from memory :", _LOG_LINE );
    Delay_1sec();

    for ( counter = _EEPROM_START_NUMBER_0; counter < _EEPROM_END_NUMBER_255; counter++ )
    {
        readData = eeprom_readByte( counter );
        Delay_10ms();
        IntToStr( readData, logText );
        mikrobus_logWrite( logText, _LOG_TEXT );
        mikrobus_logWrite( " ", _LOG_TEXT );
        Delay_100ms();
    }

    mikrobus_logWrite( "------------------------------------------", _LOG_LINE );
    Delay_1sec();
}

```



The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/388/eeprom-click-example) page.

Other mikroE Libraries used in the example:

- I2C


**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
---
