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
   config_data.Audio_Channels       = 16;
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

bool Log_File(const char *Log_File, char error_string[])
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
