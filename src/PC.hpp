/**
 * Copyright (C) 2011 Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
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
 * @date 2011-08-30
 */

#ifndef PC_H
#define PC_H

#include "bullets.hpp"

const int   MAX_PLAYERS     = 2;

struct player_class
{
    public:
    int            front_weapon;
    int            side_weapon;
    int            front_shield;
    int            thrusters;
    float          x_pos;
    float          y_pos;
    float          x_dir;
    float          y_dir;
    float          x_vel;
    float          y_vel;
    float          width;
    float          hight;
    float          health;
    float          health_regen_rate;
    float          max_health;
    int            image;
    bullet_type    bullet[MAX_BULLETS];
};

int   init_player            (void);
float thruster_offset        (void);
int   process_player         (int command);

int  spawn_player_bullet_num (int player_bullet_num, int location);
int  spawn_player_bullet     (int position);
int  kill_player_bullet      (void);
int  kill_player_bullet      (int player_bullet_num);
void init_player_bullets     (void);
int  proccess_player_bullets (void);

#endif //PC_H
