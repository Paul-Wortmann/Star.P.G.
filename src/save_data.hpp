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

#ifndef SAVE_DATA_H
#define SAVE_DATA_H

#include "core/core.hpp"
#include "core/savegame.hpp"
#include "game.hpp"

struct layer_type
{
    bool  active;
    int   image;
    int   dir_x;
    int   dir_y;
    float pos_x;
    float pos_y;
    float scroll_rate_x;
    float scroll_rate_y;
};

struct background_data_type
{
    layer_type  layer[MAX_LAYERS+1];
    int         movement_type;
};

struct save_data_type
{
   int                  save_version;
   int                  npc_damage_duration;
   bool                 cheats_enabled;
   int                  number_bombs;
   int                  bomb_delay;
   int                  bomb_delay_count;
   bool                 immune;
   int                  immunity_state;
   int                  immunity_delay;
   int                  immunity_delay_count;
   bool                 anc_enabled;
   bool                 fps_enabled;
   bool                 game_paused;
   bool                 game_active;
   bool                 game_resume;
   bool                 menu_active;
   bool                 pdie_active;
   bool                 nlvl_active;
   bool                 outr_active;
   bool                 status_quit_active;
   int                  exp_rate;
   int                  level_locked[MAX_LEVELS];
   int                  level;
   int                  level_waves;
   bool                 wave_spawnable;
   int                  level_npc_type;
   bool                 level_boss_level;
   int                  score;
   int                  kills;
   int                  level_kills;
   int                  level_spawened;
   int                  level_score;
   int                  victory_kills;
   int                  victory_spawened;
   int                  victory_score;
   int                  level_end_count;
   int                  level_end_time_out;
   bool                 level_end_time;
   int                  level_end_phase;
   bool                 level_end_display_active;
   bool                 level_end_display_alpha;
   bool                 level_end_display_count;
   bool                 powerups_spawened;
   bool                 completed;
   float                speed;
   int                  fw_rof_count;
   int                  sw_rof_count;
   int                  coin_spawn_rate;
   int                  wexp_spawn_rate;
   int                  npc_spawn_rate;
   int                  npc_spawn_rate_count;
   int                  npc_projectile_spawn_rate;
   wave_class           wave[MAX_WAVES];
   player_class         player;
   supportship_class    supportship[MAX_SUPPORTSHIPS];
   enemy_type           enemy[MAX_ENEMYS];
   npc_type             npc[MAX_NPCS];
   projectile_class     projectile[MAX_PROJECTILES];
   shield_class         shield[MAX_SHIELDS];
   thruster_class       thruster[MAX_THRUSTERS];
   explosion_class      explosion[MAX_EXPLOSIONS];
   powerup_type         powerup[MAX_POWERUPS];
   coin_type            coin[MAX_COINS];
   wexp_type            wexp[MAX_WEXPS];
   int                  active_npc_count;
   active_npc_type      active_npc[MAX_NPCS];
   achivement_type      achivement;
   background_data_type background;
};

void update_save_data(void);
void update_game_data(void);

#endif // SAVE_DATA_H

