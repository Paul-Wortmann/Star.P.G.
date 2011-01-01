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

    music[ 0].music = Mix_LoadMUS("data/music/menu.mp3");
/*
    music[ 1].music = Mix_LoadMUS("data/music/level_00.mp3");
    music[ 2].music = Mix_LoadMUS("data/music/level_01.mp3");
    music[ 3].music = Mix_LoadMUS("data/music/level_02.mp3");
    music[ 4].music = Mix_LoadMUS("data/music/level_03.mp3");
    music[ 5].music = Mix_LoadMUS("data/music/level_04.mp3");
    music[ 6].music = Mix_LoadMUS("data/music/level_05.mp3");
    music[ 7].music = Mix_LoadMUS("data/music/level_06.mp3");
    music[ 8].music = Mix_LoadMUS("data/music/level_07.mp3");
    music[ 9].music = Mix_LoadMUS("data/music/level_08.mp3");
    music[10].music = Mix_LoadMUS("data/music/level_09.mp3");
*/
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
