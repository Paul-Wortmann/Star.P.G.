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
    sound[4].active =  true; sound[4].sound =  Mix_LoadWAV("data/sound/explosion_001.wav");
    sound[5].active =  true; sound[5].sound =  Mix_LoadWAV("data/sound/explosion_002.wav");
    sound[6].active =  true; sound[6].sound =  Mix_LoadWAV("data/sound/explosion_003.wav");
    sound[7].active =  true; sound[7].sound =  Mix_LoadWAV("data/sound/projectile_000.wav");
    sound[8].active =  true; sound[8].sound =  Mix_LoadWAV("data/sound/projectile_001.wav");
    sound[9].active =  true; sound[9].sound =  Mix_LoadWAV("data/sound/projectile_002.wav");
    sound[10].active = true; sound[10].sound = Mix_LoadWAV("data/sound/projectile_003.wav");
    sound[11].active = true; sound[11].sound = Mix_LoadWAV("data/sound/projectile_004.wav");
    sound[12].active = true; sound[12].sound = Mix_LoadWAV("data/sound/projectile_005.wav");
    sound[13].active = true; sound[13].sound = Mix_LoadWAV("data/sound/shield_hit.wav");

    sound[14].active = true; sound[14].sound = Mix_LoadWAV("data/sound/powerup_01.wav");
    sound[15].active = true; sound[15].sound = Mix_LoadWAV("data/sound/powerup_02.wav");
    sound[16].active = true; sound[16].sound = Mix_LoadWAV("data/sound/powerup_03.wav");
    sound[17].active = true; sound[17].sound = Mix_LoadWAV("data/sound/powerup_04.wav");
    sound[18].active = true; sound[18].sound = Mix_LoadWAV("data/sound/powerup_05.wav");
    sound[19].active = true; sound[19].sound = Mix_LoadWAV("data/sound/powerup_06.wav");
    sound[20].active = true; sound[20].sound = Mix_LoadWAV("data/sound/powerup_07.wav");

    sound[21].active = true; sound[21].sound = Mix_LoadWAV("data/sound/coin_00.wav");
    sound[22].active = true; sound[22].sound = Mix_LoadWAV("data/sound/wexp_00.wav");

    sound[23].active = true; sound[23].sound = Mix_LoadWAV("data/sound/projectile_006.wav");
    sound[24].active = true; sound[24].sound = Mix_LoadWAV("data/sound/projectile_007.wav");
    sound[25].active = true; sound[25].sound = Mix_LoadWAV("data/sound/projectile_008.wav");
    sound[26].active = true; sound[26].sound = Mix_LoadWAV("data/sound/projectile_009.wav");
    sound[27].active = true; sound[27].sound = Mix_LoadWAV("data/sound/projectile_010.wav");
    sound[28].active = true; sound[28].sound = Mix_LoadWAV("data/sound/projectile_011.wav");
    sound[29].active = true; sound[29].sound = Mix_LoadWAV("data/sound/projectile_012.wav");
    sound[30].active = true; sound[30].sound = Mix_LoadWAV("data/sound/projectile_013.wav");
    sound[31].active = true; sound[31].sound = Mix_LoadWAV("data/sound/projectile_014.wav");
    sound[32].active = true; sound[32].sound = Mix_LoadWAV("data/sound/projectile_015.wav");
    sound[33].active = true; sound[33].sound = Mix_LoadWAV("data/sound/projectile_016.wav");
    sound[34].active = true; sound[34].sound = Mix_LoadWAV("data/sound/projectile_017.wav");
    sound[35].active = true; sound[35].sound = Mix_LoadWAV("data/sound/projectile_018.wav");
    sound[36].active = true; sound[36].sound = Mix_LoadWAV("data/sound/projectile_019.wav");
    sound[37].active = true; sound[37].sound = Mix_LoadWAV("data/sound/projectile_020.wav");
    sound[38].active = true; sound[38].sound = Mix_LoadWAV("data/sound/projectile_021.wav");
    sound[39].active = true; sound[39].sound = Mix_LoadWAV("data/sound/projectile_022.wav");
    sound[40].active = true; sound[40].sound = Mix_LoadWAV("data/sound/projectile_023.wav");
    sound[41].active = true; sound[41].sound = Mix_LoadWAV("data/sound/projectile_024.wav");
    sound[42].active = true; sound[42].sound = Mix_LoadWAV("data/sound/projectile_025.wav");
    sound[43].active = true; sound[43].sound = Mix_LoadWAV("data/sound/projectile_026.wav");
    sound[44].active = true; sound[44].sound = Mix_LoadWAV("data/sound/projectile_027.wav");
    sound[45].active = true; sound[45].sound = Mix_LoadWAV("data/sound/projectile_028.wav");
    sound[46].active = true; sound[46].sound = Mix_LoadWAV("data/sound/projectile_029.wav");
    sound[47].active = true; sound[47].sound = Mix_LoadWAV("data/sound/projectile_030.wav");

    sound[48].active = true; sound[48].sound = Mix_LoadWAV("data/sound/explosion_004.wav");
    sound[49].active = true; sound[49].sound = Mix_LoadWAV("data/sound/explosion_005.wav");
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
