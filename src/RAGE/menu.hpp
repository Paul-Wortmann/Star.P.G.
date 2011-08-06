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

#ifndef MENU_H
#define MENU_H

#include <string>
//-------------------------- button -------------------------------
class button_class
{
    private:
        bool        active;
        int         image_normal;
        int         image_highlighted;
        int         image_disabled;
        bool        highlighted;
        bool        enabled;
        bool        glow;
        bool        zoom;
        float       zoom_size;
        float       pos_x;
        float       pos_y;
        float       pos_z;
        float       height;
        float       width;
        std::string label;
        int         normal_color_r;
        int         normal_color_g;
        int         normal_color_b;
        int         normal_color_a;
        int         highlighted_color_r;
        int         highlighted_color_g;
        int         highlighted_color_b;
        int         highlighted_color_a;
        int         disabled_color_r;
        int         disabled_color_g;
        int         disabled_color_b;
        int         disabled_color_a;

    public:
        button_class(void);
        button_class(float x, float y, float z, float w, float h, int in, int ih, int id, bool hl, bool en, bool gl, bool zm, float zs, int nr, int ng, int nb, int na, int hr, int hg, int hb, int ha, int dr, int dg, int db, int da, std::string lb);
       ~button_class(void);
        void set_pos(float x, float y, float z);
        void set_size(float w, float h);
        void set_label(std::string text);
        void set_color_normal(int r, int g, int b, int a);
        void set_color_highlighted(int r, int g, int b, int a);
        void set_color_disabled(int r, int g, int b, int a);
        void draw(void);
        void set_image_normal(int image);
        void set_image_disabled(int image);
        void set_image_highlighted(int image);
        void set_enabled(bool bool_value);
        void set_highlighted(bool bool_value);
        bool mouse_over(void);
        bool mouse_clicked(void);
        bool button_pressed(void);
        void set_active(bool bool_data);
        void set_zoom(bool bool_data);
        void set_zoom(bool bool_data, float zs);
};

//-------------------------- menu -------------------------------
class menu_class
{
    private:
        int           number_of_buttons;
        float         pos_x;
        float         pos_y;
        float         pos_z;
        int           image_background;
        int           button_image_normal;
        int           button_image_highlighted;
        int           button_image_disabled;
        float         button_width;
        float         button_height;
        bool          enabled;
        bool          glow;
        bool          zoom;
        float         zoom_size;
        float         height;
        float         width;
        std::string   title;
        std::string   status;
        int           normal_color_r;
        int           normal_color_g;
        int           normal_color_b;
        int           normal_color_a;
        int           highlighted_color_r;
        int           highlighted_color_g;
        int           highlighted_color_b;
        int           highlighted_color_a;
        int           disabled_color_r;
        int           disabled_color_g;
        int           disabled_color_b;
        int           disabled_color_a;
    public:
        button_class  close_button;
        button_class  button_1;
        button_class  button_2;
        button_class  button_3;
        button_class  button_4;
        button_class  button_5;
        button_class  button_6;
        button_class  button_7;
        button_class  button_8;
        menu_class(void);
        menu_class(int num_buttons);
        void draw(void);
        void set_pos(float x, float y, float z);
        void set_size(float w, float h);
        void set_image_background(int bi);
        void set_color_normal(int r, int g, int b, int a);
        void set_color_highlighted(int r, int g, int b, int a);
        void set_color_disabled(int r, int g, int b, int a);
        void set_image_normal(int image);
        void set_image_disabled(int image);
        void set_image_highlighted(int image);
        void set_button_data(int button_number);
        void set_button_size(float w, float h);
};

#endif //MENU_H







































