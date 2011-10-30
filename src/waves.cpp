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
 * @author  Paul Wortmann
 * @email   physhex@gmail.com
 * @website www.physhexgames.co.nr
 * @license GPL
 * @date 2011-10-01
 */

#include "core/core.hpp"
#include "waves.hpp"
#include "load_resources.hpp"
#include "game.hpp"
#include "misc.hpp"

extern  sound_type       sound;
extern  music_type       music;
extern  texture_type     texture;
extern  game_type        game_o;
extern  game_class       game;

/*----------------------------------------------------------------------------*/
int  init_waves     (void)
{
    for(int wave_count = 0; wave_count < MAX_WAVES; wave_count++)
    {
        game_o.level[game_o.current_level].number_of_waves                 = 0;
        game_o.level[game_o.current_level].wave[wave_count].active         = false;
        game_o.level[game_o.current_level].wave[wave_count].leader_num     = 0;
        game_o.level[game_o.current_level].wave[wave_count].npc_type       = 0;
        game_o.level[game_o.current_level].wave[wave_count].target_kills   = 0;
        game_o.level[game_o.current_level].wave[wave_count].count_kills    = 0;
        game_o.level[game_o.current_level].wave[wave_count].target_spawned = 0;
        game_o.level[game_o.current_level].wave[wave_count].count_spawned  = 0;
        game_o.level[game_o.current_level].wave[wave_count].spawn_pattern  = 0;
    }
    return(0);
};
/*----------------------------------------------------------------------------*/
int get_next_active_wave(void)
{
    int temp_int = 0;
    for(int wave_count = 0;wave_count < MAX_WAVES;wave_count++)
    {
        if (game_o.level[game_o.current_level].wave[wave_count].active) temp_int = wave_count;
    }
    return(temp_int);
}
/*----------------------------------------------------------------------------*/
int spawn_wave(void)
{
   float temp_float = 0.0f;
   int   wave_count = get_next_active_wave();
   if(game_o.level[game_o.current_level].wave[wave_count].spawn_pattern == 0)
   {
      temp_float = random_GLcoord();
      if (temp_float > ( 1.0f-(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*1))) temp_float = ( 1.0f-(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*1));
      if (temp_float < (-1.0f+(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*1))) temp_float = (-1.0f+(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*1));
      spawn_npc(1.0f+game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].width,temp_float+game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height,game_o.level[game_o.current_level].wave[wave_count].npc_type,game_o.level[game_o.current_level].wave[wave_count].spawn_pattern,+game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].width,+game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height);
      spawn_npc(1.0f,temp_float,game_o.level[game_o.current_level].wave[wave_count].npc_type,game_o.level[game_o.current_level].wave[wave_count].spawn_pattern,0.0f,0.0f);
      spawn_npc(1.0f+game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].width,temp_float-game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height,game_o.level[game_o.current_level].wave[wave_count].npc_type,game_o.level[game_o.current_level].wave[wave_count].spawn_pattern,+game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].width,-game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height);
      game_o.level_spawened += 3;
      game_o.wave_spawnable = false;
   }
   if(game_o.level[game_o.current_level].wave[wave_count].spawn_pattern == 1)
   {
      temp_float = random_GLcoord();
      if (temp_float > ( 1.0f-(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*3))) temp_float = ( 1.0f-(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*3));
      if (temp_float < (-1.0f+(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*3))) temp_float = (-1.0f+(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*3));
      spawn_npc(1.0f+(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].width*2),temp_float+(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*2),game_o.level[game_o.current_level].wave[wave_count].npc_type,game_o.level[game_o.current_level].wave[wave_count].spawn_pattern,+game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].width*2,+game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*2);
      spawn_npc(1.0f+game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].width,temp_float+game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height,game_o.level[game_o.current_level].wave[wave_count].npc_type,game_o.level[game_o.current_level].wave[wave_count].spawn_pattern,+game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].width,+game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height);
      spawn_npc(1.0f,temp_float,game_o.level[game_o.current_level].wave[wave_count].npc_type,game_o.level[game_o.current_level].wave[wave_count].spawn_pattern,0.0f,0.0f);
      spawn_npc(1.0f+game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].width,temp_float-game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height,game_o.level[game_o.current_level].wave[wave_count].npc_type,game_o.level[game_o.current_level].wave[wave_count].spawn_pattern,+game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].width,-game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height);
      spawn_npc(1.0f+(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].width*2),temp_float-(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*2),game_o.level[game_o.current_level].wave[wave_count].npc_type,game_o.level[game_o.current_level].wave[wave_count].spawn_pattern,-game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].width*2,-game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*2);
      game_o.level_spawened += 5;
      game_o.wave_spawnable = false;
   }
   if(game_o.level[game_o.current_level].wave[wave_count].spawn_pattern == 2)
   {
      temp_float = random_GLcoord();
      if (temp_float > ( 1.0f-(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*1))) temp_float = ( 1.0f-(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*1));
      if (temp_float < (-1.0f+(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*1))) temp_float = (-1.0f+(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*1));
      spawn_npc(1.0f+game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].width,temp_float+game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height,game_o.level[game_o.current_level].wave[wave_count].npc_type,game_o.level[game_o.current_level].wave[wave_count].spawn_pattern,+game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].width,+game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height);
      spawn_npc(1.0f,temp_float,game_o.level[game_o.current_level].wave[wave_count].npc_type,game_o.level[game_o.current_level].wave[wave_count].spawn_pattern,0.0f,0.0f);
      spawn_npc(1.0f+game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].width,temp_float-game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height,game_o.level[game_o.current_level].wave[wave_count].npc_type,game_o.level[game_o.current_level].wave[wave_count].spawn_pattern,+game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].width,-game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height);
      spawn_npc(1.0f+game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].width,temp_float,game_o.level[game_o.current_level].wave[wave_count].npc_type,game_o.level[game_o.current_level].wave[wave_count].spawn_pattern,+game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].width,0.0f);
      game_o.level_spawened += 4;
      game_o.wave_spawnable = false;
   }
   if(game_o.level[game_o.current_level].wave[wave_count].spawn_pattern == 3)
   {
      temp_float = random_GLcoord();
      if (temp_float > ( 1.0f-(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*3))) temp_float = ( 1.0f-(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*3));
      if (temp_float < (-1.0f+(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*3))) temp_float = (-1.0f+(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*3));
      spawn_npc(1.0f+(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].width*3),temp_float+(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*1.5f),game_o.level[game_o.current_level].wave[wave_count].npc_type,game_o.level[game_o.current_level].wave[wave_count].spawn_pattern,+game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].width*3,+game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*1.5f);
      spawn_npc(1.0f+(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].width*2),temp_float+(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*1.0f),game_o.level[game_o.current_level].wave[wave_count].npc_type,game_o.level[game_o.current_level].wave[wave_count].spawn_pattern,+game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].width*2,+game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*1.0f);
      spawn_npc(1.0f+game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].width,temp_float+(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*0.5f),game_o.level[game_o.current_level].wave[wave_count].npc_type,game_o.level[game_o.current_level].wave[wave_count].spawn_pattern,+game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].width,+game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*0.5f);
      spawn_npc(1.0f,temp_float,game_o.level[game_o.current_level].wave[wave_count].npc_type,game_o.level[game_o.current_level].wave[wave_count].spawn_pattern,0.0f,0.0f);
      spawn_npc(1.0f+game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].width,temp_float-(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*0.5f),game_o.level[game_o.current_level].wave[wave_count].npc_type,game_o.level[game_o.current_level].wave[wave_count].spawn_pattern,+game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].width,-game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*0.5f);
      spawn_npc(1.0f+(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].width*2),temp_float-(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*1.0f),game_o.level[game_o.current_level].wave[wave_count].npc_type,game_o.level[game_o.current_level].wave[wave_count].spawn_pattern,+game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].width*2,-game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*1.0f);
      spawn_npc(1.0f+(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].width*3),temp_float-(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*1.5f),game_o.level[game_o.current_level].wave[wave_count].npc_type,game_o.level[game_o.current_level].wave[wave_count].spawn_pattern,+game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].width*3,-game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*1.5f);
      game_o.level_spawened += 7;
      game_o.wave_spawnable = false;
   }
   if(game_o.level[game_o.current_level].wave[wave_count].spawn_pattern == 4)
   {
      temp_float = random_GLcoord();
      if (temp_float > ( 1.0f-(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*3))) temp_float = ( 1.0f-(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*3));
      if (temp_float < (-1.0f+(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*3))) temp_float = (-1.0f+(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*3));
      spawn_npc(1.0f+game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].width,temp_float+(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*0.5f),game_o.level[game_o.current_level].wave[wave_count].npc_type,game_o.level[game_o.current_level].wave[wave_count].spawn_pattern,+game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].width,+game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*0.5f);
      spawn_npc(1.0f,temp_float,game_o.level[game_o.current_level].wave[wave_count].npc_type,game_o.level[game_o.current_level].wave[wave_count].spawn_pattern,0.0f,0.0f);
      spawn_npc(1.0f+game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].width,temp_float-(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*0.5f),game_o.level[game_o.current_level].wave[wave_count].npc_type,game_o.level[game_o.current_level].wave[wave_count].spawn_pattern,+game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].width,-game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*0.5f);
      game_o.level_spawened += 3;
      game_o.wave_spawnable = false;
   }
   if(game_o.level[game_o.current_level].wave[wave_count].spawn_pattern == 5)
   {
      temp_float = random_GLcoord();
      if (temp_float > ( 1.0f-(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*3))) temp_float = ( 1.0f-(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*3));
      if (temp_float < (-1.0f+(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*3))) temp_float = (-1.0f+(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*3));
      spawn_npc(1.0f+(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].width*2),temp_float+(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*1.0f),game_o.level[game_o.current_level].wave[wave_count].npc_type,game_o.level[game_o.current_level].wave[wave_count].spawn_pattern,game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].width*2,+game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*1.0f);
      spawn_npc(1.0f+game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].width,temp_float+(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*0.5f),game_o.level[game_o.current_level].wave[wave_count].npc_type,game_o.level[game_o.current_level].wave[wave_count].spawn_pattern,game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].width,+game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*0.5f);
      spawn_npc(1.0f,temp_float,game_o.level[game_o.current_level].wave[wave_count].npc_type,game_o.level[game_o.current_level].wave[wave_count].spawn_pattern,0.0f,0.0f);
      spawn_npc(1.0f+game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].width,temp_float-(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*0.5f),game_o.level[game_o.current_level].wave[wave_count].npc_type,game_o.level[game_o.current_level].wave[wave_count].spawn_pattern,game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].width,-game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*0.5f);
      spawn_npc(1.0f+(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].width*2),temp_float-(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*1.0f),game_o.level[game_o.current_level].wave[wave_count].npc_type,game_o.level[game_o.current_level].wave[wave_count].spawn_pattern,game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].width*2,-game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*1.0f);
      game_o.level_spawened += 5;
      game_o.wave_spawnable = false;
   }
   if(game_o.level[game_o.current_level].wave[wave_count].spawn_pattern == 6)
   {
      temp_float = random_GLcoord();
      if (temp_float > ( 1.0f-(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*3))) temp_float = ( 1.0f-(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*3));
      if (temp_float < (-1.0f+(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*3))) temp_float = (-1.0f+(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*3));
      spawn_npc(1.0f+(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].width*2),temp_float+(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*1.0f),game_o.level[game_o.current_level].wave[wave_count].npc_type,game_o.level[game_o.current_level].wave[wave_count].spawn_pattern,game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].width*2,+game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*1.0f);
      spawn_npc(1.0f,temp_float,game_o.level[game_o.current_level].wave[wave_count].npc_type,game_o.level[game_o.current_level].wave[wave_count].spawn_pattern,0.0f,0.0f);
      spawn_npc(1.0f+game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].width,temp_float,game_o.level[game_o.current_level].wave[wave_count].npc_type,game_o.level[game_o.current_level].wave[wave_count].spawn_pattern,game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].width,0.0f);
      spawn_npc(1.0f+(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].width*2),temp_float-(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*1.0f),game_o.level[game_o.current_level].wave[wave_count].npc_type,game_o.level[game_o.current_level].wave[wave_count].spawn_pattern,game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].width*2,-game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*1.0f);
      game_o.level_spawened += 4;
      game_o.wave_spawnable = false;
   }
   if(game_o.level[game_o.current_level].wave[wave_count].spawn_pattern == 7)
   {
      temp_float = random_GLcoord();
      if (temp_float > ( 1.0f-(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*3))) temp_float = ( 1.0f-(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*3));
      if (temp_float < (-1.0f+(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*3))) temp_float = (-1.0f+(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*3));
      spawn_npc(1.0f,temp_float,game_o.level[game_o.current_level].wave[wave_count].npc_type,game_o.level[game_o.current_level].wave[wave_count].spawn_pattern,0.0f,0.0f);
      game_o.level_spawened += 1;
      game_o.wave_spawnable = false;
   }
   if(game_o.level[game_o.current_level].wave[wave_count].spawn_pattern == 8)
   {
      temp_float = random_GLcoord();
      if (temp_float > ( 1.0f-(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*3))) temp_float = ( 1.0f-(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*3));
      if (temp_float < (-1.0f+(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*3))) temp_float = (-1.0f+(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*3));
      spawn_npc(1.0f,temp_float+(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*0.5f),game_o.level[game_o.current_level].wave[wave_count].npc_type,game_o.level[game_o.current_level].wave[wave_count].spawn_pattern,0.0f,+game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*0.5f);
      spawn_npc(1.0f,temp_float-(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*0.5f),game_o.level[game_o.current_level].wave[wave_count].npc_type,game_o.level[game_o.current_level].wave[wave_count].spawn_pattern,0.0f,-game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*0.5f);
      game_o.level_spawened += 2;
      game_o.wave_spawnable = false;
   }
   if(game_o.level[game_o.current_level].wave[wave_count].spawn_pattern == 9)
   {
      temp_float = random_GLcoord();
      if (temp_float > ( 1.0f-(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*3))) temp_float = ( 1.0f-(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*3));
      if (temp_float < (-1.0f+(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*3))) temp_float = (-1.0f+(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*3));
      spawn_npc(1.0f,temp_float,game_o.level[game_o.current_level].wave[wave_count].npc_type,game_o.level[game_o.current_level].wave[wave_count].spawn_pattern,0.0f,0.0f);
      spawn_npc(1.0f+(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].width*0.75f),temp_float,game_o.level[game_o.current_level].wave[wave_count].npc_type,game_o.level[game_o.current_level].wave[wave_count].spawn_pattern,game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].width*0.75f,0.0f);
      spawn_npc(1.0f+(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].width*1.50f),temp_float,game_o.level[game_o.current_level].wave[wave_count].npc_type,game_o.level[game_o.current_level].wave[wave_count].spawn_pattern,game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].width*1.50f,0.0f);
      spawn_npc(1.0f+(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].width*2.25f),temp_float,game_o.level[game_o.current_level].wave[wave_count].npc_type,game_o.level[game_o.current_level].wave[wave_count].spawn_pattern,game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].width*2.25f,0.0f);
      game_o.level_spawened += 4;
      game_o.wave_spawnable = false;
   }
   if(game_o.level[game_o.current_level].wave[wave_count].spawn_pattern == 10)
   {
      temp_float = random_GLcoord();
      if (temp_float > ( 1.0f-(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*3))) temp_float = ( 1.0f-(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*3));
      if (temp_float < (-1.0f+(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*3))) temp_float = (-1.0f+(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*3));
      spawn_npc(1.0f,temp_float,game_o.level[game_o.current_level].wave[wave_count].npc_type,game_o.level[game_o.current_level].wave[wave_count].spawn_pattern,0.0f,0.0f);
      spawn_npc(1.0f+(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].width*0.75f),temp_float,game_o.level[game_o.current_level].wave[wave_count].npc_type,game_o.level[game_o.current_level].wave[wave_count].spawn_pattern,game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].width*0.75f,0.0f);
      spawn_npc(1.0f+(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].width*1.50f),temp_float,game_o.level[game_o.current_level].wave[wave_count].npc_type,game_o.level[game_o.current_level].wave[wave_count].spawn_pattern,game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].width*1.50f,0.0f);
      game_o.level_spawened += 3;
      game_o.wave_spawnable = false;
   }
   if(game_o.level[game_o.current_level].wave[wave_count].spawn_pattern == 11)
   {
      temp_float = random_GLcoord();
      if (temp_float > ( 1.0f-(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*3))) temp_float = ( 1.0f-(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*3));
      if (temp_float < (-1.0f+(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*3))) temp_float = (-1.0f+(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*3));
      spawn_npc(1.0f,temp_float+(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*1.0f),game_o.level[game_o.current_level].wave[wave_count].npc_type,game_o.level[game_o.current_level].wave[wave_count].spawn_pattern,0.0f,+game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*1.0f);
      spawn_npc(1.0f,temp_float,game_o.level[game_o.current_level].wave[wave_count].npc_type,game_o.level[game_o.current_level].wave[wave_count].spawn_pattern,0.0f,0.0f);
      spawn_npc(1.0f,temp_float-(game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*1.0f),game_o.level[game_o.current_level].wave[wave_count].npc_type,game_o.level[game_o.current_level].wave[wave_count].spawn_pattern,0.0f,-game_o.enemy[game_o.level[game_o.current_level].wave[wave_count].npc_type].height*1.0f);
      game_o.level_spawened += 3;
      game_o.wave_spawnable = false;
   }
}
/*----------------------------------------------------------------------------*/
int   process_waves(void)
{
    for(int wave_count = 0;wave_count < MAX_WAVES;wave_count++)
    {
        if ((game_o.level[game_o.current_level].wave[wave_count].active) && (!game_o.wave_spawnable))
        {
            game_o.level[game_o.current_level].wave[wave_count].active = false;
            if (wave_count >= game_o.level[game_o.current_level].number_of_waves) game_o.level[game_o.current_level].wave[0].active = true;
            else game_o.level[game_o.current_level].wave[wave_count+1].active = true;
            game_o.wave_spawnable = true;
        }
    }
}

