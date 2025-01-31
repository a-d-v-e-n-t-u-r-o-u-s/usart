/*!
 * \file
 * \brief Usart driver
 * \author Dawid Babula
 * \email dbabula@adventurous.pl
 *
 * \par Copyright (C) Dawid Babula, 2018
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef USART_H
#define USART_H

/*!
 *
 * \addtogroup usart
 * \ingroup drivers
 * \brief USART implementation
 */

/*@{*/

#include <stdint.h>

/*!
 *
 * \addtogroup usart_baudrates
 * \ingroup usart
 * \brief USART baudrates
 */
/*@{*/
#define USART_300_BAUDRATE      (0U)
#define USART_1200_BAUDRATE     (1U)
#define USART_2400_BAUDRATE     (2U)
#define USART_4800_BAUDRATE     (3U)
#define USART_9600_BAUDRATE     (4U)
#define USART_19200_BAUDRATE    (5U)
#define USART_38400_BAUDRATE    (6U)
#define USART_57600_BAUDRATE    (7U)
#define USART_115200_BAUDRATE   (8U)
#define USART_230400_BAUDRATE   (9U)
/*@}*/

/*!
 *
 * \addtogroup usart_databits
 * \ingroup usart
 * \brief USART data bits
 */
/*@{*/
#define USART_5_DATA_BITS       (0U)
#define USART_6_DATA_BITS       (1U)
#define USART_7_DATA_BITS       (2U)
#define USART_8_DATA_BITS       (3U)
#define USART_9_DATA_BITS       (4U)
/*@}*/

/*!
 *
 * \addtogroup usart_parity
 * \ingroup usart
 * \brief USART parity
 */
/*@{*/
#define USART_NO_PARITY         (0U)
#define USART_EVEN_PARITY       (1U)
#define USART_ODD_PARITY        (2U)
/*@}*/

/*!
 *
 * \addtogroup usart_stopbits
 * \ingroup usart
 * \brief USART stop bits
 */
/*@{*/
#define USART_1_STOP_BITS       (0U)
#define USART_2_STOP_BITS       (1U)
/*@}*/


/*!
 * \struct USART_config_t
 *
 * \brief Usart configuration structure
 *
 * \var USART_config_t::baudrate
 *      Usart baudrate setting
 * \var USART_config_t::databits
 *      Usart data bits setting
 * \var USART_config_t::parity
 *      Usart parity setting
 * \var USART_config_t::stopbits
 *      Usart stop bits setting
 */
typedef struct
{
    uint8_t baudrate;
    uint8_t databits;
    uint8_t parity;
    uint8_t stopbits;
} USART_config_t;

/*!
 * \brief Transmits data over usart
 *
 * \param data data to be transmitted
 */
void USART_transmit(uint8_t data);

/*!
 * \brief Configures usart driver.
 *
 * \param config usart configuration structure
 */
void USART_configure(const USART_config_t *config);

/*@}*/
#endif
