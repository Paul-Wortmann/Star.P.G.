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

#include "core.hpp"
#include "sound.hpp"

sound_class::sound_class()
{
    sound_class::sound_channel = -1;
};

sound_class::~sound_class()
{
    Mix_HaltChannel(-1);
    Mix_FreeChunk(sound_class::sound_data);
};

void sound_class::load(std::string file_name, int index_number)
{
    sound_class::ref_number =  index_number;
    sound_class::sound_data = Mix_LoadWAV(file_name.c_str());
};

void sound_class::play(void)
{
    sound_class::sound_channel = Mix_PlayChannel(-1, sound_data, 0);
};

