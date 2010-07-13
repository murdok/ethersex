/*
 *
 * Copyright (c) by Alexander Neumann <alexander@bumpern.de>
 * Copyright (c) 2007 by Stefan Siegl <stesie@brokenpipe.de>
 * Copyright (c) 2007 by Christian Dietrich <stettberger@dokucode.de>
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

#include <string.h>
#include <avr/pgmspace.h>

#include "config.h"
#include "core/bit-macros.h"
#include "core/debug.h"
#include "hardware/btn_4way/btn_4way.h"

#include "protocols/ecmd/ecmd-base.h"


int16_t parse_cmd_btn_4way_init(char *cmd, char *output, uint16_t len)
{
	btn_4way_init();

	return ECMD_FINAL_OK;
}

int16_t parse_cmd_btn_4way_get(char *cmd, char *output, uint16_t len)
{
	uint8_t btn_4way_state = btn_4way_get();

	return ECMD_FINAL(snprintf_P(output, len, PSTR("%u"), btn_4way_state));
}


/*
  -- Ethersex META --
  block(BTN_4WAY)
  ecmd_feature(btn_4way_init, "4way reinit",, re init btn 4way module)
  ecmd_feature(btn_4way_get, "4way state",, get current 4way state)
*/
