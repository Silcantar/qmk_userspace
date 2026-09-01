/* Copyright 2025 Joshua Lucas
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
 
 #define PLOOPY_DPI_SNIPE 0

#define CONFIG_DBLCLK LT(_CONFIG, KC_0)

#define HT_DRAG_SCROLL LT(0, KC_0)
#define HT_SNIPE LT(0, KC_1)

enum layers {
	_DEFAULT = 0,
	_CONFIG,
};

enum custom_keycodes {
	PRINT_DPI = SAFE_RANGE,
	SCROLL_CONFIG,
	DOUBLE_CLICK,
	HSCROLL_TOGGLE,
};