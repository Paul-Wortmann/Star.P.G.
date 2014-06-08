/**
 * Copyright (C) 2010-2012 Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
 * This file is part of Star.P.G.
 *
 * Star.P.G. is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Star.P.G. is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Star.P.G. If not, see <http://www.gnu.org/licenses/>.
 *
 * @author  Paul Wortmann
 * @email   physhex@gmail.com
 * @website www.physhexgames.co.nr
 * @license GPL
 * @date 2011-10-01
 */

#include "core.hpp"

game_class        game;

game_class::game_class(void)
{
    game_class::GAME_VERSION_MAJOR          = 1;
    game_class::GAME_VERSION_MINOR          = 2;
    game_class::game_paused                 = false;
    game_class::game_active                 = false;
    game_class::game_resume                 = false;
    game_class::menu_active                 = false;
    game_class::pdie_active                 = false;
    game_class::nlvl_active                 = false;
    game_class::outr_active                 = false;
    game_class::status_quit_active          = false;
    game_class::menu_level                  = 1;
    game_class::FPS                         = 0;
    game_class::LastTicks                   = 0;
    game_class::music_track                 = -1;
    game_class::process_ready               = true;
    game_class::music_next_track            = true;
    game_class::io.joystick_button_0        = false;
    game_class::io.joystick_button_1        = false;
    game_class::io.joystick_button_2        = false;
    game_class::io.joystick_button_3        = false;
    game_class::io.joystick_button_4        = false;
    game_class::io.joystick_button_5        = false;
    game_class::io.joystick_button_6        = false;
    game_class::io.joystick_button_7        = false;
    game_class::io.joystick_button_8        = false;
    game_class::io.joystick_button_9        = false;
    game_class::io.joystick_button_10       = false;
    game_class::io.joystick_button_11       = false;
    game_class::io.joystick_up              = false;
    game_class::io.joystick_down            = false;
    game_class::io.joystick_left            = false;
    game_class::io.joystick_right           = false;
    game_class::io.mouse_button_left        = false;
    game_class::io.mouse_button_middle      = false;
    game_class::io.mouse_button_right       = false;
    game_class::io.mouse_button_delay       = 0;
    game_class::io.mouse_button_delay_count = 0;
    game_class::io.mouse_x                  = 0.0f;
    game_class::io.mouse_y                  = 0.0f;
    game_class::io.mouse_xrel               = 0.0f;
    game_class::io.mouse_yrel               = 0.0f;
    game_class::io.joystick_sensitivity     = 0;
    game_class::io.keyboard_delay           = 0;
    game_class::io.keyboard_delay_count     = 0;
    game_class::io.joystick_delay           = 0;
    game_class::io.joystick_delay_count     = 0;
    game_class::io.key_0                    = false;
    game_class::io.key_1                    = false;
    game_class::io.key_2                    = false;
    game_class::io.key_3                    = false;
    game_class::io.key_4                    = false;
    game_class::io.key_5                    = false;
    game_class::io.key_6                    = false;
    game_class::io.key_7                    = false;
    game_class::io.key_8                    = false;
    game_class::io.key_9                    = false;
    game_class::io.key_a                    = false;
    game_class::io.key_b                    = false;
    game_class::io.key_c                    = false;
    game_class::io.key_d                    = false;
    game_class::io.key_e                    = false;
    game_class::io.key_f                    = false;
    game_class::io.key_g                    = false;
    game_class::io.key_h                    = false;
    game_class::io.key_i                    = false;
    game_class::io.key_j                    = false;
    game_class::io.key_k                    = false;
    game_class::io.key_l                    = false;
    game_class::io.key_m                    = false;
    game_class::io.key_n                    = false;
    game_class::io.key_o                    = false;
    game_class::io.key_p                    = false;
    game_class::io.key_q                    = false;
    game_class::io.key_r                    = false;
    game_class::io.key_s                    = false;
    game_class::io.key_t                    = false;
    game_class::io.key_u                    = false;
    game_class::io.key_v                    = false;
    game_class::io.key_w                    = false;
    game_class::io.key_x                    = false;
    game_class::io.key_y                    = false;
    game_class::io.key_z                    = false;
    game_class::io.key_up                   = false;
    game_class::io.key_down                 = false;
    game_class::io.key_left                 = false;
    game_class::io.key_right                = false;
    game_class::io.space                    = false;
    game_class::io.enter                    = false;
    game_class::io.plus                     = false;
    game_class::io.minus                    = false;
    game_class::io.shoot                    = false;
    game_class::io.select                   = false;
    game_class::io.escape                   = false;
    game_class::io.pause                    = false;
    game_class::io.up                       = false;
    game_class::io.down                     = false;
    game_class::io.left                     = false;
    game_class::io.right                    = false;
    game_class::network.enabled             = 0;
    game_class::network.port                = 0;
    game_class::network.server              = false;
    //game_class::emitter.
}

game_class::~game_class(void)
{

}
