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
        float pos_x;
        float pos_y;
        float pos_z;
        float velocity_x;
        float velocity_y;
        float velocity_z;
        float velocity_max;
        float acceleration_x;
        float acceleration_y;
        float acceleration_z;
        float direction; //2D
        float force_x;
        float force_y;
        float force_z;
        float color_r;
        float color_g;
        float color_b;
        float TTL;
        float TTL_rate;
        void  init(void);
        void  process(void);
};

class emitter_class
{
    public:
        particle_class  particle[MAX_PARTICLES];
        bool            active;
        bool            always_on;
        int             image_reference;
        float           width;
        float           height;
        float           pos_x;
        float           pos_y;
        float           pos_z;
        float           velocity_max;
        float           acceleration_x;
        float           acceleration_y;
        float           acceleration_z;
        float           direction;
        float           force_x;
        float           force_y;
        float           force_z;
        float           color_start_r;
        float           color_start_g;
        float           color_start_b;
        float           color_stop_r;
        float           color_stop_g;
        float           color_stop_b;
        int             spawn_frequency;
        int             spawn_frequency_count;
        int             TTL;
        int             TTL_count;
        float           particle_TTL_rate;
        void            init(void);
        void            process(void);
        void            draw(void);
};

#endif //PARTICLES_H









