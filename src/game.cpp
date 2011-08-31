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


#include <SDL/SDL.h>
#include "RAGE/rage.hpp"
#include "load_resources.hpp"
#include "game.hpp"
#include "misc.hpp"

extern  sound_type       sound;
extern  music_type       music;
extern  texture_type     texture;
extern  font_type        font;
extern  game_class       game;
        game_type        game_o;

int init_game(bool re_init)
{
   game.game_paused                       = false;
   game.game_active                       = false;
   game.game_resume                       = false;
   game.outr_active                       = false;
   game.menu_active                       = true;
   game.pdie_active                       = false;
   game.nlvl_active                       = false;

   game_o.anc_enabled                       = false;
   game_o.fps_enabled                       = false;
   game_o.npc_damage_duration               = 10;
   game_o.exp_rate                          = 5;
   game_o.coin_spawn_rate                   = 665.36 * 5;
   game_o.wexp_spawn_rate                   = 665.36 * 10;
   game_o.npc_spawn_rate                    = 256;
   game_o.npc_spawn_rate_count              = 0;
   game_o.paused.active                     = false;
   game_o.number_bombs                      = 0;
   game_o.bomb_delay                        = 32;
   game_o.bomb_delay_count                  = 0;
   game_o.immune                            = true;
   game_o.immunity_state                    = 0;
   game_o.immunity_delay                    = 256;
   game_o.immunity_delay_count              = 0;
   game_o.score                             = 0;
   game_o.kills                             = 0;
   game_o.level_kills                       = 0;
   game_o.level_spawened                    = 0;
   game_o.level_score                       = 0;
   game_o.victory_kills                     = 0;
   game_o.victory_spawened                  = 0;
   game_o.victory_score                     = 0;
   game_o.level_end_count                   = 0;
   game_o.level_end_time_out                = 300;
   game_o.level_end_time                    = false;
   game_o.level_end_phase                   = 0;
   game_o.level_end_display_active          = false;
   game_o.powerups_spawened                 = false;
   game_o.completed                         = 0;
   game_o.speed                             = 0.045f;
   game_o.fw_rof_count                      = 0;
   game_o.sw_rof_count                      = 0;
   game_o.player.x_pos                      =-0.9f;
   game_o.player.y_pos                      = 0.0f;
   game_o.player.x_dir                      = 0.0f;
   game_o.player.y_dir                      = 0.0f;
   game_o.player.x_vel                      = 0.0f;
   game_o.player.y_vel                      = 0.0f;
   game_o.player.width                      = 0.2f;
   game_o.player.hight                      = 0.2f;
   game_o.player.health                     = 0.100f;
   game_o.player.health_regen_rate          = 0.00005f;
   game_o.player.max_health                 = 0.100f;
   game_o.player.image                      = 278;
   game_o.player.front_weapon               = 0;
   game_o.player.side_weapon                = 0;
   game_o.player.front_shield               = -1;
   game_o.player.thrusters                  = -1;
   game_o.achivement.score                  = 0;
   game_o.achivement.kills                  = 0;
   game_o.achivement.score_level_1          = 625;
   game_o.achivement.score_level_2          = 1250;
   game_o.achivement.score_level_3          = 2500;
   game_o.achivement.score_level_4          = 5000;
   game_o.achivement.score_level_5          = 10000;
   game_o.achivement.score_level_6          = 20000;
   game_o.achivement.score_level_7          = 40000;
   game_o.achivement.kills_level_1          = 128;
   game_o.achivement.kills_level_2          = 256;
   game_o.achivement.kills_level_3          = 512;
   game_o.achivement.kills_level_4          = 1024;
   game_o.achivement.kills_level_5          = 2048;
   game_o.achivement.kills_level_6          = 4096;
   game_o.achivement.kills_level_7          = 8192;

    init_projectiles(re_init);
    init_shields    (re_init);
    init_thrusters  (re_init);
    init_enemies    (re_init);
    init_player_bullets();
    init_supportships();
    init_waves();
    init_coin();
    init_wexp();
    init_levels();
    init_explosions();
    return(0);
};


/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
bool level_completed(void)
{
   if ((game_o.level_kills >= game_o.victory_kills) && (game_o.level_spawened >= game_o.victory_spawened) && (game_o.level_score >= game_o.victory_score))
   {
       game_o.level_end_time = true;
       if (game_o.level_end_phase == 0)
       {
          game_o.level_end_count++;
          if (game_o.level_end_count >= game_o.level_end_time_out)
          {
              game_o.level_end_phase = 1;
              game_o.level_end_count = 0;
          }
       }
       if (game_o.level_end_phase == 1)
       {
          game_o.level_end_count++;
          if (game_o.level_end_count >= game_o.level_end_time_out)
          {
              game_o.level_end_phase = 2;
              game_o.level_end_count = 0;
          }
       }
       if (game_o.level_end_phase == 2) return(true);
       else return(false);
   }
   else return(false);
}

bool boss_level(void)
{
    if ((game_o.level ==  3) || (game_o.level ==  7) || (game_o.level == 11) || (game_o.level == 15) || (game_o.level == 19) || (game_o.level == 23) || (game_o.level == 24)) return (true);
    else return (false);
};

/*----------------------------------------------------------------------------*/
int process_game(void)
{
    bool return_data       = false;
   float temp_x            = 0.0f;
   float temp_y            = 0.0f;
   int   temp_r            = 0;
   game_o.player.health += game_o.player.health_regen_rate;
   if (game_o.player.health > game_o.player.max_health) game_o.player.health = game_o.player.max_health;
   game.background.process();
   return_data = false;
   if (game_o.player.y_pos >= 0.75f) return_data = game.background.scroll_up();
   if(return_data)
    {
            for (int npc_count = 0; npc_count < MAX_NPCS; npc_count++)
            {
                for (int bullet_count = 0; bullet_count < MAX_BULLETS; bullet_count++)
                {
                   game_o.npc[npc_count].bullet[bullet_count].y_pos  -= (game.background.get_scroll_y(1));
                }
                game_o.npc[npc_count].y_pos -= (game.background.get_scroll_y(1));
            }
            for (int player_bullet_num = 0; player_bullet_num < MAX_BULLETS; player_bullet_num++)
            {
               if (game_o.player.bullet[player_bullet_num].active)
               {
                  game_o.player.bullet[player_bullet_num].y_pos -= (game.background.get_scroll_y(1));
               }
            }
            for (int count =0;count < MAX_EXPLOSIONS;count++)
            {
               if(game_o.explosion[count].active)
               {
                  game_o.explosion[count].y_pos -= (game.background.get_scroll_y(1));
               }
            }
            for (int count = 0; count < MAX_WEXPS; count++)
            {
               if (game_o.wexp[count].active)
               {
                  game_o.wexp[count].y_pos -= (game.background.get_scroll_y(1));
               }
            }
            for (int count = 0; count < MAX_COINS; count++)
            {
               if (game_o.coin[count].active)
               {
                  game_o.coin[count].y_pos -= (game.background.get_scroll_y(1));
               }
            }
            for (int count = 1; count < MAX_POWERUPS; count++)
            {
               if (game_o.powerup[count].active)
               {
                  game_o.powerup[count].y_pos -= (game.background.get_scroll_y(1));
               }
            }
         }
   return_data = false;
   if (game_o.player.y_pos <= -0.75f) return_data = game.background.scroll_down();
   if(return_data)
    {
            for (int npc_count = 0; npc_count < MAX_NPCS; npc_count++)
            {
                for (int bullet_count = 0; bullet_count < MAX_BULLETS; bullet_count++)
                {
                   game_o.npc[npc_count].bullet[bullet_count].y_pos  += (game.background.get_scroll_y(1));
                }
                game_o.npc[npc_count].y_pos += (game.background.get_scroll_y(1));
            }
            for (int player_bullet_num = 0; player_bullet_num < MAX_BULLETS; player_bullet_num++)
            {
               if (game_o.player.bullet[player_bullet_num].active)
               {
                  game_o.player.bullet[player_bullet_num].y_pos += (game.background.get_scroll_y(1));
               }
            }
            for (int count =0;count < MAX_EXPLOSIONS;count++)
            {
               if(game_o.explosion[count].active)
               {
                  game_o.explosion[count].y_pos += (game.background.get_scroll_y(1));
               }
            }
            for (int count = 0; count < MAX_WEXPS; count++)
            {
               if (game_o.wexp[count].active)
               {
                  game_o.wexp[count].y_pos += (game.background.get_scroll_y(1));
               }
            }
            for (int count = 0; count < MAX_COINS; count++)
            {
               if (game_o.coin[count].active)
               {
                  game_o.coin[count].y_pos += (game.background.get_scroll_y(1));
               }
            }
            for (int count = 1; count < MAX_POWERUPS; count++)
            {
               if (game_o.powerup[count].active)
               {
                  game_o.powerup[count].y_pos += (game.background.get_scroll_y(1));
               }
            }
         }
   process_p_actinium_shields();
   process_p_blasters();
   process_p_burst_lasers();
   process_p_chain_guns();
   process_p_convolution_thrusters();
   process_p_health();
   process_p_ion_cannons();
   process_p_iridium_shileds();
   process_p_maelstrom_thrusters();
   process_p_plasma_rockets();
   process_p_rail_turrets();
   process_p_rubidium_shields();
   process_p_seismic_thrusters();
   process_p_shield_level_up();
   process_p_tantalum_shields();
   process_p_terbium_shields();
   process_p_thrusters_level_up();
   process_p_vortex_thrusters();
   process_p_weapon_level_up();
   process_a_score();
   process_a_kills();
   process_paused();
   process_loaded();
   process_saved();
   process_player(0);
   proccess_player_bullets();
   game_o.fw_rof_count++;
   if(game_o.fw_rof_count > game_o.projectile[game_o.player.front_weapon].rate_of_fire) game_o.fw_rof_count = game_o.projectile[game_o.player.front_weapon].rate_of_fire;
   game_o.sw_rof_count++;
   if(game_o.sw_rof_count > game_o.projectile[game_o.player.side_weapon].rate_of_fire)  game_o.sw_rof_count = game_o.projectile[game_o.player.side_weapon].rate_of_fire;
   proccess_npcs();
   process_waves();
   proccess_npc_bullets();
   proccess_explosions();
   proccess_powerups();
   proccess_coin();
   proccess_wexp();
    if (level_completed())
    {
        game.game_active      = false;
        game.nlvl_active      = true;
        game.music_next_track = true;
        game.background.set_data ( 1, 1, 1, 0.0f, 0.0f, 0.0015f, 0.0015f, 63);
        game.background.set_data ( 2, 1, 1, 0.0f, 0.0f, 0.0015f, 0.0015f, 63);
        game.background.set_data ( 3, 1, 1, 0.0f, 0.0f, 0.0020f, 0.0020f, 64);
        game.background.set_data ( 4, 1, 1, 0.0f, 0.0f, 0.0020f, 0.0020f, 64);
        game.background.set_movement_type(BOUNCE);
    }
   if  (random(game_o.powerup[1 ].spawn_rate) <= 5) spawn_powerup(1.0f,random_GLcoord(), 1);//spawn health powerup
   if ((random(game_o.powerup[8 ].spawn_rate) <= 5)&& (!boss_level())) spawn_powerup(1.0f,random_GLcoord(), 8);//spawn bomb powerup

   if ((game_o.level >=  4) && (random(game_o.powerup[9 ].spawn_rate) <= 2)) spawn_powerup(1.0f,random_GLcoord(), 9);//spawn supportship 0 powerup
   if ((game_o.level >=  7) && (random(game_o.powerup[10].spawn_rate) <= 2)) spawn_powerup(1.0f,random_GLcoord(),10);//spawn supportship 1 powerup
   if ((game_o.level >= 11) && (random(game_o.powerup[11].spawn_rate) <= 2)) spawn_powerup(1.0f,random_GLcoord(),11);//spawn supportship 2 powerup
   if ((game_o.level >= 15) && (random(game_o.powerup[12].spawn_rate) <= 2)) spawn_powerup(1.0f,random_GLcoord(),12);//spawn supportship 3 powerup

   if ((game_o.shield[game_o.player.front_shield].level  < 3) && (random(game_o.powerup[2].spawn_rate) == 5)) spawn_powerup(1.0f,random_GLcoord(),2);//spawn shield lvl powerup
   if ((game_o.thruster[game_o.player.thrusters].level   < 3) && (random(game_o.powerup[2].spawn_rate) == 5)) spawn_powerup(1.0f,random_GLcoord(),4);//spawn thruster lvl powerup
   // if player missed boss weapon drops enable random spawning of powerups to keep consistency
   if ((game_o.level >=  4) && (!game_o.projectile[1].active) && (random(game_o.powerup[7].spawn_rate) == 5)) spawn_powerup(1.0f,random_GLcoord(),7); // spawn new weapon
   if ((game_o.level >=  7) && (!game_o.projectile[2].active) && (random(game_o.powerup[7].spawn_rate) == 5)) spawn_powerup(1.0f,random_GLcoord(),7); // spawn new weapon
   if ((game_o.level >= 11) && (!game_o.projectile[3].active) && (random(game_o.powerup[7].spawn_rate) == 5)) spawn_powerup(1.0f,random_GLcoord(),7); // spawn new weapon
   if ((game_o.level >= 15) && (!game_o.projectile[4].active) && (random(game_o.powerup[7].spawn_rate) == 5)) spawn_powerup(1.0f,random_GLcoord(),7); // spawn new weapon
   if ((game_o.level >= 19) && (!game_o.projectile[5].active) && (random(game_o.powerup[7].spawn_rate) == 5)) spawn_powerup(1.0f,random_GLcoord(),7); // spawn new weapon

   if ((game_o.level >=  7) && (!game_o.shield[0].active) && (random(game_o.powerup[3].spawn_rate) == 5)) spawn_powerup(1.0f,random_GLcoord(),3); // spawn new shield
   if ((game_o.level >= 11) && (!game_o.shield[1].active) && (random(game_o.powerup[3].spawn_rate) == 5)) spawn_powerup(1.0f,random_GLcoord(),3); // spawn new shield
   if ((game_o.level >= 15) && (!game_o.shield[2].active) && (random(game_o.powerup[3].spawn_rate) == 5)) spawn_powerup(1.0f,random_GLcoord(),3); // spawn new shield
   if ((game_o.level >= 19) && (!game_o.shield[3].active) && (random(game_o.powerup[3].spawn_rate) == 5)) spawn_powerup(1.0f,random_GLcoord(),3); // spawn new shield
   if ((game_o.level >= 23) && (!game_o.shield[4].active) && (random(game_o.powerup[3].spawn_rate) == 5)) spawn_powerup(1.0f,random_GLcoord(),3); // spawn new shield

   if ((game_o.level >= 15) && (!game_o.thruster[0].active) && (random(game_o.powerup[5].spawn_rate) == 5)) spawn_powerup(1.0f,random_GLcoord(),5); // spawn new thruster
   if ((game_o.level >= 19) && (!game_o.thruster[1].active) && (random(game_o.powerup[5].spawn_rate) == 5)) spawn_powerup(1.0f,random_GLcoord(),5); // spawn new thruster
   if ((game_o.level >= 23) && (!game_o.thruster[2].active) && (random(game_o.powerup[5].spawn_rate) == 5)) spawn_powerup(1.0f,random_GLcoord(),5); // spawn new thruster
   game_o.npc_spawn_rate_count++;
   game_o.npc_spawn_rate_count += random_dec()/4;
   if (game_o.npc_spawn_rate_count >= game_o.npc_spawn_rate)
   {
      game_o.npc_spawn_rate_count = 0;
      if ((!game_o.level_boss_level) && (!game_o.level_end_time) && (game_o.wave_spawnable)) spawn_wave();
      if (game_o.level_boss_level && (game_o.level_spawened == 0))
      {
         spawn_npc(1.0f,random_GLcoord(),game_o.level_npc_type,0,0.0f,0.0f);
         game_o.level_spawened += 1;
      }
   }
   for (int npc_count = 0; npc_count < MAX_NPCS; npc_count++)//npc spawn bullet
   {
      if (game_o.npc[npc_count].active)
      {
         if (random(game_o.npc_projectile_spawn_rate) == 5)
         {
            if (game_o.npc[npc_count].projectiles == 1)
            {
               spawn_npc_bullet(npc_count,1);
            }
            if (game_o.npc[npc_count].projectiles == 2)
            {
               spawn_npc_bullet(npc_count,0);
               spawn_npc_bullet(npc_count,2);
            }
            if (game_o.npc[npc_count].projectiles == 3)
            {
               spawn_npc_bullet(npc_count,0);
               spawn_npc_bullet(npc_count,1);
               spawn_npc_bullet(npc_count,2);
            }
            if (game_o.npc[npc_count].projectiles == 4)
            {
               spawn_npc_bullet(npc_count,0);
               spawn_npc_bullet(npc_count,2);
               spawn_npc_bullet(npc_count,5);
               spawn_npc_bullet(npc_count,6);
            }
            if (game_o.npc[npc_count].projectiles == 5)
            {
               spawn_npc_bullet(npc_count,1);
               spawn_npc_bullet(npc_count,5);
               spawn_npc_bullet(npc_count,6);
               spawn_npc_bullet(npc_count,7);
               spawn_npc_bullet(npc_count,8);
            }
            if (game_o.npc[npc_count].projectiles == 6)
            {
               spawn_npc_bullet(npc_count,0);
               spawn_npc_bullet(npc_count,2);
               spawn_npc_bullet(npc_count,3);
               spawn_npc_bullet(npc_count,5);
               spawn_npc_bullet(npc_count,6);
               spawn_npc_bullet(npc_count,8);
            }
            if (game_o.npc[npc_count].projectiles == 7)
            {
               spawn_npc_bullet(npc_count,1);
               spawn_npc_bullet(npc_count,3);
               spawn_npc_bullet(npc_count,4);
               spawn_npc_bullet(npc_count,5);
               spawn_npc_bullet(npc_count,6);
               spawn_npc_bullet(npc_count,7);
               spawn_npc_bullet(npc_count,8);
            }
            if (game_o.npc[npc_count].projectiles == 8)
            {
               spawn_npc_bullet(npc_count,0);
               spawn_npc_bullet(npc_count,2);
               spawn_npc_bullet(npc_count,3);
               spawn_npc_bullet(npc_count,4);
               spawn_npc_bullet(npc_count,5);
               spawn_npc_bullet(npc_count,6);
               spawn_npc_bullet(npc_count,7);
               spawn_npc_bullet(npc_count,8);
            }
            if (game_o.npc[npc_count].projectiles == 9)
            {
               spawn_npc_bullet(npc_count,0);
               spawn_npc_bullet(npc_count,1);
               spawn_npc_bullet(npc_count,2);
               spawn_npc_bullet(npc_count,3);
               spawn_npc_bullet(npc_count,4);
               spawn_npc_bullet(npc_count,5);
               spawn_npc_bullet(npc_count,6);
               spawn_npc_bullet(npc_count,7);
               spawn_npc_bullet(npc_count,8);
            }
         if (game_o.npc[npc_count].bullet[0].warhead ==  0) sound.projectile_000.play();
         if (game_o.npc[npc_count].bullet[0].warhead ==  1) sound.projectile_001.play();
         if (game_o.npc[npc_count].bullet[0].warhead ==  2) sound.projectile_002.play();
         if (game_o.npc[npc_count].bullet[0].warhead ==  3) sound.projectile_003.play();
         if (game_o.npc[npc_count].bullet[0].warhead ==  4) sound.projectile_004.play();
         if (game_o.npc[npc_count].bullet[0].warhead ==  5) sound.projectile_005.play();
         if (game_o.npc[npc_count].bullet[0].warhead ==  6) sound.projectile_006.play();
         if (game_o.npc[npc_count].bullet[0].warhead ==  7) sound.projectile_007.play();
         if (game_o.npc[npc_count].bullet[0].warhead ==  8) sound.projectile_008.play();
         if (game_o.npc[npc_count].bullet[0].warhead ==  9) sound.projectile_009.play();
         if (game_o.npc[npc_count].bullet[0].warhead == 10) sound.projectile_010.play();
         if (game_o.npc[npc_count].bullet[0].warhead == 11) sound.projectile_011.play();
         if (game_o.npc[npc_count].bullet[0].warhead == 12) sound.projectile_012.play();
         if (game_o.npc[npc_count].bullet[0].warhead == 13) sound.projectile_013.play();
         if (game_o.npc[npc_count].bullet[0].warhead == 14) sound.projectile_014.play();
         if (game_o.npc[npc_count].bullet[0].warhead == 15) sound.projectile_015.play();
         if (game_o.npc[npc_count].bullet[0].warhead == 16) sound.projectile_016.play();
         if (game_o.npc[npc_count].bullet[0].warhead == 17) sound.projectile_017.play();
         if (game_o.npc[npc_count].bullet[0].warhead == 18) sound.projectile_018.play();
         if (game_o.npc[npc_count].bullet[0].warhead == 19) sound.projectile_019.play();
         if (game_o.npc[npc_count].bullet[0].warhead == 20) sound.projectile_020.play();
         if (game_o.npc[npc_count].bullet[0].warhead == 21) sound.projectile_021.play();
         if (game_o.npc[npc_count].bullet[0].warhead == 22) sound.projectile_022.play();
         if (game_o.npc[npc_count].bullet[0].warhead == 23) sound.projectile_023.play();
         if (game_o.npc[npc_count].bullet[0].warhead == 24) sound.projectile_024.play();
         if (game_o.npc[npc_count].bullet[0].warhead == 25) sound.projectile_025.play();
         if (game_o.npc[npc_count].bullet[0].warhead == 26) sound.projectile_026.play();
         if (game_o.npc[npc_count].bullet[0].warhead == 27) sound.projectile_027.play();
         if (game_o.npc[npc_count].bullet[0].warhead == 28) sound.projectile_028.play();
         if (game_o.npc[npc_count].bullet[0].warhead == 29) sound.projectile_029.play();
         if (game_o.npc[npc_count].bullet[0].warhead == 30) sound.projectile_030.play();
         }
      }
   }
   if (game_o.level_end_time) process_d_level_end();
   if ((game_o.level_end_time) && (game_o.level_end_phase == 0)) //level outro
   {
     game_o.player.health = 0.100f;
     for (int npc_count = 0; npc_count < MAX_NPCS; npc_count++) //kill all npcs
     {
         sound.explosion_005.play();
         if (game_o.npc[npc_count].active)
         {
            spawn_explosion(game_o.npc[npc_count].x_pos,game_o.npc[npc_count].y_pos,0.50f);
            kill_npc(npc_count);
         }
     }
     for (int npc_count = 0; npc_count < MAX_NPCS; npc_count++)//kill all npc bullets
     {
        for (int bullet_count = 0; bullet_count < MAX_BULLETS; bullet_count++)
        {
           if (game_o.npc[npc_count].bullet[bullet_count].active)
           {
              spawn_explosion(game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,0.125f);
              kill_npc_bullet(npc_count,bullet_count);
           }
        }
     }
     temp_r = random_int();
     if (temp_r < 6000) //spawn explosion with coin / wexp
     {
        temp_x = random_double();
        temp_y = random_double();
        temp_r = random_int();
        if (temp_r < 8000) //spawn explosion + coin
        {
           spawn_explosion(temp_x,temp_y,0.25f);
           sound.explosion_005.play();
           spawn_coin(temp_x,temp_y,1.5f);
        }
        if ((temp_r > 8000) && (temp_r < 16000)) //spawn explosion + coin
        {
           spawn_explosion(temp_x,temp_y,0.25f);
           sound.explosion_005.play();
           spawn_wexp(temp_x,temp_y,1.5f);
        }
     }
     if (!game_o.powerups_spawened)
     {
        if ((game_o.level_boss_level) && (game_o.level_locked[game_o.level + 1]))//if its first time to kill a boss spawn some powerups!!
        {
            if (game_o.level == 3)
            {
                spawn_powerup(1.0f,random_GLcoord(),1);//spawn health powerup
                spawn_powerup(1.0f,random_GLcoord(),4);//spawn thruster lvl powerup
                spawn_powerup(1.0f,random_GLcoord(),7);//new weapon
            }
            if (game_o.level == 7)
            {
                spawn_powerup(1.0f,random_GLcoord(),1);//spawn health powerup
                spawn_powerup(1.0f,random_GLcoord(),3);//spawn shield new powerup
                spawn_powerup(1.0f,random_GLcoord(),7);//new weapon
            }
            if (game_o.level == 11)
            {
                spawn_powerup(1.0f,random_GLcoord(),1);//spawn health powerup
                spawn_powerup(1.0f,random_GLcoord(),3);//spawn shield new powerup
                spawn_powerup(1.0f,random_GLcoord(),7);//new weapon
            }
            if (game_o.level == 15)
            {
                spawn_powerup(1.0f,random_GLcoord(),1);//spawn health powerup
                spawn_powerup(1.0f,random_GLcoord(),5);//spawn thruster new powerup
                spawn_powerup(1.0f,random_GLcoord(),3);//spawn shield new powerup
                spawn_powerup(1.0f,random_GLcoord(),7);//new weapon
            }
            if (game_o.level == 19)
            {
                spawn_powerup(1.0f,random_GLcoord(),1);//spawn health powerup
                spawn_powerup(1.0f,random_GLcoord(),5);//spawn thruster new powerup
                spawn_powerup(1.0f,random_GLcoord(),3);//spawn shield new powerup
                spawn_powerup(1.0f,random_GLcoord(),7);//new weapon
            }
            if (game_o.level == 23)
            {
                spawn_powerup(1.0f,random_GLcoord(),1);//spawn health powerup
                spawn_powerup(1.0f,random_GLcoord(),5);//spawn thruster new powerup
                spawn_powerup(1.0f,random_GLcoord(),3);//spawn shield new powerup
                spawn_powerup(1.0f,random_GLcoord(),6);//spawn weapon lvl powerup
            }
        }
        else
        {
           // spawn poweups if level is too low, ie. player missed the power up last level or in game or it hasnt spawned in game
           if ((game_o.level >=  4) && (!game_o.projectile[1].active)) spawn_powerup(1.0f,random_GLcoord(),7); // spawn new weapon
           if ((game_o.level >=  7) && (!game_o.projectile[2].active)) spawn_powerup(1.0f,random_GLcoord(),7); // spawn new weapon
           if ((game_o.level >= 11) && (!game_o.projectile[3].active)) spawn_powerup(1.0f,random_GLcoord(),7); // spawn new weapon
           if ((game_o.level >= 15) && (!game_o.projectile[4].active)) spawn_powerup(1.0f,random_GLcoord(),7); // spawn new weapon
           if ((game_o.level >= 19) && (!game_o.projectile[5].active)) spawn_powerup(1.0f,random_GLcoord(),7); // spawn new weapon

           if ((game_o.level >=  7) && (!game_o.shield[0].active)) spawn_powerup(1.0f,random_GLcoord(),3); // spawn new shield
           if ((game_o.level >= 11) && (!game_o.shield[1].active)) spawn_powerup(1.0f,random_GLcoord(),3); // spawn new shield
           if ((game_o.level >= 15) && (!game_o.shield[2].active)) spawn_powerup(1.0f,random_GLcoord(),3); // spawn new shield
           if ((game_o.level >= 19) && (!game_o.shield[3].active)) spawn_powerup(1.0f,random_GLcoord(),3); // spawn new shield
           if ((game_o.level >= 23) && (!game_o.shield[4].active)) spawn_powerup(1.0f,random_GLcoord(),3); // spawn new shield

           if ((game_o.level >= 15) && (!game_o.thruster[0].active)) spawn_powerup(1.0f,random_GLcoord(),5); // spawn new thruster
           if ((game_o.level >= 19) && (!game_o.thruster[1].active)) spawn_powerup(1.0f,random_GLcoord(),5); // spawn new thruster
           if ((game_o.level >= 23) && (!game_o.thruster[2].active)) spawn_powerup(1.0f,random_GLcoord(),5); // spawn new thruster
           spawn_powerup(1.0f,random_GLcoord(),1);//spawn health powerup
           spawn_powerup(1.0f,random_GLcoord(),2);//spawn shield lvl powerup
           spawn_powerup(1.0f,random_GLcoord(),4);//spawn thruster lvl powerup
        }
     game_o.powerups_spawened = true;
     }
     if (!game_o.level_end_display_active) spawn_d_level_end();
  }
   if ((game_o.level_end_time) && (game_o.level_end_phase == 1)) //level outro
   {
     game_o.player.health = 0.100f;
     process_player(1024);//warp player out
   }
   return(0);
};
/*----------------------------------------------------------------------------*/
int display_game(void)
{
   float z_pos = 0;
   float temp_val;
   glPushMatrix();
   glDisable(GL_DEPTH_TEST);
   game.background.draw();
//-----------------------------------------------------------------------------------------------------------------------
   for (int npc_count =MAX_NPCS-1;npc_count >=0;npc_count--)  // npcs
   {
      for (int bullet_count = MAX_BULLETS-1;bullet_count >=0;bullet_count--)  // npcs bullets
      {
         z_pos = 0.05f + (0.0001*bullet_count);
         bind_texture(game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].image);
         glLoadIdentity();
         if (game_o.npc[npc_count].bullet[bullet_count].active)
         {
            glBegin( GL_QUADS );
            glTexCoord2i( 0, 1 );glVertex3f(game_o.npc[npc_count].bullet[bullet_count].x_pos+(game_o.npc[npc_count].bullet[bullet_count].width/2),game_o.npc[npc_count].bullet[bullet_count].y_pos-(game_o.npc[npc_count].bullet[bullet_count].hight/2),z_pos);
            glTexCoord2i( 0, 0 );glVertex3f(game_o.npc[npc_count].bullet[bullet_count].x_pos+(game_o.npc[npc_count].bullet[bullet_count].width/2),game_o.npc[npc_count].bullet[bullet_count].y_pos+(game_o.npc[npc_count].bullet[bullet_count].hight/2),z_pos);
            glTexCoord2i( 1, 0 );glVertex3f(game_o.npc[npc_count].bullet[bullet_count].x_pos-(game_o.npc[npc_count].bullet[bullet_count].width/2),game_o.npc[npc_count].bullet[bullet_count].y_pos+(game_o.npc[npc_count].bullet[bullet_count].hight/2),z_pos);
            glTexCoord2i( 1, 1 );glVertex3f(game_o.npc[npc_count].bullet[bullet_count].x_pos-(game_o.npc[npc_count].bullet[bullet_count].width/2),game_o.npc[npc_count].bullet[bullet_count].y_pos-(game_o.npc[npc_count].bullet[bullet_count].hight/2),z_pos);
            glEnd();
         }
      }
      z_pos = 0.04f + (0.0001*npc_count); // npc's
      if (game_o.npc[npc_count].active)
      {
         if (game_o.npc[npc_count].damaged > (game_o.npc_damage_duration/5)) glColor4f(1.0f,0.0f,0.0f,0.6f);
         bind_texture(game_o.enemy[game_o.npc[npc_count].type_npc].image);
         glLoadIdentity();
         glBegin( GL_QUADS );
         glTexCoord2i( 1, 1 );glVertex3f(game_o.npc[npc_count].x_pos+(game_o.npc[npc_count].width/2),game_o.npc[npc_count].y_pos-(game_o.npc[npc_count].hight/2),z_pos);
         glTexCoord2i( 0, 1 );glVertex3f(game_o.npc[npc_count].x_pos+(game_o.npc[npc_count].width/2),game_o.npc[npc_count].y_pos+(game_o.npc[npc_count].hight/2),z_pos);
         glTexCoord2i( 0, 0 );glVertex3f(game_o.npc[npc_count].x_pos-(game_o.npc[npc_count].width/2),game_o.npc[npc_count].y_pos+(game_o.npc[npc_count].hight/2),z_pos);
         glTexCoord2i( 1, 0 );glVertex3f(game_o.npc[npc_count].x_pos-(game_o.npc[npc_count].width/2),game_o.npc[npc_count].y_pos-(game_o.npc[npc_count].hight/2),z_pos);
         glEnd();
         glColor4f(1.0f,1.0f,1.0f,1.0f);
      }
   }
   for (int count =0;count < MAX_BULLETS;count++) //player bullets
   {
      if (game_o.player.bullet[count].active)
      {
         z_pos = 0.05f + (0.001*count);
         if (game_o.player.bullet[count].location < 3) bind_texture(game_o.projectile[game_o.player.front_weapon].image);
         else bind_texture(game_o.projectile[game_o.player.side_weapon].image);
         glLoadIdentity();
         glBegin( GL_QUADS );
         glTexCoord2i( 1, 0 );glVertex3f(game_o.player.bullet[count].x_pos+(game_o.player.bullet[count].width/2),game_o.player.bullet[count].y_pos-(game_o.player.bullet[count].hight/2), z_pos);
         glTexCoord2i( 1, 1 );glVertex3f(game_o.player.bullet[count].x_pos+(game_o.player.bullet[count].width/2),game_o.player.bullet[count].y_pos+(game_o.player.bullet[count].hight/2), z_pos);
         glTexCoord2i( 0, 1 );glVertex3f(game_o.player.bullet[count].x_pos-(game_o.player.bullet[count].width/2),game_o.player.bullet[count].y_pos+(game_o.player.bullet[count].hight/2), z_pos);
         glTexCoord2i( 0, 0 );glVertex3f(game_o.player.bullet[count].x_pos-(game_o.player.bullet[count].width/2),game_o.player.bullet[count].y_pos-(game_o.player.bullet[count].hight/2), z_pos);
         glEnd();
      }
   }

   for (int supportship_count = 0;supportship_count < MAX_SUPPORTSHIPS;supportship_count++)//display supportship bullets
   {
      for (int bullet_count = 0;bullet_count < MAX_BULLETS;bullet_count++)
      {
         if (game_o.supportship[supportship_count].bullet[bullet_count].active)
         {
            z_pos = 0.05f + (0.001*bullet_count);
            bind_texture(game_o.projectile[game_o.supportship[supportship_count].bullet[bullet_count].warhead].image);
            glLoadIdentity();
            glBegin( GL_QUADS );
            glTexCoord2i( 1, 0 );glVertex3f(game_o.supportship[supportship_count].bullet[bullet_count].x_pos+(game_o.supportship[supportship_count].bullet[bullet_count].width/2),game_o.supportship[supportship_count].bullet[bullet_count].y_pos-(game_o.supportship[supportship_count].bullet[bullet_count].hight/2), z_pos);
            glTexCoord2i( 1, 1 );glVertex3f(game_o.supportship[supportship_count].bullet[bullet_count].x_pos+(game_o.supportship[supportship_count].bullet[bullet_count].width/2),game_o.supportship[supportship_count].bullet[bullet_count].y_pos+(game_o.supportship[supportship_count].bullet[bullet_count].hight/2), z_pos);
            glTexCoord2i( 0, 1 );glVertex3f(game_o.supportship[supportship_count].bullet[bullet_count].x_pos-(game_o.supportship[supportship_count].bullet[bullet_count].width/2),game_o.supportship[supportship_count].bullet[bullet_count].y_pos+(game_o.supportship[supportship_count].bullet[bullet_count].hight/2), z_pos);
            glTexCoord2i( 0, 0 );glVertex3f(game_o.supportship[supportship_count].bullet[bullet_count].x_pos-(game_o.supportship[supportship_count].bullet[bullet_count].width/2),game_o.supportship[supportship_count].bullet[bullet_count].y_pos-(game_o.supportship[supportship_count].bullet[bullet_count].hight/2), z_pos);
            glEnd();
         }
      }
   }

   for (int count =MAX_EXPLOSIONS;count >=0;count--)  // explosions
   {
      z_pos = 0.001f + (0.0001*count);
      bind_texture(game_o.explosion[count].image + game_o.explosion[count].frame);
      glLoadIdentity();
      if (game_o.explosion[count].active)
      {
         glBegin( GL_QUADS );
         glTexCoord2i( 1, 0 );glVertex3f(game_o.explosion[count].x_pos+(game_o.explosion[count].width/2),game_o.explosion[count].y_pos-(game_o.explosion[count].hight/2),z_pos);
         glTexCoord2i( 1, 1 );glVertex3f(game_o.explosion[count].x_pos+(game_o.explosion[count].width/2),game_o.explosion[count].y_pos+(game_o.explosion[count].hight/2),z_pos);
         glTexCoord2i( 0, 1 );glVertex3f(game_o.explosion[count].x_pos-(game_o.explosion[count].width/2),game_o.explosion[count].y_pos+(game_o.explosion[count].hight/2),z_pos);
         glTexCoord2i( 0, 0 );glVertex3f(game_o.explosion[count].x_pos-(game_o.explosion[count].width/2),game_o.explosion[count].y_pos-(game_o.explosion[count].hight/2),z_pos);
         glEnd();
      }
   }
//----------------------------------------------------------------------------------------
   if ((game_o.immune) && (game_o.immunity_state == 0)) glColor4f(1.0f,0.0f,0.0f,0.6f);
   if (game_o.player.thrusters > -1)//player starship
   {
      bind_texture(game_o.thruster[game_o.player.thrusters].image); //player thrusters
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 0 );glVertex3f(game_o.player.x_pos+(game_o.player.width/2)-0.190f,game_o.player.y_pos-(game_o.player.hight/2), 0.035f );
      glTexCoord2i( 1, 0 );glVertex3f(game_o.player.x_pos+(game_o.player.width/2)-0.190f,game_o.player.y_pos+(game_o.player.hight/2), 0.035f );
      glTexCoord2i( 1, 1 );glVertex3f(game_o.player.x_pos-(game_o.player.width/2)-0.190f,game_o.player.y_pos+(game_o.player.hight/2), 0.035f );
      glTexCoord2i( 0, 1 );glVertex3f(game_o.player.x_pos-(game_o.player.width/2)-0.190f,game_o.player.y_pos-(game_o.player.hight/2), 0.035f );
      glEnd();
   }

   bind_texture(game_o.player.image); //player starship
   glLoadIdentity();
   glBegin( GL_QUADS );
   glTexCoord2i( 0, 0 );glVertex3f(game_o.player.x_pos+(game_o.player.width/2),game_o.player.y_pos-(game_o.player.hight/2), 0.03f );
   glTexCoord2i( 1, 0 );glVertex3f(game_o.player.x_pos+(game_o.player.width/2),game_o.player.y_pos+(game_o.player.hight/2), 0.03f );
   glTexCoord2i( 1, 1 );glVertex3f(game_o.player.x_pos-(game_o.player.width/2),game_o.player.y_pos+(game_o.player.hight/2), 0.03f );
   glTexCoord2i( 0, 1 );glVertex3f(game_o.player.x_pos-(game_o.player.width/2),game_o.player.y_pos-(game_o.player.hight/2), 0.03f );
   glEnd();

   for (int count = 0;count < MAX_SUPPORTSHIPS;count++)
   {
      if (game_o.supportship[count].active)
      {
         bind_texture(game_o.supportship[count].image); //supportships
         glLoadIdentity();
         glBegin( GL_QUADS );//top
         glTexCoord2i( 0, 0 );glVertex3f(game_o.player.x_pos-(game_o.player.width/4)+game_o.supportship[count].width,game_o.player.y_pos+(game_o.player.hight/2)+game_o.supportship[count].height, 0.001f);
         glTexCoord2i( 1, 0 );glVertex3f(game_o.player.x_pos-(game_o.player.width/4)+game_o.supportship[count].width,game_o.player.y_pos+(game_o.player.hight/2)                            , 0.001f);
         glTexCoord2i( 1, 1 );glVertex3f(game_o.player.x_pos-(game_o.player.width/4)                           ,game_o.player.y_pos+(game_o.player.hight/2)                            , 0.001f);
         glTexCoord2i( 0, 1 );glVertex3f(game_o.player.x_pos-(game_o.player.width/4)                           ,game_o.player.y_pos+(game_o.player.hight/2)+game_o.supportship[count].height, 0.001f);
         glEnd();
         glBegin( GL_QUADS );//bottom
         glTexCoord2i( 0, 0 );glVertex3f(game_o.player.x_pos-(game_o.player.width/4)+game_o.supportship[count].width,game_o.player.y_pos-(game_o.player.hight/2)-game_o.supportship[count].height, 0.001f);
         glTexCoord2i( 1, 0 );glVertex3f(game_o.player.x_pos-(game_o.player.width/4)+game_o.supportship[count].width,game_o.player.y_pos-(game_o.player.hight/2)                            , 0.001f);
         glTexCoord2i( 1, 1 );glVertex3f(game_o.player.x_pos-(game_o.player.width/4)                           ,game_o.player.y_pos-(game_o.player.hight/2)                            , 0.001f);
         glTexCoord2i( 0, 1 );glVertex3f(game_o.player.x_pos-(game_o.player.width/4)                           ,game_o.player.y_pos-(game_o.player.hight/2)-game_o.supportship[count].height, 0.001f);
         glEnd();
      }
   }

     if (game_o.player.front_weapon > -1)
      {
         bind_texture(game_o.player.front_weapon+211); //player starship front weapon
         glLoadIdentity();
         glBegin( GL_QUADS );
         glTexCoord2i( 0, 0 );glVertex3f(game_o.player.x_pos+(game_o.player.width/8)+0.053f,game_o.player.y_pos-(game_o.player.hight/8), 0.025f );
         glTexCoord2i( 1, 0 );glVertex3f(game_o.player.x_pos+(game_o.player.width/8)+0.053f,game_o.player.y_pos+(game_o.player.hight/8), 0.025f );
         glTexCoord2i( 1, 1 );glVertex3f(game_o.player.x_pos-(game_o.player.width/8)+0.078f,game_o.player.y_pos+(game_o.player.hight/8), 0.025f );
         glTexCoord2i( 0, 1 );glVertex3f(game_o.player.x_pos-(game_o.player.width/8)+0.078f,game_o.player.y_pos-(game_o.player.hight/8), 0.025f );
         glEnd();
      }

    if (game_o.player.side_weapon > -1)
    {
        bind_texture(game_o.player.side_weapon+211); //player starship side weapons
        glLoadIdentity();
        glBegin( GL_QUADS );
        glTexCoord2i( 0, 0 );glVertex3f(game_o.player.x_pos+(game_o.player.width/6)+0.067f,game_o.player.y_pos-(game_o.player.hight/6)+0.075f, 0.025f );
        glTexCoord2i( 1, 0 );glVertex3f(game_o.player.x_pos+(game_o.player.width/6)+0.067f,game_o.player.y_pos+(game_o.player.hight/6)+0.075f, 0.025f );
        glTexCoord2i( 1, 1 );glVertex3f(game_o.player.x_pos-(game_o.player.width/6)+0.067f,game_o.player.y_pos+(game_o.player.hight/6)+0.075f, 0.025f );
        glTexCoord2i( 0, 1 );glVertex3f(game_o.player.x_pos-(game_o.player.width/6)+0.067f,game_o.player.y_pos-(game_o.player.hight/6)+0.075f, 0.025f );
        glEnd();
        glBegin( GL_QUADS );
        glTexCoord2i( 0, 0 );glVertex3f(game_o.player.x_pos+(game_o.player.width/6)+0.067f,game_o.player.y_pos-(game_o.player.hight/6)-0.075f, 0.025f );
        glTexCoord2i( 1, 0 );glVertex3f(game_o.player.x_pos+(game_o.player.width/6)+0.067f,game_o.player.y_pos+(game_o.player.hight/6)-0.075f, 0.025f );
        glTexCoord2i( 1, 1 );glVertex3f(game_o.player.x_pos-(game_o.player.width/6)+0.067f,game_o.player.y_pos+(game_o.player.hight/6)-0.075f, 0.025f );
        glTexCoord2i( 0, 1 );glVertex3f(game_o.player.x_pos-(game_o.player.width/6)+0.067f,game_o.player.y_pos-(game_o.player.hight/6)-0.075f, 0.025f );
        glEnd();
    }
    if (game_o.player.front_shield > -1)
    {
        bind_texture(game_o.shield[game_o.player.front_shield].image); //player starship shield
        glLoadIdentity();
        glBegin( GL_QUADS );
        glTexCoord2i( 1, 0 );glVertex3f(game_o.player.x_pos+(game_o.player.width/1.5),game_o.player.y_pos-(game_o.player.hight/1.5), 0.02f );
        glTexCoord2i( 1, 1 );glVertex3f(game_o.player.x_pos+(game_o.player.width/1.5),game_o.player.y_pos+(game_o.player.hight/1.5), 0.02f );
        glTexCoord2i( 0, 1 );glVertex3f(game_o.player.x_pos-(game_o.player.width/1.5),game_o.player.y_pos+(game_o.player.hight/1.5), 0.02f );
        glTexCoord2i( 0, 0 );glVertex3f(game_o.player.x_pos-(game_o.player.width/1.5),game_o.player.y_pos-(game_o.player.hight/1.5), 0.02f );
        glEnd();
    }
    glColor4f(1.0f,1.0f,1.0f,1.0f);//------------------------------------------------
   float  npc_num = 0.0f;
   for  (int npc_count = 0; npc_count < MAX_NPCS; npc_count++)
   {
       bind_texture(210); // npc health bars
       glLoadIdentity();
       if (game_o.active_npc[npc_count].active)
       {
          npc_num += 0.05f;
          glBegin( GL_QUADS );
          glTexCoord2i( 0, 1 );glVertex3f(0.89f +((game_o.npc[npc_count].health/game_o.enemy[game_o.npc[npc_count].type_npc].health)/10),1.0f -0.025f-npc_num, 0.001f);
          glTexCoord2i( 0, 0 );glVertex3f(0.89f +((game_o.npc[npc_count].health/game_o.enemy[game_o.npc[npc_count].type_npc].health)/10),1.0f +0.025f-npc_num, 0.001f);
          glTexCoord2i( 1, 0 );glVertex3f(0.89f                ,1.0f +0.025f-npc_num, 0.001f);
          glTexCoord2i( 1, 1 );glVertex3f(0.89f                ,1.0f -0.025f-npc_num, 0.001f);
          glEnd();
       }
   }

   for (int count = MAX_POWERUPS;count >=1;count--)  // powerups
   {
      z_pos = 0.002f + (0.0002*count);
      bind_texture(game_o.powerup[count].image);
      glLoadIdentity();
      if (game_o.powerup[count].active)
      {
         glBegin( GL_QUADS );
         glTexCoord2i( 0, 1 );glVertex3f(game_o.powerup[count].x_pos+(game_o.powerup[count].width/2),game_o.powerup[count].y_pos-(game_o.powerup[count].hight/2),z_pos);
         glTexCoord2i( 0, 0 );glVertex3f(game_o.powerup[count].x_pos+(game_o.powerup[count].width/2),game_o.powerup[count].y_pos+(game_o.powerup[count].hight/2),z_pos);
         glTexCoord2i( 1, 0 );glVertex3f(game_o.powerup[count].x_pos-(game_o.powerup[count].width/2),game_o.powerup[count].y_pos+(game_o.powerup[count].hight/2),z_pos);
         glTexCoord2i( 1, 1 );glVertex3f(game_o.powerup[count].x_pos-(game_o.powerup[count].width/2),game_o.powerup[count].y_pos-(game_o.powerup[count].hight/2),z_pos);
         glEnd();
      }
   }

   for (int count = MAX_COINS;count >=1;count--)  // coin
   {
      z_pos = 0.002f + (0.0002*(count+MAX_POWERUPS));
      bind_texture(game_o.coin[count].image);
      glLoadIdentity();
      if (game_o.coin[count].active)
      {
         glBegin( GL_QUADS );
         glTexCoord2i( 0, 1 );glVertex3f(game_o.coin[count].x_pos+(game_o.coin[count].width/2),game_o.coin[count].y_pos-(game_o.coin[count].hight/2),z_pos);
         glTexCoord2i( 0, 0 );glVertex3f(game_o.coin[count].x_pos+(game_o.coin[count].width/2),game_o.coin[count].y_pos+(game_o.coin[count].hight/2),z_pos);
         glTexCoord2i( 1, 0 );glVertex3f(game_o.coin[count].x_pos-(game_o.coin[count].width/2),game_o.coin[count].y_pos+(game_o.coin[count].hight/2),z_pos);
         glTexCoord2i( 1, 1 );glVertex3f(game_o.coin[count].x_pos-(game_o.coin[count].width/2),game_o.coin[count].y_pos-(game_o.coin[count].hight/2),z_pos);
         glEnd();
      }
   }

   for (int count = MAX_WEXPS;count >=1;count--)  // wexp
   {
      z_pos = 0.002f + (0.0002*(count+MAX_POWERUPS+MAX_COINS));
      bind_texture(game_o.wexp[count].image);
      glLoadIdentity();
      if (game_o.wexp[count].active)
      {
         glBegin( GL_QUADS );
         glTexCoord2i( 0, 1 );glVertex3f(game_o.wexp[count].x_pos+(game_o.wexp[count].width/2),game_o.wexp[count].y_pos-(game_o.wexp[count].hight/2),z_pos);
         glTexCoord2i( 0, 0 );glVertex3f(game_o.wexp[count].x_pos+(game_o.wexp[count].width/2),game_o.wexp[count].y_pos+(game_o.wexp[count].hight/2),z_pos);
         glTexCoord2i( 1, 0 );glVertex3f(game_o.wexp[count].x_pos-(game_o.wexp[count].width/2),game_o.wexp[count].y_pos+(game_o.wexp[count].hight/2),z_pos);
         glTexCoord2i( 1, 1 );glVertex3f(game_o.wexp[count].x_pos-(game_o.wexp[count].width/2),game_o.wexp[count].y_pos-(game_o.wexp[count].hight/2),z_pos);
         glEnd();
      }
   }

   bind_texture(210); //player health bar
   glLoadIdentity();
   glBegin( GL_QUADS );
   glTexCoord2i( 0, 1 );glVertex3f(-0.6f +((game_o.player.health/game_o.player.max_health)/5),0.900f, 0.001f);
   glTexCoord2i( 0, 0 );glVertex3f(-0.6f +((game_o.player.health/game_o.player.max_health)/5),0.975f, 0.001f);
   glTexCoord2i( 1, 0 );glVertex3f(-0.6f                                                 ,0.975f, 0.001f);
   glTexCoord2i( 1, 1 );glVertex3f(-0.6f                                                 ,0.900f, 0.001f);
   glEnd();

    if (game_o.number_bombs > 0) //bomb icons
    {
        bind_texture(341);
        glLoadIdentity();
        glBegin( GL_QUADS );
        glTexCoord2i( 0, 1 );glVertex3f(-0.995f,0.900f, 0.001f);
        glTexCoord2i( 0, 0 );glVertex3f(-0.995f,0.975f, 0.001f);
        glTexCoord2i( 1, 0 );glVertex3f(-0.945f,0.975f, 0.001f);
        glTexCoord2i( 1, 1 );glVertex3f(-0.945f,0.900f, 0.001f);
        glEnd();
    }
    if (game_o.number_bombs > 1)
    {
        bind_texture(341);
        glLoadIdentity();
        glBegin( GL_QUADS );
        glTexCoord2i( 0, 1 );glVertex3f(-0.935f,0.900f, 0.001f);
        glTexCoord2i( 0, 0 );glVertex3f(-0.935f,0.975f, 0.001f);
        glTexCoord2i( 1, 0 );glVertex3f(-0.885f,0.975f, 0.001f);
        glTexCoord2i( 1, 1 );glVertex3f(-0.885f,0.900f, 0.001f);
        glEnd();
    }
    if (game_o.number_bombs > 2)
    {
        bind_texture(341);
        glLoadIdentity();
        glBegin( GL_QUADS );
        glTexCoord2i( 0, 1 );glVertex3f(-0.875f,0.900f, 0.001f);
        glTexCoord2i( 0, 0 );glVertex3f(-0.875f,0.975f, 0.001f);
        glTexCoord2i( 1, 0 );glVertex3f(-0.825f,0.975f, 0.001f);
        glTexCoord2i( 1, 1 );glVertex3f(-0.825f,0.900f, 0.001f);
        glEnd();
    }
    if (game_o.number_bombs > 3)
    {
        bind_texture(341);
        glLoadIdentity();
        glBegin( GL_QUADS );
        glTexCoord2i( 0, 1 );glVertex3f(-0.815f,0.900f, 0.001f);
        glTexCoord2i( 0, 0 );glVertex3f(-0.815f,0.975f, 0.001f);
        glTexCoord2i( 1, 0 );glVertex3f(-0.765f,0.975f, 0.001f);
        glTexCoord2i( 1, 1 );glVertex3f(-0.765f,0.900f, 0.001f);
        glEnd();
    }
    if (game_o.number_bombs > 4)
    {
        bind_texture(341);
        glLoadIdentity();
        glBegin( GL_QUADS );
        glTexCoord2i( 0, 1 );glVertex3f(-0.755f,0.900f, 0.001f);
        glTexCoord2i( 0, 0 );glVertex3f(-0.755f,0.975f, 0.001f);
        glTexCoord2i( 1, 0 );glVertex3f(-0.705f,0.975f, 0.001f);
        glTexCoord2i( 1, 1 );glVertex3f(-0.705f,0.900f, 0.001f);
        glEnd();
    }
    if (game_o.number_bombs > 5)
    {
        bind_texture(341);
        glLoadIdentity();
        glBegin( GL_QUADS );
        glTexCoord2i( 0, 1 );glVertex3f(-0.695f,0.900f, 0.001f);
        glTexCoord2i( 0, 0 );glVertex3f(-0.695f,0.975f, 0.001f);
        glTexCoord2i( 1, 0 );glVertex3f(-0.645f,0.975f, 0.001f);
        glTexCoord2i( 1, 1 );glVertex3f(-0.645f,0.900f, 0.001f);
        glEnd();
    }

   if (game_o.player.front_weapon > -1)
   {
      bind_texture(game_o.projectile[game_o.player.front_weapon].image);// front weapon pic next to the exp bar
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 1, 0 );glVertex3f(-0.310f, 0.900f, 0.002f );
      glTexCoord2i( 1, 1 );glVertex3f(-0.310f, 0.975f, 0.002f );
      glTexCoord2i( 0, 1 );glVertex3f(-0.385f, 0.975f, 0.002f );
      glTexCoord2i( 0, 0 );glVertex3f(-0.385f, 0.900f, 0.002f );
      glEnd();

      if (game_o.projectile[game_o.player.front_weapon].level == 0) temp_val = ((game_o.projectile[game_o.player.front_weapon].experience / game_o.projectile[game_o.player.front_weapon].level_1)/5);
      if (game_o.projectile[game_o.player.front_weapon].level == 1) temp_val = ((game_o.projectile[game_o.player.front_weapon].experience / game_o.projectile[game_o.player.front_weapon].level_2)/5);
      if (game_o.projectile[game_o.player.front_weapon].level == 2) temp_val = ((game_o.projectile[game_o.player.front_weapon].experience / game_o.projectile[game_o.player.front_weapon].level_3)/5);
      if (game_o.projectile[game_o.player.front_weapon].level == 3) temp_val = 0.2f;
      bind_texture(285); //front weapon exp bar
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 1 );glVertex3f(-0.3f +temp_val,0.900f, 0.001f);
      glTexCoord2i( 0, 0 );glVertex3f(-0.3f +temp_val,0.975f, 0.001f);
      glTexCoord2i( 1, 0 );glVertex3f(-0.3f          ,0.975f, 0.001f);
      glTexCoord2i( 1, 1 );glVertex3f(-0.3f          ,0.900f, 0.001f);
      glEnd();
   }

   if (game_o.player.side_weapon > -1)
   {
      bind_texture(game_o.projectile[game_o.player.side_weapon].image);// side weapon pic next to the exp bar
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 1, 0 );glVertex3f(-0.010f, 0.900f, 0.002f );
      glTexCoord2i( 1, 1 );glVertex3f(-0.010f, 0.975f, 0.002f );
      glTexCoord2i( 0, 1 );glVertex3f(-0.085f, 0.975f, 0.002f );
      glTexCoord2i( 0, 0 );glVertex3f(-0.085f, 0.900f, 0.002f );
      glEnd();

      if (game_o.projectile[game_o.player.side_weapon].level == 0) temp_val = ((game_o.projectile[game_o.player.side_weapon].experience / game_o.projectile[game_o.player.side_weapon].level_1)/5);
      if (game_o.projectile[game_o.player.side_weapon].level == 1) temp_val = ((game_o.projectile[game_o.player.side_weapon].experience / game_o.projectile[game_o.player.side_weapon].level_2)/5);
      if (game_o.projectile[game_o.player.side_weapon].level == 2) temp_val = ((game_o.projectile[game_o.player.side_weapon].experience / game_o.projectile[game_o.player.side_weapon].level_3)/5);
      if (game_o.projectile[game_o.player.side_weapon].level == 3) temp_val = 0.2f;
      bind_texture(285); //side weapon exp bar
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 1 );glVertex3f( 0.0f +temp_val,0.900f, 0.001f);
      glTexCoord2i( 0, 0 );glVertex3f( 0.0f +temp_val,0.975f, 0.001f);
      glTexCoord2i( 1, 0 );glVertex3f( 0.0f          ,0.975f, 0.001f);
      glTexCoord2i( 1, 1 );glVertex3f( 0.0f          ,0.900f, 0.001f);
        glEnd();
    }

    temp_val = (1.95f*((float)game_o.level_kills/(float)game_o.victory_kills));
    bind_texture(340); //level progress bar
    glLoadIdentity();
    glBegin( GL_QUADS );
    glTexCoord2i( 0, 1 );glVertex3f(-0.975f +temp_val,-0.950f, 0.001f);
    glTexCoord2i( 0, 0 );glVertex3f(-0.975f +temp_val,-0.975f, 0.001f);
    glTexCoord2i( 1, 0 );glVertex3f(-0.975f          ,-0.975f, 0.001f);
    glTexCoord2i( 1, 1 );glVertex3f(-0.975f          ,-0.950f, 0.001f);
    glEnd();
    //--------------------------- Touch screen controls ------------------------------------------------------------------------------------
    if(game.config.Display_Touchscreen)
    {
        bind_texture(350); // Left button
        glLoadIdentity();
        glBegin( GL_QUADS );
        glTexCoord2i( 1, 1 );glVertex3f(-0.775f ,-0.450f, 0.001f);
        glTexCoord2i( 0, 1 );glVertex3f(-0.775f ,-0.650f, 0.001f);
        glTexCoord2i( 0, 0 );glVertex3f(-0.975f ,-0.650f, 0.001f);
        glTexCoord2i( 1, 0 );glVertex3f(-0.975f ,-0.450f, 0.001f);
        glEnd();
        bind_texture(350); // Right button
        glLoadIdentity();
        glBegin( GL_QUADS );
        glTexCoord2i( 0, 0 );glVertex3f(-0.375f ,-0.450f, 0.001f);
        glTexCoord2i( 1, 0 );glVertex3f(-0.375f ,-0.650f, 0.001f);
        glTexCoord2i( 1, 1 );glVertex3f(-0.575f ,-0.650f, 0.001f);
        glTexCoord2i( 0, 1 );glVertex3f(-0.575f ,-0.450f, 0.001f);
        glEnd();
        bind_texture(350); // Up button
        glLoadIdentity();
        glBegin( GL_QUADS );
        glTexCoord2i( 1, 0 );glVertex3f(-0.575f ,-0.250f, 0.001f);
        glTexCoord2i( 1, 1 );glVertex3f(-0.575f ,-0.450f, 0.001f);
        glTexCoord2i( 0, 1 );glVertex3f(-0.775f ,-0.450f, 0.001f);
        glTexCoord2i( 0, 0 );glVertex3f(-0.775f ,-0.250f, 0.001f);
        glEnd();
        bind_texture(350); // Down button
        glLoadIdentity();
        glBegin( GL_QUADS );
        glTexCoord2i( 0, 1 );glVertex3f(-0.575f ,-0.650f, 0.001f);
        glTexCoord2i( 0, 0 );glVertex3f(-0.575f ,-0.850f, 0.001f);
        glTexCoord2i( 1, 0 );glVertex3f(-0.775f ,-0.850f, 0.001f);
        glTexCoord2i( 1, 1 );glVertex3f(-0.775f ,-0.650f, 0.001f);
        glEnd();
        bind_texture(351); // Fire button
        glLoadIdentity();
        glBegin( GL_QUADS );
        glTexCoord2i( 0, 1 );glVertex3f( 0.775f ,-0.650f, 0.001f);
        glTexCoord2i( 0, 0 );glVertex3f( 0.775f ,-0.850f, 0.001f);
        glTexCoord2i( 1, 0 );glVertex3f( 0.975f ,-0.850f, 0.001f);
        glTexCoord2i( 1, 1 );glVertex3f( 0.975f ,-0.650f, 0.001f);
        glEnd();
        bind_texture(351); // Bomb button
        glLoadIdentity();
        glBegin( GL_QUADS );
        glTexCoord2i( 0, 1 );glVertex3f( 0.475f ,-0.650f, 0.001f);
        glTexCoord2i( 0, 0 );glVertex3f( 0.475f ,-0.850f, 0.001f);
        glTexCoord2i( 1, 0 );glVertex3f( 0.675f ,-0.850f, 0.001f);
        glTexCoord2i( 1, 1 );glVertex3f( 0.675f ,-0.650f, 0.001f);
        glEnd();
        bind_texture(351); // Menu button
        glLoadIdentity();
        glBegin( GL_QUADS );
        glTexCoord2i( 0, 1 );glVertex3f( 0.775f , 0.650f, 0.001f);
        glTexCoord2i( 0, 0 );glVertex3f( 0.775f , 0.850f, 0.001f);
        glTexCoord2i( 1, 0 );glVertex3f( 0.975f , 0.850f, 0.001f);
        glTexCoord2i( 1, 1 );glVertex3f( 0.975f , 0.650f, 0.001f);
        glEnd();
    }
    //--------------------------------------------------------------------------------------------------------------------------------------
    if (game_o.paused.active)                   display_paused();
    if (game_o.loaded.active)                   display_loaded();
    if (game_o.saved.active)                    display_saved();
    if (game_o.a_score.active)                  display_a_score();
    if (game_o.a_kills.active)                  display_a_kills();
    if (game_o.p_actinium_shields.active)       display_p_actinium_shields();
    if (game_o.p_blasters.active)               display_p_blasters();
    if (game_o.p_burst_lasers.active)           display_p_burst_lasers();
    if (game_o.p_chain_guns.active)             display_p_chain_guns();
    if (game_o.p_convolution_thrusters.active)  display_p_convolution_thrusters();
    if (game_o.p_health.active)                 display_p_health();
    if (game_o.p_ion_cannons.active)            display_p_ion_cannons();
    if (game_o.p_iridium_shileds.active)        display_p_iridium_shileds();
    if (game_o.p_maelstrom_thrusters.active)    display_p_maelstrom_thrusters();
    if (game_o.p_plasma_rockets.active)         display_p_plasma_rockets();
    if (game_o.p_rail_turrets.active)           display_p_rail_turrets();
    if (game_o.p_rubidium_shields.active)       display_p_rubidium_shields();
    if (game_o.p_seismic_thrusters.active)      display_p_seismic_thrusters();
    if (game_o.p_shield_level_up.active)        display_p_shield_level_up();
    if (game_o.p_tantalum_shields.active)       display_p_tantalum_shields();
    if (game_o.p_terbium_shields.active)        display_p_terbium_shields();
    if (game_o.p_thrusters_level_up.active)     display_p_thrusters_level_up();
    if (game_o.p_vortex_thrusters.active)       display_p_vortex_thrusters();
    if (game_o.p_weapon_level_up.active)        display_p_weapon_level_up();
    if (game_o.level_end_display_active)        display_d_level_end();

    font.font_1.Write(255,255,255,64,-0.98f,-0.95f,"Score - ", game_o.score);
    font.font_1.Write(255,255,255,64,-0.98f,-0.91f,"Kills - ", game_o.kills);
    if (game_o.anc_enabled) font.font_1.Write(255,255,255,64, 0.40f, 0.95f,"Active NPCs - ",  game_o.active_npc_count);
    if (game_o.fps_enabled &&  game_o.anc_enabled) font.font_1.Write(255,255,255,64, 0.40f, 0.90f,"FPS - ",  game.FPS);
    if (game_o.fps_enabled && !game_o.anc_enabled) font.font_1.Write(255,255,255,64, 0.40f, 0.95f,"FPS - ",  game.FPS);
    glPopMatrix();
    return(1);
};

int kill_paused(void)
{
    game_o.paused.active = false;
    return(1);
};

int spawn_paused(void)
{
    game_o.paused.active = true;
    game_o.paused.alpha  = 2.0f;
    return(1);
};

int display_paused(void)
{
    bind_texture(288); //display paused logo
    glLoadIdentity();
    glBegin( GL_QUADS );
    glColor4f (1.0f, 1.0f, 1.0f,game_o.paused.alpha);
    glTexCoord2i( 0, 1 );glVertex3f(-0.5f,-0.250f, 0.0001f);
    glTexCoord2i( 0, 0 );glVertex3f(-0.5f, 0.250f, 0.0001f);
    glTexCoord2i( 1, 0 );glVertex3f( 0.5f, 0.250f, 0.0001f);
    glTexCoord2i( 1, 1 );glVertex3f( 0.5f,-0.250f, 0.0001f);
    glColor4f (1.0f, 1.0f, 1.0f,1.0f);
    glEnd();
    return(1);
};

int process_paused(void)
{
   if (game_o.paused.active)
   {
        game_o.paused.alpha  -= 0.025f;
        if (game_o.paused.alpha <= 0) kill_paused();
   }
   return(1);
};

int kill_loaded(void)
{
   game_o.loaded.active = false;
   return(1);
};

int spawn_loaded(void)
{
   game_o.loaded.active = true;
   game_o.loaded.alpha  = 2.0f;
   return(1);
};

int display_loaded(void)
{
   bind_texture(290); //display loaded logo
   glLoadIdentity();
   glBegin( GL_QUADS );
   glColor4f (1.0f, 1.0f, 1.0f,game_o.loaded.alpha);
   glTexCoord2i( 0, 1 );glVertex3f(-0.5f,-0.250f, 0.0001f);
   glTexCoord2i( 0, 0 );glVertex3f(-0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 0 );glVertex3f( 0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 1 );glVertex3f( 0.5f,-0.250f, 0.0001f);
   glColor4f (1.0f, 1.0f, 1.0f,1.0f);
   glEnd();
   return(1);
};

int process_loaded(void)
{
   if (game_o.loaded.active)
   {
      game_o.loaded.alpha  -= 0.025f;
      if (game_o.loaded.alpha <= 0) kill_loaded();
   }
   return(1);
};

int kill_saved(void)
{
   game_o.saved.active = false;
   return(1);
};

int spawn_saved(void)
{
   game_o.saved.active = true;
   game_o.saved.alpha  = 3.0f;
   return(1);
};

int display_saved(void)
{
   bind_texture(289); //display saved logo
   glLoadIdentity();
   glBegin( GL_QUADS );
   glColor4f (1.0f, 1.0f, 1.0f,game_o.saved.alpha);
   glTexCoord2i( 0, 1 );glVertex3f(-0.5f,-0.250f, 0.0001f);
   glTexCoord2i( 0, 0 );glVertex3f(-0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 0 );glVertex3f( 0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 1 );glVertex3f( 0.5f,-0.250f, 0.0001f);
   glColor4f (1.0f, 1.0f, 1.0f,1.0f);
   glEnd();
   return(1);
};

int process_saved(void)
{
   if (game_o.saved.active)
   {
      game_o.saved.alpha  -= 0.025f;
      if (game_o.saved.alpha <= 0) kill_saved();
   }
   return(1);
};

int kill_a_score(void)
{
   game_o.a_score.active = false;
   return(1);
};

int spawn_a_score(void)
{
   game_o.a_score.active = true;
   game_o.a_score.alpha  = 3.0f;
   return(1);
};

int display_a_score(void)
{
   bind_texture(309); //display score logo
   glLoadIdentity();
   glBegin( GL_QUADS );
   glColor4f (1.0f, 1.0f, 1.0f,game_o.a_score.alpha);
   glTexCoord2i( 0, 1 );glVertex3f(-0.5f,-0.250f, 0.0001f);
   glTexCoord2i( 0, 0 );glVertex3f(-0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 0 );glVertex3f( 0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 1 );glVertex3f( 0.5f,-0.250f, 0.0001f);
   glColor4f (1.0f, 1.0f, 1.0f,1.0f);
   glEnd();
   return(1);
};

int process_a_score(void)
{
   if (game_o.a_score.active)
   {
      game_o.a_score.alpha  -= 0.025f;
      if (game_o.a_score.alpha <= 0) kill_a_score();
   }
   if ((game_o.score >= game_o.achivement.score_level_1) && (game_o.achivement.score < 1))
   {
      game_o.achivement.score = 1;
      spawn_a_score();
   };
   if ((game_o.score >= game_o.achivement.score_level_2) && (game_o.achivement.score < 2))
   {
      game_o.achivement.score = 2;
      spawn_a_score();
   };
   if ((game_o.score >= game_o.achivement.score_level_3) && (game_o.achivement.score < 3))
   {
      game_o.achivement.score = 3;
      spawn_a_score();
   };
   if ((game_o.score >= game_o.achivement.score_level_4) && (game_o.achivement.score < 4))
   {
      game_o.achivement.score = 4;
      spawn_a_score();
   };
   if ((game_o.score >= game_o.achivement.score_level_5) && (game_o.achivement.score < 5))
   {
      game_o.achivement.score = 5;
      spawn_a_score();
   };
   if ((game_o.score >= game_o.achivement.score_level_6) && (game_o.achivement.score < 6))
   {
      game_o.achivement.score = 6;
      spawn_a_score();
   };
   if ((game_o.score >= game_o.achivement.score_level_7) && (game_o.achivement.score < 7))
   {
      game_o.achivement.score = 7;
      spawn_a_score();
   };
return(1);
};

int kill_a_kills(void)
{
   game_o.a_kills.active = false;
   return(1);
};

int spawn_a_kills(void)
{
   game_o.a_kills.active = true;
   game_o.a_kills.alpha  = 3.0f;
   return(1);
};

int display_a_kills(void)
{
   bind_texture(308); //display kills logo
   glLoadIdentity();
   glBegin( GL_QUADS );
   glColor4f (1.0f, 1.0f, 1.0f,game_o.a_kills.alpha);
   glTexCoord2i( 0, 1 );glVertex3f(-0.5f,-0.250f, 0.0001f);
   glTexCoord2i( 0, 0 );glVertex3f(-0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 0 );glVertex3f( 0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 1 );glVertex3f( 0.5f,-0.250f, 0.0001f);
   glColor4f (1.0f, 1.0f, 1.0f,1.0f);
   glEnd();
   return(1);
};

int process_a_kills(void)
{
   if (game_o.a_kills.active)
   {
      game_o.a_kills.alpha  -= 0.025f;
      if (game_o.a_kills.alpha <= 0) kill_a_kills();
   }
   if ((game_o.kills >= game_o.achivement.kills_level_1) && (game_o.achivement.kills < 1))
   {
      game_o.achivement.kills = 1;
      spawn_a_kills();
   };
   if ((game_o.kills >= game_o.achivement.kills_level_2) && (game_o.achivement.kills < 2))
   {
      game_o.achivement.kills = 2;
      spawn_a_kills();
   };
   if ((game_o.kills >= game_o.achivement.kills_level_3) && (game_o.achivement.kills < 3))
   {
      game_o.achivement.kills = 3;
      spawn_a_kills();
   };
   if ((game_o.kills >= game_o.achivement.kills_level_4) && (game_o.achivement.kills < 4))
   {
      game_o.achivement.kills = 4;
      spawn_a_kills();
   };
   if ((game_o.kills >= game_o.achivement.kills_level_5) && (game_o.achivement.kills < 5))
   {
      game_o.achivement.kills = 5;
      spawn_a_kills();
   };
   if ((game_o.kills >= game_o.achivement.kills_level_6) && (game_o.achivement.kills < 6))
   {
      game_o.achivement.kills = 6;
      spawn_a_kills();
   };
   if ((game_o.kills >= game_o.achivement.kills_level_7) && (game_o.achivement.kills < 7))
   {
      game_o.achivement.kills = 7;
      spawn_a_kills();
   };
   return(1);
};

int kill_p_actinium_shields(void)
{
   game_o.p_actinium_shields.active = false;
   return(1);
};

int spawn_p_actinium_shields(void)
{
   game_o.p_actinium_shields.active = true;
   game_o.p_actinium_shields.alpha  = 3.0f;
   return(1);
};

int display_p_actinium_shields(void)
{
   bind_texture(310); //actinium_shields logo
   glLoadIdentity();
   glBegin( GL_QUADS );
   glColor4f (1.0f, 1.0f, 1.0f,game_o.p_actinium_shields.alpha);
   glTexCoord2i( 0, 1 );glVertex3f(-0.5f,-0.250f, 0.0001f);
   glTexCoord2i( 0, 0 );glVertex3f(-0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 0 );glVertex3f( 0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 1 );glVertex3f( 0.5f,-0.250f, 0.0001f);
   glColor4f (1.0f, 1.0f, 1.0f,1.0f);
   glEnd();
   return(1);
};

int process_p_actinium_shields(void)
{
   if (game_o.p_actinium_shields.active)
   {
      game_o.p_actinium_shields.alpha  -= 0.025f;
      if (game_o.p_actinium_shields.alpha <= 0) kill_p_actinium_shields();
   }
   return(1);
};

int kill_p_blasters(void)
{
   game_o.p_blasters.active = false;
   return(1);
};

int spawn_p_blasters(void)
{
   game_o.p_blasters.active = true;
   game_o.p_blasters.alpha  = 3.0f;
   return(1);
};

int display_p_blasters(void)
{
   bind_texture(311); //display kills logo
   glLoadIdentity();
   glBegin( GL_QUADS );
   glColor4f (1.0f, 1.0f, 1.0f,game_o.p_blasters.alpha);
   glTexCoord2i( 0, 1 );glVertex3f(-0.5f,-0.250f, 0.0001f);
   glTexCoord2i( 0, 0 );glVertex3f(-0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 0 );glVertex3f( 0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 1 );glVertex3f( 0.5f,-0.250f, 0.0001f);
   glColor4f (1.0f, 1.0f, 1.0f,1.0f);
   glEnd();
   return(1);
};

int process_p_blasters(void)
{
   if (game_o.p_blasters.active)
   {
      game_o.p_blasters.alpha  -= 0.025f;
      if (game_o.p_blasters.alpha <= 0) kill_p_blasters();
   }
   return(1);
};

int kill_p_burst_lasers(void)
{
   game_o.p_burst_lasers.active = false;
   return(1);
};

int spawn_p_burst_lasers(void)
{
   game_o.p_burst_lasers.active = true;
   game_o.p_burst_lasers.alpha  = 3.0f;
   return(1);
};

int display_p_burst_lasers(void)
{
   bind_texture(312); //display kills logo
   glLoadIdentity();
   glBegin( GL_QUADS );
   glColor4f (1.0f, 1.0f, 1.0f,game_o.p_burst_lasers.alpha);
   glTexCoord2i( 0, 1 );glVertex3f(-0.5f,-0.250f, 0.0001f);
   glTexCoord2i( 0, 0 );glVertex3f(-0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 0 );glVertex3f( 0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 1 );glVertex3f( 0.5f,-0.250f, 0.0001f);
   glColor4f (1.0f, 1.0f, 1.0f,1.0f);
   glEnd();
   return(1);
};

int process_p_burst_lasers(void)
{
   if (game_o.p_burst_lasers.active)
   {
      game_o.p_burst_lasers.alpha  -= 0.025f;
      if (game_o.p_burst_lasers.alpha <= 0) kill_p_burst_lasers();
   }
   return(1);
};

int kill_p_chain_guns(void)
{
   game_o.p_chain_guns.active = false;
   return(1);
};

int spawn_p_chain_guns(void)
{
   game_o.p_chain_guns.active = true;
   game_o.p_chain_guns.alpha  = 3.0f;
   return(1);
};

int display_p_chain_guns(void)
{
   bind_texture(313); //display kills logo
   glLoadIdentity();
   glBegin( GL_QUADS );
   glColor4f (1.0f, 1.0f, 1.0f,game_o.p_chain_guns.alpha);
   glTexCoord2i( 0, 1 );glVertex3f(-0.5f,-0.250f, 0.0001f);
   glTexCoord2i( 0, 0 );glVertex3f(-0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 0 );glVertex3f( 0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 1 );glVertex3f( 0.5f,-0.250f, 0.0001f);
   glColor4f (1.0f, 1.0f, 1.0f,1.0f);
   glEnd();
   return(1);
};

int process_p_chain_guns(void)
{
   if (game_o.p_chain_guns.active)
   {
      game_o.p_chain_guns.alpha  -= 0.025f;
      if (game_o.p_chain_guns.alpha <= 0) kill_p_chain_guns();
   }
   return(1);
};

int kill_p_convolution_thrusters(void)
{
   game_o.p_convolution_thrusters.active = false;
   return(1);
};

int spawn_p_convolution_thrusters(void)
{
   game_o.p_convolution_thrusters.active = true;
   game_o.p_convolution_thrusters.alpha  = 3.0f;
   return(1);
};

int display_p_convolution_thrusters(void)
{
   bind_texture(314); //display kills logo
   glLoadIdentity();
   glBegin( GL_QUADS );
   glColor4f (1.0f, 1.0f, 1.0f,game_o.p_convolution_thrusters.alpha);
   glTexCoord2i( 0, 1 );glVertex3f(-0.5f,-0.250f, 0.0001f);
   glTexCoord2i( 0, 0 );glVertex3f(-0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 0 );glVertex3f( 0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 1 );glVertex3f( 0.5f,-0.250f, 0.0001f);
   glColor4f (1.0f, 1.0f, 1.0f,1.0f);
   glEnd();
   return(1);
};

int process_p_convolution_thrusters(void)
{
   if (game_o.p_convolution_thrusters.active)
   {
      game_o.p_convolution_thrusters.alpha  -= 0.025f;
      if (game_o.p_convolution_thrusters.alpha <= 0) kill_p_convolution_thrusters();
   }
   return(1);
};

int kill_p_health(void)
{
   game_o.p_health.active = false;
   return(1);
};

int spawn_p_health(void)
{
   game_o.p_health.active = true;
   game_o.p_health.alpha  = 3.0f;
   return(1);
};

int display_p_health(void)
{
   bind_texture(315); //display kills logo
   glLoadIdentity();
   glBegin( GL_QUADS );
   glColor4f (1.0f, 1.0f, 1.0f,game_o.p_health.alpha);
   glTexCoord2i( 0, 1 );glVertex3f(-0.5f,-0.250f, 0.0001f);
   glTexCoord2i( 0, 0 );glVertex3f(-0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 0 );glVertex3f( 0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 1 );glVertex3f( 0.5f,-0.250f, 0.0001f);
   glColor4f (1.0f, 1.0f, 1.0f,1.0f);
   glEnd();
   return(1);
};

int process_p_health(void)
{
   if (game_o.p_health.active)
   {
      game_o.p_health.alpha  -= 0.025f;
      if (game_o.p_health.alpha <= 0) kill_p_health();
   }
   return(1);
};

int kill_p_ion_cannons(void)
{
   game_o.p_ion_cannons.active = false;
   return(1);
};

int spawn_p_ion_cannons(void)
{
   game_o.p_ion_cannons.active = true;
   game_o.p_ion_cannons.alpha  = 3.0f;
   return(1);
};

int display_p_ion_cannons(void)
{
   bind_texture(316); //display kills logo
   glLoadIdentity();
   glBegin( GL_QUADS );
   glColor4f (1.0f, 1.0f, 1.0f,game_o.p_ion_cannons.alpha);
   glTexCoord2i( 0, 1 );glVertex3f(-0.5f,-0.250f, 0.0001f);
   glTexCoord2i( 0, 0 );glVertex3f(-0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 0 );glVertex3f( 0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 1 );glVertex3f( 0.5f,-0.250f, 0.0001f);
   glColor4f (1.0f, 1.0f, 1.0f,1.0f);
   glEnd();
   return(1);
};

int process_p_ion_cannons(void)
{
   if (game_o.p_ion_cannons.active)
   {
      game_o.p_ion_cannons.alpha  -= 0.025f;
      if (game_o.p_ion_cannons.alpha <= 0) kill_p_ion_cannons();
   }
   return(1);
};

int kill_p_iridium_shileds(void)
{
   game_o.p_iridium_shileds.active = false;
   return(1);
};

int spawn_p_iridium_shileds(void)
{
   game_o.p_iridium_shileds.active = true;
   game_o.p_iridium_shileds.alpha  = 3.0f;
   return(1);
};

int display_p_iridium_shileds(void)
{
   bind_texture(317); //iridium_shileds logo
   glLoadIdentity();
   glBegin( GL_QUADS );
   glColor4f (1.0f, 1.0f, 1.0f,game_o.p_iridium_shileds.alpha);
   glTexCoord2i( 0, 1 );glVertex3f(-0.5f,-0.250f, 0.0001f);
   glTexCoord2i( 0, 0 );glVertex3f(-0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 0 );glVertex3f( 0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 1 );glVertex3f( 0.5f,-0.250f, 0.0001f);
   glColor4f (1.0f, 1.0f, 1.0f,1.0f);
   glEnd();
   return(1);
};

int process_p_iridium_shileds(void)
{
   if (game_o.p_iridium_shileds.active)
   {
      game_o.p_iridium_shileds.alpha  -= 0.025f;
      if (game_o.p_iridium_shileds.alpha <= 0) kill_p_iridium_shileds();
   }
   return(1);
};

int kill_p_maelstrom_thrusters(void)
{
   game_o.p_maelstrom_thrusters.active = false;
   return(1);
};

int spawn_p_maelstrom_thrusters(void)
{
   game_o.p_maelstrom_thrusters.active = true;
   game_o.p_maelstrom_thrusters.alpha  = 3.0f;
   return(1);
};

int display_p_maelstrom_thrusters(void)
{
   bind_texture(318); //display maelstrom_thrusters logo
   glLoadIdentity();
   glBegin( GL_QUADS );
   glColor4f (1.0f, 1.0f, 1.0f,game_o.p_maelstrom_thrusters.alpha);
   glTexCoord2i( 0, 1 );glVertex3f(-0.5f,-0.250f, 0.0001f);
   glTexCoord2i( 0, 0 );glVertex3f(-0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 0 );glVertex3f( 0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 1 );glVertex3f( 0.5f,-0.250f, 0.0001f);
   glColor4f (1.0f, 1.0f, 1.0f,1.0f);
   glEnd();
   return(1);
};

int process_p_maelstrom_thrusters(void)
{
   if (game_o.p_maelstrom_thrusters.active)
   {
      game_o.p_maelstrom_thrusters.alpha  -= 0.025f;
      if (game_o.p_maelstrom_thrusters.alpha <= 0) kill_p_maelstrom_thrusters();
   }
   return(1);
};

int kill_p_plasma_rockets(void)
{
   game_o.p_plasma_rockets.active = false;
   return(1);
};

int spawn_p_plasma_rockets(void)
{
   game_o.p_plasma_rockets.active = true;
   game_o.p_plasma_rockets.alpha  = 3.0f;
   return(1);
};

int display_p_plasma_rockets(void)
{
   bind_texture(319); //display kills logo
   glLoadIdentity();
   glBegin( GL_QUADS );
   glColor4f (1.0f, 1.0f, 1.0f,game_o.p_plasma_rockets.alpha);
   glTexCoord2i( 0, 1 );glVertex3f(-0.5f,-0.250f, 0.0001f);
   glTexCoord2i( 0, 0 );glVertex3f(-0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 0 );glVertex3f( 0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 1 );glVertex3f( 0.5f,-0.250f, 0.0001f);
   glColor4f (1.0f, 1.0f, 1.0f,1.0f);
   glEnd();
   return(1);
};

int process_p_plasma_rockets(void)
{
   if (game_o.p_plasma_rockets.active)
   {
      game_o.p_plasma_rockets.alpha  -= 0.025f;
      if (game_o.p_plasma_rockets.alpha <= 0) kill_p_plasma_rockets();
   }
   return(1);
};

int kill_p_rail_turrets(void)
{
   game_o.p_rail_turrets.active = false;
   return(1);
};

int spawn_p_rail_turrets(void)
{
   game_o.p_rail_turrets.active = true;
   game_o.p_rail_turrets.alpha  = 3.0f;
   return(1);
};

int display_p_rail_turrets(void)
{
   bind_texture(320); //display kills logo
   glLoadIdentity();
   glBegin( GL_QUADS );
   glColor4f (1.0f, 1.0f, 1.0f,game_o.p_rail_turrets.alpha);
   glTexCoord2i( 0, 1 );glVertex3f(-0.5f,-0.250f, 0.0001f);
   glTexCoord2i( 0, 0 );glVertex3f(-0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 0 );glVertex3f( 0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 1 );glVertex3f( 0.5f,-0.250f, 0.0001f);
   glColor4f (1.0f, 1.0f, 1.0f,1.0f);
   glEnd();
   return(1);
};

int process_p_rail_turrets(void)
{
   if (game_o.p_rail_turrets.active)
   {
      game_o.p_rail_turrets.alpha  -= 0.025f;
      if (game_o.p_rail_turrets.alpha <= 0) kill_p_rail_turrets();
   }
   return(1);
};

int kill_p_rubidium_shields(void)
{
   game_o.p_rubidium_shields.active = false;
   return(1);
};

int spawn_p_rubidium_shields(void)
{
   game_o.p_rubidium_shields.active = true;
   game_o.p_rubidium_shields.alpha  = 3.0f;
   return(1);
};

int display_p_rubidium_shields(void)
{
   bind_texture(321); //display kills logo
   glLoadIdentity();
   glBegin( GL_QUADS );
   glColor4f (1.0f, 1.0f, 1.0f,game_o.p_rubidium_shields.alpha);
   glTexCoord2i( 0, 1 );glVertex3f(-0.5f,-0.250f, 0.0001f);
   glTexCoord2i( 0, 0 );glVertex3f(-0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 0 );glVertex3f( 0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 1 );glVertex3f( 0.5f,-0.250f, 0.0001f);
   glColor4f (1.0f, 1.0f, 1.0f,1.0f);
   glEnd();
   return(1);
};

int process_p_rubidium_shields(void)
{
   if (game_o.p_rubidium_shields.active)
   {
      game_o.p_rubidium_shields.alpha  -= 0.025f;
      if (game_o.p_rubidium_shields.alpha <= 0) kill_p_rubidium_shields();
   }
   return(1);
};

int kill_p_seismic_thrusters(void)
{
   game_o.p_seismic_thrusters.active = false;
   return(1);
};

int spawn_p_seismic_thrusters(void)
{
   game_o.p_seismic_thrusters.active = true;
   game_o.p_seismic_thrusters.alpha  = 3.0f;
   return(1);
};

int display_p_seismic_thrusters(void)
{
   bind_texture(322); //display kills logo
   glLoadIdentity();
   glBegin( GL_QUADS );
   glColor4f (1.0f, 1.0f, 1.0f,game_o.p_seismic_thrusters.alpha);
   glTexCoord2i( 0, 1 );glVertex3f(-0.5f,-0.250f, 0.0001f);
   glTexCoord2i( 0, 0 );glVertex3f(-0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 0 );glVertex3f( 0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 1 );glVertex3f( 0.5f,-0.250f, 0.0001f);
   glColor4f (1.0f, 1.0f, 1.0f,1.0f);
   glEnd();
   return(1);
};

int process_p_seismic_thrusters(void)
{
   if (game_o.p_seismic_thrusters.active)
   {
      game_o.p_seismic_thrusters.alpha  -= 0.025f;
      if (game_o.p_seismic_thrusters.alpha <= 0) kill_p_seismic_thrusters();
   }
   return(1);
};

int kill_p_shield_level_up(void)
{
   game_o.p_shield_level_up.active = false;
   return(1);
};

int spawn_p_shield_level_up(void)
{
   game_o.p_shield_level_up.active = true;
   game_o.p_shield_level_up.alpha  = 3.0f;
   return(1);
};

int display_p_shield_level_up(void)
{
   bind_texture(323); //display kills logo
   glLoadIdentity();
   glBegin( GL_QUADS );
   glColor4f (1.0f, 1.0f, 1.0f,game_o.p_shield_level_up.alpha);
   glTexCoord2i( 0, 1 );glVertex3f(-0.5f,-0.250f, 0.0001f);
   glTexCoord2i( 0, 0 );glVertex3f(-0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 0 );glVertex3f( 0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 1 );glVertex3f( 0.5f,-0.250f, 0.0001f);
   glColor4f (1.0f, 1.0f, 1.0f,1.0f);
   glEnd();
   return(1);
};

int process_p_shield_level_up(void)
{
   if (game_o.p_shield_level_up.active)
   {
      game_o.p_shield_level_up.alpha  -= 0.025f;
      if (game_o.p_shield_level_up.alpha <= 0) kill_p_shield_level_up();
   }
   return(1);
};

int kill_p_tantalum_shields(void)
{
   game_o.p_tantalum_shields.active = false;
   return(1);
};

int spawn_p_tantalum_shields(void)
{
   game_o.p_tantalum_shields.active = true;
   game_o.p_tantalum_shields.alpha  = 3.0f;
   return(1);
};

int display_p_tantalum_shields(void)
{
   bind_texture(324); //display kills logo
   glLoadIdentity();
   glBegin( GL_QUADS );
   glColor4f (1.0f, 1.0f, 1.0f,game_o.p_tantalum_shields.alpha);
   glTexCoord2i( 0, 1 );glVertex3f(-0.5f,-0.250f, 0.0001f);
   glTexCoord2i( 0, 0 );glVertex3f(-0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 0 );glVertex3f( 0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 1 );glVertex3f( 0.5f,-0.250f, 0.0001f);
   glColor4f (1.0f, 1.0f, 1.0f,1.0f);
   glEnd();
   return(1);
};

int process_p_tantalum_shields(void)
{
   if (game_o.p_tantalum_shields.active)
   {
      game_o.p_tantalum_shields.alpha  -= 0.025f;
      if (game_o.p_tantalum_shields.alpha <= 0) kill_p_tantalum_shields();
   }
   return(1);
};

int kill_p_terbium_shields(void)
{
   game_o.p_terbium_shields.active = false;
   return(1);
};

int spawn_p_terbium_shields(void)
{
   game_o.p_terbium_shields.active = true;
   game_o.p_terbium_shields.alpha  = 3.0f;
   return(1);
};

int display_p_terbium_shields(void)
{
   bind_texture(325); //display kills logo
   glLoadIdentity();
   glBegin( GL_QUADS );
   glColor4f (1.0f, 1.0f, 1.0f,game_o.p_terbium_shields.alpha);
   glTexCoord2i( 0, 1 );glVertex3f(-0.5f,-0.250f, 0.0001f);
   glTexCoord2i( 0, 0 );glVertex3f(-0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 0 );glVertex3f( 0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 1 );glVertex3f( 0.5f,-0.250f, 0.0001f);
   glColor4f (1.0f, 1.0f, 1.0f,1.0f);
   glEnd();
   return(1);
};

int process_p_terbium_shields(void)
{
   if (game_o.p_terbium_shields.active)
   {
      game_o.p_terbium_shields.alpha  -= 0.025f;
      if (game_o.p_terbium_shields.alpha <= 0) kill_p_terbium_shields();
   }
   return(1);
};

int kill_p_thrusters_level_up(void)
{
   game_o.p_thrusters_level_up.active = false;
   return(1);
};

int spawn_p_thrusters_level_up(void)
{
   game_o.p_thrusters_level_up.active = true;
   game_o.p_thrusters_level_up.alpha  = 3.0f;
   return(1);
};

int display_p_thrusters_level_up(void)
{
   bind_texture(326); //display kills logo
   glLoadIdentity();
   glBegin( GL_QUADS );
   glColor4f (1.0f, 1.0f, 1.0f,game_o.p_thrusters_level_up.alpha);
   glTexCoord2i( 0, 1 );glVertex3f(-0.5f,-0.250f, 0.0001f);
   glTexCoord2i( 0, 0 );glVertex3f(-0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 0 );glVertex3f( 0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 1 );glVertex3f( 0.5f,-0.250f, 0.0001f);
   glColor4f (1.0f, 1.0f, 1.0f,1.0f);
   glEnd();
   return(1);
};

int process_p_thrusters_level_up(void)
{
   if (game_o.p_thrusters_level_up.active)
   {
      game_o.p_thrusters_level_up.alpha  -= 0.025f;
      if (game_o.p_thrusters_level_up.alpha <= 0) kill_p_thrusters_level_up();
   }
   return(1);
};

int kill_p_vortex_thrusters(void)
{
   game_o.p_vortex_thrusters.active = false;
   return(1);
};

int spawn_p_vortex_thrusters(void)

{
   game_o.p_vortex_thrusters.active = true;
   game_o.p_vortex_thrusters.alpha  = 3.0f;
   return(1);
};

int display_p_vortex_thrusters(void)
{
   bind_texture(327); //display kills logo
   glLoadIdentity();
   glBegin( GL_QUADS );
   glColor4f (1.0f, 1.0f, 1.0f,game_o.p_vortex_thrusters.alpha);
   glTexCoord2i( 0, 1 );glVertex3f(-0.5f,-0.250f, 0.0001f);
   glTexCoord2i( 0, 0 );glVertex3f(-0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 0 );glVertex3f( 0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 1 );glVertex3f( 0.5f,-0.250f, 0.0001f);
   glColor4f (1.0f, 1.0f, 1.0f,1.0f);
   glEnd();
   return(1);
};

int process_p_vortex_thrusters(void)
{
   if (game_o.p_vortex_thrusters.active)
   {
      game_o.p_vortex_thrusters.alpha  -= 0.025f;
      if (game_o.p_vortex_thrusters.alpha <= 0) kill_p_vortex_thrusters();
   }
   return(1);
};

int kill_p_weapon_level_up(void)
{
   game_o.p_weapon_level_up.active = false;
   return(1);
};

int spawn_p_weapon_level_up(void)
{
   game_o.p_weapon_level_up.active = true;
   game_o.p_weapon_level_up.alpha  = 3.0f;
   return(1);
};

int display_p_weapon_level_up(void)
{
   bind_texture(328); //display kills logo
   glLoadIdentity();
   glBegin( GL_QUADS );
   glColor4f (1.0f, 1.0f, 1.0f,game_o.p_weapon_level_up.alpha);
   glTexCoord2i( 0, 1 );glVertex3f(-0.5f,-0.250f, 0.0001f);
   glTexCoord2i( 0, 0 );glVertex3f(-0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 0 );glVertex3f( 0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 1 );glVertex3f( 0.5f,-0.250f, 0.0001f);
   glColor4f (1.0f, 1.0f, 1.0f,1.0f);
   glEnd();
   return(1);
};

int process_p_weapon_level_up(void)
{
   if (game_o.p_weapon_level_up.active)
   {
      game_o.p_weapon_level_up.alpha  -= 0.025f;
      if (game_o.p_weapon_level_up.alpha <= 0) kill_p_weapon_level_up();
   }
   return(1);
};

int kill_d_level_end(void)
{
   game_o.level_end_display_active = false;
   return(1);
};

int spawn_d_level_end(void)
{
   game_o.level_end_display_active = true;
   game_o.level_end_display_alpha  = 0.001250f;
   game_o.level_end_display_count  = 3.0f;
   return(1);
};

int display_d_level_end(void)
{
   bind_texture(333); //display level completed
   glLoadIdentity();
   glBegin( GL_QUADS );
   glColor4f (1.0f, 1.0f, 1.0f,game_o.level_end_display_count);
   glTexCoord2i( 0, 1 );glVertex3f(-0.5f,-0.250f, 0.0001f);
   glTexCoord2i( 0, 0 );glVertex3f(-0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 0 );glVertex3f( 0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 1 );glVertex3f( 0.5f,-0.250f, 0.0001f);
   glColor4f (1.0f, 1.0f, 1.0f,1.0f);
   glEnd();
   return(1);
};

int process_d_level_end(void)
{
   if (game_o.level_end_display_active)
   {
      game_o.level_end_display_count  -= 0.025f;
      if (game_o.level_end_display_count <= game_o.level_end_display_alpha) game_o.level_end_display_count = game_o.level_end_display_alpha;
   }
   return(1);
};


