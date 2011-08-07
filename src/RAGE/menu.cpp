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

extern  game_class               game;
extern  font_type                font;

button_class::button_class(void)
{
    button_class::active              = false;
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

button_class::button_class(float x, float y, float z, float w, float h, int in, int ih, int id, bool hl, bool en, bool gl, bool zm, float zs, int nr, int ng, int nb, int na, int hr, int hg, int hb, int ha, int dr, int dg, int db, int da, std::string lb)
{
    button_class::active              = false;
    button_class::image_normal        = in;
    button_class::image_highlighted   = ih;
    button_class::image_disabled      = id;
    button_class::highlighted         = hl;
    button_class::enabled             = en;
    button_class::glow                = gl;
    button_class::zoom                = zm;
    button_class::zoom_size           = zs;
    button_class::pos_x               = x;
    button_class::pos_y               = y;
    button_class::pos_z               = z;
    button_class::width               = w;
    button_class::height              = h;
    button_class::label               = lb;
    button_class::normal_color_r      = nr;
    button_class::normal_color_g      = ng;
    button_class::normal_color_b      = nb;
    button_class::normal_color_a      = na;
    button_class::highlighted_color_r = hr;
    button_class::highlighted_color_g = hg;
    button_class::highlighted_color_b = hb;
    button_class::highlighted_color_a = ha;
    button_class::disabled_color_r    = dr;
    button_class::disabled_color_g    = dg;
    button_class::disabled_color_b    = db;
    button_class::disabled_color_a    = da;
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

void button_class::set_pos_y(float y)
{
    button_class::pos_y = y;
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
    if (!button_class::active) return;
    if (!button_class::enabled) bind_texture(button_class::image_disabled);
    else
    {
        if (button_class::highlighted) bind_texture(button_class::image_highlighted);
        else bind_texture(button_class::image_normal);
    };
    if((button_class::zoom) && (button_class::highlighted))
    {
        glLoadIdentity();
        glBegin( GL_QUADS );
        glTexCoord2i( 0, 1 );glVertex3f(button_class::pos_x-(button_class::width/2)-button_class::zoom,button_class::pos_y-(button_class::height/2)-button_class::zoom,button_class::pos_z);
        glTexCoord2i( 0, 0 );glVertex3f(button_class::pos_x-(button_class::width/2)-button_class::zoom,button_class::pos_y+(button_class::height/2)+button_class::zoom,button_class::pos_z);
        glTexCoord2i( 1, 0 );glVertex3f(button_class::pos_x+(button_class::width/2)+button_class::zoom,button_class::pos_y+(button_class::height/2)+button_class::zoom,button_class::pos_z);
        glTexCoord2i( 1, 1 );glVertex3f(button_class::pos_x+(button_class::width/2)+button_class::zoom,button_class::pos_y-(button_class::height/2)-button_class::zoom,button_class::pos_z);
        glEnd();
        font.font_2.Write(button_class::highlighted_color_r,button_class::highlighted_color_g,button_class::highlighted_color_b,button_class::highlighted_color_a,button_class::pos_x-button_class::width/8,button_class::pos_y-button_class::height/3,button_class::label);
        ///font print label!!!
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
        font.font_2.Write(button_class::normal_color_r,button_class::normal_color_g,button_class::normal_color_b,button_class::normal_color_a,button_class::pos_x-button_class::width/8,button_class::pos_y-button_class::height/3,button_class::label);
        ///font print label!!!
    };
};

bool button_class::button_pressed(void)
{
    if ((game.io.select) && (button_class::highlighted)) return (true);
    else return (false);
};

void button_class::set_active(bool bool_data)
{
    button_class::active = bool_data;
};

void button_class::set_zoom(bool bool_data)
{
    button_class::zoom      = bool_data;
};

void button_class::set_zoom(bool bool_data, float zs)
{
    button_class::zoom      = bool_data;
    button_class::zoom_size = zs;
};

//--------------------------------------- menu ----------------------------------------------------
void menu_class::set_pos(float x, float y, float z)
{
    menu_class::pos_x = x;
    menu_class::pos_y = y;
    menu_class::pos_z = z;
};

void menu_class::set_size(float w, float h)
{
    menu_class::width  = w;
    menu_class::height = h;
};

void menu_class::set_image_background(int bi)
{
    menu_class::image_background = bi;
};

menu_class::menu_class(void)
{

};

menu_class::menu_class(int num_buttons)
{
    for (int button_count = 1; button_count < menu_class::number_of_buttons; button_count++)
    {
        if (button_count <= num_buttons) menu_class::button[button_count].set_active(true);
        else menu_class::button[button_count].set_active(false);
    }
};

void menu_class::draw(void)
{
    bind_texture(menu_class::image_background);
    glLoadIdentity();
    glBegin( GL_QUADS );
    glTexCoord2i( 0, 1 );glVertex3f(menu_class::pos_x-menu_class::width/2,menu_class::pos_y-menu_class::height/2,menu_class::pos_y);
    glTexCoord2i( 0, 0 );glVertex3f(menu_class::pos_x-menu_class::width/2,menu_class::pos_y+menu_class::height/2,menu_class::pos_y);
    glTexCoord2i( 1, 0 );glVertex3f(menu_class::pos_x+menu_class::width/2,menu_class::pos_y+menu_class::height/2,menu_class::pos_y);
    glTexCoord2i( 1, 1 );glVertex3f(menu_class::pos_x+menu_class::width/2,menu_class::pos_y-menu_class::height/2,menu_class::pos_y);
    glEnd();
    for (int button_count = 1; button_count < menu_class::number_of_buttons; button_count++)
    {
        menu_class::button[button_count].draw();
    }
};

void menu_class::set_color_normal(int r, int g, int b, int a)
{
    menu_class::normal_color_r = r;
    menu_class::normal_color_g = g;
    menu_class::normal_color_b = b;
    menu_class::normal_color_a = a;
};

void menu_class::set_color_highlighted(int r, int g, int b, int a)
{
    menu_class::highlighted_color_r = r;
    menu_class::highlighted_color_g = g;
    menu_class::highlighted_color_b = b;
    menu_class::highlighted_color_a = a;
};

void menu_class::set_color_disabled(int r, int g, int b, int a)
{
    menu_class::disabled_color_r = r;
    menu_class::disabled_color_g = g;
    menu_class::disabled_color_b = b;
    menu_class::disabled_color_a = a;
};

void menu_class::set_button_image_normal(int image)
{
    menu_class::button_image_normal = image;
};

void menu_class::set_button_image_disabled(int image)
{
    menu_class::button_image_disabled = image;
};

void menu_class::set_button_image_highlighted(int image)
{
    menu_class::button_image_highlighted = image;
};

void menu_class::set_button_data(int button_number)
{
    menu_class::set_button_active(button_number,true);
    menu_class::button[button_number].set_size(menu_class::button_width,menu_class::button_height);
    menu_class::button[button_number].set_label("Not Set");
    menu_class::button[button_number].set_color_normal(menu_class::normal_color_r,menu_class::normal_color_g,menu_class::normal_color_b,menu_class::normal_color_a);
    menu_class::button[button_number].set_color_highlighted(menu_class::highlighted_color_r,menu_class::highlighted_color_g,menu_class::highlighted_color_b,menu_class::highlighted_color_a);
    menu_class::button[button_number].set_color_disabled(menu_class::disabled_color_r,menu_class::disabled_color_g,menu_class::disabled_color_b,menu_class::disabled_color_a);
    menu_class::button[button_number].set_image_normal(menu_class::button_image_normal);
    menu_class::button[button_number].set_image_disabled(menu_class::button_image_disabled);
    menu_class::button[button_number].set_image_highlighted(menu_class::button_image_highlighted);
    menu_class::button[button_number].set_zoom(menu_class::zoom,menu_class::zoom_size);
};

void menu_class::set_button_data(int button_number, std::string label)
{
    menu_class::button[button_number].set_label(label);
    menu_class::set_button_active(button_number,true);
    menu_class::button[button_number].set_size(menu_class::button_width,menu_class::button_height);
    menu_class::button[button_number].set_color_normal(menu_class::normal_color_r,menu_class::normal_color_g,menu_class::normal_color_b,menu_class::normal_color_a);
    menu_class::button[button_number].set_color_highlighted(menu_class::highlighted_color_r,menu_class::highlighted_color_g,menu_class::highlighted_color_b,menu_class::highlighted_color_a);
    menu_class::button[button_number].set_color_disabled(menu_class::disabled_color_r,menu_class::disabled_color_g,menu_class::disabled_color_b,menu_class::disabled_color_a);
    menu_class::button[button_number].set_image_normal(menu_class::button_image_normal);
    menu_class::button[button_number].set_image_disabled(menu_class::button_image_disabled);
    menu_class::button[button_number].set_image_highlighted(menu_class::button_image_highlighted);
    menu_class::button[button_number].set_zoom(menu_class::zoom,menu_class::zoom_size);
};

void menu_class::set_button_data(int button_number, std::string label,float x, float y, float z)
{
    menu_class::button[button_number].set_pos(x,y,z);
    menu_class::button[button_number].set_label(label);
    menu_class::set_button_active(button_number,true);
    menu_class::button[button_number].set_size(menu_class::button_width,menu_class::button_height);
    menu_class::button[button_number].set_color_normal(menu_class::normal_color_r,menu_class::normal_color_g,menu_class::normal_color_b,menu_class::normal_color_a);
    menu_class::button[button_number].set_color_highlighted(menu_class::highlighted_color_r,menu_class::highlighted_color_g,menu_class::highlighted_color_b,menu_class::highlighted_color_a);
    menu_class::button[button_number].set_color_disabled(menu_class::disabled_color_r,menu_class::disabled_color_g,menu_class::disabled_color_b,menu_class::disabled_color_a);
    menu_class::button[button_number].set_image_normal(menu_class::button_image_normal);
    menu_class::button[button_number].set_image_disabled(menu_class::button_image_disabled);
    menu_class::button[button_number].set_image_highlighted(menu_class::button_image_highlighted);
    menu_class::button[button_number].set_zoom(menu_class::zoom,menu_class::zoom_size);
};

void menu_class::set_button_data(void)
{
    for (int button_count = 1; button_count < menu_class::number_of_buttons; button_count++)
    {
        menu_class::button[button_count].set_size(menu_class::button_width,menu_class::button_height);
        menu_class::button[button_count].set_label("Label Not Set");
        menu_class::button[button_count].set_color_normal(menu_class::normal_color_r,menu_class::normal_color_g,menu_class::normal_color_b,menu_class::normal_color_a);
        menu_class::button[button_count].set_color_highlighted(menu_class::highlighted_color_r,menu_class::highlighted_color_g,menu_class::highlighted_color_b,menu_class::highlighted_color_a);
        menu_class::button[button_count].set_color_disabled(menu_class::disabled_color_r,menu_class::disabled_color_g,menu_class::disabled_color_b,menu_class::disabled_color_a);
        menu_class::button[button_count].set_image_normal(menu_class::button_image_normal);
        menu_class::button[button_count].set_image_disabled(menu_class::button_image_disabled);
        menu_class::button[button_count].set_image_highlighted(menu_class::button_image_highlighted);
        menu_class::button[button_count].set_zoom(menu_class::zoom,menu_class::zoom_size);
    }
};

void menu_class::set_button_zoom(bool z, float zs)
{
    menu_class::zoom      = z;
    menu_class::zoom_size = zs;
};

void menu_class::set_button_size(float w, float h)
{
    menu_class::button_width  = w;
    menu_class::button_height = h;
};

void menu_class::set_number_of_buttons(int nob)
{
    if (nob <  0) nob = 0;
    menu_class::number_of_buttons = nob;
};

void menu_class::set_button_active(int button_number, bool bool_data)
{
    menu_class::button[button_number].set_active(bool_data);
};

void menu_class::set_button_spacing(void)
{
    menu_class::button_spacing = ((menu_class::width - menu_class::button_width) /2);
};

void menu_class::set_button_spacing(float button_offset)
{
    menu_class::button_spacing = button_offset;
};

void menu_class::set_button_spacing_auto(void)
{
    float button_offset = ((menu_class::width - menu_class::button_width));
    float temp_float = (menu_class::height/2) - button_offset;
    button_offset += button_offset/2;
    menu_class::button_spacing = button_offset;
    for (int button_count = 1; button_count < menu_class::number_of_buttons; button_count++)
    {
        temp_float -= button_offset;
        menu_class::button[button_count].set_pos_y(temp_float);
    }
};

void menu_class::set_button_spacing_auto(float button_offset)
{
    float temp_float = 0;
    menu_class::button_spacing = button_offset;
    temp_float = (menu_class::height/2) -  (button_offset /2);
    for (int button_count = 1; button_count < menu_class::number_of_buttons; button_count++)
    {
        temp_float -= button_offset;
        menu_class::button[button_count].set_pos_y(temp_float);
    }
};



















