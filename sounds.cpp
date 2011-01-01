#include "sounds.h"

sound_type sound[MAX_SOUNDS];

int init_sounds(void)
{
   for(int count = 0; count < MAX_SOUNDS; count++)
   {
      sound[count].active  = false;
      sound[count].channel = -1;
      sound[count].sound = NULL;
   }
    return(0);
};

int load_sounds(void)
{

    sound[0].active =  true; sound[0].sound =  Mix_LoadWAV("data/sound/menu_move.wav");
    sound[1].active =  true; sound[1].sound =  Mix_LoadWAV("data/sound/menu_select.wav");
    sound[2].active =  true; sound[2].sound =  Mix_LoadWAV("data/sound/bullet_001.wav");
    sound[3].active =  true; sound[3].sound =  Mix_LoadWAV("data/sound/bullet_002.wav");
    sound[4].active =  true; sound[4].sound =  Mix_LoadWAV("data/sound/explosion_001.mp3");
    sound[5].active =  true; sound[5].sound =  Mix_LoadWAV("data/sound/explosion_002.mp3");
    sound[6].active =  true; sound[6].sound =  Mix_LoadWAV("data/sound/explosion_003.wav");
    sound[7].active =  true; sound[7].sound =  Mix_LoadWAV("data/sound/projectile_000.wav");
    sound[8].active =  true; sound[8].sound =  Mix_LoadWAV("data/sound/projectile_001.wav");
    sound[9].active =  true; sound[9].sound =  Mix_LoadWAV("data/sound/projectile_002.wav");
    sound[10].active = true; sound[10].sound = Mix_LoadWAV("data/sound/projectile_003.wav");
    sound[11].active = true; sound[11].sound = Mix_LoadWAV("data/sound/projectile_004.wav");
    sound[12].active = true; sound[12].sound = Mix_LoadWAV("data/sound/projectile_005.wav");
    sound[13].active = true; sound[13].sound = Mix_LoadWAV("data/sound/shield_hit.wav");
    return(0);
};

int kill_sounds(void)
{
   Mix_HaltChannel(-1);
   for(int count = 0; count < MAX_SOUNDS; count++)
   {
      if (sound[count].active == true) Mix_FreeChunk(sound[count].sound);
      sound[count].active = false;
   }
   return(1);
};

int play_sound (int sound_num)
{
   sound[sound_num].channel = Mix_PlayChannel(-1, sound[sound_num].sound, 0);
   return(1);
};
