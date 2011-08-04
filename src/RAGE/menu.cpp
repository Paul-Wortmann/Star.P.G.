/**
 * Copyright (C) 2011 Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
 * This file is part of R.A.G.E. (RoboPaul's Adaptable Game Engine)
 *
 * R.A.G.E. (RoboPaul's Adaptable Game Engine) is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * R.A.G.E. (RoboPaul's Adaptable Game Engine) is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with R.A.G.E. (RoboPaul's Adaptable Game Engine) If not, see <http://www.gnu.org/licenses/>.
 *
 * @author Paul Wortmann
 * @license GPL
 * @date 2011-07-17
 */

#include "menu.hpp"
#include "rage.hpp"
#include "../load_resources.hpp"

extern game_class        game;

button_class::button_class(void)
{
    button_class::image_normal        = 0;
    button_class::image_highlighted   = 0;
    button_class::image_disabled      = 0;
    button_class::highlighted         = false;
    button_class::enabled             = true;
    button_class::glow                = true;
    button_class::zoom                = true;
    button_class::zoom_size           = 0.01f;
    button_class::pos_x               = 0.0f;
    button_class::pos_y               = 0.0f;
    button_class::pos_z               = 0.0f;
    button_class::height              = 0.0f;
    button_class::width               = 0.0f;
    button_class::label               = "Label Not Set";
    button_class::normal_color_r      = 255;
    button_class::normal_color_g      = 255;
    button_class::normal_color_b      = 255;
    button_class::normal_color_a      = 255;
    button_class::highlighted_color_r = 255;
    button_class::highlighted_color_g = 255;
    button_class::highlighted_color_b = 255;
    button_class::highlighted_color_a = 255;
    button_class::disabled_color_r    = 255;
    button_class::disabled_color_g    = 255;
    button_class::disabled_color_b    = 255;
    button_class::disabled_color_a    = 255;
};

button_class::~button_class(void)
{

};

void button_class::set_pos(float x, float y, float z)
{
    button_class::pos_x = x;
    button_class::pos_y = y;
    button_class::pos_z = z;
};

void button_class::set_size(float w, float h)
{
    button_class::width  = w;
    button_class::height = h;
};

void button_class::set_label(std::string text)
{
    button_class::label = text;
};

void button_class::set_color_normal(int r, int g, int b, int a)
{
    button_class::normal_color_r = r;
    button_class::normal_color_g = g;
    button_class::normal_color_b = b;
    button_class::normal_color_a = a;
};

void button_class::set_color_highlighted(int r, int g, int b, int a)
{
    button_class::highlighted_color_r = r;
    button_class::highlighted_color_g = g;
    button_class::highlighted_color_b = b;
    button_class::highlighted_color_a = a;
};

void button_class::set_color_disabled(int r, int g, int b, int a)
{
    button_class::disabled_color_r = r;
    button_class::disabled_color_g = g;
    button_class::disabled_color_b = b;
    button_class::disabled_color_a = a;
};

void button_class::set_image_normal(int image)
{
    button_class::image_normal = image;
};

void button_class::set_image_disabled(int image)
{
    button_class::image_disabled = image;
};

void button_class::set_image_highlighted(int image)
{
    button_class::image_highlighted = image;
};

void button_class::set_enabled(bool bool_value)
{
    button_class::enabled = bool_value;
};

void button_class::set_highlighted(bool bool_value)
{
    button_class::highlighted = bool_value;
};

bool button_class::mouse_over(void)
{
    if ((highlighted) && (zoom)) return(game.physics.point_in_quadrangle(button_class::pos_x,button_class::width+button_class::zoom_size,button_class::pos_y,button_class::height+button_class::zoom_size,game.io.mouse_x,game.io.mouse_y));
    else return(game.physics.point_in_quadrangle(button_class::pos_x,button_class::width,button_class::pos_y,button_class::height,game.io.mouse_x,game.io.mouse_y));
};

bool button_class::mouse_clicked(void)
{
    if (game.io.mouse_button_left)
    {
        if ((highlighted) && (zoom)) return(game.physics.point_in_quadrangle(button_class::pos_x,button_class::width+button_class::zoom_size,button_class::pos_y,button_class::height+button_class::zoom_size,game.io.mouse_x,game.io.mouse_y));
       else return(game.physics.point_in_quadrangle(button_class::pos_x,button_class::width,button_class::pos_y,button_class::height,game.io.mouse_x,game.io.mouse_y));
    }
    else return(false);
};

void button_class::draw(void)
{
    if (!button_class::enabled) bind_texture(button_class::image_disabled);
    else
    {
        if (button_class::highlighted) bind_texture(button_class::image_highlighted);
        else bind_texture(button_class::image_normal);
    }
    if((button_class::zoom) && (button_class::highlighted))
    {
        glLoadIdentity();
        glBegin( GL_QUADS );
        glTexCoord2i( 0, 1 );glVertex3f(button_class::pos_x-(button_class::width/2)-button_class::zoom,button_class::pos_y-(button_class::height/2)-button_class::zoom,button_class::pos_z);
        glTexCoord2i( 0, 0 );glVertex3f(button_class::pos_x-(button_class::width/2)-button_class::zoom,button_class::pos_y+(button_class::height/2)+button_class::zoom,button_class::pos_z);
        glTexCoord2i( 1, 0 );glVertex3f(button_class::pos_x+(button_class::width/2)+button_class::zoom,button_class::pos_y+(button_class::height/2)+button_class::zoom,button_class::pos_z);
        glTexCoord2i( 1, 1 );glVertex3f(button_class::pos_x+(button_class::width/2)+button_class::zoom,button_class::pos_y-(button_class::height/2)-button_class::zoom,button_class::pos_z);
        glEnd();
    }
    else
    {
        glLoadIdentity();
        glBegin( GL_QUADS );
        glTexCoord2i( 0, 1 );glVertex3f(button_class::pos_x-(button_class::width/2),button_class::pos_y-(button_class::height/2),button_class::pos_z);
        glTexCoord2i( 0, 0 );glVertex3f(button_class::pos_x-(button_class::width/2),button_class::pos_y+(button_class::height/2),button_class::pos_z);
        glTexCoord2i( 1, 0 );glVertex3f(button_class::pos_x+(button_class::width/2),button_class::pos_y+(button_class::height/2),button_class::pos_z);
        glTexCoord2i( 1, 1 );glVertex3f(button_class::pos_x+(button_class::width/2),button_class::pos_y-(button_class::height/2),button_class::pos_z);
        glEnd();
    }
};

bool button_class::button_pressed(void)
{
    if ((game.io.select) && (button_class::highlighted)) return (true);
    else return (false);
};

button_class::button_class(float x, float y, float z, float w, float h, int in, int ih, int id, bool hl, bool en, bool gl, bool zm, float zs, int nr, int ng, int nb, int na, int hr, int hg, int hb, int ha, int dr, int dg, int db, int da, std::string lb)
{
    button_class::pos_x = x;
    button_class::pos_y = y;
    button_class::pos_z = z;
    button_class::width  = w;
    button_class::height = h;
    button_class::image_normal = in;
    button_class::image_highlighted = ih;
    button_class::image_disabled = id;


};





