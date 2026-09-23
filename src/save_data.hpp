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

#ifndef SAVE_DATA_H
#define SAVE_DATA_H

#include "core/core.hpp"
#include "core/savegame.hpp"
#include "game.hpp"

// The version written into every save file.  Bump this whenever the layout
// of save_data_type changes so that old, incompatible saves are rejected
// rather than being silently misinterpreted.
const int   SAVE_VERSION      = 200;
const int   SAVE_NAME_LENGTH  = 64;

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

/* ---------------------------------------------------------------------------
 * POD mirror types
 * ---------------------------------------------------------------------------
 * The runtime classes enemy_class, projectile_class, shield_class,
 * thruster_class and explosion_class cannot be written to disk verbatim
 * because they contain std::string members (which hold pointers) and/or
 * emitter_class members (which contain a ~160 KB particle array).  These
 * mirror structs hold only trivially-copyable data; names are stored as
 * fixed-length char arrays, and emitters are dropped entirely (they are
 * re-initialised from their config files on load).
 * ------------------------------------------------------------------------- */
struct save_enemy_type
{
    char  name[SAVE_NAME_LENGTH];
    int   image;
    int   sound;
    float health;
    float speed;
    float max_speed;
    float acceleration;
    float start_angle;
    int   movement;
    int   weapon_1;
    int   weapon_2;
    int   projectiles;
    float width;
    float height;
};

struct save_projectile_type
{
    char  name[SAVE_NAME_LENGTH];
    bool  active;
    int   level;
    float experience;
    float level_1;
    float level_2;
    float level_3;
    float level_4;
    float level_5;
    float level_6;
    int   image;
    float width;
    float height;
    int   sound;
    float damage;
    float health;
    float speed;
    int   rate_of_fire;
    int   movement;
    float wave_size;
    float wave_velocity;
};

struct save_shield_type
{
    char  name[SAVE_NAME_LENGTH];
    bool  active;
    int   level;
    float level_1;
    float level_2;
    float level_3;
    float experience;
    int   image;
    float absorption;
};

struct save_thruster_type
{
    char  name[SAVE_NAME_LENGTH];
    bool  active;
    int   level;
    float level_1;
    float level_2;
    float level_3;
    float experience;
    int   image;
    float thrust;
    int   frame;
    int   frame_max;
};

struct save_explosion_type
{
    bool  active;
    int   image;
    int   frame;
    int   frame_max;
    float frame_delay;
    float frame_delay_count;
    float frame_delay_max;
    float x_pos;
    float y_pos;
    float width;
    float height;
    float size;
};

struct save_data_type
{
    int                  game_difficulty;
    int                  current_level;
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
    bool                 wave_spawnable;
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
    player_class         player;
    supportship_class    supportship[MAX_SUPPORTSHIPS];
    save_enemy_type      enemy[MAX_ENEMYS];
    npc_type             npc[MAX_NPCS];
    save_projectile_type projectile[MAX_PROJECTILES];
    save_shield_type     shield[MAX_SHIELDS];
    save_thruster_type   thruster[MAX_THRUSTERS];
    save_explosion_type  explosion[MAX_EXPLOSIONS];
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
