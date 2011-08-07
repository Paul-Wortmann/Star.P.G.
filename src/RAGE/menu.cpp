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
    button_class::zoom_size           = 0.0f;
    button_class::zoom_size_counter   = 0.0f;
    button_class::zoom_speed          = 0.0f;
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

void button_class::set_pos_x(float x)
{
    button_class::pos_x = x;
};

void button_class::set_pos_y(float y)
{
    button_class::pos_y = y;
};

void button_class::set_pos_z(float z)
{
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

void  button_class::set_zoom_size_counter(float zsc)
{
    button_class::zoom_size_counter = zsc;
};

float button_class::get_zoom_size_counter(void)
{
    return(button_class::zoom_size_counter);
};

void  button_class::set_zoom_speed(float zsp)
{
    button_class::zoom_speed = zsp;
};

float button_class::get_zoom_speed(void)
{
    return(button_class::zoom_speed);
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
    glLoadIdentity();
    glBegin( GL_QUADS );
    glTexCoord2i( 0, 1 );glVertex3f(button_class::pos_x-(button_class::width/2)-(button_class::get_zoom_size_counter()/2),button_class::pos_y-(button_class::height/2)-(button_class::get_zoom_size_counter()/2),button_class::pos_z);
    glTexCoord2i( 0, 0 );glVertex3f(button_class::pos_x-(button_class::width/2)-(button_class::get_zoom_size_counter()/2),button_class::pos_y+(button_class::height/2)+(button_class::get_zoom_size_counter()/2),button_class::pos_z);
    glTexCoord2i( 1, 0 );glVertex3f(button_class::pos_x+(button_class::width/2)+(button_class::get_zoom_size_counter()/2),button_class::pos_y+(button_class::height/2)+(button_class::get_zoom_size_counter()/2),button_class::pos_z);
    glTexCoord2i( 1, 1 );glVertex3f(button_class::pos_x+(button_class::width/2)+(button_class::get_zoom_size_counter()/2),button_class::pos_y-(button_class::height/2)-(button_class::get_zoom_size_counter()/2),button_class::pos_z);
    glEnd();
    if(button_class::zoom)
    {
        switch(button_class::get_font())
        {
            case 1:
                if ((!button_class::enabled) && ( button_class::highlighted)) font.font_1.Write(button_class::disabled_color_r,button_class::disabled_color_g,button_class::disabled_color_b,button_class::disabled_color_a,button_class::pos_x-button_class::width/2.4,button_class::pos_y-button_class::height/3,1.7f+(button_class::zoom_size/2),12.0f+(button_class::zoom_size/2),button_class::label);
                if ((!button_class::enabled) && (!button_class::highlighted)) font.font_1.Write(button_class::disabled_color_r,button_class::disabled_color_g,button_class::disabled_color_b,button_class::disabled_color_a,button_class::pos_x-button_class::width/2.4,button_class::pos_y-button_class::height/3,1.7f+(button_class::zoom_size/2),12.0f+(button_class::zoom_size/2),button_class::label);
                if (( button_class::enabled) && ( button_class::highlighted)) font.font_1.Write(button_class::highlighted_color_r,button_class::highlighted_color_g,button_class::highlighted_color_b,button_class::highlighted_color_a,button_class::pos_x-button_class::width/2.4,button_class::pos_y-button_class::height/3,1.7f,12.0f+(button_class::zoom_size/2),button_class::label);
                if (( button_class::enabled) && (!button_class::highlighted)) font.font_1.Write(button_class::normal_color_r,button_class::normal_color_g,button_class::normal_color_b,button_class::normal_color_a,button_class::pos_x-button_class::width/2.4,button_class::pos_y-button_class::height/3,1.7f+(button_class::zoom_size/2),12.0f+(button_class::zoom_size/2),button_class::label);
            break;
            case 2:
                if ((!button_class::enabled) && ( button_class::highlighted)) font.font_1.Write(button_class::disabled_color_r,button_class::disabled_color_g,button_class::disabled_color_b,button_class::disabled_color_a,button_class::pos_x-button_class::width/2.4,button_class::pos_y-button_class::height/3,1.7f+(button_class::zoom_size/2),16.0f+(button_class::zoom_size/2),button_class::label);
                if ((!button_class::enabled) && (!button_class::highlighted)) font.font_1.Write(button_class::disabled_color_r,button_class::disabled_color_g,button_class::disabled_color_b,button_class::disabled_color_a,button_class::pos_x-button_class::width/2.4,button_class::pos_y-button_class::height/3,1.7f+(button_class::zoom_size/2),16.0f+(button_class::zoom_size/2),button_class::label);
                if (( button_class::enabled) && ( button_class::highlighted)) font.font_1.Write(button_class::highlighted_color_r,button_class::highlighted_color_g,button_class::highlighted_color_b,button_class::highlighted_color_a,button_class::pos_x-button_class::width/2.4,button_class::pos_y-button_class::height/3,1.7f+(button_class::zoom_size/2),16.0f+(button_class::zoom_size/2),button_class::label);
                if (( button_class::enabled) && (!button_class::highlighted)) font.font_1.Write(button_class::normal_color_r,button_class::normal_color_g,button_class::normal_color_b,button_class::normal_color_a,button_class::pos_x-button_class::width/2.4,button_class::pos_y-button_class::height/3,1.7f+(button_class::zoom_size/2),16.0f+(button_class::zoom_size/2),button_class::label);
            break;
            default:
                if ((!button_class::enabled) && ( button_class::highlighted)) font.font_1.Write(button_class::disabled_color_r,button_class::disabled_color_g,button_class::disabled_color_b,button_class::disabled_color_a,button_class::pos_x-button_class::width/2.4,button_class::pos_y-button_class::height/3,1.7f+(button_class::zoom_size/2),12.0f+(button_class::zoom_size/2),button_class::label);
                if ((!button_class::enabled) && (!button_class::highlighted)) font.font_1.Write(button_class::disabled_color_r,button_class::disabled_color_g,button_class::disabled_color_b,button_class::disabled_color_a,button_class::pos_x-button_class::width/2.4,button_class::pos_y-button_class::height/3,1.7f+(button_class::zoom_size/2),12.0f+(button_class::zoom_size/2),button_class::label);
                if (( button_class::enabled) && ( button_class::highlighted)) font.font_1.Write(button_class::highlighted_color_r,button_class::highlighted_color_g,button_class::highlighted_color_b,button_class::highlighted_color_a,button_class::pos_x-button_class::width/2.4,button_class::pos_y-button_class::height/3,1.7f,12.0f+(button_class::zoom_size/2),button_class::label);
                if (( button_class::enabled) && (!button_class::highlighted)) font.font_1.Write(button_class::normal_color_r,button_class::normal_color_g,button_class::normal_color_b,button_class::normal_color_a,button_class::pos_x-button_class::width/2.4,button_class::pos_y-button_class::height/3,1.7f+(button_class::zoom_size/2),12.0f+(button_class::zoom_size/2),button_class::label);
            break;
        }
    }
    else
    {
        switch(button_class::get_font())
        {
            case 1:
                if ((!button_class::enabled) && ( button_class::highlighted)) font.font_1.Write(button_class::disabled_color_r,button_class::disabled_color_g,button_class::disabled_color_b,button_class::disabled_color_a,button_class::pos_x-button_class::width/2.4,button_class::pos_y-button_class::height/3,1.7f,12.0f,button_class::label);
                if ((!button_class::enabled) && (!button_class::highlighted)) font.font_1.Write(button_class::disabled_color_r,button_class::disabled_color_g,button_class::disabled_color_b,button_class::disabled_color_a,button_class::pos_x-button_class::width/2.4,button_class::pos_y-button_class::height/3,1.7f,12.0f,button_class::label);
                if (( button_class::enabled) && ( button_class::highlighted)) font.font_1.Write(button_class::highlighted_color_r,button_class::highlighted_color_g,button_class::highlighted_color_b,button_class::highlighted_color_a,button_class::pos_x-button_class::width/2.4,button_class::pos_y-button_class::height/3,1.7f,12.0f,button_class::label);
                if (( button_class::enabled) && (!button_class::highlighted)) font.font_1.Write(button_class::normal_color_r,button_class::normal_color_g,button_class::normal_color_b,button_class::normal_color_a,button_class::pos_x-button_class::width/2.4,button_class::pos_y-button_class::height/3,1.7f,12.0f,button_class::label);
            break;
            case 2:
                if ((!button_class::enabled) && ( button_class::highlighted)) font.font_1.Write(button_class::disabled_color_r,button_class::disabled_color_g,button_class::disabled_color_b,button_class::disabled_color_a,button_class::pos_x-button_class::width/2.4,button_class::pos_y-button_class::height/3,1.7f,16.0f,button_class::label);
                if ((!button_class::enabled) && (!button_class::highlighted)) font.font_1.Write(button_class::disabled_color_r,button_class::disabled_color_g,button_class::disabled_color_b,button_class::disabled_color_a,button_class::pos_x-button_class::width/2.4,button_class::pos_y-button_class::height/3,1.7f,16.0f,button_class::label);
                if (( button_class::enabled) && ( button_class::highlighted)) font.font_1.Write(button_class::highlighted_color_r,button_class::highlighted_color_g,button_class::highlighted_color_b,button_class::highlighted_color_a,button_class::pos_x-button_class::width/2.4,button_class::pos_y-button_class::height/3,1.7f,16.0f,button_class::label);
                if (( button_class::enabled) && (!button_class::highlighted)) font.font_1.Write(button_class::normal_color_r,button_class::normal_color_g,button_class::normal_color_b,button_class::normal_color_a,button_class::pos_x-button_class::width/2.4,button_class::pos_y-button_class::height/3,1.7f,16.0f,button_class::label);
            break;
            default:
                if ((!button_class::enabled) && ( button_class::highlighted)) font.font_1.Write(button_class::disabled_color_r,button_class::disabled_color_g,button_class::disabled_color_b,button_class::disabled_color_a,button_class::pos_x-button_class::width/2.4,button_class::pos_y-button_class::height/3,1.7f,12.0f,button_class::label);
                if ((!button_class::enabled) && (!button_class::highlighted)) font.font_1.Write(button_class::disabled_color_r,button_class::disabled_color_g,button_class::disabled_color_b,button_class::disabled_color_a,button_class::pos_x-button_class::width/2.4,button_class::pos_y-button_class::height/3,1.7f,12.0f,button_class::label);
                if (( button_class::enabled) && ( button_class::highlighted)) font.font_1.Write(button_class::highlighted_color_r,button_class::highlighted_color_g,button_class::highlighted_color_b,button_class::highlighted_color_a,button_class::pos_x-button_class::width/2.4,button_class::pos_y-button_class::height/3,1.7f,12.0f,button_class::label);
                if (( button_class::enabled) && (!button_class::highlighted)) font.font_1.Write(button_class::normal_color_r,button_class::normal_color_g,button_class::normal_color_b,button_class::normal_color_a,button_class::pos_x-button_class::width/2.4,button_class::pos_y-button_class::height/3,1.7f,12.0f,button_class::label);
            break;
        }
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

bool  button_class::get_active(void)
{
    return(button_class::active);
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

void  button_class::set_zoom(bool bool_data, float zs, float zsp)
{
    button_class::zoom       = bool_data;
    button_class::zoom_size  = zs;
    button_class::zoom_speed = zsp;
};

void button_class::set_font(int font_number)
{
    button_class::button_font = font_number;
};

int  button_class::get_font(void)
{
    return(button_class::button_font);
};

bool  button_class::get_highlighted(void)
{
    return(button_class::highlighted);
};

void  button_class::set_zoom_size(float zs)
{
    button_class::zoom_size = zs;
};

float button_class::get_zoom_size(void)
{
    return(button_class::zoom_size);
};

void  button_class::set_data(float x, float y, float z, float w, float h, int in, int ih);
{
    button_class::active              = true;
    button_class::image_normal        = in;
    button_class::image_highlighted   = ih;
    button_class::highlighted         = false;
    button_class::pos_x               = x;
    button_class::pos_y               = y;
    button_class::pos_z               = z;
    button_class::width               = w;
    button_class::height              = h;
;

//--------------------------------------- menu ----------------------------------------------------

menu_class::menu_class(void)
{
    menu_class::current_selection = 1;
    menu_class::button[1].set_highlighted(true);
};

menu_class::menu_class(int num_buttons)
{
    menu_class::current_selection = 1;
    for (int button_count = 1; button_count <= menu_class::number_of_buttons; button_count++)
    {
        if (button_count <= num_buttons) menu_class::button[button_count].set_active(true);
        else menu_class::button[button_count].set_active(false);
    }
    menu_class::button[1].set_highlighted(true);
};

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
    for (int button_count = 1; button_count <= menu_class::number_of_buttons; button_count++)
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
    menu_class::button[button_number].set_active(true);
    menu_class::button[button_number].set_font(menu_class::button_font);
    menu_class::button[button_number].set_pos_z(menu_class::button_z_pos);
    menu_class::button[button_number].set_size(menu_class::button_width,menu_class::button_height);
    menu_class::button[button_number].set_label("Not Set");
    menu_class::button[button_number].set_color_normal(menu_class::normal_color_r,menu_class::normal_color_g,menu_class::normal_color_b,menu_class::normal_color_a);
    menu_class::button[button_number].set_color_highlighted(menu_class::highlighted_color_r,menu_class::highlighted_color_g,menu_class::highlighted_color_b,menu_class::highlighted_color_a);
    menu_class::button[button_number].set_color_disabled(menu_class::disabled_color_r,menu_class::disabled_color_g,menu_class::disabled_color_b,menu_class::disabled_color_a);
    menu_class::button[button_number].set_image_normal(menu_class::button_image_normal);
    menu_class::button[button_number].set_image_disabled(menu_class::button_image_disabled);
    menu_class::button[button_number].set_image_highlighted(menu_class::button_image_highlighted);
    menu_class::button[button_number].set_zoom(menu_class::zoom,menu_class::zoom_size,menu_class::zoom_speed);
};

void menu_class::set_button_data(int button_number, std::string label)
{
    menu_class::button[button_number].set_active(true);
    menu_class::button[button_number].set_font(menu_class::button_font);
    menu_class::button[button_number].set_pos_z(menu_class::button_z_pos);
    menu_class::button[button_number].set_label(label);
    menu_class::button[button_number].set_size(menu_class::button_width,menu_class::button_height);
    menu_class::button[button_number].set_color_normal(menu_class::normal_color_r,menu_class::normal_color_g,menu_class::normal_color_b,menu_class::normal_color_a);
    menu_class::button[button_number].set_color_highlighted(menu_class::highlighted_color_r,menu_class::highlighted_color_g,menu_class::highlighted_color_b,menu_class::highlighted_color_a);
    menu_class::button[button_number].set_color_disabled(menu_class::disabled_color_r,menu_class::disabled_color_g,menu_class::disabled_color_b,menu_class::disabled_color_a);
    menu_class::button[button_number].set_image_normal(menu_class::button_image_normal);
    menu_class::button[button_number].set_image_disabled(menu_class::button_image_disabled);
    menu_class::button[button_number].set_image_highlighted(menu_class::button_image_highlighted);
    menu_class::button[button_number].set_zoom(menu_class::zoom,menu_class::zoom_size,menu_class::zoom_speed);
};

void menu_class::set_button_data(int button_number, std::string label,float x, float y, float z)
{
    menu_class::button[button_number].set_active(true);
    menu_class::button[button_number].set_font(menu_class::button_font);
    menu_class::button[button_number].set_pos(x,y,z);
    menu_class::button[button_number].set_label(label);
    menu_class::button[button_number].set_size(menu_class::button_width,menu_class::button_height);
    menu_class::button[button_number].set_color_normal(menu_class::normal_color_r,menu_class::normal_color_g,menu_class::normal_color_b,menu_class::normal_color_a);
    menu_class::button[button_number].set_color_highlighted(menu_class::highlighted_color_r,menu_class::highlighted_color_g,menu_class::highlighted_color_b,menu_class::highlighted_color_a);
    menu_class::button[button_number].set_color_disabled(menu_class::disabled_color_r,menu_class::disabled_color_g,menu_class::disabled_color_b,menu_class::disabled_color_a);
    menu_class::button[button_number].set_image_normal(menu_class::button_image_normal);
    menu_class::button[button_number].set_image_disabled(menu_class::button_image_disabled);
    menu_class::button[button_number].set_image_highlighted(menu_class::button_image_highlighted);
    menu_class::button[button_number].set_zoom(menu_class::zoom,menu_class::zoom_size,menu_class::zoom_speed);
};

void menu_class::set_button_data(void)
{
    for (int button_count = 1; button_count <= menu_class::number_of_buttons; button_count++)
    {
        menu_class::button[button_count].set_active(true);
        menu_class::button[button_count].set_font(menu_class::button_font);
        menu_class::button[button_count].set_pos_z(menu_class::button_z_pos);
        menu_class::button[button_count].set_size(menu_class::button_width,menu_class::button_height);
        menu_class::button[button_count].set_label("Label Not Set");
        menu_class::button[button_count].set_color_normal(menu_class::normal_color_r,menu_class::normal_color_g,menu_class::normal_color_b,menu_class::normal_color_a);
        menu_class::button[button_count].set_color_highlighted(menu_class::highlighted_color_r,menu_class::highlighted_color_g,menu_class::highlighted_color_b,menu_class::highlighted_color_a);
        menu_class::button[button_count].set_color_disabled(menu_class::disabled_color_r,menu_class::disabled_color_g,menu_class::disabled_color_b,menu_class::disabled_color_a);
        menu_class::button[button_count].set_image_normal(menu_class::button_image_normal);
        menu_class::button[button_count].set_image_disabled(menu_class::button_image_disabled);
        menu_class::button[button_count].set_image_highlighted(menu_class::button_image_highlighted);
        menu_class::button[button_count].set_zoom(menu_class::zoom,menu_class::zoom_size,menu_class::zoom_speed);
    }
};

void menu_class::set_button_zoom(bool z, float zs)
{
    menu_class::zoom      = z;
    menu_class::zoom_size = zs;
};

void  menu_class::set_button_zoom(bool bool_data, float zs, float zsp)
{
    menu_class::zoom       = bool_data;
    menu_class::zoom_size  = zs;
    menu_class::zoom_speed = zsp;
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
    float button_offset = (menu_class::button_height/2.0f)*3.0f;
    float temp_float = (menu_class::pos_y + (menu_class::height/2)) - (menu_class::button_height/2.0f);
    menu_class::button_spacing = button_offset;
    for (int button_count = 1; button_count <= menu_class::number_of_buttons; button_count++)
    {
        temp_float -= button_offset;
        menu_class::button[button_count].set_pos_y(temp_float);
    }
};

void menu_class::set_button_spacing_auto(float button_offset)
{
    float temp_float = 0;
    menu_class::button_spacing = button_offset;
    temp_float = (menu_class::height/2) - button_offset - (button_offset /2);
    for (int button_count = 1; button_count <= menu_class::number_of_buttons; button_count++)
    {
        temp_float -= button_offset;
        menu_class::button[button_count].set_pos_y(temp_float);
    }
};

void menu_class::set_button_x_pos(float xp)
{
    menu_class::button_x_pos = xp;
};

float menu_class::get_menu_x_pos(void)
{
    return(menu_class::pos_x);
};

void menu_class::set_button_y_pos(float yp)
{
    menu_class::button_y_pos = yp;
};

float menu_class::get_menu_y_pos(void)
{
    return(menu_class::pos_y);
};

void menu_class::set_button_z_pos(float zp)
{
    menu_class::button_z_pos = zp;
};

float menu_class::get_menu_z_pos(void)
{
    return(menu_class::pos_z);
};

void menu_class::set_menu_title(std::string menu_title)
{
    menu_class::title = menu_title;
};

void menu_class::set_menu_font(int font_number)
{
    menu_class::menu_font = font_number;
};

void menu_class::set_menu_button_font(int font_number)
{
    menu_class::button_font = font_number;
};

int  menu_class::get_menu_font(void)
{
    return(menu_class::menu_font);
};

void menu_class::set_button_font(int button_number)
{
    menu_class::button[button_number].set_font(menu_class::button_font);
};

void menu_class::set_button_size_auto(void)
{
    menu_class::button_width  = (menu_class::width / 100.0f) * 90.0f;
    menu_class::button_height = (menu_class::height / (menu_class::number_of_buttons+((menu_class::number_of_buttons + 4) / 2)));
    set_button_size(menu_class::button_width,menu_class::button_height);
    for (int button_count = 1; button_count <= menu_class::number_of_buttons; button_count++)
    {
        menu_class::button[button_count].set_size(menu_class::button_width,menu_class::button_height);
    }
};

void menu_class::set_current_selection(int cs)
{
    menu_class::current_selection = cs;
};

int  menu_class::get_current_selection(void)
{
    return(menu_class::current_selection);
};


void  menu_class::set_zoom_size_counter(int button_number,float zsc)
{
    menu_class::button[button_number].set_zoom_size_counter(zsc);
};

float menu_class::get_zoom_size_counter(int button_number)
{
    return(menu_class::button[button_number].get_zoom_size_counter());
};

void  menu_class::set_zoom_speed(int button_number,float zsp)
{
    menu_class::button[button_number].set_zoom_speed(zsp);
};

float menu_class::get_zoom_speed(int button_number)
{
    return(menu_class::button[button_number].get_zoom_speed());
};

bool  menu_class::mouse_over_any_button(void)
{
    bool return_value = false;
    for (int button_count = 1; button_count <= menu_class::number_of_buttons; button_count++)
    {
        if (menu_class::button[button_count].mouse_over()) return_value = true;
    }
    return(return_value);
};

int menu_class::process(void)
{
    int  return_value = -1;
    bool done = false;
    // ---- movement from io ----
    if (game.io.up)
    {
        done = false;
        while ((!done) && (menu_class::current_selection != 1))
        {
            menu_class::current_selection--;
            if (menu_class::button[current_selection].get_active()) done = true;
            if (menu_class::current_selection == 1) done = true;
        }
    }
    if (game.io.down)
    {
        done = false;
        while ((!done) && (menu_class::current_selection != menu_class::number_of_buttons))
        {
            menu_class::current_selection++;
            if (menu_class::button[current_selection].get_active()) done = true;
            if (menu_class::current_selection == menu_class::number_of_buttons) done = true;
        }
    }
    if (menu_class::current_selection < 1) menu_class::current_selection = 1;
    if (menu_class::current_selection > menu_class::number_of_buttons) menu_class::current_selection = menu_class::number_of_buttons;
    for (int button_count = 1; button_count <= menu_class::number_of_buttons; button_count++)
    {
        if (menu_class::current_selection == button_count) menu_class::button[button_count].set_highlighted(true);
        else  menu_class::button[button_count].set_highlighted(false);
    }
    //---- mouse ----
    if (menu_class::mouse_over_any_button())
    {
        for (int button_count = 1; button_count <= menu_class::number_of_buttons; button_count++)
        {
            if (menu_class::button[button_count].mouse_over())
            {
                menu_class::current_selection = button_count;
                menu_class::button[button_count].set_highlighted(true);
            }
            else  menu_class::button[button_count].set_highlighted(false);
        }
        for (int button_count = 1; button_count <= menu_class::number_of_buttons; button_count++)
        {
            if (menu_class::button[button_count].mouse_clicked()) return_value = button_count;
        }
        if (game.io.select) return_value = current_selection;
    }
    // ---- zoom ----
    for (int button_count = 1; button_count <= menu_class::number_of_buttons; button_count++)
    {
        if (menu_class::button[button_count].get_highlighted())
        {
            menu_class::button[button_count].set_zoom_size_counter(menu_class::button[button_count].get_zoom_size_counter()+menu_class::button[button_count].get_zoom_speed());
            if (menu_class::button[button_count].get_zoom_size_counter() > menu_class::button[button_count].get_zoom_size()) menu_class::button[button_count].set_zoom_size_counter(menu_class::button[button_count].get_zoom_size());
        }
        else
        {
            menu_class::button[button_count].set_zoom_size_counter(menu_class::button[button_count].get_zoom_size_counter()-menu_class::button[button_count].get_zoom_speed());
            if (menu_class::button[button_count].get_zoom_size_counter() < 0.0f) menu_class::button[button_count].set_zoom_size_counter(0.0f);
        }
    }
    return(return_value);
};













