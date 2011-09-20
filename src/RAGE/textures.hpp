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
 * @date    2011-09-16
 */

#ifndef TEXTURES_H
#define TEXTURES_H

#include <GL/gl.h>
#include <string>

const int MAX_FRAMES           = 64;
const int DEFAULT_FRAME_WIDTH  = 64;
const int DEFAULT_FRAME_HEIGHT = 64;

struct frame_type
{
    bool      active;
    GLuint    data;
};

class texture_class
{
    private:
    public:
        int             width;
        int             height;
        bool            rotate_able;
        float           rotate_speed;
        int             rotate_direction;
        float           angle;
        int             frame_delay;
        int             frame_delay_count;
        int             frame_num;
        int             frame_max;
        frame_type      frame[MAX_FRAMES];
        int             ref_number;

        texture_class();
       ~texture_class();
        bool     load_image      (std::string file_name, int index_number);
        bool     load_spritesheet(std::string file_name, int index_number);
        void     process(void);
        void     draw(float pos_x, float pos_y, float pos_z, float width, float height);
        void     draw(float pos_x, float pos_y, float pos_z, float width, float height, int   angle);
        void     draw(float pos_x, float pos_y, float pos_z, float width, float height, float angle);
        void     draw(float pos_x, float pos_y, float pos_z, float width, float height, float angle, float alpha);
        void     draw(float pos_x, float pos_y, float pos_z, float width, float height, float angle, float red, float green, float blue, float alpha);
};

#endif //TEXTURES_H
