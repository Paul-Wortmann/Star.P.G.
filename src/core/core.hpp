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
#include "menu.hpp"
#include "io.hpp"
#include "background.hpp"

class game_class
{
    public:
        int               GAME_VERSION_MAJOR;
        int               GAME_VERSION_MINOR;
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
        int               menu_level;
        save_game_class   save_01;
        save_game_class   save_02;
        save_game_class   save_03;
        save_game_class   save_04;
        save_game_class   save_05;
        save_game_class   save_06;
        save_game_class   save_07;
        io_type           io;
        SDL_Event         event;
        log_file_class    log;
        config_file_class config;
        graphics_class    graphics;
        physics_class     physics;
        network_class     network;
        timer_class       timer;
        background_class  background;
         game_class(void);
        ~game_class(void);
};


#endif //RAGE_H
