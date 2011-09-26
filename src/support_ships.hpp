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
 * @date 2011-09-03
 */

#ifndef SUPPORT_SHIPS_H
#define SUPPORT_SHIPS_H

#include "bullets.hpp"

const int   MAX_SUPPORTSHIPS         = 6;
const int   MAX_SUPPORTSHIP_LEVELS   = 6;

struct supportship_pos_type
{
    bool  active;
    float angle;
    float pos_x;
    float pos_y;
};

class supportship_class
{
    public:
        supportship_pos_type supportship_pos[MAX_SUPPORTSHIP_LEVELS];
        bool                 rotate_follow;
        bool                 side_follow;
        bool                 multi_follow;
        bool                 follow;
        float                follow_distance;
        float                movement_speed;
        int                  number_of_ships;
        int                  rate_of_fire;
        int                  rate_of_fire_count;
        bool                 active;
        int                  level;
        int                  image;
        float                width;
        float                height;
        bullet_type          bullet[MAX_BULLETS];

        void        init        (int  supportship_count, int number_of_ships, float x_pos, float y_pos);
        void        process     (bool spawn_bullet);
        void        kill_bullets(void);
        int         spawn_bullet(int  location, int direction_x, int direction_y);
};

void  init_supportships       (int number_of_ships, float x_pos, float y_pos);
void  process_supportships    (bool spawn_bullet);
void  kill_supportship_bullets(void);
void  draw_supportships       (void);
void  pos_supportships        (float x_pos, float y_pos);

#endif //SUPPORT_SHIPS_H
