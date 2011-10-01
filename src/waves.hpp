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

#ifndef WAVES_H
#define WAVES_H

const int   MAX_WAVES          = 32;

struct wave_class
{
    public:
    bool   active;
    int    leader_num;
    int    npc_type;
    int    target_kills;
    int    count_kills;
    int    target_spawned;
    int    count_spawned;
    int    spawn_pattern;
    float  wave_size;
};

int   init_waves          (void);
int   spawn_wave          (void);
int   get_next_active_wave(void);
int   process_waves       (void);

#endif //WAVES_H
