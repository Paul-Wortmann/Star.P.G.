/* Copyright (C) 2011 Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
 * This file is part of Star.P.G.
 *
 * Star.P.G. is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * Star.P.G. is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Star.P.G. If not, see <http://www.gnu.org/licenses/>.
 */

#include "levels.h"
#include "game.h"

extern game_type  game;

int unlock_levels(void)
{
   for (int level_no_count = 0;level_no_count < (MAX_LEVELS+1); level_no_count++)
   {
      game.level_locked[level_no_count] = false;
   }
   return(1);
}

int init_game_level(int level_no)
{
   game.level_end_time           = false;
   game.level_end_count          = 0;
   game.level_end_phase          = 0;
   game.level_end_display_active = false;
   game.powerups_spawened        = false;
   game.level_kills              = 0;
   game.level_spawened           = 0;
   game.level_score              = 0;
   game.active_npc_count         = 0;
   game.player.x_pos             =-0.9f+thruster_offset();
   game.player.y_pos             = 0.0f;
   init_npcs(0);
   init_active_npcs();
   kill_powerups();
   kill_coins();
   kill_wexps();
   game.wave[0].active = true;

   if (level_no == 0)
   {
      game.level                             = level_no;
      game.level_npc_type                    = 0;
      game.level_boss_level                  = false;
      game.music_track                       = level_no;
      game.background_scroll[0].image        = 66;
      game.background_scroll[1].image        = 66;
      game.background_scroll[2].image        = 96;
      game.background_scroll[3].image        = 96;
      game.background_scroll[0].scroll_rate  = 0.005f;
      game.background_scroll[1].scroll_rate  = 0.005f;
      game.background_scroll[2].scroll_rate  = 0.0025f;
      game.background_scroll[3].scroll_rate  = 0.0025f;
      game.background_scroll[0].x_pos        = 0.0f;
      game.background_scroll[1].x_pos        = 4.0f;
      game.background_scroll[2].x_pos        = 0.0f;
      game.background_scroll[3].x_pos        = 4.0f;
      game.speed                             = 0.045f;
      game.npc_spawn_rate                    = 300;
      game.npc_spawn_rate_count              = 300;
      game.npc_projectile_spawn_rate         = 50;
      game.victory_kills                     = 128;
      game.victory_spawened                  = 1;
      game.victory_score                     = 0;
      game.wave[ 0].wave_size                = 0.25f;
      game.wave[ 0].npc_type                 = 0;
      game.wave[ 0].spawn_pattern            = 0;
      game.wave[ 1].npc_type                 = 0;
      game.wave[ 1].spawn_pattern            = 7;
      game.wave[ 2].npc_type                 = 0;
      game.wave[ 2].spawn_pattern            = 8;
      game.wave[ 3].npc_type                 = 0;
      game.wave[ 3].spawn_pattern            = 10;
      game.wave[ 4].npc_type                 = 0;
      game.wave[ 4].spawn_pattern            = 11;
      game.level_waves                       = 4;
   }
   if (level_no == 1)
   {
      game.level                             = level_no;
      game.level_npc_type                    = 1;
      game.level_boss_level                  = false;
      game.music_track                       = level_no;
      game.background_scroll[0].image        = 66;
      game.background_scroll[1].image        = 66;
      game.background_scroll[2].image        = 95;
      game.background_scroll[3].image        = 95;
      game.background_scroll[0].scroll_rate  = 0.005f;
      game.background_scroll[1].scroll_rate  = 0.005f;
      game.background_scroll[2].scroll_rate  = 0.0025f;
      game.background_scroll[3].scroll_rate  = 0.0025f;
      game.background_scroll[0].x_pos        =-0.0f;
      game.background_scroll[1].x_pos        = 4.0f;
      game.background_scroll[2].x_pos        = 0.0f;
      game.background_scroll[3].x_pos        = 4.0f;
      game.speed                             = 0.050f;
      game.npc_spawn_rate                    = 280;
      game.npc_spawn_rate_count              = 280;
      game.npc_projectile_spawn_rate         = 50;
      game.victory_kills                     = 128;
      game.victory_spawened                  = 0;
      game.victory_score                     = 0;
      game.wave[ 0].wave_size                = 0.25f;
      game.wave[ 0].npc_type                 = 0;
      game.wave[ 0].spawn_pattern            = 0;
      game.wave[ 1].npc_type                 = 1;
      game.wave[ 1].spawn_pattern            = 11;
      game.wave[ 2].npc_type                 = 0;
      game.wave[ 2].spawn_pattern            = 7;
      game.wave[ 3].npc_type                 = 1;
      game.wave[ 3].spawn_pattern            = 10;
      game.wave[ 4].npc_type                 = 0;
      game.wave[ 4].spawn_pattern            = 8;
      game.wave[ 5].npc_type                 = 1;
      game.wave[ 5].spawn_pattern            = 8;
      game.wave[ 6].npc_type                 = 0;
      game.wave[ 6].spawn_pattern            = 10;
      game.wave[ 7].npc_type                 = 1;
      game.wave[ 7].spawn_pattern            = 7;
      game.wave[ 8].npc_type                 = 0;
      game.wave[ 8].spawn_pattern            = 11;
      game.level_waves                       = 8;
   }
   if (level_no == 2)
   {
      game.level                             = level_no;
      game.level_npc_type                    = 2;
      game.level_boss_level                  = false;
      game.music_track                       = level_no;
      game.background_scroll[0].image        = 66;
      game.background_scroll[1].image        = 66;
      game.background_scroll[2].image        = 94;
      game.background_scroll[3].image        = 94;
      game.background_scroll[0].scroll_rate  = 0.005f;
      game.background_scroll[1].scroll_rate  = 0.005f;
      game.background_scroll[2].scroll_rate  = 0.0025f;
      game.background_scroll[3].scroll_rate  = 0.0025f;
      game.background_scroll[0].x_pos        =-0.0f;
      game.background_scroll[1].x_pos        = 4.0f;
      game.background_scroll[2].x_pos        = 0.0f;
      game.background_scroll[3].x_pos        = 4.0f;
      game.speed                             = 0.055f;
      game.npc_spawn_rate                    = 270;
      game.npc_spawn_rate_count              = 270;
      game.npc_projectile_spawn_rate         = 50;
      game.victory_kills                     = 256;
      game.victory_spawened                  = 0;
      game.victory_score                     = 0;
      game.wave[ 0].wave_size                = 0.25f;
      game.wave[ 0].npc_type                 = 0;
      game.wave[ 0].spawn_pattern            = 0;
      game.wave[ 1].npc_type                 = 1;
      game.wave[ 1].spawn_pattern            = 11;
      game.wave[ 2].npc_type                 = 2;
      game.wave[ 2].spawn_pattern            = 2;
      game.wave[ 3].npc_type                 = 0;
      game.wave[ 3].spawn_pattern            = 7;
      game.wave[ 4].npc_type                 = 1;
      game.wave[ 4].spawn_pattern            = 10;
      game.wave[ 5].npc_type                 = 2;
      game.wave[ 5].spawn_pattern            = 7;
      game.wave[ 6].npc_type                 = 0;
      game.wave[ 6].spawn_pattern            = 8;
      game.wave[ 7].npc_type                 = 1;
      game.wave[ 7].spawn_pattern            = 8;
      game.wave[ 8].npc_type                 = 2;
      game.wave[ 8].spawn_pattern            = 11;
      game.wave[ 9].npc_type                 = 0;
      game.wave[ 9].spawn_pattern            = 10;
      game.wave[10].npc_type                 = 1;
      game.wave[10].spawn_pattern            = 7;
      game.wave[11].npc_type                 = 2;
      game.wave[11].spawn_pattern            = 10;
      game.wave[12].npc_type                 = 0;
      game.wave[12].spawn_pattern            = 11;
      game.level_waves                       = 12;
   }
   if (level_no == 3)
   {
      game.level                             = level_no;
      game.level_npc_type                    = 3;
      game.level_boss_level                  = true;
      game.music_track                       = level_no;
      game.background_scroll[0].image        = 65;
      game.background_scroll[1].image        = 65;
      game.background_scroll[2].image        = 94;
      game.background_scroll[3].image        = 94;
      game.background_scroll[0].scroll_rate  = 0.005f;
      game.background_scroll[1].scroll_rate  = 0.005f;
      game.background_scroll[2].scroll_rate  = 0.0025f;
      game.background_scroll[3].scroll_rate  = 0.0025f;
      game.background_scroll[0].x_pos        =-0.0f;
      game.background_scroll[1].x_pos        = 4.0f;
      game.background_scroll[2].x_pos        = 0.0f;
      game.background_scroll[3].x_pos        = 4.0f;
      game.speed                             = 0.060f;
      game.npc_spawn_rate                    = 1;
      game.npc_spawn_rate_count              = 1;
      game.npc_projectile_spawn_rate         = 10;
      game.victory_kills                     = 1;
      game.victory_spawened                  = 0;
      game.victory_score                     = 0;
   } /// add / ballence game below !!!
   if (level_no == 4)
   {
      game.level                             = level_no;
      game.level_npc_type                    = 4;
      game.level_boss_level                  = false;
      game.music_track                       = level_no;
      game.background_scroll[0].image        = 67;
      game.background_scroll[1].image        = 67;
      game.background_scroll[2].image        = 93;
      game.background_scroll[3].image        = 93;
      game.background_scroll[0].scroll_rate  = 0.005f;
      game.background_scroll[1].scroll_rate  = 0.005f;
      game.background_scroll[2].scroll_rate  = 0.0025f;
      game.background_scroll[3].scroll_rate  = 0.0025f;
      game.background_scroll[0].x_pos        =-0.0f;
      game.background_scroll[1].x_pos        = 4.0f;
      game.background_scroll[2].x_pos        = 0.0f;
      game.background_scroll[3].x_pos        = 4.0f;
      game.speed                             = 0.065f;
      game.npc_spawn_rate                    = 320;
      game.npc_spawn_rate_count              = 320;
      game.npc_projectile_spawn_rate         = 125;
      game.victory_kills                     = 128;
      game.victory_spawened                  = 0;
      game.victory_score                     = 0;
      game.wave[0].wave_size                 = 0.5f;
      game.wave[0].npc_type                  = 4;
      game.wave[0].spawn_pattern             = 0;
      game.wave[1].wave_size                 = 0.45f;
      game.wave[1].npc_type                  = 4;
      game.wave[1].spawn_pattern             = 8;
      game.level_waves                       = 1;
   }
   if (level_no == 5)
   {
      game.level                             = level_no;
      game.level_npc_type                    = 5;
      game.level_boss_level                  = false;
      game.music_track                       = level_no;
      game.background_scroll[0].image        = 67;
      game.background_scroll[1].image        = 67;
      game.background_scroll[2].image        = 92;
      game.background_scroll[3].image        = 92;
      game.background_scroll[0].scroll_rate  = 0.005f;
      game.background_scroll[1].scroll_rate  = 0.005f;
      game.background_scroll[2].scroll_rate  = 0.0025f;
      game.background_scroll[3].scroll_rate  = 0.0025f;
      game.background_scroll[0].x_pos        =-0.0f;
      game.background_scroll[1].x_pos        = 4.0f;
      game.background_scroll[2].x_pos        = 0.0f;
      game.background_scroll[3].x_pos        = 4.0f;
      game.speed                             = 0.070f;
      game.npc_spawn_rate                    = 220;
      game.npc_spawn_rate_count              = 220;
      game.npc_projectile_spawn_rate         = 125;
      game.victory_kills                     = 128;
      game.victory_spawened                  = 0;
      game.victory_score                     = 0;
      game.wave[0].wave_size                 = 0.3f;
      game.wave[0].npc_type                  = 4;
      game.wave[0].spawn_pattern             = 4;
      game.wave[1].npc_type                  = 5;
      game.wave[1].spawn_pattern             = 5;
      game.level_waves                       = 1;
   }
   if (level_no == 6)
   {
      game.level                             = level_no;
      game.level_npc_type                    = 6;
      game.level_boss_level                  = false;
      game.music_track                       = level_no;
      game.background_scroll[0].image        = 67;
      game.background_scroll[1].image        = 67;
      game.background_scroll[2].image        = 91;
      game.background_scroll[3].image        = 91;
      game.background_scroll[0].scroll_rate  = 0.005f;
      game.background_scroll[1].scroll_rate  = 0.005f;
      game.background_scroll[2].scroll_rate  = 0.0025f;
      game.background_scroll[3].scroll_rate  = 0.0025f;
      game.background_scroll[0].x_pos        =-0.0f;
      game.background_scroll[1].x_pos        = 4.0f;
      game.background_scroll[2].x_pos        = 0.0f;
      game.background_scroll[3].x_pos        = 4.0f;
      game.speed                             = 0.075f;
      game.npc_spawn_rate                    = 220;
      game.npc_spawn_rate_count              = 220;
      game.npc_projectile_spawn_rate         = 150;
      game.victory_kills                     = 256;
      game.victory_spawened                  = 0;
      game.victory_score                     = 0;
      game.wave[0].npc_type                  = 6;
      game.wave[0].spawn_pattern             = 6;
      game.wave[1].wave_size                 = 0.25f;
      game.wave[1].npc_type                  = 4;
      game.wave[1].spawn_pattern             = 4;
      game.wave[2].npc_type                  = 5;
      game.wave[2].spawn_pattern             = 5;
      game.level_waves                       = 2;
   }
   if (level_no == 7)
   {
      game.level                             = level_no;
      game.level_npc_type                    = 7;
      game.level_boss_level                  = true;
      game.music_track                       = level_no;
      game.background_scroll[0].image        = 64;
      game.background_scroll[1].image        = 64;
      game.background_scroll[2].image        = 91;
      game.background_scroll[3].image        = 91;
      game.background_scroll[0].scroll_rate  = 0.005f;
      game.background_scroll[1].scroll_rate  = 0.005f;
      game.background_scroll[2].scroll_rate  = 0.0025f;
      game.background_scroll[3].scroll_rate  = 0.0025f;
      game.background_scroll[0].x_pos        =-0.0f;
      game.background_scroll[1].x_pos        = 4.0f;
      game.background_scroll[2].x_pos        = 0.0f;
      game.background_scroll[3].x_pos        = 4.0f;
      game.speed                             = 0.080f;
      game.npc_spawn_rate                    = 1;
      game.npc_spawn_rate_count              = 1;
      game.npc_projectile_spawn_rate         = 150;
      game.victory_kills                     = 1;
      game.victory_spawened                  = 0;
      game.victory_score                     = 0;
   }
   if (level_no == 8)
   {
      game.level                             = level_no;
      game.level_npc_type                    = 8;
      game.level_boss_level                  = false;
      game.music_track                       = level_no;
      game.background_scroll[0].image        = 68;
      game.background_scroll[1].image        = 68;
      game.background_scroll[2].image        = 89;
      game.background_scroll[3].image        = 89;
      game.background_scroll[0].scroll_rate  = 0.005f;
      game.background_scroll[1].scroll_rate  = 0.005f;
      game.background_scroll[2].scroll_rate  = 0.0025f;
      game.background_scroll[3].scroll_rate  = 0.0025f;
      game.background_scroll[0].x_pos        =-0.0f;
      game.background_scroll[1].x_pos        = 4.0f;
      game.background_scroll[2].x_pos        = 0.0f;
      game.background_scroll[3].x_pos        = 4.0f;
      game.speed                             = 0.085f;
      game.npc_spawn_rate                    = 220;
      game.npc_spawn_rate_count              = 220;
      game.npc_projectile_spawn_rate         = 150;
      game.victory_kills                     = 128;
      game.victory_spawened                  = 0;
      game.victory_score                     = 0;
      game.wave[0].npc_type                  = 8;
      game.wave[0].spawn_pattern             = 4;
      game.level_waves                       = 0;
   }
   if (level_no == 9)
   {
      game.level                             = level_no;
      game.level_npc_type                    = 9;
      game.level_boss_level                  = false;
      game.music_track                       = level_no;
      game.background_scroll[0].image        = 68;
      game.background_scroll[1].image        = 68;
      game.background_scroll[2].image        = 88;
      game.background_scroll[3].image        = 88;
      game.background_scroll[0].scroll_rate  = 0.005f;
      game.background_scroll[1].scroll_rate  = 0.005f;
      game.background_scroll[2].scroll_rate  = 0.0025f;
      game.background_scroll[3].scroll_rate  = 0.0025f;
      game.background_scroll[0].x_pos        =-0.0f;
      game.background_scroll[1].x_pos        = 4.0f;
      game.background_scroll[2].x_pos        = 0.0f;
      game.background_scroll[3].x_pos        = 4.0f;
      game.speed                             = 0.090f;
      game.npc_spawn_rate                    = 220;
      game.npc_spawn_rate_count              = 220;
      game.npc_projectile_spawn_rate         = 150;
      game.victory_kills                     = 128;
      game.victory_spawened                  = 0;
      game.victory_score                     = 0;
      game.wave[0].npc_type                  = 9;
      game.wave[0].spawn_pattern             = 6;
      game.wave[1].npc_type                  = 8;
      game.wave[1].spawn_pattern             = 7;
      game.level_waves                       = 1;
   }
   if (level_no == 10)
   {
      game.level                             = level_no;
      game.level_npc_type                    = 10;
      game.level_boss_level                  = false;
      game.music_track                       = level_no;
      game.background_scroll[0].image        = 68;
      game.background_scroll[1].image        = 68;
      game.background_scroll[2].image        = 87;
      game.background_scroll[3].image        = 87;
      game.background_scroll[0].scroll_rate  = 0.005f;
      game.background_scroll[1].scroll_rate  = 0.005f;
      game.background_scroll[2].scroll_rate  = 0.0025f;
      game.background_scroll[3].scroll_rate  = 0.0025f;
      game.background_scroll[0].x_pos        =-0.0f;
      game.background_scroll[1].x_pos        = 4.0f;
      game.background_scroll[2].x_pos        = 0.0f;
      game.background_scroll[3].x_pos        = 4.0f;
      game.speed                             = 0.095f;
      game.npc_spawn_rate                    = 220;
      game.npc_spawn_rate_count              = 220;
      game.npc_projectile_spawn_rate         = 125;
      game.victory_kills                     = 256;
      game.victory_spawened                  = 0;
      game.victory_score                     = 0;
      game.wave[0].wave_size                 = 0.15f;
      game.wave[0].npc_type                  = 10;
      game.wave[0].spawn_pattern             = 4;
      game.wave[1].npc_type                  = 9;
      game.wave[1].spawn_pattern             = 6;
      game.wave[2].npc_type                  = 8;
      game.wave[2].spawn_pattern             = 7;
      game.level_waves                       = 2;
   }
   if (level_no == 11)
   {
      game.level                             = level_no;
      game.level_npc_type                    = 11;
      game.level_boss_level                  = true;
      game.music_track                       = level_no;
      game.background_scroll[0].image        = 65;
      game.background_scroll[1].image        = 65;
      game.background_scroll[2].image        = 87;
      game.background_scroll[3].image        = 87;
      game.background_scroll[0].scroll_rate  = 0.005f;
      game.background_scroll[1].scroll_rate  = 0.005f;
      game.background_scroll[2].scroll_rate  = 0.0025f;
      game.background_scroll[3].scroll_rate  = 0.0025f;
      game.background_scroll[0].x_pos        =-0.0f;
      game.background_scroll[1].x_pos        = 4.0f;
      game.background_scroll[2].x_pos        = 0.0f;
      game.background_scroll[3].x_pos        = 4.0f;
      game.speed                             = 0.100f;
      game.npc_spawn_rate                    = 1;
      game.npc_spawn_rate_count              = 1;
      game.npc_projectile_spawn_rate         = 75;
      game.victory_kills                     = 1;
      game.victory_spawened                  = 0;
      game.victory_score                     = 0;
   }
   if (level_no == 12)
   {
      game.level                             = level_no;
      game.level_npc_type                    = 12;
      game.level_boss_level                  = false;
      game.music_track                       = level_no;
      game.background_scroll[0].image        = 69;
      game.background_scroll[1].image        = 69;
      game.background_scroll[2].image        = 86;
      game.background_scroll[3].image        = 86;
      game.background_scroll[0].scroll_rate  = 0.005f;
      game.background_scroll[1].scroll_rate  = 0.005f;
      game.background_scroll[2].scroll_rate  = 0.0025f;
      game.background_scroll[3].scroll_rate  = 0.0025f;
      game.background_scroll[0].x_pos        =-0.0f;
      game.background_scroll[1].x_pos        = 4.0f;
      game.background_scroll[2].x_pos        = 0.0f;
      game.background_scroll[3].x_pos        = 4.0f;
      game.speed                             = 0.105f;
      game.npc_spawn_rate                    = 180;
      game.npc_spawn_rate_count              = 180;
      game.npc_projectile_spawn_rate         = 75;
      game.victory_kills                     = 128;
      game.victory_spawened                  = 0;
      game.victory_score                     = 0;
      game.wave[0].npc_type                  = 12;
      game.wave[0].spawn_pattern             = 7;
      game.level_waves                       = 0;
   }
   if (level_no == 13)
   {
      game.level                             = level_no;
      game.level_npc_type                    = 13;
      game.level_boss_level                  = false;
      game.music_track                       = level_no;
      game.background_scroll[0].image        = 69;
      game.background_scroll[1].image        = 69;
      game.background_scroll[2].image        = 85;
      game.background_scroll[3].image        = 85;
      game.background_scroll[0].scroll_rate  = 0.005f;
      game.background_scroll[1].scroll_rate  = 0.005f;
      game.background_scroll[2].scroll_rate  = 0.0025f;
      game.background_scroll[3].scroll_rate  = 0.0025f;
      game.background_scroll[0].x_pos        =-0.0f;
      game.background_scroll[1].x_pos        = 4.0f;
      game.background_scroll[2].x_pos        = 0.0f;
      game.background_scroll[3].x_pos        = 4.0f;
      game.speed                             = 0.110f;
      game.npc_spawn_rate                    = 220;
      game.npc_spawn_rate_count              = 220;
      game.npc_projectile_spawn_rate         = 150;
      game.victory_kills                     = 128;
      game.victory_spawened                  = 0;
      game.victory_score                     = 0;
      game.wave[0].npc_type                  = 13;
      game.wave[0].spawn_pattern             = 0;
      game.wave[1].npc_type                  = 12;
      game.wave[1].spawn_pattern             = 1;
      game.level_waves                       = 1;
   }
   if (level_no == 14)
   {
      game.level                             = level_no;
      game.level_npc_type                    = 14;
      game.level_boss_level                  = false;
      game.music_track                       = level_no;
      game.background_scroll[0].image        = 69;
      game.background_scroll[1].image        = 69;
      game.background_scroll[2].image        = 84;
      game.background_scroll[3].image        = 84;
      game.background_scroll[0].scroll_rate  = 0.005f;
      game.background_scroll[1].scroll_rate  = 0.005f;
      game.background_scroll[2].scroll_rate  = 0.0025f;
      game.background_scroll[3].scroll_rate  = 0.0025f;
      game.background_scroll[0].x_pos        =-0.0f;
      game.background_scroll[1].x_pos        = 4.0f;
      game.background_scroll[2].x_pos        = 0.0f;
      game.background_scroll[3].x_pos        = 4.0f;
      game.speed                             = 0.115f;
      game.npc_spawn_rate                    = 220;
      game.npc_spawn_rate_count              = 220;
      game.npc_projectile_spawn_rate         = 150;
      game.victory_kills                     = 256;
      game.victory_spawened                  = 0;
      game.victory_score                     = 0;
      game.wave[0].wave_size                 = 0.25f;
      game.wave[0].npc_type                  = 14;
      game.wave[0].spawn_pattern             = 4;
      game.wave[1].npc_type                  = 13;
      game.wave[1].spawn_pattern             = 0;
      game.wave[2].wave_size                 = 0.35f;
      game.wave[2].npc_type                  = 14;
      game.wave[2].spawn_pattern             = 4;
      game.wave[3].npc_type                  = 12;
      game.wave[3].spawn_pattern             = 1;
      game.level_waves                       = 3;
   }
   if (level_no == 15)
   {
      game.level                             = level_no;
      game.level_npc_type                    = 15;
      game.level_boss_level                  = true;
      game.music_track                       = level_no;
      game.background_scroll[0].image        = 65;
      game.background_scroll[1].image        = 65;
      game.background_scroll[2].image        = 83;
      game.background_scroll[3].image        = 83;
      game.background_scroll[0].scroll_rate  = 0.005f;
      game.background_scroll[1].scroll_rate  = 0.005f;
      game.background_scroll[2].scroll_rate  = 0.0025f;
      game.background_scroll[3].scroll_rate  = 0.0025f;
      game.background_scroll[0].x_pos        =-0.0f;
      game.background_scroll[1].x_pos        = 4.0f;
      game.background_scroll[2].x_pos        = 0.0f;
      game.background_scroll[3].x_pos        = 4.0f;
      game.speed                             = 0.120f;
      game.npc_spawn_rate                    = 1;
      game.npc_spawn_rate_count              = 1;
      game.npc_projectile_spawn_rate         = 50;
      game.victory_kills                     = 1;
      game.victory_spawened                  = 0;
      game.victory_score                     = 0;
   }
   if (level_no == 16)
   {
      game.level                             = level_no;
      game.level_npc_type                    = 16;
      game.level_boss_level                  = false;
      game.music_track                       = level_no;
      game.background_scroll[0].image        = 70;
      game.background_scroll[1].image        = 70;
      game.background_scroll[2].image        = 82;
      game.background_scroll[3].image        = 82;
      game.background_scroll[0].scroll_rate  = 0.005f;
      game.background_scroll[1].scroll_rate  = 0.005f;
      game.background_scroll[2].scroll_rate  = 0.0025f;
      game.background_scroll[3].scroll_rate  = 0.0025f;
      game.background_scroll[0].x_pos        =-0.0f;
      game.background_scroll[1].x_pos        = 4.0f;
      game.background_scroll[2].x_pos        = 0.0f;
      game.background_scroll[3].x_pos        = 4.0f;
      game.speed                             = 0.125f;
      game.npc_spawn_rate                    = 220;
      game.npc_spawn_rate_count              = 220;
      game.npc_projectile_spawn_rate         = 150;
      game.victory_kills                     = 128;
      game.victory_spawened                  = 0;
      game.victory_score                     = 0;
      game.wave[0].wave_size                 = 0.45f;
      game.wave[0].npc_type                  = 16;
      game.wave[0].spawn_pattern             = 8;
      game.level_waves                       = 0;
   }
   if (level_no == 17)
   {
      game.level                             = level_no;
      game.level_npc_type                    = 17;
      game.level_boss_level                  = false;
      game.music_track                       = level_no;
      game.background_scroll[0].image        = 70;
      game.background_scroll[1].image        = 70;
      game.background_scroll[2].image        = 81;
      game.background_scroll[3].image        = 81;
      game.background_scroll[0].scroll_rate  = 0.005f;
      game.background_scroll[1].scroll_rate  = 0.005f;
      game.background_scroll[2].scroll_rate  = 0.0025f;
      game.background_scroll[3].scroll_rate  = 0.0025f;
      game.background_scroll[0].x_pos        =-0.0f;
      game.background_scroll[1].x_pos        = 4.0f;
      game.background_scroll[2].x_pos        = 0.0f;
      game.background_scroll[3].x_pos        = 4.0f;
      game.speed                             = 0.130f;
      game.npc_spawn_rate                    = 220;
      game.npc_spawn_rate_count              = 220;
      game.npc_projectile_spawn_rate         = 150;
      game.victory_kills                     = 128;
      game.victory_spawened                  = 0;
      game.victory_score                     = 0;
      game.wave[0].npc_type                  = 17;
      game.wave[0].spawn_pattern             = 9;
      game.wave[1].wave_size                 = 0.25f;
      game.wave[1].npc_type                  = 16;
      game.wave[1].spawn_pattern             = 8;
      game.level_waves                       = 1;
   }
   if (level_no == 18)
   {
      game.level                             = level_no;
      game.level_npc_type                    = 18;
      game.level_boss_level                  = false;
      game.music_track                       = level_no;
      game.background_scroll[0].image        = 70;
      game.background_scroll[1].image        = 70;
      game.background_scroll[2].image        = 80;
      game.background_scroll[3].image        = 80;
      game.background_scroll[0].scroll_rate  = 0.005f;
      game.background_scroll[1].scroll_rate  = 0.005f;
      game.background_scroll[2].scroll_rate  = 0.0025f;
      game.background_scroll[3].scroll_rate  = 0.0025f;
      game.background_scroll[0].x_pos        =-0.0f;
      game.background_scroll[1].x_pos        = 4.0f;
      game.background_scroll[2].x_pos        = 0.0f;
      game.background_scroll[3].x_pos        = 4.0f;
      game.speed                             = 0.135f;
      game.npc_spawn_rate                    = 220;
      game.npc_spawn_rate_count              = 220;
      game.npc_projectile_spawn_rate         = 150;
      game.victory_kills                     = 258;
      game.victory_spawened                  = 0;
      game.victory_score                     = 0;
      game.wave[0].npc_type                  = 18;
      game.wave[0].spawn_pattern             = 9;
      game.wave[1].wave_size                 = 0.35f;
      game.wave[1].npc_type                  = 16;
      game.wave[1].spawn_pattern             = 10;
      game.wave[2].npc_type                  = 17;
      game.wave[2].spawn_pattern             = 11;
      game.level_waves                       = 2;
   }
   if (level_no == 19)
   {
      game.level                             = level_no;
      game.level_npc_type                    = 19;
      game.level_boss_level                  = true;
      game.music_track                       = level_no;
      game.background_scroll[0].image        = 70;
      game.background_scroll[1].image        = 70;
      game.background_scroll[2].image        = 79;
      game.background_scroll[3].image        = 79;
      game.background_scroll[0].scroll_rate  = 0.005f;
      game.background_scroll[1].scroll_rate  = 0.005f;
      game.background_scroll[2].scroll_rate  = 0.0025f;
      game.background_scroll[3].scroll_rate  = 0.0025f;
      game.background_scroll[0].x_pos        =-0.0f;
      game.background_scroll[1].x_pos        = 4.0f;
      game.background_scroll[2].x_pos        = 0.0f;
      game.background_scroll[3].x_pos        = 4.0f;
      game.speed                             = 0.140f;
      game.npc_spawn_rate                    = 1;
      game.npc_spawn_rate_count              = 1;
      game.npc_projectile_spawn_rate         = 50;
      game.victory_kills                     = 1;
      game.victory_spawened                  = 0;
      game.victory_score                     = 0;
   }
   if (level_no == 20)
   {
      game.level                             = level_no;
      game.level_npc_type                    = 20;
      game.level_boss_level                  = false;
      game.music_track                       = level_no;
      game.background_scroll[0].image        = 71;
      game.background_scroll[1].image        = 71;
      game.background_scroll[2].image        = 78;
      game.background_scroll[3].image        = 78;
      game.background_scroll[0].scroll_rate  = 0.005f;
      game.background_scroll[1].scroll_rate  = 0.005f;
      game.background_scroll[2].scroll_rate  = 0.0025f;
      game.background_scroll[3].scroll_rate  = 0.0025f;
      game.background_scroll[0].x_pos        =-0.0f;
      game.background_scroll[1].x_pos        = 4.0f;
      game.background_scroll[2].x_pos        = 0.0f;
      game.background_scroll[3].x_pos        = 4.0f;
      game.speed                             = 0.145f;
      game.npc_spawn_rate                    = 120;
      game.npc_spawn_rate_count              = 120;
      game.npc_projectile_spawn_rate         = 150;
      game.victory_kills                     = 128;
      game.victory_spawened                  = 0;
      game.victory_score                     = 0;
      game.wave[0].npc_type                  = 20;
      game.wave[0].spawn_pattern             = 4;
      game.wave[1].npc_type                  = 20;
      game.wave[1].spawn_pattern             = 7;
      game.level_waves                       = 1;
   }
   if (level_no == 21)
   {
      game.level                             = level_no;
      game.level_npc_type                    = 21;
      game.level_boss_level                  = false;
      game.music_track                       = level_no;
      game.background_scroll[0].image        = 71;
      game.background_scroll[1].image        = 71;
      game.background_scroll[2].image        = 77;
      game.background_scroll[3].image        = 77;
      game.background_scroll[0].scroll_rate  = 0.005f;
      game.background_scroll[1].scroll_rate  = 0.005f;
      game.background_scroll[2].scroll_rate  = 0.0025f;
      game.background_scroll[3].scroll_rate  = 0.0025f;
      game.background_scroll[0].x_pos        =-0.0f;
      game.background_scroll[1].x_pos        = 4.0f;
      game.background_scroll[2].x_pos        = 0.0f;
      game.background_scroll[3].x_pos        = 4.0f;
      game.speed                             = 0.150f;
      game.npc_spawn_rate                    = 120;
      game.npc_spawn_rate_count              = 120;
      game.npc_projectile_spawn_rate         = 150;
      game.victory_kills                     = 256;
      game.victory_spawened                  = 0;
      game.victory_score                     = 0;
      game.wave[0].wave_size                 = 0.35f;
      game.wave[0].npc_type                  = 21;
      game.wave[0].spawn_pattern             = 8;
      game.wave[1].npc_type                  = 20;
      game.wave[1].spawn_pattern             = 5;
      game.wave[2].wave_size                 = 0.25f;
      game.wave[2].npc_type                  = 21;
      game.wave[2].spawn_pattern             = 7;
      game.wave[3].npc_type                  = 20;
      game.wave[3].spawn_pattern             = 8;
      game.wave[4].wave_size                 = 0.15f;
      game.wave[4].npc_type                  = 21;
      game.wave[4].spawn_pattern             = 4;
      game.wave[5].npc_type                  = 20;
      game.wave[5].spawn_pattern             = 7;
      game.level_waves                       = 5;
   }
   if (level_no == 22)
   {
      game.level                             = level_no;
      game.level_npc_type                    = 22;
      game.level_boss_level                  = false;
      game.music_track                       = level_no;
      game.background_scroll[0].image        = 71;
      game.background_scroll[1].image        = 71;
      game.background_scroll[2].image        = 76;
      game.background_scroll[3].image        = 76;
      game.background_scroll[0].scroll_rate  = 0.005f;
      game.background_scroll[1].scroll_rate  = 0.005f;
      game.background_scroll[2].scroll_rate  = 0.0025f;
      game.background_scroll[3].scroll_rate  = 0.0025f;
      game.background_scroll[0].x_pos        =-0.0f;
      game.background_scroll[1].x_pos        = 4.0f;
      game.background_scroll[2].x_pos        = 0.0f;
      game.background_scroll[3].x_pos        = 4.0f;
      game.speed                             = 0.155f;
      game.npc_spawn_rate                    = 120;
      game.npc_spawn_rate_count              = 120;
      game.npc_projectile_spawn_rate         = 150;
      game.victory_kills                     = 512;
      game.victory_spawened                  = 0;
      game.victory_score                     = 0;
      game.wave[ 0].npc_type                 = 22;
      game.wave[ 0].spawn_pattern            = 0;
      game.wave[ 1].wave_size                = 0.25f;
      game.wave[ 1].npc_type                 = 21;
      game.wave[ 1].spawn_pattern            = 1;
      game.wave[ 2].npc_type                 = 20;
      game.wave[ 2].spawn_pattern            = 2;
      game.wave[ 3].npc_type                 = 22;
      game.wave[ 3].spawn_pattern            = 3;
      game.wave[ 4].wave_size                = 0.25f;
      game.wave[ 4].npc_type                 = 21;
      game.wave[ 4].spawn_pattern            = 4;
      game.wave[ 5].npc_type                 = 20;
      game.wave[ 5].spawn_pattern            = 5;
      game.wave[ 6].npc_type                 = 22;
      game.wave[ 6].spawn_pattern            = 6;
      game.wave[ 7].npc_type                 = 21;
      game.wave[ 7].spawn_pattern            = 7;
      game.wave[ 8].npc_type                 = 20;
      game.wave[ 8].spawn_pattern            = 8;
      game.wave[ 9].npc_type                 = 22;
      game.wave[ 9].spawn_pattern            = 9;
      game.wave[10].wave_size                = 0.25f;
      game.wave[10].npc_type                 = 21;
      game.wave[10].spawn_pattern            = 10;
      game.wave[11].npc_type                 = 20;
      game.wave[11].spawn_pattern            = 11;
      game.level_waves                       = 2;
   }
   if (level_no == 23)
   {
      game.level                             = level_no;
      game.level_npc_type                    = 23;
      game.level_boss_level                  = true;
      game.music_track                       = level_no+1;
      game.background_scroll[0].image        = 71;
      game.background_scroll[1].image        = 71;
      game.background_scroll[2].image        = 75;
      game.background_scroll[3].image        = 75;
      game.background_scroll[0].scroll_rate  = 0.005f;
      game.background_scroll[1].scroll_rate  = 0.005f;
      game.background_scroll[2].scroll_rate  = 0.0025f;
      game.background_scroll[3].scroll_rate  = 0.0025f;
      game.background_scroll[0].x_pos        =-0.0f;
      game.background_scroll[1].x_pos        = 4.0f;
      game.background_scroll[2].x_pos        = 0.0f;
      game.background_scroll[3].x_pos        = 4.0f;
      game.speed                             = 0.160f;
      game.npc_spawn_rate                    = 1;
      game.npc_spawn_rate_count              = 1;
      game.npc_projectile_spawn_rate         = 20;
      game.victory_kills                     = 1;
      game.victory_spawened                  = 0;
      game.victory_score                     = 0;
   }
   if (level_no == 24)
   {
      game.level                             = level_no;
      game.level_npc_type                    = 24;
      game.level_boss_level                  = true;
      game.music_track                       = level_no+1;
      game.background_scroll[0].image        = 72;
      game.background_scroll[1].image        = 72;
      game.background_scroll[2].image        = 74;
      game.background_scroll[3].image        = 74;
      game.background_scroll[0].scroll_rate  = 0.005f;
      game.background_scroll[1].scroll_rate  = 0.005f;
      game.background_scroll[2].scroll_rate  = 0.0025f;
      game.background_scroll[3].scroll_rate  = 0.0025f;
      game.background_scroll[0].x_pos        =-0.0f;
      game.background_scroll[1].x_pos        = 4.0f;
      game.background_scroll[2].x_pos        = 0.0f;
      game.background_scroll[3].x_pos        = 4.0f;
      game.speed                             = 0.165f;
      game.npc_spawn_rate                    = 1;
      game.npc_spawn_rate_count              = 1;
      game.npc_projectile_spawn_rate         = 10;
      game.victory_kills                     = 1;
      game.victory_spawened                  = 0;
      game.victory_score                     = 0;
   }
   init_npcs(game.level_npc_type);
   return(0);
};
