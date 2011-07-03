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
#include "config.h"

config_data_type config_data;

bool Load_Default_Config(void)
{
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

bool Init_Log_File(const char *Log_File)
{
  std::fstream logfile(Log_File,std::ios::out|std::ios::binary|std::ios::trunc);
  if (logfile.is_open()) logfile.close();
  else return(1);
  return(0);
};

bool Log_File(const char *Log_File, const char error_string[])
{
  std::fstream logfile(Log_File,std::ios::out|std::ios::app);
  if (logfile.is_open())
  {
     logfile << error_string;
     logfile << "\n";
     logfile.close();
  }
  else return(1);
  return(0);
};
