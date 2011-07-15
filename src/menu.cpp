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

#include <gl/gl.h>
#include "menu.hpp"
#include "graphics.hpp"
#include "savegame.hpp"
#include "game.hpp"
#include "config.hpp"
#include "log.hpp"
#include "sounds.hpp"
#include "music.hpp"
#include "textures.hpp"
#include "levels.hpp"
#include "font.hpp"

extern log_file_class    main_log;
extern config_data_type  config_data;
extern sound_type        sound[MAX_SOUNDS];
extern music_type        music[MAX_MUSIC];
extern texture_type      texture[MAX_TEXTURES];
extern game_type         game;
       menu_type         menu;

int process_menu_background(void)
{
// -------------------------   background 0  -----------------------------------
   if (menu.background_scroll[0].x_dir == 0)
   {
      menu.background_scroll[0].x_pos -= menu.background_scroll[0].scroll_rate;
      if (menu.background_scroll[0].x_pos < 0.0f) menu.background_scroll[0].x_dir = 1;
   }
   if (menu.background_scroll[0].x_dir == 1)
   {
      menu.background_scroll[0].x_pos += menu.background_scroll[0].scroll_rate;
      if (menu.background_scroll[0].x_pos > 1.0f) menu.background_scroll[0].x_dir = 0;
   }

   if (menu.background_scroll[0].y_dir == 0)
   {
      menu.background_scroll[0].y_pos -= menu.background_scroll[0].scroll_rate;
      if (menu.background_scroll[0].y_pos < 0.0f) menu.background_scroll[0].y_dir = 1;
   }
   if (menu.background_scroll[0].y_dir == 1)
   {
      menu.background_scroll[0].y_pos += menu.background_scroll[0].scroll_rate;
      if (menu.background_scroll[0].y_pos > 0.75f) menu.background_scroll[0].y_dir = 0;
   }
// -------------------------   background 1  -----------------------------------
   if (menu.background_scroll[1].x_dir == 0)
   {
      menu.background_scroll[1].x_pos -= menu.background_scroll[1].scroll_rate;
      if (menu.background_scroll[1].x_pos < 0.0f) menu.background_scroll[1].x_dir = 1;
   }
   if (menu.background_scroll[1].x_dir == 1)
   {
      menu.background_scroll[1].x_pos += menu.background_scroll[1].scroll_rate;
      if (menu.background_scroll[1].x_pos > 1.0f) menu.background_scroll[1].x_dir = 0;
   }

   if (menu.background_scroll[1].y_dir == 0)
   {
      menu.background_scroll[1].y_pos -= menu.background_scroll[1].scroll_rate;
      if (menu.background_scroll[1].y_pos < 0.0f) menu.background_scroll[1].y_dir = 1;
   }
   if (menu.background_scroll[1].y_dir == 1)
   {
      menu.background_scroll[1].y_pos += menu.background_scroll[1].scroll_rate;
      if (menu.background_scroll[1].y_pos > 0.75f) menu.background_scroll[1].y_dir = 0;
   }
};

   //---------------------------------------------------------------------------------------
int process_menu(void)
{
    process_menu_background();
        game.io.keyboard_delay_count++;
        if (game.io.keyboard_delay_count > game.io.keyboard_delay) game.io.keyboard_delay_count = game.io.keyboard_delay;
        if ((game.io.escape) && (game.io.keyboard_delay_count >= game.io.keyboard_delay))
              {
                 game.io.keyboard_delay_count = 0;
                 play_sound(1);
                 switch (menu.level)
                 {
                    case 0://main menu
                       game.status_quit_active = true;
                       main_log.File_Write("User terminating game - used escape key!");
                    break;
                    case 1://game menu
                       menu.possition = 0;
                       menu.level = 0;
                       menu.possition_max = 4;
                       main_log.File_Write("Entering 'main' menu.");
                    break;
                    case 2: // options menu
                       menu.possition = 3;
                       menu.level = 0;
                       menu.possition_max = 4;
                       main_log.File_Write("Entering 'main' menu.");
                    break;
                    case 3: // customize starship menu
                       menu.possition = 2;
                       menu.level = 1;
                       menu.possition_max = 6;
                       main_log.File_Write("Entering 'new game' menu.");
                    break;
                    case 4: // star map menu
                       menu.possition = 0;
                       menu.level = 1;
                       menu.possition_max = 6;
                       main_log.File_Write("Entering 'new game' menu.");
                    break;
                    case 5: // save game menu
                       menu.possition = 4;
                       menu.level = 1;
                       menu.possition_max = 6;
                       main_log.File_Write("Entering 'new game' menu.");
                    break;
                    case 6: // load game menu
                       menu.possition = 5;
                       menu.level = 1;
                       menu.possition_max = 6;
                       main_log.File_Write("Entering 'new game' menu.");
                    break;
                    case 7: // Achievements menu
                       menu.possition = 1;
                       menu.level = 1;
                       menu.possition_max = 6;
                       main_log.File_Write("Entering 'new game' menu.");
                    break;
                    default:
                       main_log.File_Write("Undefined menu choice, quiting.");
                       game.status_quit_active = true;
                 }
              }
        if ((game.io.up) && (game.io.keyboard_delay_count >= game.io.keyboard_delay))
              {
                 game.io.keyboard_delay_count = 0;
                 if (menu.level == 0)//main menu
                 {
                 menu.possition--;
                 if (menu.possition < 0) menu.possition = 0;
                 else play_sound(0);
                 }
                 if (menu.level == 1)//new game menu
                 {
                 menu.possition--;
                 if (menu.possition < 0) menu.possition = 0;
                 else play_sound(0);
                 }
                 if (menu.level == 2)//options menu
                 {
                 menu.possition--;
                 if (menu.possition < 0) menu.possition = 0;
                 else play_sound(0);
                 }
                 if (menu.level == 3)//customize starship menu
                 {
                 menu.possition--;
                 if (menu.possition < 0) menu.possition = 0;
                 else play_sound(0);
                 }
                 if ((menu.level == 4) && (menu.possition == 3))//star map menu
                 {
                    menu.possition = menu.recall_position;
                    play_sound(0);
                 }
                 if (menu.level == 5)//save game menu
                 {
                    menu.possition--;
                    if (menu.possition < 0) menu.possition = 0;
                    else play_sound(0);
                 }
                 if (menu.level == 6)//load game menu
                 {
                 menu.possition--;
                 if (menu.possition < 0) menu.possition = 0;
                 else play_sound(0);
                 }
                 if (menu.level == 7)//Achievements menu
                 {
                 menu.possition--;
                 if (menu.possition < 0) menu.possition = 0;
                 else play_sound(0);
                 }
              }
        if ((game.io.down) && (game.io.keyboard_delay_count >= game.io.keyboard_delay))
              {
                 game.io.keyboard_delay_count = 0;
                 if (menu.level == 0)//main menu
                 {
                 menu.possition++;
                 if (menu.possition > menu.possition_max) menu.possition = menu.possition_max;
                 else play_sound(0);
                 }
                 if (menu.level == 1)//new game menu
                 {
                 menu.possition++;
                 if (menu.possition > menu.possition_max) menu.possition = menu.possition_max;
                 else play_sound(0);
                 }
                 if (menu.level == 2)//options menu
                 {
                 menu.possition++;
                 if (menu.possition > menu.possition_max) menu.possition = menu.possition_max;
                 else play_sound(0);
                 }
                 if (menu.level == 3)//customize starship menu
                 {
                 menu.possition++;
                 if (menu.possition > menu.possition_max) menu.possition = menu.possition_max;
                 else play_sound(0);
                 }
                 if ((menu.level == 4) && (menu.possition != 3))//star map menu
                 {
                    menu.recall_position = menu.possition;
                    menu.possition = 3;
                    play_sound(0);
                 }
                 if (menu.level == 5)//save game menu
                 {
                 menu.possition++;
                 if (menu.possition > menu.possition_max) menu.possition = menu.possition_max;
                 else play_sound(0);
                 }
                 if (menu.level == 6)//load menu
                 {
                 menu.possition++;
                 if (menu.possition > menu.possition_max) menu.possition = menu.possition_max;
                 else play_sound(0);
                 }
                 if (menu.level == 7)//Achievements menu
                 {
                 menu.possition++;
                 if (menu.possition > menu.possition_max) menu.possition = menu.possition_max;
                 else play_sound(0);
                 }
              }
        if (game.io.left)
            {
                 if ((menu.level == 2) and (menu.possition == 0))//decrease sound volume
              {
                 config_data.Audio_Sound_Volume--;
                 if (config_data.Audio_Sound_Volume < 0) config_data.Audio_Sound_Volume = 0;
                 Mix_Volume(-1,config_data.Audio_Sound_Volume);
              }
              if ((menu.level == 2) and (menu.possition == 1))//decrease music volume
              {
                 config_data.Audio_Music_Volume--;
                 if (config_data.Audio_Music_Volume < 0) config_data.Audio_Music_Volume = 0;
                 Mix_VolumeMusic(config_data.Audio_Music_Volume);
              }
            }
        if ((game.io.left) && (game.io.keyboard_delay_count >= game.io.keyboard_delay))
            {
                game.io.keyboard_delay_count = 0;
              if ((menu.level == 2) and (menu.possition == 2))//disable fullscreen
              {
                 if (config_data.Display_Fullscreen == true)
                 {
                    kill_textures();
                    SDL_SetVideoMode(config_data.Display_X_Resolution,config_data.Display_Y_Resolution,config_data.Display_BPS,SDL_OPENGL);
                    init_gl();
                    load_textures();
                    config_data.Display_Fullscreen   = false;
                  }
              }
                 if ((menu.level == 2) && (menu.possition == 3) && (config_data.Display_resolution != 0))//resolution select <
                 {
                    config_data.Display_resolution--;
                    if (config_data.Display_resolution < 0) config_data.Display_resolution = 0;
                    if (config_data.Display_resolution == 0)
                    {
                       config_data.Display_X_Resolution = 640;
                       config_data.Display_Y_Resolution = 480;
                    }
                    if (config_data.Display_resolution == 1)
                    {
                       config_data.Display_X_Resolution = 800;
                       config_data.Display_Y_Resolution = 600;
                    }
                    if (config_data.Display_resolution == 2)
                    {
                       config_data.Display_X_Resolution = 1024;
                       config_data.Display_Y_Resolution = 768;
                    }
                    if (config_data.Display_resolution == 3)
                    {
                       config_data.Display_X_Resolution = 1280;
                       config_data.Display_Y_Resolution = 1024;
                    }
                    if (config_data.Display_resolution == 4)
                    {
                       config_data.Display_X_Resolution = 1366;
                       config_data.Display_Y_Resolution = 768;
                    }
                    if (config_data.Display_resolution == 5)
                    {
                       config_data.Display_X_Resolution = 1440;
                       config_data.Display_Y_Resolution = 900;
                    }
                    if (config_data.Display_resolution == 6)
                    {
                       config_data.Display_X_Resolution = 1680;
                       config_data.Display_Y_Resolution = 1050;
                    }
                    if (config_data.Display_resolution == 7)
                    {
                       config_data.Display_X_Resolution = 1920;
                       config_data.Display_Y_Resolution = 1080;
                    }
                    config_data.mouse_resolution_x   = config_data.Display_X_Resolution;
                    config_data.mouse_resolution_y   = config_data.Display_Y_Resolution;
                    kill_textures();
                    if (config_data.Display_Fullscreen == true ) SDL_SetVideoMode(config_data.Display_X_Resolution,config_data.Display_Y_Resolution,config_data.Display_BPS,SDL_OPENGL | SDL_FULLSCREEN);
                    if (config_data.Display_Fullscreen == false) SDL_SetVideoMode(config_data.Display_X_Resolution,config_data.Display_Y_Resolution,config_data.Display_BPS,SDL_OPENGL);
                    init_gl();
                    load_textures();
                 }
                 if ((menu.level == 4) && (menu.possition < 3))//star map level select <
                 {
                    if ((menu.possition == 0) && (menu.level_no > 0))
                    {
                       menu.level_no -= 1;
                       if (menu.level_no < 0) menu.level_no = 0;
                       play_sound(0);
                    }
                    menu.possition--;
                    if (menu.possition < 0) menu.possition = 0;
                    else play_sound(0);
                 }
                 if (menu.level == 3)//customize starship
                 {
                    switch (menu.possition)
                    {
                       case 0://front weapon select
                       game.player.front_weapon--;
                       if (game.player.front_weapon < -1) game.player.front_weapon = -1;
                       break;
                       case 1://side weapon select
                       game.player.side_weapon--;
                       if (game.player.side_weapon < -1) game.player.side_weapon = -1;
                       break;
                       case 2://shield select
                       game.player.front_shield--;
                       if (game.player.front_shield < -1) game.player.front_shield = -1;
                       break;
                       case 3://thrusters select
                       game.player.thrusters--;
                       if (game.player.thrusters < -1) game.player.thrusters = -1;
                       break;
                    }
                 play_sound(0);
                 }
              }
        if (game.io.right)
              {
                 if ((menu.level == 2) and (menu.possition == 0))//increase sound volume
                 {
                    config_data.Audio_Sound_Volume++;
                    if (config_data.Audio_Sound_Volume > 128) config_data.Audio_Sound_Volume = 128;
                    Mix_Volume(-1,config_data.Audio_Sound_Volume);
                 }
                 if ((menu.level == 2) and (menu.possition == 1))//increase music volume
                 {
                    config_data.Audio_Music_Volume++;
                    if (config_data.Audio_Music_Volume > 128) config_data.Audio_Music_Volume = 128;
                    Mix_VolumeMusic(config_data.Audio_Music_Volume);
                 }
              }
        if ((game.io.right) && (game.io.keyboard_delay_count >= game.io.keyboard_delay))
              {
                game.io.keyboard_delay_count = 0;
                 if ((menu.level == 2) and (menu.possition == 2))//enable fullscreen
                 {
                    if (config_data.Display_Fullscreen == false)
                    {
                       kill_textures();
                       SDL_SetVideoMode(config_data.Display_X_Resolution,config_data.Display_Y_Resolution,config_data.Display_BPS,SDL_OPENGL | SDL_FULLSCREEN);
                       init_gl();
                       load_textures();
                       config_data.Display_Fullscreen   = true;
                    }
                 }
                 if ((menu.level == 2) && (menu.possition == 3) && (config_data.Display_resolution != 7))//resolution select <
                 {
                    config_data.Display_resolution++;
                    if (config_data.Display_resolution > 7) config_data.Display_resolution = 7;
                    if (config_data.Display_resolution == 0)
                    {
                       config_data.Display_X_Resolution = 640;
                       config_data.Display_Y_Resolution = 480;
                    }
                    if (config_data.Display_resolution == 1)
                    {
                       config_data.Display_X_Resolution = 800;
                       config_data.Display_Y_Resolution = 600;
                    }
                    if (config_data.Display_resolution == 2)
                    {
                       config_data.Display_X_Resolution = 1024;
                       config_data.Display_Y_Resolution = 768;
                    }
                    if (config_data.Display_resolution == 3)
                    {
                       config_data.Display_X_Resolution = 1280;
                       config_data.Display_Y_Resolution = 1024;
                    }
                    if (config_data.Display_resolution == 4)
                    {
                       config_data.Display_X_Resolution = 1366;
                       config_data.Display_Y_Resolution = 768;
                    }
                    if (config_data.Display_resolution == 5)
                    {
                       config_data.Display_X_Resolution = 1440;
                       config_data.Display_Y_Resolution = 900;
                    }
                    if (config_data.Display_resolution == 6)
                    {
                       config_data.Display_X_Resolution = 1680;
                       config_data.Display_Y_Resolution = 1050;
                    }
                    if (config_data.Display_resolution == 7)
                    {
                       config_data.Display_X_Resolution = 1920;
                       config_data.Display_Y_Resolution = 1080;
                    }
                    config_data.mouse_resolution_x   = config_data.Display_X_Resolution;
                    config_data.mouse_resolution_y   = config_data.Display_Y_Resolution;
                    kill_textures();
                    if (config_data.Display_Fullscreen == true ) SDL_SetVideoMode(config_data.Display_X_Resolution,config_data.Display_Y_Resolution,config_data.Display_BPS,SDL_OPENGL | SDL_FULLSCREEN);
                    if (config_data.Display_Fullscreen == false) SDL_SetVideoMode(config_data.Display_X_Resolution,config_data.Display_Y_Resolution,config_data.Display_BPS,SDL_OPENGL);
                    init_gl();
                    load_textures();
                 }
                 if ((menu.level == 4) && (menu.possition < 3))//star map level select <
                 {
                    if ((menu.possition == 2) && (menu.level_no < 22))
                    {
                       menu.level_no += 1;
                       if (menu.level_no > 22) menu.level_no = 22;
                       play_sound(0);
                    }
                    menu.possition++;
                    if (menu.possition > 2) menu.possition = 2;
                    else play_sound(0);
                 }
                 if (menu.level == 3)//customize starship
                 {
                    switch (menu.possition)
                    {
                       case 0://front weapon select
                       if ((game.projectile[game.player.front_weapon+1].active) && (game.player.front_weapon < 6)) game.player.front_weapon++;
                       if (game.player.front_weapon > 5) game.player.front_weapon = 5;
                       break;
                       case 1://side weapon select
                       if ((game.projectile[game.player.side_weapon+1].active) && (game.player.side_weapon < 6)) game.player.side_weapon++;
                       if (game.player.side_weapon > 5) game.player.side_weapon = 5;
                       break;
                       case 2://shield select
                       if ((game.shield[game.player.front_shield+1].active) && (game.player.front_shield < 6)) game.player.front_shield++;
                       if (game.player.front_shield > 4) game.player.front_shield = 4;
                       break;
                       case 3://thrusters select
                       if ((game.thruster[game.player.thrusters+1].active) && (game.player.thrusters < 6)) game.player.thrusters++;
                       if (game.player.thrusters > 2) game.player.thrusters = 2;
                       break;
                    }
                 play_sound(0);
                 }
              }
        if ((game.io.select) && (game.io.keyboard_delay_count >= game.io.keyboard_delay))
              {
                 game.io.keyboard_delay_count = 0;
                 play_sound(1);
                 switch (menu.level)
                 {
                    case 0://main menu
                       switch (menu.possition)
                          {
                             case 0://new game
                                init_game();
                                menu.possition = 0;
                                menu.level = 1;
                                menu.possition_max = 6;
                                main_log.File_Write("Entering 'new game' menu.");
                             break;
                             case 1://resume game
                                if (game.game_resume)
                                {
                                   game.game_active = true;
                                   game.menu_active = false;
                                   main_log.File_Write("Resuming game.");
                                }
                             break;
                             case 2://load game
                                menu.possition = 0;
                                menu.level = 6;
                                menu.possition_max = 5;
                                main_log.File_Write("Entering 'load game' menu.");
                             break;
                             case 3://options
                                menu.possition = 0;
                                menu.level = 2;
                                menu.possition_max = 4;
                                main_log.File_Write("Entering 'options game' menu.");
                            break;
                             case 4://quit game
                                main_log.File_Write("User terminating game - via menu system.");
                                game.status_quit_active = true;
                             break;
                          }
                       break;
                    case 1://game menu
                       switch (menu.possition)
                          {
                             case 0://starmap
                                menu.possition = 0;
                                menu.level = 4;
                                menu.possition_max = 3;
                                main_log.File_Write("Entering 'star map' menu.");
                             break;
                             case 1://achievements
                                menu.possition = 0;
                                menu.level = 7;
                                menu.possition_max = 0;
                                main_log.File_Write("Entering 'Achievements' menu.");
                             break;
                             case 2://customize starship
                                menu.possition = 0;
                                menu.level = 3;
                                menu.possition_max = 4;
                                main_log.File_Write("Entering 'customize starship' menu.");
                             break;
                             case 3://resume game
                                if (game.game_resume)
                                {
                                   game.game_active = true;
                                   game.menu_active = false;
                                   main_log.File_Write("Resuming game.");
                                }
                             break;
                             case 4://save game
                                if (game.game_resume)
                                {
                                   menu.possition = 0;
                                   menu.level = 5;
                                   menu.possition_max = 5;
                                   main_log.File_Write("Entering 'save game' menu.");
                                }
                             break;
                             case 5://load game
                                menu.possition = 0;
                                menu.level = 6;
                                menu.possition_max = 5;
                                main_log.File_Write("Entering 'load game' menu.");
                             break;
                             case 6://main menu
                                menu.possition = 0;
                                menu.level = 0;
                                menu.possition_max = 4;
                                main_log.File_Write("Entering 'main' menu.");
                             break;
                          }
                       break;
                    case 2: // options menu
                       switch (menu.possition)
                          {
                             case 0://sound volume
                             break;
                             case 1://music volume
                             break;
                             case 2://full screen
                             break;
                             case 3://resolution
                             break;
                             case 4://main menu
                                menu.possition = 0;
                                menu.level = 0;
                                menu.possition_max = 4;
                                main_log.File_Write("Entering 'main' menu.");
                             break;
                          }
                       break;
                    case 3: // customize starship menu
                       switch (menu.possition)
                          {
                             case 0:
                             break;
                             case 1:
                             break;
                             case 2:
                             break;
                             case 3:
                             break;
                             case 4://game menu
                                menu.possition = 2;
                                menu.level = 1;
                                menu.possition_max = 6;
                                main_log.File_Write("Entering 'game' menu.");
                             break;
                          }
                       break;
                    case 4: // star map menu
                       switch (menu.possition)
                          {
                             case 0://level x+0 select
                                if (!game.level_locked[menu.level_no + 0])
                                {
                                   game.level = menu.level_no + 0;
                                   init_game_level(game.level);
                                   game.game_active = true;
                                   game.menu_active = false;
                                   main_log.File_Write("Starting level ");
                                }
                             break;
                             case 1://level x+1 select
                                if (!game.level_locked[menu.level_no + 1])
                                {
                                   game.level = menu.level_no + 1;
                                   init_game_level(game.level);
                                   game.game_active = true;
                                   game.menu_active = false;
                                   main_log.File_Write("Starting level ");
                                }
                             break;
                             case 2://level x+2 select
                                if (!game.level_locked[menu.level_no + 2])
                                {
                                   game.level = menu.level_no + 2;
                                   init_game_level(game.level);
                                   game.game_active = true;
                                   game.menu_active = false;
                                   main_log.File_Write("Starting level ");
                                }
                             break;
                             case 3://game menu
                                menu.possition = 0;
                                menu.level = 1;
                                menu.possition_max = 6;
                                main_log.File_Write("Entering 'game' menu.");
                             break;
                          }
                        break;
                    case 5: // save game menu
                       switch (menu.possition)
                          {
                             case 0://save to slot 0
                                Save_Game(0);
                                main_log.File_Write("Saving to slot 0");
                                spawn_saved();
                                menu.possition = 3;
                                menu.level = 1;
                                menu.possition_max = 5;
                                game.game_active = true;
                                game.menu_active = false;
                                main_log.File_Write("Resuming game");
                             break;
                             case 1://save to slot 1
                                Save_Game(1);
                                main_log.File_Write("Saving to slot 1");
                                spawn_saved();
                                menu.possition = 3;
                                menu.level = 1;
                                menu.possition_max = 5;
                                game.game_active = true;
                                game.menu_active = false;
                                main_log.File_Write("Resuming game");
                             break;
                             case 2://save to slot 2
                                Save_Game(2);
                                main_log.File_Write("Saving to slot 2");
                                spawn_saved();
                                menu.possition = 3;
                                menu.level = 1;
                                menu.possition_max = 5;
                                game.game_active = true;
                                game.menu_active = false;
                                main_log.File_Write("Resuming game");
                             break;
                             case 3://save to slot 3
                                Save_Game(3);
                                main_log.File_Write("Saving to slot 3");
                                spawn_saved();
                                menu.possition = 3;
                                menu.level = 1;
                                menu.possition_max = 5;
                                game.game_active = true;
                                game.menu_active = false;
                                main_log.File_Write("Resuming game");
                             break;
                             case 4://save to slot 4
                                Save_Game(4);
                                main_log.File_Write("Saving to slot 4");
                                spawn_saved();
                                menu.possition = 3;
                                menu.level = 1;
                                menu.possition_max = 5;
                                game.game_active = true;
                                game.menu_active = false;
                                main_log.File_Write("Resuming game");
                             break;
                             case 5://game menu
                                menu.possition = 4;
                                menu.level = 1;
                                menu.possition_max = 6;
                                main_log.File_Write("Entering 'game' menu.");
                            break;
                          }
                       break;
                    case 6: // load game menu
                       switch (menu.possition)
                          {
                             case 0://load from slot 0
                                if (Load_Game(0) == 0)
                                {
                                   main_log.File_Write("Loading from slot 0");
                                   spawn_loaded();
                                   menu.possition = 3;
                                   menu.level = 1;
                                   menu.possition_max = 5;
                                   game.game_active = true;
                                   game.menu_active = false;
                                   main_log.File_Write("Resuming game");
                                }
                                else main_log.File_Write("Error loadng from slot 0");
                             break;
                             case 1://load from slot 1
                                if (Load_Game(1) == 0)
                                {
                                   main_log.File_Write("Loading from slot 1");
                                   spawn_loaded();
                                   menu.possition = 3;
                                   menu.level = 1;
                                   menu.possition_max = 5;
                                   game.game_active = true;
                                   game.menu_active = false;
                                   main_log.File_Write("Resuming game");
                                }
                                else main_log.File_Write("Error loadng from slot 1");
                             break;
                             case 2://load from slot 2
                                if (Load_Game(2) == 0)
                                {
                                   main_log.File_Write("Loading from slot 2");
                                   spawn_loaded();
                                   menu.possition = 3;
                                   menu.level = 1;
                                   menu.possition_max = 5;
                                   game.game_active = true;
                                   game.menu_active = false;
                                   main_log.File_Write("Resuming game");
                                }
                                else main_log.File_Write("Error loadng from slot 2");
                             break;
                             case 3://load from slot 3
                                if (Load_Game(3) == 0)
                                {
                                   main_log.File_Write("Loading from slot 3");
                                   spawn_loaded();
                                   menu.possition = 3;
                                   menu.level = 1;
                                   menu.possition_max = 5;
                                   game.game_active = true;
                                   game.menu_active = false;
                                   main_log.File_Write("Resuming game");
                                }
                                else main_log.File_Write("Error loadng from slot 3");
                             break;
                             case 4://load from slot 4
                                if (Load_Game(4) == 0)
                                {
                                   main_log.File_Write("Loading from slot 4");
                                   spawn_loaded();
                                   menu.possition = 3;
                                   menu.level = 1;
                                   menu.possition_max = 5;
                                   game.game_active = true;
                                   game.menu_active = false;
                                   main_log.File_Write("Resuming game");
                                }
                                else main_log.File_Write("Error loadng from slot 4");
                             break;
                             case 5://game menu
                                menu.possition = 5;
                                menu.level = 1;
                                menu.possition_max = 6;
                                main_log.File_Write("Entering 'game' menu.");
                             break;
                             default:
                             break;

                          }
                    case 7: // Achievements menu
                       switch (menu.possition)
                          {
                             case 0://game menu
                                menu.possition = 1;
                                menu.level = 1;
                                menu.possition_max = 6;
                                main_log.File_Write("Entering 'game' menu.");
                             break;
                          }
                       break;
                    default:
                       play_sound(1);
                 }
              }
   return(0);
};

int init_menu   (void)
{
   menu.level_no                          = 0;
   menu.possition                         = 0;
   menu.level                             = 0;
   menu.possition_max                     = 4;
   menu.recall_position                   = 0;
   menu.recall_view                       = 0;
   menu.background_scroll[0].x_dir        = 0;
   menu.background_scroll[0].y_dir        = 0;
   menu.background_scroll[0].x_pos        = 0.0f;
   menu.background_scroll[0].y_pos        = 0.0f;
   menu.background_scroll[0].scroll_rate  = 0.0005f;
   menu.background_scroll[1].x_dir        = 1;
   menu.background_scroll[1].y_dir        = 1;
   menu.background_scroll[1].x_pos        = 0.0f;
   menu.background_scroll[1].y_pos        = 0.0f;
   menu.background_scroll[1].scroll_rate  = 0.001f;
   return(0);
};

   //---------------------------------------------------------------------------------------
int diplay_menu (void)
{
    glPushMatrix();
    glDisable(GL_DEPTH_TEST);
/*-----------------------------------------------------------------------------*/
   if (menu.level == 0) //main_menu
   {
      glBindTexture( GL_TEXTURE_2D, texture[63].texture); //background 01
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-2.0f + menu.background_scroll[0].x_pos,-2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 0, 0 );glVertex3f(-2.0f + menu.background_scroll[0].x_pos, 2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 1, 0 );glVertex3f( 2.0f + menu.background_scroll[0].x_pos, 2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 1, 1 );glVertex3f( 2.0f + menu.background_scroll[0].x_pos,-2.0f + menu.background_scroll[0].y_pos, 0.15f );
      glEnd();

      glBindTexture( GL_TEXTURE_2D, texture[64].texture); //background 02
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-2.0f + menu.background_scroll[1].x_pos,-2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 0, 0 );glVertex3f(-2.0f + menu.background_scroll[1].x_pos, 2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 1, 0 );glVertex3f( 2.0f + menu.background_scroll[1].x_pos, 2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 1, 1 );glVertex3f( 2.0f + menu.background_scroll[1].x_pos,-2.0f + menu.background_scroll[1].y_pos, 0.1f );
      glEnd();

      glBindTexture( GL_TEXTURE_2D, texture[30].texture); //logo
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.9f, 0.75f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.9f, 1.0f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.9f, 1.0f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.9f, 0.75f, 0.0f );
      glEnd();

      if (menu.possition == 0) glBindTexture( GL_TEXTURE_2D, texture[36].texture); //new game highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[35].texture); //new game
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.4f, 0.4f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f, 0.6f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f, 0.6f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f, 0.4f, 0.0f );
      glEnd();

      if (menu.possition == 1) glBindTexture( GL_TEXTURE_2D, texture[50].texture); //resume game highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[49].texture); //resume game
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 1 );glVertex3f(-0.4f, 0.15f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f, 0.35f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f, 0.35f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f, 0.15f, 0.0f );
      glEnd();

      if (menu.possition == 2) glBindTexture( GL_TEXTURE_2D, texture[29].texture); //load game highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[28].texture); //load game
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 1 );glVertex3f(-0.4f,-0.1f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f, 0.1f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f, 0.1f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f,-0.1f, 0.0f );
      glEnd();

      if (menu.possition == 3) glBindTexture( GL_TEXTURE_2D, texture[44].texture); //options highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[43].texture); //options
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 1 );glVertex3f(-0.4f,-0.35f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f,-0.15f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f,-0.15f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f,-0.35f, 0.0f );
      glEnd();

      if (menu.possition == 4) glBindTexture( GL_TEXTURE_2D, texture[46].texture); //quit highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[45].texture); //quit
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.4f,-0.85f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f,-0.65f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f,-0.65f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f,-0.85f, 0.0f );
      glEnd();
   }
/*-----------------------------------------------------------------------------*/

   if (menu.level == 1) //game_menu
   {
      glBindTexture( GL_TEXTURE_2D, texture[63].texture); //background 01
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-2.0f + menu.background_scroll[0].x_pos,-2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 0, 0 );glVertex3f(-2.0f + menu.background_scroll[0].x_pos, 2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 1, 0 );glVertex3f( 2.0f + menu.background_scroll[0].x_pos, 2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 1, 1 );glVertex3f( 2.0f + menu.background_scroll[0].x_pos,-2.0f + menu.background_scroll[0].y_pos, 0.15f );
      glEnd();

      glBindTexture( GL_TEXTURE_2D, texture[64].texture); //background 02
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-2.0f + menu.background_scroll[1].x_pos,-2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 0, 0 );glVertex3f(-2.0f + menu.background_scroll[1].x_pos, 2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 1, 0 );glVertex3f( 2.0f + menu.background_scroll[1].x_pos, 2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 1, 1 );glVertex3f( 2.0f + menu.background_scroll[1].x_pos,-2.0f + menu.background_scroll[1].y_pos, 0.1f );
      glEnd();

      glBindTexture( GL_TEXTURE_2D, texture[27].texture); //logo - game menu
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.9f, 0.75f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.9f, 1.0f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.9f, 1.0f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.9f, 0.75f, 0.0f );
      glEnd();

      if (menu.possition == 0) glBindTexture( GL_TEXTURE_2D, texture[60].texture); //starmap highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[59].texture); //starmap
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.4f, 0.55f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f, 0.75f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f, 0.75f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f, 0.55f, 0.0f );
      glEnd();

      if (menu.possition == 1) glBindTexture( GL_TEXTURE_2D, texture[299].texture); //achievements highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[298].texture); //achievements
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.4f, 0.3f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f, 0.5f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f, 0.5f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f, 0.3f, 0.0f );
      glEnd();

      if (menu.possition == 2) glBindTexture( GL_TEXTURE_2D, texture[21].texture); //customize starship highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[20].texture); //customize starship
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 1 );glVertex3f(-0.4f, 0.05f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f, 0.25f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f, 0.25f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f, 0.05f, 0.0f );
      glEnd();

      if (menu.possition == 3) glBindTexture( GL_TEXTURE_2D, texture[50].texture); //resume game highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[49].texture); //resume game
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 1 );glVertex3f(-0.4f,-0.2f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f, 0.0f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f, 0.0f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f,-0.2f, 0.0f );
      glEnd();

      if (menu.possition == 4) glBindTexture( GL_TEXTURE_2D, texture[52].texture); //save game highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[51].texture); //save game
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 1 );glVertex3f(-0.4f,-0.45f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f,-0.25f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f,-0.25f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f,-0.45f, 0.0f );
      glEnd();

      if (menu.possition == 5) glBindTexture( GL_TEXTURE_2D, texture[29].texture); //load game highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[28].texture); //load game
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 1 );glVertex3f(-0.4f,-0.7f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f,-0.5f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f,-0.5f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f,-0.7f, 0.0f );
      glEnd();

      if (menu.possition == 6) glBindTexture( GL_TEXTURE_2D, texture[32].texture); //main menu highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[31].texture); //main menu
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.4f,-0.95f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f,-0.75f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f,-0.75f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f,-0.95f, 0.0f );
      glEnd();
   }
/*-----------------------------------------------------------------------------*/

   if (menu.level == 2) //options_menu
   {
      glBindTexture( GL_TEXTURE_2D, texture[63].texture); //background 01
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-2.0f + menu.background_scroll[0].x_pos,-2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 0, 0 );glVertex3f(-2.0f + menu.background_scroll[0].x_pos, 2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 1, 0 );glVertex3f( 2.0f + menu.background_scroll[0].x_pos, 2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 1, 1 );glVertex3f( 2.0f + menu.background_scroll[0].x_pos,-2.0f + menu.background_scroll[0].y_pos, 0.15f );
      glEnd();

      glBindTexture( GL_TEXTURE_2D, texture[64].texture); //background 02
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-2.0f + menu.background_scroll[1].x_pos,-2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 0, 0 );glVertex3f(-2.0f + menu.background_scroll[1].x_pos, 2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 1, 0 );glVertex3f( 2.0f + menu.background_scroll[1].x_pos, 2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 1, 1 );glVertex3f( 2.0f + menu.background_scroll[1].x_pos,-2.0f + menu.background_scroll[1].y_pos, 0.1f );
      glEnd();

      glBindTexture( GL_TEXTURE_2D, texture[44].texture); //logo
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.9f, 0.75f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.9f, 1.0f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.9f, 1.0f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.9f, 0.75f, 0.0f );
      glEnd();

      if (menu.possition == 0) glBindTexture( GL_TEXTURE_2D, texture[58].texture); //Sound Volume highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[57].texture); //Sound Volume
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.8f, 0.55f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.8f, 0.75f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.0f, 0.75f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.0f, 0.55f, 0.0f );
      glEnd();

      if (menu.possition == 0) glBindTexture( GL_TEXTURE_2D, texture[17].texture); //Sound Volume bar highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[16].texture); //Sound Volume bar
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f((config_data.Audio_Sound_Volume / 160.0f), 0.55f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f((config_data.Audio_Sound_Volume / 160.0f), 0.75f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.0f, 0.75f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.0f, 0.55f, 0.0f );
      glEnd();

      if (menu.possition == 1) glBindTexture( GL_TEXTURE_2D, texture[34].texture); //Music Volume highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[33].texture); //Music Volume
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 1 );glVertex3f(-0.8f, 0.30f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.8f, 0.50f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.0f, 0.50f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.0f, 0.30f, 0.0f );
      glEnd();

      if (menu.possition == 1) glBindTexture( GL_TEXTURE_2D, texture[17].texture); //Music Volume bar highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[16].texture); //Music Volume bar
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 1 );glVertex3f((config_data.Audio_Music_Volume / 160.0f), 0.30f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f((config_data.Audio_Music_Volume / 160.0f), 0.50f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.0f, 0.50f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.0f, 0.30f, 0.0f );
      glEnd();

      if (menu.possition == 2) glBindTexture( GL_TEXTURE_2D, texture[25].texture); //Fullscreen highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[24].texture); //Fullscreen
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 1 );glVertex3f(-0.8f, 0.05f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.8f, 0.25f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.0f, 0.25f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.0f, 0.05f, 0.0f );
      glEnd();

      if ((menu.possition == 2) && (config_data.Display_Fullscreen == false)) glBindTexture( GL_TEXTURE_2D, texture[38].texture); //Fullscreen off highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[37].texture); //Fullscreen off
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 1 );glVertex3f( 0.0f, 0.05f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.0f, 0.25f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f, 0.25f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f, 0.05f, 0.0f );
      glEnd();

      if ((menu.possition == 2) && (config_data.Display_Fullscreen == true)) glBindTexture( GL_TEXTURE_2D, texture[40].texture); //Fullscreen on highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[39].texture); //Fullscreen on
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 1 );glVertex3f( 0.4f, 0.05f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.4f, 0.25f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.8f, 0.25f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.8f, 0.05f, 0.0f );
      glEnd();

      if (menu.possition == 3) glBindTexture( GL_TEXTURE_2D, texture[48].texture); //Resolution highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[47].texture); //Resolution
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 1 );glVertex3f(-0.8f,-0.20f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.8f, 0.00f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.0f, 0.00f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.0f,-0.20f, 0.0f );
      glEnd();

      if ((menu.possition == 3) && (config_data.Display_resolution == 0)) glBindTexture( GL_TEXTURE_2D, texture[13].texture); //640x480 highlighted
      if ((menu.possition != 3) && (config_data.Display_resolution == 0)) glBindTexture( GL_TEXTURE_2D, texture[12].texture); //640x480 Resolution
      if ((menu.possition == 3) && (config_data.Display_resolution == 1)) glBindTexture( GL_TEXTURE_2D, texture[15].texture); //800x600 highlighted
      if ((menu.possition != 3) && (config_data.Display_resolution == 1)) glBindTexture( GL_TEXTURE_2D, texture[14].texture); //800x600 Resolution
      if ((menu.possition == 3) && (config_data.Display_resolution == 2)) glBindTexture( GL_TEXTURE_2D, texture[1].texture); //1024x768 highlighted
      if ((menu.possition != 3) && (config_data.Display_resolution == 2)) glBindTexture( GL_TEXTURE_2D, texture[0].texture); //1024x768 Resolution
      if ((menu.possition == 3) && (config_data.Display_resolution == 3)) glBindTexture( GL_TEXTURE_2D, texture[3].texture); //1280x1024 highlighted
      if ((menu.possition != 3) && (config_data.Display_resolution == 3)) glBindTexture( GL_TEXTURE_2D, texture[2].texture); //1280x1024 Resolution
      if ((menu.possition == 3) && (config_data.Display_resolution == 4)) glBindTexture( GL_TEXTURE_2D, texture[5].texture); //1366x768 highlighted
      if ((menu.possition != 3) && (config_data.Display_resolution == 4)) glBindTexture( GL_TEXTURE_2D, texture[4].texture); //1366x768 Resolution
      if ((menu.possition == 3) && (config_data.Display_resolution == 5)) glBindTexture( GL_TEXTURE_2D, texture[7].texture); //1440x900 highlighted
      if ((menu.possition != 3) && (config_data.Display_resolution == 5)) glBindTexture( GL_TEXTURE_2D, texture[6].texture); //1440x900 Resolution
      if ((menu.possition == 3) && (config_data.Display_resolution == 6)) glBindTexture( GL_TEXTURE_2D, texture[9].texture); //1680x1050 highlighted
      if ((menu.possition != 3) && (config_data.Display_resolution == 6)) glBindTexture( GL_TEXTURE_2D, texture[8].texture); //1680x1050 Resolution
      if ((menu.possition == 3) && (config_data.Display_resolution == 7)) glBindTexture( GL_TEXTURE_2D, texture[11].texture); //1920x1080 highlighted
      if ((menu.possition != 3) && (config_data.Display_resolution == 7)) glBindTexture( GL_TEXTURE_2D, texture[10].texture); //1920x1080 Resolution
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 1 );glVertex3f( 0.0f,-0.20f, 0.0f );
      glTexCoord2i( 0, 0 );glVertex3f( 0.0f, 0.00f, 0.0f );
      glTexCoord2i( 1, 0 );glVertex3f( 0.8f, 0.00f, 0.0f );
      glTexCoord2i( 1, 1 );glVertex3f( 0.8f,-0.20f, 0.0f );
      glEnd();

      if (menu.possition == 4) glBindTexture( GL_TEXTURE_2D, texture[32].texture); //main menu highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[31].texture); //main menu
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.4f,-0.95f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f,-0.75f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f,-0.75f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f,-0.95f, 0.0f );
      glEnd();
   }
/*-----------------------------------------------------------------------------*/

   if (menu.level == 3) //customize_starship_menu
   {
      float ship_pos_x =  0.0f;
      float ship_pos_y = -0.5f;

      glBindTexture( GL_TEXTURE_2D, texture[63].texture); //background 01
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-2.0f + menu.background_scroll[0].x_pos,-2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 0, 0 );glVertex3f(-2.0f + menu.background_scroll[0].x_pos, 2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 1, 0 );glVertex3f( 2.0f + menu.background_scroll[0].x_pos, 2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 1, 1 );glVertex3f( 2.0f + menu.background_scroll[0].x_pos,-2.0f + menu.background_scroll[0].y_pos, 0.15f );
      glEnd();

      glBindTexture( GL_TEXTURE_2D, texture[64].texture); //background 02
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-2.0f + menu.background_scroll[1].x_pos,-2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 0, 0 );glVertex3f(-2.0f + menu.background_scroll[1].x_pos, 2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 1, 0 );glVertex3f( 2.0f + menu.background_scroll[1].x_pos, 2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 1, 1 );glVertex3f( 2.0f + menu.background_scroll[1].x_pos,-2.0f + menu.background_scroll[1].y_pos, 0.1f );
      glEnd();

      glBindTexture( GL_TEXTURE_2D, texture[21].texture); //logo - customize startship menu
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.9f, 0.75f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.9f, 1.00f, 0.05f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.9f, 1.00f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.9f, 0.75f, 0.05f );
      glEnd();

      if (menu.possition == 0) glBindTexture( GL_TEXTURE_2D, texture[23].texture); //front weapon highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[22].texture); //front weapon
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-1.0f, 0.65f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f(-1.0f, 0.75f, 0.05f );
	  glTexCoord2i( 1, 0 );glVertex3f(-0.4f, 0.75f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f(-0.4f, 0.65f, 0.05f );
      glEnd();

      glBindTexture( GL_TEXTURE_2D, texture[283].texture); //weapon none
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f(-0.2f, 0.65f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f(-0.2f, 0.75f, 0.05f );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.3f, 0.75f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.3f, 0.65f, 0.05f );
      glEnd();

      if (game.player.front_weapon == -1)
      {
         glBindTexture( GL_TEXTURE_2D, texture[282].texture); //weapon none highlighted
         glLoadIdentity();
         glBegin( GL_QUADS );
	     glTexCoord2i( 1, 0 );glVertex3f(-0.2f, 0.65f, 0.04f );
	     glTexCoord2i( 1, 1 );glVertex3f(-0.2f, 0.75f, 0.04f );
	     glTexCoord2i( 0, 1 );glVertex3f(-0.3f, 0.75f, 0.04f );
	     glTexCoord2i( 0, 0 );glVertex3f(-0.3f, 0.65f, 0.04f );
         glEnd();
      }

      if (game.projectile[0].active) glBindTexture( GL_TEXTURE_2D, texture[game.projectile[0].image].texture); //weapon 0
      else glBindTexture( GL_TEXTURE_2D, texture[284].texture);
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f(-0.05f, 0.65f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f(-0.05f, 0.75f, 0.05f );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.15f, 0.75f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.15f, 0.65f, 0.05f );
      glEnd();

      if (game.player.front_weapon == 0)
      {
         glBindTexture( GL_TEXTURE_2D, texture[282].texture); //weapon 0 highlighted
         glLoadIdentity();
         glBegin( GL_QUADS );
	     glTexCoord2i( 1, 0 );glVertex3f(-0.05f, 0.65f, 0.04f );
	     glTexCoord2i( 1, 1 );glVertex3f(-0.05f, 0.75f, 0.04f );
   	     glTexCoord2i( 0, 1 );glVertex3f(-0.15f, 0.75f, 0.04f );
	     glTexCoord2i( 0, 0 );glVertex3f(-0.15f, 0.65f, 0.04f );
         glEnd();
      }

      if (game.projectile[1].active) glBindTexture( GL_TEXTURE_2D, texture[game.projectile[1].image].texture); //weapon 1
      else glBindTexture( GL_TEXTURE_2D, texture[284].texture);
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.10f, 0.65f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.10f, 0.75f, 0.05f );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.00f, 0.75f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.00f, 0.65f, 0.05f );
      glEnd();

      if (game.player.front_weapon == 1)
      {
         glBindTexture( GL_TEXTURE_2D, texture[282].texture); //weapon 1 highlighted
         glLoadIdentity();
         glBegin( GL_QUADS );
   	     glTexCoord2i( 1, 0 );glVertex3f( 0.10f, 0.65f, 0.04f );
	     glTexCoord2i( 1, 1 );glVertex3f( 0.10f, 0.75f, 0.04f );
	     glTexCoord2i( 0, 1 );glVertex3f( 0.00f, 0.75f, 0.04f );
	     glTexCoord2i( 0, 0 );glVertex3f( 0.00f, 0.65f, 0.04f );
         glEnd();
      }

      if (game.projectile[2].active) glBindTexture( GL_TEXTURE_2D, texture[game.projectile[2].image].texture); //weapon 2
      else glBindTexture( GL_TEXTURE_2D, texture[284].texture);
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.25f, 0.65f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.25f, 0.75f, 0.05f );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.15f, 0.75f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.15f, 0.65f, 0.05f );
      glEnd();

      if (game.player.front_weapon == 2)
      {
         glBindTexture( GL_TEXTURE_2D, texture[282].texture); //weapon 2 highlighted
         glLoadIdentity();
         glBegin( GL_QUADS );
	     glTexCoord2i( 1, 0 );glVertex3f( 0.25f, 0.65f, 0.04f );
	     glTexCoord2i( 1, 1 );glVertex3f( 0.25f, 0.75f, 0.04f );
	     glTexCoord2i( 0, 1 );glVertex3f( 0.15f, 0.75f, 0.04f );
	     glTexCoord2i( 0, 0 );glVertex3f( 0.15f, 0.65f, 0.04f );
         glEnd();
      }

      if (game.projectile[3].active) glBindTexture( GL_TEXTURE_2D, texture[game.projectile[3].image].texture); //weapon 3
      else glBindTexture( GL_TEXTURE_2D, texture[284].texture);
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.40f, 0.65f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.40f, 0.75f, 0.05f );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.30f, 0.75f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.30f, 0.65f, 0.05f );
      glEnd();

      if (game.player.front_weapon == 3)
      {
         glBindTexture( GL_TEXTURE_2D, texture[282].texture); //weapon 3 highlighted
         glLoadIdentity();
         glBegin( GL_QUADS );
	     glTexCoord2i( 1, 0 );glVertex3f( 0.40f, 0.65f, 0.04f );
	     glTexCoord2i( 1, 1 );glVertex3f( 0.40f, 0.75f, 0.04f );
	     glTexCoord2i( 0, 1 );glVertex3f( 0.30f, 0.75f, 0.04f );
	     glTexCoord2i( 0, 0 );glVertex3f( 0.30f, 0.65f, 0.04f );
         glEnd();
      }

      if (game.projectile[4].active) glBindTexture( GL_TEXTURE_2D, texture[game.projectile[4].image].texture); //weapon 4
      else glBindTexture( GL_TEXTURE_2D, texture[284].texture);
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.55f, 0.65f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.55f, 0.75f, 0.05f );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.45f, 0.75f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.45f, 0.65f, 0.05f );
      glEnd();

      if (game.player.front_weapon == 4)
      {
         glBindTexture( GL_TEXTURE_2D, texture[282].texture); //weapon 4 highlighted
         glLoadIdentity();
         glBegin( GL_QUADS );
	     glTexCoord2i( 1, 0 );glVertex3f( 0.55f, 0.65f, 0.04f );
	     glTexCoord2i( 1, 1 );glVertex3f( 0.55f, 0.75f, 0.04f );
	     glTexCoord2i( 0, 1 );glVertex3f( 0.45f, 0.75f, 0.04f );
	     glTexCoord2i( 0, 0 );glVertex3f( 0.45f, 0.65f, 0.04f );
         glEnd();
      }

      if (game.projectile[5].active) glBindTexture( GL_TEXTURE_2D, texture[game.projectile[5].image].texture); //weapon 5
      else glBindTexture( GL_TEXTURE_2D, texture[284].texture);
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.70f, 0.65f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.70f, 0.75f, 0.05f );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.60f, 0.75f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.60f, 0.65f, 0.05f );
      glEnd();

      if (game.player.front_weapon == 5)
      {
         glBindTexture( GL_TEXTURE_2D, texture[282].texture); //weapon 5 highlighted
         glLoadIdentity();
         glBegin( GL_QUADS );
	     glTexCoord2i( 1, 0 );glVertex3f( 0.70f, 0.65f, 0.04f );
	     glTexCoord2i( 1, 1 );glVertex3f( 0.70f, 0.75f, 0.04f );
	     glTexCoord2i( 0, 1 );glVertex3f( 0.60f, 0.75f, 0.04f );
	     glTexCoord2i( 0, 0 );glVertex3f( 0.60f, 0.65f, 0.04f );
         glEnd();
      }

      if (menu.possition == 1) glBindTexture( GL_TEXTURE_2D, texture[56].texture); //side weapon highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[55].texture); //side weapon
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-1.0f, 0.50f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f(-1.0f, 0.60f, 0.05f );
	  glTexCoord2i( 1, 0 );glVertex3f(-0.4f, 0.60f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f(-0.4f, 0.50f, 0.05f );
      glEnd();

      glBindTexture( GL_TEXTURE_2D, texture[283].texture); //weapon none
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f(-0.2f, 0.50f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f(-0.2f, 0.60f, 0.05f );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.3f, 0.60f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.3f, 0.50f, 0.05f );
      glEnd();

      if (game.player.side_weapon == -1)
      {
         glBindTexture( GL_TEXTURE_2D, texture[282].texture); //weapon none highlighted
         glLoadIdentity();
         glBegin( GL_QUADS );
	     glTexCoord2i( 1, 0 );glVertex3f(-0.2f, 0.50f, 0.04f );
	     glTexCoord2i( 1, 1 );glVertex3f(-0.2f, 0.60f, 0.04f );
	     glTexCoord2i( 0, 1 );glVertex3f(-0.3f, 0.60f, 0.04f );
	     glTexCoord2i( 0, 0 );glVertex3f(-0.3f, 0.50f, 0.04f );
         glEnd();
      }

      if (game.projectile[0].active) glBindTexture( GL_TEXTURE_2D, texture[game.projectile[0].image].texture); //weapon 0
      else glBindTexture( GL_TEXTURE_2D, texture[284].texture);
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f(-0.05f, 0.50f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f(-0.05f, 0.60f, 0.05f );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.15f, 0.60f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.15f, 0.50f, 0.05f );
      glEnd();

      if (game.player.side_weapon == 0)
      {
         glBindTexture( GL_TEXTURE_2D, texture[282].texture); //weapon 0 highlighted
         glLoadIdentity();
         glBegin( GL_QUADS );
	     glTexCoord2i( 1, 0 );glVertex3f(-0.05f, 0.50f, 0.04f );
	     glTexCoord2i( 1, 1 );glVertex3f(-0.05f, 0.60f, 0.04f );
	     glTexCoord2i( 0, 1 );glVertex3f(-0.15f, 0.60f, 0.04f );
	     glTexCoord2i( 0, 0 );glVertex3f(-0.15f, 0.50f, 0.04f );
         glEnd();
      }

      if (game.projectile[1].active) glBindTexture( GL_TEXTURE_2D, texture[game.projectile[1].image].texture); //weapon 1
      else glBindTexture( GL_TEXTURE_2D, texture[284].texture);
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.10f, 0.50f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.10f, 0.60f, 0.05f );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.00f, 0.60f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.00f, 0.50f, 0.05f );
      glEnd();

      if (game.player.side_weapon == 1)
      {
         glBindTexture( GL_TEXTURE_2D, texture[282].texture); //weapon 1 highlighted
         glLoadIdentity();
         glBegin( GL_QUADS );
	     glTexCoord2i( 1, 0 );glVertex3f( 0.10f, 0.50f, 0.04f );
	     glTexCoord2i( 1, 1 );glVertex3f( 0.10f, 0.60f, 0.04f );
	     glTexCoord2i( 0, 1 );glVertex3f( 0.00f, 0.60f, 0.04f );
	     glTexCoord2i( 0, 0 );glVertex3f( 0.00f, 0.50f, 0.04f );
         glEnd();
      }

      if (game.projectile[2].active) glBindTexture( GL_TEXTURE_2D, texture[game.projectile[2].image].texture); //weapon 2
      else glBindTexture( GL_TEXTURE_2D, texture[284].texture);
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.25f, 0.50f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.25f, 0.60f, 0.05f );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.15f, 0.60f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.15f, 0.50f, 0.05f );
      glEnd();

      if (game.player.side_weapon == 2)
      {
         glBindTexture( GL_TEXTURE_2D, texture[282].texture); //weapon 2 highlighted
         glLoadIdentity();
         glBegin( GL_QUADS );
	     glTexCoord2i( 1, 0 );glVertex3f( 0.25f, 0.50f, 0.04f );
	     glTexCoord2i( 1, 1 );glVertex3f( 0.25f, 0.60f, 0.04f );
	     glTexCoord2i( 0, 1 );glVertex3f( 0.15f, 0.60f, 0.04f );
	     glTexCoord2i( 0, 0 );glVertex3f( 0.15f, 0.50f, 0.04f );
         glEnd();
      }

      if (game.projectile[3].active) glBindTexture( GL_TEXTURE_2D, texture[game.projectile[3].image].texture); //weapon 3
      else glBindTexture( GL_TEXTURE_2D, texture[284].texture);
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.40f, 0.50f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.40f, 0.60f, 0.05f );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.30f, 0.60f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.30f, 0.50f, 0.05f );
      glEnd();

      if (game.player.side_weapon == 3)
      {
         glBindTexture( GL_TEXTURE_2D, texture[282].texture); //weapon 3 highlighted
         glLoadIdentity();
         glBegin( GL_QUADS );
	     glTexCoord2i( 1, 0 );glVertex3f( 0.40f, 0.50f, 0.04f );
	     glTexCoord2i( 1, 1 );glVertex3f( 0.40f, 0.60f, 0.04f );
	     glTexCoord2i( 0, 1 );glVertex3f( 0.30f, 0.60f, 0.04f );
	     glTexCoord2i( 0, 0 );glVertex3f( 0.30f, 0.50f, 0.04f );
         glEnd();
      }

      if (game.projectile[4].active) glBindTexture( GL_TEXTURE_2D, texture[game.projectile[4].image].texture); //weapon 4
      else glBindTexture( GL_TEXTURE_2D, texture[284].texture);
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.55f, 0.50f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.55f, 0.60f, 0.05f );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.45f, 0.60f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.45f, 0.50f, 0.05f );
      glEnd();

      if (game.player.side_weapon == 4)
      {
         glBindTexture( GL_TEXTURE_2D, texture[282].texture); //weapon 4 highlighted
         glLoadIdentity();
         glBegin( GL_QUADS );
	     glTexCoord2i( 1, 0 );glVertex3f( 0.55f, 0.50f, 0.04f );
	     glTexCoord2i( 1, 1 );glVertex3f( 0.55f, 0.60f, 0.04f );
	     glTexCoord2i( 0, 1 );glVertex3f( 0.45f, 0.60f, 0.04f );
	     glTexCoord2i( 0, 0 );glVertex3f( 0.45f, 0.50f, 0.04f );
         glEnd();
      }

      if (game.projectile[5].active) glBindTexture( GL_TEXTURE_2D, texture[game.projectile[5].image].texture); //weapon 5
      else glBindTexture( GL_TEXTURE_2D, texture[284].texture);
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.70f, 0.50f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.70f, 0.60f, 0.05f );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.60f, 0.60f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.60f, 0.50f, 0.05f );
      glEnd();

      if (game.player.side_weapon == 5)
      {
         glBindTexture( GL_TEXTURE_2D, texture[282].texture); //weapon 5 highlighted
         glLoadIdentity();
         glBegin( GL_QUADS );
	     glTexCoord2i( 1, 0 );glVertex3f( 0.70f, 0.50f, 0.04f );
	     glTexCoord2i( 1, 1 );glVertex3f( 0.70f, 0.60f, 0.04f );
	     glTexCoord2i( 0, 1 );glVertex3f( 0.60f, 0.60f, 0.04f );
	     glTexCoord2i( 0, 0 );glVertex3f( 0.60f, 0.50f, 0.04f );
         glEnd();
      }

      if (menu.possition == 2) glBindTexture( GL_TEXTURE_2D, texture[54].texture); //shield highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[53].texture); //shield
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-1.0f, 0.35f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f(-1.0f, 0.45f, 0.05f );
	  glTexCoord2i( 1, 0 );glVertex3f(-0.4f, 0.45f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f(-0.4f, 0.35f, 0.05f );
      glEnd();

      glBindTexture( GL_TEXTURE_2D, texture[283].texture); //shield none
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f(-0.2f, 0.35f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f(-0.2f, 0.45f, 0.05f );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.3f, 0.45f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.3f, 0.35f, 0.05f );
      glEnd();

      if (game.player.front_shield == -1)
      {
         glBindTexture( GL_TEXTURE_2D, texture[282].texture); //shield none highlighted
         glLoadIdentity();
         glBegin( GL_QUADS );
	     glTexCoord2i( 1, 0 );glVertex3f(-0.2f, 0.35f, 0.04f );
	     glTexCoord2i( 1, 1 );glVertex3f(-0.2f, 0.45f, 0.04f );
	     glTexCoord2i( 0, 1 );glVertex3f(-0.3f, 0.45f, 0.04f );
	     glTexCoord2i( 0, 0 );glVertex3f(-0.3f, 0.35f, 0.04f );
         glEnd();
      }

      if (game.shield[0].active) glBindTexture( GL_TEXTURE_2D, texture[game.shield[0].image].texture); //shield 0
      else glBindTexture( GL_TEXTURE_2D, texture[284].texture);
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f(-0.05f, 0.35f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f(-0.05f, 0.45f, 0.05f );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.15f, 0.45f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.15f, 0.35f, 0.05f );
      glEnd();

      if (game.player.front_shield == 0)
      {
         glBindTexture( GL_TEXTURE_2D, texture[282].texture); //shield 0 highlighted
         glLoadIdentity();
         glBegin( GL_QUADS );
	     glTexCoord2i( 1, 0 );glVertex3f(-0.05f, 0.35f, 0.04f );
	     glTexCoord2i( 1, 1 );glVertex3f(-0.05f, 0.45f, 0.04f );
	     glTexCoord2i( 0, 1 );glVertex3f(-0.15f, 0.45f, 0.04f );
	     glTexCoord2i( 0, 0 );glVertex3f(-0.15f, 0.35f, 0.04f );
         glEnd();
      }

      if (game.shield[1].active) glBindTexture( GL_TEXTURE_2D, texture[game.shield[1].image].texture); //shield 1
      else glBindTexture( GL_TEXTURE_2D, texture[284].texture);
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.10f, 0.35f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.10f, 0.45f, 0.05f );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.00f, 0.45f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.00f, 0.35f, 0.05f );
      glEnd();

      if (game.player.front_shield == 1)
      {
         glBindTexture( GL_TEXTURE_2D, texture[282].texture); //shield 1 highlighted
         glLoadIdentity();
         glBegin( GL_QUADS );
	     glTexCoord2i( 1, 0 );glVertex3f( 0.10f, 0.35f, 0.04f );
	     glTexCoord2i( 1, 1 );glVertex3f( 0.10f, 0.45f, 0.04f );
	     glTexCoord2i( 0, 1 );glVertex3f( 0.00f, 0.45f, 0.04f );
	     glTexCoord2i( 0, 0 );glVertex3f( 0.00f, 0.35f, 0.04f );
         glEnd();
      }

      if (game.shield[2].active) glBindTexture( GL_TEXTURE_2D, texture[game.shield[2].image].texture); //shield 2
      else glBindTexture( GL_TEXTURE_2D, texture[284].texture);
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.25f, 0.35f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.25f, 0.45f, 0.05f );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.15f, 0.45f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.15f, 0.35f, 0.05f );
      glEnd();

      if (game.player.front_shield == 2)
      {
         glBindTexture( GL_TEXTURE_2D, texture[282].texture); //shield 2 highlighted
         glLoadIdentity();
         glBegin( GL_QUADS );
         glTexCoord2i( 1, 0 );glVertex3f( 0.25f, 0.35f, 0.04f );
         glTexCoord2i( 1, 1 );glVertex3f( 0.25f, 0.45f, 0.04f );
         glTexCoord2i( 0, 1 );glVertex3f( 0.15f, 0.45f, 0.04f );
         glTexCoord2i( 0, 0 );glVertex3f( 0.15f, 0.35f, 0.04f );
         glEnd();
      }

      if (game.shield[3].active) glBindTexture( GL_TEXTURE_2D, texture[game.shield[3].image].texture); //shield 3
      else glBindTexture( GL_TEXTURE_2D, texture[284].texture);
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.40f, 0.35f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.40f, 0.45f, 0.05f );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.30f, 0.45f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.30f, 0.35f, 0.05f );
      glEnd();

      if (game.player.front_shield == 3)
      {
         glBindTexture( GL_TEXTURE_2D, texture[282].texture); //shield 3 highlighted
         glLoadIdentity();
         glBegin( GL_QUADS );
	     glTexCoord2i( 1, 0 );glVertex3f( 0.40f, 0.35f, 0.04f );
	     glTexCoord2i( 1, 1 );glVertex3f( 0.40f, 0.45f, 0.04f );
	     glTexCoord2i( 0, 1 );glVertex3f( 0.30f, 0.45f, 0.04f );
 	     glTexCoord2i( 0, 0 );glVertex3f( 0.30f, 0.35f, 0.04f );
         glEnd();
      }

      if (game.shield[4].active) glBindTexture( GL_TEXTURE_2D, texture[game.shield[4].image].texture); //shield 4
      else glBindTexture( GL_TEXTURE_2D, texture[284].texture);
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.55f, 0.35f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.55f, 0.45f, 0.05f );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.45f, 0.45f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.45f, 0.35f, 0.05f );
      glEnd();

      if (game.player.front_shield == 4)
      {
         glBindTexture( GL_TEXTURE_2D, texture[282].texture); //shield 4 highlighted
         glLoadIdentity();
         glBegin( GL_QUADS );
	     glTexCoord2i( 1, 0 );glVertex3f( 0.55f, 0.35f, 0.04f );
	     glTexCoord2i( 1, 1 );glVertex3f( 0.55f, 0.45f, 0.04f );
	     glTexCoord2i( 0, 1 );glVertex3f( 0.45f, 0.45f, 0.04f );
	     glTexCoord2i( 0, 0 );glVertex3f( 0.45f, 0.35f, 0.04f );
         glEnd();
      }

      if (menu.possition == 3) glBindTexture( GL_TEXTURE_2D, texture[62].texture); //thrusters highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[61].texture); //thrusters
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-1.0f, 0.20f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f(-1.0f, 0.30f, 0.05f );
	  glTexCoord2i( 1, 0 );glVertex3f(-0.4f, 0.30f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f(-0.4f, 0.20f, 0.05f );
      glEnd();

      glBindTexture( GL_TEXTURE_2D, texture[283].texture); //thrusters none
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f(-0.2f, 0.20f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f(-0.2f, 0.30f, 0.05f );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.3f, 0.30f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.3f, 0.20f, 0.05f );
      glEnd();

      if (game.player.thrusters == -1)
      {
         glBindTexture( GL_TEXTURE_2D, texture[282].texture); //thrusters none highlighted
         glLoadIdentity();
         glBegin( GL_QUADS );
	     glTexCoord2i( 1, 0 );glVertex3f(-0.2f, 0.20f, 0.04f );
	     glTexCoord2i( 1, 1 );glVertex3f(-0.2f, 0.30f, 0.04f );
	     glTexCoord2i( 0, 1 );glVertex3f(-0.3f, 0.30f, 0.04f );
	     glTexCoord2i( 0, 0 );glVertex3f(-0.3f, 0.20f, 0.04f );
         glEnd();
      }

      if (game.thruster[0].active) glBindTexture( GL_TEXTURE_2D, texture[game.thruster[0].image].texture); //thrusters 0
      else glBindTexture( GL_TEXTURE_2D, texture[284].texture);
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f(-0.05f, 0.20f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f(-0.05f, 0.30f, 0.05f );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.15f, 0.30f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.15f, 0.20f, 0.05f );
      glEnd();

      if (game.player.thrusters == 0)
      {
         glBindTexture( GL_TEXTURE_2D, texture[282].texture); //thrusters 0 highlighted
         glLoadIdentity();
         glBegin( GL_QUADS );
	     glTexCoord2i( 0, 0 );glVertex3f(-0.05f, 0.20f, 0.04f );
	     glTexCoord2i( 1, 0 );glVertex3f(-0.05f, 0.30f, 0.04f );
	     glTexCoord2i( 1, 1 );glVertex3f(-0.15f, 0.30f, 0.04f );
	     glTexCoord2i( 0, 1 );glVertex3f(-0.15f, 0.20f, 0.04f );
         glEnd();
      }

      if (game.thruster[1].active) glBindTexture( GL_TEXTURE_2D, texture[game.thruster[1].image].texture); //thrusters 1
      else glBindTexture( GL_TEXTURE_2D, texture[284].texture);
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.10f, 0.20f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.10f, 0.30f, 0.05f );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.00f, 0.30f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.00f, 0.20f, 0.05f );
      glEnd();

      if (game.player.thrusters == 1)
      {
         glBindTexture( GL_TEXTURE_2D, texture[282].texture); //thrusters 1 highlighted
         glLoadIdentity();
         glBegin( GL_QUADS );
	     glTexCoord2i( 0, 0 );glVertex3f( 0.10f, 0.20f, 0.04f );
	     glTexCoord2i( 1, 0 );glVertex3f( 0.10f, 0.30f, 0.04f );
	     glTexCoord2i( 1, 1 );glVertex3f( 0.00f, 0.30f, 0.04f );
	     glTexCoord2i( 0, 1 );glVertex3f( 0.00f, 0.20f, 0.04f );
         glEnd();
      }

      if (game.thruster[2].active) glBindTexture( GL_TEXTURE_2D, texture[game.thruster[2].image].texture); //thrusters 2
      else glBindTexture( GL_TEXTURE_2D, texture[284].texture);
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.251f, 0.20f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.251f, 0.30f, 0.05f );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.151f, 0.30f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.151f, 0.20f, 0.05f );
      glEnd();

      if (game.player.thrusters == 2)
      {
         glBindTexture( GL_TEXTURE_2D, texture[282].texture); //thrusters 2 highlighted
         glLoadIdentity();
         glBegin( GL_QUADS );
	     glTexCoord2i( 0, 0 );glVertex3f( 0.25f, 0.20f, 0.04f );
	     glTexCoord2i( 1, 0 );glVertex3f( 0.25f, 0.30f, 0.04f );
	     glTexCoord2i( 1, 1 );glVertex3f( 0.15f, 0.30f, 0.04f );
	     glTexCoord2i( 0, 1 );glVertex3f( 0.15f, 0.20f, 0.04f );
         glEnd();
      }

      if (game.player.thrusters > -1)
      {
         glBindTexture( GL_TEXTURE_2D, texture[game.thruster[game.player.thrusters].image].texture); //player starship thrusters
         glLoadIdentity();
         glBegin( GL_QUADS );
         glTexCoord2i( 0, 0 );glVertex3f(ship_pos_x+(game.player.width)-0.379f,ship_pos_y-(game.player.hight), 0.035f );
         glTexCoord2i( 1, 0 );glVertex3f(ship_pos_x+(game.player.width)-0.379f,ship_pos_y+(game.player.hight), 0.035f );
         glTexCoord2i( 1, 1 );glVertex3f(ship_pos_x-(game.player.width)-0.379f,ship_pos_y+(game.player.hight), 0.035f );
         glTexCoord2i( 0, 1 );glVertex3f(ship_pos_x-(game.player.width)-0.379f,ship_pos_y-(game.player.hight), 0.035f );
         glEnd();
      }

      glBindTexture( GL_TEXTURE_2D, texture[game.player.image].texture); //player starship
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 0 );glVertex3f(ship_pos_x+(game.player.width),ship_pos_y-(game.player.hight), 0.03f );
      glTexCoord2i( 1, 0 );glVertex3f(ship_pos_x+(game.player.width),ship_pos_y+(game.player.hight), 0.03f );
      glTexCoord2i( 1, 1 );glVertex3f(ship_pos_x-(game.player.width),ship_pos_y+(game.player.hight), 0.03f );
      glTexCoord2i( 0, 1 );glVertex3f(ship_pos_x-(game.player.width),ship_pos_y-(game.player.hight), 0.03f );
      glEnd();

      if (game.player.front_weapon > -1)
      {
         glBindTexture( GL_TEXTURE_2D, texture[game.player.front_weapon+211].texture); //player starship front weapon
         glLoadIdentity();
         glBegin( GL_QUADS );
         glTexCoord2i( 0, 0 );glVertex3f(ship_pos_x+(game.player.width/6)+0.134f,ship_pos_y-(game.player.hight/4), 0.025f );
         glTexCoord2i( 1, 0 );glVertex3f(ship_pos_x+(game.player.width/6)+0.134f,ship_pos_y+(game.player.hight/4), 0.025f );
         glTexCoord2i( 1, 1 );glVertex3f(ship_pos_x-(game.player.width/6)+0.150f,ship_pos_y+(game.player.hight/4), 0.025f );
         glTexCoord2i( 0, 1 );glVertex3f(ship_pos_x-(game.player.width/6)+0.150f,ship_pos_y-(game.player.hight/4), 0.025f );
         glEnd();
      }

      if (game.player.side_weapon > -1)
      {
         glBindTexture( GL_TEXTURE_2D, texture[game.player.side_weapon+211].texture); //player starship side weapons
         glLoadIdentity();
         glBegin( GL_QUADS );
         glTexCoord2i( 0, 0 );glVertex3f(ship_pos_x+(game.player.width/3)+0.124f,ship_pos_y-(game.player.hight/3)+0.150f, 0.025f );
         glTexCoord2i( 1, 0 );glVertex3f(ship_pos_x+(game.player.width/3)+0.124f,ship_pos_y+(game.player.hight/3)+0.150f, 0.025f );
         glTexCoord2i( 1, 1 );glVertex3f(ship_pos_x-(game.player.width/3)+0.134f,ship_pos_y+(game.player.hight/3)+0.150f, 0.025f );
         glTexCoord2i( 0, 1 );glVertex3f(ship_pos_x-(game.player.width/3)+0.134f,ship_pos_y-(game.player.hight/3)+0.150f, 0.025f );
         glEnd();
         glBegin( GL_QUADS );
         glTexCoord2i( 0, 0 );glVertex3f(ship_pos_x+(game.player.width/3)+0.134f,ship_pos_y-(game.player.hight/3)-0.150f, 0.025f );
         glTexCoord2i( 1, 0 );glVertex3f(ship_pos_x+(game.player.width/3)+0.134f,ship_pos_y+(game.player.hight/3)-0.150f, 0.025f );
         glTexCoord2i( 1, 1 );glVertex3f(ship_pos_x-(game.player.width/3)+0.134f,ship_pos_y+(game.player.hight/3)-0.150f, 0.025f );
         glTexCoord2i( 0, 1 );glVertex3f(ship_pos_x-(game.player.width/3)+0.134f,ship_pos_y-(game.player.hight/3)-0.150f, 0.025f );
         glEnd();
      }

      if (game.player.front_shield > -1)
      {
         glBindTexture( GL_TEXTURE_2D, texture[game.shield[game.player.front_shield].image].texture); //player starship shield
         glLoadIdentity();
         glBegin( GL_QUADS );
         glTexCoord2i( 1, 0 );glVertex3f(ship_pos_x+(game.player.width*1.5),ship_pos_y-(game.player.hight*1.5), 0.02f );
         glTexCoord2i( 1, 1 );glVertex3f(ship_pos_x+(game.player.width*1.5),ship_pos_y+(game.player.hight*1.5), 0.02f );
         glTexCoord2i( 0, 1 );glVertex3f(ship_pos_x-(game.player.width*1.5),ship_pos_y+(game.player.hight*1.5), 0.02f );
         glTexCoord2i( 0, 0 );glVertex3f(ship_pos_x-(game.player.width*1.5),ship_pos_y-(game.player.hight*1.5), 0.02f );
         glEnd();
      }

      if (menu.possition == 4) glBindTexture( GL_TEXTURE_2D, texture[27].texture); //game menu highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[26].texture); //game menu
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.4f,-1.0f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f,-0.8f, 0.05f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f,-0.8f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f,-1.0f, 0.05f );
      glEnd();

      if ((menu.possition == 0) && (game.player.front_weapon >= 0)) //front weapon
      {
          font_print(128,128,192,-1.0f,-0.000f,game.projectile[game.player.front_weapon].name,0.0f);
          font_print(128,128,192,-1.0f,-0.075f,"Level            - %1.0f", game.projectile[game.player.front_weapon].level);
          font_print(128,128,192,-1.0f,-0.150f,"Experience  - %1.0f", game.projectile[game.player.front_weapon].experience);
          if (game.projectile[game.player.front_weapon].level == 0) font_print(128,128,192,-1.0f,-0.225f,"Next level    - %1.0f", game.projectile[game.player.front_weapon].level_1);
          if (game.projectile[game.player.front_weapon].level == 1) font_print(128,128,192,-1.0f,-0.225f,"Next level    - %1.0f", game.projectile[game.player.front_weapon].level_2);
          if (game.projectile[game.player.front_weapon].level == 2) font_print(128,128,192,-1.0f,-0.225f,"Next level    - %1.0f", game.projectile[game.player.front_weapon].level_3);
          if (game.projectile[game.player.front_weapon].level >= 3) font_print(128,128,192,-1.0f,-0.225f,"Next level    - Max", 0.0f);
          font_print(128,128,192,-1.0f,-0.300f,"Damage       - %1.0f", game.projectile[game.player.front_weapon].damage);
          font_print(128,128,192,-1.0f,-0.375f,"Speed          - %1.0f", game.projectile[game.player.front_weapon].speed);
          font_print(128,128,192,-1.0f,-0.450f,"Health         - %1.0f", game.projectile[game.player.front_weapon].health);
          font_print(128,128,192,-1.0f,-0.525f,"Rate of Fire - %1.0f", game.projectile[game.player.front_weapon].rate_of_fire);
      }
      if ((menu.possition == 1) && (game.player.side_weapon >= 0)) //side weapon
      {
          font_print(128,128,192,-1.0f,-0.000f,game.projectile[game.player.side_weapon].name,0.0f);
          font_print(128,128,192,-1.0f,-0.075f,"Level            - %1.0f", game.projectile[game.player.side_weapon].level);
          font_print(128,128,192,-1.0f,-0.150f,"Experience  - %1.0f", game.projectile[game.player.side_weapon].experience);
          if (game.projectile[game.player.side_weapon].level == 0) font_print(128,128,192,-1.0f,-0.225f,"Next level    - %1.0f", game.projectile[game.player.side_weapon].level_1);
          if (game.projectile[game.player.side_weapon].level == 1) font_print(128,128,192,-1.0f,-0.225f,"Next level    - %1.0f", game.projectile[game.player.side_weapon].level_2);
          if (game.projectile[game.player.side_weapon].level == 2) font_print(128,128,192,-1.0f,-0.225f,"Next level    - %1.0f", game.projectile[game.player.side_weapon].level_3);
          if (game.projectile[game.player.side_weapon].level >= 3) font_print(128,128,192,-1.0f,-0.225f,"Next level    - Max", 0.0f);
          font_print(128,128,192,-1.0f,-0.300f,"Damage       - %1.0f", game.projectile[game.player.side_weapon].damage);
          font_print(128,128,192,-1.0f,-0.375f,"Speed          - %1.0f", game.projectile[game.player.side_weapon].speed);
          font_print(128,128,192,-1.0f,-0.450f,"Health         - %1.0f", game.projectile[game.player.side_weapon].health);
          font_print(128,128,192,-1.0f,-0.525f,"Rate of Fire - %1.0f", game.projectile[game.player.side_weapon].rate_of_fire);
      }
      if ((menu.possition == 2) && (game.player.front_shield >= 0)) //front shield
      {
          font_print(128,128,192,-1.0f,-0.000f,game.shield[game.player.front_shield].name,0.0f);
          font_print(128,128,192,-1.0f,-0.075f,"Level            - %1.0f", game.shield[game.player.front_shield].level);
          font_print(128,128,192,-1.0f,-0.150f,"Experience  - %1.0f", game.shield[game.player.front_shield].experience);
          if (game.shield[game.player.front_shield].level == 0) font_print(128,128,192,-1.0f,-0.225f,"Next level    - %1.0f", game.shield[game.player.front_shield].level_1);
          if (game.shield[game.player.front_shield].level == 1) font_print(128,128,192,-1.0f,-0.225f,"Next level    - %1.0f", game.shield[game.player.front_shield].level_2);
          if (game.shield[game.player.front_shield].level == 2) font_print(128,128,192,-1.0f,-0.225f,"Next level    - %1.0f", game.shield[game.player.front_shield].level_3);
          if (game.shield[game.player.front_shield].level >= 3) font_print(128,128,192,-1.0f,-0.225f,"Next level    - Max", 0.0f);
          font_print(128,128,192,-1.0f,-0.300f,"Absorption   - %1.0f", (10000*(game.shield[game.player.front_shield].absorption+(0.0001f*game.shield[game.player.front_shield].level))));
      }
      if ((menu.possition == 3) && (game.player.thrusters >= 0)) //thrusters
      {
          font_print(128,128,192,-1.0f,-0.00f,game.thruster[game.player.thrusters].name,0.0f);
          font_print(128,128,192,-1.0f,-0.075f,"Level            - %1.0f", game.thruster[game.player.thrusters].level);
          font_print(128,128,192,-1.0f,-0.150f,"Experience  - %1.0f", game.thruster[game.player.thrusters].experience);
          if (game.thruster[game.player.thrusters].level == 0) font_print(128,128,192,-1.0f,-0.225f,"Next level    - %1.0f", game.thruster[game.player.thrusters].level_1);
          if (game.thruster[game.player.thrusters].level == 1) font_print(128,128,192,-1.0f,-0.225f,"Next level    - %1.0f", game.thruster[game.player.thrusters].level_2);
          if (game.thruster[game.player.thrusters].level == 2) font_print(128,128,192,-1.0f,-0.225f,"Next level    - %1.0f", game.thruster[game.player.thrusters].level_3);
          if (game.thruster[game.player.thrusters].level >= 3) font_print(128,128,192,-1.0f,-0.225f,"Next level    - Max", 0.0f);
          font_print(128,128,192,-1.0f,-0.300f,"Thrust          - %1.0f", (10000*(game.thruster[game.player.thrusters].thrust+(0.0001f*game.thruster[game.player.thrusters].level))));
      }
   }
/*-----------------------------------------------------------------------------*/

   if (menu.level == 4) //starmap_menu
   {
      glBindTexture( GL_TEXTURE_2D, texture[63].texture); //background 01
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-2.0f + menu.background_scroll[0].x_pos,-2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 0, 0 );glVertex3f(-2.0f + menu.background_scroll[0].x_pos, 2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 1, 0 );glVertex3f( 2.0f + menu.background_scroll[0].x_pos, 2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 1, 1 );glVertex3f( 2.0f + menu.background_scroll[0].x_pos,-2.0f + menu.background_scroll[0].y_pos, 0.15f );
      glEnd();

      glBindTexture( GL_TEXTURE_2D, texture[64].texture); //background 02
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-2.0f + menu.background_scroll[1].x_pos,-2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 0, 0 );glVertex3f(-2.0f + menu.background_scroll[1].x_pos, 2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 1, 0 );glVertex3f( 2.0f + menu.background_scroll[1].x_pos, 2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 1, 1 );glVertex3f( 2.0f + menu.background_scroll[1].x_pos,-2.0f + menu.background_scroll[1].y_pos, 0.1f );
      glEnd();

      glBindTexture( GL_TEXTURE_2D, texture[60].texture); //logo - star map menu
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.9f, 0.75f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.9f, 1.0f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.9f, 1.0f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.9f, 0.75f, 0.0f );
      glEnd();

      if (menu.possition == 0) glBindTexture( GL_TEXTURE_2D, texture[122+menu.level_no].texture); //level choice 0 highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[97+menu.level_no].texture); //level choice 0
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.95f, 0.4f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.95f, 0.6f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f(-0.35f, 0.6f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f(-0.35f, 0.4f, 0.0f );
      glEnd();

      if (game.level_locked[menu.level_no]) glBindTexture( GL_TEXTURE_2D, texture[172].texture); //level choice 0 game screen preview
      else glBindTexture( GL_TEXTURE_2D, texture[147+menu.level_no].texture); //level choice 0 game screen preview
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f(-0.35f, 0.3f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f(-0.35f,-0.3f, 0.0f );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.95f,-0.3f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.95f, 0.3f, 0.0f );
      glEnd();

      if (menu.possition == 1) glBindTexture( GL_TEXTURE_2D, texture[123+menu.level_no].texture); //level choice 1 highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[98+menu.level_no].texture); //level choice 1
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.3f, 0.4f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.3f, 0.6f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.3f, 0.6f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.3f, 0.4f, 0.0f );
      glEnd();

      if (game.level_locked[menu.level_no+1]) glBindTexture( GL_TEXTURE_2D, texture[172].texture); //level choice 1 game screen preview
      else glBindTexture( GL_TEXTURE_2D, texture[148+menu.level_no].texture); //level choice 1 game screen preview
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.30f, 0.3f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.30f,-0.3f, 0.0f );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.30f,-0.3f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.30f, 0.3f, 0.0f );
      glEnd();

      if (menu.possition == 2) glBindTexture( GL_TEXTURE_2D, texture[124+menu.level_no].texture); //level choice 2 highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[99+menu.level_no].texture); //level choice 2
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.35f, 0.4f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.35f, 0.6f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.95f, 0.6f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.95f, 0.4f, 0.0f );
      glEnd();

      if (game.level_locked[menu.level_no+2]) glBindTexture( GL_TEXTURE_2D, texture[172].texture); //level choice 2 game screen preview
      else glBindTexture( GL_TEXTURE_2D, texture[149+menu.level_no].texture); //level choice 2 game screen preview
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.95f, 0.3f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.95f,-0.3f, 0.0f );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.35f,-0.3f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.35f, 0.3f, 0.0f );
      glEnd();

      if (menu.possition == 3) glBindTexture( GL_TEXTURE_2D, texture[27].texture); //game menu highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[26].texture); //game menu
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.4f,-0.85f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f,-0.65f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f,-0.65f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f,-0.85f, 0.0f );
      glEnd();
   }

/*-----------------------------------------------------------------------------*/
   if (menu.level == 5) //Save Game
   {
      glBindTexture( GL_TEXTURE_2D, texture[63].texture); //background 01
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-2.0f + menu.background_scroll[0].x_pos,-2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 0, 0 );glVertex3f(-2.0f + menu.background_scroll[0].x_pos, 2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 1, 0 );glVertex3f( 2.0f + menu.background_scroll[0].x_pos, 2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 1, 1 );glVertex3f( 2.0f + menu.background_scroll[0].x_pos,-2.0f + menu.background_scroll[0].y_pos, 0.15f );
      glEnd();

      glBindTexture( GL_TEXTURE_2D, texture[64].texture); //background 02
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-2.0f + menu.background_scroll[1].x_pos,-2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 0, 0 );glVertex3f(-2.0f + menu.background_scroll[1].x_pos, 2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 1, 0 );glVertex3f( 2.0f + menu.background_scroll[1].x_pos, 2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 1, 1 );glVertex3f( 2.0f + menu.background_scroll[1].x_pos,-2.0f + menu.background_scroll[1].y_pos, 0.1f );
      glEnd();

      glBindTexture( GL_TEXTURE_2D, texture[52].texture); //logo - save game menu
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.9f, 0.75f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.9f, 1.0f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.9f, 1.0f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.9f, 0.75f, 0.0f );
      glEnd();

      if (menu.possition == 0) glBindTexture( GL_TEXTURE_2D, texture[179].texture); //game 0 highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[173].texture); //game 0
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.4f, 0.4f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f, 0.6f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f, 0.6f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f, 0.4f, 0.0f );
      glEnd();

      if (menu.possition == 1) glBindTexture( GL_TEXTURE_2D, texture[180].texture); //game 1 highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[174].texture); //game 1
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 1 );glVertex3f(-0.4f, 0.15f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f, 0.35f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f, 0.35f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f, 0.15f, 0.0f );
      glEnd();

      if (menu.possition == 2) glBindTexture( GL_TEXTURE_2D, texture[181].texture); //game 2 highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[175].texture); //game 2
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 1 );glVertex3f(-0.4f,-0.1f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f, 0.1f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f, 0.1f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f,-0.1f, 0.0f );
      glEnd();

      if (menu.possition == 3) glBindTexture( GL_TEXTURE_2D, texture[182].texture); //game 3 highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[176].texture); //game 3
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 1 );glVertex3f(-0.4f,-0.35f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f,-0.15f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f,-0.15f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f,-0.35f, 0.0f );
      glEnd();

      if (menu.possition == 4) glBindTexture( GL_TEXTURE_2D, texture[183].texture); //game 4 highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[177].texture); //game 4
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 1 );glVertex3f(-0.4f,-0.6f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f,-0.4f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f,-0.4f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f,-0.6f, 0.0f );
      glEnd();

      if (menu.possition == 5) glBindTexture( GL_TEXTURE_2D, texture[27].texture); //game menu highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[26].texture); //game menu
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.4f,-0.85f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f,-0.65f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f,-0.65f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f,-0.85f, 0.0f );
      glEnd();
   }

/*-----------------------------------------------------------------------------*/
   if (menu.level == 6) //Load Game
   {
      glBindTexture( GL_TEXTURE_2D, texture[63].texture); //background 01
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-2.0f + menu.background_scroll[0].x_pos,-2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 0, 0 );glVertex3f(-2.0f + menu.background_scroll[0].x_pos, 2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 1, 0 );glVertex3f( 2.0f + menu.background_scroll[0].x_pos, 2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 1, 1 );glVertex3f( 2.0f + menu.background_scroll[0].x_pos,-2.0f + menu.background_scroll[0].y_pos, 0.15f );
      glEnd();

      glBindTexture( GL_TEXTURE_2D, texture[64].texture); //background 02
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-2.0f + menu.background_scroll[1].x_pos,-2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 0, 0 );glVertex3f(-2.0f + menu.background_scroll[1].x_pos, 2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 1, 0 );glVertex3f( 2.0f + menu.background_scroll[1].x_pos, 2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 1, 1 );glVertex3f( 2.0f + menu.background_scroll[1].x_pos,-2.0f + menu.background_scroll[1].y_pos, 0.1f );
      glEnd();

      glBindTexture( GL_TEXTURE_2D, texture[29].texture); //logo - load game menu
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.9f, 0.75f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.9f, 1.0f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.9f, 1.0f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.9f, 0.75f, 0.0f );
      glEnd();

      if (menu.possition == 0) glBindTexture( GL_TEXTURE_2D, texture[179].texture); //game 0 highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[173].texture); //game 0
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.4f, 0.4f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f, 0.6f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f, 0.6f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f, 0.4f, 0.0f );
      glEnd();

      if (menu.possition == 1) glBindTexture( GL_TEXTURE_2D, texture[180].texture); //game 1 highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[174].texture); //game 1
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 1 );glVertex3f(-0.4f, 0.15f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f, 0.35f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f, 0.35f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f, 0.15f, 0.0f );
      glEnd();

      if (menu.possition == 2) glBindTexture( GL_TEXTURE_2D, texture[181].texture); //game 2 highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[175].texture); //game 2
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 1 );glVertex3f(-0.4f,-0.1f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f, 0.1f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f, 0.1f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f,-0.1f, 0.0f );
      glEnd();

      if (menu.possition == 3) glBindTexture( GL_TEXTURE_2D, texture[182].texture); //game 3 highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[176].texture); //game 3
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 1 );glVertex3f(-0.4f,-0.35f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f,-0.15f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f,-0.15f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f,-0.35f, 0.0f );
      glEnd();

      if (menu.possition == 4) glBindTexture( GL_TEXTURE_2D, texture[183].texture); //game 4 highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[177].texture); //game 4
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 1 );glVertex3f(-0.4f,-0.6f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f,-0.4f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f,-0.4f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f,-0.6f, 0.0f );
      glEnd();

      if (menu.possition == 5) glBindTexture( GL_TEXTURE_2D, texture[27].texture); //game menu highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[26].texture); //game menu
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.4f,-0.85f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f,-0.65f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f,-0.65f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f,-0.85f, 0.0f );
      glEnd();
   }
/*-----------------------------------------------------------------------------*/
   if (menu.level == 7) //Achievements
   {
      glBindTexture( GL_TEXTURE_2D, texture[63].texture); //background 01
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-2.0f + menu.background_scroll[0].x_pos,-2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 0, 0 );glVertex3f(-2.0f + menu.background_scroll[0].x_pos, 2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 1, 0 );glVertex3f( 2.0f + menu.background_scroll[0].x_pos, 2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 1, 1 );glVertex3f( 2.0f + menu.background_scroll[0].x_pos,-2.0f + menu.background_scroll[0].y_pos, 0.15f );
      glEnd();

      glBindTexture( GL_TEXTURE_2D, texture[64].texture); //background 02
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-2.0f + menu.background_scroll[1].x_pos,-2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 0, 0 );glVertex3f(-2.0f + menu.background_scroll[1].x_pos, 2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 1, 0 );glVertex3f( 2.0f + menu.background_scroll[1].x_pos, 2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 1, 1 );glVertex3f( 2.0f + menu.background_scroll[1].x_pos,-2.0f + menu.background_scroll[1].y_pos, 0.1f );
      glEnd();

      glBindTexture( GL_TEXTURE_2D, texture[299].texture); //logo - Achievements
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.9f, 0.75f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.9f, 1.0f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.9f, 1.0f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.9f, 0.75f, 0.0f );
      glEnd();

      glBindTexture( GL_TEXTURE_2D, texture[301].texture); //score
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.95f, 0.55f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.95f, 0.75f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f(-0.25f, 0.75f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f(-0.25f, 0.55f, 0.0f );
      glEnd();

      if (game.achivement.score >= 1) glBindTexture( GL_TEXTURE_2D, texture[305].texture); //score - star 1 (bronze)
      else                            glBindTexture( GL_TEXTURE_2D, texture[304].texture); //score - star 1 (grey)
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.25f, 0.55f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.25f, 0.75f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f(-0.05f, 0.75f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f(-0.05f, 0.55f, 0.0f );
      glEnd();

      if (game.achivement.score >= 2) glBindTexture( GL_TEXTURE_2D, texture[306].texture); //score - star 2 (silver)
      else                            glBindTexture( GL_TEXTURE_2D, texture[304].texture); //score - star 2 (grey)
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.00f, 0.55f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.00f, 0.75f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.20f, 0.75f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.20f, 0.55f, 0.0f );
      glEnd();

      if (game.achivement.score >= 3) glBindTexture( GL_TEXTURE_2D, texture[307].texture); //score - star 3 (gold)
      else                            glBindTexture( GL_TEXTURE_2D, texture[304].texture); //score - star 3 (grey)
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.25f, 0.55f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.25f, 0.75f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.45f, 0.75f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.45f, 0.55f, 0.0f );
      glEnd();

      if (game.achivement.score >= 4) glBindTexture( GL_TEXTURE_2D, texture[307].texture); //score - star 4 (gold)
      else                            glBindTexture( GL_TEXTURE_2D, texture[304].texture); //score - star 4 (grey)
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.50f, 0.55f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.50f, 0.75f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.70f, 0.75f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.70f, 0.55f, 0.0f );
      glEnd();

      if (game.achivement.score >= 5) glBindTexture( GL_TEXTURE_2D, texture[307].texture); //score - star 5 (gold)
      else                            glBindTexture( GL_TEXTURE_2D, texture[304].texture); //score - star 5 (grey)
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.75f, 0.55f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.75f, 0.75f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.95f, 0.75f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.95f, 0.55f, 0.0f );
      glEnd();

      glBindTexture( GL_TEXTURE_2D, texture[303].texture); //kills
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.95f, 0.10f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.95f, 0.30f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f(-0.25f, 0.30f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f(-0.25f, 0.10f, 0.0f );
      glEnd();

      if (game.achivement.kills >= 1) glBindTexture( GL_TEXTURE_2D, texture[305].texture); //score - star 1 (bronze)
      else                            glBindTexture( GL_TEXTURE_2D, texture[304].texture); //score - star 1 (grey)
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.25f, 0.10f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.25f, 0.30f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f(-0.05f, 0.30f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f(-0.05f, 0.10f, 0.0f );
      glEnd();

      if (game.achivement.kills >= 2) glBindTexture( GL_TEXTURE_2D, texture[306].texture); //score - star 2 (silver)
      else                            glBindTexture( GL_TEXTURE_2D, texture[304].texture); //score - star 2 (grey)
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.00f, 0.10f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.00f, 0.30f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.20f, 0.30f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.20f, 0.10f, 0.0f );
      glEnd();

      if (game.achivement.kills >= 3) glBindTexture( GL_TEXTURE_2D, texture[307].texture); //score - star 3 (gold)
      else                            glBindTexture( GL_TEXTURE_2D, texture[304].texture); //score - star 3 (grey)
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.25f, 0.10f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.25f, 0.30f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.45f, 0.30f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.45f, 0.10f, 0.0f );
      glEnd();

      if (game.achivement.kills >= 4) glBindTexture( GL_TEXTURE_2D, texture[307].texture); //score - star 4 (gold)
      else                            glBindTexture( GL_TEXTURE_2D, texture[304].texture); //score - star 4 (grey)
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.50f, 0.10f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.50f, 0.30f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.70f, 0.30f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.70f, 0.10f, 0.0f );
      glEnd();

      if (game.achivement.kills >= 5) glBindTexture( GL_TEXTURE_2D, texture[307].texture); //score - star 5 (gold)
      else                            glBindTexture( GL_TEXTURE_2D, texture[304].texture); //score - star 5 (grey)
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.75f, 0.10f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.75f, 0.30f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.95f, 0.30f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.95f, 0.10f, 0.0f );
      glEnd();

      if (menu.possition == 0) glBindTexture( GL_TEXTURE_2D, texture[27].texture); //game menu highlighted
      else                     glBindTexture( GL_TEXTURE_2D, texture[26].texture); //game menu
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.4f,-0.95f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f,-0.75f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f,-0.75f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f,-0.95f, 0.0f );
      glEnd();
   }
/*-----------------------------------------------------------------------------*/
   if (menu.level == 8) //Player death screen
   {
      glBindTexture( GL_TEXTURE_2D, texture[84].texture); //background 01
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-2.0f + menu.background_scroll[0].x_pos,-2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 0, 0 );glVertex3f(-2.0f + menu.background_scroll[0].x_pos, 2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 1, 0 );glVertex3f( 2.0f + menu.background_scroll[0].x_pos, 2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 1, 1 );glVertex3f( 2.0f + menu.background_scroll[0].x_pos,-2.0f + menu.background_scroll[0].y_pos, 0.15f );
      glEnd();

      glBindTexture( GL_TEXTURE_2D, texture[73].texture); //background 02
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-2.0f + menu.background_scroll[1].x_pos,-2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 0, 0 );glVertex3f(-2.0f + menu.background_scroll[1].x_pos, 2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 1, 0 );glVertex3f( 2.0f + menu.background_scroll[1].x_pos, 2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 1, 1 );glVertex3f( 2.0f + menu.background_scroll[1].x_pos,-2.0f + menu.background_scroll[1].y_pos, 0.1f );
      glEnd();

      glBindTexture( GL_TEXTURE_2D, texture[330].texture); //logo
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.9f, 0.75f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.9f, 1.0f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.9f, 1.0f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.9f, 0.75f, 0.0f );
      glEnd();

      glBindTexture( GL_TEXTURE_2D, texture[329].texture); //Game Over
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.4f, 0.55f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f, 0.75f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f, 0.75f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f, 0.55f, 0.0f );
      glEnd();

      glBindTexture( GL_TEXTURE_2D, texture[332].texture); //explosion
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.6f,-0.70f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.6f, 0.50f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.6f, 0.50f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.6f,-0.70f, 0.0f );
      glEnd();

      glBindTexture( GL_TEXTURE_2D, texture[331].texture); //Press any key to return to the main menu
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.8f,-0.95f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.8f,-0.75f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.8f,-0.75f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.8f,-0.95f, 0.0f );
      glEnd();
   }
/*-----------------------------------------------------------------------------*/
   if (menu.level == 9) //Next level screen
   {
      int level_t = game.level + 1;
      if (level_t > 24) level_t = 24;
      glBindTexture( GL_TEXTURE_2D, texture[63].texture); //background 01
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-2.0f + menu.background_scroll[0].x_pos,-2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 0, 0 );glVertex3f(-2.0f + menu.background_scroll[0].x_pos, 2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 1, 0 );glVertex3f( 2.0f + menu.background_scroll[0].x_pos, 2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 1, 1 );glVertex3f( 2.0f + menu.background_scroll[0].x_pos,-2.0f + menu.background_scroll[0].y_pos, 0.15f );
      glEnd();

      glBindTexture( GL_TEXTURE_2D, texture[64].texture); //background 02
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-2.0f + menu.background_scroll[1].x_pos,-2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 0, 0 );glVertex3f(-2.0f + menu.background_scroll[1].x_pos, 2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 1, 0 );glVertex3f( 2.0f + menu.background_scroll[1].x_pos, 2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 1, 1 );glVertex3f( 2.0f + menu.background_scroll[1].x_pos,-2.0f + menu.background_scroll[1].y_pos, 0.1f );
      glEnd();

      glBindTexture( GL_TEXTURE_2D, texture[30].texture); //logo
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.9f, 0.75f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.9f, 1.0f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.9f, 1.0f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.9f, 0.75f, 0.0f );
      glEnd();

      glBindTexture( GL_TEXTURE_2D, texture[333].texture); //Congratulations
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.5f, 0.55f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.5f, 0.75f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.5f, 0.75f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.5f, 0.55f, 0.0f );
      glEnd();

      if (game.level_locked[level_t])
      {
         glBindTexture( GL_TEXTURE_2D, texture[335].texture); //level unlocked
         glLoadIdentity();
         glBegin( GL_QUADS );
	     glTexCoord2i( 0, 1 );glVertex3f(-0.5f, 0.35f, 0.0f );
	     glTexCoord2i( 0, 0 );glVertex3f(-0.5f, 0.55f, 0.0f );
	     glTexCoord2i( 1, 0 );glVertex3f( 0.5f, 0.55f, 0.0f );
   	     glTexCoord2i( 1, 1 );glVertex3f( 0.5f, 0.35f, 0.0f );
         glEnd();
      }

      glBindTexture( GL_TEXTURE_2D, texture[147+level_t].texture); //next level game screen preview
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.5f,-0.70f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.5f, 0.30f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.5f, 0.30f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.5f,-0.70f, 0.0f );
      glEnd();

      glBindTexture( GL_TEXTURE_2D, texture[334].texture); //Press any key to continue
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.8f,-0.95f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.8f,-0.75f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.8f,-0.75f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.8f,-0.95f, 0.0f );
      glEnd();

      font_print(128,128,192,-1.00f,-0.00f,"Level score - %1.0f", game.level_score);
      font_print(128,128,192,-1.00f,-0.10f,"Total score - %1.0f", game.score);
      font_print(128,128,192,-1.00f,-0.20f,"Level kills - %1.0f", game.level_kills);
      font_print(128,128,192,-1.00f,-0.30f,"Total kills - %1.0f", game.kills);
      font_print(128,128,192,-1.00f,-0.40f,"Kill rate   - %1.0f./'",(((float)game.level_kills/(float)game.level_spawened)*100));
   }
/*-----------------------------------------------------------------------------*/
   if (menu.level == 10) //Outro screen
   {
      int level_t = game.level + 1;
      if (level_t > 24) level_t = 24;
      glBindTexture( GL_TEXTURE_2D, texture[63].texture); //background 01
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-2.0f + menu.background_scroll[0].x_pos,-2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 0, 0 );glVertex3f(-2.0f + menu.background_scroll[0].x_pos, 2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 1, 0 );glVertex3f( 2.0f + menu.background_scroll[0].x_pos, 2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 1, 1 );glVertex3f( 2.0f + menu.background_scroll[0].x_pos,-2.0f + menu.background_scroll[0].y_pos, 0.15f );
      glEnd();

      glBindTexture( GL_TEXTURE_2D, texture[64].texture); //background 02
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-2.0f + menu.background_scroll[1].x_pos,-2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 0, 0 );glVertex3f(-2.0f + menu.background_scroll[1].x_pos, 2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 1, 0 );glVertex3f( 2.0f + menu.background_scroll[1].x_pos, 2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 1, 1 );glVertex3f( 2.0f + menu.background_scroll[1].x_pos,-2.0f + menu.background_scroll[1].y_pos, 0.1f );
      glEnd();

      glBindTexture( GL_TEXTURE_2D, texture[30].texture); //logo
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.9f, 0.75f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.9f, 1.0f,  0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.9f, 1.0f,  0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.9f, 0.75f, 0.0f );
      glEnd();

      glBindTexture( GL_TEXTURE_2D, texture[334].texture); //Press any key to continue
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.8f,-0.95f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.8f,-0.75f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.8f,-0.75f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.8f,-0.95f, 0.0f );
      glEnd();

      glBindTexture( GL_TEXTURE_2D, texture[339].texture); //credits
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-1.0f,-1.0f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-1.0f, 1.0f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 1.0f, 1.0f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 1.0f,-1.0f, 0.0f );
      glEnd();
   }
   glPopMatrix();
   return(0);
};
