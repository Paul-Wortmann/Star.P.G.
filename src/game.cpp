/* Copyright (C) 2011 Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
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
 */

#include <SDL/SDL.h>
#include "game.h"
#include "config.h"
#include "sounds.h"
#include "music.h"
#include "textures.h"
#include "physics.h"
#include "misc.h"
#include "font.h"

extern config_data_type config_data;
extern sound_type       sound[MAX_SOUNDS];
extern music_type       music[MAX_MUSIC];
extern texture_type     texture[MAX_TEXTURES];
       game_type        game;

int init_game(void)
{
   for (int count =0;count < MAX_BACKGROUNDS;count++)
   {
      game.background_scroll[count].x_dir        = 0;
      game.background_scroll[count].y_dir        = 0;
      game.background_scroll[count].x_pos        = 0.0f;
      game.background_scroll[count].y_pos        = 0.0f;
      game.background_scroll[count].scroll_rate  = 0.0005f;
      game.background_scroll[count].image        = 119;
   }
   game.joystick_sensitivity              = 6400;
   game.gamepad_button_0                  = false;
   game.gamepad_button_1                  = false;
   game.gamepad_button_2                  = false;
   game.gamepad_button_3                  = false;
   game.button_up                         = false;
   game.button_down                       = false;
   game.button_left                       = false;
   game.button_right                      = false;
   game.cheats_enabled                    = false;
   game.anc_enabled                       = false;
   game.fps_enabled                       = false;
   game.game_paused                       = false;
   game.game_active                       = false;
   game.game_resume                       = false;
   game.outr_active                       = false;
   game.menu_active                       = true;
   game.pdie_active                       = false;
   game.nlvl_active                       = false;
   game.npc_damage_duration               = 10;
   game.exp_rate                          = 5;
   game.coin_spawn_rate                   = 16384;
   game.wexp_spawn_rate                   = 24576;
   game.npc_spawn_rate                    = 256;
   game.npc_spawn_rate_count              = 0;
   game.paused.active                     = false;
   game.music_track                       = 0;
   game.menu_music_track                  = 26;
   game.nlvl_music_track                  = 27;
   game.pdie_music_track                  = 28;
   game.score                             = 0;
   game.kills                             = 0;
   game.level_kills                       = 0;
   game.level_spawened                    = 0;
   game.level_score                       = 0;
   game.victory_kills                     = 0;
   game.victory_spawened                  = 0;
   game.victory_score                     = 0;
   game.level_end_count                   = 0;
   game.level_end_time_out                = 300;
   game.level_end_time                    = false;
   game.level_end_phase                   = 0;
   game.level_end_display_active          = false;
   game.powerups_spawened                 = false;
   game.completed                         = 0;
   game.speed                             = 0.045f;
   game.fw_rof_count                      = 0;
   game.sw_rof_count                      = 0;
   game.player.x_pos                      =-0.9f;
   game.player.y_pos                      = 0.0f;
   game.player.width                      = 0.2f;
   game.player.hight                      = 0.2f;
   game.player.health                     = 0.100f;
   game.player.health_regen_rate          = 0.00005f;
   game.player.max_health                 = 0.100f;
   game.player.image                      = 278;
   game.player.front_weapon               = 0;
   game.player.side_weapon                = 0;
   game.player.front_shield               = -1;
   game.player.thrusters                  = -1;
   game.achivement.score                  = 0;
   game.achivement.kills                  = 0;
   game.achivement.score_level_1          = 625;
   game.achivement.score_level_2          = 1250;
   game.achivement.score_level_3          = 2500;
   game.achivement.score_level_4          = 5000;
   game.achivement.score_level_5          = 10000;
   game.achivement.kills_level_1          = 128;
   game.achivement.kills_level_2          = 256;
   game.achivement.kills_level_3          = 512;
   game.achivement.kills_level_4          = 1024;
   game.achivement.kills_level_5          = 2048;

   for (int count =0;count < MAX_BULLETS;count++)
   {
      game.player.bullet[count].active         =  false;
      game.player.bullet[count].x_pos          = -2.0f;
      game.player.bullet[count].y_pos          = -2.0f;
      game.player.bullet[count].x_speed        =  0.0f;
      game.player.bullet[count].y_speed        =  0.0f;
      game.player.bullet[count].width          =  0.05f;
      game.player.bullet[count].hight          =  0.05f;
      game.player.bullet[count].warhead        =  0;
      game.player.bullet[count].location       =  0;
      game.player.bullet[count].wave_hight     =  0.125f;
      game.player.bullet[count].wave_count     =  0.0f;
      game.player.bullet[count].wave_speed     =  0.0035f;
      game.player.bullet[count].wave_direction =  1;
   }
   game.projectile[ 0].name[0]       = 'B';
   game.projectile[ 0].name[1]       = 'l';
   game.projectile[ 0].name[2]       = 'a';
   game.projectile[ 0].name[3]       = 's';
   game.projectile[ 0].name[4]       = 't';
   game.projectile[ 0].name[5]       = 'e';
   game.projectile[ 0].name[6]       = 'r';
   game.projectile[ 0].name[7]       = 's';
   game.projectile[ 0].active        = true;
   game.projectile[ 0].level         = 0;
   game.projectile[ 0].experience    = 0;
   game.projectile[ 0].level_1       = 1024.0f;
   game.projectile[ 0].level_2       = 2048.0f;
   game.projectile[ 0].level_3       = 4096.0f;
   game.projectile[ 0].image         = 222;
   game.projectile[ 0].sound         = 7;
   game.projectile[ 0].damage        = 2.5f;
   game.projectile[ 0].speed         = 0.0015f;
   game.projectile[ 0].health        = 10;
   game.projectile[ 0].rate_of_fire  = 25;
   game.projectile[ 0].movement      = 3;
   game.projectile[ 0].wave_size     = 0.125f;
   game.projectile[ 0].wave_velocity = 0.00015f;
   game.projectile[ 0].size          = 0.075f;

   game.projectile[ 1].name[0]       = 'C';
   game.projectile[ 1].name[1]       = 'h';
   game.projectile[ 1].name[2]       = 'a';
   game.projectile[ 1].name[3]       = 'i';
   game.projectile[ 1].name[4]       = 'n';
   game.projectile[ 1].name[5]       = ' ';
   game.projectile[ 1].name[6]       = 'g';
   game.projectile[ 1].name[7]       = 'u';
   game.projectile[ 1].name[8]       = 'n';
   game.projectile[ 1].name[9]       = 's';
   game.projectile[ 1].active        = false;
   game.projectile[ 1].level         = 0;
   game.projectile[ 1].experience    = 0;
   game.projectile[ 1].level_1       = 2048.0f;
   game.projectile[ 1].level_2       = 4096.0f;
   game.projectile[ 1].level_3       = 8192.0f;
   game.projectile[ 1].image         = 223;
   game.projectile[ 1].sound         = 8;
   game.projectile[ 1].damage        = 6;
   game.projectile[ 1].speed         = 0.01f;
   game.projectile[ 1].health        = 10;
   game.projectile[ 1].rate_of_fire  = 23;
   game.projectile[ 1].movement      = 2;
   game.projectile[ 1].wave_size     = 0.125f;
   game.projectile[ 1].wave_velocity = 0.0035f;
   game.projectile[ 1].size          = 0.05f;

   game.projectile[ 2].name[0]       = 'B';
   game.projectile[ 2].name[1]       = 'u';
   game.projectile[ 2].name[2]       = 'r';
   game.projectile[ 2].name[3]       = 's';
   game.projectile[ 2].name[4]       = 't';
   game.projectile[ 2].name[5]       = ' ';
   game.projectile[ 2].name[6]       = 'l';
   game.projectile[ 2].name[7]       = 'a';
   game.projectile[ 2].name[8]       = 's';
   game.projectile[ 2].name[9]       = 'e';
   game.projectile[ 2].name[10]      = 'r';
   game.projectile[ 2].name[11]      = 's';
   game.projectile[ 2].active        = false;
   game.projectile[ 2].level         = 0;
   game.projectile[ 2].experience    = 0;
   game.projectile[ 2].level_1       = 4096.0f;
   game.projectile[ 2].level_2       = 8192.0f;
   game.projectile[ 2].level_3       = 16384.0f;
   game.projectile[ 2].image         = 224;
   game.projectile[ 2].sound         = 9;
   game.projectile[ 2].damage        = 7;
   game.projectile[ 2].speed         = 0.015f;
   game.projectile[ 2].health        = 10;
   game.projectile[ 2].rate_of_fire  = 21;
   game.projectile[ 2].movement      = 0;
   game.projectile[ 2].wave_size     = 0.125f;
   game.projectile[ 2].wave_velocity = 0.00015f;
   game.projectile[ 2].size          = 0.05f;

   game.projectile[ 3].name[0]       = 'R';
   game.projectile[ 3].name[1]       = 'a';
   game.projectile[ 3].name[2]       = 'i';
   game.projectile[ 3].name[3]       = 'l';
   game.projectile[ 3].name[4]       = ' ';
   game.projectile[ 3].name[5]       = 't';
   game.projectile[ 3].name[6]       = 'u';
   game.projectile[ 3].name[7]       = 'r';
   game.projectile[ 3].name[8]       = 'r';
   game.projectile[ 3].name[9]       = 'e';
   game.projectile[ 3].name[10]      = 't';
   game.projectile[ 3].name[11]      = 's';
   game.projectile[ 3].active        = false;
   game.projectile[ 3].level         = 0;
   game.projectile[ 3].experience    = 0;
   game.projectile[ 3].level_1       = 8192.0f;
   game.projectile[ 3].level_2       = 16384.0f;
   game.projectile[ 3].level_3       = 32768.0f;
   game.projectile[ 3].image         = 225;
   game.projectile[ 3].sound         = 10;
   game.projectile[ 3].damage        = 8;
   game.projectile[ 3].speed         = 0.02f;
   game.projectile[ 3].health        = 10;
   game.projectile[ 3].rate_of_fire  = 19;
   game.projectile[ 3].movement      = 0;
   game.projectile[ 3].wave_size     = 0.125f;
   game.projectile[ 3].wave_velocity = 0.0035f;
   game.projectile[ 3].size          = 0.05f;

   game.projectile[ 4].name[0]       = 'P';
   game.projectile[ 4].name[1]       = 'l';
   game.projectile[ 4].name[2]       = 'a';
   game.projectile[ 4].name[3]       = 's';
   game.projectile[ 4].name[4]       = 'm';
   game.projectile[ 4].name[5]       = 'a';
   game.projectile[ 4].name[6]       = ' ';
   game.projectile[ 4].name[7]       = 'r';
   game.projectile[ 4].name[8]       = 'o';
   game.projectile[ 4].name[9]       = 'c';
   game.projectile[ 4].name[10]      = 'k';
   game.projectile[ 4].name[11]      = 'e';
   game.projectile[ 4].name[12]      = 't';
   game.projectile[ 4].name[13]      = 's';
   game.projectile[ 4].active        = false;
   game.projectile[ 4].level         = 0;
   game.projectile[ 4].experience    = 0;
   game.projectile[ 4].level_1       = 16384.0f;
   game.projectile[ 4].level_2       = 32768.0f;
   game.projectile[ 4].level_3       = 65536.0f;
   game.projectile[ 4].image         = 226;
   game.projectile[ 4].sound         = 11;
   game.projectile[ 4].damage        = 9;
   game.projectile[ 4].speed         = 0.025f;
   game.projectile[ 4].health        = 10;
   game.projectile[ 4].rate_of_fire  = 17;
   game.projectile[ 4].movement      = 1;
   game.projectile[ 4].wave_size     = 0.125f;
   game.projectile[ 4].wave_velocity = 0.0035f;
   game.projectile[ 4].size          = 0.05f;

   game.projectile[ 5].name[0]       = 'I';
   game.projectile[ 5].name[1]       = 'o';
   game.projectile[ 5].name[2]       = 'n';
   game.projectile[ 5].name[3]       = ' ';
   game.projectile[ 5].name[4]       = 'c';
   game.projectile[ 5].name[5]       = 'a';
   game.projectile[ 5].name[6]       = 'n';
   game.projectile[ 5].name[7]       = 'n';
   game.projectile[ 5].name[8]       = 'o';
   game.projectile[ 5].name[9]       = 'n';
   game.projectile[ 5].name[10]      = 's';
   game.projectile[ 5].active        = false;
   game.projectile[ 5].level         = 0;
   game.projectile[ 5].experience    = 0;
   game.projectile[ 5].level_1       = 32768.0f;
   game.projectile[ 5].level_2       = 65536.0f;
   game.projectile[ 5].level_3       = 131072.0f;
   game.projectile[ 5].image         = 227;
   game.projectile[ 5].sound         = 12;
   game.projectile[ 5].damage        = 10;
   game.projectile[ 5].speed         = 0.03f;
   game.projectile[ 5].health        = 10;
   game.projectile[ 5].rate_of_fire  = 15;
   game.projectile[ 5].movement      = 0;
   game.projectile[ 5].wave_size     = 0.125f;
   game.projectile[ 5].wave_velocity = 0.0035f;
   game.projectile[ 5].size          = 0.05f;

   game.projectile[ 6].name[0]       = 'E';
   game.projectile[ 6].name[1]       = 'n';
   game.projectile[ 6].name[2]       = 'e';
   game.projectile[ 6].name[3]       = 'm';
   game.projectile[ 6].name[4]       = 'y';
   game.projectile[ 6].name[5]       = ' ';
   game.projectile[ 6].name[6]       = 'l';
   game.projectile[ 6].name[7]       = 'a';
   game.projectile[ 6].name[8]       = 's';
   game.projectile[ 6].name[9]       = 'e';
   game.projectile[ 6].name[10]      = 'r';
   game.projectile[ 6].active        = false;
   game.projectile[ 6].level         = 0;
   game.projectile[ 6].experience    = 0;
   game.projectile[ 6].level_1       = 0.0f;
   game.projectile[ 6].level_2       = 0.0f;
   game.projectile[ 6].level_3       = 0.0f;
   game.projectile[ 6].image         = 228;
   game.projectile[ 6].sound         = 23;
   game.projectile[ 6].damage        = 0.0125f;
   game.projectile[ 6].speed         = 0.0075f;
   game.projectile[ 6].health        = 5;
   game.projectile[ 6].rate_of_fire  = 5;
   game.projectile[ 6].movement      = 0;
   game.projectile[ 6].wave_size     = 0.125f;
   game.projectile[ 6].wave_velocity = 0.0035f;
   game.projectile[ 6].size          = 0.05f;

   game.projectile[ 7].name[0]       = 'E';
   game.projectile[ 7].name[1]       = 'n';
   game.projectile[ 7].name[2]       = 'e';
   game.projectile[ 7].name[3]       = 'm';
   game.projectile[ 7].name[4]       = 'y';
   game.projectile[ 7].name[5]       = ' ';
   game.projectile[ 7].name[6]       = 'l';
   game.projectile[ 7].name[7]       = 'a';
   game.projectile[ 7].name[8]       = 's';
   game.projectile[ 7].name[9]       = 'e';
   game.projectile[ 7].name[10]      = 'r';
   game.projectile[ 7].active        = false;
   game.projectile[ 7].level         = 0;
   game.projectile[ 7].experience    = 0;
   game.projectile[ 7].level_1       = 0.0f;
   game.projectile[ 7].level_2       = 0.0f;
   game.projectile[ 7].level_3       = 0.0f;
   game.projectile[ 7].image         = 229;
   game.projectile[ 7].sound         = 24;
   game.projectile[ 7].damage        = 0.025f;
   game.projectile[ 7].speed         = 0.0080f;
   game.projectile[ 7].health        = 5;
   game.projectile[ 7].rate_of_fire  = 5;
   game.projectile[ 7].movement      = 0;
   game.projectile[ 7].wave_size     = 0.125f;
   game.projectile[ 7].wave_velocity = 0.0035f;
   game.projectile[ 7].size          = 0.05f;

   game.projectile[ 8].name[0]       = 'E';
   game.projectile[ 8].name[1]       = 'n';
   game.projectile[ 8].name[2]       = 'e';
   game.projectile[ 8].name[3]       = 'm';
   game.projectile[ 8].name[4]       = 'y';
   game.projectile[ 8].name[5]       = ' ';
   game.projectile[ 8].name[6]       = 'l';
   game.projectile[ 8].name[7]       = 'a';
   game.projectile[ 8].name[8]       = 's';
   game.projectile[ 8].name[9]       = 'e';
   game.projectile[ 8].name[10]      = 'r';
   game.projectile[ 8].active        = false;
   game.projectile[ 8].level         = 0;
   game.projectile[ 8].experience    = 0;
   game.projectile[ 8].level_1       = 0.0f;
   game.projectile[ 8].level_2       = 0.0f;
   game.projectile[ 8].level_3       = 0.0f;
   game.projectile[ 8].image         = 230;
   game.projectile[ 8].sound         = 25;
   game.projectile[ 8].damage        = 0.0375f;
   game.projectile[ 8].speed         = 0.0075f;
   game.projectile[ 8].health        = 5;
   game.projectile[ 8].rate_of_fire  = 5;
   game.projectile[ 8].movement      = 0;
   game.projectile[ 8].wave_size     = 0.125f;
   game.projectile[ 8].wave_velocity = 0.0035f;
   game.projectile[ 8].size          = 0.05f;

   game.projectile[ 9].name[0]       = 'E';
   game.projectile[ 9].name[1]       = 'n';
   game.projectile[ 9].name[2]       = 'e';
   game.projectile[ 9].name[3]       = 'm';
   game.projectile[ 9].name[4]       = 'y';
   game.projectile[ 9].name[5]       = ' ';
   game.projectile[ 9].name[6]       = 'l';
   game.projectile[ 9].name[7]       = 'a';
   game.projectile[ 9].name[8]       = 's';
   game.projectile[ 9].name[9]       = 'e';
   game.projectile[ 9].name[10]      = 'r';
   game.projectile[ 9].active        = false;
   game.projectile[ 9].level         = 0;
   game.projectile[ 9].experience    = 0;
   game.projectile[ 9].level_1       = 0.0f;
   game.projectile[ 9].level_2       = 0.0f;
   game.projectile[ 9].level_3       = 0.0f;
   game.projectile[ 9].image         = 231;
   game.projectile[ 9].sound         = 26;
   game.projectile[ 9].damage        = 0.05f;
   game.projectile[ 9].speed         = 0.0075f;
   game.projectile[ 9].health        = 10;
   game.projectile[ 9].rate_of_fire  = 5;
   game.projectile[ 9].movement      = 2;
   game.projectile[ 9].wave_size     = 0.125f;
   game.projectile[ 9].wave_velocity = 0.0035f;
   game.projectile[ 9].size          = 0.05f;

   game.projectile[10].name[0]       = 'E';
   game.projectile[10].name[1]       = 'n';
   game.projectile[10].name[2]       = 'e';
   game.projectile[10].name[3]       = 'm';
   game.projectile[10].name[4]       = 'y';
   game.projectile[10].name[5]       = ' ';
   game.projectile[10].name[6]       = 'l';
   game.projectile[10].name[7]       = 'a';
   game.projectile[10].name[8]       = 's';
   game.projectile[10].name[9]       = 'e';
   game.projectile[10].name[10]      = 'r';
   game.projectile[10].active        = false;
   game.projectile[10].level         = 0;
   game.projectile[10].experience    = 0;
   game.projectile[10].level_1       = 0.0f;
   game.projectile[10].level_2       = 0.0f;
   game.projectile[10].level_3       = 0.0f;
   game.projectile[10].image         = 232;
   game.projectile[10].sound         = 27;
   game.projectile[10].damage        = 0.0625f;
   game.projectile[10].speed         = 0.0075f;
   game.projectile[10].health        = 5;
   game.projectile[10].rate_of_fire  = 5;
   game.projectile[10].movement      = 2;
   game.projectile[10].wave_size     = 0.125f;
   game.projectile[10].wave_velocity = 0.0035f;
   game.projectile[10].size          = 0.05f;

   game.projectile[11].name[0]       = 'E';
   game.projectile[11].name[1]       = 'n';
   game.projectile[11].name[2]       = 'e';
   game.projectile[11].name[3]       = 'm';
   game.projectile[11].name[4]       = 'y';
   game.projectile[11].name[5]       = ' ';
   game.projectile[11].name[6]       = 'l';
   game.projectile[11].name[7]       = 'a';
   game.projectile[11].name[8]       = 's';
   game.projectile[11].name[9]       = 'e';
   game.projectile[11].name[10]      = 'r';
   game.projectile[11].active        = false;
   game.projectile[11].level         = 0;
   game.projectile[11].experience    = 0;
   game.projectile[11].level_1       = 0.0f;
   game.projectile[11].level_2       = 0.0f;
   game.projectile[11].level_3       = 0.0f;
   game.projectile[11].image         = 233;
   game.projectile[11].sound         = 28;
   game.projectile[11].damage        = 0.075f;
   game.projectile[11].speed         = 0.0075f;
   game.projectile[11].health        = 5;
   game.projectile[11].rate_of_fire  = 5;
   game.projectile[11].movement      = 2;
   game.projectile[11].wave_size     = 0.085f;
   game.projectile[11].wave_velocity = 0.0065f;
   game.projectile[11].size          = 0.05f;

   game.projectile[12].name[0]       = 'E';
   game.projectile[12].name[1]       = 'n';
   game.projectile[12].name[2]       = 'e';
   game.projectile[12].name[3]       = 'm';
   game.projectile[12].name[4]       = 'y';
   game.projectile[12].name[5]       = ' ';
   game.projectile[12].name[6]       = 'l';
   game.projectile[12].name[7]       = 'a';
   game.projectile[12].name[8]       = 's';
   game.projectile[12].name[9]       = 'e';
   game.projectile[12].name[10]      = 'r';
   game.projectile[12].active        = false;
   game.projectile[12].level         = 0;
   game.projectile[12].experience    = 0;
   game.projectile[12].level_1       = 0.0f;
   game.projectile[12].level_2       = 0.0f;
   game.projectile[12].level_3       = 0.0f;
   game.projectile[12].image         = 234;
   game.projectile[12].sound         = 29;
   game.projectile[12].damage        = 0.0875f;
   game.projectile[12].speed         = 0.0075f;
   game.projectile[12].health        = 5;
   game.projectile[12].rate_of_fire  = 5;
   game.projectile[12].movement      = 2;
   game.projectile[12].wave_size     = 0.125f;
   game.projectile[12].wave_velocity = 0.0035f;
   game.projectile[12].size          = 0.05f;

   game.projectile[13].name[0]       = 'E';
   game.projectile[13].name[1]       = 'n';
   game.projectile[13].name[2]       = 'e';
   game.projectile[13].name[3]       = 'm';
   game.projectile[13].name[4]       = 'y';
   game.projectile[13].name[5]       = ' ';
   game.projectile[13].name[6]       = 'l';
   game.projectile[13].name[7]       = 'a';
   game.projectile[13].name[8]       = 's';
   game.projectile[13].name[9]       = 'e';
   game.projectile[13].name[10]      = 'r';
   game.projectile[13].active        = false;
   game.projectile[13].level         = 0;
   game.projectile[13].experience    = 0;
   game.projectile[13].level_1       = 0.0f;
   game.projectile[13].level_2       = 0.0f;
   game.projectile[13].level_3       = 0.0f;
   game.projectile[13].image         = 235;
   game.projectile[13].sound         = 30;
   game.projectile[13].damage        = 0.500f;
   game.projectile[13].speed         = 0.0175f;
   game.projectile[13].health        = 25;
   game.projectile[13].rate_of_fire  = 5;
   game.projectile[13].movement      = 2;
   game.projectile[13].wave_size     = 0.125f;
   game.projectile[13].wave_velocity = 0.0035f;
   game.projectile[13].size          = 0.05f;

   game.projectile[14].name[0]       = 'E';
   game.projectile[14].name[1]       = 'n';
   game.projectile[14].name[2]       = 'e';
   game.projectile[14].name[3]       = 'm';
   game.projectile[14].name[4]       = 'y';
   game.projectile[14].name[5]       = ' ';
   game.projectile[14].name[6]       = 'l';
   game.projectile[14].name[7]       = 'a';
   game.projectile[14].name[8]       = 's';
   game.projectile[14].name[9]       = 'e';
   game.projectile[14].name[10]      = 'r';
   game.projectile[14].active        = false;
   game.projectile[14].level         = 0;
   game.projectile[14].experience    = 0;
   game.projectile[14].level_1       = 0.0f;
   game.projectile[14].level_2       = 0.0f;
   game.projectile[14].level_3       = 0.0f;
   game.projectile[14].image         = 236;
   game.projectile[14].sound         = 31;
   game.projectile[14].damage        = 0.1125f;
   game.projectile[14].speed         = 0.0075f;
   game.projectile[14].health        = 5;
   game.projectile[14].rate_of_fire  = 5;
   game.projectile[14].movement      = 0;
   game.projectile[14].wave_size     = 0.125f;
   game.projectile[14].wave_velocity = 0.0035f;
   game.projectile[14].size          = 0.05f;

   game.projectile[15].name[0]       = 'E';
   game.projectile[15].name[1]       = 'n';
   game.projectile[15].name[2]       = 'e';
   game.projectile[15].name[3]       = 'm';
   game.projectile[15].name[4]       = 'y';
   game.projectile[15].name[5]       = ' ';
   game.projectile[15].name[6]       = 'l';
   game.projectile[15].name[7]       = 'a';
   game.projectile[15].name[8]       = 's';
   game.projectile[15].name[9]       = 'e';
   game.projectile[15].name[10]      = 'r';
   game.projectile[15].active        = false;
   game.projectile[15].level         = 0;
   game.projectile[15].experience    = 0;
   game.projectile[15].level_1       = 0.0f;
   game.projectile[15].level_2       = 0.0f;
   game.projectile[15].level_3       = 0.0f;
   game.projectile[15].image         = 237;
   game.projectile[15].sound         = 32;
   game.projectile[15].damage        = 0.125f;
   game.projectile[15].speed         = 0.0075f;
   game.projectile[15].health        = 5;
   game.projectile[15].rate_of_fire  = 5;
   game.projectile[15].movement      = 1;
   game.projectile[15].wave_size     = 0.125f;
   game.projectile[15].wave_velocity = 0.0035f;
   game.projectile[15].size          = 0.05f;

   game.projectile[16].name[0]       = 'E';
   game.projectile[16].name[1]       = 'n';
   game.projectile[16].name[2]       = 'e';
   game.projectile[16].name[3]       = 'm';
   game.projectile[16].name[4]       = 'y';
   game.projectile[16].name[5]       = ' ';
   game.projectile[16].name[6]       = 'l';
   game.projectile[16].name[7]       = 'a';
   game.projectile[16].name[8]       = 's';
   game.projectile[16].name[9]       = 'e';
   game.projectile[16].name[10]      = 'r';
   game.projectile[16].active        = false;
   game.projectile[16].level         = 0;
   game.projectile[16].experience    = 0;
   game.projectile[16].level_1       = 0.0f;
   game.projectile[16].level_2       = 0.0f;
   game.projectile[16].level_3       = 0.0f;
   game.projectile[16].image         = 238;
   game.projectile[16].sound         = 33;
   game.projectile[16].damage        = 0.1375f;
   game.projectile[16].speed         = 0.0075f;
   game.projectile[16].health        = 5;
   game.projectile[16].rate_of_fire  = 5;
   game.projectile[16].movement      = 0;
   game.projectile[16].wave_size     = 0.125f;
   game.projectile[16].wave_velocity = 0.0035f;
   game.projectile[16].size          = 0.05f;

   game.projectile[17].name[0]       = 'E';
   game.projectile[17].name[1]       = 'n';
   game.projectile[17].name[2]       = 'e';
   game.projectile[17].name[3]       = 'm';
   game.projectile[17].name[4]       = 'y';
   game.projectile[17].name[5]       = ' ';
   game.projectile[17].name[6]       = 'l';
   game.projectile[17].name[7]       = 'a';
   game.projectile[17].name[8]       = 's';
   game.projectile[17].name[9]       = 'e';
   game.projectile[17].name[10]      = 'r';
   game.projectile[17].active        = false;
   game.projectile[17].level         = 0;
   game.projectile[17].experience    = 0;
   game.projectile[17].level_1       = 0.0f;
   game.projectile[17].level_2       = 0.0f;
   game.projectile[17].level_3       = 0.0f;
   game.projectile[17].image         = 239;
   game.projectile[17].sound         = 34;
   game.projectile[17].damage        = 0.75f;
   game.projectile[17].speed         = 0.0175f;
   game.projectile[17].health        = 5;
   game.projectile[17].rate_of_fire  = 5;
   game.projectile[17].movement      = 1;
   game.projectile[17].wave_size     = 0.125f;
   game.projectile[17].wave_velocity = 0.0035f;
   game.projectile[17].size          = 0.05f;

   game.projectile[18].name[0]       = 'E';
   game.projectile[18].name[1]       = 'n';
   game.projectile[18].name[2]       = 'e';
   game.projectile[18].name[3]       = 'm';
   game.projectile[18].name[4]       = 'y';
   game.projectile[18].name[5]       = ' ';
   game.projectile[18].name[6]       = 'l';
   game.projectile[18].name[7]       = 'a';
   game.projectile[18].name[8]       = 's';
   game.projectile[18].name[9]       = 'e';
   game.projectile[18].name[10]      = 'r';
   game.projectile[18].active        = false;
   game.projectile[18].level         = 0;
   game.projectile[18].experience    = 0;
   game.projectile[18].level_1       = 0.0f;
   game.projectile[18].level_2       = 0.0f;
   game.projectile[18].level_3       = 0.0f;
   game.projectile[18].image         = 240;
   game.projectile[18].sound         = 35;
   game.projectile[18].damage        = 0.1625f;
   game.projectile[18].speed         = 0.0075f;
   game.projectile[18].health        = 5;
   game.projectile[18].rate_of_fire  = 5;
   game.projectile[18].movement      = 1;
   game.projectile[18].wave_size     = 0.125f;
   game.projectile[18].wave_velocity = 0.0035f;
   game.projectile[18].size          = 0.05f;

   game.projectile[19].name[0]       = 'E';
   game.projectile[19].name[1]       = 'n';
   game.projectile[19].name[2]       = 'e';
   game.projectile[19].name[3]       = 'm';
   game.projectile[19].name[4]       = 'y';
   game.projectile[19].name[5]       = ' ';
   game.projectile[19].name[6]       = 'l';
   game.projectile[19].name[7]       = 'a';
   game.projectile[19].name[8]       = 's';
   game.projectile[19].name[9]       = 'e';
   game.projectile[19].name[10]      = 'r';
   game.projectile[19].active        = false;
   game.projectile[19].level         = 0;
   game.projectile[19].experience    = 0;
   game.projectile[19].level_1       = 0.0f;
   game.projectile[19].level_2       = 0.0f;
   game.projectile[19].level_3       = 0.0f;
   game.projectile[19].image         = 241;
   game.projectile[19].sound         = 36;
   game.projectile[19].damage        = 0.175f;
   game.projectile[19].speed         = 0.0075f;
   game.projectile[19].health        = 5;
   game.projectile[19].rate_of_fire  = 5;
   game.projectile[19].movement      = 0;
   game.projectile[19].wave_size     = 0.125f;
   game.projectile[19].wave_velocity = 0.0035f;
   game.projectile[19].size          = 0.05f;

   game.projectile[20].name[0]       = 'E';
   game.projectile[20].name[1]       = 'n';
   game.projectile[20].name[2]       = 'e';
   game.projectile[20].name[3]       = 'm';
   game.projectile[20].name[4]       = 'y';
   game.projectile[20].name[5]       = ' ';
   game.projectile[20].name[6]       = 'l';
   game.projectile[20].name[7]       = 'a';
   game.projectile[20].name[8]       = 's';
   game.projectile[20].name[9]       = 'e';
   game.projectile[20].name[10]      = 'r';
   game.projectile[20].active        = false;
   game.projectile[20].level         = 0;
   game.projectile[20].experience    = 0;
   game.projectile[20].level_1       = 0.0f;
   game.projectile[20].level_2       = 0.0f;
   game.projectile[20].level_3       = 0.0f;
   game.projectile[20].image         = 242;
   game.projectile[20].sound         = 37;
   game.projectile[20].damage        = 0.1875f;
   game.projectile[20].speed         = 0.0075f;
   game.projectile[20].health        = 5;
   game.projectile[20].rate_of_fire  = 5;
   game.projectile[20].movement      = 0;
   game.projectile[20].wave_size     = 0.125f;
   game.projectile[20].wave_velocity = 0.0035f;
   game.projectile[20].size          = 0.05f;

   game.projectile[21].name[0]       = 'E';
   game.projectile[21].name[1]       = 'n';
   game.projectile[21].name[2]       = 'e';
   game.projectile[21].name[3]       = 'm';
   game.projectile[21].name[4]       = 'y';
   game.projectile[21].name[5]       = ' ';
   game.projectile[21].name[6]       = 'l';
   game.projectile[21].name[7]       = 'a';
   game.projectile[21].name[8]       = 's';
   game.projectile[21].name[9]       = 'e';
   game.projectile[21].name[10]      = 'r';
   game.projectile[21].active        = false;
   game.projectile[21].level         = 0;
   game.projectile[21].experience    = 0;
   game.projectile[21].level_1       = 0.0f;
   game.projectile[21].level_2       = 0.0f;
   game.projectile[21].level_3       = 0.0f;
   game.projectile[21].image         = 243;
   game.projectile[21].sound         = 38;
   game.projectile[21].damage        = 0.86f;
   game.projectile[21].speed         = 0.0225f;
   game.projectile[21].health        = 5;
   game.projectile[21].rate_of_fire  = 3;
   game.projectile[21].movement      = 3;
   game.projectile[21].wave_size     = 0.125f;
   game.projectile[21].wave_velocity = 0.0035f;
   game.projectile[21].size          = 0.05f;

   game.projectile[22].name[0]       = 'E';
   game.projectile[22].name[1]       = 'n';
   game.projectile[22].name[2]       = 'e';
   game.projectile[22].name[3]       = 'm';
   game.projectile[22].name[4]       = 'y';
   game.projectile[22].name[5]       = ' ';
   game.projectile[22].name[6]       = 'l';
   game.projectile[22].name[7]       = 'a';
   game.projectile[22].name[8]       = 's';
   game.projectile[22].name[9]       = 'e';
   game.projectile[22].name[10]      = 'r';
   game.projectile[22].active        = false;
   game.projectile[22].level         = 0;
   game.projectile[22].experience    = 0;
   game.projectile[22].level_1       = 0.0f;
   game.projectile[22].level_2       = 0.0f;
   game.projectile[22].level_3       = 0.0f;
   game.projectile[22].image         = 244;
   game.projectile[22].sound         = 39;
   game.projectile[22].damage        = 0.2125f;
   game.projectile[22].speed         = 0.0075f;
   game.projectile[22].health        = 5;
   game.projectile[22].rate_of_fire  = 5;
   game.projectile[22].movement      = 0;
   game.projectile[22].wave_size     = 0.125f;
   game.projectile[22].wave_velocity = 0.0035f;
   game.projectile[22].size          = 0.05f;

   game.projectile[23].name[0]       = 'E';
   game.projectile[23].name[1]       = 'n';
   game.projectile[23].name[2]       = 'e';
   game.projectile[23].name[3]       = 'm';
   game.projectile[23].name[4]       = 'y';
   game.projectile[23].name[5]       = ' ';
   game.projectile[23].name[6]       = 'l';
   game.projectile[23].name[7]       = 'a';
   game.projectile[23].name[8]       = 's';
   game.projectile[23].name[9]       = 'e';
   game.projectile[23].name[10]      = 'r';
   game.projectile[23].active        = false;
   game.projectile[23].level         = 0;
   game.projectile[23].experience    = 0;
   game.projectile[23].level_1       = 0.0f;
   game.projectile[23].level_2       = 0.0f;
   game.projectile[23].level_3       = 0.0f;
   game.projectile[23].image         = 245;
   game.projectile[23].sound         = 40;
   game.projectile[23].damage        = 0.225f;
   game.projectile[23].speed         = 0.0075f;
   game.projectile[23].health        = 5;
   game.projectile[23].rate_of_fire  = 5;
   game.projectile[23].movement      = 0;
   game.projectile[23].wave_size     = 0.125f;
   game.projectile[23].wave_velocity = 0.0035f;
   game.projectile[23].size          = 0.05f;

   game.projectile[24].name[0]       = 'E';
   game.projectile[24].name[1]       = 'n';
   game.projectile[24].name[2]       = 'e';
   game.projectile[24].name[3]       = 'm';
   game.projectile[24].name[4]       = 'y';
   game.projectile[24].name[5]       = ' ';
   game.projectile[24].name[6]       = 'l';
   game.projectile[24].name[7]       = 'a';
   game.projectile[24].name[8]       = 's';
   game.projectile[24].name[9]       = 'e';
   game.projectile[24].name[10]      = 'r';
   game.projectile[24].active        = false;
   game.projectile[24].level         = 0;
   game.projectile[24].experience    = 0;
   game.projectile[24].level_1       = 0.0f;
   game.projectile[24].level_2       = 0.0f;
   game.projectile[24].level_3       = 0.0f;
   game.projectile[24].image         = 246;
   game.projectile[24].sound         = 41;
   game.projectile[24].damage        = 0.2375f;
   game.projectile[24].speed         = 0.0075f;
   game.projectile[24].health        = 5;
   game.projectile[24].rate_of_fire  = 5;
   game.projectile[24].movement      = 0;
   game.projectile[24].wave_size     = 0.125f;
   game.projectile[24].wave_velocity = 0.0035f;
   game.projectile[24].size          = 0.05f;

   game.projectile[25].name[0]       = 'E';
   game.projectile[25].name[1]       = 'n';
   game.projectile[25].name[2]       = 'e';
   game.projectile[25].name[3]       = 'm';
   game.projectile[25].name[4]       = 'y';
   game.projectile[25].name[5]       = ' ';
   game.projectile[25].name[6]       = 'l';
   game.projectile[25].name[7]       = 'a';
   game.projectile[25].name[8]       = 's';
   game.projectile[25].name[9]       = 'e';
   game.projectile[25].name[10]      = 'r';
   game.projectile[25].active        = false;
   game.projectile[25].level         = 0;
   game.projectile[25].experience    = 0;
   game.projectile[25].level_1       = 0.0f;
   game.projectile[25].level_2       = 0.0f;
   game.projectile[25].level_3       = 0.0f;
   game.projectile[25].image         = 247;
   game.projectile[25].sound         = 42;
   game.projectile[25].damage        = 0.25f;
   game.projectile[25].speed         = 0.0075f;
   game.projectile[25].health        = 5;
   game.projectile[25].rate_of_fire  = 5;
   game.projectile[25].movement      = 0;
   game.projectile[25].wave_size     = 0.125f;
   game.projectile[25].wave_velocity = 0.0035f;
   game.projectile[25].size          = 0.05f;

   game.projectile[26].name[0]       = 'E';
   game.projectile[26].name[1]       = 'n';
   game.projectile[26].name[2]       = 'e';
   game.projectile[26].name[3]       = 'm';
   game.projectile[26].name[4]       = 'y';
   game.projectile[26].name[5]       = ' ';
   game.projectile[26].name[6]       = 'l';
   game.projectile[26].name[7]       = 'a';
   game.projectile[26].name[8]       = 's';
   game.projectile[26].name[9]       = 'e';
   game.projectile[26].name[10]      = 'r';
   game.projectile[26].active        = false;
   game.projectile[26].level         = 0;
   game.projectile[26].experience    = 0;
   game.projectile[26].level_1       = 0.0f;
   game.projectile[26].level_2       = 0.0f;
   game.projectile[26].level_3       = 0.0f;
   game.projectile[26].image         = 248;
   game.projectile[26].sound         = 43;
   game.projectile[26].damage        = 0.2625f;
   game.projectile[26].speed         = 0.0075f;
   game.projectile[26].health        = 5;
   game.projectile[26].rate_of_fire  = 5;
   game.projectile[26].movement      = 0;
   game.projectile[26].wave_size     = 0.125f;
   game.projectile[26].wave_velocity = 0.0035f;
   game.projectile[26].size          = 0.05f;

   game.projectile[27].name[0]       = 'E';
   game.projectile[27].name[1]       = 'n';
   game.projectile[27].name[2]       = 'e';
   game.projectile[27].name[3]       = 'm';
   game.projectile[27].name[4]       = 'y';
   game.projectile[27].name[5]       = ' ';
   game.projectile[27].name[6]       = 'l';
   game.projectile[27].name[7]       = 'a';
   game.projectile[27].name[8]       = 's';
   game.projectile[27].name[9]       = 'e';
   game.projectile[27].name[10]      = 'r';
   game.projectile[27].active        = false;
   game.projectile[27].level         = 0;
   game.projectile[27].experience    = 0;
   game.projectile[27].level_1       = 0.0f;
   game.projectile[27].level_2       = 0.0f;
   game.projectile[27].level_3       = 0.0f;
   game.projectile[27].image         = 249;
   game.projectile[27].sound         = 44;
   game.projectile[27].damage        = 0.275f;
   game.projectile[27].speed         = 0.0075f;
   game.projectile[27].health        = 5;
   game.projectile[27].rate_of_fire  = 5;
   game.projectile[27].movement      = 0;
   game.projectile[27].wave_size     = 0.125f;
   game.projectile[27].wave_velocity = 0.0035f;
   game.projectile[27].size          = 0.05f;

   game.projectile[28].name[0]       = 'E';
   game.projectile[28].name[1]       = 'n';
   game.projectile[28].name[2]       = 'e';
   game.projectile[28].name[3]       = 'm';
   game.projectile[28].name[4]       = 'y';
   game.projectile[28].name[5]       = ' ';
   game.projectile[28].name[6]       = 'l';
   game.projectile[28].name[7]       = 'a';
   game.projectile[28].name[8]       = 's';
   game.projectile[28].name[9]       = 'e';
   game.projectile[28].name[10]      = 'r';
   game.projectile[28].active        = false;
   game.projectile[28].level         = 0;
   game.projectile[28].experience    = 0;
   game.projectile[28].level_1       = 0.0f;
   game.projectile[28].level_2       = 0.0f;
   game.projectile[28].level_3       = 0.0f;
   game.projectile[28].image         = 250;
   game.projectile[28].sound         = 45;
   game.projectile[28].damage        = 0.2875f;
   game.projectile[28].speed         = 0.0075f;
   game.projectile[28].health        = 5;
   game.projectile[28].rate_of_fire  = 5;
   game.projectile[28].movement      = 0;
   game.projectile[28].wave_size     = 0.125f;
   game.projectile[28].wave_velocity = 0.0035f;
   game.projectile[28].size          = 0.05f;

   game.projectile[29].name[0]       = 'E';
   game.projectile[29].name[1]       = 'n';
   game.projectile[29].name[2]       = 'e';
   game.projectile[29].name[3]       = 'm';
   game.projectile[29].name[4]       = 'y';
   game.projectile[29].name[5]       = ' ';
   game.projectile[29].name[6]       = 'l';
   game.projectile[29].name[7]       = 'a';
   game.projectile[29].name[8]       = 's';
   game.projectile[29].name[9]       = 'e';
   game.projectile[29].name[10]      = 'r';
   game.projectile[29].active        = false;
   game.projectile[29].level         = 0;
   game.projectile[29].experience    = 0;
   game.projectile[29].level_1       = 0.0f;
   game.projectile[29].level_2       = 0.0f;
   game.projectile[29].level_3       = 0.0f;
   game.projectile[29].image         = 251;
   game.projectile[29].sound         = 46;
   game.projectile[29].damage        = 0.3f;
   game.projectile[29].speed         = 0.0075f;
   game.projectile[29].health        = 5;
   game.projectile[29].rate_of_fire  = 5;
   game.projectile[29].movement      = 0;
   game.projectile[29].wave_size     = 0.125f;
   game.projectile[29].wave_velocity = 0.0035f;
   game.projectile[29].size          = 0.05f;

   game.projectile[30].name[0]       = 'E';
   game.projectile[30].name[1]       = 'n';
   game.projectile[30].name[2]       = 'e';
   game.projectile[30].name[3]       = 'm';
   game.projectile[30].name[4]       = 'y';
   game.projectile[30].name[5]       = ' ';
   game.projectile[30].name[6]       = 'l';
   game.projectile[30].name[7]       = 'a';
   game.projectile[30].name[8]       = 's';
   game.projectile[30].name[9]       = 'e';
   game.projectile[30].name[10]      = 'r';
   game.projectile[30].active        = false;
   game.projectile[30].level         = 0;
   game.projectile[30].experience    = 0;
   game.projectile[30].level_1       = 0.0f;
   game.projectile[30].level_2       = 0.0f;
   game.projectile[30].level_3       = 0.0f;
   game.projectile[30].image         = 252;
   game.projectile[30].sound         = 47;
   game.projectile[30].damage        = 0.3125f;
   game.projectile[30].speed         = 0.0175f;
   game.projectile[30].health        = 5;
   game.projectile[30].rate_of_fire  = 2;
   game.projectile[30].movement      = 1;
   game.projectile[30].wave_size     = 0.125f;
   game.projectile[30].wave_velocity = 0.0035f;
   game.projectile[30].size          = 0.05f;

   game.shield[0].name[0]          = 'T';
   game.shield[0].name[1]          = 'e';
   game.shield[0].name[2]          = 'r';
   game.shield[0].name[3]          = 'b';
   game.shield[0].name[4]          = 'i';
   game.shield[0].name[5]          = 'u';
   game.shield[0].name[6]          = 'm';
   game.shield[0].name[7]          = ' ';
   game.shield[0].name[8]          = 's';
   game.shield[0].name[9]          = 'h';
   game.shield[0].name[10]         = 'i';
   game.shield[0].name[11]         = 'e';
   game.shield[0].name[12]         = 'l';
   game.shield[0].name[13]         = 'd';
   game.shield[0].name[14]         = 's';
   game.shield[0].active           = false;
   game.shield[0].level            = 0;
   game.shield[0].level_1          = 256;
   game.shield[0].level_2          = 512;
   game.shield[0].level_3          = 1024;
   game.shield[0].experience       = 0;
   game.shield[0].image            = 217;
   game.shield[0].absorption       = 0.0005f;
   game.shield[1].name[0]          = 'I';
   game.shield[1].name[1]          = 'r';
   game.shield[1].name[2]          = 'i';
   game.shield[1].name[3]          = 'd';
   game.shield[1].name[4]          = 'i';
   game.shield[1].name[5]          = 'u';
   game.shield[1].name[6]          = 'm';
   game.shield[1].name[7]          = ' ';
   game.shield[1].name[8]          = 's';
   game.shield[1].name[9]          = 'h';
   game.shield[1].name[10]         = 'i';
   game.shield[1].name[11]         = 'e';
   game.shield[1].name[12]         = 'l';
   game.shield[1].name[13]         = 'd';
   game.shield[1].name[14]         = 's';
   game.shield[1].active           = false;
   game.shield[1].level            = 0;
   game.shield[1].level_1          = 512;
   game.shield[1].level_2          = 1024;
   game.shield[1].level_3          = 2048;
   game.shield[1].experience       = 0;
   game.shield[1].image            = 218;
   game.shield[1].absorption       = 0.0010f;
   game.shield[2].name[0]          = 'R';
   game.shield[2].name[1]          = 'u';
   game.shield[2].name[2]          = 'b';
   game.shield[2].name[3]          = 'i';
   game.shield[2].name[4]          = 'd';
   game.shield[2].name[5]          = 'i';
   game.shield[2].name[6]          = 'u';
   game.shield[2].name[7]          = 'm';
   game.shield[2].name[8]          = ' ';
   game.shield[2].name[9]          = 's';
   game.shield[2].name[10]         = 'h';
   game.shield[2].name[11]         = 'i';
   game.shield[2].name[12]         = 'e';
   game.shield[2].name[13]         = 'l';
   game.shield[2].name[14]         = 'd';
   game.shield[2].name[15]         = 's';
   game.shield[2].active           = false;
   game.shield[2].level            = 0;
   game.shield[2].level_1          = 1024;
   game.shield[2].level_2          = 2048;
   game.shield[2].level_3          = 4096;
   game.shield[2].experience       = 0;
   game.shield[2].image            = 219;
   game.shield[2].absorption       = 0.0015f;
   game.shield[3].name[0]          = 'T';
   game.shield[3].name[1]          = 'a';
   game.shield[3].name[2]          = 'n';
   game.shield[3].name[3]          = 't';
   game.shield[3].name[4]          = 'a';
   game.shield[3].name[5]          = 'l';
   game.shield[3].name[6]          = 'u';
   game.shield[3].name[7]          = 'm';
   game.shield[3].name[8]          = ' ';
   game.shield[3].name[9]          = 's';
   game.shield[3].name[10]         = 'h';
   game.shield[3].name[11]         = 'i';
   game.shield[3].name[12]         = 'e';
   game.shield[3].name[13]         = 'l';
   game.shield[3].name[14]         = 'd';
   game.shield[3].name[15]         = 's';
   game.shield[3].active           = false;
   game.shield[3].level            = 0;
   game.shield[3].level_1          = 2048;
   game.shield[3].level_2          = 4096;
   game.shield[3].level_3          = 8192;
   game.shield[3].experience       = 0;
   game.shield[3].image            = 220;
   game.shield[3].absorption       = 0.0020f;
   game.shield[4].name[0]          = 'A';
   game.shield[4].name[1]          = 'c';
   game.shield[4].name[2]          = 't';
   game.shield[4].name[3]          = 'i';
   game.shield[4].name[4]          = 'n';
   game.shield[4].name[5]          = 'i';
   game.shield[4].name[6]          = 'u';
   game.shield[4].name[7]          = 'm';
   game.shield[4].name[8]          = ' ';
   game.shield[4].name[9]          = 's';
   game.shield[4].name[10]         = 'h';
   game.shield[4].name[11]         = 'i';
   game.shield[4].name[12]         = 'e';
   game.shield[4].name[13]         = 'l';
   game.shield[4].name[14]         = 'd';
   game.shield[4].name[15]         = 's';
   game.shield[4].active           = false;
   game.shield[4].level            = 0;
   game.shield[4].level_1          = 4096;
   game.shield[4].level_2          = 8192;
   game.shield[4].level_3          = 16384;
   game.shield[4].experience       = 0;
   game.shield[4].image            = 221;
   game.shield[4].absorption       = 0.0025f;

   game.thruster[0].name[0]        = 'M';
   game.thruster[0].name[1]        = 'a';
   game.thruster[0].name[2]        = 'e';
   game.thruster[0].name[3]        = 'l';
   game.thruster[0].name[4]        = 's';
   game.thruster[0].name[5]        = 't';
   game.thruster[0].name[6]        = 'r';
   game.thruster[0].name[7]        = 'o';
   game.thruster[0].name[8]        = 'm';
   game.thruster[0].name[9]        = ' ';
   game.thruster[0].name[10]       = 't';
   game.thruster[0].name[11]       = 'h';
   game.thruster[0].name[12]       = 'r';
   game.thruster[0].name[13]       = 'u';
   game.thruster[0].name[14]       = 's';
   game.thruster[0].name[15]       = 't';
   game.thruster[0].name[16]       = 'e';
   game.thruster[0].name[17]       = 'r';
   game.thruster[0].name[18]       = 's';
   game.thruster[0].active         = false;
   game.thruster[0].level          = 0;
   game.thruster[0].level_1        = 256;
   game.thruster[0].level_2        = 512;
   game.thruster[0].level_3        = 1024;
   game.thruster[0].experience     = 0;
   game.thruster[0].image          = 279;
   game.thruster[0].thrust         = 0.002f;
   game.thruster[1].name[0]        = 'S';
   game.thruster[1].name[1]        = 'e';
   game.thruster[1].name[2]        = 'i';
   game.thruster[1].name[3]        = 's';
   game.thruster[1].name[4]        = 'm';
   game.thruster[1].name[5]        = 'i';
   game.thruster[1].name[6]        = 'c';
   game.thruster[1].name[7]        = ' ';
   game.thruster[1].name[8]        = 't';
   game.thruster[1].name[9]        = 'h';
   game.thruster[1].name[10]       = 'r';
   game.thruster[1].name[11]       = 'u';
   game.thruster[1].name[12]       = 's';
   game.thruster[1].name[13]       = 't';
   game.thruster[1].name[14]       = 'e';
   game.thruster[1].name[15]       = 'r';
   game.thruster[1].name[16]       = 's';
   game.thruster[1].active         = false;
   game.thruster[1].level          = 0;
   game.thruster[1].level_1        = 512;
   game.thruster[1].level_2        = 1024;
   game.thruster[1].level_3        = 2048;
   game.thruster[1].experience     = 0;
   game.thruster[1].image          = 280;
   game.thruster[1].thrust         = 0.004f;
   game.thruster[2].name[0]        = 'V';
   game.thruster[2].name[1]        = 'o';
   game.thruster[2].name[2]        = 'r';
   game.thruster[2].name[3]        = 't';
   game.thruster[2].name[4]        = 'e';
   game.thruster[2].name[5]        = 'x';
   game.thruster[2].name[6]        = ' ';
   game.thruster[2].name[7]        = 't';
   game.thruster[2].name[8]        = 'h';
   game.thruster[2].name[9]        = 'r';
   game.thruster[2].name[10]       = 'u';
   game.thruster[2].name[11]       = 's';
   game.thruster[2].name[12]       = 't';
   game.thruster[2].name[13]       = 'e';
   game.thruster[2].name[14]       = 'r';
   game.thruster[2].name[15]       = 's';
   game.thruster[2].active         = false;
   game.thruster[2].level          = 0;
   game.thruster[2].level_1        = 1024;
   game.thruster[2].level_2        = 2048;
   game.thruster[2].level_3        = 4096;
   game.thruster[2].experience     = 0;
   game.thruster[2].image          = 281;
   game.thruster[2].thrust         = 0.006f;
   game.thruster[3].name[0]        = 'C';
   game.thruster[3].name[1]        = 'o';
   game.thruster[3].name[2]        = 'n';
   game.thruster[3].name[3]        = 'v';
   game.thruster[3].name[4]        = 'o';
   game.thruster[3].name[5]        = 'l';
   game.thruster[3].name[6]        = 'u';
   game.thruster[3].name[7]        = 't';
   game.thruster[3].name[8]        = 'i';
   game.thruster[3].name[9]        = 'o';
   game.thruster[3].name[10]       = 'n';
   game.thruster[3].name[11]       = ' ';
   game.thruster[3].name[12]       = 't';
   game.thruster[3].name[13]       = 'h';
   game.thruster[3].name[14]       = 'r';
   game.thruster[3].name[15]       = 'u';
   game.thruster[3].name[16]       = 's';
   game.thruster[3].name[17]       = 't';
   game.thruster[3].name[18]       = 'e';
   game.thruster[3].name[19]       = 'r';
   game.thruster[3].name[20]       = 's';
   game.thruster[3].active         = false;
   game.thruster[3].level          = 0;
   game.thruster[3].level_1        = 2048;
   game.thruster[3].level_2        = 4096;
   game.thruster[3].level_3        = 8192;
   game.thruster[3].experience     = 0;
   game.thruster[3].image          = 336;
   game.thruster[3].thrust         = 0.008f;

   for (int count =0;count < MAX_EXPLOSIONS;count++)
   {
      game.explosion[count].active  = false;
      game.explosion[count].frame   = 0;
      game.explosion[count].image   = 185;
      game.explosion[count].sound   = 5;
      game.explosion[count].x_pos   = 0.0f;
      game.explosion[count].y_pos   = 0.0f;
      game.explosion[count].width   = 0.25f;
      game.explosion[count].hight   = 0.25f;
   }
   game.enemy[0 ].image       = 253;
   game.enemy[0 ].health      = 05.0f;
   game.enemy[0 ].movement    = 0;//move staright forward
   game.enemy[0 ].weapon      = 6;
   game.enemy[0 ].projectiles = 1;
   game.enemy[0 ].size_h      = 0.15f;
   game.enemy[0 ].size_w      = 0.15f;
   game.enemy[0 ].sound       = 0;
   game.enemy[0 ].speed       = (game.projectile[game.enemy[0 ].weapon].speed/2);
   game.enemy[1 ].image       = 254;
   game.enemy[1 ].health      = 10.0f;
   game.enemy[1 ].movement    = 7;//move to position player was in on spawn
   game.enemy[1 ].weapon      = 7;
   game.enemy[1 ].projectiles = 2;
   game.enemy[1 ].size_h      = 0.2f;
   game.enemy[1 ].size_w      = 0.2f;
   game.enemy[1 ].sound       = 0;
   game.enemy[1 ].speed       = (game.projectile[game.enemy[1 ].weapon].speed/2);
   game.enemy[2 ].image       = 255;
   game.enemy[2 ].health      = 15.0f;
   game.enemy[2 ].movement    = 5; //wave motion
   game.enemy[2 ].weapon      = 8;
   game.enemy[2 ].projectiles = 3;
   game.enemy[2 ].size_h      = 0.2f;
   game.enemy[2 ].size_w      = 0.2f;
   game.enemy[2 ].sound       = 0;
   game.enemy[2 ].speed       = (game.projectile[game.enemy[2 ].weapon].speed/2);
   game.enemy[3 ].image       = 256;
   game.enemy[3 ].health      = 100.0f;
   game.enemy[3 ].movement    = 2;//boss, avoid player, move up n down, stay far right  ---- Cantide ----
   game.enemy[3 ].weapon      = 9;
   game.enemy[3 ].projectiles = 6;
   game.enemy[3 ].size_h      = 0.8f;
   game.enemy[3 ].size_w      = 0.4f;
   game.enemy[3 ].sound       = 0;
   game.enemy[3 ].speed       = (game.projectile[game.enemy[3 ].weapon].speed/2);
   game.enemy[4 ].image       = 257;
   game.enemy[4 ].health      = 50.0f;
   game.enemy[4 ].movement    = 5;//wave motion
   game.enemy[4 ].weapon      = 10;
   game.enemy[4 ].projectiles = 2;
   game.enemy[4 ].size_h      = 0.2f;
   game.enemy[4 ].size_w      = 0.2f;
   game.enemy[4 ].sound       = 0;
   game.enemy[4 ].speed       = (game.projectile[game.enemy[4 ].weapon].speed/2);
   game.enemy[5 ].image       = 258;
   game.enemy[5 ].health      = 60.0f;
   game.enemy[5 ].movement    = 3;
   game.enemy[5 ].weapon      = 11;
   game.enemy[5 ].projectiles = 4;
   game.enemy[5 ].size_h      = 0.2f;
   game.enemy[5 ].size_w      = 0.2f;
   game.enemy[5 ].sound       = 0;
   game.enemy[5 ].speed       = (game.projectile[game.enemy[5 ].weapon].speed/2);
   game.enemy[6 ].image       = 259;
   game.enemy[6 ].health      = 70.0f;
   game.enemy[6 ].movement    = 4; // wave
   game.enemy[6 ].weapon      = 12;
   game.enemy[6 ].projectiles = 6;
   game.enemy[6 ].size_h      = 0.2f;
   game.enemy[6 ].size_w      = 0.2f;
   game.enemy[6 ].sound       = 0;
   game.enemy[6 ].speed       = (game.projectile[game.enemy[6 ].weapon].speed/2);
   game.enemy[7 ].image       = 260;
   game.enemy[7 ].health      = 500.0f;
   game.enemy[7 ].movement    = 2;//boss   --- Wrathorn ---
   game.enemy[7 ].weapon      = 13;
   game.enemy[7 ].projectiles = 9;
   game.enemy[7 ].size_h      = 0.8f;
   game.enemy[7 ].size_w      = 0.4f;
   game.enemy[7 ].sound       = 0;
   game.enemy[7 ].speed       = (game.projectile[game.enemy[7 ].weapon].speed/2);
   game.enemy[8 ].image       = 261;
   game.enemy[8 ].health      = 80.0f;
   game.enemy[8 ].movement    = 0; // just move forward only
   game.enemy[8 ].weapon      = 14;
   game.enemy[8 ].projectiles = 2;
   game.enemy[8 ].size_h      = 0.2f;
   game.enemy[8 ].size_w      = 0.2f;
   game.enemy[8 ].sound       = 0;
   game.enemy[8 ].speed       = (game.projectile[game.enemy[8 ].weapon].speed/2);
   game.enemy[9 ].image       = 262;
   game.enemy[9 ].health      = 100.0f;
   game.enemy[9 ].movement    = 1; // home in on player
   game.enemy[9 ].weapon      = 15;
   game.enemy[9 ].projectiles = 4;
   game.enemy[9 ].size_h      = 0.2f;
   game.enemy[9 ].size_w      = 0.2f;
   game.enemy[9 ].sound       = 0;
   game.enemy[9 ].speed       = (game.projectile[game.enemy[9 ].weapon].speed/2);
   game.enemy[10].image       = 263;
   game.enemy[10].health      = 100.0f;
   game.enemy[10].movement    = 6;//fast wave motion
   game.enemy[10].weapon      = 16;
   game.enemy[10].projectiles = 6;
   game.enemy[10].size_h      = 0.2f;
   game.enemy[10].size_w      = 0.2f;
   game.enemy[10].sound       = 0;
   game.enemy[10].speed       = (game.projectile[game.enemy[10].weapon].speed/2);
   game.enemy[11].image       = 264;
   game.enemy[11].health      = 2000.0f;
   game.enemy[11].movement    = 2;//boss
   game.enemy[11].weapon      = 17;
   game.enemy[11].projectiles = 9;
   game.enemy[11].size_h      = 0.8f;
   game.enemy[11].size_w      = 0.4f;
   game.enemy[11].sound       = 0;
   game.enemy[11].speed       = (game.projectile[game.enemy[11].weapon].speed/2);
   game.enemy[12].image       = 265;
   game.enemy[12].health      = 120.0f;
   game.enemy[12].movement    = 4; // wave
   game.enemy[12].weapon      = 18;
   game.enemy[12].projectiles = 2;
   game.enemy[12].size_h      = 0.2f;
   game.enemy[12].size_w      = 0.2f;
   game.enemy[12].sound       = 0;
   game.enemy[12].speed       = (game.projectile[game.enemy[12].weapon].speed/2);   init_powerups();
   game.enemy[13].image       = 266;
   game.enemy[13].health      = 120.0f;
   game.enemy[13].movement    = 0; // only forward
   game.enemy[13].weapon      = 19;
   game.enemy[13].projectiles = 3;
   game.enemy[13].size_h      = 0.2f;
   game.enemy[13].size_w      = 0.2f;
   game.enemy[13].sound       = 0;
   game.enemy[13].speed       = (game.projectile[game.enemy[13].weapon].speed/2);   init_powerups();
   game.enemy[14].image       = 267;
   game.enemy[14].health      = 120.0f;
   game.enemy[14].movement    = 5; // wave action
   game.enemy[14].weapon      = 20;
   game.enemy[14].projectiles = 5;
   game.enemy[14].size_h      = 0.2f;
   game.enemy[14].size_w      = 0.2f;
   game.enemy[14].sound       = 0;
   game.enemy[14].speed       = (game.projectile[game.enemy[14].weapon].speed/2);   init_powerups();
   game.enemy[15].image       = 268;
   game.enemy[15].health      = 2000.0f;
   game.enemy[15].movement    = 2; //boss
   game.enemy[15].weapon      = 21;
   game.enemy[15].projectiles = 9;
   game.enemy[15].size_h      = 0.8f;
   game.enemy[15].size_w      = 0.4f;
   game.enemy[15].sound       = 0;
   game.enemy[15].speed       = (game.projectile[game.enemy[15].weapon].speed/2);
   game.enemy[16].image       = 269;
   game.enemy[16].health      = 130.0f;
   game.enemy[16].movement    = 6; // fast wave action
   game.enemy[16].weapon      = 22;
   game.enemy[16].projectiles = 2;
   game.enemy[16].size_h      = 0.2f;
   game.enemy[16].size_w      = 0.2f;
   game.enemy[16].sound       = 0;
   game.enemy[16].speed       = (game.projectile[game.enemy[16].weapon].speed/2);   init_powerups();
   game.enemy[17].image       = 270;
   game.enemy[17].health      = 140.0f;
   game.enemy[17].movement    = 1; // home in on player
   game.enemy[17].weapon      = 23;
   game.enemy[17].projectiles = 3;
   game.enemy[17].size_h      = 0.2f;
   game.enemy[17].size_w      = 0.2f;
   game.enemy[17].sound       = 0;
   game.enemy[17].speed       = (game.projectile[game.enemy[17].weapon].speed/2);   init_powerups();
   game.enemy[18].image       = 271;
   game.enemy[18].health      = 150.0f;
   game.enemy[18].movement    = 3; // avoid then attack
   game.enemy[18].weapon      = 24;
   game.enemy[18].projectiles = 5;
   game.enemy[18].size_h      = 0.2f;
   game.enemy[18].size_w      = 0.2f;
   game.enemy[18].sound       = 0;
   game.enemy[18].speed       = (game.projectile[game.enemy[18].weapon].speed/2);   init_powerups();
   game.enemy[19].image       = 272;
   game.enemy[19].health      = 3000.0f;
   game.enemy[19].movement    = 2; // boss
   game.enemy[19].weapon      = 25;
   game.enemy[19].projectiles = 9;
   game.enemy[19].size_h      = 0.8f;
   game.enemy[19].size_w      = 0.4f;
   game.enemy[19].sound       = 0;
   game.enemy[19].speed       = (game.projectile[game.enemy[19].weapon].speed/2);   init_npcs(0);
   game.enemy[20].image       = 273;
   game.enemy[20].health      = 150.0f;
   game.enemy[20].movement    = 1;//home in on player
   game.enemy[20].weapon      = 26;
   game.enemy[20].projectiles = 2;
   game.enemy[20].size_h      = 0.2f;
   game.enemy[20].size_w      = 0.2f;
   game.enemy[20].sound       = 0;
   game.enemy[20].speed       = (game.projectile[game.enemy[20].weapon].speed/2);   init_powerups();
   game.enemy[21].image       = 274;
   game.enemy[21].health      = 160.0f;
   game.enemy[21].movement    = 5; // wave action
   game.enemy[21].weapon      = 27;
   game.enemy[21].projectiles = 3;
   game.enemy[21].size_h      = 0.2f;
   game.enemy[21].size_w      = 0.2f;
   game.enemy[21].sound       = 0;
   game.enemy[21].speed       = (game.projectile[game.enemy[21].weapon].speed/2);   init_powerups();
   game.enemy[22].image       = 275;
   game.enemy[22].health      = 170.0f;
   game.enemy[22].movement    = 3; // avoid n attack
   game.enemy[22].weapon      = 28;
   game.enemy[22].projectiles = 5;
   game.enemy[22].size_h      = 0.2f;
   game.enemy[22].size_w      = 0.2f;
   game.enemy[22].sound       = 0;
   game.enemy[22].speed       = (game.projectile[game.enemy[22].weapon].speed/2);   init_powerups();
   game.enemy[23].image       = 276;
   game.enemy[23].health      = 6000.0f;
   game.enemy[23].movement    = 2;
   game.enemy[23].weapon      = 29;
   game.enemy[23].projectiles = 9;
   game.enemy[23].size_h      = 0.8f;
   game.enemy[23].size_w      = 0.4f;
   game.enemy[23].sound       = 0;
   game.enemy[23].speed       = (game.projectile[game.enemy[23].weapon].speed/2);   init_npcs(0);
   game.enemy[24].image       = 277;
   game.enemy[24].health      = 12000.0f;
   game.enemy[24].movement    = 2;
   game.enemy[24].weapon      = 30;
   game.enemy[24].projectiles = 9;
   game.enemy[24].size_h      = 1.2f;
   game.enemy[24].size_w      = 0.8f;
   game.enemy[24].sound       = 0;
   game.enemy[24].speed       = (game.projectile[game.enemy[24].weapon].speed/2);   init_npcs(0);   game.active_npc_count = 0;

   for (int level_no_count = 0;level_no_count < (MAX_LEVELS+1); level_no_count++)
   {
      game.level_locked[level_no_count] = false; /// change me!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!11
   }
   game.level_locked[0] = false;
   initialize_sideships();
   init_waves();
   init_coin();
   init_wexp();
   return(0);
};
/*----------------------------------------------------------------------------*/
int  init_waves     (void)
{
   game.level_waves = 0;
   for(int wave_count = 0; wave_count < MAX_WAVES; wave_count++)
   {
      game.wave[wave_count].active         = false;
      game.wave[wave_count].leader_num     = 0;
      game.wave[wave_count].npc_type       = 0;
      game.wave[wave_count].target_kills   = 0;
      game.wave[wave_count].count_kills    = 0;
      game.wave[wave_count].target_spawned = 0;
      game.wave[wave_count].count_spawned  = 0;
      game.wave[wave_count].spawn_pattern  = 0;
   }
   return(0);
};
/*----------------------------------------------------------------------------*/
int get_next_active_wave(void)
{
    int temp_int = 0;
    for(int wave_count = 0;wave_count < MAX_WAVES;wave_count++)
    {
        if (game.wave[wave_count].active) temp_int = wave_count;
    }
    return(temp_int);
}
/*----------------------------------------------------------------------------*/
int spawn_wave(void)
{
   float temp_float = 0.0f;
   int   wave_count = get_next_active_wave();
   if(game.wave[wave_count].spawn_pattern == 0)
   {
      temp_float = random_GLcoord();
      if (temp_float > ( 1.0f-(game.enemy[game.wave[wave_count].npc_type].size_h*1))) temp_float = ( 1.0f-(game.enemy[game.wave[wave_count].npc_type].size_h*1));
      if (temp_float < (-1.0f+(game.enemy[game.wave[wave_count].npc_type].size_h*1))) temp_float = (-1.0f+(game.enemy[game.wave[wave_count].npc_type].size_h*1));
      spawn_npc(1.0f+game.enemy[game.wave[wave_count].npc_type].size_w,temp_float+game.enemy[game.wave[wave_count].npc_type].size_h,game.wave[wave_count].npc_type,game.wave[wave_count].spawn_pattern,+game.enemy[game.wave[wave_count].npc_type].size_w,+game.enemy[game.wave[wave_count].npc_type].size_h);
      spawn_npc(1.0f,temp_float,game.wave[wave_count].npc_type,game.wave[wave_count].spawn_pattern,0.0f,0.0f);
      spawn_npc(1.0f+game.enemy[game.wave[wave_count].npc_type].size_w,temp_float-game.enemy[game.wave[wave_count].npc_type].size_h,game.wave[wave_count].npc_type,game.wave[wave_count].spawn_pattern,+game.enemy[game.wave[wave_count].npc_type].size_w,-game.enemy[game.wave[wave_count].npc_type].size_h);
      game.level_spawened += 3;
      game.wave_spawnable = false;
   }
   if(game.wave[wave_count].spawn_pattern == 1)
   {
      temp_float = random_GLcoord();
      if (temp_float > ( 1.0f-(game.enemy[game.wave[wave_count].npc_type].size_h*3))) temp_float = ( 1.0f-(game.enemy[game.wave[wave_count].npc_type].size_h*3));
      if (temp_float < (-1.0f+(game.enemy[game.wave[wave_count].npc_type].size_h*3))) temp_float = (-1.0f+(game.enemy[game.wave[wave_count].npc_type].size_h*3));
      spawn_npc(1.0f+(game.enemy[game.wave[wave_count].npc_type].size_w*2),temp_float+(game.enemy[game.wave[wave_count].npc_type].size_h*2),game.wave[wave_count].npc_type,game.wave[wave_count].spawn_pattern,+game.enemy[game.wave[wave_count].npc_type].size_w*2,+game.enemy[game.wave[wave_count].npc_type].size_h*2);
      spawn_npc(1.0f+game.enemy[game.wave[wave_count].npc_type].size_w,temp_float+game.enemy[game.wave[wave_count].npc_type].size_h,game.wave[wave_count].npc_type,game.wave[wave_count].spawn_pattern,+game.enemy[game.wave[wave_count].npc_type].size_w,+game.enemy[game.wave[wave_count].npc_type].size_h);
      spawn_npc(1.0f,temp_float,game.wave[wave_count].npc_type,game.wave[wave_count].spawn_pattern,0.0f,0.0f);
      spawn_npc(1.0f+game.enemy[game.wave[wave_count].npc_type].size_w,temp_float-game.enemy[game.wave[wave_count].npc_type].size_h,game.wave[wave_count].npc_type,game.wave[wave_count].spawn_pattern,+game.enemy[game.wave[wave_count].npc_type].size_w,-game.enemy[game.wave[wave_count].npc_type].size_h);
      spawn_npc(1.0f+(game.enemy[game.wave[wave_count].npc_type].size_w*2),temp_float-(game.enemy[game.wave[wave_count].npc_type].size_h*2),game.wave[wave_count].npc_type,game.wave[wave_count].spawn_pattern,-game.enemy[game.wave[wave_count].npc_type].size_w*2,-game.enemy[game.wave[wave_count].npc_type].size_h*2);
      game.level_spawened += 5;
      game.wave_spawnable = false;
   }
   if(game.wave[wave_count].spawn_pattern == 2)
   {
      temp_float = random_GLcoord();
      if (temp_float > ( 1.0f-(game.enemy[game.wave[wave_count].npc_type].size_h*1))) temp_float = ( 1.0f-(game.enemy[game.wave[wave_count].npc_type].size_h*1));
      if (temp_float < (-1.0f+(game.enemy[game.wave[wave_count].npc_type].size_h*1))) temp_float = (-1.0f+(game.enemy[game.wave[wave_count].npc_type].size_h*1));
      spawn_npc(1.0f+game.enemy[game.wave[wave_count].npc_type].size_w,temp_float+game.enemy[game.wave[wave_count].npc_type].size_h,game.wave[wave_count].npc_type,game.wave[wave_count].spawn_pattern,+game.enemy[game.wave[wave_count].npc_type].size_w,+game.enemy[game.wave[wave_count].npc_type].size_h);
      spawn_npc(1.0f,temp_float,game.wave[wave_count].npc_type,game.wave[wave_count].spawn_pattern,0.0f,0.0f);
      spawn_npc(1.0f+game.enemy[game.wave[wave_count].npc_type].size_w,temp_float-game.enemy[game.wave[wave_count].npc_type].size_h,game.wave[wave_count].npc_type,game.wave[wave_count].spawn_pattern,+game.enemy[game.wave[wave_count].npc_type].size_w,-game.enemy[game.wave[wave_count].npc_type].size_h);
      spawn_npc(1.0f+game.enemy[game.wave[wave_count].npc_type].size_w,temp_float,game.wave[wave_count].npc_type,game.wave[wave_count].spawn_pattern,+game.enemy[game.wave[wave_count].npc_type].size_w,0.0f);
      game.level_spawened += 4;
      game.wave_spawnable = false;
   }
   if(game.wave[wave_count].spawn_pattern == 3)
   {
      temp_float = random_GLcoord();
      if (temp_float > ( 1.0f-(game.enemy[game.wave[wave_count].npc_type].size_h*3))) temp_float = ( 1.0f-(game.enemy[game.wave[wave_count].npc_type].size_h*3));
      if (temp_float < (-1.0f+(game.enemy[game.wave[wave_count].npc_type].size_h*3))) temp_float = (-1.0f+(game.enemy[game.wave[wave_count].npc_type].size_h*3));
      spawn_npc(1.0f+(game.enemy[game.wave[wave_count].npc_type].size_w*3),temp_float+(game.enemy[game.wave[wave_count].npc_type].size_h*1.5f),game.wave[wave_count].npc_type,game.wave[wave_count].spawn_pattern,+game.enemy[game.wave[wave_count].npc_type].size_w*3,+game.enemy[game.wave[wave_count].npc_type].size_h*1.5f);
      spawn_npc(1.0f+(game.enemy[game.wave[wave_count].npc_type].size_w*2),temp_float+(game.enemy[game.wave[wave_count].npc_type].size_h*1.0f),game.wave[wave_count].npc_type,game.wave[wave_count].spawn_pattern,+game.enemy[game.wave[wave_count].npc_type].size_w*2,+game.enemy[game.wave[wave_count].npc_type].size_h*1.0f);
      spawn_npc(1.0f+game.enemy[game.wave[wave_count].npc_type].size_w,temp_float+(game.enemy[game.wave[wave_count].npc_type].size_h*0.5f),game.wave[wave_count].npc_type,game.wave[wave_count].spawn_pattern,+game.enemy[game.wave[wave_count].npc_type].size_w,+game.enemy[game.wave[wave_count].npc_type].size_h*0.5f);
      spawn_npc(1.0f,temp_float,game.wave[wave_count].npc_type,game.wave[wave_count].spawn_pattern,0.0f,0.0f);
      spawn_npc(1.0f+game.enemy[game.wave[wave_count].npc_type].size_w,temp_float-(game.enemy[game.wave[wave_count].npc_type].size_h*0.5f),game.wave[wave_count].npc_type,game.wave[wave_count].spawn_pattern,+game.enemy[game.wave[wave_count].npc_type].size_w,-game.enemy[game.wave[wave_count].npc_type].size_h*0.5f);
      spawn_npc(1.0f+(game.enemy[game.wave[wave_count].npc_type].size_w*2),temp_float-(game.enemy[game.wave[wave_count].npc_type].size_h*1.0f),game.wave[wave_count].npc_type,game.wave[wave_count].spawn_pattern,+game.enemy[game.wave[wave_count].npc_type].size_w*2,-game.enemy[game.wave[wave_count].npc_type].size_h*1.0f);
      spawn_npc(1.0f+(game.enemy[game.wave[wave_count].npc_type].size_w*3),temp_float-(game.enemy[game.wave[wave_count].npc_type].size_h*1.5f),game.wave[wave_count].npc_type,game.wave[wave_count].spawn_pattern,+game.enemy[game.wave[wave_count].npc_type].size_w*3,-game.enemy[game.wave[wave_count].npc_type].size_h*1.5f);
      game.level_spawened += 7;
      game.wave_spawnable = false;
   }
   if(game.wave[wave_count].spawn_pattern == 4)
   {
      temp_float = random_GLcoord();
      if (temp_float > ( 1.0f-(game.enemy[game.wave[wave_count].npc_type].size_h*3))) temp_float = ( 1.0f-(game.enemy[game.wave[wave_count].npc_type].size_h*3));
      if (temp_float < (-1.0f+(game.enemy[game.wave[wave_count].npc_type].size_h*3))) temp_float = (-1.0f+(game.enemy[game.wave[wave_count].npc_type].size_h*3));
      spawn_npc(1.0f+game.enemy[game.wave[wave_count].npc_type].size_w,temp_float+(game.enemy[game.wave[wave_count].npc_type].size_h*0.5f),game.wave[wave_count].npc_type,game.wave[wave_count].spawn_pattern,+game.enemy[game.wave[wave_count].npc_type].size_w,+game.enemy[game.wave[wave_count].npc_type].size_h*0.5f);
      spawn_npc(1.0f,temp_float,game.wave[wave_count].npc_type,game.wave[wave_count].spawn_pattern,0.0f,0.0f);
      spawn_npc(1.0f+game.enemy[game.wave[wave_count].npc_type].size_w,temp_float-(game.enemy[game.wave[wave_count].npc_type].size_h*0.5f),game.wave[wave_count].npc_type,game.wave[wave_count].spawn_pattern,+game.enemy[game.wave[wave_count].npc_type].size_w,-game.enemy[game.wave[wave_count].npc_type].size_h*0.5f);
      game.level_spawened += 3;
      game.wave_spawnable = false;
   }
   if(game.wave[wave_count].spawn_pattern == 5)
   {
      temp_float = random_GLcoord();
      if (temp_float > ( 1.0f-(game.enemy[game.wave[wave_count].npc_type].size_h*3))) temp_float = ( 1.0f-(game.enemy[game.wave[wave_count].npc_type].size_h*3));
      if (temp_float < (-1.0f+(game.enemy[game.wave[wave_count].npc_type].size_h*3))) temp_float = (-1.0f+(game.enemy[game.wave[wave_count].npc_type].size_h*3));
      spawn_npc(1.0f+(game.enemy[game.wave[wave_count].npc_type].size_w*2),temp_float+(game.enemy[game.wave[wave_count].npc_type].size_h*1.0f),game.wave[wave_count].npc_type,game.wave[wave_count].spawn_pattern,game.enemy[game.wave[wave_count].npc_type].size_w*2,+game.enemy[game.wave[wave_count].npc_type].size_h*1.0f);
      spawn_npc(1.0f+game.enemy[game.wave[wave_count].npc_type].size_w,temp_float+(game.enemy[game.wave[wave_count].npc_type].size_h*0.5f),game.wave[wave_count].npc_type,game.wave[wave_count].spawn_pattern,game.enemy[game.wave[wave_count].npc_type].size_w,+game.enemy[game.wave[wave_count].npc_type].size_h*0.5f);
      spawn_npc(1.0f,temp_float,game.wave[wave_count].npc_type,game.wave[wave_count].spawn_pattern,0.0f,0.0f);
      spawn_npc(1.0f+game.enemy[game.wave[wave_count].npc_type].size_w,temp_float-(game.enemy[game.wave[wave_count].npc_type].size_h*0.5f),game.wave[wave_count].npc_type,game.wave[wave_count].spawn_pattern,game.enemy[game.wave[wave_count].npc_type].size_w,-game.enemy[game.wave[wave_count].npc_type].size_h*0.5f);
      spawn_npc(1.0f+(game.enemy[game.wave[wave_count].npc_type].size_w*2),temp_float-(game.enemy[game.wave[wave_count].npc_type].size_h*1.0f),game.wave[wave_count].npc_type,game.wave[wave_count].spawn_pattern,game.enemy[game.wave[wave_count].npc_type].size_w*2,-game.enemy[game.wave[wave_count].npc_type].size_h*1.0f);
      game.level_spawened += 5;
      game.wave_spawnable = false;
   }
   if(game.wave[wave_count].spawn_pattern == 6)
   {
      temp_float = random_GLcoord();
      if (temp_float > ( 1.0f-(game.enemy[game.wave[wave_count].npc_type].size_h*3))) temp_float = ( 1.0f-(game.enemy[game.wave[wave_count].npc_type].size_h*3));
      if (temp_float < (-1.0f+(game.enemy[game.wave[wave_count].npc_type].size_h*3))) temp_float = (-1.0f+(game.enemy[game.wave[wave_count].npc_type].size_h*3));
      spawn_npc(1.0f+(game.enemy[game.wave[wave_count].npc_type].size_w*2),temp_float+(game.enemy[game.wave[wave_count].npc_type].size_h*1.0f),game.wave[wave_count].npc_type,game.wave[wave_count].spawn_pattern,game.enemy[game.wave[wave_count].npc_type].size_w*2,+game.enemy[game.wave[wave_count].npc_type].size_h*1.0f);
      spawn_npc(1.0f,temp_float,game.wave[wave_count].npc_type,game.wave[wave_count].spawn_pattern,0.0f,0.0f);
      spawn_npc(1.0f+game.enemy[game.wave[wave_count].npc_type].size_w,temp_float,game.wave[wave_count].npc_type,game.wave[wave_count].spawn_pattern,game.enemy[game.wave[wave_count].npc_type].size_w,0.0f);
      spawn_npc(1.0f+(game.enemy[game.wave[wave_count].npc_type].size_w*2),temp_float-(game.enemy[game.wave[wave_count].npc_type].size_h*1.0f),game.wave[wave_count].npc_type,game.wave[wave_count].spawn_pattern,game.enemy[game.wave[wave_count].npc_type].size_w*2,-game.enemy[game.wave[wave_count].npc_type].size_h*1.0f);
      game.level_spawened += 4;
      game.wave_spawnable = false;
   }
   if(game.wave[wave_count].spawn_pattern == 7)
   {
      temp_float = random_GLcoord();
      if (temp_float > ( 1.0f-(game.enemy[game.wave[wave_count].npc_type].size_h*3))) temp_float = ( 1.0f-(game.enemy[game.wave[wave_count].npc_type].size_h*3));
      if (temp_float < (-1.0f+(game.enemy[game.wave[wave_count].npc_type].size_h*3))) temp_float = (-1.0f+(game.enemy[game.wave[wave_count].npc_type].size_h*3));
      spawn_npc(1.0f,temp_float,game.wave[wave_count].npc_type,game.wave[wave_count].spawn_pattern,0.0f,0.0f);
      game.level_spawened += 1;
      game.wave_spawnable = false;
   }
   if(game.wave[wave_count].spawn_pattern == 8)
   {
      temp_float = random_GLcoord();
      if (temp_float > ( 1.0f-(game.enemy[game.wave[wave_count].npc_type].size_h*3))) temp_float = ( 1.0f-(game.enemy[game.wave[wave_count].npc_type].size_h*3));
      if (temp_float < (-1.0f+(game.enemy[game.wave[wave_count].npc_type].size_h*3))) temp_float = (-1.0f+(game.enemy[game.wave[wave_count].npc_type].size_h*3));
      spawn_npc(1.0f,temp_float+(game.enemy[game.wave[wave_count].npc_type].size_h*0.5f),game.wave[wave_count].npc_type,game.wave[wave_count].spawn_pattern,0.0f,+game.enemy[game.wave[wave_count].npc_type].size_h*0.5f);
      spawn_npc(1.0f,temp_float-(game.enemy[game.wave[wave_count].npc_type].size_h*0.5f),game.wave[wave_count].npc_type,game.wave[wave_count].spawn_pattern,0.0f,-game.enemy[game.wave[wave_count].npc_type].size_h*0.5f);
      game.level_spawened += 2;
      game.wave_spawnable = false;
   }
   if(game.wave[wave_count].spawn_pattern == 9)
   {
      temp_float = random_GLcoord();
      if (temp_float > ( 1.0f-(game.enemy[game.wave[wave_count].npc_type].size_h*3))) temp_float = ( 1.0f-(game.enemy[game.wave[wave_count].npc_type].size_h*3));
      if (temp_float < (-1.0f+(game.enemy[game.wave[wave_count].npc_type].size_h*3))) temp_float = (-1.0f+(game.enemy[game.wave[wave_count].npc_type].size_h*3));
      spawn_npc(1.0f,temp_float,game.wave[wave_count].npc_type,game.wave[wave_count].spawn_pattern,0.0f,0.0f);
      spawn_npc(1.0f+(game.enemy[game.wave[wave_count].npc_type].size_w*0.75f),temp_float,game.wave[wave_count].npc_type,game.wave[wave_count].spawn_pattern,game.enemy[game.wave[wave_count].npc_type].size_w*0.75f,0.0f);
      spawn_npc(1.0f+(game.enemy[game.wave[wave_count].npc_type].size_w*1.50f),temp_float,game.wave[wave_count].npc_type,game.wave[wave_count].spawn_pattern,game.enemy[game.wave[wave_count].npc_type].size_w*1.50f,0.0f);
      spawn_npc(1.0f+(game.enemy[game.wave[wave_count].npc_type].size_w*2.25f),temp_float,game.wave[wave_count].npc_type,game.wave[wave_count].spawn_pattern,game.enemy[game.wave[wave_count].npc_type].size_w*2.25f,0.0f);
      game.level_spawened += 4;
      game.wave_spawnable = false;
   }
   if(game.wave[wave_count].spawn_pattern == 10)
   {
      temp_float = random_GLcoord();
      if (temp_float > ( 1.0f-(game.enemy[game.wave[wave_count].npc_type].size_h*3))) temp_float = ( 1.0f-(game.enemy[game.wave[wave_count].npc_type].size_h*3));
      if (temp_float < (-1.0f+(game.enemy[game.wave[wave_count].npc_type].size_h*3))) temp_float = (-1.0f+(game.enemy[game.wave[wave_count].npc_type].size_h*3));
      spawn_npc(1.0f,temp_float,game.wave[wave_count].npc_type,game.wave[wave_count].spawn_pattern,0.0f,0.0f);
      spawn_npc(1.0f+(game.enemy[game.wave[wave_count].npc_type].size_w*0.75f),temp_float,game.wave[wave_count].npc_type,game.wave[wave_count].spawn_pattern,game.enemy[game.wave[wave_count].npc_type].size_w*0.75f,0.0f);
      spawn_npc(1.0f+(game.enemy[game.wave[wave_count].npc_type].size_w*1.50f),temp_float,game.wave[wave_count].npc_type,game.wave[wave_count].spawn_pattern,game.enemy[game.wave[wave_count].npc_type].size_w*1.50f,0.0f);
      game.level_spawened += 3;
      game.wave_spawnable = false;
   }
   if(game.wave[wave_count].spawn_pattern == 11)
   {
      temp_float = random_GLcoord();
      if (temp_float > ( 1.0f-(game.enemy[game.wave[wave_count].npc_type].size_h*3))) temp_float = ( 1.0f-(game.enemy[game.wave[wave_count].npc_type].size_h*3));
      if (temp_float < (-1.0f+(game.enemy[game.wave[wave_count].npc_type].size_h*3))) temp_float = (-1.0f+(game.enemy[game.wave[wave_count].npc_type].size_h*3));
      spawn_npc(1.0f,temp_float+(game.enemy[game.wave[wave_count].npc_type].size_h*1.0f),game.wave[wave_count].npc_type,game.wave[wave_count].spawn_pattern,0.0f,+game.enemy[game.wave[wave_count].npc_type].size_h*1.0f);
      spawn_npc(1.0f,temp_float,game.wave[wave_count].npc_type,game.wave[wave_count].spawn_pattern,0.0f,0.0f);
      spawn_npc(1.0f,temp_float-(game.enemy[game.wave[wave_count].npc_type].size_h*1.0f),game.wave[wave_count].npc_type,game.wave[wave_count].spawn_pattern,0.0f,-game.enemy[game.wave[wave_count].npc_type].size_h*1.0f);
      game.level_spawened += 3;
      game.wave_spawnable = false;
   }
}
/*----------------------------------------------------------------------------*/
int   process_waves(void)
{
    for(int wave_count = 0;wave_count < MAX_WAVES;wave_count++)
    {
        if ((game.wave[wave_count].active) && (!game.wave_spawnable))
        {
            game.wave[wave_count].active = false;
            if (wave_count >= game.level_waves) game.wave[0].active = true;
            else game.wave[wave_count+1].active = true;
            game.wave_spawnable = true;
        }
    }
}
/*----------------------------------------------------------------------------*/
int init_active_npcs(void)
{
   for(int npc_count = 0; npc_count < MAX_NPCS; npc_count++)
   {
      game.active_npc[npc_count].number = -1;
      game.active_npc[npc_count].active = false;
   }
   return(0);
}
/*----------------------------------------------------------------------------*/
int check_active_npcs(void)
{
   for(int npc_count = 0; npc_count < MAX_NPCS; npc_count++)
   {
      if ((game.active_npc[npc_count].active) && (!game.npc[game.active_npc[npc_count].number].active)) game.active_npc[npc_count].active = false;
   }
}
/*----------------------------------------------------------------------------*/
int sort_active_npcs(void)
{
   check_active_npcs();
/*
   int  npc_num = 0;
   bool done = false;
   for(int npc_count = 0; npc_count < MAX_NPCS; npc_count++)
   {
      if (!game.active_npc[npc_count].active)
      {
         npc_num = npc_count;
         while ((npc_num < MAX_NPCS) && (!done))
         {
            game.active_npc[npc_num].active = game.active_npc[npc_num+1].active;
            game.active_npc[npc_num].number = game.active_npc[npc_num+1].number;
            npc_num++;
         }
      }
   }
   return(0);
*/
}
/*----------------------------------------------------------------------------*/
int add_active_npc  (int npc_num)
{
   bool spawn_done = 0;
   for  (int npc_count = 0; npc_count < MAX_NPCS; npc_count++)
   {
       if (!spawn_done && !game.active_npc[npc_count].active)
       {
           game.active_npc[npc_count].active  = true;
           game.active_npc[npc_count].number  = npc_num;
           game.active_npc_count++;
           spawn_done = 1;
       }
   }
   return(0);
}
/*----------------------------------------------------------------------------*/
int del_active_npc  (int npc_num)
{
   for(int npc_count = 0; npc_count < MAX_NPCS; npc_count++)
   {
       if (game.active_npc[npc_count].number == npc_num)
       {
           game.active_npc[npc_count].active  = false;
           game.active_npc[npc_count].number  = -1;
           game.active_npc_count--;
           if (game.active_npc_count < 0) game.active_npc_count = 0;
       }
   }
   sort_active_npcs();
   return(0);
}
/*----------------------------------------------------------------------------*/
int spawn_npc(float x_position, float y_position, int type_npc, int type_formation, float x_formation_ofset, float y_formation_ofset)
{
   bool  spawn_done = 0;
   for  (int npc_num = 0; npc_num < MAX_NPCS; npc_num++)
   {
       if (!spawn_done and !game.npc[npc_num].active)
       {
          game.npc[npc_num].active              = true;
          game.npc[npc_num].damaged             = 0;
          game.npc[npc_num].type_npc            = type_npc;
          game.npc[npc_num].x_pos               = x_position;
          game.npc[npc_num].y_pos               = y_position;
          game.npc[npc_num].formation_wave_no   = get_next_active_wave();
          game.npc[npc_num].formation_wave_axis = y_position;
          game.npc[npc_num].formation_target    = game.player.y_pos;
          game.npc[npc_num].formation_type      = type_formation;
          game.npc[npc_num].formation_ofset_x   = x_formation_ofset;
          game.npc[npc_num].formation_ofset_y   = y_formation_ofset;
          game.npc[npc_num].weapon              = game.enemy[game.npc[npc_num].type_npc].weapon;
          game.npc[npc_num].projectiles         = game.enemy[game.npc[npc_num].type_npc].projectiles;
          game.npc[npc_num].health              = game.enemy[game.npc[npc_num].type_npc].health;
          game.npc[npc_num].width               = game.enemy[game.npc[npc_num].type_npc].size_w;
          game.npc[npc_num].hight               = game.enemy[game.npc[npc_num].type_npc].size_h;
          game.npc[npc_num].x_speed             = game.enemy[game.npc[npc_num].type_npc].speed;
          game.npc[npc_num].y_speed             = game.enemy[game.npc[npc_num].type_npc].speed;
          game.npc[npc_num].movement            = game.enemy[game.npc[npc_num].type_npc].movement;
          game.npc[npc_num].x_direction         = 1;
          game.npc[npc_num].y_direction         = 1;
          spawn_done = 1;
          add_active_npc(npc_num);
       }
   }
   return(1);
}
/*----------------------------------------------------------------------------*/
int kill_npc(int npc_num)
{
   game.npc[npc_num].active     = false;
   game.npc[npc_num].x_pos      = -2.0f;
   game.npc[npc_num].y_pos      = -2.0f;
   game.npc[npc_num].movement   = game.enemy[game.npc[npc_num].type_npc].movement;
   game.npc[npc_num].movement   = game.enemy[game.npc[npc_num].type_npc].movement;
   del_active_npc(npc_num);
   return(0);
}
/*----------------------------------------------------------------------------*/
int kill_active_npcs(void)
{
   for (int npc_count = 0; npc_count < MAX_NPCS; npc_count++) //kill all npcs
   {
       if (game.npc[npc_count].active) kill_npc(npc_count);
   }
}
/*----------------------------------------------------------------------------*/
int init_npcs(int type_npc)
{
   for (int npc_count = 0; npc_count < MAX_NPCS; npc_count++)
   {
      game.npc[npc_count].active              = false;
      game.npc[npc_count].damaged             = 0;
      game.npc[npc_count].type_npc            = type_npc;
      game.npc[npc_count].x_pos               = -2.0f;
      game.npc[npc_count].y_pos               = -2.0f;
      game.npc[npc_count].formation_wave_axis = 0.0f;
      game.npc[npc_count].formation_wave_no   = 0;
      game.npc[npc_count].formation_type      = 0;
      game.npc[npc_count].formation_ofset_x   = 0.0f;
      game.npc[npc_count].formation_ofset_y   = 0.0f;
      game.npc[npc_count].weapon              = game.enemy[game.npc[npc_count].type_npc].weapon;
      game.npc[npc_count].projectiles         = game.enemy[game.npc[npc_count].type_npc].projectiles;
      game.npc[npc_count].health              = game.enemy[game.npc[npc_count].type_npc].health;
      game.npc[npc_count].width               = game.enemy[game.npc[npc_count].type_npc].size_w;
      game.npc[npc_count].hight               = game.enemy[game.npc[npc_count].type_npc].size_h;
      game.npc[npc_count].x_speed             = game.enemy[game.npc[npc_count].type_npc].speed;
      game.npc[npc_count].y_speed             = game.enemy[game.npc[npc_count].type_npc].speed;
      game.npc[npc_count].movement            = game.enemy[game.npc[npc_count].type_npc].movement;
      game.npc[npc_count].x_direction         = 1;
      game.npc[npc_count].y_direction         = 1;
   }
   init_npc_bullets();
   return(0);
}
/*----------------------------------------------------------------------------*/
int proccess_npcs(void)
{
   for (int npc_count = 0; npc_count < MAX_NPCS; npc_count++)
   {
      if  (game.npc[npc_count].damaged > 0) game.npc[npc_count].damaged--;
      else game.npc[npc_count].damaged = 0;
      if (game.npc[npc_count].active)
      {
         if (game.npc[npc_count].movement == 0)//straight line from right to left
         {
            game.npc[npc_count].x_pos -= game.npc[npc_count].x_speed;
            if (game.npc[npc_count].x_pos < -1.0f) kill_npc(npc_count);
         }
         if (game.npc[npc_count].movement == 1)//home in on player
         {
            game.npc[npc_count].x_pos -= game.npc[npc_count].x_speed;
            if (game.npc[npc_count].x_pos < -1.0f) kill_npc(npc_count);
            if ((game.npc[npc_count].y_pos-game.npc[npc_count].formation_ofset_y) < game.player.y_pos) game.npc[npc_count].y_pos += game.npc[npc_count].y_speed;
            if ((game.npc[npc_count].y_pos-game.npc[npc_count].formation_ofset_y) > game.player.y_pos) game.npc[npc_count].y_pos -= game.npc[npc_count].y_speed;
         }
         if (game.npc[npc_count].movement == 2)// move up and down,avoid player and stay far right
         {
            game.npc[npc_count].x_pos -= game.npc[npc_count].x_speed;
            if (game.npc[npc_count].x_pos < ((1.0f) - (game.npc[npc_count].width/2))) game.npc[npc_count].x_pos = ((1.0f)- (game.npc[npc_count].width/2));
            if (((game.player.y_pos + (game.player.hight/2)) > (game.npc[npc_count].y_pos - (game.npc[npc_count].hight/2))) && ((game.player.y_pos - (game.player.hight/2)) < (game.npc[npc_count].y_pos + (game.npc[npc_count].hight/2))))
            {
               if (game.npc[npc_count].y_pos > game.player.y_pos) game.npc[npc_count].y_pos += game.npc[npc_count].y_speed;
               if (game.npc[npc_count].y_pos < game.player.y_pos) game.npc[npc_count].y_pos -= game.npc[npc_count].y_speed;
            }
            else
            {
                if (game.npc[npc_count].y_direction ==  1) game.npc[npc_count].y_pos -= game.npc[npc_count].y_speed;
                if (game.npc[npc_count].y_direction == -1) game.npc[npc_count].y_pos += game.npc[npc_count].y_speed;
            }
            if ((game.npc[npc_count].y_pos - (game.npc[npc_count].hight/2)) < -1.0f)
            {
               game.npc[npc_count].y_pos = ((-1.0f) + (game.npc[npc_count].hight/2));
               game.npc[npc_count].y_direction *= -1;
            }
            if ((game.npc[npc_count].y_pos + (game.npc[npc_count].hight/2)) >  1.0f)
            {
               game.npc[npc_count].y_pos = (( 1.0f) - (game.npc[npc_count].hight/2));
               game.npc[npc_count].y_direction *= -1;
            }
         }
         if (game.npc[npc_count].movement == 3)// avoid player till border then home in on player
         {
            game.npc[npc_count].x_pos -= game.npc[npc_count].x_speed;
            if (game.npc[npc_count].x_pos < -1.0f) kill_npc(npc_count);
            if ((game.npc[npc_count].y_pos-game.npc[npc_count].formation_ofset_y) > game.player.y_pos) game.npc[npc_count].y_pos += game.npc[npc_count].y_speed;
            if ((game.npc[npc_count].y_pos-game.npc[npc_count].formation_ofset_y) < game.player.y_pos) game.npc[npc_count].y_pos -= game.npc[npc_count].y_speed;
            if (((game.npc[npc_count].y_pos-game.npc[npc_count].formation_ofset_y) - (game.npc[npc_count].hight/2)) < -1.0f) game.npc[npc_count].movement = 1;
            if (((game.npc[npc_count].y_pos-game.npc[npc_count].formation_ofset_y) + (game.npc[npc_count].hight/2)) >  1.0f) game.npc[npc_count].movement = 1;
         }
         if (game.npc[npc_count].movement == 4)// home in on player and then move to border
         {
            game.npc[npc_count].x_pos -= game.npc[npc_count].x_speed;
            if (game.npc[npc_count].x_pos <  -1.0f) kill_npc(npc_count);
            if ((game.npc[npc_count].y_pos-game.npc[npc_count].formation_ofset_y) <  game.player.y_pos) game.npc[npc_count].y_pos += game.npc[npc_count].y_speed;
            if ((game.npc[npc_count].y_pos-game.npc[npc_count].formation_ofset_y) >  game.player.y_pos) game.npc[npc_count].y_pos -= game.npc[npc_count].y_speed;
            if (((game.npc[npc_count].y_pos-game.npc[npc_count].formation_ofset_y) <= (game.player.y_pos+game.player.hight)) && ((game.npc[npc_count].y_pos-game.npc[npc_count].formation_ofset_y) >= (game.player.y_pos-game.player.hight))) game.npc[npc_count].movement = 3;
         }
         if (game.npc[npc_count].movement == 5)// move in an oscillating sine wave
         {
            game.npc[npc_count].x_pos -= game.npc[npc_count].x_speed;
            if (game.npc[npc_count].x_pos <  -1.0f) kill_npc(npc_count);
            if (game.npc[npc_count].y_direction ==  1) game.npc[npc_count].y_pos -= game.npc[npc_count].y_speed;
            if (game.npc[npc_count].y_direction == -1) game.npc[npc_count].y_pos += game.npc[npc_count].y_speed;
            if ((game.npc[npc_count].y_pos - (game.npc[npc_count].hight/2)) < (game.npc[npc_count].formation_wave_axis - game.wave[game.npc[npc_count].formation_wave_no].wave_size)) game.npc[npc_count].y_direction *= -1;
            if ((game.npc[npc_count].y_pos + (game.npc[npc_count].hight/2)) > (game.npc[npc_count].formation_wave_axis + game.wave[game.npc[npc_count].formation_wave_no].wave_size)) game.npc[npc_count].y_direction *= -1;
         }
         if (game.npc[npc_count].movement == 6)// move in a faster oscillating sine wave
         {
            game.npc[npc_count].x_pos -= game.npc[npc_count].x_speed;
            if (game.npc[npc_count].x_pos <  -1.0f) kill_npc(npc_count);
            if (game.npc[npc_count].y_direction ==  1) game.npc[npc_count].y_pos -= game.npc[npc_count].y_speed*2;
            if (game.npc[npc_count].y_direction == -1) game.npc[npc_count].y_pos += game.npc[npc_count].y_speed*2;
            if ((game.npc[npc_count].y_pos - (game.npc[npc_count].hight/2)) < (game.npc[npc_count].formation_wave_axis - game.wave[game.npc[npc_count].formation_wave_no].wave_size)) game.npc[npc_count].y_direction *= -1;
            if ((game.npc[npc_count].y_pos + (game.npc[npc_count].hight/2)) > (game.npc[npc_count].formation_wave_axis + game.wave[game.npc[npc_count].formation_wave_no].wave_size)) game.npc[npc_count].y_direction *= -1;
         }
         if (game.npc[npc_count].movement == 7)// home in on position player was in when spawned
         {
            game.npc[npc_count].x_pos -= game.npc[npc_count].x_speed;
            if (game.npc[npc_count].x_pos <  -1.0f) kill_npc(npc_count);
            if ((game.npc[npc_count].y_pos-game.npc[npc_count].formation_ofset_y) < game.npc[npc_count].formation_target) game.npc[npc_count].y_pos += game.npc[npc_count].y_speed;
            if ((game.npc[npc_count].y_pos-game.npc[npc_count].formation_ofset_y) > game.npc[npc_count].formation_target) game.npc[npc_count].y_pos -= game.npc[npc_count].y_speed;
         }
      }
   }
}
/*----------------------------------------------------------------------------*/
int spawn_npc_bullet_num(int npc_num, int npc_bullet_num, int location)
{
   if (npc_bullet_num > MAX_BULLETS) npc_bullet_num  = MAX_BULLETS;
   game.npc[npc_num].bullet[npc_bullet_num].active   = true;
   game.npc[npc_num].bullet[npc_bullet_num].location = location;
   game.npc[npc_num].bullet[npc_bullet_num].warhead  = game.npc[npc_num].weapon;
   if (location == 0) game.npc[npc_num].bullet[npc_bullet_num].x_pos = (game.npc[npc_num].x_pos - (game.npc[npc_num].width/3));  // 1   straight - top
   if (location == 1) game.npc[npc_num].bullet[npc_bullet_num].x_pos = (game.npc[npc_num].x_pos - (game.npc[npc_num].width/2));  //  2  straight - mid
   if (location == 2) game.npc[npc_num].bullet[npc_bullet_num].x_pos = (game.npc[npc_num].x_pos - (game.npc[npc_num].width/3));  //   3 straight - bot
   if (location == 3) game.npc[npc_num].bullet[npc_bullet_num].x_pos = (game.npc[npc_num].x_pos - (game.npc[npc_num].width/2));  // 1   down     - top
   if (location == 4) game.npc[npc_num].bullet[npc_bullet_num].x_pos = (game.npc[npc_num].x_pos - (game.npc[npc_num].width/4));  //  2  down     - mid
   if (location == 5) game.npc[npc_num].bullet[npc_bullet_num].x_pos = (game.npc[npc_num].x_pos - (game.npc[npc_num].width/5));  //   3 down     - bot
   if (location == 6) game.npc[npc_num].bullet[npc_bullet_num].x_pos = (game.npc[npc_num].x_pos - (game.npc[npc_num].width/5));  // 1   up       - top
   if (location == 7) game.npc[npc_num].bullet[npc_bullet_num].x_pos = (game.npc[npc_num].x_pos - (game.npc[npc_num].width/4));  //  2  up       - mid
   if (location == 8) game.npc[npc_num].bullet[npc_bullet_num].x_pos = (game.npc[npc_num].x_pos - (game.npc[npc_num].width/2));  //   3 up       - bot

   if (location == 0) game.npc[npc_num].bullet[npc_bullet_num].y_pos = (game.npc[npc_num].y_pos + (game.npc[npc_num].hight/3));  // 1   straight - top
   if (location == 1) game.npc[npc_num].bullet[npc_bullet_num].y_pos = (game.npc[npc_num].y_pos);                                //  2  straight - mid
   if (location == 2) game.npc[npc_num].bullet[npc_bullet_num].y_pos = (game.npc[npc_num].y_pos - (game.npc[npc_num].hight/3));  //   3 straight - bot
   if (location == 3) game.npc[npc_num].bullet[npc_bullet_num].y_pos = (game.npc[npc_num].y_pos + (game.npc[npc_num].hight/2));  // 1   down     - top
   if (location == 4) game.npc[npc_num].bullet[npc_bullet_num].y_pos = (game.npc[npc_num].y_pos + (game.npc[npc_num].hight/5));  //  2  down     - mid
   if (location == 5) game.npc[npc_num].bullet[npc_bullet_num].y_pos = (game.npc[npc_num].y_pos - (game.npc[npc_num].hight/4));  //   3 down     - bot
   if (location == 6) game.npc[npc_num].bullet[npc_bullet_num].y_pos = (game.npc[npc_num].y_pos + (game.npc[npc_num].hight/4));  // 1   up       - top
   if (location == 7) game.npc[npc_num].bullet[npc_bullet_num].y_pos = (game.npc[npc_num].y_pos - (game.npc[npc_num].hight/5));  //  2  up       - mid
   if (location == 8) game.npc[npc_num].bullet[npc_bullet_num].y_pos = (game.npc[npc_num].y_pos - (game.npc[npc_num].hight/2));  //   3 up       - bot

   switch (game.projectile[game.npc[npc_num].bullet[npc_bullet_num].warhead].movement)
      {
         case 0: //staright
            game.npc[npc_num].bullet[npc_bullet_num].straight       = true;
            game.npc[npc_num].bullet[npc_bullet_num].homeing_00     = false;
            game.npc[npc_num].bullet[npc_bullet_num].homeing_01     = false;
            game.npc[npc_num].bullet[npc_bullet_num].wave           = false;
            game.npc[npc_num].bullet[npc_bullet_num].wave_hight     = 0.0f;
            game.npc[npc_num].bullet[npc_bullet_num].wave_count     = 0.0f;
            game.npc[npc_num].bullet[npc_bullet_num].wave_speed     = 0.0f;
            game.npc[npc_num].bullet[npc_bullet_num].wave_direction = true;
         break;
         case 1: //homeing
            game.npc[npc_num].bullet[npc_bullet_num].straight       = false;
            game.npc[npc_num].bullet[npc_bullet_num].homeing_00     = true;
            game.npc[npc_num].bullet[npc_bullet_num].homeing_01     = false;
            game.npc[npc_num].bullet[npc_bullet_num].wave           = false;
            game.npc[npc_num].bullet[npc_bullet_num].wave_hight     = 0.0f;
            game.npc[npc_num].bullet[npc_bullet_num].wave_count     = 0.0f;
            game.npc[npc_num].bullet[npc_bullet_num].wave_speed     = 0.0f;
            game.npc[npc_num].bullet[npc_bullet_num].wave_direction = true;
         break;
         case 2: //wave
            game.npc[npc_num].bullet[npc_bullet_num].straight       = false;
            game.npc[npc_num].bullet[npc_bullet_num].homeing_00     = false;
            game.npc[npc_num].bullet[npc_bullet_num].homeing_01     = false;
            game.npc[npc_num].bullet[npc_bullet_num].wave           = true;
            game.npc[npc_num].bullet[npc_bullet_num].wave_hight     = game.projectile[game.npc[npc_num].bullet[npc_bullet_num].warhead].wave_size;
            game.npc[npc_num].bullet[npc_bullet_num].wave_count     = 0.0f;
            game.npc[npc_num].bullet[npc_bullet_num].wave_speed     = game.projectile[game.npc[npc_num].bullet[npc_bullet_num].warhead].wave_velocity;
            game.npc[npc_num].bullet[npc_bullet_num].wave_direction = 1;
         break;
         case 3: //super homeing
            game.npc[npc_num].bullet[npc_bullet_num].straight       = false;
            game.npc[npc_num].bullet[npc_bullet_num].homeing_00     = false;
            game.npc[npc_num].bullet[npc_bullet_num].homeing_01     = true;
            game.npc[npc_num].bullet[npc_bullet_num].wave           = false;
            game.npc[npc_num].bullet[npc_bullet_num].wave_hight     = game.projectile[game.npc[npc_num].bullet[npc_bullet_num].warhead].wave_size;
            game.npc[npc_num].bullet[npc_bullet_num].wave_count     = 0.0f;
            game.npc[npc_num].bullet[npc_bullet_num].wave_speed     = game.projectile[game.npc[npc_num].bullet[npc_bullet_num].warhead].wave_velocity;
            game.npc[npc_num].bullet[npc_bullet_num].wave_direction = 1;
         break;
         case 4: //homeing wave
            game.npc[npc_num].bullet[npc_bullet_num].straight       = false;
            game.npc[npc_num].bullet[npc_bullet_num].homeing_00     = true;
            game.npc[npc_num].bullet[npc_bullet_num].homeing_01     = false;
            game.npc[npc_num].bullet[npc_bullet_num].wave           = true;
            game.npc[npc_num].bullet[npc_bullet_num].wave_hight     = game.projectile[game.npc[npc_num].bullet[npc_bullet_num].warhead].wave_size;
            game.npc[npc_num].bullet[npc_bullet_num].wave_count     = 0.0f;
            game.npc[npc_num].bullet[npc_bullet_num].wave_speed     = game.projectile[game.npc[npc_num].bullet[npc_bullet_num].warhead].wave_velocity;
            game.npc[npc_num].bullet[npc_bullet_num].wave_direction = 1;
         break;
         default://staright
            game.npc[npc_num].bullet[npc_bullet_num].straight       = true;
            game.npc[npc_num].bullet[npc_bullet_num].homeing_00     = false;
            game.npc[npc_num].bullet[npc_bullet_num].homeing_01     = false;
            game.npc[npc_num].bullet[npc_bullet_num].wave           = false;
            game.npc[npc_num].bullet[npc_bullet_num].wave_hight     = 0.0f;
            game.npc[npc_num].bullet[npc_bullet_num].wave_count     = 0.0f;
            game.npc[npc_num].bullet[npc_bullet_num].wave_speed     = 0.0f;
            game.npc[npc_num].bullet[npc_bullet_num].wave_direction = true;
        break;
      }
   return(0);
}
/*----------------------------------------------------------------------------*/
int spawn_npc_bullet(int npc_num, int location)
{
   bool spawn_done = 0;
   for (int npc_bullet_num = 0; npc_bullet_num < MAX_BULLETS; npc_bullet_num++)
   {
       if (!spawn_done and !game.npc[npc_num].bullet[npc_bullet_num].active)
       {
           spawn_npc_bullet_num(npc_num,npc_bullet_num,location);
           spawn_done = 1;
       }
   }
 return(0);
}
/*----------------------------------------------------------------------------*/
int kill_npc_bullet(int npc_num, int npc_bullet_num)
{
  if (npc_bullet_num > MAX_BULLETS) npc_bullet_num = MAX_BULLETS;
  game.npc[npc_num].bullet[npc_bullet_num].active  = false;
  game.npc[npc_num].bullet[npc_bullet_num].x_pos   = -2.0f;
  game.npc[npc_num].bullet[npc_bullet_num].y_pos   = -2.0f;
  return npc_bullet_num;
}
/*----------------------------------------------------------------------------*/
int init_npc_bullets(void)
{
   for (int npc_count = 0; npc_count < MAX_NPCS; npc_count++)
   {
      for (int bullet_count = 0; bullet_count < MAX_BULLETS; bullet_count++)
      {
         game.npc[npc_count].bullet[bullet_count].active   = false;
         game.npc[npc_count].bullet[bullet_count].x_pos    = -2.0f;
         game.npc[npc_count].bullet[bullet_count].y_pos    = -2.0f;
         game.npc[npc_count].bullet[bullet_count].x_speed  = game.enemy[game.npc[npc_count].type_npc].speed;
         game.npc[npc_count].bullet[bullet_count].y_speed  = game.enemy[game.npc[npc_count].type_npc].speed;
         game.npc[npc_count].bullet[bullet_count].width    = 0.05f;
         game.npc[npc_count].bullet[bullet_count].hight    = 0.05f;
         game.npc[npc_count].bullet[bullet_count].warhead  = game.enemy[game.npc[npc_count].type_npc].weapon;
         game.npc[npc_count].bullet[bullet_count].location = 0;
      }
   }
   return(0);
}
/*----------------------------------------------------------------------------*/
int proccess_npc_bullets(void)
{
   for (int npc_count = 0; npc_count < MAX_NPCS; npc_count++)
   {
      for (int bullet_count = 0; bullet_count < MAX_BULLETS; bullet_count++)
      {
         if (game.projectile[game.npc[npc_count].bullet[bullet_count].warhead].movement == 0) //bullet moves in "straight" lines
         {
            if (game.npc[npc_count].bullet[bullet_count].active) game.npc[npc_count].bullet[bullet_count].x_pos -= game.projectile[game.npc[npc_count].bullet[bullet_count].warhead].speed;
            if (game.npc[npc_count].bullet[bullet_count].location == 3) game.npc[npc_count].bullet[bullet_count].y_pos += (game.projectile[game.npc[npc_count].bullet[bullet_count].warhead].speed / 1);
            if (game.npc[npc_count].bullet[bullet_count].location == 4) game.npc[npc_count].bullet[bullet_count].y_pos += (game.projectile[game.npc[npc_count].bullet[bullet_count].warhead].speed / 2);
            if (game.npc[npc_count].bullet[bullet_count].location == 5) game.npc[npc_count].bullet[bullet_count].y_pos += (game.projectile[game.npc[npc_count].bullet[bullet_count].warhead].speed / 3);
            if (game.npc[npc_count].bullet[bullet_count].location == 6) game.npc[npc_count].bullet[bullet_count].y_pos -= (game.projectile[game.npc[npc_count].bullet[bullet_count].warhead].speed / 3);
            if (game.npc[npc_count].bullet[bullet_count].location == 7) game.npc[npc_count].bullet[bullet_count].y_pos -= (game.projectile[game.npc[npc_count].bullet[bullet_count].warhead].speed / 2);
            if (game.npc[npc_count].bullet[bullet_count].location == 8) game.npc[npc_count].bullet[bullet_count].y_pos -= (game.projectile[game.npc[npc_count].bullet[bullet_count].warhead].speed / 1);
         }
         if (game.projectile[game.npc[npc_count].bullet[bullet_count].warhead].movement == 1) //bullet homes in on player
         {
            if (game.npc[npc_count].bullet[bullet_count].active) game.npc[npc_count].bullet[bullet_count].x_pos -= game.projectile[game.npc[npc_count].bullet[bullet_count].warhead].speed;
            if (game.npc[npc_count].bullet[bullet_count].active)
            {
                if (game.npc[npc_count].bullet[bullet_count].x_pos > game.player.x_pos)
                {
                   if (game.npc[npc_count].bullet[bullet_count].y_pos > game.player.y_pos) game.npc[npc_count].bullet[bullet_count].y_pos -= (game.projectile[game.npc[npc_count].bullet[bullet_count].warhead].speed/2);
                   if (game.npc[npc_count].bullet[bullet_count].y_pos < game.player.y_pos) game.npc[npc_count].bullet[bullet_count].y_pos += (game.projectile[game.npc[npc_count].bullet[bullet_count].warhead].speed/2);
                }
            }
         }
         if (game.projectile[game.npc[npc_count].bullet[bullet_count].warhead].movement == 2) //bullet moves in a wave pattern
         {
             if (game.npc[npc_count].bullet[bullet_count].active) game.npc[npc_count].bullet[bullet_count].x_pos -= game.projectile[game.npc[npc_count].bullet[bullet_count].warhead].speed;
             game.npc[npc_count].bullet[bullet_count].wave_count += game.npc[npc_count].bullet[bullet_count].wave_speed;
             if (game.npc[npc_count].bullet[bullet_count].wave_count >= game.npc[npc_count].bullet[bullet_count].wave_hight)
             {
                game.npc[npc_count].bullet[bullet_count].wave_count = 0.0f;
                game.npc[npc_count].bullet[bullet_count].wave_direction = !game.npc[npc_count].bullet[bullet_count].wave_direction;
             }
            if (game.npc[npc_count].bullet[bullet_count].wave_direction == true) game.npc[npc_count].bullet[bullet_count].y_pos += game.npc[npc_count].bullet[bullet_count].wave_speed;
            else game.npc[npc_count].bullet[bullet_count].y_pos -= game.npc[npc_count].bullet[bullet_count].wave_speed;
         }
         if (game.projectile[game.npc[npc_count].bullet[bullet_count].warhead].movement == 3) //bullet super homes in on player
         {
           if (game.npc[npc_count].bullet[bullet_count].active)
            {
                if (game.npc[npc_count].bullet[bullet_count].y_pos > game.player.y_pos) game.npc[npc_count].bullet[bullet_count].y_pos -= (game.projectile[game.npc[npc_count].bullet[bullet_count].warhead].speed/2);
                if (game.npc[npc_count].bullet[bullet_count].y_pos < game.player.y_pos) game.npc[npc_count].bullet[bullet_count].y_pos += (game.projectile[game.npc[npc_count].bullet[bullet_count].warhead].speed/2);
                if (game.npc[npc_count].bullet[bullet_count].x_pos > game.player.x_pos) game.npc[npc_count].bullet[bullet_count].x_pos -= (game.projectile[game.npc[npc_count].bullet[bullet_count].warhead].speed/2);
                if (game.npc[npc_count].bullet[bullet_count].x_pos < game.player.x_pos) game.npc[npc_count].bullet[bullet_count].x_pos += (game.projectile[game.npc[npc_count].bullet[bullet_count].warhead].speed/2);
            }
         }
         if (game.projectile[game.npc[npc_count].bullet[bullet_count].warhead].movement == 4) //bullet homes in on player and moves in a wave pattern
         {
            if (game.npc[npc_count].bullet[bullet_count].active) game.npc[npc_count].bullet[bullet_count].x_pos -= game.projectile[game.npc[npc_count].bullet[bullet_count].warhead].speed;
            if (game.npc[npc_count].bullet[bullet_count].active)
            {
                if (game.npc[npc_count].bullet[bullet_count].x_pos > game.player.x_pos)
                {
                   if (game.npc[npc_count].bullet[bullet_count].y_pos > (game.player.y_pos+(game.player.hight/2))) game.npc[npc_count].bullet[bullet_count].y_pos -= (game.projectile[game.npc[npc_count].bullet[bullet_count].warhead].speed/2);
                   if (game.npc[npc_count].bullet[bullet_count].y_pos < (game.player.y_pos-(game.player.hight/2))) game.npc[npc_count].bullet[bullet_count].y_pos += (game.projectile[game.npc[npc_count].bullet[bullet_count].warhead].speed/2);
                }
                game.npc[npc_count].bullet[bullet_count].wave_count += game.npc[npc_count].bullet[bullet_count].wave_speed;
                if (game.npc[npc_count].bullet[bullet_count].wave_count >= game.npc[npc_count].bullet[bullet_count].wave_hight)
                {
                   game.npc[npc_count].bullet[bullet_count].wave_count = 0.0f;
                   game.npc[npc_count].bullet[bullet_count].wave_direction = !game.npc[npc_count].bullet[bullet_count].wave_direction;
                }
                if (game.npc[npc_count].bullet[bullet_count].wave_direction == true) game.npc[npc_count].bullet[bullet_count].y_pos += game.npc[npc_count].bullet[bullet_count].wave_speed;
                else game.npc[npc_count].bullet[bullet_count].y_pos -= game.npc[npc_count].bullet[bullet_count].wave_speed;
            }
         }
         if (game.npc[npc_count].bullet[bullet_count].x_pos < (-1.0f - game.npc[npc_count].bullet[bullet_count].width)) kill_npc_bullet(npc_count,bullet_count);
         // check player starship / npc bullet collisions...
         if (quadrangle_collision(game.player.x_pos,game.player.y_pos,game.player.width,game.player.hight,game.npc[npc_count].bullet[bullet_count].x_pos,game.npc[npc_count].bullet[bullet_count].y_pos,game.npc[npc_count].bullet[bullet_count].width,game.npc[npc_count].bullet[bullet_count].hight))
         {
            spawn_explosion(game.npc[npc_count].bullet[bullet_count].x_pos,game.npc[npc_count].bullet[bullet_count].y_pos,0.125f);
            kill_npc_bullet(npc_count,bullet_count);
            play_sound(13);//player shield hit
            game.player.health -= (0.005f+game.shield[game.player.front_shield].absorption+(0.0001f*game.shield[game.player.front_shield].level));
            if ((game.shield[game.player.front_shield].level <= 2) && (game.player.front_shield >= 0))
            {
                game.shield[game.player.front_shield].experience++;
                if (game.shield[game.player.front_shield].level == 0)
                {
                    if (game.shield[game.player.front_shield].experience >= game.shield[game.player.front_shield].level_1)
                    {
                       spawn_p_shield_level_up();
                       game.shield[game.player.front_shield].experience = 0;
                       game.shield[game.player.front_shield].level++;
                    }
                }
                if (game.shield[game.player.front_shield].level == 1)
                {
                    if (game.shield[game.player.front_shield].experience >= game.shield[game.player.front_shield].level_2)
                    {
                       spawn_p_shield_level_up();
                       game.shield[game.player.front_shield].experience = 0;
                       game.shield[game.player.front_shield].level++;
                    }
                }
                if (game.shield[game.player.front_shield].level == 2)
                {
                    if (game.shield[game.player.front_shield].experience >= game.shield[game.player.front_shield].level_3)
                    {
                       spawn_p_shield_level_up();
                       game.shield[game.player.front_shield].experience = 0;
                       game.shield[game.player.front_shield].level++;
                    }
                }
            }
         }
      }
   }
   return(0);
}
/*----------------------------------------------------------------------------*/
int spawn_powerup(float x_position, float y_position, int type_powerup)
{
   if (!game.powerup[type_powerup].active)
   {
      game.powerup[type_powerup].active     = true;
      game.powerup[type_powerup].x_pos      = x_position;
      game.powerup[type_powerup].y_pos      = y_position;
      game.powerup[type_powerup].width      = 0.10f;
      game.powerup[type_powerup].hight      = 0.10f;
      game.powerup[type_powerup].speed      = 0.0025f;
      game.powerup[type_powerup].spawn_rate = 20000;
   }
   return(0);
};
/*----------------------------------------------------------------------------*/
int kill_powerup(int type_powerup)
{
   game.powerup[type_powerup].active     = false;
   game.powerup[type_powerup].x_pos      = -2.0f;
   game.powerup[type_powerup].y_pos      = -2.0f;
   game.powerup[type_powerup].width      = 0.10f;
   game.powerup[type_powerup].hight      = 0.10f;
   game.powerup[type_powerup].speed      = 0.0025f;
   game.powerup[type_powerup].spawn_rate = 20000;
   return(0);
};
/*----------------------------------------------------------------------------*/
int kill_powerups(void)
{
   for (int count = 0;count < MAX_POWERUPS;count++)
   {
      game.powerup[count].active     = false;
      game.powerup[count].x_pos      = -2.0f;
      game.powerup[count].y_pos      = -2.0f;
      game.powerup[count].width      = 0.10f;
      game.powerup[count].hight      = 0.10f;
      game.powerup[count].speed      = 0.0025f;
      game.powerup[count].spawn_rate = 20000;
   }
   return(0);
};
/*----------------------------------------------------------------------------*/
int init_powerups(void)
{
   for (int count = 0;count < MAX_POWERUPS;count++)
   {
      game.powerup[count].active     = false;
      game.powerup[count].image      = 291;
      game.powerup[count].sound      = 5;
      game.powerup[count].x_pos      = -2.0f;
      game.powerup[count].y_pos      = -2.0f;
      game.powerup[count].width      = 0.10f;
      game.powerup[count].hight      = 0.10f;
      game.powerup[count].speed      = 0.0025f;
      game.powerup[count].spawn_rate = 20000;
   }
   game.powerup[1 ].image   = 291;//health
   game.powerup[2 ].image   = 292;//shield lvl up
   game.powerup[3 ].image   = 293;//shield new
   game.powerup[4 ].image   = 294;//thruster lvl up
   game.powerup[5 ].image   = 295;//thruster new
   game.powerup[6 ].image   = 296;//weapon lvl up
   game.powerup[7 ].image   = 297;//weapon new
   game.powerup[8 ].image   = 341;//bomb
   game.powerup[9 ].image   = 346;//side helper ship 0
   game.powerup[10].image   = 347;//side helper ship 1
   game.powerup[11].image   = 348;//side helper ship 2
   game.powerup[12].image   = 349;//side helper ship 3

   game.powerup[1 ].sound   = 14;//health
   game.powerup[2 ].sound   = 15;//shield lvl up
   game.powerup[3 ].sound   = 16;//shield new
   game.powerup[4 ].sound   = 17;//thruster lvl up
   game.powerup[5 ].sound   = 18;//thruster new
   game.powerup[6 ].sound   = 19;//weapon lvl up
   game.powerup[7 ].sound   = 20;//weapon new
   game.powerup[8 ].sound   = 14;//bomb
   game.powerup[9 ].sound   = 18;//side helper ship 0
   game.powerup[10].sound   = 18;//side helper ship 1
   game.powerup[11].sound   = 18;//side helper ship 2
   game.powerup[12].sound   = 18;//side helper ship 3

   game.powerup[9 ].spawn_rate = 4000;//side helper ship 0
   game.powerup[10].spawn_rate = 4000;//side helper ship 1
   game.powerup[11].spawn_rate = 4000;//side helper ship 2
   game.powerup[12].spawn_rate = 4000;//side helper ship 3
   return(0);
};
/*----------------------------------------------------------------------------*/
int proccess_powerups(void)
{
   for (int count = 1; count < MAX_POWERUPS; count++)
   {
      if (game.powerup[count].active)
      {
         game.powerup[count].x_pos -= game.powerup[count].speed;
         if (game.powerup[count].x_pos <= (-1.0f - game.powerup[count].width)) kill_powerup(count);
         if (quadrangle_collision(game.player.x_pos,game.player.y_pos,game.player.width,game.player.hight,game.powerup[count].x_pos,game.powerup[count].y_pos,game.powerup[count].width,game.powerup[count].hight))
         {
            play_sound(game.powerup[count].sound);
            kill_powerup(count);
            switch (count)
            {
                case 1: //health 100%
                    {
                       game.player.health = 0.100f;
                       spawn_p_health();
                    }
                break;
                case 2://shield lvl up
                    {
                       if (game.player.front_shield >= 0)
                       {
                          if (game.shield[game.player.front_shield].level  < 3)
                          {
                             game.shield[game.player.front_shield].level++;
                             spawn_p_shield_level_up();
                          }
                       }
                    }
                break;
                case 3://get new shield
                    {
                       bool done = false;
                       for (int s_count = 0; s_count < MAX_SHIELDS; s_count++)
                       {
                           if ((!game.shield[s_count].active) and (!done))
                           {
                               game.player.front_shield = s_count;
                               game.shield[s_count].active = true;
                               done = true;
                               if (game.player.front_shield == 0) spawn_p_terbium_shields();
                               if (game.player.front_shield == 1) spawn_p_iridium_shileds();
                               if (game.player.front_shield == 2) spawn_p_rubidium_shields();
                               if (game.player.front_shield == 3) spawn_p_tantalum_shields();
                               if (game.player.front_shield == 4) spawn_p_actinium_shields();
                           }
                       }
                    }
                break;
                case 4://thrusters lvl up
                    {
                       if (game.player.thrusters >= 0)
                       {
                          if (game.thruster[game.player.thrusters].level  < 3)
                          {
                             game.thruster[game.player.thrusters].level++;
                             spawn_p_thrusters_level_up();
                          }
                       }
                    }
                break;
                case 5://get new thrusters
                    {
                       bool done = false;
                       for (int t_count = 0; t_count < MAX_THRUSTERS-1; t_count++)
                       {
                           if ((!game.thruster[t_count].active) and (!done))
                           {
                               game.player.thrusters = t_count;
                               game.thruster[t_count].active = true;
                               done = true;
                               if (game.player.thrusters == 0) spawn_p_maelstrom_thrusters();
                               if (game.player.thrusters == 1) spawn_p_seismic_thrusters();
                               if (game.player.thrusters == 2) spawn_p_vortex_thrusters();
                               if (game.player.thrusters == 3) spawn_p_convolution_thrusters();
                           }
                       }
                    }
                break;
                case 6://weapon lvl up
                    {
                       game.projectile[game.player.front_weapon].level++;
                       if (game.projectile[game.player.front_weapon].level > 3) game.projectile[game.player.front_weapon].level = 3;
                       game.projectile[game.player.front_weapon].experience = 0;
                       if (game.player.side_weapon != game.player.front_weapon)
                       {
                          game.projectile[game.player.side_weapon].level++;
                          if (game.projectile[game.player.side_weapon].level > 3) game.projectile[game.player.side_weapon].level = 3;
                          game.projectile[game.player.side_weapon].experience = 0;
                       }
                       spawn_p_weapon_level_up();
                    }
                break;
                case 7://get new weapon
                    {
                       bool done = false;
                       for (int w_count = 0; w_count < MAX_PROJECTILES; w_count++)
                       {
                           if (!game.projectile[w_count].active and !done and (w_count < 6))
                           {
                               game.player.front_weapon = w_count;
                               game.player.side_weapon  = w_count;
                               game.projectile[w_count].active = true;
                               done = true;
                               if (game.player.front_weapon == 0) spawn_p_blasters();
                               if (game.player.front_weapon == 1) spawn_p_chain_guns();
                               if (game.player.front_weapon == 2) spawn_p_burst_lasers();
                               if (game.player.front_weapon == 3) spawn_p_rail_turrets();
                               if (game.player.front_weapon == 4) spawn_p_plasma_rockets();
                               if (game.player.front_weapon == 5) spawn_p_ion_cannons();
                           }
                       }
                    }
                break;
                case 8://get bomb
                    {
                       Mix_Volume(-1,(config_data.Audio_Sound_Volume/2));
                       for (int npc_count = 0; npc_count < MAX_NPCS; npc_count++) //kill all npcs
                       {
                          play_sound(49);
                          if (game.npc[npc_count].active)
                           {
                              int random_temp = random_int();
                              if (random_temp <= game.coin_spawn_rate) //spawn coin
                              {
                                 spawn_coin(game.npc[npc_count].x_pos,game.npc[npc_count].y_pos,(game.npc[npc_count].type_npc+1+random_dec()));
                              }
                              if ((random_temp > game.coin_spawn_rate) && (random_temp <= game.wexp_spawn_rate)) //spawn wexp
                              {
                                 spawn_wexp(game.npc[npc_count].x_pos,game.npc[npc_count].y_pos,(game.npc[npc_count].type_npc+1+random_dec()));
                              }
                              if (random_temp > game.wexp_spawn_rate) //spawn null
                              {
                                 ;
                              }
                              game.score += (game.npc[npc_count].type_npc + 1) * 10;
                              game.level_score += (game.npc[npc_count].type_npc + 1) * 10;
                              spawn_explosion(game.npc[npc_count].x_pos,game.npc[npc_count].y_pos,0.50f);
                              kill_npc(npc_count);
                              game.kills++;
                              game.level_kills++;

                           }
                       }
                       for (int npc_count = 0; npc_count < MAX_NPCS; npc_count++)//kill all npc bullets
                       {
                          for (int bullet_count = 0; bullet_count < MAX_BULLETS; bullet_count++)
                          {
                             if (game.npc[npc_count].bullet[bullet_count].active)
                             {
                                spawn_explosion(game.npc[npc_count].bullet[bullet_count].x_pos,game.npc[npc_count].bullet[bullet_count].y_pos,0.125f);
                                kill_npc_bullet(npc_count,bullet_count);
                             }
                          }
                       }
                    }
                Mix_Volume(-1,config_data.Audio_Sound_Volume);
                break;
                case 9://sideship 0
                    {
                        if (game.sideship[0].active)
                        {
                            game.sideship[0].level++;
                            if (game.sideship[0].level > 3) game.sideship[0].level = 3;
                        }
                        else
                        {
                           for (int count = 0;count < MAX_SIDESHIPS;count++)
                           {
                              game.sideship[count].active = false;
                              game.sideship[count].level  = -1;
                              for (int bullet_count = 0;bullet_count < MAX_BULLETS;bullet_count++)
                              {
                                 game.sideship[count].bullet[bullet_count].active = false;
                              }
                           }
                           game.sideship[0].active = true;
                           game.sideship[0].level  = 0;
                        }
                    }
                break;
                case 10://sideship 1
                    {
                        if (game.sideship[1].active)
                        {
                            game.sideship[1].level++;
                            if (game.sideship[1].level > 3) game.sideship[1].level = 3;
                        }
                        else
                        {
                           for (int count = 0;count < MAX_SIDESHIPS;count++)
                           {
                              game.sideship[count].active = false;
                              game.sideship[count].level  = -1;
                              for (int bullet_count = 0;bullet_count < MAX_BULLETS;bullet_count++)
                              {
                                 game.sideship[count].bullet[bullet_count].active = false;
                              }
                           }
                           game.sideship[1].active = true;
                           game.sideship[1].level  = 0;
                        }
                    }
                break;
                case 11://sideship 2
                    {
                        if (game.sideship[2].active)
                        {
                            game.sideship[2].level++;
                            if (game.sideship[2].level > 3) game.sideship[2].level = 3;
                        }
                        else
                        {
                           for (int count = 0;count < MAX_SIDESHIPS;count++)
                           {
                              game.sideship[count].active = false;
                              game.sideship[count].level  = -1;
                              for (int bullet_count = 0;bullet_count < MAX_BULLETS;bullet_count++)
                              {
                                 game.sideship[count].bullet[bullet_count].active = false;
                              }
                           }
                           game.sideship[2].active = true;
                           game.sideship[2].level  = 0;
                        }
                    }
                break;
                case 12://sideship 3
                    {
                        if (game.sideship[3].active)
                        {
                            game.sideship[3].level++;
                            if (game.sideship[3].level > 3) game.sideship[3].level = 3;
                        }
                        else
                        {
                           for (int count = 0;count < MAX_SIDESHIPS;count++)
                           {
                              game.sideship[count].active = false;
                              game.sideship[count].level  = -1;
                              for (int bullet_count = 0;bullet_count < MAX_BULLETS;bullet_count++)
                              {
                                 game.sideship[count].bullet[bullet_count].active = false;
                              }
                           }
                           game.sideship[3].active = true;
                           game.sideship[3].level  = 0;
                        }
                    }
                break;
            }
         }
      }
   }
   return(0);
};
/*----------------------------------------------------------------------------*/
int spawn_coin(float x_position, float y_position, int coin_value)
{
   bool spawned = false;
   for (int count = 1;count < MAX_COINS;count++)
   {
      if (!game.coin[count].active && !spawned)
      {
         game.coin[count].active        = true;
         game.coin[count].x_pos         = x_position;
         game.coin[count].y_pos         = y_position;
         game.coin[count].width         = (0.075f + (coin_value / 400.0f));
         game.coin[count].hight         = (0.075f + (coin_value / 400.0f));
         game.coin[count].sound         = 21;
         game.coin[count].speed         = 0.0025f;
         game.coin[count].value         = coin_value;
         spawned = true;
      }
   }
   return(0);
}
/*----------------------------------------------------------------------------*/
int kill_coin(int coin_num)
{
   game.coin[coin_num].active     = false;
   game.coin[coin_num].image      = 337;
   game.coin[coin_num].sound      = 21;
   game.coin[coin_num].x_pos      = -2.0f;
   game.coin[coin_num].y_pos      = -2.0f;
   game.coin[coin_num].width      = 0.10f;
   game.coin[coin_num].hight      = 0.10f;
   game.coin[coin_num].speed      = 0.0025f;
   game.coin[coin_num].value      = 0;
   return(0);
}
/*----------------------------------------------------------------------------*/
int kill_coins(void)
{
   for (int count = 0;count < MAX_COINS;count++)
   {
      game.coin[count].active     = false;
      game.coin[count].image      = 337;
      game.coin[count].sound      = 21;
      game.coin[count].x_pos      = -2.0f;
      game.coin[count].y_pos      = -2.0f;
      game.coin[count].width      = 0.10f;
      game.coin[count].hight      = 0.10f;
      game.coin[count].speed      = 0.0025f;
      game.coin[count].value      = 0;
   }
   return(0);
}
/*----------------------------------------------------------------------------*/
int init_coin(void)
{
   for (int count = 0;count < MAX_COINS;count++)
   {
      game.coin[count].active     = false;
      game.coin[count].image      = 337;
      game.coin[count].sound      = 21;
      game.coin[count].x_pos      = -2.0f;
      game.coin[count].y_pos      = -2.0f;
      game.coin[count].width      = 0.10f;
      game.coin[count].hight      = 0.10f;
      game.coin[count].speed      = 0.0025f;
      game.coin[count].value      = 0;
   }
   return(0);
}
/*----------------------------------------------------------------------------*/
int proccess_coin(void)
{
   for (int count = 0; count < MAX_COINS; count++)
   {
      if (game.coin[count].active)
      {
         game.coin[count].x_pos -= game.coin[count].speed;
         if (game.coin[count].x_pos <= (-1.0f - game.coin[count].width)) kill_coin(count);
         if (quadrangle_collision(game.player.x_pos,game.player.y_pos,game.player.width,game.player.hight,game.coin[count].x_pos,game.coin[count].y_pos,game.coin[count].width,game.coin[count].hight))
         {
            game.score += game.coin[count].value;
            game.level_score += game.coin[count].value;
            kill_coin(count);
            play_sound(game.coin[count].sound);
         }
      }
   }
   return(0);
}
/*----------------------------------------------------------------------------*/
int spawn_wexp(float x_position, float y_position, int wexp_value)
{
   bool spawned = false;
   for (int count = 0;count < MAX_WEXPS;count++)
   {
      if (!game.wexp[count].active && !spawned)
      {
         game.wexp[count].active        = true;
         game.wexp[count].x_pos         = x_position;
         game.wexp[count].y_pos         = y_position;
         game.wexp[count].width         = (0.075f + (wexp_value / 400.f));
         game.wexp[count].hight         = (0.075f + (wexp_value / 400.f));
         game.wexp[count].value         = wexp_value;
         spawned = true;
      }
   }
   return(0);
}
/*----------------------------------------------------------------------------*/
int kill_wexp(int wexp_num)
{
   game.wexp[wexp_num].active     = false;
   game.wexp[wexp_num].image      = 338;
   game.wexp[wexp_num].sound      = 22;
   game.wexp[wexp_num].x_pos      = -2.0f;
   game.wexp[wexp_num].y_pos      = -2.0f;
   game.wexp[wexp_num].width      = 0.10f;
   game.wexp[wexp_num].hight      = 0.10f;
   game.wexp[wexp_num].speed      = 0.0025f;
   game.wexp[wexp_num].value      = 0;
   return(0);
}
/*----------------------------------------------------------------------------*/
int kill_wexps(void)
{
   for (int count = 0;count < MAX_WEXPS;count++)
   {
      game.wexp[count].active     = false;
      game.wexp[count].image      = 338;
      game.wexp[count].sound      = 22;
      game.wexp[count].x_pos      = -2.0f;
      game.wexp[count].y_pos      = -2.0f;
      game.wexp[count].width      = 0.10f;
      game.wexp[count].hight      = 0.10f;
      game.wexp[count].speed      = 0.0025f;
      game.wexp[count].value      = 0;
   }
   return(0);
}
/*----------------------------------------------------------------------------*/
int init_wexp(void)
{
   for (int count = 0;count < MAX_WEXPS;count++)
   {
      game.wexp[count].active     = false;
      game.wexp[count].image      = 338;
      game.wexp[count].sound      = 22;
      game.wexp[count].x_pos      = -2.0f;
      game.wexp[count].y_pos      = -2.0f;
      game.wexp[count].width      = 0.10f;
      game.wexp[count].hight      = 0.10f;
      game.wexp[count].speed      = 0.0025f;
      game.wexp[count].value      = 0;
   }
   return(0);
}
/*----------------------------------------------------------------------------*/
int proccess_wexp(void)
{
   for (int count = 0; count < MAX_WEXPS; count++)
   {
      if (game.wexp[count].active)
      {
         game.wexp[count].x_pos -= game.wexp[count].speed;
         if (game.wexp[count].x_pos <= (-1.0f - game.wexp[count].width)) kill_wexp(count);
         if (quadrangle_collision(game.player.x_pos,game.player.y_pos,game.player.width,game.player.hight,game.wexp[count].x_pos,game.wexp[count].y_pos,game.wexp[count].width,game.wexp[count].hight))
         {
            //level up our front weapon!
            game.projectile[game.player.front_weapon].experience += game.wexp[count].value*game.exp_rate;
            if ((game.projectile[game.player.front_weapon].experience >= game.projectile[game.player.front_weapon].level_1) && (game.projectile[game.player.front_weapon].level == 0))
            {
               spawn_p_weapon_level_up();
               game.projectile[game.player.front_weapon].level = 1;
               game.projectile[game.player.front_weapon].experience = 0;
            }
            if ((game.projectile[game.player.front_weapon].experience >= game.projectile[game.player.front_weapon].level_2) && (game.projectile[game.player.front_weapon].level == 1))
            {
               spawn_p_weapon_level_up();
               game.projectile[game.player.front_weapon].level = 2;
               game.projectile[game.player.front_weapon].experience = 0;
            }
            if ((game.projectile[game.player.front_weapon].experience >= game.projectile[game.player.front_weapon].level_3) && (game.projectile[game.player.front_weapon].level == 2))
            {
               spawn_p_weapon_level_up();
               game.projectile[game.player.front_weapon].level = 3;
               game.projectile[game.player.front_weapon].experience = game.projectile[game.player.front_weapon].level_3;
            }
            if ((game.projectile[game.player.front_weapon].experience >= game.projectile[game.player.front_weapon].level_3) && (game.projectile[game.player.front_weapon].level == 3))
            {
               //spawn_p_weapon_level_up();
               game.projectile[game.player.front_weapon].level = 3;
               game.projectile[game.player.front_weapon].experience = game.projectile[game.player.front_weapon].level_3;
            }
            //level up our side weapon!
            game.projectile[game.player.side_weapon].experience += game.wexp[count].value*game.exp_rate;
            if ((game.projectile[game.player.side_weapon].experience >= game.projectile[game.player.side_weapon].level_1) && (game.projectile[game.player.side_weapon].level == 0))
            {
               spawn_p_weapon_level_up();
               game.projectile[game.player.side_weapon].level = 1;
               game.projectile[game.player.side_weapon].experience = 0;
            }
            if ((game.projectile[game.player.side_weapon].experience >= game.projectile[game.player.side_weapon].level_2) && (game.projectile[game.player.side_weapon].level == 1))
            {
               spawn_p_weapon_level_up();
               game.projectile[game.player.side_weapon].level = 2;
               game.projectile[game.player.side_weapon].experience = 0;
            }
            if ((game.projectile[game.player.side_weapon].experience >= game.projectile[game.player.side_weapon].level_3) && (game.projectile[game.player.side_weapon].level == 2))
            {
               spawn_p_weapon_level_up();
               game.projectile[game.player.side_weapon].level = 3;
               game.projectile[game.player.side_weapon].experience = game.projectile[game.player.side_weapon].level_3;
            }
            if ((game.projectile[game.player.side_weapon].experience >= game.projectile[game.player.side_weapon].level_3) && (game.projectile[game.player.side_weapon].level == 3))
            {
               //spawn_p_weapon_level_up();
               game.projectile[game.player.side_weapon].level = 3;
               game.projectile[game.player.side_weapon].experience = game.projectile[game.player.side_weapon].level_3;
            }
            kill_wexp(count);
            play_sound(game.wexp[count].sound);
         }
      }
   }
   return(0);
}
/*----------------------------------------------------------------------------*/
int spawn_explosion(float x_position, float y_position, float size)
{
   bool spawn_done = 0;
   int  explosion_num;
   for  (explosion_num = 0; explosion_num < MAX_EXPLOSIONS;explosion_num++)
   {
       if (!spawn_done and !game.explosion[explosion_num].active)
       {
           game.explosion[explosion_num].active  = true;
           game.explosion[explosion_num].frame   = 0;
           game.explosion[explosion_num].image   = 185;
           game.explosion[explosion_num].sound   = 4;
           game.explosion[explosion_num].size    = size;
           game.explosion[explosion_num].width   = size/2;
           game.explosion[explosion_num].hight   = size/2;
           game.explosion[explosion_num].x_pos   = x_position;
           game.explosion[explosion_num].y_pos   = y_position;
           spawn_done = 1;
       }
   }
   return(0);
}
/*----------------------------------------------------------------------------*/
int kill_explosion(int explosion_num)
{
   game.explosion[explosion_num].active  = false;
   game.explosion[explosion_num].frame   = 0;
   game.explosion[explosion_num].image   = 185;
   game.explosion[explosion_num].sound   = 4;
   game.explosion[explosion_num].x_pos   = 0.0f;
   game.explosion[explosion_num].y_pos   = 0.0f;
   game.explosion[explosion_num].size    = 0.0f;
   return(0);
}
/*----------------------------------------------------------------------------*/
int init_explosions(void)
{
   for (int count =0;count < MAX_EXPLOSIONS;count++)
   {
      game.explosion[count].active  = false;
      game.explosion[count].frame   = 0;
      game.explosion[count].image   = 185;
      game.explosion[count].sound   = 4;
      game.explosion[count].x_pos   = 0.0f;
      game.explosion[count].y_pos   = 0.0f;
      game.explosion[count].size    = 0.0f;
   }
   return(0);
}
/*----------------------------------------------------------------------------*/
int proccess_explosions(void)
{
   for (int count =0;count < MAX_EXPLOSIONS;count++)
   {
      if(game.explosion[count].active)
      {
         game.explosion[count].x_pos -= (game.background_scroll[0].scroll_rate*2);
         game.explosion[count].frame++;
         if (game.explosion[count].frame > 24)
         {
            game.explosion[count].active = false;
            game.explosion[count].frame   = 0;
         }
      }
   }
   return(0);
}
/*----------------------------------------------------------------------------*/
int spawn_player_bullet_num(int player_bullet_num, int location)
{
       //           play_sound(game.projectile[game.player.front_weapon].sound);

   if (player_bullet_num > MAX_BULLETS) player_bullet_num = MAX_BULLETS;
   game.player.bullet[player_bullet_num].active   = true;
   game.player.bullet[player_bullet_num].location = location;
   if (location < 3) game.player.bullet[player_bullet_num].warhead = game.player.front_weapon;
   else              game.player.bullet[player_bullet_num].warhead = game.player.side_weapon;
   game.player.bullet[player_bullet_num].x_pos    = (game.player.x_pos + (game.player.width/2));
   if (location == 0) game.player.bullet[player_bullet_num].y_pos =(game.player.y_pos + (game.player.hight/2))-0.02f;
   if (location == 1) game.player.bullet[player_bullet_num].y_pos = game.player.y_pos;
   if (location == 2) game.player.bullet[player_bullet_num].y_pos =(game.player.y_pos - (game.player.hight/2))+0.02f;
   if (location == 3) game.player.bullet[player_bullet_num].y_pos =(game.player.y_pos + (game.player.hight/2))-0.02f;
   if (location == 4) game.player.bullet[player_bullet_num].y_pos = game.player.y_pos;
   if (location == 5) game.player.bullet[player_bullet_num].y_pos =(game.player.y_pos - (game.player.hight/2))+0.02f;
   if (location == 6) game.player.bullet[player_bullet_num].y_pos =(game.player.y_pos + (game.player.hight/2))-0.02f;
   if (location == 7) game.player.bullet[player_bullet_num].y_pos = game.player.y_pos;
   if (location == 8) game.player.bullet[player_bullet_num].y_pos =(game.player.y_pos - (game.player.hight/2))+0.02f;
   game.player.bullet[player_bullet_num].wave_hight     =  game.projectile[game.player.bullet[player_bullet_num].warhead].wave_size;
   game.player.bullet[player_bullet_num].wave_count     =  0.0f;
   game.player.bullet[player_bullet_num].wave_speed     =  game.projectile[game.player.bullet[player_bullet_num].warhead].wave_velocity;
   if (location == 0) game.player.bullet[player_bullet_num].wave_direction =  1;
   if (location == 1) game.player.bullet[player_bullet_num].wave_direction =  1;
   if (location == 2) game.player.bullet[player_bullet_num].wave_direction =  0;
   if (location == 3) game.player.bullet[player_bullet_num].wave_direction =  1;
   if (location == 4) game.player.bullet[player_bullet_num].wave_direction =  0;
   if (location == 5) game.player.bullet[player_bullet_num].wave_direction =  0;
   if (location == 6) game.player.bullet[player_bullet_num].wave_direction =  1;
   if (location == 7) game.player.bullet[player_bullet_num].wave_direction =  1;
   if (location == 8) game.player.bullet[player_bullet_num].wave_direction =  0;
   if (location < 3) game.player.bullet[player_bullet_num].width = game.projectile[game.player.front_weapon].size;
   else              game.player.bullet[player_bullet_num].width = game.projectile[game.player.side_weapon].size;
   if (location < 3) game.player.bullet[player_bullet_num].hight = game.projectile[game.player.front_weapon].size;
   else              game.player.bullet[player_bullet_num].hight = game.projectile[game.player.side_weapon].size;
   return(0);
}
/*----------------------------------------------------------------------------*/
int spawn_player_bullet(int position)
{
   bool spawn_done = 0;
   int  player_bullet_num;
   if (((position == 0) && (game.player.front_weapon > -1)) || ((position == 1) && (game.player.side_weapon > -1)))
   {
      if (position == 0)//front weapon
      {
         play_sound(game.projectile[game.player.front_weapon].sound);
         if (game.projectile[game.player.front_weapon].level == 0)
         {
            spawn_done = 0;
            for  (player_bullet_num = 0; player_bullet_num < MAX_BULLETS;player_bullet_num++)
            {
               if (!spawn_done and !game.player.bullet[player_bullet_num].active)
               {
                  spawn_player_bullet_num(player_bullet_num,1);
                  spawn_done = 1;
               }
            }
         }
         if (game.projectile[game.player.front_weapon].level == 1)
         {
            spawn_done = 0;
            for  (player_bullet_num = 0; player_bullet_num < MAX_BULLETS;player_bullet_num++)
            {
               if (!spawn_done and !game.player.bullet[player_bullet_num].active)
               {
                  spawn_player_bullet_num(player_bullet_num,0);
                  spawn_done = 1;
               }
            }
            spawn_done = 0;
            for  (player_bullet_num = 0; player_bullet_num < MAX_BULLETS;player_bullet_num++)
            {
               if (!spawn_done and !game.player.bullet[player_bullet_num].active)
               {
                  spawn_player_bullet_num(player_bullet_num,2);
                  spawn_done = 1;
               }
            }
         }
         if (game.projectile[game.player.front_weapon].level >= 2)
         {
            spawn_done = 0;
            for  (player_bullet_num = 0; player_bullet_num < MAX_BULLETS;player_bullet_num++)
            {
               if (!spawn_done and !game.player.bullet[player_bullet_num].active)
               {
                  spawn_player_bullet_num(player_bullet_num,0);
                  spawn_done = 1;
               }
            }
            spawn_done = 0;
            for  (player_bullet_num = 0; player_bullet_num < MAX_BULLETS;player_bullet_num++)
            {
               if (!spawn_done and !game.player.bullet[player_bullet_num].active)
               {
                  spawn_player_bullet_num(player_bullet_num,1);
                  spawn_done = 1;
               }
            }
            spawn_done = 0;
            for  (player_bullet_num = 0; player_bullet_num < MAX_BULLETS;player_bullet_num++)
            {
               if (!spawn_done and !game.player.bullet[player_bullet_num].active)
               {
                  spawn_player_bullet_num(player_bullet_num,2);
                  spawn_done = 1;
               }
            }
         }
      }
      if (position == 1)//side weapon
      {
         play_sound(game.projectile[game.player.side_weapon].sound);
         if (game.projectile[game.player.side_weapon].level == 0)
         {
            spawn_done = 0;
            for  (player_bullet_num = 0; player_bullet_num < MAX_BULLETS;player_bullet_num++)
            {
               if (!spawn_done and !game.player.bullet[player_bullet_num].active)
               {
                  spawn_player_bullet_num(player_bullet_num,4);
                  spawn_done = 1;
               }
            }
            spawn_done = 0;
            for  (player_bullet_num = 0; player_bullet_num < MAX_BULLETS;player_bullet_num++)
            {
               if (!spawn_done and !game.player.bullet[player_bullet_num].active)
               {
                  spawn_player_bullet_num(player_bullet_num,7);
                  spawn_done = 1;
               }
            }
         }
         if (game.projectile[game.player.side_weapon].level == 1)
         {
            spawn_done = 0;
            for  (player_bullet_num = 0; player_bullet_num < MAX_BULLETS;player_bullet_num++)
            {
               if (!spawn_done and !game.player.bullet[player_bullet_num].active)
               {
                  spawn_player_bullet_num(player_bullet_num,3);
                  spawn_done = 1;
               }
            }
            spawn_done = 0;
            for  (player_bullet_num = 0; player_bullet_num < MAX_BULLETS;player_bullet_num++)
            {
               if (!spawn_done and !game.player.bullet[player_bullet_num].active)
               {
                  spawn_player_bullet_num(player_bullet_num,5);
                  spawn_done = 1;
               }
            }
            spawn_done = 0;
            for  (player_bullet_num = 0; player_bullet_num < MAX_BULLETS;player_bullet_num++)
            {
               if (!spawn_done and !game.player.bullet[player_bullet_num].active)
               {
                  spawn_player_bullet_num(player_bullet_num,6);
                  spawn_done = 1;
               }
            }
            spawn_done = 0;
            for  (player_bullet_num = 0; player_bullet_num < MAX_BULLETS;player_bullet_num++)
            {
               if (!spawn_done and !game.player.bullet[player_bullet_num].active)
               {
                  spawn_player_bullet_num(player_bullet_num,8);
                  spawn_done = 1;
               }
            }
         }
         if (game.projectile[game.player.side_weapon].level >= 2)
         {
            spawn_done = 0;
            for  (player_bullet_num = 0; player_bullet_num < MAX_BULLETS;player_bullet_num++)
            {
               if (!spawn_done and !game.player.bullet[player_bullet_num].active)
               {
                  spawn_player_bullet_num(player_bullet_num,4);
                  spawn_done = 1;
               }
            }
            spawn_done = 0;
            for  (player_bullet_num = 0; player_bullet_num < MAX_BULLETS;player_bullet_num++)
            {
               if (!spawn_done and !game.player.bullet[player_bullet_num].active)
               {
                  spawn_player_bullet_num(player_bullet_num,7);
                  spawn_done = 1;
               }
            }
            spawn_done = 0;
            for  (player_bullet_num = 0; player_bullet_num < MAX_BULLETS;player_bullet_num++)
            {
               if (!spawn_done and !game.player.bullet[player_bullet_num].active)
               {
                  spawn_player_bullet_num(player_bullet_num,3);
                  spawn_done = 1;
               }
            }
            spawn_done = 0;
            for  (player_bullet_num = 0; player_bullet_num < MAX_BULLETS;player_bullet_num++)
            {
               if (!spawn_done and !game.player.bullet[player_bullet_num].active)
               {
                  spawn_player_bullet_num(player_bullet_num,5);
                  spawn_done = 1;
               }
            }
            spawn_done = 0;
            for  (player_bullet_num = 0; player_bullet_num < MAX_BULLETS;player_bullet_num++)
            {
               if (!spawn_done and !game.player.bullet[player_bullet_num].active)
               {
                  spawn_player_bullet_num(player_bullet_num,6);
                  spawn_done = 1;
               }
            }
            spawn_done = 0;
            for  (player_bullet_num = 0; player_bullet_num < MAX_BULLETS;player_bullet_num++)
            {
               if (!spawn_done and !game.player.bullet[player_bullet_num].active)
               {
                  spawn_player_bullet_num(player_bullet_num,8);
                  spawn_done = 1;
               }
            }
         }
      }
   }
 return(spawn_done);
}
/*----------------------------------------------------------------------------*/
int kill_player_bullet(int player_bullet_num)
{
  if (player_bullet_num > MAX_BULLETS) player_bullet_num = MAX_BULLETS;
  game.player.bullet[player_bullet_num].active  = false;
  return player_bullet_num;
}
/*----------------------------------------------------------------------------*/
int init_player_bullets(void)
{
   for (int num_player_bullets = 0; num_player_bullets < MAX_BULLETS; num_player_bullets++) kill_player_bullet(num_player_bullets);
   return(1);
}
/*----------------------------------------------------------------------------*/
int proccess_player_bullets(void)
{
   int   random_temp     =  0;
   int   target_id       = -1;
   float target_distance = 10.0f;
   float temp_distance   =  0.0f;
   float x_temp_velocity =  0.0f;
   float y_temp_velocity =  0.0f;
   for (int player_bullet_num = 0; player_bullet_num < MAX_BULLETS; player_bullet_num++)
   {
      if (game.player.bullet[player_bullet_num].active)
      {
         switch (game.projectile[game.player.bullet[player_bullet_num].warhead].movement)
         {
            case 0://bullet moves in a straight line
               if (game.player.bullet[player_bullet_num].location < 3) game.player.bullet[player_bullet_num].x_pos += game.projectile[game.player.front_weapon].speed;
               else game.player.bullet[player_bullet_num].x_pos += game.projectile[game.player.side_weapon].speed;
               if (game.player.bullet[player_bullet_num].location == 3) game.player.bullet[player_bullet_num].y_pos += (game.projectile[game.player.bullet[player_bullet_num].warhead].speed / 1);
               if (game.player.bullet[player_bullet_num].location == 4) game.player.bullet[player_bullet_num].y_pos += (game.projectile[game.player.bullet[player_bullet_num].warhead].speed / 2);
               if (game.player.bullet[player_bullet_num].location == 5) game.player.bullet[player_bullet_num].y_pos += (game.projectile[game.player.bullet[player_bullet_num].warhead].speed / 3);
               if (game.player.bullet[player_bullet_num].location == 6) game.player.bullet[player_bullet_num].y_pos -= (game.projectile[game.player.bullet[player_bullet_num].warhead].speed / 3);
               if (game.player.bullet[player_bullet_num].location == 7) game.player.bullet[player_bullet_num].y_pos -= (game.projectile[game.player.bullet[player_bullet_num].warhead].speed / 2);
               if (game.player.bullet[player_bullet_num].location == 8) game.player.bullet[player_bullet_num].y_pos -= (game.projectile[game.player.bullet[player_bullet_num].warhead].speed / 1);
            break;
            case 1://bullet homes in on closest enemy
               target_id       = -1;
               target_distance = 10.0f;
               temp_distance   =  0.0f;
               for (int npc_count = 0; npc_count < MAX_NPCS; npc_count++)
               {
                  if (game.npc[npc_count].active)// find closest enemy
                  {
                     temp_distance = distance_2D(game.player.x_pos,game.player.y_pos,game.npc[npc_count].x_pos,game.npc[npc_count].y_pos);
                     if (target_distance > temp_distance)
                     {
                        target_distance = temp_distance;
                        target_id = npc_count;
                     }
                  }
               }
               if (game.active_npc_count > 0)
               {
                  //calculate new vector / bullet speed
                  x_temp_velocity = (game.player.x_pos+2)-(game.npc[target_id].x_pos-2);
                  if (x_temp_velocity < 0) x_temp_velocity *= -1;
                  y_temp_velocity = (game.player.y_pos+2)-(game.npc[target_id].y_pos-2);
                  if (y_temp_velocity < 0) y_temp_velocity *= -1;
                  if (x_temp_velocity < y_temp_velocity)
                  {
                     x_temp_velocity = ((x_temp_velocity/y_temp_velocity) * game.projectile[game.player.bullet[player_bullet_num].warhead].speed) + game.projectile[game.player.bullet[player_bullet_num].warhead].speed;
                     y_temp_velocity = game.projectile[game.player.bullet[player_bullet_num].warhead].speed;
                  }
                  else
                  {
                     y_temp_velocity = ((x_temp_velocity/y_temp_velocity) * game.projectile[game.player.bullet[player_bullet_num].warhead].speed) + game.projectile[game.player.bullet[player_bullet_num].warhead].speed;
                     x_temp_velocity = game.projectile[game.player.bullet[player_bullet_num].warhead].speed;
                  }
                  if (game.player.bullet[player_bullet_num].x_pos < game.npc[target_id].x_pos) game.player.bullet[player_bullet_num].x_pos += x_temp_velocity;
                  if (game.player.bullet[player_bullet_num].x_pos > game.npc[target_id].x_pos) game.player.bullet[player_bullet_num].x_pos -= x_temp_velocity;
                  if (game.player.bullet[player_bullet_num].y_pos < game.npc[target_id].y_pos) game.player.bullet[player_bullet_num].y_pos += y_temp_velocity;
                  if (game.player.bullet[player_bullet_num].y_pos > game.npc[target_id].y_pos) game.player.bullet[player_bullet_num].y_pos -= y_temp_velocity;
               }
               else
               {
                  if (game.player.bullet[player_bullet_num].location < 3) game.player.bullet[player_bullet_num].x_pos += game.projectile[game.player.front_weapon].speed;
                  else game.player.bullet[player_bullet_num].x_pos += game.projectile[game.player.side_weapon].speed;
                  if (game.player.bullet[player_bullet_num].location == 3) game.player.bullet[player_bullet_num].y_pos += (game.projectile[game.player.bullet[player_bullet_num].warhead].speed / 1);
                  if (game.player.bullet[player_bullet_num].location == 4) game.player.bullet[player_bullet_num].y_pos += (game.projectile[game.player.bullet[player_bullet_num].warhead].speed / 2);
                  if (game.player.bullet[player_bullet_num].location == 5) game.player.bullet[player_bullet_num].y_pos += (game.projectile[game.player.bullet[player_bullet_num].warhead].speed / 3);
                  if (game.player.bullet[player_bullet_num].location == 6) game.player.bullet[player_bullet_num].y_pos -= (game.projectile[game.player.bullet[player_bullet_num].warhead].speed / 3);
                  if (game.player.bullet[player_bullet_num].location == 7) game.player.bullet[player_bullet_num].y_pos -= (game.projectile[game.player.bullet[player_bullet_num].warhead].speed / 2);
                  if (game.player.bullet[player_bullet_num].location == 8) game.player.bullet[player_bullet_num].y_pos -= (game.projectile[game.player.bullet[player_bullet_num].warhead].speed / 1);
               }
            break;
            case 2://bullet moves in a wave like pattern
               if (game.player.bullet[player_bullet_num].location < 3) game.player.bullet[player_bullet_num].x_pos += game.projectile[game.player.front_weapon].speed;
               else game.player.bullet[player_bullet_num].x_pos += game.projectile[game.player.side_weapon].speed;
               game.player.bullet[player_bullet_num].wave_count += game.player.bullet[player_bullet_num].wave_speed;
               if (game.player.bullet[player_bullet_num].wave_count >= game.player.bullet[player_bullet_num].wave_hight)
               {
                  game.player.bullet[player_bullet_num].wave_count = 0.0f;
                  game.player.bullet[player_bullet_num].wave_direction = !game.player.bullet[player_bullet_num].wave_direction;
               }
               if (game.player.bullet[player_bullet_num].wave_direction == true) game.player.bullet[player_bullet_num].y_pos += game.player.bullet[player_bullet_num].wave_speed;
               else game.player.bullet[player_bullet_num].y_pos -= game.player.bullet[player_bullet_num].wave_speed;
               if (game.player.bullet[player_bullet_num].location == 3) game.player.bullet[player_bullet_num].y_pos += (game.projectile[game.player.bullet[player_bullet_num].warhead].speed / 1);
               if (game.player.bullet[player_bullet_num].location == 4) game.player.bullet[player_bullet_num].y_pos += (game.projectile[game.player.bullet[player_bullet_num].warhead].speed / 2);
               if (game.player.bullet[player_bullet_num].location == 5) game.player.bullet[player_bullet_num].y_pos += (game.projectile[game.player.bullet[player_bullet_num].warhead].speed / 3);
               if (game.player.bullet[player_bullet_num].location == 6) game.player.bullet[player_bullet_num].y_pos -= (game.projectile[game.player.bullet[player_bullet_num].warhead].speed / 3);
               if (game.player.bullet[player_bullet_num].location == 7) game.player.bullet[player_bullet_num].y_pos -= (game.projectile[game.player.bullet[player_bullet_num].warhead].speed / 2);
               if (game.player.bullet[player_bullet_num].location == 8) game.player.bullet[player_bullet_num].y_pos -= (game.projectile[game.player.bullet[player_bullet_num].warhead].speed / 1);
            break;
            case 3://bullet speeds up as it moves
               game.player.bullet[player_bullet_num].wave_count += game.player.bullet[player_bullet_num].wave_speed;
               if (game.player.bullet[player_bullet_num].location < 3)
               {
                  x_temp_velocity = game.player.bullet[player_bullet_num].wave_count + game.projectile[game.player.front_weapon].speed;
                  game.player.bullet[player_bullet_num].x_pos += x_temp_velocity;
               }
               else
               {
                 x_temp_velocity = game.player.bullet[player_bullet_num].wave_count + game.projectile[game.player.side_weapon].speed;
                 game.player.bullet[player_bullet_num].x_pos += x_temp_velocity;
               }
               if (game.player.bullet[player_bullet_num].location == 3) game.player.bullet[player_bullet_num].y_pos += ((game.projectile[game.player.bullet[player_bullet_num].warhead].speed*3) / 1);
               if (game.player.bullet[player_bullet_num].location == 4) game.player.bullet[player_bullet_num].y_pos += ((game.projectile[game.player.bullet[player_bullet_num].warhead].speed*3) / 2);
               if (game.player.bullet[player_bullet_num].location == 5) game.player.bullet[player_bullet_num].y_pos += ((game.projectile[game.player.bullet[player_bullet_num].warhead].speed*3) / 3);
               if (game.player.bullet[player_bullet_num].location == 6) game.player.bullet[player_bullet_num].y_pos -= ((game.projectile[game.player.bullet[player_bullet_num].warhead].speed*3) / 3);
               if (game.player.bullet[player_bullet_num].location == 7) game.player.bullet[player_bullet_num].y_pos -= ((game.projectile[game.player.bullet[player_bullet_num].warhead].speed*3) / 2);
               if (game.player.bullet[player_bullet_num].location == 8) game.player.bullet[player_bullet_num].y_pos -= ((game.projectile[game.player.bullet[player_bullet_num].warhead].speed*3) / 1);
            break;
            default:
               if (game.player.bullet[player_bullet_num].location < 3) game.player.bullet[player_bullet_num].x_pos += game.projectile[game.player.front_weapon].speed;
               else game.player.bullet[player_bullet_num].x_pos += game.projectile[game.player.side_weapon].speed;
               if (game.player.bullet[player_bullet_num].location == 3) game.player.bullet[player_bullet_num].y_pos += (game.projectile[game.player.bullet[player_bullet_num].warhead].speed / 1);
               if (game.player.bullet[player_bullet_num].location == 4) game.player.bullet[player_bullet_num].y_pos += (game.projectile[game.player.bullet[player_bullet_num].warhead].speed / 2);
               if (game.player.bullet[player_bullet_num].location == 5) game.player.bullet[player_bullet_num].y_pos += (game.projectile[game.player.bullet[player_bullet_num].warhead].speed / 3);
               if (game.player.bullet[player_bullet_num].location == 6) game.player.bullet[player_bullet_num].y_pos -= (game.projectile[game.player.bullet[player_bullet_num].warhead].speed / 3);
               if (game.player.bullet[player_bullet_num].location == 7) game.player.bullet[player_bullet_num].y_pos -= (game.projectile[game.player.bullet[player_bullet_num].warhead].speed / 2);
               if (game.player.bullet[player_bullet_num].location == 8) game.player.bullet[player_bullet_num].y_pos -= (game.projectile[game.player.bullet[player_bullet_num].warhead].speed / 1);
         }
         // if a bullet goes out of the screen kill it!!!!
         if (game.player.bullet[player_bullet_num].x_pos < -1.0f) kill_player_bullet(player_bullet_num);
         if (game.player.bullet[player_bullet_num].x_pos >  1.0f) kill_player_bullet(player_bullet_num);
         if (game.player.bullet[player_bullet_num].y_pos < -1.0f) kill_player_bullet(player_bullet_num);
         if (game.player.bullet[player_bullet_num].y_pos >  1.0f) kill_player_bullet(player_bullet_num);
         //---------- collision detection ---------
         for (int npc_count = 0; npc_count < MAX_NPCS; npc_count++)
         {
            if (game.npc[npc_count].active)// check player bullets / npc collisions...
            {
               if (quadrangle_collision(game.npc[npc_count].x_pos,game.npc[npc_count].y_pos,game.npc[npc_count].width,game.npc[npc_count].hight,game.player.bullet[player_bullet_num].x_pos,game.player.bullet[player_bullet_num].y_pos,game.player.bullet[player_bullet_num].width,game.player.bullet[player_bullet_num].hight))
               {
                  if (game.player.bullet[player_bullet_num].location < 3) game.npc[npc_count].health -= game.projectile[game.player.front_weapon].damage;
                  else // hit npc ship, but not a kill
                  {
                      game.npc[npc_count].health -= game.projectile[game.player.side_weapon].damage;
                      spawn_explosion(game.npc[npc_count].x_pos,game.npc[npc_count].y_pos,0.1250f);
                      if (game.npc[npc_count].damaged <= 0) game.npc[npc_count].damaged = game.npc_damage_duration;
                  }
                  kill_player_bullet(player_bullet_num);
                  if (game.npc[npc_count].health <= 0)
                  {
                     if (game.player.bullet[player_bullet_num].location < 3) //level up our front weapon!
                     {
                        game.projectile[game.player.front_weapon].experience += ((game.enemy[game.npc[npc_count].type_npc].health / 10) * game.exp_rate);
                        if ((game.projectile[game.player.front_weapon].experience >= game.projectile[game.player.front_weapon].level_1) && (game.projectile[game.player.front_weapon].level == 0))
                        {
                           spawn_p_weapon_level_up();
                           game.projectile[game.player.front_weapon].level = 1;
                           game.projectile[game.player.front_weapon].experience = 0;
                        }
                        if ((game.projectile[game.player.front_weapon].experience >= game.projectile[game.player.front_weapon].level_2) && (game.projectile[game.player.front_weapon].level == 1))
                        {
                           spawn_p_weapon_level_up();
                           game.projectile[game.player.front_weapon].level = 2;
                           game.projectile[game.player.front_weapon].experience = 0;
                        }
                        if ((game.projectile[game.player.front_weapon].experience >= game.projectile[game.player.front_weapon].level_3) && (game.projectile[game.player.front_weapon].level == 2))
                        {
                           spawn_p_weapon_level_up();
                           game.projectile[game.player.front_weapon].level = 3;
                           game.projectile[game.player.front_weapon].experience = game.projectile[game.player.front_weapon].level_3;
                        }
                        if ((game.projectile[game.player.front_weapon].experience >= game.projectile[game.player.front_weapon].level_3) && (game.projectile[game.player.front_weapon].level == 3))
                        {
                           //spawn_p_weapon_level_up();
                           game.projectile[game.player.front_weapon].level = 3;
                           game.projectile[game.player.front_weapon].experience = game.projectile[game.player.front_weapon].level_3;
                        }
                     }
                     else  //level up our side weapon!
                     {
                        game.projectile[game.player.side_weapon].experience += (game.enemy[game.npc[npc_count].type_npc].health / game.exp_rate);
                        if ((game.projectile[game.player.side_weapon].experience >= game.projectile[game.player.side_weapon].level_1) && (game.projectile[game.player.side_weapon].level == 0))
                        {
                           spawn_p_weapon_level_up();
                           game.projectile[game.player.side_weapon].level = 1;
                           game.projectile[game.player.side_weapon].experience = 0;
                        }
                        if ((game.projectile[game.player.side_weapon].experience >= game.projectile[game.player.side_weapon].level_2) && (game.projectile[game.player.side_weapon].level == 1))
                        {
                           spawn_p_weapon_level_up();
                           game.projectile[game.player.side_weapon].level = 2;
                           game.projectile[game.player.side_weapon].experience = 0;
                        }
                        if ((game.projectile[game.player.side_weapon].experience >= game.projectile[game.player.side_weapon].level_3) && (game.projectile[game.player.side_weapon].level == 2))
                        {
                           spawn_p_weapon_level_up();
                           game.projectile[game.player.side_weapon].level = 3;
                           game.projectile[game.player.side_weapon].experience = game.projectile[game.player.side_weapon].level_3;
                        }
                        if ((game.projectile[game.player.side_weapon].experience >= game.projectile[game.player.side_weapon].level_3) && (game.projectile[game.player.side_weapon].level == 3))
                        {
                           //spawn_p_weapon_level_up();
                           game.projectile[game.player.side_weapon].level = 3;
                           game.projectile[game.player.side_weapon].experience = game.projectile[game.player.side_weapon].level_3;
                        }
                     }
                     random_temp = random_int();
                     if (random_temp <= game.coin_spawn_rate) //spawn coin
                     {
                        spawn_coin(game.npc[npc_count].x_pos,game.npc[npc_count].y_pos,(game.npc[npc_count].type_npc+1+random_dec()));
                     }
                     if ((random_temp > game.coin_spawn_rate) && (random_temp <= game.wexp_spawn_rate)) //spawn wexp
                     {
                        spawn_wexp(game.npc[npc_count].x_pos,game.npc[npc_count].y_pos,(game.npc[npc_count].type_npc+1+random_dec()));
                     }
                     if (random_temp > game.wexp_spawn_rate) //spawn null
                     {
                        ;
                     }
                     spawn_explosion(game.npc[npc_count].x_pos,game.npc[npc_count].y_pos,0.50f);
                     play_sound(4);
                     kill_npc(npc_count);
                     game.score += (game.npc[npc_count].type_npc + 1) * 10;
                     game.level_score += (game.npc[npc_count].type_npc + 1) * 10;
                     game.kills += 1;
                     game.level_kills += 1;
                  }
               else play_sound(0);
               }
               for (int npc_bullet_num =0;npc_bullet_num < MAX_BULLETS;npc_bullet_num++) // check player bullets / npc bullet collisions...
               {
                  if(game.npc[npc_count].bullet[npc_bullet_num].active)
                  {
                     if (quadrangle_collision(game.npc[npc_count].bullet[npc_bullet_num].x_pos,game.npc[npc_count].bullet[npc_bullet_num].y_pos,game.npc[npc_count].bullet[npc_bullet_num].width,game.npc[npc_count].bullet[npc_bullet_num].hight,game.player.bullet[player_bullet_num].x_pos,game.player.bullet[player_bullet_num].y_pos,game.player.bullet[player_bullet_num].width,game.player.bullet[player_bullet_num].hight))
                     {
                     if (game.player.bullet[player_bullet_num].location < 3) //level up our front weapon!
                     {
                        game.projectile[game.player.front_weapon].experience += game.player.bullet[player_bullet_num].warhead;
                        if ((game.projectile[game.player.front_weapon].experience >= game.projectile[game.player.front_weapon].level_1) && (game.projectile[game.player.front_weapon].level == 0))
                        {
                           spawn_p_weapon_level_up();
                           game.projectile[game.player.front_weapon].level = 1;
                           game.projectile[game.player.front_weapon].experience = 0;
                        }
                        if ((game.projectile[game.player.front_weapon].experience >= game.projectile[game.player.front_weapon].level_2) && (game.projectile[game.player.front_weapon].level == 1))
                        {
                           spawn_p_weapon_level_up();
                           game.projectile[game.player.front_weapon].level = 2;
                           game.projectile[game.player.front_weapon].experience = 0;
                        }
                        if ((game.projectile[game.player.front_weapon].experience >= game.projectile[game.player.front_weapon].level_3) && (game.projectile[game.player.front_weapon].level == 2))
                        {
                           spawn_p_weapon_level_up();
                           game.projectile[game.player.front_weapon].level = 3;
                           game.projectile[game.player.front_weapon].experience = game.projectile[game.player.front_weapon].level_3;
                        }
                        if ((game.projectile[game.player.front_weapon].experience >= game.projectile[game.player.front_weapon].level_3) && (game.projectile[game.player.front_weapon].level == 3))
                        {
                           //spawn_p_weapon_level_up();
                           game.projectile[game.player.front_weapon].level = 3;
                           game.projectile[game.player.front_weapon].experience = game.projectile[game.player.front_weapon].level_3;
                        }
                     }
                     else  //level up our side weapon!
                     {
                        game.projectile[game.player.side_weapon].experience += game.player.bullet[player_bullet_num].warhead;
                        if ((game.projectile[game.player.side_weapon].experience >= game.projectile[game.player.side_weapon].level_1) && (game.projectile[game.player.side_weapon].level == 0))
                        {
                           spawn_p_weapon_level_up();
                           game.projectile[game.player.side_weapon].level = 1;
                           game.projectile[game.player.side_weapon].experience = 0;
                        }
                        if ((game.projectile[game.player.side_weapon].experience >= game.projectile[game.player.side_weapon].level_2) && (game.projectile[game.player.side_weapon].level == 1))
                        {
                           spawn_p_weapon_level_up();
                           game.projectile[game.player.side_weapon].level = 2;
                           game.projectile[game.player.side_weapon].experience = 0;
                        }
                        if ((game.projectile[game.player.side_weapon].experience >= game.projectile[game.player.side_weapon].level_3) && (game.projectile[game.player.side_weapon].level == 2))
                        {
                           spawn_p_weapon_level_up();
                           game.projectile[game.player.side_weapon].level = 3;
                           game.projectile[game.player.side_weapon].experience = game.projectile[game.player.side_weapon].level_3;
                        }
                        if ((game.projectile[game.player.side_weapon].experience >= game.projectile[game.player.side_weapon].level_3) && (game.projectile[game.player.side_weapon].level == 3))
                        {
                           //spawn_p_weapon_level_up();
                           game.projectile[game.player.side_weapon].level = 3;
                           game.projectile[game.player.side_weapon].experience = game.projectile[game.player.side_weapon].level_3;
                        }
                     }
                        spawn_explosion(game.npc[npc_count].bullet[npc_bullet_num].x_pos,game.npc[npc_count].bullet[npc_bullet_num].y_pos,0.25f);
                        play_sound(4);
                        kill_player_bullet(player_bullet_num);
                        kill_npc_bullet(npc_count,npc_bullet_num);
                        game.score += game.npc[npc_count].type_npc + 1;
                        game.level_score += game.npc[npc_count].type_npc + 1;;
                     }
                  }
               }
            }
         }
      }
   }
}
/*----------------------------------------------------------------------------*/
float thruster_offset(void)
{
   if (game.player.thrusters < 0) return(0.0f);
   else return(0.03f);
};
/*----------------------------------------------------------------------------*/
int process_player(int command)
{
   //level up our trusters, only if used! :)
   if ((command == 3) && (game.thruster[game.player.thrusters].level <= 2) && (game.player.thrusters >= 0))
   {
       game.thruster[game.player.thrusters].experience++;
       if (game.thruster[game.player.thrusters].level == 0)
       {
           if (game.thruster[game.player.thrusters].experience >= game.thruster[game.player.thrusters].level_1)
           {
              spawn_p_thrusters_level_up();
              game.thruster[game.player.thrusters].experience = 0;
              game.thruster[game.player.thrusters].level++;
           }
       }
       if (game.thruster[game.player.thrusters].level == 1)
       {
           if (game.thruster[game.player.thrusters].experience >= game.thruster[game.player.thrusters].level_2)
           {
              spawn_p_thrusters_level_up();
              game.thruster[game.player.thrusters].experience = 0;
              game.thruster[game.player.thrusters].level++;
           }
       }
       if (game.thruster[game.player.thrusters].level == 2)
       {
           if (game.thruster[game.player.thrusters].experience >= game.thruster[game.player.thrusters].level_3)
           {
              spawn_p_thrusters_level_up();
              game.thruster[game.player.thrusters].experience = 0;
              game.thruster[game.player.thrusters].level++;
           }
       }
   }
   if (game.level_end_phase == 1)
   {
      if (game.player.y_pos >  0.0f) game.player.y_pos -= (0.020 + game.thruster[game.player.thrusters].thrust);
      if (game.player.y_pos <  0.0f) game.player.y_pos += (0.020 + game.thruster[game.player.thrusters].thrust);
      game.player.x_pos += (0.020 + game.thruster[game.player.thrusters].thrust) + (game.level_end_count / 1000);
   }
   else
   {
      switch (command)
      {
         case 1://Up
            game.player.y_pos += (0.020 + game.thruster[game.player.thrusters].thrust + (0.0001f*game.thruster[game.player.thrusters].level));
            if (game.player.y_pos >  (1.0f -(game.player.hight/2))) game.player.y_pos = (1.0f -(game.player.hight/2));
         break;
         case 2://Down
            game.player.y_pos -= (0.020 + game.thruster[game.player.thrusters].thrust + (0.0001f*game.thruster[game.player.thrusters].level));
            if (game.player.y_pos < -(1.0f -(game.player.hight/2))) game.player.y_pos = -(1.0f -(game.player.hight/2));
         break;
         case 3://right
            game.player.x_pos += (0.020 + game.thruster[game.player.thrusters].thrust + (0.0001f*game.thruster[game.player.thrusters].level));
            if (game.player.x_pos >  (1.0f -(game.player.width/2))) game.player.x_pos = (1.0f -(game.player.width/2));
         break;
         case 4://Left
            game.player.x_pos -= (0.020 + game.thruster[game.player.thrusters].thrust + (0.0001f*game.thruster[game.player.thrusters].level));
            if (game.player.x_pos < -(1.0f - (game.player.width/2) - thruster_offset())) game.player.x_pos = -(1.0f -(game.player.width/2) - thruster_offset());
         break;
         default:
         break;
      }
   }
   for (int npc_count = 0; npc_count < MAX_NPCS; npc_count++)
   {
      if (quadrangle_collision(game.npc[npc_count].x_pos,game.npc[npc_count].y_pos,game.npc[npc_count].width,game.npc[npc_count].hight,game.player.x_pos,game.player.y_pos,game.player.width,game.player.hight))
      {
         play_sound(13);//player shield hit
         game.npc[npc_count].health -= game.projectile[game.player.front_weapon].damage;
         game.player.health -= ((game.enemy[game.npc[npc_count].type_npc].health / 1000.0f) - game.shield[game.player.front_shield].absorption);
         if (game.npc[npc_count].health < 0)
         {
            spawn_explosion(game.npc[npc_count].x_pos,game.npc[npc_count].y_pos,0.50f);
            kill_npc(npc_count);
            game.score += (game.npc[npc_count].type_npc + 1) * 10;
            game.level_score += (game.npc[npc_count].type_npc + 1) * 10;
            game.kills += 1;
            game.level_kills += 1;
         }
         else spawn_explosion(game.npc[npc_count].x_pos,game.npc[npc_count].y_pos,0.1250f);
      }
   }
   return(0);
};
/*----------------------------------------------------------------------------*/
bool level_completed(void)
{
   if ((game.level_kills >= game.victory_kills) && (game.level_spawened >= game.victory_spawened) && (game.level_score >= game.victory_score))
   {
       game.level_end_time = true;
       if (game.level_end_phase == 0)
       {
          game.level_end_count++;
          if (game.level_end_count >= game.level_end_time_out)
          {
              game.level_end_phase = 1;
              game.level_end_count = 0;
          }
       }
       if (game.level_end_phase == 1)
       {
          game.level_end_count++;
          if (game.level_end_count >= game.level_end_time_out)
          {
              game.level_end_phase = 2;
              game.level_end_count = 0;
          }
       }
       if (game.level_end_phase == 2) return(true);
       else return(false);
   }
   else return(false);
}

/*----------------------------------------------------------------------------*/
int process_game(void)
{
   float temp_x            = 0.0f;
   float temp_y            = 0.0f;
   int   temp_r            = 0;
   game.player.health += game.player.health_regen_rate;
   if (game.player.health > game.player.max_health) game.player.health = game.player.max_health;
   for (int count = 0;count < MAX_BACKGROUNDS+1;count++)//process backgrounds
   {
      game.background_scroll[count].x_pos -= game.background_scroll[count].scroll_rate;
      if (game.background_scroll[count].x_pos <= -4.0f) game.background_scroll[count].x_pos = 4.0f;
      //now for y pos scrolling
      if (game.player.y_pos >= 0.75f)
      {
         game.background_scroll[count].y_pos  -= game.background_scroll[count].scroll_rate;
         if (game.background_scroll[count].y_pos < -1.0f) game.background_scroll[count].y_pos = -1.0f;
         else
         {
            for (int npc_count = 0; npc_count < MAX_NPCS; npc_count++)
            {
                for (int bullet_count = 0; bullet_count < MAX_BULLETS; bullet_count++)
                {
                   game.npc[npc_count].bullet[bullet_count].y_pos  -= (game.thruster[game.player.thrusters].thrust/2);
                }
                game.npc[npc_count].y_pos -= (game.thruster[game.player.thrusters].thrust/2);
            }
            for (int player_bullet_num = 0; player_bullet_num < MAX_BULLETS; player_bullet_num++)
            {
               if (game.player.bullet[player_bullet_num].active)
               {
                  game.player.bullet[player_bullet_num].y_pos -= (game.thruster[game.player.thrusters].thrust/2);
               }
            }
            for (int count =0;count < MAX_EXPLOSIONS;count++)
            {
               if(game.explosion[count].active)
               {
                  game.explosion[count].y_pos -= (game.thruster[game.player.thrusters].thrust/2);
               }
            }
            for (int count = 0; count < MAX_WEXPS; count++)
            {
               if (game.wexp[count].active)
               {
                  game.wexp[count].y_pos -= (game.thruster[game.player.thrusters].thrust/2);
               }
            }
            for (int count = 0; count < MAX_COINS; count++)
            {
               if (game.coin[count].active)
               {
                  game.coin[count].y_pos -= (game.thruster[game.player.thrusters].thrust/2);
               }
            }
            for (int count = 1; count < MAX_POWERUPS; count++)
            {
               if (game.powerup[count].active)
               {
                  game.powerup[count].y_pos -= (game.thruster[game.player.thrusters].thrust/2);
               }
            }
         }
      }
      if (game.player.y_pos <= -0.75f)
      {
         game.background_scroll[count].y_pos  += game.background_scroll[count].scroll_rate;
         if (game.background_scroll[count].y_pos > 1.0f) game.background_scroll[count].y_pos = 1.0f;
         else
         {
            for (int npc_count = 0; npc_count < MAX_NPCS; npc_count++)
            {
                for (int bullet_count = 0; bullet_count < MAX_BULLETS; bullet_count++)
                {
                   game.npc[npc_count].bullet[bullet_count].y_pos  += (game.thruster[game.player.thrusters].thrust/2);
                }
                game.npc[npc_count].y_pos += (game.thruster[game.player.thrusters].thrust/2);
            }
            for (int player_bullet_num = 0; player_bullet_num < MAX_BULLETS; player_bullet_num++)
            {
               if (game.player.bullet[player_bullet_num].active)
               {
                  game.player.bullet[player_bullet_num].y_pos += (game.thruster[game.player.thrusters].thrust/2);
               }
            }
            for (int count =0;count < MAX_EXPLOSIONS;count++)
            {
               if(game.explosion[count].active)
               {
                  game.explosion[count].y_pos += (game.thruster[game.player.thrusters].thrust/2);
               }
            }
            for (int count = 0; count < MAX_WEXPS; count++)
            {
               if (game.wexp[count].active)
               {
                  game.wexp[count].y_pos += (game.thruster[game.player.thrusters].thrust/2);
               }
            }
            for (int count = 0; count < MAX_COINS; count++)
            {
               if (game.coin[count].active)
               {
                  game.coin[count].y_pos += (game.thruster[game.player.thrusters].thrust/2);
               }
            }
            for (int count = 1; count < MAX_POWERUPS; count++)
            {
               if (game.powerup[count].active)
               {
                  game.powerup[count].y_pos += (game.thruster[game.player.thrusters].thrust/2);
               }
            }
         }
      }
   }
   process_p_actinium_shields();
   process_p_blasters();
   process_p_burst_lasers();
   process_p_chain_guns();
   process_p_convolution_thrusters();
   process_p_health();
   process_p_ion_cannons();
   process_p_iridium_shileds();
   process_p_maelstrom_thrusters();
   process_p_plasma_rockets();
   process_p_rail_turrets();
   process_p_rubidium_shields();
   process_p_seismic_thrusters();
   process_p_shield_level_up();
   process_p_tantalum_shields();
   process_p_terbium_shields();
   process_p_thrusters_level_up();
   process_p_vortex_thrusters();
   process_p_weapon_level_up();
   process_a_score();
   process_a_kills();
   process_paused();
   process_loaded();
   process_saved();
   process_player(0);
   proccess_player_bullets();
   game.fw_rof_count++;
   if(game.fw_rof_count > game.projectile[game.player.front_weapon].rate_of_fire) game.fw_rof_count = game.projectile[game.player.front_weapon].rate_of_fire;
   game.sw_rof_count++;
   if(game.sw_rof_count > game.projectile[game.player.side_weapon].rate_of_fire)  game.sw_rof_count = game.projectile[game.player.side_weapon].rate_of_fire;
   proccess_npcs();
   process_waves();
   proccess_npc_bullets();
   proccess_explosions();
   proccess_powerups();
   proccess_coin();
   proccess_wexp();
   if (level_completed())
   {
      game.game_active = false;
      game.nlvl_active = true;
   }
   if (random(game.powerup[1 ].spawn_rate) <= 9) spawn_powerup(1.0f,random_GLcoord(), 1);//spawn health powerup
   if (random(game.powerup[8 ].spawn_rate) <= 9) spawn_powerup(1.0f,random_GLcoord(), 8);//spawn bomb powerup
   if (random(game.powerup[9 ].spawn_rate) <= 9) spawn_powerup(1.0f,random_GLcoord(), 9);//spawn sideship 0 powerup
   if (random(game.powerup[10].spawn_rate) <= 9) spawn_powerup(1.0f,random_GLcoord(),10);//spawn sideship 1 powerup
   if (random(game.powerup[11].spawn_rate) <= 9) spawn_powerup(1.0f,random_GLcoord(),11);//spawn sideship 2 powerup
   if (random(game.powerup[12].spawn_rate) <= 9) spawn_powerup(1.0f,random_GLcoord(),12);//spawn sideship 3 powerup
   if ((game.shield[game.player.front_shield].level  < 3) && (random(game.powerup[2].spawn_rate) == 5)) spawn_powerup(1.0f,random_GLcoord(),2);//spawn shield lvl powerup
   if ((game.thruster[game.player.thrusters].level   < 3) && (random(game.powerup[2].spawn_rate) == 5)) spawn_powerup(1.0f,random_GLcoord(),4);//spawn thruster lvl powerup
   // if player missed boss weapon drops enable random spawning of powerups to keep consistancy
   if ((game.level >=  4) && (!game.projectile[1].active) && (random(game.powerup[7].spawn_rate) == 5)) spawn_powerup(1.0f,random_GLcoord(),7); // spawn new weapon
   if ((game.level >=  7) && (!game.projectile[2].active) && (random(game.powerup[7].spawn_rate) == 5)) spawn_powerup(1.0f,random_GLcoord(),7); // spawn new weapon
   if ((game.level >= 11) && (!game.projectile[3].active) && (random(game.powerup[7].spawn_rate) == 5)) spawn_powerup(1.0f,random_GLcoord(),7); // spawn new weapon
   if ((game.level >= 15) && (!game.projectile[4].active) && (random(game.powerup[7].spawn_rate) == 5)) spawn_powerup(1.0f,random_GLcoord(),7); // spawn new weapon
   if ((game.level >= 19) && (!game.projectile[5].active) && (random(game.powerup[7].spawn_rate) == 5)) spawn_powerup(1.0f,random_GLcoord(),7); // spawn new weapon

   if ((game.level >=  7) && (!game.shield[0].active) && (random(game.powerup[3].spawn_rate) == 5)) spawn_powerup(1.0f,random_GLcoord(),3); // spawn new shield
   if ((game.level >= 11) && (!game.shield[1].active) && (random(game.powerup[3].spawn_rate) == 5)) spawn_powerup(1.0f,random_GLcoord(),3); // spawn new shield
   if ((game.level >= 15) && (!game.shield[2].active) && (random(game.powerup[3].spawn_rate) == 5)) spawn_powerup(1.0f,random_GLcoord(),3); // spawn new shield
   if ((game.level >= 19) && (!game.shield[3].active) && (random(game.powerup[3].spawn_rate) == 5)) spawn_powerup(1.0f,random_GLcoord(),3); // spawn new shield
   if ((game.level >= 23) && (!game.shield[4].active) && (random(game.powerup[3].spawn_rate) == 5)) spawn_powerup(1.0f,random_GLcoord(),3); // spawn new shield

   if ((game.level >= 15) && (!game.thruster[0].active) && (random(game.powerup[5].spawn_rate) == 5)) spawn_powerup(1.0f,random_GLcoord(),5); // spawn new thruster
   if ((game.level >= 19) && (!game.thruster[1].active) && (random(game.powerup[5].spawn_rate) == 5)) spawn_powerup(1.0f,random_GLcoord(),5); // spawn new thruster
   if ((game.level >= 23) && (!game.thruster[2].active) && (random(game.powerup[5].spawn_rate) == 5)) spawn_powerup(1.0f,random_GLcoord(),5); // spawn new thruster
   game.npc_spawn_rate_count++;
   game.npc_spawn_rate_count += random_dec()/4;
   if (game.npc_spawn_rate_count >= game.npc_spawn_rate)
   {
      game.npc_spawn_rate_count = 0;
      if ((!game.level_boss_level) && (!game.level_end_time) && (game.wave_spawnable)) spawn_wave();
      if (game.level_boss_level && (game.level_spawened == 0))
      {
         spawn_npc(1.0f,random_GLcoord(),game.level_npc_type,0,0.0f,0.0f);
         game.level_spawened += 1;
      }
   }
   for (int npc_count = 0; npc_count < MAX_NPCS; npc_count++)//npc spawn bullet
   {
      if (game.npc[npc_count].active)
      {
         if (random(game.npc_projectile_spawn_rate) == 5)
         {
            if (game.npc[npc_count].projectiles == 1)
            {
               spawn_npc_bullet(npc_count,1);
            }
            if (game.npc[npc_count].projectiles == 2)
            {
               spawn_npc_bullet(npc_count,0);
               spawn_npc_bullet(npc_count,2);
            }
            if (game.npc[npc_count].projectiles == 3)
            {
               spawn_npc_bullet(npc_count,0);
               spawn_npc_bullet(npc_count,1);
               spawn_npc_bullet(npc_count,2);
            }
            if (game.npc[npc_count].projectiles == 4)
            {
               spawn_npc_bullet(npc_count,0);
               spawn_npc_bullet(npc_count,2);
               spawn_npc_bullet(npc_count,5);
               spawn_npc_bullet(npc_count,6);
            }
            if (game.npc[npc_count].projectiles == 5)
            {
               spawn_npc_bullet(npc_count,1);
               spawn_npc_bullet(npc_count,5);
               spawn_npc_bullet(npc_count,6);
               spawn_npc_bullet(npc_count,7);
               spawn_npc_bullet(npc_count,8);
            }
            if (game.npc[npc_count].projectiles == 6)
            {
               spawn_npc_bullet(npc_count,0);
               spawn_npc_bullet(npc_count,2);
               spawn_npc_bullet(npc_count,3);
               spawn_npc_bullet(npc_count,5);
               spawn_npc_bullet(npc_count,6);
               spawn_npc_bullet(npc_count,8);
            }
            if (game.npc[npc_count].projectiles == 7)
            {
               spawn_npc_bullet(npc_count,1);
               spawn_npc_bullet(npc_count,3);
               spawn_npc_bullet(npc_count,4);
               spawn_npc_bullet(npc_count,5);
               spawn_npc_bullet(npc_count,6);
               spawn_npc_bullet(npc_count,7);
               spawn_npc_bullet(npc_count,8);
            }
            if (game.npc[npc_count].projectiles == 8)
            {
               spawn_npc_bullet(npc_count,0);
               spawn_npc_bullet(npc_count,2);
               spawn_npc_bullet(npc_count,3);
               spawn_npc_bullet(npc_count,4);
               spawn_npc_bullet(npc_count,5);
               spawn_npc_bullet(npc_count,6);
               spawn_npc_bullet(npc_count,7);
               spawn_npc_bullet(npc_count,8);
            }
            if (game.npc[npc_count].projectiles == 9)
            {
               spawn_npc_bullet(npc_count,0);
               spawn_npc_bullet(npc_count,1);
               spawn_npc_bullet(npc_count,2);
               spawn_npc_bullet(npc_count,3);
               spawn_npc_bullet(npc_count,4);
               spawn_npc_bullet(npc_count,5);
               spawn_npc_bullet(npc_count,6);
               spawn_npc_bullet(npc_count,7);
               spawn_npc_bullet(npc_count,8);
            }
            play_sound(game.projectile[game.npc[npc_count].bullet[0].warhead].sound);
         }
      }
   }
   if (game.level_end_time) process_d_level_end();
   if ((game.level_end_time) && (game.level_end_phase == 0)) //level outro
   {
     game.player.health = 0.100f;
     for (int npc_count = 0; npc_count < MAX_NPCS; npc_count++) //kill all npcs
     {
         play_sound(49);
         if (game.npc[npc_count].active)
         {
            spawn_explosion(game.npc[npc_count].x_pos,game.npc[npc_count].y_pos,0.50f);
            kill_npc(npc_count);
         }
     }
     for (int npc_count = 0; npc_count < MAX_NPCS; npc_count++)//kill all npc bullets
     {
        for (int bullet_count = 0; bullet_count < MAX_BULLETS; bullet_count++)
        {
           if (game.npc[npc_count].bullet[bullet_count].active)
           {
              spawn_explosion(game.npc[npc_count].bullet[bullet_count].x_pos,game.npc[npc_count].bullet[bullet_count].y_pos,0.125f);
              kill_npc_bullet(npc_count,bullet_count);
           }
        }
     }
     temp_r = random_int();
     if (temp_r < 6000) //spawn explosion with coin / wexp
     {
        temp_x = random_double();
        temp_y = random_double();
        temp_r = random_int();
        if (temp_r < 8000) //spawn explosion + coin
        {
           spawn_explosion(temp_x,temp_y,0.25f);
           play_sound(49);
           spawn_coin(temp_x,temp_y,1.5f);
        }
        if ((temp_r > 8000) && (temp_r < 16000)) //spawn explosion + coin
        {
           spawn_explosion(temp_x,temp_y,0.25f);
           play_sound(49);
           spawn_wexp(temp_x,temp_y,1.5f);
        }
     }
     if (!game.powerups_spawened)
     {
        if ((game.level_boss_level) && (game.level_locked[game.level + 1]))//if its first time to kill a boss spawn some powerups!!
        {
            if (game.level == 3)
            {
                spawn_powerup(1.0f,random_GLcoord(),1);//spawn health powerup
                spawn_powerup(1.0f,random_GLcoord(),4);//spawn thruster lvl powerup
                spawn_powerup(1.0f,random_GLcoord(),7);//new weapon
            }
            if (game.level == 7)
            {
                spawn_powerup(1.0f,random_GLcoord(),1);//spawn health powerup
                spawn_powerup(1.0f,random_GLcoord(),3);//spawn shield new powerup
                spawn_powerup(1.0f,random_GLcoord(),7);//new weapon
            }
            if (game.level == 11)
            {
                spawn_powerup(1.0f,random_GLcoord(),1);//spawn health powerup
                spawn_powerup(1.0f,random_GLcoord(),3);//spawn shield new powerup
                spawn_powerup(1.0f,random_GLcoord(),7);//new weapon
            }
            if (game.level == 15)
            {
                spawn_powerup(1.0f,random_GLcoord(),1);//spawn health powerup
                spawn_powerup(1.0f,random_GLcoord(),5);//spawn thruster new powerup
                spawn_powerup(1.0f,random_GLcoord(),3);//spawn shield new powerup
                spawn_powerup(1.0f,random_GLcoord(),7);//new weapon
            }
            if (game.level == 19)
            {
                spawn_powerup(1.0f,random_GLcoord(),1);//spawn health powerup
                spawn_powerup(1.0f,random_GLcoord(),5);//spawn thruster new powerup
                spawn_powerup(1.0f,random_GLcoord(),3);//spawn shield new powerup
                spawn_powerup(1.0f,random_GLcoord(),7);//new weapon
            }
            if (game.level == 23)
            {
                spawn_powerup(1.0f,random_GLcoord(),1);//spawn health powerup
                spawn_powerup(1.0f,random_GLcoord(),5);//spawn thruster new powerup
                spawn_powerup(1.0f,random_GLcoord(),3);//spawn shield new powerup
                spawn_powerup(1.0f,random_GLcoord(),6);//spawn weapon lvl powerup
            }
        }
        else
        {
           // spawn poweups if level is too low, ie. player missed the power up last level or in game or it hasnt spawned in game
           if ((game.level >=  4) && (!game.projectile[1].active)) spawn_powerup(1.0f,random_GLcoord(),7); // spawn new weapon
           if ((game.level >=  7) && (!game.projectile[2].active)) spawn_powerup(1.0f,random_GLcoord(),7); // spawn new weapon
           if ((game.level >= 11) && (!game.projectile[3].active)) spawn_powerup(1.0f,random_GLcoord(),7); // spawn new weapon
           if ((game.level >= 15) && (!game.projectile[4].active)) spawn_powerup(1.0f,random_GLcoord(),7); // spawn new weapon
           if ((game.level >= 19) && (!game.projectile[5].active)) spawn_powerup(1.0f,random_GLcoord(),7); // spawn new weapon

           if ((game.level >=  7) && (!game.shield[0].active)) spawn_powerup(1.0f,random_GLcoord(),3); // spawn new shield
           if ((game.level >= 11) && (!game.shield[1].active)) spawn_powerup(1.0f,random_GLcoord(),3); // spawn new shield
           if ((game.level >= 15) && (!game.shield[2].active)) spawn_powerup(1.0f,random_GLcoord(),3); // spawn new shield
           if ((game.level >= 19) && (!game.shield[3].active)) spawn_powerup(1.0f,random_GLcoord(),3); // spawn new shield
           if ((game.level >= 23) && (!game.shield[4].active)) spawn_powerup(1.0f,random_GLcoord(),3); // spawn new shield

           if ((game.level >= 15) && (!game.thruster[0].active)) spawn_powerup(1.0f,random_GLcoord(),5); // spawn new thruster
           if ((game.level >= 19) && (!game.thruster[1].active)) spawn_powerup(1.0f,random_GLcoord(),5); // spawn new thruster
           if ((game.level >= 23) && (!game.thruster[2].active)) spawn_powerup(1.0f,random_GLcoord(),5); // spawn new thruster
           spawn_powerup(1.0f,random_GLcoord(),1);//spawn health powerup
           spawn_powerup(1.0f,random_GLcoord(),2);//spawn shield lvl powerup
           spawn_powerup(1.0f,random_GLcoord(),4);//spawn thruster lvl powerup
        }
     game.powerups_spawened = true;
     }
     if (!game.level_end_display_active) spawn_d_level_end();
  }
   if ((game.level_end_time) && (game.level_end_phase == 1)) //level outro
   {
     game.player.health = 0.100f;
     process_player(1024);//warp player out
   }
   return(0);
};
/*----------------------------------------------------------------------------*/
int display_game(void)
{
   float z_pos = 0;
   float temp_val;
   glPushMatrix();
   glDisable(GL_DEPTH_TEST);
 //---------------------------------- display backgrounds ---------------------------------------------------------------------
   if (game.background_scroll[3].x_pos > game.background_scroll[2].x_pos)
   {
       z_pos = 0.16f;
       glBindTexture( GL_TEXTURE_2D, texture[game.background_scroll[3].image].texture);
       glLoadIdentity();
       glBegin( GL_QUADS );
       glTexCoord2i( 0, 1 );glVertex3f( 2.000f + game.background_scroll[2].x_pos,-2.000f + game.background_scroll[3].y_pos,z_pos);
       glTexCoord2i( 0, 0 );glVertex3f( 2.000f + game.background_scroll[2].x_pos, 2.000f + game.background_scroll[3].y_pos,z_pos);
       glTexCoord2i( 1, 0 );glVertex3f( 2.000f + game.background_scroll[3].x_pos, 2.000f + game.background_scroll[3].y_pos,z_pos);
       glTexCoord2i( 1, 1 );glVertex3f( 2.000f + game.background_scroll[3].x_pos,-2.000f + game.background_scroll[3].y_pos,z_pos);
       glEnd();
   }
   else
   {
       z_pos = 0.16f;
       glBindTexture( GL_TEXTURE_2D, texture[game.background_scroll[3].image].texture);
       glLoadIdentity();
       glBegin( GL_QUADS );
       glTexCoord2i( 0, 1 );glVertex3f(-2.000f + game.background_scroll[3].x_pos,-2.000f + game.background_scroll[3].y_pos,z_pos);
       glTexCoord2i( 0, 0 );glVertex3f(-2.000f + game.background_scroll[3].x_pos, 2.000f + game.background_scroll[3].y_pos,z_pos);
       glTexCoord2i( 1, 0 );glVertex3f(-2.000f + game.background_scroll[2].x_pos, 2.000f + game.background_scroll[3].y_pos,z_pos);
       glTexCoord2i( 1, 1 );glVertex3f(-2.000f + game.background_scroll[2].x_pos,-2.000f + game.background_scroll[3].y_pos,z_pos);
       glEnd();
   }
   if (game.background_scroll[2].x_pos > game.background_scroll[3].x_pos)
   {
       z_pos = 0.16f;
       glBindTexture( GL_TEXTURE_2D, texture[game.background_scroll[2].image].texture);
       glLoadIdentity();
       glBegin( GL_QUADS );
       glTexCoord2i( 0, 1 );glVertex3f( 2.000f + game.background_scroll[3].x_pos,-2.000f + game.background_scroll[2].y_pos,z_pos);
       glTexCoord2i( 0, 0 );glVertex3f( 2.000f + game.background_scroll[3].x_pos, 2.000f + game.background_scroll[2].y_pos,z_pos);
       glTexCoord2i( 1, 0 );glVertex3f( 2.000f + game.background_scroll[2].x_pos, 2.000f + game.background_scroll[2].y_pos,z_pos);
       glTexCoord2i( 1, 1 );glVertex3f( 2.000f + game.background_scroll[2].x_pos,-2.000f + game.background_scroll[2].y_pos,z_pos);
       glEnd();
   }
   else
   {
       z_pos = 0.16f;
       glBindTexture( GL_TEXTURE_2D, texture[game.background_scroll[2].image].texture);
       glLoadIdentity();
       glBegin( GL_QUADS );
       glTexCoord2i( 0, 1 );glVertex3f(-2.000f + game.background_scroll[2].x_pos,-2.000f + game.background_scroll[2].y_pos,z_pos);
       glTexCoord2i( 0, 0 );glVertex3f(-2.000f + game.background_scroll[2].x_pos, 2.000f + game.background_scroll[2].y_pos,z_pos);
       glTexCoord2i( 1, 0 );glVertex3f(-2.000f + game.background_scroll[3].x_pos, 2.000f + game.background_scroll[2].y_pos,z_pos);
       glTexCoord2i( 1, 1 );glVertex3f(-2.000f + game.background_scroll[3].x_pos,-2.000f + game.background_scroll[2].y_pos,z_pos);
       glEnd();
   }
//-----------------------------------------------------------------------------------------------------------------------
   for (int npc_count =MAX_NPCS-1;npc_count >=0;npc_count--)  // npcs
   {
      for (int bullet_count = MAX_BULLETS-1;bullet_count >=0;bullet_count--)  // npcs bullets
      {
         z_pos = 0.05f + (0.0001*bullet_count);
         glBindTexture( GL_TEXTURE_2D, texture[game.projectile[game.npc[npc_count].bullet[bullet_count].warhead].image].texture);
         glLoadIdentity();
         if (game.npc[npc_count].bullet[bullet_count].active)
         {
            glBegin( GL_QUADS );
            glTexCoord2i( 0, 1 );glVertex3f(game.npc[npc_count].bullet[bullet_count].x_pos+(game.npc[npc_count].bullet[bullet_count].width/2),game.npc[npc_count].bullet[bullet_count].y_pos-(game.npc[npc_count].bullet[bullet_count].hight/2),z_pos);
            glTexCoord2i( 0, 0 );glVertex3f(game.npc[npc_count].bullet[bullet_count].x_pos+(game.npc[npc_count].bullet[bullet_count].width/2),game.npc[npc_count].bullet[bullet_count].y_pos+(game.npc[npc_count].bullet[bullet_count].hight/2),z_pos);
            glTexCoord2i( 1, 0 );glVertex3f(game.npc[npc_count].bullet[bullet_count].x_pos-(game.npc[npc_count].bullet[bullet_count].width/2),game.npc[npc_count].bullet[bullet_count].y_pos+(game.npc[npc_count].bullet[bullet_count].hight/2),z_pos);
            glTexCoord2i( 1, 1 );glVertex3f(game.npc[npc_count].bullet[bullet_count].x_pos-(game.npc[npc_count].bullet[bullet_count].width/2),game.npc[npc_count].bullet[bullet_count].y_pos-(game.npc[npc_count].bullet[bullet_count].hight/2),z_pos);
            glEnd();
         }
      }
      z_pos = 0.04f + (0.0001*npc_count); // npc's
      if (game.npc[npc_count].active)
      {
         if (game.npc[npc_count].damaged > (game.npc_damage_duration/5)) glColor4f(1.0f,0.0f,0.0f,0.6f);
         glBindTexture( GL_TEXTURE_2D, texture[game.enemy[game.npc[npc_count].type_npc].image].texture);
         glLoadIdentity();
         glBegin( GL_QUADS );
         glTexCoord2i( 1, 1 );glVertex3f(game.npc[npc_count].x_pos+(game.npc[npc_count].width/2),game.npc[npc_count].y_pos-(game.npc[npc_count].hight/2),z_pos);
         glTexCoord2i( 0, 1 );glVertex3f(game.npc[npc_count].x_pos+(game.npc[npc_count].width/2),game.npc[npc_count].y_pos+(game.npc[npc_count].hight/2),z_pos);
         glTexCoord2i( 0, 0 );glVertex3f(game.npc[npc_count].x_pos-(game.npc[npc_count].width/2),game.npc[npc_count].y_pos+(game.npc[npc_count].hight/2),z_pos);
         glTexCoord2i( 1, 0 );glVertex3f(game.npc[npc_count].x_pos-(game.npc[npc_count].width/2),game.npc[npc_count].y_pos-(game.npc[npc_count].hight/2),z_pos);
         glEnd();
         glColor4f(1.0f,1.0f,1.0f,1.0f);
      }
   }
   for (int count =0;count < MAX_BULLETS;count++) //player bullets
   {
      if (game.player.bullet[count].active)
      {
         z_pos = 0.05f + (0.001*count);
         if (game.player.bullet[count].location < 3) glBindTexture( GL_TEXTURE_2D, texture[game.projectile[game.player.front_weapon].image].texture);
         else glBindTexture( GL_TEXTURE_2D, texture[game.projectile[game.player.side_weapon].image].texture);
         glLoadIdentity();
         glBegin( GL_QUADS );
         glTexCoord2i( 1, 0 );glVertex3f(game.player.bullet[count].x_pos+(game.player.bullet[count].width/2),game.player.bullet[count].y_pos-(game.player.bullet[count].hight/2), z_pos);
         glTexCoord2i( 1, 1 );glVertex3f(game.player.bullet[count].x_pos+(game.player.bullet[count].width/2),game.player.bullet[count].y_pos+(game.player.bullet[count].hight/2), z_pos);
         glTexCoord2i( 0, 1 );glVertex3f(game.player.bullet[count].x_pos-(game.player.bullet[count].width/2),game.player.bullet[count].y_pos+(game.player.bullet[count].hight/2), z_pos);
         glTexCoord2i( 0, 0 );glVertex3f(game.player.bullet[count].x_pos-(game.player.bullet[count].width/2),game.player.bullet[count].y_pos-(game.player.bullet[count].hight/2), z_pos);
         glEnd();
      }
   }

   for (int sideship_count = 0;sideship_count < MAX_SIDESHIPS;sideship_count++)//display sideship bullets
   {
      for (int bullet_count = 0;bullet_count < MAX_BULLETS;bullet_count++)
      {
         if (game.sideship[sideship_count].bullet[bullet_count].active)
         {
            z_pos = 0.05f + (0.001*bullet_count);
            glBindTexture( GL_TEXTURE_2D, texture[game.projectile[game.sideship[sideship_count].bullet[bullet_count].warhead].image].texture);
            glLoadIdentity();
            glBegin( GL_QUADS );
            glTexCoord2i( 1, 0 );glVertex3f(game.sideship[sideship_count].bullet[bullet_count].x_pos+(game.sideship[sideship_count].bullet[bullet_count].width/2),game.sideship[sideship_count].bullet[bullet_count].y_pos-(game.sideship[sideship_count].bullet[bullet_count].hight/2), z_pos);
            glTexCoord2i( 1, 1 );glVertex3f(game.sideship[sideship_count].bullet[bullet_count].x_pos+(game.sideship[sideship_count].bullet[bullet_count].width/2),game.sideship[sideship_count].bullet[bullet_count].y_pos+(game.sideship[sideship_count].bullet[bullet_count].hight/2), z_pos);
            glTexCoord2i( 0, 1 );glVertex3f(game.sideship[sideship_count].bullet[bullet_count].x_pos-(game.sideship[sideship_count].bullet[bullet_count].width/2),game.sideship[sideship_count].bullet[bullet_count].y_pos+(game.sideship[sideship_count].bullet[bullet_count].hight/2), z_pos);
            glTexCoord2i( 0, 0 );glVertex3f(game.sideship[sideship_count].bullet[bullet_count].x_pos-(game.sideship[sideship_count].bullet[bullet_count].width/2),game.sideship[sideship_count].bullet[bullet_count].y_pos-(game.sideship[sideship_count].bullet[bullet_count].hight/2), z_pos);
            glEnd();
         }
      }
   }

   for (int count =MAX_EXPLOSIONS;count >=0;count--)  // explosions
   {
      z_pos = 0.001f + (0.0001*count);
      glBindTexture( GL_TEXTURE_2D, texture[(game.explosion[count].image + game.explosion[count].frame)].texture);
      glLoadIdentity();
      if (game.explosion[count].active)
      {
         glBegin( GL_QUADS );
         glTexCoord2i( 1, 0 );glVertex3f(game.explosion[count].x_pos+(game.explosion[count].width/2),game.explosion[count].y_pos-(game.explosion[count].hight/2),z_pos);
         glTexCoord2i( 1, 1 );glVertex3f(game.explosion[count].x_pos+(game.explosion[count].width/2),game.explosion[count].y_pos+(game.explosion[count].hight/2),z_pos);
         glTexCoord2i( 0, 1 );glVertex3f(game.explosion[count].x_pos-(game.explosion[count].width/2),game.explosion[count].y_pos+(game.explosion[count].hight/2),z_pos);
         glTexCoord2i( 0, 0 );glVertex3f(game.explosion[count].x_pos-(game.explosion[count].width/2),game.explosion[count].y_pos-(game.explosion[count].hight/2),z_pos);
         glEnd();
      }
   }

   if (game.player.thrusters > -1)//player starship
   {
      glBindTexture( GL_TEXTURE_2D, texture[game.thruster[game.player.thrusters].image].texture); //player thrusters
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 0 );glVertex3f(game.player.x_pos+(game.player.width/2)-0.190f,game.player.y_pos-(game.player.hight/2), 0.035f );
      glTexCoord2i( 1, 0 );glVertex3f(game.player.x_pos+(game.player.width/2)-0.190f,game.player.y_pos+(game.player.hight/2), 0.035f );
      glTexCoord2i( 1, 1 );glVertex3f(game.player.x_pos-(game.player.width/2)-0.190f,game.player.y_pos+(game.player.hight/2), 0.035f );
      glTexCoord2i( 0, 1 );glVertex3f(game.player.x_pos-(game.player.width/2)-0.190f,game.player.y_pos-(game.player.hight/2), 0.035f );
      glEnd();
   }

   glBindTexture( GL_TEXTURE_2D, texture[game.player.image].texture); //player starship
   glLoadIdentity();
   glBegin( GL_QUADS );
   glTexCoord2i( 0, 0 );glVertex3f(game.player.x_pos+(game.player.width/2),game.player.y_pos-(game.player.hight/2), 0.03f );
   glTexCoord2i( 1, 0 );glVertex3f(game.player.x_pos+(game.player.width/2),game.player.y_pos+(game.player.hight/2), 0.03f );
   glTexCoord2i( 1, 1 );glVertex3f(game.player.x_pos-(game.player.width/2),game.player.y_pos+(game.player.hight/2), 0.03f );
   glTexCoord2i( 0, 1 );glVertex3f(game.player.x_pos-(game.player.width/2),game.player.y_pos-(game.player.hight/2), 0.03f );
   glEnd();

   for (int count = 0;count < MAX_SIDESHIPS;count++)
   {
      if (game.sideship[count].active)
      {
         glBindTexture( GL_TEXTURE_2D, texture[game.sideship[count].image].texture); //sideships
         glLoadIdentity();
         glBegin( GL_QUADS );//top
         glTexCoord2i( 0, 0 );glVertex3f(game.player.x_pos-(game.player.width/4)+game.sideship[count].width,game.player.y_pos+(game.player.hight/2)+game.sideship[count].height, 0.001f);
         glTexCoord2i( 1, 0 );glVertex3f(game.player.x_pos-(game.player.width/4)+game.sideship[count].width,game.player.y_pos+(game.player.hight/2)                            , 0.001f);
         glTexCoord2i( 1, 1 );glVertex3f(game.player.x_pos-(game.player.width/4)                           ,game.player.y_pos+(game.player.hight/2)                            , 0.001f);
         glTexCoord2i( 0, 1 );glVertex3f(game.player.x_pos-(game.player.width/4)                           ,game.player.y_pos+(game.player.hight/2)+game.sideship[count].height, 0.001f);
         glEnd();
         glBegin( GL_QUADS );//bottom
         glTexCoord2i( 0, 0 );glVertex3f(game.player.x_pos-(game.player.width/4)+game.sideship[count].width,game.player.y_pos-(game.player.hight/2)-game.sideship[count].height, 0.001f);
         glTexCoord2i( 1, 0 );glVertex3f(game.player.x_pos-(game.player.width/4)+game.sideship[count].width,game.player.y_pos-(game.player.hight/2)                            , 0.001f);
         glTexCoord2i( 1, 1 );glVertex3f(game.player.x_pos-(game.player.width/4)                           ,game.player.y_pos-(game.player.hight/2)                            , 0.001f);
         glTexCoord2i( 0, 1 );glVertex3f(game.player.x_pos-(game.player.width/4)                           ,game.player.y_pos-(game.player.hight/2)-game.sideship[count].height, 0.001f);
         glEnd();
      }
   }

     if (game.player.front_weapon > -1)
      {
         glBindTexture( GL_TEXTURE_2D, texture[game.player.front_weapon+211].texture); //player starship front weapon
         glLoadIdentity();
         glBegin( GL_QUADS );
         glTexCoord2i( 0, 0 );glVertex3f(game.player.x_pos+(game.player.width/8)+0.053f,game.player.y_pos-(game.player.hight/8), 0.025f );
         glTexCoord2i( 1, 0 );glVertex3f(game.player.x_pos+(game.player.width/8)+0.053f,game.player.y_pos+(game.player.hight/8), 0.025f );
         glTexCoord2i( 1, 1 );glVertex3f(game.player.x_pos-(game.player.width/8)+0.078f,game.player.y_pos+(game.player.hight/8), 0.025f );
         glTexCoord2i( 0, 1 );glVertex3f(game.player.x_pos-(game.player.width/8)+0.078f,game.player.y_pos-(game.player.hight/8), 0.025f );
         glEnd();
      }

      if (game.player.side_weapon > -1)
      {
         glBindTexture( GL_TEXTURE_2D, texture[game.player.side_weapon+211].texture); //player starship side weapons
         glLoadIdentity();
         glBegin( GL_QUADS );
         glTexCoord2i( 0, 0 );glVertex3f(game.player.x_pos+(game.player.width/6)+0.067f,game.player.y_pos-(game.player.hight/6)+0.075f, 0.025f );
         glTexCoord2i( 1, 0 );glVertex3f(game.player.x_pos+(game.player.width/6)+0.067f,game.player.y_pos+(game.player.hight/6)+0.075f, 0.025f );
         glTexCoord2i( 1, 1 );glVertex3f(game.player.x_pos-(game.player.width/6)+0.067f,game.player.y_pos+(game.player.hight/6)+0.075f, 0.025f );
         glTexCoord2i( 0, 1 );glVertex3f(game.player.x_pos-(game.player.width/6)+0.067f,game.player.y_pos-(game.player.hight/6)+0.075f, 0.025f );
         glEnd();
         glBegin( GL_QUADS );
         glTexCoord2i( 0, 0 );glVertex3f(game.player.x_pos+(game.player.width/6)+0.067f,game.player.y_pos-(game.player.hight/6)-0.075f, 0.025f );
         glTexCoord2i( 1, 0 );glVertex3f(game.player.x_pos+(game.player.width/6)+0.067f,game.player.y_pos+(game.player.hight/6)-0.075f, 0.025f );
         glTexCoord2i( 1, 1 );glVertex3f(game.player.x_pos-(game.player.width/6)+0.067f,game.player.y_pos+(game.player.hight/6)-0.075f, 0.025f );
         glTexCoord2i( 0, 1 );glVertex3f(game.player.x_pos-(game.player.width/6)+0.067f,game.player.y_pos-(game.player.hight/6)-0.075f, 0.025f );
         glEnd();
      }

   if (game.player.front_shield > -1)
   {
      glBindTexture( GL_TEXTURE_2D, texture[game.shield[game.player.front_shield].image].texture); //player starship shield
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 1, 0 );glVertex3f(game.player.x_pos+(game.player.width/1.5),game.player.y_pos-(game.player.hight/1.5), 0.02f );
      glTexCoord2i( 1, 1 );glVertex3f(game.player.x_pos+(game.player.width/1.5),game.player.y_pos+(game.player.hight/1.5), 0.02f );
      glTexCoord2i( 0, 1 );glVertex3f(game.player.x_pos-(game.player.width/1.5),game.player.y_pos+(game.player.hight/1.5), 0.02f );
      glTexCoord2i( 0, 0 );glVertex3f(game.player.x_pos-(game.player.width/1.5),game.player.y_pos-(game.player.hight/1.5), 0.02f );
      glEnd();
   }
   float  npc_num = 0.0f;
   for  (int npc_count = 0; npc_count < MAX_NPCS; npc_count++)
   {
       glBindTexture( GL_TEXTURE_2D, texture[210].texture); // npc health bars
       glLoadIdentity();
       if (game.active_npc[npc_count].active)
       {
          npc_num += 0.05f;
          glBegin( GL_QUADS );
          glTexCoord2i( 0, 1 );glVertex3f(0.89f +((game.npc[npc_count].health/game.enemy[game.npc[npc_count].type_npc].health)/10),1.0f -0.025f-npc_num, 0.001f);
          glTexCoord2i( 0, 0 );glVertex3f(0.89f +((game.npc[npc_count].health/game.enemy[game.npc[npc_count].type_npc].health)/10),1.0f +0.025f-npc_num, 0.001f);
          glTexCoord2i( 1, 0 );glVertex3f(0.89f                ,1.0f +0.025f-npc_num, 0.001f);
          glTexCoord2i( 1, 1 );glVertex3f(0.89f                ,1.0f -0.025f-npc_num, 0.001f);
          glEnd();
       }
   }

   glBindTexture( GL_TEXTURE_2D, texture[210].texture); //player health bar
   glLoadIdentity();
   glBegin( GL_QUADS );
   glTexCoord2i( 0, 1 );glVertex3f(-0.6f +((game.player.health/game.player.max_health)/5),0.900f, 0.001f);
   glTexCoord2i( 0, 0 );glVertex3f(-0.6f +((game.player.health/game.player.max_health)/5),0.975f, 0.001f);
   glTexCoord2i( 1, 0 );glVertex3f(-0.6f                                                 ,0.975f, 0.001f);
   glTexCoord2i( 1, 1 );glVertex3f(-0.6f                                                 ,0.900f, 0.001f);
   glEnd();

   for (int count = MAX_POWERUPS;count >=1;count--)  // powerups
   {
      z_pos = 0.002f + (0.0002*count);
      glBindTexture( GL_TEXTURE_2D, texture[game.powerup[count].image].texture);
      glLoadIdentity();
      if (game.powerup[count].active)
      {
         glBegin( GL_QUADS );
         glTexCoord2i( 0, 1 );glVertex3f(game.powerup[count].x_pos+(game.powerup[count].width/2),game.powerup[count].y_pos-(game.powerup[count].hight/2),z_pos);
         glTexCoord2i( 0, 0 );glVertex3f(game.powerup[count].x_pos+(game.powerup[count].width/2),game.powerup[count].y_pos+(game.powerup[count].hight/2),z_pos);
         glTexCoord2i( 1, 0 );glVertex3f(game.powerup[count].x_pos-(game.powerup[count].width/2),game.powerup[count].y_pos+(game.powerup[count].hight/2),z_pos);
         glTexCoord2i( 1, 1 );glVertex3f(game.powerup[count].x_pos-(game.powerup[count].width/2),game.powerup[count].y_pos-(game.powerup[count].hight/2),z_pos);
         glEnd();
      }
   }

   for (int count = MAX_COINS;count >=1;count--)  // coin
   {
      z_pos = 0.002f + (0.0002*(count+MAX_POWERUPS));
      glBindTexture( GL_TEXTURE_2D, texture[game.coin[count].image].texture);
      glLoadIdentity();
      if (game.coin[count].active)
      {
         glBegin( GL_QUADS );
         glTexCoord2i( 0, 1 );glVertex3f(game.coin[count].x_pos+(game.coin[count].width/2),game.coin[count].y_pos-(game.coin[count].hight/2),z_pos);
         glTexCoord2i( 0, 0 );glVertex3f(game.coin[count].x_pos+(game.coin[count].width/2),game.coin[count].y_pos+(game.coin[count].hight/2),z_pos);
         glTexCoord2i( 1, 0 );glVertex3f(game.coin[count].x_pos-(game.coin[count].width/2),game.coin[count].y_pos+(game.coin[count].hight/2),z_pos);
         glTexCoord2i( 1, 1 );glVertex3f(game.coin[count].x_pos-(game.coin[count].width/2),game.coin[count].y_pos-(game.coin[count].hight/2),z_pos);
         glEnd();
      }
   }

   for (int count = MAX_WEXPS;count >=1;count--)  // wexp
   {
      z_pos = 0.002f + (0.0002*(count+MAX_POWERUPS+MAX_COINS));
      glBindTexture( GL_TEXTURE_2D, texture[game.wexp[count].image].texture);
      glLoadIdentity();
      if (game.wexp[count].active)
      {
         glBegin( GL_QUADS );
         glTexCoord2i( 0, 1 );glVertex3f(game.wexp[count].x_pos+(game.wexp[count].width/2),game.wexp[count].y_pos-(game.wexp[count].hight/2),z_pos);
         glTexCoord2i( 0, 0 );glVertex3f(game.wexp[count].x_pos+(game.wexp[count].width/2),game.wexp[count].y_pos+(game.wexp[count].hight/2),z_pos);
         glTexCoord2i( 1, 0 );glVertex3f(game.wexp[count].x_pos-(game.wexp[count].width/2),game.wexp[count].y_pos+(game.wexp[count].hight/2),z_pos);
         glTexCoord2i( 1, 1 );glVertex3f(game.wexp[count].x_pos-(game.wexp[count].width/2),game.wexp[count].y_pos-(game.wexp[count].hight/2),z_pos);
         glEnd();
      }
   }
//------------------------------------------- display effects layer ------------------------------------------------------
   if (game.background_scroll[1].x_pos > game.background_scroll[0].x_pos)
   {
       z_pos = 0.15f;
       glBindTexture( GL_TEXTURE_2D, texture[game.background_scroll[1].image].texture);
       glLoadIdentity();
       glBegin( GL_QUADS );
       glTexCoord2i( 0, 1 );glVertex3f( 2.000f + game.background_scroll[0].x_pos,-2.000f + game.background_scroll[1].y_pos,z_pos);
       glTexCoord2i( 0, 0 );glVertex3f( 2.000f + game.background_scroll[0].x_pos, 2.000f + game.background_scroll[1].y_pos,z_pos);
       glTexCoord2i( 1, 0 );glVertex3f( 2.000f + game.background_scroll[1].x_pos, 2.000f + game.background_scroll[1].y_pos,z_pos);
       glTexCoord2i( 1, 1 );glVertex3f( 2.000f + game.background_scroll[1].x_pos,-2.000f + game.background_scroll[1].y_pos,z_pos);
       glEnd();
   }
   else
   {
       z_pos = 0.15f;
       glBindTexture( GL_TEXTURE_2D, texture[game.background_scroll[1].image].texture);
       glLoadIdentity();
       glBegin( GL_QUADS );
       glTexCoord2i( 0, 1 );glVertex3f(-2.000f + game.background_scroll[1].x_pos,-2.000f + game.background_scroll[1].y_pos,z_pos);
       glTexCoord2i( 0, 0 );glVertex3f(-2.000f + game.background_scroll[1].x_pos, 2.000f + game.background_scroll[1].y_pos,z_pos);
       glTexCoord2i( 1, 0 );glVertex3f(-2.000f + game.background_scroll[0].x_pos, 2.000f + game.background_scroll[1].y_pos,z_pos);
       glTexCoord2i( 1, 1 );glVertex3f(-2.000f + game.background_scroll[0].x_pos,-2.000f + game.background_scroll[1].y_pos,z_pos);
       glEnd();
   }
   if (game.background_scroll[0].x_pos > game.background_scroll[1].x_pos)
   {
       z_pos = 0.15f;
       glBindTexture( GL_TEXTURE_2D, texture[game.background_scroll[0].image].texture);
       glLoadIdentity();
       glBegin( GL_QUADS );
       glTexCoord2i( 0, 1 );glVertex3f( 2.000f + game.background_scroll[1].x_pos,-2.000f + game.background_scroll[0].y_pos,z_pos);
       glTexCoord2i( 0, 0 );glVertex3f( 2.000f + game.background_scroll[1].x_pos, 2.000f + game.background_scroll[0].y_pos,z_pos);
       glTexCoord2i( 1, 0 );glVertex3f( 2.000f + game.background_scroll[0].x_pos, 2.000f + game.background_scroll[0].y_pos,z_pos);
       glTexCoord2i( 1, 1 );glVertex3f( 2.000f + game.background_scroll[0].x_pos,-2.000f + game.background_scroll[0].y_pos,z_pos);
       glEnd();
   }
   else
   {
       z_pos = 0.15f;
       glBindTexture( GL_TEXTURE_2D, texture[game.background_scroll[0].image].texture);
       glLoadIdentity();
       glBegin( GL_QUADS );
       glTexCoord2i( 0, 1 );glVertex3f(-2.000f + game.background_scroll[0].x_pos,-2.000f + game.background_scroll[0].y_pos,z_pos);
       glTexCoord2i( 0, 0 );glVertex3f(-2.000f + game.background_scroll[0].x_pos, 2.000f + game.background_scroll[0].y_pos,z_pos);
       glTexCoord2i( 1, 0 );glVertex3f(-2.000f + game.background_scroll[1].x_pos, 2.000f + game.background_scroll[0].y_pos,z_pos);
       glTexCoord2i( 1, 1 );glVertex3f(-2.000f + game.background_scroll[1].x_pos,-2.000f + game.background_scroll[0].y_pos,z_pos);
       glEnd();
   }
//--------------------------------------------------------------------------------------------------------------------------------------

   if (game.player.front_weapon > -1)
   {
      glBindTexture( GL_TEXTURE_2D, texture[game.projectile[game.player.front_weapon].image].texture);// front weapon pic next to the exp bar
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 1, 0 );glVertex3f(-0.310f, 0.900f, 0.002f );
      glTexCoord2i( 1, 1 );glVertex3f(-0.310f, 0.975f, 0.002f );
      glTexCoord2i( 0, 1 );glVertex3f(-0.385f, 0.975f, 0.002f );
      glTexCoord2i( 0, 0 );glVertex3f(-0.385f, 0.900f, 0.002f );
      glEnd();

      if (game.projectile[game.player.front_weapon].level == 0) temp_val = ((game.projectile[game.player.front_weapon].experience / game.projectile[game.player.front_weapon].level_1)/5);
      if (game.projectile[game.player.front_weapon].level == 1) temp_val = ((game.projectile[game.player.front_weapon].experience / game.projectile[game.player.front_weapon].level_2)/5);
      if (game.projectile[game.player.front_weapon].level == 2) temp_val = ((game.projectile[game.player.front_weapon].experience / game.projectile[game.player.front_weapon].level_3)/5);
      if (game.projectile[game.player.front_weapon].level == 3) temp_val = 0.2f;
      glBindTexture( GL_TEXTURE_2D, texture[285].texture); //front weapon exp bar
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 1 );glVertex3f(-0.3f +temp_val,0.900f, 0.001f);
      glTexCoord2i( 0, 0 );glVertex3f(-0.3f +temp_val,0.975f, 0.001f);
      glTexCoord2i( 1, 0 );glVertex3f(-0.3f          ,0.975f, 0.001f);
      glTexCoord2i( 1, 1 );glVertex3f(-0.3f          ,0.900f, 0.001f);
      glEnd();
   }

   if (game.player.side_weapon > -1)
   {
      glBindTexture( GL_TEXTURE_2D, texture[game.projectile[game.player.side_weapon].image].texture);// side weapon pic next to the exp bar
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 1, 0 );glVertex3f(-0.010f, 0.900f, 0.002f );
      glTexCoord2i( 1, 1 );glVertex3f(-0.010f, 0.975f, 0.002f );
      glTexCoord2i( 0, 1 );glVertex3f(-0.085f, 0.975f, 0.002f );
      glTexCoord2i( 0, 0 );glVertex3f(-0.085f, 0.900f, 0.002f );
      glEnd();

      if (game.projectile[game.player.side_weapon].level == 0) temp_val = ((game.projectile[game.player.side_weapon].experience / game.projectile[game.player.side_weapon].level_1)/5);
      if (game.projectile[game.player.side_weapon].level == 1) temp_val = ((game.projectile[game.player.side_weapon].experience / game.projectile[game.player.side_weapon].level_2)/5);
      if (game.projectile[game.player.side_weapon].level == 2) temp_val = ((game.projectile[game.player.side_weapon].experience / game.projectile[game.player.side_weapon].level_3)/5);
      if (game.projectile[game.player.side_weapon].level == 3) temp_val = 0.2f;
      glBindTexture( GL_TEXTURE_2D, texture[285].texture); //side weapon exp bar
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 1 );glVertex3f( 0.0f +temp_val,0.900f, 0.001f);
      glTexCoord2i( 0, 0 );glVertex3f( 0.0f +temp_val,0.975f, 0.001f);
      glTexCoord2i( 1, 0 );glVertex3f( 0.0f          ,0.975f, 0.001f);
      glTexCoord2i( 1, 1 );glVertex3f( 0.0f          ,0.900f, 0.001f);
      glEnd();
   }

   temp_val = (1.95f*((float)game.level_kills/(float)game.victory_kills));
   glBindTexture( GL_TEXTURE_2D, texture[340].texture); //level progress bar
   glLoadIdentity();
   glBegin( GL_QUADS );
   glTexCoord2i( 0, 1 );glVertex3f(-0.975f +temp_val,-0.950f, 0.001f);
   glTexCoord2i( 0, 0 );glVertex3f(-0.975f +temp_val,-0.975f, 0.001f);
   glTexCoord2i( 1, 0 );glVertex3f(-0.975f          ,-0.975f, 0.001f);
   glTexCoord2i( 1, 1 );glVertex3f(-0.975f          ,-0.950f, 0.001f);
   glEnd();

   if (game.paused.active)                   display_paused();
   if (game.loaded.active)                   display_loaded();
   if (game.saved.active)                    display_saved();
   if (game.a_score.active)                  display_a_score();
   if (game.a_kills.active)                  display_a_kills();
   if (game.p_actinium_shields.active)       display_p_actinium_shields();
   if (game.p_blasters.active)               display_p_blasters();
   if (game.p_burst_lasers.active)           display_p_burst_lasers();
   if (game.p_chain_guns.active)             display_p_chain_guns();
   if (game.p_convolution_thrusters.active)  display_p_convolution_thrusters();
   if (game.p_health.active)                 display_p_health();
   if (game.p_ion_cannons.active)            display_p_ion_cannons();
   if (game.p_iridium_shileds.active)        display_p_iridium_shileds();
   if (game.p_maelstrom_thrusters.active)    display_p_maelstrom_thrusters();
   if (game.p_plasma_rockets.active)         display_p_plasma_rockets();
   if (game.p_rail_turrets.active)           display_p_rail_turrets();
   if (game.p_rubidium_shields.active)       display_p_rubidium_shields();
   if (game.p_seismic_thrusters.active)      display_p_seismic_thrusters();
   if (game.p_shield_level_up.active)        display_p_shield_level_up();
   if (game.p_tantalum_shields.active)       display_p_tantalum_shields();
   if (game.p_terbium_shields.active)        display_p_terbium_shields();
   if (game.p_thrusters_level_up.active)     display_p_thrusters_level_up();
   if (game.p_vortex_thrusters.active)       display_p_vortex_thrusters();
   if (game.p_weapon_level_up.active)        display_p_weapon_level_up();
   if (game.level_end_display_active)        display_d_level_end();

   font_print(128,128,192,-1.00f, 0.95f,"Score - %1.0f", game.score);
   font_print(128,128,192,-1.00f, 0.90f,"Kills - %1.0f", game.kills);
   if (game.anc_enabled) font_print(128,128,192, 0.40f, 0.95f,"Active NPCs - %1.0f",  game.active_npc_count);
   if (game.fps_enabled &&  game.anc_enabled) font_print(128,128,192, 0.40f, 0.90f,"FPS - %1.0f",  game.FPS);
   if (game.fps_enabled && !game.anc_enabled) font_print(128,128,192, 0.40f, 0.95f,"FPS - %1.0f",  game.FPS);
   glPopMatrix();
   SDL_GL_SwapBuffers();
   return(1);
};

int kill_paused(void)
{
   game.paused.active = false;
   return(1);
};

int spawn_paused(void)
{
   game.paused.active = true;
   game.paused.alpha  = 2.0f;
   return(1);
};

int display_paused(void)
{
   glBindTexture( GL_TEXTURE_2D, texture[288].texture); //display paused logo
   glLoadIdentity();
   glBegin( GL_QUADS );
   glColor4f (1.0f, 1.0f, 1.0f,game.paused.alpha);
   glTexCoord2i( 0, 1 );glVertex3f(-0.5f,-0.250f, 0.0001f);
   glTexCoord2i( 0, 0 );glVertex3f(-0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 0 );glVertex3f( 0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 1 );glVertex3f( 0.5f,-0.250f, 0.0001f);
   glColor4f (1.0f, 1.0f, 1.0f,1.0f);
   glEnd();
   return(1);
};

int process_paused(void)
{
   if (game.paused.active)
   {
      game.paused.alpha  -= 0.025f;
      if (game.paused.alpha <= 0) kill_paused();
   }
   return(1);
};

int kill_loaded(void)
{
   game.loaded.active = false;
   return(1);
};

int spawn_loaded(void)
{
   game.loaded.active = true;
   game.loaded.alpha  = 2.0f;
   return(1);
};

int display_loaded(void)
{
   glBindTexture( GL_TEXTURE_2D, texture[290].texture); //display loaded logo
   glLoadIdentity();
   glBegin( GL_QUADS );
   glColor4f (1.0f, 1.0f, 1.0f,game.loaded.alpha);
   glTexCoord2i( 0, 1 );glVertex3f(-0.5f,-0.250f, 0.0001f);
   glTexCoord2i( 0, 0 );glVertex3f(-0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 0 );glVertex3f( 0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 1 );glVertex3f( 0.5f,-0.250f, 0.0001f);
   glColor4f (1.0f, 1.0f, 1.0f,1.0f);
   glEnd();
   return(1);
};

int process_loaded(void)
{
   if (game.loaded.active)
   {
      game.loaded.alpha  -= 0.025f;
      if (game.loaded.alpha <= 0) kill_loaded();
   }
   return(1);
};

int kill_saved(void)
{
   game.saved.active = false;
   return(1);
};

int spawn_saved(void)
{
   game.saved.active = true;
   game.saved.alpha  = 3.0f;
   return(1);
};

int display_saved(void)
{
   glBindTexture( GL_TEXTURE_2D, texture[289].texture); //display saved logo
   glLoadIdentity();
   glBegin( GL_QUADS );
   glColor4f (1.0f, 1.0f, 1.0f,game.saved.alpha);
   glTexCoord2i( 0, 1 );glVertex3f(-0.5f,-0.250f, 0.0001f);
   glTexCoord2i( 0, 0 );glVertex3f(-0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 0 );glVertex3f( 0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 1 );glVertex3f( 0.5f,-0.250f, 0.0001f);
   glColor4f (1.0f, 1.0f, 1.0f,1.0f);
   glEnd();
   return(1);
};

int process_saved(void)
{
   if (game.saved.active)
   {
      game.saved.alpha  -= 0.025f;
      if (game.saved.alpha <= 0) kill_saved();
   }
   return(1);
};

int kill_a_score(void)
{
   game.a_score.active = false;
   return(1);
};

int spawn_a_score(void)
{
   game.a_score.active = true;
   game.a_score.alpha  = 3.0f;
   return(1);
};

int display_a_score(void)
{
   glBindTexture( GL_TEXTURE_2D, texture[309].texture); //display score logo
   glLoadIdentity();
   glBegin( GL_QUADS );
   glColor4f (1.0f, 1.0f, 1.0f,game.a_score.alpha);
   glTexCoord2i( 0, 1 );glVertex3f(-0.5f,-0.250f, 0.0001f);
   glTexCoord2i( 0, 0 );glVertex3f(-0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 0 );glVertex3f( 0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 1 );glVertex3f( 0.5f,-0.250f, 0.0001f);
   glColor4f (1.0f, 1.0f, 1.0f,1.0f);
   glEnd();
   return(1);
};

int process_a_score(void)
{
   if (game.a_score.active)
   {
      game.a_score.alpha  -= 0.025f;
      if (game.a_score.alpha <= 0) kill_a_score();
   }
   if ((game.score >= game.achivement.score_level_1) && (game.achivement.score < 1))
   {
      game.achivement.score = 1;
      spawn_a_score();
   };
   if ((game.score >= game.achivement.score_level_2) && (game.achivement.score < 2))
   {
      game.achivement.score = 2;
      spawn_a_score();
   };
   if ((game.score >= game.achivement.score_level_3) && (game.achivement.score < 3))
   {
      game.achivement.score = 3;
      spawn_a_score();
   };
   if ((game.score >= game.achivement.score_level_4) && (game.achivement.score < 4))
   {
      game.achivement.score = 4;
      spawn_a_score();
   };
   if ((game.score >= game.achivement.score_level_5) && (game.achivement.score < 5))
   {
      game.achivement.score = 5;
      spawn_a_score();
   };
return(1);
};

int kill_a_kills(void)
{
   game.a_kills.active = false;
   return(1);
};

int spawn_a_kills(void)
{
   game.a_kills.active = true;
   game.a_kills.alpha  = 3.0f;
   return(1);
};

int display_a_kills(void)
{
   glBindTexture( GL_TEXTURE_2D, texture[308].texture); //display kills logo
   glLoadIdentity();
   glBegin( GL_QUADS );
   glColor4f (1.0f, 1.0f, 1.0f,game.a_kills.alpha);
   glTexCoord2i( 0, 1 );glVertex3f(-0.5f,-0.250f, 0.0001f);
   glTexCoord2i( 0, 0 );glVertex3f(-0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 0 );glVertex3f( 0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 1 );glVertex3f( 0.5f,-0.250f, 0.0001f);
   glColor4f (1.0f, 1.0f, 1.0f,1.0f);
   glEnd();
   return(1);
};

int process_a_kills(void)
{
   if (game.a_kills.active)
   {
      game.a_kills.alpha  -= 0.025f;
      if (game.a_kills.alpha <= 0) kill_a_kills();
   }
   if ((game.kills >= game.achivement.kills_level_1) && (game.achivement.kills < 1))
   {
      game.achivement.kills = 1;
      spawn_a_kills();
   };
   if ((game.kills >= game.achivement.kills_level_2) && (game.achivement.kills < 2))
   {
      game.achivement.kills = 2;
      spawn_a_kills();
   };
   if ((game.kills >= game.achivement.kills_level_3) && (game.achivement.kills < 3))
   {
      game.achivement.kills = 3;
      spawn_a_kills();
   };
   if ((game.kills >= game.achivement.kills_level_4) && (game.achivement.kills < 4))
   {
      game.achivement.kills = 4;
      spawn_a_kills();
   };
   if ((game.kills >= game.achivement.kills_level_5) && (game.achivement.kills < 5))
   {
      game.achivement.kills = 5;
      spawn_a_kills();
   };
   return(1);
};

int kill_p_actinium_shields(void)
{
   game.p_actinium_shields.active = false;
   return(1);
};

int spawn_p_actinium_shields(void)
{
   game.p_actinium_shields.active = true;
   game.p_actinium_shields.alpha  = 3.0f;
   return(1);
};

int display_p_actinium_shields(void)
{
   glBindTexture( GL_TEXTURE_2D, texture[310].texture); //actinium_shields logo
   glLoadIdentity();
   glBegin( GL_QUADS );
   glColor4f (1.0f, 1.0f, 1.0f,game.p_actinium_shields.alpha);
   glTexCoord2i( 0, 1 );glVertex3f(-0.5f,-0.250f, 0.0001f);
   glTexCoord2i( 0, 0 );glVertex3f(-0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 0 );glVertex3f( 0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 1 );glVertex3f( 0.5f,-0.250f, 0.0001f);
   glColor4f (1.0f, 1.0f, 1.0f,1.0f);
   glEnd();
   return(1);
};

int process_p_actinium_shields(void)
{
   if (game.p_actinium_shields.active)
   {
      game.p_actinium_shields.alpha  -= 0.025f;
      if (game.p_actinium_shields.alpha <= 0) kill_p_actinium_shields();
   }
   return(1);
};

int kill_p_blasters(void)
{
   game.p_blasters.active = false;
   return(1);
};

int spawn_p_blasters(void)
{
   game.p_blasters.active = true;
   game.p_blasters.alpha  = 3.0f;
   return(1);
};

int display_p_blasters(void)
{
   glBindTexture( GL_TEXTURE_2D, texture[311].texture); //display kills logo
   glLoadIdentity();
   glBegin( GL_QUADS );
   glColor4f (1.0f, 1.0f, 1.0f,game.p_blasters.alpha);
   glTexCoord2i( 0, 1 );glVertex3f(-0.5f,-0.250f, 0.0001f);
   glTexCoord2i( 0, 0 );glVertex3f(-0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 0 );glVertex3f( 0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 1 );glVertex3f( 0.5f,-0.250f, 0.0001f);
   glColor4f (1.0f, 1.0f, 1.0f,1.0f);
   glEnd();
   return(1);
};

int process_p_blasters(void)
{
   if (game.p_blasters.active)
   {
      game.p_blasters.alpha  -= 0.025f;
      if (game.p_blasters.alpha <= 0) kill_p_blasters();
   }
   return(1);
};

int kill_p_burst_lasers(void)
{
   game.p_burst_lasers.active = false;
   return(1);
};

int spawn_p_burst_lasers(void)
{
   game.p_burst_lasers.active = true;
   game.p_burst_lasers.alpha  = 3.0f;
   return(1);
};

int display_p_burst_lasers(void)
{
   glBindTexture( GL_TEXTURE_2D, texture[312].texture); //display kills logo
   glLoadIdentity();
   glBegin( GL_QUADS );
   glColor4f (1.0f, 1.0f, 1.0f,game.p_burst_lasers.alpha);
   glTexCoord2i( 0, 1 );glVertex3f(-0.5f,-0.250f, 0.0001f);
   glTexCoord2i( 0, 0 );glVertex3f(-0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 0 );glVertex3f( 0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 1 );glVertex3f( 0.5f,-0.250f, 0.0001f);
   glColor4f (1.0f, 1.0f, 1.0f,1.0f);
   glEnd();
   return(1);
};

int process_p_burst_lasers(void)
{
   if (game.p_burst_lasers.active)
   {
      game.p_burst_lasers.alpha  -= 0.025f;
      if (game.p_burst_lasers.alpha <= 0) kill_p_burst_lasers();
   }
   return(1);
};

int kill_p_chain_guns(void)
{
   game.p_chain_guns.active = false;
   return(1);
};

int spawn_p_chain_guns(void)
{
   game.p_chain_guns.active = true;
   game.p_chain_guns.alpha  = 3.0f;
   return(1);
};

int display_p_chain_guns(void)
{
   glBindTexture( GL_TEXTURE_2D, texture[313].texture); //display kills logo
   glLoadIdentity();
   glBegin( GL_QUADS );
   glColor4f (1.0f, 1.0f, 1.0f,game.p_chain_guns.alpha);
   glTexCoord2i( 0, 1 );glVertex3f(-0.5f,-0.250f, 0.0001f);
   glTexCoord2i( 0, 0 );glVertex3f(-0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 0 );glVertex3f( 0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 1 );glVertex3f( 0.5f,-0.250f, 0.0001f);
   glColor4f (1.0f, 1.0f, 1.0f,1.0f);
   glEnd();
   return(1);
};

int process_p_chain_guns(void)
{
   if (game.p_chain_guns.active)
   {
      game.p_chain_guns.alpha  -= 0.025f;
      if (game.p_chain_guns.alpha <= 0) kill_p_chain_guns();
   }
   return(1);
};

int kill_p_convolution_thrusters(void)
{
   game.p_convolution_thrusters.active = false;
   return(1);
};

int spawn_p_convolution_thrusters(void)
{
   game.p_convolution_thrusters.active = true;
   game.p_convolution_thrusters.alpha  = 3.0f;
   return(1);
};

int display_p_convolution_thrusters(void)
{
   glBindTexture( GL_TEXTURE_2D, texture[314].texture); //display kills logo
   glLoadIdentity();
   glBegin( GL_QUADS );
   glColor4f (1.0f, 1.0f, 1.0f,game.p_convolution_thrusters.alpha);
   glTexCoord2i( 0, 1 );glVertex3f(-0.5f,-0.250f, 0.0001f);
   glTexCoord2i( 0, 0 );glVertex3f(-0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 0 );glVertex3f( 0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 1 );glVertex3f( 0.5f,-0.250f, 0.0001f);
   glColor4f (1.0f, 1.0f, 1.0f,1.0f);
   glEnd();
   return(1);
};

int process_p_convolution_thrusters(void)
{
   if (game.p_convolution_thrusters.active)
   {
      game.p_convolution_thrusters.alpha  -= 0.025f;
      if (game.p_convolution_thrusters.alpha <= 0) kill_p_convolution_thrusters();
   }
   return(1);
};

int kill_p_health(void)
{
   game.p_health.active = false;
   return(1);
};

int spawn_p_health(void)
{
   game.p_health.active = true;
   game.p_health.alpha  = 3.0f;
   return(1);
};

int display_p_health(void)
{
   glBindTexture( GL_TEXTURE_2D, texture[315].texture); //display kills logo
   glLoadIdentity();
   glBegin( GL_QUADS );
   glColor4f (1.0f, 1.0f, 1.0f,game.p_health.alpha);
   glTexCoord2i( 0, 1 );glVertex3f(-0.5f,-0.250f, 0.0001f);
   glTexCoord2i( 0, 0 );glVertex3f(-0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 0 );glVertex3f( 0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 1 );glVertex3f( 0.5f,-0.250f, 0.0001f);
   glColor4f (1.0f, 1.0f, 1.0f,1.0f);
   glEnd();
   return(1);
};

int process_p_health(void)
{
   if (game.p_health.active)
   {
      game.p_health.alpha  -= 0.025f;
      if (game.p_health.alpha <= 0) kill_p_health();
   }
   return(1);
};

int kill_p_ion_cannons(void)
{
   game.p_ion_cannons.active = false;
   return(1);
};

int spawn_p_ion_cannons(void)
{
   game.p_ion_cannons.active = true;
   game.p_ion_cannons.alpha  = 3.0f;
   return(1);
};

int display_p_ion_cannons(void)
{
   glBindTexture( GL_TEXTURE_2D, texture[316].texture); //display kills logo
   glLoadIdentity();
   glBegin( GL_QUADS );
   glColor4f (1.0f, 1.0f, 1.0f,game.p_ion_cannons.alpha);
   glTexCoord2i( 0, 1 );glVertex3f(-0.5f,-0.250f, 0.0001f);
   glTexCoord2i( 0, 0 );glVertex3f(-0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 0 );glVertex3f( 0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 1 );glVertex3f( 0.5f,-0.250f, 0.0001f);
   glColor4f (1.0f, 1.0f, 1.0f,1.0f);
   glEnd();
   return(1);
};

int process_p_ion_cannons(void)
{
   if (game.p_ion_cannons.active)
   {
      game.p_ion_cannons.alpha  -= 0.025f;
      if (game.p_ion_cannons.alpha <= 0) kill_p_ion_cannons();
   }
   return(1);
};

int kill_p_iridium_shileds(void)
{
   game.p_iridium_shileds.active = false;
   return(1);
};

int spawn_p_iridium_shileds(void)
{
   game.p_iridium_shileds.active = true;
   game.p_iridium_shileds.alpha  = 3.0f;
   return(1);
};

int display_p_iridium_shileds(void)
{
   glBindTexture( GL_TEXTURE_2D, texture[317].texture); //iridium_shileds logo
   glLoadIdentity();
   glBegin( GL_QUADS );
   glColor4f (1.0f, 1.0f, 1.0f,game.p_iridium_shileds.alpha);
   glTexCoord2i( 0, 1 );glVertex3f(-0.5f,-0.250f, 0.0001f);
   glTexCoord2i( 0, 0 );glVertex3f(-0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 0 );glVertex3f( 0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 1 );glVertex3f( 0.5f,-0.250f, 0.0001f);
   glColor4f (1.0f, 1.0f, 1.0f,1.0f);
   glEnd();
   return(1);
};

int process_p_iridium_shileds(void)
{
   if (game.p_iridium_shileds.active)
   {
      game.p_iridium_shileds.alpha  -= 0.025f;
      if (game.p_iridium_shileds.alpha <= 0) kill_p_iridium_shileds();
   }
   return(1);
};

int kill_p_maelstrom_thrusters(void)
{
   game.p_maelstrom_thrusters.active = false;
   return(1);
};

int spawn_p_maelstrom_thrusters(void)
{
   game.p_maelstrom_thrusters.active = true;
   game.p_maelstrom_thrusters.alpha  = 3.0f;
   return(1);
};

int display_p_maelstrom_thrusters(void)
{
   glBindTexture( GL_TEXTURE_2D, texture[318].texture); //display maelstrom_thrusters logo
   glLoadIdentity();
   glBegin( GL_QUADS );
   glColor4f (1.0f, 1.0f, 1.0f,game.p_maelstrom_thrusters.alpha);
   glTexCoord2i( 0, 1 );glVertex3f(-0.5f,-0.250f, 0.0001f);
   glTexCoord2i( 0, 0 );glVertex3f(-0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 0 );glVertex3f( 0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 1 );glVertex3f( 0.5f,-0.250f, 0.0001f);
   glColor4f (1.0f, 1.0f, 1.0f,1.0f);
   glEnd();
   return(1);
};

int process_p_maelstrom_thrusters(void)
{
   if (game.p_maelstrom_thrusters.active)
   {
      game.p_maelstrom_thrusters.alpha  -= 0.025f;
      if (game.p_maelstrom_thrusters.alpha <= 0) kill_p_maelstrom_thrusters();
   }
   return(1);
};

int kill_p_plasma_rockets(void)
{
   game.p_plasma_rockets.active = false;
   return(1);
};

int spawn_p_plasma_rockets(void)
{
   game.p_plasma_rockets.active = true;
   game.p_plasma_rockets.alpha  = 3.0f;
   return(1);
};

int display_p_plasma_rockets(void)
{
   glBindTexture( GL_TEXTURE_2D, texture[319].texture); //display kills logo
   glLoadIdentity();
   glBegin( GL_QUADS );
   glColor4f (1.0f, 1.0f, 1.0f,game.p_plasma_rockets.alpha);
   glTexCoord2i( 0, 1 );glVertex3f(-0.5f,-0.250f, 0.0001f);
   glTexCoord2i( 0, 0 );glVertex3f(-0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 0 );glVertex3f( 0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 1 );glVertex3f( 0.5f,-0.250f, 0.0001f);
   glColor4f (1.0f, 1.0f, 1.0f,1.0f);
   glEnd();
   return(1);
};

int process_p_plasma_rockets(void)
{
   if (game.p_plasma_rockets.active)
   {
      game.p_plasma_rockets.alpha  -= 0.025f;
      if (game.p_plasma_rockets.alpha <= 0) kill_p_plasma_rockets();
   }
   return(1);
};

int kill_p_rail_turrets(void)
{
   game.p_rail_turrets.active = false;
   return(1);
};

int spawn_p_rail_turrets(void)
{
   game.p_rail_turrets.active = true;
   game.p_rail_turrets.alpha  = 3.0f;
   return(1);
};

int display_p_rail_turrets(void)
{
   glBindTexture( GL_TEXTURE_2D, texture[320].texture); //display kills logo
   glLoadIdentity();
   glBegin( GL_QUADS );
   glColor4f (1.0f, 1.0f, 1.0f,game.p_rail_turrets.alpha);
   glTexCoord2i( 0, 1 );glVertex3f(-0.5f,-0.250f, 0.0001f);
   glTexCoord2i( 0, 0 );glVertex3f(-0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 0 );glVertex3f( 0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 1 );glVertex3f( 0.5f,-0.250f, 0.0001f);
   glColor4f (1.0f, 1.0f, 1.0f,1.0f);
   glEnd();
   return(1);
};

int process_p_rail_turrets(void)
{
   if (game.p_rail_turrets.active)
   {
      game.p_rail_turrets.alpha  -= 0.025f;
      if (game.p_rail_turrets.alpha <= 0) kill_p_rail_turrets();
   }
   return(1);
};

int kill_p_rubidium_shields(void)
{
   game.p_rubidium_shields.active = false;
   return(1);
};

int spawn_p_rubidium_shields(void)
{
   game.p_rubidium_shields.active = true;
   game.p_rubidium_shields.alpha  = 3.0f;
   return(1);
};

int display_p_rubidium_shields(void)
{
   glBindTexture( GL_TEXTURE_2D, texture[321].texture); //display kills logo
   glLoadIdentity();
   glBegin( GL_QUADS );
   glColor4f (1.0f, 1.0f, 1.0f,game.p_rubidium_shields.alpha);
   glTexCoord2i( 0, 1 );glVertex3f(-0.5f,-0.250f, 0.0001f);
   glTexCoord2i( 0, 0 );glVertex3f(-0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 0 );glVertex3f( 0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 1 );glVertex3f( 0.5f,-0.250f, 0.0001f);
   glColor4f (1.0f, 1.0f, 1.0f,1.0f);
   glEnd();
   return(1);
};

int process_p_rubidium_shields(void)
{
   if (game.p_rubidium_shields.active)
   {
      game.p_rubidium_shields.alpha  -= 0.025f;
      if (game.p_rubidium_shields.alpha <= 0) kill_p_rubidium_shields();
   }
   return(1);
};

int kill_p_seismic_thrusters(void)
{
   game.p_seismic_thrusters.active = false;
   return(1);
};

int spawn_p_seismic_thrusters(void)
{
   game.p_seismic_thrusters.active = true;
   game.p_seismic_thrusters.alpha  = 3.0f;
   return(1);
};

int display_p_seismic_thrusters(void)
{
   glBindTexture( GL_TEXTURE_2D, texture[322].texture); //display kills logo
   glLoadIdentity();
   glBegin( GL_QUADS );
   glColor4f (1.0f, 1.0f, 1.0f,game.p_seismic_thrusters.alpha);
   glTexCoord2i( 0, 1 );glVertex3f(-0.5f,-0.250f, 0.0001f);
   glTexCoord2i( 0, 0 );glVertex3f(-0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 0 );glVertex3f( 0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 1 );glVertex3f( 0.5f,-0.250f, 0.0001f);
   glColor4f (1.0f, 1.0f, 1.0f,1.0f);
   glEnd();
   return(1);
};

int process_p_seismic_thrusters(void)
{
   if (game.p_seismic_thrusters.active)
   {
      game.p_seismic_thrusters.alpha  -= 0.025f;
      if (game.p_seismic_thrusters.alpha <= 0) kill_p_seismic_thrusters();
   }
   return(1);
};

int kill_p_shield_level_up(void)
{
   game.p_shield_level_up.active = false;
   return(1);
};

int spawn_p_shield_level_up(void)
{
   game.p_shield_level_up.active = true;
   game.p_shield_level_up.alpha  = 3.0f;
   return(1);
};

int display_p_shield_level_up(void)
{
   glBindTexture( GL_TEXTURE_2D, texture[323].texture); //display kills logo
   glLoadIdentity();
   glBegin( GL_QUADS );
   glColor4f (1.0f, 1.0f, 1.0f,game.p_shield_level_up.alpha);
   glTexCoord2i( 0, 1 );glVertex3f(-0.5f,-0.250f, 0.0001f);
   glTexCoord2i( 0, 0 );glVertex3f(-0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 0 );glVertex3f( 0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 1 );glVertex3f( 0.5f,-0.250f, 0.0001f);
   glColor4f (1.0f, 1.0f, 1.0f,1.0f);
   glEnd();
   return(1);
};

int process_p_shield_level_up(void)
{
   if (game.p_shield_level_up.active)
   {
      game.p_shield_level_up.alpha  -= 0.025f;
      if (game.p_shield_level_up.alpha <= 0) kill_p_shield_level_up();
   }
   return(1);
};

int kill_p_tantalum_shields(void)
{
   game.p_tantalum_shields.active = false;
   return(1);
};

int spawn_p_tantalum_shields(void)
{
   game.p_tantalum_shields.active = true;
   game.p_tantalum_shields.alpha  = 3.0f;
   return(1);
};

int display_p_tantalum_shields(void)
{
   glBindTexture( GL_TEXTURE_2D, texture[324].texture); //display kills logo
   glLoadIdentity();
   glBegin( GL_QUADS );
   glColor4f (1.0f, 1.0f, 1.0f,game.p_tantalum_shields.alpha);
   glTexCoord2i( 0, 1 );glVertex3f(-0.5f,-0.250f, 0.0001f);
   glTexCoord2i( 0, 0 );glVertex3f(-0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 0 );glVertex3f( 0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 1 );glVertex3f( 0.5f,-0.250f, 0.0001f);
   glColor4f (1.0f, 1.0f, 1.0f,1.0f);
   glEnd();
   return(1);
};

int process_p_tantalum_shields(void)
{
   if (game.p_tantalum_shields.active)
   {
      game.p_tantalum_shields.alpha  -= 0.025f;
      if (game.p_tantalum_shields.alpha <= 0) kill_p_tantalum_shields();
   }
   return(1);
};

int kill_p_terbium_shields(void)
{
   game.p_terbium_shields.active = false;
   return(1);
};

int spawn_p_terbium_shields(void)
{
   game.p_terbium_shields.active = true;
   game.p_terbium_shields.alpha  = 3.0f;
   return(1);
};

int display_p_terbium_shields(void)
{
   glBindTexture( GL_TEXTURE_2D, texture[325].texture); //display kills logo
   glLoadIdentity();
   glBegin( GL_QUADS );
   glColor4f (1.0f, 1.0f, 1.0f,game.p_terbium_shields.alpha);
   glTexCoord2i( 0, 1 );glVertex3f(-0.5f,-0.250f, 0.0001f);
   glTexCoord2i( 0, 0 );glVertex3f(-0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 0 );glVertex3f( 0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 1 );glVertex3f( 0.5f,-0.250f, 0.0001f);
   glColor4f (1.0f, 1.0f, 1.0f,1.0f);
   glEnd();
   return(1);
};

int process_p_terbium_shields(void)
{
   if (game.p_terbium_shields.active)
   {
      game.p_terbium_shields.alpha  -= 0.025f;
      if (game.p_terbium_shields.alpha <= 0) kill_p_terbium_shields();
   }
   return(1);
};

int kill_p_thrusters_level_up(void)
{
   game.p_thrusters_level_up.active = false;
   return(1);
};

int spawn_p_thrusters_level_up(void)
{
   game.p_thrusters_level_up.active = true;
   game.p_thrusters_level_up.alpha  = 3.0f;
   return(1);
};

int display_p_thrusters_level_up(void)
{
   glBindTexture( GL_TEXTURE_2D, texture[326].texture); //display kills logo
   glLoadIdentity();
   glBegin( GL_QUADS );
   glColor4f (1.0f, 1.0f, 1.0f,game.p_thrusters_level_up.alpha);
   glTexCoord2i( 0, 1 );glVertex3f(-0.5f,-0.250f, 0.0001f);
   glTexCoord2i( 0, 0 );glVertex3f(-0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 0 );glVertex3f( 0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 1 );glVertex3f( 0.5f,-0.250f, 0.0001f);
   glColor4f (1.0f, 1.0f, 1.0f,1.0f);
   glEnd();
   return(1);
};

int process_p_thrusters_level_up(void)
{
   if (game.p_thrusters_level_up.active)
   {
      game.p_thrusters_level_up.alpha  -= 0.025f;
      if (game.p_thrusters_level_up.alpha <= 0) kill_p_thrusters_level_up();
   }
   return(1);
};

int kill_p_vortex_thrusters(void)
{
   game.p_vortex_thrusters.active = false;
   return(1);
};

int spawn_p_vortex_thrusters(void)

{
   game.p_vortex_thrusters.active = true;
   game.p_vortex_thrusters.alpha  = 3.0f;
   return(1);
};

int display_p_vortex_thrusters(void)
{
   glBindTexture( GL_TEXTURE_2D, texture[327].texture); //display kills logo
   glLoadIdentity();
   glBegin( GL_QUADS );
   glColor4f (1.0f, 1.0f, 1.0f,game.p_vortex_thrusters.alpha);
   glTexCoord2i( 0, 1 );glVertex3f(-0.5f,-0.250f, 0.0001f);
   glTexCoord2i( 0, 0 );glVertex3f(-0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 0 );glVertex3f( 0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 1 );glVertex3f( 0.5f,-0.250f, 0.0001f);
   glColor4f (1.0f, 1.0f, 1.0f,1.0f);
   glEnd();
   return(1);
};

int process_p_vortex_thrusters(void)
{
   if (game.p_vortex_thrusters.active)
   {
      game.p_vortex_thrusters.alpha  -= 0.025f;
      if (game.p_vortex_thrusters.alpha <= 0) kill_p_vortex_thrusters();
   }
   return(1);
};

int kill_p_weapon_level_up(void)
{
   game.p_weapon_level_up.active = false;
   return(1);
};

int spawn_p_weapon_level_up(void)
{
   game.p_weapon_level_up.active = true;
   game.p_weapon_level_up.alpha  = 3.0f;
   return(1);
};

int display_p_weapon_level_up(void)
{
   glBindTexture( GL_TEXTURE_2D, texture[328].texture); //display kills logo
   glLoadIdentity();
   glBegin( GL_QUADS );
   glColor4f (1.0f, 1.0f, 1.0f,game.p_weapon_level_up.alpha);
   glTexCoord2i( 0, 1 );glVertex3f(-0.5f,-0.250f, 0.0001f);
   glTexCoord2i( 0, 0 );glVertex3f(-0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 0 );glVertex3f( 0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 1 );glVertex3f( 0.5f,-0.250f, 0.0001f);
   glColor4f (1.0f, 1.0f, 1.0f,1.0f);
   glEnd();
   return(1);
};

int process_p_weapon_level_up(void)
{
   if (game.p_weapon_level_up.active)
   {
      game.p_weapon_level_up.alpha  -= 0.025f;
      if (game.p_weapon_level_up.alpha <= 0) kill_p_weapon_level_up();
   }
   return(1);
};

int kill_d_level_end(void)
{
   game.level_end_display_active = false;
   return(1);
};

int spawn_d_level_end(void)
{
   game.level_end_display_active = true;
   game.level_end_display_alpha  = 0.001250f;
   game.level_end_display_count  = 3.0f;
   return(1);
};

int display_d_level_end(void)
{
   glBindTexture( GL_TEXTURE_2D, texture[333].texture); //display level completed
   glLoadIdentity();
   glBegin( GL_QUADS );
   glColor4f (1.0f, 1.0f, 1.0f,game.level_end_display_count);
   glTexCoord2i( 0, 1 );glVertex3f(-0.5f,-0.250f, 0.0001f);
   glTexCoord2i( 0, 0 );glVertex3f(-0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 0 );glVertex3f( 0.5f, 0.250f, 0.0001f);
   glTexCoord2i( 1, 1 );glVertex3f( 0.5f,-0.250f, 0.0001f);
   glColor4f (1.0f, 1.0f, 1.0f,1.0f);
   glEnd();
   return(1);
};

int process_d_level_end(void)
{
   if (game.level_end_display_active)
   {
      game.level_end_display_count  -= 0.025f;
      if (game.level_end_display_count <= game.level_end_display_alpha) game.level_end_display_count = game.level_end_display_alpha;
   }
   return(1);
};

int initialize_sideships(void)
{
   for (int sideship_count = 0;sideship_count < MAX_SIDESHIPS;sideship_count++)
   {
      game.sideship[sideship_count].rate_of_fire       = 5;
      game.sideship[sideship_count].rate_of_fire_count = 0;
      game.sideship[sideship_count].active             = false;
      game.sideship[sideship_count].level              = -1;
      game.sideship[sideship_count].image              = sideship_count+242;
      game.sideship[sideship_count].width              = 0.075f;
      game.sideship[sideship_count].height             = 0.075f;
      for (int bullet_count = 0;bullet_count < MAX_BULLETS;bullet_count++)
      {
         game.sideship[sideship_count].bullet[bullet_count].active = false;
         if (sideship_count == 0) game.sideship[sideship_count].bullet[bullet_count].warhead = 1;
         if (sideship_count == 1) game.sideship[sideship_count].bullet[bullet_count].warhead = 2;
         if (sideship_count == 2) game.sideship[sideship_count].bullet[bullet_count].warhead = 3;
         if (sideship_count == 3) game.sideship[sideship_count].bullet[bullet_count].warhead = 4;
      }
   }
   return(1);
};

int spawn_sideship_bullet(int sideship_count,int location, int direction_x, int direction_y)
{
   bool done = false;
   for (int bullet_count = 0;bullet_count < MAX_BULLETS;bullet_count++)//spawn bullet
   {
       if ((!game.sideship[sideship_count].bullet[bullet_count].active) && (!done))
       {
          done = true;
          game.sideship[sideship_count].bullet[bullet_count].active = true;
          game.sideship[sideship_count].bullet[bullet_count].x_pos  = game.player.x_pos-(game.player.width/4)+game.sideship[sideship_count].width;
          if (location  == 1) game.sideship[sideship_count].bullet[bullet_count].y_pos  = game.player.y_pos+(game.player.hight/2)+game.sideship[sideship_count].height;
          if (location  == 0) game.sideship[sideship_count].bullet[bullet_count].y_pos  = game.player.y_pos-(game.player.hight/2)-game.sideship[sideship_count].height;
          game.sideship[sideship_count].bullet[bullet_count].x_dir   = direction_x;
          game.sideship[sideship_count].bullet[bullet_count].y_dir   = direction_y;
          game.sideship[sideship_count].bullet[bullet_count].x_speed = game.projectile[game.sideship[sideship_count].bullet[bullet_count].warhead].speed;
          game.sideship[sideship_count].bullet[bullet_count].y_speed = game.projectile[game.sideship[sideship_count].bullet[bullet_count].warhead].speed;
          game.sideship[sideship_count].bullet[bullet_count].hight   = game.projectile[game.sideship[sideship_count].bullet[bullet_count].warhead].size;
          game.sideship[sideship_count].bullet[bullet_count].width   = game.projectile[game.sideship[sideship_count].bullet[bullet_count].warhead].size;
       }
   }
   if (done) return(1);
   else return(0);
};

int process_sideships(bool spawn_bullet)
{
   int   random_temp     =  0;
   for (int sideship_count = 0;sideship_count < MAX_SIDESHIPS;sideship_count++)
   {
      if (game.sideship[sideship_count].active)
      {
         switch (sideship_count)//rof
         {
            case 0://sideship 1
               if (game.sideship[sideship_count].rate_of_fire_count > game.sideship[sideship_count].rate_of_fire)//rof spawn bullets
               {
                  game.sideship[sideship_count].rate_of_fire_count = 0;
                  if ((game.sideship[sideship_count].level >= 0) && (spawn_bullet))
                  {
                     spawn_sideship_bullet(sideship_count,0,0,0);
                     spawn_sideship_bullet(sideship_count,1,1,1);
                  }
                  if ((game.sideship[sideship_count].level >= 1) && (spawn_bullet))
                  {
                     spawn_sideship_bullet(sideship_count,0,2,2);
                     spawn_sideship_bullet(sideship_count,1,3,3);
                  }
                  if ((game.sideship[sideship_count].level >= 2) && (spawn_bullet))
                  {
                     spawn_sideship_bullet(sideship_count,0,4,4);
                     spawn_sideship_bullet(sideship_count,1,5,5);
                  }
               }
               else game.sideship[sideship_count].rate_of_fire_count++;
            break;
            default://default action if undefined value submitted to switch function
               if (game.sideship[sideship_count].rate_of_fire_count > game.sideship[sideship_count].rate_of_fire)//rof spawn bullets
               {
                  game.sideship[sideship_count].rate_of_fire_count = 0;
                  if ((game.sideship[sideship_count].level >= 0) && (spawn_bullet))
                  {
                     spawn_sideship_bullet(sideship_count,0,0,0);
                     spawn_sideship_bullet(sideship_count,1,1,1);
                  }
                  if ((game.sideship[sideship_count].level >= 1) && (spawn_bullet))
                  {
                     spawn_sideship_bullet(sideship_count,0,2,2);
                     spawn_sideship_bullet(sideship_count,1,3,3);
                  }
                  if ((game.sideship[sideship_count].level >= 2) && (spawn_bullet))
                  {
                     spawn_sideship_bullet(sideship_count,0,4,4);
                     spawn_sideship_bullet(sideship_count,1,5,5);
                  }
               }
               else game.sideship[sideship_count].rate_of_fire_count++;
            break;
         }
         for (int bullet_count = 0;bullet_count < MAX_BULLETS;bullet_count++)//process bullets
         {
            switch (sideship_count)//different bullet types require different movement...
            {
               case 0://sideship 1
                  if (game.sideship[sideship_count].bullet[bullet_count].active)
                  {
                     if (game.sideship[sideship_count].bullet[bullet_count].x_dir == 0)
                     {
                        game.sideship[sideship_count].bullet[bullet_count].x_pos += game.sideship[sideship_count].bullet[bullet_count].x_speed;
                        if (game.sideship[sideship_count].bullet[bullet_count].x_pos > (1.0f+game.sideship[sideship_count].bullet[bullet_count].width/2))
                        {
                            game.sideship[sideship_count].bullet[bullet_count].active = false;
                        }
                     }
                     if (game.sideship[sideship_count].bullet[bullet_count].x_dir == 2)
                     {
                        game.sideship[sideship_count].bullet[bullet_count].x_pos += (game.sideship[sideship_count].bullet[bullet_count].x_speed);
                        if (game.sideship[sideship_count].bullet[bullet_count].x_pos > (1.0f+game.sideship[sideship_count].bullet[bullet_count].width/2))
                        {
                            game.sideship[sideship_count].bullet[bullet_count].active = false;
                        }
                     }
                     if (game.sideship[sideship_count].bullet[bullet_count].x_dir == 4)
                     {
                        game.sideship[sideship_count].bullet[bullet_count].x_pos += (game.sideship[sideship_count].bullet[bullet_count].x_speed);
                        if (game.sideship[sideship_count].bullet[bullet_count].x_pos > (1.0f+game.sideship[sideship_count].bullet[bullet_count].width/2))
                        {
                            game.sideship[sideship_count].bullet[bullet_count].active = false;
                        }
                     }
                     if (game.sideship[sideship_count].bullet[bullet_count].x_dir == 1)
                     {
                        game.sideship[sideship_count].bullet[bullet_count].x_pos += game.sideship[sideship_count].bullet[bullet_count].x_speed;
                       if (game.sideship[sideship_count].bullet[bullet_count].x_pos > (1.0f+game.sideship[sideship_count].bullet[bullet_count].width/2))
                        {
                            game.sideship[sideship_count].bullet[bullet_count].active = false;
                        }
                     }
                     if (game.sideship[sideship_count].bullet[bullet_count].x_dir == 3)
                     {
                        game.sideship[sideship_count].bullet[bullet_count].x_pos += game.sideship[sideship_count].bullet[bullet_count].x_speed;
                        if (game.sideship[sideship_count].bullet[bullet_count].x_pos > (1.0f+game.sideship[sideship_count].bullet[bullet_count].width/2))
                        {
                            game.sideship[sideship_count].bullet[bullet_count].active = false;
                        }
                     }
                     if (game.sideship[sideship_count].bullet[bullet_count].x_dir == 5)
                     {
                        game.sideship[sideship_count].bullet[bullet_count].x_pos += game.sideship[sideship_count].bullet[bullet_count].x_speed;
                        if (game.sideship[sideship_count].bullet[bullet_count].x_pos > (1.0f+game.sideship[sideship_count].bullet[bullet_count].width/2))
                        {
                            game.sideship[sideship_count].bullet[bullet_count].active = false;
                        }
                     }


                     if (game.sideship[sideship_count].bullet[bullet_count].y_dir == 0)
                     {
                        game.sideship[sideship_count].bullet[bullet_count].y_pos -= game.sideship[sideship_count].bullet[bullet_count].y_speed*0.25;
                        if (game.sideship[sideship_count].bullet[bullet_count].y_pos < (-1.0f-game.sideship[sideship_count].bullet[bullet_count].hight/2))
                        {
                            game.sideship[sideship_count].bullet[bullet_count].active = false;
                        }
                     }
                     if (game.sideship[sideship_count].bullet[bullet_count].y_dir == 2)
                     {
                        game.sideship[sideship_count].bullet[bullet_count].y_pos -= game.sideship[sideship_count].bullet[bullet_count].y_speed*0.75f;
                        if (game.sideship[sideship_count].bullet[bullet_count].y_pos < (-1.0f-game.sideship[sideship_count].bullet[bullet_count].hight/2))
                        {
                            game.sideship[sideship_count].bullet[bullet_count].active = false;
                        }
                     }
                     if (game.sideship[sideship_count].bullet[bullet_count].y_dir == 4)
                     {
                        game.sideship[sideship_count].bullet[bullet_count].y_pos -= game.sideship[sideship_count].bullet[bullet_count].y_speed*1.25f;
                        if (game.sideship[sideship_count].bullet[bullet_count].y_pos < (-1.0f-game.sideship[sideship_count].bullet[bullet_count].hight/2))
                        {
                            game.sideship[sideship_count].bullet[bullet_count].active = false;
                        }
                     }
                     if (game.sideship[sideship_count].bullet[bullet_count].y_dir == 1)
                     {
                        game.sideship[sideship_count].bullet[bullet_count].y_pos += game.sideship[sideship_count].bullet[bullet_count].y_speed*0.25;
                        if (game.sideship[sideship_count].bullet[bullet_count].y_pos > (1.0f+game.sideship[sideship_count].bullet[bullet_count].hight/2))
                        {
                            game.sideship[sideship_count].bullet[bullet_count].active = false;
                        }
                     }
                     if (game.sideship[sideship_count].bullet[bullet_count].y_dir == 3)
                     {
                        game.sideship[sideship_count].bullet[bullet_count].y_pos += game.sideship[sideship_count].bullet[bullet_count].y_speed*0.75f;
                        if (game.sideship[sideship_count].bullet[bullet_count].y_pos > (1.0f+game.sideship[sideship_count].bullet[bullet_count].hight/2))
                        {
                            game.sideship[sideship_count].bullet[bullet_count].active = false;
                        }
                     }
                     if (game.sideship[sideship_count].bullet[bullet_count].y_dir == 5)
                     {
                       game.sideship[sideship_count].bullet[bullet_count].y_pos += game.sideship[sideship_count].bullet[bullet_count].y_speed*1.25f;
                        if (game.sideship[sideship_count].bullet[bullet_count].y_pos > (1.0f+game.sideship[sideship_count].bullet[bullet_count].hight/2))
                        {
                            game.sideship[sideship_count].bullet[bullet_count].active = false;
                        }
                    }
                  }
               break;
               default://default action if undefined value submitted to switch function
                  if (game.sideship[sideship_count].bullet[bullet_count].active)
                  {
                     if (game.sideship[sideship_count].bullet[bullet_count].x_dir == 0)
                     {
                        game.sideship[sideship_count].bullet[bullet_count].x_pos += game.sideship[sideship_count].bullet[bullet_count].x_speed;
                        if (game.sideship[sideship_count].bullet[bullet_count].x_pos > (1.0f+game.sideship[sideship_count].bullet[bullet_count].width/2))
                        {
                            game.sideship[sideship_count].bullet[bullet_count].active = false;
                        }
                     }
                     if (game.sideship[sideship_count].bullet[bullet_count].x_dir == 2)
                     {
                        game.sideship[sideship_count].bullet[bullet_count].x_pos += (game.sideship[sideship_count].bullet[bullet_count].x_speed);
                        if (game.sideship[sideship_count].bullet[bullet_count].x_pos > (1.0f+game.sideship[sideship_count].bullet[bullet_count].width/2))
                        {
                            game.sideship[sideship_count].bullet[bullet_count].active = false;
                        }
                     }
                     if (game.sideship[sideship_count].bullet[bullet_count].x_dir == 4)
                     {
                        game.sideship[sideship_count].bullet[bullet_count].x_pos += (game.sideship[sideship_count].bullet[bullet_count].x_speed);
                        if (game.sideship[sideship_count].bullet[bullet_count].x_pos > (1.0f+game.sideship[sideship_count].bullet[bullet_count].width/2))
                        {
                            game.sideship[sideship_count].bullet[bullet_count].active = false;
                        }
                     }
                     if (game.sideship[sideship_count].bullet[bullet_count].x_dir == 1)
                     {
                        game.sideship[sideship_count].bullet[bullet_count].x_pos += game.sideship[sideship_count].bullet[bullet_count].x_speed;
                       if (game.sideship[sideship_count].bullet[bullet_count].x_pos > (1.0f+game.sideship[sideship_count].bullet[bullet_count].width/2))
                        {
                            game.sideship[sideship_count].bullet[bullet_count].active = false;
                        }
                     }
                     if (game.sideship[sideship_count].bullet[bullet_count].x_dir == 3)
                     {
                        game.sideship[sideship_count].bullet[bullet_count].x_pos += game.sideship[sideship_count].bullet[bullet_count].x_speed;
                        if (game.sideship[sideship_count].bullet[bullet_count].x_pos > (1.0f+game.sideship[sideship_count].bullet[bullet_count].width/2))
                        {
                            game.sideship[sideship_count].bullet[bullet_count].active = false;
                        }
                     }
                     if (game.sideship[sideship_count].bullet[bullet_count].x_dir == 5)
                     {
                        game.sideship[sideship_count].bullet[bullet_count].x_pos += game.sideship[sideship_count].bullet[bullet_count].x_speed;
                        if (game.sideship[sideship_count].bullet[bullet_count].x_pos > (1.0f+game.sideship[sideship_count].bullet[bullet_count].width/2))
                        {
                            game.sideship[sideship_count].bullet[bullet_count].active = false;
                        }
                     }


                     if (game.sideship[sideship_count].bullet[bullet_count].y_dir == 0)
                     {
                        game.sideship[sideship_count].bullet[bullet_count].y_pos -= game.sideship[sideship_count].bullet[bullet_count].y_speed*0.25;
                        if (game.sideship[sideship_count].bullet[bullet_count].y_pos < (-1.0f-game.sideship[sideship_count].bullet[bullet_count].hight/2))
                        {
                            game.sideship[sideship_count].bullet[bullet_count].active = false;
                        }
                     }
                     if (game.sideship[sideship_count].bullet[bullet_count].y_dir == 2)
                     {
                        game.sideship[sideship_count].bullet[bullet_count].y_pos -= game.sideship[sideship_count].bullet[bullet_count].y_speed*0.75f;
                        if (game.sideship[sideship_count].bullet[bullet_count].y_pos < (-1.0f-game.sideship[sideship_count].bullet[bullet_count].hight/2))
                        {
                            game.sideship[sideship_count].bullet[bullet_count].active = false;
                        }
                     }
                     if (game.sideship[sideship_count].bullet[bullet_count].y_dir == 4)
                     {
                        game.sideship[sideship_count].bullet[bullet_count].y_pos -= game.sideship[sideship_count].bullet[bullet_count].y_speed*1.25f;
                        if (game.sideship[sideship_count].bullet[bullet_count].y_pos < (-1.0f-game.sideship[sideship_count].bullet[bullet_count].hight/2))
                        {
                            game.sideship[sideship_count].bullet[bullet_count].active = false;
                        }
                     }
                     if (game.sideship[sideship_count].bullet[bullet_count].y_dir == 1)
                     {
                        game.sideship[sideship_count].bullet[bullet_count].y_pos += game.sideship[sideship_count].bullet[bullet_count].y_speed*0.25;
                        if (game.sideship[sideship_count].bullet[bullet_count].y_pos > (1.0f+game.sideship[sideship_count].bullet[bullet_count].hight/2))
                        {
                            game.sideship[sideship_count].bullet[bullet_count].active = false;
                        }
                     }
                     if (game.sideship[sideship_count].bullet[bullet_count].y_dir == 3)
                     {
                        game.sideship[sideship_count].bullet[bullet_count].y_pos += game.sideship[sideship_count].bullet[bullet_count].y_speed*0.75f;
                        if (game.sideship[sideship_count].bullet[bullet_count].y_pos > (1.0f+game.sideship[sideship_count].bullet[bullet_count].hight/2))
                        {
                            game.sideship[sideship_count].bullet[bullet_count].active = false;
                        }
                     }
                     if (game.sideship[sideship_count].bullet[bullet_count].y_dir == 5)
                     {
                       game.sideship[sideship_count].bullet[bullet_count].y_pos += game.sideship[sideship_count].bullet[bullet_count].y_speed*1.25f;
                        if (game.sideship[sideship_count].bullet[bullet_count].y_pos > (1.0f+game.sideship[sideship_count].bullet[bullet_count].hight/2))
                        {
                            game.sideship[sideship_count].bullet[bullet_count].active = false;
                        }
                    }
                  }
               break;
            }
            //---------- collision detection ---------
            for (int npc_count = 0; npc_count < MAX_NPCS; npc_count++)
            {
               if (game.npc[npc_count].active)// check player sideship bullets / npc collisions...
               {
                  if (quadrangle_collision(game.npc[npc_count].x_pos,game.npc[npc_count].y_pos,game.npc[npc_count].width,game.npc[npc_count].hight,game.sideship[sideship_count].bullet[bullet_count].x_pos,game.sideship[sideship_count].bullet[bullet_count].y_pos,game.sideship[sideship_count].bullet[bullet_count].width,game.sideship[sideship_count].bullet[bullet_count].hight))
                  {
                     game.npc[npc_count].health -= game.projectile[game.sideship[sideship_count].bullet[bullet_count].warhead].damage;
                     if (game.npc[npc_count].health <= 0)
                     {
                        random_temp = random_int();
                        if (random_temp <= game.coin_spawn_rate) //spawn coin
                        {
                           spawn_coin(game.npc[npc_count].x_pos,game.npc[npc_count].y_pos,(game.npc[npc_count].type_npc+1+random_dec()));
                        }
                        if ((random_temp > game.coin_spawn_rate) && (random_temp <= game.wexp_spawn_rate)) //spawn wexp
                        {
                           spawn_wexp(game.npc[npc_count].x_pos,game.npc[npc_count].y_pos,(game.npc[npc_count].type_npc+1+random_dec()));
                        }
                        if (random_temp > game.wexp_spawn_rate) //spawn null
                        {
                           ;
                        }
                        spawn_explosion(game.npc[npc_count].x_pos,game.npc[npc_count].y_pos,0.50f);
                        play_sound(4);
                        kill_npc(npc_count);
                        game.score += (game.npc[npc_count].type_npc + 1) * 10;
                        game.level_score += (game.npc[npc_count].type_npc + 1) * 10;
                        game.kills += 1;
                        game.level_kills += 1;
                        game.sideship[sideship_count].bullet[bullet_count].active = false;
                     }
                     else
                     {
                         spawn_explosion(game.npc[npc_count].x_pos,game.npc[npc_count].y_pos,0.1250f);
                         if (game.npc[npc_count].damaged <= 0) game.npc[npc_count].damaged = game.npc_damage_duration;
                         game.sideship[sideship_count].bullet[bullet_count].active = false;
                         play_sound(0);
                     }
                     for (int npc_bullet_num =0;npc_bullet_num < MAX_BULLETS;npc_bullet_num++) // check player sideship bullets / npc bullets for collisions...
                     {
                        if(game.npc[npc_count].bullet[npc_bullet_num].active)
                        {
                           if (quadrangle_collision(game.npc[npc_count].bullet[npc_bullet_num].x_pos,game.npc[npc_count].bullet[npc_bullet_num].y_pos,game.npc[npc_count].bullet[npc_bullet_num].width,game.npc[npc_count].bullet[npc_bullet_num].hight,game.sideship[sideship_count].bullet[bullet_count].x_pos,game.sideship[sideship_count].bullet[bullet_count].y_pos,game.sideship[sideship_count].bullet[bullet_count].width,game.sideship[sideship_count].bullet[bullet_count].hight))
                           {
                              spawn_explosion(game.npc[npc_count].bullet[npc_bullet_num].x_pos,game.npc[npc_count].bullet[npc_bullet_num].y_pos,0.25f);
                              play_sound(4);
                              game.sideship[sideship_count].bullet[bullet_count].active = false;
                              kill_npc_bullet(npc_count,npc_bullet_num);
                              game.score += game.npc[npc_count].type_npc + 1;
                              game.level_score += game.npc[npc_count].type_npc + 1;;
                           }
                        }
                     }
                  }
               }
            }
         }
      }
   }
   return(1);
};

int kill_player_bullet(void)
{
    for (int num_player_bullets = 0; num_player_bullets < MAX_BULLETS-1; num_player_bullets++)
    {
        kill_player_bullet(num_player_bullets);
    }
    return(1);
};

int kill_player_sideship_bullet(void)
{
    for (int sideship_count = 0;sideship_count < MAX_SIDESHIPS;sideship_count++)
    {
        for (int bullet_count = 0;bullet_count < MAX_BULLETS;bullet_count++)
        {
            game.sideship[sideship_count].bullet[bullet_count].active = false;
        }
    }
    return(1);
};
