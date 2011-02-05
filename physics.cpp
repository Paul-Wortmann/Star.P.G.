/* Copyright (C) 2011 Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
 * This file is part of Star.P.G.
 *
 * Star.P.G. is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * Star.P.G. is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Star.P.G. If not, see <http://www.gnu.org/licenses/>.
 */

#include "physics.h"

bool box_collision   (float a_x, float a_y, float a_w, float a_h, float b_x, float b_y, float b_w, float b_h)
{
if (((a_x-(a_w/2) < b_x+(b_w/2)) && (b_x+(b_w/2) > a_x-(a_w/2))) && ((b_x-(b_w/2) < a_x+(a_w/2)) && (a_x+(a_w/2) > b_x-(b_w/2)))
 && ((a_y-(a_h/2) < b_y+(b_h/2)) && (b_y+(b_h/2) > a_y-(a_h/2))) && ((b_y-(b_h/2) < a_y+(a_h/2)) && (a_y+(a_h/2) > b_y-(b_h/2)))) return(true);
else return(false);
}

bool circle_collision(float a_x, float a_y, float a_r, float b_x, float b_y, float b_r)
{
   return(0);
};



