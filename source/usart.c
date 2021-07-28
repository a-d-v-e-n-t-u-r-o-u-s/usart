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

#include "usart.h"
#include "hardware.h"
#include <stddef.h>
#include <avr/io.h>
#include <limits.h>

#define BAUDRATE        500000UL
#define UBRR            (F_CPU/16/BAUDRATE - 1)

#define MODE_8BIT_MASK  (3u << UCSZ0)

void USART_transmit(uint8_t data)
{
    while((UCSRA & (1 << UDRE)) == 0)
    {
        /* busy wait for flag to be set */
    }

    UDR = data;
}

void USART_configure(const USART_config_t *config)
{
    if(config != NULL)
    {
        UBRRH = (UBRR >> CHAR_BIT);
        UBRRL = (UBRR);
        UCSRB = (1 << RXEN)|(1 << TXEN);
        UCSRC = (1 << URSEL)|(1 << USBS) | MODE_8BIT_MASK;
    }
}
