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
#include "in_game_messages.hpp"

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
   int                         npc_damage_duration;
   bool                        cheats_enabled;
   int                         number_bombs;
   int                         bomb_delay;
   int                         bomb_delay_count;
   bool                        immune;
   int                         immunity_state;
   int                         immunity_delay;
   int                         immunity_delay_count;
   bool                        anc_enabled;
   bool                        fps_enabled;
   int                         exp_rate;
   int                         level_locked[MAX_LEVELS];
   int                         level;
   int                         level_waves;
   bool                        wave_spawnable;
   int                         level_npc_type;
   bool                        level_boss_level;
   int                         score;
   int                         kills;
   int                         level_kills;
   int                         level_spawened;
   int                         level_score;
   int                         victory_kills;
   int                         victory_spawened;
   int                         victory_score;
   int                         level_end_count;
   int                         level_end_time_out;
   bool                        level_end_time;
   int                         level_end_phase;
   bool                        level_end_display_active;
   bool                        level_end_display_alpha;
   bool                        level_end_display_count;
   bool                        powerups_spawened;
   bool                        completed;
   float                       speed;
   int                         fw_rof_count;
   int                         sw_rof_count;
   int                         coin_spawn_rate;
   int                         wexp_spawn_rate;
   int                         npc_spawn_rate;
   int                         npc_spawn_rate_count;
   int                         npc_projectile_spawn_rate;
   wave_class                  wave[MAX_WAVES];
   player_class                player;
   supportship_class           supportship[MAX_SUPPORTSHIPS];
   enemy_type                  enemy[MAX_ENEMYS];
   npc_type                    npc[MAX_NPCS];
   projectile_class            projectile[MAX_PROJECTILES];
   shield_class                shield[MAX_SHIELDS];
   thruster_class              thruster[MAX_THRUSTERS];
   explosion_class             explosion[MAX_EXPLOSIONS];
   powerup_type                powerup[MAX_POWERUPS];
   coin_type                   coin[MAX_COINS];
   wexp_type                   wexp[MAX_WEXPS];
   int                         active_npc_count;
   active_npc_type             active_npc[MAX_NPCS];
   achivement_type             achivement;
   in_game_message_class       paused;
   in_game_message_class       loaded;
   in_game_message_class       saved;
   in_game_message_class       a_score;
   in_game_message_class       a_kills;
   in_game_message_class       p_actinium_shields;
   in_game_message_class       p_blasters;
   in_game_message_class       p_burst_lasers;
   in_game_message_class       p_chain_guns;
   in_game_message_class       p_convolution_thrusters;
   in_game_message_class       p_health;
   in_game_message_class       p_ion_cannons;
   in_game_message_class       p_iridium_shileds;
   in_game_message_class       p_maelstrom_thrusters;
   in_game_message_class       p_plasma_rockets;
   in_game_message_class       p_rail_turrets;
   in_game_message_class       p_rubidium_shields;
   in_game_message_class       p_seismic_thrusters;
   in_game_message_class       p_shield_level_up;
   in_game_message_class       p_tantalum_shields;
   in_game_message_class       p_terbium_shields;
   in_game_message_class       p_thrusters_level_up;
   in_game_message_class       p_vortex_thrusters;
   in_game_message_class       p_weapon_level_up;
   in_game_message_class       d_level_end;
};

int   init_game           (bool re_init);
int   process_game        (void);
int   display_game        (void);

bool  boss_level(void);

#endif //GAME_H
