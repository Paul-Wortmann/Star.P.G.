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

#include "rage.hpp"
#include "../load_resources.hpp"
#include "background.hpp"

extern texture_type texture;

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

int   background_class::get_image(int layer_number)
{
    return(background_class::layer[layer_number].image);
};

int   background_class::get_dir_x(int layer_number)
{
    return(background_class::layer[layer_number].dir_x);
};

int   background_class::get_dir_y(int layer_number)
{
    return(background_class::layer[layer_number].dir_y);
};

float background_class::get_pos_x(int layer_number)
{
    return(background_class::layer[layer_number].pos_x);
};

float background_class::get_pos_y(int layer_number)
{
    return(background_class::layer[layer_number].pos_y);
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
    for(int layer_count = MAX_LAYERS; layer_count > 0; layer_count--)
    {
        if(background_class::layer[layer_count].active)
        {
            if (background_class::layer[layer_count].image == texture.menu_background_000.ref_number) texture.menu_background_000.draw(background_class::layer[layer_count].pos_x,background_class::layer[layer_count].pos_y,z_pos,4.0f,4.0f);
            if (background_class::layer[layer_count].image == texture.menu_background_001.ref_number) texture.menu_background_001.draw(background_class::layer[layer_count].pos_x,background_class::layer[layer_count].pos_y,z_pos,4.0f,4.0f);
            if (background_class::layer[layer_count].image == texture.background_000.ref_number)      texture.background_000.draw     (background_class::layer[layer_count].pos_x,background_class::layer[layer_count].pos_y,z_pos,4.0f,4.0f);
            if (background_class::layer[layer_count].image == texture.background_001.ref_number)      texture.background_001.draw     (background_class::layer[layer_count].pos_x,background_class::layer[layer_count].pos_y,z_pos,4.0f,4.0f);
            if (background_class::layer[layer_count].image == texture.background_002.ref_number)      texture.background_002.draw     (background_class::layer[layer_count].pos_x,background_class::layer[layer_count].pos_y,z_pos,4.0f,4.0f);
            if (background_class::layer[layer_count].image == texture.background_003.ref_number)      texture.background_003.draw     (background_class::layer[layer_count].pos_x,background_class::layer[layer_count].pos_y,z_pos,4.0f,4.0f);
            if (background_class::layer[layer_count].image == texture.background_004.ref_number)      texture.background_004.draw     (background_class::layer[layer_count].pos_x,background_class::layer[layer_count].pos_y,z_pos,4.0f,4.0f);
            if (background_class::layer[layer_count].image == texture.background_005.ref_number)      texture.background_005.draw     (background_class::layer[layer_count].pos_x,background_class::layer[layer_count].pos_y,z_pos,4.0f,4.0f);
            if (background_class::layer[layer_count].image == texture.background_006.ref_number)      texture.background_006.draw     (background_class::layer[layer_count].pos_x,background_class::layer[layer_count].pos_y,z_pos,4.0f,4.0f);
            if (background_class::layer[layer_count].image == texture.background_007.ref_number)      texture.background_007.draw     (background_class::layer[layer_count].pos_x,background_class::layer[layer_count].pos_y,z_pos,4.0f,4.0f);
            if (background_class::layer[layer_count].image == texture.background_008.ref_number)      texture.background_008.draw     (background_class::layer[layer_count].pos_x,background_class::layer[layer_count].pos_y,z_pos,4.0f,4.0f);
            if (background_class::layer[layer_count].image == texture.background_009.ref_number)      texture.background_009.draw     (background_class::layer[layer_count].pos_x,background_class::layer[layer_count].pos_y,z_pos,4.0f,4.0f);
            if (background_class::layer[layer_count].image == texture.background_010.ref_number)      texture.background_010.draw     (background_class::layer[layer_count].pos_x,background_class::layer[layer_count].pos_y,z_pos,4.0f,4.0f);
            if (background_class::layer[layer_count].image == texture.background_011.ref_number)      texture.background_011.draw     (background_class::layer[layer_count].pos_x,background_class::layer[layer_count].pos_y,z_pos,4.0f,4.0f);
            if (background_class::layer[layer_count].image == texture.background_012.ref_number)      texture.background_012.draw     (background_class::layer[layer_count].pos_x,background_class::layer[layer_count].pos_y,z_pos,4.0f,4.0f);
            if (background_class::layer[layer_count].image == texture.background_013.ref_number)      texture.background_013.draw     (background_class::layer[layer_count].pos_x,background_class::layer[layer_count].pos_y,z_pos,4.0f,4.0f);
            if (background_class::layer[layer_count].image == texture.background_014.ref_number)      texture.background_014.draw     (background_class::layer[layer_count].pos_x,background_class::layer[layer_count].pos_y,z_pos,4.0f,4.0f);
            if (background_class::layer[layer_count].image == texture.background_015.ref_number)      texture.background_015.draw     (background_class::layer[layer_count].pos_x,background_class::layer[layer_count].pos_y,z_pos,4.0f,4.0f);
            if (background_class::layer[layer_count].image == texture.background_016.ref_number)      texture.background_016.draw     (background_class::layer[layer_count].pos_x,background_class::layer[layer_count].pos_y,z_pos,4.0f,4.0f);
            if (background_class::layer[layer_count].image == texture.background_017.ref_number)      texture.background_017.draw     (background_class::layer[layer_count].pos_x,background_class::layer[layer_count].pos_y,z_pos,4.0f,4.0f);
            if (background_class::layer[layer_count].image == texture.background_018.ref_number)      texture.background_018.draw     (background_class::layer[layer_count].pos_x,background_class::layer[layer_count].pos_y,z_pos,4.0f,4.0f);
            if (background_class::layer[layer_count].image == texture.background_019.ref_number)      texture.background_019.draw     (background_class::layer[layer_count].pos_x,background_class::layer[layer_count].pos_y,z_pos,4.0f,4.0f);
            if (background_class::layer[layer_count].image == texture.background_020.ref_number)      texture.background_020.draw     (background_class::layer[layer_count].pos_x,background_class::layer[layer_count].pos_y,z_pos,4.0f,4.0f);
            if (background_class::layer[layer_count].image == texture.background_021.ref_number)      texture.background_021.draw     (background_class::layer[layer_count].pos_x,background_class::layer[layer_count].pos_y,z_pos,4.0f,4.0f);
            if (background_class::layer[layer_count].image == texture.background_022.ref_number)      texture.background_022.draw     (background_class::layer[layer_count].pos_x,background_class::layer[layer_count].pos_y,z_pos,4.0f,4.0f);
            if (background_class::layer[layer_count].image == texture.background_023.ref_number)      texture.background_023.draw     (background_class::layer[layer_count].pos_x,background_class::layer[layer_count].pos_y,z_pos,4.0f,4.0f);
            if (background_class::layer[layer_count].image == texture.background_024.ref_number)      texture.background_024.draw     (background_class::layer[layer_count].pos_x,background_class::layer[layer_count].pos_y,z_pos,4.0f,4.0f);
            if (background_class::layer[layer_count].image == texture.background_025.ref_number)      texture.background_025.draw     (background_class::layer[layer_count].pos_x,background_class::layer[layer_count].pos_y,z_pos,4.0f,4.0f);
            if (background_class::layer[layer_count].image == texture.background_026.ref_number)      texture.background_026.draw     (background_class::layer[layer_count].pos_x,background_class::layer[layer_count].pos_y,z_pos,4.0f,4.0f);
            if (background_class::layer[layer_count].image == texture.background_027.ref_number)      texture.background_027.draw     (background_class::layer[layer_count].pos_x,background_class::layer[layer_count].pos_y,z_pos,4.0f,4.0f);
            if (background_class::layer[layer_count].image == texture.background_028.ref_number)      texture.background_028.draw     (background_class::layer[layer_count].pos_x,background_class::layer[layer_count].pos_y,z_pos,4.0f,4.0f);
            if (background_class::layer[layer_count].image == texture.background_029.ref_number)      texture.background_029.draw     (background_class::layer[layer_count].pos_x,background_class::layer[layer_count].pos_y,z_pos,4.0f,4.0f);
            if (background_class::layer[layer_count].image == texture.background_030.ref_number)      texture.background_030.draw     (background_class::layer[layer_count].pos_x,background_class::layer[layer_count].pos_y,z_pos,4.0f,4.0f);
            if (background_class::layer[layer_count].image == texture.background_031.ref_number)      texture.background_031.draw     (background_class::layer[layer_count].pos_x,background_class::layer[layer_count].pos_y,z_pos,4.0f,4.0f);
        }
    }
}
