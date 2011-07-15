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
 * @version 0.16
 */

#include <SDL/SDL.h>
#include <SDL/SDL_main.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_net.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_opengl.h>
#include <gl/gl.h>
//#include <physfs.h>
#include "graphics.hpp"
#include "misc.hpp"
#include "main.hpp"
#include "config.hpp"
#include "log.hpp"
#include "sounds.hpp"
#include "music.hpp"
#include "textures.hpp"
#include "menu.hpp"
#include "game.hpp"
#include "levels.hpp"
#include "physics.hpp"
#include "font.hpp"
#include "savegame.hpp"
#include "timer.hpp"
#include "network.hpp"
#include "version.h"
#include "io.hpp"

extern config_data_type  config_data;
extern sound_type        sound[MAX_SOUNDS];
extern music_type        music[MAX_MUSIC];
extern texture_type      texture[MAX_TEXTURES];
extern menu_type         menu;
extern game_type         game;
extern log_file_class    main_log;

const char App_Name[] = ("Star.P.G V0.17 - www.physhexgames.co.nr");
const char App_Icon[] = "data/icon.bmp";
const char App_Conf[] = "Star.P.G..cfg";

Uint32                   colorkey;
SDL_Surface             *App_Icon_Surface;
timer                    fps;

//----------------------------------- Main -------------------------------------
int main(int argc, char *argv[])
{
  events_init();
  main_log.File_Set("Star.P.G..log");
  main_log.File_Clear();
  for (int count = 0; count < (argc+1); count++)
  {
     main_log.File_Write(argv[count]);
     if (argv[count] == "cheat") game.cheats_enabled = true;
  }
  game.cheats_enabled = true; /// test!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

  main_log.File_Write("------------------");
  main_log.File_Write("| Star.P.G V0.17 |");
  main_log.File_Write("------------------\n");
  main_log.File_Write("Booting up!");
  main_log.File_Write("------------------\n");
  if (game.cheats_enabled) main_log.File_Write("Cheating enabled!\n");
  Load_Default_Config();
  main_log.File_Write("Loading config...");
  Load_Config_File(App_Conf);
 //----------------------------------- Start the PhysicsFS ----------------------
  //main_log.File_Write("Starting PhysicsFS...");
  //PHYSFS_init(argv[0]);
  //PHYSFS_addToSearchPath("Star.P.G..spg", 1);
//----------------------------------- SDL Video --------------------------------
  main_log.File_Write("Starting SDL...");
  putenv("SDL_VIDEO_WINDOW_POS");
  putenv("SDL_VIDEO_CENTERED=1");
  getenv("SDL_VIDEO_WINDOW_POS");
  getenv("SDL_VIDEO_CENTERED");
  SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTTHREAD);
  main_log.File_Write("Starting OpenGL...");
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
  main_log.File_Write("Starting sound system...");
  SDL_Init(SDL_INIT_AUDIO);
  Mix_AllocateChannels(config_data.Audio_Channels);
  Mix_OpenAudio(config_data.Audio_Rate, AUDIO_S16, 2, config_data.Audio_Buffers);
  Mix_Volume(-1,config_data.Audio_Sound_Volume);
  Mix_VolumeMusic(config_data.Audio_Music_Volume);
  main_log.File_Write("Initializing joystick / gamepad...");
  SDL_Init(SDL_INIT_JOYSTICK);
  SDL_Joystick *joystick;
  SDL_JoystickEventState(SDL_ENABLE);
  joystick = SDL_JoystickOpen(0);
  config_data.joystick_sensitivity     = 6400;
  main_log.File_Write("Loading fonts...");
  Init_Font();
  main_log.File_Write("Loading sounds...");
  init_sounds();
  load_sounds();
  main_log.File_Write("Loading music...");
  init_music();
  load_music();
  main_log.File_Write("Loading textures...");
  init_textures();
  load_textures();
  main_log.File_Write("Initializing menu system...");
  init_menu();
  main_log.File_Write("Initializing game system...");
  init_game();
  main_log.File_Write("Initializing projectiles...");
  init_player_bullets();
  main_log.File_Write("Initializing explosions...");
  init_explosions();
  main_log.File_Write("Initializing NPCs...\n");
  init_active_npcs();
  init_npc_bullets();
  init_npcs(0);
  game.level = 0;
  init_gl();
  seed_rand();
  main_log.File_Write("Starting game...");
  main_log.File_Write("---------------\n");
//----------------------------------- Main loop --------------------------------
  for(int quit = 0; !quit;)
  {
     if (game.status_quit_active) quit = 1;
     events_process();
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
              config_data.menu_delay_count = 0;
              main_log.File_Write("User terminated due to insuficient health...better luck next time buddy!");
           }
        if (game.io.escape)
              {
                 play_sound(1);
                 game.game_active             = false;
                 menu.level                   = 1;
                 menu.possition               = 3;
                 menu.possition_max           = 6;
                 game.menu_active             = true;
                 game.io.escape               = false;
                 game.io.keyboard_delay_count = 0;
                 config_data.menu_delay_count = 0;
                 while (config_data.menu_delay_count < (config_data.menu_delay/2))
                 {
                    config_data.menu_delay_count++;
                 }
              }
        if (game.io.pause)
              {
                 game.game_paused = true;
                 game.game_active = false;
                 spawn_paused();
                 game.io.pause    = false;
                 game.io.keyboard_delay_count = 0;
              };
        //if (game.cheats_enabled == true)
        {
          if (game.io.key_0) game.victory_kills = game.level_kills;  //complete level
          if (game.io.key_1) spawn_powerup(1.0f,random_GLcoord(), 1);//spawn health powerup
          if (game.io.key_2) spawn_powerup(1.0f,random_GLcoord(), 2);//spawn shield lvl powerup
          if (game.io.key_3) spawn_powerup(1.0f,random_GLcoord(), 3);//spawn shield new powerup
          if (game.io.key_4) spawn_powerup(1.0f,random_GLcoord(), 4);//spawn thruster lvl powerup
          if (game.io.key_5) spawn_powerup(1.0f,random_GLcoord(), 5);//spawn thruster new powerup
          if (game.io.key_6) spawn_powerup(1.0f,random_GLcoord(), 6);//spawn weapon lvl powerup
          if (game.io.key_7) spawn_powerup(1.0f,random_GLcoord(), 7);//spawn weapon new powerup
          if (game.io.key_8) unlock_levels();                        //unlock all levels
          if (game.io.key_9) spawn_powerup(1.0f,random_GLcoord(), 8);//spawn bomb powerup
          if (game.io.key_a) game.anc_enabled   = !game.anc_enabled; //toggle active NPC count display
          if (game.io.key_f) game.fps_enabled   = !game.fps_enabled; //toggle active NPC count display
          if (game.io.key_q) spawn_powerup(1.0f,random_GLcoord(), 9);//spawn sideship 0 powerup
          if (game.io.key_w) spawn_powerup(1.0f,random_GLcoord(),10);//spawn sideship 1 powerup
          if (game.io.key_e) spawn_powerup(1.0f,random_GLcoord(),11);//spawn sideship 2 powerup
          if (game.io.key_r) spawn_powerup(1.0f,random_GLcoord(),12);//spawn sideship 3 powerup
        }
        if (game.io.shoot)
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
        if (game.io.up)    process_player(1);
        if (game.io.down)  process_player(2);
        if (game.io.right) process_player(3);
        if (game.io.left)  process_player(4);
     }
//*********************************** Game paused *****************************************
    if (game.game_paused)
    {
        play_music(game.music_track);
        display_game();
        config_data.menu_delay_count++;
        if (config_data.menu_delay_count >= config_data.menu_delay)
        {
            config_data.menu_delay_count = config_data.menu_delay;
            if (((game.io.escape) || (game.io.select)) && (game.io.keyboard_delay_count >= game.io.keyboard_delay))
            {
                game.io.keyboard_delay_count = 0;
                game.game_paused = false;
                game.game_active = true;
                game.io.escape   = false;
                game.io.select   = false;
                game.io.pause    = false;
            }
        }
    }
//*********************************** PLAYER DEATH SCREEN *****************************************
    if (game.pdie_active)
    {
        play_music(game.pdie_music_track);
        glPushMatrix();
        diplay_menu ();
        process_menu_background();
        glPopMatrix();
        SDL_GL_SwapBuffers();
        config_data.menu_delay_count++;
        if (config_data.menu_delay_count >= config_data.menu_delay)
        {
            config_data.menu_delay_count = config_data.menu_delay;
            if ((game.io.escape) || (game.io.enter) || (game.io.space))
            {
                play_sound(1);
                init_game();
                menu.level = 0;
                menu.possition = 0;
                menu.possition_max = 4;
                game.menu_active = true;
                game.pdie_active = false;
                game.io.keyboard_delay_count = 0;
                game.io.escape   = false;
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
        process_menu_background();
        glPopMatrix ();
        SDL_GL_SwapBuffers();
        config_data.menu_delay_count++;
        if (config_data.menu_delay_count >= config_data.menu_delay)
        {
            config_data.menu_delay_count = config_data.menu_delay;
            if ((game.io.escape) || (game.io.enter) || (game.io.space))
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
                    main_log.File_Write("Player just completed the game, proceeding to Outro!");
                    config_data.menu_delay_count = 0;
                 }
                 else
                 {
                    game.game_active = true;
                    game.menu_active = false;
                    game.nlvl_active = false;
                    main_log.File_Write("Victory conditions met, player proceeding to next level!");
                    config_data.menu_delay_count = 0;
                 }
              game.io.keyboard_delay_count = 0;
              game.io.escape   = false;
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
        process_menu_background();
        glPopMatrix ();
        SDL_GL_SwapBuffers();
        config_data.menu_delay_count++;
        if (config_data.menu_delay_count >= config_data.menu_delay)
        {
            config_data.menu_delay_count = config_data.menu_delay;
            if ((game.io.escape) || (game.io.enter) || (game.io.space))
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
                 main_log.File_Write("Outro finished, proceeding to main menu!");
                 game.io.keyboard_delay_count = 0;
                 game.io.escape   = false;
              }
        }
    }
//---------------------------- code for end of main loop -----------------------
     game.FPS += fps.getticks();
     game.FPS  = 1000 - (game.FPS / 2);
     fps.stop();
//----------------------------------- Exit -------------------------------------
  }
  main_log.File_Write("\n");
  main_log.File_Write("Shuting down...");
  main_log.File_Write("---------------\n");
  main_log.File_Write("Saving config...");
  Save_Config_File(App_Conf);
  main_log.File_Write("Unloading textures...");
  kill_textures();
  main_log.File_Write("Unloading fonts...");
  Kill_Font();
  main_log.File_Write("Shuting down audio system...");
  Mix_CloseAudio();
  main_log.File_Write("Unloading music...");
  kill_music();
  main_log.File_Write("Unloading sounds...");
  kill_sounds();
//  main_log.File_Write("PhysicsFS deinit...");
//  PHYSFS_deinit();
  main_log.File_Write("SDL deinit...");
  SDL_Quit();
  return(0);
}

