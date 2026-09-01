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

bool last_direction;

bool encoder_update_user(uint8_t index, bool clockwise) {

	/*static uint16_t key_timer;
	key_timer = timer_read();

	if (timer_elapsed(key_timer) < TAPPING_TERM && clockwise != last_direction) {
		set_dpi(PLOOPY_DPI_DEFAULT);
	} else {
		clockwise ? cycle_dpi(1) : cycle_dpi(-1);
	}
	
	last_direction = clockwise;*/

	clockwise ? set_dpi(PLOOPY_DPI_DEFAULT) : set_dpi(PLOOPY_DPI_SNIPE);

	return false;
}