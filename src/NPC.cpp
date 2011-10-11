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
#include "NPC.hpp"
#include "load_resources.hpp"
#include "game.hpp"
#include "misc.hpp"

extern  sound_type       sound;
extern  music_type       music;
extern  texture_type     texture;
extern  game_type  game_o;
extern  game_class game;

void init_enemies(bool re_init)
{
    if(re_init)
    {
        ;
    }
    else
    {
        game_o.enemy[0 ].image       = texture.ship_000.ref_number;
        game_o.enemy[0 ].health      = 05.0f;
        game_o.enemy[0 ].movement    = 0;//move straight forward
        game_o.enemy[0 ].weapon      = 6;
        game_o.enemy[0 ].projectiles = 1;
        game_o.enemy[0 ].size_h      = 0.1f;
        game_o.enemy[0 ].size_w      = 0.1f;
        game_o.enemy[0 ].sound       = 0;
        game_o.enemy[0 ].speed       = (game_o.projectile[game_o.enemy[0 ].weapon].speed/2) + 0.0005f;
        game_o.enemy[1 ].image       = texture.ship_001.ref_number;
        game_o.enemy[1 ].health      = 10.0f;
        game_o.enemy[1 ].movement    = 7;//move to position player was in on spawn
        game_o.enemy[1 ].weapon      = 7;
        game_o.enemy[1 ].projectiles = 2;
        game_o.enemy[1 ].size_h      = 0.15f;
        game_o.enemy[1 ].size_w      = 0.15f;
        game_o.enemy[1 ].sound       = 0;
        game_o.enemy[1 ].speed       = (game_o.projectile[game_o.enemy[1 ].weapon].speed/2) + 0.002f;
        game_o.enemy[2 ].image       = texture.ship_002.ref_number;
        game_o.enemy[2 ].health      = 15.0f;
        game_o.enemy[2 ].movement    = 5; //wave motion
        game_o.enemy[2 ].weapon      = 8;
        game_o.enemy[2 ].projectiles = 3;
        game_o.enemy[2 ].size_h      = 0.225f;
        game_o.enemy[2 ].size_w      = 0.225f;
        game_o.enemy[2 ].sound       = 0;
        game_o.enemy[2 ].speed       = (game_o.projectile[game_o.enemy[2 ].weapon].speed/2) - 0.0005f;
        game_o.enemy[3 ].image       = texture.ship_003.ref_number;
        game_o.enemy[3 ].health      = 100.0f;
        game_o.enemy[3 ].movement    = 8;//boss, avoid player, move up n down, stay far right  ---- Cantide ----
        game_o.enemy[3 ].weapon      = 9;
        game_o.enemy[3 ].projectiles = 6;
        game_o.enemy[3 ].size_h      = 0.8f;
        game_o.enemy[3 ].size_w      = 0.4f;
        game_o.enemy[3 ].sound       = 0;
        game_o.enemy[3 ].speed       = (game_o.projectile[game_o.enemy[3 ].weapon].speed/2);
        game_o.enemy[4 ].image       = texture.ship_004.ref_number;
        game_o.enemy[4 ].health      = 50.0f;
        game_o.enemy[4 ].movement    = 5;//wave motion
        game_o.enemy[4 ].weapon      = 10;
        game_o.enemy[4 ].projectiles = 2;
        game_o.enemy[4 ].size_h      = 0.2f;
        game_o.enemy[4 ].size_w      = 0.2f;
        game_o.enemy[4 ].sound       = 0;
        game_o.enemy[4 ].speed       = (game_o.projectile[game_o.enemy[4 ].weapon].speed/2) + 0.003f;
        game_o.enemy[5 ].image       = texture.ship_005.ref_number;
        game_o.enemy[5 ].health      = 30.0f;
        game_o.enemy[5 ].movement    = 3;
        game_o.enemy[5 ].weapon      = 11;
        game_o.enemy[5 ].projectiles = 4;
        game_o.enemy[5 ].size_h      = 0.15f;
        game_o.enemy[5 ].size_w      = 0.15f;
        game_o.enemy[5 ].sound       = 0;
        game_o.enemy[5 ].speed       = (game_o.projectile[game_o.enemy[5 ].weapon].speed/2) - 0.0005f;
        game_o.enemy[6 ].image       = texture.ship_006.ref_number;
        game_o.enemy[6 ].health      = 70.0f;
        game_o.enemy[6 ].movement    = 4; // wave
        game_o.enemy[6 ].weapon      = 12;
        game_o.enemy[6 ].projectiles = 6;
        game_o.enemy[6 ].size_h      = 0.225f;
        game_o.enemy[6 ].size_w      = 0.225f;
        game_o.enemy[6 ].sound       = 0;
        game_o.enemy[6 ].speed       = (game_o.projectile[game_o.enemy[6 ].weapon].speed/2);
        game_o.enemy[7 ].image       = texture.ship_007.ref_number;
        game_o.enemy[7 ].health      = 500.0f;
        game_o.enemy[7 ].movement    = 2;//boss   --- Wrathorn ---
        game_o.enemy[7 ].weapon      = 13;
        game_o.enemy[7 ].projectiles = 9;
        game_o.enemy[7 ].size_h      = 0.8f;
        game_o.enemy[7 ].size_w      = 0.4f;
        game_o.enemy[7 ].sound       = 0;
        game_o.enemy[7 ].speed       = (game_o.projectile[game_o.enemy[7 ].weapon].speed/2);
        game_o.enemy[8 ].image       = texture.ship_008.ref_number;
        game_o.enemy[8 ].health      = 80.0f;
        game_o.enemy[8 ].movement    = 0; // just move forward only
        game_o.enemy[8 ].weapon      = 14;
        game_o.enemy[8 ].projectiles = 2;
        game_o.enemy[8 ].size_h      = 0.175f;
        game_o.enemy[8 ].size_w      = 0.175f;
        game_o.enemy[8 ].sound       = 0;
        game_o.enemy[8 ].speed       = (game_o.projectile[game_o.enemy[8 ].weapon].speed/2);
        game_o.enemy[9 ].image       = texture.ship_009.ref_number;
        game_o.enemy[9 ].health      = 100.0f;
        game_o.enemy[9 ].movement    = 1; // home in on player
        game_o.enemy[9 ].weapon      = 15;
        game_o.enemy[9 ].projectiles = 4;
        game_o.enemy[9 ].size_h      = 0.25f;
        game_o.enemy[9 ].size_w      = 0.25f;
        game_o.enemy[9 ].sound       = 0;
        game_o.enemy[9 ].speed       = (game_o.projectile[game_o.enemy[9 ].weapon].speed/2);
        game_o.enemy[10].image       = texture.ship_010.ref_number;
        game_o.enemy[10].health      = 100.0f;
        game_o.enemy[10].movement    = 6;//fast wave motion
        game_o.enemy[10].weapon      = 16;
        game_o.enemy[10].projectiles = 6;
        game_o.enemy[10].size_h      = 0.215f;
        game_o.enemy[10].size_w      = 0.215f;
        game_o.enemy[10].sound       = 0;
        game_o.enemy[10].speed       = (game_o.projectile[game_o.enemy[10].weapon].speed/2);
        game_o.enemy[11].image       = texture.ship_011.ref_number;
        game_o.enemy[11].health      = 2000.0f;
        game_o.enemy[11].movement    = 2;//boss
        game_o.enemy[11].weapon      = 17;
        game_o.enemy[11].projectiles = 9;
        game_o.enemy[11].size_h      = 0.8f;
        game_o.enemy[11].size_w      = 0.4f;
        game_o.enemy[11].sound       = 0;
        game_o.enemy[11].speed       = (game_o.projectile[game_o.enemy[11].weapon].speed/2);
        game_o.enemy[12].image       = texture.ship_012.ref_number;
        game_o.enemy[12].health      = 120.0f;
        game_o.enemy[12].movement    = 4; // wave
        game_o.enemy[12].weapon      = 18;
        game_o.enemy[12].projectiles = 2;
        game_o.enemy[12].size_h      = 0.15f;
        game_o.enemy[12].size_w      = 0.15f;
        game_o.enemy[12].sound       = 0;
        game_o.enemy[12].speed       = (game_o.projectile[game_o.enemy[12].weapon].speed/2);   init_powerups();
        game_o.enemy[13].image       = texture.ship_013.ref_number;
        game_o.enemy[13].health      = 120.0f;
        game_o.enemy[13].movement    = 0; // only forward
        game_o.enemy[13].weapon      = 19;
        game_o.enemy[13].projectiles = 3;
        game_o.enemy[13].size_h      = 0.2f;
        game_o.enemy[13].size_w      = 0.1f;
        game_o.enemy[13].sound       = 0;
        game_o.enemy[13].speed       = (game_o.projectile[game_o.enemy[13].weapon].speed/2);   init_powerups();
        game_o.enemy[14].image       = texture.ship_014.ref_number;
        game_o.enemy[14].health      = 120.0f;
        game_o.enemy[14].movement    = 5; // wave action
        game_o.enemy[14].weapon      = 20;
        game_o.enemy[14].projectiles = 5;
        game_o.enemy[14].size_h      = 0.25f;
        game_o.enemy[14].size_w      = 0.2f;
        game_o.enemy[14].sound       = 0;
        game_o.enemy[14].speed       = (game_o.projectile[game_o.enemy[14].weapon].speed/2);   init_powerups();
        game_o.enemy[15].image       = texture.ship_015.ref_number;
        game_o.enemy[15].health      = 2000.0f;
        game_o.enemy[15].movement    = 2; //boss
        game_o.enemy[15].weapon      = 21;
        game_o.enemy[15].projectiles = 9;
        game_o.enemy[15].size_h      = 0.8f;
        game_o.enemy[15].size_w      = 0.4f;
        game_o.enemy[15].sound       = 0;
        game_o.enemy[15].speed       = (game_o.projectile[game_o.enemy[15].weapon].speed/2);
        game_o.enemy[16].image       = texture.ship_016.ref_number;
        game_o.enemy[16].health      = 130.0f;
        game_o.enemy[16].movement    = 6; // fast wave action
        game_o.enemy[16].weapon      = 22;
        game_o.enemy[16].projectiles = 2;
        game_o.enemy[16].size_h      = 0.2f;
        game_o.enemy[16].size_w      = 0.2f;
        game_o.enemy[16].sound       = 0;
        game_o.enemy[16].speed       = (game_o.projectile[game_o.enemy[16].weapon].speed/2);   init_powerups();
        game_o.enemy[17].image       = texture.ship_017.ref_number;
        game_o.enemy[17].health      = 140.0f;
        game_o.enemy[17].movement    = 1; // home in on player
        game_o.enemy[17].weapon      = 23;
        game_o.enemy[17].projectiles = 3;
        game_o.enemy[17].size_h      = 0.2f;
        game_o.enemy[17].size_w      = 0.2f;
        game_o.enemy[17].sound       = 0;
        game_o.enemy[17].speed       = (game_o.projectile[game_o.enemy[17].weapon].speed/2);   init_powerups();
        game_o.enemy[18].image       = texture.ship_018.ref_number;
        game_o.enemy[18].health      = 150.0f;
        game_o.enemy[18].movement    = 3; // avoid then attack
        game_o.enemy[18].weapon      = 24;
        game_o.enemy[18].projectiles = 5;
        game_o.enemy[18].size_h      = 0.2f;
        game_o.enemy[18].size_w      = 0.2f;
        game_o.enemy[18].sound       = 0;
        game_o.enemy[18].speed       = (game_o.projectile[game_o.enemy[18].weapon].speed/2);   init_powerups();
        game_o.enemy[19].image       = texture.ship_019.ref_number;
        game_o.enemy[19].health      = 3000.0f;
        game_o.enemy[19].movement    = 2; // boss
        game_o.enemy[19].weapon      = 25;
        game_o.enemy[19].projectiles = 9;
        game_o.enemy[19].size_h      = 0.8f;
        game_o.enemy[19].size_w      = 0.4f;
        game_o.enemy[19].sound       = 0;
        game_o.enemy[19].speed       = (game_o.projectile[game_o.enemy[19].weapon].speed/2);   init_npcs(0);
        game_o.enemy[20].image       = texture.ship_020.ref_number;
        game_o.enemy[20].health      = 150.0f;
        game_o.enemy[20].movement    = 1;//home in on player
        game_o.enemy[20].weapon      = 26;
        game_o.enemy[20].projectiles = 2;
        game_o.enemy[20].size_h      = 0.2f;
        game_o.enemy[20].size_w      = 0.2f;
        game_o.enemy[20].sound       = 0;
        game_o.enemy[20].speed       = (game_o.projectile[game_o.enemy[20].weapon].speed/2);   init_powerups();
        game_o.enemy[21].image       = texture.ship_021.ref_number;
        game_o.enemy[21].health      = 160.0f;
        game_o.enemy[21].movement    = 5; // wave action
        game_o.enemy[21].weapon      = 27;
        game_o.enemy[21].projectiles = 3;
        game_o.enemy[21].size_h      = 0.2f;
        game_o.enemy[21].size_w      = 0.2f;
        game_o.enemy[21].sound       = 0;
        game_o.enemy[21].speed       = (game_o.projectile[game_o.enemy[21].weapon].speed/2);   init_powerups();
        game_o.enemy[22].image       = texture.ship_022.ref_number;
        game_o.enemy[22].health      = 170.0f;
        game_o.enemy[22].movement    = 3; // avoid n attack
        game_o.enemy[22].weapon      = 28;
        game_o.enemy[22].projectiles = 5;
        game_o.enemy[22].size_h      = 0.2f;
        game_o.enemy[22].size_w      = 0.2f;
        game_o.enemy[22].sound       = 0;
        game_o.enemy[22].speed       = (game_o.projectile[game_o.enemy[22].weapon].speed/2);   init_powerups();
        game_o.enemy[23].image       = texture.ship_023.ref_number;
        game_o.enemy[23].health      = 6000.0f;
        game_o.enemy[23].movement    = 2;
        game_o.enemy[23].weapon      = 29;
        game_o.enemy[23].projectiles = 9;
        game_o.enemy[23].size_h      = 0.8f;
        game_o.enemy[23].size_w      = 0.4f;
        game_o.enemy[23].sound       = 0;
        game_o.enemy[23].speed       = (game_o.projectile[game_o.enemy[23].weapon].speed/2);   init_npcs(0);
        game_o.enemy[24].image       = texture.ship_024.ref_number;
        game_o.enemy[24].health      = 12000.0f;
        game_o.enemy[24].movement    = 2;
        game_o.enemy[24].weapon      = 30;
        game_o.enemy[24].projectiles = 9;
        game_o.enemy[24].size_h      = 1.2f;
        game_o.enemy[24].size_w      = 0.8f;
        game_o.enemy[24].sound       = 0;
        game_o.enemy[24].speed       = (game_o.projectile[game_o.enemy[24].weapon].speed/2);   init_npcs(0);   game_o.active_npc_count = 0;
    }
};

/*----------------------------------------------------------------------------*/
int init_active_npcs(void)
{
   for(int npc_count = 0; npc_count < MAX_NPCS; npc_count++)
   {
      game_o.active_npc[npc_count].number = -1;
      game_o.active_npc[npc_count].active = false;
   }
   return(0);
}
/*----------------------------------------------------------------------------*/
int check_active_npcs(void)
{
   for(int npc_count = 0; npc_count < MAX_NPCS; npc_count++)
   {
      if ((game_o.active_npc[npc_count].active) && (!game_o.npc[game_o.active_npc[npc_count].number].active)) game_o.active_npc[npc_count].active = false;
   }
}
/*----------------------------------------------------------------------------*/
int sort_active_npcs(void)
{
   check_active_npcs();
/*
   int  npc_num = 0;
   bool done = false;
   for(int npc_count = 0; npc_count < MAX_NPCS; npc_count++)
   {
      if (!game_o.active_npc[npc_count].active)
      {
         npc_num = npc_count;
         while ((npc_num < MAX_NPCS) && (!done))
         {
            game_o.active_npc[npc_num].active = game_o.active_npc[npc_num+1].active;
            game_o.active_npc[npc_num].number = game_o.active_npc[npc_num+1].number;
            npc_num++;
         }
      }
   }
   return(0);
*/
}
/*----------------------------------------------------------------------------*/
int add_active_npc  (int npc_num)
{
   bool spawn_done = 0;
   for  (int npc_count = 0; npc_count < MAX_NPCS; npc_count++)
   {
       if (!spawn_done && !game_o.active_npc[npc_count].active)
       {
           game_o.active_npc[npc_count].active  = true;
           game_o.active_npc[npc_count].number  = npc_num;
           game_o.active_npc_count++;
           spawn_done = 1;
       }
   }
   return(0);
}
/*----------------------------------------------------------------------------*/
int del_active_npc  (int npc_num)
{
   for(int npc_count = 0; npc_count < MAX_NPCS; npc_count++)
   {
       if (game_o.active_npc[npc_count].number == npc_num)
       {
           game_o.active_npc[npc_count].active  = false;
           game_o.active_npc[npc_count].number  = -1;
           game_o.active_npc_count--;
           if (game_o.active_npc_count < 0) game_o.active_npc_count = 0;
       }
   }
   sort_active_npcs();
   return(0);
}
/*----------------------------------------------------------------------------*/
int spawn_npc(float x_position, float y_position, int type_npc, int type_formation, float x_formation_ofset, float y_formation_ofset)
{
   bool  spawn_done = 0;
   for  (int npc_num = 0; npc_num < MAX_NPCS; npc_num++)
   {
       if (!spawn_done and !game_o.npc[npc_num].active)
       {
          game_o.npc[npc_num].active              = true;
          game_o.npc[npc_num].damaged             = 0;
          game_o.npc[npc_num].type_npc            = type_npc;
          game_o.npc[npc_num].x_pos               = x_position;
          game_o.npc[npc_num].y_pos               = y_position;
          game_o.npc[npc_num].formation_wave_no   = get_next_active_wave();
          game_o.npc[npc_num].formation_wave_axis = y_position;
          game_o.npc[npc_num].formation_target    = game_o.player.y_pos;
          game_o.npc[npc_num].formation_type      = type_formation;
          game_o.npc[npc_num].formation_ofset_x   = x_formation_ofset;
          game_o.npc[npc_num].formation_ofset_y   = y_formation_ofset;
          game_o.npc[npc_num].weapon              = game_o.enemy[game_o.npc[npc_num].type_npc].weapon;
          game_o.npc[npc_num].projectiles         = game_o.enemy[game_o.npc[npc_num].type_npc].projectiles;
          game_o.npc[npc_num].health              = game_o.enemy[game_o.npc[npc_num].type_npc].health;
          game_o.npc[npc_num].width               = game_o.enemy[game_o.npc[npc_num].type_npc].size_w;
          game_o.npc[npc_num].height              = game_o.enemy[game_o.npc[npc_num].type_npc].size_h;
          game_o.npc[npc_num].x_speed             = game_o.enemy[game_o.npc[npc_num].type_npc].speed;
          game_o.npc[npc_num].y_speed             = game_o.enemy[game_o.npc[npc_num].type_npc].speed;
          game_o.npc[npc_num].movement            = game_o.enemy[game_o.npc[npc_num].type_npc].movement;
          game_o.npc[npc_num].x_direction         = 1;
          game_o.npc[npc_num].y_direction         = 1;
          spawn_done = 1;
          add_active_npc(npc_num);
       }
   }
   return(1);
}
/*----------------------------------------------------------------------------*/
int kill_npc(int npc_num)
{
   game_o.npc[npc_num].active     = false;
   game_o.npc[npc_num].x_pos      = -2.0f;
   game_o.npc[npc_num].y_pos      = -2.0f;
   del_active_npc(npc_num);
   return(0);
}
/*----------------------------------------------------------------------------*/
int kill_active_npcs(void)
{
   for (int npc_count = 0; npc_count < MAX_NPCS; npc_count++) //kill all npcs
   {
       if (game_o.npc[npc_count].active) kill_npc(npc_count);
   }
}
/*----------------------------------------------------------------------------*/
int init_npcs(int type_npc)
{
   for (int npc_count = 0; npc_count < MAX_NPCS; npc_count++)
   {
      game_o.npc[npc_count].active              = false;
      game_o.npc[npc_count].damaged             = 0;
      game_o.npc[npc_count].type_npc            = type_npc;
      game_o.npc[npc_count].x_pos               = -2.0f;
      game_o.npc[npc_count].y_pos               = -2.0f;
      game_o.npc[npc_count].formation_wave_axis = 0.0f;
      game_o.npc[npc_count].formation_wave_no   = 0;
      game_o.npc[npc_count].formation_type      = 0;
      game_o.npc[npc_count].formation_ofset_x   = 0.0f;
      game_o.npc[npc_count].formation_ofset_y   = 0.0f;
      game_o.npc[npc_count].weapon              = game_o.enemy[game_o.npc[npc_count].type_npc].weapon;
      game_o.npc[npc_count].projectiles         = game_o.enemy[game_o.npc[npc_count].type_npc].projectiles;
      game_o.npc[npc_count].health              = game_o.enemy[game_o.npc[npc_count].type_npc].health;
      game_o.npc[npc_count].width               = game_o.enemy[game_o.npc[npc_count].type_npc].size_w;
      game_o.npc[npc_count].height              = game_o.enemy[game_o.npc[npc_count].type_npc].size_h;
      game_o.npc[npc_count].x_speed             = game_o.enemy[game_o.npc[npc_count].type_npc].speed;
      game_o.npc[npc_count].y_speed             = game_o.enemy[game_o.npc[npc_count].type_npc].speed;
      game_o.npc[npc_count].movement            = game_o.enemy[game_o.npc[npc_count].type_npc].movement;
      game_o.npc[npc_count].x_direction         = 1;
      game_o.npc[npc_count].y_direction         = 1;
   }
   init_npc_bullets();
   return(0);
}
/*----------------------------------------------------------------------------*/
int proccess_npcs(void)
{
   for (int npc_count = 0; npc_count < MAX_NPCS; npc_count++)
   {
      if  (game_o.npc[npc_count].damaged > 0) game_o.npc[npc_count].damaged--;
      else game_o.npc[npc_count].damaged = 0;
      if (game_o.npc[npc_count].active)
      {
         if (game_o.npc[npc_count].movement == 0)//straight line from right to left
         {
            game_o.npc[npc_count].x_pos -= game_o.npc[npc_count].x_speed;
            if (game_o.npc[npc_count].x_pos < -1.0f) kill_npc(npc_count);
         }
         if (game_o.npc[npc_count].movement == 1)//home in on player
         {
            game_o.npc[npc_count].x_pos -= game_o.npc[npc_count].x_speed;
            if (game_o.npc[npc_count].x_pos < -1.0f) kill_npc(npc_count);
            if ((game_o.npc[npc_count].y_pos-game_o.npc[npc_count].formation_ofset_y) < game_o.player.y_pos) game_o.npc[npc_count].y_pos += game_o.npc[npc_count].y_speed;
            if ((game_o.npc[npc_count].y_pos-game_o.npc[npc_count].formation_ofset_y) > game_o.player.y_pos) game_o.npc[npc_count].y_pos -= game_o.npc[npc_count].y_speed;
         }
         if (game_o.npc[npc_count].movement == 2)// move up and down,avoid player and stay far right
         {
            game_o.npc[npc_count].x_pos -= game_o.npc[npc_count].x_speed;
            if (game_o.npc[npc_count].x_pos < ((1.0f) - (game_o.npc[npc_count].width/2))) game_o.npc[npc_count].x_pos = ((1.0f)- (game_o.npc[npc_count].width/2));
            if (((game_o.player.y_pos + (game_o.player.height/2)) > (game_o.npc[npc_count].y_pos - (game_o.npc[npc_count].height/2))) && ((game_o.player.y_pos - (game_o.player.height/2)) < (game_o.npc[npc_count].y_pos + (game_o.npc[npc_count].height/2))))
            {
               if (game_o.npc[npc_count].y_pos > game_o.player.y_pos) game_o.npc[npc_count].y_pos += game_o.npc[npc_count].y_speed;
               if (game_o.npc[npc_count].y_pos < game_o.player.y_pos) game_o.npc[npc_count].y_pos -= game_o.npc[npc_count].y_speed;
            }
            else
            {
                if (game_o.npc[npc_count].y_direction ==  1) game_o.npc[npc_count].y_pos -= game_o.npc[npc_count].y_speed;
                if (game_o.npc[npc_count].y_direction == -1) game_o.npc[npc_count].y_pos += game_o.npc[npc_count].y_speed;
            }
            if ((game_o.npc[npc_count].y_pos - (game_o.npc[npc_count].height/2)) < -1.0f)
            {
               game_o.npc[npc_count].y_pos = ((-1.0f) + (game_o.npc[npc_count].height/2));
               game_o.npc[npc_count].y_direction *= -1;
            }
            if ((game_o.npc[npc_count].y_pos + (game_o.npc[npc_count].height/2)) >  1.0f)
            {
               game_o.npc[npc_count].y_pos = (( 1.0f) - (game_o.npc[npc_count].height/2));
               game_o.npc[npc_count].y_direction *= -1;
            }
         }
         if (game_o.npc[npc_count].movement == 3)// avoid player till border then home in on player
         {
            game_o.npc[npc_count].x_pos -= game_o.npc[npc_count].x_speed;
            if (game_o.npc[npc_count].x_pos < -1.0f) kill_npc(npc_count);
            if ((game_o.npc[npc_count].y_pos-game_o.npc[npc_count].formation_ofset_y) > game_o.player.y_pos) game_o.npc[npc_count].y_pos += game_o.npc[npc_count].y_speed;
            if ((game_o.npc[npc_count].y_pos-game_o.npc[npc_count].formation_ofset_y) < game_o.player.y_pos) game_o.npc[npc_count].y_pos -= game_o.npc[npc_count].y_speed;
            if (((game_o.npc[npc_count].y_pos-game_o.npc[npc_count].formation_ofset_y) - (game_o.npc[npc_count].height/2)) < -1.0f) game_o.npc[npc_count].movement = 1;
            if (((game_o.npc[npc_count].y_pos-game_o.npc[npc_count].formation_ofset_y) + (game_o.npc[npc_count].height/2)) >  1.0f) game_o.npc[npc_count].movement = 1;
         }
         if (game_o.npc[npc_count].movement == 4)// home in on player and then move to border
         {
            game_o.npc[npc_count].x_pos -= game_o.npc[npc_count].x_speed;
            if (game_o.npc[npc_count].x_pos <  -1.0f) kill_npc(npc_count);
            if ((game_o.npc[npc_count].y_pos-game_o.npc[npc_count].formation_ofset_y) <  game_o.player.y_pos) game_o.npc[npc_count].y_pos += game_o.npc[npc_count].y_speed;
            if ((game_o.npc[npc_count].y_pos-game_o.npc[npc_count].formation_ofset_y) >  game_o.player.y_pos) game_o.npc[npc_count].y_pos -= game_o.npc[npc_count].y_speed;
            if (((game_o.npc[npc_count].y_pos-game_o.npc[npc_count].formation_ofset_y) <= (game_o.player.y_pos+game_o.player.height)) && ((game_o.npc[npc_count].y_pos-game_o.npc[npc_count].formation_ofset_y) >= (game_o.player.y_pos-game_o.player.height))) game_o.npc[npc_count].movement = 3;
         }
         if (game_o.npc[npc_count].movement == 5)// move in an oscillating sine wave
         {
            game_o.npc[npc_count].x_pos -= game_o.npc[npc_count].x_speed;
            if (game_o.npc[npc_count].x_pos <  -1.0f) kill_npc(npc_count);
            if (game_o.npc[npc_count].y_direction ==  1) game_o.npc[npc_count].y_pos -= game_o.npc[npc_count].y_speed;
            if (game_o.npc[npc_count].y_direction == -1) game_o.npc[npc_count].y_pos += game_o.npc[npc_count].y_speed;
            if ((game_o.npc[npc_count].y_pos - (game_o.npc[npc_count].height/2)) < (game_o.npc[npc_count].formation_wave_axis - game_o.wave[game_o.npc[npc_count].formation_wave_no].wave_size)) game_o.npc[npc_count].y_direction *= -1;
            if ((game_o.npc[npc_count].y_pos + (game_o.npc[npc_count].height/2)) > (game_o.npc[npc_count].formation_wave_axis + game_o.wave[game_o.npc[npc_count].formation_wave_no].wave_size)) game_o.npc[npc_count].y_direction *= -1;
         }
         if (game_o.npc[npc_count].movement == 6)// move in a faster oscillating sine wave
         {
            game_o.npc[npc_count].x_pos -= game_o.npc[npc_count].x_speed;
            if (game_o.npc[npc_count].x_pos <  -1.0f) kill_npc(npc_count);
            if (game_o.npc[npc_count].y_direction ==  1) game_o.npc[npc_count].y_pos -= game_o.npc[npc_count].y_speed*2;
            if (game_o.npc[npc_count].y_direction == -1) game_o.npc[npc_count].y_pos += game_o.npc[npc_count].y_speed*2;
            if ((game_o.npc[npc_count].y_pos - (game_o.npc[npc_count].height/2)) < (game_o.npc[npc_count].formation_wave_axis - game_o.wave[game_o.npc[npc_count].formation_wave_no].wave_size)) game_o.npc[npc_count].y_direction *= -1;
            if ((game_o.npc[npc_count].y_pos + (game_o.npc[npc_count].height/2)) > (game_o.npc[npc_count].formation_wave_axis + game_o.wave[game_o.npc[npc_count].formation_wave_no].wave_size)) game_o.npc[npc_count].y_direction *= -1;
         }
         if (game_o.npc[npc_count].movement == 7)// home in on position player was in when spawned
         {
            game_o.npc[npc_count].x_pos -= game_o.npc[npc_count].x_speed;
            if (game_o.npc[npc_count].x_pos <  -1.0f) kill_npc(npc_count);
            if ((game_o.npc[npc_count].y_pos-game_o.npc[npc_count].formation_ofset_y) < game_o.npc[npc_count].formation_target) game_o.npc[npc_count].y_pos += game_o.npc[npc_count].y_speed;
            if ((game_o.npc[npc_count].y_pos-game_o.npc[npc_count].formation_ofset_y) > game_o.npc[npc_count].formation_target) game_o.npc[npc_count].y_pos -= game_o.npc[npc_count].y_speed;
         }
         if (game_o.npc[npc_count].movement == 8)// move in an oscillating sine wave and stay far right
         {
            game_o.npc[npc_count].x_pos -= game_o.npc[npc_count].x_speed;
            if (game_o.npc[npc_count].x_pos < ((1.0f) - (game_o.npc[npc_count].width/2))) game_o.npc[npc_count].x_pos = ((1.0f)- (game_o.npc[npc_count].width/2));
            if (game_o.npc[npc_count].y_direction ==  1) game_o.npc[npc_count].y_pos -= game_o.npc[npc_count].y_speed;
            if (game_o.npc[npc_count].y_direction == -1) game_o.npc[npc_count].y_pos += game_o.npc[npc_count].y_speed;
            if ((game_o.npc[npc_count].y_pos) < (-1.0f + (game_o.npc[npc_count].height/2)))
            {
                game_o.npc[npc_count].y_pos = (-1.0f + (game_o.npc[npc_count].height/2));
                game_o.npc[npc_count].y_direction *= -1;
            }
            if ((game_o.npc[npc_count].y_pos) > ( 1.0f - (game_o.npc[npc_count].height/2)))
            {
                game_o.npc[npc_count].y_pos = ( 1.0f - (game_o.npc[npc_count].height/2));
                game_o.npc[npc_count].y_direction *= -1;
            }
         }
      }
   }
}
/*----------------------------------------------------------------------------*/
int spawn_npc_bullet_num(int npc_num, int npc_bullet_num, int location)
{
   if (npc_bullet_num > MAX_BULLETS) npc_bullet_num  = MAX_BULLETS;
   game_o.npc[npc_num].bullet[npc_bullet_num].active   = true;
   game_o.npc[npc_num].bullet[npc_bullet_num].location = location;
   game_o.npc[npc_num].bullet[npc_bullet_num].warhead  = game_o.npc[npc_num].weapon;
   if (location == 0) game_o.npc[npc_num].bullet[npc_bullet_num].x_pos = (game_o.npc[npc_num].x_pos - (game_o.npc[npc_num].width/3));  // 1   straight - top
   if (location == 1) game_o.npc[npc_num].bullet[npc_bullet_num].x_pos = (game_o.npc[npc_num].x_pos - (game_o.npc[npc_num].width/2));  //  2  straight - mid
   if (location == 2) game_o.npc[npc_num].bullet[npc_bullet_num].x_pos = (game_o.npc[npc_num].x_pos - (game_o.npc[npc_num].width/3));  //   3 straight - bot
   if (location == 3) game_o.npc[npc_num].bullet[npc_bullet_num].x_pos = (game_o.npc[npc_num].x_pos - (game_o.npc[npc_num].width/2));  // 1   down     - top
   if (location == 4) game_o.npc[npc_num].bullet[npc_bullet_num].x_pos = (game_o.npc[npc_num].x_pos - (game_o.npc[npc_num].width/4));  //  2  down     - mid
   if (location == 5) game_o.npc[npc_num].bullet[npc_bullet_num].x_pos = (game_o.npc[npc_num].x_pos - (game_o.npc[npc_num].width/5));  //   3 down     - bot
   if (location == 6) game_o.npc[npc_num].bullet[npc_bullet_num].x_pos = (game_o.npc[npc_num].x_pos - (game_o.npc[npc_num].width/5));  // 1   up       - top
   if (location == 7) game_o.npc[npc_num].bullet[npc_bullet_num].x_pos = (game_o.npc[npc_num].x_pos - (game_o.npc[npc_num].width/4));  //  2  up       - mid
   if (location == 8) game_o.npc[npc_num].bullet[npc_bullet_num].x_pos = (game_o.npc[npc_num].x_pos - (game_o.npc[npc_num].width/2));  //   3 up       - bot

   if (location == 0) game_o.npc[npc_num].bullet[npc_bullet_num].y_pos = (game_o.npc[npc_num].y_pos + (game_o.npc[npc_num].height/3));  // 1   straight - top
   if (location == 1) game_o.npc[npc_num].bullet[npc_bullet_num].y_pos = (game_o.npc[npc_num].y_pos);                                //  2  straight - mid
   if (location == 2) game_o.npc[npc_num].bullet[npc_bullet_num].y_pos = (game_o.npc[npc_num].y_pos - (game_o.npc[npc_num].height/3));  //   3 straight - bot
   if (location == 3) game_o.npc[npc_num].bullet[npc_bullet_num].y_pos = (game_o.npc[npc_num].y_pos + (game_o.npc[npc_num].height/2));  // 1   down     - top
   if (location == 4) game_o.npc[npc_num].bullet[npc_bullet_num].y_pos = (game_o.npc[npc_num].y_pos + (game_o.npc[npc_num].height/5));  //  2  down     - mid
   if (location == 5) game_o.npc[npc_num].bullet[npc_bullet_num].y_pos = (game_o.npc[npc_num].y_pos - (game_o.npc[npc_num].height/4));  //   3 down     - bot
   if (location == 6) game_o.npc[npc_num].bullet[npc_bullet_num].y_pos = (game_o.npc[npc_num].y_pos + (game_o.npc[npc_num].height/4));  // 1   up       - top
   if (location == 7) game_o.npc[npc_num].bullet[npc_bullet_num].y_pos = (game_o.npc[npc_num].y_pos - (game_o.npc[npc_num].height/5));  //  2  up       - mid
   if (location == 8) game_o.npc[npc_num].bullet[npc_bullet_num].y_pos = (game_o.npc[npc_num].y_pos - (game_o.npc[npc_num].height/2));  //   3 up       - bot

   switch (game_o.projectile[game_o.npc[npc_num].bullet[npc_bullet_num].warhead].movement)
      {
         case 0: //staright
            game_o.npc[npc_num].bullet[npc_bullet_num].straight       = true;
            game_o.npc[npc_num].bullet[npc_bullet_num].homeing_00     = false;
            game_o.npc[npc_num].bullet[npc_bullet_num].homeing_01     = false;
            game_o.npc[npc_num].bullet[npc_bullet_num].wave           = false;
            game_o.npc[npc_num].bullet[npc_bullet_num].wave_height    = 0.0f;
            game_o.npc[npc_num].bullet[npc_bullet_num].wave_count     = 0.0f;
            game_o.npc[npc_num].bullet[npc_bullet_num].wave_speed     = 0.0f;
            game_o.npc[npc_num].bullet[npc_bullet_num].wave_direction = true;
         break;
         case 1: //homeing
            game_o.npc[npc_num].bullet[npc_bullet_num].straight       = false;
            game_o.npc[npc_num].bullet[npc_bullet_num].homeing_00     = true;
            game_o.npc[npc_num].bullet[npc_bullet_num].homeing_01     = false;
            game_o.npc[npc_num].bullet[npc_bullet_num].wave           = false;
            game_o.npc[npc_num].bullet[npc_bullet_num].wave_height    = 0.0f;
            game_o.npc[npc_num].bullet[npc_bullet_num].wave_count     = 0.0f;
            game_o.npc[npc_num].bullet[npc_bullet_num].wave_speed     = 0.0f;
            game_o.npc[npc_num].bullet[npc_bullet_num].wave_direction = true;
         break;
         case 2: //wave
            game_o.npc[npc_num].bullet[npc_bullet_num].straight       = false;
            game_o.npc[npc_num].bullet[npc_bullet_num].homeing_00     = false;
            game_o.npc[npc_num].bullet[npc_bullet_num].homeing_01     = false;
            game_o.npc[npc_num].bullet[npc_bullet_num].wave           = true;
            game_o.npc[npc_num].bullet[npc_bullet_num].wave_height    = game_o.projectile[game_o.npc[npc_num].bullet[npc_bullet_num].warhead].wave_size;
            game_o.npc[npc_num].bullet[npc_bullet_num].wave_count     = 0.0f;
            game_o.npc[npc_num].bullet[npc_bullet_num].wave_speed     = game_o.projectile[game_o.npc[npc_num].bullet[npc_bullet_num].warhead].wave_velocity;
            game_o.npc[npc_num].bullet[npc_bullet_num].wave_direction = 1;
         break;
         case 3: //super homeing
            game_o.npc[npc_num].bullet[npc_bullet_num].straight       = false;
            game_o.npc[npc_num].bullet[npc_bullet_num].homeing_00     = false;
            game_o.npc[npc_num].bullet[npc_bullet_num].homeing_01     = true;
            game_o.npc[npc_num].bullet[npc_bullet_num].wave           = false;
            game_o.npc[npc_num].bullet[npc_bullet_num].wave_height    = game_o.projectile[game_o.npc[npc_num].bullet[npc_bullet_num].warhead].wave_size;
            game_o.npc[npc_num].bullet[npc_bullet_num].wave_count     = 0.0f;
            game_o.npc[npc_num].bullet[npc_bullet_num].wave_speed     = game_o.projectile[game_o.npc[npc_num].bullet[npc_bullet_num].warhead].wave_velocity;
            game_o.npc[npc_num].bullet[npc_bullet_num].wave_direction = 1;
         break;
         case 4: //homeing wave
            game_o.npc[npc_num].bullet[npc_bullet_num].straight       = false;
            game_o.npc[npc_num].bullet[npc_bullet_num].homeing_00     = true;
            game_o.npc[npc_num].bullet[npc_bullet_num].homeing_01     = false;
            game_o.npc[npc_num].bullet[npc_bullet_num].wave           = true;
            game_o.npc[npc_num].bullet[npc_bullet_num].wave_height    = game_o.projectile[game_o.npc[npc_num].bullet[npc_bullet_num].warhead].wave_size;
            game_o.npc[npc_num].bullet[npc_bullet_num].wave_count     = 0.0f;
            game_o.npc[npc_num].bullet[npc_bullet_num].wave_speed     = game_o.projectile[game_o.npc[npc_num].bullet[npc_bullet_num].warhead].wave_velocity;
            game_o.npc[npc_num].bullet[npc_bullet_num].wave_direction = 1;
         break;
         default://staright
            game_o.npc[npc_num].bullet[npc_bullet_num].straight       = true;
            game_o.npc[npc_num].bullet[npc_bullet_num].homeing_00     = false;
            game_o.npc[npc_num].bullet[npc_bullet_num].homeing_01     = false;
            game_o.npc[npc_num].bullet[npc_bullet_num].wave           = false;
            game_o.npc[npc_num].bullet[npc_bullet_num].wave_height    = 0.0f;
            game_o.npc[npc_num].bullet[npc_bullet_num].wave_count     = 0.0f;
            game_o.npc[npc_num].bullet[npc_bullet_num].wave_speed     = 0.0f;
            game_o.npc[npc_num].bullet[npc_bullet_num].wave_direction = true;
        break;
      }
   return(0);
}
/*----------------------------------------------------------------------------*/
int spawn_npc_bullet(int npc_num, int location)
{
   bool spawn_done = 0;
   for (int npc_bullet_num = 0; npc_bullet_num < MAX_BULLETS; npc_bullet_num++)
   {
       if (!spawn_done and !game_o.npc[npc_num].bullet[npc_bullet_num].active)
       {
           spawn_npc_bullet_num(npc_num,npc_bullet_num,location);
           spawn_done = 1;
       }
   }
 return(0);
}
/*----------------------------------------------------------------------------*/
int kill_npc_bullet(int npc_num, int npc_bullet_num)
{
  if (npc_bullet_num > MAX_BULLETS) npc_bullet_num = MAX_BULLETS;
  game_o.npc[npc_num].bullet[npc_bullet_num].active  = false;
  game_o.npc[npc_num].bullet[npc_bullet_num].x_pos   = -2.0f;
  game_o.npc[npc_num].bullet[npc_bullet_num].y_pos   = -2.0f;
  return npc_bullet_num;
}
/*----------------------------------------------------------------------------*/
int init_npc_bullets(void)
{
   for (int npc_count = 0; npc_count < MAX_NPCS; npc_count++)
   {
      for (int bullet_count = 0; bullet_count < MAX_BULLETS; bullet_count++)
      {
         game_o.npc[npc_count].bullet[bullet_count].active   = false;
         game_o.npc[npc_count].bullet[bullet_count].x_pos    = -2.0f;
         game_o.npc[npc_count].bullet[bullet_count].y_pos    = -2.0f;
         game_o.npc[npc_count].bullet[bullet_count].x_speed  = game_o.enemy[game_o.npc[npc_count].type_npc].speed;
         game_o.npc[npc_count].bullet[bullet_count].y_speed  = game_o.enemy[game_o.npc[npc_count].type_npc].speed;
         game_o.npc[npc_count].bullet[bullet_count].width    = 0.05f;
         game_o.npc[npc_count].bullet[bullet_count].height   = 0.05f;
         game_o.npc[npc_count].bullet[bullet_count].warhead  = game_o.enemy[game_o.npc[npc_count].type_npc].weapon;
         game_o.npc[npc_count].bullet[bullet_count].location = 0;
      }
   }
   return(0);
}
/*----------------------------------------------------------------------------*/
int proccess_npc_bullets(void)
{
   for (int npc_count = 0; npc_count < MAX_NPCS; npc_count++)
   {
      for (int bullet_count = 0; bullet_count < MAX_BULLETS; bullet_count++)
      {
         if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].movement == 0) //bullet moves in "straight" lines
         {
            if (game_o.npc[npc_count].bullet[bullet_count].active) game_o.npc[npc_count].bullet[bullet_count].x_pos -= game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].speed;
            if (game_o.npc[npc_count].bullet[bullet_count].location == 3) game_o.npc[npc_count].bullet[bullet_count].y_pos += (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].speed / 1);
            if (game_o.npc[npc_count].bullet[bullet_count].location == 4) game_o.npc[npc_count].bullet[bullet_count].y_pos += (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].speed / 2);
            if (game_o.npc[npc_count].bullet[bullet_count].location == 5) game_o.npc[npc_count].bullet[bullet_count].y_pos += (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].speed / 3);
            if (game_o.npc[npc_count].bullet[bullet_count].location == 6) game_o.npc[npc_count].bullet[bullet_count].y_pos -= (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].speed / 3);
            if (game_o.npc[npc_count].bullet[bullet_count].location == 7) game_o.npc[npc_count].bullet[bullet_count].y_pos -= (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].speed / 2);
            if (game_o.npc[npc_count].bullet[bullet_count].location == 8) game_o.npc[npc_count].bullet[bullet_count].y_pos -= (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].speed / 1);
         }
         if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].movement == 1) //bullet homes in on player
         {
            if (game_o.npc[npc_count].bullet[bullet_count].active) game_o.npc[npc_count].bullet[bullet_count].x_pos -= game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].speed;
            if (game_o.npc[npc_count].bullet[bullet_count].active)
            {
                if (game_o.npc[npc_count].bullet[bullet_count].x_pos > game_o.player.x_pos)
                {
                   if (game_o.npc[npc_count].bullet[bullet_count].y_pos > game_o.player.y_pos) game_o.npc[npc_count].bullet[bullet_count].y_pos -= (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].speed/2);
                   if (game_o.npc[npc_count].bullet[bullet_count].y_pos < game_o.player.y_pos) game_o.npc[npc_count].bullet[bullet_count].y_pos += (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].speed/2);
                }
            }
         }
         if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].movement == 2) //bullet moves in a wave pattern
         {
             if (game_o.npc[npc_count].bullet[bullet_count].active) game_o.npc[npc_count].bullet[bullet_count].x_pos -= game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].speed;
             game_o.npc[npc_count].bullet[bullet_count].wave_count += game_o.npc[npc_count].bullet[bullet_count].wave_speed;
             if (game_o.npc[npc_count].bullet[bullet_count].wave_count >= game_o.npc[npc_count].bullet[bullet_count].wave_height)
             {
                game_o.npc[npc_count].bullet[bullet_count].wave_count = 0.0f;
                game_o.npc[npc_count].bullet[bullet_count].wave_direction = !game_o.npc[npc_count].bullet[bullet_count].wave_direction;
             }
            if (game_o.npc[npc_count].bullet[bullet_count].wave_direction == true) game_o.npc[npc_count].bullet[bullet_count].y_pos += game_o.npc[npc_count].bullet[bullet_count].wave_speed;
            else game_o.npc[npc_count].bullet[bullet_count].y_pos -= game_o.npc[npc_count].bullet[bullet_count].wave_speed;
         }
         if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].movement == 3) //bullet super homes in on player
         {
           if (game_o.npc[npc_count].bullet[bullet_count].active)
            {
                if (game_o.npc[npc_count].bullet[bullet_count].y_pos > game_o.player.y_pos) game_o.npc[npc_count].bullet[bullet_count].y_pos -= (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].speed/2);
                if (game_o.npc[npc_count].bullet[bullet_count].y_pos < game_o.player.y_pos) game_o.npc[npc_count].bullet[bullet_count].y_pos += (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].speed/2);
                if (game_o.npc[npc_count].bullet[bullet_count].x_pos > game_o.player.x_pos) game_o.npc[npc_count].bullet[bullet_count].x_pos -= (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].speed/2);
                if (game_o.npc[npc_count].bullet[bullet_count].x_pos < game_o.player.x_pos) game_o.npc[npc_count].bullet[bullet_count].x_pos += (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].speed/2);
            }
         }
         if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].movement == 4) //bullet homes in on player and moves in a wave pattern
         {
            if (game_o.npc[npc_count].bullet[bullet_count].active) game_o.npc[npc_count].bullet[bullet_count].x_pos -= game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].speed;
            if (game_o.npc[npc_count].bullet[bullet_count].active)
            {
                if (game_o.npc[npc_count].bullet[bullet_count].x_pos > game_o.player.x_pos)
                {
                   if (game_o.npc[npc_count].bullet[bullet_count].y_pos > (game_o.player.y_pos+(game_o.player.height/2))) game_o.npc[npc_count].bullet[bullet_count].y_pos -= (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].speed/2);
                   if (game_o.npc[npc_count].bullet[bullet_count].y_pos < (game_o.player.y_pos-(game_o.player.height/2))) game_o.npc[npc_count].bullet[bullet_count].y_pos += (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].speed/2);
                }
                game_o.npc[npc_count].bullet[bullet_count].wave_count += game_o.npc[npc_count].bullet[bullet_count].wave_speed;
                if (game_o.npc[npc_count].bullet[bullet_count].wave_count >= game_o.npc[npc_count].bullet[bullet_count].wave_height)
                {
                   game_o.npc[npc_count].bullet[bullet_count].wave_count = 0.0f;
                   game_o.npc[npc_count].bullet[bullet_count].wave_direction = !game_o.npc[npc_count].bullet[bullet_count].wave_direction;
                }
                if (game_o.npc[npc_count].bullet[bullet_count].wave_direction == true) game_o.npc[npc_count].bullet[bullet_count].y_pos += game_o.npc[npc_count].bullet[bullet_count].wave_speed;
                else game_o.npc[npc_count].bullet[bullet_count].y_pos -= game_o.npc[npc_count].bullet[bullet_count].wave_speed;
            }
         }
         if (game_o.npc[npc_count].bullet[bullet_count].x_pos < (-1.0f - game_o.npc[npc_count].bullet[bullet_count].width)) kill_npc_bullet(npc_count,bullet_count);
         // check player starship / npc bullet collisions...
         if ((game.physics.quadrangle_collision(game_o.player.x_pos,game_o.player.y_pos,game_o.player.width,game_o.player.height,game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,game_o.npc[npc_count].bullet[bullet_count].width,game_o.npc[npc_count].bullet[bullet_count].height)) && (!game_o.immune))
         {
            spawn_explosion(game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,0.125f);
            kill_npc_bullet(npc_count,bullet_count);
            sound.shield_hit.play();//player shield hit
            game_o.player.shield -= (0.005f+game_o.shield[game_o.player.front_shield].absorption+(0.0001f*game_o.shield[game_o.player.front_shield].level));
            if (game_o.player.shield < 0.0f) game_o.player.health += game_o.player.shield;
            if ((game_o.shield[game_o.player.front_shield].level <= 2) && (game_o.player.front_shield >= 0))
            {
                game_o.shield[game_o.player.front_shield].experience++;
                if (game_o.shield[game_o.player.front_shield].level == 0)
                {
                    if (game_o.shield[game_o.player.front_shield].experience >= game_o.shield[game_o.player.front_shield].level_1)
                    {
                       game_o.p_shield_level_up.spawn();
                       game_o.shield[game_o.player.front_shield].experience = 0;
                       game_o.shield[game_o.player.front_shield].level++;
                    }
                }
                if (game_o.shield[game_o.player.front_shield].level == 1)
                {
                    if (game_o.shield[game_o.player.front_shield].experience >= game_o.shield[game_o.player.front_shield].level_2)
                    {
                       game_o.p_shield_level_up.spawn();
                       game_o.shield[game_o.player.front_shield].experience = 0;
                       game_o.shield[game_o.player.front_shield].level++;
                    }
                }
                if (game_o.shield[game_o.player.front_shield].level == 2)
                {
                    if (game_o.shield[game_o.player.front_shield].experience >= game_o.shield[game_o.player.front_shield].level_3)
                    {
                       game_o.p_shield_level_up.spawn();
                       game_o.shield[game_o.player.front_shield].experience = 0;
                       game_o.shield[game_o.player.front_shield].level++;
                    }
                }
            }
         }
      }
   }
   return(0);
}
/*----------------------------------------------------------------------------*/

