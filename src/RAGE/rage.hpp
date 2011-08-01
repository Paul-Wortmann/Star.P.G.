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

#ifndef RAGE_H
#define RAGE_H

#include "log.hpp"
#include "config.hpp"
#include "graphics.hpp"
#include "physics.hpp"
#include "network.hpp"
#include "timer.hpp"
#include "sound.hpp"
#include "savegame.hpp"
#include "font.hpp"
#include "io.hpp"

class game_class
{
    public:
        int               GAME_VERSION;
        int               FPS;
        int               LastTicks;
        bool              process_ready;
        int               music_track;
        bool              music_next_track;
        bool              game_paused;
        bool              game_active;
        bool              game_resume;
        bool              menu_active;
        bool              pdie_active;
        bool              nlvl_active;
        bool              outr_active;
        bool              status_quit_active;
        io_type           io;
        SDL_Event         event;
        log_file_class    log;
        config_file_class config;
        graphics_class    graphics;
        physics_class     physics;
        network_class     network;
        timer_class       timer;
         game_class(void);
        ~game_class(void);
};


#endif //RAGE_H
