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
#include "explosions.hpp"
#include "load_resources.hpp"
#include "game.hpp"
#include "misc.hpp"

extern  sound_type       sound;
extern  music_type       music;
extern  texture_type     texture;
extern  game_type        game_o;
extern  game_class       game;

int spawn_explosion(float x_position, float y_position, float size)
{
    bool spawn_done = 0;
    int  explosion_num;
    int  temp_type  = random_cen();//randomize for sound choice.
    if ((temp_type >=   0) && (temp_type <   25)) sound.explosion_001.play();
    if ((temp_type >=  25) && (temp_type <   50)) sound.explosion_002.play();
    if ((temp_type >=  50) && (temp_type <   75)) sound.explosion_006.play();
    if ((temp_type >=  75) && (temp_type <= 100)) sound.explosion_007.play();
    for  (explosion_num = 0; explosion_num < MAX_EXPLOSIONS;explosion_num++)
    {
        if (!spawn_done and !game_o.explosion[explosion_num].active)
        {
            game_o.explosion[explosion_num].shrapnel.init();
            game_o.explosion[explosion_num].shrapnel.load("data/configuration/particle_systems/shrapnel.txt");
            temp_type  = random_cen();//re-randomize for shrapnel choice.
            game_o.explosion[explosion_num].shrapnel.set_emitter_pos(x_position,y_position,0.01f);
            if ((temp_type >=   0) && (temp_type <   13)) game_o.explosion[explosion_num].shrapnel.set_emitter_image(texture.shrapnel_00.ref_number);
            if ((temp_type >=  13) && (temp_type <   25)) game_o.explosion[explosion_num].shrapnel.set_emitter_image(texture.shrapnel_01.ref_number);
            if ((temp_type >=  25) && (temp_type <   38)) game_o.explosion[explosion_num].shrapnel.set_emitter_image(texture.shrapnel_02.ref_number);
            if ((temp_type >=  38) && (temp_type <   50)) game_o.explosion[explosion_num].shrapnel.set_emitter_image(texture.shrapnel_03.ref_number);
            if ((temp_type >=  50) && (temp_type <   63)) game_o.explosion[explosion_num].shrapnel.set_emitter_image(texture.shrapnel_04.ref_number);
            if ((temp_type >=  63) && (temp_type <   75)) game_o.explosion[explosion_num].shrapnel.set_emitter_image(texture.shrapnel_05.ref_number);
            if ((temp_type >=  75) && (temp_type <   88)) game_o.explosion[explosion_num].shrapnel.set_emitter_image(texture.shrapnel_06.ref_number);
            if ((temp_type >=  88) && (temp_type <= 100)) game_o.explosion[explosion_num].shrapnel.set_emitter_image(texture.shrapnel_07.ref_number);
            temp_type  = random_cen();//re-randomize for sprite choice.
            game_o.explosion[explosion_num].image               = texture.explosion_00.ref_number;
            if ((temp_type >=   0) && (temp_type <  25))
            {
                game_o.explosion[explosion_num].image           = texture.explosion_00.ref_number;
                game_o.explosion[explosion_num].frame_max       = texture.explosion_00.frame_max;
                game_o.explosion[explosion_num].frame_delay     = texture.explosion_00.frame_delay;
                game_o.explosion[explosion_num].frame_delay_max = texture.explosion_00.frame_delay_max;
            }
            if ((temp_type >=  25) && (temp_type <  50))
            {
                game_o.explosion[explosion_num].image           = texture.explosion_01.ref_number;
                game_o.explosion[explosion_num].frame_max       = texture.explosion_01.frame_max;
                game_o.explosion[explosion_num].frame_delay     = texture.explosion_01.frame_delay;
                game_o.explosion[explosion_num].frame_delay_max = texture.explosion_01.frame_delay_max;
            }
            if ((temp_type >=  50) && (temp_type < 75))
            {
                game_o.explosion[explosion_num].image           = texture.explosion_02.ref_number;
                game_o.explosion[explosion_num].frame_max       = texture.explosion_02.frame_max;
                game_o.explosion[explosion_num].frame_delay     = texture.explosion_02.frame_delay;
                game_o.explosion[explosion_num].frame_delay_max = texture.explosion_02.frame_delay_max;
            }
            if ((temp_type >= 75) && (temp_type < 101))
            {
                game_o.explosion[explosion_num].image           = texture.explosion_03.ref_number;
                game_o.explosion[explosion_num].frame_max       = texture.explosion_03.frame_max;
                game_o.explosion[explosion_num].frame_delay     = texture.explosion_03.frame_delay;
                game_o.explosion[explosion_num].frame_delay_max = texture.explosion_03.frame_delay_max;
            }
            if (game_o.explosion[explosion_num].frame_max < 24)
            {
                game_o.explosion[explosion_num].frame_delay       = 0.56f;
                game_o.explosion[explosion_num].frame_delay_max   = 1.0f;
                game_o.explosion[explosion_num].frame_delay_count = 0.0f;
            }
            else
            {
                game_o.explosion[explosion_num].frame_delay       = 0.56f;
                game_o.explosion[explosion_num].frame_delay_max   = 0.0f;
                game_o.explosion[explosion_num].frame_delay_count = 0.0f;
            }
            game_o.explosion[explosion_num].active    = true;
            game_o.explosion[explosion_num].size      = size;
            game_o.explosion[explosion_num].width     = size/2;
            game_o.explosion[explosion_num].height    = size/2;
            game_o.explosion[explosion_num].x_pos     = x_position;
            game_o.explosion[explosion_num].y_pos     = y_position;
            spawn_done = 1;
        }
    }
    return(0);
};

int kill_explosion(int explosion_num)
{
    game_o.explosion[explosion_num].active    = false;
    game_o.explosion[explosion_num].x_pos     = 0.0f;
    game_o.explosion[explosion_num].y_pos     = 0.0f;
    game_o.explosion[explosion_num].size      = 0.0f;
    game_o.explosion[explosion_num].shrapnel.kill();
    return(0);
};

int init_explosions(void)
{
    for (int count =0;count < MAX_EXPLOSIONS;count++)
    {
        game_o.explosion[count].active            = false;
        game_o.explosion[count].image             = 0;
        game_o.explosion[count].frame             = 0;
        game_o.explosion[count].frame_max         = 0;
        game_o.explosion[count].frame_delay       = 0;
        game_o.explosion[count].frame_delay_count = 0;
        game_o.explosion[count].frame_delay_max   = 0;
        game_o.explosion[count].x_pos             = 0.0f;
        game_o.explosion[count].y_pos             = 0.0f;
        game_o.explosion[count].size              = 0.0f;
        game_o.explosion[count].shrapnel.init();
    }
    return(0);
};

int proccess_explosions(void)
{
    for (int count =0;count < MAX_EXPLOSIONS;count++)
    {
        game_o.explosion[count].shrapnel.process();
        if(game_o.explosion[count].active)
        {
            game_o.explosion[count].x_pos -= (game.background.get_scroll_x(1)*2);
            game_o.explosion[count].frame_delay_count += game_o.explosion[count].frame_delay;
            if(game_o.explosion[count].frame_delay_count > game_o.explosion[count].frame_delay_max)
            {
                game_o.explosion[count].frame_delay_count = 0.0f;
                game_o.explosion[count].frame++;
                if (game_o.explosion[count].frame > game_o.explosion[count].frame_max)
                {
                    game_o.explosion[count].active  = false;
                    game_o.explosion[count].frame   = 0;
                }
            }
        }
    }
    return(0);
};

void draw_explosions(void)
{
    float z_pos;
    for (int count =MAX_EXPLOSIONS;count >=0;count--)
    {
        game_o.explosion[count].shrapnel.draw();
        z_pos = 0.001f + (0.0001*count);
        if (game_o.explosion[count].active)
        {
            if (game_o.explosion[count].image == texture.explosion_00.ref_number) texture.explosion_00.draw(true,game_o.explosion[count].x_pos,game_o.explosion[count].y_pos,z_pos,game_o.explosion[count].width,game_o.explosion[count].height,0.0f,game_o.explosion[count].frame);
            if (game_o.explosion[count].image == texture.explosion_01.ref_number) texture.explosion_01.draw(true,game_o.explosion[count].x_pos,game_o.explosion[count].y_pos,z_pos,game_o.explosion[count].width,game_o.explosion[count].height,0.0f,game_o.explosion[count].frame);
            if (game_o.explosion[count].image == texture.explosion_02.ref_number) texture.explosion_02.draw(true,game_o.explosion[count].x_pos,game_o.explosion[count].y_pos,z_pos,game_o.explosion[count].width,game_o.explosion[count].height,0.0f,game_o.explosion[count].frame);
            if (game_o.explosion[count].image == texture.explosion_03.ref_number) texture.explosion_03.draw(true,game_o.explosion[count].x_pos,game_o.explosion[count].y_pos,z_pos,game_o.explosion[count].width,game_o.explosion[count].height,0.0f,game_o.explosion[count].frame);
        }
    }
};


