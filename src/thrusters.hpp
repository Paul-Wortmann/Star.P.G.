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

#ifndef THRUSTERS_H
#define THRUSTERS_H

#include "core/core.hpp"
#include <string>

const int   MAX_THRUSTERS      = 4;

class thruster_class
{
    public:
    std::string   name;
    bool          active;
    int           level;
    float         level_1;
    float         level_2;
    float         level_3;
    float         experience;
    int           image;
    float         thrust;
    int           frame;
    int           frame_max;
    emitter_class fire;
    emitter_class smoke;
};

void init_thrusters(bool re_init);
void proc_thrusters(void);
void draw_thrusters(void);

#endif //THRUSTERS_H
