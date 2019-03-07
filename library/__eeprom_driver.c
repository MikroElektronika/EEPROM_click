/*
    __eeprom_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__eeprom_driver.h"
#include "__eeprom_hal.c"

/* ------------------------------------------------------------------- MACROS */



/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __EEPROM_DRV_I2C__
static uint8_t _slaveAddress;
#endif

const uint8_t _EEPROM_DEFAULT_I2C_ADDRESS                                = 0x51;
const uint8_t _EEPROM_START_NUMBER_0                                     = 0x00;
const uint8_t _EEPROM_END_NUMBER_255                                     = 0xFF;

/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */



/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */



/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __EEPROM_DRV_SPI__

void eeprom_spiDriverInit(T_EEPROM_P gpioObj, T_EEPROM_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __EEPROM_DRV_I2C__

void eeprom_i2cDriverInit(T_EEPROM_P gpioObj, T_EEPROM_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __EEPROM_DRV_UART__

void eeprom_uartDriverInit(T_EEPROM_P gpioObj, T_EEPROM_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif



/* ----------------------------------------------------------- IMPLEMENTATION */


/* Generic write byte of data function */
void eeprom_writeByte( uint8_t regAddress, uint8_t writeData )
{
    uint8_t wBuffer[ 2 ];
    
    wBuffer[ 0 ] = regAddress;
    wBuffer[ 1 ] = writeData;
    
    hal_i2cStart();
    hal_i2cWrite( _slaveAddress, wBuffer, 2, END_MODE_STOP );
}

/* Generic read byte of data function */
uint8_t eeprom_readByte( uint8_t regAddress )
{
    uint8_t wBuffer[ 1 ];
    uint8_t rBuffer[ 1 ];

    wBuffer[ 0 ] = regAddress;

    hal_i2cStart();
    hal_i2cWrite( _slaveAddress, wBuffer, 1, END_MODE_RESTART );
    hal_i2cRead( _slaveAddress, rBuffer, 1, END_MODE_STOP );
    
    return rBuffer[ 0 ];
}

/* Sequential read function */
void eeprom_readSequential( uint8_t regAddress, uint8_t *readData, uint8_t nBytes )
{
    uint8_t wBuffer[ 1 ];
    
    wBuffer[ 0 ] = regAddress;

    hal_i2cStart();
    hal_i2cWrite(_slaveAddress, wBuffer, 1, END_MODE_RESTART);
    hal_i2cRead(_slaveAddress, readData, nBytes, END_MODE_STOP);
}

/* Enable write to register function */
void eeprom_writeEnable()
{
    hal_gpio_pwmSet( 0 );
}

/* Disable ( protect ) write to register function */
void eeprom_writeProtect()
{
    hal_gpio_pwmSet( 1 );
}



/* -------------------------------------------------------------------------- */
/*
  __eeprom_driver.c

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */