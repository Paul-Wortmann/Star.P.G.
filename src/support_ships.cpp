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
#include "support_ships.hpp"
#include "load_resources.hpp"
#include "game.hpp"
#include "misc.hpp"

extern  sound_type       sound;
extern  music_type       music;
extern  texture_type     texture;
extern  game_type  game_o;
extern  game_class game;

void supportship_class::init(int supportship_count)
{
    supportship_class::rate_of_fire       = 5;
    supportship_class::rate_of_fire_count = 0;
    supportship_class::active             = false;
    supportship_class::level              = -1;
    supportship_class::image              = supportship_count+242;
    supportship_class::width              = 0.075f;
    supportship_class::height             = 0.075f;
    for (int bullet_count = 0;bullet_count < MAX_BULLETS-1;bullet_count++)
    {
        supportship_class::bullet[bullet_count].active = false;
        supportship_class::bullet[bullet_count].x_pos  = 2.0f;
        supportship_class::bullet[bullet_count].y_pos  = 2.0f;
        if (supportship_count == 0) supportship_class::bullet[bullet_count].warhead = 31;
        if (supportship_count == 1) supportship_class::bullet[bullet_count].warhead = 32;
        if (supportship_count == 2) supportship_class::bullet[bullet_count].warhead = 33;
        if (supportship_count == 3) supportship_class::bullet[bullet_count].warhead = 34;
    }
};

void  init_supportships(void)
{
   for (int supportship_count = 0;supportship_count < MAX_SUPPORTSHIPS-1;supportship_count++)
   {
       game_o.supportship[supportship_count].init(supportship_count);
   }
};

int supportship_class::spawn_bullet(int location, int direction_x, int direction_y)
{
   bool done = false;
   for (int bullet_count = 0;bullet_count < MAX_BULLETS-1;bullet_count++)//spawn bullet
   {
       if ((!supportship_class::bullet[bullet_count].active) && (!done))
       {
          done = true;
          supportship_class::bullet[bullet_count].active = true;
          supportship_class::bullet[bullet_count].x_pos  = game_o.player.x_pos-(game_o.player.width/4)+supportship_class::width;
          if (location  == 0) supportship_class::bullet[bullet_count].y_pos  = game_o.player.y_pos-(game_o.player.hight/2)-supportship_class::height;
          if (location  == 1) supportship_class::bullet[bullet_count].y_pos  = game_o.player.y_pos+(game_o.player.hight/2)+supportship_class::height;
          if (location  == 2) supportship_class::bullet[bullet_count].y_pos  = game_o.player.y_pos-(game_o.player.hight/2)-((supportship_class::height/2)*3);
          if (location  == 3) supportship_class::bullet[bullet_count].y_pos  = game_o.player.y_pos+(game_o.player.hight/2)+((supportship_class::height/2)*3);
          if (location  == 4) supportship_class::bullet[bullet_count].y_pos  = game_o.player.y_pos-(game_o.player.hight/2)-supportship_class::height;
          if (location  == 5) supportship_class::bullet[bullet_count].y_pos  = game_o.player.y_pos+(game_o.player.hight/2)+supportship_class::height;
          if (location  == 4) supportship_class::bullet[bullet_count].x_pos -= supportship_class::width/2;
          if (location  == 5) supportship_class::bullet[bullet_count].x_pos -= supportship_class::width/2;
          supportship_class::bullet[bullet_count].x_dir   = direction_x;
          supportship_class::bullet[bullet_count].y_dir   = direction_y;
          supportship_class::bullet[bullet_count].x_speed = game_o.projectile[supportship_class::bullet[bullet_count].warhead].speed;
          supportship_class::bullet[bullet_count].y_speed = game_o.projectile[supportship_class::bullet[bullet_count].warhead].speed;
          supportship_class::bullet[bullet_count].hight   = game_o.projectile[supportship_class::bullet[bullet_count].warhead].size;
          supportship_class::bullet[bullet_count].width   = game_o.projectile[supportship_class::bullet[bullet_count].warhead].size;
       }
   }
   if (done) return(1);
   else return(0);
};

void  process_supportships(bool spawn_bullet)
{
   for (int supportship_count = 0;supportship_count < MAX_SUPPORTSHIPS-1;supportship_count++)
   {
        game_o.supportship[supportship_count].process(spawn_bullet);
   }
};

void supportship_class::process(bool spawn_bullet)
{
    int   random_temp     =  0;
    int   target_id       = -1;
    float target_distance = 10.0f;
    float temp_distance   =  0.0f;
    float x_temp_velocity =  0.0f;
    float y_temp_velocity =  0.0f;
    if (supportship_class::active)
    {
        if (supportship_class::rate_of_fire_count > supportship_class::rate_of_fire)//rof spawn bullets
        {
            supportship_class::rate_of_fire_count = 0;
            if ((supportship_class::level >= 0) && (spawn_bullet))
            {
                supportship_class::spawn_bullet(0,0,0);
                supportship_class::spawn_bullet(1,1,1);
            }
            if ((supportship_class::level >= 1) && (spawn_bullet))
            {
                supportship_class::spawn_bullet(0,2,2);
                supportship_class::spawn_bullet(1,3,3);
                supportship_class::spawn_bullet(2,2,2);
                supportship_class::spawn_bullet(3,3,3);
            }
            if ((supportship_class::level >= 2) && (spawn_bullet))
            {
                supportship_class::spawn_bullet(0,4,4);
                supportship_class::spawn_bullet(1,5,5);
                supportship_class::spawn_bullet(2,4,4);
                supportship_class::spawn_bullet(3,5,5);
                supportship_class::spawn_bullet(4,4,4);
                supportship_class::spawn_bullet(5,5,5);
            }
        }
        else supportship_class::rate_of_fire_count++;
        for (int bullet_count = 0;bullet_count < MAX_BULLETS-1;bullet_count++)//process bullets
        {
            if (supportship_class::bullet[bullet_count].active)
            {
                switch (game_o.projectile[supportship_class::bullet[bullet_count].warhead].movement)
                {
                    //case 0:
                    //break;
                    case 1:
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
                                x_temp_velocity = ((x_temp_velocity/y_temp_velocity) * game_o.projectile[supportship_class::bullet[bullet_count].warhead].speed) + game_o.projectile[supportship_class::bullet[bullet_count].warhead].speed;
                                y_temp_velocity = game_o.projectile[supportship_class::bullet[bullet_count].warhead].speed;
                            }
                            else
                            {
                                y_temp_velocity = ((x_temp_velocity/y_temp_velocity) * game_o.projectile[supportship_class::bullet[bullet_count].warhead].speed) + game_o.projectile[supportship_class::bullet[bullet_count].warhead].speed;
                                x_temp_velocity = game_o.projectile[supportship_class::bullet[bullet_count].warhead].speed;
                            }
                            if (supportship_class::bullet[bullet_count].x_pos < game_o.npc[target_id].x_pos)
                            {
                                supportship_class::bullet[bullet_count].x_pos += x_temp_velocity;
                                if (supportship_class::bullet[bullet_count].y_pos < game_o.npc[target_id].y_pos) supportship_class::bullet[bullet_count].y_pos += y_temp_velocity;
                                if (supportship_class::bullet[bullet_count].y_pos > game_o.npc[target_id].y_pos) supportship_class::bullet[bullet_count].y_pos -= y_temp_velocity;
                            }
                            else supportship_class::bullet[bullet_count].x_pos += x_temp_velocity;
                        }
                        else
                        {
                            supportship_class::bullet[bullet_count].x_pos += game_o.projectile[supportship_class::bullet[bullet_count].warhead].speed;
                            if (supportship_class::bullet[bullet_count].y_pos < game_o.player.y_pos) supportship_class::bullet[bullet_count].y_pos -= game_o.projectile[supportship_class::bullet[bullet_count].warhead].speed;
                            if (supportship_class::bullet[bullet_count].y_pos > game_o.player.y_pos) supportship_class::bullet[bullet_count].y_pos += game_o.projectile[supportship_class::bullet[bullet_count].warhead].speed;
                        }
                        if (supportship_class::bullet[bullet_count].x_pos > (1.0f+supportship_class::bullet[bullet_count].width/2))
                        {
                            supportship_class::bullet[bullet_count].active = false;
                            supportship_class::bullet[bullet_count].x_pos  = 2.0f;
                            supportship_class::bullet[bullet_count].y_pos  = 2.0f;
                        }
                        if (supportship_class::bullet[bullet_count].x_pos < (-1.0f-supportship_class::bullet[bullet_count].width/2))
                        {
                            supportship_class::bullet[bullet_count].active = false;
                            supportship_class::bullet[bullet_count].x_pos  = 2.0f;
                            supportship_class::bullet[bullet_count].y_pos  = 2.0f;
                        }
                        if (supportship_class::bullet[bullet_count].y_pos > (1.0f+supportship_class::bullet[bullet_count].hight/2))
                        {
                            supportship_class::bullet[bullet_count].active = false;
                            supportship_class::bullet[bullet_count].x_pos  = 2.0f;
                            supportship_class::bullet[bullet_count].y_pos  = 2.0f;
                        }
                        if (supportship_class::bullet[bullet_count].y_pos < (-1.0f-supportship_class::bullet[bullet_count].hight/2))
                        {
                            supportship_class::bullet[bullet_count].active = false;
                            supportship_class::bullet[bullet_count].x_pos  = 2.0f;
                            supportship_class::bullet[bullet_count].y_pos  = 2.0f;
                        }
                    break;
                    default:
                        if (supportship_class::bullet[bullet_count].x_dir == 0)
                        {
                            supportship_class::bullet[bullet_count].x_pos += supportship_class::bullet[bullet_count].x_speed;
                            if (supportship_class::bullet[bullet_count].x_pos > (1.0f+supportship_class::bullet[bullet_count].width/2))
                            {
                                supportship_class::bullet[bullet_count].active = false;
                                supportship_class::bullet[bullet_count].x_pos  = 2.0f;
                                supportship_class::bullet[bullet_count].y_pos  = 2.0f;
                            }
                        }
                        if (supportship_class::bullet[bullet_count].x_dir == 2)
                        {
                            supportship_class::bullet[bullet_count].x_pos += (supportship_class::bullet[bullet_count].x_speed);
                            if (supportship_class::bullet[bullet_count].x_pos > (1.0f+supportship_class::bullet[bullet_count].width/2))
                            {
                                supportship_class::bullet[bullet_count].active = false;
                                supportship_class::bullet[bullet_count].x_pos  = 2.0f;
                                supportship_class::bullet[bullet_count].y_pos  = 2.0f;
                            }
                        }
                        if (supportship_class::bullet[bullet_count].x_dir == 4)
                        {
                            supportship_class::bullet[bullet_count].x_pos += (supportship_class::bullet[bullet_count].x_speed);
                            if (supportship_class::bullet[bullet_count].x_pos > (1.0f+supportship_class::bullet[bullet_count].width/2))
                            {
                                supportship_class::bullet[bullet_count].active = false;
                                supportship_class::bullet[bullet_count].x_pos  = 2.0f;
                                supportship_class::bullet[bullet_count].y_pos  = 2.0f;
                            }
                        }
                        if (supportship_class::bullet[bullet_count].x_dir == 1)
                        {
                            supportship_class::bullet[bullet_count].x_pos += supportship_class::bullet[bullet_count].x_speed;
                            if (supportship_class::bullet[bullet_count].x_pos > (1.0f+supportship_class::bullet[bullet_count].width/2))
                            {
                                supportship_class::bullet[bullet_count].active = false;
                                supportship_class::bullet[bullet_count].x_pos  = 2.0f;
                                supportship_class::bullet[bullet_count].y_pos  = 2.0f;
                            }
                        }
                        if (supportship_class::bullet[bullet_count].x_dir == 3)
                        {
                            supportship_class::bullet[bullet_count].x_pos += supportship_class::bullet[bullet_count].x_speed;
                            if (supportship_class::bullet[bullet_count].x_pos > (1.0f+supportship_class::bullet[bullet_count].width/2))
                            {
                                supportship_class::bullet[bullet_count].active = false;
                                supportship_class::bullet[bullet_count].x_pos  = 2.0f;
                                supportship_class::bullet[bullet_count].y_pos  = 2.0f;
                            }
                        }
                        if (supportship_class::bullet[bullet_count].x_dir == 5)
                        {
                            supportship_class::bullet[bullet_count].x_pos += supportship_class::bullet[bullet_count].x_speed;
                            if (supportship_class::bullet[bullet_count].x_pos > (1.0f+supportship_class::bullet[bullet_count].width/2))
                            {
                                supportship_class::bullet[bullet_count].active = false;
                                supportship_class::bullet[bullet_count].x_pos  = 2.0f;
                                supportship_class::bullet[bullet_count].y_pos  = 2.0f;
                            }
                        }
                        if (supportship_class::bullet[bullet_count].y_dir == 0)
                        {
                            supportship_class::bullet[bullet_count].y_pos -= supportship_class::bullet[bullet_count].y_speed*0.25;
                            if (supportship_class::bullet[bullet_count].y_pos < (-1.0f-supportship_class::bullet[bullet_count].hight/2))
                            {
                                supportship_class::bullet[bullet_count].active = false;
                                supportship_class::bullet[bullet_count].x_pos  = 2.0f;
                                supportship_class::bullet[bullet_count].y_pos  = 2.0f;
                            }
                        }
                        if (supportship_class::bullet[bullet_count].y_dir == 2)
                        {
                            supportship_class::bullet[bullet_count].y_pos -= supportship_class::bullet[bullet_count].y_speed*0.75f;
                            if (supportship_class::bullet[bullet_count].y_pos < (-1.0f-supportship_class::bullet[bullet_count].hight/2))
                            {
                                supportship_class::bullet[bullet_count].active = false;
                                supportship_class::bullet[bullet_count].x_pos  = 2.0f;
                                supportship_class::bullet[bullet_count].y_pos  = 2.0f;
                            }
                        }
                        if (supportship_class::bullet[bullet_count].y_dir == 4)
                        {
                            supportship_class::bullet[bullet_count].y_pos -= supportship_class::bullet[bullet_count].y_speed*1.25f;
                            if (supportship_class::bullet[bullet_count].y_pos < (-1.0f-supportship_class::bullet[bullet_count].hight/2))
                            {
                                supportship_class::bullet[bullet_count].active = false;
                                supportship_class::bullet[bullet_count].x_pos  = 2.0f;
                                supportship_class::bullet[bullet_count].y_pos  = 2.0f;
                            }
                        }
                        if (supportship_class::bullet[bullet_count].y_dir == 1)
                        {
                            supportship_class::bullet[bullet_count].y_pos += supportship_class::bullet[bullet_count].y_speed*0.25;
                            if (supportship_class::bullet[bullet_count].y_pos > (1.0f+supportship_class::bullet[bullet_count].hight/2))
                            {
                                supportship_class::bullet[bullet_count].active = false;
                                supportship_class::bullet[bullet_count].x_pos  = 2.0f;
                                supportship_class::bullet[bullet_count].y_pos  = 2.0f;
                            }
                        }
                        if (supportship_class::bullet[bullet_count].y_dir == 3)
                        {
                            supportship_class::bullet[bullet_count].y_pos += supportship_class::bullet[bullet_count].y_speed*0.75f;
                            if (supportship_class::bullet[bullet_count].y_pos > (1.0f+supportship_class::bullet[bullet_count].hight/2))
                            {
                                supportship_class::bullet[bullet_count].active = false;
                                supportship_class::bullet[bullet_count].x_pos  = 2.0f;
                                supportship_class::bullet[bullet_count].y_pos  = 2.0f;
                            }
                        }
                        if (supportship_class::bullet[bullet_count].y_dir == 5)
                        {
                        supportship_class::bullet[bullet_count].y_pos += supportship_class::bullet[bullet_count].y_speed*1.25f;
                            if (supportship_class::bullet[bullet_count].y_pos > (1.0f+supportship_class::bullet[bullet_count].hight/2))
                            {
                                supportship_class::bullet[bullet_count].active = false;
                                supportship_class::bullet[bullet_count].x_pos  = 2.0f;
                                supportship_class::bullet[bullet_count].y_pos  = 2.0f;
                            }
                        }
                    break;
                }
            }
            //---------- collision detection ---------
            for (int npc_count = 0; npc_count < MAX_NPCS-1; npc_count++)
            {
                if ((game_o.npc[npc_count].active) and (supportship_class::bullet[bullet_count].active))// check player supportship bullets / npc collisions...
                {
                    if (game.physics.quadrangle_collision(game_o.npc[npc_count].x_pos,game_o.npc[npc_count].y_pos,game_o.npc[npc_count].width,game_o.npc[npc_count].hight,supportship_class::bullet[bullet_count].x_pos,supportship_class::bullet[bullet_count].y_pos,supportship_class::bullet[bullet_count].width,supportship_class::bullet[bullet_count].hight))
                    {
                        game_o.npc[npc_count].health -= game_o.projectile[supportship_class::bullet[bullet_count].warhead].damage;
                        if (game_o.npc[npc_count].health <= 0)
                        {
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
                            sound.explosion_001.play();
                            kill_npc(npc_count);
                            game_o.score += (game_o.npc[npc_count].type_npc + 1) * 10;
                            game_o.level_score += (game_o.npc[npc_count].type_npc + 1) * 10;
                            game_o.kills += 1;
                            game_o.level_kills += 1;
                            supportship_class::bullet[bullet_count].active = false;
                            supportship_class::bullet[bullet_count].x_pos  = 2.0f;
                            supportship_class::bullet[bullet_count].y_pos  = 2.0f;
                        }
                        else
                        {
                            spawn_explosion(game_o.npc[npc_count].x_pos,game_o.npc[npc_count].y_pos,0.1250f);
                            if (game_o.npc[npc_count].damaged <= 0) game_o.npc[npc_count].damaged = game_o.npc_damage_duration;
                            supportship_class::bullet[bullet_count].active = false;
                            supportship_class::bullet[bullet_count].x_pos  = 2.0f;
                            supportship_class::bullet[bullet_count].y_pos  = 2.0f;
                            sound.menu_move.play();
                        }
                    }
                }
                for (int npc_bullet_num =0;npc_bullet_num < MAX_BULLETS-1;npc_bullet_num++) // check player supportship bullets / npc bullets for collisions...
                {
                    if ((game_o.npc[npc_count].bullet[npc_bullet_num].active) and (supportship_class::bullet[bullet_count].active))
                    {
                        if (game.physics.quadrangle_collision(game_o.npc[npc_count].bullet[npc_bullet_num].x_pos,game_o.npc[npc_count].bullet[npc_bullet_num].y_pos,game_o.npc[npc_count].bullet[npc_bullet_num].width,game_o.npc[npc_count].bullet[npc_bullet_num].hight,supportship_class::bullet[bullet_count].x_pos,supportship_class::bullet[bullet_count].y_pos,supportship_class::bullet[bullet_count].width,supportship_class::bullet[bullet_count].hight))
                        {
                            spawn_explosion(game_o.npc[npc_count].bullet[npc_bullet_num].x_pos,game_o.npc[npc_count].bullet[npc_bullet_num].y_pos,0.25f);
                            sound.explosion_001.play();
                            supportship_class::bullet[bullet_count].active = false;
                            supportship_class::bullet[bullet_count].x_pos  = 2.0f;
                            supportship_class::bullet[bullet_count].y_pos  = 2.0f;
                            kill_npc_bullet(npc_count,npc_bullet_num);
                            game_o.score += game_o.npc[npc_count].type_npc + 1;
                            game_o.level_score += game_o.npc[npc_count].type_npc + 1;;
                        }
                    }
                }
            }
        }
    }
};

void supportship_class::kill_bullets(void)
{
    for (int bullet_count = 0;bullet_count < MAX_BULLETS-1;bullet_count++)
    {
        supportship_class::bullet[bullet_count].active = false;
        supportship_class::bullet[bullet_count].x_pos  = 2.0f;
        supportship_class::bullet[bullet_count].y_pos  = 2.0f;
    }
};

void kill_supportship_bullets(void)
{
    for (int supportship_count = 0;supportship_count < MAX_SUPPORTSHIPS-1;supportship_count++)
    {
        game_o.supportship[supportship_count].kill_bullets();
    }
};
