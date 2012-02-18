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

#ifndef POWERUPS_H
#define POWERUPS_H

const int   MAX_POWERUPS       = 13;
const int   MAX_COINS          = 32;
const int   MAX_WEXPS          = 32;
const int   MAX_BOMBS          = 5;

struct powerup_type
{
   bool  active;
   int   image;
   int   sound;
   float x_pos;
   float y_pos;
   float width;
   float height;
   float speed;
   int   spawn_rate;
};

struct coin_type
{
   bool  active;
   int   value;
   int   image;
   int   sound;
   float x_pos;
   float y_pos;
   float width;
   float height;
   float speed;
};

struct wexp_type
{
   bool  active;
   int   value;
   int   image;
   int   sound;
   float x_pos;
   float y_pos;
   float width;
   float height;
   float speed;
};

int  spawn_powerup(float x_position, float y_position, int type_powerup);
int  kill_powerup(int type_powerup);
int  kill_powerups(void);
int  init_powerups(void);
int  proccess_powerups(void);
int  use_bomb_powerup(void);

int  spawn_coin(float x_position, float y_position, int coin_value);
int  kill_coin(int coin_num);
int  kill_coins(void);
int  init_coin(void);
int  proccess_coin(void);

int  spawn_wexp(float x_position, float y_position, int wexp_value);
int  kill_wexp(int wexp_num);
int  kill_wexps(void);
int  init_wexp(void);
int  proccess_wexp(void);

#endif //POWERUPS_H
