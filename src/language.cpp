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
#include "misc.hpp"
#include "language.hpp"


#include "menu_system.hpp"
#include "core/core.hpp"
extern  menu_class               main_menu;
extern  game_class                game;

language_class::language_class(void)
{
    language_class::text.main_menu            = "Main menu           ";
    language_class::text.star_map             = "Star Map            ";
    language_class::text.customize_starship   = "Customize Starship  ";
    language_class::text.achievements         = "Achievements        ";
    language_class::text.load_game            = "Load Game           ";
    language_class::text.save_game            = "Save Game           ";
    language_class::text.resume_game          = "Resume Game         ";
    language_class::text.options              = "Options             ";
    language_class::text.quit_game            = "Quit Game           ";
    language_class::text.level_select         = "Level Select        ";
    language_class::text.level_name_00        = "Taranis             ";
    language_class::text.level_name_01        = "Teutates            ";
    language_class::text.level_name_02        = "Esus                ";
    language_class::text.level_name_03        = "Cantidious          ";
    language_class::text.level_name_04        = "Vulcan              ";
    language_class::text.level_name_05        = "Bacchus             ";
    language_class::text.level_name_06        = "Janus               ";
    language_class::text.level_name_07        = "Wrathorn            ";
    language_class::text.level_name_08        = "Tartarus            ";
    language_class::text.level_name_09        = "Erebus              ";
    language_class::text.level_name_10        = "Nyx                 ";
    language_class::text.level_name_11        = "Dediun              ";
    language_class::text.level_name_12        = "Niflheim            ";
    language_class::text.level_name_13        = "Muspelhiem          ";
    language_class::text.level_name_14        = "Hel                 ";
    language_class::text.level_name_15        = "Paganite            ";
    language_class::text.level_name_16        = "Pixiu               ";
    language_class::text.level_name_17        = "Xiao                ";
    language_class::text.level_name_18        = "Fuxi                ";
    language_class::text.level_name_19        = "Haxorific           ";
    language_class::text.level_name_20        = "Byakko              ";
    language_class::text.level_name_21        = "Enenra              ";
    language_class::text.level_name_22        = "Tengu               ";
    language_class::text.level_name_23        = "Robonoid            ";
    language_class::text.level_name_24        = "Oyabun              ";
    language_class::text.front_weapon         = "Front Weapon        ";
    language_class::text.none                 = "None                ";
    language_class::text.side_weapon          = "Side Weapon         ";
    language_class::text.shield               = "Shield              ";
    language_class::text.thrusters            = "Thrusters           ";
    language_class::text.support_ships        = "Support Ships       ";
    language_class::text.score                = "Score               ";
    language_class::text.kills                = "Kills               ";
    language_class::text.save_menu            = "Save Menu           ";
    language_class::text.save_slot_1          = "Save Slot 1         ";
    language_class::text.save_slot_2          = "Save Slot 2         ";
    language_class::text.save_slot_3          = "Save Slot 3         ";
    language_class::text.save_slot_4          = "Save Slot 4         ";
    language_class::text.save_slot_5          = "Save Slot 5         ";
    language_class::text.save_slot_6          = "Save Slot 6         ";
    language_class::text.save_slot_7          = "Save Slot 7         ";
    language_class::text.load_menu            = "Load Menu           ";
    language_class::text.sound_volume         = "Sound Volume        ";
    language_class::text.music_volume         = "Music Volume        ";
    language_class::text.screen_resolution    = "Screen Resolution   ";
    language_class::text.res_640_x_480        = "640 X 480           ";
    language_class::text.res_800_x_600        = "800 X 600           ";
    language_class::text.res_1024_x_768       = "1024 X 768          ";
    language_class::text.res_1280_x_1024      = "1280 X 1024         ";
    language_class::text.res_1366_x_768       = "1366 X 768          ";
    language_class::text.res_1440_x_900       = "1440 X 900          ";
    language_class::text.res_1680_x_1050      = "1680 X 1050         ";
    language_class::text.res_1920_x_1080      = "1920 X 1080         ";
    language_class::text.full_screen          = "Full Screen         ";
    language_class::text.game_over            = "Game Over           ";
    language_class::text.level_completed      = "Level Completed     ";
    language_class::text.next_level           = "Next Level          ";
    language_class::text.game_completed       = "Game Completed      ";
    language_class::text.game_paused          = "Game Paused         ";
    language_class::text.UI_health_           = "Health - ";
    language_class::text.UI_shield_           = "Shield - ";
    language_class::text.UI_front             = "Front";
    language_class::text.UI_side              = "Side ";
    language_class::text.UI_score_            = "Score - ";
    language_class::text.UI_kills_            = "Kills - ";
    language_class::text.UI_active_NPCs_      = "Active NPCs - ";
    language_class::text.UI_FPS_              = "FPS - ";
};

void language_class::load(std::string file_name)
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
                    if (temp_string_key == "Main_Menu")          language_class::text.main_menu          = temp_string_data;
                    if (temp_string_key == "Star_Map")           language_class::text.star_map           = temp_string_data;
                    if (temp_string_key == "Customize_Starship") language_class::text.customize_starship = temp_string_data;
                    if (temp_string_key == "Achievements")       language_class::text.achievements       = temp_string_data;
                    if (temp_string_key == "Load_Game")          language_class::text.load_game          = temp_string_data;
                    if (temp_string_key == "Save_Game")          language_class::text.save_game          = temp_string_data;
                    if (temp_string_key == "Resume_Game")        language_class::text.resume_game        = temp_string_data;
                    if (temp_string_key == "Options")            language_class::text.options            = temp_string_data;
                    if (temp_string_key == "Quit_Game")          language_class::text.quit_game          = temp_string_data;
                    if (temp_string_key == "Level_Select")       language_class::text.level_select       = temp_string_data;
                    if (temp_string_key == "Level_Name_00")      language_class::text.level_name_00      = temp_string_data;
                    if (temp_string_key == "Level_Name_01")      language_class::text.level_name_01      = temp_string_data;
                    if (temp_string_key == "Level_Name_02")      language_class::text.level_name_02      = temp_string_data;
                    if (temp_string_key == "Level_Name_03")      language_class::text.level_name_03      = temp_string_data;
                    if (temp_string_key == "Level_Name_04")      language_class::text.level_name_04      = temp_string_data;
                    if (temp_string_key == "Level_Name_05")      language_class::text.level_name_05      = temp_string_data;
                    if (temp_string_key == "Level_Name_06")      language_class::text.level_name_06      = temp_string_data;
                    if (temp_string_key == "Level_Name_07")      language_class::text.level_name_07      = temp_string_data;
                    if (temp_string_key == "Level_Name_08")      language_class::text.level_name_08      = temp_string_data;
                    if (temp_string_key == "Level_Name_09")      language_class::text.level_name_09      = temp_string_data;
                    if (temp_string_key == "Level_Name_10")      language_class::text.level_name_10      = temp_string_data;
                    if (temp_string_key == "Level_Name_11")      language_class::text.level_name_11      = temp_string_data;
                    if (temp_string_key == "Level_Name_02")      language_class::text.level_name_12      = temp_string_data;
                    if (temp_string_key == "Level_Name_13")      language_class::text.level_name_13      = temp_string_data;
                    if (temp_string_key == "Level_Name_14")      language_class::text.level_name_14      = temp_string_data;
                    if (temp_string_key == "Level_Name_15")      language_class::text.level_name_15      = temp_string_data;
                    if (temp_string_key == "Level_Name_16")      language_class::text.level_name_16      = temp_string_data;
                    if (temp_string_key == "Level_Name_17")      language_class::text.level_name_17      = temp_string_data;
                    if (temp_string_key == "Level_Name_18")      language_class::text.level_name_18      = temp_string_data;
                    if (temp_string_key == "Level_Name_19")      language_class::text.level_name_19      = temp_string_data;
                    if (temp_string_key == "Level_Name_20")      language_class::text.level_name_20      = temp_string_data;
                    if (temp_string_key == "Level_Name_21")      language_class::text.level_name_21      = temp_string_data;
                    if (temp_string_key == "Level_Name_22")      language_class::text.level_name_22      = temp_string_data;
                    if (temp_string_key == "Level_Name_23")      language_class::text.level_name_23      = temp_string_data;
                    if (temp_string_key == "Level_Name_24")      language_class::text.level_name_24      = temp_string_data;
                    if (temp_string_key == "Front_Weapon")       language_class::text.front_weapon       = temp_string_data;
                    if (temp_string_key == "None")               language_class::text.none               = temp_string_data;
                    if (temp_string_key == "Side_Weapon")        language_class::text.side_weapon        = temp_string_data;
                    if (temp_string_key == "Shield")             language_class::text.shield             = temp_string_data;
                    if (temp_string_key == "Thrusters")          language_class::text.thrusters          = temp_string_data;
                    if (temp_string_key == "Support_Ships")      language_class::text.support_ships      = temp_string_data;
                    if (temp_string_key == "Score")              language_class::text.score              = temp_string_data;
                    if (temp_string_key == "Kills")              language_class::text.kills              = temp_string_data;
                    if (temp_string_key == "Save_Menu")          language_class::text.save_menu          = temp_string_data;
                    if (temp_string_key == "Save_Slot_1")        language_class::text.save_slot_1        = temp_string_data;
                    if (temp_string_key == "Save_Slot_2")        language_class::text.save_slot_2        = temp_string_data;
                    if (temp_string_key == "Save_Slot_3")        language_class::text.save_slot_3        = temp_string_data;
                    if (temp_string_key == "Save_Slot_4")        language_class::text.save_slot_4        = temp_string_data;
                    if (temp_string_key == "Save_Slot_5")        language_class::text.save_slot_5        = temp_string_data;
                    if (temp_string_key == "Save_Slot_6")        language_class::text.save_slot_6        = temp_string_data;
                    if (temp_string_key == "Save_Slot_7")        language_class::text.save_slot_7        = temp_string_data;
                    if (temp_string_key == "Load_Menu")          language_class::text.load_menu          = temp_string_data;
                    if (temp_string_key == "Sound_Volume")       language_class::text.sound_volume       = temp_string_data;
                    if (temp_string_key == "Music_Volume")       language_class::text.music_volume       = temp_string_data;
                    if (temp_string_key == "Screen_Resolution")  language_class::text.screen_resolution  = temp_string_data;
                    if (temp_string_key == "Res_640_X_480")      language_class::text.res_640_x_480      = temp_string_data;
                    if (temp_string_key == "Res_800_X_600")      language_class::text.res_800_x_600      = temp_string_data;
                    if (temp_string_key == "Res_1024_X_768")     language_class::text.res_1024_x_768     = temp_string_data;
                    if (temp_string_key == "Res_1280_X_1024")    language_class::text.res_1280_x_1024    = temp_string_data;
                    if (temp_string_key == "Res_1366_X_768")     language_class::text.res_1366_x_768     = temp_string_data;
                    if (temp_string_key == "Res_1440_X_900")     language_class::text.res_1440_x_900     = temp_string_data;
                    if (temp_string_key == "Res_1680_X_1050")    language_class::text.res_1680_x_1050    = temp_string_data;
                    if (temp_string_key == "Res_1920_X_1080")    language_class::text.res_1920_x_1080    = temp_string_data;
                    if (temp_string_key == "Full_Screen")        language_class::text.full_screen        = temp_string_data;
                    if (temp_string_key == "Game_Over")          language_class::text.game_over          = temp_string_data;
                    if (temp_string_key == "Level_Completed")    language_class::text.level_completed    = temp_string_data;
                    if (temp_string_key == "Next_Level")         language_class::text.next_level         = temp_string_data;
                    if (temp_string_key == "Game_Completed")     language_class::text.game_completed     = temp_string_data;
                    if (temp_string_key == "Game_Paused")        language_class::text.game_paused        = temp_string_data;
                    if (temp_string_key == "UI_health_")         language_class::text.UI_health_         = temp_string_data;
                    if (temp_string_key == "UI_shield_")         language_class::text.UI_shield_         = temp_string_data;
                    if (temp_string_key == "UI_front")           language_class::text.UI_front           = temp_string_data;
                    if (temp_string_key == "UI_side")            language_class::text.UI_side            = temp_string_data;
                    if (temp_string_key == "UI_score_")          language_class::text.UI_score_          = temp_string_data;
                    if (temp_string_key == "UI_kills_")          language_class::text.UI_kills_          = temp_string_data;
                    if (temp_string_key == "UI_active_NPCs_")    language_class::text.UI_active_NPCs_    = temp_string_data;
                    if (temp_string_key == "UI_FPS_")            language_class::text.UI_FPS_            = temp_string_data;
                }
            }
        }
        script_file.close();
    }
};
