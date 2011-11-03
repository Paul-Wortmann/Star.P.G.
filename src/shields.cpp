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
#include "shields.hpp"
#include "game.hpp"

extern  game_type game_o;
extern  texture_type     texture;

void init_shields(bool re_init)
{
    if (re_init)
    {
        for (int count = 0; count <= MAX_SHIELDS; count++)
        {
            game_o.shield[count].active         = false;
            game_o.shield[count].experience     = 0;
            game_o.shield[count].level          = 0;
        }
    }
    else
    {
        game_o.shield[0].name             = game_o.language.text.shield_name_00;
        game_o.shield[0].active           = false;
        game_o.shield[0].level            = 0;
        game_o.shield[0].level_1          = 256;
        game_o.shield[0].level_2          = 512;
        game_o.shield[0].level_3          = 1024;
        game_o.shield[0].experience       = 0;
        game_o.shield[0].image            = texture.shield_000.ref_number;
        game_o.shield[0].absorption       = 0.0005f;
        game_o.shield[1].name             = game_o.language.text.shield_name_01;
        game_o.shield[1].active           = false;
        game_o.shield[1].level            = 0;
        game_o.shield[1].level_1          = 512;
        game_o.shield[1].level_2          = 1024;
        game_o.shield[1].level_3          = 2048;
        game_o.shield[1].experience       = 0;
        game_o.shield[1].image            = texture.shield_001.ref_number;
        game_o.shield[1].absorption       = 0.0010f;
        game_o.shield[2].name             = game_o.language.text.shield_name_02;
        game_o.shield[2].active           = false;
        game_o.shield[2].level            = 0;
        game_o.shield[2].level_1          = 1024;
        game_o.shield[2].level_2          = 2048;
        game_o.shield[2].level_3          = 4096;
        game_o.shield[2].experience       = 0;
        game_o.shield[2].image            = texture.shield_002.ref_number;
        game_o.shield[2].absorption       = 0.0015f;
        game_o.shield[3].name             = game_o.language.text.shield_name_03;
        game_o.shield[3].active           = false;
        game_o.shield[3].level            = 0;
        game_o.shield[3].level_1          = 2048;
        game_o.shield[3].level_2          = 4096;
        game_o.shield[3].level_3          = 8192;
        game_o.shield[3].experience       = 0;
        game_o.shield[3].image            = texture.shield_003.ref_number;
        game_o.shield[3].absorption       = 0.0020f;
        game_o.shield[4].name             = game_o.language.text.shield_name_04;
        game_o.shield[4].active           = false;
        game_o.shield[4].level            = 0;
        game_o.shield[4].level_1          = 4096;
        game_o.shield[4].level_2          = 8192;
        game_o.shield[4].level_3          = 16384;
        game_o.shield[4].experience       = 0;
        game_o.shield[4].image            = texture.shield_004.ref_number;
        game_o.shield[4].absorption       = 0.0025f;
    }
};

