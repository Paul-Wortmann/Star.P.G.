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

#include "load_resources.hpp"
#include "RAGE/rage.hpp"

extern game_class        game;
       sound_type        sound;

bool load_resources(void)
{
    load_sounds();
    return(true);
};

bool load_sounds(void)
{
    int sfx_count = 0;
    sound.menu_move.load  ("data/sounds/menu_move.wav");  sfx_count++;
    sound.menu_select.load("data/sounds/menu_select.wav");sfx_count++;
    sound.bullet_001.load("data/sounds/bullet_001.wav");sfx_count++;
    sound.bullet_002.load("data/sounds/bullet_002.wav");sfx_count++;
    sound.explosion_001.load("data/sounds/explosion_001.wav");sfx_count++;
    sound.explosion_002.load("data/sounds/explosion_002.wav");sfx_count++;
    sound.explosion_003.load("data/sounds/explosion_003.wav");sfx_count++;
    sound.explosion_004.load("data/sounds/explosion_004.wav");sfx_count++;
    sound.explosion_005.load("data/sounds/explosion_005.wav");sfx_count++;
    sound.projectile_000.load("data/sounds/projectile_000.wav");sfx_count++;
    sound.projectile_001.load("data/sounds/projectile_001.wav");sfx_count++;
    sound.projectile_002.load("data/sounds/projectile_002.wav");sfx_count++;
    sound.projectile_003.load("data/sounds/projectile_003.wav");sfx_count++;
    sound.projectile_004.load("data/sounds/projectile_004.wav");sfx_count++;
    sound.projectile_005.load("data/sounds/projectile_005.wav");sfx_count++;
    sound.projectile_006.load("data/sounds/projectile_006.wav");sfx_count++;
    sound.projectile_007.load("data/sounds/projectile_007.wav");sfx_count++;
    sound.projectile_008.load("data/sounds/projectile_008.wav");sfx_count++;
    sound.projectile_009.load("data/sounds/projectile_009.wav");sfx_count++;
    sound.projectile_010.load("data/sounds/projectile_010.wav");sfx_count++;
    sound.projectile_011.load("data/sounds/projectile_011.wav");sfx_count++;
    sound.projectile_012.load("data/sounds/projectile_012.wav");sfx_count++;
    sound.projectile_013.load("data/sounds/projectile_013.wav");sfx_count++;
    sound.projectile_014.load("data/sounds/projectile_014.wav");sfx_count++;
    sound.projectile_015.load("data/sounds/projectile_015.wav");sfx_count++;
    sound.projectile_016.load("data/sounds/projectile_016.wav");sfx_count++;
    sound.projectile_017.load("data/sounds/projectile_017.wav");sfx_count++;
    sound.projectile_018.load("data/sounds/projectile_018.wav");sfx_count++;
    sound.projectile_019.load("data/sounds/projectile_019.wav");sfx_count++;
    sound.projectile_020.load("data/sounds/projectile_020.wav");sfx_count++;
    sound.projectile_021.load("data/sounds/projectile_021.wav");sfx_count++;
    sound.projectile_022.load("data/sounds/projectile_022.wav");sfx_count++;
    sound.projectile_023.load("data/sounds/projectile_023.wav");sfx_count++;
    sound.projectile_024.load("data/sounds/projectile_024.wav");sfx_count++;
    sound.projectile_025.load("data/sounds/projectile_025.wav");sfx_count++;
    sound.projectile_026.load("data/sounds/projectile_026.wav");sfx_count++;
    sound.projectile_027.load("data/sounds/projectile_027.wav");sfx_count++;
    sound.projectile_028.load("data/sounds/projectile_028.wav");sfx_count++;
    sound.projectile_029.load("data/sounds/projectile_029.wav");sfx_count++;
    sound.projectile_030.load("data/sounds/projectile_030.wav");sfx_count++;
    sound.shield_hit.load("data/sounds/shield_hit.wav");sfx_count++;
    sound.powerup_01.load("data/sounds/powerup_01.wav");sfx_count++;
    sound.powerup_02.load("data/sounds/powerup_02.wav");sfx_count++;
    sound.powerup_03.load("data/sounds/powerup_03.wav");sfx_count++;
    sound.powerup_04.load("data/sounds/powerup_04.wav");sfx_count++;
    sound.powerup_05.load("data/sounds/powerup_05.wav");sfx_count++;
    sound.powerup_06.load("data/sounds/powerup_06.wav");sfx_count++;
    sound.powerup_07.load("data/sounds/powerup_07.wav");sfx_count++;
    sound.coin_00.load("data/sounds/coin_00.wav");sfx_count++;
    sound.wexp_00.load("data/sounds/wexp_00.wav");sfx_count++;

    game.log.File_Write("Sound files loaded -> ",sfx_count-1);
    return(true);
};
/*
bool load_music(void)
{
    return(true);
};

bool load_textures(void)
{
    return(true);
};
*/



