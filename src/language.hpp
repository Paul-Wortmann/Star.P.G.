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
 * @date 2011-10-01
 */

#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <string>

struct text_type
{
    std::string    main_menu;
    std::string    star_map;
    std::string    customize_starship;
    std::string    achievements;
    std::string    load_game;
    std::string    save_game;
    std::string    resume_game;
    std::string    options;
    std::string    quit_game;
    std::string    level_select;
    std::string    level_name_00;
    std::string    level_name_01;
    std::string    level_name_02;
    std::string    level_name_03;
    std::string    level_name_04;
    std::string    level_name_05;
    std::string    level_name_06;
    std::string    level_name_07;
    std::string    level_name_08;
    std::string    level_name_09;
    std::string    level_name_10;
    std::string    level_name_11;
    std::string    level_name_12;
    std::string    level_name_13;
    std::string    level_name_14;
    std::string    level_name_15;
    std::string    level_name_16;
    std::string    level_name_17;
    std::string    level_name_18;
    std::string    level_name_19;
    std::string    level_name_20;
    std::string    level_name_21;
    std::string    level_name_22;
    std::string    level_name_23;
    std::string    level_name_24;
    std::string    front_weapon;
    std::string    none;
    std::string    side_weapon;
    std::string    shield;
    std::string    thrusters;
    std::string    support_ships;
    std::string    score;
    std::string    kills;
    std::string    save_menu;
    std::string    save_slot_1;
    std::string    save_slot_2;
    std::string    save_slot_3;
    std::string    save_slot_4;
    std::string    save_slot_5;
    std::string    save_slot_6;
    std::string    save_slot_7;
    std::string    load_menu;
    std::string    sound_volume;
    std::string    music_volume;
    std::string    screen_resolution;
    std::string    res_640_x_480;
    std::string    res_800_x_600;
    std::string    res_1024_x_768;
    std::string    res_1280_x_1024;
    std::string    res_1366_x_768;
    std::string    res_1440_x_900;
    std::string    res_1680_x_1050;
    std::string    res_1920_x_1080;
    std::string    full_screen;
    std::string    game_over;
    std::string    level_completed;
    std::string    next_level;
    std::string    game_completed;
    std::string    game_paused;
    std::string    UI_health_;
    std::string    UI_shield_;
    std::string    UI_front;
    std::string    UI_side;
    std::string    UI_score_;
    std::string    UI_kills_;
    std::string    UI_active_NPCs_;
    std::string    UI_FPS_;
    std::string    NL_level_score_;
    std::string    NL_total_score_;
    std::string    NL_level_kills_;
    std::string    NL_total_kills_;
    std::string    NL_kill_rate_;
    std::string    NL_percentage_sign;
};

class language_class
{
    public:
        void load(std::string file_name);
        text_type text;
        language_class(void);
};

#endif //LANGUAGE_H
