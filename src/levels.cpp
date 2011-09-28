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
 * @date    2011-09-03
 */

#include "load_resources.hpp"
#include "RAGE/rage.hpp"
#include "levels.hpp"
#include "game.hpp"

extern game_type     game_o;
extern game_class    game;
extern texture_type  texture;

void init_levels(void)
{
    for (int level_no_count = 0;level_no_count < (MAX_LEVELS+1); level_no_count++)
    {
        game_o.level_locked[level_no_count] = false;/// set to false to unlock all levels....for testing!
    }
    game_o.level_locked[0] = false;
};

int unlock_levels(void)
{
   for (int level_no_count = 0;level_no_count < (MAX_LEVELS+1); level_no_count++)
   {
      game_o.level_locked[level_no_count] = false;
   }
   return(1);
}

int init_game_level(int level_no)
{
    game_o.level_end_rumble                  = true;
    game_o.bomb_delay_count                  = 0;
    game_o.immune                            = true;
    game_o.immunity_state                    = 0;
    game_o.immunity_delay_count              = 0;
    game_o.immune                            = true;
    game_o.level_end_time                    = false;
    game_o.level_end_count                   = 0;
    game_o.level_end_phase                   = 0;
    game_o.level_end_display_active          = false;
    game_o.powerups_spawened                 = false;
    game_o.level_kills                       = 0;
    game_o.level_spawened                    = 0;
    game_o.level_score                       = 0;
    game_o.active_npc_count                  = 0;
    game_o.player.x_pos                      =-0.9f+thruster_offset();
    game_o.player.y_pos                      = 0.0f;
    game_o.player.x_dir                      = 0.0f;
    game_o.player.y_dir                      = 0.0f;
    game_o.player.x_vel                      = 0.0f;
    game_o.player.y_vel                      = 0.0f;
    kill_active_npcs();
    init_npcs(0);
    init_active_npcs();
    kill_powerups();
    kill_coins();
    kill_wexps();
    kill_player_bullet();
    pos_supportships(game_o.player.x_pos,game_o.player.y_pos);
    kill_supportship_bullets();
    init_waves();
    game_o.wave[0].active = true;

    if (level_no == 0) // Taranis
    {
        game_o.level                             = level_no;
        game_o.level_npc_type                    = 0;
        game_o.level_boss_level                  = false;
        game.music_track                         = level_no;
        game_o.speed                             = 0.015f;
        game_o.npc_spawn_rate                    = 300;
        game_o.npc_spawn_rate_count              = 300;
        game_o.npc_projectile_spawn_rate         = 50;
        game_o.victory_kills                     = 128;
        game_o.victory_spawened                  = 1;
        game_o.victory_score                     = 0;
        game_o.wave[ 0].wave_size                = 0.25f;
        game_o.wave[ 0].npc_type                 = 0;
        game_o.wave[ 0].spawn_pattern            = 0;
        game_o.wave[ 1].npc_type                 = 0;
        game_o.wave[ 1].spawn_pattern            = 7;
        game_o.wave[ 2].npc_type                 = 0;
        game_o.wave[ 2].spawn_pattern            = 8;
        game_o.wave[ 3].npc_type                 = 0;
        game_o.wave[ 3].spawn_pattern            = 10;
        game_o.wave[ 4].npc_type                 = 0;
        game_o.wave[ 4].spawn_pattern            = 11;
        game_o.level_waves                       = 4;
        game.background.set_data ( 1, 1, 1, 0.0f, 0.0f, 0.0050f, 0.0050f, texture.background_001.ref_number);
        game.background.set_data ( 2, 1, 1, 4.0f, 0.0f, 0.0050f, 0.0050f, texture.background_001.ref_number);
        game.background.set_data ( 3, 1, 1, 0.0f, 0.0f, 0.0020f, 0.0020f, texture.background_031.ref_number);
        game.background.set_data ( 4, 1, 1, 4.0f, 0.0f, 0.0020f, 0.0020f, texture.background_031.ref_number);
    }
   if (level_no == 1) // Teutates
   {
        game_o.level                             = level_no;
        game_o.level_npc_type                    = 1;
        game_o.level_boss_level                  = false;
        game.music_track                         = level_no;
        game_o.speed                             = 0.050f;
        game_o.npc_spawn_rate                    = 280;
        game_o.npc_spawn_rate_count              = 280;
        game_o.npc_projectile_spawn_rate         = 50;
        game_o.victory_kills                     = 128;
        game_o.victory_spawened                  = 0;
        game_o.victory_score                     = 0;
        game_o.wave[ 0].wave_size                = 0.25f;
        game_o.wave[ 0].npc_type                 = 0;
        game_o.wave[ 0].spawn_pattern            = 0;
        game_o.wave[ 1].npc_type                 = 1;
        game_o.wave[ 1].spawn_pattern            = 11;
        game_o.wave[ 2].npc_type                 = 0;
        game_o.wave[ 2].spawn_pattern            = 7;
        game_o.wave[ 3].npc_type                 = 1;
        game_o.wave[ 3].spawn_pattern            = 10;
        game_o.wave[ 4].npc_type                 = 0;
        game_o.wave[ 4].spawn_pattern            = 8;
        game_o.wave[ 5].npc_type                 = 1;
        game_o.wave[ 5].spawn_pattern            = 8;
        game_o.wave[ 6].npc_type                 = 0;
        game_o.wave[ 6].spawn_pattern            = 10;
        game_o.wave[ 7].npc_type                 = 1;
        game_o.wave[ 7].spawn_pattern            = 7;
        game_o.wave[ 8].npc_type                 = 0;
        game_o.wave[ 8].spawn_pattern            = 11;
        game_o.level_waves                       = 8;
        game.background.set_data ( 1, 1, 1, 0.0f, 0.0f, 0.0050f, 0.0050f, texture.background_001.ref_number);
        game.background.set_data ( 2, 1, 1, 4.0f, 0.0f, 0.0050f, 0.0050f, texture.background_001.ref_number);
        game.background.set_data ( 3, 1, 1, 0.0f, 0.0f, 0.0020f, 0.0020f, texture.background_030.ref_number);
        game.background.set_data ( 4, 1, 1, 4.0f, 0.0f, 0.0020f, 0.0020f, texture.background_030.ref_number);
   }
   if (level_no == 2) // Esus
   {
        game_o.level                             = level_no;
        game_o.level_npc_type                    = 2;
        game_o.level_boss_level                  = false;
        game.music_track                         = level_no;
        game_o.speed                             = 0.055f;
        game_o.npc_spawn_rate                    = 270;
        game_o.npc_spawn_rate_count              = 270;
        game_o.npc_projectile_spawn_rate         = 50;
        game_o.victory_kills                     = 256;
        game_o.victory_spawened                  = 0;
        game_o.victory_score                     = 0;
        game_o.wave[ 0].wave_size                = 0.25f;
        game_o.wave[ 0].npc_type                 = 0;
        game_o.wave[ 0].spawn_pattern            = 0;
        game_o.wave[ 1].npc_type                 = 1;
        game_o.wave[ 1].spawn_pattern            = 11;
        game_o.wave[ 2].npc_type                 = 2;
        game_o.wave[ 2].spawn_pattern            = 2;
        game_o.wave[ 3].npc_type                 = 0;
        game_o.wave[ 3].spawn_pattern            = 7;
        game_o.wave[ 4].npc_type                 = 1;
        game_o.wave[ 4].spawn_pattern            = 10;
        game_o.wave[ 5].npc_type                 = 2;
        game_o.wave[ 5].spawn_pattern            = 7;
        game_o.wave[ 6].npc_type                 = 0;
        game_o.wave[ 6].spawn_pattern            = 8;
        game_o.wave[ 7].npc_type                 = 1;
        game_o.wave[ 7].spawn_pattern            = 8;
        game_o.wave[ 8].npc_type                 = 2;
        game_o.wave[ 8].spawn_pattern            = 11;
        game_o.wave[ 9].npc_type                 = 0;
        game_o.wave[ 9].spawn_pattern            = 10;
        game_o.wave[10].npc_type                 = 1;
        game_o.wave[10].spawn_pattern            = 7;
        game_o.wave[11].npc_type                 = 2;
        game_o.wave[11].spawn_pattern            = 10;
        game_o.wave[12].npc_type                 = 0;
        game_o.wave[12].spawn_pattern            = 11;
        game_o.level_waves                       = 12;
        game.background.set_data ( 1, 1, 1, 0.0f, 0.0f, 0.0050f, 0.0050f, texture.background_001.ref_number);
        game.background.set_data ( 2, 1, 1, 4.0f, 0.0f, 0.0050f, 0.0050f, texture.background_001.ref_number);
        game.background.set_data ( 3, 1, 1, 0.0f, 0.0f, 0.0020f, 0.0020f, texture.background_029.ref_number);
        game.background.set_data ( 4, 1, 1, 4.0f, 0.0f, 0.0020f, 0.0020f, texture.background_029.ref_number);
   }
   if (level_no == 3) // Cantidious - BOSS 1
   {
        game_o.level                             = level_no;
        game_o.level_npc_type                    = 3;
        game_o.level_boss_level                  = true;
        game.music_track                         = level_no;
        game_o.speed                             = 0.060f;
        game_o.npc_spawn_rate                    = 1;
        game_o.npc_spawn_rate_count              = 1;
        game_o.npc_projectile_spawn_rate         = 10;
        game_o.victory_kills                     = 1;
        game_o.victory_spawened                  = 0;
        game_o.victory_score                     = 0;
        game.background.set_data ( 1, 1, 1, 0.0f, 0.0f, 0.0050f, 0.0050f, texture.background_000.ref_number);
        game.background.set_data ( 2, 1, 1, 4.0f, 0.0f, 0.0050f, 0.0050f, texture.background_000.ref_number);
        game.background.set_data ( 3, 1, 1, 0.0f, 0.0f, 0.0020f, 0.0020f, texture.background_029.ref_number);
        game.background.set_data ( 4, 1, 1, 4.0f, 0.0f, 0.0020f, 0.0020f, texture.background_029.ref_number);
   } /// add / balance game below !!!
   if (level_no == 4) // Vulcan
   {
      game_o.level                             = level_no;
      game_o.level_npc_type                    = 4;
      game_o.level_boss_level                  = false;
      game.music_track                         = level_no;
        game.background.set_data ( 1, 1, 1, 0.0f, 0.0f, 0.0050f, 0.0050f, texture.background_002.ref_number);
        game.background.set_data ( 2, 1, 1, 4.0f, 0.0f, 0.0050f, 0.0050f, texture.background_002.ref_number);
        game.background.set_data ( 3, 1, 1, 0.0f, 0.0f, 0.0020f, 0.0020f, texture.background_028.ref_number);
        game.background.set_data ( 4, 1, 1, 4.0f, 0.0f, 0.0020f, 0.0020f, texture.background_028.ref_number);
      game_o.speed                             = 0.065f;
      game_o.npc_spawn_rate                    = 480;
      game_o.npc_spawn_rate_count              = 480;
      game_o.npc_projectile_spawn_rate         = 270;
      game_o.victory_kills                     = 128;
      game_o.victory_spawened                  = 0;
      game_o.victory_score                     = 0;
      game_o.wave[0].wave_size                 = 0.5f;
      game_o.wave[0].npc_type                  = 4;
      game_o.wave[0].spawn_pattern             = 0;
      game_o.wave[1].wave_size                 = 0.45f;
      game_o.wave[1].npc_type                  = 4;
      game_o.wave[1].spawn_pattern             = 8;
      game_o.level_waves                       = 1;
   }
   if (level_no == 5) // Bacchus
   {
      game_o.level                             = level_no;
      game_o.level_npc_type                    = 5;
      game_o.level_boss_level                  = false;
      game.music_track                         = level_no;
        game.background.set_data ( 1, 1, 1, 0.0f, 0.0f, 0.0050f, 0.0050f, texture.background_002.ref_number);
        game.background.set_data ( 2, 1, 1, 4.0f, 0.0f, 0.0050f, 0.0050f, texture.background_002.ref_number);
        game.background.set_data ( 3, 1, 1, 0.0f, 0.0f, 0.0020f, 0.0020f, texture.background_027.ref_number);
        game.background.set_data ( 4, 1, 1, 4.0f, 0.0f, 0.0020f, 0.0020f, texture.background_027.ref_number);
      game_o.speed                             = 0.070f;
      game_o.npc_spawn_rate                    = 460;
      game_o.npc_spawn_rate_count              = 460;
      game_o.npc_projectile_spawn_rate         = 225;
      game_o.victory_kills                     = 128;
      game_o.victory_spawened                  = 0;
      game_o.victory_score                     = 0;
      game_o.wave[0].wave_size                 = 0.3f;
      game_o.wave[0].npc_type                  = 4;
      game_o.wave[0].spawn_pattern             = 4;
      game_o.wave[1].npc_type                  = 5;
      game_o.wave[1].spawn_pattern             = 5;
      game_o.level_waves                       = 1;
   }
   if (level_no == 6) // Janus
   {
      game_o.level                             = level_no;
      game_o.level_npc_type                    = 6;
      game_o.level_boss_level                  = false;
      game.music_track                         = level_no;
        game.background.set_data ( 1, 1, 1, 0.0f, 0.0f, 0.0050f, 0.0050f, texture.background_002.ref_number);
        game.background.set_data ( 2, 1, 1, 4.0f, 0.0f, 0.0050f, 0.0050f, texture.background_002.ref_number);
        game.background.set_data ( 3, 1, 1, 0.0f, 0.0f, 0.0020f, 0.0020f, texture.background_026.ref_number);
        game.background.set_data ( 4, 1, 1, 4.0f, 0.0f, 0.0020f, 0.0020f, texture.background_026.ref_number);
      game_o.speed                             = 0.075f;
      game_o.npc_spawn_rate                    = 420;
      game_o.npc_spawn_rate_count              = 420;
      game_o.npc_projectile_spawn_rate         = 250;
      game_o.victory_kills                     = 256;
      game_o.victory_spawened                  = 0;
      game_o.victory_score                     = 0;
      game_o.wave[0].npc_type                  = 6;
      game_o.wave[0].spawn_pattern             = 6;
      game_o.wave[1].wave_size                 = 0.25f;
      game_o.wave[1].npc_type                  = 4;
      game_o.wave[1].spawn_pattern             = 4;
      game_o.wave[2].npc_type                  = 5;
      game_o.wave[2].spawn_pattern             = 5;
      game_o.level_waves                       = 2;
   }
   if (level_no == 7) // Wrathorn - BOSS 2
   {
      game_o.level                             = level_no;
      game_o.level_npc_type                    = 7;
      game_o.level_boss_level                  = true;
      game.music_track                         = level_no;
        game.background.set_data ( 1, 1, 1, 0.0f, 0.0f, 0.0050f, 0.0050f, texture.menu_background_001.ref_number);
        game.background.set_data ( 2, 1, 1, 4.0f, 0.0f, 0.0050f, 0.0050f, texture.menu_background_001.ref_number);
        game.background.set_data ( 3, 1, 1, 0.0f, 0.0f, 0.0020f, 0.0020f, texture.background_026.ref_number);
        game.background.set_data ( 4, 1, 1, 4.0f, 0.0f, 0.0020f, 0.0020f, texture.background_026.ref_number);
      game_o.speed                             = 0.080f;
      game_o.npc_spawn_rate                    = 1;
      game_o.npc_spawn_rate_count              = 1;
      game_o.npc_projectile_spawn_rate         = 16;
      game_o.victory_kills                     = 1;
      game_o.victory_spawened                  = 0;
      game_o.victory_score                     = 0;
   }
   if (level_no == 8) // Tartarus
   {
      game_o.level                             = level_no;
      game_o.level_npc_type                    = 8;
      game_o.level_boss_level                  = false;
      game.music_track                         = level_no;
        game.background.set_data ( 1, 1, 1, 0.0f, 0.0f, 0.0050f, 0.0050f, texture.background_003.ref_number);
        game.background.set_data ( 2, 1, 1, 4.0f, 0.0f, 0.0050f, 0.0050f, texture.background_003.ref_number);
        game.background.set_data ( 3, 1, 1, 0.0f, 0.0f, 0.0020f, 0.0020f, texture.background_024.ref_number);
        game.background.set_data ( 4, 1, 1, 4.0f, 0.0f, 0.0020f, 0.0020f, texture.background_024.ref_number);
      game_o.speed                             = 0.085f;
      game_o.npc_spawn_rate                    = 250;
      game_o.npc_spawn_rate_count              = 250;
      game_o.npc_projectile_spawn_rate         = 150;
      game_o.victory_kills                     = 128;
      game_o.victory_spawened                  = 0;
      game_o.victory_score                     = 0;
      game_o.wave[0].npc_type                  = 8;
      game_o.wave[0].spawn_pattern             = 4;
      game_o.level_waves                       = 0;
   }
   if (level_no == 9) // Erebus
   {
      game_o.level                             = level_no;
      game_o.level_npc_type                    = 9;
      game_o.level_boss_level                  = false;
      game.music_track                         = level_no;
        game.background.set_data ( 1, 1, 1, 0.0f, 0.0f, 0.0050f, 0.0050f, texture.background_003.ref_number);
        game.background.set_data ( 2, 1, 1, 4.0f, 0.0f, 0.0050f, 0.0050f, texture.background_003.ref_number);
        game.background.set_data ( 3, 1, 1, 0.0f, 0.0f, 0.0020f, 0.0020f, texture.background_023.ref_number);
        game.background.set_data ( 4, 1, 1, 4.0f, 0.0f, 0.0020f, 0.0020f, texture.background_023.ref_number);
      game_o.speed                             = 0.090f;
      game_o.npc_spawn_rate                    = 250;
      game_o.npc_spawn_rate_count              = 250;
      game_o.npc_projectile_spawn_rate         = 150;
      game_o.victory_kills                     = 128;
      game_o.victory_spawened                  = 0;
      game_o.victory_score                     = 0;
      game_o.wave[0].npc_type                  = 9;
      game_o.wave[0].spawn_pattern             = 6;
      game_o.wave[1].npc_type                  = 8;
      game_o.wave[1].spawn_pattern             = 7;
      game_o.wave[2].npc_type                  = 9;
      game_o.wave[2].spawn_pattern             = 8;
      game_o.wave[3].npc_type                  = 8;
      game_o.wave[3].spawn_pattern             = 7;
      game_o.wave[4].npc_type                  = 9;
      game_o.wave[4].spawn_pattern             = 7;
      game_o.level_waves                       = 4;
   }
   if (level_no == 10) // Nyx
   {
      game_o.level                             = level_no;
      game_o.level_npc_type                    = 10;
      game_o.level_boss_level                  = false;
      game.music_track                         = level_no;
        game.background.set_data ( 1, 1, 1, 0.0f, 0.0f, 0.0050f, 0.0050f, texture.background_003.ref_number);
        game.background.set_data ( 2, 1, 1, 4.0f, 0.0f, 0.0050f, 0.0050f, texture.background_003.ref_number);
        game.background.set_data ( 3, 1, 1, 0.0f, 0.0f, 0.0020f, 0.0020f, texture.background_022.ref_number);
        game.background.set_data ( 4, 1, 1, 4.0f, 0.0f, 0.0020f, 0.0020f, texture.background_022.ref_number);
      game_o.speed                             = 0.095f;
      game_o.npc_spawn_rate                    = 320;
      game_o.npc_spawn_rate_count              = 320;
      game_o.npc_projectile_spawn_rate         = 125;
      game_o.victory_kills                     = 256;
      game_o.victory_spawened                  = 0;
      game_o.victory_score                     = 0;
      game_o.wave[0].wave_size                 = 0.15f;
      game_o.wave[0].npc_type                  = 10;
      game_o.wave[0].spawn_pattern             = 4;
      game_o.wave[1].npc_type                  = 9;
      game_o.wave[1].spawn_pattern             = 6;
      game_o.wave[2].npc_type                  = 8;
      game_o.wave[2].spawn_pattern             = 7;
      game_o.level_waves                       = 2;
   }
   if (level_no == 11) // Dediun - BOSS 3
   {
      game_o.level                             = level_no;
      game_o.level_npc_type                    = 11;
      game_o.level_boss_level                  = true;
      game.music_track                         = level_no;
        game.background.set_data ( 1, 1, 1, 0.0f, 0.0f, 0.0050f, 0.0050f, texture.background_000.ref_number);
        game.background.set_data ( 2, 1, 1, 4.0f, 0.0f, 0.0050f, 0.0050f, texture.background_000.ref_number);
        game.background.set_data ( 3, 1, 1, 0.0f, 0.0f, 0.0020f, 0.0020f, texture.background_022.ref_number);
        game.background.set_data ( 4, 1, 1, 4.0f, 0.0f, 0.0020f, 0.0020f, texture.background_022.ref_number);
      game_o.speed                             = 0.100f;
      game_o.npc_spawn_rate                    = 1;
      game_o.npc_spawn_rate_count              = 1;
      game_o.npc_projectile_spawn_rate         = 15;
      game_o.victory_kills                     = 1;
      game_o.victory_spawened                  = 0;
      game_o.victory_score                     = 0;
   }
   if (level_no == 12) // Niflheim
   {
      game_o.level                             = level_no;
      game_o.level_npc_type                    = 12;
      game_o.level_boss_level                  = false;
      game.music_track                         = level_no;
        game.background.set_data ( 1, 1, 1, 0.0f, 0.0f, 0.0050f, 0.0050f, texture.background_004.ref_number);
        game.background.set_data ( 2, 1, 1, 4.0f, 0.0f, 0.0050f, 0.0050f, texture.background_004.ref_number);
        game.background.set_data ( 3, 1, 1, 0.0f, 0.0f, 0.0020f, 0.0020f, texture.background_021.ref_number);
        game.background.set_data ( 4, 1, 1, 4.0f, 0.0f, 0.0020f, 0.0020f, texture.background_021.ref_number);
      game_o.speed                             = 0.105f;
      game_o.npc_spawn_rate                    = 280;
      game_o.npc_spawn_rate_count              = 280;
      game_o.npc_projectile_spawn_rate         = 75;
      game_o.victory_kills                     = 128;
      game_o.victory_spawened                  = 0;
      game_o.victory_score                     = 0;
      game_o.wave[0].npc_type                  = 12;
      game_o.wave[0].spawn_pattern             = 7;
      game_o.wave[0].wave_size                 = 0.25f;
      game_o.level_waves                       = 0;
   }
   if (level_no == 13) // Muspelhiem
   {
      game_o.level                             = level_no;
      game_o.level_npc_type                    = 13;
      game_o.level_boss_level                  = false;
      game.music_track                         = level_no;
        game.background.set_data ( 1, 1, 1, 0.0f, 0.0f, 0.0050f, 0.0050f, texture.background_004.ref_number);
        game.background.set_data ( 2, 1, 1, 4.0f, 0.0f, 0.0050f, 0.0050f, texture.background_004.ref_number);
        game.background.set_data ( 3, 1, 1, 0.0f, 0.0f, 0.0020f, 0.0020f, texture.background_020.ref_number);
        game.background.set_data ( 4, 1, 1, 4.0f, 0.0f, 0.0020f, 0.0020f, texture.background_020.ref_number);
      game_o.speed                             = 0.110f;
      game_o.npc_spawn_rate                    = 420;
      game_o.npc_spawn_rate_count              = 420;
      game_o.npc_projectile_spawn_rate         = 150;
      game_o.victory_kills                     = 128;
      game_o.victory_spawened                  = 0;
      game_o.victory_score                     = 0;
      game_o.wave[0].npc_type                  = 13;
      game_o.wave[0].spawn_pattern             = 0;
      game_o.wave[1].npc_type                  = 12;
      game_o.wave[1].spawn_pattern             = 1;
      game_o.level_waves                       = 1;
   }
   if (level_no == 14) // Hel
   {
      game_o.level                             = level_no;
      game_o.level_npc_type                    = 14;
      game_o.level_boss_level                  = false;
      game.music_track                         = level_no;
        game.background.set_data ( 1, 1, 1, 0.0f, 0.0f, 0.0050f, 0.0050f, texture.background_004.ref_number);
        game.background.set_data ( 2, 1, 1, 4.0f, 0.0f, 0.0050f, 0.0050f, texture.background_004.ref_number);
        game.background.set_data ( 3, 1, 1, 0.0f, 0.0f, 0.0020f, 0.0020f, texture.background_019.ref_number);
        game.background.set_data ( 4, 1, 1, 4.0f, 0.0f, 0.0020f, 0.0020f, texture.background_019.ref_number);
      game_o.speed                             = 0.115f;
      game_o.npc_spawn_rate                    = 320;
      game_o.npc_spawn_rate_count              = 320;
      game_o.npc_projectile_spawn_rate         = 150;
      game_o.victory_kills                     = 256;
      game_o.victory_spawened                  = 0;
      game_o.victory_score                     = 0;
      game_o.wave[0].wave_size                 = 0.25f;
      game_o.wave[0].npc_type                  = 14;
      game_o.wave[0].spawn_pattern             = 4;
      game_o.wave[1].npc_type                  = 13;
      game_o.wave[1].spawn_pattern             = 0;
      game_o.wave[2].wave_size                 = 0.35f;
      game_o.wave[2].npc_type                  = 14;
      game_o.wave[2].spawn_pattern             = 4;
      game_o.wave[3].npc_type                  = 12;
      game_o.wave[3].spawn_pattern             = 1;
      game_o.level_waves                       = 3;
   }
   if (level_no == 15) // Paganite - BOSS 4
   {
      game_o.level                             = level_no;
      game_o.level_npc_type                    = 15;
      game_o.level_boss_level                  = true;
      game.music_track                         = level_no;
        game.background.set_data ( 1, 1, 1, 0.0f, 0.0f, 0.0050f, 0.0050f, texture.background_000.ref_number);
        game.background.set_data ( 2, 1, 1, 4.0f, 0.0f, 0.0050f, 0.0050f, texture.background_000.ref_number);
        game.background.set_data ( 3, 1, 1, 0.0f, 0.0f, 0.0020f, 0.0020f, texture.background_018.ref_number);
        game.background.set_data ( 4, 1, 1, 4.0f, 0.0f, 0.0020f, 0.0020f, texture.background_018.ref_number);
      game_o.speed                             = 0.120f;
      game_o.npc_spawn_rate                    = 1;
      game_o.npc_spawn_rate_count              = 1;
      game_o.npc_projectile_spawn_rate         = 15;
      game_o.victory_kills                     = 1;
      game_o.victory_spawened                  = 0;
      game_o.victory_score                     = 0;
   }
   if (level_no == 16) // Pixiu
   {
      game_o.level                             = level_no;
      game_o.level_npc_type                    = 16;
      game_o.level_boss_level                  = false;
      game.music_track                         = level_no;
        game.background.set_data ( 1, 1, 1, 0.0f, 0.0f, 0.0050f, 0.0050f, texture.background_005.ref_number);
        game.background.set_data ( 2, 1, 1, 4.0f, 0.0f, 0.0050f, 0.0050f, texture.background_005.ref_number);
        game.background.set_data ( 3, 1, 1, 0.0f, 0.0f, 0.0020f, 0.0020f, texture.background_017.ref_number);
        game.background.set_data ( 4, 1, 1, 4.0f, 0.0f, 0.0020f, 0.0020f, texture.background_017.ref_number);
      game_o.speed                             = 0.125f;
      game_o.npc_spawn_rate                    = 220;
      game_o.npc_spawn_rate_count              = 220;
      game_o.npc_projectile_spawn_rate         = 150;
      game_o.victory_kills                     = 128;
      game_o.victory_spawened                  = 0;
      game_o.victory_score                     = 0;
      game_o.wave[0].wave_size                 = 0.45f;
      game_o.wave[0].npc_type                  = 16;
      game_o.wave[0].spawn_pattern             = 8;
      game_o.level_waves                       = 0;
   }
   if (level_no == 17) // Xiao
   {
      game_o.level                             = level_no;
      game_o.level_npc_type                    = 17;
      game_o.level_boss_level                  = false;
      game.music_track                         = level_no;
        game.background.set_data ( 1, 1, 1, 0.0f, 0.0f, 0.0050f, 0.0050f, texture.background_005.ref_number);
        game.background.set_data ( 2, 1, 1, 4.0f, 0.0f, 0.0050f, 0.0050f, texture.background_005.ref_number);
        game.background.set_data ( 3, 1, 1, 0.0f, 0.0f, 0.0020f, 0.0020f, texture.background_016.ref_number);
        game.background.set_data ( 4, 1, 1, 4.0f, 0.0f, 0.0020f, 0.0020f, texture.background_016.ref_number);
      game_o.speed                             = 0.130f;
      game_o.npc_spawn_rate                    = 220;
      game_o.npc_spawn_rate_count              = 220;
      game_o.npc_projectile_spawn_rate         = 150;
      game_o.victory_kills                     = 128;
      game_o.victory_spawened                  = 0;
      game_o.victory_score                     = 0;
      game_o.wave[0].npc_type                  = 17;
      game_o.wave[0].spawn_pattern             = 9;
      game_o.wave[1].wave_size                 = 0.25f;
      game_o.wave[1].npc_type                  = 16;
      game_o.wave[1].spawn_pattern             = 8;
      game_o.level_waves                       = 1;
   }
   if (level_no == 18) // Fuxi
   {
      game_o.level                             = level_no;
      game_o.level_npc_type                    = 18;
      game_o.level_boss_level                  = false;
      game.music_track                         = level_no;
        game.background.set_data ( 1, 1, 1, 0.0f, 0.0f, 0.0050f, 0.0050f, texture.background_005.ref_number);
        game.background.set_data ( 2, 1, 1, 4.0f, 0.0f, 0.0050f, 0.0050f, texture.background_005.ref_number);
        game.background.set_data ( 3, 1, 1, 0.0f, 0.0f, 0.0020f, 0.0020f, texture.background_015.ref_number);
        game.background.set_data ( 4, 1, 1, 4.0f, 0.0f, 0.0020f, 0.0020f, texture.background_015.ref_number);
      game_o.speed                             = 0.135f;
      game_o.npc_spawn_rate                    = 220;
      game_o.npc_spawn_rate_count              = 220;
      game_o.npc_projectile_spawn_rate         = 150;
      game_o.victory_kills                     = 258;
      game_o.victory_spawened                  = 0;
      game_o.victory_score                     = 0;
      game_o.wave[0].npc_type                  = 18;
      game_o.wave[0].spawn_pattern             = 9;
      game_o.wave[1].wave_size                 = 0.35f;
      game_o.wave[1].npc_type                  = 16;
      game_o.wave[1].spawn_pattern             = 10;
      game_o.wave[2].npc_type                  = 17;
      game_o.wave[2].spawn_pattern             = 11;
      game_o.level_waves                       = 2;
   }
   if (level_no == 19) // Haxorific - BOSS 5
   {
      game_o.level                             = level_no;
      game_o.level_npc_type                    = 19;
      game_o.level_boss_level                  = true;
      game.music_track                         = level_no;
        game.background.set_data ( 1, 1, 1, 0.0f, 0.0f, 0.0050f, 0.0050f, texture.background_005.ref_number);
        game.background.set_data ( 2, 1, 1, 4.0f, 0.0f, 0.0050f, 0.0050f, texture.background_005.ref_number);
        game.background.set_data ( 3, 1, 1, 0.0f, 0.0f, 0.0020f, 0.0020f, texture.background_014.ref_number);
        game.background.set_data ( 4, 1, 1, 4.0f, 0.0f, 0.0020f, 0.0020f, texture.background_014.ref_number);
      game_o.speed                             = 0.140f;
      game_o.npc_spawn_rate                    = 1;
      game_o.npc_spawn_rate_count              = 1;
      game_o.npc_projectile_spawn_rate         = 50;
      game_o.victory_kills                     = 1;
      game_o.victory_spawened                  = 0;
      game_o.victory_score                     = 0;
   }
   if (level_no == 20) // Byakko
   {
      game_o.level                             = level_no;
      game_o.level_npc_type                    = 20;
      game_o.level_boss_level                  = false;
      game.music_track                         = level_no;
        game.background.set_data ( 1, 1, 1, 0.0f, 0.0f, 0.0050f, 0.0050f, texture.background_006.ref_number);
        game.background.set_data ( 2, 1, 1, 4.0f, 0.0f, 0.0050f, 0.0050f, texture.background_006.ref_number);
        game.background.set_data ( 3, 1, 1, 0.0f, 0.0f, 0.0020f, 0.0020f, texture.background_013.ref_number);
        game.background.set_data ( 4, 1, 1, 4.0f, 0.0f, 0.0020f, 0.0020f, texture.background_013.ref_number);
      game_o.speed                             = 0.145f;
      game_o.npc_spawn_rate                    = 120;
      game_o.npc_spawn_rate_count              = 120;
      game_o.npc_projectile_spawn_rate         = 150;
      game_o.victory_kills                     = 128;
      game_o.victory_spawened                  = 0;
      game_o.victory_score                     = 0;
      game_o.wave[0].npc_type                  = 20;
      game_o.wave[0].spawn_pattern             = 4;
      game_o.wave[1].npc_type                  = 20;
      game_o.wave[1].spawn_pattern             = 7;
      game_o.level_waves                       = 1;
   }
   if (level_no == 21) // Enenra
   {
      game_o.level                             = level_no;
      game_o.level_npc_type                    = 21;
      game_o.level_boss_level                  = false;
      game.music_track                         = level_no;
        game.background.set_data ( 1, 1, 1, 0.0f, 0.0f, 0.0050f, 0.0050f, texture.background_006.ref_number);
        game.background.set_data ( 2, 1, 1, 4.0f, 0.0f, 0.0050f, 0.0050f, texture.background_006.ref_number);
        game.background.set_data ( 3, 1, 1, 0.0f, 0.0f, 0.0020f, 0.0020f, texture.background_012.ref_number);
        game.background.set_data ( 4, 1, 1, 4.0f, 0.0f, 0.0020f, 0.0020f, texture.background_012.ref_number);
      game_o.speed                             = 0.150f;
      game_o.npc_spawn_rate                    = 120;
      game_o.npc_spawn_rate_count              = 120;
      game_o.npc_projectile_spawn_rate         = 150;
      game_o.victory_kills                     = 256;
      game_o.victory_spawened                  = 0;
      game_o.victory_score                     = 0;
      game_o.wave[0].wave_size                 = 0.35f;
      game_o.wave[0].npc_type                  = 21;
      game_o.wave[0].spawn_pattern             = 8;
      game_o.wave[1].npc_type                  = 20;
      game_o.wave[1].spawn_pattern             = 5;
      game_o.wave[2].wave_size                 = 0.25f;
      game_o.wave[2].npc_type                  = 21;
      game_o.wave[2].spawn_pattern             = 7;
      game_o.wave[3].npc_type                  = 20;
      game_o.wave[3].spawn_pattern             = 8;
      game_o.wave[4].wave_size                 = 0.15f;
      game_o.wave[4].npc_type                  = 21;
      game_o.wave[4].spawn_pattern             = 4;
      game_o.wave[5].npc_type                  = 20;
      game_o.wave[5].spawn_pattern             = 7;
      game_o.level_waves                       = 5;
   }
   if (level_no == 22) // Tengu
   {
      game_o.level                             = level_no;
      game_o.level_npc_type                    = 22;
      game_o.level_boss_level                  = false;
      game.music_track                         = level_no;
        game.background.set_data ( 1, 1, 1, 0.0f, 0.0f, 0.0050f, 0.0050f, texture.background_006.ref_number);
        game.background.set_data ( 2, 1, 1, 4.0f, 0.0f, 0.0050f, 0.0050f, texture.background_006.ref_number);
        game.background.set_data ( 3, 1, 1, 0.0f, 0.0f, 0.0020f, 0.0020f, texture.background_011.ref_number);
        game.background.set_data ( 4, 1, 1, 4.0f, 0.0f, 0.0020f, 0.0020f, texture.background_011.ref_number);
      game_o.speed                             = 0.155f;
      game_o.npc_spawn_rate                    = 120;
      game_o.npc_spawn_rate_count              = 120;
      game_o.npc_projectile_spawn_rate         = 150;
      game_o.victory_kills                     = 512;
      game_o.victory_spawened                  = 0;
      game_o.victory_score                     = 0;
      game_o.wave[ 0].npc_type                 = 22;
      game_o.wave[ 0].spawn_pattern            = 0;
      game_o.wave[ 1].wave_size                = 0.25f;
      game_o.wave[ 1].npc_type                 = 21;
      game_o.wave[ 1].spawn_pattern            = 1;
      game_o.wave[ 2].npc_type                 = 20;
      game_o.wave[ 2].spawn_pattern            = 2;
      game_o.wave[ 3].npc_type                 = 22;
      game_o.wave[ 3].spawn_pattern            = 3;
      game_o.wave[ 4].wave_size                = 0.25f;
      game_o.wave[ 4].npc_type                 = 21;
      game_o.wave[ 4].spawn_pattern            = 4;
      game_o.wave[ 5].npc_type                 = 20;
      game_o.wave[ 5].spawn_pattern            = 5;
      game_o.wave[ 6].npc_type                 = 22;
      game_o.wave[ 6].spawn_pattern            = 6;
      game_o.wave[ 7].npc_type                 = 21;
      game_o.wave[ 7].spawn_pattern            = 7;
      game_o.wave[ 8].npc_type                 = 20;
      game_o.wave[ 8].spawn_pattern            = 8;
      game_o.wave[ 9].npc_type                 = 22;
      game_o.wave[ 9].spawn_pattern            = 9;
      game_o.wave[10].wave_size                = 0.25f;
      game_o.wave[10].npc_type                 = 21;
      game_o.wave[10].spawn_pattern            = 10;
      game_o.wave[11].npc_type                 = 20;
      game_o.wave[11].spawn_pattern            = 11;
      game_o.level_waves                       = 2;
   }
   if (level_no == 23) // Robonoid - BOSS 6
   {
      game_o.level                             = level_no;
      game_o.level_npc_type                    = 23;
      game_o.level_boss_level                  = true;
      game.music_track                         = level_no+1;
        game.background.set_data ( 1, 1, 1, 0.0f, 0.0f, 0.0050f, 0.0050f, texture.background_006.ref_number);
        game.background.set_data ( 2, 1, 1, 4.0f, 0.0f, 0.0050f, 0.0050f, texture.background_006.ref_number);
        game.background.set_data ( 3, 1, 1, 0.0f, 0.0f, 0.0020f, 0.0020f, texture.background_010.ref_number);
        game.background.set_data ( 4, 1, 1, 4.0f, 0.0f, 0.0020f, 0.0020f, texture.background_010.ref_number);
      game_o.speed                             = 0.160f;
      game_o.npc_spawn_rate                    = 1;
      game_o.npc_spawn_rate_count              = 1;
      game_o.npc_projectile_spawn_rate         = 20;
      game_o.victory_kills                     = 1;
      game_o.victory_spawened                  = 0;
      game_o.victory_score                     = 0;
   }
   if (level_no == 24) // Oyabun - BOSS 7 (final)
   {
      game_o.level                             = level_no;
      game_o.level_npc_type                    = 24;
      game_o.level_boss_level                  = true;
      game.music_track                         = level_no+1;
        game.background.set_data ( 1, 1, 1, 0.0f, 0.0f, 0.0050f, 0.0050f, texture.background_007.ref_number);
        game.background.set_data ( 2, 1, 1, 4.0f, 0.0f, 0.0050f, 0.0050f, texture.background_007.ref_number);
        game.background.set_data ( 3, 1, 1, 0.0f, 0.0f, 0.0020f, 0.0020f, texture.background_009.ref_number);
        game.background.set_data ( 4, 1, 1, 4.0f, 0.0f, 0.0020f, 0.0020f, texture.background_009.ref_number);
      game_o.speed                             = 0.165f;
      game_o.npc_spawn_rate                    = 1;
      game_o.npc_spawn_rate_count              = 1;
      game_o.npc_projectile_spawn_rate         = 10;
      game_o.victory_kills                     = 1;
      game_o.victory_spawened                  = 0;
      game_o.victory_score                     = 0;
   }
    game.background.set_movement_type(SCROLL);
    init_npcs(game_o.level_npc_type);
    return(0);
};

bool level_completed(void)
{
   if ((game_o.level_kills >= game_o.victory_kills) && (game_o.level_spawened >= game_o.victory_spawened) && (game_o.level_score >= game_o.victory_score))
   {
       game_o.level_end_time = true;
       if (game_o.level_end_phase == 0)
       {
          game_o.level_end_count++;
          if (game_o.level_end_count >= game_o.level_end_time_out)
          {
              game_o.level_end_phase = 1;
              game_o.level_end_count = 0;
          }
       }
       if (game_o.level_end_phase == 1)
       {
          game_o.level_end_count++;
          if (game_o.level_end_count >= game_o.level_end_time_out)
          {
              game_o.level_end_phase = 2;
              game_o.level_end_count = 0;
          }
       }
       if (game_o.level_end_phase == 2) return(true);
       else return(false);
   }
   else return(false);
}

bool boss_level(void)
{
    if ((game_o.level ==  3) || (game_o.level ==  7) || (game_o.level == 11) || (game_o.level == 15) || (game_o.level == 19) || (game_o.level == 23) || (game_o.level == 24)) return (true);
    else return (false);
};
