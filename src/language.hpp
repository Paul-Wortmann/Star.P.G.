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

#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <string>

struct text_type
{
    std::string    main_menu;
    std::string    star_map;
    std::string    customize_starship;
    std::string    achievements;
    std::string    load_game;
    std::string    save_game;
    std::string    resume_game;
    std::string    options;
    std::string    quit_game;
};

class language_class
{
    public:
        void load(std::string file_name);
        text_type text;
};

#endif //LANGUAGE_H
