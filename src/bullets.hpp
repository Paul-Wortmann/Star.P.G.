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

#ifndef BULLETS_H
#define BULLETS_H

const int   MAX_BULLETS        = 128;

struct bullet_type
{
    int           warhead; //projectile
    bool          active;
    int           location;
    float         x_pos;
    float         y_pos;
    int           x_dir;
    int           y_dir;
    float         x_speed;
    float         y_speed;
    float         max_speed;
    float         acceleration;
    float         angle;
    float         width;
    float         height;
    bool          straight;
    bool          homeing_00;
    bool          homeing_01;
    bool          wave;
    float         wave_height;
    float         wave_count;
    float         wave_speed;
    bool          wave_direction;
};

#endif //BULLETS_H
