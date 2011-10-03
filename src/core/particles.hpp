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
 * @date 2011-10-01
 */

#ifndef PARTICLES_H
#define PARTICLES_H

const int   MAX_PARTICLES        = 128;
const int   MAX_EMITTERS         = 16;

class particle_class
{
    public:
        bool  active;
        int   image_reference;
        float pos_x;
        float pos_y;
        float pos_z;
        float velocity;
        float acceleration;
        float direction;
        float color;
        float color_start;
        float color_stop;
        float TTL;
        float TTL_rate;
};

class emitter_class
{
    public:
        bool  active;
        float TTL;
        float TTL_count;
};

#endif //PARTICLES_H









