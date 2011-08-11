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
 * @version 0.16
 */

#include "background.hpp"

void background_class::set_movement_type(int type_data)
{
    background_class::movemennt_type = type_data;
};

void background_class::set_data (int layer_number, int dx, int dy, int px, int py, float sr)
{
    background_class::layer[layer_number].dir_x       = dx;
    background_class::layer[layer_number].dir_y       = dy;
    background_class::layer[layer_number].pos_x       = px;
    background_class::layer[layer_number].pos_y       = py;
    background_class::layer[layer_number].scroll_rate = sr;
};

void background_class::set_image(int layer_number, int image_ref)
{
    background_class::layer[layer_number].image       = image_ref;
};

void background_class::draw(void)
{
    if (background_class::movemennt_type == BOUNCE)
    {
        for(int layer_count = 1; layer_count < MAX_LAYERS; layer_count++)
        {
            bind_texture(background_class::layer[layer_number].image);
            glLoadIdentity();
            glBegin( GL_QUADS );
	        glTexCoord2i( 0, 1 );glVertex3f(-2.0f + background_class::layer[layer_number].pos_x,-2.0f + background_class::layer[layer_number].pos_y, 0.15f );
	        glTexCoord2i( 0, 0 );glVertex3f(-2.0f + background_class::layer[layer_number].pos_x, 2.0f + background_class::layer[layer_number].pos_y, 0.15f );
	        glTexCoord2i( 1, 0 );glVertex3f( 2.0f + background_class::layer[layer_number].pos_x, 2.0f + background_class::layer[layer_number].pos_y, 0.15f );
	        glTexCoord2i( 1, 1 );glVertex3f( 2.0f + background_class::layer[layer_number].pos_x,-2.0f + background_class::layer[layer_number].pos_y, 0.15f );
            glEnd();
        }
    }
};

void background_class::process(void)
{
    if (background_class::movemennt_type == BOUNCE)
    {
        for(int layer_count = 1; layer_count < MAX_LAYERS; layer_count++)
        {
            if(background_class::layer[layer_count].dir_x == 0)
            {
                background_class::layer[layer_count].pos_x -= background_class::layer[layer_count].scroll_rate;
                if (background_class::layer[layer_count].pos_x < 0.0f) background_class::layer[layer_count].dir_x = 1;
            }
            if (background_class::layer[layer_count].dir_x == 1)
            {
                background_class::layer[layer_count].pos_x += background_class::layer[layer_count].scroll_rate;
                if (background_class::layer[layer_count].pos_x > 1.0f) background_class::layer[layer_count].dir_x = 0;
            }
            if(background_class::layer[layer_count].dir_y == 0)
            {
                background_class::layer[layer_count].pos_y -= background_class::layer[layer_count].scroll_rate;
                if (background_class::layer[layer_count].pos_y < 0.0f) background_class::layer[layer_count].dir_y = 1;
            }
            if (background_class::layer[layer_count].dir_y == 1)
            {
                background_class::layer[layer_count].pos_y += background_class::layer[layer_count].scroll_rate;
                if (background_class::layer[layer_count].pos_y > 1.0f) background_class::layer[layer_count].dir_y = 0;
            }
        }
    };
};


        void set_active(int layer_number,bool bool_data);
        bool get_active(int layer_number);


