#include "music.h"

music_type music[MAX_MUSIC];
int current_track;

int init_music(void)
{
   current_track = -1;
   for(int count = 0; count < MAX_MUSIC; count++)
   {
      music[count].music = NULL;
   }
    return(0);
};

int load_music(void)
{
    music[ 0].music = Mix_LoadMUS("data/music/level_00.s3m");
    music[ 1].music = Mix_LoadMUS("data/music/level_01.s3m");
    music[ 2].music = Mix_LoadMUS("data/music/level_02.s3m");
    music[ 3].music = Mix_LoadMUS("data/music/level_03.s3m");
    music[ 4].music = Mix_LoadMUS("data/music/level_04.s3m");
    music[ 5].music = Mix_LoadMUS("data/music/level_05.s3m");
    music[ 6].music = Mix_LoadMUS("data/music/level_06.it");
    music[ 7].music = Mix_LoadMUS("data/music/level_07.it");
    music[ 8].music = Mix_LoadMUS("data/music/level_08.it");
    music[ 9].music = Mix_LoadMUS("data/music/level_09.it");
    music[10].music = Mix_LoadMUS("data/music/level_10.it");
    music[11].music = Mix_LoadMUS("data/music/level_11.it");
    music[12].music = Mix_LoadMUS("data/music/level_12.mod");
    music[13].music = Mix_LoadMUS("data/music/level_13.mod");
    music[14].music = Mix_LoadMUS("data/music/level_14.mod");
    music[15].music = Mix_LoadMUS("data/music/level_15.mod");
    music[16].music = Mix_LoadMUS("data/music/level_16.mod");
    music[17].music = Mix_LoadMUS("data/music/level_17.mod");
    music[18].music = Mix_LoadMUS("data/music/level_18.mod");
    music[19].music = Mix_LoadMUS("data/music/level_19.mod");
    music[20].music = Mix_LoadMUS("data/music/level_20.mod");
    music[21].music = Mix_LoadMUS("data/music/level_21.mod");
    music[22].music = Mix_LoadMUS("data/music/level_22.mod");
    music[23].music = Mix_LoadMUS("data/music/level_23.mod");
    music[24].music = Mix_LoadMUS("data/music/level_24.mod");
    music[25].music = Mix_LoadMUS("data/music/level_25.mod");

    music[26].music = Mix_LoadMUS("data/music/menu_00.it");
    music[27].music = Mix_LoadMUS("data/music/level_nl.mod");
    music[28].music = Mix_LoadMUS("data/music/level_pd.mod");
    return(0);
};

int kill_music(void)
{
   Mix_HaltMusic();
   for(int count = 0; count < MAX_MUSIC; count++)
   {
      Mix_FreeMusic(music[count].music);
   }
   return(0);
};

int play_music(int music_num)
{
   if (music_num != current_track)
   {
      current_track = music_num;
      Mix_PlayMusic(music[music_num].music,-1);
   }
   return(0);
};
