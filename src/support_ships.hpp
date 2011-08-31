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

#ifndef SUPPORT_SHIPS_H
#define SUPPORT_SHIPS_H

#include "bullets.hpp"

const int   MAX_SUPPORTSHIPS   = 5;

class supportship_class
{
    public:
    int         rate_of_fire;
    int         rate_of_fire_count;
    bool        active;
    int         level;
    int         image;
    float       width;
    float       height;
    bullet_type bullet[MAX_BULLETS];

    void        init        (int  supportship_count);
    void        process     (bool spawn_bullet);
    void        kill_bullets(void);
    int         spawn_bullet(int  location, int direction_x, int direction_y);
};

void  process_supportships    (bool spawn_bullet);
void  init_supportships (void);
void  kill_supportship_bullets(void);

#endif //SUPPORT_SHIPS_H