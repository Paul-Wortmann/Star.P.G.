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


#include "music.hpp"

music_class::music_class()
{
    music_data = NULL;
};

music_class::~music_class()
{
    Mix_HaltMusic();
    Mix_FreeMusic(music_data);
};

void music_class::play(void)
{
    Mix_PlayMusic(music_data,-1);
};

void music_class::load(std::string file_name)
{
    music_data = Mix_LoadMUS(file_name.c_str());
};

