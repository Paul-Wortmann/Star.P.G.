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

#ifndef GAME_H
#define GAME_H

#include <string>
#include <SDL/SDL.h>
#include "PC.hpp"
#include "NPC.hpp"
#include "waves.hpp"
#include "levels.hpp"
#include "shields.hpp"
#include "powerups.hpp"
#include "thrusters.hpp"
#include "explosions.hpp"
#include "projectiles.hpp"
#include "support_ships.hpp"

struct fade_logo_type
{
   bool  active;
   float alpha;
};

struct achivement_type
{
   int score;
   int score_level_1;
   int score_level_2;
   int score_level_3;
   int score_level_4;
   int score_level_5;
   int score_level_6;
   int score_level_7;
   int kills;
   int kills_level_1;
   int kills_level_2;
   int kills_level_3;
   int kills_level_4;
   int kills_level_5;
   int kills_level_6;
   int kills_level_7;
};

struct game_type
{
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
   fade_logo_type       paused;
   fade_logo_type       loaded;
   fade_logo_type       saved;
   fade_logo_type       a_score;
   fade_logo_type       a_kills;
   fade_logo_type       p_actinium_shields;
   fade_logo_type       p_blasters;
   fade_logo_type       p_burst_lasers;
   fade_logo_type       p_chain_guns;
   fade_logo_type       p_convolution_thrusters;
   fade_logo_type       p_health;
   fade_logo_type       p_ion_cannons;
   fade_logo_type       p_iridium_shileds;
   fade_logo_type       p_maelstrom_thrusters;
   fade_logo_type       p_plasma_rockets;
   fade_logo_type       p_rail_turrets;
   fade_logo_type       p_rubidium_shields;
   fade_logo_type       p_seismic_thrusters;
   fade_logo_type       p_shield_level_up;
   fade_logo_type       p_tantalum_shields;
   fade_logo_type       p_terbium_shields;
   fade_logo_type       p_thrusters_level_up;
   fade_logo_type       p_vortex_thrusters;
   fade_logo_type       p_weapon_level_up;
};

int   init_game           (bool re_init);
bool  level_completed     (void);
int   process_game        (void);
int   display_game        (void);

int  kill_paused(void);
int  spawn_paused(void);
int  display_paused(void);
int  process_paused(void);

int  kill_loaded(void);
int  spawn_loaded(void);
int  display_loaded(void);
int  process_loaded(void);

int  kill_saved(void);
int  spawn_saved(void);
int  display_saved(void);
int  process_saved(void);

int  kill_a_score(void);
int  spawn_a_score(void);
int  display_a_score(void);
int  process_a_score(void);

int  kill_a_kills(void);
int  spawn_a_kills(void);
int  display_a_kills(void);
int  process_a_kills(void);

int  kill_p_actinium_shields(void);
int  spawn_p_actinium_shields(void);
int  display_p_actinium_shields(void);
int  process_p_actinium_shields(void);

int  kill_p_blasters(void);
int  spawn_p_blasters(void);
int  display_p_blasters(void);
int  process_p_blasters(void);

int  kill_p_burst_lasers(void);
int  spawn_p_burst_lasers(void);
int  display_p_burst_lasers(void);
int  process_p_burst_lasers(void);

int  kill_p_chain_guns(void);
int  spawn_p_chain_guns(void);
int  display_p_chain_guns(void);
int  process_p_chain_guns(void);

int  kill_p_convolution_thrusters(void);
int  spawn_p_convolution_thrusters(void);
int  display_p_convolution_thrusters(void);
int  process_p_convolution_thrusters(void);

int  kill_p_health(void);
int  spawn_p_health(void);
int  display_p_health(void);
int  process_p_health(void);

int  kill_p_ion_cannons(void);
int  spawn_p_ion_cannons(void);
int  display_p_ion_cannons(void);
int  process_p_ion_cannons(void);

int  kill_p_iridium_shileds(void);
int  spawn_p_iridium_shileds(void);
int  display_p_iridium_shileds(void);
int  process_p_iridium_shileds(void);

int  kill_p_maelstrom_thrusters(void);
int  spawn_p_maelstrom_thrusters(void);
int  display_p_maelstrom_thrusters(void);
int  process_p_maelstrom_thrusters(void);

int  kill_p_plasma_rockets(void);
int  spawn_p_plasma_rockets(void);
int  display_p_plasma_rockets(void);
int  process_p_plasma_rockets(void);

int  kill_p_rail_turrets(void);
int  spawn_p_rail_turrets(void);
int  display_p_rail_turrets(void);
int  process_p_rail_turrets(void);

int  kill_p_rubidium_shields(void);
int  spawn_p_rubidium_shields(void);
int  display_p_rubidium_shields(void);
int  process_p_rubidium_shields(void);

int  kill_p_seismic_thrusters(void);
int  spawn_p_seismic_thrusters(void);
int  display_p_seismic_thrusters(void);
int  process_p_seismic_thrusters(void);

int  kill_p_shield_level_up(void);
int  spawn_p_shield_level_up(void);
int  display_p_shield_level_up(void);
int  process_p_shield_level_up(void);

int  kill_p_tantalum_shields(void);
int  spawn_p_tantalum_shields(void);
int  display_p_tantalum_shields(void);
int  process_p_tantalum_shields(void);

int  kill_p_terbium_shields(void);
int  spawn_p_terbium_shields(void);
int  display_p_terbium_shields(void);
int  process_p_terbium_shields(void);

int  kill_p_thrusters_level_up(void);
int  spawn_p_thrusters_level_up(void);
int  display_p_thrusters_level_up(void);
int  process_p_thrusters_level_up(void);

int  kill_p_vortex_thrusters(void);
int  spawn_p_vortex_thrusters(void);
int  display_p_vortex_thrusters(void);
int  process_p_vortex_thrusters(void);

int  kill_p_weapon_level_up(void);
int  spawn_p_weapon_level_up(void);
int  display_p_weapon_level_up(void);
int  process_p_weapon_level_up(void);

int  kill_d_level_end(void);
int  spawn_d_level_end(void);
int  display_d_level_end(void);
int  process_d_level_end(void);

bool boss_level(void);

#endif //GAME_H
