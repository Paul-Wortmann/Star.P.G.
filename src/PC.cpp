/**
 * Copyright (C) 2010-2012 Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
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
#include "PC.hpp"
#include "NPC.hpp"
#include "load_resources.hpp"
#include "game.hpp"
#include "misc.hpp"

extern  sound_type       sound;
extern  music_type       music;
extern  texture_type     texture;
extern  game_type  game_o;
extern  game_class game;

void  init_player            (void)
{
    game_o.player.shield                     =  0.100f;
    game_o.player.shield_regen_rate          =  0.000025f;
    game_o.player.max_shield                 =  0.011f;
    game_o.player.x_pos                      = -0.9f;
    game_o.player.y_pos                      =  0.0f;
    game_o.player.x_dir                      =  0.0f;
    game_o.player.y_dir                      =  0.0f;
    game_o.player.x_vel                      =  0.0f;
    game_o.player.y_vel                      =  0.0f;
    game_o.player.width                      =  0.2f;
    game_o.player.height                     =  0.2f;
    game_o.player.health                     =  0.100f;
    game_o.player.health_regen_rate          =  0.00005f;
    game_o.player.max_health                 =  0.100f;
    game_o.player.image                      =  texture.ship_025.ref_number; // change game_draw(); code for drawing player if you change this!!!!
    game_o.player.front_weapon               =  0;
    game_o.player.side_weapon                =  0;
    game_o.player.front_shield               = -1;
    game_o.player.thrusters                  = -1;
};

/*----------------------------------------------------------------------------*/
int spawn_player_bullet_num(int player_bullet_num, int location)
{
       //           play_sound(game_o.projectile[game_o.player.front_weapon].sound);

   if (player_bullet_num > MAX_BULLETS) player_bullet_num = MAX_BULLETS;
   game_o.player.bullet[player_bullet_num].active   = true;
   game_o.player.bullet[player_bullet_num].location = location;
   if (location < 3) game_o.player.bullet[player_bullet_num].warhead = game_o.player.front_weapon;
   else              game_o.player.bullet[player_bullet_num].warhead = game_o.player.side_weapon;
   game_o.player.bullet[player_bullet_num].x_pos    = (game_o.player.x_pos + (game_o.player.width/2));
   if (location == 0) game_o.player.bullet[player_bullet_num].y_pos =(game_o.player.y_pos + (game_o.player.height/2))-0.02f;
   if (location == 1) game_o.player.bullet[player_bullet_num].y_pos = game_o.player.y_pos;
   if (location == 2) game_o.player.bullet[player_bullet_num].y_pos =(game_o.player.y_pos - (game_o.player.height/2))+0.02f;
   if (location == 3) game_o.player.bullet[player_bullet_num].y_pos =(game_o.player.y_pos + (game_o.player.height/2))-0.02f;
   if (location == 4) game_o.player.bullet[player_bullet_num].y_pos = game_o.player.y_pos;
   if (location == 5) game_o.player.bullet[player_bullet_num].y_pos =(game_o.player.y_pos - (game_o.player.height/2))+0.02f;
   if (location == 6) game_o.player.bullet[player_bullet_num].y_pos =(game_o.player.y_pos + (game_o.player.height/2))-0.02f;
   if (location == 7) game_o.player.bullet[player_bullet_num].y_pos = game_o.player.y_pos;
   if (location == 8) game_o.player.bullet[player_bullet_num].y_pos =(game_o.player.y_pos - (game_o.player.height/2))+0.02f;
   game_o.player.bullet[player_bullet_num].wave_height    =  game_o.projectile[game_o.player.bullet[player_bullet_num].warhead].wave_size;
   game_o.player.bullet[player_bullet_num].wave_count     =  0.0f;
   game_o.player.bullet[player_bullet_num].wave_speed     =  game_o.projectile[game_o.player.bullet[player_bullet_num].warhead].wave_velocity;
   if (location == 0) game_o.player.bullet[player_bullet_num].wave_direction =  1;
   if (location == 1) game_o.player.bullet[player_bullet_num].wave_direction =  1;
   if (location == 2) game_o.player.bullet[player_bullet_num].wave_direction =  0;
   if (location == 3) game_o.player.bullet[player_bullet_num].wave_direction =  1;
   if (location == 4) game_o.player.bullet[player_bullet_num].wave_direction =  0;
   if (location == 5) game_o.player.bullet[player_bullet_num].wave_direction =  0;
   if (location == 6) game_o.player.bullet[player_bullet_num].wave_direction =  1;
   if (location == 7) game_o.player.bullet[player_bullet_num].wave_direction =  1;
   if (location == 8) game_o.player.bullet[player_bullet_num].wave_direction =  0;
   if (location < 3)  game_o.player.bullet[player_bullet_num].width  = game_o.projectile[game_o.player.front_weapon].width;
   else               game_o.player.bullet[player_bullet_num].width  = game_o.projectile[game_o.player.side_weapon ].width;
   if (location < 3)  game_o.player.bullet[player_bullet_num].height = game_o.projectile[game_o.player.front_weapon].height;
   else               game_o.player.bullet[player_bullet_num].height = game_o.projectile[game_o.player.side_weapon ].height;
   return(0);
}
/*----------------------------------------------------------------------------*/
int spawn_player_bullet(int position)
{
   bool spawn_done = 0;
   int  player_bullet_num;
   if (((position == 0) && (game_o.player.front_weapon > -1)) || ((position == 1) && (game_o.player.side_weapon > -1)))
   {
      if (position == 0)//front weapon
      {
         if (game_o.player.front_weapon ==  0) sound.projectile_000.play();
         if (game_o.player.front_weapon ==  1) sound.projectile_001.play();
         if (game_o.player.front_weapon ==  2) sound.projectile_002.play();
         if (game_o.player.front_weapon ==  3) sound.projectile_003.play();
         if (game_o.player.front_weapon ==  4) sound.projectile_004.play();
         if (game_o.player.front_weapon ==  5) sound.projectile_005.play();
         if (game_o.player.front_weapon ==  6) sound.projectile_006.play();
         if (game_o.player.front_weapon ==  7) sound.projectile_007.play();
         if (game_o.player.front_weapon ==  8) sound.projectile_008.play();
         if (game_o.player.front_weapon ==  9) sound.projectile_009.play();
         if (game_o.player.front_weapon == 10) sound.projectile_010.play();
         if (game_o.player.front_weapon == 11) sound.projectile_011.play();
         if (game_o.player.front_weapon == 12) sound.projectile_012.play();
         if (game_o.player.front_weapon == 13) sound.projectile_013.play();
         if (game_o.player.front_weapon == 14) sound.projectile_014.play();
         if (game_o.player.front_weapon == 15) sound.projectile_015.play();
         if (game_o.player.front_weapon == 16) sound.projectile_016.play();
         if (game_o.player.front_weapon == 17) sound.projectile_017.play();
         if (game_o.player.front_weapon == 18) sound.projectile_018.play();
         if (game_o.player.front_weapon == 19) sound.projectile_019.play();
         if (game_o.player.front_weapon == 20) sound.projectile_020.play();
         if (game_o.player.front_weapon == 21) sound.projectile_021.play();
         if (game_o.player.front_weapon == 22) sound.projectile_022.play();
         if (game_o.player.front_weapon == 23) sound.projectile_023.play();
         if (game_o.player.front_weapon == 24) sound.projectile_024.play();
         if (game_o.player.front_weapon == 25) sound.projectile_025.play();
         if (game_o.player.front_weapon == 26) sound.projectile_026.play();
         if (game_o.player.front_weapon == 27) sound.projectile_027.play();
         if (game_o.player.front_weapon == 28) sound.projectile_028.play();
         if (game_o.player.front_weapon == 29) sound.projectile_029.play();
         if (game_o.player.front_weapon == 30) sound.projectile_030.play();
         if (game_o.projectile[game_o.player.front_weapon].level == 0)
         {
            spawn_done = 0;
            for  (player_bullet_num = 0; player_bullet_num < MAX_BULLETS;player_bullet_num++)
            {
               if (!spawn_done and !game_o.player.bullet[player_bullet_num].active)
               {
                  spawn_player_bullet_num(player_bullet_num,1);
                  spawn_done = 1;
               }
            }
         }
         if (game_o.projectile[game_o.player.front_weapon].level == 1)
         {
            spawn_done = 0;
            for  (player_bullet_num = 0; player_bullet_num < MAX_BULLETS;player_bullet_num++)
            {
               if (!spawn_done and !game_o.player.bullet[player_bullet_num].active)
               {
                  spawn_player_bullet_num(player_bullet_num,0);
                  spawn_done = 1;
               }
            }
            spawn_done = 0;
            for  (player_bullet_num = 0; player_bullet_num < MAX_BULLETS;player_bullet_num++)
            {
               if (!spawn_done and !game_o.player.bullet[player_bullet_num].active)
               {
                  spawn_player_bullet_num(player_bullet_num,2);
                  spawn_done = 1;
               }
            }
         }
         if (game_o.projectile[game_o.player.front_weapon].level >= 2)
         {
            spawn_done = 0;
            for  (player_bullet_num = 0; player_bullet_num < MAX_BULLETS;player_bullet_num++)
            {
               if (!spawn_done and !game_o.player.bullet[player_bullet_num].active)
               {
                  spawn_player_bullet_num(player_bullet_num,0);
                  spawn_done = 1;
               }
            }
            spawn_done = 0;
            for  (player_bullet_num = 0; player_bullet_num < MAX_BULLETS;player_bullet_num++)
            {
               if (!spawn_done and !game_o.player.bullet[player_bullet_num].active)
               {
                  spawn_player_bullet_num(player_bullet_num,1);
                  spawn_done = 1;
               }
            }
            spawn_done = 0;
            for  (player_bullet_num = 0; player_bullet_num < MAX_BULLETS;player_bullet_num++)
            {
               if (!spawn_done and !game_o.player.bullet[player_bullet_num].active)
               {
                  spawn_player_bullet_num(player_bullet_num,2);
                  spawn_done = 1;
               }
            }
         }
      }
      if (position == 1)//side weapon
      {
         if (game_o.player.side_weapon ==  0) sound.projectile_000.play();
         if (game_o.player.side_weapon ==  1) sound.projectile_001.play();
         if (game_o.player.side_weapon ==  2) sound.projectile_002.play();
         if (game_o.player.side_weapon ==  3) sound.projectile_003.play();
         if (game_o.player.side_weapon ==  4) sound.projectile_004.play();
         if (game_o.player.side_weapon ==  5) sound.projectile_005.play();
         if (game_o.player.side_weapon ==  6) sound.projectile_006.play();
         if (game_o.player.side_weapon ==  7) sound.projectile_007.play();
         if (game_o.player.side_weapon ==  8) sound.projectile_008.play();
         if (game_o.player.side_weapon ==  9) sound.projectile_009.play();
         if (game_o.player.side_weapon == 10) sound.projectile_010.play();
         if (game_o.player.side_weapon == 11) sound.projectile_011.play();
         if (game_o.player.side_weapon == 12) sound.projectile_012.play();
         if (game_o.player.side_weapon == 13) sound.projectile_013.play();
         if (game_o.player.side_weapon == 14) sound.projectile_014.play();
         if (game_o.player.side_weapon == 15) sound.projectile_015.play();
         if (game_o.player.side_weapon == 16) sound.projectile_016.play();
         if (game_o.player.side_weapon == 17) sound.projectile_017.play();
         if (game_o.player.side_weapon == 18) sound.projectile_018.play();
         if (game_o.player.side_weapon == 19) sound.projectile_019.play();
         if (game_o.player.side_weapon == 20) sound.projectile_020.play();
         if (game_o.player.side_weapon == 21) sound.projectile_021.play();
         if (game_o.player.side_weapon == 22) sound.projectile_022.play();
         if (game_o.player.side_weapon == 23) sound.projectile_023.play();
         if (game_o.player.side_weapon == 24) sound.projectile_024.play();
         if (game_o.player.side_weapon == 25) sound.projectile_025.play();
         if (game_o.player.side_weapon == 26) sound.projectile_026.play();
         if (game_o.player.side_weapon == 27) sound.projectile_027.play();
         if (game_o.player.side_weapon == 28) sound.projectile_028.play();
         if (game_o.player.side_weapon == 29) sound.projectile_029.play();
         if (game_o.player.side_weapon == 30) sound.projectile_030.play();
         if (game_o.projectile[game_o.player.side_weapon].level == 0)
         {
            spawn_done = 0;
            for  (player_bullet_num = 0; player_bullet_num < MAX_BULLETS;player_bullet_num++)
            {
               if (!spawn_done and !game_o.player.bullet[player_bullet_num].active)
               {
                  spawn_player_bullet_num(player_bullet_num,4);
                  spawn_done = 1;
               }
            }
            spawn_done = 0;
            for  (player_bullet_num = 0; player_bullet_num < MAX_BULLETS;player_bullet_num++)
            {
               if (!spawn_done and !game_o.player.bullet[player_bullet_num].active)
               {
                  spawn_player_bullet_num(player_bullet_num,7);
                  spawn_done = 1;
               }
            }
         }
         if (game_o.projectile[game_o.player.side_weapon].level == 1)
         {
            spawn_done = 0;
            for  (player_bullet_num = 0; player_bullet_num < MAX_BULLETS;player_bullet_num++)
            {
               if (!spawn_done and !game_o.player.bullet[player_bullet_num].active)
               {
                  spawn_player_bullet_num(player_bullet_num,3);
                  spawn_done = 1;
               }
            }
            spawn_done = 0;
            for  (player_bullet_num = 0; player_bullet_num < MAX_BULLETS;player_bullet_num++)
            {
               if (!spawn_done and !game_o.player.bullet[player_bullet_num].active)
               {
                  spawn_player_bullet_num(player_bullet_num,5);
                  spawn_done = 1;
               }
            }
            spawn_done = 0;
            for  (player_bullet_num = 0; player_bullet_num < MAX_BULLETS;player_bullet_num++)
            {
               if (!spawn_done and !game_o.player.bullet[player_bullet_num].active)
               {
                  spawn_player_bullet_num(player_bullet_num,6);
                  spawn_done = 1;
               }
            }
            spawn_done = 0;
            for  (player_bullet_num = 0; player_bullet_num < MAX_BULLETS;player_bullet_num++)
            {
               if (!spawn_done and !game_o.player.bullet[player_bullet_num].active)
               {
                  spawn_player_bullet_num(player_bullet_num,8);
                  spawn_done = 1;
               }
            }
         }
         if (game_o.projectile[game_o.player.side_weapon].level >= 2)
         {
            spawn_done = 0;
            for  (player_bullet_num = 0; player_bullet_num < MAX_BULLETS;player_bullet_num++)
            {
               if (!spawn_done and !game_o.player.bullet[player_bullet_num].active)
               {
                  spawn_player_bullet_num(player_bullet_num,4);
                  spawn_done = 1;
               }
            }
            spawn_done = 0;
            for  (player_bullet_num = 0; player_bullet_num < MAX_BULLETS;player_bullet_num++)
            {
               if (!spawn_done and !game_o.player.bullet[player_bullet_num].active)
               {
                  spawn_player_bullet_num(player_bullet_num,7);
                  spawn_done = 1;
               }
            }
            spawn_done = 0;
            for  (player_bullet_num = 0; player_bullet_num < MAX_BULLETS;player_bullet_num++)
            {
               if (!spawn_done and !game_o.player.bullet[player_bullet_num].active)
               {
                  spawn_player_bullet_num(player_bullet_num,3);
                  spawn_done = 1;
               }
            }
            spawn_done = 0;
            for  (player_bullet_num = 0; player_bullet_num < MAX_BULLETS;player_bullet_num++)
            {
               if (!spawn_done and !game_o.player.bullet[player_bullet_num].active)
               {
                  spawn_player_bullet_num(player_bullet_num,5);
                  spawn_done = 1;
               }
            }
            spawn_done = 0;
            for  (player_bullet_num = 0; player_bullet_num < MAX_BULLETS;player_bullet_num++)
            {
               if (!spawn_done and !game_o.player.bullet[player_bullet_num].active)
               {
                  spawn_player_bullet_num(player_bullet_num,6);
                  spawn_done = 1;
               }
            }
            spawn_done = 0;
            for  (player_bullet_num = 0; player_bullet_num < MAX_BULLETS;player_bullet_num++)
            {
               if (!spawn_done and !game_o.player.bullet[player_bullet_num].active)
               {
                  spawn_player_bullet_num(player_bullet_num,8);
                  spawn_done = 1;
               }
            }
         }
      }
   }
 return(spawn_done);
}

/*----------------------------------------------------------------------------*/
int kill_player_bullet(void)
{
    for (int num_player_bullets = 0; num_player_bullets < MAX_BULLETS-1; num_player_bullets++)
    {
        kill_player_bullet(num_player_bullets);
    }
    return(1);
}

/*----------------------------------------------------------------------------*/
int kill_player_bullet(int player_bullet_num)
{
  if (player_bullet_num > MAX_BULLETS) player_bullet_num = MAX_BULLETS;
  game_o.player.bullet[player_bullet_num].active  = false;
  return player_bullet_num;
}

/*----------------------------------------------------------------------------*/
void init_player_bullets(void)
{
    for (int count = 0;count < MAX_BULLETS;count++)
    {
        game_o.player.bullet[count].active         =  false;
        game_o.player.bullet[count].x_pos          = -2.0f;
        game_o.player.bullet[count].y_pos          = -2.0f;
        game_o.player.bullet[count].x_speed        =  0.0f;
        game_o.player.bullet[count].y_speed        =  0.0f;
        game_o.player.bullet[count].width          =  0.05f;
        game_o.player.bullet[count].height          =  0.05f;
        game_o.player.bullet[count].warhead        =  0;
        game_o.player.bullet[count].location       =  0;
        game_o.player.bullet[count].wave_height     =  0.125f;
        game_o.player.bullet[count].wave_count     =  0.0f;
        game_o.player.bullet[count].wave_speed     =  0.0035f;
        game_o.player.bullet[count].wave_direction =  1;
    }
}

/*----------------------------------------------------------------------------*/
void proccess_player_bullets(void)
{
   int   random_temp     =  0;
   int   target_id       = -1;
   float target_distance = 10.0f;
   float temp_distance   =  0.0f;
   float x_temp_velocity =  0.0f;
   float y_temp_velocity =  0.0f;
   for (int player_bullet_num = 0; player_bullet_num < MAX_BULLETS; player_bullet_num++)
   {
      if (game_o.player.bullet[player_bullet_num].active)
      {
         switch (game_o.projectile[game_o.player.bullet[player_bullet_num].warhead].movement)
         {
            case 0://bullet moves in a straight line
               if (game_o.player.bullet[player_bullet_num].location < 3) game_o.player.bullet[player_bullet_num].x_pos += game_o.projectile[game_o.player.front_weapon].speed;
               else game_o.player.bullet[player_bullet_num].x_pos += game_o.projectile[game_o.player.side_weapon].speed;
               if (game_o.player.bullet[player_bullet_num].location == 3) game_o.player.bullet[player_bullet_num].y_pos += (game_o.projectile[game_o.player.bullet[player_bullet_num].warhead].speed / 1);
               if (game_o.player.bullet[player_bullet_num].location == 4) game_o.player.bullet[player_bullet_num].y_pos += (game_o.projectile[game_o.player.bullet[player_bullet_num].warhead].speed / 2);
               if (game_o.player.bullet[player_bullet_num].location == 5) game_o.player.bullet[player_bullet_num].y_pos += (game_o.projectile[game_o.player.bullet[player_bullet_num].warhead].speed / 3);
               if (game_o.player.bullet[player_bullet_num].location == 6) game_o.player.bullet[player_bullet_num].y_pos -= (game_o.projectile[game_o.player.bullet[player_bullet_num].warhead].speed / 3);
               if (game_o.player.bullet[player_bullet_num].location == 7) game_o.player.bullet[player_bullet_num].y_pos -= (game_o.projectile[game_o.player.bullet[player_bullet_num].warhead].speed / 2);
               if (game_o.player.bullet[player_bullet_num].location == 8) game_o.player.bullet[player_bullet_num].y_pos -= (game_o.projectile[game_o.player.bullet[player_bullet_num].warhead].speed / 1);
            break;
            case 1://bullet homes in on closest enemy
               target_id       = -1;
               target_distance = 10.0f;
               temp_distance   =  0.0f;
               for (int npc_count = 0; npc_count < MAX_NPCS; npc_count++)
               {
                  if (game_o.npc[npc_count].active)// find closest enemy
                  {
                     temp_distance = game.physics.distance_2D(game_o.player.x_pos,game_o.player.y_pos,game_o.npc[npc_count].x_pos,game_o.npc[npc_count].y_pos);
                     if (target_distance > temp_distance)
                     {
                        target_distance = temp_distance;
                        target_id = npc_count;
                     }
                  }
               }
               if (game_o.active_npc_count > 0)
               {
                  //calculate new vector / bullet speed
                  x_temp_velocity = (game_o.player.x_pos+2)-(game_o.npc[target_id].x_pos-2);
                  if (x_temp_velocity < 0) x_temp_velocity *= -1;
                  y_temp_velocity = (game_o.player.y_pos+2)-(game_o.npc[target_id].y_pos-2);
                  if (y_temp_velocity < 0) y_temp_velocity *= -1;
                  if (x_temp_velocity < y_temp_velocity)
                  {
                     x_temp_velocity = ((x_temp_velocity/y_temp_velocity) * game_o.projectile[game_o.player.bullet[player_bullet_num].warhead].speed) + game_o.projectile[game_o.player.bullet[player_bullet_num].warhead].speed;
                     y_temp_velocity = game_o.projectile[game_o.player.bullet[player_bullet_num].warhead].speed;
                  }
                  else
                  {
                     y_temp_velocity = ((x_temp_velocity/y_temp_velocity) * game_o.projectile[game_o.player.bullet[player_bullet_num].warhead].speed) + game_o.projectile[game_o.player.bullet[player_bullet_num].warhead].speed;
                     x_temp_velocity = game_o.projectile[game_o.player.bullet[player_bullet_num].warhead].speed;
                  }
                  if (game_o.player.bullet[player_bullet_num].x_pos < game_o.npc[target_id].x_pos) game_o.player.bullet[player_bullet_num].x_pos += x_temp_velocity;
                  if (game_o.player.bullet[player_bullet_num].x_pos > game_o.npc[target_id].x_pos) game_o.player.bullet[player_bullet_num].x_pos -= x_temp_velocity;
                  if (game_o.player.bullet[player_bullet_num].y_pos < game_o.npc[target_id].y_pos) game_o.player.bullet[player_bullet_num].y_pos += y_temp_velocity;
                  if (game_o.player.bullet[player_bullet_num].y_pos > game_o.npc[target_id].y_pos) game_o.player.bullet[player_bullet_num].y_pos -= y_temp_velocity;
               }
               else
               {
                  if (game_o.player.bullet[player_bullet_num].location < 3) game_o.player.bullet[player_bullet_num].x_pos += game_o.projectile[game_o.player.front_weapon].speed;
                  else game_o.player.bullet[player_bullet_num].x_pos += game_o.projectile[game_o.player.side_weapon].speed;
                  if (game_o.player.bullet[player_bullet_num].location == 3) game_o.player.bullet[player_bullet_num].y_pos += (game_o.projectile[game_o.player.bullet[player_bullet_num].warhead].speed / 1);
                  if (game_o.player.bullet[player_bullet_num].location == 4) game_o.player.bullet[player_bullet_num].y_pos += (game_o.projectile[game_o.player.bullet[player_bullet_num].warhead].speed / 2);
                  if (game_o.player.bullet[player_bullet_num].location == 5) game_o.player.bullet[player_bullet_num].y_pos += (game_o.projectile[game_o.player.bullet[player_bullet_num].warhead].speed / 3);
                  if (game_o.player.bullet[player_bullet_num].location == 6) game_o.player.bullet[player_bullet_num].y_pos -= (game_o.projectile[game_o.player.bullet[player_bullet_num].warhead].speed / 3);
                  if (game_o.player.bullet[player_bullet_num].location == 7) game_o.player.bullet[player_bullet_num].y_pos -= (game_o.projectile[game_o.player.bullet[player_bullet_num].warhead].speed / 2);
                  if (game_o.player.bullet[player_bullet_num].location == 8) game_o.player.bullet[player_bullet_num].y_pos -= (game_o.projectile[game_o.player.bullet[player_bullet_num].warhead].speed / 1);
               }
            break;
            case 2://bullet moves in a wave like pattern
               if (game_o.player.bullet[player_bullet_num].location < 3) game_o.player.bullet[player_bullet_num].x_pos += game_o.projectile[game_o.player.front_weapon].speed;
               else game_o.player.bullet[player_bullet_num].x_pos += game_o.projectile[game_o.player.side_weapon].speed;
               game_o.player.bullet[player_bullet_num].wave_count += game_o.player.bullet[player_bullet_num].wave_speed;
               if (game_o.player.bullet[player_bullet_num].wave_count >= game_o.player.bullet[player_bullet_num].wave_height)
               {
                  game_o.player.bullet[player_bullet_num].wave_count = 0.0f;
                  game_o.player.bullet[player_bullet_num].wave_direction = !game_o.player.bullet[player_bullet_num].wave_direction;
               }
               if (game_o.player.bullet[player_bullet_num].wave_direction == true) game_o.player.bullet[player_bullet_num].y_pos += game_o.player.bullet[player_bullet_num].wave_speed;
               else game_o.player.bullet[player_bullet_num].y_pos -= game_o.player.bullet[player_bullet_num].wave_speed;
               if (game_o.player.bullet[player_bullet_num].location == 3) game_o.player.bullet[player_bullet_num].y_pos += (game_o.projectile[game_o.player.bullet[player_bullet_num].warhead].speed / 1);
               if (game_o.player.bullet[player_bullet_num].location == 4) game_o.player.bullet[player_bullet_num].y_pos += (game_o.projectile[game_o.player.bullet[player_bullet_num].warhead].speed / 2);
               if (game_o.player.bullet[player_bullet_num].location == 5) game_o.player.bullet[player_bullet_num].y_pos += (game_o.projectile[game_o.player.bullet[player_bullet_num].warhead].speed / 3);
               if (game_o.player.bullet[player_bullet_num].location == 6) game_o.player.bullet[player_bullet_num].y_pos -= (game_o.projectile[game_o.player.bullet[player_bullet_num].warhead].speed / 3);
               if (game_o.player.bullet[player_bullet_num].location == 7) game_o.player.bullet[player_bullet_num].y_pos -= (game_o.projectile[game_o.player.bullet[player_bullet_num].warhead].speed / 2);
               if (game_o.player.bullet[player_bullet_num].location == 8) game_o.player.bullet[player_bullet_num].y_pos -= (game_o.projectile[game_o.player.bullet[player_bullet_num].warhead].speed / 1);
            break;
            case 3://bullet speeds up as it moves
               game_o.player.bullet[player_bullet_num].wave_count += game_o.player.bullet[player_bullet_num].wave_speed;
               if (game_o.player.bullet[player_bullet_num].location < 3)
               {
                  x_temp_velocity = game_o.player.bullet[player_bullet_num].wave_count + game_o.projectile[game_o.player.front_weapon].speed;
                  game_o.player.bullet[player_bullet_num].x_pos += x_temp_velocity;
               }
               else
               {
                 x_temp_velocity = game_o.player.bullet[player_bullet_num].wave_count + game_o.projectile[game_o.player.side_weapon].speed;
                 game_o.player.bullet[player_bullet_num].x_pos += x_temp_velocity;
               }
               if (game_o.player.bullet[player_bullet_num].location == 3) game_o.player.bullet[player_bullet_num].y_pos += ((game_o.projectile[game_o.player.bullet[player_bullet_num].warhead].speed*3) / 1);
               if (game_o.player.bullet[player_bullet_num].location == 4) game_o.player.bullet[player_bullet_num].y_pos += ((game_o.projectile[game_o.player.bullet[player_bullet_num].warhead].speed*3) / 2);
               if (game_o.player.bullet[player_bullet_num].location == 5) game_o.player.bullet[player_bullet_num].y_pos += ((game_o.projectile[game_o.player.bullet[player_bullet_num].warhead].speed*3) / 3);
               if (game_o.player.bullet[player_bullet_num].location == 6) game_o.player.bullet[player_bullet_num].y_pos -= ((game_o.projectile[game_o.player.bullet[player_bullet_num].warhead].speed*3) / 3);
               if (game_o.player.bullet[player_bullet_num].location == 7) game_o.player.bullet[player_bullet_num].y_pos -= ((game_o.projectile[game_o.player.bullet[player_bullet_num].warhead].speed*3) / 2);
               if (game_o.player.bullet[player_bullet_num].location == 8) game_o.player.bullet[player_bullet_num].y_pos -= ((game_o.projectile[game_o.player.bullet[player_bullet_num].warhead].speed*3) / 1);
            break;
            default:
               if (game_o.player.bullet[player_bullet_num].location < 3) game_o.player.bullet[player_bullet_num].x_pos += game_o.projectile[game_o.player.front_weapon].speed;
               else game_o.player.bullet[player_bullet_num].x_pos += game_o.projectile[game_o.player.side_weapon].speed;
               if (game_o.player.bullet[player_bullet_num].location == 3) game_o.player.bullet[player_bullet_num].y_pos += (game_o.projectile[game_o.player.bullet[player_bullet_num].warhead].speed / 1);
               if (game_o.player.bullet[player_bullet_num].location == 4) game_o.player.bullet[player_bullet_num].y_pos += (game_o.projectile[game_o.player.bullet[player_bullet_num].warhead].speed / 2);
               if (game_o.player.bullet[player_bullet_num].location == 5) game_o.player.bullet[player_bullet_num].y_pos += (game_o.projectile[game_o.player.bullet[player_bullet_num].warhead].speed / 3);
               if (game_o.player.bullet[player_bullet_num].location == 6) game_o.player.bullet[player_bullet_num].y_pos -= (game_o.projectile[game_o.player.bullet[player_bullet_num].warhead].speed / 3);
               if (game_o.player.bullet[player_bullet_num].location == 7) game_o.player.bullet[player_bullet_num].y_pos -= (game_o.projectile[game_o.player.bullet[player_bullet_num].warhead].speed / 2);
               if (game_o.player.bullet[player_bullet_num].location == 8) game_o.player.bullet[player_bullet_num].y_pos -= (game_o.projectile[game_o.player.bullet[player_bullet_num].warhead].speed / 1);
         }
         // if a bullet goes out of the screen kill it!!!!
         if (game_o.player.bullet[player_bullet_num].x_pos < -1.0f) kill_player_bullet(player_bullet_num);
         if (game_o.player.bullet[player_bullet_num].x_pos >  1.0f) kill_player_bullet(player_bullet_num);
         if (game_o.player.bullet[player_bullet_num].y_pos < -1.0f) kill_player_bullet(player_bullet_num);
         if (game_o.player.bullet[player_bullet_num].y_pos >  1.0f) kill_player_bullet(player_bullet_num);
         //---------- collision detection ---------
         for (int npc_count = 0; npc_count < MAX_NPCS; npc_count++)
         {
            if (game_o.npc[npc_count].active)// check player bullets / npc collisions...
            {
               if (game.physics.quadrangle_collision(game_o.npc[npc_count].x_pos,game_o.npc[npc_count].y_pos,game_o.npc[npc_count].width,game_o.npc[npc_count].height,game_o.player.bullet[player_bullet_num].x_pos,game_o.player.bullet[player_bullet_num].y_pos,game_o.player.bullet[player_bullet_num].width,game_o.player.bullet[player_bullet_num].height))
               {
                  if (game_o.player.bullet[player_bullet_num].location < 3) game_o.npc[npc_count].health -= game_o.projectile[game_o.player.front_weapon].damage;
                  else // hit npc ship, but not a kill
                  {
                      game_o.npc[npc_count].health -= game_o.projectile[game_o.player.side_weapon].damage;
                      spawn_explosion(game_o.npc[npc_count].x_pos,game_o.npc[npc_count].y_pos,0.1250f);
                      if (game_o.npc[npc_count].damaged <= 0) game_o.npc[npc_count].damaged = game_o.npc_damage_duration;
                  }
                  kill_player_bullet(player_bullet_num);
                  if (game_o.npc[npc_count].health <= 0)
                  {
                     if (game_o.player.bullet[player_bullet_num].location < 3) //level up our front weapon!
                     {
                        game_o.projectile[game_o.player.front_weapon].experience += ((game_o.enemy[game_o.npc[npc_count].type_npc].health / 10) * game_o.exp_rate);
                        if ((game_o.projectile[game_o.player.front_weapon].experience >= game_o.projectile[game_o.player.front_weapon].level_1) && (game_o.projectile[game_o.player.front_weapon].level == 0))
                        {
                            game_o.p_weapon_level_up.spawn();
                           game_o.projectile[game_o.player.front_weapon].level = 1;
                           game_o.projectile[game_o.player.front_weapon].experience = 0;
                        }
                        if ((game_o.projectile[game_o.player.front_weapon].experience >= game_o.projectile[game_o.player.front_weapon].level_2) && (game_o.projectile[game_o.player.front_weapon].level == 1))
                        {
                            game_o.p_weapon_level_up.spawn();
                           game_o.projectile[game_o.player.front_weapon].level = 2;
                           game_o.projectile[game_o.player.front_weapon].experience = 0;
                        }
                        if ((game_o.projectile[game_o.player.front_weapon].experience >= game_o.projectile[game_o.player.front_weapon].level_3) && (game_o.projectile[game_o.player.front_weapon].level == 2))
                        {
                            game_o.p_weapon_level_up.spawn();
                           game_o.projectile[game_o.player.front_weapon].level = 3;
                           game_o.projectile[game_o.player.front_weapon].experience = game_o.projectile[game_o.player.front_weapon].level_3;
                        }
                        if ((game_o.projectile[game_o.player.front_weapon].experience >= game_o.projectile[game_o.player.front_weapon].level_3) && (game_o.projectile[game_o.player.front_weapon].level == 3))
                        {
                           //game_o.p_weapon_level_up.spawn();
                           game_o.projectile[game_o.player.front_weapon].level = 3;
                           game_o.projectile[game_o.player.front_weapon].experience = game_o.projectile[game_o.player.front_weapon].level_3;
                        }
                     }
                     else  //level up our side weapon!
                     {
                        game_o.projectile[game_o.player.side_weapon].experience += (game_o.enemy[game_o.npc[npc_count].type_npc].health / game_o.exp_rate);
                        if ((game_o.projectile[game_o.player.side_weapon].experience >= game_o.projectile[game_o.player.side_weapon].level_1) && (game_o.projectile[game_o.player.side_weapon].level == 0))
                        {
                            game_o.p_weapon_level_up.spawn();
                           game_o.projectile[game_o.player.side_weapon].level = 1;
                           game_o.projectile[game_o.player.side_weapon].experience = 0;
                        }
                        if ((game_o.projectile[game_o.player.side_weapon].experience >= game_o.projectile[game_o.player.side_weapon].level_2) && (game_o.projectile[game_o.player.side_weapon].level == 1))
                        {
                            game_o.p_weapon_level_up.spawn();
                           game_o.projectile[game_o.player.side_weapon].level = 2;
                           game_o.projectile[game_o.player.side_weapon].experience = 0;
                        }
                        if ((game_o.projectile[game_o.player.side_weapon].experience >= game_o.projectile[game_o.player.side_weapon].level_3) && (game_o.projectile[game_o.player.side_weapon].level == 2))
                        {
                            game_o.p_weapon_level_up.spawn();
                           game_o.projectile[game_o.player.side_weapon].level = 3;
                           game_o.projectile[game_o.player.side_weapon].experience = game_o.projectile[game_o.player.side_weapon].level_3;
                        }
                        if ((game_o.projectile[game_o.player.side_weapon].experience >= game_o.projectile[game_o.player.side_weapon].level_3) && (game_o.projectile[game_o.player.side_weapon].level == 3))
                        {
                            //game_o.p_weapon_level_up.spawn();
                           game_o.projectile[game_o.player.side_weapon].level = 3;
                           game_o.projectile[game_o.player.side_weapon].experience = game_o.projectile[game_o.player.side_weapon].level_3;
                        }
                     }
                     random_temp = random_int();
                     if (random_temp <= game_o.coin_spawn_rate) //spawn coin
                     {
                        spawn_coin(game_o.npc[npc_count].x_pos,game_o.npc[npc_count].y_pos,(game_o.npc[npc_count].type_npc+1+random_dec()));
                     }
                     if ((random_temp > game_o.coin_spawn_rate) && (random_temp <= game_o.wexp_spawn_rate)) //spawn wexp
                     {
                        spawn_wexp(game_o.npc[npc_count].x_pos,game_o.npc[npc_count].y_pos,(game_o.npc[npc_count].type_npc+1+random_dec()));
                     }
                     if (random_temp > game_o.wexp_spawn_rate) //spawn null
                     {
                        ;
                     }
                     spawn_explosion(game_o.npc[npc_count].x_pos,game_o.npc[npc_count].y_pos,0.50f);
                     kill_npc(npc_count);
                     game_o.score += (game_o.npc[npc_count].type_npc + 1) * 10;
                     game_o.level_score += (game_o.npc[npc_count].type_npc + 1) * 10;
                     game_o.kills += 1;
                     game_o.level_kills += 1;
                  }
                 else sound.menu_move_00.play();
               }
               for (int npc_bullet_num =0;npc_bullet_num < MAX_BULLETS;npc_bullet_num++) // check player bullets / npc bullet collisions...
               {
                  if(game_o.npc[npc_count].bullet[npc_bullet_num].active)
                  {
                     if (game.physics.quadrangle_collision(game_o.npc[npc_count].bullet[npc_bullet_num].x_pos,game_o.npc[npc_count].bullet[npc_bullet_num].y_pos,game_o.npc[npc_count].bullet[npc_bullet_num].width,game_o.npc[npc_count].bullet[npc_bullet_num].height,game_o.player.bullet[player_bullet_num].x_pos,game_o.player.bullet[player_bullet_num].y_pos,game_o.player.bullet[player_bullet_num].width,game_o.player.bullet[player_bullet_num].height))
                     {
                     if (game_o.player.bullet[player_bullet_num].location < 3) //level up our front weapon!
                     {
                        game_o.projectile[game_o.player.front_weapon].experience += game_o.player.bullet[player_bullet_num].warhead;
                        if ((game_o.projectile[game_o.player.front_weapon].experience >= game_o.projectile[game_o.player.front_weapon].level_1) && (game_o.projectile[game_o.player.front_weapon].level == 0))
                        {
                            game_o.p_weapon_level_up.spawn();
                           game_o.projectile[game_o.player.front_weapon].level = 1;
                           game_o.projectile[game_o.player.front_weapon].experience = 0;
                        }
                        if ((game_o.projectile[game_o.player.front_weapon].experience >= game_o.projectile[game_o.player.front_weapon].level_2) && (game_o.projectile[game_o.player.front_weapon].level == 1))
                        {
                            game_o.p_weapon_level_up.spawn();
                           game_o.projectile[game_o.player.front_weapon].level = 2;
                           game_o.projectile[game_o.player.front_weapon].experience = 0;
                        }
                        if ((game_o.projectile[game_o.player.front_weapon].experience >= game_o.projectile[game_o.player.front_weapon].level_3) && (game_o.projectile[game_o.player.front_weapon].level == 2))
                        {
                            game_o.p_weapon_level_up.spawn();
                           game_o.projectile[game_o.player.front_weapon].level = 3;
                           game_o.projectile[game_o.player.front_weapon].experience = game_o.projectile[game_o.player.front_weapon].level_3;
                        }
                        if ((game_o.projectile[game_o.player.front_weapon].experience >= game_o.projectile[game_o.player.front_weapon].level_3) && (game_o.projectile[game_o.player.front_weapon].level == 3))
                        {
                            //game_o.p_weapon_level_up.spawn();
                           game_o.projectile[game_o.player.front_weapon].level = 3;
                           game_o.projectile[game_o.player.front_weapon].experience = game_o.projectile[game_o.player.front_weapon].level_3;
                        }
                     }
                     else  //level up our side weapon!
                     {
                        game_o.projectile[game_o.player.side_weapon].experience += game_o.player.bullet[player_bullet_num].warhead;
                        if ((game_o.projectile[game_o.player.side_weapon].experience >= game_o.projectile[game_o.player.side_weapon].level_1) && (game_o.projectile[game_o.player.side_weapon].level == 0))
                        {
                            game_o.p_weapon_level_up.spawn();
                           game_o.projectile[game_o.player.side_weapon].level = 1;
                           game_o.projectile[game_o.player.side_weapon].experience = 0;
                        }
                        if ((game_o.projectile[game_o.player.side_weapon].experience >= game_o.projectile[game_o.player.side_weapon].level_2) && (game_o.projectile[game_o.player.side_weapon].level == 1))
                        {
                            game_o.p_weapon_level_up.spawn();
                           game_o.projectile[game_o.player.side_weapon].level = 2;
                           game_o.projectile[game_o.player.side_weapon].experience = 0;
                        }
                        if ((game_o.projectile[game_o.player.side_weapon].experience >= game_o.projectile[game_o.player.side_weapon].level_3) && (game_o.projectile[game_o.player.side_weapon].level == 2))
                        {
                            game_o.p_weapon_level_up.spawn();
                           game_o.projectile[game_o.player.side_weapon].level = 3;
                           game_o.projectile[game_o.player.side_weapon].experience = game_o.projectile[game_o.player.side_weapon].level_3;
                        }
                        if ((game_o.projectile[game_o.player.side_weapon].experience >= game_o.projectile[game_o.player.side_weapon].level_3) && (game_o.projectile[game_o.player.side_weapon].level == 3))
                        {
                            //game_o.p_weapon_level_up.spawn();
                           game_o.projectile[game_o.player.side_weapon].level = 3;
                           game_o.projectile[game_o.player.side_weapon].experience = game_o.projectile[game_o.player.side_weapon].level_3;
                        }
                     }
                        spawn_explosion(game_o.npc[npc_count].bullet[npc_bullet_num].x_pos,game_o.npc[npc_count].bullet[npc_bullet_num].y_pos,0.25f);
                        kill_player_bullet(player_bullet_num);
                        kill_npc_bullet(npc_count,npc_bullet_num);
                        game_o.score += game_o.npc[npc_count].type_npc + 1;
                        game_o.level_score += game_o.npc[npc_count].type_npc + 1;;
                     }
                  }
               }
            }
         }
      }
   }
}
/*----------------------------------------------------------------------------*/

float thruster_offset(void)
{
   if (game_o.player.thrusters < 0) return(0.0f);
   else return(0.03f);
}

/*----------------------------------------------------------------------------*/
int process_player(int command)
{
    if (game_o.player.shield < 0.0f) game_o.player.shield = 0.0f;
    game_o.player.shield += game_o.player.shield_regen_rate; // shield regeneration
    if (game_o.player.shield > game_o.player.max_shield) game_o.player.shield = game_o.player.max_shield;
    game_o.player.health += game_o.player.health_regen_rate; // health regeneration
    if (game_o.player.health > game_o.player.max_health) game_o.player.health = game_o.player.max_health;
    game_o.immunity_delay_count++;
    if (game_o.immunity_delay_count < game_o.immunity_delay)
    {
        if ((game_o.immunity_delay_count >   0) && (game_o.immunity_delay_count <  16)) game_o.immunity_state = 0;
        if ((game_o.immunity_delay_count >  16) && (game_o.immunity_delay_count <  32)) game_o.immunity_state = 1;
        if ((game_o.immunity_delay_count >  32) && (game_o.immunity_delay_count <  48)) game_o.immunity_state = 0;
        if ((game_o.immunity_delay_count >  48) && (game_o.immunity_delay_count <  64)) game_o.immunity_state = 1;
        if ((game_o.immunity_delay_count >  64) && (game_o.immunity_delay_count <  80)) game_o.immunity_state = 0;
        if ((game_o.immunity_delay_count >  80) && (game_o.immunity_delay_count <  96)) game_o.immunity_state = 1;
        if ((game_o.immunity_delay_count >  96) && (game_o.immunity_delay_count < 112)) game_o.immunity_state = 0;
        if ((game_o.immunity_delay_count > 112) && (game_o.immunity_delay_count < 128)) game_o.immunity_state = 1;
        if ((game_o.immunity_delay_count > 128) && (game_o.immunity_delay_count < 144)) game_o.immunity_state = 0;
        if ((game_o.immunity_delay_count > 144) && (game_o.immunity_delay_count < 160)) game_o.immunity_state = 1;
        if ((game_o.immunity_delay_count > 160) && (game_o.immunity_delay_count < 176)) game_o.immunity_state = 0;
        if ((game_o.immunity_delay_count > 176) && (game_o.immunity_delay_count < 192)) game_o.immunity_state = 1;
        if ((game_o.immunity_delay_count > 192) && (game_o.immunity_delay_count < 208)) game_o.immunity_state = 0;
        if ((game_o.immunity_delay_count > 208) && (game_o.immunity_delay_count < 224)) game_o.immunity_state = 1;
        if ((game_o.immunity_delay_count > 224) && (game_o.immunity_delay_count < 240)) game_o.immunity_state = 0;
        if ((game_o.immunity_delay_count > 240) && (game_o.immunity_delay_count < 256)) game_o.immunity_state = 1;
    }
    if (game_o.immunity_delay_count > game_o.immunity_delay)
        {
            game_o.immunity_delay_count = game_o.immunity_delay;
            game_o.immune = false;
        }
   //level up our thrusters, only if used! :)
    if ((command == 3) && (game_o.player.thrusters >= 0) && (game_o.thruster[game_o.player.thrusters].level <= 2) && (game_o.player.thrusters >= 0))
    {
        game_o.thruster[game_o.player.thrusters].experience++;
        if (game_o.thruster[game_o.player.thrusters].level == 0)
        {
            if (game_o.thruster[game_o.player.thrusters].experience >= game_o.thruster[game_o.player.thrusters].level_1)
            {
                game_o.p_thrusters_level_up.spawn();
                game_o.thruster[game_o.player.thrusters].experience = 0;
                game_o.thruster[game_o.player.thrusters].level++;
            }
        }
        if (game_o.thruster[game_o.player.thrusters].level == 1)
        {
            if (game_o.thruster[game_o.player.thrusters].experience >= game_o.thruster[game_o.player.thrusters].level_2)
            {
                game_o.p_thrusters_level_up.spawn();
                game_o.thruster[game_o.player.thrusters].experience = 0;
                game_o.thruster[game_o.player.thrusters].level++;
            }
        }
        if (game_o.thruster[game_o.player.thrusters].level == 2)
        {
            if (game_o.thruster[game_o.player.thrusters].experience >= game_o.thruster[game_o.player.thrusters].level_3)
            {
                game_o.p_thrusters_level_up.spawn();
                game_o.thruster[game_o.player.thrusters].experience = 0;
                game_o.thruster[game_o.player.thrusters].level++;
            }
        }
    }
    if (game_o.level_end_phase == 1)
    {
        if (game_o.player.thrusters >= 0) // if we have thrusters
        {
            if (game_o.player.y_pos >  0.0f) game_o.player.y_pos -= (0.020 + game_o.thruster[game_o.player.thrusters].thrust);
            if (game_o.player.y_pos <  0.0f) game_o.player.y_pos += (0.020 + game_o.thruster[game_o.player.thrusters].thrust);
            game_o.player.x_pos += (0.020 + game_o.thruster[game_o.player.thrusters].thrust) + (game_o.level_end_count / 1000);
        }
        else // if we don't have thrusters
        {
            if (game_o.player.y_pos >  0.0f) game_o.player.y_pos -= (0.020);
            if (game_o.player.y_pos <  0.0f) game_o.player.y_pos += (0.020);
            game_o.player.x_pos += (0.020 + (game_o.level_end_count / 1000));
        }
    }
    else
    {
        if (game_o.player.thrusters >= 0) // if we have thrusters
        {
            switch (command)
            {
                case 1://Up
                    game_o.player.y_dir =  1;
                    game_o.player.y_vel += (0.0025f + game_o.thruster[game_o.player.thrusters].thrust + (0.0001f*game_o.thruster[game_o.player.thrusters].level));
                    if (game_o.player.y_vel > MAX_VELOCITY) game_o.player.y_vel = MAX_VELOCITY;
                break;
                case 2://Down
                    game_o.player.y_dir = -1;
                    game_o.player.y_vel -= (0.0025f + game_o.thruster[game_o.player.thrusters].thrust + (0.0001f*game_o.thruster[game_o.player.thrusters].level));
                    if (game_o.player.y_vel < (-1*MAX_VELOCITY)) game_o.player.y_vel = (-1*MAX_VELOCITY);
                break;
                case 3://right
                    game_o.player.x_dir =  1;
                    game_o.player.x_vel += (0.0025f + game_o.thruster[game_o.player.thrusters].thrust + (0.0001f*game_o.thruster[game_o.player.thrusters].level));
                    if (game_o.player.x_vel > MAX_VELOCITY) game_o.player.x_vel = MAX_VELOCITY;
                break;
                case 4://Left
                    game_o.player.x_dir = -1;
                    game_o.player.x_vel -= (0.0025f + game_o.thruster[game_o.player.thrusters].thrust + (0.0001f*game_o.thruster[game_o.player.thrusters].level));
                    if (game_o.player.x_vel < (-1*MAX_VELOCITY)) game_o.player.x_vel = (-1*MAX_VELOCITY);
                break;
                default:
                break;
            }
        }
        else // if we don't have thrusters
        {
            switch (command)
            {
                case 1://Up
                    game_o.player.y_dir =  1;
                    game_o.player.y_vel += (0.0025f + (0.0001f));
                    if (game_o.player.y_vel > MAX_VELOCITY) game_o.player.y_vel = MAX_VELOCITY;
                break;
                case 2://Down
                    game_o.player.y_dir = -1;
                    game_o.player.y_vel -= (0.0025f + (0.0001f));
                    if (game_o.player.y_vel < (-1*MAX_VELOCITY)) game_o.player.y_vel = (-1*MAX_VELOCITY);
                break;
                case 3://right
                    game_o.player.x_dir =  1;
                    game_o.player.x_vel += (0.0025f + (0.0001f));
                    if (game_o.player.x_vel > MAX_VELOCITY) game_o.player.x_vel = MAX_VELOCITY;
                break;
                case 4://Left
                    game_o.player.x_dir = -1;
                    game_o.player.x_vel -= (0.0025f + (0.0001));
                    if (game_o.player.x_vel < (-1*MAX_VELOCITY)) game_o.player.x_vel = (-1*MAX_VELOCITY);
                break;
                default:
                break;
            }
        }
        if (game_o.player.y_dir ==  1)
        {
            if (game_o.player.y_vel > 0.0f) game_o.player.y_vel -= 0.00025f;
            if (game_o.player.y_vel < 0.0f) game_o.player.y_vel  = 0.0f;
        };
        if (game_o.player.y_dir == -1)
        {
            if (game_o.player.y_vel < 0.0f) game_o.player.y_vel += 0.00025f;
            if (game_o.player.y_vel > 0.0f) game_o.player.y_vel  = 0.0f;
        };
        if (game_o.player.x_dir ==  1)
        {
            if (game_o.player.x_vel > 0.0f) game_o.player.x_vel -= 0.00025f;
            if (game_o.player.x_vel < 0.0f) game_o.player.x_vel  = 0.0f;
        };
        if (game_o.player.x_dir == -1)
        {
            if (game_o.player.x_vel < 0.0f) game_o.player.x_vel += 0.00025f;
            if (game_o.player.x_vel > 0.0f) game_o.player.x_vel  = 0.0f;
        };
        game_o.player.y_pos += game_o.player.y_vel;
        if (game_o.player.y_pos >  (1.0f - (game_o.player.height/2))) game_o.player.y_pos = (1.0f -(game_o.player.height/2));
        if (game_o.player.y_pos < -(1.0f - (game_o.player.height/2))) game_o.player.y_pos = -(1.0f -(game_o.player.height/2));
        game_o.player.x_pos += game_o.player.x_vel;
        if (game_o.player.x_pos >  (1.0f - (game_o.player.width/2))) game_o.player.x_pos = (1.0f -(game_o.player.width/2));
        if (game_o.player.x_pos < -(1.0f - (game_o.player.width/2) - thruster_offset())) game_o.player.x_pos = -(1.0f -(game_o.player.width/2) - thruster_offset());
    }
    if (!game_o.immune)
    {
        for (int npc_count = 0; npc_count < MAX_NPCS; npc_count++) // player - NPC collision?
        {
            if (game.physics.quadrangle_collision(game_o.npc[npc_count].x_pos,game_o.npc[npc_count].y_pos,game_o.npc[npc_count].width,game_o.npc[npc_count].height,game_o.player.x_pos,game_o.player.y_pos,game_o.player.width,game_o.player.height))
            {
                sound.shield_hit.play();//player shield hit
                game_o.npc[npc_count].health -= game_o.projectile[game_o.player.front_weapon].damage;
                game_o.player.shield -= ((game_o.enemy[game_o.npc[npc_count].type_npc].health / 5000.0f) - game_o.shield[game_o.player.front_shield].absorption);
                if (game_o.player.shield < 0.0f) game_o.player.health += game_o.player.shield;
                if (game_o.npc[npc_count].health < 0)
                {
                    spawn_explosion(game_o.npc[npc_count].x_pos,game_o.npc[npc_count].y_pos,0.50f);
                    kill_npc(npc_count);
                    game_o.score += (game_o.npc[npc_count].type_npc + 1) * 10;
                    game_o.level_score += (game_o.npc[npc_count].type_npc + 1) * 10;
                    game_o.kills += 1;
                    game_o.level_kills += 1;
                }
                else spawn_explosion(game_o.npc[npc_count].x_pos,game_o.npc[npc_count].y_pos,0.1250f);
            }
        }
    }
   return(0);
};

