/**
 * Copyright (C) 2011 Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
 * This file is part of R.A.G.E. (RoboPaul's Adaptable Game Engine)
 *
 * R.A.G.E. (RoboPaul's Adaptable Game Engine) is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * R.A.G.E. (RoboPaul's Adaptable Game Engine) is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with R.A.G.E. (RoboPaul's Adaptable Game Engine) If not, see <http://www.gnu.org/licenses/>.
 *
 * @author Paul Wortmann
 * @license GPL
 * @date 2011-07-17
 */

#include "save_data.hpp"
#include "RAGE/rage.hpp"
#include "game.hpp"

extern game_type      game_o;
       save_data_type save_data;

void update_save_data(void)
{
    int count;
    save_data.npc_damage_duration = game_o.npc_damage_duration;
    save_data.cheats_enabled = game_o.cheats_enabled;
    save_data.number_bombs = game_o.number_bombs;
    save_data.bomb_delay = game_o.bomb_delay;
    save_data.bomb_delay_count = game_o.bomb_delay_count;
    save_data.immune = game_o.immune;
    save_data.immunity_state = game_o.immunity_state;
    save_data.immunity_delay = game_o.immunity_delay;
    save_data.immunity_delay_count = game_o.immunity_delay_count;
    save_data.anc_enabled = game_o.anc_enabled;
    save_data.fps_enabled = game_o.fps_enabled;
    save_data.game_paused = game_o.game_paused;
    save_data.game_active = game_o.game_active;
    save_data.game_resume = game_o.game_resume;
    save_data.menu_active = game_o.menu_active;
    save_data.pdie_active = game_o.pdie_active;
    save_data.nlvl_active = game_o.nlvl_active;
    save_data.outr_active = game_o.outr_active;
    save_data.status_quit_active = game_o.status_quit_active;
    save_data.exp_rate = game_o.exp_rate;
    save_data.level = game_o.level;
    save_data.level_waves = game_o.level_waves;
    save_data.wave_spawnable = game_o.wave_spawnable;
    save_data.level_npc_type = game_o.level_npc_type;
    save_data.level_boss_level = game_o.level_boss_level;
    save_data.score = game_o.score;
    save_data.kills = game_o.kills;
    save_data.level_kills = game_o.level_kills;
    save_data.level_spawened = game_o.level_spawened;
    save_data.level_score = game_o.level_score;
    save_data.victory_kills = game_o.victory_kills;
    save_data.victory_spawened = game_o.victory_spawened;
    save_data.victory_score = game_o.victory_score;
    save_data.level_end_count = game_o.level_end_count;
    save_data.level_end_time_out = game_o.level_end_time_out;
    save_data.level_end_time = game_o.level_end_time;
    save_data.level_end_phase = game_o.level_end_phase;
    save_data.level_end_display_active = game_o.level_end_display_active;
    save_data.level_end_display_alpha = game_o.level_end_display_alpha;
    save_data.level_end_display_count = game_o.level_end_display_count;
    save_data.powerups_spawened = game_o.powerups_spawened;
    save_data.completed = game_o.completed;
    save_data.speed = game_o.speed;
    save_data.fw_rof_count = game_o.fw_rof_count;
    save_data.sw_rof_count = game_o.sw_rof_count;
    save_data.coin_spawn_rate = game_o.coin_spawn_rate;
    save_data.wexp_spawn_rate = game_o.wexp_spawn_rate;
    save_data.npc_spawn_rate = game_o.npc_spawn_rate;
    save_data.npc_spawn_rate_count = game_o.npc_spawn_rate_count;
    save_data.npc_projectile_spawn_rate = game_o.npc_projectile_spawn_rate;
    save_data.player = game_o.player;
    save_data.active_npc_count = game_o.active_npc_count;
    save_data.achivement = game_o.achivement;
    for (count = 0; count < MAX_LEVELS; count++)
    {
        save_data.level_locked[count] = game_o.level_locked[count];
    }
    for (count = 0; count < MAX_WAVES; count++)
    {
        save_data.wave[count] = game_o.wave[count];
    }
    for (count = 0; count < MAX_SIDESHIPS; count++)
    {
        save_data.sideship[count] = game_o.sideship[count];
    }
    for (count = 0; count < MAX_ENEMYS; count++)
    {
        save_data.enemy[count] = game_o.enemy[count];
    }
    for (count = 0; count < MAX_NPCS; count++)
    {
        save_data.npc[count] = game_o.npc[count];
    }
    for (count = 0; count < MAX_PROJECTILES; count++)
    {
        save_data.projectile[count] = game_o.projectile[count];
    }
    for (count = 0; count < MAX_SHIELDS; count++)
    {
        save_data.shield[count] = game_o.shield[count];
    }
    for (count = 0; count < MAX_THRUSTERS; count++)
    {
        save_data.thruster[count] = game_o.thruster[count];
    }
    for (count = 0; count < MAX_EXPLOSIONS; count++)
    {
        save_data.explosion[count] = game_o.explosion[count];
    }
    for (count = 0; count < MAX_BACKGROUNDS; count++)
    {
        save_data.background_scroll[count] = game_o.background_scroll[count];
    }
    for (count = 0; count < MAX_POWERUPS; count++)
    {
        save_data.powerup[count] = game_o.powerup[count];
    }
    for (count = 0; count < MAX_COINS; count++)
    {
        save_data.coin[count] = game_o.coin[count];
    }
    for (count = 0; count < MAX_WEXPS; count++)
    {
        save_data.wexp[count] = game_o.wexp[count];
    }
    for (count = 0; count < MAX_NPCS; count++)
    {
        save_data.active_npc[count] = game_o.active_npc[count];
    }
    save_data.save_version = 1;
};

void update_game_data(void)
{
    int count;
    game_o.npc_damage_duration = save_data.npc_damage_duration;
    game_o.cheats_enabled = save_data.cheats_enabled;
    game_o.number_bombs = save_data.number_bombs;
    game_o.bomb_delay = save_data.bomb_delay;
    game_o.bomb_delay_count = save_data.bomb_delay_count;
    game_o.immune = save_data.immune;
    game_o.immunity_state = save_data.immunity_state;
    game_o.immunity_delay = save_data.immunity_delay;
    game_o.immunity_delay_count = save_data.immunity_delay_count;
    game_o.anc_enabled = save_data.anc_enabled;
    game_o.fps_enabled = save_data.fps_enabled;
    game_o.game_paused = save_data.game_paused;
    game_o.game_active = save_data.game_active;
    game_o.game_resume = save_data.game_resume;
    game_o.menu_active = save_data.menu_active;
    game_o.pdie_active = save_data.pdie_active;
    game_o.nlvl_active = save_data.nlvl_active;
    game_o.outr_active = save_data.outr_active;
    game_o.status_quit_active = save_data.status_quit_active;
    game_o.exp_rate = save_data.exp_rate;
    game_o.level = save_data.level;
    game_o.level_waves = save_data.level_waves;
    game_o.wave_spawnable = save_data.wave_spawnable;
    game_o.level_npc_type = save_data.level_npc_type;
    game_o.level_boss_level = save_data.level_boss_level;
    game_o.score = save_data.score;
    game_o.kills = save_data.kills;
    game_o.level_kills = save_data.level_kills;
    game_o.level_spawened = save_data.level_spawened;
    game_o.level_score = save_data.level_score;
    game_o.victory_kills = save_data.victory_kills;
    game_o.victory_spawened = save_data.victory_spawened;
    game_o.victory_score = save_data.victory_score;
    game_o.level_end_count = save_data.level_end_count;
    game_o.level_end_time_out = save_data.level_end_time_out;
    game_o.level_end_time = save_data.level_end_time;
    game_o.level_end_phase = save_data.level_end_phase;
    game_o.level_end_display_active = save_data.level_end_display_active;
    game_o.level_end_display_alpha = save_data.level_end_display_alpha;
    game_o.level_end_display_count = save_data.level_end_display_count;
    game_o.powerups_spawened = save_data.powerups_spawened;
    game_o.completed = save_data.completed;
    game_o.speed = save_data.speed;
    game_o.fw_rof_count = save_data.fw_rof_count;
    game_o.sw_rof_count = save_data.sw_rof_count;
    game_o.coin_spawn_rate = save_data.coin_spawn_rate;
    game_o.wexp_spawn_rate = save_data.wexp_spawn_rate;
    game_o.npc_spawn_rate = save_data.npc_spawn_rate;
    game_o.npc_spawn_rate_count = save_data.npc_spawn_rate_count;
    game_o.npc_projectile_spawn_rate = save_data.npc_projectile_spawn_rate;
    game_o.player = save_data.player;
    game_o.active_npc_count = save_data.active_npc_count;
    game_o.achivement = save_data.achivement;
    for (count = 0; count < MAX_LEVELS; count++)
    {
        game_o.level_locked[count] = save_data.level_locked[count];
    }
    for (count = 0; count < MAX_WAVES; count++)
    {
        game_o.wave[count] = save_data.wave[count];
    }
    for (count = 0; count < MAX_SIDESHIPS; count++)
    {
        game_o.sideship[count] = save_data.sideship[count];
    }
    for (count = 0; count < MAX_ENEMYS; count++)
    {
        game_o.enemy[count] = save_data.enemy[count];
    }
    for (count = 0; count < MAX_NPCS; count++)
    {
        game_o.npc[count] = save_data.npc[count];
    }
    for (count = 0; count < MAX_PROJECTILES; count++)
    {
        game_o.projectile[count] = save_data.projectile[count];
    }
    for (count = 0; count < MAX_SHIELDS; count++)
    {
        game_o.shield[count] = save_data.shield[count];
    }
    for (count = 0; count < MAX_THRUSTERS; count++)
    {
        game_o.thruster[count] = save_data.thruster[count];
    }
    for (count = 0; count < MAX_EXPLOSIONS; count++)
    {
        game_o.explosion[count] = save_data.explosion[count];
    }
    for (count = 0; count < MAX_BACKGROUNDS; count++)
    {
        game_o.background_scroll[count] = save_data.background_scroll[count];
    }
    for (count = 0; count < MAX_POWERUPS; count++)
    {
        game_o.powerup[count] = save_data.powerup[count];
    }
    for (count = 0; count < MAX_COINS; count++)
    {
        game_o.coin[count] = save_data.coin[count];
    }
    for (count = 0; count < MAX_WEXPS; count++)
    {
        game_o.wexp[count] = save_data.wexp[count];
    }
    for (count = 0; count < MAX_NPCS; count++)
    {
        game_o.active_npc[count] = save_data.active_npc[count];
    }
    save_data.save_version = 1;
};





