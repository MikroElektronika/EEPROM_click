/*
Example for EEPROM Click

    Date          : Nov 2018.
    Author        : Nenad Filipovic

Test configuration PIC :
    
    MCU             : P18F87K22
    Dev. Board      : EasyPIC PRO v7
    PIC Compiler ver : v7.2.0.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes GPIO, I2C and LOG structures
     and set PWM pin as output.
- Application Initialization - Initialization driver enable's - I2C
     and start write log.
- Application Task - (code snippet) This is a example which demonstrates the use of EEPROM Click board.
     EEPROM Click communicates with register via I2C protocol
     by write data to and read data from memory of 24C08 chip on serial EEPROM.
     Results are being sent to the Usart Terminal where you can track their changes.


*/

#include "Click_EEPROM_types.h"
#include "Click_EEPROM_config.h"


uint8_t readData;
uint8_t counter;
char logText[ 50 ] = { 0 };

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_PWM_PIN, _GPIO_OUTPUT );

    mikrobus_i2cInit( _MIKROBUS1, &_EEPROM_I2C_CFG[0] );

    mikrobus_logInit( _LOG_USBUART, 9600 );

    Delay_100ms();
}

void applicationInit()
{
    eeprom_i2cDriverInit( (T_EEPROM_P)&_MIKROBUS1_GPIO, (T_EEPROM_P)&_MIKROBUS1_I2C, _EEPROM_DEFAULT_I2C_ADDRESS );

    mikrobus_logWrite( "             ----------------", _LOG_LINE );
    mikrobus_logWrite( "               EEPROM Click               ", _LOG_LINE );
    mikrobus_logWrite( "             ----------------", _LOG_LINE );
}

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

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
            applicationTask();
    }
}