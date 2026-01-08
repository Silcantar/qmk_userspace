/* Copyright 2025 Joshua Lucas
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 * Copyright 2019 Sunjun Kim
 * Copyright 2020 Ploopy Corporation
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#include "01_alias.c"

#include "02_macros.c"

#include "03_tapdance.c"

#include "04_encoder.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DEFAULT] = LAYOUT(
/*		
 * Layer 0: Default Layer
 *		,-------------------,-------------------,-------------------,-------------------,-------------------.
 *		|					|					|					|					|					|
 *		|		Mouse		|	 MO Layer 1		|   MO Drag Scroll  |		Mouse		|		Mouse		|
 *		|	   Button 1		|	Double Click	|   TG Drag Scroll  |	   Button 2		|	   Button 3		|
 *		|					|					|				    |					|					|
 *		`-------------------'-------------------'-------------------'-------------------'-------------------'
 */
		  KC_BTN1			, CONFIG_DBLCLK		, TD(TD_DRAG_SCROLL), KC_BTN2			, KC_BTN3
	),

	[_CONFIG] = LAYOUT(
/*		
 * Layer 1: Configuration
 *		,-------------------,-------------------,-------------------,-------------------,-------------------.
 *		|					|					|					|					|					|
 *		|		Trans		|		Trans		|		Print		|	  Cycle	Drag	|	  Bootloader	|
 *		|					|					|		 DPI		|		Scroll		|					|
 *		|					|					|					|					|					|
 *		`-------------------'-------------------'-------------------'-------------------'-------------------'
 */
		  KC_TRNS			, KC_TRNS			, PRINT_DPI			, SCROLL_CONFIG		, QK_BOOT
	)
};
