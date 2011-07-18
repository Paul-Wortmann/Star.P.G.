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
#include "RAGE/rage.hpp"
#include "game.hpp"
#include "io.hpp"

extern game_type          game_o;
extern game_class         game;


bool events_init(void)
{
   SDL_Init(SDL_INIT_JOYSTICK);
   SDL_Joystick *joystick;
   SDL_JoystickEventState(SDL_ENABLE);
   joystick = SDL_JoystickOpen(0);
   if (SDL_JoystickOpened(0) == 1)
   {
      game.config.joystick_enabled        = true;
      game_o.io.joystick_sensitivity        = 6400;
      game.config.joystick_no_buttons     = SDL_JoystickNumButtons(joystick);
   }
   else
   {
      game.config.joystick_enabled    = false;
      game_o.io.joystick_sensitivity    = 0;
      game.config.joystick_no_buttons = 0;
   }
   game_o.io.mouse_button_delay         = 32;
   game_o.io.mouse_button_delay_count   = 0;
   game_o.io.keyboard_delay             = 24;
   game_o.io.keyboard_delay_count       = 0;
   game_o.io.joystick_delay             = 24;
   game_o.io.joystick_delay_count       = 0;
   game_o.io.joystick_up                = false;
   game_o.io.joystick_down              = false;
   game_o.io.joystick_left              = false;
   game_o.io.joystick_right             = false;
   game_o.io.joystick_button_0          = false;
   game_o.io.joystick_button_1          = false;
   game_o.io.joystick_button_2          = false;
   game_o.io.joystick_button_3          = false;
   game_o.io.joystick_button_4          = false;
   game_o.io.joystick_button_5          = false;
   game_o.io.joystick_button_6          = false;
   game_o.io.joystick_button_7          = false;
   game_o.io.joystick_button_8          = false;
   game_o.io.joystick_button_9          = false;
   game_o.io.joystick_button_10         = false;
   game_o.io.joystick_button_11         = false;
   game_o.io.mouse_button_left          = false;
   game_o.io.mouse_button_middle        = false;
   game_o.io.mouse_button_right         = false;
   game_o.io.mouse_x                    = 0.0f;
   game_o.io.mouse_y                    = 0.0f;
   game_o.io.mouse_xrel                 = 0.0f;
   game_o.io.mouse_yrel                 = 0.0f;
   game_o.io.key_0                      = false;
   game_o.io.key_1                      = false;
   game_o.io.key_2                      = false;
   game_o.io.key_3                      = false;
   game_o.io.key_4                      = false;
   game_o.io.key_5                      = false;
   game_o.io.key_6                      = false;
   game_o.io.key_7                      = false;
   game_o.io.key_8                      = false;
   game_o.io.key_9                      = false;
   game_o.io.key_a                      = false;
   game_o.io.key_b                      = false;
   game_o.io.key_c                      = false;
   game_o.io.key_d                      = false;
   game_o.io.key_e                      = false;
   game_o.io.key_f                      = false;
   game_o.io.key_g                      = false;
   game_o.io.key_h                      = false;
   game_o.io.key_i                      = false;
   game_o.io.key_j                      = false;
   game_o.io.key_k                      = false;
   game_o.io.key_l                      = false;
   game_o.io.key_m                      = false;
   game_o.io.key_n                      = false;
   game_o.io.key_o                      = false;
   game_o.io.key_p                      = false;
   game_o.io.key_q                      = false;
   game_o.io.key_r                      = false;
   game_o.io.key_s                      = false;
   game_o.io.key_t                      = false;
   game_o.io.key_u                      = false;
   game_o.io.key_v                      = false;
   game_o.io.key_w                      = false;
   game_o.io.key_x                      = false;
   game_o.io.key_y                      = false;
   game_o.io.key_z                      = false;
   game_o.io.key_up                     = false;
   game_o.io.key_down                   = false;
   game_o.io.key_left                   = false;
   game_o.io.key_right                  = false;
   game_o.io.select                     = false;
   game_o.io.escape                     = false;
   game_o.io.pause                      = false;
   game_o.io.plus                       = false;
   game_o.io.minus                      = false;
   game_o.io.space                      = false;
   game_o.io.enter                      = false;
   game_o.io.shoot                      = false;
   game_o.io.up                         = false;
   game_o.io.down                       = false;
   game_o.io.left                       = false;
   game_o.io.right                      = false;
   return(true);
};

bool events_process(void)
{
    //----------------------------------- Process events ------------------------------------------------
    game_o.io.mouse_button_delay_count++;
    if (game_o.io.mouse_button_delay_count > game_o.io.mouse_button_delay) game_o.io.mouse_button_delay_count = game_o.io.mouse_button_delay;
    game_o.io.keyboard_delay_count++;
    if (game_o.io.keyboard_delay_count > game_o.io.keyboard_delay) game_o.io.keyboard_delay_count = game_o.io.keyboard_delay;
    while (SDL_PollEvent(&game_o.event))
    {
    //-------------------- Mouse events-------------------------------
       if (game_o.event.type == SDL_MOUSEMOTION)
       {
           game_o.io.mouse_x      = game.graphics.res_to_gl(game_o.event.motion.x,game.config.mouse_resolution_x);
           game_o.io.mouse_y      = game.graphics.res_to_gl(game_o.event.motion.y,game.config.mouse_resolution_y);
           game_o.io.mouse_xrel   = game.graphics.res_to_gl(game_o.event.motion.xrel,game.config.mouse_resolution_x);
           game_o.io.mouse_yrel   = game.graphics.res_to_gl(game_o.event.motion.yrel,game.config.mouse_resolution_y);
           game_o.io.mouse_y *= -1;
       }
       if (game_o.event.type == SDL_MOUSEBUTTONUP)
       {
           switch(game_o.event.button.button)
           {
              case 1:
                game_o.io.mouse_button_left = false;
              break;
              case 2:
                game_o.io.mouse_button_middle = false;
              break;
              case 3:
                game_o.io.mouse_button_right = false;
              break;
              default:
              break;
           }
       }
       if (game_o.event.type == SDL_MOUSEBUTTONDOWN)
       {
           switch(game_o.event.button.button)
           {
              case 1:
                if (game_o.io.mouse_button_delay_count >= game_o.io.mouse_button_delay)
                {
                   game_o.io.mouse_button_delay_count = 0;
                   game_o.io.mouse_button_left = true;
                }
                else game_o.io.mouse_button_left = false;
              break;
              case 2:
                if (game_o.io.mouse_button_delay_count >= game_o.io.mouse_button_delay)
                {
                   game_o.io.mouse_button_delay_count = 0;
                   game_o.io.mouse_button_middle = true;
                }
                else game_o.io.mouse_button_middle = false;
              break;
              case 3:
                if (game_o.io.mouse_button_delay_count >= game_o.io.mouse_button_delay)
                {
                   game_o.io.mouse_button_delay_count = 0;
                   game_o.io.mouse_button_right = true;
                }
                else game_o.io.mouse_button_right = false;
              break;
              default:
              break;
           }
       }
    //-------------------------- joystick / gamepad events --------------------------------------------
       if (game_o.event.type == SDL_JOYHATMOTION)
       {
          if (game_o.event.jhat.value & SDL_HAT_UP)
          {
              game_o.io.joystick_up    = true;
              game_o.io.joystick_down  = false;
              game_o.io.joystick_left  = false;
              game_o.io.joystick_right = false;
          }
          if (game_o.event.jhat.value & SDL_HAT_DOWN)
          {
              game_o.io.joystick_up    = false;
              game_o.io.joystick_down  = true;
              game_o.io.joystick_left  = false;
              game_o.io.joystick_right = false;
          }
          if (game_o.event.jhat.value & SDL_HAT_RIGHT)
          {
              game_o.io.joystick_up    = false;
              game_o.io.joystick_down  = false;
              game_o.io.joystick_left  = false;
              game_o.io.joystick_right = true;
          }
          if (game_o.event.jhat.value & SDL_HAT_RIGHTUP)
          {
              game_o.io.joystick_up    = true;
              game_o.io.joystick_down  = false;
              game_o.io.joystick_left  = false;
              game_o.io.joystick_right = true;
          }
          if (game_o.event.jhat.value & SDL_HAT_RIGHTDOWN)
          {
              game_o.io.joystick_up    = false;
              game_o.io.joystick_down  = true;
              game_o.io.joystick_left  = false;
              game_o.io.joystick_right = true;
          }
          if (game_o.event.jhat.value & SDL_HAT_LEFT)
          {
              game_o.io.joystick_up    = false;
              game_o.io.joystick_down  = false;
              game_o.io.joystick_left  = true;
              game_o.io.joystick_right = false;
          }
          if (game_o.event.jhat.value & SDL_HAT_LEFTUP)
          {
              game_o.io.joystick_up    = true;
              game_o.io.joystick_down  = false;
              game_o.io.joystick_left  = true;
              game_o.io.joystick_right = false;
          }
          if (game_o.event.jhat.value & SDL_HAT_LEFTDOWN)
          {
              game_o.io.joystick_up    = false;
              game_o.io.joystick_down  = true;
              game_o.io.joystick_left  = true;
              game_o.io.joystick_right = false;
          }
          if (game_o.event.jhat.value & SDL_HAT_CENTERED)
          {
              game_o.io.joystick_up    = false;
              game_o.io.joystick_down  = false;
              game_o.io.joystick_left  = false;
              game_o.io.joystick_right = false;
         }
       }
       //--------------------------------------------------------------------------
       if (game_o.event.type == SDL_JOYAXISMOTION)
       {
          if ((game_o.event.jaxis.value < (-1*(game.config.joystick_sensitivity))) || (game_o.event.jaxis.value > game.config.joystick_sensitivity))
          {
             if (game_o.event.jaxis.axis == 0)
             {
                if(game_o.event.jaxis.value < -(-1*(game.config.joystick_sensitivity)))
                {
                   game_o.io.joystick_left  = true;
                   game_o.io.joystick_right = false;
                }
                if(game_o.event.jaxis.value > game.config.joystick_sensitivity)
                {
                   game_o.io.joystick_left  = false;
                   game_o.io.joystick_right = true;
                }
             }
             if (game_o.event.jaxis.axis == 1)
             {
                if(game_o.event.jaxis.value < -(-1*(game.config.joystick_sensitivity)))
                {
                   game_o.io.joystick_up    = true;
                   game_o.io.joystick_down  = false;
                }
                if(game_o.event.jaxis.value > game.config.joystick_sensitivity)
                {
                   game_o.io.joystick_up    = false;
                   game_o.io.joystick_down  = true;
                }
             }
          }
          else
          {
               game_o.io.joystick_up    = false;
               game_o.io.joystick_down  = false;
               game_o.io.joystick_left  = false;
               game_o.io.joystick_right = false;
          }
       }
       //--------------------------------------------------------------------
       if (game_o.event.type == SDL_JOYBUTTONDOWN)
       {
           if (game_o.event.jbutton.button ==  0) game_o.io.joystick_button_0  = true;
           if (game_o.event.jbutton.button ==  1) game_o.io.joystick_button_1  = true;
           if (game_o.event.jbutton.button ==  2) game_o.io.joystick_button_2  = true;
           if (game_o.event.jbutton.button ==  3) game_o.io.joystick_button_3  = true;
           if (game_o.event.jbutton.button ==  4) game_o.io.joystick_button_4  = true;
           if (game_o.event.jbutton.button ==  5) game_o.io.joystick_button_5  = true;
           if (game_o.event.jbutton.button ==  6) game_o.io.joystick_button_6  = true;
           if (game_o.event.jbutton.button ==  7) game_o.io.joystick_button_7  = true;
           if (game_o.event.jbutton.button ==  8) game_o.io.joystick_button_8  = true;
           if (game_o.event.jbutton.button ==  9) game_o.io.joystick_button_9  = true;
           if (game_o.event.jbutton.button == 10) game_o.io.joystick_button_10 = true;
           if (game_o.event.jbutton.button == 11) game_o.io.joystick_button_11 = true;
       }
       if (game_o.event.type == SDL_JOYBUTTONUP)
       {
           if (game_o.event.jbutton.button ==  0) game_o.io.joystick_button_0  = false;
           if (game_o.event.jbutton.button ==  1) game_o.io.joystick_button_1  = false;
           if (game_o.event.jbutton.button ==  2) game_o.io.joystick_button_2  = false;
           if (game_o.event.jbutton.button ==  3) game_o.io.joystick_button_3  = false;
           if (game_o.event.jbutton.button ==  4) game_o.io.joystick_button_4  = false;
           if (game_o.event.jbutton.button ==  5) game_o.io.joystick_button_5  = false;
           if (game_o.event.jbutton.button ==  6) game_o.io.joystick_button_6  = false;
           if (game_o.event.jbutton.button ==  7) game_o.io.joystick_button_7  = false;
           if (game_o.event.jbutton.button ==  8) game_o.io.joystick_button_8  = false;
           if (game_o.event.jbutton.button ==  9) game_o.io.joystick_button_9  = false;
           if (game_o.event.jbutton.button == 10) game_o.io.joystick_button_10 = false;
           if (game_o.event.jbutton.button == 11) game_o.io.joystick_button_11 = false;
       }
       //------------------ keybord events ------------------------------------------------------
       if (game_o.event.type == SDL_QUIT) game_o.status_quit_active = true;
       if (game_o.event.type == SDL_KEYDOWN)
       {
          if (game_o.event.key.keysym.sym == SDLK_ESCAPE) game_o.io.escape     = true;
          if (game_o.event.key.keysym.sym == SDLK_UP)     game_o.io.key_up     = true;
          if (game_o.event.key.keysym.sym == SDLK_DOWN)   game_o.io.key_down   = true;
          if (game_o.event.key.keysym.sym == SDLK_LEFT)   game_o.io.key_left   = true;
          if (game_o.event.key.keysym.sym == SDLK_RIGHT)  game_o.io.key_right  = true;
          if (game_o.event.key.keysym.sym == SDLK_PLUS)   game_o.io.plus       = true;
          if (game_o.event.key.keysym.sym == SDLK_MINUS)  game_o.io.minus      = true;
          if (game_o.event.key.keysym.sym == SDLK_SPACE)  game_o.io.space      = true;
          if (game_o.event.key.keysym.sym == SDLK_RETURN) game_o.io.enter      = true;
          if (game_o.event.key.keysym.sym == SDLK_0)      game_o.io.key_0      = true;
          if (game_o.event.key.keysym.sym == SDLK_1)      game_o.io.key_1      = true;
          if (game_o.event.key.keysym.sym == SDLK_2)      game_o.io.key_2      = true;
          if (game_o.event.key.keysym.sym == SDLK_3)      game_o.io.key_3      = true;
          if (game_o.event.key.keysym.sym == SDLK_4)      game_o.io.key_4      = true;
          if (game_o.event.key.keysym.sym == SDLK_5)      game_o.io.key_5      = true;
          if (game_o.event.key.keysym.sym == SDLK_6)      game_o.io.key_6      = true;
          if (game_o.event.key.keysym.sym == SDLK_7)      game_o.io.key_7      = true;
          if (game_o.event.key.keysym.sym == SDLK_8)      game_o.io.key_8      = true;
          if (game_o.event.key.keysym.sym == SDLK_9)      game_o.io.key_9      = true;
          if (game_o.event.key.keysym.sym == SDLK_a)      game_o.io.key_a      = true;
          if (game_o.event.key.keysym.sym == SDLK_b)      game_o.io.key_b      = true;
          if (game_o.event.key.keysym.sym == SDLK_c)      game_o.io.key_c      = true;
          if (game_o.event.key.keysym.sym == SDLK_d)      game_o.io.key_d      = true;
          if (game_o.event.key.keysym.sym == SDLK_e)      game_o.io.key_e      = true;
          if (game_o.event.key.keysym.sym == SDLK_f)      game_o.io.key_f      = true;
          if (game_o.event.key.keysym.sym == SDLK_g)      game_o.io.key_g      = true;
          if (game_o.event.key.keysym.sym == SDLK_h)      game_o.io.key_h      = true;
          if (game_o.event.key.keysym.sym == SDLK_i)      game_o.io.key_i      = true;
          if (game_o.event.key.keysym.sym == SDLK_j)      game_o.io.key_j      = true;
          if (game_o.event.key.keysym.sym == SDLK_k)      game_o.io.key_k      = true;
          if (game_o.event.key.keysym.sym == SDLK_l)      game_o.io.key_l      = true;
          if (game_o.event.key.keysym.sym == SDLK_m)      game_o.io.key_m      = true;
          if (game_o.event.key.keysym.sym == SDLK_n)      game_o.io.key_n      = true;
          if (game_o.event.key.keysym.sym == SDLK_o)      game_o.io.key_o      = true;
          if (game_o.event.key.keysym.sym == SDLK_p)      game_o.io.key_p      = true;
          if (game_o.event.key.keysym.sym == SDLK_q)      game_o.io.key_q      = true;
          if (game_o.event.key.keysym.sym == SDLK_r)      game_o.io.key_r      = true;
          if (game_o.event.key.keysym.sym == SDLK_s)      game_o.io.key_s      = true;
          if (game_o.event.key.keysym.sym == SDLK_t)      game_o.io.key_t      = true;
          if (game_o.event.key.keysym.sym == SDLK_u)      game_o.io.key_u      = true;
          if (game_o.event.key.keysym.sym == SDLK_v)      game_o.io.key_v      = true;
          if (game_o.event.key.keysym.sym == SDLK_w)      game_o.io.key_w      = true;
          if (game_o.event.key.keysym.sym == SDLK_x)      game_o.io.key_x      = true;
          if (game_o.event.key.keysym.sym == SDLK_y)      game_o.io.key_y      = true;
          if (game_o.event.key.keysym.sym == SDLK_z)      game_o.io.key_z      = true;
       }
       if (game_o.event.type == SDL_KEYUP)
       {
          if (game_o.event.key.keysym.sym == SDLK_ESCAPE) game_o.io.escape     = false;
          if (game_o.event.key.keysym.sym == SDLK_UP)     game_o.io.key_up     = false;
          if (game_o.event.key.keysym.sym == SDLK_DOWN)   game_o.io.key_down   = false;
          if (game_o.event.key.keysym.sym == SDLK_LEFT)   game_o.io.key_left   = false;
          if (game_o.event.key.keysym.sym == SDLK_RIGHT)  game_o.io.key_right  = false;
          if (game_o.event.key.keysym.sym == SDLK_PLUS)   game_o.io.plus       = false;
          if (game_o.event.key.keysym.sym == SDLK_MINUS)  game_o.io.minus      = false;
          if (game_o.event.key.keysym.sym == SDLK_SPACE)  game_o.io.space      = false;
          if (game_o.event.key.keysym.sym == SDLK_RETURN) game_o.io.enter      = false;
          if (game_o.event.key.keysym.sym == SDLK_0)      game_o.io.key_0      = false;
          if (game_o.event.key.keysym.sym == SDLK_1)      game_o.io.key_1      = false;
          if (game_o.event.key.keysym.sym == SDLK_2)      game_o.io.key_2      = false;
          if (game_o.event.key.keysym.sym == SDLK_3)      game_o.io.key_3      = false;
          if (game_o.event.key.keysym.sym == SDLK_4)      game_o.io.key_4      = false;
          if (game_o.event.key.keysym.sym == SDLK_5)      game_o.io.key_5      = false;
          if (game_o.event.key.keysym.sym == SDLK_6)      game_o.io.key_6      = false;
          if (game_o.event.key.keysym.sym == SDLK_7)      game_o.io.key_7      = false;
          if (game_o.event.key.keysym.sym == SDLK_8)      game_o.io.key_8      = false;
          if (game_o.event.key.keysym.sym == SDLK_9)      game_o.io.key_9      = false;
          if (game_o.event.key.keysym.sym == SDLK_a)      game_o.io.key_a      = false;
          if (game_o.event.key.keysym.sym == SDLK_b)      game_o.io.key_b      = false;
          if (game_o.event.key.keysym.sym == SDLK_c)      game_o.io.key_c      = false;
          if (game_o.event.key.keysym.sym == SDLK_d)      game_o.io.key_d      = false;
          if (game_o.event.key.keysym.sym == SDLK_e)      game_o.io.key_e      = false;
          if (game_o.event.key.keysym.sym == SDLK_f)      game_o.io.key_f      = false;
          if (game_o.event.key.keysym.sym == SDLK_g)      game_o.io.key_g      = false;
          if (game_o.event.key.keysym.sym == SDLK_h)      game_o.io.key_h      = false;
          if (game_o.event.key.keysym.sym == SDLK_i)      game_o.io.key_i      = false;
          if (game_o.event.key.keysym.sym == SDLK_j)      game_o.io.key_j      = false;
          if (game_o.event.key.keysym.sym == SDLK_k)      game_o.io.key_k      = false;
          if (game_o.event.key.keysym.sym == SDLK_l)      game_o.io.key_l      = false;
          if (game_o.event.key.keysym.sym == SDLK_m)      game_o.io.key_m      = false;
          if (game_o.event.key.keysym.sym == SDLK_n)      game_o.io.key_n      = false;
          if (game_o.event.key.keysym.sym == SDLK_o)      game_o.io.key_o      = false;
          if (game_o.event.key.keysym.sym == SDLK_p)      game_o.io.key_p      = false;
          if (game_o.event.key.keysym.sym == SDLK_q)      game_o.io.key_q      = false;
          if (game_o.event.key.keysym.sym == SDLK_r)      game_o.io.key_r      = false;
          if (game_o.event.key.keysym.sym == SDLK_s)      game_o.io.key_s      = false;
          if (game_o.event.key.keysym.sym == SDLK_t)      game_o.io.key_t      = false;
          if (game_o.event.key.keysym.sym == SDLK_u)      game_o.io.key_u      = false;
          if (game_o.event.key.keysym.sym == SDLK_v)      game_o.io.key_v      = false;
          if (game_o.event.key.keysym.sym == SDLK_w)      game_o.io.key_w      = false;
          if (game_o.event.key.keysym.sym == SDLK_x)      game_o.io.key_x      = false;
          if (game_o.event.key.keysym.sym == SDLK_y)      game_o.io.key_y      = false;
          if (game_o.event.key.keysym.sym == SDLK_z)      game_o.io.key_z      = false;
       }
    }
    //---------------------------------------------------------------------------------------------
    if ((game_o.io.joystick_button_0) || (game_o.io.space) || (game_o.io.enter)) game_o.io.select = true; else game_o.io.select = false;
    if ((game_o.io.joystick_button_1) || (game_o.io.space) || (game_o.io.mouse_button_left)) game_o.io.shoot   = true; else game_o.io.shoot  = false;
    if ((game_o.io.joystick_button_2) || (game_o.io.key_p)) game_o.io.pause   = true; else game_o.io.pause  = false;
    if ((game_o.io.joystick_button_3) || (game_o.io.escape)) game_o.io.escape = true; else game_o.io.escape = false;
    if ((game_o.io.joystick_up)    || (game_o.io.key_up   )) game_o.io.up     = true; else game_o.io.up     = false;
    if ((game_o.io.joystick_down)  || (game_o.io.key_down )) game_o.io.down   = true; else game_o.io.down   = false;
    if ((game_o.io.joystick_left)  || (game_o.io.key_left )) game_o.io.left   = true; else game_o.io.left   = false;
    if ((game_o.io.joystick_right) || (game_o.io.key_right)) game_o.io.right  = true; else game_o.io.right  = false;
   return(true);
}





