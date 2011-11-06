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

#include "save_data.hpp"
#include "core/core.hpp"
#include "game.hpp"
#include "levels.hpp"

extern game_class     game;
extern game_type      game_o;
       save_data_type save_data;

void update_save_data(void)
{
    save_data.game_difficulty           = game_o.difficulty;
    save_data.npc_damage_duration       = game_o.npc_damage_duration;
    save_data.cheats_enabled            = game_o.cheats_enabled;
    save_data.number_bombs              = game_o.number_bombs;
    save_data.bomb_delay                = game_o.bomb_delay;
    save_data.bomb_delay_count          = game_o.bomb_delay_count;
    save_data.immune                    = game_o.immune;
    save_data.immunity_state            = game_o.immunity_state;
    save_data.immunity_delay            = game_o.immunity_delay;
    save_data.immunity_delay_count      = game_o.immunity_delay_count;
    save_data.anc_enabled               = game_o.anc_enabled;
    save_data.fps_enabled               = game_o.fps_enabled;
    save_data.game_paused               = game.game_paused;
    save_data.game_active               = game.game_active;
    save_data.game_resume               = game.game_resume;
    save_data.menu_active               = game.menu_active;
    save_data.pdie_active               = game.pdie_active;
    save_data.nlvl_active               = game.nlvl_active;
    save_data.outr_active               = game.outr_active;
    save_data.status_quit_active        = game.status_quit_active;
    save_data.exp_rate                  = game_o.exp_rate;
    save_data.current_level             = game_o.current_level;
    save_data.wave_spawnable            = game_o.wave_spawnable;
    save_data.score                     = game_o.score;
    save_data.kills                     = game_o.kills;
    save_data.level_kills               = game_o.level_kills;
    save_data.level_spawened            = game_o.level_spawened;
    save_data.level_score               = game_o.level_score;
    save_data.victory_kills             = game_o.victory_kills;
    save_data.victory_spawened          = game_o.victory_spawened;
    save_data.victory_score             = game_o.victory_score;
    save_data.level_end_count           = game_o.level_end_count;
    save_data.level_end_time_out        = game_o.level_end_time_out;
    save_data.level_end_time            = game_o.level_end_time;
    save_data.level_end_phase           = game_o.level_end_phase;
    save_data.level_end_display_active  = game_o.level_end_display_active;
    save_data.level_end_display_alpha   = game_o.level_end_display_alpha;
    save_data.level_end_display_count   = game_o.level_end_display_count;
    save_data.powerups_spawened         = game_o.powerups_spawened;
    save_data.completed                 = game_o.completed;
    save_data.speed                     = game_o.speed;
    save_data.fw_rof_count              = game_o.fw_rof_count;
    save_data.sw_rof_count              = game_o.sw_rof_count;
    save_data.coin_spawn_rate           = game_o.coin_spawn_rate;
    save_data.wexp_spawn_rate           = game_o.wexp_spawn_rate;
    save_data.npc_spawn_rate            = game_o.npc_spawn_rate;
    save_data.npc_spawn_rate_count      = game_o.npc_spawn_rate_count;
    save_data.npc_projectile_spawn_rate = game_o.npc_projectile_spawn_rate;
    save_data.player                    = game_o.player;
    save_data.active_npc_count          = game_o.active_npc_count;
    save_data.achivement                = game_o.achivement;
    for (int count = 0; count <= MAX_LEVELS; count++)
    {
        save_data.level_locked[count] = game_o.level[count].locked;
    }
    for (int count = 0; count <= MAX_SUPPORTSHIPS; count++)
    {
        save_data.supportship[count] = game_o.supportship[count];
    }
    for (int count = 0; count <= MAX_ENEMYS; count++)
    {
        save_data.enemy[count] = game_o.enemy[count];
    }
    for (int count = 0; count <= MAX_NPCS; count++)
    {
        save_data.npc[count] = game_o.npc[count];
    }
    for (int count = 0; count <= MAX_PROJECTILES; count++)
    {
        save_data.projectile[count] = game_o.projectile[count];
    }
    for (int count = 0; count <= MAX_SHIELDS; count++)
    {
        save_data.shield[count] = game_o.shield[count];
    }
    for (int count = 0; count <= MAX_THRUSTERS; count++)
    {
        save_data.thruster[count].active     = game_o.thruster[count].active;
        save_data.thruster[count].level      = game_o.thruster[count].level;
        save_data.thruster[count].level_1    = game_o.thruster[count].level_1;
        save_data.thruster[count].level_2    = game_o.thruster[count].level_2;
        save_data.thruster[count].level_3    = game_o.thruster[count].level_3;
        save_data.thruster[count].experience = game_o.thruster[count].experience;
        save_data.thruster[count].thrust     = game_o.thruster[count].thrust;
        save_data.thruster[count].image      = game_o.thruster[count].image;
        save_data.thruster[count].frame      = game_o.thruster[count].frame;
        save_data.thruster[count].frame_max  = game_o.thruster[count].frame_max;
    }
    for (int count = 0; count <= MAX_EXPLOSIONS; count++)
    {
        save_data.explosion[count].active            = game_o.explosion[count].active;
        save_data.explosion[count].image             = game_o.explosion[count].image;
        save_data.explosion[count].frame             = game_o.explosion[count].frame;
        save_data.explosion[count].frame_max         = game_o.explosion[count].frame_max;
        save_data.explosion[count].frame_delay       = game_o.explosion[count].frame_delay;
        save_data.explosion[count].frame_delay_count = game_o.explosion[count].frame_delay_count;
        save_data.explosion[count].frame_delay_max   = game_o.explosion[count].frame_delay_max;
        save_data.explosion[count].x_pos             = game_o.explosion[count].x_pos;
        save_data.explosion[count].y_pos             = game_o.explosion[count].y_pos;
        save_data.explosion[count].width             = game_o.explosion[count].width;
        save_data.explosion[count].height            = game_o.explosion[count].height;
        save_data.explosion[count].size              = game_o.explosion[count].size;
    }
    for (int count = 0; count <= MAX_POWERUPS; count++)
    {
        save_data.powerup[count] = game_o.powerup[count];
    }
    for (int count = 0; count <= MAX_COINS; count++)
    {
        save_data.coin[count] = game_o.coin[count];
    }
    for (int count = 0; count <= MAX_WEXPS; count++)
    {
        save_data.wexp[count] = game_o.wexp[count];
    }
    for (int count = 0; count <= MAX_NPCS; count++)
    {
        save_data.active_npc[count] = game_o.active_npc[count];
    }
    for (int count = 0; count <= MAX_LAYERS+1; count++)
    {
        save_data.background.layer[count].active        = game.background.get_active  (count);
        save_data.background.layer[count].dir_x         = game.background.get_dir_x   (count);
        save_data.background.layer[count].dir_y         = game.background.get_dir_y   (count);
        save_data.background.layer[count].image         = game.background.get_image   (count);
        save_data.background.layer[count].pos_x         = game.background.get_pos_x   (count);
        save_data.background.layer[count].pos_y         = game.background.get_pos_y   (count);
        save_data.background.layer[count].scroll_rate_x = game.background.get_scroll_x(count);
        save_data.background.layer[count].scroll_rate_y = game.background.get_scroll_y(count);
    }
    save_data.background.movement_type = game.background.get_movement_type();
    save_data.save_version = 100;
};

void update_game_data(void)
{
    game_o.current_level = save_data.current_level;
    init_game_level(save_data.current_level);
/*
    for (int count = 0; count <= MAX_LAYERS+1; count++)
    {
        game.background.set_active  (count,save_data.background.layer[count].active);
        game.background.set_data    (count,save_data.background.layer[count].dir_x,save_data.background.layer[count].dir_y,save_data.background.layer[count].pos_x,save_data.background.layer[count].pos_y,save_data.background.layer[count].scroll_rate_x,save_data.background.layer[count].scroll_rate_y,save_data.background.layer[count].image);
        game.background.set_image   (count,save_data.background.layer[count].image);
    }
    game.background.set_movement_type(save_data.background.movement_type);
*/
    game_o.difficulty                = save_data.game_difficulty;
    game_o.npc_damage_duration       = save_data.npc_damage_duration;
    game_o.cheats_enabled            = save_data.cheats_enabled;
    game_o.number_bombs              = save_data.number_bombs;
    game_o.bomb_delay                = save_data.bomb_delay;
    game_o.bomb_delay_count          = save_data.bomb_delay_count;
    game_o.immune                    = save_data.immune;
    game_o.immunity_state            = save_data.immunity_state;
    game_o.immunity_delay            = save_data.immunity_delay;
    game_o.immunity_delay_count      = save_data.immunity_delay_count;
    game_o.anc_enabled               = save_data.anc_enabled;
    game_o.fps_enabled               = save_data.fps_enabled;
    game.game_paused                 = save_data.game_paused;
    game.game_active                 = save_data.game_active;
    game.game_resume                 = save_data.game_resume;
    game.menu_active                 = save_data.menu_active;
    game.pdie_active                 = save_data.pdie_active;
    game.nlvl_active                 = save_data.nlvl_active;
    game.outr_active                 = save_data.outr_active;
    game.status_quit_active          = save_data.status_quit_active;
    game_o.exp_rate                  = save_data.exp_rate;
    game_o.wave_spawnable            = save_data.wave_spawnable;
    game_o.score                     = save_data.score;
    game_o.kills                     = save_data.kills;
    game_o.level_kills               = save_data.level_kills;
    game_o.level_spawened            = save_data.level_spawened;
    game_o.level_score               = save_data.level_score;
    game_o.victory_kills             = save_data.victory_kills;
    game_o.victory_spawened          = save_data.victory_spawened;
    game_o.victory_score             = save_data.victory_score;
    game_o.level_end_count           = save_data.level_end_count;
    game_o.level_end_time_out        = save_data.level_end_time_out;
    game_o.level_end_time            = save_data.level_end_time;
    game_o.level_end_phase           = save_data.level_end_phase;
    game_o.level_end_display_active  = save_data.level_end_display_active;
    game_o.level_end_display_alpha   = save_data.level_end_display_alpha;
    game_o.level_end_display_count   = save_data.level_end_display_count;
    game_o.powerups_spawened         = save_data.powerups_spawened;
    game_o.completed                 = save_data.completed;
    game_o.speed                     = save_data.speed;
    game_o.fw_rof_count              = save_data.fw_rof_count;
    game_o.sw_rof_count              = save_data.sw_rof_count;
    game_o.coin_spawn_rate           = save_data.coin_spawn_rate;
    game_o.wexp_spawn_rate           = save_data.wexp_spawn_rate;
    game_o.npc_spawn_rate            = save_data.npc_spawn_rate;
    game_o.npc_spawn_rate_count      = save_data.npc_spawn_rate_count;
    game_o.npc_projectile_spawn_rate = save_data.npc_projectile_spawn_rate;
    game_o.player                    = save_data.player;
    game_o.active_npc_count          = save_data.active_npc_count;
    game_o.achivement                = save_data.achivement;
    for (int count = 0; count <= MAX_LEVELS; count++)
    {
        game_o.level[count].locked = save_data.level_locked[count];
    }
    for (int count = 0; count <= MAX_SUPPORTSHIPS; count++)
    {
        game_o.supportship[count] = save_data.supportship[count];
    }
    for (int count = 0; count <= MAX_ENEMYS; count++)
    {
        game_o.enemy[count] = save_data.enemy[count];
    }
    for (int count = 0; count <= MAX_NPCS; count++)
    {
        game_o.npc[count] = save_data.npc[count];
    }
    for (int count = 0; count <= MAX_PROJECTILES; count++)
    {
        game_o.projectile[count] = save_data.projectile[count];
    }
    for (int count = 0; count <= MAX_SHIELDS; count++)
    {
        game_o.shield[count] = save_data.shield[count];
    }
    for (int count = 0; count <= MAX_THRUSTERS; count++)
    {
        game_o.thruster[count].active     = save_data.thruster[count].active;
        game_o.thruster[count].level      = save_data.thruster[count].level;
        game_o.thruster[count].level_1    = save_data.thruster[count].level_1;
        game_o.thruster[count].level_2    = save_data.thruster[count].level_2;
        game_o.thruster[count].level_3    = save_data.thruster[count].level_3;
        game_o.thruster[count].experience = save_data.thruster[count].experience;
        game_o.thruster[count].thrust     = save_data.thruster[count].thrust;
        game_o.thruster[count].image      = save_data.thruster[count].image;
        game_o.thruster[count].frame      = save_data.thruster[count].frame;
        game_o.thruster[count].frame_max  = save_data.thruster[count].frame_max;
    }
    for (int count = 0; count <= MAX_EXPLOSIONS; count++)
    {
        game_o.explosion[count].active            = save_data.explosion[count].active;
        game_o.explosion[count].image             = save_data.explosion[count].image;
        game_o.explosion[count].frame             = save_data.explosion[count].frame;
        game_o.explosion[count].frame_max         = save_data.explosion[count].frame_max;
        game_o.explosion[count].frame_delay       = save_data.explosion[count].frame_delay;
        game_o.explosion[count].frame_delay_count = save_data.explosion[count].frame_delay_count;
        game_o.explosion[count].frame_delay_max   = save_data.explosion[count].frame_delay_max;
        game_o.explosion[count].x_pos             = save_data.explosion[count].x_pos;
        game_o.explosion[count].y_pos             = save_data.explosion[count].y_pos;
        game_o.explosion[count].width             = save_data.explosion[count].width;
        game_o.explosion[count].height            = save_data.explosion[count].height;
        game_o.explosion[count].size              = save_data.explosion[count].size;
    }
    for (int count = 0; count <= MAX_POWERUPS; count++)
    {
        game_o.powerup[count] = save_data.powerup[count];
    }
    for (int count = 0; count <= MAX_COINS; count++)
    {
        game_o.coin[count] = save_data.coin[count];
    }
    for (int count = 0; count <= MAX_WEXPS; count++)
    {
        game_o.wexp[count] = save_data.wexp[count];
    }
    for (int count = 0; count <= MAX_NPCS; count++)
    {
        game_o.active_npc[count] = save_data.active_npc[count];
    }
    save_data.save_version = 1;
};





