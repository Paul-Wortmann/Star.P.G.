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
#include "core/core.hpp"
#include "NPC.hpp"
#include "load_resources.hpp"
#include "game.hpp"
#include "misc.hpp"

extern  sound_type       sound;
extern  music_type       music;
extern  texture_type     texture;
extern  game_type        game_o;
extern  game_class       game;

void enemy_class::load(std::string file_name)
{
    char         temp_char = ' ';
    std::string  temp_string_data;
    std::string  temp_string_key;
    std::string  temp_string_value;
    std::string  data_line;
    std::fstream script_file(file_name.c_str(),std::ios::in|std::ios::binary);
    if (script_file.is_open())
    {
        float temp_float_data;
        int   temp_int_data;
        while ( script_file.good() )
        {
            getline(script_file,data_line);
            {
                temp_char = data_line[0];
                if((temp_char != '#') && ((int)data_line.length() > 2))
                {
                    temp_char         = '#';
                    temp_string_key   = "";
                    temp_string_value = "";
                    int count = 0;
                    while(temp_char != ' ')
                    {
                        temp_char = data_line[count];
                        if(temp_char != ' ') temp_string_key += temp_char;
                        count++;
                        if(count > (int)data_line.length()) (temp_char = ' ');
                    }
                    while((temp_char == ' ') || (temp_char == '='))
                    {
                        temp_char = data_line[count];
                        count++;
                        if(count > (int)data_line.length()) (temp_char = '#');
                    }
                    count--;
                    while(temp_char != ' ')
                    {
                        temp_char = data_line[count];
                        if(temp_char != ' ') temp_string_value += temp_char;
                        count++;
                        if(count > (int)data_line.length()) (temp_char = ' ');
                    }
                    temp_string_data = temp_string_value.c_str();
                    temp_float_data  = atof(temp_string_value.c_str());
                    temp_int_data    = atoi(temp_string_value.c_str());
                    if (temp_string_key == "Name")
                    {
                        enemy_class::name = temp_string_data;
                    }
                    if (temp_string_key == "Image")
                    {
                        enemy_class::image = temp_int_data;
                    }
                    if (temp_string_key == "Sound")
                    {
                        enemy_class::sound = temp_int_data;
                    }
                    if (temp_string_key == "Health")
                    {
                        enemy_class::health = temp_float_data;
                    }
                    if (temp_string_key == "Speed")
                    {
                        enemy_class::speed = temp_float_data;
                    }
                    if (temp_string_key == "Speed_Max")
                    {
                        enemy_class::max_speed = temp_float_data;
                    }
                    if (temp_string_key == "Acceleration")
                    {
                        enemy_class::acceleration = temp_float_data;
                    }
                    if (temp_string_key == "Start_Angle")
                    {
                        enemy_class::start_angle = temp_float_data;
                    }
                    if (temp_string_key == "Movement")
                    {
                        enemy_class::movement = temp_int_data;
                    }
                    if (temp_string_key == "Weapon_1")
                    {
                        enemy_class::weapon_1 = temp_int_data;
                    }
                    if (temp_string_key == "Weapon_2")
                    {
                        enemy_class::weapon_2 = temp_int_data;
                    }
                    if (temp_string_key == "Projectiles")
                    {
                        enemy_class::projectiles = temp_int_data;
                    }
                    if (temp_string_key == "Width")
                    {
                        enemy_class::width = temp_float_data;
                    }
                    if (temp_string_key == "Height")
                    {
                        enemy_class::height = temp_float_data;
                    }
                }
            }
        }
        script_file.close();
    }
}

void init_enemies(bool re_init)
{
    if(re_init)
    {
        ;
    }
    else
    {
        game_o.enemy[ 0].load("data/configuration/enemies/enemy_00.txt");
        game_o.enemy[ 0].name        = game_o.language.text.enemy_name_00;
        game_o.enemy[ 0].image       = texture.ship_000.ref_number;
        game_o.enemy[ 0].max_speed   = (game_o.projectile[game_o.enemy[ 0].weapon_1].speed/2) + game_o.enemy[ 0].max_speed;
        game_o.enemy[ 1].load("data/configuration/enemies/enemy_01.txt");
        game_o.enemy[ 1].name        = game_o.language.text.enemy_name_01;
        game_o.enemy[ 1].image       = texture.ship_001.ref_number;
        game_o.enemy[ 1].max_speed   = (game_o.projectile[game_o.enemy[ 1].weapon_1].speed/2) + game_o.enemy[ 1].max_speed;
        game_o.enemy[ 2].load("data/configuration/enemies/enemy_02.txt");
        game_o.enemy[ 2].name        = game_o.language.text.enemy_name_02;
        game_o.enemy[ 2].image       = texture.ship_002.ref_number;
        game_o.enemy[ 2].max_speed   = (game_o.projectile[game_o.enemy[ 2].weapon_1].speed/2) + game_o.enemy[ 2].max_speed;
        game_o.enemy[ 3].load("data/configuration/enemies/enemy_03.txt");
        game_o.enemy[ 3].name        = game_o.language.text.enemy_name_03;
        game_o.enemy[ 3].image       = texture.ship_003.ref_number;
        game_o.enemy[ 3].max_speed   = (game_o.projectile[game_o.enemy[ 3].weapon_1].speed/2) + game_o.enemy[ 3].max_speed;
        game_o.enemy[ 4].load("data/configuration/enemies/enemy_04.txt");
        game_o.enemy[ 4].name        = game_o.language.text.enemy_name_04;
        game_o.enemy[ 4].image       = texture.ship_004.ref_number;
        game_o.enemy[ 4].max_speed   = (game_o.projectile[game_o.enemy[ 4].weapon_1].speed/2) + game_o.enemy[ 4].max_speed;
        game_o.enemy[ 5].load("data/configuration/enemies/enemy_05.txt");
        game_o.enemy[ 5].name        = game_o.language.text.enemy_name_05;
        game_o.enemy[ 5].image       = texture.ship_005.ref_number;
        game_o.enemy[ 5].max_speed   = (game_o.projectile[game_o.enemy[ 5].weapon_1].speed/2) + game_o.enemy[ 5].max_speed;
        game_o.enemy[ 6].load("data/configuration/enemies/enemy_06.txt");
        game_o.enemy[ 6].name        = game_o.language.text.enemy_name_06;
        game_o.enemy[ 6].image       = texture.ship_006.ref_number;
        game_o.enemy[ 6].max_speed   = (game_o.projectile[game_o.enemy[ 6].weapon_1].speed/2) + game_o.enemy[ 6].max_speed;
        game_o.enemy[ 7].load("data/configuration/enemies/enemy_07.txt");
        game_o.enemy[ 7].name        = game_o.language.text.enemy_name_07;
        game_o.enemy[ 7].image       = texture.ship_007.ref_number;
        game_o.enemy[ 7].max_speed   = (game_o.projectile[game_o.enemy[ 7].weapon_1].speed/2) + game_o.enemy[ 7].max_speed;
        game_o.enemy[ 8].load("data/configuration/enemies/enemy_08.txt");
        game_o.enemy[ 8].name        = game_o.language.text.enemy_name_08;
        game_o.enemy[ 8].image       = texture.ship_008.ref_number;
        game_o.enemy[ 8].max_speed   = (game_o.projectile[game_o.enemy[ 8].weapon_1].speed/2) + game_o.enemy[ 8].max_speed;
        game_o.enemy[ 9].load("data/configuration/enemies/enemy_09.txt");
        game_o.enemy[ 9].name        = game_o.language.text.enemy_name_09;
        game_o.enemy[ 9].image       = texture.ship_009.ref_number;
        game_o.enemy[ 9].max_speed   = (game_o.projectile[game_o.enemy[ 9].weapon_1].speed/2) + game_o.enemy[ 9].max_speed;
        game_o.enemy[10].load("data/configuration/enemies/enemy_10.txt");
        game_o.enemy[10].name        = game_o.language.text.enemy_name_10;
        game_o.enemy[10].image       = texture.ship_010.ref_number;
        game_o.enemy[10].max_speed   = (game_o.projectile[game_o.enemy[10].weapon_1].speed/2) + game_o.enemy[10].max_speed;
        game_o.enemy[11].load("data/configuration/enemies/enemy_11.txt");
        game_o.enemy[11].name        = game_o.language.text.enemy_name_11;
        game_o.enemy[11].image       = texture.ship_011.ref_number;
        game_o.enemy[11].max_speed   = (game_o.projectile[game_o.enemy[11].weapon_1].speed/2) + game_o.enemy[11].max_speed;
        game_o.enemy[12].load("data/configuration/enemies/enemy_12.txt");
        game_o.enemy[12].name        = game_o.language.text.enemy_name_12;
        game_o.enemy[12].image       = texture.ship_012.ref_number;
        game_o.enemy[12].max_speed   = (game_o.projectile[game_o.enemy[12].weapon_1].speed/2) + game_o.enemy[12].max_speed;
        game_o.enemy[13].load("data/configuration/enemies/enemy_13.txt");
        game_o.enemy[13].name        = game_o.language.text.enemy_name_13;
        game_o.enemy[13].image       = texture.ship_013.ref_number;
        game_o.enemy[13].max_speed   = (game_o.projectile[game_o.enemy[13].weapon_1].speed/2) + game_o.enemy[13].max_speed;
        game_o.enemy[14].load("data/configuration/enemies/enemy_14.txt");
        game_o.enemy[14].name        = game_o.language.text.enemy_name_14;
        game_o.enemy[14].image       = texture.ship_014.ref_number;
        game_o.enemy[14].max_speed   = (game_o.projectile[game_o.enemy[14].weapon_1].speed/2) + game_o.enemy[14].max_speed;
        game_o.enemy[15].load("data/configuration/enemies/enemy_15.txt");
        game_o.enemy[15].name        = game_o.language.text.enemy_name_15;
        game_o.enemy[15].image       = texture.ship_015.ref_number;
        game_o.enemy[15].max_speed   = (game_o.projectile[game_o.enemy[15].weapon_1].speed/2) + game_o.enemy[15].max_speed;
        game_o.enemy[16].load("data/configuration/enemies/enemy_16.txt");
        game_o.enemy[16].name        = game_o.language.text.enemy_name_16;
        game_o.enemy[16].image       = texture.ship_016.ref_number;
        game_o.enemy[16].max_speed   = (game_o.projectile[game_o.enemy[16].weapon_1].speed/2) + game_o.enemy[16].max_speed;
        game_o.enemy[17].load("data/configuration/enemies/enemy_17.txt");
        game_o.enemy[17].name        = game_o.language.text.enemy_name_17;
        game_o.enemy[17].image       = texture.ship_017.ref_number;
        game_o.enemy[17].max_speed   = (game_o.projectile[game_o.enemy[17].weapon_1].speed/2) + game_o.enemy[17].max_speed;
        game_o.enemy[18].load("data/configuration/enemies/enemy_18.txt");
        game_o.enemy[18].name        = game_o.language.text.enemy_name_18;
        game_o.enemy[18].image       = texture.ship_018.ref_number;
        game_o.enemy[18].max_speed   = (game_o.projectile[game_o.enemy[18].weapon_1].speed/2) + game_o.enemy[18].max_speed;
        game_o.enemy[19].load("data/configuration/enemies/enemy_19.txt");
        game_o.enemy[19].name        = game_o.language.text.enemy_name_19;
        game_o.enemy[19].image       = texture.ship_019.ref_number;
        game_o.enemy[19].max_speed   = (game_o.projectile[game_o.enemy[19].weapon_1].speed/2) + game_o.enemy[19].max_speed;
        game_o.enemy[20].load("data/configuration/enemies/enemy_20.txt");
        game_o.enemy[20].name        = game_o.language.text.enemy_name_20;
        game_o.enemy[20].image       = texture.ship_020.ref_number;
        game_o.enemy[20].max_speed   = (game_o.projectile[game_o.enemy[20].weapon_1].speed/2) + game_o.enemy[20].max_speed;
        game_o.enemy[21].load("data/configuration/enemies/enemy_21.txt");
        game_o.enemy[21].name        = game_o.language.text.enemy_name_21;
        game_o.enemy[21].image       = texture.ship_021.ref_number;
        game_o.enemy[21].max_speed   = (game_o.projectile[game_o.enemy[21].weapon_1].speed/2) + game_o.enemy[21].max_speed;
        game_o.enemy[22].load("data/configuration/enemies/enemy_22.txt");
        game_o.enemy[22].name        = game_o.language.text.enemy_name_22;
        game_o.enemy[22].image       = texture.ship_002.ref_number;
        game_o.enemy[22].max_speed   = (game_o.projectile[game_o.enemy[22].weapon_1].speed/2) + game_o.enemy[22].max_speed;
        game_o.enemy[23].load("data/configuration/enemies/enemy_23.txt");
        game_o.enemy[23].name        = game_o.language.text.enemy_name_23;
        game_o.enemy[23].image       = texture.ship_023.ref_number;
        game_o.enemy[23].max_speed   = (game_o.projectile[game_o.enemy[23].weapon_1].speed/2) + game_o.enemy[23].max_speed;
        game_o.enemy[24].load("data/configuration/enemies/enemy_24.txt");
        game_o.enemy[24].name        = game_o.language.text.enemy_name_24;
        game_o.enemy[24].image       = texture.ship_024.ref_number;
        game_o.enemy[24].max_speed   = (game_o.projectile[game_o.enemy[24].weapon_1].speed/2) + game_o.enemy[24].max_speed;
    }
}

/*----------------------------------------------------------------------------*/
void init_active_npcs(void)
{
    for(int npc_count = 0; npc_count < MAX_NPCS; npc_count++)
    {
        game_o.active_npc[npc_count].number = -1;
        game_o.active_npc[npc_count].active = false;
    }
}
/*----------------------------------------------------------------------------*/
void check_active_npcs(void)
{
    for(int npc_count = 0; npc_count < MAX_NPCS; npc_count++)
    {
        if ((game_o.active_npc[npc_count].active) && (!game_o.npc[game_o.active_npc[npc_count].number].active)) game_o.active_npc[npc_count].active = false;
    }
}
/*----------------------------------------------------------------------------*/
void sort_active_npcs(void)
{
    check_active_npcs();
/*
    int  npc_num = 0;
    bool done = false;
    for(int npc_count = 0; npc_count < MAX_NPCS; npc_count++)
    {
        if (!game_o.active_npc[npc_count].active)
        {
            npc_num = npc_count;
            while ((npc_num < MAX_NPCS) && (!done))
            {
                game_o.active_npc[npc_num].active = game_o.active_npc[npc_num+1].active;
                game_o.active_npc[npc_num].number = game_o.active_npc[npc_num+1].number;
                npc_num++;
            }
        }
    }
    return(0);
*/
}
/*----------------------------------------------------------------------------*/
void add_active_npc  (int npc_num)
{
    bool spawn_done = 0;
    for  (int npc_count = 0; npc_count < MAX_NPCS; npc_count++)
    {
        if (!spawn_done && !game_o.active_npc[npc_count].active)
        {
            game_o.active_npc[npc_count].active  = true;
            game_o.active_npc[npc_count].number  = npc_num;
            game_o.active_npc_count++;
            spawn_done = 1;
        }
    }
}
/*----------------------------------------------------------------------------*/
void del_active_npc  (int npc_num)
{
    for(int npc_count = 0; npc_count < MAX_NPCS; npc_count++)
    {
        if (game_o.active_npc[npc_count].number == npc_num)
        {
            game_o.active_npc[npc_count].active  = false;
            game_o.active_npc[npc_count].number  = -1;
            game_o.active_npc_count--;
            if (game_o.active_npc_count < 0) game_o.active_npc_count = 0;
        }
    }
    sort_active_npcs();
}
/*----------------------------------------------------------------------------*/
void spawn_npc(float x_position, float y_position, int type_npc, int type_formation, float x_formation_ofset, float y_formation_ofset)
{
    bool  spawn_done = 0;
    for  (int npc_num = 0; npc_num < MAX_NPCS; npc_num++)
    {
        if (!spawn_done and !game_o.npc[npc_num].active)
        {
            game_o.npc[npc_num].active              = true;
            game_o.npc[npc_num].damaged             = 0;
            game_o.npc[npc_num].type_npc            = type_npc;
            game_o.npc[npc_num].x_pos               = x_position+game_o.enemy[game_o.npc[npc_num].type_npc].width;
            game_o.npc[npc_num].y_pos               = y_position;
            game_o.npc[npc_num].formation_wave_no   = get_next_active_wave();
            game_o.npc[npc_num].formation_wave_axis = y_position;
            game_o.npc[npc_num].formation_target    = game_o.player.y_pos;
            game_o.npc[npc_num].formation_type      = type_formation;
            game_o.npc[npc_num].formation_ofset_x   = x_formation_ofset;
            game_o.npc[npc_num].formation_ofset_y   = y_formation_ofset;
            game_o.npc[npc_num].weapon_1            = game_o.enemy[game_o.npc[npc_num].type_npc].weapon_1;
            game_o.npc[npc_num].weapon_2            = game_o.enemy[game_o.npc[npc_num].type_npc].weapon_2;
            game_o.npc[npc_num].projectiles         = game_o.enemy[game_o.npc[npc_num].type_npc].projectiles;
            game_o.npc[npc_num].health              = game_o.enemy[game_o.npc[npc_num].type_npc].health;
            game_o.npc[npc_num].width               = game_o.enemy[game_o.npc[npc_num].type_npc].width;
            game_o.npc[npc_num].height              = game_o.enemy[game_o.npc[npc_num].type_npc].height;
            game_o.npc[npc_num].x_speed             = game_o.enemy[game_o.npc[npc_num].type_npc].speed;
            game_o.npc[npc_num].y_speed             = game_o.enemy[game_o.npc[npc_num].type_npc].speed;
            game_o.npc[npc_num].max_speed           = game_o.enemy[game_o.npc[npc_num].type_npc].max_speed;
            game_o.npc[npc_num].acceleration        = game_o.enemy[game_o.npc[npc_num].type_npc].acceleration;
            game_o.npc[npc_num].angle               = game_o.enemy[game_o.npc[npc_num].type_npc].start_angle;
            game_o.npc[npc_num].movement            = game_o.enemy[game_o.npc[npc_num].type_npc].movement;
            game_o.npc[npc_num].x_direction         = 1;
            game_o.npc[npc_num].y_direction         = 1;
            spawn_done = 1;
            add_active_npc(npc_num);
        }
    }
}
/*----------------------------------------------------------------------------*/
void kill_npc(int npc_num)
{
    game_o.npc[npc_num].active     = false;
    game_o.npc[npc_num].x_pos      = -2.0f;
    game_o.npc[npc_num].y_pos      = -2.0f;
    del_active_npc(npc_num);
}
/*----------------------------------------------------------------------------*/
void kill_active_npcs(void)
{
    for (int npc_count = 0; npc_count < MAX_NPCS; npc_count++) //kill all npcs
    {
        if (game_o.npc[npc_count].active) kill_npc(npc_count);
    }
}
/*----------------------------------------------------------------------------*/
void init_npcs(int type_npc)
{
    for (int npc_count = 0; npc_count < MAX_NPCS; npc_count++)
    {
        game_o.npc[npc_count].active              = false;
        game_o.npc[npc_count].damaged             = 0;
        game_o.npc[npc_count].type_npc            = type_npc;
        game_o.npc[npc_count].x_pos               = -2.0f;
        game_o.npc[npc_count].y_pos               = -2.0f;
        game_o.npc[npc_count].formation_wave_axis = 0.0f;
        game_o.npc[npc_count].formation_wave_no   = 0;
        game_o.npc[npc_count].formation_type      = 0;
        game_o.npc[npc_count].formation_ofset_x   = 0.0f;
        game_o.npc[npc_count].formation_ofset_y   = 0.0f;
        game_o.npc[npc_count].weapon_1            = game_o.enemy[game_o.npc[npc_count].type_npc].weapon_1;
        game_o.npc[npc_count].weapon_2            = game_o.enemy[game_o.npc[npc_count].type_npc].weapon_2;
        game_o.npc[npc_count].projectiles         = game_o.enemy[game_o.npc[npc_count].type_npc].projectiles;
        game_o.npc[npc_count].health              = game_o.enemy[game_o.npc[npc_count].type_npc].health;
        game_o.npc[npc_count].width               = game_o.enemy[game_o.npc[npc_count].type_npc].width;
        game_o.npc[npc_count].height              = game_o.enemy[game_o.npc[npc_count].type_npc].height;
        game_o.npc[npc_count].x_speed             = game_o.enemy[game_o.npc[npc_count].type_npc].speed;
        game_o.npc[npc_count].y_speed             = game_o.enemy[game_o.npc[npc_count].type_npc].speed;
        game_o.npc[npc_count].max_speed           = game_o.enemy[game_o.npc[npc_count].type_npc].max_speed;
        game_o.npc[npc_count].acceleration        = game_o.enemy[game_o.npc[npc_count].type_npc].acceleration;
        game_o.npc[npc_count].angle               = game_o.enemy[game_o.npc[npc_count].type_npc].start_angle;
        game_o.npc[npc_count].movement            = game_o.enemy[game_o.npc[npc_count].type_npc].movement;
        game_o.npc[npc_count].x_direction         = 1;
        game_o.npc[npc_count].y_direction         = 1;
    }
    init_npc_bullets();
    init_npc_bullets2();
}

/*----------------------------------------------------------------------------*/
void proccess_npcs(void)
{
    float temp_angle = 0.0f;
    for (int npc_count = 0; npc_count < MAX_NPCS; npc_count++)
    {
        if  (game_o.npc[npc_count].damaged > 0) game_o.npc[npc_count].damaged--;
        else game_o.npc[npc_count].damaged = 0;
        if (game_o.npc[npc_count].active)
        {
            game_o.npc[npc_count].x_speed += game_o.npc[npc_count].acceleration;
            if (game_o.npc[npc_count].x_speed > game_o.npc[npc_count].max_speed) game_o.npc[npc_count].x_speed = game_o.npc[npc_count].max_speed;
            game_o.npc[npc_count].y_speed += game_o.npc[npc_count].acceleration;
            if (game_o.npc[npc_count].y_speed > game_o.npc[npc_count].max_speed) game_o.npc[npc_count].y_speed = game_o.npc[npc_count].max_speed;
            if (game_o.npc[npc_count].movement == 0)//straight line from right to left (depending on enemy angle)
            {
                temp_angle = game.physics.degrees_to_radians(game_o.npc[npc_count].angle);
                game_o.npc[npc_count].x_pos = game.physics.move_speed_angle_2D_x(game_o.npc[npc_count].x_pos,game_o.npc[npc_count].x_speed,temp_angle);
                game_o.npc[npc_count].y_pos = game.physics.move_speed_angle_2D_y(game_o.npc[npc_count].y_pos,game_o.npc[npc_count].y_speed,temp_angle);
                if (game_o.npc[npc_count].x_pos < -1.0f-game_o.npc[npc_count].width) kill_npc(npc_count);
            }
            if (game_o.npc[npc_count].movement == 1)//home in on player
            {
                temp_angle = game.physics.line_angle(game_o.player.x_pos,game_o.player.y_pos,game_o.npc[npc_count].x_pos,game_o.npc[npc_count].y_pos);
                temp_angle = game.physics.radians_to_degrees(temp_angle);
                if (temp_angle <   0.0f) temp_angle += 360.0f;
                if (temp_angle > 360.0f) temp_angle -= 360.0f;
                temp_angle = 270.0f - temp_angle;
                if (temp_angle <   0.0f) temp_angle += 360.0f;
                if (temp_angle > 360.0f) temp_angle -= 360.0f;
                game_o.npc[npc_count].angle = temp_angle;
                temp_angle = game.physics.degrees_to_radians(temp_angle);
                game_o.npc[npc_count].x_pos = game.physics.move_speed_angle_2D_x(game_o.npc[npc_count].x_pos,game_o.npc[npc_count].x_speed,temp_angle);
                game_o.npc[npc_count].y_pos = game.physics.move_speed_angle_2D_y(game_o.npc[npc_count].y_pos,game_o.npc[npc_count].y_speed,temp_angle);
                if (game_o.npc[npc_count].x_pos < -1.0f-game_o.npc[npc_count].width) kill_npc(npc_count);
            }
            if (game_o.npc[npc_count].movement == 2)// move up and down,avoid player and stay far right
            {
                game_o.npc[npc_count].x_pos -= game_o.npc[npc_count].x_speed;
                if (game_o.npc[npc_count].x_pos < ((1.0f) - (game_o.npc[npc_count].width/2))) game_o.npc[npc_count].x_pos = ((1.0f)- (game_o.npc[npc_count].width/2));
                if (((game_o.player.y_pos + (game_o.player.height/2)) > (game_o.npc[npc_count].y_pos - (game_o.npc[npc_count].height/2))) && ((game_o.player.y_pos - (game_o.player.height/2)) < (game_o.npc[npc_count].y_pos + (game_o.npc[npc_count].height/2))))
                {
                    if (game_o.npc[npc_count].y_pos > game_o.player.y_pos) game_o.npc[npc_count].y_pos += game_o.npc[npc_count].y_speed;
                    if (game_o.npc[npc_count].y_pos < game_o.player.y_pos) game_o.npc[npc_count].y_pos -= game_o.npc[npc_count].y_speed;
                }
                else
                {
                    if (game_o.npc[npc_count].y_direction ==  1) game_o.npc[npc_count].y_pos -= game_o.npc[npc_count].y_speed;
                    if (game_o.npc[npc_count].y_direction == -1) game_o.npc[npc_count].y_pos += game_o.npc[npc_count].y_speed;
                }
                if ((game_o.npc[npc_count].y_pos - (game_o.npc[npc_count].height/2)) < -1.0f)
                {
                    game_o.npc[npc_count].y_pos = ((-1.0f) + (game_o.npc[npc_count].height/2));
                    game_o.npc[npc_count].y_direction *= -1;
                }
                if ((game_o.npc[npc_count].y_pos + (game_o.npc[npc_count].height/2)) >  1.0f)
                {
                    game_o.npc[npc_count].y_pos = (( 1.0f) - (game_o.npc[npc_count].height/2));
                    game_o.npc[npc_count].y_direction *= -1;
                }
                if (game_o.npc[npc_count].x_pos < -1.0f-game_o.npc[npc_count].width) game_o.npc[npc_count].x_pos = 1.0f+game_o.npc[npc_count].width;
            }
            if (game_o.npc[npc_count].movement == 3)// avoid player till border then home in on player
            {
                game_o.npc[npc_count].x_pos -= game_o.npc[npc_count].x_speed;
                if (game_o.npc[npc_count].x_pos < -1.0f-game_o.npc[npc_count].width) kill_npc(npc_count);
                if ((game_o.npc[npc_count].y_pos-game_o.npc[npc_count].formation_ofset_y) > game_o.player.y_pos) game_o.npc[npc_count].y_pos += game_o.npc[npc_count].y_speed;
                if ((game_o.npc[npc_count].y_pos-game_o.npc[npc_count].formation_ofset_y) < game_o.player.y_pos) game_o.npc[npc_count].y_pos -= game_o.npc[npc_count].y_speed;
                if (((game_o.npc[npc_count].y_pos-game_o.npc[npc_count].formation_ofset_y) - (game_o.npc[npc_count].height/2)) < -1.0f) game_o.npc[npc_count].movement = 1;
                if (((game_o.npc[npc_count].y_pos-game_o.npc[npc_count].formation_ofset_y) + (game_o.npc[npc_count].height/2)) >  1.0f) game_o.npc[npc_count].movement = 1;
            }
            if (game_o.npc[npc_count].movement == 4)// home in on player and then move to border
            {
                game_o.npc[npc_count].x_pos -= game_o.npc[npc_count].x_speed;
                if (game_o.npc[npc_count].x_pos <  -1.0f-game_o.npc[npc_count].width) kill_npc(npc_count);
                if ((game_o.npc[npc_count].y_pos-game_o.npc[npc_count].formation_ofset_y) <  game_o.player.y_pos) game_o.npc[npc_count].y_pos += game_o.npc[npc_count].y_speed;
                if ((game_o.npc[npc_count].y_pos-game_o.npc[npc_count].formation_ofset_y) >  game_o.player.y_pos) game_o.npc[npc_count].y_pos -= game_o.npc[npc_count].y_speed;
                if (((game_o.npc[npc_count].y_pos-game_o.npc[npc_count].formation_ofset_y) <= (game_o.player.y_pos+game_o.player.height)) && ((game_o.npc[npc_count].y_pos-game_o.npc[npc_count].formation_ofset_y) >= (game_o.player.y_pos-game_o.player.height))) game_o.npc[npc_count].movement = 3;
            }
            if (game_o.npc[npc_count].movement == 5)// move in an oscillating sine wave
            {
                game_o.npc[npc_count].x_pos -= game_o.npc[npc_count].x_speed;
                if (game_o.npc[npc_count].x_pos <  -1.0f-game_o.npc[npc_count].width) kill_npc(npc_count);
                if (game_o.npc[npc_count].y_direction ==  1) game_o.npc[npc_count].y_pos -= game_o.npc[npc_count].y_speed;
                if (game_o.npc[npc_count].y_direction == -1) game_o.npc[npc_count].y_pos += game_o.npc[npc_count].y_speed;
                if ((game_o.npc[npc_count].y_pos - (game_o.npc[npc_count].height/2)) < (game_o.npc[npc_count].formation_wave_axis - game_o.level[game_o.current_level].wave[game_o.npc[npc_count].formation_wave_no].wave_size)) game_o.npc[npc_count].y_direction *= -1;
                if ((game_o.npc[npc_count].y_pos + (game_o.npc[npc_count].height/2)) > (game_o.npc[npc_count].formation_wave_axis + game_o.level[game_o.current_level].wave[game_o.npc[npc_count].formation_wave_no].wave_size)) game_o.npc[npc_count].y_direction *= -1;
            }
            if (game_o.npc[npc_count].movement == 6)// move in a faster oscillating sine wave
            {
                game_o.npc[npc_count].x_pos -= game_o.npc[npc_count].x_speed;
                if (game_o.npc[npc_count].x_pos <  -1.0f-game_o.npc[npc_count].width) kill_npc(npc_count);
                if (game_o.npc[npc_count].y_direction ==  1) game_o.npc[npc_count].y_pos -= game_o.npc[npc_count].y_speed*2;
                if (game_o.npc[npc_count].y_direction == -1) game_o.npc[npc_count].y_pos += game_o.npc[npc_count].y_speed*2;
                if ((game_o.npc[npc_count].y_pos - (game_o.npc[npc_count].height/2)) < (game_o.npc[npc_count].formation_wave_axis - game_o.level[game_o.current_level].wave[game_o.npc[npc_count].formation_wave_no].wave_size)) game_o.npc[npc_count].y_direction *= -1;
                if ((game_o.npc[npc_count].y_pos + (game_o.npc[npc_count].height/2)) > (game_o.npc[npc_count].formation_wave_axis + game_o.level[game_o.current_level].wave[game_o.npc[npc_count].formation_wave_no].wave_size)) game_o.npc[npc_count].y_direction *= -1;
            }
            if (game_o.npc[npc_count].movement == 7)// home in on position player was in when spawned
            {
                game_o.npc[npc_count].x_pos -= game_o.npc[npc_count].x_speed;
                if (game_o.npc[npc_count].x_pos <  -1.0f-game_o.npc[npc_count].width) kill_npc(npc_count);
                if ((game_o.npc[npc_count].y_pos-game_o.npc[npc_count].formation_ofset_y) < game_o.npc[npc_count].formation_target) game_o.npc[npc_count].y_pos += game_o.npc[npc_count].y_speed;
                if ((game_o.npc[npc_count].y_pos-game_o.npc[npc_count].formation_ofset_y) > game_o.npc[npc_count].formation_target) game_o.npc[npc_count].y_pos -= game_o.npc[npc_count].y_speed;
            }
            if (game_o.npc[npc_count].movement == 8)// move in an oscillating sine wave and stay far right
            {
                game_o.npc[npc_count].x_pos -= game_o.npc[npc_count].x_speed;
                if (game_o.npc[npc_count].x_pos < ((1.0f) - (game_o.npc[npc_count].width/2))) game_o.npc[npc_count].x_pos = ((1.0f)- (game_o.npc[npc_count].width/2));
                if (game_o.npc[npc_count].y_direction ==  1) game_o.npc[npc_count].y_pos -= game_o.npc[npc_count].y_speed;
                if (game_o.npc[npc_count].y_direction == -1) game_o.npc[npc_count].y_pos += game_o.npc[npc_count].y_speed;
                if ((game_o.npc[npc_count].y_pos) < (-1.0f + (game_o.npc[npc_count].height/2)))
                {
                    game_o.npc[npc_count].y_pos = (-1.0f + (game_o.npc[npc_count].height/2));
                    game_o.npc[npc_count].y_direction *= -1;
                }
                if ((game_o.npc[npc_count].y_pos) > ( 1.0f - (game_o.npc[npc_count].height/2)))
                {
                    game_o.npc[npc_count].y_pos = ( 1.0f - (game_o.npc[npc_count].height/2));
                    game_o.npc[npc_count].y_direction *= -1;
                }
            }
        }
    }
    proccess_npc_bullets();
    proccess_npc_bullets2();
}

/*----------------------------------------------------------------------------*/
int spawn_npc_bullet_num(int npc_num, int npc_bullet_num, int location)
{
   if (npc_bullet_num > MAX_BULLETS) npc_bullet_num    = MAX_BULLETS;
   game_o.npc[npc_num].bullet[npc_bullet_num].active   = true;
   game_o.npc[npc_num].bullet[npc_bullet_num].angle    = game_o.npc[npc_num].angle;
   game_o.npc[npc_num].bullet[npc_bullet_num].location = location;
   game_o.npc[npc_num].bullet[npc_bullet_num].warhead  = game_o.npc[npc_num].weapon_1;
   if (location == 0) game_o.npc[npc_num].bullet[npc_bullet_num].x_pos = (game_o.npc[npc_num].x_pos - (game_o.npc[npc_num].width/3));  // 1   straight - top
   if (location == 1) game_o.npc[npc_num].bullet[npc_bullet_num].x_pos = (game_o.npc[npc_num].x_pos - (game_o.npc[npc_num].width/2));  //  2  straight - mid
   if (location == 2) game_o.npc[npc_num].bullet[npc_bullet_num].x_pos = (game_o.npc[npc_num].x_pos - (game_o.npc[npc_num].width/3));  //   3 straight - bot
   if (location == 3) game_o.npc[npc_num].bullet[npc_bullet_num].x_pos = (game_o.npc[npc_num].x_pos - (game_o.npc[npc_num].width/2));  // 1   down     - top
   if (location == 4) game_o.npc[npc_num].bullet[npc_bullet_num].x_pos = (game_o.npc[npc_num].x_pos - (game_o.npc[npc_num].width/4));  //  2  down     - mid
   if (location == 5) game_o.npc[npc_num].bullet[npc_bullet_num].x_pos = (game_o.npc[npc_num].x_pos - (game_o.npc[npc_num].width/5));  //   3 down     - bot
   if (location == 6) game_o.npc[npc_num].bullet[npc_bullet_num].x_pos = (game_o.npc[npc_num].x_pos - (game_o.npc[npc_num].width/5));  // 1   up       - top
   if (location == 7) game_o.npc[npc_num].bullet[npc_bullet_num].x_pos = (game_o.npc[npc_num].x_pos - (game_o.npc[npc_num].width/4));  //  2  up       - mid
   if (location == 8) game_o.npc[npc_num].bullet[npc_bullet_num].x_pos = (game_o.npc[npc_num].x_pos - (game_o.npc[npc_num].width/2));  //   3 up       - bot

   if (location == 0) game_o.npc[npc_num].bullet[npc_bullet_num].y_pos = (game_o.npc[npc_num].y_pos + (game_o.npc[npc_num].height/3));  // 1   straight - top
   if (location == 1) game_o.npc[npc_num].bullet[npc_bullet_num].y_pos = (game_o.npc[npc_num].y_pos);                                //  2  straight - mid
   if (location == 2) game_o.npc[npc_num].bullet[npc_bullet_num].y_pos = (game_o.npc[npc_num].y_pos - (game_o.npc[npc_num].height/3));  //   3 straight - bot
   if (location == 3) game_o.npc[npc_num].bullet[npc_bullet_num].y_pos = (game_o.npc[npc_num].y_pos + (game_o.npc[npc_num].height/2));  // 1   down     - top
   if (location == 4) game_o.npc[npc_num].bullet[npc_bullet_num].y_pos = (game_o.npc[npc_num].y_pos + (game_o.npc[npc_num].height/5));  //  2  down     - mid
   if (location == 5) game_o.npc[npc_num].bullet[npc_bullet_num].y_pos = (game_o.npc[npc_num].y_pos - (game_o.npc[npc_num].height/4));  //   3 down     - bot
   if (location == 6) game_o.npc[npc_num].bullet[npc_bullet_num].y_pos = (game_o.npc[npc_num].y_pos + (game_o.npc[npc_num].height/4));  // 1   up       - top
   if (location == 7) game_o.npc[npc_num].bullet[npc_bullet_num].y_pos = (game_o.npc[npc_num].y_pos - (game_o.npc[npc_num].height/5));  //  2  up       - mid
   if (location == 8) game_o.npc[npc_num].bullet[npc_bullet_num].y_pos = (game_o.npc[npc_num].y_pos - (game_o.npc[npc_num].height/2));  //   3 up       - bot

   switch (game_o.projectile[game_o.npc[npc_num].bullet[npc_bullet_num].warhead].movement)
      {
         case 0: //straight
            game_o.npc[npc_num].bullet[npc_bullet_num].straight       = true;
            game_o.npc[npc_num].bullet[npc_bullet_num].homeing_00     = false;
            game_o.npc[npc_num].bullet[npc_bullet_num].homeing_01     = false;
            game_o.npc[npc_num].bullet[npc_bullet_num].wave           = false;
            game_o.npc[npc_num].bullet[npc_bullet_num].wave_height    = 0.0f;
            game_o.npc[npc_num].bullet[npc_bullet_num].wave_count     = 0.0f;
            game_o.npc[npc_num].bullet[npc_bullet_num].wave_speed     = 0.0f;
            game_o.npc[npc_num].bullet[npc_bullet_num].wave_direction = true;
         break;
         case 1: //homeing
            game_o.npc[npc_num].bullet[npc_bullet_num].straight       = false;
            game_o.npc[npc_num].bullet[npc_bullet_num].homeing_00     = true;
            game_o.npc[npc_num].bullet[npc_bullet_num].homeing_01     = false;
            game_o.npc[npc_num].bullet[npc_bullet_num].wave           = false;
            game_o.npc[npc_num].bullet[npc_bullet_num].wave_height    = 0.0f;
            game_o.npc[npc_num].bullet[npc_bullet_num].wave_count     = 0.0f;
            game_o.npc[npc_num].bullet[npc_bullet_num].wave_speed     = 0.0f;
            game_o.npc[npc_num].bullet[npc_bullet_num].wave_direction = true;
         break;
         case 2: //wave
            game_o.npc[npc_num].bullet[npc_bullet_num].straight       = false;
            game_o.npc[npc_num].bullet[npc_bullet_num].homeing_00     = false;
            game_o.npc[npc_num].bullet[npc_bullet_num].homeing_01     = false;
            game_o.npc[npc_num].bullet[npc_bullet_num].wave           = true;
            game_o.npc[npc_num].bullet[npc_bullet_num].wave_height    = game_o.projectile[game_o.npc[npc_num].bullet[npc_bullet_num].warhead].wave_size;
            game_o.npc[npc_num].bullet[npc_bullet_num].wave_count     = 0.0f;
            game_o.npc[npc_num].bullet[npc_bullet_num].wave_speed     = game_o.projectile[game_o.npc[npc_num].bullet[npc_bullet_num].warhead].wave_velocity;
            game_o.npc[npc_num].bullet[npc_bullet_num].wave_direction = 1;
         break;
         case 3: //super homeing
            game_o.npc[npc_num].bullet[npc_bullet_num].straight       = false;
            game_o.npc[npc_num].bullet[npc_bullet_num].homeing_00     = false;
            game_o.npc[npc_num].bullet[npc_bullet_num].homeing_01     = true;
            game_o.npc[npc_num].bullet[npc_bullet_num].wave           = false;
            game_o.npc[npc_num].bullet[npc_bullet_num].wave_height    = game_o.projectile[game_o.npc[npc_num].bullet[npc_bullet_num].warhead].wave_size;
            game_o.npc[npc_num].bullet[npc_bullet_num].wave_count     = 0.0f;
            game_o.npc[npc_num].bullet[npc_bullet_num].wave_speed     = game_o.projectile[game_o.npc[npc_num].bullet[npc_bullet_num].warhead].wave_velocity;
            game_o.npc[npc_num].bullet[npc_bullet_num].wave_direction = 1;
         break;
         case 4: //homeing wave
            game_o.npc[npc_num].bullet[npc_bullet_num].straight       = false;
            game_o.npc[npc_num].bullet[npc_bullet_num].homeing_00     = true;
            game_o.npc[npc_num].bullet[npc_bullet_num].homeing_01     = false;
            game_o.npc[npc_num].bullet[npc_bullet_num].wave           = true;
            game_o.npc[npc_num].bullet[npc_bullet_num].wave_height    = game_o.projectile[game_o.npc[npc_num].bullet[npc_bullet_num].warhead].wave_size;
            game_o.npc[npc_num].bullet[npc_bullet_num].wave_count     = 0.0f;
            game_o.npc[npc_num].bullet[npc_bullet_num].wave_speed     = game_o.projectile[game_o.npc[npc_num].bullet[npc_bullet_num].warhead].wave_velocity;
            game_o.npc[npc_num].bullet[npc_bullet_num].wave_direction = 1;
         break;
         default://straight
            game_o.npc[npc_num].bullet[npc_bullet_num].straight       = true;
            game_o.npc[npc_num].bullet[npc_bullet_num].homeing_00     = false;
            game_o.npc[npc_num].bullet[npc_bullet_num].homeing_01     = false;
            game_o.npc[npc_num].bullet[npc_bullet_num].wave           = false;
            game_o.npc[npc_num].bullet[npc_bullet_num].wave_height    = 0.0f;
            game_o.npc[npc_num].bullet[npc_bullet_num].wave_count     = 0.0f;
            game_o.npc[npc_num].bullet[npc_bullet_num].wave_speed     = 0.0f;
            game_o.npc[npc_num].bullet[npc_bullet_num].wave_direction = true;
        break;
      }
   return(0);
}
/*----------------------------------------------------------------------------*/
int spawn_npc_bullet(int npc_num, int location)
{
   bool spawn_done = 0;
   for (int npc_bullet_num = 0; npc_bullet_num < MAX_BULLETS; npc_bullet_num++)
   {
       if (!spawn_done and !game_o.npc[npc_num].bullet[npc_bullet_num].active)
       {
           spawn_npc_bullet_num(npc_num,npc_bullet_num,location);
           spawn_done = 1;
       }
   }
 return(0);
}
/*----------------------------------------------------------------------------*/
int kill_npc_bullet(int npc_num, int npc_bullet_num)
{
  if (npc_bullet_num > MAX_BULLETS) npc_bullet_num   = MAX_BULLETS;
  game_o.npc[npc_num].bullet[npc_bullet_num].active  = false;
  game_o.npc[npc_num].bullet[npc_bullet_num].x_pos   = -2.0f;
  game_o.npc[npc_num].bullet[npc_bullet_num].y_pos   = -2.0f;
  return npc_bullet_num;
}
/*----------------------------------------------------------------------------*/
int init_npc_bullets(void)
{
    for (int npc_count = 0; npc_count < MAX_NPCS; npc_count++)
    {
        for (int bullet_count = 0; bullet_count < MAX_BULLETS; bullet_count++)
        {
            game_o.npc[npc_count].bullet[bullet_count].active          = false;
            game_o.npc[npc_count].bullet[bullet_count].x_pos           = -2.0f;
            game_o.npc[npc_count].bullet[bullet_count].y_pos           = -2.0f;
            game_o.npc[npc_count].bullet[bullet_count].max_speed       = game_o.enemy[game_o.npc[npc_count].type_npc].speed;
            game_o.npc[npc_count].bullet[bullet_count].x_speed         = game_o.npc[npc_count].bullet[bullet_count].max_speed;
            game_o.npc[npc_count].bullet[bullet_count].y_speed         = game_o.npc[npc_count].bullet[bullet_count].max_speed;
            game_o.npc[npc_count].bullet[bullet_count].acceleration    = 0.0f;
            game_o.npc[npc_count].bullet[bullet_count].angle           = game_o.enemy[game_o.npc[npc_count].type_npc].start_angle;
            game_o.npc[npc_count].bullet[bullet_count].width           = 0.05f;
            game_o.npc[npc_count].bullet[bullet_count].height          = 0.05f;
            game_o.npc[npc_count].bullet[bullet_count].warhead         = game_o.enemy[game_o.npc[npc_count].type_npc].weapon_1;
            game_o.npc[npc_count].bullet[bullet_count].location        = 0;
        }
    }
    return(0);
}
/*----------------------------------------------------------------------------*/
int proccess_npc_bullets(void)
{
    float temp_angle = 0.0f;
    for (int npc_count = 0; npc_count < MAX_NPCS; npc_count++)
    {
        for (int bullet_count = 0; bullet_count < MAX_BULLETS; bullet_count++)
        {
            if (game_o.npc[npc_count].bullet[bullet_count].active)
            {
                if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].movement == 0) //bullet moves in a "straight" line (dependent on angle)
                {
                    if (game_o.npc[npc_count].bullet[bullet_count].location == 5) temp_angle =  264.0f;
                    if (game_o.npc[npc_count].bullet[bullet_count].location == 4) temp_angle =  266.0f;
                    if (game_o.npc[npc_count].bullet[bullet_count].location == 3) temp_angle =  268.0f;
                    if (game_o.npc[npc_count].bullet[bullet_count].location == 2) temp_angle =  270.0f;
                    if (game_o.npc[npc_count].bullet[bullet_count].location == 1) temp_angle =  270.0f;
                    if (game_o.npc[npc_count].bullet[bullet_count].location == 0) temp_angle =  270.0f;
                    if (game_o.npc[npc_count].bullet[bullet_count].location == 8) temp_angle =  272.0f;
                    if (game_o.npc[npc_count].bullet[bullet_count].location == 7) temp_angle =  274.0f;
                    if (game_o.npc[npc_count].bullet[bullet_count].location == 6) temp_angle =  276.0f;
                    temp_angle -= 270.0f;
                    temp_angle += game_o.npc[npc_count].bullet[bullet_count].angle;
                    temp_angle = game.physics.degrees_to_radians(temp_angle);
                    game_o.npc[npc_count].bullet[bullet_count].x_pos = game.physics.move_speed_angle_2D_x(game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].speed,temp_angle);
                    game_o.npc[npc_count].bullet[bullet_count].y_pos = game.physics.move_speed_angle_2D_y(game_o.npc[npc_count].bullet[bullet_count].y_pos,game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].speed,temp_angle);
                }
                if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].movement == 1) //bullet homes in on player
                {
                    temp_angle = game.physics.line_angle(game_o.player.x_pos,game_o.player.y_pos,game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos);
                    temp_angle = game.physics.radians_to_degrees(temp_angle);
                    if (temp_angle <   0.0f) temp_angle += 360.0f;
                    if (temp_angle > 360.0f) temp_angle -= 360.0f;
                    temp_angle = 270.0f - temp_angle;
                    if (temp_angle <   0.0f) temp_angle += 360.0f;
                    if (temp_angle > 360.0f) temp_angle -= 360.0f;
                    game_o.npc[npc_count].bullet[bullet_count].angle = temp_angle;
                    temp_angle = game.physics.degrees_to_radians(temp_angle);
                    game_o.npc[npc_count].bullet[bullet_count].x_pos = game.physics.move_speed_angle_2D_x(game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].speed,temp_angle);
                    game_o.npc[npc_count].bullet[bullet_count].y_pos = game.physics.move_speed_angle_2D_y(game_o.npc[npc_count].bullet[bullet_count].y_pos,game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].speed,temp_angle);
                }
                if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].movement == 2) //bullet moves in a wave pattern
                {
                    if (game_o.npc[npc_count].bullet[bullet_count].active) game_o.npc[npc_count].bullet[bullet_count].x_pos -= game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].speed;
                    game_o.npc[npc_count].bullet[bullet_count].wave_count += game_o.npc[npc_count].bullet[bullet_count].wave_speed;
                    if (game_o.npc[npc_count].bullet[bullet_count].wave_count >= game_o.npc[npc_count].bullet[bullet_count].wave_height)
                    {
                        game_o.npc[npc_count].bullet[bullet_count].wave_count = 0.0f;
                        game_o.npc[npc_count].bullet[bullet_count].wave_direction = !game_o.npc[npc_count].bullet[bullet_count].wave_direction;
                    }
                    if (game_o.npc[npc_count].bullet[bullet_count].wave_direction == true) game_o.npc[npc_count].bullet[bullet_count].y_pos += game_o.npc[npc_count].bullet[bullet_count].wave_speed;
                    else game_o.npc[npc_count].bullet[bullet_count].y_pos -= game_o.npc[npc_count].bullet[bullet_count].wave_speed;
                }
                if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].movement == 3) //bullet super homes in on player
                {
                    if (game_o.npc[npc_count].bullet[bullet_count].active)
                    {
                        if (game_o.npc[npc_count].bullet[bullet_count].y_pos > game_o.player.y_pos) game_o.npc[npc_count].bullet[bullet_count].y_pos -= (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].speed/2);
                        if (game_o.npc[npc_count].bullet[bullet_count].y_pos < game_o.player.y_pos) game_o.npc[npc_count].bullet[bullet_count].y_pos += (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].speed/2);
                        if (game_o.npc[npc_count].bullet[bullet_count].x_pos > game_o.player.x_pos) game_o.npc[npc_count].bullet[bullet_count].x_pos -= (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].speed/2);
                        if (game_o.npc[npc_count].bullet[bullet_count].x_pos < game_o.player.x_pos) game_o.npc[npc_count].bullet[bullet_count].x_pos += (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].speed/2);
                    }
                }
         if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].movement == 4) //bullet homes in on player and moves in a wave pattern
         {
            if (game_o.npc[npc_count].bullet[bullet_count].active) game_o.npc[npc_count].bullet[bullet_count].x_pos -= game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].speed;
            if (game_o.npc[npc_count].bullet[bullet_count].active)
            {
                if (game_o.npc[npc_count].bullet[bullet_count].x_pos > game_o.player.x_pos)
                {
                   if (game_o.npc[npc_count].bullet[bullet_count].y_pos > (game_o.player.y_pos+(game_o.player.height/2))) game_o.npc[npc_count].bullet[bullet_count].y_pos -= (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].speed/2);
                   if (game_o.npc[npc_count].bullet[bullet_count].y_pos < (game_o.player.y_pos-(game_o.player.height/2))) game_o.npc[npc_count].bullet[bullet_count].y_pos += (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].speed/2);
                }
                game_o.npc[npc_count].bullet[bullet_count].wave_count += game_o.npc[npc_count].bullet[bullet_count].wave_speed;
                if (game_o.npc[npc_count].bullet[bullet_count].wave_count >= game_o.npc[npc_count].bullet[bullet_count].wave_height)
                {
                   game_o.npc[npc_count].bullet[bullet_count].wave_count = 0.0f;
                   game_o.npc[npc_count].bullet[bullet_count].wave_direction = !game_o.npc[npc_count].bullet[bullet_count].wave_direction;
                }
                if (game_o.npc[npc_count].bullet[bullet_count].wave_direction == true) game_o.npc[npc_count].bullet[bullet_count].y_pos += game_o.npc[npc_count].bullet[bullet_count].wave_speed;
                else game_o.npc[npc_count].bullet[bullet_count].y_pos -= game_o.npc[npc_count].bullet[bullet_count].wave_speed;
            }
         }
         if (game_o.npc[npc_count].bullet[bullet_count].x_pos < (-1.0f - game_o.npc[npc_count].bullet[bullet_count].width)) kill_npc_bullet(npc_count,bullet_count);
         // check player starship / npc bullet collisions...
         if ((game.physics.quadrangle_collision(game_o.player.x_pos,game_o.player.y_pos,game_o.player.width,game_o.player.height,game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,game_o.npc[npc_count].bullet[bullet_count].width,game_o.npc[npc_count].bullet[bullet_count].height)) && (!game_o.immune))
         {
            spawn_explosion(game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,0.125f);
            kill_npc_bullet(npc_count,bullet_count);
            sound.shield_hit.play();//player shield hit
            game_o.player.shield -= (0.005f+game_o.shield[game_o.player.front_shield].absorption+(0.0001f*game_o.shield[game_o.player.front_shield].level));
            if (game_o.player.shield < 0.0f) game_o.player.health += game_o.player.shield;
            if ((game_o.shield[game_o.player.front_shield].level <= 2) && (game_o.player.front_shield >= 0))
            {
                game_o.shield[game_o.player.front_shield].experience++;
                if (game_o.shield[game_o.player.front_shield].level == 0)
                {
                    if (game_o.shield[game_o.player.front_shield].experience >= game_o.shield[game_o.player.front_shield].level_1)
                    {
                       game_o.p_shield_level_up.spawn();
                       game_o.shield[game_o.player.front_shield].experience = 0;
                       game_o.shield[game_o.player.front_shield].level++;
                    }
                }
                if (game_o.shield[game_o.player.front_shield].level == 1)
                {
                    if (game_o.shield[game_o.player.front_shield].experience >= game_o.shield[game_o.player.front_shield].level_2)
                    {
                       game_o.p_shield_level_up.spawn();
                       game_o.shield[game_o.player.front_shield].experience = 0;
                       game_o.shield[game_o.player.front_shield].level++;
                    }
                }
                if (game_o.shield[game_o.player.front_shield].level == 2)
                {
                    if (game_o.shield[game_o.player.front_shield].experience >= game_o.shield[game_o.player.front_shield].level_3)
                    {
                       game_o.p_shield_level_up.spawn();
                       game_o.shield[game_o.player.front_shield].experience = 0;
                       game_o.shield[game_o.player.front_shield].level++;
                    }
                }
            }
         }
      }
   }
   }
   return(0);
}
/*----------------------------------------------------------------------------*/


int  init_npc_bullets2    (void)
{
   for (int npc_count = 0; npc_count < MAX_NPCS; npc_count++)
   {
      for (int bullet_count = 0; bullet_count < MAX_BULLETS; bullet_count++)
      {
         game_o.npc[npc_count].bullet2[bullet_count].active   = false;
         game_o.npc[npc_count].bullet2[bullet_count].x_pos    = -2.0f;
         game_o.npc[npc_count].bullet2[bullet_count].y_pos    = -2.0f;
         game_o.npc[npc_count].bullet2[bullet_count].x_speed  = game_o.enemy[game_o.npc[npc_count].type_npc].speed;
         game_o.npc[npc_count].bullet2[bullet_count].y_speed  = game_o.enemy[game_o.npc[npc_count].type_npc].speed;
         game_o.npc[npc_count].bullet2[bullet_count].width    = 0.05f;
         game_o.npc[npc_count].bullet2[bullet_count].height   = 0.05f;
         game_o.npc[npc_count].bullet2[bullet_count].warhead  = game_o.enemy[game_o.npc[npc_count].type_npc].weapon_2;
         game_o.npc[npc_count].bullet2[bullet_count].location = 0;
      }
   }
   return(0);
}

void  proccess_npc_bullets2(void)
{

}

void draw_npcs(void)
{
    float temp_r     = 1.0f;
    float temp_g     = 1.0f;
    float temp_b     = 1.0f;
    float temp_a     = 1.0f;
    float z_pos      = 0.05f;
    float temp_angle = 0.00f;
    for (int npc_count = MAX_NPCS-1;npc_count >=0;npc_count--)  // npcs
    {
        for (int bullet_count = MAX_BULLETS-1;bullet_count >=0;bullet_count--)  // npcs bullets
        {
            if (game_o.npc[npc_count].bullet[bullet_count].active)
            {
                temp_angle = 360.0f - game_o.npc[npc_count].bullet[bullet_count].angle;
                z_pos = 0.05f + (0.0001*bullet_count);
                if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].image == texture.projectile_000.ref_number) texture.projectile_000.draw(true,game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,z_pos,game_o.npc[npc_count].bullet[bullet_count].width,game_o.npc[npc_count].bullet[bullet_count].height,180.0f);
                if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].image == texture.projectile_001.ref_number) texture.projectile_001.draw(true,game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,z_pos,game_o.npc[npc_count].bullet[bullet_count].width,game_o.npc[npc_count].bullet[bullet_count].height,180.0f);
                if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].image == texture.projectile_002.ref_number) texture.projectile_002.draw(true,game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,z_pos,game_o.npc[npc_count].bullet[bullet_count].width,game_o.npc[npc_count].bullet[bullet_count].height,180.0f);
                if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].image == texture.projectile_003.ref_number) texture.projectile_003.draw(true,game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,z_pos,game_o.npc[npc_count].bullet[bullet_count].width,game_o.npc[npc_count].bullet[bullet_count].height,180.0f);
                if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].image == texture.projectile_004.ref_number) texture.projectile_004.draw(true,game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,z_pos,game_o.npc[npc_count].bullet[bullet_count].width,game_o.npc[npc_count].bullet[bullet_count].height,180.0f);
                if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].image == texture.projectile_005.ref_number) texture.projectile_005.draw(true,game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,z_pos,game_o.npc[npc_count].bullet[bullet_count].width,game_o.npc[npc_count].bullet[bullet_count].height,180.0f);
                if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].image == texture.projectile_006.ref_number) texture.projectile_006.draw(true,game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,z_pos,game_o.npc[npc_count].bullet[bullet_count].width,game_o.npc[npc_count].bullet[bullet_count].height,180.0f);
                if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].image == texture.projectile_007.ref_number) texture.projectile_007.draw(true,game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,z_pos,game_o.npc[npc_count].bullet[bullet_count].width,game_o.npc[npc_count].bullet[bullet_count].height,180.0f);
                if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].image == texture.projectile_008.ref_number) texture.projectile_008.draw(true,game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,z_pos,game_o.npc[npc_count].bullet[bullet_count].width,game_o.npc[npc_count].bullet[bullet_count].height,180.0f);
                if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].image == texture.projectile_009.ref_number) texture.projectile_009.draw(true,game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,z_pos,game_o.npc[npc_count].bullet[bullet_count].width,game_o.npc[npc_count].bullet[bullet_count].height,180.0f);
                if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].image == texture.projectile_010.ref_number) texture.projectile_010.draw(true,game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,z_pos,game_o.npc[npc_count].bullet[bullet_count].width,game_o.npc[npc_count].bullet[bullet_count].height,180.0f);
                if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].image == texture.projectile_011.ref_number) texture.projectile_011.draw(true,game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,z_pos,game_o.npc[npc_count].bullet[bullet_count].width,game_o.npc[npc_count].bullet[bullet_count].height,180.0f);
                if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].image == texture.projectile_012.ref_number) texture.projectile_012.draw(true,game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,z_pos,game_o.npc[npc_count].bullet[bullet_count].width,game_o.npc[npc_count].bullet[bullet_count].height,180.0f);
                if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].image == texture.projectile_013.ref_number) texture.projectile_013.draw(true,game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,z_pos,game_o.npc[npc_count].bullet[bullet_count].width,game_o.npc[npc_count].bullet[bullet_count].height,180.0f);
                if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].image == texture.projectile_014.ref_number) texture.projectile_014.draw(true,game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,z_pos,game_o.npc[npc_count].bullet[bullet_count].width,game_o.npc[npc_count].bullet[bullet_count].height,180.0f);
                if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].image == texture.projectile_015.ref_number) texture.projectile_015.draw(true,game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,z_pos,game_o.npc[npc_count].bullet[bullet_count].width,game_o.npc[npc_count].bullet[bullet_count].height,180.0f);
                if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].image == texture.projectile_016.ref_number) texture.projectile_016.draw(true,game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,z_pos,game_o.npc[npc_count].bullet[bullet_count].width,game_o.npc[npc_count].bullet[bullet_count].height,180.0f);
                if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].image == texture.projectile_017.ref_number) texture.projectile_017.draw(true,game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,z_pos,game_o.npc[npc_count].bullet[bullet_count].width,game_o.npc[npc_count].bullet[bullet_count].height,180.0f);
                if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].image == texture.projectile_018.ref_number) texture.projectile_018.draw(true,game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,z_pos,game_o.npc[npc_count].bullet[bullet_count].width,game_o.npc[npc_count].bullet[bullet_count].height,180.0f);
                if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].image == texture.projectile_019.ref_number) texture.projectile_019.draw(true,game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,z_pos,game_o.npc[npc_count].bullet[bullet_count].width,game_o.npc[npc_count].bullet[bullet_count].height,180.0f);
                if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].image == texture.projectile_020.ref_number) texture.projectile_020.draw(true,game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,z_pos,game_o.npc[npc_count].bullet[bullet_count].width,game_o.npc[npc_count].bullet[bullet_count].height,180.0f);
                if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].image == texture.projectile_021.ref_number) texture.projectile_021.draw(true,game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,z_pos,game_o.npc[npc_count].bullet[bullet_count].width,game_o.npc[npc_count].bullet[bullet_count].height,180.0f);
                if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].image == texture.projectile_022.ref_number) texture.projectile_022.draw(true,game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,z_pos,game_o.npc[npc_count].bullet[bullet_count].width,game_o.npc[npc_count].bullet[bullet_count].height,180.0f);
                if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].image == texture.projectile_023.ref_number) texture.projectile_023.draw(true,game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,z_pos,game_o.npc[npc_count].bullet[bullet_count].width,game_o.npc[npc_count].bullet[bullet_count].height,180.0f);
                if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].image == texture.projectile_024.ref_number) texture.projectile_024.draw(true,game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,z_pos,game_o.npc[npc_count].bullet[bullet_count].width,game_o.npc[npc_count].bullet[bullet_count].height,180.0f);
                if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].image == texture.projectile_025.ref_number) texture.projectile_025.draw(true,game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,z_pos,game_o.npc[npc_count].bullet[bullet_count].width,game_o.npc[npc_count].bullet[bullet_count].height,180.0f);
                if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].image == texture.projectile_026.ref_number) texture.projectile_026.draw(true,game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,z_pos,game_o.npc[npc_count].bullet[bullet_count].width,game_o.npc[npc_count].bullet[bullet_count].height,180.0f);
                if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].image == texture.projectile_027.ref_number) texture.projectile_027.draw(true,game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,z_pos,game_o.npc[npc_count].bullet[bullet_count].width,game_o.npc[npc_count].bullet[bullet_count].height,180.0f);
                if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].image == texture.projectile_028.ref_number) texture.projectile_028.draw(true,game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,z_pos,game_o.npc[npc_count].bullet[bullet_count].width,game_o.npc[npc_count].bullet[bullet_count].height,180.0f);
                if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].image == texture.projectile_029.ref_number) texture.projectile_029.draw(true,game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,z_pos,game_o.npc[npc_count].bullet[bullet_count].width,game_o.npc[npc_count].bullet[bullet_count].height,180.0f);
                if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].image == texture.projectile_030.ref_number) texture.projectile_030.draw(true,game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,z_pos,game_o.npc[npc_count].bullet[bullet_count].width,game_o.npc[npc_count].bullet[bullet_count].height,180.0f);
                if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].image == texture.projectile_031.ref_number) texture.projectile_031.draw(true,game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,z_pos,game_o.npc[npc_count].bullet[bullet_count].width,game_o.npc[npc_count].bullet[bullet_count].height,180.0f);
                if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].image == texture.projectile_032.ref_number) texture.projectile_032.draw(true,game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,z_pos,game_o.npc[npc_count].bullet[bullet_count].width,game_o.npc[npc_count].bullet[bullet_count].height,180.0f);
                if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].image == texture.projectile_033.ref_number) texture.projectile_033.draw(true,game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,z_pos,game_o.npc[npc_count].bullet[bullet_count].width,game_o.npc[npc_count].bullet[bullet_count].height,180.0f);
                if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].image == texture.projectile_034.ref_number) texture.projectile_034.draw(true,game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,z_pos,game_o.npc[npc_count].bullet[bullet_count].width,game_o.npc[npc_count].bullet[bullet_count].height,180.0f);
            }
        }
        z_pos = 0.04f + (0.0001*npc_count); // npc's
        if (game_o.npc[npc_count].active)
        {
            temp_angle = 360.0f - game_o.npc[npc_count].angle;
            if (game_o.npc[npc_count].damaged > (game_o.npc_damage_duration/5))
            {
                temp_r = 1.0f;
                temp_g = 0.0f;
                temp_b = 0.0f;
                temp_a = 0.6f;
            }
            else
            {
                temp_r = 1.0f;
                temp_g = 1.0f;
                temp_b = 1.0f;
                temp_a = 1.0f;
            }
            //ps. width and height are used in reverse as values are swapped somewhere.
            if (game_o.enemy[game_o.npc[npc_count].type_npc].image == texture.ship_000.ref_number) texture.ship_000.draw(true,game_o.npc[npc_count].x_pos,game_o.npc[npc_count].y_pos,z_pos,game_o.npc[npc_count].height,game_o.npc[npc_count].width,temp_angle,temp_r,temp_g,temp_b,temp_a);
            if (game_o.enemy[game_o.npc[npc_count].type_npc].image == texture.ship_001.ref_number) texture.ship_001.draw(true,game_o.npc[npc_count].x_pos,game_o.npc[npc_count].y_pos,z_pos,game_o.npc[npc_count].height,game_o.npc[npc_count].width,temp_angle,temp_r,temp_g,temp_b,temp_a);
            if (game_o.enemy[game_o.npc[npc_count].type_npc].image == texture.ship_002.ref_number) texture.ship_002.draw(true,game_o.npc[npc_count].x_pos,game_o.npc[npc_count].y_pos,z_pos,game_o.npc[npc_count].height,game_o.npc[npc_count].width,temp_angle,temp_r,temp_g,temp_b,temp_a);
            if (game_o.enemy[game_o.npc[npc_count].type_npc].image == texture.ship_003.ref_number) texture.ship_003.draw(true,game_o.npc[npc_count].x_pos,game_o.npc[npc_count].y_pos,z_pos,game_o.npc[npc_count].height,game_o.npc[npc_count].width,temp_angle,temp_r,temp_g,temp_b,temp_a);
            if (game_o.enemy[game_o.npc[npc_count].type_npc].image == texture.ship_004.ref_number) texture.ship_004.draw(true,game_o.npc[npc_count].x_pos,game_o.npc[npc_count].y_pos,z_pos,game_o.npc[npc_count].height,game_o.npc[npc_count].width,temp_angle,temp_r,temp_g,temp_b,temp_a);
            if (game_o.enemy[game_o.npc[npc_count].type_npc].image == texture.ship_005.ref_number) texture.ship_005.draw(true,game_o.npc[npc_count].x_pos,game_o.npc[npc_count].y_pos,z_pos,game_o.npc[npc_count].height,game_o.npc[npc_count].width,temp_angle,temp_r,temp_g,temp_b,temp_a);
            if (game_o.enemy[game_o.npc[npc_count].type_npc].image == texture.ship_006.ref_number) texture.ship_006.draw(true,game_o.npc[npc_count].x_pos,game_o.npc[npc_count].y_pos,z_pos,game_o.npc[npc_count].height,game_o.npc[npc_count].width,temp_angle,temp_r,temp_g,temp_b,temp_a);
            if (game_o.enemy[game_o.npc[npc_count].type_npc].image == texture.ship_007.ref_number) texture.ship_007.draw(true,game_o.npc[npc_count].x_pos,game_o.npc[npc_count].y_pos,z_pos,game_o.npc[npc_count].height,game_o.npc[npc_count].width,temp_angle,temp_r,temp_g,temp_b,temp_a);
            if (game_o.enemy[game_o.npc[npc_count].type_npc].image == texture.ship_008.ref_number) texture.ship_008.draw(true,game_o.npc[npc_count].x_pos,game_o.npc[npc_count].y_pos,z_pos,game_o.npc[npc_count].height,game_o.npc[npc_count].width,temp_angle,temp_r,temp_g,temp_b,temp_a);
            if (game_o.enemy[game_o.npc[npc_count].type_npc].image == texture.ship_009.ref_number) texture.ship_009.draw(true,game_o.npc[npc_count].x_pos,game_o.npc[npc_count].y_pos,z_pos,game_o.npc[npc_count].height,game_o.npc[npc_count].width,temp_angle,temp_r,temp_g,temp_b,temp_a);
            if (game_o.enemy[game_o.npc[npc_count].type_npc].image == texture.ship_010.ref_number) texture.ship_010.draw(true,game_o.npc[npc_count].x_pos,game_o.npc[npc_count].y_pos,z_pos,game_o.npc[npc_count].height,game_o.npc[npc_count].width,temp_angle,temp_r,temp_g,temp_b,temp_a);
            if (game_o.enemy[game_o.npc[npc_count].type_npc].image == texture.ship_011.ref_number) texture.ship_011.draw(true,game_o.npc[npc_count].x_pos,game_o.npc[npc_count].y_pos,z_pos,game_o.npc[npc_count].height,game_o.npc[npc_count].width,temp_angle,temp_r,temp_g,temp_b,temp_a);
            if (game_o.enemy[game_o.npc[npc_count].type_npc].image == texture.ship_012.ref_number) texture.ship_012.draw(true,game_o.npc[npc_count].x_pos,game_o.npc[npc_count].y_pos,z_pos,game_o.npc[npc_count].height,game_o.npc[npc_count].width,temp_angle,temp_r,temp_g,temp_b,temp_a);
            if (game_o.enemy[game_o.npc[npc_count].type_npc].image == texture.ship_013.ref_number) texture.ship_013.draw(true,game_o.npc[npc_count].x_pos,game_o.npc[npc_count].y_pos,z_pos,game_o.npc[npc_count].height,game_o.npc[npc_count].width,temp_angle,temp_r,temp_g,temp_b,temp_a);
            if (game_o.enemy[game_o.npc[npc_count].type_npc].image == texture.ship_014.ref_number) texture.ship_014.draw(true,game_o.npc[npc_count].x_pos,game_o.npc[npc_count].y_pos,z_pos,game_o.npc[npc_count].height,game_o.npc[npc_count].width,temp_angle,temp_r,temp_g,temp_b,temp_a);
            if (game_o.enemy[game_o.npc[npc_count].type_npc].image == texture.ship_015.ref_number) texture.ship_015.draw(true,game_o.npc[npc_count].x_pos,game_o.npc[npc_count].y_pos,z_pos,game_o.npc[npc_count].height,game_o.npc[npc_count].width,temp_angle,temp_r,temp_g,temp_b,temp_a);
            if (game_o.enemy[game_o.npc[npc_count].type_npc].image == texture.ship_016.ref_number) texture.ship_016.draw(true,game_o.npc[npc_count].x_pos,game_o.npc[npc_count].y_pos,z_pos,game_o.npc[npc_count].height,game_o.npc[npc_count].width,temp_angle,temp_r,temp_g,temp_b,temp_a);
            if (game_o.enemy[game_o.npc[npc_count].type_npc].image == texture.ship_017.ref_number) texture.ship_017.draw(true,game_o.npc[npc_count].x_pos,game_o.npc[npc_count].y_pos,z_pos,game_o.npc[npc_count].height,game_o.npc[npc_count].width,temp_angle,temp_r,temp_g,temp_b,temp_a);
            if (game_o.enemy[game_o.npc[npc_count].type_npc].image == texture.ship_018.ref_number) texture.ship_018.draw(true,game_o.npc[npc_count].x_pos,game_o.npc[npc_count].y_pos,z_pos,game_o.npc[npc_count].height,game_o.npc[npc_count].width,temp_angle,temp_r,temp_g,temp_b,temp_a);
            if (game_o.enemy[game_o.npc[npc_count].type_npc].image == texture.ship_019.ref_number) texture.ship_019.draw(true,game_o.npc[npc_count].x_pos,game_o.npc[npc_count].y_pos,z_pos,game_o.npc[npc_count].height,game_o.npc[npc_count].width,temp_angle,temp_r,temp_g,temp_b,temp_a);
            if (game_o.enemy[game_o.npc[npc_count].type_npc].image == texture.ship_020.ref_number) texture.ship_020.draw(true,game_o.npc[npc_count].x_pos,game_o.npc[npc_count].y_pos,z_pos,game_o.npc[npc_count].height,game_o.npc[npc_count].width,temp_angle,temp_r,temp_g,temp_b,temp_a);
            if (game_o.enemy[game_o.npc[npc_count].type_npc].image == texture.ship_021.ref_number) texture.ship_021.draw(true,game_o.npc[npc_count].x_pos,game_o.npc[npc_count].y_pos,z_pos,game_o.npc[npc_count].height,game_o.npc[npc_count].width,temp_angle,temp_r,temp_g,temp_b,temp_a);
            if (game_o.enemy[game_o.npc[npc_count].type_npc].image == texture.ship_022.ref_number) texture.ship_022.draw(true,game_o.npc[npc_count].x_pos,game_o.npc[npc_count].y_pos,z_pos,game_o.npc[npc_count].height,game_o.npc[npc_count].width,temp_angle,temp_r,temp_g,temp_b,temp_a);
            if (game_o.enemy[game_o.npc[npc_count].type_npc].image == texture.ship_023.ref_number) texture.ship_023.draw(true,game_o.npc[npc_count].x_pos,game_o.npc[npc_count].y_pos,z_pos,game_o.npc[npc_count].height,game_o.npc[npc_count].width,temp_angle,temp_r,temp_g,temp_b,temp_a);
            if (game_o.enemy[game_o.npc[npc_count].type_npc].image == texture.ship_024.ref_number) texture.ship_024.draw(true,game_o.npc[npc_count].x_pos,game_o.npc[npc_count].y_pos,z_pos,game_o.npc[npc_count].height,game_o.npc[npc_count].width,temp_angle,temp_r,temp_g,temp_b,temp_a);
            if (game_o.enemy[game_o.npc[npc_count].type_npc].image == texture.ship_025.ref_number) texture.ship_025.draw(true,game_o.npc[npc_count].x_pos,game_o.npc[npc_count].y_pos,z_pos,game_o.npc[npc_count].height,game_o.npc[npc_count].width,temp_angle,temp_r,temp_g,temp_b,temp_a);
        }
    }
}




