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
#include "powerups.hpp"
#include "load_resources.hpp"
#include "game.hpp"
#include "misc.hpp"

extern  sound_type       sound;
extern  music_type       music;
extern  texture_type     texture;
extern  game_type  game_o;
extern  game_class game;

int spawn_powerup(float x_position, float y_position, int type_powerup)
{
    if (!game_o.powerup[type_powerup].active)
    {
        game_o.powerup[type_powerup].active     = true;
        game_o.powerup[type_powerup].x_pos      = x_position;
        game_o.powerup[type_powerup].y_pos      = y_position;
        game_o.powerup[type_powerup].width      = 0.10f;
        game_o.powerup[type_powerup].height      = 0.10f;
        game_o.powerup[type_powerup].speed      = 0.0025f;
    }
    return(0);
};
/*----------------------------------------------------------------------------*/
int kill_powerup(int type_powerup)
{
    game_o.powerup[type_powerup].active     = false;
    game_o.powerup[type_powerup].x_pos      = -2.0f;
    game_o.powerup[type_powerup].y_pos      = -2.0f;
    game_o.powerup[type_powerup].width      = 0.10f;
    game_o.powerup[type_powerup].height      = 0.10f;
    game_o.powerup[type_powerup].speed      = 0.0025f;
    return(0);
};
/*----------------------------------------------------------------------------*/
int kill_powerups(void)
{
    for (int count = 0;count < MAX_POWERUPS-1;count++)
    {
        game_o.powerup[count].active     = false;
        game_o.powerup[count].x_pos      = -2.0f;
        game_o.powerup[count].y_pos      = -2.0f;
        game_o.powerup[count].width      = 0.10f;
        game_o.powerup[count].height      = 0.10f;
        game_o.powerup[count].speed      = 0.0025f;
    }
    return(0);
};
/*----------------------------------------------------------------------------*/
int init_powerups(void)
{
    for (int count = 0;count < MAX_POWERUPS-1;count++)
    {
        game_o.powerup[count].active     = false;
        game_o.powerup[count].image      = 291;
        game_o.powerup[count].sound      = 5;
        game_o.powerup[count].x_pos      = -2.0f;
        game_o.powerup[count].y_pos      = -2.0f;
        game_o.powerup[count].width      = 0.10f;
        game_o.powerup[count].height      = 0.10f;
        game_o.powerup[count].speed      = 0.0025f;
        game_o.powerup[count].spawn_rate = 20000;
    }
    game_o.powerup[1 ].image   = texture.health_powerup.ref_number;          //health
    game_o.powerup[2 ].image   = texture.shield_lvlup_powerup.ref_number;    //shield lvl up
    game_o.powerup[3 ].image   = texture.shield_new_powerup.ref_number;      //shield new
    game_o.powerup[4 ].image   = texture.thruster_lvlup_powerup.ref_number;  //thruster lvl up
    game_o.powerup[5 ].image   = texture.thruster_new_powerup.ref_number;    //thruster new
    game_o.powerup[6 ].image   = texture.weapon_lvlup_powerup.ref_number;    //weapon lvl up
    game_o.powerup[7 ].image   = texture.weapon_new_powerup.ref_number;      //weapon new
    game_o.powerup[8 ].image   = texture.bomb_powerup.ref_number;            //bomb
    game_o.powerup[9 ].image   = texture.powerup_sideship_00.ref_number;     //side helper ship 0
    game_o.powerup[10].image   = texture.powerup_sideship_01.ref_number;     //side helper ship 1
    game_o.powerup[11].image   = texture.powerup_sideship_02.ref_number;     //side helper ship 2
    game_o.powerup[12].image   = texture.powerup_sideship_03.ref_number;     //side helper ship 3

    game_o.powerup[1 ].sound   = 14;//health
    game_o.powerup[2 ].sound   = 15;//shield lvl up
    game_o.powerup[3 ].sound   = 16;//shield new
    game_o.powerup[4 ].sound   = 17;//thruster lvl up
    game_o.powerup[5 ].sound   = 18;//thruster new
    game_o.powerup[6 ].sound   = 19;//weapon lvl up
    game_o.powerup[7 ].sound   = 20;//weapon new
    game_o.powerup[8 ].sound   = 14;//bomb
    game_o.powerup[9 ].sound   = 18;//side helper ship 0
    game_o.powerup[10].sound   = 18;//side helper ship 1
    game_o.powerup[11].sound   = 18;//side helper ship 2
    game_o.powerup[12].sound   = 18;//side helper ship 3

    game_o.powerup[9 ].spawn_rate = 65000;//side helper ship 0
    game_o.powerup[10].spawn_rate = 65000;//side helper ship 1
    game_o.powerup[11].spawn_rate = 65000;//side helper ship 2
    game_o.powerup[12].spawn_rate = 65000;//side helper ship 3
    return(0);
};
/*----------------------------------------------------------------------------*/
int proccess_powerups(void)
{
    for (int count = 1; count < MAX_POWERUPS; count++)
    {
        if (game_o.powerup[count].active)
        {
            game_o.powerup[count].x_pos -= game_o.powerup[count].speed;
            if (game_o.powerup[count].x_pos <= (-1.0f - game_o.powerup[count].width)) kill_powerup(count);
            if (game.physics.quadrangle_collision(game_o.player.x_pos,game_o.player.y_pos,game_o.player.width,game_o.player.height,game_o.powerup[count].x_pos,game_o.powerup[count].y_pos,game_o.powerup[count].width,game_o.powerup[count].height))
            {
                if (count ==  1) sound.powerup_01.play();
                if (count ==  2) sound.powerup_02.play();
                if (count ==  3) sound.powerup_03.play();
                if (count ==  4) sound.powerup_04.play();
                if (count ==  5) sound.powerup_05.play();
                if (count ==  6) sound.powerup_06.play();
                if (count ==  7) sound.powerup_07.play();
                if (count ==  8) sound.powerup_08.play();
                if (count ==  9) sound.powerup_09.play();
                if (count == 10) sound.powerup_10.play();
                if (count == 11) sound.powerup_11.play();
                if (count == 12) sound.powerup_12.play();
                kill_powerup(count);
                switch (count)
                {
                    case 1: //health 100%
                        {
                        game_o.player.health = game_o.player.max_health;
                        game_o.p_health.spawn();
                        }
                    break;
                    case 2://shield level up
                        {
                            if (game_o.player.front_shield >= 0)
                            {
                                if (game_o.shield[game_o.player.front_shield].level  < 3)
                                {
                                    game_o.shield[game_o.player.front_shield].level++;
                                    game_o.p_shield_level_up.spawn();
                                }
                            }
                        }
                    break;
                    case 3://gain a new shield
                        {
                            bool done = false;
                            for (int s_count = 0; s_count < MAX_SHIELDS; s_count++)
                            {
                                if ((!game_o.shield[s_count].active) and (!done))
                                {
                                    game_o.player.front_shield = s_count;
                                    game_o.shield[s_count].active = true;
                                    done = true;
                                    if (game_o.player.front_shield == 0)
                                    {
                                        game_o.player.shield_regen_rate   = 0.00005f;
                                        game_o.player.max_shield          = 0.100f;
                                        game_o.player.health_regen_rate   = 0.000075f;
                                        game_o.player.max_health          = 0.200f;
                                        game_o.p_terbium_shields.spawn();
                                    }
                                    if (game_o.player.front_shield == 1)
                                    {
                                        game_o.player.shield_regen_rate   = 0.000075f;
                                        game_o.player.max_shield          = 0.150f;
                                        game_o.player.health_regen_rate   = 0.0001f;
                                        game_o.player.max_health          = 0.250f;
                                        game_o.p_iridium_shileds.spawn();
                                    }
                                    if (game_o.player.front_shield == 2)
                                    {
                                        game_o.player.shield_regen_rate   = 0.0001f;
                                        game_o.player.max_shield          = 0.200f;
                                        game_o.player.health_regen_rate   = 0.000125f;
                                        game_o.player.max_health          = 0.300f;
                                        game_o.p_rubidium_shields.spawn();
                                    }
                                    if (game_o.player.front_shield == 3)
                                    {
                                        game_o.player.shield_regen_rate   = 0.000125f;
                                        game_o.player.max_shield          = 0.250f;
                                        game_o.player.health_regen_rate   = 0.00015f;
                                        game_o.player.max_health          = 0.350f;
                                        game_o.p_tantalum_shields.spawn();
                                    }
                                    if (game_o.player.front_shield == 4)
                                    {
                                        game_o.player.shield_regen_rate   = 0.00015f;
                                        game_o.player.max_shield          = 0.300f;
                                        game_o.player.health_regen_rate   = 0.000175f;
                                        game_o.player.max_health          = 0.400f;
                                        game_o.p_actinium_shields.spawn();
                                    }
                                }
                            }
                        }
                    break;
                    case 4://thrusters level up
                        {
                            if (game_o.player.thrusters >= 0)
                            {
                                if (game_o.thruster[game_o.player.thrusters].level  < 3)
                                {
                                    game_o.thruster[game_o.player.thrusters].level++;
                                    game_o.p_thrusters_level_up.spawn();
                                }
                            }
                        }
                    break;
                    case 5://get new thrusters
                        {
                            bool done = false;
                            for (int t_count = 0; t_count < MAX_THRUSTERS; t_count++)
                            {
                                if ((!game_o.thruster[t_count].active) and (!done))
                                {
                                    game_o.player.thrusters = t_count;
                                    game_o.thruster[t_count].active = true;
                                    done = true;
                                    if (game_o.player.thrusters == 0) game_o.p_maelstrom_thrusters.spawn();
                                    if (game_o.player.thrusters == 1) game_o.p_seismic_thrusters.spawn();
                                    if (game_o.player.thrusters == 2) game_o.p_vortex_thrusters.spawn();
                                    if (game_o.player.thrusters == 3) game_o.p_convolution_thrusters.spawn();
                                }
                            }
                        }
                    break;
                    case 6://weapon lvl up
                        {
                            game_o.projectile[game_o.player.front_weapon].level++;
                            if (game_o.projectile[game_o.player.front_weapon].level > 3) game_o.projectile[game_o.player.front_weapon].level = 3;
                            game_o.projectile[game_o.player.front_weapon].experience = 0;
                            if (game_o.player.side_weapon != game_o.player.front_weapon)
                            {
                                game_o.projectile[game_o.player.side_weapon].level++;
                                if (game_o.projectile[game_o.player.side_weapon].level > 3) game_o.projectile[game_o.player.side_weapon].level = 3;
                                game_o.projectile[game_o.player.side_weapon].experience = 0;
                            }
                            game_o.p_weapon_level_up.spawn();
                        }
                    break;
                    case 7://get new weapon
                        {
                            bool done = false;
                            for (int w_count = 0; w_count < MAX_PROJECTILES; w_count++)
                            {
                                if (!game_o.projectile[w_count].active and !done and (w_count < 6))
                                {
                                    game_o.player.front_weapon = w_count;
                                    game_o.player.side_weapon  = w_count;
                                    game_o.projectile[w_count].active = true;
                                    done = true;
                                    if (game_o.player.front_weapon == 0) game_o.p_blasters.spawn();
                                    if (game_o.player.front_weapon == 1) game_o.p_chain_guns.spawn();
                                    if (game_o.player.front_weapon == 2) game_o.p_burst_lasers.spawn();
                                    if (game_o.player.front_weapon == 3) game_o.p_rail_turrets.spawn();
                                    if (game_o.player.front_weapon == 4) game_o.p_plasma_rockets.spawn();
                                    if (game_o.player.front_weapon == 5) game_o.p_ion_cannons.spawn();
                                }
                            }
                        }
                    break;
                    case 8://get bomb
                        {
                            game_o.number_bombs++;
                            if(game_o.number_bombs > MAX_BOMBS) game_o.number_bombs = MAX_BOMBS;
                        }
                    break;
                    case 9://support ship 0
                        {
                            if (game_o.supportship[0].active)
                            {
                                game_o.supportship[0].level++;
                                if (game_o.supportship[0].level > MAX_SUPPORTSHIP_LEVELS-1) game_o.supportship[0].level = MAX_SUPPORTSHIP_LEVELS-1;
                                game_o.supportship[0].supportship_pos[game_o.supportship[0].level].active = true;
                            }
                            else
                            {
                                for (int count = 0;count < MAX_SUPPORTSHIPS-1;count++)
                                {
                                    game_o.supportship[count].active = false;
                                    if (game_o.difficulty > 0) game_o.supportship[count].level  = -1;
                                    for (int supportship_level_count = 1;supportship_level_count < MAX_SUPPORTSHIP_LEVELS;supportship_level_count++)
                                    {
                                        if (game_o.difficulty > 0) game_o.supportship[count].supportship_pos[supportship_level_count].active = false;
                                    }
                                    for (int bullet_count = 0;bullet_count < MAX_BULLETS-1;bullet_count++)
                                    {
                                        game_o.supportship[count].bullet[bullet_count].active = false;
                                    }
                                }
                                game_o.supportship[0].active = true;
                                if (game_o.difficulty > 0) game_o.supportship[0].level  = 0;
                                else
                                {
                                    if (game_o.supportship[0].level < 0) game_o.supportship[0].level  = 0;
                                }
                            }
                        }
                    break;
                    case 10://support ship 1
                        {
                            if (game_o.supportship[1].active)
                            {
                                game_o.supportship[1].level++;
                                if (game_o.supportship[1].level > MAX_SUPPORTSHIP_LEVELS-1) game_o.supportship[1].level = MAX_SUPPORTSHIP_LEVELS-1;
                                game_o.supportship[1].supportship_pos[game_o.supportship[1].level].active = true;
                            }
                            else
                            {
                                for (int count = 0;count < MAX_SUPPORTSHIPS-1;count++)
                                {
                                    game_o.supportship[count].active = false;
                                    if (game_o.difficulty > 0) game_o.supportship[count].level  = -1;
                                    for (int supportship_level_count = 1;supportship_level_count < MAX_SUPPORTSHIP_LEVELS;supportship_level_count++)
                                    {
                                        if (game_o.difficulty > 0) game_o.supportship[count].supportship_pos[supportship_level_count].active = false;
                                    }
                                    for (int bullet_count = 0;bullet_count < MAX_BULLETS-1;bullet_count++)
                                    {
                                        game_o.supportship[count].bullet[bullet_count].active = false;
                                    }
                                }
                                game_o.supportship[1].active = true;
                                if (game_o.difficulty > 0) game_o.supportship[1].level  = 0;
                                else
                                {
                                    if (game_o.supportship[1].level < 0) game_o.supportship[1].level  = 0;
                                }
                            }
                        }
                    break;
                    case 11://support ship 2
                        {
                            if (game_o.supportship[2].active)
                            {
                                game_o.supportship[2].level++;
                                if (game_o.supportship[2].level > MAX_SUPPORTSHIP_LEVELS-1) game_o.supportship[2].level = MAX_SUPPORTSHIP_LEVELS-1;
                                game_o.supportship[2].supportship_pos[game_o.supportship[2].level].active = true;
                            }
                            else
                            {
                                for (int count = 0;count < MAX_SUPPORTSHIPS-1;count++)
                                {
                                    game_o.supportship[count].active = false;
                                    if (game_o.difficulty > 0) game_o.supportship[count].level  = -1;
                                    for (int supportship_level_count = 1;supportship_level_count < MAX_SUPPORTSHIP_LEVELS;supportship_level_count++)
                                    {
                                        if (game_o.difficulty > 0) game_o.supportship[count].supportship_pos[supportship_level_count].active = false;
                                    }
                                    for (int bullet_count = 0;bullet_count < MAX_BULLETS-1;bullet_count++)
                                    {
                                        game_o.supportship[count].bullet[bullet_count].active = false;
                                    }
                                }
                                game_o.supportship[2].active = true;
                                if (game_o.difficulty > 0) game_o.supportship[2].level  = 0;
                                else
                                {
                                    if (game_o.supportship[2].level < 0) game_o.supportship[2].level  = 0;
                                }
                            }
                        }
                    break;
                    case 12://support ship 3
                        {
                            if (game_o.supportship[3].active)
                            {
                                game_o.supportship[3].supportship_pos[0].active = true;
                                game_o.supportship[3].level++;
                                if (game_o.supportship[3].level > MAX_SUPPORTSHIP_LEVELS-1) game_o.supportship[3].level = MAX_SUPPORTSHIP_LEVELS-1;
                                game_o.supportship[3].supportship_pos[game_o.supportship[3].level].active = true;
                            }
                            else
                            {
                                for (int count = 0;count < MAX_SUPPORTSHIPS-1;count++)
                                {
                                    game_o.supportship[count].active = false;
                                    if (game_o.difficulty > 0) game_o.supportship[count].level  = -1;
                                    for (int supportship_level_count = 1;supportship_level_count < MAX_SUPPORTSHIP_LEVELS;supportship_level_count++)
                                    {
                                        if (game_o.difficulty > 0) game_o.supportship[count].supportship_pos[supportship_level_count].active = false;
                                    }
                                    for (int bullet_count = 0;bullet_count < MAX_BULLETS-1;bullet_count++)
                                    {
                                        game_o.supportship[count].bullet[bullet_count].active = false;
                                    }
                                }
                                game_o.supportship[3].active = true;
                                if (game_o.difficulty > 0) game_o.supportship[3].level  = 0;
                                else
                                {
                                    if (game_o.supportship[3].level < 0) game_o.supportship[3].level  = 0;
                                }
                            }
                        }
                    break;
                }
            }
        }
    }
   return(0);
};

/*----------------------------------------------------------------------------*/
int  use_bomb_powerup(void)
{
    Mix_Volume(-1,(game.config.Audio_Sound_Volume/2));
    if (!boss_level())
    {
        for (int npc_count = 0; npc_count < MAX_NPCS; npc_count++) //kill all npcs
        {
            sound.explosion_005.play();
            if (game_o.npc[npc_count].active)
            {
                int random_temp = random_int();
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
                game_o.score += (game_o.npc[npc_count].type_npc + 1) * 10;
                game_o.level_score += (game_o.npc[npc_count].type_npc + 1) * 10;
                spawn_explosion(game_o.npc[npc_count].x_pos,game_o.npc[npc_count].y_pos,0.50f);
                kill_npc(npc_count);
                game_o.kills++;
                game_o.level_kills++;
            }
        }
    }
    if (boss_level())
    {
        for (int npc_count = 0; npc_count < MAX_NPCS; npc_count++) //damage all npcs
        {
            sound.explosion_005.play();
            if (game_o.npc[npc_count].active)
            {
                game_o.npc[npc_count].health -= (game_o.enemy[game_o.npc[npc_count].type_npc].health/10);
                if (game_o.npc[npc_count].health <= 0)
                {
                    kill_npc(npc_count);
                    game_o.kills++;
                    game_o.level_kills++;
                }
            }
        }
    }
    for (int npc_count = 0; npc_count < MAX_NPCS; npc_count++)//kill all npc bullets
    {
        for (int bullet_count = 0; bullet_count < MAX_BULLETS-1; bullet_count++)
        {
            if (game_o.npc[npc_count].bullet[bullet_count].active)
            {
                spawn_explosion(game_o.npc[npc_count].bullet[bullet_count].x_pos,game_o.npc[npc_count].bullet[bullet_count].y_pos,0.125f);
                kill_npc_bullet(npc_count,1,bullet_count);
                kill_npc_bullet(npc_count,2,bullet_count);
            }
        }
    }
    Mix_Volume(-1,game.config.Audio_Sound_Volume);
};

/*----------------------------------------------------------------------------*/
int spawn_coin(float x_position, float y_position, int coin_value)
{
    bool spawned = false;
    for (int count = 1;count < MAX_COINS;count++)
    {
        if (!game_o.coin[count].active && !spawned)
        {
            game_o.coin[count].active        = true;
            game_o.coin[count].x_pos         = x_position;
            game_o.coin[count].y_pos         = y_position;
            game_o.coin[count].width         = (0.055f + (coin_value / 750.0f));
            game_o.coin[count].height        = (0.055f + (coin_value / 750.0f));
            game_o.coin[count].sound         = 21;
            game_o.coin[count].speed         = 0.0025f;
            game_o.coin[count].value         = coin_value;
            spawned = true;
        }
    }
    return(0);
}
/*----------------------------------------------------------------------------*/
int kill_coin(int coin_num)
{
    game_o.coin[coin_num].active     = false;
    game_o.coin[coin_num].image      = texture.coin_powerup.ref_number;
    game_o.coin[coin_num].sound      = 21;
    game_o.coin[coin_num].x_pos      = -2.0f;
    game_o.coin[coin_num].y_pos      = -2.0f;
    game_o.coin[coin_num].width      = 0.10f;
    game_o.coin[coin_num].height     = 0.10f;
    game_o.coin[coin_num].speed      = 0.0025f;
    game_o.coin[coin_num].value      = 0;
    return(0);
}
/*----------------------------------------------------------------------------*/
int kill_coins(void)
{
    for (int count = 0;count < MAX_COINS;count++)
    {
        game_o.coin[count].active     = false;
        game_o.coin[count].image      = texture.coin_powerup.ref_number;
        game_o.coin[count].sound      = 21;
        game_o.coin[count].x_pos      = -2.0f;
        game_o.coin[count].y_pos      = -2.0f;
        game_o.coin[count].width      = 0.10f;
        game_o.coin[count].height     = 0.10f;
        game_o.coin[count].speed      = 0.0025f;
        game_o.coin[count].value      = 0;
    }
    return(0);
}
/*----------------------------------------------------------------------------*/
int init_coin(void)
{
   for (int count = 0;count < MAX_COINS;count++)
   {
      game_o.coin[count].active     = false;
      game_o.coin[count].image      = texture.coin_powerup.ref_number;
      game_o.coin[count].sound      = 21;
      game_o.coin[count].x_pos      = -2.0f;
      game_o.coin[count].y_pos      = -2.0f;
      game_o.coin[count].width      = 0.10f;
      game_o.coin[count].height     = 0.10f;
      game_o.coin[count].speed      = 0.0025f;
      game_o.coin[count].value      = 0;
   }
   return(0);
}
/*----------------------------------------------------------------------------*/
int proccess_coin(void)
{
    for (int count = 0; count < MAX_COINS; count++)
    {
        if (game_o.coin[count].active)
        {
            game_o.coin[count].x_pos -= game_o.coin[count].speed;
            if (game_o.coin[count].x_pos <= (-1.0f - game_o.coin[count].width)) kill_coin(count);
            if (game.physics.quadrangle_collision(game_o.player.x_pos,game_o.player.y_pos,game_o.player.width,game_o.player.height,game_o.coin[count].x_pos,game_o.coin[count].y_pos,game_o.coin[count].width,game_o.coin[count].height))
            {
                game_o.score += game_o.coin[count].value;
                game_o.level_score += game_o.coin[count].value;
                kill_coin(count);
                sound.coin_00.play();
            }
        }
    }
    return(0);
}
/*----------------------------------------------------------------------------*/
int spawn_wexp(float x_position, float y_position, int wexp_value)
{
   bool spawned = false;
   for (int count = 0;count < MAX_WEXPS;count++)
   {
        if (!game_o.wexp[count].active && !spawned)
        {
            game_o.wexp[count].active        = true;
            game_o.wexp[count].x_pos         = x_position;
            game_o.wexp[count].y_pos         = y_position;
            game_o.wexp[count].width         = (0.055f + (wexp_value / 750.f));
            game_o.wexp[count].height        = (0.055f + (wexp_value / 750.f));
            game_o.wexp[count].value         = wexp_value;
            spawned = true;
        }
    }
    return(0);
}
/*----------------------------------------------------------------------------*/
int kill_wexp(int wexp_num)
{
    game_o.wexp[wexp_num].active     = false;
    game_o.wexp[wexp_num].image      = texture.wexp_powerup.ref_number;
    game_o.wexp[wexp_num].sound      = 22;
    game_o.wexp[wexp_num].x_pos      = -2.0f;
    game_o.wexp[wexp_num].y_pos      = -2.0f;
    game_o.wexp[wexp_num].width      = 0.10f;
    game_o.wexp[wexp_num].height     = 0.10f;
    game_o.wexp[wexp_num].speed      = 0.0025f;
    game_o.wexp[wexp_num].value      = 0;
    return(0);
}
/*----------------------------------------------------------------------------*/
int kill_wexps(void)
{
    for (int count = 0;count < MAX_WEXPS;count++)
    {
        game_o.wexp[count].active     = false;
        game_o.wexp[count].image      = texture.wexp_powerup.ref_number;
        game_o.wexp[count].sound      = 22;
        game_o.wexp[count].x_pos      = -2.0f;
        game_o.wexp[count].y_pos      = -2.0f;
        game_o.wexp[count].width      = 0.10f;
        game_o.wexp[count].height     = 0.10f;
        game_o.wexp[count].speed      = 0.0025f;
        game_o.wexp[count].value      = 0;
    }
    return(0);
}
/*----------------------------------------------------------------------------*/
int init_wexp(void)
{
    for (int count = 0;count < MAX_WEXPS;count++)
    {
        game_o.wexp[count].active     = false;
        game_o.wexp[count].image      = texture.wexp_powerup.ref_number;
        game_o.wexp[count].sound      = 22;
        game_o.wexp[count].x_pos      = -2.0f;
        game_o.wexp[count].y_pos      = -2.0f;
        game_o.wexp[count].width      = 0.10f;
        game_o.wexp[count].height     = 0.10f;
        game_o.wexp[count].speed      = 0.0025f;
        game_o.wexp[count].value      = 0;
    }
    return(0);
}
/*----------------------------------------------------------------------------*/
int proccess_wexp(void)
{
    for (int count = 0; count < MAX_WEXPS; count++)
    {
        if (game_o.wexp[count].active)
        {
            game_o.wexp[count].x_pos -= game_o.wexp[count].speed;
            if (game_o.wexp[count].x_pos <= (-1.0f - game_o.wexp[count].width)) kill_wexp(count);
            if (game.physics.quadrangle_collision(game_o.player.x_pos,game_o.player.y_pos,game_o.player.width,game_o.player.height,game_o.wexp[count].x_pos,game_o.wexp[count].y_pos,game_o.wexp[count].width,game_o.wexp[count].height))
            {
                //level up our front weapon!
                game_o.projectile[game_o.player.front_weapon].experience += game_o.wexp[count].value*game_o.exp_rate;
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
                //level up our side weapon!
                game_o.projectile[game_o.player.side_weapon].experience += game_o.wexp[count].value*game_o.exp_rate;
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
                kill_wexp(count);
                sound.wexp_00.play();
            }
        }
    }
    return(0);
}
