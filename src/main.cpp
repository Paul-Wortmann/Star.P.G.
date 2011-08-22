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
#include <GL/gl.h>
//#include <physfs.h>
#include "RAGE/rage.hpp"
#include "load_resources.hpp"
#include "misc.hpp"
#include "main.hpp"
#include "menu_system.hpp"
#include "game.hpp"
#include "levels.hpp"
#include "version.h"

extern sound_type        sound;
extern music_type        music;
extern texture_type      texture;
extern menu_type         menu;
extern game_type         game_o;
extern game_class        game;
extern TTF_Font         *font;

const char App_Name[] = ("Star.P.G V0.18 - www.physhexgames.co.nr");
const char App_Icon[] = "data/icon.bmp";

Uint32                   colorkey;
SDL_Surface             *App_Icon_Surface;


//----------------------------------- Main -------------------------------------
int main(int argc, char *argv[])
{
  events_init();
  game.log.File_Set("Star.P.G..log");
  game.log.File_Clear();
  for (int count = 0; count < (argc+1); count++)
  {
     game.log.File_Write(argv[count]);
     if (argv[count] == "cheat") game_o.cheats_enabled = true;
  }
  game_o.cheats_enabled = true; /// test!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

  game.log.File_Write("------------------");
  game.log.File_Write("| Star.P.G V0.18 |");
  game.log.File_Write("------------------\n");
  game.log.File_Write("Starting up!");
  game.log.File_Write("------------------\n");
  if (game_o.cheats_enabled) game.log.File_Write("Cheating enabled!\n");
  game.config.File_Set("Star.P.G..cfg");
  game.config.Set_Defaults();
  game.log.File_Write("Loading config...");
  game.config.File_Set("Star.P.G..cfg");
  game.config.File_Read();
 //----------------------------------- Start the PhysicsFS ----------------------
  //game.log.File_Write("Starting PhysicsFS...");
  //PHYSFS_init(argv[0]);
  //PHYSFS_addToSearchPath("Star.P.G..spg", 1);
//----------------------------------- SDL Video --------------------------------
  game.log.File_Write("Starting SDL...");
  putenv("SDL_VIDEO_WINDOW_POS");
  putenv("SDL_VIDEO_CENTERED=1");
  getenv("SDL_VIDEO_WINDOW_POS");
  getenv("SDL_VIDEO_CENTERED");
  SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTTHREAD);
  game.log.File_Write("Starting OpenGL...");
  if (game.config.Display_Fullscreen) SDL_SetVideoMode(game.config.Display_X_Resolution,game.config.Display_Y_Resolution,game.config.Display_BPS,SDL_OPENGL | SDL_FULLSCREEN);
    else SDL_SetVideoMode(game.config.Display_X_Resolution,game.config.Display_Y_Resolution,game.config.Display_BPS,SDL_OPENGL/* | SDL_NOFRAME/* | SDL_FULLSCREEN */);
  SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );
  App_Icon_Surface = SDL_LoadBMP(App_Icon);
  colorkey = SDL_MapRGB(App_Icon_Surface->format, 255, 0, 255);
  SDL_SetColorKey(App_Icon_Surface, SDL_SRCCOLORKEY, colorkey);
  SDL_WM_SetIcon(App_Icon_Surface,NULL);
  SDL_WM_SetCaption(App_Name, 0);
  //SDL_ShowCursor(SDL_DISABLE);
//----------------------------------- SDL Audio --------------------------------
  game.log.File_Write("Starting sound system...");
  SDL_Init(SDL_INIT_AUDIO);
  Mix_AllocateChannels(game.config.Audio_Channels);
  Mix_OpenAudio(game.config.Audio_Rate, AUDIO_S16, 2, game.config.Audio_Buffers);
  Mix_Volume(-1,game.config.Audio_Sound_Volume);
  Mix_VolumeMusic(game.config.Audio_Music_Volume);
  game.log.File_Write("Initializing joystick / gamepad...");
  SDL_Init(SDL_INIT_JOYSTICK);
  SDL_Joystick *joystick;
  SDL_JoystickEventState(SDL_ENABLE);
  joystick = SDL_JoystickOpen(0);
  game.log.File_Write("Initializing game system...");
  init_game();
  game.log.File_Write("Initializing menu system...");
  init_menu();
  game.log.File_Write("Initializing projectiles...");
  init_player_bullets();
  game.log.File_Write("Initializing explosions...");
  init_explosions();
  game.log.File_Write("Initializing NPCs...\n");
  init_active_npcs();
  init_npc_bullets();
  init_npcs(0);
  game_o.level = 0;
  game.graphics.init_gl(game.config.Display_X_Resolution,game.config.Display_Y_Resolution);
  seed_rand();
  TTF_Init();
  game.log.File_Write("Loading resources...");
  loading_screen_display("data/textures/misc/loading_screen.png");
  load_resources();
  game.log.File_Write("Starting game...");
  game.log.File_Write("---------------\n");
//----------------------------------- Main loop --------------------------------
  game.timer.start();
  game.LastTicks = game.timer.getticks();
  for(int quit = 0; !quit;)
  {
     if (game.status_quit_active) quit = 1;
     events_process();
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//****************************************** MENU *****************************************
     if (game.menu_active)
     {
        if (game.music_next_track)
        {
            music.menu_00.play();
            game.music_next_track = false;
        }
        glPushMatrix();
        diplay_menu ();
        glPopMatrix();
        SDL_GL_SwapBuffers();
        if (game.process_ready) game.background.process();
        if (game.process_ready) process_menu();
       }
//****************************************** GAME *****************************************
        if (game.game_active)
        {
            if (game.music_next_track)
            {
                game.music_next_track = false;
                if (game.music_track ==  0) music.level_00.play();
                if (game.music_track ==  1) music.level_01.play();
                if (game.music_track ==  2) music.level_02.play();
                if (game.music_track ==  3) music.level_03.play();
                if (game.music_track ==  4) music.level_04.play();
                if (game.music_track ==  5) music.level_05.play();
                if (game.music_track ==  6) music.level_06.play();
                if (game.music_track ==  7) music.level_07.play();
                if (game.music_track ==  8) music.level_08.play();
                if (game.music_track ==  9) music.level_09.play();
                if (game.music_track == 10) music.level_10.play();
                if (game.music_track == 11) music.level_11.play();
                if (game.music_track == 12) music.level_12.play();
                if (game.music_track == 13) music.level_13.play();
                if (game.music_track == 14) music.level_14.play();
                if (game.music_track == 15) music.level_15.play();
                if (game.music_track == 16) music.level_16.play();
                if (game.music_track == 17) music.level_17.play();
                if (game.music_track == 18) music.level_18.play();
                if (game.music_track == 19) music.level_19.play();
                if (game.music_track == 20) music.level_20.play();
                if (game.music_track == 21) music.level_21.play();
                if (game.music_track == 22) music.level_22.play();
                if (game.music_track == 23) music.level_23.play();
                if (game.music_track == 24) music.level_24.play();
                if (game.music_track == 25) music.level_25.play();
            }
            game.game_resume = true;
            if (game.process_ready) process_game();
            display_game();
            if(game.config.Display_Touchscreen)
            {
                if(game.physics.point_in_quadrangle(-0.875f,0.2f,-0.550f,0.2f,game.io.mouse_x,game.io.mouse_y)) game.io.left = true;
                if(game.physics.point_in_quadrangle(-0.475f,0.2f,-0.550f,0.2f,game.io.mouse_x,game.io.mouse_y)) game.io.right = true;
                if(game.physics.point_in_quadrangle(-0.675f,0.2f,-0.350f,0.2f,game.io.mouse_x,game.io.mouse_y)) game.io.up = true;
                if(game.physics.point_in_quadrangle(-0.675f,0.2f,-0.750f,0.2f,game.io.mouse_x,game.io.mouse_y)) game.io.down = true;
                if(game.physics.point_in_quadrangle( 0.875f,0.2f,-0.750f,0.2f,game.io.mouse_x,game.io.mouse_y)) game.io.shoot = true;
                if(game.physics.point_in_quadrangle( 0.575f,0.2f,-0.750f,0.2f,game.io.mouse_x,game.io.mouse_y)) game.io.key_b = true;
                if(game.physics.point_in_quadrangle( 0.875f,0.2f, 0.750f,0.2f,game.io.mouse_x,game.io.mouse_y)) game.io.escape = true;
            }
            if (game_o.player.health < 0)
            {
                sound.menu_select.play();
                game.game_active             = false;
                game.game_resume             = false;
                game.pdie_active             = true;
                game.menu_level              = 8;
                game.config.menu_delay_count = 0;
                music.level_pd.play();
                game.background.set_data ( 1, 1, 1, 0.0f, 0.0f, 0.0050f, 0.0050f, 84);
                game.background.set_data ( 2, 1, 1, 0.0f, 0.0f, 0.0050f, 0.0050f, 84);
                game.background.set_data ( 3, 1, 1, 0.0f, 0.0f, 0.0020f, 0.0020f, 73);
                game.background.set_data ( 4, 1, 1, 0.0f, 0.0f, 0.0020f, 0.0020f, 73);
                game.background.set_movement_type(BOUNCE);
                game.log.File_Write("User terminated due to insufficient health...better luck next time buddy!");
            }
        if (game.io.escape)
        {
            sound.menu_select.play();
            game.music_next_track        = true;
            game.game_active             = false;
            game.menu_level              = 1;
            game.menu_active             = true;
            game.io.escape               = false;
            game.io.keyboard_delay_count = 0;
            game.config.menu_delay_count = 0;
            while (game.config.menu_delay_count < (game.config.menu_delay/2))
            {
                game.config.menu_delay_count++;
            }
        }

        if (game_o.bomb_delay_count < game_o.bomb_delay)//bomb delay counter
        {
            game_o.bomb_delay_count++;
            if (game_o.bomb_delay_count > game_o.bomb_delay) game_o.bomb_delay_count = game_o.bomb_delay;
        }
        if (game.io.key_b)//user pressed "b" for bomb
        {
            if ((game_o.number_bombs > 0) && (game_o.bomb_delay_count >= game_o.bomb_delay))
            {
                game_o.number_bombs--;
                use_bomb_powerup();
                game_o.bomb_delay_count = 0;
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
        //if (game_o.cheats_enabled == true)
        {
          if (game.io.key_0) game_o.victory_kills = game_o.level_kills;  //complete level
          if (game.io.key_1) spawn_powerup(1.0f,random_GLcoord(), 1);//spawn health powerup
          if (game.io.key_2) spawn_powerup(1.0f,random_GLcoord(), 2);//spawn shield lvl powerup
          if (game.io.key_3) spawn_powerup(1.0f,random_GLcoord(), 3);//spawn shield new powerup
          if (game.io.key_4) spawn_powerup(1.0f,random_GLcoord(), 4);//spawn thruster lvl powerup
          if (game.io.key_5) spawn_powerup(1.0f,random_GLcoord(), 5);//spawn thruster new powerup
          if (game.io.key_6) spawn_powerup(1.0f,random_GLcoord(), 6);//spawn weapon lvl powerup
          if (game.io.key_7) spawn_powerup(1.0f,random_GLcoord(), 7);//spawn weapon new powerup
          if (game.io.key_8) unlock_levels();                        //unlock all levels
          if (game.io.key_9) spawn_powerup(1.0f,random_GLcoord(), 8);//spawn bomb powerup
          if (game.io.key_a) game_o.anc_enabled   = !game_o.anc_enabled; //toggle active NPC count display
          if (game.io.key_f) game_o.fps_enabled   = !game_o.fps_enabled; //toggle active NPC count display
          if (game.io.key_q) spawn_powerup(1.0f,random_GLcoord(), 9);//spawn sideship 0 powerup
          if (game.io.key_w) spawn_powerup(1.0f,random_GLcoord(),10);//spawn sideship 1 powerup
          if (game.io.key_e) spawn_powerup(1.0f,random_GLcoord(),11);//spawn sideship 2 powerup
          if (game.io.key_r) spawn_powerup(1.0f,random_GLcoord(),12);//spawn sideship 3 powerup
        }
        if (game.io.shoot)
        {
           process_sideships(true);
           if(game_o.fw_rof_count >= game_o.projectile[game_o.player.front_weapon].rate_of_fire)
           {
              spawn_player_bullet(0);
              game_o.fw_rof_count = 0;
           }
           if(game_o.sw_rof_count >= game_o.projectile[game_o.player.side_weapon].rate_of_fire)
           {
              spawn_player_bullet(1);
              game_o.sw_rof_count = 0;
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
        display_game();
        game.config.menu_delay_count++;
        if (game.config.menu_delay_count >= game.config.menu_delay)
        {
            game.config.menu_delay_count = game.config.menu_delay;
            if (((game.io.escape) || (game.io.select)) && (game.io.keyboard_delay_count >= game.io.keyboard_delay))
            {
                game.io.keyboard_delay_count = 0;
                game.game_paused      = false;
                game.game_active      = true;
                game.io.escape        = false;
                game.io.select        = false;
                game.io.pause         = false;
                game.music_next_track = true;
            }
        }
    }
//*********************************** PLAYER DEATH SCREEN *****************************************
        if (game.pdie_active)
        {
            if (game.music_next_track)
            {
                game.music_next_track = false;
                music.level_pd.play();
            }
            glPushMatrix();
            diplay_menu ();
            glPopMatrix();
            SDL_GL_SwapBuffers();
            if (game.process_ready) game.background.process();
            if (game.process_ready) process_menu();
        }
//******************************* PLAYER NEXT LEVEL SCREEN *************************************
        if (game.nlvl_active)
        {
            if (game.music_next_track)
            {
                game.music_next_track = false;
                music.level_nl.play();
            }
            game.menu_level = 9;
            if (game.process_ready) game.background.process();
            if (game.process_ready) process_menu();
            glPushMatrix();
            diplay_menu ();
            glPopMatrix ();
            SDL_GL_SwapBuffers();
        }
//******************************* OUTRO SCREEN *************************************************
     if (game.outr_active)
     {
        if (game.music_next_track)
        {
            game.music_next_track = false;
            music.outro_00.play();
        }
        glPushMatrix();
        game.menu_level = 10;
        diplay_menu ();
        if (game.process_ready) game.background.process();
        glPopMatrix ();
        SDL_GL_SwapBuffers();
        game.config.menu_delay_count++;
        if ((game.config.menu_delay_count >= game.config.menu_delay) && (game.process_ready))
        {
            game.config.menu_delay_count = game.config.menu_delay;
            if ((game.io.escape) || (game.io.enter) || (game.io.space))
              {
                 sound.menu_select.play();
                 game.menu_level            = 1;
                 menu.possition        = 0;
                 menu.possition_max    = 6;
                 game.game_resume    = false;
                 game.pdie_active    = false;
                 game.outr_active    = false;
                 game.game_active    = false;
                 game.menu_active    = true;
                 game.nlvl_active    = false;
                 game.log.File_Write("Outro finished, proceeding to main menu!");
                 game.io.keyboard_delay_count = 0;
                 game.io.escape      = false;
                 game.music_next_track = true;
              }
        }
        }
//---------------------------- code for end of main loop -----------------------
        game.FPS = (game.timer.getticks() - game.LastTicks);
        if ((game.timer.getticks() - game.LastTicks) >= 1000/90)
        {
            game.LastTicks = game.timer.getticks();
            game.process_ready = true;
        }
        else game.process_ready = false;
    }
//----------------------------------- Exit -------------------------------------
    game.log.File_Write("Saving config...");
    game.config.File_Set("Star.P.G..cfg");
    game.config.File_Clear();
    game.config.File_Write();
    game.log.File_Write("\n");
    game.log.File_Write("Shuting down...");
    game.log.File_Write("---------------\n");
    game.log.File_Write("Unloading fonts...");
    TTF_Quit();
    game.log.File_Write("Shuting down audio system...");
    Mix_CloseAudio();
//    game.log.File_Write("PhysicsFS deinit...");
//    PHYSFS_deinit();
    game.log.File_Write("SDL deinit...");
    SDL_Quit();
    return(0);
}

