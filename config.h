
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
bool Log_File(const char *Log_File, char error_string[]);
