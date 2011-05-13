/* Copyright (C) 2011 Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
 * This file is part of Star.P.G.
 *
 * Star.P.G. is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * Star.P.G. is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Star.P.G. If not, see <http://www.gnu.org/licenses/>.
 */


struct config_data_type
{
   int  Display_resolution;
   int  Display_X_Resolution;
   int  Display_Y_Resolution;
   int  Display_BPS;
   bool Display_Fullscreen;
   int  Audio_Rate;
   int  Audio_Channels;
   int  Audio_Buffers;
   int  Audio_Music_Volume;
   int  Audio_Sound_Volume;
   int  player_0_image;
   int  player_1_image;
   int  ball_1_image;
};

bool Save_Config_File(const char *Config_File);
bool Load_Config_File(const char *Config_File);
bool Load_Default_Config(void);

bool Init_Log_File(const char *Log_File);
bool Log_File(const char *Log_File, const char error_string[]);
