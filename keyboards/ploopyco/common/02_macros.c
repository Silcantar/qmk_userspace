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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case CONFIG_DBLCLK: {
			if (record->event.pressed && record->tap.count) {
				tap_code16(MS_BTN1);
				tap_code16(MS_BTN1);
				return false;
			}
			break;
		}
		case PRINT_DPI: {
			if (record->event.pressed) {
				int cpiInt = pointing_device_get_cpi();
				int length = snprintf(NULL, 0, "%d", cpiInt);
				char* cpiStr = malloc(length + 1);
				snprintf(cpiStr, length + 1, "%d", cpiInt);
				SEND_STRING(cpiStr);
				free(cpiStr);
				return false;
			}
			break;
		}
		case SCROLL_CONFIG: {
			cycle_dragscroll(1);
			return false;
			break;
		}
		case DOUBLE_CLICK: {
			if (record->event.pressed) {
				tap_code16(MS_BTN1);
				tap_code16(MS_BTN1);
				return false;
			}
			break;
		}
		case HSCROLL_TOGGLE: {
			hscroll_toggle();
			return false;
			break;
		}
		case HT_DRAG_SCROLL: {
			if (record->event.pressed && record->tap.count) {
				toggle_drag_scroll();
				return false;
			} else if (record->event.pressed) {
				is_drag_scroll = true;
				return false;
			} else {
				is_drag_scroll = false;
				return false;
			}
			break;
		}
		case HT_SNIPE: {
			if (record->event.pressed && record->tap.count) {
				cycle_dpi(1);
				return false;
			} else if (record->event.pressed) {
				pointing_device_set_cpi(dpi_array[PLOOPY_DPI_SNIPE]);
				return false;
			} else {
				pointing_device_set_cpi(dpi_array[PLOOPY_DPI_DEFAULT]);
				return false;
			}
			break;
		}
		
	}
	return true;
}