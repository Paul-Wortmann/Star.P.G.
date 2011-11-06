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

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "load_resources.hpp"
#include "thrusters.hpp"
#include "game.hpp"

extern  game_type        game_o;
extern  texture_type     texture;

void init_thrusters(bool re_init)
{
    if (re_init)
    {
        for (int thruster_count = 0; thruster_count < MAX_THRUSTERS; thruster_count++)
        {
            game_o.thruster[thruster_count].active       = false;
            game_o.thruster[thruster_count].experience   = 0;
            game_o.thruster[thruster_count].level        = 0;
        }
    }
    else
    {
        game_o.thruster[0].load("data/configuration/thrusters/thruster_00.txt");
        game_o.thruster[0].name           = game_o.language.text.thruster_name_00;
        game_o.thruster[0].active         = false;
        game_o.thruster[0].image          = texture.thrusters_000.ref_number;
        game_o.thruster[0].frame_max      = texture.thrusters_000.frame_max;
        game_o.thruster[0].fire.init();
        game_o.thruster[0].fire.set_emitter_image(texture.particle_000.ref_number);
        game_o.thruster[0].fire.load("data/configuration/particle_systems/thruster_000_fire.txt");
        game_o.thruster[0].smoke.init();
        game_o.thruster[0].smoke.set_emitter_image(texture.particle_002.ref_number);
        game_o.thruster[0].smoke.load("data/configuration/particle_systems/thruster_000_smoke.txt");

        game_o.thruster[1].load("data/configuration/thrusters/thruster_01.txt");
        game_o.thruster[1].name           = game_o.language.text.thruster_name_01;
        game_o.thruster[1].active         = false;
        game_o.thruster[1].image          = texture.thrusters_001.ref_number;
        game_o.thruster[1].frame_max      = texture.thrusters_001.frame_max;
        game_o.thruster[1].fire.init();
        game_o.thruster[1].fire.set_emitter_image(texture.particle_000.ref_number);
        game_o.thruster[1].fire.load("data/configuration/particle_systems/thruster_001_fire.txt");
        game_o.thruster[1].smoke.init();
        game_o.thruster[1].smoke.set_emitter_image(texture.particle_002.ref_number);
        game_o.thruster[1].smoke.load("data/configuration/particle_systems/thruster_001_smoke.txt");

        game_o.thruster[2].load("data/configuration/thrusters/thruster_02.txt");
        game_o.thruster[2].name           = game_o.language.text.thruster_name_02;
        game_o.thruster[2].active         = false;
        game_o.thruster[2].image          = texture.thrusters_002.ref_number;
        game_o.thruster[2].frame_max      = texture.thrusters_002.frame_max;
        game_o.thruster[2].fire.init();
        game_o.thruster[2].fire.set_emitter_image(texture.particle_000.ref_number);
        game_o.thruster[2].fire.load("data/configuration/particle_systems/thruster_002_fire.txt");
        game_o.thruster[2].smoke.init();
        game_o.thruster[2].smoke.set_emitter_image(texture.particle_002.ref_number);
        game_o.thruster[2].smoke.load("data/configuration/particle_systems/thruster_002_smoke.txt");

        game_o.thruster[3].load("data/configuration/thrusters/thruster_03.txt");
        game_o.thruster[3].name           = game_o.language.text.thruster_name_03;
        game_o.thruster[3].active         = false;
        game_o.thruster[3].image          = texture.thrusters_003.ref_number;
        game_o.thruster[3].frame_max      = texture.thrusters_003.frame_max;
        game_o.thruster[3].fire.init();
        game_o.thruster[3].fire.set_emitter_image(texture.particle_000.ref_number);
        game_o.thruster[3].fire.load("data/configuration/particle_systems/thruster_003_fire.txt");
        game_o.thruster[3].smoke.init();
        game_o.thruster[3].smoke.set_emitter_image(texture.particle_002.ref_number);
        game_o.thruster[3].smoke.load("data/configuration/particle_systems/thruster_003_smoke.txt");
/*
        game_o.thruster[4].load("data/configuration/thrusters/thruster_04.txt");
        game_o.thruster[4].name           = game_o.language.text.thruster_name_04;
        game_o.thruster[4].active         = true;
        game_o.thruster[4].image          = texture.thrusters_004.ref_number;
        game_o.thruster[4].frame_max      = texture.thrusters_004.frame_max;
        game_o.thruster[4].fire.init();
        game_o.thruster[4].fire.set_emitter_image(texture.particle_000.ref_number);
        game_o.thruster[4].fire.load("data/configuration/particle_systems/thruster_004_fire.txt");
        game_o.thruster[4].smoke.init();
        game_o.thruster[4].smoke.set_emitter_image(texture.particle_002.ref_number);
        game_o.thruster[4].smoke.load("data/configuration/particle_systems/thruster_004_smoke.txt");
*/
    }
};

void proc_thrusters(void)
{
    for (int thruster_count = 0; thruster_count < MAX_THRUSTERS; thruster_count++)
    {
        game_o.thruster[thruster_count].smoke.process();
        game_o.thruster[thruster_count].fire.process();
        game_o.thruster[thruster_count].frame++;
        if (game_o.thruster[thruster_count].frame > game_o.thruster[thruster_count].frame_max) game_o.thruster[thruster_count].frame = 0;
    }
};

void draw_thrusters(void)
{
    game_o.thruster[game_o.player.thrusters].smoke.draw();
    game_o.thruster[game_o.player.thrusters].fire.draw();
};

void thruster_class::load(std::string file_name)
{
    char           temp_char_UTF8   = ' ';
    short          temp_char_UTF16  = ' ';
    int            temp_char_UTF32  = ' ';
    float          temp_float_data;
    int            temp_int_data;
    bool           temp_bool_data;
    std::string    temp_string_data;
    std::string    temp_string_key;
    std::string    temp_string_value;
    int            count;
    std::string    data_line;
    std::ifstream  script_file(file_name.c_str(),std::ios::in);
    if (script_file.is_open())
    {
        while ( script_file.good() )
        {
            getline(script_file,data_line);
            if (data_line.length() > 0)
            {
                if ('\r' == data_line.at(data_line.length()-1))
                {
                    data_line = data_line.substr(0, data_line.length()-1);
                }
            }
            {
                temp_char_UTF32 = data_line[0];
                if((temp_char_UTF32 != '#') && (data_line.length() > 2))
                {
                    temp_char_UTF32   = '#';
                    temp_string_key   = "";
                    temp_string_value = "";
                    count = 0;
                    while(temp_char_UTF32 != ' ')
                    {
                        temp_char_UTF32 = data_line[count];
                        if(temp_char_UTF32 != ' ') temp_string_key += temp_char_UTF32;
                        count++;
                        if(count > data_line.length()) (temp_char_UTF32 = ' ');
                    }
                    while((temp_char_UTF32 == ' ') || (temp_char_UTF32 == '='))
                    {
                        temp_char_UTF32 = data_line[count];
                        count++;
                        if(count > data_line.length()) (temp_char_UTF32 = '#');
                    }
                    count--;
                    while(count < (data_line.length()-1))
                    {
                        temp_char_UTF32  = data_line[count];
                        if (temp_char_UTF32 != '"') temp_string_value += temp_char_UTF32;
                        count++;
                    }
                    temp_string_data = temp_string_value.c_str();
                    temp_float_data  = (float) atof(temp_string_value.c_str());
                    temp_int_data    = (int)   atoi(temp_string_value.c_str());
                    if (temp_int_data == 1) temp_bool_data = true;
                    else temp_bool_data = false;
                    if (temp_string_key == "Name")        thruster_class::name       = temp_string_data;
                    if (temp_string_key == "Active")      thruster_class::active     = temp_bool_data;
                    if (temp_string_key == "Level")       thruster_class::level      = temp_int_data;
                    if (temp_string_key == "Level_1")     thruster_class::level_1    = temp_float_data;
                    if (temp_string_key == "Level_2")     thruster_class::level_2    = temp_float_data;
                    if (temp_string_key == "Level_3")     thruster_class::level_3    = temp_float_data;
                    if (temp_string_key == "Experience")  thruster_class::experience = temp_float_data;
                    if (temp_string_key == "Image")       thruster_class::image      = temp_int_data;
                    if (temp_string_key == "Thrust")      thruster_class::thrust     = temp_float_data;
                    if (temp_string_key == "Frame")       thruster_class::frame      = temp_int_data;
                    if (temp_string_key == "Frame_Max")   thruster_class::frame_max  = temp_int_data;
                }
            }
        }
        script_file.close();
    }
};
