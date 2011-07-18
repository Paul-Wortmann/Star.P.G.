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

#ifndef LOAD_RESOURCES_H
#define LOAD_RESOURCES_H

#include "RAGE/rage.hpp"
#include "RAGE/sound.hpp"
#include "RAGE/music.hpp"

struct sound_type
{
    sound_class menu_move;
    sound_class menu_select;
    sound_class bullet_001;
    sound_class bullet_002;
    sound_class explosion_001;
    sound_class explosion_002;
    sound_class explosion_003;
    sound_class explosion_004;
    sound_class explosion_005;
    sound_class projectile_000;
    sound_class projectile_001;
    sound_class projectile_002;
    sound_class projectile_003;
    sound_class projectile_004;
    sound_class projectile_005;
    sound_class projectile_006;
    sound_class projectile_007;
    sound_class projectile_008;
    sound_class projectile_009;
    sound_class projectile_010;
    sound_class projectile_011;
    sound_class projectile_012;
    sound_class projectile_013;
    sound_class projectile_014;
    sound_class projectile_015;
    sound_class projectile_016;
    sound_class projectile_017;
    sound_class projectile_018;
    sound_class projectile_019;
    sound_class projectile_020;
    sound_class projectile_021;
    sound_class projectile_022;
    sound_class projectile_023;
    sound_class projectile_024;
    sound_class projectile_025;
    sound_class projectile_026;
    sound_class projectile_027;
    sound_class projectile_028;
    sound_class projectile_029;
    sound_class projectile_030;
    sound_class shield_hit;
    sound_class powerup_01;
    sound_class powerup_02;
    sound_class powerup_03;
    sound_class powerup_04;
    sound_class powerup_05;
    sound_class powerup_06;
    sound_class powerup_07;
    sound_class coin_00;
    sound_class wexp_00;
};

struct music_type
{
    music_class level_00;
    music_class level_01;
    music_class level_02;
    music_class level_03;
    music_class level_04;
    music_class level_05;
    music_class level_06;
    music_class level_07;
    music_class level_08;
    music_class level_09;
    music_class level_10;
    music_class level_11;
    music_class level_12;
    music_class level_13;
    music_class level_14;
    music_class level_15;
    music_class level_16;
    music_class level_17;
    music_class level_18;
    music_class level_19;
    music_class level_20;
    music_class level_21;
    music_class level_22;
    music_class level_23;
    music_class level_24;
    music_class level_25;
    music_class menu_00;
    music_class level_nl;
    music_class level_pd;
    music_class outro_00;
};

/*
struct texture_type
{
};
*/


bool load_resources(void);
bool load_sounds(void);
bool load_music(void);
//bool load_textures(void);

#endif // LOAD_RESOURCES_H
