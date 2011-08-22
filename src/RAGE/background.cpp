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

#include "rage.hpp"
#include "../load_resources.hpp"
#include "background.hpp"

background_class::background_class       (void)
{
    for(int layer_count = 1; layer_count < MAX_LAYERS+1; layer_count++)
    {
        background_class::layer[layer_count].active      = false;
    }
};

void background_class::set_movement_type (int type_data)
{
    background_class::movemennt_type = type_data;
};

int   background_class::get_movement_type (void)
{
    return(background_class::movemennt_type);
};

void background_class::set_data          (int layer_number, int dx, int dy, int px, int py, float srx, float sry, int image_ref)
{
    background_class::layer[layer_number].active        = true;
    background_class::layer[layer_number].dir_x         = dx;
    background_class::layer[layer_number].dir_y         = dy;
    background_class::layer[layer_number].pos_x         = px;
    background_class::layer[layer_number].pos_y         = py;
    background_class::layer[layer_number].scroll_rate_x = srx;
    background_class::layer[layer_number].scroll_rate_y = sry;
    background_class::layer[layer_number].image         = image_ref;
};

void background_class::set_image         (int layer_number, int image_ref)
{
    background_class::layer[layer_number].image       = image_ref;
};

void background_class::set_active        (int layer_number,bool bool_data)
{
    background_class::layer[layer_number].active = bool_data;
};

bool background_class::get_active        (int layer_number)
{
    return(background_class::layer[layer_number].active);
};

float background_class::get_scroll_x     (int layer_number)
{
    return(background_class::layer[layer_number].scroll_rate_x);
};

float background_class::get_scroll_y     (int layer_number)
{
    return(background_class::layer[layer_number].scroll_rate_y);
};

bool  background_class::scroll_up        (void)
{
    bool return_value = false;
    for(int layer_count = 1; layer_count < MAX_LAYERS+1; layer_count++)
    {
        background_class::layer[layer_count].pos_y -= background_class::layer[layer_count].scroll_rate_y;
        if (background_class::layer[layer_count].pos_y < -1.0f) background_class::layer[layer_count].pos_y = -1.0f;
        else return_value = true;
    }
    return(return_value);
};

bool  background_class::scroll_down      (void)
{
    bool return_value = false;
    for(int layer_count = 1; layer_count < MAX_LAYERS+1; layer_count++)
    {
        background_class::layer[layer_count].pos_y += background_class::layer[layer_count].scroll_rate_y;
        if (background_class::layer[layer_count].pos_y > 1.0f) background_class::layer[layer_count].pos_y = 1.0f;
        else return_value = true;
    }
    return(return_value);
};


void background_class::process           (void)
{
    if (background_class::get_movement_type() == BOUNCE)
    {
        for(int layer_count = 1; layer_count < MAX_LAYERS+1; layer_count++)
        {
            if(background_class::layer[layer_count].dir_x == 0)
            {
                background_class::layer[layer_count].pos_x -= background_class::layer[layer_count].scroll_rate_x;
                if (background_class::layer[layer_count].pos_x < 0.0f) background_class::layer[layer_count].dir_x = 1;
            }
            if (background_class::layer[layer_count].dir_x == 1)
            {
                background_class::layer[layer_count].pos_x += background_class::layer[layer_count].scroll_rate_x;
                if (background_class::layer[layer_count].pos_x > 1.0f) background_class::layer[layer_count].dir_x = 0;
            }
            if(background_class::layer[layer_count].dir_y == 0)
            {
                background_class::layer[layer_count].pos_y -= background_class::layer[layer_count].scroll_rate_y;
                if (background_class::layer[layer_count].pos_y < 0.0f) background_class::layer[layer_count].dir_y = 1;
            }
            if (background_class::layer[layer_count].dir_y == 1)
            {
                background_class::layer[layer_count].pos_y += background_class::layer[layer_count].scroll_rate_y;
                if (background_class::layer[layer_count].pos_y > 1.0f) background_class::layer[layer_count].dir_y = 0;
            }
        }
    };
    if (background_class::get_movement_type() == SCROLL)
    {
        for(int layer_count = 1; layer_count < MAX_LAYERS+1; layer_count++)
        {
            background_class::layer[layer_count].pos_x -= background_class::layer[layer_count].scroll_rate_x;
            if (background_class::layer[layer_count].pos_x <= -4.0f) background_class::layer[layer_count].pos_x = 4.0f;
        }
    }
};

void background_class::draw             (void)
{
    float z_pos = 0.15f;
    if (background_class::get_movement_type() == BOUNCE)
    {
        for(int layer_count = 1; layer_count < MAX_LAYERS; layer_count++)
        {
            if(background_class::layer[layer_count].active)
            {
                bind_texture(background_class::layer[layer_count].image);
                glLoadIdentity();
                glBegin( GL_QUADS );
	            glTexCoord2i( 0, 1 );glVertex3f(-2.0f + background_class::layer[layer_count].pos_x,-2.0f + background_class::layer[layer_count].pos_y, z_pos );
    	        glTexCoord2i( 0, 0 );glVertex3f(-2.0f + background_class::layer[layer_count].pos_x, 2.0f + background_class::layer[layer_count].pos_y, z_pos );
	            glTexCoord2i( 1, 0 );glVertex3f( 2.0f + background_class::layer[layer_count].pos_x, 2.0f + background_class::layer[layer_count].pos_y, z_pos );
	            glTexCoord2i( 1, 1 );glVertex3f( 2.0f + background_class::layer[layer_count].pos_x,-2.0f + background_class::layer[layer_count].pos_y, z_pos );
                glEnd();
            }
        }
    }
    if (background_class::get_movement_type() == SCROLL)
    {
        //---------------------------------- display backgrounds ---------------------------------------------------------------------
        if (background_class::layer[4].pos_x >= background_class::layer[3].pos_x)
        {
            z_pos = 0.16f;
            bind_texture(background_class::layer[4].image);
            glLoadIdentity();
            glBegin( GL_QUADS );
            glTexCoord2i( 0, 1 );glVertex3f( 2.000f + background_class::layer[3].pos_x,-2.000f + background_class::layer[4].pos_y,z_pos);
            glTexCoord2i( 0, 0 );glVertex3f( 2.000f + background_class::layer[3].pos_x, 2.000f + background_class::layer[4].pos_y,z_pos);
            glTexCoord2i( 1, 0 );glVertex3f( 2.000f + background_class::layer[4].pos_x, 2.000f + background_class::layer[4].pos_y,z_pos);
            glTexCoord2i( 1, 1 );glVertex3f( 2.000f + background_class::layer[4].pos_x,-2.000f + background_class::layer[4].pos_y,z_pos);
            glEnd();
        }
        else
        {
            z_pos = 0.16f;
            bind_texture(background_class::layer[4].image);
            glLoadIdentity();
            glBegin( GL_QUADS );
            glTexCoord2i( 0, 1 );glVertex3f(-2.000f + background_class::layer[4].pos_x,-2.000f + background_class::layer[4].pos_y,z_pos);
            glTexCoord2i( 0, 0 );glVertex3f(-2.000f + background_class::layer[4].pos_x, 2.000f + background_class::layer[4].pos_y,z_pos);
            glTexCoord2i( 1, 0 );glVertex3f(-2.000f + background_class::layer[3].pos_x, 2.000f + background_class::layer[4].pos_y,z_pos);
            glTexCoord2i( 1, 1 );glVertex3f(-2.000f + background_class::layer[3].pos_x,-2.000f + background_class::layer[4].pos_y,z_pos);
            glEnd();
        }
        if (background_class::layer[3].pos_x >= background_class::layer[4].pos_x)
        {
            z_pos = 0.16f;
            bind_texture(background_class::layer[3].image);
            glLoadIdentity();
            glBegin( GL_QUADS );
            glTexCoord2i( 0, 1 );glVertex3f( 2.000f + background_class::layer[4].pos_x,-2.000f + background_class::layer[3].pos_y,z_pos);
            glTexCoord2i( 0, 0 );glVertex3f( 2.000f + background_class::layer[4].pos_x, 2.000f + background_class::layer[3].pos_y,z_pos);
            glTexCoord2i( 1, 0 );glVertex3f( 2.000f + background_class::layer[3].pos_x, 2.000f + background_class::layer[3].pos_y,z_pos);
            glTexCoord2i( 1, 1 );glVertex3f( 2.000f + background_class::layer[3].pos_x,-2.000f + background_class::layer[3].pos_y,z_pos);
            glEnd();
        }
        else
        {
            z_pos = 0.16f;
            bind_texture(background_class::layer[3].image);
            glLoadIdentity();
            glBegin( GL_QUADS );
            glTexCoord2i( 0, 1 );glVertex3f(-2.000f + background_class::layer[3].pos_x,-2.000f + background_class::layer[3].pos_y,z_pos);
            glTexCoord2i( 0, 0 );glVertex3f(-2.000f + background_class::layer[3].pos_x, 2.000f + background_class::layer[3].pos_y,z_pos);
            glTexCoord2i( 1, 0 );glVertex3f(-2.000f + background_class::layer[4].pos_x, 2.000f + background_class::layer[3].pos_y,z_pos);
            glTexCoord2i( 1, 1 );glVertex3f(-2.000f + background_class::layer[4].pos_x,-2.000f + background_class::layer[3].pos_y,z_pos);
            glEnd();
        }
        //------------------------------------------- display effects layer ------------------------------------------------------
        if (background_class::layer[2].pos_x >= background_class::layer[1].pos_x)
        {
            z_pos = 0.15f;
            bind_texture(background_class::layer[2].image);
            glLoadIdentity();
            glBegin( GL_QUADS );
            glTexCoord2i( 0, 1 );glVertex3f( 2.000f + background_class::layer[1].pos_x,-2.000f + background_class::layer[2].pos_y,z_pos);
            glTexCoord2i( 0, 0 );glVertex3f( 2.000f + background_class::layer[1].pos_x, 2.000f + background_class::layer[2].pos_y,z_pos);
            glTexCoord2i( 1, 0 );glVertex3f( 2.000f + background_class::layer[2].pos_x, 2.000f + background_class::layer[2].pos_y,z_pos);
            glTexCoord2i( 1, 1 );glVertex3f( 2.000f + background_class::layer[2].pos_x,-2.000f + background_class::layer[2].pos_y,z_pos);
            glEnd();
        }
        else
        {
            z_pos = 0.15f;
            bind_texture(background_class::layer[2].image);
            glLoadIdentity();
            glBegin( GL_QUADS );
            glTexCoord2i( 0, 1 );glVertex3f(-2.000f + background_class::layer[2].pos_x,-2.000f + background_class::layer[2].pos_y,z_pos);
            glTexCoord2i( 0, 0 );glVertex3f(-2.000f + background_class::layer[2].pos_x, 2.000f + background_class::layer[2].pos_y,z_pos);
            glTexCoord2i( 1, 0 );glVertex3f(-2.000f + background_class::layer[1].pos_x, 2.000f + background_class::layer[2].pos_y,z_pos);
            glTexCoord2i( 1, 1 );glVertex3f(-2.000f + background_class::layer[1].pos_x,-2.000f + background_class::layer[2].pos_y,z_pos);
            glEnd();
        }
        if (background_class::layer[1].pos_x >= background_class::layer[2].pos_x)
        {
            z_pos = 0.15f;
            bind_texture(background_class::layer[1].image);
            glLoadIdentity();
            glBegin( GL_QUADS );
            glTexCoord2i( 0, 1 );glVertex3f( 2.000f + background_class::layer[2].pos_x,-2.000f + background_class::layer[1].pos_y,z_pos);
            glTexCoord2i( 0, 0 );glVertex3f( 2.000f + background_class::layer[2].pos_x, 2.000f + background_class::layer[1].pos_y,z_pos);
            glTexCoord2i( 1, 0 );glVertex3f( 2.000f + background_class::layer[1].pos_x, 2.000f + background_class::layer[1].pos_y,z_pos);
            glTexCoord2i( 1, 1 );glVertex3f( 2.000f + background_class::layer[1].pos_x,-2.000f + background_class::layer[1].pos_y,z_pos);
            glEnd();
        }
        else
        {
            z_pos = 0.15f;
            bind_texture(background_class::layer[1].image);
            glLoadIdentity();
            glBegin( GL_QUADS );
            glTexCoord2i( 0, 1 );glVertex3f(-2.000f + background_class::layer[1].pos_x,-2.000f + background_class::layer[1].pos_y,z_pos);
            glTexCoord2i( 0, 0 );glVertex3f(-2.000f + background_class::layer[1].pos_x, 2.000f + background_class::layer[1].pos_y,z_pos);
            glTexCoord2i( 1, 0 );glVertex3f(-2.000f + background_class::layer[2].pos_x, 2.000f + background_class::layer[1].pos_y,z_pos);
            glTexCoord2i( 1, 1 );glVertex3f(-2.000f + background_class::layer[2].pos_x,-2.000f + background_class::layer[1].pos_y,z_pos);
            glEnd();
        }
        //--------------------------------------------------------------------------------------------------------------------------------------
    }
};


int   get_image(void);
int   get_dir_x(void);
int   get_dir_y(void);
float get_pos_x(void);
float get_pos_y(void);


