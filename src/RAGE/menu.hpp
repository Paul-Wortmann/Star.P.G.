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

#define NORMAL   0
#define CLOSE    1
#define SLIDER   2
#define TOGGLE   3
#define CHOICE   4

const int MAX_MENU_BUTTONS = 11;

//-------------------------- button -------------------------------
class button_class
{
    private:
        struct choice_data_type
        {
            int         image_ref;
            std::string text_label;
        };
        int           type;
        bool          active;
        int           image_normal;
        int           image_highlighted;
        int           image_disabled;
        int           image_arrow_normal;
        int           image_arrow_highlighted;
        int           image_arrow_disabled;
        bool          highlighted;
        bool          enabled;
        bool          glow;
        bool          zoom;
        float         zoom_size;
        float         zoom_size_counter;
        float         zoom_speed;
        float         pos_x;
        float         pos_y;
        float         pos_z;
        float         height;
        float         width;
        float         arrow_left_pos_x;
        float         arrow_left_pos_y;
        float         arrow_right_pos_x;
        float         arrow_right_pos_y;
        float         arrow_width;
        float         arrow_height;
        float         slider_position;
        float         choice_position;
        std::string   label;
        int           button_font;
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
        button_class(void);
        button_class(float x, float y, float z, float w, float h, int in, int ih, int id, bool hl, bool en, bool gl, bool zm, float zs, int nr, int ng, int nb, int na, int hr, int hg, int hb, int ha, int dr, int dg, int db, int da, std::string lb);
       ~button_class(void);
        void  set_pos(float x, float y, float z);
        void  set_pos_x(float x);
        void  set_pos_y(float y);
        void  set_pos_z(float z);
        float get_pos_x(void);
        float get_pos_y(void);
        float get_pos_z(void);
        void  set_size(float w, float h);
        void  set_label(std::string text);
        void  set_color_normal(int r, int g, int b, int a);
        void  set_color_highlighted(int r, int g, int b, int a);
        void  set_color_disabled(int r, int g, int b, int a);
        void  draw(void);
        void  set_image_normal(int image);
        void  set_image_disabled(int image);
        void  set_image_highlighted(int image);
        void  set_image_arrow_normal(int image);
        void  set_image_arrow_disabled(int image);
        void  set_image_arrow_highlighted(int image);
        void  set_enabled(bool bool_value);
        void  set_highlighted(bool bool_value);
        bool  get_highlighted(void);
        bool  mouse_over(void);
        bool  mouse_clicked(void);
        bool  button_pressed(void);
        void  set_active(bool bool_data);
        bool  get_active(void);
        void  set_zoom(bool bool_data);
        void  set_zoom(bool bool_data, float zs);
        void  set_zoom(bool bool_data, float zs, float zsp);
        void  set_font(int font_number);
        int   get_font(void);
        void  set_zoom_size(float zs);
        float get_zoom_size(void);
        void  set_zoom_size_counter(float zsc);
        float get_zoom_size_counter(void);
        void  set_zoom_speed(float zsp);
        float get_zoom_speed(void);
        void  set_data(float x, float y, float z, float w, float h, int in, int ih);
        void  set_data(float x, float y, float z, float w, float h);
        void  set_data(int in, int ih);
        void  set_button_type(int bt);
        int   get_button_type(void);
        void  set_arrow_left_pos_x(float set_data);
        void  set_arrow_left_pos_y(float set_data);
        void  set_arrow_right_pos_x(float set_data);
        void  set_arrow_right_pos_y(float set_data);
        void  set_arrow_width(float set_data);
        void  set_arrow_height(float set_data);
        void  set_arrow_data(float lx, float ly, float rx, float ry, float w, float h);
        void  set_slider_position(float set_data);
        float get_slider_position(void);
};

//-------------------------- menu -------------------------------
class menu_class
{
    private:
        bool          drag_active;
        float         drag_offset_x;
        float         drag_offset_y;
        int           keyboard_delay;
        int           keyboard_delay_count;
        int           mouse_delay;
        int           mouse_delay_count;
        int           current_vertical_selection;
        int           current_horizontal_selection;
        int           number_of_buttons;
        float         pos_x;
        float         pos_y;
        float         pos_z;
        int           image_background;
        int           button_image_normal;
        int           button_image_highlighted;
        int           button_image_disabled;
        int           button_image_arrow_normal;
        int           button_image_arrow_highlighted;
        int           button_image_arrow_disabled;
        float         button_width;
        float         button_height;
        float         button_spacing;
        float         button_x_pos;
        float         button_y_pos;
        float         button_z_pos;
        float         button_arrow_left_pos_x;
        float         button_arrow_left_pos_y;
        float         button_arrow_right_pos_x;
        float         button_arrow_right_pos_y;
        float         button_arrow_width;
        float         button_arrow_height;
        float         button_slider_position;
        bool          enabled;
        bool          glow;
        bool          zoom;
        float         zoom_size;
        float         zoom_size_counter;
        float         zoom_speed;
        float         height;
        float         width;
        std::string   title_label;
        float         title_height;
        float         title_width;
        float         title_pos_x;
        float         title_pos_y;
        float         title_pos_z;
        int           menu_font;
        int           button_font;
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
        button_class  button[12];
        menu_class(void);
        menu_class(int num_buttons);
        void  draw(void);
        void  set_pos(float x, float y, float z);
        void  set_size(float w, float h);
        void  set_image_background(int bi);
        void  set_color_normal(int r, int g, int b, int a);
        void  set_color_highlighted(int r, int g, int b, int a);
        void  set_color_disabled(int r, int g, int b, int a);
        void  set_button_image_normal(int image);
        void  set_button_image_disabled(int image);
        void  set_button_image_highlighted(int image);
        void  set_button_zoom(bool z, float zs);
        void  set_button_zoom(bool bool_data, float zs, float zsp);
        void  set_button_data(int button_number);
        void  set_button_data(int button_number, std::string label);
        void  set_button_data(int button_number, std::string label,float x, float y, float z);
        void  set_button_data(void);
        void  set_button_size(float w, float h);
        void  set_number_of_buttons(int nob);
        void  set_button_active(int button_number, bool bool_data);
        void  set_button_spacing(void);
        void  set_button_spacing(float button_offset);
        void  set_button_spacing_auto(void);
        void  set_button_spacing_auto(float button_offset);
        void  set_button_x_pos(float xp);
        float get_menu_x_pos(void);
        void  set_button_y_pos(float yp);
        float get_menu_y_pos(void);
        void  set_button_z_pos(float zp);
        float get_menu_z_pos(void);
        void  set_menu_title(std::string menu_title);
        void  set_menu_font(int font_number);
        void  set_menu_button_font(int font_number);
        void  set_button_font(int button_number);
        int   get_menu_font(void);
        void  set_button_size_auto(void);
        void  set_current_vertical_selection(int cvs);
        int   get_current_vertical_selection(void);
        bool  mouse_over_any_button(void);
        void  set_zoom_size_counter(int button_number,float zsc);
        float get_zoom_size_counter(int button_number);
        void  set_zoom_speed(int button_number,float zsp);
        float get_zoom_speed(int button_number);
        void  set_close_button_data(float x, float y, float z, float w, float h, int in, int ih);
        void  set_close_button_data(float x, float y, float z, float w, float h);
        void  set_close_button_data(float x, float y, float z);
        void  set_close_button_data(int in, int ih);
        float get_close_button_pos_x(void);
        float get_close_button_pos_y(void);
        float get_close_button_pos_z(void);
        void  set_close_button_type(int bt);
        void  set_keyboard_delay(int kd);
        int   get_keyboard_delay(void);
        void  set_keyboard_delay_count(int kdc);
        int   get_keyboard_delay_count(void);
        void  set_mouse_delay(int md);
        int   get_mouse_delay(void);
        void  set_mouse_delay_count(int mdc);
        int   get_mouse_delay_count(void);
        void  set_drag_active(bool bool_data);
        bool  get_drag_active(void);
        void  set_title_data(std::string menu_title);
        void  set_title_data(float x, float y, float z, float w, float h, std::string menu_title);
        bool  mouse_over_title(void);
        bool  mouse_click_title(void);
        float set_buttons_auto(void);
        void  set_image_arrow_normal(int image_ref_no);
        void  set_image_arrow_highlighted(int image_ref_no);
        void  set_image_arrow_disabled(int image_ref_no);
        void  set_button_images(int in, int ih, int id, int ian, int iah, int iad);
        void  set_button_arrow_left_pos_x(float set_data);
        void  set_button_arrow_left_pos_y(float set_data);
        void  set_button_arrow_right_pos_x(float set_data);
        void  set_button_arrow_right_pos_y(float set_data);
        void  set_button_arrow_width(float set_data);
        void  set_button_arrow_height(float set_data);
        void  set_button_arrow_data(float lx, float ly, float rx, float ry, float w, float h);
        void  set_button_slider_position(int button_number, float set_data);
        float get_button_slider_position(int button_number);
        int   process(void);
};

#endif //MENU_H







































