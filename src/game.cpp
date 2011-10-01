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


#include <SDL/SDL.h>
#include "core/core.hpp"
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
    game.game_paused                         = false;
    game.game_active                         = false;
    game.game_resume                         = false;
    game.outr_active                         = false;
    game.menu_active                         = true;
    game.pdie_active                         = false;
    game.nlvl_active                         = false;

    game_o.anc_enabled                       =  false;
    game_o.fps_enabled                       =  false;
    game_o.npc_damage_duration               =  10;
    game_o.exp_rate                          =  5;
    game_o.coin_spawn_rate                   =  665.36 * 5;
    game_o.wexp_spawn_rate                   =  665.36 * 10;
    game_o.npc_spawn_rate                    =  256;
    game_o.npc_spawn_rate_count              =  0;
    game_o.paused.active                     =  false;
    game_o.number_bombs                      =  0;
    game_o.bomb_delay                        =  32;
    game_o.bomb_delay_count                  =  0;
    game_o.immune                            =  true;
    game_o.immunity_state                    =  0;
    game_o.immunity_delay                    =  256;
    game_o.immunity_delay_count              =  0;
    game_o.score                             =  0;
    game_o.kills                             =  0;
    game_o.level_kills                       =  0;
    game_o.level_spawened                    =  0;
    game_o.level_score                       =  0;
    game_o.victory_kills                     =  0;
    game_o.victory_spawened                  =  0;
    game_o.victory_score                     =  0;
    game_o.level_end_count                   =  0;
    game_o.level_end_time_out                =  300;
    game_o.level_end_time                    =  false;
    game_o.level_end_phase                   =  0;
    game_o.level_end_display_active          =  false;
    game_o.powerups_spawened                 =  false;
    game_o.completed                         =  0;
    game_o.speed                             =  0.045f;
    game_o.fw_rof_count                      =  0;
    game_o.sw_rof_count                      =  0;
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

    init_achievements();
    init_projectiles(re_init);
    init_shields    (re_init);
    init_thrusters  (re_init);
    init_enemies    (re_init);
    init_in_game_message_class();
    init_player_bullets();
    init_supportships(2,game_o.player.x_pos,game_o.player.y_pos);
    init_waves();
    init_coin();
    init_wexp();
    init_levels();
    init_explosions();
    return(0);
};


/*----------------------------------------------------------------------------*/
int process_game(void)
{
    bool return_data        = false;
    float temp_x            = 0.0f;
    float temp_y            = 0.0f;
    int   temp_r            = 0;
    if (game_o.rumble.active) game_o.rumble.process();
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
    game_o.p_actinium_shields.process();
    game_o.p_blasters.process();
    game_o.p_burst_lasers.process();
    game_o.p_chain_guns.process();
    game_o.p_convolution_thrusters.process();
    game_o.p_health.process();
    game_o.p_ion_cannons.process();
    game_o.p_iridium_shileds.process();
    game_o.p_maelstrom_thrusters.process();
    game_o.p_plasma_rockets.process();
    game_o.p_rail_turrets.process();
    game_o.p_rubidium_shields.process();
    game_o.p_seismic_thrusters.process();
    game_o.p_shield_level_up.process();
    game_o.p_tantalum_shields.process();
    game_o.p_terbium_shields.process();
    game_o.p_thrusters_level_up.process();
    game_o.p_vortex_thrusters.process();
    game_o.p_weapon_level_up.process();
    achievement_kills_process();
    achievement_score_process();
    game_o.paused.process();
    game_o.loaded.process();
    game_o.saved.process();
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
    proc_thrusters();
    if (level_completed())
    {
        game.game_active      = false;
        game.nlvl_active      = true;
        game.music_next_track = true;
        game.background.set_data  ( 1, 1, 1, 0.0f, 0.0f, 0.0020f, 0.0020f, texture.menu_background_001.ref_number);
        game.background.set_data  ( 2, 1, 1, 0.0f, 0.0f, 0.0050f, 0.0050f, texture.menu_background_000.ref_number);
        game.background.set_active( 3, false);
        game.background.set_active( 4, false);
        game.background.set_movement_type(BOUNCE);
    }
    if  (random(game_o.powerup[1 ].spawn_rate) <= 5) spawn_powerup(1.0f,random_GLcoord(), 1);//spawn health power-up
    if ((random(game_o.powerup[8 ].spawn_rate) <= 5)&& (!boss_level())) spawn_powerup(1.0f,random_GLcoord(), 8);//spawn bomb power-up

    if ((game_o.level >=  4) && (random(game_o.powerup[9 ].spawn_rate) <= 2)) spawn_powerup(1.0f,random_GLcoord(), 9);//spawn support ship 0 power-up
    if ((game_o.level >=  7) && (random(game_o.powerup[10].spawn_rate) <= 2)) spawn_powerup(1.0f,random_GLcoord(),10);//spawn support ship 1 power-up
    if ((game_o.level >= 11) && (random(game_o.powerup[11].spawn_rate) <= 2)) spawn_powerup(1.0f,random_GLcoord(),11);//spawn support ship 2 power-up
    if ((game_o.level >= 15) && (random(game_o.powerup[12].spawn_rate) <= 2)) spawn_powerup(1.0f,random_GLcoord(),12);//spawn support ship 3 power-up

    if ((game_o.shield[game_o.player.front_shield].level  < 3) && (random(game_o.powerup[2].spawn_rate) == 5)) spawn_powerup(1.0f,random_GLcoord(),2);//spawn shield level power-up
    if ((game_o.thruster[game_o.player.thrusters].level   < 3) && (random(game_o.powerup[2].spawn_rate) == 5)) spawn_powerup(1.0f,random_GLcoord(),4);//spawn thruster level power-up
    // if player missed boss weapon drops enable random spawning of power-ups to keep consistency
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
        if (game_o.level_boss_level && (game_o.level_spawened == 0))
        {
            spawn_npc(1.0f,random_GLcoord(),game_o.level_npc_type,0,0.0f,0.0f);
            game_o.level_spawened += 1;
        }
        if ((!game_o.level_boss_level) && (!game_o.level_end_time) && (game_o.wave_spawnable)) spawn_wave();
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
    if (game_o.level_end_time) game_o.d_level_end.process();
    if ((game_o.level_end_time) && (game_o.level_end_phase == 0)) //level end phase
    {
        if (game_o.level_end_rumble)
        {
            game_o.level_end_rumble = false;
            game_o.rumble.start(0.025,300);
        }
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
                    spawn_powerup(1.0f,random_GLcoord(),1);//spawn health power-up
                    spawn_powerup(1.0f,random_GLcoord(),4);//spawn thruster level power-up
                    spawn_powerup(1.0f,random_GLcoord(),7);//new weapon
                }
                if (game_o.level == 7)
                {
                    spawn_powerup(1.0f,random_GLcoord(),1);//spawn health power-up
                    spawn_powerup(1.0f,random_GLcoord(),3);//spawn shield new power-up
                    spawn_powerup(1.0f,random_GLcoord(),7);//new weapon
                }
                if (game_o.level == 11)
                {
                    spawn_powerup(1.0f,random_GLcoord(),1);//spawn health power-up
                    spawn_powerup(1.0f,random_GLcoord(),3);//spawn shield new power-up
                    spawn_powerup(1.0f,random_GLcoord(),7);//new weapon
                }
                if (game_o.level == 15)
                {
                    spawn_powerup(1.0f,random_GLcoord(),1);//spawn health power-up
                    spawn_powerup(1.0f,random_GLcoord(),5);//spawn thruster new power-up
                    spawn_powerup(1.0f,random_GLcoord(),3);//spawn shield new power-up
                    spawn_powerup(1.0f,random_GLcoord(),7);//new weapon
                }
                if (game_o.level == 19)
                {
                    spawn_powerup(1.0f,random_GLcoord(),1);//spawn health power-up
                    spawn_powerup(1.0f,random_GLcoord(),5);//spawn thruster new power-up
                    spawn_powerup(1.0f,random_GLcoord(),3);//spawn shield new power-up
                    spawn_powerup(1.0f,random_GLcoord(),7);//new weapon
                }
                if (game_o.level == 23)
                {
                    spawn_powerup(1.0f,random_GLcoord(),1);//spawn health power-up
                    spawn_powerup(1.0f,random_GLcoord(),5);//spawn thruster new power-up
                    spawn_powerup(1.0f,random_GLcoord(),3);//spawn shield new power-up
                    spawn_powerup(1.0f,random_GLcoord(),6);//spawn weapon level power-up
                }
            }
            else
            {
                // spawn power-ups if level is too low, ie. player missed the power up last level or in game or it hasn't spawned in game
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
        if (!game_o.level_end_display_active) game_o.d_level_end.spawn();
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
            if (game_o.npc[npc_count].bullet[bullet_count].active)
            {
                z_pos = 0.05f + (0.0001*bullet_count);
                if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].image == texture.projectile_000.ref_number) texture.projectile_000.draw(true,game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,z_pos,game_o.npc[npc_count].bullet[bullet_count].width,game_o.npc[npc_count].bullet[bullet_count].height,180.0f);
                if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].image == texture.projectile_001.ref_number) texture.projectile_001.draw(true,game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,z_pos,game_o.npc[npc_count].bullet[bullet_count].width,game_o.npc[npc_count].bullet[bullet_count].height,180.0f);
                if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].image == texture.projectile_002.ref_number) texture.projectile_002.draw(true,game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,z_pos,game_o.npc[npc_count].bullet[bullet_count].width,game_o.npc[npc_count].bullet[bullet_count].height,180.0f);
                if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].image == texture.projectile_003.ref_number) texture.projectile_003.draw(true,game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,z_pos,game_o.npc[npc_count].bullet[bullet_count].width,game_o.npc[npc_count].bullet[bullet_count].height,180.0f);
                if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].image == texture.projectile_004.ref_number) texture.projectile_004.draw(true,game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,z_pos,game_o.npc[npc_count].bullet[bullet_count].width,game_o.npc[npc_count].bullet[bullet_count].height,180.0f);
                if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].image == texture.projectile_005.ref_number) texture.projectile_005.draw(true,game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,z_pos,game_o.npc[npc_count].bullet[bullet_count].width,game_o.npc[npc_count].bullet[bullet_count].height,180.0f);
                if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].image == texture.projectile_006.ref_number) texture.projectile_006.draw(true,game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,z_pos,game_o.npc[npc_count].bullet[bullet_count].width,game_o.npc[npc_count].bullet[bullet_count].height,180.0f);
                if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].image == texture.projectile_007.ref_number) texture.projectile_007.draw(true,game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,z_pos,game_o.npc[npc_count].bullet[bullet_count].width,game_o.npc[npc_count].bullet[bullet_count].height,180.0f);
                if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].image == texture.projectile_008.ref_number) texture.projectile_008.draw(true,game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,z_pos,game_o.npc[npc_count].bullet[bullet_count].width,game_o.npc[npc_count].bullet[bullet_count].height,180.0f);
                if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].image == texture.projectile_009.ref_number) texture.projectile_009.draw(true,game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,z_pos,game_o.npc[npc_count].bullet[bullet_count].width,game_o.npc[npc_count].bullet[bullet_count].height,180.0f);
                if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].image == texture.projectile_010.ref_number) texture.projectile_010.draw(true,game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,z_pos,game_o.npc[npc_count].bullet[bullet_count].width,game_o.npc[npc_count].bullet[bullet_count].height,180.0f);
                if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].image == texture.projectile_011.ref_number) texture.projectile_011.draw(true,game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,z_pos,game_o.npc[npc_count].bullet[bullet_count].width,game_o.npc[npc_count].bullet[bullet_count].height,180.0f);
                if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].image == texture.projectile_012.ref_number) texture.projectile_012.draw(true,game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,z_pos,game_o.npc[npc_count].bullet[bullet_count].width,game_o.npc[npc_count].bullet[bullet_count].height,180.0f);
                if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].image == texture.projectile_013.ref_number) texture.projectile_013.draw(true,game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,z_pos,game_o.npc[npc_count].bullet[bullet_count].width,game_o.npc[npc_count].bullet[bullet_count].height,180.0f);
                if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].image == texture.projectile_014.ref_number) texture.projectile_014.draw(true,game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,z_pos,game_o.npc[npc_count].bullet[bullet_count].width,game_o.npc[npc_count].bullet[bullet_count].height,180.0f);
                if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].image == texture.projectile_015.ref_number) texture.projectile_015.draw(true,game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,z_pos,game_o.npc[npc_count].bullet[bullet_count].width,game_o.npc[npc_count].bullet[bullet_count].height,180.0f);
                if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].image == texture.projectile_016.ref_number) texture.projectile_016.draw(true,game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,z_pos,game_o.npc[npc_count].bullet[bullet_count].width,game_o.npc[npc_count].bullet[bullet_count].height,180.0f);
                if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].image == texture.projectile_017.ref_number) texture.projectile_017.draw(true,game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,z_pos,game_o.npc[npc_count].bullet[bullet_count].width,game_o.npc[npc_count].bullet[bullet_count].height,180.0f);
                if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].image == texture.projectile_018.ref_number) texture.projectile_018.draw(true,game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,z_pos,game_o.npc[npc_count].bullet[bullet_count].width,game_o.npc[npc_count].bullet[bullet_count].height,180.0f);
                if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].image == texture.projectile_019.ref_number) texture.projectile_019.draw(true,game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,z_pos,game_o.npc[npc_count].bullet[bullet_count].width,game_o.npc[npc_count].bullet[bullet_count].height,180.0f);
                if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].image == texture.projectile_020.ref_number) texture.projectile_020.draw(true,game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,z_pos,game_o.npc[npc_count].bullet[bullet_count].width,game_o.npc[npc_count].bullet[bullet_count].height,180.0f);
                if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].image == texture.projectile_021.ref_number) texture.projectile_021.draw(true,game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,z_pos,game_o.npc[npc_count].bullet[bullet_count].width,game_o.npc[npc_count].bullet[bullet_count].height,180.0f);
                if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].image == texture.projectile_022.ref_number) texture.projectile_022.draw(true,game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,z_pos,game_o.npc[npc_count].bullet[bullet_count].width,game_o.npc[npc_count].bullet[bullet_count].height,180.0f);
                if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].image == texture.projectile_023.ref_number) texture.projectile_023.draw(true,game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,z_pos,game_o.npc[npc_count].bullet[bullet_count].width,game_o.npc[npc_count].bullet[bullet_count].height,180.0f);
                if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].image == texture.projectile_024.ref_number) texture.projectile_024.draw(true,game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,z_pos,game_o.npc[npc_count].bullet[bullet_count].width,game_o.npc[npc_count].bullet[bullet_count].height,180.0f);
                if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].image == texture.projectile_025.ref_number) texture.projectile_025.draw(true,game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,z_pos,game_o.npc[npc_count].bullet[bullet_count].width,game_o.npc[npc_count].bullet[bullet_count].height,180.0f);
                if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].image == texture.projectile_026.ref_number) texture.projectile_026.draw(true,game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,z_pos,game_o.npc[npc_count].bullet[bullet_count].width,game_o.npc[npc_count].bullet[bullet_count].height,180.0f);
                if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].image == texture.projectile_027.ref_number) texture.projectile_027.draw(true,game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,z_pos,game_o.npc[npc_count].bullet[bullet_count].width,game_o.npc[npc_count].bullet[bullet_count].height,180.0f);
                if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].image == texture.projectile_028.ref_number) texture.projectile_028.draw(true,game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,z_pos,game_o.npc[npc_count].bullet[bullet_count].width,game_o.npc[npc_count].bullet[bullet_count].height,180.0f);
                if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].image == texture.projectile_029.ref_number) texture.projectile_029.draw(true,game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,z_pos,game_o.npc[npc_count].bullet[bullet_count].width,game_o.npc[npc_count].bullet[bullet_count].height,180.0f);
                if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].image == texture.projectile_030.ref_number) texture.projectile_030.draw(true,game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,z_pos,game_o.npc[npc_count].bullet[bullet_count].width,game_o.npc[npc_count].bullet[bullet_count].height,180.0f);
                if (game_o.projectile[game_o.npc[npc_count].bullet[bullet_count].warhead].image == texture.projectile_031.ref_number) texture.projectile_031.draw(true,game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,z_pos,game_o.npc[npc_count].bullet[bullet_count].width,game_o.npc[npc_count].bullet[bullet_count].height,180.0f);
            }
        }
        z_pos = 0.04f + (0.0001*npc_count); // npc's
        if (game_o.npc[npc_count].active)
        {
            float temp_r = 1.0f;
            float temp_g = 1.0f;
            float temp_b = 1.0f;
            float temp_a = 1.0f;
            if (game_o.npc[npc_count].damaged > (game_o.npc_damage_duration/5))
            {
                temp_r = 1.0f;
                temp_g = 0.0f;
                temp_b = 0.0f;
                temp_a = 0.6f;
            }//ps. width and height are used in reverse as values are swapped somewhere.
            if (game_o.enemy[game_o.npc[npc_count].type_npc].image == texture.ship_000.ref_number) texture.ship_000.draw(true,game_o.npc[npc_count].x_pos,game_o.npc[npc_count].y_pos,z_pos,game_o.npc[npc_count].height,game_o.npc[npc_count].width, 90.0f,temp_r,temp_g,temp_b,temp_a);
            if (game_o.enemy[game_o.npc[npc_count].type_npc].image == texture.ship_001.ref_number) texture.ship_001.draw(true,game_o.npc[npc_count].x_pos,game_o.npc[npc_count].y_pos,z_pos,game_o.npc[npc_count].height,game_o.npc[npc_count].width, 90.0f,temp_r,temp_g,temp_b,temp_a);
            if (game_o.enemy[game_o.npc[npc_count].type_npc].image == texture.ship_002.ref_number) texture.ship_002.draw(true,game_o.npc[npc_count].x_pos,game_o.npc[npc_count].y_pos,z_pos,game_o.npc[npc_count].height,game_o.npc[npc_count].width, 90.0f,temp_r,temp_g,temp_b,temp_a);
            if (game_o.enemy[game_o.npc[npc_count].type_npc].image == texture.ship_003.ref_number) texture.ship_003.draw(true,game_o.npc[npc_count].x_pos,game_o.npc[npc_count].y_pos,z_pos,game_o.npc[npc_count].height,game_o.npc[npc_count].width, 90.0f,temp_r,temp_g,temp_b,temp_a);
            if (game_o.enemy[game_o.npc[npc_count].type_npc].image == texture.ship_004.ref_number) texture.ship_004.draw(true,game_o.npc[npc_count].x_pos,game_o.npc[npc_count].y_pos,z_pos,game_o.npc[npc_count].height,game_o.npc[npc_count].width, 90.0f,temp_r,temp_g,temp_b,temp_a);
            if (game_o.enemy[game_o.npc[npc_count].type_npc].image == texture.ship_005.ref_number) texture.ship_005.draw(true,game_o.npc[npc_count].x_pos,game_o.npc[npc_count].y_pos,z_pos,game_o.npc[npc_count].height,game_o.npc[npc_count].width, 90.0f,temp_r,temp_g,temp_b,temp_a);
            if (game_o.enemy[game_o.npc[npc_count].type_npc].image == texture.ship_006.ref_number) texture.ship_006.draw(true,game_o.npc[npc_count].x_pos,game_o.npc[npc_count].y_pos,z_pos,game_o.npc[npc_count].height,game_o.npc[npc_count].width, 90.0f,temp_r,temp_g,temp_b,temp_a);
            if (game_o.enemy[game_o.npc[npc_count].type_npc].image == texture.ship_007.ref_number) texture.ship_007.draw(true,game_o.npc[npc_count].x_pos,game_o.npc[npc_count].y_pos,z_pos,game_o.npc[npc_count].height,game_o.npc[npc_count].width, 90.0f,temp_r,temp_g,temp_b,temp_a);
            if (game_o.enemy[game_o.npc[npc_count].type_npc].image == texture.ship_008.ref_number) texture.ship_008.draw(true,game_o.npc[npc_count].x_pos,game_o.npc[npc_count].y_pos,z_pos,game_o.npc[npc_count].height,game_o.npc[npc_count].width, 90.0f,temp_r,temp_g,temp_b,temp_a);
            if (game_o.enemy[game_o.npc[npc_count].type_npc].image == texture.ship_009.ref_number) texture.ship_009.draw(true,game_o.npc[npc_count].x_pos,game_o.npc[npc_count].y_pos,z_pos,game_o.npc[npc_count].height,game_o.npc[npc_count].width, 90.0f,temp_r,temp_g,temp_b,temp_a);
            if (game_o.enemy[game_o.npc[npc_count].type_npc].image == texture.ship_010.ref_number) texture.ship_010.draw(true,game_o.npc[npc_count].x_pos,game_o.npc[npc_count].y_pos,z_pos,game_o.npc[npc_count].height,game_o.npc[npc_count].width, 90.0f,temp_r,temp_g,temp_b,temp_a);
            if (game_o.enemy[game_o.npc[npc_count].type_npc].image == texture.ship_011.ref_number) texture.ship_011.draw(true,game_o.npc[npc_count].x_pos,game_o.npc[npc_count].y_pos,z_pos,game_o.npc[npc_count].height,game_o.npc[npc_count].width, 90.0f,temp_r,temp_g,temp_b,temp_a);
            if (game_o.enemy[game_o.npc[npc_count].type_npc].image == texture.ship_012.ref_number) texture.ship_012.draw(true,game_o.npc[npc_count].x_pos,game_o.npc[npc_count].y_pos,z_pos,game_o.npc[npc_count].height,game_o.npc[npc_count].width, 90.0f,temp_r,temp_g,temp_b,temp_a);
            if (game_o.enemy[game_o.npc[npc_count].type_npc].image == texture.ship_013.ref_number) texture.ship_013.draw(true,game_o.npc[npc_count].x_pos,game_o.npc[npc_count].y_pos,z_pos,game_o.npc[npc_count].height,game_o.npc[npc_count].width, 90.0f,temp_r,temp_g,temp_b,temp_a);
            if (game_o.enemy[game_o.npc[npc_count].type_npc].image == texture.ship_014.ref_number) texture.ship_014.draw(true,game_o.npc[npc_count].x_pos,game_o.npc[npc_count].y_pos,z_pos,game_o.npc[npc_count].height,game_o.npc[npc_count].width, 90.0f,temp_r,temp_g,temp_b,temp_a);
            if (game_o.enemy[game_o.npc[npc_count].type_npc].image == texture.ship_015.ref_number) texture.ship_015.draw(true,game_o.npc[npc_count].x_pos,game_o.npc[npc_count].y_pos,z_pos,game_o.npc[npc_count].height,game_o.npc[npc_count].width, 90.0f,temp_r,temp_g,temp_b,temp_a);
            if (game_o.enemy[game_o.npc[npc_count].type_npc].image == texture.ship_016.ref_number) texture.ship_016.draw(true,game_o.npc[npc_count].x_pos,game_o.npc[npc_count].y_pos,z_pos,game_o.npc[npc_count].height,game_o.npc[npc_count].width, 90.0f,temp_r,temp_g,temp_b,temp_a);
            if (game_o.enemy[game_o.npc[npc_count].type_npc].image == texture.ship_017.ref_number) texture.ship_017.draw(true,game_o.npc[npc_count].x_pos,game_o.npc[npc_count].y_pos,z_pos,game_o.npc[npc_count].height,game_o.npc[npc_count].width, 90.0f,temp_r,temp_g,temp_b,temp_a);
            if (game_o.enemy[game_o.npc[npc_count].type_npc].image == texture.ship_018.ref_number) texture.ship_018.draw(true,game_o.npc[npc_count].x_pos,game_o.npc[npc_count].y_pos,z_pos,game_o.npc[npc_count].height,game_o.npc[npc_count].width, 90.0f,temp_r,temp_g,temp_b,temp_a);
            if (game_o.enemy[game_o.npc[npc_count].type_npc].image == texture.ship_019.ref_number) texture.ship_019.draw(true,game_o.npc[npc_count].x_pos,game_o.npc[npc_count].y_pos,z_pos,game_o.npc[npc_count].height,game_o.npc[npc_count].width, 90.0f,temp_r,temp_g,temp_b,temp_a);
            if (game_o.enemy[game_o.npc[npc_count].type_npc].image == texture.ship_020.ref_number) texture.ship_020.draw(true,game_o.npc[npc_count].x_pos,game_o.npc[npc_count].y_pos,z_pos,game_o.npc[npc_count].height,game_o.npc[npc_count].width, 90.0f,temp_r,temp_g,temp_b,temp_a);
            if (game_o.enemy[game_o.npc[npc_count].type_npc].image == texture.ship_021.ref_number) texture.ship_021.draw(true,game_o.npc[npc_count].x_pos,game_o.npc[npc_count].y_pos,z_pos,game_o.npc[npc_count].height,game_o.npc[npc_count].width, 90.0f,temp_r,temp_g,temp_b,temp_a);
            if (game_o.enemy[game_o.npc[npc_count].type_npc].image == texture.ship_022.ref_number) texture.ship_022.draw(true,game_o.npc[npc_count].x_pos,game_o.npc[npc_count].y_pos,z_pos,game_o.npc[npc_count].height,game_o.npc[npc_count].width, 90.0f,temp_r,temp_g,temp_b,temp_a);
            if (game_o.enemy[game_o.npc[npc_count].type_npc].image == texture.ship_023.ref_number) texture.ship_023.draw(true,game_o.npc[npc_count].x_pos,game_o.npc[npc_count].y_pos,z_pos,game_o.npc[npc_count].height,game_o.npc[npc_count].width, 90.0f,temp_r,temp_g,temp_b,temp_a);
            if (game_o.enemy[game_o.npc[npc_count].type_npc].image == texture.ship_024.ref_number) texture.ship_024.draw(true,game_o.npc[npc_count].x_pos,game_o.npc[npc_count].y_pos,z_pos,game_o.npc[npc_count].height,game_o.npc[npc_count].width, 90.0f,temp_r,temp_g,temp_b,temp_a);
            if (game_o.enemy[game_o.npc[npc_count].type_npc].image == texture.ship_025.ref_number) texture.ship_025.draw(true,game_o.npc[npc_count].x_pos,game_o.npc[npc_count].y_pos,z_pos,game_o.npc[npc_count].height,game_o.npc[npc_count].width, 90.0f,temp_r,temp_g,temp_b,temp_a);
        }
    }
    for (int count =0;count < MAX_BULLETS;count++) //player bullets
    {
        if (game_o.player.bullet[count].active)
        {
            z_pos = 0.05f + (0.001*count);
            if (game_o.player.bullet[count].warhead ==  0) texture.projectile_000.draw(true,game_o.player.bullet[count].x_pos,game_o.player.bullet[count].y_pos,z_pos,game_o.player.bullet[count].width,game_o.player.bullet[count].height);
            if (game_o.player.bullet[count].warhead ==  1) texture.projectile_001.draw(true,game_o.player.bullet[count].x_pos,game_o.player.bullet[count].y_pos,z_pos,game_o.player.bullet[count].width,game_o.player.bullet[count].height);
            if (game_o.player.bullet[count].warhead ==  2) texture.projectile_002.draw(true,game_o.player.bullet[count].x_pos,game_o.player.bullet[count].y_pos,z_pos,game_o.player.bullet[count].width,game_o.player.bullet[count].height);
            if (game_o.player.bullet[count].warhead ==  3) texture.projectile_003.draw(true,game_o.player.bullet[count].x_pos,game_o.player.bullet[count].y_pos,z_pos,game_o.player.bullet[count].width,game_o.player.bullet[count].height);
            if (game_o.player.bullet[count].warhead ==  4) texture.projectile_004.draw(true,game_o.player.bullet[count].x_pos,game_o.player.bullet[count].y_pos,z_pos,game_o.player.bullet[count].width,game_o.player.bullet[count].height);
            if (game_o.player.bullet[count].warhead ==  5) texture.projectile_005.draw(true,game_o.player.bullet[count].x_pos,game_o.player.bullet[count].y_pos,z_pos,game_o.player.bullet[count].width,game_o.player.bullet[count].height);
            if (game_o.player.bullet[count].warhead ==  6) texture.projectile_006.draw(true,game_o.player.bullet[count].x_pos,game_o.player.bullet[count].y_pos,z_pos,game_o.player.bullet[count].width,game_o.player.bullet[count].height);
            if (game_o.player.bullet[count].warhead ==  7) texture.projectile_007.draw(true,game_o.player.bullet[count].x_pos,game_o.player.bullet[count].y_pos,z_pos,game_o.player.bullet[count].width,game_o.player.bullet[count].height);
            if (game_o.player.bullet[count].warhead ==  8) texture.projectile_008.draw(true,game_o.player.bullet[count].x_pos,game_o.player.bullet[count].y_pos,z_pos,game_o.player.bullet[count].width,game_o.player.bullet[count].height);
            if (game_o.player.bullet[count].warhead ==  9) texture.projectile_009.draw(true,game_o.player.bullet[count].x_pos,game_o.player.bullet[count].y_pos,z_pos,game_o.player.bullet[count].width,game_o.player.bullet[count].height);
            if (game_o.player.bullet[count].warhead == 10) texture.projectile_010.draw(true,game_o.player.bullet[count].x_pos,game_o.player.bullet[count].y_pos,z_pos,game_o.player.bullet[count].width,game_o.player.bullet[count].height);
            if (game_o.player.bullet[count].warhead == 11) texture.projectile_011.draw(true,game_o.player.bullet[count].x_pos,game_o.player.bullet[count].y_pos,z_pos,game_o.player.bullet[count].width,game_o.player.bullet[count].height);
            if (game_o.player.bullet[count].warhead == 12) texture.projectile_012.draw(true,game_o.player.bullet[count].x_pos,game_o.player.bullet[count].y_pos,z_pos,game_o.player.bullet[count].width,game_o.player.bullet[count].height);
            if (game_o.player.bullet[count].warhead == 13) texture.projectile_013.draw(true,game_o.player.bullet[count].x_pos,game_o.player.bullet[count].y_pos,z_pos,game_o.player.bullet[count].width,game_o.player.bullet[count].height);
            if (game_o.player.bullet[count].warhead == 14) texture.projectile_014.draw(true,game_o.player.bullet[count].x_pos,game_o.player.bullet[count].y_pos,z_pos,game_o.player.bullet[count].width,game_o.player.bullet[count].height);
            if (game_o.player.bullet[count].warhead == 15) texture.projectile_015.draw(true,game_o.player.bullet[count].x_pos,game_o.player.bullet[count].y_pos,z_pos,game_o.player.bullet[count].width,game_o.player.bullet[count].height);
            if (game_o.player.bullet[count].warhead == 16) texture.projectile_016.draw(true,game_o.player.bullet[count].x_pos,game_o.player.bullet[count].y_pos,z_pos,game_o.player.bullet[count].width,game_o.player.bullet[count].height);
            if (game_o.player.bullet[count].warhead == 17) texture.projectile_017.draw(true,game_o.player.bullet[count].x_pos,game_o.player.bullet[count].y_pos,z_pos,game_o.player.bullet[count].width,game_o.player.bullet[count].height);
            if (game_o.player.bullet[count].warhead == 18) texture.projectile_018.draw(true,game_o.player.bullet[count].x_pos,game_o.player.bullet[count].y_pos,z_pos,game_o.player.bullet[count].width,game_o.player.bullet[count].height);
            if (game_o.player.bullet[count].warhead == 19) texture.projectile_019.draw(true,game_o.player.bullet[count].x_pos,game_o.player.bullet[count].y_pos,z_pos,game_o.player.bullet[count].width,game_o.player.bullet[count].height);
            if (game_o.player.bullet[count].warhead == 20) texture.projectile_020.draw(true,game_o.player.bullet[count].x_pos,game_o.player.bullet[count].y_pos,z_pos,game_o.player.bullet[count].width,game_o.player.bullet[count].height);
            if (game_o.player.bullet[count].warhead == 21) texture.projectile_021.draw(true,game_o.player.bullet[count].x_pos,game_o.player.bullet[count].y_pos,z_pos,game_o.player.bullet[count].width,game_o.player.bullet[count].height);
            if (game_o.player.bullet[count].warhead == 22) texture.projectile_022.draw(true,game_o.player.bullet[count].x_pos,game_o.player.bullet[count].y_pos,z_pos,game_o.player.bullet[count].width,game_o.player.bullet[count].height);
            if (game_o.player.bullet[count].warhead == 23) texture.projectile_023.draw(true,game_o.player.bullet[count].x_pos,game_o.player.bullet[count].y_pos,z_pos,game_o.player.bullet[count].width,game_o.player.bullet[count].height);
            if (game_o.player.bullet[count].warhead == 24) texture.projectile_024.draw(true,game_o.player.bullet[count].x_pos,game_o.player.bullet[count].y_pos,z_pos,game_o.player.bullet[count].width,game_o.player.bullet[count].height);
            if (game_o.player.bullet[count].warhead == 25) texture.projectile_025.draw(true,game_o.player.bullet[count].x_pos,game_o.player.bullet[count].y_pos,z_pos,game_o.player.bullet[count].width,game_o.player.bullet[count].height);
            if (game_o.player.bullet[count].warhead == 26) texture.projectile_026.draw(true,game_o.player.bullet[count].x_pos,game_o.player.bullet[count].y_pos,z_pos,game_o.player.bullet[count].width,game_o.player.bullet[count].height);
            if (game_o.player.bullet[count].warhead == 27) texture.projectile_027.draw(true,game_o.player.bullet[count].x_pos,game_o.player.bullet[count].y_pos,z_pos,game_o.player.bullet[count].width,game_o.player.bullet[count].height);
            if (game_o.player.bullet[count].warhead == 28) texture.projectile_028.draw(true,game_o.player.bullet[count].x_pos,game_o.player.bullet[count].y_pos,z_pos,game_o.player.bullet[count].width,game_o.player.bullet[count].height);
            if (game_o.player.bullet[count].warhead == 29) texture.projectile_029.draw(true,game_o.player.bullet[count].x_pos,game_o.player.bullet[count].y_pos,z_pos,game_o.player.bullet[count].width,game_o.player.bullet[count].height);
            if (game_o.player.bullet[count].warhead == 30) texture.projectile_030.draw(true,game_o.player.bullet[count].x_pos,game_o.player.bullet[count].y_pos,z_pos,game_o.player.bullet[count].width,game_o.player.bullet[count].height);
            if (game_o.player.bullet[count].warhead == 31) texture.projectile_031.draw(true,game_o.player.bullet[count].x_pos,game_o.player.bullet[count].y_pos,z_pos,game_o.player.bullet[count].width,game_o.player.bullet[count].height);
        }
    }
    for (int supportship_count = 0;supportship_count < MAX_SUPPORTSHIPS;supportship_count++)//display support ship bullets
    {
        for (int bullet_count = 0;bullet_count < MAX_BULLETS;bullet_count++)
        {
            if (game_o.supportship[supportship_count].bullet[bullet_count].active)
            {
                z_pos = 0.05f + (0.001*bullet_count);
                if (game_o.projectile[game_o.supportship[supportship_count].bullet[bullet_count].warhead].image == texture.projectile_000.ref_number) texture.projectile_000.draw(true,game_o.supportship[supportship_count].bullet[bullet_count].x_pos,game_o.supportship[supportship_count].bullet[bullet_count].y_pos,z_pos,game_o.supportship[supportship_count].bullet[bullet_count].width,game_o.supportship[supportship_count].bullet[bullet_count].height);
                if (game_o.projectile[game_o.supportship[supportship_count].bullet[bullet_count].warhead].image == texture.projectile_001.ref_number) texture.projectile_001.draw(true,game_o.supportship[supportship_count].bullet[bullet_count].x_pos,game_o.supportship[supportship_count].bullet[bullet_count].y_pos,z_pos,game_o.supportship[supportship_count].bullet[bullet_count].width,game_o.supportship[supportship_count].bullet[bullet_count].height);
                if (game_o.projectile[game_o.supportship[supportship_count].bullet[bullet_count].warhead].image == texture.projectile_002.ref_number) texture.projectile_002.draw(true,game_o.supportship[supportship_count].bullet[bullet_count].x_pos,game_o.supportship[supportship_count].bullet[bullet_count].y_pos,z_pos,game_o.supportship[supportship_count].bullet[bullet_count].width,game_o.supportship[supportship_count].bullet[bullet_count].height);
                if (game_o.projectile[game_o.supportship[supportship_count].bullet[bullet_count].warhead].image == texture.projectile_003.ref_number) texture.projectile_003.draw(true,game_o.supportship[supportship_count].bullet[bullet_count].x_pos,game_o.supportship[supportship_count].bullet[bullet_count].y_pos,z_pos,game_o.supportship[supportship_count].bullet[bullet_count].width,game_o.supportship[supportship_count].bullet[bullet_count].height);
                if (game_o.projectile[game_o.supportship[supportship_count].bullet[bullet_count].warhead].image == texture.projectile_004.ref_number) texture.projectile_004.draw(true,game_o.supportship[supportship_count].bullet[bullet_count].x_pos,game_o.supportship[supportship_count].bullet[bullet_count].y_pos,z_pos,game_o.supportship[supportship_count].bullet[bullet_count].width,game_o.supportship[supportship_count].bullet[bullet_count].height);
                if (game_o.projectile[game_o.supportship[supportship_count].bullet[bullet_count].warhead].image == texture.projectile_005.ref_number) texture.projectile_005.draw(true,game_o.supportship[supportship_count].bullet[bullet_count].x_pos,game_o.supportship[supportship_count].bullet[bullet_count].y_pos,z_pos,game_o.supportship[supportship_count].bullet[bullet_count].width,game_o.supportship[supportship_count].bullet[bullet_count].height);
                if (game_o.projectile[game_o.supportship[supportship_count].bullet[bullet_count].warhead].image == texture.projectile_006.ref_number) texture.projectile_006.draw(true,game_o.supportship[supportship_count].bullet[bullet_count].x_pos,game_o.supportship[supportship_count].bullet[bullet_count].y_pos,z_pos,game_o.supportship[supportship_count].bullet[bullet_count].width,game_o.supportship[supportship_count].bullet[bullet_count].height);
                if (game_o.projectile[game_o.supportship[supportship_count].bullet[bullet_count].warhead].image == texture.projectile_007.ref_number) texture.projectile_007.draw(true,game_o.supportship[supportship_count].bullet[bullet_count].x_pos,game_o.supportship[supportship_count].bullet[bullet_count].y_pos,z_pos,game_o.supportship[supportship_count].bullet[bullet_count].width,game_o.supportship[supportship_count].bullet[bullet_count].height);
                if (game_o.projectile[game_o.supportship[supportship_count].bullet[bullet_count].warhead].image == texture.projectile_008.ref_number) texture.projectile_008.draw(true,game_o.supportship[supportship_count].bullet[bullet_count].x_pos,game_o.supportship[supportship_count].bullet[bullet_count].y_pos,z_pos,game_o.supportship[supportship_count].bullet[bullet_count].width,game_o.supportship[supportship_count].bullet[bullet_count].height);
                if (game_o.projectile[game_o.supportship[supportship_count].bullet[bullet_count].warhead].image == texture.projectile_009.ref_number) texture.projectile_009.draw(true,game_o.supportship[supportship_count].bullet[bullet_count].x_pos,game_o.supportship[supportship_count].bullet[bullet_count].y_pos,z_pos,game_o.supportship[supportship_count].bullet[bullet_count].width,game_o.supportship[supportship_count].bullet[bullet_count].height);
                if (game_o.projectile[game_o.supportship[supportship_count].bullet[bullet_count].warhead].image == texture.projectile_010.ref_number) texture.projectile_010.draw(true,game_o.supportship[supportship_count].bullet[bullet_count].x_pos,game_o.supportship[supportship_count].bullet[bullet_count].y_pos,z_pos,game_o.supportship[supportship_count].bullet[bullet_count].width,game_o.supportship[supportship_count].bullet[bullet_count].height);
                if (game_o.projectile[game_o.supportship[supportship_count].bullet[bullet_count].warhead].image == texture.projectile_011.ref_number) texture.projectile_011.draw(true,game_o.supportship[supportship_count].bullet[bullet_count].x_pos,game_o.supportship[supportship_count].bullet[bullet_count].y_pos,z_pos,game_o.supportship[supportship_count].bullet[bullet_count].width,game_o.supportship[supportship_count].bullet[bullet_count].height);
                if (game_o.projectile[game_o.supportship[supportship_count].bullet[bullet_count].warhead].image == texture.projectile_012.ref_number) texture.projectile_012.draw(true,game_o.supportship[supportship_count].bullet[bullet_count].x_pos,game_o.supportship[supportship_count].bullet[bullet_count].y_pos,z_pos,game_o.supportship[supportship_count].bullet[bullet_count].width,game_o.supportship[supportship_count].bullet[bullet_count].height);
                if (game_o.projectile[game_o.supportship[supportship_count].bullet[bullet_count].warhead].image == texture.projectile_013.ref_number) texture.projectile_013.draw(true,game_o.supportship[supportship_count].bullet[bullet_count].x_pos,game_o.supportship[supportship_count].bullet[bullet_count].y_pos,z_pos,game_o.supportship[supportship_count].bullet[bullet_count].width,game_o.supportship[supportship_count].bullet[bullet_count].height);
                if (game_o.projectile[game_o.supportship[supportship_count].bullet[bullet_count].warhead].image == texture.projectile_014.ref_number) texture.projectile_014.draw(true,game_o.supportship[supportship_count].bullet[bullet_count].x_pos,game_o.supportship[supportship_count].bullet[bullet_count].y_pos,z_pos,game_o.supportship[supportship_count].bullet[bullet_count].width,game_o.supportship[supportship_count].bullet[bullet_count].height);
                if (game_o.projectile[game_o.supportship[supportship_count].bullet[bullet_count].warhead].image == texture.projectile_015.ref_number) texture.projectile_015.draw(true,game_o.supportship[supportship_count].bullet[bullet_count].x_pos,game_o.supportship[supportship_count].bullet[bullet_count].y_pos,z_pos,game_o.supportship[supportship_count].bullet[bullet_count].width,game_o.supportship[supportship_count].bullet[bullet_count].height);
                if (game_o.projectile[game_o.supportship[supportship_count].bullet[bullet_count].warhead].image == texture.projectile_016.ref_number) texture.projectile_016.draw(true,game_o.supportship[supportship_count].bullet[bullet_count].x_pos,game_o.supportship[supportship_count].bullet[bullet_count].y_pos,z_pos,game_o.supportship[supportship_count].bullet[bullet_count].width,game_o.supportship[supportship_count].bullet[bullet_count].height);
                if (game_o.projectile[game_o.supportship[supportship_count].bullet[bullet_count].warhead].image == texture.projectile_017.ref_number) texture.projectile_017.draw(true,game_o.supportship[supportship_count].bullet[bullet_count].x_pos,game_o.supportship[supportship_count].bullet[bullet_count].y_pos,z_pos,game_o.supportship[supportship_count].bullet[bullet_count].width,game_o.supportship[supportship_count].bullet[bullet_count].height);
                if (game_o.projectile[game_o.supportship[supportship_count].bullet[bullet_count].warhead].image == texture.projectile_018.ref_number) texture.projectile_018.draw(true,game_o.supportship[supportship_count].bullet[bullet_count].x_pos,game_o.supportship[supportship_count].bullet[bullet_count].y_pos,z_pos,game_o.supportship[supportship_count].bullet[bullet_count].width,game_o.supportship[supportship_count].bullet[bullet_count].height);
                if (game_o.projectile[game_o.supportship[supportship_count].bullet[bullet_count].warhead].image == texture.projectile_019.ref_number) texture.projectile_019.draw(true,game_o.supportship[supportship_count].bullet[bullet_count].x_pos,game_o.supportship[supportship_count].bullet[bullet_count].y_pos,z_pos,game_o.supportship[supportship_count].bullet[bullet_count].width,game_o.supportship[supportship_count].bullet[bullet_count].height);
                if (game_o.projectile[game_o.supportship[supportship_count].bullet[bullet_count].warhead].image == texture.projectile_020.ref_number) texture.projectile_020.draw(true,game_o.supportship[supportship_count].bullet[bullet_count].x_pos,game_o.supportship[supportship_count].bullet[bullet_count].y_pos,z_pos,game_o.supportship[supportship_count].bullet[bullet_count].width,game_o.supportship[supportship_count].bullet[bullet_count].height);
                if (game_o.projectile[game_o.supportship[supportship_count].bullet[bullet_count].warhead].image == texture.projectile_021.ref_number) texture.projectile_021.draw(true,game_o.supportship[supportship_count].bullet[bullet_count].x_pos,game_o.supportship[supportship_count].bullet[bullet_count].y_pos,z_pos,game_o.supportship[supportship_count].bullet[bullet_count].width,game_o.supportship[supportship_count].bullet[bullet_count].height);
                if (game_o.projectile[game_o.supportship[supportship_count].bullet[bullet_count].warhead].image == texture.projectile_022.ref_number) texture.projectile_022.draw(true,game_o.supportship[supportship_count].bullet[bullet_count].x_pos,game_o.supportship[supportship_count].bullet[bullet_count].y_pos,z_pos,game_o.supportship[supportship_count].bullet[bullet_count].width,game_o.supportship[supportship_count].bullet[bullet_count].height);
                if (game_o.projectile[game_o.supportship[supportship_count].bullet[bullet_count].warhead].image == texture.projectile_023.ref_number) texture.projectile_023.draw(true,game_o.supportship[supportship_count].bullet[bullet_count].x_pos,game_o.supportship[supportship_count].bullet[bullet_count].y_pos,z_pos,game_o.supportship[supportship_count].bullet[bullet_count].width,game_o.supportship[supportship_count].bullet[bullet_count].height);
                if (game_o.projectile[game_o.supportship[supportship_count].bullet[bullet_count].warhead].image == texture.projectile_024.ref_number) texture.projectile_024.draw(true,game_o.supportship[supportship_count].bullet[bullet_count].x_pos,game_o.supportship[supportship_count].bullet[bullet_count].y_pos,z_pos,game_o.supportship[supportship_count].bullet[bullet_count].width,game_o.supportship[supportship_count].bullet[bullet_count].height);
                if (game_o.projectile[game_o.supportship[supportship_count].bullet[bullet_count].warhead].image == texture.projectile_025.ref_number) texture.projectile_025.draw(true,game_o.supportship[supportship_count].bullet[bullet_count].x_pos,game_o.supportship[supportship_count].bullet[bullet_count].y_pos,z_pos,game_o.supportship[supportship_count].bullet[bullet_count].width,game_o.supportship[supportship_count].bullet[bullet_count].height);
                if (game_o.projectile[game_o.supportship[supportship_count].bullet[bullet_count].warhead].image == texture.projectile_026.ref_number) texture.projectile_026.draw(true,game_o.supportship[supportship_count].bullet[bullet_count].x_pos,game_o.supportship[supportship_count].bullet[bullet_count].y_pos,z_pos,game_o.supportship[supportship_count].bullet[bullet_count].width,game_o.supportship[supportship_count].bullet[bullet_count].height);
                if (game_o.projectile[game_o.supportship[supportship_count].bullet[bullet_count].warhead].image == texture.projectile_027.ref_number) texture.projectile_027.draw(true,game_o.supportship[supportship_count].bullet[bullet_count].x_pos,game_o.supportship[supportship_count].bullet[bullet_count].y_pos,z_pos,game_o.supportship[supportship_count].bullet[bullet_count].width,game_o.supportship[supportship_count].bullet[bullet_count].height);
                if (game_o.projectile[game_o.supportship[supportship_count].bullet[bullet_count].warhead].image == texture.projectile_028.ref_number) texture.projectile_028.draw(true,game_o.supportship[supportship_count].bullet[bullet_count].x_pos,game_o.supportship[supportship_count].bullet[bullet_count].y_pos,z_pos,game_o.supportship[supportship_count].bullet[bullet_count].width,game_o.supportship[supportship_count].bullet[bullet_count].height);
                if (game_o.projectile[game_o.supportship[supportship_count].bullet[bullet_count].warhead].image == texture.projectile_029.ref_number) texture.projectile_029.draw(true,game_o.supportship[supportship_count].bullet[bullet_count].x_pos,game_o.supportship[supportship_count].bullet[bullet_count].y_pos,z_pos,game_o.supportship[supportship_count].bullet[bullet_count].width,game_o.supportship[supportship_count].bullet[bullet_count].height);
                if (game_o.projectile[game_o.supportship[supportship_count].bullet[bullet_count].warhead].image == texture.projectile_030.ref_number) texture.projectile_030.draw(true,game_o.supportship[supportship_count].bullet[bullet_count].x_pos,game_o.supportship[supportship_count].bullet[bullet_count].y_pos,z_pos,game_o.supportship[supportship_count].bullet[bullet_count].width,game_o.supportship[supportship_count].bullet[bullet_count].height);
                if (game_o.projectile[game_o.supportship[supportship_count].bullet[bullet_count].warhead].image == texture.projectile_031.ref_number) texture.projectile_031.draw(true,game_o.supportship[supportship_count].bullet[bullet_count].x_pos,game_o.supportship[supportship_count].bullet[bullet_count].y_pos,z_pos,game_o.supportship[supportship_count].bullet[bullet_count].width,game_o.supportship[supportship_count].bullet[bullet_count].height);
            }
        }
    }
    for (int count =MAX_EXPLOSIONS;count >=0;count--)  // explosions
    {
        z_pos = 0.001f + (0.0001*count);
        if (game_o.explosion[count].active)
        {
            if (game_o.explosion[count].image == texture.explosion_00.ref_number) texture.explosion_00.draw(true,game_o.explosion[count].x_pos,game_o.explosion[count].y_pos,z_pos,game_o.explosion[count].width,game_o.explosion[count].height,0.0f,game_o.explosion[count].frame);
            if (game_o.explosion[count].image == texture.explosion_01.ref_number) texture.explosion_01.draw(true,game_o.explosion[count].x_pos,game_o.explosion[count].y_pos,z_pos,game_o.explosion[count].width,game_o.explosion[count].height,0.0f,game_o.explosion[count].frame);
            if (game_o.explosion[count].image == texture.explosion_02.ref_number) texture.explosion_02.draw(true,game_o.explosion[count].x_pos,game_o.explosion[count].y_pos,z_pos,game_o.explosion[count].width,game_o.explosion[count].height,0.0f,game_o.explosion[count].frame);
        }
    }
    draw_supportships(); // support ships
    //----------------------------------------------------------------------------------------
    float temp_r = 1.0f;
    float temp_g = 1.0f;
    float temp_b = 1.0f;
    float temp_a = 1.0f;
    if ((game_o.immune) && (game_o.immunity_state == 0))
    {
        temp_r = 1.0f;
        temp_g = 0.0f;
        temp_b = 0.0f;
        temp_a = 0.6f;
    }
    if (game_o.player.thrusters > -1)//player starship
    {//player thrusters
        if (game_o.thruster[game_o.player.thrusters].image == texture.thrusters_000.ref_number) texture.thrusters_000.draw(true,game_o.player.x_pos-0.190f,game_o.player.y_pos, 0.035f,game_o.player.width,game_o.player.height,90.0f,temp_r,temp_g,temp_b,temp_a,game_o.thruster[game_o.player.thrusters].frame);

        if (game_o.thruster[game_o.player.thrusters].image == texture.thruster_000.ref_number) texture.thruster_000.draw(true,game_o.player.x_pos-0.190f,game_o.player.y_pos, 0.035f,game_o.player.width,game_o.player.height,270.0f,temp_r,temp_g,temp_b,temp_a);
        if (game_o.thruster[game_o.player.thrusters].image == texture.thruster_001.ref_number) texture.thruster_000.draw(true,game_o.player.x_pos-0.190f,game_o.player.y_pos, 0.035f,game_o.player.width,game_o.player.height,270.0f,temp_r,temp_g,temp_b,temp_a);
        if (game_o.thruster[game_o.player.thrusters].image == texture.thruster_002.ref_number) texture.thruster_000.draw(true,game_o.player.x_pos-0.190f,game_o.player.y_pos, 0.035f,game_o.player.width,game_o.player.height,270.0f,temp_r,temp_g,temp_b,temp_a);
        if (game_o.thruster[game_o.player.thrusters].image == texture.thruster_003.ref_number) texture.thruster_000.draw(true,game_o.player.x_pos-0.190f,game_o.player.y_pos, 0.035f,game_o.player.width,game_o.player.height,270.0f,temp_r,temp_g,temp_b,temp_a);
    }
    //player starship
    if (game_o.player.image == texture.ship_025.ref_number) texture.ship_025.draw(true,game_o.player.x_pos,game_o.player.y_pos, 0.030f,game_o.player.width,game_o.player.height,270.0f,temp_r,temp_g,temp_b,temp_a);

    if (game_o.player.front_weapon > -1)//player starship front weapon
    {
        if (game_o.player.front_weapon == 0)
        {
            texture.weapon_000.draw(true,game_o.player.x_pos+0.076f,game_o.player.y_pos, 0.025f,game_o.player.width/6,game_o.player.height/6,270.0f,temp_r,temp_g,temp_b,temp_a);
        }
        if (game_o.player.front_weapon == 1)
        {
            texture.weapon_001.draw(true,game_o.player.x_pos+0.076f,game_o.player.y_pos, 0.025f,game_o.player.width/6,game_o.player.height/6,270.0f,temp_r,temp_g,temp_b,temp_a);
        }
        if (game_o.player.front_weapon == 2)
        {
            texture.weapon_002.draw(true,game_o.player.x_pos+0.076f,game_o.player.y_pos, 0.025f,game_o.player.width/6,game_o.player.height/6,270.0f,temp_r,temp_g,temp_b,temp_a);
        }
        if (game_o.player.front_weapon == 3)
        {
            texture.weapon_003.draw(true,game_o.player.x_pos+0.076f,game_o.player.y_pos, 0.025f,game_o.player.width/6,game_o.player.height/6,270.0f,temp_r,temp_g,temp_b,temp_a);
        }
        if (game_o.player.front_weapon == 4)
        {
            texture.weapon_004.draw(true,game_o.player.x_pos+0.076f,game_o.player.y_pos, 0.025f,game_o.player.width/6,game_o.player.height/6,270.0f,temp_r,temp_g,temp_b,temp_a);
        }
        if (game_o.player.front_weapon == 5)
        {
            texture.weapon_005.draw(true,game_o.player.x_pos+0.076f,game_o.player.y_pos, 0.025f,game_o.player.width/6,game_o.player.height/6,270.0f,temp_r,temp_g,temp_b,temp_a);
        }
    }
    if (game_o.player.side_weapon > -1)//player starship side weapon
    {
        if (game_o.player.side_weapon == 0)
        {
            texture.weapon_000.draw(true,game_o.player.x_pos+0.067f,game_o.player.y_pos+0.075f, 0.025f,game_o.player.width/3,game_o.player.height/3,270.0f,temp_r,temp_g,temp_b,temp_a);
            texture.weapon_000.draw(true,game_o.player.x_pos+0.067f,game_o.player.y_pos-0.075f, 0.025f,game_o.player.width/3,game_o.player.height/3,270.0f,temp_r,temp_g,temp_b,temp_a);
        }
        if (game_o.player.side_weapon == 1)
        {
            texture.weapon_001.draw(true,game_o.player.x_pos+0.067f,game_o.player.y_pos+0.075f, 0.025f,game_o.player.width/3,game_o.player.height/3,270.0f,temp_r,temp_g,temp_b,temp_a);
            texture.weapon_001.draw(true,game_o.player.x_pos+0.067f,game_o.player.y_pos-0.075f, 0.025f,game_o.player.width/3,game_o.player.height/3,270.0f,temp_r,temp_g,temp_b,temp_a);
        }
        if (game_o.player.side_weapon == 2)
        {
            texture.weapon_002.draw(true,game_o.player.x_pos+0.067f,game_o.player.y_pos+0.075f, 0.025f,game_o.player.width/3,game_o.player.height/3,270.0f,temp_r,temp_g,temp_b,temp_a);
            texture.weapon_002.draw(true,game_o.player.x_pos+0.067f,game_o.player.y_pos-0.075f, 0.025f,game_o.player.width/3,game_o.player.height/3,270.0f,temp_r,temp_g,temp_b,temp_a);
        }
        if (game_o.player.side_weapon == 3)
        {
            texture.weapon_003.draw(true,game_o.player.x_pos+0.067f,game_o.player.y_pos+0.075f, 0.025f,game_o.player.width/3,game_o.player.height/3,270.0f,temp_r,temp_g,temp_b,temp_a);
            texture.weapon_003.draw(true,game_o.player.x_pos+0.067f,game_o.player.y_pos-0.075f, 0.025f,game_o.player.width/3,game_o.player.height/3,270.0f,temp_r,temp_g,temp_b,temp_a);
        }
        if (game_o.player.side_weapon == 4)
        {
            texture.weapon_004.draw(true,game_o.player.x_pos+0.067f,game_o.player.y_pos+0.075f, 0.025f,game_o.player.width/3,game_o.player.height/3,270.0f,temp_r,temp_g,temp_b,temp_a);
            texture.weapon_004.draw(true,game_o.player.x_pos+0.067f,game_o.player.y_pos-0.075f, 0.025f,game_o.player.width/3,game_o.player.height/3,270.0f,temp_r,temp_g,temp_b,temp_a);
        }
        if (game_o.player.side_weapon == 5)
        {
            texture.weapon_005.draw(true,game_o.player.x_pos+0.067f,game_o.player.y_pos+0.075f, 0.025f,game_o.player.width/3,game_o.player.height/3,270.0f,temp_r,temp_g,temp_b,temp_a);
            texture.weapon_005.draw(true,game_o.player.x_pos+0.067f,game_o.player.y_pos-0.075f, 0.025f,game_o.player.width/3,game_o.player.height/3,270.0f,temp_r,temp_g,temp_b,temp_a);
        }
    }
    if (game_o.player.front_shield > -1) // player starship shield
    {
        if (game_o.shield[game_o.player.front_shield].image == texture.shield_000.ref_number) texture.shield_000.draw(true,game_o.player.x_pos,game_o.player.y_pos, 0.02f,(game_o.player.width/1.5)*2,(game_o.player.height/1.5)*2,0.0f,temp_r,temp_g,temp_b,temp_a);
        if (game_o.shield[game_o.player.front_shield].image == texture.shield_001.ref_number) texture.shield_001.draw(true,game_o.player.x_pos,game_o.player.y_pos, 0.02f,(game_o.player.width/1.5)*2,(game_o.player.height/1.5)*2,0.0f,temp_r,temp_g,temp_b,temp_a);
        if (game_o.shield[game_o.player.front_shield].image == texture.shield_002.ref_number) texture.shield_002.draw(true,game_o.player.x_pos,game_o.player.y_pos, 0.02f,(game_o.player.width/1.5)*2,(game_o.player.height/1.5)*2,0.0f,temp_r,temp_g,temp_b,temp_a);
        if (game_o.shield[game_o.player.front_shield].image == texture.shield_003.ref_number) texture.shield_003.draw(true,game_o.player.x_pos,game_o.player.y_pos, 0.02f,(game_o.player.width/1.5)*2,(game_o.player.height/1.5)*2,0.0f,temp_r,temp_g,temp_b,temp_a);
        if (game_o.shield[game_o.player.front_shield].image == texture.shield_004.ref_number) texture.shield_004.draw(true,game_o.player.x_pos,game_o.player.y_pos, 0.02f,(game_o.player.width/1.5)*2,(game_o.player.height/1.5)*2,0.0f,temp_r,temp_g,temp_b,temp_a);
    }
    //------------------------------------------------

    float  npc_num   = 0.0f;
    float  temp_size = 0.0f;
    for  (int npc_count = 0; npc_count < MAX_NPCS; npc_count++)
    {
        if (game_o.active_npc[npc_count].active)
        {
            npc_num += 0.05f;
            if (boss_level())
            {
                temp_size = ((game_o.npc[npc_count].health/game_o.enemy[game_o.npc[npc_count].type_npc].health)*100)/52.5f;
                texture.health_bar.draw(false,-0.95f + (temp_size/2),0.85f-npc_num, 0.001f,temp_size, 0.10); // NPC BOSS health bars
            }
            else
            {
                texture.health_bar.draw(false,0.89f +((game_o.npc[npc_count].health/game_o.enemy[game_o.npc[npc_count].type_npc].health)/20),1.0f-npc_num, 0.001f,((game_o.npc[npc_count].health/game_o.enemy[game_o.npc[npc_count].type_npc].health)/10), 0.050); // NPC health bars
            }
        }
    }

    for (int count = MAX_POWERUPS;count >=1;count--)  // powerups
    {
        z_pos = 0.002f + (0.0002*count);
        if (game_o.powerup[count].active)
        {
            if (game_o.powerup[count].image == texture.health_powerup.ref_number        ) texture.health_powerup.draw        (true,game_o.powerup[count].x_pos,game_o.powerup[count].y_pos,z_pos,game_o.powerup[count].width,game_o.powerup[count].height); // health power up
            if (game_o.powerup[count].image == texture.shield_lvlup_powerup.ref_number  ) texture.shield_lvlup_powerup.draw  (true,game_o.powerup[count].x_pos,game_o.powerup[count].y_pos,z_pos,game_o.powerup[count].width,game_o.powerup[count].height); // shield level up
            if (game_o.powerup[count].image == texture.shield_new_powerup.ref_number    ) texture.shield_new_powerup.draw    (true,game_o.powerup[count].x_pos,game_o.powerup[count].y_pos,z_pos,game_o.powerup[count].width,game_o.powerup[count].height); // shield new
            if (game_o.powerup[count].image == texture.thruster_lvlup_powerup.ref_number) texture.thruster_lvlup_powerup.draw(true,game_o.powerup[count].x_pos,game_o.powerup[count].y_pos,z_pos,game_o.powerup[count].width,game_o.powerup[count].height); // thruster level up
            if (game_o.powerup[count].image == texture.thruster_new_powerup.ref_number  ) texture.thruster_new_powerup.draw  (true,game_o.powerup[count].x_pos,game_o.powerup[count].y_pos,z_pos,game_o.powerup[count].width,game_o.powerup[count].height); // thruster new
            if (game_o.powerup[count].image == texture.weapon_lvlup_powerup.ref_number  ) texture.weapon_lvlup_powerup.draw  (true,game_o.powerup[count].x_pos,game_o.powerup[count].y_pos,z_pos,game_o.powerup[count].width,game_o.powerup[count].height); // weapon level up
            if (game_o.powerup[count].image == texture.weapon_new_powerup.ref_number    ) texture.weapon_new_powerup.draw    (true,game_o.powerup[count].x_pos,game_o.powerup[count].y_pos,z_pos,game_o.powerup[count].width,game_o.powerup[count].height); // weapon new
            if (game_o.powerup[count].image == texture.bomb_powerup.ref_number          ) texture.bomb_powerup.draw          (true,game_o.powerup[count].x_pos,game_o.powerup[count].y_pos,z_pos,game_o.powerup[count].width,game_o.powerup[count].height); // bomb
            if (game_o.powerup[count].image == texture.powerup_sideship_00.ref_number   ) texture.powerup_sideship_00.draw   (true,game_o.powerup[count].x_pos,game_o.powerup[count].y_pos,z_pos,game_o.powerup[count].width,game_o.powerup[count].height); // side helper ship 0
            if (game_o.powerup[count].image == texture.powerup_sideship_01.ref_number   ) texture.powerup_sideship_01.draw   (true,game_o.powerup[count].x_pos,game_o.powerup[count].y_pos,z_pos,game_o.powerup[count].width,game_o.powerup[count].height); // side helper ship 1
            if (game_o.powerup[count].image == texture.powerup_sideship_02.ref_number   ) texture.powerup_sideship_02.draw   (true,game_o.powerup[count].x_pos,game_o.powerup[count].y_pos,z_pos,game_o.powerup[count].width,game_o.powerup[count].height); // side helper ship 2
            if (game_o.powerup[count].image == texture.powerup_sideship_03.ref_number   ) texture.powerup_sideship_03.draw   (true,game_o.powerup[count].x_pos,game_o.powerup[count].y_pos,z_pos,game_o.powerup[count].width,game_o.powerup[count].height); // side helper ship 3
        }
    }

    for (int count = MAX_COINS;count >=1;count--)  // coin
    {
        z_pos = 0.002f + (0.0002*(count+MAX_POWERUPS));
        if (game_o.coin[count].active) texture.coin_powerup.draw(true,game_o.coin[count].x_pos,game_o.coin[count].y_pos,z_pos,game_o.coin[count].width,game_o.coin[count].height);
    }

   for (int count = MAX_WEXPS;count >=1;count--)  // wexp
   {
      z_pos = 0.002f + (0.0002*(count+MAX_POWERUPS+MAX_COINS));
      if (game_o.wexp[count].active) texture.wexp_powerup.draw(true,game_o.wexp[count].x_pos,game_o.wexp[count].y_pos,z_pos,game_o.wexp[count].width,game_o.wexp[count].height);
   }
    texture.health_bar.draw (false,-0.6f +((game_o.player.health/game_o.player.max_health)/10), 0.9375f, 0.001f,((game_o.player.health/game_o.player.max_health)/5), 0.075f); //player health bar

    if (game_o.number_bombs > 0) texture.bomb_powerup.draw(false,-0.960f, 0.9375f, 0.001f, 0.075f, 0.075f); // bomb icons
    if (game_o.number_bombs > 1) texture.bomb_powerup.draw(false,-0.885f, 0.9375f, 0.001f, 0.075f, 0.075f); // bomb icons
    if (game_o.number_bombs > 2) texture.bomb_powerup.draw(false,-0.810f, 0.9375f, 0.001f, 0.075f, 0.075f); // bomb icons
    if (game_o.number_bombs > 3) texture.bomb_powerup.draw(false,-0.735f, 0.9375f, 0.001f, 0.075f, 0.075f); // bomb icons
    if (game_o.number_bombs > 4) texture.bomb_powerup.draw(false,-0.660f, 0.9375f, 0.001f, 0.075f, 0.075f); // bomb icons
    if (game_o.number_bombs > 5) texture.bomb_powerup.draw(false,-0.585f, 0.9375f, 0.001f, 0.075f, 0.075f); // bomb icons

    if (game_o.player.front_weapon > -1)
    {
        if(game_o.projectile[game_o.player.front_weapon].image == texture.projectile_000.ref_number) texture.projectile_000.draw(false,-0.3475f, 0.9375f, 0.001f, 0.075f, 0.075f); // front weapon picture next to the exp bar
        if(game_o.projectile[game_o.player.front_weapon].image == texture.projectile_001.ref_number) texture.projectile_001.draw(false,-0.3475f, 0.9375f, 0.001f, 0.075f, 0.075f); // front weapon picture next to the exp bar
        if(game_o.projectile[game_o.player.front_weapon].image == texture.projectile_002.ref_number) texture.projectile_002.draw(false,-0.3475f, 0.9375f, 0.001f, 0.075f, 0.075f); // front weapon picture next to the exp bar
        if(game_o.projectile[game_o.player.front_weapon].image == texture.projectile_003.ref_number) texture.projectile_003.draw(false,-0.3475f, 0.9375f, 0.001f, 0.075f, 0.075f); // front weapon picture next to the exp bar
        if(game_o.projectile[game_o.player.front_weapon].image == texture.projectile_004.ref_number) texture.projectile_004.draw(false,-0.3475f, 0.9375f, 0.001f, 0.075f, 0.075f); // front weapon picture next to the exp bar
        if(game_o.projectile[game_o.player.front_weapon].image == texture.projectile_005.ref_number) texture.projectile_005.draw(false,-0.3475f, 0.9375f, 0.001f, 0.075f, 0.075f); // front weapon picture next to the exp bar
        if(game_o.projectile[game_o.player.front_weapon].image == texture.projectile_006.ref_number) texture.projectile_006.draw(false,-0.3475f, 0.9375f, 0.001f, 0.075f, 0.075f); // front weapon picture next to the exp bar
        if(game_o.projectile[game_o.player.front_weapon].image == texture.projectile_007.ref_number) texture.projectile_007.draw(false,-0.3475f, 0.9375f, 0.001f, 0.075f, 0.075f); // front weapon picture next to the exp bar
        if(game_o.projectile[game_o.player.front_weapon].image == texture.projectile_008.ref_number) texture.projectile_008.draw(false,-0.3475f, 0.9375f, 0.001f, 0.075f, 0.075f); // front weapon picture next to the exp bar
        if(game_o.projectile[game_o.player.front_weapon].image == texture.projectile_009.ref_number) texture.projectile_009.draw(false,-0.3475f, 0.9375f, 0.001f, 0.075f, 0.075f); // front weapon picture next to the exp bar
        if(game_o.projectile[game_o.player.front_weapon].image == texture.projectile_010.ref_number) texture.projectile_010.draw(false,-0.3475f, 0.9375f, 0.001f, 0.075f, 0.075f); // front weapon picture next to the exp bar
        if(game_o.projectile[game_o.player.front_weapon].image == texture.projectile_011.ref_number) texture.projectile_011.draw(false,-0.3475f, 0.9375f, 0.001f, 0.075f, 0.075f); // front weapon picture next to the exp bar
        if(game_o.projectile[game_o.player.front_weapon].image == texture.projectile_012.ref_number) texture.projectile_012.draw(false,-0.3475f, 0.9375f, 0.001f, 0.075f, 0.075f); // front weapon picture next to the exp bar
        if(game_o.projectile[game_o.player.front_weapon].image == texture.projectile_013.ref_number) texture.projectile_013.draw(false,-0.3475f, 0.9375f, 0.001f, 0.075f, 0.075f); // front weapon picture next to the exp bar
        if(game_o.projectile[game_o.player.front_weapon].image == texture.projectile_014.ref_number) texture.projectile_014.draw(false,-0.3475f, 0.9375f, 0.001f, 0.075f, 0.075f); // front weapon picture next to the exp bar
        if(game_o.projectile[game_o.player.front_weapon].image == texture.projectile_015.ref_number) texture.projectile_015.draw(false,-0.3475f, 0.9375f, 0.001f, 0.075f, 0.075f); // front weapon picture next to the exp bar
        if(game_o.projectile[game_o.player.front_weapon].image == texture.projectile_016.ref_number) texture.projectile_016.draw(false,-0.3475f, 0.9375f, 0.001f, 0.075f, 0.075f); // front weapon picture next to the exp bar
        if(game_o.projectile[game_o.player.front_weapon].image == texture.projectile_017.ref_number) texture.projectile_017.draw(false,-0.3475f, 0.9375f, 0.001f, 0.075f, 0.075f); // front weapon picture next to the exp bar
        if(game_o.projectile[game_o.player.front_weapon].image == texture.projectile_018.ref_number) texture.projectile_018.draw(false,-0.3475f, 0.9375f, 0.001f, 0.075f, 0.075f); // front weapon picture next to the exp bar
        if(game_o.projectile[game_o.player.front_weapon].image == texture.projectile_019.ref_number) texture.projectile_019.draw(false,-0.3475f, 0.9375f, 0.001f, 0.075f, 0.075f); // front weapon picture next to the exp bar
        if(game_o.projectile[game_o.player.front_weapon].image == texture.projectile_020.ref_number) texture.projectile_020.draw(false,-0.3475f, 0.9375f, 0.001f, 0.075f, 0.075f); // front weapon picture next to the exp bar
        if(game_o.projectile[game_o.player.front_weapon].image == texture.projectile_021.ref_number) texture.projectile_021.draw(false,-0.3475f, 0.9375f, 0.001f, 0.075f, 0.075f); // front weapon picture next to the exp bar
        if(game_o.projectile[game_o.player.front_weapon].image == texture.projectile_022.ref_number) texture.projectile_022.draw(false,-0.3475f, 0.9375f, 0.001f, 0.075f, 0.075f); // front weapon picture next to the exp bar
        if(game_o.projectile[game_o.player.front_weapon].image == texture.projectile_023.ref_number) texture.projectile_023.draw(false,-0.3475f, 0.9375f, 0.001f, 0.075f, 0.075f); // front weapon picture next to the exp bar
        if(game_o.projectile[game_o.player.front_weapon].image == texture.projectile_024.ref_number) texture.projectile_024.draw(false,-0.3475f, 0.9375f, 0.001f, 0.075f, 0.075f); // front weapon picture next to the exp bar
        if(game_o.projectile[game_o.player.front_weapon].image == texture.projectile_025.ref_number) texture.projectile_025.draw(false,-0.3475f, 0.9375f, 0.001f, 0.075f, 0.075f); // front weapon picture next to the exp bar
        if(game_o.projectile[game_o.player.front_weapon].image == texture.projectile_026.ref_number) texture.projectile_026.draw(false,-0.3475f, 0.9375f, 0.001f, 0.075f, 0.075f); // front weapon picture next to the exp bar
        if(game_o.projectile[game_o.player.front_weapon].image == texture.projectile_027.ref_number) texture.projectile_027.draw(false,-0.3475f, 0.9375f, 0.001f, 0.075f, 0.075f); // front weapon picture next to the exp bar
        if(game_o.projectile[game_o.player.front_weapon].image == texture.projectile_028.ref_number) texture.projectile_028.draw(false,-0.3475f, 0.9375f, 0.001f, 0.075f, 0.075f); // front weapon picture next to the exp bar
        if(game_o.projectile[game_o.player.front_weapon].image == texture.projectile_029.ref_number) texture.projectile_029.draw(false,-0.3475f, 0.9375f, 0.001f, 0.075f, 0.075f); // front weapon picture next to the exp bar
        if(game_o.projectile[game_o.player.front_weapon].image == texture.projectile_030.ref_number) texture.projectile_030.draw(false,-0.3475f, 0.9375f, 0.001f, 0.075f, 0.075f); // front weapon picture next to the exp bar
        if(game_o.projectile[game_o.player.front_weapon].image == texture.projectile_031.ref_number) texture.projectile_031.draw(false,-0.3475f, 0.9375f, 0.001f, 0.075f, 0.075f); // front weapon picture next to the exp bar

        if (game_o.projectile[game_o.player.front_weapon].level == 0) temp_val = ((game_o.projectile[game_o.player.front_weapon].experience / game_o.projectile[game_o.player.front_weapon].level_1)/5);
        if (game_o.projectile[game_o.player.front_weapon].level == 1) temp_val = ((game_o.projectile[game_o.player.front_weapon].experience / game_o.projectile[game_o.player.front_weapon].level_2)/5);
        if (game_o.projectile[game_o.player.front_weapon].level == 2) temp_val = ((game_o.projectile[game_o.player.front_weapon].experience / game_o.projectile[game_o.player.front_weapon].level_3)/5);
        if (game_o.projectile[game_o.player.front_weapon].level == 3) temp_val = 0.2f;
        texture.weapon_bar.draw (false,-0.3f +(temp_val/2), 0.9375f, 0.001f,temp_val, 0.075f);// front weapon exp bar
    }

    if (game_o.player.side_weapon > -1)
    {
        if(game_o.projectile[game_o.player.side_weapon].image == texture.projectile_000.ref_number) texture.projectile_000.draw(false,-0.0475f, 0.9375f, 0.001f, 0.075f, 0.075f); // side weapon picture next to the exp bar
        if(game_o.projectile[game_o.player.side_weapon].image == texture.projectile_001.ref_number) texture.projectile_001.draw(false,-0.0475f, 0.9375f, 0.001f, 0.075f, 0.075f); // side weapon picture next to the exp bar
        if(game_o.projectile[game_o.player.side_weapon].image == texture.projectile_002.ref_number) texture.projectile_002.draw(false,-0.0475f, 0.9375f, 0.001f, 0.075f, 0.075f); // side weapon picture next to the exp bar
        if(game_o.projectile[game_o.player.side_weapon].image == texture.projectile_003.ref_number) texture.projectile_003.draw(false,-0.0475f, 0.9375f, 0.001f, 0.075f, 0.075f); // side weapon picture next to the exp bar
        if(game_o.projectile[game_o.player.side_weapon].image == texture.projectile_004.ref_number) texture.projectile_004.draw(false,-0.0475f, 0.9375f, 0.001f, 0.075f, 0.075f); // side weapon picture next to the exp bar
        if(game_o.projectile[game_o.player.side_weapon].image == texture.projectile_005.ref_number) texture.projectile_005.draw(false,-0.0475f, 0.9375f, 0.001f, 0.075f, 0.075f); // side weapon picture next to the exp bar
        if(game_o.projectile[game_o.player.side_weapon].image == texture.projectile_006.ref_number) texture.projectile_006.draw(false,-0.0475f, 0.9375f, 0.001f, 0.075f, 0.075f); // side weapon picture next to the exp bar
        if(game_o.projectile[game_o.player.side_weapon].image == texture.projectile_007.ref_number) texture.projectile_007.draw(false,-0.0475f, 0.9375f, 0.001f, 0.075f, 0.075f); // side weapon picture next to the exp bar
        if(game_o.projectile[game_o.player.side_weapon].image == texture.projectile_008.ref_number) texture.projectile_008.draw(false,-0.0475f, 0.9375f, 0.001f, 0.075f, 0.075f); // side weapon picture next to the exp bar
        if(game_o.projectile[game_o.player.side_weapon].image == texture.projectile_009.ref_number) texture.projectile_009.draw(false,-0.0475f, 0.9375f, 0.001f, 0.075f, 0.075f); // side weapon picture next to the exp bar
        if(game_o.projectile[game_o.player.side_weapon].image == texture.projectile_010.ref_number) texture.projectile_010.draw(false,-0.0475f, 0.9375f, 0.001f, 0.075f, 0.075f); // side weapon picture next to the exp bar
        if(game_o.projectile[game_o.player.side_weapon].image == texture.projectile_011.ref_number) texture.projectile_011.draw(false,-0.0475f, 0.9375f, 0.001f, 0.075f, 0.075f); // side weapon picture next to the exp bar
        if(game_o.projectile[game_o.player.side_weapon].image == texture.projectile_012.ref_number) texture.projectile_012.draw(false,-0.0475f, 0.9375f, 0.001f, 0.075f, 0.075f); // side weapon picture next to the exp bar
        if(game_o.projectile[game_o.player.side_weapon].image == texture.projectile_013.ref_number) texture.projectile_013.draw(false,-0.0475f, 0.9375f, 0.001f, 0.075f, 0.075f); // side weapon picture next to the exp bar
        if(game_o.projectile[game_o.player.side_weapon].image == texture.projectile_014.ref_number) texture.projectile_014.draw(false,-0.0475f, 0.9375f, 0.001f, 0.075f, 0.075f); // side weapon picture next to the exp bar
        if(game_o.projectile[game_o.player.side_weapon].image == texture.projectile_015.ref_number) texture.projectile_015.draw(false,-0.0475f, 0.9375f, 0.001f, 0.075f, 0.075f); // side weapon picture next to the exp bar
        if(game_o.projectile[game_o.player.side_weapon].image == texture.projectile_016.ref_number) texture.projectile_016.draw(false,-0.0475f, 0.9375f, 0.001f, 0.075f, 0.075f); // side weapon picture next to the exp bar
        if(game_o.projectile[game_o.player.side_weapon].image == texture.projectile_017.ref_number) texture.projectile_017.draw(false,-0.0475f, 0.9375f, 0.001f, 0.075f, 0.075f); // side weapon picture next to the exp bar
        if(game_o.projectile[game_o.player.side_weapon].image == texture.projectile_018.ref_number) texture.projectile_018.draw(false,-0.0475f, 0.9375f, 0.001f, 0.075f, 0.075f); // side weapon picture next to the exp bar
        if(game_o.projectile[game_o.player.side_weapon].image == texture.projectile_019.ref_number) texture.projectile_019.draw(false,-0.0475f, 0.9375f, 0.001f, 0.075f, 0.075f); // side weapon picture next to the exp bar
        if(game_o.projectile[game_o.player.side_weapon].image == texture.projectile_020.ref_number) texture.projectile_020.draw(false,-0.0475f, 0.9375f, 0.001f, 0.075f, 0.075f); // side weapon picture next to the exp bar
        if(game_o.projectile[game_o.player.side_weapon].image == texture.projectile_021.ref_number) texture.projectile_021.draw(false,-0.0475f, 0.9375f, 0.001f, 0.075f, 0.075f); // side weapon picture next to the exp bar
        if(game_o.projectile[game_o.player.side_weapon].image == texture.projectile_022.ref_number) texture.projectile_022.draw(false,-0.0475f, 0.9375f, 0.001f, 0.075f, 0.075f); // side weapon picture next to the exp bar
        if(game_o.projectile[game_o.player.side_weapon].image == texture.projectile_023.ref_number) texture.projectile_023.draw(false,-0.0475f, 0.9375f, 0.001f, 0.075f, 0.075f); // side weapon picture next to the exp bar
        if(game_o.projectile[game_o.player.side_weapon].image == texture.projectile_024.ref_number) texture.projectile_024.draw(false,-0.0475f, 0.9375f, 0.001f, 0.075f, 0.075f); // side weapon picture next to the exp bar
        if(game_o.projectile[game_o.player.side_weapon].image == texture.projectile_025.ref_number) texture.projectile_025.draw(false,-0.0475f, 0.9375f, 0.001f, 0.075f, 0.075f); // side weapon picture next to the exp bar
        if(game_o.projectile[game_o.player.side_weapon].image == texture.projectile_026.ref_number) texture.projectile_026.draw(false,-0.0475f, 0.9375f, 0.001f, 0.075f, 0.075f); // side weapon picture next to the exp bar
        if(game_o.projectile[game_o.player.side_weapon].image == texture.projectile_027.ref_number) texture.projectile_027.draw(false,-0.0475f, 0.9375f, 0.001f, 0.075f, 0.075f); // side weapon picture next to the exp bar
        if(game_o.projectile[game_o.player.side_weapon].image == texture.projectile_028.ref_number) texture.projectile_028.draw(false,-0.0475f, 0.9375f, 0.001f, 0.075f, 0.075f); // side weapon picture next to the exp bar
        if(game_o.projectile[game_o.player.side_weapon].image == texture.projectile_029.ref_number) texture.projectile_029.draw(false,-0.0475f, 0.9375f, 0.001f, 0.075f, 0.075f); // side weapon picture next to the exp bar
        if(game_o.projectile[game_o.player.side_weapon].image == texture.projectile_030.ref_number) texture.projectile_030.draw(false,-0.0475f, 0.9375f, 0.001f, 0.075f, 0.075f); // side weapon picture next to the exp bar
        if(game_o.projectile[game_o.player.side_weapon].image == texture.projectile_031.ref_number) texture.projectile_031.draw(false,-0.0475f, 0.9375f, 0.001f, 0.075f, 0.075f); // side weapon picture next to the exp bar

        if (game_o.projectile[game_o.player.side_weapon].level == 0) temp_val = ((game_o.projectile[game_o.player.side_weapon].experience / game_o.projectile[game_o.player.side_weapon].level_1)/5);
        if (game_o.projectile[game_o.player.side_weapon].level == 1) temp_val = ((game_o.projectile[game_o.player.side_weapon].experience / game_o.projectile[game_o.player.side_weapon].level_2)/5);
        if (game_o.projectile[game_o.player.side_weapon].level == 2) temp_val = ((game_o.projectile[game_o.player.side_weapon].experience / game_o.projectile[game_o.player.side_weapon].level_3)/5);
        if (game_o.projectile[game_o.player.side_weapon].level == 3) temp_val = 0.2f;
        texture.weapon_bar.draw (false,0.0f +(temp_val/2),0.9375f, 0.001f,temp_val, 0.075f);// side weapon exp bar
    }
    temp_val = (1.95f*((float)game_o.level_kills/(float)game_o.victory_kills));
    texture.level_progress_bar.draw (false,-0.975f +(temp_val/2),-0.965f, 0.001f,temp_val, 0.025f);// level progress bar

    //--------------------------- Touch screen controls ------------------------------------------------------------------------------------
    if(game.config.Display_Touchscreen)
    {
        texture.touchscreen_arrow.draw (true,-0.875,-0.550f, 0.001f, 0.2f, 0.2f, 90.0f);// Left  button
        texture.touchscreen_arrow.draw (true,-0.475,-0.550f, 0.001f, 0.2f, 0.2f,270.0f);// Right button
        texture.touchscreen_arrow.draw (true,-0.675,-0.350f, 0.001f, 0.2f, 0.2f,  0.0f);// Up    button
        texture.touchscreen_arrow.draw (true,-0.675,-0.750f, 0.001f, 0.2f, 0.2f,180.0f);// Down  button
        texture.touchscreen_button.draw(true, 0.875,-0.750f, 0.001f, 0.2f, 0.2f,  0.0f);// Fire  button
        texture.touchscreen_button.draw(true, 0.575,-0.750f, 0.001f, 0.2f, 0.2f,  0.0f);// Bomb  button
        texture.touchscreen_button.draw(true, 0.875, 0.750f, 0.001f, 0.2f, 0.2f,  0.0f);// Menu  button
    }
    //--------------------------------------------------------------------------------------------------------------------------------------
    if (game_o.paused.active)                   game_o.paused.draw();
    if (game_o.loaded.active)                   game_o.loaded.draw();
    if (game_o.saved.active)                    game_o.saved.draw();
    if (game_o.a_score.active)                  game_o.a_score.draw();
    if (game_o.a_kills.active)                  game_o.a_kills.draw();
    if (game_o.p_actinium_shields.active)       game_o.p_actinium_shields.draw();
    if (game_o.p_blasters.active)               game_o.p_blasters.draw();
    if (game_o.p_burst_lasers.active)           game_o.p_burst_lasers.draw();
    if (game_o.p_chain_guns.active)             game_o.p_chain_guns.draw();
    if (game_o.p_convolution_thrusters.active)  game_o.p_convolution_thrusters.draw();
    if (game_o.p_health.active)                 game_o.p_health.draw();
    if (game_o.p_ion_cannons.active)            game_o.p_ion_cannons.draw();
    if (game_o.p_iridium_shileds.active)        game_o.p_iridium_shileds.draw();
    if (game_o.p_maelstrom_thrusters.active)    game_o.p_maelstrom_thrusters.draw();
    if (game_o.p_plasma_rockets.active)         game_o.p_plasma_rockets.draw();
    if (game_o.p_rail_turrets.active)           game_o.p_rail_turrets.draw();
    if (game_o.p_rubidium_shields.active)       game_o.p_rubidium_shields.draw();
    if (game_o.p_seismic_thrusters.active)      game_o.p_seismic_thrusters.draw();
    if (game_o.p_shield_level_up.active)        game_o.p_shield_level_up.draw();
    if (game_o.p_tantalum_shields.active)       game_o.p_tantalum_shields.draw();
    if (game_o.p_terbium_shields.active)        game_o.p_terbium_shields.draw();
    if (game_o.p_thrusters_level_up.active)     game_o.p_thrusters_level_up.draw();
    if (game_o.p_vortex_thrusters.active)       game_o.p_vortex_thrusters.draw();
    if (game_o.p_weapon_level_up.active)        game_o.p_weapon_level_up.draw();
    if (game_o.d_level_end.active)              game_o.d_level_end.draw();

    font.font_1.Write(255,255,255,64,-0.98f,-0.95f,"Score - ", game_o.score);
    font.font_1.Write(255,255,255,64,-0.98f,-0.91f,"Kills - ", game_o.kills);
    if (game_o.anc_enabled) font.font_1.Write(255,255,255,64, 0.40f, 0.95f,"Active NPCs - ",  game_o.active_npc_count);
    if (game_o.fps_enabled &&  game_o.anc_enabled) font.font_1.Write(255,255,255,64, 0.40f, 0.90f,"FPS - ",  game.FPS);
    if (game_o.fps_enabled && !game_o.anc_enabled) font.font_1.Write(255,255,255,64, 0.40f, 0.95f,"FPS - ",  game.FPS);
    glPopMatrix();
    return(1);
};


