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
 * @author Paul Wortmann
 * @license GPL
 */

#include <fstream>
#include "config.hpp"

config_data_type config_data;

bool Load_Default_Config(void)
{
    config_data.menu_delay           = 128;
    config_data.menu_delay_count     = 0;
    config_data.Display_resolution   = 0;
    config_data.Display_X_Resolution = 640;
    config_data.Display_Y_Resolution = 480;
    config_data.Display_BPS          = 32;
    config_data.Display_Fullscreen   = false;
    config_data.Audio_Rate           = 44100;
    config_data.Audio_Channels       = 32;
    config_data.Audio_Buffers        = 2048;
    config_data.Audio_Music_Volume   = 32;
    config_data.Audio_Sound_Volume   = 64;
    config_data.joystick_enabled     = false;
    config_data.joystick_sensitivity = 6400;
    config_data.joystick_no_buttons  = 0;
    config_data.mouse_resolution_x   = config_data.Display_X_Resolution;
    config_data.mouse_resolution_y   = config_data.Display_Y_Resolution;
   return(0);
};

bool Save_Config_File(const char *Config_File)
{
  std::fstream configfile(Config_File,std::ios::out|std::ios::binary|std::ios::trunc);
  if (configfile.is_open())
  {
     configfile.write(reinterpret_cast<char*>(&config_data), sizeof(config_data_type));
     configfile.close();
  }
  else return(1);
  return(0);
};

bool Load_Config_File(const char *Config_File)
{
  std::fstream configfile(Config_File,std::ios::in|std::ios::binary);
  if (configfile.is_open())
  {
     configfile.read(reinterpret_cast<char*>(&config_data), sizeof(config_data_type));
     configfile.close();
  }
  else return(1);
  return(0);
};
