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
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "textures.hpp"
#include "rage.hpp"

#define GL_BGR  0x80E0
#define GL_BGRA 0x80E1

texture_class::texture_class()
{

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
