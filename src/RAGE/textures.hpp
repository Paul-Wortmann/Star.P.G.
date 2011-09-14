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

#ifndef TEXTURES_H
#define TEXTURES_H

#include <GL/gl.h>
#include <string>

const int MAX_FRAMES = 8;

class texture_class
{
    private:
    public:
        bool      rotate_able;
        float     rotate_speed;
        int       rotate_direction;
        float     angle;
        int       frame;
        int       frame_max;
        GLuint    data[MAX_FRAMES];

        int       ref_number;
        GLuint    texture_data;
        texture_class();
       ~texture_class();
        bool     load(std::string file_name);
        bool     load(std::string file_name, int index_number);
        void     process(void);
        void     draw(float pos_x, float pos_y, float pos_z, float width, float height);
};

#endif //TEXTURES_H
