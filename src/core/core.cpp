/**
 * Copyright (C) 2010-2012 Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
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

game_class        game;

game_class::game_class(void)
{
    game_class::GAME_VERSION_MAJOR = 1;
    game_class::GAME_VERSION_MINOR = 2;
    game_class::game_paused        = false;
    game_class::game_active        = false;
    game_class::game_resume        = false;
    game_class::menu_active        = false;
    game_class::pdie_active        = false;
    game_class::nlvl_active        = false;
    game_class::outr_active        = false;
    game_class::status_quit_active = false;
    game_class::menu_level         = 1;
    game_class::FPS                = 0;
    game_class::LastTicks          = 0;
    game_class::music_track        = -1;
    game_class::process_ready      = true;
    game_class::music_next_track   = true;
}

game_class::~game_class(void)
{

}
