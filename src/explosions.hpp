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

#ifndef EXPLOSIONS_H
#define EXPLOSIONS_H

const int   MAX_EXPLOSIONS     = 32;

struct explosion_class
{
    public:
    bool  active;
    int   image;
    int   frame;
    int   frame_max;
    float frame_delay;
    float frame_delay_count;
    float frame_delay_max;
    int   sound;
    float x_pos;
    float y_pos;
    float width;
    float height;
    float size;
};

int  spawn_explosion    (float x_position, float y_position, float size);
int  kill_explosion     (int explosion_num);
int  init_explosions    (void);
int  proccess_explosions(void);

#endif //EXPLOSIONS_H
