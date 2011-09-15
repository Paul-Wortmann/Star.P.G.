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


#ifndef BACKGROUND_H
#define BACKGROUND_H

#define BOUNCE  1
#define SCROLL  2

const int MAX_LAYERS = 4;

class background_class
{
    private:
        struct layer_type
        {
        bool  active;
        int   image;
        int   dir_x;
        int   dir_y;
        float pos_x;
        float pos_y;
        float scroll_rate_x;
        float scroll_rate_y;
        };
        layer_type  layer[MAX_LAYERS+1];
        int         movemennt_type;
    public:
        background_class        (void);
        void  set_movement_type (int type_data);
        int   get_movement_type (void);
        void  set_data          (int layer_number, int dx, int dy, int px, int py, float srx, float sry, int image_ref);
        void  set_image         (int layer_number, int image_ref);
        void  set_active        (int layer_number, bool bool_data);
        bool  get_active        (int layer_number);
        float get_scroll_x      (int layer_number);
        float get_scroll_y      (int layer_number);
        int   get_image         (int layer_number);
        int   get_dir_x         (int layer_number);
        int   get_dir_y         (int layer_number);
        float get_pos_x         (int layer_number);
        float get_pos_y         (int layer_number);
        bool  scroll_up         (void);
        bool  scroll_down       (void);
        void  process           (void);
        void  draw              (void);
        void  draw_background   (int image_ref);
};

#endif //BACKGROUND_H
















