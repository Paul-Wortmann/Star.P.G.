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


#include <SDL/SDL.h>
#include <SDL/SDL_main.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_net.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_opengl.h>
#include <gl/gl.h>
//#include <physfs.h>
#include "misc.h"
#include "main.h"
#include "config.h"
#include "sounds.h"
#include "music.h"
#include "textures.h"
#include "menu.h"
#include "game.h"
#include "levels.h"
#include "physics.h"
#include "font.h"
#include "savegame.h"
#include "timer.h"
#include "network.h"
#include "version.h"

extern config_data_type config_data;
extern sound_type sound[MAX_SOUNDS];
extern music_type music[MAX_MUSIC];
extern texture_type texture[MAX_TEXTURES];
extern menu_type menu;
extern game_type game;

const char App_Name[] = ("Star.P.G V0.17 - www.physhexgames.co.nr");
const char App_Icon[] = "data/icon.bmp";
const char App_Conf[] = "Star.P.G..cfg";
const char App_Logf[] = "Star.P.G..log";

Uint32                   colorkey;
SDL_Surface             *App_Icon_Surface;
Uint8                   *keys;
SDL_Event                event;
Uint8                   *keystate = SDL_GetKeyState(NULL);
int                      menu_level_pos = 0;
timer                    fps;

int init_gl(void)
{
  glViewport(0, 0,config_data.Display_X_Resolution,config_data.Display_Y_Resolution);
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  glClearDepth(1.0);
  glDepthFunc(GL_LESS);
  glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
  glEnable(GL_BLEND);
  glEnable(GL_DEPTH_TEST);
  glShadeModel(GL_SMOOTH);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glEnable(GL_TEXTURE_2D);
  return(0);
}

//----------------------------------- Main -------------------------------------
int main(int argc, char *argv[])
{
  Init_Log_File(App_Logf);
  for (int count = 0; count < (argc+1); count++)
  {
     Log_File(App_Logf,argv[count]);
     if (argv[count] == "cheat") game.cheats_enabled = true;
  }
  game.cheats_enabled = true; /// test!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  Log_File(App_Logf,"------------------");
  Log_File(App_Logf,"| Star.P.G V0.17 |");
  Log_File(App_Logf,"------------------\n");
  Log_File(App_Logf,"Booting up!");
  Log_File(App_Logf,"------------------\n");
  if (game.cheats_enabled) Log_File(App_Logf,"Cheating enabled!\n");
  Load_Default_Config();
  Log_File(App_Logf,"Loading config...");
  Load_Config_File(App_Conf);
 //----------------------------------- Start the PhysicsFS ----------------------
  //Log_File(App_Logf,"Starting PhysicsFS...");
  //PHYSFS_init(argv[0]);
  //PHYSFS_addToSearchPath("Star.P.G..spg", 1);
//----------------------------------- SDL Video --------------------------------
  Log_File(App_Logf,"Starting SDL...");
  putenv("SDL_VIDEO_WINDOW_POS");
  putenv("SDL_VIDEO_CENTERED=1");
  getenv("SDL_VIDEO_WINDOW_POS");
  getenv("SDL_VIDEO_CENTERED");
  SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTTHREAD);
  Log_File(App_Logf,"Starting OpenGL...");
  if (config_data.Display_Fullscreen) SDL_SetVideoMode(config_data.Display_X_Resolution,config_data.Display_Y_Resolution,config_data.Display_BPS,SDL_OPENGL | SDL_FULLSCREEN);
    else SDL_SetVideoMode(config_data.Display_X_Resolution,config_data.Display_Y_Resolution,config_data.Display_BPS,SDL_OPENGL/* | SDL_NOFRAME/* | SDL_FULLSCREEN */);
  SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );
  App_Icon_Surface = SDL_LoadBMP(App_Icon);
  colorkey = SDL_MapRGB(App_Icon_Surface->format, 255, 0, 255);
  SDL_SetColorKey(App_Icon_Surface, SDL_SRCCOLORKEY, colorkey);
  SDL_WM_SetIcon(App_Icon_Surface,NULL);
  SDL_WM_SetCaption(App_Name, 0);
  SDL_ShowCursor(SDL_DISABLE);
//----------------------------------- SDL Audio --------------------------------
  Log_File(App_Logf,"Starting sound system...");
  SDL_Init(SDL_INIT_AUDIO);
  Mix_AllocateChannels(config_data.Audio_Channels);
  Mix_OpenAudio(config_data.Audio_Rate, AUDIO_S16, 2, config_data.Audio_Buffers);
  Mix_Volume(-1,config_data.Audio_Sound_Volume);
  Mix_VolumeMusic(config_data.Audio_Music_Volume);
  Log_File(App_Logf,"Initializing joystick / gamepad...");
  SDL_Init(SDL_INIT_JOYSTICK);
  SDL_Joystick *joystick;
  SDL_JoystickEventState(SDL_ENABLE);
  joystick = SDL_JoystickOpen(0);
  game.joystick_sensitivity     = 6400;
  Log_File(App_Logf,"Loading fonts...");
  Init_Font();
  Log_File(App_Logf,"Loading sounds...");
  init_sounds();
  load_sounds();
  Log_File(App_Logf,"Loading music...");
  init_music();
  load_music();
  Log_File(App_Logf,"Loading textures...");
  init_textures();
  load_textures();
  Log_File(App_Logf,"Initializing menu system...");
  init_menu();
  Log_File(App_Logf,"Initializing game system...");
  init_game();
  Log_File(App_Logf,"Initializing projectiles...");
  init_player_bullets();
  Log_File(App_Logf,"Initializing explosions...");
  init_explosions();
  Log_File(App_Logf,"Initializing NPCs...\n");
  init_active_npcs();
  init_npc_bullets();
  init_npcs(0);
  game.level = 0;
  init_gl();
  seed_rand();
  Log_File(App_Logf,"Starting game...");
  Log_File(App_Logf,"---------------\n");
//----------------------------------- Main loop --------------------------------
  for(int quit = 0; !quit;)
  {
     fps.start();
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//****************************************** MENU *****************************************
     if (game.menu_active)
     {
        play_music(game.menu_music_track);
        glPushMatrix();
        diplay_menu ();
        glPopMatrix();
        SDL_GL_SwapBuffers();
        process_menu();
        //--- proccess keyboard events ---
        while ( SDL_PollEvent(&event) )
        {
           if ( event.type == SDL_QUIT ) quit = 1;
           if ( event.type == SDL_KEYDOWN )
           {
              if ( event.key.keysym.sym == SDLK_ESCAPE )
              {
                 play_sound(1);
                 switch (menu.level)
                 {
                    case 0://main menu
                       quit = 1;
                       Log_File(App_Logf,"User terminating game - used escape key!");
                    break;
                    case 1://game menu
                       menu.possition = 0;
                       menu.level = 0;
                       menu.possition_max = 4;
                       Log_File(App_Logf,"Entering 'main' menu.");
                    break;
                    case 2: // options menu
                       menu.possition = 3;
                       menu.level = 0;
                       menu.possition_max = 4;
                       Log_File(App_Logf,"Entering 'main' menu.");
                    break;
                    case 3: // customize starship menu
                       menu.possition = 2;
                       menu.level = 1;
                       menu.possition_max = 6;
                       Log_File(App_Logf,"Entering 'new game' menu.");
                    break;
                    case 4: // star map menu
                       menu.possition = 0;
                       menu.level = 1;
                       menu.possition_max = 6;
                       Log_File(App_Logf,"Entering 'new game' menu.");
                    break;
                    case 5: // save game menu
                       menu.possition = 4;
                       menu.level = 1;
                       menu.possition_max = 6;
                       Log_File(App_Logf,"Entering 'new game' menu.");
                    break;
                    case 6: // load game menu
                       menu.possition = 5;
                       menu.level = 1;
                       menu.possition_max = 6;
                       Log_File(App_Logf,"Entering 'new game' menu.");
                    break;
                    case 7: // Achievements menu
                       menu.possition = 1;
                       menu.level = 1;
                       menu.possition_max = 6;
                       Log_File(App_Logf,"Entering 'new game' menu.");
                    break;
                    default:
                       quit = 1;
                 }
              }
              if ( event.key.keysym.sym == SDLK_UP     )
              {
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
                    menu.possition = menu_level_pos;
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
              if ( event.key.keysym.sym == SDLK_DOWN   )
              {
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
                    menu_level_pos = menu.possition;
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
              if ( event.key.keysym.sym == SDLK_LEFT   )
              {
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
              if ( event.key.keysym.sym == SDLK_RIGHT   )
              {
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
              if ((event.key.keysym.sym == SDLK_RETURN) || (event.key.keysym.sym == SDLK_SPACE))
              {
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
                                Log_File(App_Logf,"Entering 'new game' menu.");
                             break;
                             case 1://resume game
                                if (game.game_resume)
                                {
                                   game.game_active = true;
                                   game.menu_active = false;
                                   Log_File(App_Logf,"Resuming game.");
                                }
                             break;
                             case 2://load game
                                menu.possition = 0;
                                menu.level = 6;
                                menu.possition_max = 5;
                                Log_File(App_Logf,"Entering 'load game' menu.");
                             break;
                             case 3://options
                                menu.possition = 0;
                                menu.level = 2;
                                menu.possition_max = 4;
                                Log_File(App_Logf,"Entering 'options game' menu.");
                            break;
                             case 4://quit game
                                Log_File(App_Logf,"User terminating game - via menu system.");
                                quit = 1;
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
                                Log_File(App_Logf,"Entering 'star map' menu.");
                             break;
                             case 1://achievements
                                menu.possition = 0;
                                menu.level = 7;
                                menu.possition_max = 0;
                                Log_File(App_Logf,"Entering 'Achievements' menu.");
                             break;
                             case 2://customize starship
                                menu.possition = 0;
                                menu.level = 3;
                                menu.possition_max = 4;
                                Log_File(App_Logf,"Entering 'customize starship' menu.");
                             break;
                             case 3://resume game
                                if (game.game_resume)
                                {
                                   game.game_active = true;
                                   game.menu_active = false;
                                   Log_File(App_Logf,"Resuming game.");
                                }
                             break;
                             case 4://save game
                                if (game.game_resume)
                                {
                                   menu.possition = 0;
                                   menu.level = 5;
                                   menu.possition_max = 5;
                                   Log_File(App_Logf,"Entering 'save game' menu.");
                                }
                             break;
                             case 5://load game
                                menu.possition = 0;
                                menu.level = 6;
                                menu.possition_max = 5;
                                Log_File(App_Logf,"Entering 'load game' menu.");
                             break;
                             case 6://main menu
                                menu.possition = 0;
                                menu.level = 0;
                                menu.possition_max = 4;
                                Log_File(App_Logf,"Entering 'main' menu.");
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
                                Log_File(App_Logf,"Entering 'main' menu.");
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
                                Log_File(App_Logf,"Entering 'game' menu.");
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
                                   Log_File(App_Logf,"Starting level ");
                                }
                             break;
                             case 1://level x+1 select
                                if (!game.level_locked[menu.level_no + 1])
                                {
                                   game.level = menu.level_no + 1;
                                   init_game_level(game.level);
                                   game.game_active = true;
                                   game.menu_active = false;
                                   Log_File(App_Logf,"Starting level ");
                                }
                             break;
                             case 2://level x+2 select
                                if (!game.level_locked[menu.level_no + 2])
                                {
                                   game.level = menu.level_no + 2;
                                   init_game_level(game.level);
                                   game.game_active = true;
                                   game.menu_active = false;
                                   Log_File(App_Logf,"Starting level ");
                                }
                             break;
                             case 3://game menu
                                menu.possition = 0;
                                menu.level = 1;
                                menu.possition_max = 6;
                                Log_File(App_Logf,"Entering 'game' menu.");
                             break;
                          }
                        break;
                    case 5: // save game menu
                       switch (menu.possition)
                          {
                             case 0://save to slot 0
                                Save_Game(0);
                                Log_File(App_Logf,"Saving to slot 0");
                                spawn_saved();
                                menu.possition = 3;
                                menu.level = 1;
                                menu.possition_max = 5;
                                game.game_active = true;
                                game.menu_active = false;
                                Log_File(App_Logf,"Resuming game");
                             break;
                             case 1://save to slot 1
                                Save_Game(1);
                                Log_File(App_Logf,"Saving to slot 1");
                                spawn_saved();
                                menu.possition = 3;
                                menu.level = 1;
                                menu.possition_max = 5;
                                game.game_active = true;
                                game.menu_active = false;
                                Log_File(App_Logf,"Resuming game");
                             break;
                             case 2://save to slot 2
                                Save_Game(2);
                                Log_File(App_Logf,"Saving to slot 2");
                                spawn_saved();
                                menu.possition = 3;
                                menu.level = 1;
                                menu.possition_max = 5;
                                game.game_active = true;
                                game.menu_active = false;
                                Log_File(App_Logf,"Resuming game");
                             break;
                             case 3://save to slot 3
                                Save_Game(3);
                                Log_File(App_Logf,"Saving to slot 3");
                                spawn_saved();
                                menu.possition = 3;
                                menu.level = 1;
                                menu.possition_max = 5;
                                game.game_active = true;
                                game.menu_active = false;
                                Log_File(App_Logf,"Resuming game");
                             break;
                             case 4://save to slot 4
                                Save_Game(4);
                                Log_File(App_Logf,"Saving to slot 4");
                                spawn_saved();
                                menu.possition = 3;
                                menu.level = 1;
                                menu.possition_max = 5;
                                game.game_active = true;
                                game.menu_active = false;
                                Log_File(App_Logf,"Resuming game");
                             break;
                             case 5://game menu
                                menu.possition = 4;
                                menu.level = 1;
                                menu.possition_max = 6;
                                Log_File(App_Logf,"Entering 'game' menu.");
                            break;
                          }
                       break;
                    case 6: // load game menu
                       switch (menu.possition)
                          {
                             case 0://load from slot 0
                                if (Load_Game(0) == 0)
                                {
                                   Log_File(App_Logf,"Loading from slot 0");
                                   spawn_loaded();
                                   menu.possition = 3;
                                   menu.level = 1;
                                   menu.possition_max = 5;
                                   game.game_active = true;
                                   game.menu_active = false;
                                   Log_File(App_Logf,"Resuming game");
                                }
                                else Log_File(App_Logf,"Error loadng from slot 0");
                             break;
                             case 1://load from slot 1
                                if (Load_Game(1) == 0)
                                {
                                   Log_File(App_Logf,"Loading from slot 1");
                                   spawn_loaded();
                                   menu.possition = 3;
                                   menu.level = 1;
                                   menu.possition_max = 5;
                                   game.game_active = true;
                                   game.menu_active = false;
                                   Log_File(App_Logf,"Resuming game");
                                }
                                else Log_File(App_Logf,"Error loadng from slot 1");
                             break;
                             case 2://load from slot 2
                                if (Load_Game(2) == 0)
                                {
                                   Log_File(App_Logf,"Loading from slot 2");
                                   spawn_loaded();
                                   menu.possition = 3;
                                   menu.level = 1;
                                   menu.possition_max = 5;
                                   game.game_active = true;
                                   game.menu_active = false;
                                   Log_File(App_Logf,"Resuming game");
                                }
                                else Log_File(App_Logf,"Error loadng from slot 2");
                             break;
                             case 3://load from slot 3
                                if (Load_Game(3) == 0)
                                {
                                   Log_File(App_Logf,"Loading from slot 3");
                                   spawn_loaded();
                                   menu.possition = 3;
                                   menu.level = 1;
                                   menu.possition_max = 5;
                                   game.game_active = true;
                                   game.menu_active = false;
                                   Log_File(App_Logf,"Resuming game");
                                }
                                else Log_File(App_Logf,"Error loadng from slot 3");
                             break;
                             case 4://load from slot 4
                                if (Load_Game(4) == 0)
                                {
                                   Log_File(App_Logf,"Loading from slot 4");
                                   spawn_loaded();
                                   menu.possition = 3;
                                   menu.level = 1;
                                   menu.possition_max = 5;
                                   game.game_active = true;
                                   game.menu_active = false;
                                   Log_File(App_Logf,"Resuming game");
                                }
                                else Log_File(App_Logf,"Error loadng from slot 4");
                             break;
                             case 5://game menu
                                menu.possition = 5;
                                menu.level = 1;
                                menu.possition_max = 6;
                                Log_File(App_Logf,"Entering 'game' menu.");
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
                                Log_File(App_Logf,"Entering 'game' menu.");
                             break;
                          }
                       break;
                    default:
                       play_sound(1);
                 }
              }
           }
        }
        if (keystate[SDLK_LEFT])
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
        }
        if (keystate[SDLK_RIGHT])
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
        }
//        keys = SDL_GetKeyState(NULL);
       }
//****************************************** GAME *****************************************
        if (game.game_active)
        {
           game.game_resume = true;
           play_music(game.music_track);
           process_game();
           display_game();
           if (game.player.health < 0)
           {
              play_sound(1);
              game.game_active = false;
              game.game_resume = false;
              game.pdie_active = true;
              menu.level = 8;
              Log_File(App_Logf,"User terminated due to insuficient health...better luck next time buddy!");
           }
        //--- proccess keyboard events ---
        while ( SDL_PollEvent(&event) )
        {
    //-------------------------- joystick / gamepad events --------------------------------------------
       if (event.type == SDL_JOYAXISMOTION)
       {
          if ((event.jaxis.value < (-1*(game.joystick_sensitivity))) || (event.jaxis.value > game.joystick_sensitivity))
          {
             if (event.jaxis.axis == 0)
             {
                if(event.jaxis.value < -(-1*(game.joystick_sensitivity)))
                {
                   game.button_left  = true;
                   game.button_right = false;
                }
                if(event.jaxis.value > game.joystick_sensitivity)
                {
                   game.button_left  = false;
                   game.button_right = true;
                }
             }
             if (event.jaxis.axis == 1)
             {
                if(event.jaxis.value < -(-1*(game.joystick_sensitivity)))
                {
                   game.button_up    = true;
                   game.button_down  = false;
                }
                if(event.jaxis.value > game.joystick_sensitivity)
                {
                   game.button_up    = false;
                   game.button_down  = true;
                }
             }
          }
          else
          {
               game.button_up    = false;
               game.button_down  = false;
               game.button_left  = false;
               game.button_right = false;
          }
       }
       if (event.type == SDL_JOYHATMOTION)
       {
          if (event.jhat.value & SDL_HAT_UP)
          {
              game.button_up    = true;
              game.button_down  = false;
              game.button_left  = false;
              game.button_right = false;
          }
          if (event.jhat.value & SDL_HAT_DOWN)
          {
              game.button_up    = false;
              game.button_down  = true;
              game.button_left  = false;
              game.button_right = false;
          }
          if (event.jhat.value & SDL_HAT_RIGHT)
          {
              game.button_up    = false;
              game.button_down  = false;
              game.button_left  = false;
              game.button_right = true;
          }
          if (event.jhat.value & SDL_HAT_RIGHTUP)
          {
              game.button_up    = true;
              game.button_down  = false;
              game.button_left  = false;
              game.button_right = true;
          }
          if (event.jhat.value & SDL_HAT_RIGHTDOWN)
          {
              game.button_up    = false;
              game.button_down  = true;
              game.button_left  = false;
              game.button_right = true;
          }
          if (event.jhat.value & SDL_HAT_LEFT)
          {
              game.button_up    = false;
              game.button_down  = false;
              game.button_left  = true;
              game.button_right = false;
          }
          if (event.jhat.value & SDL_HAT_LEFTUP)
          {
              game.button_up    = true;
              game.button_down  = false;
              game.button_left  = true;
              game.button_right = false;
          }
          if (event.jhat.value & SDL_HAT_LEFTDOWN)
          {
              game.button_up    = false;
              game.button_down  = true;
              game.button_left  = true;
              game.button_right = false;
          }
          if (event.jhat.value & SDL_HAT_CENTERED)
          {
              game.button_up    = false;
              game.button_down  = false;
              game.button_left  = false;
              game.button_right = false;
         }
       }
       if (event.type == SDL_JOYBUTTONDOWN)
       {
           switch(event.jbutton.button)
           {
              case 0:
                game.gamepad_button_0 = true;
              break;
              case 1:
                game.gamepad_button_1 = true;
              break;
              case 2:
                game.gamepad_button_2 = true;
              break;
              case 3:
                game.gamepad_button_3 = true;
              break;
              default:
              break;
           }
       }
       if (event.type == SDL_JOYBUTTONUP)
       {
           switch(event.jbutton.button)
           {
              case 0:
                game.gamepad_button_0 = false;
              break;
              case 1:
                game.gamepad_button_1 = false;
              break;
              case 2:
                game.gamepad_button_2 = false;
              break;
              case 3:
                game.gamepad_button_3 = false;
              break;
              default:
              break;
           }
       }
           if ( event.type == SDL_QUIT ) quit = 1;
           if ( event.type == SDL_KEYDOWN )
           {
              if ((event.key.keysym.sym == SDLK_ESCAPE) || (game.gamepad_button_3))
              {
                 play_sound(1);
                 game.game_active   = false;
                 menu.level         = 1;
                 menu.possition     = 3;
                 menu.possition_max = 6;
                 game.menu_active   = true;
              }
              if ( event.key.keysym.sym == SDLK_SPACE  ) {};
              if ( event.key.keysym.sym == SDLK_p      )
              {
                 game.game_paused = true;
                 game.game_active = false;
                 spawn_paused();
              };
              //if (game.cheats_enabled == true)
              {
                 if (event.key.keysym.sym == SDLK_b)    spawn_powerup(1.0f,random_GLcoord(), 8);//spawn bomb powerup
                 if (event.key.keysym.sym == SDLK_u)    spawn_powerup(1.0f,random_GLcoord(), 9);//spawn sideship 0 powerup
                 if (event.key.keysym.sym == SDLK_i)    spawn_powerup(1.0f,random_GLcoord(),10);//spawn sideship 1 powerup
                 if (event.key.keysym.sym == SDLK_o)    spawn_powerup(1.0f,random_GLcoord(),11);//spawn sideship 2 powerup
                 if (event.key.keysym.sym == SDLK_p)    spawn_powerup(1.0f,random_GLcoord(),12);//spawn sideship 3 powerup
                 if (event.key.keysym.sym == SDLK_1)    spawn_powerup(1.0f,random_GLcoord(), 1);//spawn health powerup
                 if (event.key.keysym.sym == SDLK_2)    spawn_powerup(1.0f,random_GLcoord(), 2);//spawn shield lvl powerup
                 if (event.key.keysym.sym == SDLK_3)    spawn_powerup(1.0f,random_GLcoord(), 3);//spawn shield new powerup
                 if (event.key.keysym.sym == SDLK_4)    spawn_powerup(1.0f,random_GLcoord(), 4);//spawn thruster lvl powerup
                 if (event.key.keysym.sym == SDLK_5)    spawn_powerup(1.0f,random_GLcoord(), 5);//spawn thruster new powerup
                 if (event.key.keysym.sym == SDLK_6)    spawn_powerup(1.0f,random_GLcoord(), 6);//spawn weapon lvl powerup
                 if (event.key.keysym.sym == SDLK_7)    spawn_powerup(1.0f,random_GLcoord(), 7);//spawn weapon new powerup
                 if (event.key.keysym.sym == SDLK_8)    unlock_levels();                        //unlock all levels
                 if (event.key.keysym.sym == SDLK_0)    game.victory_kills = game.level_kills;  //complete level
                 if (event.key.keysym.sym == SDLK_a)    game.anc_enabled   = !game.anc_enabled; //toggle active NPC count display
                 if (event.key.keysym.sym == SDLK_f)    game.fps_enabled   = !game.fps_enabled; //toggle active NPC count display
              }
           }
        }
        if ((keystate[SDLK_SPACE]) || (game.gamepad_button_0))
        {
           process_sideships(true);
           if(game.fw_rof_count >= game.projectile[game.player.front_weapon].rate_of_fire)
           {
              spawn_player_bullet(0);
              game.fw_rof_count = 0;
           }
           if(game.sw_rof_count >= game.projectile[game.player.side_weapon].rate_of_fire)
           {
              spawn_player_bullet(1);
              game.sw_rof_count = 0;
           }
        }
        else
        {
            process_sideships(false);
        }
        if ((keystate[SDLK_UP]    || (keystate[SDLK_w]) || (game.button_up)))    process_player(1);
        if ((keystate[SDLK_DOWN]  || (keystate[SDLK_s]) || (game.button_down)))  process_player(2);
        if ((keystate[SDLK_RIGHT] || (keystate[SDLK_d]) || (game.button_right))) process_player(3);
        if ((keystate[SDLK_LEFT]  || (keystate[SDLK_a]) || (game.button_left)))  process_player(4);
//    keys = SDL_GetKeyState(NULL);
     }
//*********************************** Game paused *****************************************
     if (game.game_paused)
     {
        play_music(game.music_track);
        display_game();
        //--- proccess keyboard events ---
        while (SDL_PollEvent(&event))
        {
           if ( event.type == SDL_QUIT ) quit = 1;
           if ( event.type == SDL_KEYDOWN )
           {
              if ((event.key.keysym.sym == SDLK_ESCAPE) || (event.key.keysym.sym == SDLK_RETURN) || (event.key.keysym.sym == SDLK_SPACE))
              {
                 game.game_paused = false;
                 game.game_active = true;
              }
              if ( event.key.keysym.sym == SDLK_p      )
              {
                 game.game_paused = false;
                 game.game_active = true;
              };
           }
        }
     }
//*********************************** PLAYER DEATH SCREEN *****************************************
     if (game.pdie_active)
     {
        play_music(game.pdie_music_track);
        glPushMatrix();
        diplay_menu ();
        process_menu();
        glPopMatrix();
        SDL_GL_SwapBuffers();
        //--- proccess keyboard events ---
        while (SDL_PollEvent(&event))
        {
           if ( event.type == SDL_QUIT ) quit = 1;
           if ( event.type == SDL_KEYDOWN )
           {
              if ((event.key.keysym.sym == SDLK_ESCAPE) || (event.key.keysym.sym == SDLK_RETURN) || (event.key.keysym.sym == SDLK_SPACE))
              {
                 play_sound(1);
                 init_game();
                 menu.level = 0;
                 menu.possition = 0;
                 menu.possition_max = 4;
                 game.menu_active = true;
                 game.pdie_active = false;
              }
           }
        }
     }
//******************************* PLAYER NEXT LEVEL SCREEN *************************************
     if (game.nlvl_active)
     {
        bool outro_time = false;
        play_music  (game.nlvl_music_track);
        glPushMatrix();
        menu.level = 9;
        diplay_menu ();
        process_menu();
        glPopMatrix ();
        SDL_GL_SwapBuffers();
        //--- proccess keyboard events ---
        while (SDL_PollEvent(&event))
        {
           if ( event.type == SDL_QUIT ) quit = 1;
           if ( event.type == SDL_KEYDOWN )
           {
              if ((event.key.keysym.sym == SDLK_ESCAPE) || (event.key.keysym.sym == SDLK_RETURN) || (event.key.keysym.sym == SDLK_SPACE))
              {
                 play_sound(1);
                 game.level++;
                 if (game.level > 24) // killed last boss!
                 {
                     outro_time = true;
                     game.level = 24;
                     if (!game.completed)
                     {
                         for(int count = 0; count < MAX_ENEMYS; count++) //finished the game, now its twice as hard! ;)
                         {
                            game.enemy[count].health += game.enemy[count].health;
                            if (game.enemy[count].health > 65535) game.enemy[count].health = 65535;
                         }
                         game.completed = true;
                     }
                 }
                 if (game.level_locked[game.level]) game.level_locked[game.level] = false;
                 init_game_level(game.level);
                 if (outro_time)
                 {
                    game.outr_active = true;
                    game.game_active = false;
                    game.menu_active = false;
                    game.nlvl_active = false;
                    Log_File(App_Logf,"Player just completed the game, proceeding to Outro!");
                 }
                 else
                 {
                    game.game_active = true;
                    game.menu_active = false;
                    game.nlvl_active = false;
                    Log_File(App_Logf,"Victory conditions met, player proceeding to next level!");
                 }
              }
           }
        }
     }

//******************************* OUTRO SCREEN *************************************************
     if (game.outr_active)
     {
        play_music  (game.outro_music_track);
        glPushMatrix();
        menu.level = 10;
        diplay_menu ();
        process_menu();
        glPopMatrix ();
        SDL_GL_SwapBuffers();
        //--- proccess keyboard events ---
        while (SDL_PollEvent(&event))
        {
           if ( event.type == SDL_QUIT ) quit = 1;
           if ( event.type == SDL_KEYDOWN )
           {
              if ((event.key.keysym.sym == SDLK_ESCAPE) || (event.key.keysym.sym == SDLK_RETURN) || (event.key.keysym.sym == SDLK_SPACE))
              {
                 play_sound(1);
                 menu.level = 1;
                 menu.possition = 0;
                 menu.possition_max = 6;
                 game.game_resume = false;
                 game.pdie_active = false;
                 game.outr_active = false;
                 game.game_active = false;
                 game.menu_active = true;
                 game.nlvl_active = false;
                 Log_File(App_Logf,"Outro finished, proceeding to main menu!");
              }
           }
        }
    }
//---------------------------- code for end of main loop -----------------------
     game.FPS += fps.getticks();
     game.FPS  = 1000 - (game.FPS / 2);
     fps.stop();
//----------------------------------- Exit -------------------------------------
  }
  Log_File(App_Logf,"\n");
  Log_File(App_Logf,"Shuting down...");
  Log_File(App_Logf,"---------------\n");
  Log_File(App_Logf,"Saving config...");
  Save_Config_File(App_Conf);
  Log_File(App_Logf,"Unloading textures...");
  kill_textures();
  Log_File(App_Logf,"Unloading fonts...");
  Kill_Font();
  Log_File(App_Logf,"Shuting down audio system...");
  Mix_CloseAudio();
  Log_File(App_Logf,"Unloading music...");
  kill_music();
  Log_File(App_Logf,"Unloading sounds...");
  kill_sounds();
//  Log_File(App_Logf,"PhysicsFS deinit...");
//  PHYSFS_deinit();
  Log_File(App_Logf,"SDL deinit...");
  SDL_Quit();
  return(0);
}

