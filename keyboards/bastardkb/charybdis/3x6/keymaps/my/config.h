/**
 * Copyright 2022 Charly Delay <charly@codesink.dev> (@0xcharly)
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
#pragma once

#ifdef VIA_ENABLE
/* VIA configuration. */
#    define DYNAMIC_KEYMAP_LAYER_COUNT 4
#endif // VIA_ENABLE

#ifndef __arm__
/* Disable unused features. */
#    define NO_ACTION_ONESHOT
#endif // __arm__

/* Charybdis-specific features. */

#ifdef POINTING_DEVICE_ENABLE
#    define POINTING_DEVICE_AUTO_MOUSE_ENABLE
#    define AUTO_MOUSE_TIME 300

#    define CHARYBDIS_MINIMUM_DEFAULT_DPI 1200
#    define CHARYBDIS_MINIMUM_SNIPING_DPI 400
#    define CHARYBDIS_DRAGSCROLL_DPI 100
#    define CHARYBDIS_DRAGSCROLL_REVERSE_Y
#    define ROTATIONAL_TRANSFORM_ANGLE -35
#endif // POINTING_DEVICE_ENABLE

#define TAPPING_TERM 200
#define HOLD_ON_OTHER_KEY_PRESS

#define SPLIT_LAYER_STATE_ENABLE
