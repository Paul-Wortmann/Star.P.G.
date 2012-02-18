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

#ifndef GRAPHICS_H
#define GRAPHICS_H

class graphics_class
{
    private:
        int resolution_x;
        int resolution_y;
    public:
              graphics_class(void);
        void  set_resolution(int x_res, int y_res);
        int   get_resolution_x(void);
        int   get_resolution_y(void);
        int   gl_to_res(float gl_coord, int max_res);
        float res_to_gl(int  res_coord, int max_res);
        int   init_gl(int x_res, int y_res);
};

#endif //GRAPHICS_H
