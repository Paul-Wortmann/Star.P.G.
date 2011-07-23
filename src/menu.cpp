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

#include <GL/gl.h>
#include "menu.hpp"
#include "game.hpp"
#include "RAGE/rage.hpp"
#include "load_resources.hpp"
#include "levels.hpp"

extern  game_class               game;
extern  sound_type               sound;
extern  music_type               music;
extern  texture_type             texture;
extern  font_type                font;
extern  game_type                game_o;
extern  save_game_class          save_00;
extern  save_game_class          save_01;
extern  save_game_class          save_02;
extern  save_game_class          save_03;
extern  save_game_class          save_04;
extern  save_game_class          save_05;
        menu_type                menu;

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
        game_o.io.keyboard_delay_count++;
        if (game_o.io.keyboard_delay_count > game_o.io.keyboard_delay) game_o.io.keyboard_delay_count = game_o.io.keyboard_delay;
        if ((game_o.io.escape) && (game_o.io.keyboard_delay_count >= game_o.io.keyboard_delay))
              {
                 game_o.io.keyboard_delay_count = 0;
                 sound.menu_select.play();
                 switch (menu.level)
                 {
                    case 0://main menu
                       game_o.status_quit_active = true;
                       game.log.File_Write("User terminating game - used escape key!");
                    break;
                    case 1://game menu
                       menu.possition = 0;
                       menu.level = 0;
                       menu.possition_max = 4;
                       game.log.File_Write("Entering 'main' menu.");
                    break;
                    case 2: // options menu
                       menu.possition = 3;
                       menu.level = 0;
                       menu.possition_max = 4;
                       game.log.File_Write("Entering 'main' menu.");
                    break;
                    case 3: // customize starship menu
                       menu.possition = 2;
                       menu.level = 1;
                       menu.possition_max = 6;
                       game.log.File_Write("Entering 'new game' menu.");
                    break;
                    case 4: // star map menu
                       menu.possition = 0;
                       menu.level = 1;
                       menu.possition_max = 6;
                       game.log.File_Write("Entering 'new game' menu.");
                    break;
                    case 5: // save game menu
                       menu.possition = 4;
                       menu.level = 1;
                       menu.possition_max = 6;
                       game.log.File_Write("Entering 'new game' menu.");
                    break;
                    case 6: // load game menu
                       menu.possition = 5;
                       menu.level = 1;
                       menu.possition_max = 6;
                       game.log.File_Write("Entering 'new game' menu.");
                    break;
                    case 7: // Achievements menu
                       menu.possition = 1;
                       menu.level = 1;
                       menu.possition_max = 6;
                       game.log.File_Write("Entering 'new game' menu.");
                    break;
                    default:
                       game.log.File_Write("Undefined menu choice, quiting.");
                       game_o.status_quit_active = true;
                 }
              }
        if ((game_o.io.up) && (game_o.io.keyboard_delay_count >= game_o.io.keyboard_delay))
              {
                 game_o.io.keyboard_delay_count = 0;
                 if (menu.level == 0)//main menu
                 {
                 menu.possition--;
                 if (menu.possition < 0) menu.possition = 0;
                 else sound.menu_move.play();
                 }
                 if (menu.level == 1)//new game menu
                 {
                 menu.possition--;
                 if (menu.possition < 0) menu.possition = 0;
                 else sound.menu_move.play();
                 }
                 if (menu.level == 2)//options menu
                 {
                 menu.possition--;
                 if (menu.possition < 0) menu.possition = 0;
                 else sound.menu_move.play();
                 }
                 if (menu.level == 3)//customize starship menu
                 {
                 menu.possition--;
                 if (menu.possition < 0) menu.possition = 0;
                 else sound.menu_move.play();
                 }
                 if ((menu.level == 4) && (menu.possition == 3))//star map menu
                 {
                    menu.possition = menu.recall_position;
                    sound.menu_move.play();
                 }
                 if (menu.level == 5)//save game menu
                 {
                    menu.possition--;
                    if (menu.possition < 0) menu.possition = 0;
                    else sound.menu_move.play();
                 }
                 if (menu.level == 6)//load game menu
                 {
                 menu.possition--;
                 if (menu.possition < 0) menu.possition = 0;
                 else sound.menu_move.play();
                 }
                 if (menu.level == 7)//Achievements menu
                 {
                 menu.possition--;
                 if (menu.possition < 0) menu.possition = 0;
                 else sound.menu_move.play();
                 }
              }
        if ((game_o.io.down) && (game_o.io.keyboard_delay_count >= game_o.io.keyboard_delay))
              {
                 game_o.io.keyboard_delay_count = 0;
                 if (menu.level == 0)//main menu
                 {
                 menu.possition++;
                 if (menu.possition > menu.possition_max) menu.possition = menu.possition_max;
                 else sound.menu_move.play();
                 }
                 if (menu.level == 1)//new game menu
                 {
                 menu.possition++;
                 if (menu.possition > menu.possition_max) menu.possition = menu.possition_max;
                 else sound.menu_move.play();
                 }
                 if (menu.level == 2)//options menu
                 {
                 menu.possition++;
                 if (menu.possition > menu.possition_max) menu.possition = menu.possition_max;
                 else sound.menu_move.play();
                 }
                 if (menu.level == 3)//customize starship menu
                 {
                 menu.possition++;
                 if (menu.possition > menu.possition_max) menu.possition = menu.possition_max;
                 else sound.menu_move.play();
                 }
                 if ((menu.level == 4) && (menu.possition != 3))//star map menu
                 {
                    menu.recall_position = menu.possition;
                    menu.possition = 3;
                    sound.menu_move.play();
                 }
                 if (menu.level == 5)//save game menu
                 {
                 menu.possition++;
                 if (menu.possition > menu.possition_max) menu.possition = menu.possition_max;
                 else sound.menu_move.play();
                 }
                 if (menu.level == 6)//load menu
                 {
                 menu.possition++;
                 if (menu.possition > menu.possition_max) menu.possition = menu.possition_max;
                 else sound.menu_move.play();
                 }
                 if (menu.level == 7)//Achievements menu
                 {
                 menu.possition++;
                 if (menu.possition > menu.possition_max) menu.possition = menu.possition_max;
                 else sound.menu_move.play();
                 }
              }
        if (game_o.io.left)
            {
                 if ((menu.level == 2) and (menu.possition == 0))//decrease sound volume
              {
                 game.config.Audio_Sound_Volume--;
                 if (game.config.Audio_Sound_Volume < 0) game.config.Audio_Sound_Volume = 0;
                 Mix_Volume(-1,game.config.Audio_Sound_Volume);
              }
              if ((menu.level == 2) and (menu.possition == 1))//decrease music volume
              {
                 game.config.Audio_Music_Volume--;
                 if (game.config.Audio_Music_Volume < 0) game.config.Audio_Music_Volume = 0;
                 Mix_VolumeMusic(game.config.Audio_Music_Volume);
              }
            }
        if ((game_o.io.left) && (game_o.io.keyboard_delay_count >= game_o.io.keyboard_delay))
            {
                game_o.io.keyboard_delay_count = 0;
              if ((menu.level == 2) and (menu.possition == 2))//disable fullscreen
              {
                 if (game.config.Display_Fullscreen == true)
                 {
                    //kill_textures();
                    SDL_SetVideoMode(game.config.Display_X_Resolution,game.config.Display_Y_Resolution,game.config.Display_BPS,SDL_OPENGL);
                    game.graphics.init_gl(game.config.Display_X_Resolution,game.config.Display_Y_Resolution);
                    load_textures();
                    game.config.Display_Fullscreen   = false;
                  }
              }
                 if ((menu.level == 2) && (menu.possition == 3) && (game.config.Display_resolution != 0))//resolution select <
                 {
                    game.config.Display_resolution--;
                    if (game.config.Display_resolution < 0) game.config.Display_resolution = 0;
                    if (game.config.Display_resolution == 0)
                    {
                       game.config.Display_X_Resolution = 640;
                       game.config.Display_Y_Resolution = 480;
                    }
                    if (game.config.Display_resolution == 1)
                    {
                       game.config.Display_X_Resolution = 800;
                       game.config.Display_Y_Resolution = 600;
                    }
                    if (game.config.Display_resolution == 2)
                    {
                       game.config.Display_X_Resolution = 1024;
                       game.config.Display_Y_Resolution = 768;
                    }
                    if (game.config.Display_resolution == 3)
                    {
                       game.config.Display_X_Resolution = 1280;
                       game.config.Display_Y_Resolution = 1024;
                    }
                    if (game.config.Display_resolution == 4)
                    {
                       game.config.Display_X_Resolution = 1366;
                       game.config.Display_Y_Resolution = 768;
                    }
                    if (game.config.Display_resolution == 5)
                    {
                       game.config.Display_X_Resolution = 1440;
                       game.config.Display_Y_Resolution = 900;
                    }
                    if (game.config.Display_resolution == 6)
                    {
                       game.config.Display_X_Resolution = 1680;
                       game.config.Display_Y_Resolution = 1050;
                    }
                    if (game.config.Display_resolution == 7)
                    {
                       game.config.Display_X_Resolution = 1920;
                       game.config.Display_Y_Resolution = 1080;
                    }
                    game.config.mouse_resolution_x   = game.config.Display_X_Resolution;
                    game.config.mouse_resolution_y   = game.config.Display_Y_Resolution;
                    //kill_textures();
                    if (game.config.Display_Fullscreen == true ) SDL_SetVideoMode(game.config.Display_X_Resolution,game.config.Display_Y_Resolution,game.config.Display_BPS,SDL_OPENGL | SDL_FULLSCREEN);
                    if (game.config.Display_Fullscreen == false) SDL_SetVideoMode(game.config.Display_X_Resolution,game.config.Display_Y_Resolution,game.config.Display_BPS,SDL_OPENGL);
                    game.graphics.init_gl(game.config.Display_X_Resolution,game.config.Display_Y_Resolution);
                    load_textures();
                 }
                 if ((menu.level == 4) && (menu.possition < 3))//star map level select <
                 {
                    if ((menu.possition == 0) && (menu.level_no > 0))
                    {
                       menu.level_no -= 1;
                       if (menu.level_no < 0) menu.level_no = 0;
                       sound.menu_move.play();
                    }
                    menu.possition--;
                    if (menu.possition < 0) menu.possition = 0;
                    else sound.menu_move.play();
                 }
                 if (menu.level == 3)//customize starship
                 {
                    switch (menu.possition)
                    {
                       case 0://front weapon select
                       game_o.player.front_weapon--;
                       if (game_o.player.front_weapon < -1) game_o.player.front_weapon = -1;
                       break;
                       case 1://side weapon select
                       game_o.player.side_weapon--;
                       if (game_o.player.side_weapon < -1) game_o.player.side_weapon = -1;
                       break;
                       case 2://shield select
                       game_o.player.front_shield--;
                       if (game_o.player.front_shield < -1) game_o.player.front_shield = -1;
                       break;
                       case 3://thrusters select
                       game_o.player.thrusters--;
                       if (game_o.player.thrusters < -1) game_o.player.thrusters = -1;
                       break;
                    }
                 sound.menu_move.play();
                 }
              }
        if (game_o.io.right)
              {
                 if ((menu.level == 2) and (menu.possition == 0))//increase sound volume
                 {
                    game.config.Audio_Sound_Volume++;
                    if (game.config.Audio_Sound_Volume > 128) game.config.Audio_Sound_Volume = 128;
                    Mix_Volume(-1,game.config.Audio_Sound_Volume);
                 }
                 if ((menu.level == 2) and (menu.possition == 1))//increase music volume
                 {
                    game.config.Audio_Music_Volume++;
                    if (game.config.Audio_Music_Volume > 128) game.config.Audio_Music_Volume = 128;
                    Mix_VolumeMusic(game.config.Audio_Music_Volume);
                 }
              }
        if ((game_o.io.right) && (game_o.io.keyboard_delay_count >= game_o.io.keyboard_delay))
              {
                game_o.io.keyboard_delay_count = 0;
                 if ((menu.level == 2) and (menu.possition == 2))//enable fullscreen
                 {
                    if (game.config.Display_Fullscreen == false)
                    {
                       //kill_textures();
                       SDL_SetVideoMode(game.config.Display_X_Resolution,game.config.Display_Y_Resolution,game.config.Display_BPS,SDL_OPENGL | SDL_FULLSCREEN);
                       game.graphics.init_gl(game.config.Display_X_Resolution,game.config.Display_Y_Resolution);
                       load_textures();
                       game.config.Display_Fullscreen   = true;
                    }
                 }
                 if ((menu.level == 2) && (menu.possition == 3) && (game.config.Display_resolution != 7))//resolution select <
                 {
                    game.config.Display_resolution++;
                    if (game.config.Display_resolution > 7) game.config.Display_resolution = 7;
                    if (game.config.Display_resolution == 0)
                    {
                       game.config.Display_X_Resolution = 640;
                       game.config.Display_Y_Resolution = 480;
                    }
                    if (game.config.Display_resolution == 1)
                    {
                       game.config.Display_X_Resolution = 800;
                       game.config.Display_Y_Resolution = 600;
                    }
                    if (game.config.Display_resolution == 2)
                    {
                       game.config.Display_X_Resolution = 1024;
                       game.config.Display_Y_Resolution = 768;
                    }
                    if (game.config.Display_resolution == 3)
                    {
                       game.config.Display_X_Resolution = 1280;
                       game.config.Display_Y_Resolution = 1024;
                    }
                    if (game.config.Display_resolution == 4)
                    {
                       game.config.Display_X_Resolution = 1366;
                       game.config.Display_Y_Resolution = 768;
                    }
                    if (game.config.Display_resolution == 5)
                    {
                       game.config.Display_X_Resolution = 1440;
                       game.config.Display_Y_Resolution = 900;
                    }
                    if (game.config.Display_resolution == 6)
                    {
                       game.config.Display_X_Resolution = 1680;
                       game.config.Display_Y_Resolution = 1050;
                    }
                    if (game.config.Display_resolution == 7)
                    {
                       game.config.Display_X_Resolution = 1920;
                       game.config.Display_Y_Resolution = 1080;
                    }
                    game.config.mouse_resolution_x   = game.config.Display_X_Resolution;
                    game.config.mouse_resolution_y   = game.config.Display_Y_Resolution;
                    //kill_textures();
                    if (game.config.Display_Fullscreen == true ) SDL_SetVideoMode(game.config.Display_X_Resolution,game.config.Display_Y_Resolution,game.config.Display_BPS,SDL_OPENGL | SDL_FULLSCREEN);
                    if (game.config.Display_Fullscreen == false) SDL_SetVideoMode(game.config.Display_X_Resolution,game.config.Display_Y_Resolution,game.config.Display_BPS,SDL_OPENGL);
                    game.graphics.init_gl(game.config.Display_X_Resolution,game.config.Display_Y_Resolution);
                    load_textures();
                 }
                 if ((menu.level == 4) && (menu.possition < 3))//star map level select <
                 {
                    if ((menu.possition == 2) && (menu.level_no < 22))
                    {
                       menu.level_no += 1;
                       if (menu.level_no > 22) menu.level_no = 22;
                       sound.menu_move.play();
                    }
                    menu.possition++;
                    if (menu.possition > 2) menu.possition = 2;
                    else sound.menu_move.play();
                 }
                 if (menu.level == 3)//customize starship
                 {
                    switch (menu.possition)
                    {
                       case 0://front weapon select
                       if ((game_o.projectile[game_o.player.front_weapon+1].active) && (game_o.player.front_weapon < 6)) game_o.player.front_weapon++;
                       if (game_o.player.front_weapon > 5) game_o.player.front_weapon = 5;
                       break;
                       case 1://side weapon select
                       if ((game_o.projectile[game_o.player.side_weapon+1].active) && (game_o.player.side_weapon < 6)) game_o.player.side_weapon++;
                       if (game_o.player.side_weapon > 5) game_o.player.side_weapon = 5;
                       break;
                       case 2://shield select
                       if ((game_o.shield[game_o.player.front_shield+1].active) && (game_o.player.front_shield < 6)) game_o.player.front_shield++;
                       if (game_o.player.front_shield > 4) game_o.player.front_shield = 4;
                       break;
                       case 3://thrusters select
                       if ((game_o.thruster[game_o.player.thrusters+1].active) && (game_o.player.thrusters < 6)) game_o.player.thrusters++;
                       if (game_o.player.thrusters > 2) game_o.player.thrusters = 2;
                       break;
                    }
                 sound.menu_move.play();
                 }
              }
        if ((game_o.io.select) && (game_o.io.keyboard_delay_count >= game_o.io.keyboard_delay))
              {
                 game_o.io.keyboard_delay_count = 0;
                 sound.menu_select.play();
                 switch (menu.level)
                 {
                    case 0://main menu
                       switch (menu.possition)
                          {
                             case 0://new game
                                init_game();
                                game.music_next_track = true;
                                menu.possition = 0;
                                menu.level = 1;
                                menu.possition_max = 6;
                                game.log.File_Write("Entering 'new game' menu.");
                             break;
                             case 1://resume game
                                if (game_o.game_resume)
                                {
                                   game.music_next_track = true;
                                   game_o.game_active    = true;
                                   game_o.menu_active    = false;
                                   game.log.File_Write("Resuming game_o.");
                                }
                             break;
                             case 2://load game
                                menu.possition = 0;
                                menu.level = 6;
                                menu.possition_max = 5;
                                game.log.File_Write("Entering 'load game' menu.");
                             break;
                             case 3://options
                                menu.possition = 0;
                                menu.level = 2;
                                menu.possition_max = 4;
                                game.log.File_Write("Entering 'options game' menu.");
                            break;
                             case 4://quit game
                                game.log.File_Write("User terminating game - via menu system.");
                                game_o.status_quit_active = true;
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
                                game.log.File_Write("Entering 'star map' menu.");
                             break;
                             case 1://achievements
                                menu.possition = 0;
                                menu.level = 7;
                                menu.possition_max = 0;
                                game.log.File_Write("Entering 'Achievements' menu.");
                             break;
                             case 2://customize starship
                                menu.possition = 0;
                                menu.level = 3;
                                menu.possition_max = 4;
                                game.log.File_Write("Entering 'customize starship' menu.");
                             break;
                             case 3://resume game
                                if (game_o.game_resume)
                                {
                                   game.music_next_track = true;
                                   game_o.game_active    = true;
                                   game_o.menu_active    = false;
                                   game.log.File_Write("Resuming game_o.");
                                }
                             break;
                             case 4://save game
                                if (game_o.game_resume)
                                {
                                   menu.possition = 0;
                                   menu.level = 5;
                                   menu.possition_max = 5;
                                   game.log.File_Write("Entering 'save game' menu.");
                                }
                             break;
                             case 5://load game
                                menu.possition = 0;
                                menu.level = 6;
                                menu.possition_max = 5;
                                game.log.File_Write("Entering 'load game' menu.");
                             break;
                             case 6://main menu
                                menu.possition = 0;
                                menu.level = 0;
                                menu.possition_max = 4;
                                game.log.File_Write("Entering 'main' menu.");
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
                                game.log.File_Write("Entering 'main' menu.");
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
                                game.log.File_Write("Entering 'game' menu.");
                             break;
                          }
                       break;
                    case 4: // star map menu
                       switch (menu.possition)
                          {
                             case 0://level x+0 select
                                if (!game_o.level_locked[menu.level_no + 0])
                                {
                                   game.music_next_track = true;
                                   game_o.level = menu.level_no + 0;
                                   init_game_level(game_o.level);
                                   game_o.game_active = true;
                                   game_o.menu_active = false;
                                   game.log.File_Write("Starting level ");
                                }
                             break;
                             case 1://level x+1 select
                                if (!game_o.level_locked[menu.level_no + 1])
                                {
                                   game.music_next_track = true;
                                   game_o.level = menu.level_no + 1;
                                   init_game_level(game_o.level);
                                   game_o.game_active = true;
                                   game_o.menu_active = false;
                                   game.log.File_Write("Starting level ");
                                }
                             break;
                             case 2://level x+2 select
                                if (!game_o.level_locked[menu.level_no + 2])
                                {
                                   game.music_next_track = true;
                                   game_o.level = menu.level_no + 2;
                                   init_game_level(game_o.level);
                                   game_o.game_active = true;
                                   game_o.menu_active = false;
                                   game.log.File_Write("Starting level ");
                                }
                             break;
                             case 3://game menu
                                menu.possition = 0;
                                menu.level = 1;
                                menu.possition_max = 6;
                                game.log.File_Write("Entering 'game' menu.");
                             break;
                          }
                        break;
                    case 5: // save game menu
                       switch (menu.possition)
                          {
                             case 0://save to slot 0
                                save_00.Save();
                                game.log.File_Write("Saving to slot 0");
                                spawn_saved();
                                menu.possition = 3;
                                menu.level = 1;
                                menu.possition_max = 5;
                                game_o.game_active = true;
                                game_o.menu_active = false;
                                game.log.File_Write("Resuming game");
                                game.music_next_track = true;
                             break;
                             case 1://save to slot 1
                                save_01.Save();
                                game.log.File_Write("Saving to slot 1");
                                spawn_saved();
                                menu.possition = 3;
                                menu.level = 1;
                                menu.possition_max = 5;
                                game_o.game_active = true;
                                game_o.menu_active = false;
                                game.log.File_Write("Resuming game");
                                game.music_next_track = true;
                             break;
                             case 2://save to slot 2
                                save_02.Save();
                                game.log.File_Write("Saving to slot 2");
                                spawn_saved();
                                menu.possition = 3;
                                menu.level = 1;
                                menu.possition_max = 5;
                                game_o.game_active = true;
                                game_o.menu_active = false;
                                game.log.File_Write("Resuming game");
                                game.music_next_track = true;
                             break;
                             case 3://save to slot 3
                                save_03.Save();
                                game.log.File_Write("Saving to slot 3");
                                spawn_saved();
                                menu.possition = 3;
                                menu.level = 1;
                                menu.possition_max = 5;
                                game_o.game_active = true;
                                game_o.menu_active = false;
                                game.log.File_Write("Resuming game");
                                game.music_next_track = true;
                             break;
                             case 4://save to slot 4
                                save_04.Save();
                                game.log.File_Write("Saving to slot 4");
                                spawn_saved();
                                menu.possition = 3;
                                menu.level = 1;
                                menu.possition_max = 5;
                                game_o.game_active = true;
                                game_o.menu_active = false;
                                game.log.File_Write("Resuming game");
                                game.music_next_track = true;
                             break;
                             case 5://game menu
                                menu.possition = 4;
                                menu.level = 1;
                                menu.possition_max = 6;
                                game.log.File_Write("Entering 'game' menu.");
                            break;
                          }
                       break;
                    case 6: // load game menu
                       switch (menu.possition)
                          {
                             case 0://load from slot 0
                                if (save_00.Load())
                                {
                                   game.log.File_Write("Loading from slot 0");
                                   spawn_loaded();
                                   menu.possition = 3;
                                   menu.level = 1;
                                   menu.possition_max = 5;
                                   game_o.game_active = true;
                                   game_o.menu_active = false;
                                   game.log.File_Write("Resuming game");
                                   game.music_next_track = true;
                                }
                                else game.log.File_Write("Error loadng from slot 0");
                             break;
                             case 1://load from slot 1
                                if (save_01.Load())
                                {
                                   game.log.File_Write("Loading from slot 1");
                                   spawn_loaded();
                                   menu.possition = 3;
                                   menu.level = 1;
                                   menu.possition_max = 5;
                                   game_o.game_active = true;
                                   game_o.menu_active = false;
                                   game.log.File_Write("Resuming game");
                                   game.music_next_track = true;
                                }
                                else game.log.File_Write("Error loadng from slot 1");
                             break;
                             case 2://load from slot 2
                                if (save_02.Load())
                                {
                                   game.log.File_Write("Loading from slot 2");
                                   spawn_loaded();
                                   menu.possition = 3;
                                   menu.level = 1;
                                   menu.possition_max = 5;
                                   game_o.game_active = true;
                                   game_o.menu_active = false;
                                   game.log.File_Write("Resuming game");
                                   game.music_next_track = true;
                                }
                                else game.log.File_Write("Error loadng from slot 2");
                             break;
                             case 3://load from slot 3
                                if (save_03.Load())
                                {
                                   game.log.File_Write("Loading from slot 3");
                                   spawn_loaded();
                                   menu.possition = 3;
                                   menu.level = 1;
                                   menu.possition_max = 5;
                                   game_o.game_active = true;
                                   game_o.menu_active = false;
                                   game.log.File_Write("Resuming game");
                                   game.music_next_track = true;
                                }
                                else game.log.File_Write("Error loadng from slot 3");
                             break;
                             case 4://load from slot 4
                                if (save_04.Load())
                                {
                                   game.log.File_Write("Loading from slot 4");
                                   spawn_loaded();
                                   menu.possition = 3;
                                   menu.level = 1;
                                   menu.possition_max = 5;
                                   game_o.game_active = true;
                                   game_o.menu_active = false;
                                   game.log.File_Write("Resuming game");
                                   game.music_next_track = true;
                                }
                                else game.log.File_Write("Error loadng from slot 4");
                             break;
                             case 5://game menu
                                menu.possition = 5;
                                menu.level = 1;
                                menu.possition_max = 6;
                                game.log.File_Write("Entering 'game' menu.");
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
                                game.log.File_Write("Entering 'game' menu.");
                             break;
                          }
                       break;
                    default:
                       sound.menu_select.play();
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
      bind_texture(63); //background 01
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-2.0f + menu.background_scroll[0].x_pos,-2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 0, 0 );glVertex3f(-2.0f + menu.background_scroll[0].x_pos, 2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 1, 0 );glVertex3f( 2.0f + menu.background_scroll[0].x_pos, 2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 1, 1 );glVertex3f( 2.0f + menu.background_scroll[0].x_pos,-2.0f + menu.background_scroll[0].y_pos, 0.15f );
      glEnd();

      bind_texture(64); //background 02
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-2.0f + menu.background_scroll[1].x_pos,-2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 0, 0 );glVertex3f(-2.0f + menu.background_scroll[1].x_pos, 2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 1, 0 );glVertex3f( 2.0f + menu.background_scroll[1].x_pos, 2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 1, 1 );glVertex3f( 2.0f + menu.background_scroll[1].x_pos,-2.0f + menu.background_scroll[1].y_pos, 0.1f );
      glEnd();

      bind_texture(30); //logo
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.9f, 0.75f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.9f, 1.0f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.9f, 1.0f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.9f, 0.75f, 0.0f );
      glEnd();

      if (menu.possition == 0) bind_texture(36); //new game highlighted
      else                    bind_texture(35); //new game
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.4f, 0.4f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f, 0.6f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f, 0.6f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f, 0.4f, 0.0f );
      glEnd();

      if (menu.possition == 1) bind_texture(50); //resume game highlighted
      else                    bind_texture(49); //resume game
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 1 );glVertex3f(-0.4f, 0.15f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f, 0.35f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f, 0.35f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f, 0.15f, 0.0f );
      glEnd();

      if (menu.possition == 2) bind_texture(29); //load game highlighted
      else                    bind_texture(28); //load game
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 1 );glVertex3f(-0.4f,-0.1f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f, 0.1f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f, 0.1f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f,-0.1f, 0.0f );
      glEnd();

      if (menu.possition == 3) bind_texture(44); //options highlighted
      else                    bind_texture(43); //options
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 1 );glVertex3f(-0.4f,-0.35f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f,-0.15f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f,-0.15f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f,-0.35f, 0.0f );
      glEnd();

      if (menu.possition == 4) bind_texture(46); //quit highlighted
      else                    bind_texture(45); //quit
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
      bind_texture(63); //background 01
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-2.0f + menu.background_scroll[0].x_pos,-2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 0, 0 );glVertex3f(-2.0f + menu.background_scroll[0].x_pos, 2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 1, 0 );glVertex3f( 2.0f + menu.background_scroll[0].x_pos, 2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 1, 1 );glVertex3f( 2.0f + menu.background_scroll[0].x_pos,-2.0f + menu.background_scroll[0].y_pos, 0.15f );
      glEnd();

      bind_texture(64); //background 02
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-2.0f + menu.background_scroll[1].x_pos,-2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 0, 0 );glVertex3f(-2.0f + menu.background_scroll[1].x_pos, 2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 1, 0 );glVertex3f( 2.0f + menu.background_scroll[1].x_pos, 2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 1, 1 );glVertex3f( 2.0f + menu.background_scroll[1].x_pos,-2.0f + menu.background_scroll[1].y_pos, 0.1f );
      glEnd();

      bind_texture(27); //logo - game menu
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.9f, 0.75f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.9f, 1.0f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.9f, 1.0f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.9f, 0.75f, 0.0f );
      glEnd();

      if (menu.possition == 0) bind_texture(60); //starmap highlighted
      else                    bind_texture(59); //starmap
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.4f, 0.55f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f, 0.75f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f, 0.75f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f, 0.55f, 0.0f );
      glEnd();

      if (menu.possition == 1) bind_texture(299); //achievements highlighted
      else                    bind_texture(298); //achievements
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.4f, 0.3f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f, 0.5f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f, 0.5f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f, 0.3f, 0.0f );
      glEnd();

      if (menu.possition == 2) bind_texture(21); //customize starship highlighted
      else                    bind_texture(20); //customize starship
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 1 );glVertex3f(-0.4f, 0.05f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f, 0.25f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f, 0.25f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f, 0.05f, 0.0f );
      glEnd();

      if (menu.possition == 3) bind_texture(50); //resume game highlighted
      else                    bind_texture(49); //resume game
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 1 );glVertex3f(-0.4f,-0.2f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f, 0.0f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f, 0.0f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f,-0.2f, 0.0f );
      glEnd();

      if (menu.possition == 4) bind_texture(52); //save game highlighted
      else                    bind_texture(51); //save game
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 1 );glVertex3f(-0.4f,-0.45f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f,-0.25f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f,-0.25f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f,-0.45f, 0.0f );
      glEnd();

      if (menu.possition == 5) bind_texture(29); //load game highlighted
      else                    bind_texture(28); //load game
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 1 );glVertex3f(-0.4f,-0.7f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f,-0.5f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f,-0.5f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f,-0.7f, 0.0f );
      glEnd();

      if (menu.possition == 6) bind_texture(32); //main menu highlighted
      else                    bind_texture(31); //main menu
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
      bind_texture(63); //background 01
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-2.0f + menu.background_scroll[0].x_pos,-2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 0, 0 );glVertex3f(-2.0f + menu.background_scroll[0].x_pos, 2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 1, 0 );glVertex3f( 2.0f + menu.background_scroll[0].x_pos, 2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 1, 1 );glVertex3f( 2.0f + menu.background_scroll[0].x_pos,-2.0f + menu.background_scroll[0].y_pos, 0.15f );
      glEnd();

      bind_texture(64); //background 02
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-2.0f + menu.background_scroll[1].x_pos,-2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 0, 0 );glVertex3f(-2.0f + menu.background_scroll[1].x_pos, 2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 1, 0 );glVertex3f( 2.0f + menu.background_scroll[1].x_pos, 2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 1, 1 );glVertex3f( 2.0f + menu.background_scroll[1].x_pos,-2.0f + menu.background_scroll[1].y_pos, 0.1f );
      glEnd();

      bind_texture(44); //logo
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.9f, 0.75f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.9f, 1.0f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.9f, 1.0f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.9f, 0.75f, 0.0f );
      glEnd();

      if (menu.possition == 0) bind_texture(58); //Sound Volume highlighted
      else                    bind_texture(57); //Sound Volume
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.8f, 0.55f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.8f, 0.75f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.0f, 0.75f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.0f, 0.55f, 0.0f );
      glEnd();

      if (menu.possition == 0) bind_texture(17); //Sound Volume bar highlighted
      else                    bind_texture(16); //Sound Volume bar
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f((game.config.Audio_Sound_Volume / 160.0f), 0.55f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f((game.config.Audio_Sound_Volume / 160.0f), 0.75f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.0f, 0.75f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.0f, 0.55f, 0.0f );
      glEnd();

      if (menu.possition == 1) bind_texture(34); //Music Volume highlighted
      else                    bind_texture(33); //Music Volume
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 1 );glVertex3f(-0.8f, 0.30f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.8f, 0.50f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.0f, 0.50f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.0f, 0.30f, 0.0f );
      glEnd();

      if (menu.possition == 1) bind_texture(17); //Music Volume bar highlighted
      else                    bind_texture(16); //Music Volume bar
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 1 );glVertex3f((game.config.Audio_Music_Volume / 160.0f), 0.30f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f((game.config.Audio_Music_Volume / 160.0f), 0.50f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.0f, 0.50f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.0f, 0.30f, 0.0f );
      glEnd();

      if (menu.possition == 2) bind_texture(25); //Fullscreen highlighted
      else                    bind_texture(24); //Fullscreen
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 1 );glVertex3f(-0.8f, 0.05f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.8f, 0.25f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.0f, 0.25f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.0f, 0.05f, 0.0f );
      glEnd();

      if ((menu.possition == 2) && (game.config.Display_Fullscreen == false)) bind_texture(38); //Fullscreen off highlighted
      else                    bind_texture(37); //Fullscreen off
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 1 );glVertex3f( 0.0f, 0.05f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.0f, 0.25f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f, 0.25f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f, 0.05f, 0.0f );
      glEnd();

      if ((menu.possition == 2) && (game.config.Display_Fullscreen == true)) bind_texture(40); //Fullscreen on highlighted
      else                    bind_texture(39); //Fullscreen on
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 1 );glVertex3f( 0.4f, 0.05f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.4f, 0.25f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.8f, 0.25f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.8f, 0.05f, 0.0f );
      glEnd();

      if (menu.possition == 3) bind_texture(48); //Resolution highlighted
      else                    bind_texture(47); //Resolution
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 1 );glVertex3f(-0.8f,-0.20f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.8f, 0.00f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.0f, 0.00f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.0f,-0.20f, 0.0f );
      glEnd();

      if ((menu.possition == 3) && (game.config.Display_resolution == 0)) bind_texture(13); //640x480 highlighted
      if ((menu.possition != 3) && (game.config.Display_resolution == 0)) bind_texture(12); //640x480 Resolution
      if ((menu.possition == 3) && (game.config.Display_resolution == 1)) bind_texture(15); //800x600 highlighted
      if ((menu.possition != 3) && (game.config.Display_resolution == 1)) bind_texture(14); //800x600 Resolution
      if ((menu.possition == 3) && (game.config.Display_resolution == 2)) bind_texture(1); //1024x768 highlighted
      if ((menu.possition != 3) && (game.config.Display_resolution == 2)) bind_texture(0); //1024x768 Resolution
      if ((menu.possition == 3) && (game.config.Display_resolution == 3)) bind_texture(3); //1280x1024 highlighted
      if ((menu.possition != 3) && (game.config.Display_resolution == 3)) bind_texture(2); //1280x1024 Resolution
      if ((menu.possition == 3) && (game.config.Display_resolution == 4)) bind_texture(5); //1366x768 highlighted
      if ((menu.possition != 3) && (game.config.Display_resolution == 4)) bind_texture(4); //1366x768 Resolution
      if ((menu.possition == 3) && (game.config.Display_resolution == 5)) bind_texture(7); //1440x900 highlighted
      if ((menu.possition != 3) && (game.config.Display_resolution == 5)) bind_texture(6); //1440x900 Resolution
      if ((menu.possition == 3) && (game.config.Display_resolution == 6)) bind_texture(9); //1680x1050 highlighted
      if ((menu.possition != 3) && (game.config.Display_resolution == 6)) bind_texture(8); //1680x1050 Resolution
      if ((menu.possition == 3) && (game.config.Display_resolution == 7)) bind_texture(11); //1920x1080 highlighted
      if ((menu.possition != 3) && (game.config.Display_resolution == 7)) bind_texture(10); //1920x1080 Resolution
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 1 );glVertex3f( 0.0f,-0.20f, 0.0f );
      glTexCoord2i( 0, 0 );glVertex3f( 0.0f, 0.00f, 0.0f );
      glTexCoord2i( 1, 0 );glVertex3f( 0.8f, 0.00f, 0.0f );
      glTexCoord2i( 1, 1 );glVertex3f( 0.8f,-0.20f, 0.0f );
      glEnd();

      if (menu.possition == 4) bind_texture(32); //main menu highlighted
      else                    bind_texture(31); //main menu
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

      bind_texture(63); //background 01
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-2.0f + menu.background_scroll[0].x_pos,-2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 0, 0 );glVertex3f(-2.0f + menu.background_scroll[0].x_pos, 2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 1, 0 );glVertex3f( 2.0f + menu.background_scroll[0].x_pos, 2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 1, 1 );glVertex3f( 2.0f + menu.background_scroll[0].x_pos,-2.0f + menu.background_scroll[0].y_pos, 0.15f );
      glEnd();

      bind_texture(64); //background 02
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-2.0f + menu.background_scroll[1].x_pos,-2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 0, 0 );glVertex3f(-2.0f + menu.background_scroll[1].x_pos, 2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 1, 0 );glVertex3f( 2.0f + menu.background_scroll[1].x_pos, 2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 1, 1 );glVertex3f( 2.0f + menu.background_scroll[1].x_pos,-2.0f + menu.background_scroll[1].y_pos, 0.1f );
      glEnd();

      bind_texture(21); //logo - customize startship menu
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.9f, 0.75f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.9f, 1.00f, 0.05f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.9f, 1.00f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.9f, 0.75f, 0.05f );
      glEnd();

      if (menu.possition == 0) bind_texture(23); //front weapon highlighted
      else                    bind_texture(22); //front weapon
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-1.0f, 0.65f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f(-1.0f, 0.75f, 0.05f );
	  glTexCoord2i( 1, 0 );glVertex3f(-0.4f, 0.75f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f(-0.4f, 0.65f, 0.05f );
      glEnd();

      bind_texture(283); //weapon none
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f(-0.2f, 0.65f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f(-0.2f, 0.75f, 0.05f );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.3f, 0.75f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.3f, 0.65f, 0.05f );
      glEnd();

      if (game_o.player.front_weapon == -1)
      {
         bind_texture(282); //weapon none highlighted
         glLoadIdentity();
         glBegin( GL_QUADS );
	     glTexCoord2i( 1, 0 );glVertex3f(-0.2f, 0.65f, 0.04f );
	     glTexCoord2i( 1, 1 );glVertex3f(-0.2f, 0.75f, 0.04f );
	     glTexCoord2i( 0, 1 );glVertex3f(-0.3f, 0.75f, 0.04f );
	     glTexCoord2i( 0, 0 );glVertex3f(-0.3f, 0.65f, 0.04f );
         glEnd();
      }

      if (game_o.projectile[0].active) bind_texture(game_o.projectile[0].image); //weapon 0
      else bind_texture(284);
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f(-0.05f, 0.65f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f(-0.05f, 0.75f, 0.05f );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.15f, 0.75f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.15f, 0.65f, 0.05f );
      glEnd();

      if (game_o.player.front_weapon == 0)
      {
         bind_texture(282); //weapon 0 highlighted
         glLoadIdentity();
         glBegin( GL_QUADS );
	     glTexCoord2i( 1, 0 );glVertex3f(-0.05f, 0.65f, 0.04f );
	     glTexCoord2i( 1, 1 );glVertex3f(-0.05f, 0.75f, 0.04f );
   	     glTexCoord2i( 0, 1 );glVertex3f(-0.15f, 0.75f, 0.04f );
	     glTexCoord2i( 0, 0 );glVertex3f(-0.15f, 0.65f, 0.04f );
         glEnd();
      }

      if (game_o.projectile[1].active) bind_texture(game_o.projectile[1].image); //weapon 1
      else bind_texture(284);
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.10f, 0.65f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.10f, 0.75f, 0.05f );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.00f, 0.75f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.00f, 0.65f, 0.05f );
      glEnd();

      if (game_o.player.front_weapon == 1)
      {
         bind_texture(282); //weapon 1 highlighted
         glLoadIdentity();
         glBegin( GL_QUADS );
   	     glTexCoord2i( 1, 0 );glVertex3f( 0.10f, 0.65f, 0.04f );
	     glTexCoord2i( 1, 1 );glVertex3f( 0.10f, 0.75f, 0.04f );
	     glTexCoord2i( 0, 1 );glVertex3f( 0.00f, 0.75f, 0.04f );
	     glTexCoord2i( 0, 0 );glVertex3f( 0.00f, 0.65f, 0.04f );
         glEnd();
      }

      if (game_o.projectile[2].active) bind_texture(game_o.projectile[2].image); //weapon 2
      else bind_texture(284);
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.25f, 0.65f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.25f, 0.75f, 0.05f );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.15f, 0.75f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.15f, 0.65f, 0.05f );
      glEnd();

      if (game_o.player.front_weapon == 2)
      {
         bind_texture(282); //weapon 2 highlighted
         glLoadIdentity();
         glBegin( GL_QUADS );
	     glTexCoord2i( 1, 0 );glVertex3f( 0.25f, 0.65f, 0.04f );
	     glTexCoord2i( 1, 1 );glVertex3f( 0.25f, 0.75f, 0.04f );
	     glTexCoord2i( 0, 1 );glVertex3f( 0.15f, 0.75f, 0.04f );
	     glTexCoord2i( 0, 0 );glVertex3f( 0.15f, 0.65f, 0.04f );
         glEnd();
      }

      if (game_o.projectile[3].active) bind_texture(game_o.projectile[3].image); //weapon 3
      else bind_texture(284);
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.40f, 0.65f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.40f, 0.75f, 0.05f );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.30f, 0.75f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.30f, 0.65f, 0.05f );
      glEnd();

      if (game_o.player.front_weapon == 3)
      {
         bind_texture(282); //weapon 3 highlighted
         glLoadIdentity();
         glBegin( GL_QUADS );
	     glTexCoord2i( 1, 0 );glVertex3f( 0.40f, 0.65f, 0.04f );
	     glTexCoord2i( 1, 1 );glVertex3f( 0.40f, 0.75f, 0.04f );
	     glTexCoord2i( 0, 1 );glVertex3f( 0.30f, 0.75f, 0.04f );
	     glTexCoord2i( 0, 0 );glVertex3f( 0.30f, 0.65f, 0.04f );
         glEnd();
      }

      if (game_o.projectile[4].active) bind_texture(game_o.projectile[4].image); //weapon 4
      else bind_texture(284);
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.55f, 0.65f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.55f, 0.75f, 0.05f );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.45f, 0.75f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.45f, 0.65f, 0.05f );
      glEnd();

      if (game_o.player.front_weapon == 4)
      {
         bind_texture(282); //weapon 4 highlighted
         glLoadIdentity();
         glBegin( GL_QUADS );
	     glTexCoord2i( 1, 0 );glVertex3f( 0.55f, 0.65f, 0.04f );
	     glTexCoord2i( 1, 1 );glVertex3f( 0.55f, 0.75f, 0.04f );
	     glTexCoord2i( 0, 1 );glVertex3f( 0.45f, 0.75f, 0.04f );
	     glTexCoord2i( 0, 0 );glVertex3f( 0.45f, 0.65f, 0.04f );
         glEnd();
      }

      if (game_o.projectile[5].active) bind_texture(game_o.projectile[5].image); //weapon 5
      else bind_texture(284);
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.70f, 0.65f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.70f, 0.75f, 0.05f );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.60f, 0.75f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.60f, 0.65f, 0.05f );
      glEnd();

      if (game_o.player.front_weapon == 5)
      {
         bind_texture(282); //weapon 5 highlighted
         glLoadIdentity();
         glBegin( GL_QUADS );
	     glTexCoord2i( 1, 0 );glVertex3f( 0.70f, 0.65f, 0.04f );
	     glTexCoord2i( 1, 1 );glVertex3f( 0.70f, 0.75f, 0.04f );
	     glTexCoord2i( 0, 1 );glVertex3f( 0.60f, 0.75f, 0.04f );
	     glTexCoord2i( 0, 0 );glVertex3f( 0.60f, 0.65f, 0.04f );
         glEnd();
      }

      if (menu.possition == 1) bind_texture(56); //side weapon highlighted
      else                    bind_texture(55); //side weapon
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-1.0f, 0.50f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f(-1.0f, 0.60f, 0.05f );
	  glTexCoord2i( 1, 0 );glVertex3f(-0.4f, 0.60f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f(-0.4f, 0.50f, 0.05f );
      glEnd();

      bind_texture(283); //weapon none
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f(-0.2f, 0.50f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f(-0.2f, 0.60f, 0.05f );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.3f, 0.60f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.3f, 0.50f, 0.05f );
      glEnd();

      if (game_o.player.side_weapon == -1)
      {
         bind_texture(282); //weapon none highlighted
         glLoadIdentity();
         glBegin( GL_QUADS );
	     glTexCoord2i( 1, 0 );glVertex3f(-0.2f, 0.50f, 0.04f );
	     glTexCoord2i( 1, 1 );glVertex3f(-0.2f, 0.60f, 0.04f );
	     glTexCoord2i( 0, 1 );glVertex3f(-0.3f, 0.60f, 0.04f );
	     glTexCoord2i( 0, 0 );glVertex3f(-0.3f, 0.50f, 0.04f );
         glEnd();
      }

      if (game_o.projectile[0].active) bind_texture(game_o.projectile[0].image); //weapon 0
      else bind_texture(284);
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f(-0.05f, 0.50f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f(-0.05f, 0.60f, 0.05f );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.15f, 0.60f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.15f, 0.50f, 0.05f );
      glEnd();

      if (game_o.player.side_weapon == 0)
      {
         bind_texture(282); //weapon 0 highlighted
         glLoadIdentity();
         glBegin( GL_QUADS );
	     glTexCoord2i( 1, 0 );glVertex3f(-0.05f, 0.50f, 0.04f );
	     glTexCoord2i( 1, 1 );glVertex3f(-0.05f, 0.60f, 0.04f );
	     glTexCoord2i( 0, 1 );glVertex3f(-0.15f, 0.60f, 0.04f );
	     glTexCoord2i( 0, 0 );glVertex3f(-0.15f, 0.50f, 0.04f );
         glEnd();
      }

      if (game_o.projectile[1].active) bind_texture(game_o.projectile[1].image); //weapon 1
      else bind_texture(284);
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.10f, 0.50f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.10f, 0.60f, 0.05f );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.00f, 0.60f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.00f, 0.50f, 0.05f );
      glEnd();

      if (game_o.player.side_weapon == 1)
      {
         bind_texture(282); //weapon 1 highlighted
         glLoadIdentity();
         glBegin( GL_QUADS );
	     glTexCoord2i( 1, 0 );glVertex3f( 0.10f, 0.50f, 0.04f );
	     glTexCoord2i( 1, 1 );glVertex3f( 0.10f, 0.60f, 0.04f );
	     glTexCoord2i( 0, 1 );glVertex3f( 0.00f, 0.60f, 0.04f );
	     glTexCoord2i( 0, 0 );glVertex3f( 0.00f, 0.50f, 0.04f );
         glEnd();
      }

      if (game_o.projectile[2].active) bind_texture(game_o.projectile[2].image); //weapon 2
      else bind_texture(284);
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.25f, 0.50f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.25f, 0.60f, 0.05f );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.15f, 0.60f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.15f, 0.50f, 0.05f );
      glEnd();

      if (game_o.player.side_weapon == 2)
      {
         bind_texture(282); //weapon 2 highlighted
         glLoadIdentity();
         glBegin( GL_QUADS );
	     glTexCoord2i( 1, 0 );glVertex3f( 0.25f, 0.50f, 0.04f );
	     glTexCoord2i( 1, 1 );glVertex3f( 0.25f, 0.60f, 0.04f );
	     glTexCoord2i( 0, 1 );glVertex3f( 0.15f, 0.60f, 0.04f );
	     glTexCoord2i( 0, 0 );glVertex3f( 0.15f, 0.50f, 0.04f );
         glEnd();
      }

      if (game_o.projectile[3].active) bind_texture(game_o.projectile[3].image); //weapon 3
      else bind_texture(284);
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.40f, 0.50f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.40f, 0.60f, 0.05f );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.30f, 0.60f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.30f, 0.50f, 0.05f );
      glEnd();

      if (game_o.player.side_weapon == 3)
      {
         bind_texture(282); //weapon 3 highlighted
         glLoadIdentity();
         glBegin( GL_QUADS );
	     glTexCoord2i( 1, 0 );glVertex3f( 0.40f, 0.50f, 0.04f );
	     glTexCoord2i( 1, 1 );glVertex3f( 0.40f, 0.60f, 0.04f );
	     glTexCoord2i( 0, 1 );glVertex3f( 0.30f, 0.60f, 0.04f );
	     glTexCoord2i( 0, 0 );glVertex3f( 0.30f, 0.50f, 0.04f );
         glEnd();
      }

      if (game_o.projectile[4].active) bind_texture(game_o.projectile[4].image); //weapon 4
      else bind_texture(284);
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.55f, 0.50f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.55f, 0.60f, 0.05f );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.45f, 0.60f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.45f, 0.50f, 0.05f );
      glEnd();

      if (game_o.player.side_weapon == 4)
      {
         bind_texture(282); //weapon 4 highlighted
         glLoadIdentity();
         glBegin( GL_QUADS );
	     glTexCoord2i( 1, 0 );glVertex3f( 0.55f, 0.50f, 0.04f );
	     glTexCoord2i( 1, 1 );glVertex3f( 0.55f, 0.60f, 0.04f );
	     glTexCoord2i( 0, 1 );glVertex3f( 0.45f, 0.60f, 0.04f );
	     glTexCoord2i( 0, 0 );glVertex3f( 0.45f, 0.50f, 0.04f );
         glEnd();
      }

      if (game_o.projectile[5].active) bind_texture(game_o.projectile[5].image); //weapon 5
      else bind_texture(284);
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.70f, 0.50f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.70f, 0.60f, 0.05f );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.60f, 0.60f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.60f, 0.50f, 0.05f );
      glEnd();

      if (game_o.player.side_weapon == 5)
      {
         bind_texture(282); //weapon 5 highlighted
         glLoadIdentity();
         glBegin( GL_QUADS );
	     glTexCoord2i( 1, 0 );glVertex3f( 0.70f, 0.50f, 0.04f );
	     glTexCoord2i( 1, 1 );glVertex3f( 0.70f, 0.60f, 0.04f );
	     glTexCoord2i( 0, 1 );glVertex3f( 0.60f, 0.60f, 0.04f );
	     glTexCoord2i( 0, 0 );glVertex3f( 0.60f, 0.50f, 0.04f );
         glEnd();
      }

      if (menu.possition == 2) bind_texture(54); //shield highlighted
      else                    bind_texture(53); //shield
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-1.0f, 0.35f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f(-1.0f, 0.45f, 0.05f );
	  glTexCoord2i( 1, 0 );glVertex3f(-0.4f, 0.45f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f(-0.4f, 0.35f, 0.05f );
      glEnd();

      bind_texture(283); //shield none
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f(-0.2f, 0.35f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f(-0.2f, 0.45f, 0.05f );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.3f, 0.45f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.3f, 0.35f, 0.05f );
      glEnd();

      if (game_o.player.front_shield == -1)
      {
         bind_texture(282); //shield none highlighted
         glLoadIdentity();
         glBegin( GL_QUADS );
	     glTexCoord2i( 1, 0 );glVertex3f(-0.2f, 0.35f, 0.04f );
	     glTexCoord2i( 1, 1 );glVertex3f(-0.2f, 0.45f, 0.04f );
	     glTexCoord2i( 0, 1 );glVertex3f(-0.3f, 0.45f, 0.04f );
	     glTexCoord2i( 0, 0 );glVertex3f(-0.3f, 0.35f, 0.04f );
         glEnd();
      }

      if (game_o.shield[0].active) bind_texture(game_o.shield[0].image); //shield 0
      else bind_texture(284);
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f(-0.05f, 0.35f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f(-0.05f, 0.45f, 0.05f );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.15f, 0.45f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.15f, 0.35f, 0.05f );
      glEnd();

      if (game_o.player.front_shield == 0)
      {
         bind_texture(282); //shield 0 highlighted
         glLoadIdentity();
         glBegin( GL_QUADS );
	     glTexCoord2i( 1, 0 );glVertex3f(-0.05f, 0.35f, 0.04f );
	     glTexCoord2i( 1, 1 );glVertex3f(-0.05f, 0.45f, 0.04f );
	     glTexCoord2i( 0, 1 );glVertex3f(-0.15f, 0.45f, 0.04f );
	     glTexCoord2i( 0, 0 );glVertex3f(-0.15f, 0.35f, 0.04f );
         glEnd();
      }

      if (game_o.shield[1].active) bind_texture(game_o.shield[1].image); //shield 1
      else bind_texture(284);
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.10f, 0.35f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.10f, 0.45f, 0.05f );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.00f, 0.45f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.00f, 0.35f, 0.05f );
      glEnd();

      if (game_o.player.front_shield == 1)
      {
         bind_texture(282); //shield 1 highlighted
         glLoadIdentity();
         glBegin( GL_QUADS );
	     glTexCoord2i( 1, 0 );glVertex3f( 0.10f, 0.35f, 0.04f );
	     glTexCoord2i( 1, 1 );glVertex3f( 0.10f, 0.45f, 0.04f );
	     glTexCoord2i( 0, 1 );glVertex3f( 0.00f, 0.45f, 0.04f );
	     glTexCoord2i( 0, 0 );glVertex3f( 0.00f, 0.35f, 0.04f );
         glEnd();
      }

      if (game_o.shield[2].active) bind_texture(game_o.shield[2].image); //shield 2
      else bind_texture(284);
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.25f, 0.35f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.25f, 0.45f, 0.05f );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.15f, 0.45f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.15f, 0.35f, 0.05f );
      glEnd();

      if (game_o.player.front_shield == 2)
      {
         bind_texture(282); //shield 2 highlighted
         glLoadIdentity();
         glBegin( GL_QUADS );
         glTexCoord2i( 1, 0 );glVertex3f( 0.25f, 0.35f, 0.04f );
         glTexCoord2i( 1, 1 );glVertex3f( 0.25f, 0.45f, 0.04f );
         glTexCoord2i( 0, 1 );glVertex3f( 0.15f, 0.45f, 0.04f );
         glTexCoord2i( 0, 0 );glVertex3f( 0.15f, 0.35f, 0.04f );
         glEnd();
      }

      if (game_o.shield[3].active) bind_texture(game_o.shield[3].image); //shield 3
      else bind_texture(284);
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.40f, 0.35f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.40f, 0.45f, 0.05f );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.30f, 0.45f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.30f, 0.35f, 0.05f );
      glEnd();

      if (game_o.player.front_shield == 3)
      {
         bind_texture(282); //shield 3 highlighted
         glLoadIdentity();
         glBegin( GL_QUADS );
	     glTexCoord2i( 1, 0 );glVertex3f( 0.40f, 0.35f, 0.04f );
	     glTexCoord2i( 1, 1 );glVertex3f( 0.40f, 0.45f, 0.04f );
	     glTexCoord2i( 0, 1 );glVertex3f( 0.30f, 0.45f, 0.04f );
 	     glTexCoord2i( 0, 0 );glVertex3f( 0.30f, 0.35f, 0.04f );
         glEnd();
      }

      if (game_o.shield[4].active) bind_texture(game_o.shield[4].image); //shield 4
      else bind_texture(284);
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.55f, 0.35f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.55f, 0.45f, 0.05f );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.45f, 0.45f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.45f, 0.35f, 0.05f );
      glEnd();

      if (game_o.player.front_shield == 4)
      {
         bind_texture(282); //shield 4 highlighted
         glLoadIdentity();
         glBegin( GL_QUADS );
	     glTexCoord2i( 1, 0 );glVertex3f( 0.55f, 0.35f, 0.04f );
	     glTexCoord2i( 1, 1 );glVertex3f( 0.55f, 0.45f, 0.04f );
	     glTexCoord2i( 0, 1 );glVertex3f( 0.45f, 0.45f, 0.04f );
	     glTexCoord2i( 0, 0 );glVertex3f( 0.45f, 0.35f, 0.04f );
         glEnd();
      }

      if (menu.possition == 3) bind_texture(62); //thrusters highlighted
      else                    bind_texture(61); //thrusters
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-1.0f, 0.20f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f(-1.0f, 0.30f, 0.05f );
	  glTexCoord2i( 1, 0 );glVertex3f(-0.4f, 0.30f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f(-0.4f, 0.20f, 0.05f );
      glEnd();

      bind_texture(283); //thrusters none
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f(-0.2f, 0.20f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f(-0.2f, 0.30f, 0.05f );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.3f, 0.30f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.3f, 0.20f, 0.05f );
      glEnd();

      if (game_o.player.thrusters == -1)
      {
         bind_texture(282); //thrusters none highlighted
         glLoadIdentity();
         glBegin( GL_QUADS );
	     glTexCoord2i( 1, 0 );glVertex3f(-0.2f, 0.20f, 0.04f );
	     glTexCoord2i( 1, 1 );glVertex3f(-0.2f, 0.30f, 0.04f );
	     glTexCoord2i( 0, 1 );glVertex3f(-0.3f, 0.30f, 0.04f );
	     glTexCoord2i( 0, 0 );glVertex3f(-0.3f, 0.20f, 0.04f );
         glEnd();
      }

      if (game_o.thruster[0].active) bind_texture(game_o.thruster[0].image); //thrusters 0
      else bind_texture(284);
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f(-0.05f, 0.20f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f(-0.05f, 0.30f, 0.05f );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.15f, 0.30f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.15f, 0.20f, 0.05f );
      glEnd();

      if (game_o.player.thrusters == 0)
      {
         bind_texture(282); //thrusters 0 highlighted
         glLoadIdentity();
         glBegin( GL_QUADS );
	     glTexCoord2i( 0, 0 );glVertex3f(-0.05f, 0.20f, 0.04f );
	     glTexCoord2i( 1, 0 );glVertex3f(-0.05f, 0.30f, 0.04f );
	     glTexCoord2i( 1, 1 );glVertex3f(-0.15f, 0.30f, 0.04f );
	     glTexCoord2i( 0, 1 );glVertex3f(-0.15f, 0.20f, 0.04f );
         glEnd();
      }

      if (game_o.thruster[1].active) bind_texture(game_o.thruster[1].image); //thrusters 1
      else bind_texture(284);
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.10f, 0.20f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.10f, 0.30f, 0.05f );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.00f, 0.30f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.00f, 0.20f, 0.05f );
      glEnd();

      if (game_o.player.thrusters == 1)
      {
         bind_texture(282); //thrusters 1 highlighted
         glLoadIdentity();
         glBegin( GL_QUADS );
	     glTexCoord2i( 0, 0 );glVertex3f( 0.10f, 0.20f, 0.04f );
	     glTexCoord2i( 1, 0 );glVertex3f( 0.10f, 0.30f, 0.04f );
	     glTexCoord2i( 1, 1 );glVertex3f( 0.00f, 0.30f, 0.04f );
	     glTexCoord2i( 0, 1 );glVertex3f( 0.00f, 0.20f, 0.04f );
         glEnd();
      }

      if (game_o.thruster[2].active) bind_texture(game_o.thruster[2].image); //thrusters 2
      else bind_texture(284);
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.251f, 0.20f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.251f, 0.30f, 0.05f );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.151f, 0.30f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.151f, 0.20f, 0.05f );
      glEnd();

      if (game_o.player.thrusters == 2)
      {
         bind_texture(282); //thrusters 2 highlighted
         glLoadIdentity();
         glBegin( GL_QUADS );
	     glTexCoord2i( 0, 0 );glVertex3f( 0.25f, 0.20f, 0.04f );
	     glTexCoord2i( 1, 0 );glVertex3f( 0.25f, 0.30f, 0.04f );
	     glTexCoord2i( 1, 1 );glVertex3f( 0.15f, 0.30f, 0.04f );
	     glTexCoord2i( 0, 1 );glVertex3f( 0.15f, 0.20f, 0.04f );
         glEnd();
      }

      if (game_o.player.thrusters > -1)
      {
         bind_texture(game_o.thruster[game_o.player.thrusters].image); //player starship thrusters
         glLoadIdentity();
         glBegin( GL_QUADS );
         glTexCoord2i( 0, 0 );glVertex3f(ship_pos_x+(game_o.player.width)-0.379f,ship_pos_y-(game_o.player.hight), 0.035f );
         glTexCoord2i( 1, 0 );glVertex3f(ship_pos_x+(game_o.player.width)-0.379f,ship_pos_y+(game_o.player.hight), 0.035f );
         glTexCoord2i( 1, 1 );glVertex3f(ship_pos_x-(game_o.player.width)-0.379f,ship_pos_y+(game_o.player.hight), 0.035f );
         glTexCoord2i( 0, 1 );glVertex3f(ship_pos_x-(game_o.player.width)-0.379f,ship_pos_y-(game_o.player.hight), 0.035f );
         glEnd();
      }

      bind_texture(game_o.player.image); //player starship
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 0 );glVertex3f(ship_pos_x+(game_o.player.width),ship_pos_y-(game_o.player.hight), 0.03f );
      glTexCoord2i( 1, 0 );glVertex3f(ship_pos_x+(game_o.player.width),ship_pos_y+(game_o.player.hight), 0.03f );
      glTexCoord2i( 1, 1 );glVertex3f(ship_pos_x-(game_o.player.width),ship_pos_y+(game_o.player.hight), 0.03f );
      glTexCoord2i( 0, 1 );glVertex3f(ship_pos_x-(game_o.player.width),ship_pos_y-(game_o.player.hight), 0.03f );
      glEnd();

      if (game_o.player.front_weapon > -1)
      {
         bind_texture(game_o.player.front_weapon+211); //player starship front weapon
         glLoadIdentity();
         glBegin( GL_QUADS );
         glTexCoord2i( 0, 0 );glVertex3f(ship_pos_x+(game_o.player.width/6)+0.134f,ship_pos_y-(game_o.player.hight/4), 0.025f );
         glTexCoord2i( 1, 0 );glVertex3f(ship_pos_x+(game_o.player.width/6)+0.134f,ship_pos_y+(game_o.player.hight/4), 0.025f );
         glTexCoord2i( 1, 1 );glVertex3f(ship_pos_x-(game_o.player.width/6)+0.150f,ship_pos_y+(game_o.player.hight/4), 0.025f );
         glTexCoord2i( 0, 1 );glVertex3f(ship_pos_x-(game_o.player.width/6)+0.150f,ship_pos_y-(game_o.player.hight/4), 0.025f );
         glEnd();
      }

      if (game_o.player.side_weapon > -1)
      {
         bind_texture(game_o.player.side_weapon+211); //player starship side weapons
         glLoadIdentity();
         glBegin( GL_QUADS );
         glTexCoord2i( 0, 0 );glVertex3f(ship_pos_x+(game_o.player.width/3)+0.124f,ship_pos_y-(game_o.player.hight/3)+0.150f, 0.025f );
         glTexCoord2i( 1, 0 );glVertex3f(ship_pos_x+(game_o.player.width/3)+0.124f,ship_pos_y+(game_o.player.hight/3)+0.150f, 0.025f );
         glTexCoord2i( 1, 1 );glVertex3f(ship_pos_x-(game_o.player.width/3)+0.134f,ship_pos_y+(game_o.player.hight/3)+0.150f, 0.025f );
         glTexCoord2i( 0, 1 );glVertex3f(ship_pos_x-(game_o.player.width/3)+0.134f,ship_pos_y-(game_o.player.hight/3)+0.150f, 0.025f );
         glEnd();
         glBegin( GL_QUADS );
         glTexCoord2i( 0, 0 );glVertex3f(ship_pos_x+(game_o.player.width/3)+0.134f,ship_pos_y-(game_o.player.hight/3)-0.150f, 0.025f );
         glTexCoord2i( 1, 0 );glVertex3f(ship_pos_x+(game_o.player.width/3)+0.134f,ship_pos_y+(game_o.player.hight/3)-0.150f, 0.025f );
         glTexCoord2i( 1, 1 );glVertex3f(ship_pos_x-(game_o.player.width/3)+0.134f,ship_pos_y+(game_o.player.hight/3)-0.150f, 0.025f );
         glTexCoord2i( 0, 1 );glVertex3f(ship_pos_x-(game_o.player.width/3)+0.134f,ship_pos_y-(game_o.player.hight/3)-0.150f, 0.025f );
         glEnd();
      }

      if (game_o.player.front_shield > -1)
      {
         bind_texture(game_o.shield[game_o.player.front_shield].image); //player starship shield
         glLoadIdentity();
         glBegin( GL_QUADS );
         glTexCoord2i( 1, 0 );glVertex3f(ship_pos_x+(game_o.player.width*1.5),ship_pos_y-(game_o.player.hight*1.5), 0.02f );
         glTexCoord2i( 1, 1 );glVertex3f(ship_pos_x+(game_o.player.width*1.5),ship_pos_y+(game_o.player.hight*1.5), 0.02f );
         glTexCoord2i( 0, 1 );glVertex3f(ship_pos_x-(game_o.player.width*1.5),ship_pos_y+(game_o.player.hight*1.5), 0.02f );
         glTexCoord2i( 0, 0 );glVertex3f(ship_pos_x-(game_o.player.width*1.5),ship_pos_y-(game_o.player.hight*1.5), 0.02f );
         glEnd();
      }

      if (menu.possition == 4) bind_texture(27); //game menu highlighted
      else                    bind_texture(26); //game menu
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.4f,-1.0f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f,-0.8f, 0.05f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f,-0.8f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f,-1.0f, 0.05f );
      glEnd();

      if ((menu.possition == 0) && (game_o.player.front_weapon >= 0)) //front weapon
      {
          font.font_1.Write(255,255,255,64,-1.0f,-0.000f,game_o.projectile[game_o.player.front_weapon].name,0.0f);
          font.font_1.Write(255,255,255,64,-1.0f,-0.075f,"Level            - ", game_o.projectile[game_o.player.front_weapon].level);
          font.font_1.Write(255,255,255,64,-1.0f,-0.150f,"Experience  - ", game_o.projectile[game_o.player.front_weapon].experience);
          if (game_o.projectile[game_o.player.front_weapon].level == 0) font.font_1.Write(255,255,255,64,-1.0f,-0.225f,"Next level    - ", game_o.projectile[game_o.player.front_weapon].level_1);
          if (game_o.projectile[game_o.player.front_weapon].level == 1) font.font_1.Write(255,255,255,64,-1.0f,-0.225f,"Next level    - ", game_o.projectile[game_o.player.front_weapon].level_2);
          if (game_o.projectile[game_o.player.front_weapon].level == 2) font.font_1.Write(255,255,255,64,-1.0f,-0.225f,"Next level    - ", game_o.projectile[game_o.player.front_weapon].level_3);
          if (game_o.projectile[game_o.player.front_weapon].level >= 3) font.font_1.Write(255,255,255,64,-1.0f,-0.225f,"Next level    - Max", 0.0f);
          font.font_1.Write(255,255,255,64,-1.0f,-0.300f,"Damage       - ", game_o.projectile[game_o.player.front_weapon].damage);
          font.font_1.Write(255,255,255,64,-1.0f,-0.375f,"Speed          - ", game_o.projectile[game_o.player.front_weapon].speed);
          font.font_1.Write(255,255,255,64,-1.0f,-0.450f,"Health         - ", game_o.projectile[game_o.player.front_weapon].health);
          font.font_1.Write(255,255,255,64,-1.0f,-0.525f,"Rate of Fire - ", game_o.projectile[game_o.player.front_weapon].rate_of_fire);
      }
      if ((menu.possition == 1) && (game_o.player.side_weapon >= 0)) //side weapon
      {
          font.font_1.Write(255,255,255,64,-1.0f,-0.000f,game_o.projectile[game_o.player.side_weapon].name,0.0f);
          font.font_1.Write(255,255,255,64,-1.0f,-0.075f,"Level            - ", game_o.projectile[game_o.player.side_weapon].level);
          font.font_1.Write(255,255,255,64,-1.0f,-0.150f,"Experience  - ", game_o.projectile[game_o.player.side_weapon].experience);
          if (game_o.projectile[game_o.player.side_weapon].level == 0) font.font_1.Write(255,255,255,64,-1.0f,-0.225f,"Next level    - ", game_o.projectile[game_o.player.side_weapon].level_1);
          if (game_o.projectile[game_o.player.side_weapon].level == 1) font.font_1.Write(255,255,255,64,-1.0f,-0.225f,"Next level    - ", game_o.projectile[game_o.player.side_weapon].level_2);
          if (game_o.projectile[game_o.player.side_weapon].level == 2) font.font_1.Write(255,255,255,64,-1.0f,-0.225f,"Next level    - ", game_o.projectile[game_o.player.side_weapon].level_3);
          if (game_o.projectile[game_o.player.side_weapon].level >= 3) font.font_1.Write(255,255,255,64,-1.0f,-0.225f,"Next level    - Max", 0.0f);
          font.font_1.Write(255,255,255,64,-1.0f,-0.300f,"Damage       - ", game_o.projectile[game_o.player.side_weapon].damage);
          font.font_1.Write(255,255,255,64,-1.0f,-0.375f,"Speed          - ", game_o.projectile[game_o.player.side_weapon].speed);
          font.font_1.Write(255,255,255,64,-1.0f,-0.450f,"Health         - ", game_o.projectile[game_o.player.side_weapon].health);
          font.font_1.Write(255,255,255,64,-1.0f,-0.525f,"Rate of Fire - ", game_o.projectile[game_o.player.side_weapon].rate_of_fire);
      }
      if ((menu.possition == 2) && (game_o.player.front_shield >= 0)) //front shield
      {
          font.font_1.Write(255,255,255,64,-1.0f,-0.000f,game_o.shield[game_o.player.front_shield].name,0.0f);
          font.font_1.Write(255,255,255,64,-1.0f,-0.075f,"Level            - ", game_o.shield[game_o.player.front_shield].level);
          font.font_1.Write(255,255,255,64,-1.0f,-0.150f,"Experience  - ", game_o.shield[game_o.player.front_shield].experience);
          if (game_o.shield[game_o.player.front_shield].level == 0) font.font_1.Write(255,255,255,64,-1.0f,-0.225f,"Next level    - ", game_o.shield[game_o.player.front_shield].level_1);
          if (game_o.shield[game_o.player.front_shield].level == 1) font.font_1.Write(255,255,255,64,-1.0f,-0.225f,"Next level    - ", game_o.shield[game_o.player.front_shield].level_2);
          if (game_o.shield[game_o.player.front_shield].level == 2) font.font_1.Write(255,255,255,64,-1.0f,-0.225f,"Next level    - ", game_o.shield[game_o.player.front_shield].level_3);
          if (game_o.shield[game_o.player.front_shield].level >= 3) font.font_1.Write(255,255,255,64,-1.0f,-0.225f,"Next level    - Max", 0.0f);
          font.font_1.Write(255,255,255,64,-1.0f,-0.300f,"Absorption   - ", (10000*(game_o.shield[game_o.player.front_shield].absorption+(0.0001f*game_o.shield[game_o.player.front_shield].level))));
      }
      if ((menu.possition == 3) && (game_o.player.thrusters >= 0)) //thrusters
      {
          font.font_1.Write(255,255,255,64,-1.0f,-0.00f,game_o.thruster[game_o.player.thrusters].name,0.0f);
          font.font_1.Write(255,255,255,64,-1.0f,-0.075f,"Level            - ", game_o.thruster[game_o.player.thrusters].level);
          font.font_1.Write(255,255,255,64,-1.0f,-0.150f,"Experience  - ", game_o.thruster[game_o.player.thrusters].experience);
          if (game_o.thruster[game_o.player.thrusters].level == 0) font.font_1.Write(255,255,255,64,-1.0f,-0.225f,"Next level    - ", game_o.thruster[game_o.player.thrusters].level_1);
          if (game_o.thruster[game_o.player.thrusters].level == 1) font.font_1.Write(255,255,255,64,-1.0f,-0.225f,"Next level    - ", game_o.thruster[game_o.player.thrusters].level_2);
          if (game_o.thruster[game_o.player.thrusters].level == 2) font.font_1.Write(255,255,255,64,-1.0f,-0.225f,"Next level    - ", game_o.thruster[game_o.player.thrusters].level_3);
          if (game_o.thruster[game_o.player.thrusters].level >= 3) font.font_1.Write(255,255,255,64,-1.0f,-0.225f,"Next level    - Max", 0.0f);
          font.font_1.Write(255,255,255,64,-1.0f,-0.300f,"Thrust          - ", (10000*(game_o.thruster[game_o.player.thrusters].thrust+(0.0001f*game_o.thruster[game_o.player.thrusters].level))));
      }
   }
/*-----------------------------------------------------------------------------*/

   if (menu.level == 4) //starmap_menu
   {
      bind_texture(63); //background 01
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-2.0f + menu.background_scroll[0].x_pos,-2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 0, 0 );glVertex3f(-2.0f + menu.background_scroll[0].x_pos, 2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 1, 0 );glVertex3f( 2.0f + menu.background_scroll[0].x_pos, 2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 1, 1 );glVertex3f( 2.0f + menu.background_scroll[0].x_pos,-2.0f + menu.background_scroll[0].y_pos, 0.15f );
      glEnd();

      bind_texture(64); //background 02
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-2.0f + menu.background_scroll[1].x_pos,-2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 0, 0 );glVertex3f(-2.0f + menu.background_scroll[1].x_pos, 2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 1, 0 );glVertex3f( 2.0f + menu.background_scroll[1].x_pos, 2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 1, 1 );glVertex3f( 2.0f + menu.background_scroll[1].x_pos,-2.0f + menu.background_scroll[1].y_pos, 0.1f );
      glEnd();

      bind_texture(60); //logo - star map menu
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.9f, 0.75f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.9f, 1.0f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.9f, 1.0f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.9f, 0.75f, 0.0f );
      glEnd();

      if (menu.possition == 0) bind_texture(122+menu.level_no); //level choice 0 highlighted
      else                    bind_texture(97+menu.level_no); //level choice 0
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.95f, 0.4f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.95f, 0.6f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f(-0.35f, 0.6f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f(-0.35f, 0.4f, 0.0f );
      glEnd();

      if (game_o.level_locked[menu.level_no]) bind_texture(172); //level choice 0 game screen preview
      else bind_texture(147+menu.level_no); //level choice 0 game screen preview
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f(-0.35f, 0.3f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f(-0.35f,-0.3f, 0.0f );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.95f,-0.3f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.95f, 0.3f, 0.0f );
      glEnd();

      if (menu.possition == 1) bind_texture(123+menu.level_no); //level choice 1 highlighted
      else                    bind_texture(98+menu.level_no); //level choice 1
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.3f, 0.4f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.3f, 0.6f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.3f, 0.6f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.3f, 0.4f, 0.0f );
      glEnd();

      if (game_o.level_locked[menu.level_no+1]) bind_texture(172); //level choice 1 game screen preview
      else bind_texture(148+menu.level_no); //level choice 1 game screen preview
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.30f, 0.3f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.30f,-0.3f, 0.0f );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.30f,-0.3f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.30f, 0.3f, 0.0f );
      glEnd();

      if (menu.possition == 2) bind_texture(124+menu.level_no); //level choice 2 highlighted
      else                    bind_texture(99+menu.level_no); //level choice 2
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.35f, 0.4f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.35f, 0.6f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.95f, 0.6f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.95f, 0.4f, 0.0f );
      glEnd();

      if (game_o.level_locked[menu.level_no+2]) bind_texture(172); //level choice 2 game screen preview
      else bind_texture(149+menu.level_no); //level choice 2 game screen preview
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.95f, 0.3f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.95f,-0.3f, 0.0f );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.35f,-0.3f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.35f, 0.3f, 0.0f );
      glEnd();

      if (menu.possition == 3) bind_texture(27); //game menu highlighted
      else                    bind_texture(26); //game menu
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
      bind_texture(63); //background 01
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-2.0f + menu.background_scroll[0].x_pos,-2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 0, 0 );glVertex3f(-2.0f + menu.background_scroll[0].x_pos, 2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 1, 0 );glVertex3f( 2.0f + menu.background_scroll[0].x_pos, 2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 1, 1 );glVertex3f( 2.0f + menu.background_scroll[0].x_pos,-2.0f + menu.background_scroll[0].y_pos, 0.15f );
      glEnd();

      bind_texture(64); //background 02
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-2.0f + menu.background_scroll[1].x_pos,-2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 0, 0 );glVertex3f(-2.0f + menu.background_scroll[1].x_pos, 2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 1, 0 );glVertex3f( 2.0f + menu.background_scroll[1].x_pos, 2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 1, 1 );glVertex3f( 2.0f + menu.background_scroll[1].x_pos,-2.0f + menu.background_scroll[1].y_pos, 0.1f );
      glEnd();

      bind_texture(52); //logo - save game menu
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.9f, 0.75f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.9f, 1.0f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.9f, 1.0f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.9f, 0.75f, 0.0f );
      glEnd();

      if (menu.possition == 0) bind_texture(179); //game 0 highlighted
      else                    bind_texture(173); //game 0
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.4f, 0.4f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f, 0.6f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f, 0.6f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f, 0.4f, 0.0f );
      glEnd();

      if (menu.possition == 1) bind_texture(180); //game 1 highlighted
      else                    bind_texture(174); //game 1
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 1 );glVertex3f(-0.4f, 0.15f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f, 0.35f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f, 0.35f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f, 0.15f, 0.0f );
      glEnd();

      if (menu.possition == 2) bind_texture(181); //game 2 highlighted
      else                    bind_texture(175); //game 2
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 1 );glVertex3f(-0.4f,-0.1f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f, 0.1f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f, 0.1f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f,-0.1f, 0.0f );
      glEnd();

      if (menu.possition == 3) bind_texture(182); //game 3 highlighted
      else                    bind_texture(176); //game 3
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 1 );glVertex3f(-0.4f,-0.35f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f,-0.15f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f,-0.15f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f,-0.35f, 0.0f );
      glEnd();

      if (menu.possition == 4) bind_texture(183); //game 4 highlighted
      else                    bind_texture(177); //game 4
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 1 );glVertex3f(-0.4f,-0.6f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f,-0.4f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f,-0.4f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f,-0.6f, 0.0f );
      glEnd();

      if (menu.possition == 5) bind_texture(27); //game menu highlighted
      else                    bind_texture(26); //game menu
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
      bind_texture(63); //background 01
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-2.0f + menu.background_scroll[0].x_pos,-2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 0, 0 );glVertex3f(-2.0f + menu.background_scroll[0].x_pos, 2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 1, 0 );glVertex3f( 2.0f + menu.background_scroll[0].x_pos, 2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 1, 1 );glVertex3f( 2.0f + menu.background_scroll[0].x_pos,-2.0f + menu.background_scroll[0].y_pos, 0.15f );
      glEnd();

      bind_texture(64); //background 02
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-2.0f + menu.background_scroll[1].x_pos,-2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 0, 0 );glVertex3f(-2.0f + menu.background_scroll[1].x_pos, 2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 1, 0 );glVertex3f( 2.0f + menu.background_scroll[1].x_pos, 2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 1, 1 );glVertex3f( 2.0f + menu.background_scroll[1].x_pos,-2.0f + menu.background_scroll[1].y_pos, 0.1f );
      glEnd();

      bind_texture(29); //logo - load game menu
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.9f, 0.75f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.9f, 1.0f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.9f, 1.0f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.9f, 0.75f, 0.0f );
      glEnd();

      if (menu.possition == 0) bind_texture(179); //game 0 highlighted
      else                    bind_texture(173); //game 0
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.4f, 0.4f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f, 0.6f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f, 0.6f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f, 0.4f, 0.0f );
      glEnd();

      if (menu.possition == 1) bind_texture(180); //game 1 highlighted
      else                    bind_texture(174); //game 1
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 1 );glVertex3f(-0.4f, 0.15f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f, 0.35f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f, 0.35f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f, 0.15f, 0.0f );
      glEnd();

      if (menu.possition == 2) bind_texture(181); //game 2 highlighted
      else                    bind_texture(175); //game 2
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 1 );glVertex3f(-0.4f,-0.1f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f, 0.1f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f, 0.1f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f,-0.1f, 0.0f );
      glEnd();

      if (menu.possition == 3) bind_texture(182); //game 3 highlighted
      else                    bind_texture(176); //game 3
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 1 );glVertex3f(-0.4f,-0.35f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f,-0.15f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f,-0.15f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f,-0.35f, 0.0f );
      glEnd();

      if (menu.possition == 4) bind_texture(183); //game 4 highlighted
      else                    bind_texture(177); //game 4
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 1 );glVertex3f(-0.4f,-0.6f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f,-0.4f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f,-0.4f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f,-0.6f, 0.0f );
      glEnd();

      if (menu.possition == 5) bind_texture(27); //game menu highlighted
      else                    bind_texture(26); //game menu
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
      bind_texture(63); //background 01
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-2.0f + menu.background_scroll[0].x_pos,-2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 0, 0 );glVertex3f(-2.0f + menu.background_scroll[0].x_pos, 2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 1, 0 );glVertex3f( 2.0f + menu.background_scroll[0].x_pos, 2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 1, 1 );glVertex3f( 2.0f + menu.background_scroll[0].x_pos,-2.0f + menu.background_scroll[0].y_pos, 0.15f );
      glEnd();

      bind_texture(64); //background 02
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-2.0f + menu.background_scroll[1].x_pos,-2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 0, 0 );glVertex3f(-2.0f + menu.background_scroll[1].x_pos, 2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 1, 0 );glVertex3f( 2.0f + menu.background_scroll[1].x_pos, 2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 1, 1 );glVertex3f( 2.0f + menu.background_scroll[1].x_pos,-2.0f + menu.background_scroll[1].y_pos, 0.1f );
      glEnd();

      bind_texture(299); //logo - Achievements
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.9f, 0.75f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.9f, 1.0f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.9f, 1.0f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.9f, 0.75f, 0.0f );
      glEnd();

      bind_texture(301); //score
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.95f, 0.55f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.95f, 0.75f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f(-0.25f, 0.75f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f(-0.25f, 0.55f, 0.0f );
      glEnd();

      if (game_o.achivement.score >= 1) bind_texture(305); //score - star 1 (bronze)
      else                            bind_texture(304); //score - star 1 (grey)
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.25f, 0.55f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.25f, 0.75f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f(-0.05f, 0.75f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f(-0.05f, 0.55f, 0.0f );
      glEnd();

      if (game_o.achivement.score >= 2) bind_texture(306); //score - star 2 (silver)
      else                            bind_texture(304); //score - star 2 (grey)
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.00f, 0.55f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.00f, 0.75f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.20f, 0.75f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.20f, 0.55f, 0.0f );
      glEnd();

      if (game_o.achivement.score >= 3) bind_texture(307); //score - star 3 (gold)
      else                            bind_texture(304); //score - star 3 (grey)
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.25f, 0.55f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.25f, 0.75f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.45f, 0.75f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.45f, 0.55f, 0.0f );
      glEnd();

      if (game_o.achivement.score >= 4) bind_texture(307); //score - star 4 (gold)
      else                            bind_texture(304); //score - star 4 (grey)
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.50f, 0.55f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.50f, 0.75f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.70f, 0.75f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.70f, 0.55f, 0.0f );
      glEnd();

      if (game_o.achivement.score >= 5) bind_texture(307); //score - star 5 (gold)
      else                            bind_texture(304); //score - star 5 (grey)
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.75f, 0.55f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.75f, 0.75f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.95f, 0.75f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.95f, 0.55f, 0.0f );
      glEnd();

      bind_texture(303); //kills
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.95f, 0.10f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.95f, 0.30f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f(-0.25f, 0.30f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f(-0.25f, 0.10f, 0.0f );
      glEnd();

      if (game_o.achivement.kills >= 1) bind_texture(305); //score - star 1 (bronze)
      else                            bind_texture(304); //score - star 1 (grey)
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.25f, 0.10f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.25f, 0.30f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f(-0.05f, 0.30f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f(-0.05f, 0.10f, 0.0f );
      glEnd();

      if (game_o.achivement.kills >= 2) bind_texture(306); //score - star 2 (silver)
      else                            bind_texture(304); //score - star 2 (grey)
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.00f, 0.10f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.00f, 0.30f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.20f, 0.30f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.20f, 0.10f, 0.0f );
      glEnd();

      if (game_o.achivement.kills >= 3) bind_texture(307); //score - star 3 (gold)
      else                            bind_texture(304); //score - star 3 (grey)
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.25f, 0.10f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.25f, 0.30f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.45f, 0.30f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.45f, 0.10f, 0.0f );
      glEnd();

      if (game_o.achivement.kills >= 4) bind_texture(307); //score - star 4 (gold)
      else                            bind_texture(304); //score - star 4 (grey)
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.50f, 0.10f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.50f, 0.30f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.70f, 0.30f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.70f, 0.10f, 0.0f );
      glEnd();

      if (game_o.achivement.kills >= 5) bind_texture(307); //score - star 5 (gold)
      else                            bind_texture(304); //score - star 5 (grey)
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.75f, 0.10f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.75f, 0.30f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.95f, 0.30f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.95f, 0.10f, 0.0f );
      glEnd();

      if (menu.possition == 0) bind_texture(27); //game menu highlighted
      else                     bind_texture(26); //game menu
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
      bind_texture(84); //background 01
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-2.0f + menu.background_scroll[0].x_pos,-2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 0, 0 );glVertex3f(-2.0f + menu.background_scroll[0].x_pos, 2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 1, 0 );glVertex3f( 2.0f + menu.background_scroll[0].x_pos, 2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 1, 1 );glVertex3f( 2.0f + menu.background_scroll[0].x_pos,-2.0f + menu.background_scroll[0].y_pos, 0.15f );
      glEnd();

      bind_texture(73); //background 02
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-2.0f + menu.background_scroll[1].x_pos,-2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 0, 0 );glVertex3f(-2.0f + menu.background_scroll[1].x_pos, 2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 1, 0 );glVertex3f( 2.0f + menu.background_scroll[1].x_pos, 2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 1, 1 );glVertex3f( 2.0f + menu.background_scroll[1].x_pos,-2.0f + menu.background_scroll[1].y_pos, 0.1f );
      glEnd();

      bind_texture(330); //logo
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.9f, 0.75f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.9f, 1.0f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.9f, 1.0f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.9f, 0.75f, 0.0f );
      glEnd();

      bind_texture(329); //Game Over
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.4f, 0.55f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f, 0.75f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f, 0.75f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f, 0.55f, 0.0f );
      glEnd();

      bind_texture(332); //explosion
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.6f,-0.70f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.6f, 0.50f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.6f, 0.50f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.6f,-0.70f, 0.0f );
      glEnd();

      bind_texture(331); //Press any key to return to the main menu
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
      int level_t = game_o.level + 1;
      if (level_t > 24) level_t = 24;
      bind_texture(63); //background 01
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-2.0f + menu.background_scroll[0].x_pos,-2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 0, 0 );glVertex3f(-2.0f + menu.background_scroll[0].x_pos, 2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 1, 0 );glVertex3f( 2.0f + menu.background_scroll[0].x_pos, 2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 1, 1 );glVertex3f( 2.0f + menu.background_scroll[0].x_pos,-2.0f + menu.background_scroll[0].y_pos, 0.15f );
      glEnd();

      bind_texture(64); //background 02
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-2.0f + menu.background_scroll[1].x_pos,-2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 0, 0 );glVertex3f(-2.0f + menu.background_scroll[1].x_pos, 2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 1, 0 );glVertex3f( 2.0f + menu.background_scroll[1].x_pos, 2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 1, 1 );glVertex3f( 2.0f + menu.background_scroll[1].x_pos,-2.0f + menu.background_scroll[1].y_pos, 0.1f );
      glEnd();

      bind_texture(30); //logo
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.9f, 0.75f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.9f, 1.0f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.9f, 1.0f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.9f, 0.75f, 0.0f );
      glEnd();

      bind_texture(333); //Congratulations
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.5f, 0.55f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.5f, 0.75f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.5f, 0.75f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.5f, 0.55f, 0.0f );
      glEnd();

      if (game_o.level_locked[level_t])
      {
         bind_texture(335); //level unlocked
         glLoadIdentity();
         glBegin( GL_QUADS );
	     glTexCoord2i( 0, 1 );glVertex3f(-0.5f, 0.35f, 0.0f );
	     glTexCoord2i( 0, 0 );glVertex3f(-0.5f, 0.55f, 0.0f );
	     glTexCoord2i( 1, 0 );glVertex3f( 0.5f, 0.55f, 0.0f );
   	     glTexCoord2i( 1, 1 );glVertex3f( 0.5f, 0.35f, 0.0f );
         glEnd();
      }

      bind_texture(147+level_t); //next level game screen preview
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.5f,-0.70f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.5f, 0.30f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.5f, 0.30f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.5f,-0.70f, 0.0f );
      glEnd();

      bind_texture(334); //Press any key to continue
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.8f,-0.95f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.8f,-0.75f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.8f,-0.75f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.8f,-0.95f, 0.0f );
      glEnd();

      font.font_1.Write(255,255,255,64,-1.00f,-0.00f,"Level score - ", game_o.level_score);
      font.font_1.Write(255,255,255,64,-1.00f,-0.10f,"Total score - ", game_o.score);
      font.font_1.Write(255,255,255,64,-1.00f,-0.20f,"Level kills - ", game_o.level_kills);
      font.font_1.Write(255,255,255,64,-1.00f,-0.30f,"Total kills - ", game_o.kills);
      font.font_1.Write(255,255,255,64,-1.00f,-0.40f,"Kill rate   - ./'",(((float)game_o.level_kills/(float)game_o.level_spawened)*100));
   }
/*-----------------------------------------------------------------------------*/
   if (menu.level == 10) //Outro screen
   {
      int level_t = game_o.level + 1;
      if (level_t > 24) level_t = 24;
      bind_texture(63); //background 01
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-2.0f + menu.background_scroll[0].x_pos,-2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 0, 0 );glVertex3f(-2.0f + menu.background_scroll[0].x_pos, 2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 1, 0 );glVertex3f( 2.0f + menu.background_scroll[0].x_pos, 2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 1, 1 );glVertex3f( 2.0f + menu.background_scroll[0].x_pos,-2.0f + menu.background_scroll[0].y_pos, 0.15f );
      glEnd();

      bind_texture(64); //background 02
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-2.0f + menu.background_scroll[1].x_pos,-2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 0, 0 );glVertex3f(-2.0f + menu.background_scroll[1].x_pos, 2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 1, 0 );glVertex3f( 2.0f + menu.background_scroll[1].x_pos, 2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 1, 1 );glVertex3f( 2.0f + menu.background_scroll[1].x_pos,-2.0f + menu.background_scroll[1].y_pos, 0.1f );
      glEnd();

      bind_texture(30); //logo
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.9f, 0.75f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.9f, 1.0f,  0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.9f, 1.0f,  0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.9f, 0.75f, 0.0f );
      glEnd();

      bind_texture(334); //Press any key to continue
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.8f,-0.95f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.8f,-0.75f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.8f,-0.75f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.8f,-0.95f, 0.0f );
      glEnd();

      bind_texture(339); //credits
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
