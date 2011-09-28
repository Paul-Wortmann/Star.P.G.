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

#ifndef SCREEN_RUMBLE_H
#define SCREEN_RUMBLE_H

struct rumble_class
{
    public:
        bool  active;
        int   maximum;
        int   counter;
        int   direction_x;
        int   direction_y;
        float counter_x;
        float counter_y;
        float max_x;
        float max_y;
        float speed_x;
        float speed_y;
        bool  init(void);
        bool  process(void);
        bool  start(void);
        bool  start(float magnitude, int duration);
};

#endif //SCREEN_RUMBLE_H
