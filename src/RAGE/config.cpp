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

#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include "config.hpp"

config_file_class::config_file_class(void)
{
    config_file_class::menu_delay           = 128;
    config_file_class::menu_delay_count     = 0;
    config_file_class::joystick_sensitivity = 6400;
    config_file_class::joystick_enabled     = false;
    config_file_class::joystick_no_buttons  = 0;
    config_file_class::Display_resolution   = 0;
    config_file_class::Display_X_Resolution = 640;
    config_file_class::Display_Y_Resolution = 480;
    config_file_class::Display_BPS          = 32;
    config_file_class::Display_Fullscreen   = false;
    config_file_class::Audio_Rate           = 44100;
    config_file_class::Audio_Channels       = 32;
    config_file_class::Audio_Buffers        = 2048;
    config_file_class::Audio_Music_Volume   = 32;
    config_file_class::Audio_Sound_Volume   = 64;
    config_file_class::mouse_resolution_x   = config_file_class::Display_X_Resolution;
    config_file_class::mouse_resolution_y   = config_file_class::Display_Y_Resolution;
};

config_file_class::~config_file_class(void)
{

};

bool config_file_class::File_Set(std::string file_name)
{
    config_file_class::Config_File = file_name.c_str();
    return(true);
};

bool  config_file_class::Set_Defaults (void)
{
    config_file_class::menu_delay           = 128;
    config_file_class::menu_delay_count     = 0;
    config_file_class::joystick_sensitivity = 6400;
    config_file_class::joystick_enabled     = false;
    config_file_class::joystick_no_buttons  = 0;
    config_file_class::Display_resolution   = 0;
    config_file_class::Display_X_Resolution = 640;
    config_file_class::Display_Y_Resolution = 480;
    config_file_class::Display_BPS          = 32;
    config_file_class::Display_Fullscreen   = false;
    config_file_class::Audio_Rate           = 44100;
    config_file_class::Audio_Channels       = 32;
    config_file_class::Audio_Buffers        = 2048;
    config_file_class::Audio_Music_Volume   = 32;
    config_file_class::Audio_Sound_Volume   = 64;
    config_file_class::mouse_resolution_x   = config_file_class::Display_X_Resolution;
    config_file_class::mouse_resolution_y   = config_file_class::Display_Y_Resolution;
};

bool config_file_class::File_Clear(void)
{
    std::fstream configfile(config_file_class::Config_File,std::ios::out|std::ios::trunc);
    if (configfile.is_open()) configfile.close();
    else return(false);
    return(true);
};

bool config_file_class::File_Delete(void)
{
  if( remove(config_file_class::Config_File) != 0 ) return(false);
  else return(true);
};

bool  config_file_class::File_Write_Data  (std::string config_comment)
{
    std::fstream configfile(config_file_class::Config_File,std::ios::out|std::ios::app);
    if (configfile.is_open())
    {
        configfile << "#";
        configfile << config_comment;
        configfile << "\n";
        configfile.close();
    }
    else return(false);
    return(true);
};

bool  config_file_class::File_Write_Data  (std::string config_key, int config_data_int)
{
    std::fstream configfile(config_file_class::Config_File,std::ios::out|std::ios::app);
    if (configfile.is_open())
    {
        configfile << config_key;
        configfile << " = ";
        configfile << config_data_int;
        configfile << "\n";
        configfile.close();
    }
    else return(false);
    return(true);
};

bool  config_file_class::File_Write_Data  (std::string config_key, bool config_data_bool)
{
    std::fstream configfile(config_file_class::Config_File,std::ios::out|std::ios::app);
    if (configfile.is_open())
    {
        configfile << config_key;
        configfile << " = ";
        if (config_data_bool) configfile << "1";
        else configfile << "0";
        configfile << "\n";
        configfile.close();
    }
    else return(false);
    return(true);
};

bool  config_file_class::File_Write   (void)
{
    config_file_class::File_Write_Data  ("Star.P.G. - config file");
    config_file_class::File_Write_Data  ("-----------------------");
    config_file_class::File_Write_Data  ("Joystick_Sensitivity",config_file_class::joystick_sensitivity);
    config_file_class::File_Write_Data  ("Display_X_Resolution",config_file_class::Display_X_Resolution);
    config_file_class::File_Write_Data  ("Display_Y_Resolution",config_file_class::Display_Y_Resolution);
    config_file_class::File_Write_Data  ("Display_BPS",config_file_class::Display_BPS);
    config_file_class::File_Write_Data  ("Display_Fullscreen",config_file_class::Display_Fullscreen);
    config_file_class::File_Write_Data  ("Audio_Rate",config_file_class::Audio_Rate);
    config_file_class::File_Write_Data  ("Audio_Channels",config_file_class::Audio_Channels);
    config_file_class::File_Write_Data  ("Audio_Buffers",config_file_class::Audio_Buffers);
    config_file_class::File_Write_Data  ("Audio_Music_Volume",config_file_class::Audio_Music_Volume);
    config_file_class::File_Write_Data  ("Audio_Sound_Volume",config_file_class::Audio_Sound_Volume);
    return(true);
};

bool config_file_class::Process_Data(std::string data_line)
{
    char        temp_char = ' ';
    int         temp_int;
    std::string temp_string_key;
    std::string temp_string_value;
    int         count;

    temp_char = data_line[0];
    if(temp_char == '#') return(false);
    else
    {
        temp_char = '#';
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
        temp_int = atoi(temp_string_value.c_str());
        if (temp_string_key == "Joystick_Sensitivity")
        {
            config_file_class::joystick_sensitivity = temp_int;
        }
        if (temp_string_key == "Display_Fullscreen")
        {
            if (temp_int == 1) config_file_class::Display_Fullscreen = true;
            else config_file_class::Display_Fullscreen = false;
        }
        if (temp_string_key == "Audio_Rate")
        {
            config_file_class::Audio_Rate = temp_int;
        }
        if (temp_string_key == "Audio_Channels")
        {
            config_file_class::Audio_Channels = temp_int;
        }
        if (temp_string_key == "Audio_Buffers")
        {
            config_file_class::Audio_Buffers = temp_int;
        }
        if (temp_string_key == "Audio_Music_Volume")
        {
            config_file_class::Audio_Music_Volume = temp_int;
        }
        if (temp_string_key == "Audio_Sound_Volume")
        {
            config_file_class::Audio_Sound_Volume = temp_int;
        }
        if (temp_string_key == "Display_BPS")
        {
            config_file_class::Display_BPS = temp_int;
        }
        if (temp_string_key == "Display_X_Resolution")
        {
            config_file_class::Display_X_Resolution = temp_int;
        }
        if (temp_string_key == "Display_Y_Resolution")
        {
            config_file_class::Display_Y_Resolution = temp_int;
        }
    }
    return(true);
};

bool config_file_class::File_Read(void)
{
    std::string input_line;
    std::fstream configfile(Config_File,std::ios::in|std::ios::binary);
    if (configfile.is_open())
    {
        while ( configfile.good() )
        {
            getline(configfile,input_line);
            config_file_class::Process_Data(input_line);
            configfile.close();
        }
    }
    else return(false);
    return(true);
};