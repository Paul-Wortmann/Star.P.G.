#include "levels.h"
#include "game.h"

extern game_type  game;

int init_game_level(int level_no)
{
   game.level_kills      = 0;
   game.level_spawened   = 0;
   game.level_score      = 0;
   game.active_npc_count = 0;
   init_npcs(0);
   init_active_npcs();

   if (level_no == 0)
   {
      game.level                             = level_no;
      game.level_npc_type                    = 0;
      game.level_boss_level                  = false;
      game.music_track                       = 1;
      game.background_scroll[0].image        = 66;
      game.background_scroll[1].image        = 66;
      game.background_scroll[2].image        = 96;
      game.background_scroll[3].image        = 96;
      game.background_scroll[0].scroll_rate  = 0.0025f;
      game.background_scroll[1].scroll_rate  = 0.0025f;
      game.background_scroll[2].scroll_rate  = 0.00025f;
      game.background_scroll[3].scroll_rate  = 0.00025f;
      game.background_scroll[0].x_pos        =-0.0f;
      game.background_scroll[1].x_pos        = 4.0f;
      game.background_scroll[2].x_pos        = 0.0f;
      game.background_scroll[3].x_pos        = 4.0f;
      game.speed                             = 0.045f;
      game.npc_spawn_rate                    = 100;
      game.npc_projectile_spawn_rate         = 50;
      game.victory_kills                     = 32;
      game.victory_spawened                  = 1;
      game.victory_score                     = 0;
   }
   if (level_no == 1)
   {
      game.level                             = level_no;
      game.level_npc_type                    = 1;
      game.level_boss_level                  = false;
      game.music_track                       = 1;
      game.background_scroll[0].image        = 66;
      game.background_scroll[1].image        = 66;
      game.background_scroll[2].image        = 95;
      game.background_scroll[3].image        = 95;
      game.background_scroll[0].scroll_rate  = 0.0025f;
      game.background_scroll[1].scroll_rate  = 0.0025f;
      game.background_scroll[2].scroll_rate  = 0.00025f;
      game.background_scroll[3].scroll_rate  = 0.00025f;
      game.background_scroll[0].x_pos        =-2.0f;
      game.background_scroll[1].x_pos        = 2.00199f;
      game.background_scroll[2].x_pos        = 0.0f;
      game.background_scroll[3].x_pos        = 4.0f;
      game.speed                             = 0.050f;
      game.npc_spawn_rate                    = 100;
      game.npc_projectile_spawn_rate         = 50;
      game.victory_kills                     = 32;
      game.victory_spawened                  = 0;
      game.victory_score                     = 0;
   }
   if (level_no == 2)
   {
      game.level                             = level_no;
      game.level_npc_type                    = 2;
      game.level_boss_level                  = false;
      game.music_track                       = 1;
      game.background_scroll[0].image        = 66;
      game.background_scroll[1].image        = 66;
      game.background_scroll[2].image        = 94;
      game.background_scroll[3].image        = 94;
      game.background_scroll[0].scroll_rate  = 0.0025f;
      game.background_scroll[1].scroll_rate  = 0.0025f;
      game.background_scroll[2].scroll_rate  = 0.00025f;
      game.background_scroll[3].scroll_rate  = 0.00025f;
      game.background_scroll[0].x_pos        =-2.0f;
      game.background_scroll[1].x_pos        = 2.00199f;
      game.background_scroll[2].x_pos        = 0.0f;
      game.background_scroll[3].x_pos        = 4.0f;
      game.speed                             = 0.055f;
      game.npc_spawn_rate                    = 100;
      game.npc_projectile_spawn_rate         = 50;
      game.victory_kills                     = 32;
      game.victory_spawened                  = 0;
      game.victory_score                     = 0;
   }
   if (level_no == 3)
   {
      game.level                             = level_no;
      game.level_npc_type                    = 3;
      game.level_boss_level                  = true;
      game.music_track                       = 1;
      game.background_scroll[0].image        = 65;
      game.background_scroll[1].image        = 65;
      game.background_scroll[2].image        = 94;
      game.background_scroll[3].image        = 94;
      game.background_scroll[0].scroll_rate  = 0.0025f;
      game.background_scroll[1].scroll_rate  = 0.0025f;
      game.background_scroll[2].scroll_rate  = 0.00025f;
      game.background_scroll[3].scroll_rate  = 0.00025f;
      game.background_scroll[0].x_pos        =-2.0f;
      game.background_scroll[1].x_pos        = 2.00199f;
      game.background_scroll[2].x_pos        = 0.0f;
      game.background_scroll[3].x_pos        = 4.0f;
      game.speed                             = 0.060f;
      game.npc_spawn_rate                    = 100;
      game.npc_projectile_spawn_rate         = 50;
      game.victory_kills                     = 1;
      game.victory_spawened                  = 0;
      game.victory_score                     = 0;
   }
   if (level_no == 4)
   {
      game.level                             = level_no;
      game.level_npc_type                    = 4;
      game.level_boss_level                  = false;
      game.music_track                       = 1;
      game.background_scroll[0].image        = 67;
      game.background_scroll[1].image        = 67;
      game.background_scroll[2].image        = 93;
      game.background_scroll[3].image        = 93;
      game.background_scroll[0].scroll_rate  = 0.0025f;
      game.background_scroll[1].scroll_rate  = 0.0025f;
      game.background_scroll[2].scroll_rate  = 0.00025f;
      game.background_scroll[3].scroll_rate  = 0.00025f;
      game.background_scroll[0].x_pos        =-2.0f;
      game.background_scroll[1].x_pos        = 2.00199f;
      game.background_scroll[2].x_pos        = 0.0f;
      game.background_scroll[3].x_pos        = 4.0f;
      game.speed                             = 0.065f;
      game.npc_spawn_rate                    = 100;
      game.npc_projectile_spawn_rate         = 50;
      game.victory_kills                     = 32;
      game.victory_spawened                  = 0;
      game.victory_score                     = 0;
   }
   if (level_no == 5)
   {
      game.level                             = level_no;
      game.level_npc_type                    = 5;
      game.level_boss_level                  = false;
      game.music_track                       = 1;
      game.background_scroll[0].image        = 67;
      game.background_scroll[1].image        = 67;
      game.background_scroll[2].image        = 92;
      game.background_scroll[3].image        = 92;
      game.background_scroll[0].scroll_rate  = 0.0025f;
      game.background_scroll[1].scroll_rate  = 0.0025f;
      game.background_scroll[2].scroll_rate  = 0.00025f;
      game.background_scroll[3].scroll_rate  = 0.00025f;
      game.background_scroll[0].x_pos        =-2.0f;
      game.background_scroll[1].x_pos        = 2.00199f;
      game.background_scroll[2].x_pos        = 0.0f;
      game.background_scroll[3].x_pos        = 4.0f;
      game.speed                             = 0.070f;
      game.npc_spawn_rate                    = 100;
      game.npc_projectile_spawn_rate         = 50;
      game.victory_kills                     = 32;
      game.victory_spawened                  = 0;
      game.victory_score                     = 0;
   }
   if (level_no == 6)
   {
      game.level                             = level_no;
      game.level_npc_type                    = 6;
      game.level_boss_level                  = false;
      game.music_track                       = 1;
      game.background_scroll[0].image        = 67;
      game.background_scroll[1].image        = 67;
      game.background_scroll[2].image        = 91;
      game.background_scroll[3].image        = 91;
      game.background_scroll[0].scroll_rate  = 0.0025f;
      game.background_scroll[1].scroll_rate  = 0.0025f;
      game.background_scroll[2].scroll_rate  = 0.00025f;
      game.background_scroll[3].scroll_rate  = 0.00025f;
      game.background_scroll[0].x_pos        =-2.0f;
      game.background_scroll[1].x_pos        = 2.00199f;
      game.background_scroll[2].x_pos        = 0.0f;
      game.background_scroll[3].x_pos        = 4.0f;
      game.speed                             = 0.075f;
      game.npc_spawn_rate                    = 100;
      game.npc_projectile_spawn_rate         = 50;
      game.victory_kills                     = 32;
      game.victory_spawened                  = 0;
      game.victory_score                     = 0;
   }
   if (level_no == 7)
   {
      game.level                             = level_no;
      game.level_npc_type                    = 7;
      game.level_boss_level                  = true;
      game.music_track                       = 1;
      game.background_scroll[0].image        = 64;
      game.background_scroll[1].image        = 64;
      game.background_scroll[2].image        = 91;
      game.background_scroll[3].image        = 91;
      game.background_scroll[0].scroll_rate  = 0.0025f;
      game.background_scroll[1].scroll_rate  = 0.0025f;
      game.background_scroll[2].scroll_rate  = 0.00025f;
      game.background_scroll[3].scroll_rate  = 0.00025f;
      game.background_scroll[0].x_pos        =-2.0f;
      game.background_scroll[1].x_pos        = 2.00199f;
      game.background_scroll[2].x_pos        = 0.0f;
      game.background_scroll[3].x_pos        = 4.0f;
      game.speed                             = 0.080f;
      game.npc_spawn_rate                    = 100;
      game.npc_projectile_spawn_rate         = 50;
      game.victory_kills                     = 1;
      game.victory_spawened                  = 0;
      game.victory_score                     = 0;
   }
   if (level_no == 8)
   {
      game.level                             = level_no;
      game.level_npc_type                    = 8;
      game.level_boss_level                  = false;
      game.music_track                       = 1;
      game.background_scroll[0].image        = 68;
      game.background_scroll[1].image        = 68;
      game.background_scroll[2].image        = 89;
      game.background_scroll[3].image        = 89;
      game.background_scroll[0].scroll_rate  = 0.0025f;
      game.background_scroll[1].scroll_rate  = 0.0025f;
      game.background_scroll[2].scroll_rate  = 0.00025f;
      game.background_scroll[3].scroll_rate  = 0.00025f;
      game.background_scroll[0].x_pos        =-2.0f;
      game.background_scroll[1].x_pos        = 2.00199f;
      game.background_scroll[2].x_pos        = 0.0f;
      game.background_scroll[3].x_pos        = 4.0f;
      game.speed                             = 0.085f;
      game.npc_spawn_rate                    = 100;
      game.npc_projectile_spawn_rate         = 50;
      game.victory_kills                     = 32;
      game.victory_spawened                  = 0;
      game.victory_score                     = 0;
   }
   if (level_no == 9)
   {
      game.level                             = level_no;
      game.level_npc_type                    = 9;
      game.level_boss_level                  = false;
      game.music_track                       = 1;
      game.background_scroll[0].image        = 68;
      game.background_scroll[1].image        = 68;
      game.background_scroll[2].image        = 88;
      game.background_scroll[3].image        = 88;
      game.background_scroll[0].scroll_rate  = 0.0025f;
      game.background_scroll[1].scroll_rate  = 0.0025f;
      game.background_scroll[2].scroll_rate  = 0.00025f;
      game.background_scroll[3].scroll_rate  = 0.00025f;
      game.background_scroll[0].x_pos        =-2.0f;
      game.background_scroll[1].x_pos        = 2.00199f;
      game.background_scroll[2].x_pos        = 0.0f;
      game.background_scroll[3].x_pos        = 4.0f;
      game.speed                             = 0.090f;
      game.npc_spawn_rate                    = 100;
      game.npc_projectile_spawn_rate         = 50;
      game.victory_kills                     = 32;
      game.victory_spawened                  = 0;
      game.victory_score                     = 0;
   }
   if (level_no == 10)
   {
      game.level                             = level_no;
      game.level_npc_type                    = 10;
      game.level_boss_level                  = false;
      game.music_track                       = 1;
      game.background_scroll[0].image        = 68;
      game.background_scroll[1].image        = 68;
      game.background_scroll[2].image        = 87;
      game.background_scroll[3].image        = 87;
      game.background_scroll[0].scroll_rate  = 0.0025f;
      game.background_scroll[1].scroll_rate  = 0.0025f;
      game.background_scroll[2].scroll_rate  = 0.00025f;
      game.background_scroll[3].scroll_rate  = 0.00025f;
      game.background_scroll[0].x_pos        =-2.0f;
      game.background_scroll[1].x_pos        = 2.00199f;
      game.background_scroll[2].x_pos        = 0.0f;
      game.background_scroll[3].x_pos        = 4.0f;
      game.speed                             = 0.095f;
      game.npc_spawn_rate                    = 100;
      game.npc_projectile_spawn_rate         = 50;
      game.victory_kills                     = 32;
      game.victory_spawened                  = 0;
      game.victory_score                     = 0;
   }
   if (level_no == 11)
   {
      game.level                             = level_no;
      game.level_npc_type                    = 11;
      game.level_boss_level                  = true;
      game.music_track                       = 1;
      game.background_scroll[0].image        = 65;
      game.background_scroll[1].image        = 65;
      game.background_scroll[2].image        = 87;
      game.background_scroll[3].image        = 87;
      game.background_scroll[0].scroll_rate  = 0.0025f;
      game.background_scroll[1].scroll_rate  = 0.0025f;
      game.background_scroll[2].scroll_rate  = 0.00025f;
      game.background_scroll[3].scroll_rate  = 0.00025f;
      game.background_scroll[0].x_pos        =-2.0f;
      game.background_scroll[1].x_pos        = 2.00199f;
      game.background_scroll[2].x_pos        = 0.0f;
      game.background_scroll[3].x_pos        = 4.0f;
      game.speed                             = 0.100f;
      game.npc_spawn_rate                    = 100;
      game.npc_projectile_spawn_rate         = 50;
      game.victory_kills                     = 1;
      game.victory_spawened                  = 0;
      game.victory_score                     = 0;
   }
   if (level_no == 12)
   {
      game.level                             = level_no;
      game.level_npc_type                    = 12;
      game.level_boss_level                  = false;
      game.music_track                       = 1;
      game.background_scroll[0].image        = 69;
      game.background_scroll[1].image        = 69;
      game.background_scroll[2].image        = 86;
      game.background_scroll[3].image        = 86;
      game.background_scroll[0].scroll_rate  = 0.0025f;
      game.background_scroll[1].scroll_rate  = 0.0025f;
      game.background_scroll[2].scroll_rate  = 0.00025f;
      game.background_scroll[3].scroll_rate  = 0.00025f;
      game.background_scroll[0].x_pos        =-2.0f;
      game.background_scroll[1].x_pos        = 2.00199f;
      game.background_scroll[2].x_pos        = 0.0f;
      game.background_scroll[3].x_pos        = 4.0f;
      game.speed                             = 0.105f;
      game.npc_spawn_rate                    = 100;
      game.npc_projectile_spawn_rate         = 50;
      game.victory_kills                     = 32;
      game.victory_spawened                  = 0;
      game.victory_score                     = 0;
   }
   if (level_no == 13)
   {
      game.level                             = level_no;
      game.level_npc_type                    = 13;
      game.level_boss_level                  = false;
      game.music_track                       = 1;
      game.background_scroll[0].image        = 69;
      game.background_scroll[1].image        = 69;
      game.background_scroll[2].image        = 85;
      game.background_scroll[3].image        = 85;
      game.background_scroll[0].scroll_rate  = 0.0025f;
      game.background_scroll[1].scroll_rate  = 0.0025f;
      game.background_scroll[2].scroll_rate  = 0.00025f;
      game.background_scroll[3].scroll_rate  = 0.00025f;
      game.background_scroll[0].x_pos        =-2.0f;
      game.background_scroll[1].x_pos        = 2.00199f;
      game.background_scroll[2].x_pos        = 0.0f;
      game.background_scroll[3].x_pos        = 4.0f;
      game.speed                             = 0.110f;
      game.npc_spawn_rate                    = 100;
      game.npc_projectile_spawn_rate         = 50;
      game.victory_kills                     = 32;
      game.victory_spawened                  = 0;
      game.victory_score                     = 0;
   }
   if (level_no == 14)
   {
      game.level                             = level_no;
      game.level_npc_type                    = 14;
      game.level_boss_level                  = false;
      game.music_track                       = 1;
      game.background_scroll[0].image        = 69;
      game.background_scroll[1].image        = 69;
      game.background_scroll[2].image        = 84;
      game.background_scroll[3].image        = 84;
      game.background_scroll[0].scroll_rate  = 0.0025f;
      game.background_scroll[1].scroll_rate  = 0.0025f;
      game.background_scroll[2].scroll_rate  = 0.00025f;
      game.background_scroll[3].scroll_rate  = 0.00025f;
      game.background_scroll[0].x_pos        =-2.0f;
      game.background_scroll[1].x_pos        = 2.00199f;
      game.background_scroll[2].x_pos        = 0.0f;
      game.background_scroll[3].x_pos        = 4.0f;
      game.speed                             = 0.115f;
      game.npc_spawn_rate                    = 100;
      game.npc_projectile_spawn_rate         = 50;
      game.victory_kills                     = 32;
      game.victory_spawened                  = 0;
      game.victory_score                     = 0;
   }
   if (level_no == 15)
   {
      game.level                             = level_no;
      game.level_npc_type                    = 15;
      game.level_boss_level                  = true;
      game.music_track                       = 1;
      game.background_scroll[0].image        = 65;
      game.background_scroll[1].image        = 65;
      game.background_scroll[2].image        = 83;
      game.background_scroll[3].image        = 83;
      game.background_scroll[0].scroll_rate  = 0.0025f;
      game.background_scroll[1].scroll_rate  = 0.0025f;
      game.background_scroll[2].scroll_rate  = 0.00025f;
      game.background_scroll[3].scroll_rate  = 0.00025f;
      game.background_scroll[0].x_pos        =-2.0f;
      game.background_scroll[1].x_pos        = 2.00199f;
      game.background_scroll[2].x_pos        = 0.0f;
      game.background_scroll[3].x_pos        = 4.0f;
      game.speed                             = 0.120f;
      game.npc_spawn_rate                    = 100;
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
      game.music_track                       = 1;
      game.background_scroll[0].image        = 70;
      game.background_scroll[1].image        = 70;
      game.background_scroll[2].image        = 82;
      game.background_scroll[3].image        = 82;
      game.background_scroll[0].scroll_rate  = 0.0025f;
      game.background_scroll[1].scroll_rate  = 0.0025f;
      game.background_scroll[2].scroll_rate  = 0.00025f;
      game.background_scroll[3].scroll_rate  = 0.00025f;
      game.background_scroll[0].x_pos        =-2.0f;
      game.background_scroll[1].x_pos        = 2.00199f;
      game.background_scroll[2].x_pos        = 0.0f;
      game.background_scroll[3].x_pos        = 4.0f;
      game.speed                             = 0.125f;
      game.npc_spawn_rate                    = 100;
      game.npc_projectile_spawn_rate         = 50;
      game.victory_kills                     = 10;
      game.victory_spawened                  = 0;
      game.victory_score                     = 0;
   }
   if (level_no == 17)
   {
      game.level                             = level_no;
      game.level_npc_type                    = 17;
      game.level_boss_level                  = false;
      game.music_track                       = 1;
      game.background_scroll[0].image        = 70;
      game.background_scroll[1].image        = 70;
      game.background_scroll[2].image        = 81;
      game.background_scroll[3].image        = 81;
      game.background_scroll[0].scroll_rate  = 0.0025f;
      game.background_scroll[1].scroll_rate  = 0.0025f;
      game.background_scroll[2].scroll_rate  = 0.00025f;
      game.background_scroll[3].scroll_rate  = 0.00025f;
      game.background_scroll[0].x_pos        =-2.0f;
      game.background_scroll[1].x_pos        = 2.00199f;
      game.background_scroll[2].x_pos        = 0.0f;
      game.background_scroll[3].x_pos        = 4.0f;
      game.speed                             = 0.130f;
      game.npc_spawn_rate                    = 100;
      game.npc_projectile_spawn_rate         = 50;
      game.victory_kills                     = 10;
      game.victory_spawened                  = 0;
      game.victory_score                     = 0;
   }
   if (level_no == 18)
   {
      game.level                             = level_no;
      game.level_npc_type                    = 18;
      game.level_boss_level                  = false;
      game.music_track                       = 1;
      game.background_scroll[0].image        = 70;
      game.background_scroll[1].image        = 70;
      game.background_scroll[2].image        = 80;
      game.background_scroll[3].image        = 80;
      game.background_scroll[0].scroll_rate  = 0.0025f;
      game.background_scroll[1].scroll_rate  = 0.0025f;
      game.background_scroll[2].scroll_rate  = 0.00025f;
      game.background_scroll[3].scroll_rate  = 0.00025f;
      game.background_scroll[0].x_pos        =-2.0f;
      game.background_scroll[1].x_pos        = 2.00199f;
      game.background_scroll[2].x_pos        = 0.0f;
      game.background_scroll[3].x_pos        = 4.0f;
      game.speed                             = 0.135f;
      game.npc_spawn_rate                    = 100;
      game.npc_projectile_spawn_rate         = 50;
      game.victory_kills                     = 10;
      game.victory_spawened                  = 0;
      game.victory_score                     = 0;
   }
   if (level_no == 19)
   {
      game.level                             = level_no;
      game.level_npc_type                    = 19;
      game.level_boss_level                  = true;
      game.music_track                       = 1;
      game.background_scroll[0].image        = 70;
      game.background_scroll[1].image        = 70;
      game.background_scroll[2].image        = 79;
      game.background_scroll[3].image        = 79;
      game.background_scroll[0].scroll_rate  = 0.0025f;
      game.background_scroll[1].scroll_rate  = 0.0025f;
      game.background_scroll[2].scroll_rate  = 0.00025f;
      game.background_scroll[3].scroll_rate  = 0.00025f;
      game.background_scroll[0].x_pos        =-2.0f;
      game.background_scroll[1].x_pos        = 2.00199f;
      game.background_scroll[2].x_pos        = 0.0f;
      game.background_scroll[3].x_pos        = 4.0f;
      game.speed                             = 0.140f;
      game.npc_spawn_rate                    = 100;
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
      game.music_track                       = 1;
      game.background_scroll[0].image        = 71;
      game.background_scroll[1].image        = 71;
      game.background_scroll[2].image        = 78;
      game.background_scroll[3].image        = 78;
      game.background_scroll[0].scroll_rate  = 0.0025f;
      game.background_scroll[1].scroll_rate  = 0.0025f;
      game.background_scroll[2].scroll_rate  = 0.00025f;
      game.background_scroll[3].scroll_rate  = 0.00025f;
      game.background_scroll[0].x_pos        =-2.0f;
      game.background_scroll[1].x_pos        = 2.00199f;
      game.background_scroll[2].x_pos        = 0.0f;
      game.background_scroll[3].x_pos        = 4.0f;
      game.speed                             = 0.145f;
      game.npc_spawn_rate                    = 100;
      game.npc_projectile_spawn_rate         = 50;
      game.victory_kills                     = 10;
      game.victory_spawened                  = 0;
      game.victory_score                     = 0;
   }
   if (level_no == 21)
   {
      game.level                             = level_no;
      game.level_npc_type                    = 21;
      game.level_boss_level                  = false;
      game.music_track                       = 1;
      game.background_scroll[0].image        = 71;
      game.background_scroll[1].image        = 71;
      game.background_scroll[2].image        = 77;
      game.background_scroll[3].image        = 77;
      game.background_scroll[0].scroll_rate  = 0.0025f;
      game.background_scroll[1].scroll_rate  = 0.0025f;
      game.background_scroll[2].scroll_rate  = 0.00025f;
      game.background_scroll[3].scroll_rate  = 0.00025f;
      game.background_scroll[0].x_pos        =-2.0f;
      game.background_scroll[1].x_pos        = 2.00199f;
      game.background_scroll[2].x_pos        = 0.0f;
      game.background_scroll[3].x_pos        = 4.0f;
      game.speed                             = 0.150f;
      game.npc_spawn_rate                    = 100;
      game.npc_projectile_spawn_rate         = 50;
      game.victory_kills                     = 10;
      game.victory_spawened                  = 0;
      game.victory_score                     = 0;
   }
   if (level_no == 22)
   {
      game.level                             = level_no;
      game.level_npc_type                    = 22;
      game.level_boss_level                  = false;
      game.music_track                       = 1;
      game.background_scroll[0].image        = 71;
      game.background_scroll[1].image        = 71;
      game.background_scroll[2].image        = 76;
      game.background_scroll[3].image        = 76;
      game.background_scroll[0].scroll_rate  = 0.0025f;
      game.background_scroll[1].scroll_rate  = 0.0025f;
      game.background_scroll[2].scroll_rate  = 0.00025f;
      game.background_scroll[3].scroll_rate  = 0.00025f;
      game.background_scroll[0].x_pos        =-2.0f;
      game.background_scroll[1].x_pos        = 2.00199f;
      game.background_scroll[2].x_pos        = 0.0f;
      game.background_scroll[3].x_pos        = 4.0f;
      game.speed                             = 0.155f;
      game.npc_spawn_rate                    = 100;
      game.npc_projectile_spawn_rate         = 50;
      game.victory_kills                     = 10;
      game.victory_spawened                  = 0;
      game.victory_score                     = 0;
   }
   if (level_no == 23)
   {
      game.level                             = level_no;
      game.level_npc_type                    = 23;
      game.level_boss_level                  = true;
      game.music_track                       = 1;
      game.background_scroll[0].image        = 71;
      game.background_scroll[1].image        = 71;
      game.background_scroll[2].image        = 75;
      game.background_scroll[3].image        = 75;
      game.background_scroll[0].scroll_rate  = 0.0025f;
      game.background_scroll[1].scroll_rate  = 0.0025f;
      game.background_scroll[2].scroll_rate  = 0.00025f;
      game.background_scroll[3].scroll_rate  = 0.00025f;
      game.background_scroll[0].x_pos        =-2.0f;
      game.background_scroll[1].x_pos        = 2.00199f;
      game.background_scroll[2].x_pos        = 0.0f;
      game.background_scroll[3].x_pos        = 4.0f;
      game.speed                             = 0.160f;
      game.npc_spawn_rate                    = 100;
      game.npc_projectile_spawn_rate         = 50;
      game.victory_kills                     = 1;
      game.victory_spawened                  = 0;
      game.victory_score                     = 0;
   }
   if (level_no == 24)
   {
      game.level                             = level_no;
      game.level_npc_type                    = 24;
      game.level_boss_level                  = true;
      game.music_track                       = 1;
      game.background_scroll[0].image        = 72;
      game.background_scroll[1].image        = 72;
      game.background_scroll[2].image        = 74;
      game.background_scroll[3].image        = 74;
      game.background_scroll[0].scroll_rate  = 0.0025f;
      game.background_scroll[1].scroll_rate  = 0.0025f;
      game.background_scroll[2].scroll_rate  = 0.00025f;
      game.background_scroll[3].scroll_rate  = 0.00025f;
      game.background_scroll[0].x_pos        =-2.0f;
      game.background_scroll[1].x_pos        = 2.00199f;
      game.background_scroll[2].x_pos        = 0.0f;
      game.background_scroll[3].x_pos        = 4.0f;
      game.speed                             = 0.165f;
      game.npc_spawn_rate                    = 100;
      game.npc_projectile_spawn_rate         = 50;
      game.victory_kills                     = 1;
      game.victory_spawened                  = 0;
      game.victory_score                     = 0;
   }
   init_npcs(game.level_npc_type);
   return(0);
};
