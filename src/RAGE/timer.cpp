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


#include "SDL/SDL.h"
#include "timer.hpp"

timer_class::timer_class()
{
	running = false;
	startticks = 0;
}

timer_class::~timer_class()
{
}

int timer_class::start()
{
	if(running == false)
	{
		running = true;
		startticks = SDL_GetTicks();
	}
	return 0;
}
int timer_class::stop()
{
	if(running == true)
	{
		running = false;
	}
	return 0;
}

int timer_class::getticks()
{
    if (running == true) return SDL_GetTicks() - startticks;
    else return 0;
}

