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
 * @date 2011-10-01
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
        bool Write(int r,int g,int b,int a,float x,float y,float ws,float hs,std::string text);
        bool Write(int r,int g,int b,int a,float x,float y,std::wstring text,int int_data);
        bool Write(int r,int g,int b,int a,float x,float y,std::wstring text,float float_data);
        bool Write(int r,int g,int b,int a,float x,float y,std::wstring text);
        bool Write(int r,int g,int b,int a,float x,float y,float ws,float hs,std::wstring text);
        bool Write(int r,int g,int b,int a,float x,float y,float ws,float hs,std::wstring text,int int_data);
        bool Write(int r,int g,int b,int a,float x,float y,float ws,float hs,std::wstring text,float float_data);
};

#endif //FONT_H



