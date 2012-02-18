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

#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "load_resources.hpp"
#include "core/core.hpp"
#include "levels.hpp"
#include "game.hpp"

extern game_type         game_o;
extern game_class        game;
extern texture_type      texture;
extern music_type        music;

void init_levels(void)
{
    game_o.level[ 0].load("data/configuration/levels/level_00.txt");
    game_o.level[ 1].load("data/configuration/levels/level_01.txt");
    game_o.level[ 2].load("data/configuration/levels/level_02.txt");
    game_o.level[ 3].load("data/configuration/levels/level_03.txt");
    game_o.level[ 4].load("data/configuration/levels/level_04.txt");
    game_o.level[ 5].load("data/configuration/levels/level_05.txt");
    game_o.level[ 6].load("data/configuration/levels/level_06.txt");
    game_o.level[ 7].load("data/configuration/levels/level_07.txt");
    game_o.level[ 8].load("data/configuration/levels/level_08.txt");
    game_o.level[ 9].load("data/configuration/levels/level_09.txt");
    game_o.level[10].load("data/configuration/levels/level_10.txt");
    game_o.level[11].load("data/configuration/levels/level_11.txt");
    game_o.level[12].load("data/configuration/levels/level_12.txt");
    game_o.level[13].load("data/configuration/levels/level_13.txt");
    game_o.level[14].load("data/configuration/levels/level_14.txt");
    game_o.level[15].load("data/configuration/levels/level_15.txt");
    game_o.level[16].load("data/configuration/levels/level_16.txt");
    game_o.level[17].load("data/configuration/levels/level_17.txt");
    game_o.level[18].load("data/configuration/levels/level_18.txt");
    game_o.level[19].load("data/configuration/levels/level_19.txt");
    game_o.level[20].load("data/configuration/levels/level_20.txt");
    game_o.level[21].load("data/configuration/levels/level_21.txt");
    game_o.level[22].load("data/configuration/levels/level_22.txt");
    game_o.level[23].load("data/configuration/levels/level_23.txt");
    game_o.level[24].load("data/configuration/levels/level_24.txt");
    for (int level_no_count = 0;level_no_count < (MAX_LEVELS); level_no_count++)
    {
        game_o.level[level_no_count].locked = true;/// set to false to unlock all levels....for testing!
    }
    game_o.level[0].locked = false;
};

int unlock_levels(void)
{
   for (int level_no_count = 0;level_no_count < (MAX_LEVELS); level_no_count++)
   {
      game_o.level[level_no_count].locked = false;
   }
   return(1);
}

int init_game_level(int level_no)
{
    game_o.current_level                     = level_no;
    game_o.level_end_rumble                  = true;
    game_o.bomb_delay_count                  = 0;
    game_o.immune                            = true;
    game_o.immunity_state                    = 0;
    game_o.immunity_delay_count              = 0;
    game_o.immune                            = true;
    game_o.level_end_time                    = false;
    game_o.level_end_count                   = 0;
    game_o.level_end_phase                   = 0;
    game_o.level_end_display_active          = false;
    game_o.powerups_spawened                 = false;
    game_o.level_kills                       = 0;
    game_o.level_spawened                    = 0;
    game_o.level_score                       = 0;
    game_o.active_npc_count                  = 0;
    game_o.player.x_pos                      =-0.9f+thruster_offset();
    game_o.player.y_pos                      = 0.0f;
    game_o.player.x_dir                      = 0.0f;
    game_o.player.y_dir                      = 0.0f;
    game_o.player.x_vel                      = 0.0f;
    game_o.player.y_vel                      = 0.0f;
    game_o.player.health                     = game_o.player.max_health;
    game_o.player.shield                     = game_o.player.max_shield;
    game_o.rumble.stop();
    init_in_game_message_class();
    kill_active_npcs();
    init_npcs(0);
    init_active_npcs();
    kill_powerups();
    kill_coins();
    kill_wexps();
    kill_player_bullet();
    pos_supportships(game_o.player.x_pos,game_o.player.y_pos);
    kill_supportship_bullets();
    game_o.level[game_o.current_level].wave[0].active = true;
    set_level_background(1,game_o.level[game_o.current_level].background_00);
    set_level_background(2,game_o.level[game_o.current_level].background_00);
    set_level_background(3,game_o.level[game_o.current_level].background_01);
    set_level_background(4,game_o.level[game_o.current_level].background_01);
    game.background.set_movement_type(SCROLL);
    game.music_track                         = game_o.level[game_o.current_level].music_track;
    game_o.speed                             = game_o.level[game_o.current_level].speed;
    game_o.npc_spawn_rate                    = game_o.level[game_o.current_level].NPC_spawn_rate;
    game_o.npc_spawn_rate_count              = game_o.level[game_o.current_level].NPC_spawn_rate_count;
    game_o.npc_projectile_spawn_rate         = game_o.level[game_o.current_level].NPC_projectile_spawn_rate;
    game_o.victory_kills                     = game_o.level[game_o.current_level].victory_kills;
    game_o.victory_score                     = game_o.level[game_o.current_level].victory_score;
    game_o.victory_spawened                  = game_o.level[game_o.current_level].victory_spawened;
    init_npcs(game_o.level[game_o.current_level].NPC_type);
    return(0);
};

void set_level_background(int layer_number, int image_reference)
{
    float background_offset = 0.0f;
    float background_speed  = 0.0f;
    if ((layer_number == 2) || (layer_number == 4)) background_offset = 4.0f;
    else  background_offset = 0.0f;
    if ((layer_number == 3) || (layer_number == 4)) background_speed = 0.0020f;
    else  background_speed = 0.0050f;
    if (image_reference ==  0) game.background.set_data (layer_number, 1, 1, background_offset, 0.0f, background_speed, background_speed, texture.background_000.ref_number);
    if (image_reference ==  1) game.background.set_data (layer_number, 1, 1, background_offset, 0.0f, background_speed, background_speed, texture.background_001.ref_number);
    if (image_reference ==  2) game.background.set_data (layer_number, 1, 1, background_offset, 0.0f, background_speed, background_speed, texture.background_002.ref_number);
    if (image_reference ==  3) game.background.set_data (layer_number, 1, 1, background_offset, 0.0f, background_speed, background_speed, texture.background_003.ref_number);
    if (image_reference ==  4) game.background.set_data (layer_number, 1, 1, background_offset, 0.0f, background_speed, background_speed, texture.background_004.ref_number);
    if (image_reference ==  5) game.background.set_data (layer_number, 1, 1, background_offset, 0.0f, background_speed, background_speed, texture.background_005.ref_number);
    if (image_reference ==  6) game.background.set_data (layer_number, 1, 1, background_offset, 0.0f, background_speed, background_speed, texture.background_006.ref_number);
    if (image_reference ==  7) game.background.set_data (layer_number, 1, 1, background_offset, 0.0f, background_speed, background_speed, texture.background_007.ref_number);
    if (image_reference ==  8) game.background.set_data (layer_number, 1, 1, background_offset, 0.0f, background_speed, background_speed, texture.background_008.ref_number);
    if (image_reference ==  9) game.background.set_data (layer_number, 1, 1, background_offset, 0.0f, background_speed, background_speed, texture.background_009.ref_number);
    if (image_reference == 10) game.background.set_data (layer_number, 1, 1, background_offset, 0.0f, background_speed, background_speed, texture.background_010.ref_number);
    if (image_reference == 11) game.background.set_data (layer_number, 1, 1, background_offset, 0.0f, background_speed, background_speed, texture.background_011.ref_number);
    if (image_reference == 12) game.background.set_data (layer_number, 1, 1, background_offset, 0.0f, background_speed, background_speed, texture.background_012.ref_number);
    if (image_reference == 13) game.background.set_data (layer_number, 1, 1, background_offset, 0.0f, background_speed, background_speed, texture.background_013.ref_number);
    if (image_reference == 14) game.background.set_data (layer_number, 1, 1, background_offset, 0.0f, background_speed, background_speed, texture.background_014.ref_number);
    if (image_reference == 15) game.background.set_data (layer_number, 1, 1, background_offset, 0.0f, background_speed, background_speed, texture.background_015.ref_number);
    if (image_reference == 16) game.background.set_data (layer_number, 1, 1, background_offset, 0.0f, background_speed, background_speed, texture.background_016.ref_number);
    if (image_reference == 17) game.background.set_data (layer_number, 1, 1, background_offset, 0.0f, background_speed, background_speed, texture.background_017.ref_number);
    if (image_reference == 18) game.background.set_data (layer_number, 1, 1, background_offset, 0.0f, background_speed, background_speed, texture.background_018.ref_number);
    if (image_reference == 19) game.background.set_data (layer_number, 1, 1, background_offset, 0.0f, background_speed, background_speed, texture.background_019.ref_number);
    if (image_reference == 20) game.background.set_data (layer_number, 1, 1, background_offset, 0.0f, background_speed, background_speed, texture.background_020.ref_number);
    if (image_reference == 21) game.background.set_data (layer_number, 1, 1, background_offset, 0.0f, background_speed, background_speed, texture.background_021.ref_number);
    if (image_reference == 22) game.background.set_data (layer_number, 1, 1, background_offset, 0.0f, background_speed, background_speed, texture.background_022.ref_number);
    if (image_reference == 23) game.background.set_data (layer_number, 1, 1, background_offset, 0.0f, background_speed, background_speed, texture.background_023.ref_number);
    if (image_reference == 24) game.background.set_data (layer_number, 1, 1, background_offset, 0.0f, background_speed, background_speed, texture.background_024.ref_number);
    if (image_reference == 25) game.background.set_data (layer_number, 1, 1, background_offset, 0.0f, background_speed, background_speed, texture.background_025.ref_number);
    if (image_reference == 26) game.background.set_data (layer_number, 1, 1, background_offset, 0.0f, background_speed, background_speed, texture.background_026.ref_number);
    if (image_reference == 27) game.background.set_data (layer_number, 1, 1, background_offset, 0.0f, background_speed, background_speed, texture.background_027.ref_number);
    if (image_reference == 28) game.background.set_data (layer_number, 1, 1, background_offset, 0.0f, background_speed, background_speed, texture.background_028.ref_number);
    if (image_reference == 29) game.background.set_data (layer_number, 1, 1, background_offset, 0.0f, background_speed, background_speed, texture.background_029.ref_number);
    if (image_reference == 30) game.background.set_data (layer_number, 1, 1, background_offset, 0.0f, background_speed, background_speed, texture.background_030.ref_number);
    if (image_reference == 31) game.background.set_data (layer_number, 1, 1, background_offset, 0.0f, background_speed, background_speed, texture.background_031.ref_number);
};

void level_class::load(std::string file_name)
{
    char         temp_char = ' ';
    float        temp_float;
    std::string  temp_string_key;
    std::string  temp_string_value;
    int          count;
    std::string  data_line;
    std::fstream level_file(file_name.c_str(),std::ios::in|std::ios::binary);
    if (level_file.is_open())
    {
        while ( level_file.good() )
        {
            getline(level_file,data_line);
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
                    temp_float = atof(temp_string_value.c_str());
                    if (temp_string_key == "NPC_Type")
                    {
                        level_class::NPC_type = (int)temp_float;
                    }
                    if (temp_string_key == "BOSS")
                    {
                        if ((int)temp_float == 1) level_class::BOSS = true;
                        else level_class::BOSS = false;
                    }
                    if (temp_string_key == "Music_Track")
                    {
                        level_class::music_track = (int)temp_float;
                    }
                    if (temp_string_key == "Background_00")
                    {
                        level_class::background_00 = (int)temp_float;
                    }
                    if (temp_string_key == "Background_01")
                    {
                        level_class::background_01 = (int)temp_float;
                    }
                    if (temp_string_key == "Speed")
                    {
                        level_class::speed = temp_float;
                    }
                    if (temp_string_key == "NPC_Spawn_Rate")
                    {
                        level_class::NPC_spawn_rate       = (int)temp_float;
                        level_class::NPC_spawn_rate_count = (int)temp_float;
                    }
                    if (temp_string_key == "NPC_Projectile_Spawn_Rate")
                    {
                        level_class::NPC_projectile_spawn_rate       = (int)temp_float;
                    }
                    if (temp_string_key == "Victory_Kills")
                    {
                        level_class::victory_kills= (int)temp_float;
                    }
                    if (temp_string_key == "Victory_Spawned")
                    {
                        level_class::victory_spawened       = (int)temp_float;
                    }
                    if (temp_string_key == "Victory_Score")
                    {
                        level_class::victory_score       = (int)temp_float;
                    }
                    if (temp_string_key == "Number_Of_Waves")
                    {
                        level_class::number_of_waves       = (int)temp_float - 1;
                    }
                    if (temp_string_key == "Wave_00_Wave_Size")
                    {
                        level_class::wave[ 0].wave_size       = temp_float;
                    }
                    if (temp_string_key == "Wave_00_NPC_Type")
                    {
                        level_class::wave[ 0].npc_type       = (int)temp_float;
                    }
                    if (temp_string_key == "Wave_00_Spawn_Pattern")
                    {
                        level_class::wave[ 0].spawn_pattern       = (int)temp_float;
                    }
                    if (temp_string_key == "Wave_01_Wave_Size")
                    {
                        level_class::wave[ 1].wave_size       = temp_float;
                    }
                    if (temp_string_key == "Wave_01_NPC_Type")
                    {
                        level_class::wave[ 1].npc_type       = (int)temp_float;
                    }
                    if (temp_string_key == "Wave_01_Spawn_Pattern")
                    {
                        level_class::wave[ 1].spawn_pattern       = (int)temp_float;
                    }
                    if (temp_string_key == "Wave_02_Wave_Size")
                    {
                        level_class::wave[ 2].wave_size       = temp_float;
                    }
                    if (temp_string_key == "Wave_02_NPC_Type")
                    {
                        level_class::wave[ 2].npc_type       = (int)temp_float;
                    }
                    if (temp_string_key == "Wave_02_Spawn_Pattern")
                    {
                        level_class::wave[ 2].spawn_pattern       = (int)temp_float;
                    }
                    if (temp_string_key == "Wave_03_Wave_Size")
                    {
                        level_class::wave[ 3].wave_size       = temp_float;
                    }
                    if (temp_string_key == "Wave_03_NPC_Type")
                    {
                        level_class::wave[ 3].npc_type       = (int)temp_float;
                    }
                    if (temp_string_key == "Wave_03_Spawn_Pattern")
                    {
                        level_class::wave[ 3].spawn_pattern       = (int)temp_float;
                    }
                    if (temp_string_key == "Wave_04_Wave_Size")
                    {
                        level_class::wave[ 4].wave_size       = temp_float;
                    }
                    if (temp_string_key == "Wave_04_NPC_Type")
                    {
                        level_class::wave[ 4].npc_type       = (int)temp_float;
                    }
                    if (temp_string_key == "Wave_04_Spawn_Pattern")
                    {
                        level_class::wave[ 4].spawn_pattern       = (int)temp_float;
                    }
                    if (temp_string_key == "Wave_05_Wave_Size")
                    {
                        level_class::wave[ 5].wave_size       = temp_float;
                    }
                    if (temp_string_key == "Wave_05_NPC_Type")
                    {
                        level_class::wave[ 5].npc_type       = (int)temp_float;
                    }
                    if (temp_string_key == "Wave_05_Spawn_Pattern")
                    {
                        level_class::wave[ 5].spawn_pattern       = (int)temp_float;
                    }
                    if (temp_string_key == "Wave_06_Wave_Size")
                    {
                        level_class::wave[ 6].wave_size       = temp_float;
                    }
                    if (temp_string_key == "Wave_06_NPC_Type")
                    {
                        level_class::wave[ 6].npc_type       = (int)temp_float;
                    }
                    if (temp_string_key == "Wave_06_Spawn_Pattern")
                    {
                        level_class::wave[ 6].spawn_pattern       = (int)temp_float;
                    }
                    if (temp_string_key == "Wave_07_Wave_Size")
                    {
                        level_class::wave[ 7].wave_size       = temp_float;
                    }
                    if (temp_string_key == "Wave_07_NPC_Type")
                    {
                        level_class::wave[ 7].npc_type       = (int)temp_float;
                    }
                    if (temp_string_key == "Wave_07_Spawn_Pattern")
                    {
                        level_class::wave[ 7].spawn_pattern       = (int)temp_float;
                    }
                    if (temp_string_key == "Wave_08_Wave_Size")
                    {
                        level_class::wave[ 8].wave_size       = temp_float;
                    }
                    if (temp_string_key == "Wave_08_NPC_Type")
                    {
                        level_class::wave[ 8].npc_type       = (int)temp_float;
                    }
                    if (temp_string_key == "Wave_08_Spawn_Pattern")
                    {
                        level_class::wave[ 8].spawn_pattern       = (int)temp_float;
                    }
                    if (temp_string_key == "Wave_09_Wave_Size")
                    {
                        level_class::wave[ 9].wave_size       = temp_float;
                    }
                    if (temp_string_key == "Wave_09_NPC_Type")
                    {
                        level_class::wave[ 9].npc_type       = (int)temp_float;
                    }
                    if (temp_string_key == "Wave_09_Spawn_Pattern")
                    {
                        level_class::wave[ 9].spawn_pattern       = (int)temp_float;
                    }
                    if (temp_string_key == "Wave_10_Wave_Size")
                    {
                        level_class::wave[10].wave_size       = temp_float;
                    }
                    if (temp_string_key == "Wave_10_NPC_Type")
                    {
                        level_class::wave[10].npc_type       = (int)temp_float;
                    }
                    if (temp_string_key == "Wave_10_Spawn_Pattern")
                    {
                        level_class::wave[10].spawn_pattern       = (int)temp_float;
                    }
                    if (temp_string_key == "Wave_11_Wave_Size")
                    {
                        level_class::wave[11].wave_size       = temp_float;
                    }
                    if (temp_string_key == "Wave_11_NPC_Type")
                    {
                        level_class::wave[11].npc_type       = (int)temp_float;
                    }
                    if (temp_string_key == "Wave_11_Spawn_Pattern")
                    {
                        level_class::wave[11].spawn_pattern       = (int)temp_float;
                    }
                    if (temp_string_key == "Wave_12_Wave_Size")
                    {
                        level_class::wave[12].wave_size       = temp_float;
                    }
                    if (temp_string_key == "Wave_12_NPC_Type")
                    {
                        level_class::wave[12].npc_type       = (int)temp_float;
                    }
                    if (temp_string_key == "Wave_12_Spawn_Pattern")
                    {
                        level_class::wave[12].spawn_pattern       = (int)temp_float;
                    }
                    if (temp_string_key == "Wave_13_Wave_Size")
                    {
                        level_class::wave[13].wave_size       = temp_float;
                    }
                    if (temp_string_key == "Wave_13_NPC_Type")
                    {
                        level_class::wave[13].npc_type       = (int)temp_float;
                    }
                    if (temp_string_key == "Wave_13_Spawn_Pattern")
                    {
                        level_class::wave[13].spawn_pattern       = (int)temp_float;
                    }
                    if (temp_string_key == "Wave_14_Wave_Size")
                    {
                        level_class::wave[14].wave_size       = temp_float;
                    }
                    if (temp_string_key == "Wave_14_NPC_Type")
                    {
                        level_class::wave[14].npc_type       = (int)temp_float;
                    }
                    if (temp_string_key == "Wave_14_Spawn_Pattern")
                    {
                        level_class::wave[14].spawn_pattern       = (int)temp_float;
                    }
                    if (temp_string_key == "Wave_15_Wave_Size")
                    {
                        level_class::wave[15].wave_size       = temp_float;
                    }
                    if (temp_string_key == "Wave_15_NPC_Type")
                    {
                        level_class::wave[15].npc_type       = (int)temp_float;
                    }
                    if (temp_string_key == "Wave_15_Spawn_Pattern")
                    {
                        level_class::wave[15].spawn_pattern       = (int)temp_float;
                    }
                    if (temp_string_key == "Wave_16_Wave_Size")
                    {
                        level_class::wave[16].wave_size       = temp_float;
                    }
                    if (temp_string_key == "Wave_16_NPC_Type")
                    {
                        level_class::wave[16].npc_type       = (int)temp_float;
                    }
                    if (temp_string_key == "Wave_16_Spawn_Pattern")
                    {
                        level_class::wave[16].spawn_pattern       = (int)temp_float;
                    }
                    if (temp_string_key == "Wave_17_Wave_Size")
                    {
                        level_class::wave[17].wave_size       = temp_float;
                    }
                    if (temp_string_key == "Wave_17_NPC_Type")
                    {
                        level_class::wave[17].npc_type       = (int)temp_float;
                    }
                    if (temp_string_key == "Wave_17_Spawn_Pattern")
                    {
                        level_class::wave[17].spawn_pattern       = (int)temp_float;
                    }
                    if (temp_string_key == "Wave_18_Wave_Size")
                    {
                        level_class::wave[18].wave_size       = temp_float;
                    }
                    if (temp_string_key == "Wave_18_NPC_Type")
                    {
                        level_class::wave[18].npc_type       = (int)temp_float;
                    }
                    if (temp_string_key == "Wave_18_Spawn_Pattern")
                    {
                        level_class::wave[18].spawn_pattern       = (int)temp_float;
                    }
                    if (temp_string_key == "Wave_19_Wave_Size")
                    {
                        level_class::wave[19].wave_size       = temp_float;
                    }
                    if (temp_string_key == "Wave_19_NPC_Type")
                    {
                        level_class::wave[19].npc_type       = (int)temp_float;
                    }
                    if (temp_string_key == "Wave_19_Spawn_Pattern")
                    {
                        level_class::wave[19].spawn_pattern       = (int)temp_float;
                    }
                    if (temp_string_key == "Wave_20_Wave_Size")
                    {
                        level_class::wave[20].wave_size       = temp_float;
                    }
                    if (temp_string_key == "Wave_20_NPC_Type")
                    {
                        level_class::wave[20].npc_type       = (int)temp_float;
                    }
                    if (temp_string_key == "Wave_20_Spawn_Pattern")
                    {
                        level_class::wave[20].spawn_pattern       = (int)temp_float;
                    }
                    if (temp_string_key == "Wave_21_Wave_Size")
                    {
                        level_class::wave[21].wave_size       = temp_float;
                    }
                    if (temp_string_key == "Wave_21_NPC_Type")
                    {
                        level_class::wave[21].npc_type       = (int)temp_float;
                    }
                    if (temp_string_key == "Wave_21_Spawn_Pattern")
                    {
                        level_class::wave[21].spawn_pattern       = (int)temp_float;
                    }
                    if (temp_string_key == "Wave_22_Wave_Size")
                    {
                        level_class::wave[22].wave_size       = temp_float;
                    }
                    if (temp_string_key == "Wave_22_NPC_Type")
                    {
                        level_class::wave[22].npc_type       = (int)temp_float;
                    }
                    if (temp_string_key == "Wave_22_Spawn_Pattern")
                    {
                        level_class::wave[22].spawn_pattern       = (int)temp_float;
                    }
                    if (temp_string_key == "Wave_23_Wave_Size")
                    {
                        level_class::wave[23].wave_size       = temp_float;
                    }
                    if (temp_string_key == "Wave_23_NPC_Type")
                    {
                        level_class::wave[23].npc_type       = (int)temp_float;
                    }
                    if (temp_string_key == "Wave_23_Spawn_Pattern")
                    {
                        level_class::wave[23].spawn_pattern       = (int)temp_float;
                    }
                    if (temp_string_key == "Wave_24_Wave_Size")
                    {
                        level_class::wave[24].wave_size       = temp_float;
                    }
                    if (temp_string_key == "Wave_24_NPC_Type")
                    {
                        level_class::wave[24].npc_type       = (int)temp_float;
                    }
                    if (temp_string_key == "Wave_24_Spawn_Pattern")
                    {
                        level_class::wave[24].spawn_pattern       = (int)temp_float;
                    }
                    if (temp_string_key == "Wave_25_Wave_Size")
                    {
                        level_class::wave[25].wave_size       = temp_float;
                    }
                    if (temp_string_key == "Wave_25_NPC_Type")
                    {
                        level_class::wave[25].npc_type       = (int)temp_float;
                    }
                    if (temp_string_key == "Wave_25_Spawn_Pattern")
                    {
                        level_class::wave[25].spawn_pattern       = (int)temp_float;
                    }
                    if (temp_string_key == "Wave_26_Wave_Size")
                    {
                        level_class::wave[26].wave_size       = temp_float;
                    }
                    if (temp_string_key == "Wave_26_NPC_Type")
                    {
                        level_class::wave[26].npc_type       = (int)temp_float;
                    }
                    if (temp_string_key == "Wave_26_Spawn_Pattern")
                    {
                        level_class::wave[26].spawn_pattern       = (int)temp_float;
                    }
                    if (temp_string_key == "Wave_27_Wave_Size")
                    {
                        level_class::wave[27].wave_size       = temp_float;
                    }
                    if (temp_string_key == "Wave_27_NPC_Type")
                    {
                        level_class::wave[27].npc_type       = (int)temp_float;
                    }
                    if (temp_string_key == "Wave_27_Spawn_Pattern")
                    {
                        level_class::wave[27].spawn_pattern       = (int)temp_float;
                    }
                    if (temp_string_key == "Wave_28_Wave_Size")
                    {
                        level_class::wave[28].wave_size       = temp_float;
                    }
                    if (temp_string_key == "Wave_28_NPC_Type")
                    {
                        level_class::wave[28].npc_type       = (int)temp_float;
                    }
                    if (temp_string_key == "Wave_28_Spawn_Pattern")
                    {
                        level_class::wave[28].spawn_pattern       = (int)temp_float;
                    }
                    if (temp_string_key == "Wave_29_Wave_Size")
                    {
                        level_class::wave[29].wave_size       = temp_float;
                    }
                    if (temp_string_key == "Wave_29_NPC_Type")
                    {
                        level_class::wave[29].npc_type       = (int)temp_float;
                    }
                    if (temp_string_key == "Wave_29_Spawn_Pattern")
                    {
                        level_class::wave[29].spawn_pattern       = (int)temp_float;
                    }
                    if (temp_string_key == "Wave_30_Wave_Size")
                    {
                        level_class::wave[30].wave_size       = temp_float;
                    }
                    if (temp_string_key == "Wave_30_NPC_Type")
                    {
                        level_class::wave[30].npc_type       = (int)temp_float;
                    }
                    if (temp_string_key == "Wave_30_Spawn_Pattern")
                    {
                        level_class::wave[30].spawn_pattern       = (int)temp_float;
                    }
                    if (temp_string_key == "Wave_31_Wave_Size")
                    {
                        level_class::wave[31].wave_size       = temp_float;
                    }
                    if (temp_string_key == "Wave_31_NPC_Type")
                    {
                        level_class::wave[31].npc_type       = (int)temp_float;
                    }
                    if (temp_string_key == "Wave_31_Spawn_Pattern")
                    {
                        level_class::wave[31].spawn_pattern       = (int)temp_float;
                    }
                    if (temp_string_key == "Wave_32_Wave_Size")
                    {
                        level_class::wave[32].wave_size       = temp_float;
                    }
                    if (temp_string_key == "Wave_32_NPC_Type")
                    {
                        level_class::wave[32].npc_type       = (int)temp_float;
                    }
                    if (temp_string_key == "Wave_32_Spawn_Pattern")
                    {
                        level_class::wave[32].spawn_pattern       = (int)temp_float;
                    }
                }
            }
        }
        level_file.close();
    }
};

bool level_completed(void)
{
   if ((game_o.level_kills >= game_o.victory_kills) && (game_o.level_spawened >= game_o.victory_spawened) && (game_o.level_score >= game_o.victory_score))
   {
       game_o.level_end_time = true;
       if (game_o.level_end_phase == 0)
       {
          game_o.level_end_count++;
          if (game_o.level_end_count >= game_o.level_end_time_out)
          {
              game_o.level_end_phase = 1;
              game_o.level_end_count = 0;
          }
       }
       if (game_o.level_end_phase == 1)
       {
          game_o.level_end_count++;
          if (game_o.level_end_count >= game_o.level_end_time_out)
          {
              game_o.level_end_phase = 2;
              game_o.level_end_count = 0;
          }
       }
       if (game_o.level_end_phase == 2) return(true);
       else return(false);
   }
   else return(false);
}

bool boss_level(void)
{
    if (game_o.level[game_o.current_level].BOSS) return (true);
    else return (false);
};
