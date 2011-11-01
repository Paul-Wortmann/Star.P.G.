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
#include "core/core.hpp"
#include "projectiles.hpp"
#include "game.hpp"
#include "misc.hpp"

extern   game_type game_o;
extern   texture_type      texture;
extern   sound_type        sound;

void projectile_class::init(void)
{
    projectile_class::name          = "data_not_set";
    projectile_class::active        = false;
    projectile_class::level         = 0;
    projectile_class::experience    = 0;
    projectile_class::level_1       = 1024.0f;
    projectile_class::level_2       = 2048.0f;
    projectile_class::level_3       = 4096.0f;
    projectile_class::image         = 222;
    projectile_class::sound         = 7;
    projectile_class::damage        = 2.5f;
    projectile_class::speed         = 0.003f;
    projectile_class::health        = 10.0f;
    projectile_class::rate_of_fire  = 25;
    projectile_class::movement      = 3;
    projectile_class::wave_size     = 0.125f;
    projectile_class::wave_velocity = 0.00015f;
    projectile_class::width         = 0.075f;
    projectile_class::height        = 0.075f;
};

void projectile_class::init(std::string name,bool active,int exp,int lvl,float l1,float l2,float l3,float l4,float l5,float l6,int img,int snd,float dmg,float spd,float hlth,int rof,int mov,float ws,float wv,float s)
{
    projectile_class::name          = name;
    projectile_class::active        = active;
    projectile_class::level         = lvl;
    projectile_class::experience    = exp;
    projectile_class::level_1       = l1;
    projectile_class::level_2       = l2;
    projectile_class::level_3       = l3;
    projectile_class::level_4       = l4;
    projectile_class::level_5       = l5;
    projectile_class::level_6       = l6;
    projectile_class::image         = img;
    projectile_class::sound         = snd;
    projectile_class::damage        = dmg;
    projectile_class::speed         = spd;
    projectile_class::health        = hlth;
    projectile_class::rate_of_fire  = rof;
    projectile_class::movement      = mov;
    projectile_class::wave_size     = ws;
    projectile_class::wave_velocity = wv;
    projectile_class::width         = 0.075f;
    projectile_class::height        = 0.075f;
};

void projectile_class::init(bool active,int exp,int lvl)
{
    projectile_class::active        = active;
    projectile_class::level         = lvl;
    projectile_class::experience    = exp;
};

void projectile_class::load(std::string file_name)
{
    char         temp_char = ' ';
    float        temp_float_data;
    int          temp_int_data;
    bool         temp_bool_data;
    std::string  temp_string_data;
    std::string  temp_string_key;
    std::string  temp_string_value;
    int          count;
    std::string  data_line;
    std::fstream projectile_file(file_name.c_str(),std::ios::in|std::ios::binary);
    if (projectile_file.is_open())
    {
        while ( projectile_file.good() )
        {
            getline(projectile_file,data_line);
            {
                temp_char = data_line[0];
                if((temp_char != '#') && (data_line.length() > 2))
                {
                    temp_char         = '#';
                    temp_string_key   = "";
                    temp_string_value = "";
                    count = 0;
                    while(temp_char != ' ')
                    {
                        temp_char = data_line[count];
                        if(temp_char != ' ') temp_string_key += temp_char;
                        count++;
                        if(count > data_line.length()) (temp_char = ' ');
                    }
                    while((temp_char == ' ') || (temp_char == '='))
                    {
                        temp_char = data_line[count];
                        count++;
                        if(count > data_line.length()) (temp_char = '#');
                    }
                    count--;
                    while(temp_char != ' ')
                    {
                        temp_char = data_line[count];
                        if(temp_char != ' ') temp_string_value += temp_char;
                        count++;
                        if(count > data_line.length()) (temp_char = ' ');
                    }
                    temp_string_data = temp_string_value.c_str();
                    temp_float_data  = atof(temp_string_value.c_str());
                    temp_int_data    = atoi(temp_string_value.c_str());
                    if (temp_int_data == 1) temp_bool_data = true;
                    else temp_bool_data = false;
                    if (temp_string_key == "Name")
                    {
                        projectile_class::name = temp_string_data;
                    }
                    if (temp_string_key == "Active")
                    {
                        projectile_class::active = temp_bool_data;
                    }
                    if (temp_string_key == "Level")
                    {
                        projectile_class::level = temp_int_data;
                    }
                    if (temp_string_key == "Experience")
                    {
                        projectile_class::experience = temp_float_data;
                    }
                    if (temp_string_key == "Level_1")
                    {
                        projectile_class::level_1 = temp_float_data;
                    }
                    if (temp_string_key == "Level_2")
                    {
                        projectile_class::level_2 = temp_float_data;
                    }
                    if (temp_string_key == "Level_3")
                    {
                        projectile_class::level_3 = temp_float_data;
                    }
                    if (temp_string_key == "Level_4")
                    {
                        projectile_class::level_4 = temp_float_data;
                    }
                    if (temp_string_key == "Level_5")
                    {
                        projectile_class::level_5 = temp_float_data;
                    }
                    if (temp_string_key == "Level_6")
                    {
                        projectile_class::level_6 = temp_float_data;
                    }
                    if (temp_string_key == "Image")
                    {
                        projectile_class::image = temp_int_data;
                    }
                    if (temp_string_key == "Sound")
                    {
                        projectile_class::sound = temp_int_data;
                    }
                    if (temp_string_key == "Damage")
                    {
                        projectile_class::damage = temp_float_data;
                    }
                    if (temp_string_key == "Speed")
                    {
                        projectile_class::speed = temp_float_data;
                    }
                    if (temp_string_key == "Health")
                    {
                        projectile_class::health = temp_float_data;
                    }
                    if (temp_string_key == "ROF")
                    {
                        projectile_class::rate_of_fire = temp_int_data;
                    }
                    if (temp_string_key == "Movement")
                    {
                        projectile_class::movement = temp_int_data;
                    }
                    if (temp_string_key == "Wave_Size")
                    {
                        projectile_class::wave_size = temp_float_data;
                    }
                    if (temp_string_key == "Wave_Velocity")
                    {
                        projectile_class::wave_velocity = temp_float_data;
                    }
                    if (temp_string_key == "Width")
                    {
                        projectile_class::width = temp_float_data;
                    }
                    if (temp_string_key == "Height")
                    {
                        projectile_class::height = temp_float_data;
                    }
                }
            }
        }
        projectile_file.close();
    }
};

void init_projectiles(bool re_init)
{
    if (re_init)
    {
        for (int count = 0; count <= MAX_PROJECTILES; count++)
        {
            game_o.projectile[count].init(false,0,0);
        }
        game_o.projectile[ 0].active            = true;
    }
    else
    {
        game_o.projectile[ 0].load("data/configuration/projectiles/projectile_00.txt");
        game_o.projectile[ 0].image = texture.projectile_000.ref_number;
        game_o.projectile[ 0].sound = sound.projectile_000.ref_number;
        game_o.projectile[ 1].load("data/configuration/projectiles/projectile_01.txt");
        game_o.projectile[ 1].image = texture.projectile_001.ref_number;
        game_o.projectile[ 1].sound = sound.projectile_001.ref_number;
        game_o.projectile[ 2].load("data/configuration/projectiles/projectile_02.txt");
        game_o.projectile[ 2].image = texture.projectile_002.ref_number;
        game_o.projectile[ 2].sound = sound.projectile_002.ref_number;
        game_o.projectile[ 3].load("data/configuration/projectiles/projectile_03.txt");
        game_o.projectile[ 3].image = texture.projectile_003.ref_number;
        game_o.projectile[ 3].sound = sound.projectile_003.ref_number;
        game_o.projectile[ 4].load("data/configuration/projectiles/projectile_04.txt");
        game_o.projectile[ 4].image = texture.projectile_004.ref_number;
        game_o.projectile[ 4].sound = sound.projectile_004.ref_number;
        game_o.projectile[ 5].load("data/configuration/projectiles/projectile_05.txt");
        game_o.projectile[ 5].image = texture.projectile_005.ref_number;
        game_o.projectile[ 5].sound = sound.projectile_005.ref_number;
        game_o.projectile[ 6].load("data/configuration/projectiles/projectile_06.txt");
        game_o.projectile[ 6].image = texture.projectile_006.ref_number;
        game_o.projectile[ 6].sound = sound.projectile_006.ref_number;
        game_o.projectile[ 7].load("data/configuration/projectiles/projectile_07.txt");
        game_o.projectile[ 7].image = texture.projectile_007.ref_number;
        game_o.projectile[ 7].sound = sound.projectile_007.ref_number;
        game_o.projectile[ 8].load("data/configuration/projectiles/projectile_08.txt");
        game_o.projectile[ 8].image = texture.projectile_008.ref_number;
        game_o.projectile[ 8].sound = sound.projectile_008.ref_number;
        game_o.projectile[ 9].load("data/configuration/projectiles/projectile_09.txt");
        game_o.projectile[ 9].image = texture.projectile_009.ref_number;
        game_o.projectile[ 9].sound = sound.projectile_009.ref_number;
        game_o.projectile[10].load("data/configuration/projectiles/projectile_10.txt");
        game_o.projectile[10].image = texture.projectile_010.ref_number;
        game_o.projectile[10].sound = sound.projectile_010.ref_number;
        game_o.projectile[11].load("data/configuration/projectiles/projectile_11.txt");
        game_o.projectile[11].image = texture.projectile_011.ref_number;
        game_o.projectile[11].sound = sound.projectile_011.ref_number;
        game_o.projectile[12].load("data/configuration/projectiles/projectile_12.txt");
        game_o.projectile[12].image = texture.projectile_012.ref_number;
        game_o.projectile[12].sound = sound.projectile_012.ref_number;
        game_o.projectile[13].load("data/configuration/projectiles/projectile_13.txt");
        game_o.projectile[13].image = texture.projectile_013.ref_number;
        game_o.projectile[13].sound = sound.projectile_013.ref_number;
        game_o.projectile[14].load("data/configuration/projectiles/projectile_14.txt");
        game_o.projectile[14].image = texture.projectile_014.ref_number;
        game_o.projectile[14].sound = sound.projectile_014.ref_number;
        game_o.projectile[15].load("data/configuration/projectiles/projectile_15.txt");
        game_o.projectile[15].image = texture.projectile_015.ref_number;
        game_o.projectile[15].sound = sound.projectile_015.ref_number;
        game_o.projectile[16].load("data/configuration/projectiles/projectile_16.txt");
        game_o.projectile[16].image = texture.projectile_016.ref_number;
        game_o.projectile[16].sound = sound.projectile_016.ref_number;
        game_o.projectile[17].load("data/configuration/projectiles/projectile_17.txt");
        game_o.projectile[17].image = texture.projectile_017.ref_number;
        game_o.projectile[17].sound = sound.projectile_017.ref_number;
        game_o.projectile[18].load("data/configuration/projectiles/projectile_18.txt");
        game_o.projectile[18].image = texture.projectile_018.ref_number;
        game_o.projectile[18].sound = sound.projectile_018.ref_number;
        game_o.projectile[19].load("data/configuration/projectiles/projectile_19.txt");
        game_o.projectile[19].image = texture.projectile_019.ref_number;
        game_o.projectile[19].sound = sound.projectile_019.ref_number;
        game_o.projectile[20].load("data/configuration/projectiles/projectile_20.txt");
        game_o.projectile[20].image = texture.projectile_020.ref_number;
        game_o.projectile[20].sound = sound.projectile_020.ref_number;
        game_o.projectile[21].load("data/configuration/projectiles/projectile_21.txt");
        game_o.projectile[21].image = texture.projectile_021.ref_number;
        game_o.projectile[21].sound = sound.projectile_021.ref_number;
        game_o.projectile[22].load("data/configuration/projectiles/projectile_22.txt");
        game_o.projectile[22].image = texture.projectile_022.ref_number;
        game_o.projectile[22].sound = sound.projectile_022.ref_number;
        game_o.projectile[23].load("data/configuration/projectiles/projectile_23.txt");
        game_o.projectile[23].image = texture.projectile_023.ref_number;
        game_o.projectile[23].sound = sound.projectile_023.ref_number;
        game_o.projectile[24].load("data/configuration/projectiles/projectile_24.txt");
        game_o.projectile[24].image = texture.projectile_024.ref_number;
        game_o.projectile[24].sound = sound.projectile_024.ref_number;
        game_o.projectile[25].load("data/configuration/projectiles/projectile_25.txt");
        game_o.projectile[25].image = texture.projectile_025.ref_number;
        game_o.projectile[25].sound = sound.projectile_025.ref_number;
        game_o.projectile[26].load("data/configuration/projectiles/projectile_26.txt");
        game_o.projectile[26].image = texture.projectile_026.ref_number;
        game_o.projectile[26].sound = sound.projectile_026.ref_number;
        game_o.projectile[27].load("data/configuration/projectiles/projectile_27.txt");
        game_o.projectile[27].image = texture.projectile_027.ref_number;
        game_o.projectile[27].sound = sound.projectile_027.ref_number;
        game_o.projectile[28].load("data/configuration/projectiles/projectile_28.txt");
        game_o.projectile[28].image = texture.projectile_028.ref_number;
        game_o.projectile[28].sound = sound.projectile_028.ref_number;
        game_o.projectile[29].load("data/configuration/projectiles/projectile_29.txt");
        game_o.projectile[29].image = texture.projectile_029.ref_number;
        game_o.projectile[29].sound = sound.projectile_029.ref_number;
        game_o.projectile[30].load("data/configuration/projectiles/projectile_30.txt");
        game_o.projectile[30].image = texture.projectile_030.ref_number;
        game_o.projectile[30].sound = sound.projectile_030.ref_number;
        game_o.projectile[31].load("data/configuration/projectiles/projectile_31.txt");
        game_o.projectile[31].image = texture.projectile_031.ref_number;
        game_o.projectile[31].sound = sound.projectile_031.ref_number;
        game_o.projectile[32].load("data/configuration/projectiles/projectile_32.txt");
        game_o.projectile[32].image = texture.projectile_032.ref_number;
        game_o.projectile[32].sound = sound.projectile_032.ref_number;
        game_o.projectile[33].load("data/configuration/projectiles/projectile_33.txt");
        game_o.projectile[33].image = texture.projectile_033.ref_number;
        game_o.projectile[33].sound = sound.projectile_033.ref_number;
        game_o.projectile[34].load("data/configuration/projectiles/projectile_34.txt");
        game_o.projectile[34].image = texture.projectile_034.ref_number;
        game_o.projectile[34].sound = sound.projectile_034.ref_number;
    }
};




