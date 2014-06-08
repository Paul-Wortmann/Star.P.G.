/**
 * Copyright (C) 2010-2012 Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
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
#include "shields.hpp"
#include "game.hpp"

extern  game_type game_o;
extern  texture_type     texture;

void init_shields(bool re_init)
{
    if (re_init)
    {
        for (int count = 0; count <= MAX_SHIELDS; count++)
        {
            game_o.shield[count].active         = false;
            game_o.shield[count].experience     = 0;
            game_o.shield[count].level          = 0;
        }
    }
    else
    {
        game_o.shield[0].load("data/configuration/shields/shield_00.txt");
        game_o.shield[0].name             = game_o.language.text.shield_name_00;
        game_o.shield[0].image            = texture.shield_000.ref_number;
        game_o.shield[1].load("data/configuration/shields/shield_01.txt");
        game_o.shield[1].name             = game_o.language.text.shield_name_01;
        game_o.shield[1].image            = texture.shield_001.ref_number;
        game_o.shield[2].load("data/configuration/shields/shield_02.txt");
        game_o.shield[2].name             = game_o.language.text.shield_name_02;
        game_o.shield[2].image            = texture.shield_002.ref_number;
        game_o.shield[3].load("data/configuration/shields/shield_03.txt");
        game_o.shield[3].name             = game_o.language.text.shield_name_03;
        game_o.shield[3].image            = texture.shield_003.ref_number;
        game_o.shield[4].load("data/configuration/shields/shield_04.txt");
        game_o.shield[4].name             = game_o.language.text.shield_name_04;
        game_o.shield[4].image            = texture.shield_004.ref_number;
    }
}

void shield_class::load(std::string file_name)
{
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
                if((temp_char_UTF32 != '#') && ((int)data_line.length() > 2))
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
                        if(count > (int)data_line.length()) (temp_char_UTF32 = ' ');
                    }
                    while((temp_char_UTF32 == ' ') || (temp_char_UTF32 == '='))
                    {
                        temp_char_UTF32 = data_line[count];
                        count++;
                        if(count > (int)data_line.length()) (temp_char_UTF32 = '#');
                    }
                    count--;
                    while(count < ((int)data_line.length()-1))
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
                    if (temp_string_key == "Name")        shield_class::name       = temp_string_data;
                    if (temp_string_key == "Active")      shield_class::active     = temp_bool_data;
                    if (temp_string_key == "Level")       shield_class::level      = temp_int_data;
                    if (temp_string_key == "Level_1")     shield_class::level_1    = temp_float_data;
                    if (temp_string_key == "Level_2")     shield_class::level_2    = temp_float_data;
                    if (temp_string_key == "Level_3")     shield_class::level_3    = temp_float_data;
                    if (temp_string_key == "Experience")  shield_class::experience = temp_float_data;
                    if (temp_string_key == "Image")       shield_class::image      = temp_int_data;
                    if (temp_string_key == "Absorption")  shield_class::absorption = temp_float_data;
                }
            }
        }
        script_file.close();
    }
}
