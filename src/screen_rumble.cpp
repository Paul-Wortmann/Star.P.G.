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

#include "screen_rumble.hpp"

bool  rumble_class::init(void)
{
    rumble_class::active       = false;
    rumble_class::maximum      = 200;
    rumble_class::counter      = 0;
    rumble_class::direction_x  = 0;
    rumble_class::direction_y  = 0;
    rumble_class::counter_x    = 0.0f;
    rumble_class::counter_y    = 0.0f;
    rumble_class::max_x        = 0.035f;
    rumble_class::max_y        = 0.01f;
    rumble_class::speed_x      = 0.0155f;
    rumble_class::speed_y      = 0.01f;
};

bool  rumble_class::process(void)
{
    if(rumble_class::active)
    {
        rumble_class::counter++;
        if(rumble_class::counter > rumble_class::maximum)
        {
            rumble_class::counter = 0;
            rumble_class::active  = false;
        };
        if (rumble_class::direction_x  == 0)
        {
            rumble_class::counter_x   += rumble_class::speed_x;
            if(rumble_class::counter_x > rumble_class::max_x)
            {
                rumble_class::direction_x = 1;
            }
        }
        if (rumble_class::direction_x  == 1)
        {
            rumble_class::counter_x   -= rumble_class::speed_x;
            if(rumble_class::counter_x < (rumble_class::max_x*-1))
            {
                rumble_class::direction_x = 0;
            }
        }
        if (rumble_class::direction_y  == 0)
        {
            rumble_class::counter_y   += rumble_class::speed_y;
            if(rumble_class::counter_y > rumble_class::max_y)
            {
                rumble_class::direction_y = 1;
            }
        }
        if (rumble_class::direction_y  == 1)
        {
            rumble_class::counter_y   -= rumble_class::speed_y;
            if(rumble_class::counter_y < (rumble_class::max_y*-1))
            {
                rumble_class::direction_y = 0;
            }
        }
    }
};

bool  rumble_class::start(void)
{
    rumble_class::init();
    rumble_class::active  = true;
};

bool  rumble_class::start(float magnitude, int duration)
{
    rumble_class::init();
    rumble_class::active       = true;
    rumble_class::maximum      = duration;
    rumble_class::max_x        = magnitude;
    rumble_class::max_y        = magnitude/3;
    rumble_class::speed_x      = magnitude/2;
    rumble_class::speed_y      = magnitude/6;
};





