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
extern sound_type sound[MAX_SOUNDS];
extern music_type music[MAX_MUSIC];
extern texture_type texture[MAX_TEXTURES];
game_type game;

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
   game.game_paused                       = false;
   game.game_active                       = false;
   game.game_resume                       = false;
   game.menu_active                       = true;
   game.pdie_active                       = false;
   game.nlvl_active                       = false;
   game.exp_rate                          = 3;
   game.FPS                               = 0.0f;
   game.paused.active                     = false;
   game.music_track                       = 0;
   game.menu_music_track                  = 26;
   game.nlvl_music_track                  = 27;
   game.pdie_music_track                  = 28;
   game.score                             = 0;
   game.kills                             = 0;
   game.level_kills                       = 0;
   game.level_spawened                    = 0;
   game.level_score                       = 0;;
   game.victory_kills                     = 0;;
   game.victory_spawened                  = 0;;
   game.victory_score                     = 0;
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
   game.player.side_weapon                = -1;
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
      game.player.bullet[count].active   = false;
      game.player.bullet[count].x_pos    = -2.0f;
      game.player.bullet[count].y_pos    = -2.0f;
      game.player.bullet[count].x_speed  = 0.0f;
      game.player.bullet[count].y_speed  = 0.0f;
      game.player.bullet[count].width    = 0.05f;
      game.player.bullet[count].hight    = 0.05f;
      game.player.bullet[count].warhead  = 0;
      game.player.bullet[count].location = 0;
   }
   game.projectile[0].name[0]      = 'B';
   game.projectile[0].name[1]      = 'l';
   game.projectile[0].name[2]      = 'a';
   game.projectile[0].name[3]      = 's';
   game.projectile[0].name[4]      = 't';
   game.projectile[0].name[5]      = 'e';
   game.projectile[0].name[6]      = 'r';
   game.projectile[0].name[7]      = 's';
   game.projectile[0].active       = true;
   game.projectile[0].level        = 0;
   game.projectile[0].experience   = 0;
   game.projectile[0].level_1      = 1024.0f;
   game.projectile[0].level_2      = 2048.0f;
   game.projectile[0].level_3      = 4096.0f;
   game.projectile[0].image        = 222;
   game.projectile[0].sound        = 7;
   game.projectile[0].damage       = 2.5f;
   game.projectile[0].speed        = 0.005f;
   game.projectile[0].health       = 10;
   game.projectile[0].rate_of_fire = 25;
   game.projectile[1].name[0]      = 'C';
   game.projectile[1].name[1]      = 'h';
   game.projectile[1].name[2]      = 'a';
   game.projectile[1].name[3]      = 'i';
   game.projectile[1].name[4]      = 'n';
   game.projectile[1].name[5]      = ' ';
   game.projectile[1].name[6]      = 'g';
   game.projectile[1].name[7]      = 'u';
   game.projectile[1].name[8]      = 'n';
   game.projectile[1].name[9]      = 's';
   game.projectile[1].active       = false;
   game.projectile[1].level        = 0;
   game.projectile[1].experience   = 0;
   game.projectile[1].level_1      = 2048.0f;
   game.projectile[1].level_2      = 4096.0f;
   game.projectile[1].level_3      = 8192.0f;
   game.projectile[1].image        = 223;
   game.projectile[1].sound        = 8;
   game.projectile[1].damage       = 6;
   game.projectile[1].speed        = 0.01f;
   game.projectile[1].health       = 10;
   game.projectile[1].rate_of_fire = 23;
   game.projectile[2].name[0]      = 'B';
   game.projectile[2].name[1]      = 'u';
   game.projectile[2].name[2]      = 'r';
   game.projectile[2].name[3]      = 's';
   game.projectile[2].name[4]      = 't';
   game.projectile[2].name[5]      = ' ';
   game.projectile[2].name[6]      = 'l';
   game.projectile[2].name[7]      = 'a';
   game.projectile[2].name[8]      = 's';
   game.projectile[2].name[9]      = 'e';
   game.projectile[2].name[10]     = 'r';
   game.projectile[2].name[11]     = 's';
   game.projectile[2].active       = false;
   game.projectile[2].level        = 0;
   game.projectile[2].experience   = 0;
   game.projectile[2].level_1      = 4096.0f;
   game.projectile[2].level_2      = 8192.0f;
   game.projectile[2].level_3      = 16384.0f;
   game.projectile[2].image        = 224;
   game.projectile[2].sound        = 9;
   game.projectile[2].damage       = 7;
   game.projectile[2].speed        = 0.015f;
   game.projectile[2].health       = 10;
   game.projectile[2].rate_of_fire = 21;
   game.projectile[3].name[0]      = 'R';
   game.projectile[3].name[1]      = 'a';
   game.projectile[3].name[2]      = 'i';
   game.projectile[3].name[3]      = 'l';
   game.projectile[3].name[4]      = ' ';
   game.projectile[3].name[5]      = 't';
   game.projectile[3].name[6]      = 'u';
   game.projectile[3].name[7]      = 'r';
   game.projectile[3].name[8]      = 'r';
   game.projectile[3].name[9]      = 'e';
   game.projectile[3].name[10]     = 't';
   game.projectile[3].name[11]     = 's';
   game.projectile[3].active       = false;
   game.projectile[3].level        = 0;
   game.projectile[3].experience   = 0;
   game.projectile[3].level_1      = 8192.0f;
   game.projectile[3].level_2      = 16384.0f;
   game.projectile[3].level_3      = 32768.0f;
   game.projectile[3].image        = 225;
   game.projectile[3].sound        = 10;
   game.projectile[3].damage       = 8;
   game.projectile[3].speed        = 0.02f;
   game.projectile[3].health       = 10;
   game.projectile[3].rate_of_fire = 19;
   game.projectile[4].name[0]      = 'P';
   game.projectile[4].name[1]      = 'l';
   game.projectile[4].name[2]      = 'a';
   game.projectile[4].name[3]      = 's';
   game.projectile[4].name[4]      = 'm';
   game.projectile[4].name[5]      = 'a';
   game.projectile[4].name[6]      = ' ';
   game.projectile[4].name[7]      = 'r';
   game.projectile[4].name[8]      = 'o';
   game.projectile[4].name[9]      = 'c';
   game.projectile[4].name[10]     = 'k';
   game.projectile[4].name[11]     = 'e';
   game.projectile[4].name[12]     = 't';
   game.projectile[4].name[13]     = 's';
   game.projectile[4].active       = false;
   game.projectile[4].level        = 0;
   game.projectile[4].experience   = 0;
   game.projectile[4].level_1      = 16384.0f;
   game.projectile[4].level_2      = 32768.0f;
   game.projectile[4].level_3      = 65536.0f;
   game.projectile[4].image        = 226;
   game.projectile[4].sound        = 11;
   game.projectile[4].damage       = 9;
   game.projectile[4].speed        = 0.025f;
   game.projectile[4].health       = 10;
   game.projectile[4].rate_of_fire = 17;
   game.projectile[5].name[0]      = 'I';
   game.projectile[5].name[1]      = 'o';
   game.projectile[5].name[2]      = 'n';
   game.projectile[5].name[3]      = ' ';
   game.projectile[5].name[4]      = 'c';
   game.projectile[5].name[5]      = 'a';
   game.projectile[5].name[6]      = 'n';
   game.projectile[5].name[7]      = 'n';
   game.projectile[5].name[8]      = 'o';
   game.projectile[5].name[9]      = 'n';
   game.projectile[5].name[10]     = 's';
   game.projectile[5].active       = false;
   game.projectile[5].level        = 0;
   game.projectile[5].experience   = 0;
   game.projectile[5].level_1      = 32768.0f;
   game.projectile[5].level_2      = 65536.0f;
   game.projectile[5].level_3      = 131072.0f;
   game.projectile[5].image        = 227;
   game.projectile[5].sound        = 12;
   game.projectile[5].damage       = 10;
   game.projectile[5].speed        = 0.03f;
   game.projectile[5].health       = 10;
   game.projectile[5].rate_of_fire = 15;

   game.projectile[ 6].name[0]      = 'E';
   game.projectile[ 6].name[1]      = 'n';
   game.projectile[ 6].name[2]      = 'e';
   game.projectile[ 6].name[3]      = 'm';
   game.projectile[ 6].name[4]      = 'y';
   game.projectile[ 6].name[5]      = ' ';
   game.projectile[ 6].name[6]      = 'l';
   game.projectile[ 6].name[7]      = 'a';
   game.projectile[ 6].name[8]      = 's';
   game.projectile[ 6].name[9]      = 'e';
   game.projectile[ 6].name[10]     = 'r';
   game.projectile[ 6].active       = false;
   game.projectile[ 6].level        = 0;
   game.projectile[ 6].experience   = 0;
   game.projectile[ 6].level_1      = 0.0f;
   game.projectile[ 6].level_2      = 0.0f;
   game.projectile[ 6].level_3      = 0.0f;
   game.projectile[ 6].image        = 228;
   game.projectile[ 6].sound        = 0;
   game.projectile[ 6].damage       = 0.0125f;
   game.projectile[ 6].speed        = 0.0075f;
   game.projectile[ 6].health       = 5;
   game.projectile[ 6].rate_of_fire = 5;

   game.projectile[ 7].name[0]      = 'E';
   game.projectile[ 7].name[1]      = 'n';
   game.projectile[ 7].name[2]      = 'e';
   game.projectile[ 7].name[3]      = 'm';
   game.projectile[ 7].name[4]      = 'y';
   game.projectile[ 7].name[5]      = ' ';
   game.projectile[ 7].name[6]      = 'l';
   game.projectile[ 7].name[7]      = 'a';
   game.projectile[ 7].name[8]      = 's';
   game.projectile[ 7].name[9]      = 'e';
   game.projectile[ 7].name[10]     = 'r';
   game.projectile[ 7].active       = false;
   game.projectile[ 7].level        = 0;
   game.projectile[ 7].experience   = 0;
   game.projectile[ 7].level_1      = 0.0f;
   game.projectile[ 7].level_2      = 0.0f;
   game.projectile[ 7].level_3      = 0.0f;
   game.projectile[ 7].image        = 229;
   game.projectile[ 7].sound        = 0;
   game.projectile[ 7].damage       = 0.025f;
   game.projectile[ 7].speed        = 0.0075f;
   game.projectile[ 7].health       = 5;
   game.projectile[ 7].rate_of_fire = 5;

   game.projectile[ 8].name[0]      = 'E';
   game.projectile[ 8].name[1]      = 'n';
   game.projectile[ 8].name[2]      = 'e';
   game.projectile[ 8].name[3]      = 'm';
   game.projectile[ 8].name[4]      = 'y';
   game.projectile[ 8].name[5]      = ' ';
   game.projectile[ 8].name[6]      = 'l';
   game.projectile[ 8].name[7]      = 'a';
   game.projectile[ 8].name[8]      = 's';
   game.projectile[ 8].name[9]      = 'e';
   game.projectile[ 8].name[10]     = 'r';
   game.projectile[ 8].active       = false;
   game.projectile[ 8].level        = 0;
   game.projectile[ 8].experience   = 0;
   game.projectile[ 8].level_1      = 0.0f;
   game.projectile[ 8].level_2      = 0.0f;
   game.projectile[ 8].level_3      = 0.0f;
   game.projectile[ 8].image        = 230;
   game.projectile[ 8].sound        = 0;
   game.projectile[ 8].damage       = 0.0375f;
   game.projectile[ 8].speed        = 0.0075f;
   game.projectile[ 8].health       = 5;
   game.projectile[ 8].rate_of_fire = 5;

   game.projectile[ 9].name[0]      = 'E';
   game.projectile[ 9].name[1]      = 'n';
   game.projectile[ 9].name[2]      = 'e';
   game.projectile[ 9].name[3]      = 'm';
   game.projectile[ 9].name[4]      = 'y';
   game.projectile[ 9].name[5]      = ' ';
   game.projectile[ 9].name[6]      = 'l';
   game.projectile[ 9].name[7]      = 'a';
   game.projectile[ 9].name[8]      = 's';
   game.projectile[ 9].name[9]      = 'e';
   game.projectile[ 9].name[10]     = 'r';
   game.projectile[ 9].active       = false;
   game.projectile[ 9].level        = 0;
   game.projectile[ 9].experience   = 0;
   game.projectile[ 9].level_1      = 0.0f;
   game.projectile[ 9].level_2      = 0.0f;
   game.projectile[ 9].level_3      = 0.0f;
   game.projectile[ 9].image        = 231;
   game.projectile[ 9].sound        = 0;
   game.projectile[ 9].damage       = 0.05f;
   game.projectile[ 9].speed        = 0.0075f;
   game.projectile[ 9].health       = 5;
   game.projectile[ 9].rate_of_fire = 5;

   game.projectile[10].name[0]      = 'E';
   game.projectile[10].name[1]      = 'n';
   game.projectile[10].name[2]      = 'e';
   game.projectile[10].name[3]      = 'm';
   game.projectile[10].name[4]      = 'y';
   game.projectile[10].name[5]      = ' ';
   game.projectile[10].name[6]      = 'l';
   game.projectile[10].name[7]      = 'a';
   game.projectile[10].name[8]      = 's';
   game.projectile[10].name[9]      = 'e';
   game.projectile[10].name[10]     = 'r';
   game.projectile[10].active       = false;
   game.projectile[10].level        = 0;
   game.projectile[10].experience   = 0;
   game.projectile[10].level_1      = 0.0f;
   game.projectile[10].level_2      = 0.0f;
   game.projectile[10].level_3      = 0.0f;
   game.projectile[10].image        = 232;
   game.projectile[10].sound        = 0;
   game.projectile[10].damage       = 0.0625f;
   game.projectile[10].speed        = 0.0075f;
   game.projectile[10].health       = 5;
   game.projectile[10].rate_of_fire = 5;

   game.projectile[11].name[0]      = 'E';
   game.projectile[11].name[1]      = 'n';
   game.projectile[11].name[2]      = 'e';
   game.projectile[11].name[3]      = 'm';
   game.projectile[11].name[4]      = 'y';
   game.projectile[11].name[5]      = ' ';
   game.projectile[11].name[6]      = 'l';
   game.projectile[11].name[7]      = 'a';
   game.projectile[11].name[8]      = 's';
   game.projectile[11].name[9]      = 'e';
   game.projectile[11].name[10]     = 'r';
   game.projectile[11].active       = false;
   game.projectile[11].level        = 0;
   game.projectile[11].experience   = 0;
   game.projectile[11].level_1      = 0.0f;
   game.projectile[11].level_2      = 0.0f;
   game.projectile[11].level_3      = 0.0f;
   game.projectile[11].image        = 233;
   game.projectile[11].sound        = 0;
   game.projectile[11].damage       = 0.075f;
   game.projectile[11].speed        = 0.0075f;
   game.projectile[11].health       = 5;
   game.projectile[11].rate_of_fire = 5;

   game.projectile[12].name[0]      = 'E';
   game.projectile[12].name[1]      = 'n';
   game.projectile[12].name[2]      = 'e';
   game.projectile[12].name[3]      = 'm';
   game.projectile[12].name[4]      = 'y';
   game.projectile[12].name[5]      = ' ';
   game.projectile[12].name[6]      = 'l';
   game.projectile[12].name[7]      = 'a';
   game.projectile[12].name[8]      = 's';
   game.projectile[12].name[9]      = 'e';
   game.projectile[12].name[10]     = 'r';
   game.projectile[12].active       = false;
   game.projectile[12].level        = 0;
   game.projectile[12].experience   = 0;
   game.projectile[12].level_1      = 0.0f;
   game.projectile[12].level_2      = 0.0f;
   game.projectile[12].level_3      = 0.0f;
   game.projectile[12].image        = 234;
   game.projectile[12].sound        = 0;
   game.projectile[12].damage       = 0.0875f;
   game.projectile[12].speed        = 0.0075f;
   game.projectile[12].health       = 5;
   game.projectile[12].rate_of_fire = 5;

   game.projectile[13].name[0]      = 'E';
   game.projectile[13].name[1]      = 'n';
   game.projectile[13].name[2]      = 'e';
   game.projectile[13].name[3]      = 'm';
   game.projectile[13].name[4]      = 'y';
   game.projectile[13].name[5]      = ' ';
   game.projectile[13].name[6]      = 'l';
   game.projectile[13].name[7]      = 'a';
   game.projectile[13].name[8]      = 's';
   game.projectile[13].name[9]      = 'e';
   game.projectile[13].name[10]     = 'r';
   game.projectile[13].active       = false;
   game.projectile[13].level        = 0;
   game.projectile[13].experience   = 0;
   game.projectile[13].level_1      = 0.0f;
   game.projectile[13].level_2      = 0.0f;
   game.projectile[13].level_3      = 0.0f;
   game.projectile[13].image        = 235;
   game.projectile[13].sound        = 0;
   game.projectile[13].damage       = 0.100f;
   game.projectile[13].speed        = 0.0075f;
   game.projectile[13].health       = 5;
   game.projectile[13].rate_of_fire = 5;

   game.projectile[14].name[0]      = 'E';
   game.projectile[14].name[1]      = 'n';
   game.projectile[14].name[2]      = 'e';
   game.projectile[14].name[3]      = 'm';
   game.projectile[14].name[4]      = 'y';
   game.projectile[14].name[5]      = ' ';
   game.projectile[14].name[6]      = 'l';
   game.projectile[14].name[7]      = 'a';
   game.projectile[14].name[8]      = 's';
   game.projectile[14].name[9]      = 'e';
   game.projectile[14].name[10]     = 'r';
   game.projectile[14].active       = false;
   game.projectile[14].level        = 0;
   game.projectile[14].experience   = 0;
   game.projectile[14].level_1      = 0.0f;
   game.projectile[14].level_2      = 0.0f;
   game.projectile[14].level_3      = 0.0f;
   game.projectile[14].image        = 236;
   game.projectile[14].sound        = 0;
   game.projectile[14].damage       = 0.1125f;
   game.projectile[14].speed        = 0.0075f;
   game.projectile[14].health       = 5;
   game.projectile[14].rate_of_fire = 5;

   game.projectile[15].name[0]      = 'E';
   game.projectile[15].name[1]      = 'n';
   game.projectile[15].name[2]      = 'e';
   game.projectile[15].name[3]      = 'm';
   game.projectile[15].name[4]      = 'y';
   game.projectile[15].name[5]      = ' ';
   game.projectile[15].name[6]      = 'l';
   game.projectile[15].name[7]      = 'a';
   game.projectile[15].name[8]      = 's';
   game.projectile[15].name[9]      = 'e';
   game.projectile[15].name[10]     = 'r';
   game.projectile[15].active       = false;
   game.projectile[15].level        = 0;
   game.projectile[15].experience   = 0;
   game.projectile[15].level_1      = 0.0f;
   game.projectile[15].level_2      = 0.0f;
   game.projectile[15].level_3      = 0.0f;
   game.projectile[15].image        = 237;
   game.projectile[15].sound        = 0;
   game.projectile[15].damage       = 0.125f;
   game.projectile[15].speed        = 0.0075f;
   game.projectile[15].health       = 5;
   game.projectile[15].rate_of_fire = 5;

   game.projectile[16].name[0]      = 'E';
   game.projectile[16].name[1]      = 'n';
   game.projectile[16].name[2]      = 'e';
   game.projectile[16].name[3]      = 'm';
   game.projectile[16].name[4]      = 'y';
   game.projectile[16].name[5]      = ' ';
   game.projectile[16].name[6]      = 'l';
   game.projectile[16].name[7]      = 'a';
   game.projectile[16].name[8]      = 's';
   game.projectile[16].name[9]      = 'e';
   game.projectile[16].name[10]     = 'r';
   game.projectile[16].active       = false;
   game.projectile[16].level        = 0;
   game.projectile[16].experience   = 0;
   game.projectile[16].level_1      = 0.0f;
   game.projectile[16].level_2      = 0.0f;
   game.projectile[16].level_3      = 0.0f;
   game.projectile[16].image        = 238;
   game.projectile[16].sound        = 0;
   game.projectile[16].damage       = 0.1375f;
   game.projectile[16].speed        = 0.0075f;
   game.projectile[16].health       = 5;
   game.projectile[16].rate_of_fire = 5;

   game.projectile[17].name[0]      = 'E';
   game.projectile[17].name[1]      = 'n';
   game.projectile[17].name[2]      = 'e';
   game.projectile[17].name[3]      = 'm';
   game.projectile[17].name[4]      = 'y';
   game.projectile[17].name[5]      = ' ';
   game.projectile[17].name[6]      = 'l';
   game.projectile[17].name[7]      = 'a';
   game.projectile[17].name[8]      = 's';
   game.projectile[17].name[9]      = 'e';
   game.projectile[17].name[10]     = 'r';
   game.projectile[17].active       = false;
   game.projectile[17].level        = 0;
   game.projectile[17].experience   = 0;
   game.projectile[17].level_1      = 0.0f;
   game.projectile[17].level_2      = 0.0f;
   game.projectile[17].level_3      = 0.0f;
   game.projectile[17].image        = 239;
   game.projectile[17].sound        = 0;
   game.projectile[17].damage       = 0.15f;
   game.projectile[17].speed        = 0.0075f;
   game.projectile[17].health       = 5;
   game.projectile[17].rate_of_fire = 5;

   game.projectile[18].name[0]      = 'E';
   game.projectile[18].name[1]      = 'n';
   game.projectile[18].name[2]      = 'e';
   game.projectile[18].name[3]      = 'm';
   game.projectile[18].name[4]      = 'y';
   game.projectile[18].name[5]      = ' ';
   game.projectile[18].name[6]      = 'l';
   game.projectile[18].name[7]      = 'a';
   game.projectile[18].name[8]      = 's';
   game.projectile[18].name[9]      = 'e';
   game.projectile[18].name[10]     = 'r';
   game.projectile[18].active       = false;
   game.projectile[18].level        = 0;
   game.projectile[18].experience   = 0;
   game.projectile[18].level_1      = 0.0f;
   game.projectile[18].level_2      = 0.0f;
   game.projectile[18].level_3      = 0.0f;
   game.projectile[18].image        = 240;
   game.projectile[18].sound        = 0;
   game.projectile[18].damage       = 0.1625f;
   game.projectile[18].speed        = 0.0075f;
   game.projectile[18].health       = 5;
   game.projectile[18].rate_of_fire = 5;

   game.projectile[19].name[0]      = 'E';
   game.projectile[19].name[1]      = 'n';
   game.projectile[19].name[2]      = 'e';
   game.projectile[19].name[3]      = 'm';
   game.projectile[19].name[4]      = 'y';
   game.projectile[19].name[5]      = ' ';
   game.projectile[19].name[6]      = 'l';
   game.projectile[19].name[7]      = 'a';
   game.projectile[19].name[8]      = 's';
   game.projectile[19].name[9]      = 'e';
   game.projectile[19].name[10]     = 'r';
   game.projectile[19].active       = false;
   game.projectile[19].level        = 0;
   game.projectile[19].experience   = 0;
   game.projectile[19].level_1      = 0.0f;
   game.projectile[19].level_2      = 0.0f;
   game.projectile[19].level_3      = 0.0f;
   game.projectile[19].image        = 241;
   game.projectile[19].sound        = 0;
   game.projectile[19].damage       = 0.175f;
   game.projectile[19].speed        = 0.0075f;
   game.projectile[19].health       = 5;
   game.projectile[19].rate_of_fire = 5;

   game.projectile[20].name[0]      = 'E';
   game.projectile[20].name[1]      = 'n';
   game.projectile[20].name[2]      = 'e';
   game.projectile[20].name[3]      = 'm';
   game.projectile[20].name[4]      = 'y';
   game.projectile[20].name[5]      = ' ';
   game.projectile[20].name[6]      = 'l';
   game.projectile[20].name[7]      = 'a';
   game.projectile[20].name[8]      = 's';
   game.projectile[20].name[9]      = 'e';
   game.projectile[20].name[10]     = 'r';
   game.projectile[20].active       = false;
   game.projectile[20].level        = 0;
   game.projectile[20].experience   = 0;
   game.projectile[20].level_1      = 0.0f;
   game.projectile[20].level_2      = 0.0f;
   game.projectile[20].level_3      = 0.0f;
   game.projectile[20].image        = 242;
   game.projectile[20].sound        = 0;
   game.projectile[20].damage       = 0.1875f;
   game.projectile[20].speed        = 0.0075f;
   game.projectile[20].health       = 5;
   game.projectile[20].rate_of_fire = 5;

   game.projectile[21].name[0]      = 'E';
   game.projectile[21].name[1]      = 'n';
   game.projectile[21].name[2]      = 'e';
   game.projectile[21].name[3]      = 'm';
   game.projectile[21].name[4]      = 'y';
   game.projectile[21].name[5]      = ' ';
   game.projectile[21].name[6]      = 'l';
   game.projectile[21].name[7]      = 'a';
   game.projectile[21].name[8]      = 's';
   game.projectile[21].name[9]      = 'e';
   game.projectile[21].name[10]     = 'r';
   game.projectile[21].active       = false;
   game.projectile[21].level        = 0;
   game.projectile[21].experience   = 0;
   game.projectile[21].level_1      = 0.0f;
   game.projectile[21].level_2      = 0.0f;
   game.projectile[21].level_3      = 0.0f;
   game.projectile[21].image        = 243;
   game.projectile[21].sound        = 0;
   game.projectile[21].damage       = 0.2f;
   game.projectile[21].speed        = 0.0075f;
   game.projectile[21].health       = 5;
   game.projectile[21].rate_of_fire = 5;

   game.projectile[22].name[0]      = 'E';
   game.projectile[22].name[1]      = 'n';
   game.projectile[22].name[2]      = 'e';
   game.projectile[22].name[3]      = 'm';
   game.projectile[22].name[4]      = 'y';
   game.projectile[22].name[5]      = ' ';
   game.projectile[22].name[6]      = 'l';
   game.projectile[22].name[7]      = 'a';
   game.projectile[22].name[8]      = 's';
   game.projectile[22].name[9]      = 'e';
   game.projectile[22].name[10]     = 'r';
   game.projectile[22].active       = false;
   game.projectile[22].level        = 0;
   game.projectile[22].experience   = 0;
   game.projectile[22].level_1      = 0.0f;
   game.projectile[22].level_2      = 0.0f;
   game.projectile[22].level_3      = 0.0f;
   game.projectile[22].image        = 244;
   game.projectile[22].sound        = 0;
   game.projectile[22].damage       = 0.2125f;
   game.projectile[22].speed        = 0.0075f;
   game.projectile[22].health       = 5;
   game.projectile[22].rate_of_fire = 5;

   game.projectile[23].name[0]      = 'E';
   game.projectile[23].name[1]      = 'n';
   game.projectile[23].name[2]      = 'e';
   game.projectile[23].name[3]      = 'm';
   game.projectile[23].name[4]      = 'y';
   game.projectile[23].name[5]      = ' ';
   game.projectile[23].name[6]      = 'l';
   game.projectile[23].name[7]      = 'a';
   game.projectile[23].name[8]      = 's';
   game.projectile[23].name[9]      = 'e';
   game.projectile[23].name[10]     = 'r';
   game.projectile[23].active       = false;
   game.projectile[23].level        = 0;
   game.projectile[23].experience   = 0;
   game.projectile[23].level_1      = 0.0f;
   game.projectile[23].level_2      = 0.0f;
   game.projectile[23].level_3      = 0.0f;
   game.projectile[23].image        = 245;
   game.projectile[23].sound        = 0;
   game.projectile[23].damage       = 0.225f;
   game.projectile[23].speed        = 0.0075f;
   game.projectile[23].health       = 5;
   game.projectile[23].rate_of_fire = 5;

   game.projectile[24].name[0]      = 'E';
   game.projectile[24].name[1]      = 'n';
   game.projectile[24].name[2]      = 'e';
   game.projectile[24].name[3]      = 'm';
   game.projectile[24].name[4]      = 'y';
   game.projectile[24].name[5]      = ' ';
   game.projectile[24].name[6]      = 'l';
   game.projectile[24].name[7]      = 'a';
   game.projectile[24].name[8]      = 's';
   game.projectile[24].name[9]      = 'e';
   game.projectile[24].name[10]     = 'r';
   game.projectile[24].active       = false;
   game.projectile[24].level        = 0;
   game.projectile[24].experience   = 0;
   game.projectile[24].level_1      = 0.0f;
   game.projectile[24].level_2      = 0.0f;
   game.projectile[24].level_3      = 0.0f;
   game.projectile[24].image        = 246;
   game.projectile[24].sound        = 0;
   game.projectile[24].damage       = 0.2375f;
   game.projectile[24].speed        = 0.0075f;
   game.projectile[24].health       = 5;
   game.projectile[24].rate_of_fire = 5;

   game.projectile[25].name[0]      = 'E';
   game.projectile[25].name[1]      = 'n';
   game.projectile[25].name[2]      = 'e';
   game.projectile[25].name[3]      = 'm';
   game.projectile[25].name[4]      = 'y';
   game.projectile[25].name[5]      = ' ';
   game.projectile[25].name[6]      = 'l';
   game.projectile[25].name[7]      = 'a';
   game.projectile[25].name[8]      = 's';
   game.projectile[25].name[9]      = 'e';
   game.projectile[25].name[10]     = 'r';
   game.projectile[25].active       = false;
   game.projectile[25].level        = 0;
   game.projectile[25].experience   = 0;
   game.projectile[25].level_1      = 0.0f;
   game.projectile[25].level_2      = 0.0f;
   game.projectile[25].level_3      = 0.0f;
   game.projectile[25].image        = 247;
   game.projectile[25].sound        = 0;
   game.projectile[25].damage       = 0.25f;
   game.projectile[25].speed        = 0.0075f;
   game.projectile[25].health       = 5;
   game.projectile[25].rate_of_fire = 5;

   game.projectile[26].name[0]      = 'E';
   game.projectile[26].name[1]      = 'n';
   game.projectile[26].name[2]      = 'e';
   game.projectile[26].name[3]      = 'm';
   game.projectile[26].name[4]      = 'y';
   game.projectile[26].name[5]      = ' ';
   game.projectile[26].name[6]      = 'l';
   game.projectile[26].name[7]      = 'a';
   game.projectile[26].name[8]      = 's';
   game.projectile[26].name[9]      = 'e';
   game.projectile[26].name[10]     = 'r';
   game.projectile[26].active       = false;
   game.projectile[26].level        = 0;
   game.projectile[26].experience   = 0;
   game.projectile[26].level_1      = 0.0f;
   game.projectile[26].level_2      = 0.0f;
   game.projectile[26].level_3      = 0.0f;
   game.projectile[26].image        = 248;
   game.projectile[26].sound        = 0;
   game.projectile[26].damage       = 0.2625f;
   game.projectile[26].speed        = 0.0075f;
   game.projectile[26].health       = 5;
   game.projectile[26].rate_of_fire = 5;

   game.projectile[27].name[0]      = 'E';
   game.projectile[27].name[1]      = 'n';
   game.projectile[27].name[2]      = 'e';
   game.projectile[27].name[3]      = 'm';
   game.projectile[27].name[4]      = 'y';
   game.projectile[27].name[5]      = ' ';
   game.projectile[27].name[6]      = 'l';
   game.projectile[27].name[7]      = 'a';
   game.projectile[27].name[8]      = 's';
   game.projectile[27].name[9]      = 'e';
   game.projectile[27].name[10]     = 'r';
   game.projectile[27].active       = false;
   game.projectile[27].level        = 0;
   game.projectile[27].experience   = 0;
   game.projectile[27].level_1      = 0.0f;
   game.projectile[27].level_2      = 0.0f;
   game.projectile[27].level_3      = 0.0f;
   game.projectile[27].image        = 249;
   game.projectile[27].sound        = 0;
   game.projectile[27].damage       = 0.275f;
   game.projectile[27].speed        = 0.0075f;
   game.projectile[27].health       = 5;
   game.projectile[27].rate_of_fire = 5;

   game.projectile[28].name[0]      = 'E';
   game.projectile[28].name[1]      = 'n';
   game.projectile[28].name[2]      = 'e';
   game.projectile[28].name[3]      = 'm';
   game.projectile[28].name[4]      = 'y';
   game.projectile[28].name[5]      = ' ';
   game.projectile[28].name[6]      = 'l';
   game.projectile[28].name[7]      = 'a';
   game.projectile[28].name[8]      = 's';
   game.projectile[28].name[9]      = 'e';
   game.projectile[28].name[10]     = 'r';
   game.projectile[28].active       = false;
   game.projectile[28].level        = 0;
   game.projectile[28].experience   = 0;
   game.projectile[28].level_1      = 0.0f;
   game.projectile[28].level_2      = 0.0f;
   game.projectile[28].level_3      = 0.0f;
   game.projectile[28].image        = 250;
   game.projectile[28].sound        = 0;
   game.projectile[28].damage       = 0.2875f;
   game.projectile[28].speed        = 0.0075f;
   game.projectile[28].health       = 5;
   game.projectile[28].rate_of_fire = 5;

   game.projectile[29].name[0]      = 'E';
   game.projectile[29].name[1]      = 'n';
   game.projectile[29].name[2]      = 'e';
   game.projectile[29].name[3]      = 'm';
   game.projectile[29].name[4]      = 'y';
   game.projectile[29].name[5]      = ' ';
   game.projectile[29].name[6]      = 'l';
   game.projectile[29].name[7]      = 'a';
   game.projectile[29].name[8]      = 's';
   game.projectile[29].name[9]      = 'e';
   game.projectile[29].name[10]     = 'r';
   game.projectile[29].active       = false;
   game.projectile[29].level        = 0;
   game.projectile[29].experience   = 0;
   game.projectile[29].level_1      = 0.0f;
   game.projectile[29].level_2      = 0.0f;
   game.projectile[29].level_3      = 0.0f;
   game.projectile[29].image        = 251;
   game.projectile[29].sound        = 0;
   game.projectile[29].damage       = 0.3f;
   game.projectile[29].speed        = 0.0075f;
   game.projectile[29].health       = 5;
   game.projectile[29].rate_of_fire = 5;

   game.projectile[30].name[0]      = 'E';
   game.projectile[30].name[1]      = 'n';
   game.projectile[30].name[2]      = 'e';
   game.projectile[30].name[3]      = 'm';
   game.projectile[30].name[4]      = 'y';
   game.projectile[30].name[5]      = ' ';
   game.projectile[30].name[6]      = 'l';
   game.projectile[30].name[7]      = 'a';
   game.projectile[30].name[8]      = 's';
   game.projectile[30].name[9]      = 'e';
   game.projectile[30].name[10]     = 'r';
   game.projectile[30].active       = false;
   game.projectile[30].level        = 0;
   game.projectile[30].experience   = 0;
   game.projectile[30].level_1      = 0.0f;
   game.projectile[30].level_2      = 0.0f;
   game.projectile[30].level_3      = 0.0f;
   game.projectile[30].image        = 252;
   game.projectile[30].sound        = 0;
   game.projectile[30].damage       = 0.3125f;
   game.projectile[30].speed        = 0.0075f;
   game.projectile[30].health       = 5;
   game.projectile[30].rate_of_fire = 5;

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
   game.enemy[0 ].movement    = 0;
   game.enemy[0 ].weapon      = 6;
   game.enemy[0 ].projectiles = 1;
   game.enemy[0 ].size_h      = 0.15f;
   game.enemy[0 ].size_w      = 0.15f;
   game.enemy[0 ].speed       = (game.projectile[game.enemy[0 ].weapon].speed/2);
   game.enemy[1 ].image       = 254;
   game.enemy[1 ].health      = 10.0f;
   game.enemy[1 ].movement    = 0;
   game.enemy[1 ].weapon      = 7;
   game.enemy[1 ].projectiles = 2;
   game.enemy[1 ].size_h      = 0.2f;
   game.enemy[1 ].size_w      = 0.2f;
   game.enemy[1 ].speed       = (game.projectile[game.enemy[1 ].weapon].speed/2);
   game.enemy[2 ].image       = 255;
   game.enemy[2 ].health      = 15.0f;
   game.enemy[2 ].movement    = 0;
   game.enemy[2 ].weapon      = 8;
   game.enemy[2 ].projectiles = 3;
   game.enemy[2 ].size_h      = 0.2f;
   game.enemy[2 ].size_w      = 0.2f;
   game.enemy[2 ].speed       = (game.projectile[game.enemy[2 ].weapon].speed/2);
   game.enemy[3 ].image       = 256;
   game.enemy[3 ].health      = 100.0f;
   game.enemy[3 ].movement    = 2;
   game.enemy[3 ].weapon      = 9;
   game.enemy[3 ].projectiles = 6;
   game.enemy[3 ].size_h      = 0.8f;
   game.enemy[3 ].size_w      = 0.4f;
   game.enemy[3 ].speed       = (game.projectile[game.enemy[3 ].weapon].speed/2);
   game.enemy[4 ].image       = 257;
   game.enemy[4 ].health      = 50.0f;
   game.enemy[4 ].movement    = 1;
   game.enemy[4 ].weapon      = 10;
   game.enemy[4 ].projectiles = 2;
   game.enemy[4 ].size_h      = 0.2f;
   game.enemy[4 ].size_w      = 0.2f;
   game.enemy[4 ].speed       = (game.projectile[game.enemy[4 ].weapon].speed/2);
   game.enemy[5 ].image       = 258;
   game.enemy[5 ].health      = 60.0f;
   game.enemy[5 ].movement    = 1;
   game.enemy[5 ].weapon      = 11;
   game.enemy[5 ].projectiles = 4;
   game.enemy[5 ].size_h      = 0.2f;
   game.enemy[5 ].size_w      = 0.2f;
   game.enemy[5 ].speed       = (game.projectile[game.enemy[5 ].weapon].speed/2);
   game.enemy[6 ].image       = 259;
   game.enemy[6 ].health      = 70.0f;
   game.enemy[6 ].movement    = 1;
   game.enemy[6 ].weapon      = 12;
   game.enemy[6 ].projectiles = 6;
   game.enemy[6 ].size_h      = 0.2f;
   game.enemy[6 ].size_w      = 0.2f;
   game.enemy[6 ].speed       = (game.projectile[game.enemy[6 ].weapon].speed/2);
   game.enemy[7 ].image       = 260;
   game.enemy[7 ].health      = 500.0f;
   game.enemy[7 ].movement    = 2;
   game.enemy[7 ].weapon      = 13;
   game.enemy[7 ].projectiles = 9;
   game.enemy[7 ].size_h      = 0.8f;
   game.enemy[7 ].size_w      = 0.4f;
   game.enemy[7 ].speed       = (game.projectile[game.enemy[7 ].weapon].speed/2);
   game.enemy[8 ].image       = 261;
   game.enemy[8 ].health      = 80.0f;
   game.enemy[8 ].movement    = 1;
   game.enemy[8 ].weapon      = 14;
   game.enemy[8 ].projectiles = 2;
   game.enemy[8 ].size_h      = 0.2f;
   game.enemy[8 ].size_w      = 0.2f;
   game.enemy[8 ].speed       = (game.projectile[game.enemy[8 ].weapon].speed/2);
   game.enemy[9 ].image       = 262;
   game.enemy[9 ].health      = 100.0f;
   game.enemy[9 ].movement    = 1;
   game.enemy[9 ].weapon      = 15;
   game.enemy[9 ].projectiles = 4;
   game.enemy[9 ].size_h      = 0.2f;
   game.enemy[9 ].size_w      = 0.2f;
   game.enemy[9 ].speed       = (game.projectile[game.enemy[9 ].weapon].speed/2);
   game.enemy[10].image       = 263;
   game.enemy[10].health      = 100.0f;
   game.enemy[10].movement    = 1;
   game.enemy[10].weapon      = 16;
   game.enemy[10].projectiles = 6;
   game.enemy[10].size_h      = 0.2f;
   game.enemy[10].size_w      = 0.2f;
   game.enemy[10].speed       = (game.projectile[game.enemy[10].weapon].speed/2);
   game.enemy[11].image       = 264;
   game.enemy[11].health      = 2000.0f;
   game.enemy[11].movement    = 2;
   game.enemy[11].weapon      = 17;
   game.enemy[11].projectiles = 9;
   game.enemy[11].size_h      = 0.8f;
   game.enemy[11].size_w      = 0.4f;
   game.enemy[11].speed       = (game.projectile[game.enemy[11].weapon].speed/2);
   game.enemy[12].image       = 265;
   game.enemy[12].health      = 120.0f;
   game.enemy[12].movement    = 1;
   game.enemy[12].weapon      = 18;
   game.enemy[12].projectiles = 2;
   game.enemy[12].size_h      = 0.2f;
   game.enemy[12].size_w      = 0.2f;
   game.enemy[12].speed       = (game.projectile[game.enemy[12].weapon].speed/2);   init_powerups();
   game.enemy[13].image       = 266;
   game.enemy[13].health      = 120.0f;
   game.enemy[13].movement    = 1;
   game.enemy[13].weapon      = 19;
   game.enemy[13].projectiles = 3;
   game.enemy[13].size_h      = 0.2f;
   game.enemy[13].size_w      = 0.2f;
   game.enemy[13].speed       = (game.projectile[game.enemy[13].weapon].speed/2);   init_powerups();
   game.enemy[14].image       = 267;
   game.enemy[14].health      = 120.0f;
   game.enemy[14].movement    = 1;
   game.enemy[14].weapon      = 20;
   game.enemy[14].projectiles = 5;
   game.enemy[14].size_h      = 0.2f;
   game.enemy[14].size_w      = 0.2f;
   game.enemy[14].speed       = (game.projectile[game.enemy[14].weapon].speed/2);   init_powerups();
   game.enemy[15].image       = 268;
   game.enemy[15].health      = 2000.0f;
   game.enemy[15].movement    = 2;
   game.enemy[15].weapon      = 21;
   game.enemy[15].projectiles = 9;
   game.enemy[15].size_h      = 0.8f;
   game.enemy[15].size_w      = 0.4f;
   game.enemy[15].speed       = (game.projectile[game.enemy[15].weapon].speed/2);
   game.enemy[16].image       = 269;
   game.enemy[16].health      = 130.0f;
   game.enemy[16].movement    = 1;
   game.enemy[16].weapon      = 22;
   game.enemy[16].projectiles = 2;
   game.enemy[16].size_h      = 0.2f;
   game.enemy[16].size_w      = 0.2f;
   game.enemy[16].speed       = (game.projectile[game.enemy[16].weapon].speed/2);   init_powerups();
   game.enemy[17].image       = 270;
   game.enemy[17].health      = 140.0f;
   game.enemy[17].movement    = 1;
   game.enemy[17].weapon      = 23;
   game.enemy[17].projectiles = 3;
   game.enemy[17].size_h      = 0.2f;
   game.enemy[17].size_w      = 0.2f;
   game.enemy[17].speed       = (game.projectile[game.enemy[17].weapon].speed/2);   init_powerups();
   game.enemy[18].image       = 271;
   game.enemy[18].health      = 150.0f;
   game.enemy[18].movement    = 1;
   game.enemy[18].weapon      = 24;
   game.enemy[18].projectiles = 5;
   game.enemy[18].size_h      = 0.2f;
   game.enemy[18].size_w      = 0.2f;
   game.enemy[18].speed       = (game.projectile[game.enemy[18].weapon].speed/2);   init_powerups();
   game.enemy[19].image       = 272;
   game.enemy[19].health      = 3000.0f;
   game.enemy[19].movement    = 2;
   game.enemy[19].weapon      = 25;
   game.enemy[19].projectiles = 9;
   game.enemy[19].size_h      = 0.8f;
   game.enemy[19].size_w      = 0.4f;
   game.enemy[19].speed       = (game.projectile[game.enemy[19].weapon].speed/2);   init_npcs(0);
   game.enemy[20].image       = 273;
   game.enemy[20].health      = 150.0f;
   game.enemy[20].movement    = 1;
   game.enemy[20].weapon      = 26;
   game.enemy[20].projectiles = 2;
   game.enemy[20].size_h      = 0.2f;
   game.enemy[20].size_w      = 0.2f;
   game.enemy[20].speed       = (game.projectile[game.enemy[20].weapon].speed/2);   init_powerups();
   game.enemy[21].image       = 274;
   game.enemy[21].health      = 160.0f;
   game.enemy[21].movement    = 1;
   game.enemy[21].weapon      = 27;
   game.enemy[21].projectiles = 3;
   game.enemy[21].size_h      = 0.2f;
   game.enemy[21].size_w      = 0.2f;
   game.enemy[21].speed       = (game.projectile[game.enemy[21].weapon].speed/2);   init_powerups();
   game.enemy[22].image       = 275;
   game.enemy[22].health      = 170.0f;
   game.enemy[22].movement    = 1;
   game.enemy[22].weapon      = 28;
   game.enemy[22].projectiles = 5;
   game.enemy[22].size_h      = 0.2f;
   game.enemy[22].size_w      = 0.2f;
   game.enemy[22].speed       = (game.projectile[game.enemy[22].weapon].speed/2);   init_powerups();
   game.enemy[23].image       = 276;
   game.enemy[23].health      = 4000.0f;
   game.enemy[23].movement    = 2;
   game.enemy[23].weapon      = 29;
   game.enemy[23].projectiles = 9;
   game.enemy[23].size_h      = 0.8f;
   game.enemy[23].size_w      = 0.4f;
   game.enemy[23].speed       = (game.projectile[game.enemy[23].weapon].speed/2);   init_npcs(0);
   game.enemy[24].image       = 277;
   game.enemy[24].health      = 5000.0f;
   game.enemy[24].movement    = 2;
   game.enemy[24].weapon      = 30;
   game.enemy[24].projectiles = 9;
   game.enemy[24].size_h      = 1.2f;
   game.enemy[24].size_w      = 0.8f;
   game.enemy[24].speed       = (game.projectile[game.enemy[24].weapon].speed/2);   init_npcs(0);   game.active_npc_count = 0;

   for (int level_no_count = 0;level_no_count < (MAX_LEVELS+1); level_no_count++)
   {
      game.level_locked[level_no_count] = false;  ///change me!!!!!! <<<<<<<<<<<<<<,
   }
      game.level_locked[0] = false;
   init_waves();
   return(0);
};
/*----------------------------------------------------------------------------*/
int  init_waves     (void)
{
   for(int wave_count = 0; wave_count < MAX_WAVES; wave_count++)
   {
      game.wave[wave_count].active         = false;
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
int spawn_npc(float x_position, float y_position, int type_npc)
{
   bool spawn_done = 0;
   for  (int npc_num = 0; npc_num < MAX_NPCS; npc_num++)
   {
       if (!spawn_done and !game.npc[npc_num].active)
       {
          game.npc[npc_num].active      = true;
          game.npc[npc_num].type_npc    = type_npc;
          game.npc[npc_num].x_pos       = x_position;
          game.npc[npc_num].y_pos       = y_position;
          game.npc[npc_num].weapon      = game.enemy[game.npc[npc_num].type_npc].weapon;
          game.npc[npc_num].projectiles = game.enemy[game.npc[npc_num].type_npc].projectiles;
          game.npc[npc_num].health      = game.enemy[game.npc[npc_num].type_npc].health;
          game.npc[npc_num].width       = game.enemy[game.npc[npc_num].type_npc].size_w;
          game.npc[npc_num].hight       = game.enemy[game.npc[npc_num].type_npc].size_h;
          game.npc[npc_num].x_speed     = game.enemy[game.npc[npc_num].type_npc].speed;
          game.npc[npc_num].y_speed     = game.enemy[game.npc[npc_num].type_npc].speed;
          game.npc[npc_num].movement    = game.enemy[game.npc[npc_num].type_npc].movement;
          game.npc[npc_num].x_direction = 0;
          game.npc[npc_num].y_direction = 0;
          spawn_done = 1;
          add_active_npc(npc_num);
       }
   }
   return(0);
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
int init_npcs(int type_npc)
{
   for (int npc_count = 0; npc_count < MAX_NPCS; npc_count++)
   {
      game.npc[npc_count].active      = false;
      game.npc[npc_count].type_npc    = type_npc;
      game.npc[npc_count].x_pos       = -2.0f;
      game.npc[npc_count].y_pos       = -2.0f;
      game.npc[npc_count].weapon      = game.enemy[game.npc[npc_count].type_npc].weapon;
      game.npc[npc_count].projectiles = game.enemy[game.npc[npc_count].type_npc].projectiles;
      game.npc[npc_count].health      = game.enemy[game.npc[npc_count].type_npc].health;
      game.npc[npc_count].width       = game.enemy[game.npc[npc_count].type_npc].size_w;
      game.npc[npc_count].hight       = game.enemy[game.npc[npc_count].type_npc].size_h;
      game.npc[npc_count].x_speed     = game.enemy[game.npc[npc_count].type_npc].speed;
      game.npc[npc_count].y_speed     = game.enemy[game.npc[npc_count].type_npc].speed;
      game.npc[npc_count].movement    = game.enemy[game.npc[npc_count].type_npc].movement;
      game.npc[npc_count].x_direction = 0;
      game.npc[npc_count].y_direction = 0;
   }
   init_npc_bullets();
   return(0);
}
/*----------------------------------------------------------------------------*/
int proccess_npcs(void)
{
   for (int npc_count = 0; npc_count < MAX_NPCS; npc_count++)
   {
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
            if (game.npc[npc_count].y_pos < game.player.y_pos) game.npc[npc_count].y_pos += game.npc[npc_count].y_speed;
            if (game.npc[npc_count].y_pos > game.player.y_pos) game.npc[npc_count].y_pos -= game.npc[npc_count].y_speed;
         }
         if (game.npc[npc_count].movement == 2)// avoid player and stay far right
         {
            game.npc[npc_count].x_pos -= game.npc[npc_count].x_speed;
            if (game.npc[npc_count].x_pos < ((1.0f) - (game.npc[npc_count].width/2))) game.npc[npc_count].x_pos = ((1.0f)- (game.npc[npc_count].width/2));
            if (((game.player.y_pos + (game.player.hight/2)) > (game.npc[npc_count].y_pos - (game.npc[npc_count].hight/2))) && ((game.player.y_pos - (game.player.hight/2)) < (game.npc[npc_count].y_pos + (game.npc[npc_count].hight/2))))
            {
               if (game.npc[npc_count].y_pos > game.player.y_pos) game.npc[npc_count].y_pos += game.npc[npc_count].y_speed;
               if (game.npc[npc_count].y_pos < game.player.y_pos) game.npc[npc_count].y_pos -= game.npc[npc_count].y_speed;
            }
            if ((game.npc[npc_count].y_pos - (game.npc[npc_count].hight/2)) < -1.0f) game.npc[npc_count].y_pos = ((-1.0f) + (game.npc[npc_count].hight/2));
            if ((game.npc[npc_count].y_pos + (game.npc[npc_count].hight/2)) >  1.0f) game.npc[npc_count].y_pos = (( 1.0f) - (game.npc[npc_count].hight/2));
         }
         if (game.npc[npc_count].movement == 3)// avoid player till border then home in on player
         {
            game.npc[npc_count].x_pos -= game.npc[npc_count].x_speed;
            if (game.npc[npc_count].x_pos < -1.0f) kill_npc(npc_count);
            if (game.npc[npc_count].y_pos > game.player.y_pos) game.npc[npc_count].y_pos += game.npc[npc_count].y_speed;
            if (game.npc[npc_count].y_pos < game.player.y_pos) game.npc[npc_count].y_pos -= game.npc[npc_count].y_speed;
            if ((game.npc[npc_count].y_pos - (game.npc[npc_count].hight/2)) < -1.0f) game.npc[npc_count].movement = 1;
            if ((game.npc[npc_count].y_pos + (game.npc[npc_count].hight/2)) >  1.0f) game.npc[npc_count].movement = 1;
         }
         if (game.npc[npc_count].movement == 4)// hone in on player and then move to border
         {
            game.npc[npc_count].x_pos -= game.npc[npc_count].x_speed;
            if (game.npc[npc_count].x_pos <  -1.0f) kill_npc(npc_count);
            if (game.npc[npc_count].y_pos <  game.player.y_pos) game.npc[npc_count].y_pos += game.npc[npc_count].y_speed;
            if (game.npc[npc_count].y_pos >  game.player.y_pos) game.npc[npc_count].y_pos -= game.npc[npc_count].y_speed;
            if (game.npc[npc_count].y_pos == game.player.y_pos) game.npc[npc_count].movement = 3;
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
   game.npc[npc_num].bullet[npc_bullet_num].x_pos    = (game.npc[npc_num].x_pos - (game.npc[npc_num].width/2));
   if (location == 0) game.npc[npc_num].bullet[npc_bullet_num].y_pos   =(game.npc[npc_num].y_pos + (game.npc[npc_num].hight/2))-0.02f;
   if (location == 1) game.npc[npc_num].bullet[npc_bullet_num].y_pos   = game.npc[npc_num].y_pos;
   if (location == 2) game.npc[npc_num].bullet[npc_bullet_num].y_pos   =(game.npc[npc_num].y_pos - (game.npc[npc_num].hight/2))+0.02f;
   if (location == 3) game.npc[npc_num].bullet[npc_bullet_num].y_pos   =(game.npc[npc_num].y_pos + (game.npc[npc_num].hight/2))-0.02f;
   if (location == 4) game.npc[npc_num].bullet[npc_bullet_num].y_pos   = game.npc[npc_num].y_pos;
   if (location == 5) game.npc[npc_num].bullet[npc_bullet_num].y_pos   =(game.npc[npc_num].y_pos - (game.npc[npc_num].hight/2))+0.02f;
   if (location == 6) game.npc[npc_num].bullet[npc_bullet_num].y_pos   =(game.npc[npc_num].y_pos + (game.npc[npc_num].hight/2))-0.02f;
   if (location == 7) game.npc[npc_num].bullet[npc_bullet_num].y_pos   = game.npc[npc_num].y_pos;
   if (location == 8) game.npc[npc_num].bullet[npc_bullet_num].y_pos   =(game.npc[npc_num].y_pos - (game.npc[npc_num].hight/2))+0.02f;
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
         if (game.npc[npc_count].bullet[bullet_count].active) game.npc[npc_count].bullet[bullet_count].x_pos -= game.projectile[game.npc[npc_count].bullet[bullet_count].warhead].speed;
         if (game.npc[npc_count].bullet[bullet_count].x_pos < (-1.0f - game.npc[npc_count].bullet[bullet_count].width)) kill_npc_bullet(npc_count,bullet_count);
         if (game.npc[npc_count].bullet[bullet_count].location == 3) game.npc[npc_count].bullet[bullet_count].y_pos += (game.projectile[game.npc[npc_count].bullet[bullet_count].warhead].speed / 1);
         if (game.npc[npc_count].bullet[bullet_count].location == 4) game.npc[npc_count].bullet[bullet_count].y_pos += (game.projectile[game.npc[npc_count].bullet[bullet_count].warhead].speed / 2);
         if (game.npc[npc_count].bullet[bullet_count].location == 5) game.npc[npc_count].bullet[bullet_count].y_pos += (game.projectile[game.npc[npc_count].bullet[bullet_count].warhead].speed / 3);
         if (game.npc[npc_count].bullet[bullet_count].location == 6) game.npc[npc_count].bullet[bullet_count].y_pos -= (game.projectile[game.npc[npc_count].bullet[bullet_count].warhead].speed / 3);
         if (game.npc[npc_count].bullet[bullet_count].location == 7) game.npc[npc_count].bullet[bullet_count].y_pos -= (game.projectile[game.npc[npc_count].bullet[bullet_count].warhead].speed / 2);
         if (game.npc[npc_count].bullet[bullet_count].location == 8) game.npc[npc_count].bullet[bullet_count].y_pos -= (game.projectile[game.npc[npc_count].bullet[bullet_count].warhead].speed / 1);
         // check player starship / npc bullet collisions...
         if (box_collision(game.player.x_pos,game.player.y_pos,game.player.width,game.player.hight,game.npc[npc_count].bullet[bullet_count].x_pos,game.npc[npc_count].bullet[bullet_count].y_pos,game.npc[npc_count].bullet[bullet_count].width,game.npc[npc_count].bullet[bullet_count].hight))
         {
            spawn_explosion(game.npc[npc_count].bullet[bullet_count].x_pos,game.npc[npc_count].bullet[bullet_count].y_pos,0.125f);
            kill_npc_bullet(npc_count,bullet_count);
            play_sound(13);//player shield hit
            game.player.health -= (0.005f - game.shield[game.player.front_shield].absorption);//(game.enemy[game.npc[npc_count].type_npc].health / 1000.0f);
            //if (game.player.health < 0.0f) game.player.health = 0.0f; //*********************** DIE **********************************
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
      game.powerup[type_powerup].active  = true;
      game.powerup[type_powerup].x_pos   = x_position;
      game.powerup[type_powerup].y_pos   = y_position;
   }
   return(0);
};
/*----------------------------------------------------------------------------*/
int kill_powerup(int type_powerup)
{
   game.powerup[type_powerup].active  = false;
   game.powerup[type_powerup].x_pos   = -2.0f;
   game.powerup[type_powerup].y_pos   = -2.0f;
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
   game.powerup[1].image   = 291;
   game.powerup[2].image   = 292;
   game.powerup[3].image   = 293;
   game.powerup[4].image   = 294;
   game.powerup[5].image   = 295;
   game.powerup[6].image   = 296;
   game.powerup[7].image   = 297;
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
         if (box_collision(game.player.x_pos,game.player.y_pos,game.player.width,game.player.hight,game.powerup[count].x_pos,game.powerup[count].y_pos,game.powerup[count].width,game.powerup[count].hight))
         {
            // spawn_message / sparckily / sound
            kill_powerup(count);
            switch (count)
            {
                case 1: //health 100%
                    {
                       game.player.health = 0.100f;
                       spawn_p_health();
                       break;
                    }
                case 2://shield lvl up
                    {
                       spawn_p_shield_level_up();
                       break;
                    }
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
                       break;
                    }
                case 4://thrusters lvl up
                    {
                       spawn_p_thrusters_level_up();
                       break;
                    }
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
                       break;
                    }
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
                       break;
                    }
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
                       break;
                    }
            }
         }
      }
   }
   return(0);
};
/*----------------------------------------------------------------------------*/
int spawn_explosion(float x_position, float y_position, float size)
{
   bool spawn_done = 0;
   int  explosion_num;
   for  (explosion_num = 0; explosion_num < MAX_EXPLOSIONS;explosion_num++)
   {
       if (!spawn_done and !game.explosion[explosion_num].active)
       {
           play_sound(game.explosion[explosion_num].sound);
           game.explosion[explosion_num].active  = true;
           game.explosion[explosion_num].frame   = 0;
           game.explosion[explosion_num].image   = 185;
           game.explosion[explosion_num].sound   = 5;
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
   game.explosion[explosion_num].active = false;
   game.explosion[explosion_num].frame   = 0;
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
      game.explosion[count].sound   = 5;
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
   return(0);
}
/*----------------------------------------------------------------------------*/
int proccess_player_bullets(void)
{
   for (int player_bullet_num = 0; player_bullet_num < MAX_BULLETS; player_bullet_num++)
   {
      if (game.player.bullet[player_bullet_num].active)
      {
         if (game.player.bullet[player_bullet_num].location < 3) game.player.bullet[player_bullet_num].x_pos += game.projectile[game.player.front_weapon].speed;
         else game.player.bullet[player_bullet_num].x_pos += game.projectile[game.player.side_weapon].speed;
         if (game.player.bullet[player_bullet_num].x_pos > 1.0f) game.player.bullet[player_bullet_num].active = false;
         if (game.player.bullet[player_bullet_num].location == 3) game.player.bullet[player_bullet_num].y_pos += (game.projectile[game.player.bullet[player_bullet_num].warhead].speed / 1);
         if (game.player.bullet[player_bullet_num].location == 4) game.player.bullet[player_bullet_num].y_pos += (game.projectile[game.player.bullet[player_bullet_num].warhead].speed / 2);
         if (game.player.bullet[player_bullet_num].location == 5) game.player.bullet[player_bullet_num].y_pos += (game.projectile[game.player.bullet[player_bullet_num].warhead].speed / 3);
         if (game.player.bullet[player_bullet_num].location == 6) game.player.bullet[player_bullet_num].y_pos -= (game.projectile[game.player.bullet[player_bullet_num].warhead].speed / 3);
         if (game.player.bullet[player_bullet_num].location == 7) game.player.bullet[player_bullet_num].y_pos -= (game.projectile[game.player.bullet[player_bullet_num].warhead].speed / 2);
         if (game.player.bullet[player_bullet_num].location == 8) game.player.bullet[player_bullet_num].y_pos -= (game.projectile[game.player.bullet[player_bullet_num].warhead].speed / 1);
//---------- collision detection ---------
         for (int npc_count = 0; npc_count < MAX_NPCS; npc_count++)
         {
            if (game.npc[npc_count].active)// check player bullets / npc collisions...
            {
               if (box_collision(game.npc[npc_count].x_pos,game.npc[npc_count].y_pos,game.npc[npc_count].width,game.npc[npc_count].hight,game.player.bullet[player_bullet_num].x_pos,game.player.bullet[player_bullet_num].y_pos,game.player.bullet[player_bullet_num].width,game.player.bullet[player_bullet_num].hight))
               {
                  if (game.player.bullet[player_bullet_num].location < 3) game.npc[npc_count].health -= game.projectile[game.player.front_weapon].damage;
                  else // hit npc ship, but not a kill
                  {
                      game.npc[npc_count].health -= game.projectile[game.player.side_weapon].damage;
                      spawn_explosion(game.npc[npc_count].x_pos,game.npc[npc_count].y_pos,0.1250f);
                  }
                  kill_player_bullet(player_bullet_num);
                  if (game.npc[npc_count].health <= 0)
                  {
                     if (game.player.bullet[player_bullet_num].location < 3) //level up our front weapon!
                     {
                        game.projectile[game.player.front_weapon].experience += (game.enemy[game.npc[npc_count].type_npc].health / game.exp_rate);
                        if ((game.projectile[game.player.front_weapon].experience >= game.projectile[game.player.front_weapon].level_1) && (game.projectile[game.player.front_weapon].level == 0))
                        {
                           game.projectile[game.player.front_weapon].level = 1;
                           game.projectile[game.player.front_weapon].experience = 0;
                        }
                        if ((game.projectile[game.player.front_weapon].experience >= game.projectile[game.player.front_weapon].level_2) && (game.projectile[game.player.front_weapon].level == 1))
                        {
                           game.projectile[game.player.front_weapon].level = 2;
                           game.projectile[game.player.front_weapon].experience = 0;
                        }
                        if ((game.projectile[game.player.front_weapon].experience >= game.projectile[game.player.front_weapon].level_3) && (game.projectile[game.player.front_weapon].level == 2))
                        {
                           game.projectile[game.player.front_weapon].level = 3;
                           game.projectile[game.player.front_weapon].experience = game.projectile[game.player.front_weapon].level_3;
                        }
                        if ((game.projectile[game.player.front_weapon].experience >= game.projectile[game.player.front_weapon].level_3) && (game.projectile[game.player.front_weapon].level == 3))
                        {
                           game.projectile[game.player.front_weapon].level = 3;
                           game.projectile[game.player.front_weapon].experience = game.projectile[game.player.front_weapon].level_3;
                        }
                     }
                     else  //level up our side weapon!
                     {
                        game.projectile[game.player.side_weapon].experience += (game.enemy[game.npc[npc_count].type_npc].health / game.exp_rate);
                        if ((game.projectile[game.player.side_weapon].experience >= game.projectile[game.player.side_weapon].level_1) && (game.projectile[game.player.side_weapon].level == 0))
                        {
                           game.projectile[game.player.side_weapon].level = 1;
                           game.projectile[game.player.side_weapon].experience = 0;
                        }
                        if ((game.projectile[game.player.side_weapon].experience >= game.projectile[game.player.side_weapon].level_2) && (game.projectile[game.player.side_weapon].level == 1))
                        {
                           game.projectile[game.player.side_weapon].level = 2;
                           game.projectile[game.player.side_weapon].experience = 0;
                        }
                        if ((game.projectile[game.player.side_weapon].experience >= game.projectile[game.player.side_weapon].level_3) && (game.projectile[game.player.side_weapon].level == 2))
                        {
                           game.projectile[game.player.side_weapon].level = 3;
                           game.projectile[game.player.side_weapon].experience = game.projectile[game.player.side_weapon].level_3;
                        }
                        if ((game.projectile[game.player.side_weapon].experience >= game.projectile[game.player.side_weapon].level_3) && (game.projectile[game.player.side_weapon].level == 3))
                        {
                           game.projectile[game.player.side_weapon].level = 3;
                           game.projectile[game.player.side_weapon].experience = game.projectile[game.player.side_weapon].level_3;
                        }
                     }
                     spawn_explosion(game.npc[npc_count].x_pos,game.npc[npc_count].y_pos,0.50f);
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
                     if (box_collision(game.npc[npc_count].bullet[npc_bullet_num].x_pos,game.npc[npc_count].bullet[npc_bullet_num].y_pos,game.npc[npc_count].bullet[npc_bullet_num].width,game.npc[npc_count].bullet[npc_bullet_num].hight,game.player.bullet[player_bullet_num].x_pos,game.player.bullet[player_bullet_num].y_pos,game.player.bullet[player_bullet_num].width,game.player.bullet[player_bullet_num].hight))
                     {
                     if (game.player.bullet[player_bullet_num].location < 3) //level up our front weapon!
                     {
                        game.projectile[game.player.front_weapon].experience += game.player.bullet[player_bullet_num].warhead;
                        if ((game.projectile[game.player.front_weapon].experience >= game.projectile[game.player.front_weapon].level_1) && (game.projectile[game.player.front_weapon].level == 0))
                        {
                           game.projectile[game.player.front_weapon].level = 1;
                           game.projectile[game.player.front_weapon].experience = 0;
                        }
                        if ((game.projectile[game.player.front_weapon].experience >= game.projectile[game.player.front_weapon].level_2) && (game.projectile[game.player.front_weapon].level == 1))
                        {
                           game.projectile[game.player.front_weapon].level = 2;
                           game.projectile[game.player.front_weapon].experience = 0;
                        }
                        if ((game.projectile[game.player.front_weapon].experience >= game.projectile[game.player.front_weapon].level_3) && (game.projectile[game.player.front_weapon].level == 2))
                        {
                           game.projectile[game.player.front_weapon].level = 3;
                           game.projectile[game.player.front_weapon].experience = game.projectile[game.player.front_weapon].level_3;
                        }
                        if ((game.projectile[game.player.front_weapon].experience >= game.projectile[game.player.front_weapon].level_3) && (game.projectile[game.player.front_weapon].level == 3))
                        {
                           game.projectile[game.player.front_weapon].level = 3;
                           game.projectile[game.player.front_weapon].experience = game.projectile[game.player.front_weapon].level_3;
                        }
                     }
                     else  //level up our side weapon!
                     {
                        game.projectile[game.player.side_weapon].experience += game.player.bullet[player_bullet_num].warhead;
                        if ((game.projectile[game.player.side_weapon].experience >= game.projectile[game.player.side_weapon].level_1) && (game.projectile[game.player.side_weapon].level == 0))
                        {
                           game.projectile[game.player.side_weapon].level = 1;
                           game.projectile[game.player.side_weapon].experience = 0;
                        }
                        if ((game.projectile[game.player.side_weapon].experience >= game.projectile[game.player.side_weapon].level_2) && (game.projectile[game.player.side_weapon].level == 1))
                        {
                           game.projectile[game.player.side_weapon].level = 2;
                           game.projectile[game.player.side_weapon].experience = 0;
                        }
                        if ((game.projectile[game.player.side_weapon].experience >= game.projectile[game.player.side_weapon].level_3) && (game.projectile[game.player.side_weapon].level == 2))
                        {
                           game.projectile[game.player.side_weapon].level = 3;
                           game.projectile[game.player.side_weapon].experience = game.projectile[game.player.side_weapon].level_3;
                        }
                        if ((game.projectile[game.player.side_weapon].experience >= game.projectile[game.player.side_weapon].level_3) && (game.projectile[game.player.side_weapon].level == 3))
                        {
                           game.projectile[game.player.side_weapon].level = 3;
                           game.projectile[game.player.side_weapon].experience = game.projectile[game.player.side_weapon].level_3;
                        }
                     }
                        spawn_explosion(game.npc[npc_count].bullet[npc_bullet_num].x_pos,game.npc[npc_count].bullet[npc_bullet_num].y_pos,0.25f);
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
   switch (command)
   {
      case 1://Up
         game.player.y_pos += (0.020 + game.thruster[game.player.thrusters].thrust);
         if (game.player.y_pos >  (1.0f -(game.player.hight/2))) game.player.y_pos = (1.0f -(game.player.hight/2));
      break;
      case 2://Down
         game.player.y_pos -= (0.020 + game.thruster[game.player.thrusters].thrust);
         if (game.player.y_pos < -(1.0f -(game.player.hight/2))) game.player.y_pos = -(1.0f -(game.player.hight/2));
      break;

      case 3://right
         game.player.x_pos += (0.020 + game.thruster[game.player.thrusters].thrust);
         if (game.player.x_pos >  (1.0f -(game.player.width/2))) game.player.x_pos = (1.0f -(game.player.width/2));
      break;
      case 4://Left
         game.player.x_pos -= (0.020 + game.thruster[game.player.thrusters].thrust);
         if (game.player.x_pos < -(1.0f - (game.player.width/2) - thruster_offset())) game.player.x_pos = -(1.0f -(game.player.width/2) - thruster_offset());
      break;
      default:
      break;
   }
   for (int npc_count = 0; npc_count < MAX_NPCS; npc_count++)
   {
      if (box_collision(game.npc[npc_count].x_pos,game.npc[npc_count].y_pos,game.npc[npc_count].width,game.npc[npc_count].hight,game.player.x_pos,game.player.y_pos,game.player.width,game.player.hight))
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
   if ((game.level_kills >= game.victory_kills) && (game.level_spawened >= game.victory_spawened) && (game.level_score >= game.victory_score)) return(true);
   else return(false);
}

/*----------------------------------------------------------------------------*/
int process_game(void)
{
   game.player.health += game.player.health_regen_rate;
   if (game.player.health > game.player.max_health) game.player.health = game.player.max_health;

   for (int count = 0;count < MAX_BACKGROUNDS+1;count++)//process backgrounds
   {
      game.background_scroll[count].x_pos -= game.background_scroll[count].scroll_rate;
      if (game.background_scroll[count].x_pos <= -4.0f) game.background_scroll[count].x_pos = 4.0f;
/*  ------------------------------------------ THERE IS A CRASH BUG HERE!!!!!!!!!!!!!!-----------------------------------------------*/
//  bug fixed? v0.11

      if (game.player.y_pos >= 0.75f)
      {
         game.background_scroll[count].y_pos  += game.background_scroll[count].scroll_rate;
         if (game.background_scroll[count].y_pos > 1.0f) game.background_scroll[count].y_pos = 1.0f;
      }
      if (game.player.y_pos <= -0.75f)
      {
         game.background_scroll[count].y_pos  -= game.background_scroll[count].scroll_rate;
         if (game.background_scroll[count].y_pos < -1.0f) game.background_scroll[count].y_pos = -1.0f;
      }
// bug above...fixed_? v0.11
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
   proccess_player_bullets();
   game.fw_rof_count++;
   if(game.fw_rof_count > game.projectile[game.player.front_weapon].rate_of_fire) game.fw_rof_count = game.projectile[game.player.front_weapon].rate_of_fire;
   game.sw_rof_count++;
   if(game.sw_rof_count > game.projectile[game.player.side_weapon].rate_of_fire)  game.sw_rof_count = game.projectile[game.player.side_weapon].rate_of_fire;
   proccess_npcs();
   proccess_npc_bullets();
   proccess_explosions();
   proccess_powerups();
   if (level_completed())
   {
      game.game_active = false;
      game.nlvl_active = true;
   };
   if (random(game.powerup[1].spawn_rate) == 5) spawn_powerup(1.0f,random_GLcoord(),1);//spawn health powerup
   if (random(game.powerup[2].spawn_rate) == 5) spawn_powerup(1.0f,random_GLcoord(),2);//spawn shield lvl powerup
   if (random(game.powerup[3].spawn_rate) == 5) spawn_powerup(1.0f,random_GLcoord(),3);//spawn shield new powerup
   if (random(game.powerup[4].spawn_rate) == 5) spawn_powerup(1.0f,random_GLcoord(),4);//spawn thruster lvl powerup
   if (random(game.powerup[5].spawn_rate) == 5) spawn_powerup(1.0f,random_GLcoord(),5);//spawn thruster new powerup
   if (random(game.powerup[6].spawn_rate) == 5) spawn_powerup(1.0f,random_GLcoord(),6);//spawn weapon lvl powerup
   if (random(game.powerup[7].spawn_rate) == 5) spawn_powerup(1.0f,random_GLcoord(),7);//spawn weapon new powerup
   if (random(game.npc_spawn_rate) == 5)//spawn npc
   {
//           play_sound(3);
      if (!game.level_boss_level)
      {
         spawn_npc(1.0f,random_GLcoord(),game.level_npc_type);
         game.level_spawened += 1;
      }
      if (game.level_boss_level && (game.level_spawened == 0))
      {
         spawn_npc(1.0f,random_GLcoord(),game.level_npc_type);
         game.level_spawened += 1;
      }
   }
   for (int npc_count = 0; npc_count < MAX_NPCS; npc_count++)//npc spawn bullet
   {
      if (game.npc[npc_count].active)
      {
         if (random(game.npc_projectile_spawn_rate) == 5)
         {
            play_sound(game.projectile[game.npc[npc_count].bullet[0].warhead].sound);
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
         }
      }
   }
   return(0);
};
/*----------------------------------------------------------------------------*/
int display_game(void)
{
   float z_pos = 0;
   float temp_val;
   glPushMatrix();
//maybe for linked backgrounds, use points from each other to connect seamlessly?????
   for (int count =MAX_BACKGROUNDS;count >=0;count--)
   {
     z_pos = 0.15f + (0.01*count);
     glBindTexture( GL_TEXTURE_2D, texture[game.background_scroll[count].image].texture);
     glLoadIdentity();
     glBegin( GL_QUADS );
     glTexCoord2i( 0, 1 );glVertex3f(-2.000f + game.background_scroll[count].x_pos,-2.000f + game.background_scroll[count].y_pos,z_pos);
     glTexCoord2i( 0, 0 );glVertex3f(-2.000f + game.background_scroll[count].x_pos, 2.000f + game.background_scroll[count].y_pos,z_pos);
     glTexCoord2i( 1, 0 );glVertex3f( 2.000f + game.background_scroll[count].x_pos, 2.000f + game.background_scroll[count].y_pos,z_pos);
     glTexCoord2i( 1, 1 );glVertex3f( 2.000f + game.background_scroll[count].x_pos,-2.000f + game.background_scroll[count].y_pos,z_pos);
     glEnd();
   }
   for (int npc_count =MAX_NPCS-1;npc_count >=0;npc_count--)  // npcs
   {
      z_pos = 0.04f + (0.0001*npc_count);
      glBindTexture( GL_TEXTURE_2D, texture[game.enemy[game.npc[npc_count].type_npc].image].texture);
      glLoadIdentity();
      if (game.npc[npc_count].active)
      {
         glBegin( GL_QUADS );
         glTexCoord2i( 1, 1 );glVertex3f(game.npc[npc_count].x_pos+(game.npc[npc_count].width/2),game.npc[npc_count].y_pos-(game.npc[npc_count].hight/2),z_pos);
         glTexCoord2i( 0, 1 );glVertex3f(game.npc[npc_count].x_pos+(game.npc[npc_count].width/2),game.npc[npc_count].y_pos+(game.npc[npc_count].hight/2),z_pos);
         glTexCoord2i( 0, 0 );glVertex3f(game.npc[npc_count].x_pos-(game.npc[npc_count].width/2),game.npc[npc_count].y_pos+(game.npc[npc_count].hight/2),z_pos);
         glTexCoord2i( 1, 0 );glVertex3f(game.npc[npc_count].x_pos-(game.npc[npc_count].width/2),game.npc[npc_count].y_pos-(game.npc[npc_count].hight/2),z_pos);
         glEnd();
      }
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
   }

   if (game.player.thrusters > -1)
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

      if (game.player.front_weapon > -1)
      {
         glBindTexture( GL_TEXTURE_2D, texture[game.player.front_weapon+211].texture); //player starship front weapon
         glLoadIdentity();
         glBegin( GL_QUADS );
         glTexCoord2i( 0, 0 );glVertex3f(game.player.x_pos+(game.player.width/6)+0.063f,game.player.y_pos-(game.player.hight/6), 0.025f );
         glTexCoord2i( 1, 0 );glVertex3f(game.player.x_pos+(game.player.width/6)+0.063f,game.player.y_pos+(game.player.hight/6), 0.025f );
         glTexCoord2i( 1, 1 );glVertex3f(game.player.x_pos-(game.player.width/6)+0.088f,game.player.y_pos+(game.player.hight/6), 0.025f );
         glTexCoord2i( 0, 1 );glVertex3f(game.player.x_pos-(game.player.width/6)+0.088f,game.player.y_pos-(game.player.hight/6), 0.025f );
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
   for (int count =0;count < MAX_BULLETS;count++) //player bullets
   {
      if (game.player.bullet[count].active)
      {
         if (game.player.bullet[count].location < 3) glBindTexture( GL_TEXTURE_2D, texture[game.projectile[game.player.front_weapon].image].texture);
         else glBindTexture( GL_TEXTURE_2D, texture[game.projectile[game.player.side_weapon].image].texture);
         glLoadIdentity();
         glBegin( GL_QUADS );
         glTexCoord2i( 1, 0 );glVertex3f(game.player.bullet[count].x_pos+(game.player.bullet[count].width/2),game.player.bullet[count].y_pos-(game.player.bullet[count].hight/2), 0.05f );
         glTexCoord2i( 1, 1 );glVertex3f(game.player.bullet[count].x_pos+(game.player.bullet[count].width/2),game.player.bullet[count].y_pos+(game.player.bullet[count].hight/2), 0.05f );
         glTexCoord2i( 0, 1 );glVertex3f(game.player.bullet[count].x_pos-(game.player.bullet[count].width/2),game.player.bullet[count].y_pos+(game.player.bullet[count].hight/2), 0.05f );
         glTexCoord2i( 0, 0 );glVertex3f(game.player.bullet[count].x_pos-(game.player.bullet[count].width/2),game.player.bullet[count].y_pos-(game.player.bullet[count].hight/2), 0.05f );
         glEnd();
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
   if (game.paused.active)   display_paused();
   if (game.loaded.active)   display_loaded();
   if (game.saved.active)    display_saved();
   if (game.a_score.active)  display_a_score();
   if (game.a_kills.active)  display_a_kills();

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

   font_print(128,128,192,-1.00f, 0.95f,"Score - %1.0f", game.score);
   font_print(128,128,192,-1.00f, 0.90f,"Kills - %1.0f", game.kills);
   font_print(128,128,192, 0.40f, 0.95f,"Active NPCs - %1.0f",  game.active_npc_count);
   font_print(128,128,192, 0.40f, 0.90f,"FPS - %1.0f",  game.FPS);
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

