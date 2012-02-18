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

#ifndef LEVELS_H
#define LEVELS_H

#include "waves.hpp"

const int   MAX_LEVELS = 25;

class level_class
{
    public:
        int        background_00;
        int        background_01;
        int        music_track;
        bool       locked;
        float      speed;
        bool       BOSS;
        int        NPC_type;
        int        NPC_spawn_rate;
        int        NPC_spawn_rate_count;
        int        NPC_projectile_spawn_rate;
        int        victory_kills;
        int        victory_spawened;
        int        victory_score;
        int        number_of_waves;
        wave_class wave[MAX_WAVES];
        void       load(std::string file_name);
};

int  unlock_levels(void);
int  init_game_level(int level_no);
int  load_level(std::string file_name);
void set_level_background(int layer_number, int image_reference);
void init_levels(void);
bool level_completed(void);
bool boss_level(void);

#endif //LEVELS_H
