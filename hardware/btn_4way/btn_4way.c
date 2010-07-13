/*
 * hd44780 driver library
 *
 * (c) by Alexander Neumann <alexander@bumpern.de>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License (either version 2 or
 * version 3) as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 * For more information on the GPL, please go to:
 * http://www.gnu.org/copyleft/gpl.html
 */

#include <avr/io.h>
#include <util/delay.h>

#include "btn_4way.h"
#include "config.h"
#include "core/debug.h"
#include "core/tty/tty.h"

/* global variables */

static uint8_t btn_4way_state = 0;
static uint8_t btn_4way_state_hist = 0;

#define BTN_4WAY_LEFT	PA0
#define BTN_4WAY_UP	PA1
#define BTN_4WAY_RIGHT	PA2
#define BTN_4WAY_DOWN	PA3

void btn_4way_main(void)
{
	btn_4way_state = 0;
	if (PIN_HIGH(BTN_4WAY_LEFT))	btn_4way_state |= _BV(0);
	if (PIN_HIGH(BTN_4WAY_UP))   	btn_4way_state |= _BV(1);
	if (PIN_HIGH(BTN_4WAY_RIGHT))	btn_4way_state |= _BV(2);
	if (PIN_HIGH(BTN_4WAY_DOWN))	btn_4way_state |= _BV(3);

	if (btn_4way_state != btn_4way_state_hist)
	{
		if (btn_4way_state == 0x08) _getch_queue(106); //j
		if (btn_4way_state == 0x02) _getch_queue(107); //k
		if (btn_4way_state == 0x04) _getch_queue(10); //enter
	}

	btn_4way_state_hist = btn_4way_state;
}

uint8_t btn_4way_get(void)
{
	return btn_4way_state;
}

void btn_4way_init(void)
{
	PIN_CLEAR(BTN_4WAY_LEFT);
	PIN_CLEAR(BTN_4WAY_UP);
	PIN_CLEAR(BTN_4WAY_RIGHT);
	PIN_CLEAR(BTN_4WAY_DOWN);
	DDR_CONFIG_IN(BTN_4WAY_LEFT);
	DDR_CONFIG_IN(BTN_4WAY_UP);
	DDR_CONFIG_IN(BTN_4WAY_RIGHT);
	DDR_CONFIG_IN(BTN_4WAY_DOWN);

	btn_4way_state = 0;
}


/*
  -- Ethersex META --
  header(hardware/btn_4way/btn_4way.h)
  init(btn_4way_init)
  mainloop(btn_4way_main)
*/
