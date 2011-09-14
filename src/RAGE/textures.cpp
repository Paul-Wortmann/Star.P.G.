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
 * @author  Paul Wortmann
 * @email   physhex@gmail.com
 * @website www.physhexgames.co.nr
 * @license GPL
 * @date 2011-09-03
 */

#include <GL/gl.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "textures.hpp"
#include "rage.hpp"

#define GL_BGR  0x80E0
#define GL_BGRA 0x80E1

extern  game_class game;

texture_class::texture_class()
{
    texture_class::rotate_able      = false;
    texture_class::rotate_speed     = 0.0f;
    texture_class::rotate_direction = 0;
    texture_class::angle            = 0.0f;
    texture_class::frame            = 0;
    texture_class::frame_max        = 0;
    for (int frame_count = 0; frame_count < MAX_FRAMES; frame_count++)
    {
        texture_class::data[frame_count] = 0;
    }
};

texture_class::~texture_class()
{
    glDeleteTextures(1, &texture_data);
};

bool texture_class::load(std::string file_name)
{
   SDL_Surface *surface;
   GLenum       texture_format;
   GLint        nOfColors;
   bool         return_value = false;
   if (surface = IMG_Load(file_name.c_str()))
   {
      return_value = true;
      if ((surface->w & (surface->w - 1)) != 0 );
      if ((surface->h & (surface->h - 1)) != 0 );
      nOfColors = surface->format->BytesPerPixel;
      if (nOfColors == 4)
      {
         if (surface->format->Rmask == 0x000000ff) texture_format = GL_RGBA;
         else texture_format = GL_BGRA;
      }
      else if (nOfColors == 3)
      {
         if (surface->format->Rmask == 0x000000ff) texture_format = GL_RGB;
         else texture_format = GL_BGR;
      }
      glGenTextures( 1, &texture_data);
      glBindTexture( GL_TEXTURE_2D, texture_data);
      glEnable(GL_BLEND);
      glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
      glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
      glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
      glTexImage2D( GL_TEXTURE_2D, 0, nOfColors, surface->w, surface->h, 0, texture_format, GL_UNSIGNED_BYTE, surface->pixels );
   }
   else
   {
      return_value = false;
      //game.log.File_Write("SDL could not load image.",File_Name);
      SDL_Quit();
   }
   if ( surface ) SDL_FreeSurface( surface );
   return(return_value);
};

bool texture_class::load(std::string file_name, int index_number)
{
   SDL_Surface *surface;
   GLenum       texture_format;
   GLint        nOfColors;
   bool         return_value = false;
   texture_class::ref_number = index_number;
   if (surface = IMG_Load(file_name.c_str()))
   {
      return_value = true;
      if ((surface->w & (surface->w - 1)) != 0 );
      if ((surface->h & (surface->h - 1)) != 0 );
      nOfColors = surface->format->BytesPerPixel;
      if (nOfColors == 4)
      {
         if (surface->format->Rmask == 0x000000ff) texture_format = GL_RGBA;
         else texture_format = GL_BGRA;
      }
      else if (nOfColors == 3)
      {
         if (surface->format->Rmask == 0x000000ff) texture_format = GL_RGB;
         else texture_format = GL_BGR;
      }
      glGenTextures( 1, &texture_data);
      glBindTexture( GL_TEXTURE_2D, texture_data);
      glEnable(GL_BLEND);
      glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
      glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
      glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
      glTexImage2D( GL_TEXTURE_2D, 0, nOfColors, surface->w, surface->h, 0, texture_format, GL_UNSIGNED_BYTE, surface->pixels );
   }
   else
   {
      return_value = false;
      //game.log.File_Write("SDL could not load image.",File_Name);
      SDL_Quit();
   }
   if ( surface ) SDL_FreeSurface( surface );
   return(return_value);
};

void texture_class::process(void)
{
    if(texture_class::rotate_able)
    {
        if(texture_class::rotate_direction == 0)
        {
            texture_class::angle += texture_class::rotate_speed;
            if (texture_class::angle > 6.2832f) texture_class::angle = 0.0f;
        }
        if(texture_class::rotate_direction == 1)
        {
            texture_class::angle -= texture_class::rotate_speed;
            if (texture_class::angle < 0.0f) texture_class::angle = 6.2832f;
        }
    }
    texture_class::frame++;
    if (texture_class::frame > texture_class::frame_max) texture_class::frame = 0;
};

void texture_class::draw(float pos_x, float pos_y, float pos_z, float width, float height)
{
    glPushMatrix();
    glBindTexture( GL_TEXTURE_2D, texture_class::data[frame]);
    glLoadIdentity();
    glBegin( GL_QUADS );
    glTexCoord2i( 0, 1 );glVertex3f(game.physics.rotate_point_2D_x(pos_x, pos_y, pos_x-(width/2),pos_y-(height/2),texture_class::angle), game.physics.rotate_point_2D_y(pos_x,pos_y,pos_x-(width/2),pos_y-(height/2), texture_class::angle), pos_z);
    glTexCoord2i( 0, 0 );glVertex3f(game.physics.rotate_point_2D_x(pos_x, pos_y, pos_x-(width/2),pos_y+(height/2),texture_class::angle), game.physics.rotate_point_2D_y(pos_x,pos_y,pos_x-(width/2),pos_y+(height/2), texture_class::angle), pos_z);
    glTexCoord2i( 1, 0 );glVertex3f(game.physics.rotate_point_2D_x(pos_x, pos_y, pos_x+(width/2),pos_y+(height/2),texture_class::angle), game.physics.rotate_point_2D_y(pos_x,pos_y,pos_x+(width/2),pos_y+(height/2), texture_class::angle), pos_z);
    glTexCoord2i( 1, 1 );glVertex3f(game.physics.rotate_point_2D_x(pos_x, pos_y, pos_x+(width/2),pos_y-(height/2),texture_class::angle), game.physics.rotate_point_2D_y(pos_x,pos_y,pos_x+(width/2),pos_y-(height/2), texture_class::angle), pos_z);
    glEnd();
    glPopMatrix();
};


