/**
 * Copyright (C) 2011 Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
 * This file is part of "Outcast Island!"
 *
 * "Outcast Island!" is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * "Outcast Island!" is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with "Outcast Island!" If not, see <http://www.gnu.org/licenses/>.
 *
 * @author Paul Wortmann
 * @license GPL
 */
#ifndef IO_H
#define IO_H

struct io_type
{
   bool      joystick_button_0;
   bool      joystick_button_1;
   bool      joystick_button_2;
   bool      joystick_button_3;
   bool      joystick_button_4;
   bool      joystick_button_5;
   bool      joystick_button_6;
   bool      joystick_button_7;
   bool      joystick_button_8;
   bool      joystick_button_9;
   bool      joystick_button_10;
   bool      joystick_button_11;
   bool      joystick_up;
   bool      joystick_down;
   bool      joystick_left;
   bool      joystick_right;
   bool      mouse_button_left;
   bool      mouse_button_middle;
   bool      mouse_button_right;
   int       mouse_button_delay;
   int       mouse_button_delay_count;
   float     mouse_x;
   float     mouse_y;
   float     mouse_xrel;
   float     mouse_yrel;
   int       joystick_sensitivity;
   int       keyboard_delay;
   int       keyboard_delay_count;
   int       joystick_delay;
   int       joystick_delay_count;
   bool      key_0;
   bool      key_1;
   bool      key_2;
   bool      key_3;
   bool      key_4;
   bool      key_5;
   bool      key_6;
   bool      key_7;
   bool      key_8;
   bool      key_9;
   bool      key_a;
   bool      key_b;
   bool      key_c;
   bool      key_d;
   bool      key_e;
   bool      key_f;
   bool      key_g;
   bool      key_h;
   bool      key_i;
   bool      key_j;
   bool      key_k;
   bool      key_l;
   bool      key_m;
   bool      key_n;
   bool      key_o;
   bool      key_p;
   bool      key_q;
   bool      key_r;
   bool      key_s;
   bool      key_t;
   bool      key_u;
   bool      key_v;
   bool      key_w;
   bool      key_x;
   bool      key_y;
   bool      key_z;
   bool      key_up;
   bool      key_down;
   bool      key_left;
   bool      key_right;
   bool      space;
   bool      enter;
   bool      plus;
   bool      minus;
   bool      shoot;
   bool      select;
   bool      escape;
   bool      pause;
   bool      up;
   bool      down;
   bool      left;
   bool      right;
};

bool events_init(void);
bool events_process(void);


#endif //IO_H

