/*
    __eeprom_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __eeprom_driver.h
@brief    EEPROM Driver
@mainpage EEPROM Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   EEPROM
@brief      EEPROM Click Driver
@{

| Global Library Prefix | **EEPROM** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **Nov 2018.**      |
| Developer             | **Nenad Filipovic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _EEPROM_H_
#define _EEPROM_H_

/** 
 * @macro T_EEPROM_P
 * @brief Driver Abstract type 
 */
#define T_EEPROM_P    const uint8_t*

/** @defgroup EEPROM_COMPILE Compilation Config */              /** @{ */

//  #define   __EEPROM_DRV_SPI__                            /**<     @macro __EEPROM_DRV_SPI__  @brief SPI driver selector */
   #define   __EEPROM_DRV_I2C__                            /**<     @macro __EEPROM_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __EEPROM_DRV_UART__                           /**<     @macro __EEPROM_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup EEPROM_VAR Variables */                           /** @{ */

extern const uint8_t _EEPROM_DEFAULT_I2C_ADDRESS;
extern const uint8_t _EEPROM_START_NUMBER_0;
extern const uint8_t _EEPROM_END_NUMBER_255;

                                                                       /** @} */
/** @defgroup EEPROM_TYPES Types */                             /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup EEPROM_INIT Driver Initialization */              /** @{ */

#ifdef   __EEPROM_DRV_SPI__
void eeprom_spiDriverInit(T_EEPROM_P gpioObj, T_EEPROM_P spiObj);
#endif
#ifdef   __EEPROM_DRV_I2C__
void eeprom_i2cDriverInit(T_EEPROM_P gpioObj, T_EEPROM_P i2cObj, uint8_t slave);
#endif
#ifdef   __EEPROM_DRV_UART__
void eeprom_uartDriverInit(T_EEPROM_P gpioObj, T_EEPROM_P uartObj);
#endif


/** @defgroup EEPROM_FUNC Driver Functions */                   /** @{ */



/**
 * @brief Generic write byte of data function
 *
 * @param[in] regAddress         8-bit register address
 *
 * @param[in] writeData          8-bit data to write
 *
 * Function write the 8-bit data to the
 * target 8-bit register address of 24C08 chip on serial EEPROM.
 */
void eeprom_writeByte( uint8_t regAddress, uint8_t writeData );

/**
 * @brief Generic read byte of data function
 *
 * @param[in] regAddress         8-bit register address
 *
 * @return
 * 8-bit read data
 *
 * Function read the 8-bit data from the
 * target 8-bit register address of 24C08 chip on serial EEPROM.
 */
uint8_t eeprom_readByte( uint8_t regAddress );

/**
 * @brief Sequential read function
 *
 * @param[in] regAddress         8-bit register address
 *
 * @param[in] readData           pointer of 8-bit read data
 *
 * @param[in] nBytes             number of bytes to read
 *
 * Function read nBytes number of the 8-bit data from the
 * target memory location of 24C08 chip on serial EEPROM
 * and stores array of 8-bit to buffer determined by readData pointer.
 */
void eeprom_readSequential( uint8_t regAddress, uint8_t *readData, uint8_t nBytes );

/**
 * @brief Enable write to register function
 *
 * Function enable to write data to register 
 * of 24C08 chip on serial EEPROM.
 */
void eeprom_writeEnable();

/**
 * @brief Disable ( protect ) write to register function
 *
 * Function disable to write data to register ( write protected )
 * of 24C08 chip on serial EEPROM.
 */
void eeprom_writeProtect();



                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_EEPROM_STM.c
    @example Click_EEPROM_TIVA.c
    @example Click_EEPROM_CEC.c
    @example Click_EEPROM_KINETIS.c
    @example Click_EEPROM_MSP.c
    @example Click_EEPROM_PIC.c
    @example Click_EEPROM_PIC32.c
    @example Click_EEPROM_DSPIC.c
    @example Click_EEPROM_AVR.c
    @example Click_EEPROM_FT90x.c
    @example Click_EEPROM_STM.mbas
    @example Click_EEPROM_TIVA.mbas
    @example Click_EEPROM_CEC.mbas
    @example Click_EEPROM_KINETIS.mbas
    @example Click_EEPROM_MSP.mbas
    @example Click_EEPROM_PIC.mbas
    @example Click_EEPROM_PIC32.mbas
    @example Click_EEPROM_DSPIC.mbas
    @example Click_EEPROM_AVR.mbas
    @example Click_EEPROM_FT90x.mbas
    @example Click_EEPROM_STM.mpas
    @example Click_EEPROM_TIVA.mpas
    @example Click_EEPROM_CEC.mpas
    @example Click_EEPROM_KINETIS.mpas
    @example Click_EEPROM_MSP.mpas
    @example Click_EEPROM_PIC.mpas
    @example Click_EEPROM_PIC32.mpas
    @example Click_EEPROM_DSPIC.mpas
    @example Click_EEPROM_AVR.mpas
    @example Click_EEPROM_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __eeprom_driver.h

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