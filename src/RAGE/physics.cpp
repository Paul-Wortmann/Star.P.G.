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


#include "physics.hpp"
#include <math.h>

bool  physics_class::cube_collision       (float x1, float y1, float z1, float w1, float h1, float d1, float x2, float y2, float z2, float w2, float h2, float d2)
{
if (((x1-(w1/2) < x2+(w2/2)) && (x2+(w2/2) > x1-(w1/2))) && ((x2-(w2/2) < x1+(w1/2)) && (x1+(w1/2) > x2-(w2/2)))
 && ((y1-(h1/2) < y2+(h2/2)) && (y2+(h2/2) > y1-(h1/2))) && ((y2-(h2/2) < y1+(h1/2)) && (y1+(h1/2) > y2-(h2/2)))
 && ((z1-(d1/2) < z2+(d2/2)) && (z2+(d2/2) > z1-(d1/2))) && ((z2-(d2/2) < z1+(d1/2)) && (z1+(d1/2) > z2-(d2/2)))) return(true);
else return(false);
}

bool physics_class::quadrangle_collision   (float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2)
{
if (((x1-(w1/2) < x2+(w2/2)) && (x2+(w2/2) > x1-(w1/2))) && ((x2-(w2/2) < x1+(w1/2)) && (x1+(w1/2) > x2-(w2/2)))
 && ((y1-(h1/2) < y2+(h2/2)) && (y2+(h2/2) > y1-(h1/2))) && ((y2-(h2/2) < y1+(h1/2)) && (y1+(h1/2) > y2-(h2/2)))) return(true);
else return(false);
}

bool physics_class::circle_collision(float x1, float y1, float r1, float x2, float y2, float r2)
{
   if (((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1)) < ((r1+r2)+(r1+r2))) return(true);
   else return(false);
}

bool physics_class::shere_collision(float x1, float y1, float z1, float r1, float x2, float y2, float z2, float r2)
{
   if ((((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1))+((z2-z1)*(z2-z1))) < ((r1+r2)+(r1+r2))) return(true);
   else return(false);
}

float physics_class::distance_2D(float x1, float y1, float x2, float y2)
{
   return(sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2))));
}

float physics_class::distance_3D(float x1, float y1, float z1, float x2, float y2, float z2)
{
   return(sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2))+((z1-z2)*(z1-z2))));
}

bool  physics_class::point_in_quadrangle  (float qx, float qw, float qy, float qh, float px, float py) //rectangle!
{
    if ((px > (qx-(qw/2))) && (px < (qx+(qw/2))) && (py > (qy-(qh/2))) && (py < (qy+(qh/2)))) return(true);
    else return(false);
};

bool  physics_class::point_in_diamond     (float dx, float dw, float dws, float dy, float dh, float dhs, float px, float py)
{
    float tx = 0.0f;
    float ty = 0.0f;
    if (px > dx) tx = (px-dx);
    if (px < dx) tx = (dx-px);
    if (py > dy) ty = (py-dy);
    if (py < dy) ty = (dy-py);
    if  ((px > (dx - (dw/(dws*2))+ty)) && (px < (dx + (dw/(dws*2))-ty)) &&
         (py > (dy - (dh/(dhs*2))+tx)) && (py < (dy + (dh/(dhs*2))-tx))) return(true);
    else return(false);
};

float physics_class::line_slope_2D(float x1, float y1, float x2, float y2)
{
    return((y2-y1)/(x2-x1));
};

float physics_class::line_angle(float x1, float y1, float x2, float y2)
{
    return(atan2(y2 - y1, x2 - x1));
};

float physics_class::line_point_2D_x(float x1, float distance, float angle)
{
    return(x1 + distance*cos(angle));
};

float physics_class::line_point_2D_y(float y1, float distance, float angle)
{
    return(y1 + distance*sin(angle));
};





