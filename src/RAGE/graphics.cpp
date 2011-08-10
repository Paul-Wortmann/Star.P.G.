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
 * @author Paul Wortmann
 * @license GPL
 */

#include <GL/gl.h>
#include "rage.hpp"
#include "graphics.hpp"

graphics_class::graphics_class(void)
{
    graphics_class::resolution_x = 0;
    graphics_class::resolution_y = 0;
};

void  graphics_class::set_resolution(int x_res, int y_res)
{
    graphics_class::resolution_x = x_res;
    graphics_class::resolution_y = y_res;
};

int   graphics_class::get_resolution_x(void)
{
    return(graphics_class::resolution_x);
};

int   graphics_class::get_resolution_y(void)
{
    return(graphics_class::resolution_y);
};

int   graphics_class::gl_to_res(float gl_coord, int max_res)
{
   return((gl_coord+1)*(max_res / 2));
}

float graphics_class::res_to_gl(int  res_coord, int max_res)
{
   return((((float) res_coord / (float) max_res) *2) -1);
}

int   graphics_class::init_gl(int x_res, int y_res)
{
  glViewport(0, 0,x_res,y_res);
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  glClearDepth(1.0);
  glDepthFunc(GL_LESS);
  glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
  glEnable(GL_BLEND);
  glEnable(GL_DEPTH_TEST);
  glShadeModel(GL_SMOOTH);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glEnable(GL_TEXTURE_2D);
  return(0);
}
