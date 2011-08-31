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
 * @date 2011-08-30
 */

#include "RAGE/rage.hpp"
#include "explosions.hpp"
#include "load_resources.hpp"
#include "game.hpp"
#include "misc.hpp"

extern  sound_type       sound;
extern  music_type       music;
extern  texture_type     texture;
extern  game_type  game_o;
extern  game_class game;

int spawn_explosion(float x_position, float y_position, float size)
{
    int  temp_type  = random_cen();
    bool spawn_done = 0;
    int  explosion_num;
    for  (explosion_num = 0; explosion_num < MAX_EXPLOSIONS;explosion_num++)
   {
       if (!spawn_done and !game_o.explosion[explosion_num].active)
       {
           game_o.explosion[explosion_num].image     = 185;
           game_o.explosion[explosion_num].animation = 0;
           if ((temp_type >=   0) && (temp_type <  33)) game_o.explosion[explosion_num].animation = 0;
           if ((temp_type >=  34) && (temp_type <  66)) game_o.explosion[explosion_num].animation = 1;
           if ((temp_type >=  67) && (temp_type < 101)) game_o.explosion[explosion_num].animation = 2;
           if (game_o.explosion[explosion_num].animation == 0) game_o.explosion[explosion_num].image = 185;
           if (game_o.explosion[explosion_num].animation == 1) game_o.explosion[explosion_num].image = 352;
           if (game_o.explosion[explosion_num].animation == 2) game_o.explosion[explosion_num].image = 364;
           game_o.explosion[explosion_num].active  = true;
           game_o.explosion[explosion_num].frame   = 0;
           game_o.explosion[explosion_num].sound   = 4;
           game_o.explosion[explosion_num].size    = size;
           game_o.explosion[explosion_num].width   = size/2;
           game_o.explosion[explosion_num].hight   = size/2;
           game_o.explosion[explosion_num].x_pos   = x_position;
           game_o.explosion[explosion_num].y_pos   = y_position;
           spawn_done = 1;
       }
   }
   return(0);
};

int kill_explosion(int explosion_num)
{
   game_o.explosion[explosion_num].animation = 0;
   game_o.explosion[explosion_num].active    = false;
   game_o.explosion[explosion_num].frame     = 0;
   game_o.explosion[explosion_num].image     = 185;
   game_o.explosion[explosion_num].sound     = 4;
   game_o.explosion[explosion_num].x_pos     = 0.0f;
   game_o.explosion[explosion_num].y_pos     = 0.0f;
   game_o.explosion[explosion_num].size      = 0.0f;
   return(0);
};

int init_explosions(void)
{
   for (int count =0;count < MAX_EXPLOSIONS;count++)
   {
      game_o.explosion[count].animation = 0;
      game_o.explosion[count].active    = false;
      game_o.explosion[count].frame     = 0;
      game_o.explosion[count].image     = 185;
      game_o.explosion[count].sound     = 4;
      game_o.explosion[count].x_pos     = 0.0f;
      game_o.explosion[count].y_pos     = 0.0f;
      game_o.explosion[count].size      = 0.0f;
   }
   return(0);
};

int proccess_explosions(void)
{
   for (int count =0;count < MAX_EXPLOSIONS;count++)
   {
      if(game_o.explosion[count].active)
      {
         game_o.explosion[count].x_pos -= (game.background.get_scroll_x(1)*2);
         game_o.explosion[count].frame++;
         if ((game_o.explosion[count].animation == 0) && (game_o.explosion[count].frame > 24))
         {
            game_o.explosion[count].active  = false;
            game_o.explosion[count].frame   = 0;
         }
         if ((game_o.explosion[count].animation == 1) && (game_o.explosion[count].frame > 23))
         {
            game_o.explosion[count].active  = false;
            game_o.explosion[count].frame   = 0;
         }
         if ((game_o.explosion[count].animation == 2) && (game_o.explosion[count].frame > 29))
         {
            game_o.explosion[count].active  = false;
            game_o.explosion[count].frame   = 0;
         }
      }
   }
   return(0);
};


