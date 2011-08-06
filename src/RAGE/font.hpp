/**
 * Copyright (C) 2011 Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
 * This file is part of R.A.G.E. (RoboPaul's Adaptable Game Engine)
 *
 * R.A.G.E. (RoboPaul's Adaptable Game Engine) is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * R.A.G.E. (RoboPaul's Adaptable Game Engine) is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with R.A.G.E. (RoboPaul's Adaptable Game Engine) If not, see <http://www.gnu.org/licenses/>.
 *
 * @author Paul Wortmann
 * @license GPL
 * @date 2011-07-17
 */

#include <SDL/SDL_ttf.h>

#ifndef FONT_H
#define FONT_H

class font_class
{
    private:
        TTF_Font   *font_data;
    public:
        font_class(void);
       ~font_class(void);
        bool Set_File(std::string filename);
        bool Write(int r,int g,int b,int a,float x,float y,std::string text,int int_data);
        bool Write(int r,int g,int b,int a,float x,float y,std::string text,float float_data);
        bool Write(int r,int g,int b,int a,float x,float y,std::string text);
};

#endif //FONT_H




