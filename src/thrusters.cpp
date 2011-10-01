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

#include "load_resources.hpp"
#include "thrusters.hpp"
#include "game.hpp"

extern  game_type        game_o;
extern  texture_type     texture;

void init_thrusters(bool re_init)
{
    if (re_init)
    {
        for (int thruster_count = 0; thruster_count <= MAX_THRUSTERS; thruster_count++)
        {
            game_o.thruster[thruster_count].active       = false;
            game_o.thruster[thruster_count].experience   = 0;
            game_o.thruster[thruster_count].level        = 0;
        }
    }
    else
    {
        game_o.thruster[0].name           = L"Maelstrom Thrusters";
        game_o.thruster[0].active         = false;
        game_o.thruster[0].level          = 0;
        game_o.thruster[0].level_1        = 256;
        game_o.thruster[0].level_2        = 512;
        game_o.thruster[0].level_3        = 1024;
        game_o.thruster[0].experience     = 0;
        game_o.thruster[0].image          = texture.thrusters_000.ref_number;
        game_o.thruster[0].thrust         = 0.002f;
        game_o.thruster[0].frame          = 0;
        game_o.thruster[0].frame_max      = 30;//texture.thrusters_000.frame_max;

        game_o.thruster[1].name           = L"Seismic Thrusters";
        game_o.thruster[1].active         = false;
        game_o.thruster[1].level          = 0;
        game_o.thruster[1].level_1        = 512;
        game_o.thruster[1].level_2        = 1024;
        game_o.thruster[1].level_3        = 2048;
        game_o.thruster[1].experience     = 0;
        game_o.thruster[1].image          = texture.thruster_001.ref_number;
        game_o.thruster[1].thrust         = 0.004f;
        game_o.thruster[2].name           = L"Vortex Thrusters";
        game_o.thruster[2].active         = false;
        game_o.thruster[2].level          = 0;
        game_o.thruster[2].level_1        = 1024;
        game_o.thruster[2].level_2        = 2048;
        game_o.thruster[2].level_3        = 4096;
        game_o.thruster[2].experience     = 0;
        game_o.thruster[2].image          = texture.thruster_002.ref_number;
        game_o.thruster[2].thrust         = 0.006f;
        game_o.thruster[3].name           = L"Convolution Thrusters";
        game_o.thruster[3].active         = false;
        game_o.thruster[3].level          = 0;
        game_o.thruster[3].level_1        = 2048;
        game_o.thruster[3].level_2        = 4096;
        game_o.thruster[3].level_3        = 8192;
        game_o.thruster[3].experience     = 0;
        game_o.thruster[3].image          = texture.thruster_003.ref_number;
        game_o.thruster[3].thrust         = 0.008f;
    }
};

void proc_thrusters(void)
{
    for (int thruster_count = 0; thruster_count < MAX_THRUSTERS; thruster_count++)
    {
        game_o.thruster[thruster_count].frame++;
        if (game_o.thruster[thruster_count].frame > game_o.thruster[thruster_count].frame_max) game_o.thruster[thruster_count].frame = 0;
    }
};

