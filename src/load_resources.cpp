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
 * @author  Paul Wortmann
 * @email   physhex@gmail.com
 * @website www.physhexgames.co.nr
 * @license GPL
 * @date 2011-09-03
 */

#include <SDL/SDL.h>
#include "load_resources.hpp"
#include "RAGE/rage.hpp"

extern game_class        game;
       sound_type        sound;
       music_type        music;
       texture_type      texture;
       font_type         font;

bool load_resources(void)
{
    load_sounds();
    load_music();
    load_textures();
    load_fonts();
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
    sound.powerup_08.load("data/sounds/powerup_08.wav");sfx_count++;
    sound.powerup_09.load("data/sounds/powerup_09.wav");sfx_count++;
    sound.powerup_10.load("data/sounds/powerup_10.wav");sfx_count++;
    sound.powerup_11.load("data/sounds/powerup_11.wav");sfx_count++;
    sound.powerup_12.load("data/sounds/powerup_12.wav");sfx_count++;
    sound.coin_00.load("data/sounds/coin_00.wav");sfx_count++;
    sound.wexp_00.load("data/sounds/wexp_00.wav");sfx_count++;

    game.log.File_Write("Sound files loaded -> ",sfx_count);
    return(true);
};

bool load_music(void)
{
    int music_count = 0;
    music.level_00.load("data/music/level_00.s3m");music_count++;
    music.level_01.load("data/music/level_01.s3m");music_count++;
    music.level_02.load("data/music/level_02.s3m");music_count++;
    music.level_03.load("data/music/level_03.s3m");music_count++;
    music.level_04.load("data/music/level_04.s3m");music_count++;
    music.level_05.load("data/music/level_05.s3m");music_count++;
    music.level_06.load("data/music/level_06.it") ;music_count++;
    music.level_07.load("data/music/level_07.it") ;music_count++;
    music.level_08.load("data/music/level_08.it") ;music_count++;
    music.level_09.load("data/music/level_09.it") ;music_count++;
    music.level_10.load("data/music/level_10.it") ;music_count++;
    music.level_11.load("data/music/level_11.it") ;music_count++;
    music.level_12.load("data/music/level_12.mod");music_count++;
    music.level_13.load("data/music/level_13.mod");music_count++;
    music.level_14.load("data/music/level_14.mod");music_count++;
    music.level_15.load("data/music/level_15.mod");music_count++;
    music.level_16.load("data/music/level_16.mod");music_count++;
    music.level_17.load("data/music/level_17.mod");music_count++;
    music.level_18.load("data/music/level_18.mod");music_count++;
    music.level_19.load("data/music/level_19.mod");music_count++;
    music.level_20.load("data/music/level_20.mod");music_count++;
    music.level_21.load("data/music/level_21.mod");music_count++;
    music.level_22.load("data/music/level_22.mod");music_count++;
    music.level_23.load("data/music/level_23.mod");music_count++;
    music.level_24.load("data/music/level_24.mod");music_count++;
    music.level_25.load("data/music/level_25.mod");music_count++;
    music.level_25.load("data/music/level_25.mod");music_count++;

    music.menu_00.load ("data/music/menu_00.it") ;music_count++;
    music.level_nl.load("data/music/level_nl.mod");music_count++;
    music.level_pd.load("data/music/level_pd.mod");music_count++;
    music.outro_00.load("data/music/outro_00.mod");music_count++;

    game.log.File_Write("Music files loaded -> ",music_count);
    return(true);
};

bool load_textures(void)
{
    int texture_count = 0;
    texture.logo.load_image("data/textures/menu/logo.png",texture_count);texture_count++;

    texture.menu_background_000.load_image("data/textures/backgrounds/menu_background_000.png",texture_count);texture_count++;
    texture.menu_background_001.load_image("data/textures/backgrounds/menu_background_001.png",texture_count);texture_count++;
    texture.background_000.load_image("data/textures/backgrounds/background_000.png",texture_count);texture_count++;
    texture.background_001.load_image("data/textures/backgrounds/background_001.png",texture_count);texture_count++;
    texture.background_002.load_image("data/textures/backgrounds/background_002.png",texture_count);texture_count++;
    texture.background_003.load_image("data/textures/backgrounds/background_003.png",texture_count);texture_count++;
    texture.background_004.load_image("data/textures/backgrounds/background_004.png",texture_count);texture_count++;
    texture.background_005.load_image("data/textures/backgrounds/background_005.png",texture_count);texture_count++;
    texture.background_006.load_image("data/textures/backgrounds/background_006.png",texture_count);texture_count++;
    texture.background_007.load_image("data/textures/backgrounds/background_007.png",texture_count);texture_count++;
    texture.background_008.load_image("data/textures/backgrounds/background_008.png",texture_count);texture_count++;
    texture.background_009.load_image("data/textures/backgrounds/background_009.png",texture_count);texture_count++;
    texture.background_010.load_image("data/textures/backgrounds/background_010.png",texture_count);texture_count++;
    texture.background_011.load_image("data/textures/backgrounds/background_011.png",texture_count);texture_count++;
    texture.background_012.load_image("data/textures/backgrounds/background_012.png",texture_count);texture_count++;
    texture.background_013.load_image("data/textures/backgrounds/background_013.png",texture_count);texture_count++;
    texture.background_014.load_image("data/textures/backgrounds/background_014.png",texture_count);texture_count++;
    texture.background_015.load_image("data/textures/backgrounds/background_015.png",texture_count);texture_count++;
    texture.background_016.load_image("data/textures/backgrounds/background_016.png",texture_count);texture_count++;
    texture.background_017.load_image("data/textures/backgrounds/background_017.png",texture_count);texture_count++;
    texture.background_018.load_image("data/textures/backgrounds/background_018.png",texture_count);texture_count++;
    texture.background_019.load_image("data/textures/backgrounds/background_019.png",texture_count);texture_count++;
    texture.background_020.load_image("data/textures/backgrounds/background_020.png",texture_count);texture_count++;
    texture.background_021.load_image("data/textures/backgrounds/background_021.png",texture_count);texture_count++;
    texture.background_022.load_image("data/textures/backgrounds/background_022.png",texture_count);texture_count++;
    texture.background_023.load_image("data/textures/backgrounds/background_023.png",texture_count);texture_count++;
    texture.background_024.load_image("data/textures/backgrounds/background_024.png",texture_count);texture_count++;
    texture.background_025.load_image("data/textures/backgrounds/background_025.png",texture_count);texture_count++;
    texture.background_026.load_image("data/textures/backgrounds/background_026.png",texture_count);texture_count++;
    texture.background_027.load_image("data/textures/backgrounds/background_027.png",texture_count);texture_count++;
    texture.background_028.load_image("data/textures/backgrounds/background_028.png",texture_count);texture_count++;
    texture.background_029.load_image("data/textures/backgrounds/background_029.png",texture_count);texture_count++;
    texture.background_030.load_image("data/textures/backgrounds/background_030.png",texture_count);texture_count++;
    texture.background_031.load_image("data/textures/backgrounds/background_031.png",texture_count);texture_count++;

    texture.level_00.load_image("data/textures/levels/level_00.png",texture_count);texture_count++;
    texture.level_01.load_image("data/textures/levels/level_01.png",texture_count);texture_count++;
    texture.level_02.load_image("data/textures/levels/level_02.png",texture_count);texture_count++;
    texture.level_03.load_image("data/textures/levels/level_03.png",texture_count);texture_count++;
    texture.level_04.load_image("data/textures/levels/level_04.png",texture_count);texture_count++;
    texture.level_05.load_image("data/textures/levels/level_05.png",texture_count);texture_count++;
    texture.level_06.load_image("data/textures/levels/level_06.png",texture_count);texture_count++;
    texture.level_07.load_image("data/textures/levels/level_07.png",texture_count);texture_count++;
    texture.level_08.load_image("data/textures/levels/level_08.png",texture_count);texture_count++;
    texture.level_09.load_image("data/textures/levels/level_09.png",texture_count);texture_count++;
    texture.level_10.load_image("data/textures/levels/level_10.png",texture_count);texture_count++;
    texture.level_11.load_image("data/textures/levels/level_11.png",texture_count);texture_count++;
    texture.level_12.load_image("data/textures/levels/level_12.png",texture_count);texture_count++;
    texture.level_13.load_image("data/textures/levels/level_13.png",texture_count);texture_count++;
    texture.level_14.load_image("data/textures/levels/level_14.png",texture_count);texture_count++;
    texture.level_15.load_image("data/textures/levels/level_15.png",texture_count);texture_count++;
    texture.level_16.load_image("data/textures/levels/level_16.png",texture_count);texture_count++;
    texture.level_17.load_image("data/textures/levels/level_17.png",texture_count);texture_count++;
    texture.level_18.load_image("data/textures/levels/level_18.png",texture_count);texture_count++;
    texture.level_19.load_image("data/textures/levels/level_19.png",texture_count);texture_count++;
    texture.level_20.load_image("data/textures/levels/level_20.png",texture_count);texture_count++;
    texture.level_21.load_image("data/textures/levels/level_21.png",texture_count);texture_count++;
    texture.level_22.load_image("data/textures/levels/level_22.png",texture_count);texture_count++;
    texture.level_23.load_image("data/textures/levels/level_23.png",texture_count);texture_count++;
    texture.level_24.load_image("data/textures/levels/level_24.png",texture_count);texture_count++;

    texture.level_highlighted_00.load_image("data/textures/levels/level_highlighted_00.png",texture_count);texture_count++;
    texture.level_highlighted_01.load_image("data/textures/levels/level_highlighted_01.png",texture_count);texture_count++;
    texture.level_highlighted_02.load_image("data/textures/levels/level_highlighted_02.png",texture_count);texture_count++;
    texture.level_highlighted_03.load_image("data/textures/levels/level_highlighted_03.png",texture_count);texture_count++;
    texture.level_highlighted_04.load_image("data/textures/levels/level_highlighted_04.png",texture_count);texture_count++;
    texture.level_highlighted_05.load_image("data/textures/levels/level_highlighted_05.png",texture_count);texture_count++;
    texture.level_highlighted_06.load_image("data/textures/levels/level_highlighted_06.png",texture_count);texture_count++;
    texture.level_highlighted_07.load_image("data/textures/levels/level_highlighted_07.png",texture_count);texture_count++;
    texture.level_highlighted_08.load_image("data/textures/levels/level_highlighted_08.png",texture_count);texture_count++;
    texture.level_highlighted_09.load_image("data/textures/levels/level_highlighted_09.png",texture_count);texture_count++;
    texture.level_highlighted_10.load_image("data/textures/levels/level_highlighted_10.png",texture_count);texture_count++;
    texture.level_highlighted_11.load_image("data/textures/levels/level_highlighted_11.png",texture_count);texture_count++;
    texture.level_highlighted_12.load_image("data/textures/levels/level_highlighted_12.png",texture_count);texture_count++;
    texture.level_highlighted_13.load_image("data/textures/levels/level_highlighted_13.png",texture_count);texture_count++;
    texture.level_highlighted_14.load_image("data/textures/levels/level_highlighted_14.png",texture_count);texture_count++;
    texture.level_highlighted_15.load_image("data/textures/levels/level_highlighted_15.png",texture_count);texture_count++;
    texture.level_highlighted_16.load_image("data/textures/levels/level_highlighted_16.png",texture_count);texture_count++;
    texture.level_highlighted_17.load_image("data/textures/levels/level_highlighted_17.png",texture_count);texture_count++;
    texture.level_highlighted_18.load_image("data/textures/levels/level_highlighted_18.png",texture_count);texture_count++;
    texture.level_highlighted_19.load_image("data/textures/levels/level_highlighted_19.png",texture_count);texture_count++;
    texture.level_highlighted_20.load_image("data/textures/levels/level_highlighted_20.png",texture_count);texture_count++;
    texture.level_highlighted_21.load_image("data/textures/levels/level_highlighted_21.png",texture_count);texture_count++;
    texture.level_highlighted_22.load_image("data/textures/levels/level_highlighted_22.png",texture_count);texture_count++;
    texture.level_highlighted_23.load_image("data/textures/levels/level_highlighted_23.png",texture_count);texture_count++;
    texture.level_highlighted_24.load_image("data/textures/levels/level_highlighted_24.png",texture_count);texture_count++;

    texture.level_preview_00.load_image("data/textures/levels/level_preview_00.png",texture_count);texture_count++;
    texture.level_preview_01.load_image("data/textures/levels/level_preview_01.png",texture_count);texture_count++;
    texture.level_preview_02.load_image("data/textures/levels/level_preview_02.png",texture_count);texture_count++;
    texture.level_preview_03.load_image("data/textures/levels/level_preview_03.png",texture_count);texture_count++;
    texture.level_preview_04.load_image("data/textures/levels/level_preview_04.png",texture_count);texture_count++;
    texture.level_preview_05.load_image("data/textures/levels/level_preview_05.png",texture_count);texture_count++;
    texture.level_preview_06.load_image("data/textures/levels/level_preview_06.png",texture_count);texture_count++;
    texture.level_preview_07.load_image("data/textures/levels/level_preview_07.png",texture_count);texture_count++;
    texture.level_preview_08.load_image("data/textures/levels/level_preview_08.png",texture_count);texture_count++;
    texture.level_preview_09.load_image("data/textures/levels/level_preview_09.png",texture_count);texture_count++;
    texture.level_preview_10.load_image("data/textures/levels/level_preview_10.png",texture_count);texture_count++;
    texture.level_preview_11.load_image("data/textures/levels/level_preview_11.png",texture_count);texture_count++;
    texture.level_preview_12.load_image("data/textures/levels/level_preview_12.png",texture_count);texture_count++;
    texture.level_preview_13.load_image("data/textures/levels/level_preview_13.png",texture_count);texture_count++;
    texture.level_preview_14.load_image("data/textures/levels/level_preview_14.png",texture_count);texture_count++;
    texture.level_preview_15.load_image("data/textures/levels/level_preview_15.png",texture_count);texture_count++;
    texture.level_preview_16.load_image("data/textures/levels/level_preview_16.png",texture_count);texture_count++;
    texture.level_preview_17.load_image("data/textures/levels/level_preview_17.png",texture_count);texture_count++;
    texture.level_preview_18.load_image("data/textures/levels/level_preview_18.png",texture_count);texture_count++;
    texture.level_preview_19.load_image("data/textures/levels/level_preview_19.png",texture_count);texture_count++;
    texture.level_preview_20.load_image("data/textures/levels/level_preview_20.png",texture_count);texture_count++;
    texture.level_preview_21.load_image("data/textures/levels/level_preview_21.png",texture_count);texture_count++;
    texture.level_preview_22.load_image("data/textures/levels/level_preview_22.png",texture_count);texture_count++;
    texture.level_preview_23.load_image("data/textures/levels/level_preview_23.png",texture_count);texture_count++;
    texture.level_preview_24.load_image("data/textures/levels/level_preview_24.png",texture_count);texture_count++;
    texture.level_preview_locked.load_image("data/textures/levels/level_preview_locked.png",texture_count);texture_count++;

    texture.explosion_00.load_spritesheet("data/textures/explosions/explosion_00.png",texture_count);texture_count++;
    texture.explosion_01.load_spritesheet("data/textures/explosions/explosion_01.png",texture_count);texture_count++;
    texture.explosion_02.load_spritesheet("data/textures/explosions/explosion_02.png",texture_count);texture_count++;

    texture.health_bar.load_image("data/textures/misc/health_bar.png",texture_count);texture_count++;

    texture.weapon_000.load_image("data/textures/weapons/weapon_000.png",texture_count);texture_count++;
    texture.weapon_001.load_image("data/textures/weapons/weapon_001.png",texture_count);texture_count++;
    texture.weapon_002.load_image("data/textures/weapons/weapon_002.png",texture_count);texture_count++;
    texture.weapon_003.load_image("data/textures/weapons/weapon_003.png",texture_count);texture_count++;
    texture.weapon_004.load_image("data/textures/weapons/weapon_004.png",texture_count);texture_count++;
    texture.weapon_005.load_image("data/textures/weapons/weapon_005.png",texture_count);texture_count++;

    texture.shield_000.load_image("data/textures/shields/shield_000.png",texture_count);texture_count++;
    texture.shield_001.load_image("data/textures/shields/shield_001.png",texture_count);texture_count++;
    texture.shield_002.load_image("data/textures/shields/shield_002.png",texture_count);texture_count++;
    texture.shield_003.load_image("data/textures/shields/shield_003.png",texture_count);texture_count++;
    texture.shield_004.load_image("data/textures/shields/shield_004.png",texture_count);texture_count++;

    texture.projectile_000.load_image("data/textures/projectiles/projectile_000.png",texture_count);texture_count++;
    texture.projectile_001.load_image("data/textures/projectiles/projectile_001.png",texture_count);texture_count++;
    texture.projectile_002.load_image("data/textures/projectiles/projectile_002.png",texture_count);texture_count++;
    texture.projectile_003.load_image("data/textures/projectiles/projectile_003.png",texture_count);texture_count++;
    texture.projectile_004.load_image("data/textures/projectiles/projectile_004.png",texture_count);texture_count++;
    texture.projectile_005.load_image("data/textures/projectiles/projectile_005.png",texture_count);texture_count++;
    texture.projectile_006.load_image("data/textures/projectiles/projectile_006.png",texture_count);texture_count++;
    texture.projectile_007.load_image("data/textures/projectiles/projectile_007.png",texture_count);texture_count++;
    texture.projectile_008.load_image("data/textures/projectiles/projectile_008.png",texture_count);texture_count++;
    texture.projectile_009.load_image("data/textures/projectiles/projectile_009.png",texture_count);texture_count++;
    texture.projectile_010.load_image("data/textures/projectiles/projectile_010.png",texture_count);texture_count++;
    texture.projectile_011.load_image("data/textures/projectiles/projectile_011.png",texture_count);texture_count++;
    texture.projectile_012.load_image("data/textures/projectiles/projectile_012.png",texture_count);texture_count++;
    texture.projectile_013.load_image("data/textures/projectiles/projectile_013.png",texture_count);texture_count++;
    texture.projectile_014.load_image("data/textures/projectiles/projectile_014.png",texture_count);texture_count++;
    texture.projectile_015.load_image("data/textures/projectiles/projectile_015.png",texture_count);texture_count++;
    texture.projectile_016.load_image("data/textures/projectiles/projectile_016.png",texture_count);texture_count++;
    texture.projectile_017.load_image("data/textures/projectiles/projectile_017.png",texture_count);texture_count++;
    texture.projectile_018.load_image("data/textures/projectiles/projectile_018.png",texture_count);texture_count++;
    texture.projectile_019.load_image("data/textures/projectiles/projectile_019.png",texture_count);texture_count++;
    texture.projectile_020.load_image("data/textures/projectiles/projectile_020.png",texture_count);texture_count++;
    texture.projectile_021.load_image("data/textures/projectiles/projectile_021.png",texture_count);texture_count++;
    texture.projectile_022.load_image("data/textures/projectiles/projectile_022.png",texture_count);texture_count++;
    texture.projectile_023.load_image("data/textures/projectiles/projectile_023.png",texture_count);texture_count++;
    texture.projectile_024.load_image("data/textures/projectiles/projectile_024.png",texture_count);texture_count++;
    texture.projectile_025.load_image("data/textures/projectiles/projectile_025.png",texture_count);texture_count++;
    texture.projectile_026.load_image("data/textures/projectiles/projectile_026.png",texture_count);texture_count++;
    texture.projectile_027.load_image("data/textures/projectiles/projectile_027.png",texture_count);texture_count++;
    texture.projectile_028.load_image("data/textures/projectiles/projectile_028.png",texture_count);texture_count++;
    texture.projectile_029.load_image("data/textures/projectiles/projectile_029.png",texture_count);texture_count++;
    texture.projectile_030.load_image("data/textures/projectiles/projectile_030.png",texture_count);texture_count++;
    texture.projectile_031.load_image("data/textures/projectiles/projectile_031.png",texture_count);texture_count++;

    texture.ship_000.load_image("data/textures/ships/ship_000.png",texture_count);texture_count++;
    texture.ship_001.load_image("data/textures/ships/ship_001.png",texture_count);texture_count++;
    texture.ship_002.load_image("data/textures/ships/ship_002.png",texture_count);texture_count++;
    texture.ship_003.load_image("data/textures/ships/ship_003.png",texture_count);texture_count++;
    texture.ship_004.load_image("data/textures/ships/ship_004.png",texture_count);texture_count++;
    texture.ship_005.load_image("data/textures/ships/ship_005.png",texture_count);texture_count++;
    texture.ship_006.load_image("data/textures/ships/ship_006.png",texture_count);texture_count++;
    texture.ship_007.load_image("data/textures/ships/ship_007.png",texture_count);texture_count++;
    texture.ship_008.load_image("data/textures/ships/ship_008.png",texture_count);texture_count++;
    texture.ship_009.load_image("data/textures/ships/ship_009.png",texture_count);texture_count++;
    texture.ship_010.load_image("data/textures/ships/ship_010.png",texture_count);texture_count++;
    texture.ship_011.load_image("data/textures/ships/ship_011.png",texture_count);texture_count++;
    texture.ship_012.load_image("data/textures/ships/ship_012.png",texture_count);texture_count++;
    texture.ship_013.load_image("data/textures/ships/ship_013.png",texture_count);texture_count++;
    texture.ship_014.load_image("data/textures/ships/ship_014.png",texture_count);texture_count++;
    texture.ship_015.load_image("data/textures/ships/ship_015.png",texture_count);texture_count++;
    texture.ship_016.load_image("data/textures/ships/ship_016.png",texture_count);texture_count++;
    texture.ship_017.load_image("data/textures/ships/ship_017.png",texture_count);texture_count++;
    texture.ship_018.load_image("data/textures/ships/ship_018.png",texture_count);texture_count++;
    texture.ship_019.load_image("data/textures/ships/ship_019.png",texture_count);texture_count++;
    texture.ship_020.load_image("data/textures/ships/ship_020.png",texture_count);texture_count++;
    texture.ship_021.load_image("data/textures/ships/ship_021.png",texture_count);texture_count++;
    texture.ship_022.load_image("data/textures/ships/ship_022.png",texture_count);texture_count++;
    texture.ship_023.load_image("data/textures/ships/ship_023.png",texture_count);texture_count++;
    texture.ship_024.load_image("data/textures/ships/ship_024.png",texture_count);texture_count++;
    texture.ship_025.load_image("data/textures/ships/ship_025.png",texture_count);texture_count++;

    texture.thruster_000.load_image("data/textures/thrusters/thruster_000.png",texture_count);texture_count++;
    texture.thruster_001.load_image("data/textures/thrusters/thruster_001.png",texture_count);texture_count++;
    texture.thruster_002.load_image("data/textures/thrusters/thruster_002.png",texture_count);texture_count++;
    texture.thruster_003.load_image("data/textures/thrusters/thruster_003.png",texture_count);texture_count++;

    texture.selection_box.load_image("data/textures/misc/selection_box.png",texture_count);texture_count++;
    texture.none.load_image("data/textures/misc/none.png",texture_count);texture_count++;
    texture.locked.load_image("data/textures/misc/locked.png",texture_count);texture_count++;
    texture.weapon_bar.load_image("data/textures/misc/weapon_bar.png",texture_count);texture_count++;
    texture.shield_bar.load_image("data/textures/misc/shield_bar.png",texture_count);texture_count++;
    texture.thruster_bar.load_image("data/textures/misc/thruster_bar.png",texture_count);texture_count++;
    texture.game_paused.load_image("data/textures/misc/game_paused.png",texture_count);texture_count++;
    texture.game_saved.load_image("data/textures/misc/game_saved.png",texture_count);texture_count++;
    texture.game_loaded.load_image("data/textures/misc/game_loaded.png",texture_count);texture_count++;

    texture.health_powerup.load_image("data/textures/powerups/health_powerup.png",texture_count);texture_count++;
    texture.shield_lvlup_powerup.load_image("data/textures/powerups/shield_lvlup_powerup.png",texture_count);texture_count++;
    texture.shield_new_powerup.load_image("data/textures/powerups/shield_new_powerup.png",texture_count);texture_count++;
    texture.thruster_lvlup_powerup.load_image("data/textures/powerups/thruster_lvlup_powerup.png",texture_count);texture_count++;
    texture.thruster_new_powerup.load_image("data/textures/powerups/thruster_new_powerup.png",texture_count);texture_count++;
    texture.weapon_lvlup_powerup.load_image("data/textures/powerups/weapon_lvlup_powerup.png",texture_count);texture_count++;
    texture.weapon_new_powerup.load_image("data/textures/powerups/weapon_new_powerup.png",texture_count);texture_count++;

    texture.grey_star.load_image("data/textures/menu/grey_star.png",texture_count);texture_count++;
    texture.bronze_star.load_image("data/textures/menu/bronze_star.png",texture_count);texture_count++;
    texture.silver_star.load_image("data/textures/menu/silver_star.png",texture_count);texture_count++;
    texture.gold_star.load_image("data/textures/menu/gold_star.png",texture_count);texture_count++;

    texture.kills_achievement.load_image("data/textures/misc/kills_achievement.png",texture_count);texture_count++;
    texture.score_achievement.load_image("data/textures/misc/score_achievement.png",texture_count);texture_count++;
    texture.actinium_shields.load_image("data/textures/misc/actinium_shields.png",texture_count);texture_count++;
    texture.blasters.load_image("data/textures/misc/blasters.png",texture_count);texture_count++;
    texture.burst_lasers.load_image("data/textures/misc/burst_lasers.png",texture_count);texture_count++;
    texture.chain_guns.load_image("data/textures/misc/chain_guns.png",texture_count);texture_count++;
    texture.convolution_thrusters.load_image("data/textures/misc/convolution_thrusters.png",texture_count);texture_count++;

    texture.health.load_image("data/textures/misc/health.png",texture_count);texture_count++;
    texture.ion_cannons.load_image("data/textures/misc/ion_cannons.png",texture_count);texture_count++;
    texture.iridium_shileds.load_image("data/textures/misc/iridium_shileds.png",texture_count);texture_count++;
    texture.maelstrom_thrusters.load_image("data/textures/misc/maelstrom_thrusters.png",texture_count);texture_count++;
    texture.plasma_rockets.load_image("data/textures/misc/plasma_rockets.png",texture_count);texture_count++;
    texture.rail_turrets.load_image("data/textures/misc/rail_turrets.png",texture_count);texture_count++;
    texture.rubidium_shields.load_image("data/textures/misc/rubidium_shields.png",texture_count);texture_count++;
    texture.seismic_thrusters.load_image("data/textures/misc/seismic_thrusters.png",texture_count);texture_count++;
    texture.shield_level_up.load_image("data/textures/misc/shield_level_up.png",texture_count);texture_count++;
    texture.tantalum_shields.load_image("data/textures/misc/tantalum_shields.png",texture_count);texture_count++;
    texture.terbium_shields.load_image("data/textures/misc/terbium_shields.png",texture_count);texture_count++;
    texture.thrusters_level_up.load_image("data/textures/misc/thrusters_level_up.png",texture_count);texture_count++;
    texture.vortex_thrusters.load_image("data/textures/misc/vortex_thrusters.png",texture_count);texture_count++;
    texture.weapon_level_up.load_image("data/textures/misc/weapon_level_up.png",texture_count);texture_count++;

    texture.game_over.load_image("data/textures/menu/game_over.png",texture_count);texture_count++;
    texture.logo_red.load_image("data/textures/menu/logo_red.png",texture_count);texture_count++;
    texture.explosion_001.load_image("data/textures/misc/explosion_001.png",texture_count);texture_count++;
    texture.level_completed.load_image("data/textures/menu/level_completed.png",texture_count);texture_count++;
    texture.new_level_unlocked.load_image("data/textures/menu/new_level_unlocked.png",texture_count);texture_count++;

    texture.coin_powerup.load_image("data/textures/powerups/coin_powerup.png",texture_count);texture_count++;
    texture.wexp_powerup.load_image("data/textures/powerups/wexp_powerup.png",texture_count);texture_count++;
    texture.credits_00.load_image("data/textures/misc/credits_00.png",texture_count);texture_count++;
    texture.level_progress_bar.load_image("data/textures/misc/level_progress_bar.png",texture_count);texture_count++;
    texture.bomb_powerup.load_image("data/textures/powerups/bomb_powerup.png",texture_count);texture_count++;
    texture.sideship_00.load_image("data/textures/ships/sideship_00.png",texture_count);texture_count++;
    texture.sideship_01.load_image("data/textures/ships/sideship_01.png",texture_count);texture_count++;
    texture.sideship_02.load_image("data/textures/ships/sideship_02.png",texture_count);texture_count++;
    texture.sideship_03.load_image("data/textures/ships/sideship_03.png",texture_count);texture_count++;
    texture.powerup_sideship_00.load_image("data/textures/powerups/powerup_sideship_00.png",texture_count);texture_count++;
    texture.powerup_sideship_01.load_image("data/textures/powerups/powerup_sideship_01.png",texture_count);texture_count++;
    texture.powerup_sideship_02.load_image("data/textures/powerups/powerup_sideship_02.png",texture_count);texture_count++;
    texture.powerup_sideship_03.load_image("data/textures/powerups/powerup_sideship_03.png",texture_count);texture_count++;
    texture.touchscreen_arrow.load_image("data/textures/misc/touchscreen_arrow.png",texture_count);texture_count++;
    texture.touchscreen_button.load_image("data/textures/misc/touchscreen_button.png",texture_count);texture_count++;

    texture.menu_background_002.load_image("data/textures/menu/menu_background_03.png",texture_count);texture_count++;
    texture.menu_background_003.load_image("data/textures/menu/menu_background_04.png",texture_count);texture_count++;
    texture.red_button.load_image("data/textures/menu/red_button.png",texture_count);texture_count++;
    texture.red_button_highlighted.load_image("data/textures/menu/red_button_highlighted.png",texture_count);texture_count++;
    texture.green_button.load_image("data/textures/menu/green_button.png",texture_count);texture_count++;
    texture.green_button_highlighted.load_image("data/textures/menu/green_button_highlighted.png",texture_count);texture_count++;
    texture.blue_button.load_image("data/textures/menu/blue_button.png",texture_count);texture_count++;
    texture.blue_button_highlighted.load_image("data/textures/menu/blue_button_highlighted.png",texture_count);texture_count++;
    texture.arrow_button_normal.load_image("data/textures/menu/arrow_normal.png",texture_count);texture_count++;
    texture.arrow_button_highlighted.load_image("data/textures/menu/arrow_highlighted.png",texture_count);texture_count++;
    texture.arrow_button_disabled.load_image("data/textures/menu/arrow_disabled.png",texture_count);texture_count++;
    texture.slider_normal.load_image("data/textures/menu/slider_normal.png",texture_count);texture_count++;
    texture.slider_highlighted.load_image("data/textures/menu/slider_highlighted.png",texture_count);texture_count++;
    texture.resolution_icon.load_image("data/textures/menu/resolution_icon.png",texture_count);texture_count++;
    game.log.File_Write("Texture files loaded -> ",texture_count);
    return(true);
};

bool load_fonts(void)
{
    int font_count = 0;
    font.font_1.Set_File("data/fonts/font_001.ttf");font_count++;
    font.font_2.Set_File("data/fonts/font_002.ttf");font_count++;
    game.log.File_Write("Font files loaded -> ",font_count);
    return(true);
};

bool loading_screen_display(std::string file_name)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    SDL_GL_SwapBuffers();
    texture_class loading_screen;
    loading_screen.load_image(file_name,0);
    loading_screen.draw(0.0f,0.0f,0.9f,2.0f,2.0f);
    SDL_GL_SwapBuffers();
    return(true);
};

bool draw_texture(int texture_number, float x, float y, float z, float w, float h)
{
    draw_texture(texture_number,x,y,z,w,h,0.0f);
};

bool draw_texture(int texture_number, float x, float y, float z, float w, float h, float angle)
{
    if (texture_number == texture.logo.ref_number) texture.logo.draw(x,y,z,w,h,angle);

    if (texture_number == texture.menu_background_000.ref_number) texture.menu_background_000.draw(x,y,z,w,h,angle);
    if (texture_number == texture.menu_background_001.ref_number) texture.menu_background_001.draw(x,y,z,w,h,angle);
    if (texture_number == texture.background_000.ref_number) texture.background_000.draw(x,y,z,w,h,angle);
    if (texture_number == texture.background_001.ref_number) texture.background_001.draw(x,y,z,w,h,angle);
    if (texture_number == texture.background_002.ref_number) texture.background_002.draw(x,y,z,w,h,angle);
    if (texture_number == texture.background_003.ref_number) texture.background_003.draw(x,y,z,w,h,angle);
    if (texture_number == texture.background_004.ref_number) texture.background_004.draw(x,y,z,w,h,angle);
    if (texture_number == texture.background_005.ref_number) texture.background_005.draw(x,y,z,w,h,angle);
    if (texture_number == texture.background_006.ref_number) texture.background_006.draw(x,y,z,w,h,angle);
    if (texture_number == texture.background_007.ref_number) texture.background_007.draw(x,y,z,w,h,angle);
    if (texture_number == texture.background_008.ref_number) texture.background_008.draw(x,y,z,w,h,angle);
    if (texture_number == texture.background_009.ref_number) texture.background_009.draw(x,y,z,w,h,angle);
    if (texture_number == texture.background_010.ref_number) texture.background_010.draw(x,y,z,w,h,angle);
    if (texture_number == texture.background_011.ref_number) texture.background_011.draw(x,y,z,w,h,angle);
    if (texture_number == texture.background_012.ref_number) texture.background_012.draw(x,y,z,w,h,angle);
    if (texture_number == texture.background_013.ref_number) texture.background_013.draw(x,y,z,w,h,angle);
    if (texture_number == texture.background_014.ref_number) texture.background_014.draw(x,y,z,w,h,angle);
    if (texture_number == texture.background_015.ref_number) texture.background_015.draw(x,y,z,w,h,angle);
    if (texture_number == texture.background_016.ref_number) texture.background_016.draw(x,y,z,w,h,angle);
    if (texture_number == texture.background_017.ref_number) texture.background_017.draw(x,y,z,w,h,angle);
    if (texture_number == texture.background_018.ref_number) texture.background_018.draw(x,y,z,w,h,angle);
    if (texture_number == texture.background_019.ref_number) texture.background_019.draw(x,y,z,w,h,angle);
    if (texture_number == texture.background_020.ref_number) texture.background_020.draw(x,y,z,w,h,angle);
    if (texture_number == texture.background_021.ref_number) texture.background_021.draw(x,y,z,w,h,angle);
    if (texture_number == texture.background_022.ref_number) texture.background_022.draw(x,y,z,w,h,angle);
    if (texture_number == texture.background_023.ref_number) texture.background_023.draw(x,y,z,w,h,angle);
    if (texture_number == texture.background_024.ref_number) texture.background_024.draw(x,y,z,w,h,angle);
    if (texture_number == texture.background_025.ref_number) texture.background_025.draw(x,y,z,w,h,angle);
    if (texture_number == texture.background_026.ref_number) texture.background_026.draw(x,y,z,w,h,angle);
    if (texture_number == texture.background_027.ref_number) texture.background_027.draw(x,y,z,w,h,angle);
    if (texture_number == texture.background_028.ref_number) texture.background_028.draw(x,y,z,w,h,angle);
    if (texture_number == texture.background_029.ref_number) texture.background_029.draw(x,y,z,w,h,angle);
    if (texture_number == texture.background_030.ref_number) texture.background_030.draw(x,y,z,w,h,angle);
    if (texture_number == texture.background_031.ref_number) texture.background_031.draw(x,y,z,w,h,angle);

    if (texture_number == texture.level_00.ref_number) texture.level_00.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_01.ref_number) texture.level_01.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_02.ref_number) texture.level_02.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_03.ref_number) texture.level_03.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_04.ref_number) texture.level_04.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_05.ref_number) texture.level_05.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_06.ref_number) texture.level_06.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_07.ref_number) texture.level_07.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_08.ref_number) texture.level_08.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_09.ref_number) texture.level_09.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_10.ref_number) texture.level_10.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_11.ref_number) texture.level_11.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_12.ref_number) texture.level_12.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_13.ref_number) texture.level_13.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_14.ref_number) texture.level_14.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_15.ref_number) texture.level_15.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_16.ref_number) texture.level_16.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_17.ref_number) texture.level_17.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_18.ref_number) texture.level_18.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_19.ref_number) texture.level_19.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_20.ref_number) texture.level_20.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_21.ref_number) texture.level_21.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_22.ref_number) texture.level_22.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_23.ref_number) texture.level_23.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_24.ref_number) texture.level_24.draw(x,y,z,w,h,angle);

    if (texture_number == texture.level_highlighted_00.ref_number) texture.level_highlighted_00.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_highlighted_01.ref_number) texture.level_highlighted_01.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_highlighted_02.ref_number) texture.level_highlighted_02.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_highlighted_03.ref_number) texture.level_highlighted_03.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_highlighted_04.ref_number) texture.level_highlighted_04.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_highlighted_05.ref_number) texture.level_highlighted_05.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_highlighted_06.ref_number) texture.level_highlighted_06.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_highlighted_07.ref_number) texture.level_highlighted_07.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_highlighted_08.ref_number) texture.level_highlighted_08.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_highlighted_09.ref_number) texture.level_highlighted_09.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_highlighted_10.ref_number) texture.level_highlighted_10.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_highlighted_11.ref_number) texture.level_highlighted_11.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_highlighted_12.ref_number) texture.level_highlighted_12.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_highlighted_13.ref_number) texture.level_highlighted_13.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_highlighted_14.ref_number) texture.level_highlighted_14.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_highlighted_15.ref_number) texture.level_highlighted_15.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_highlighted_16.ref_number) texture.level_highlighted_16.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_highlighted_17.ref_number) texture.level_highlighted_17.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_highlighted_18.ref_number) texture.level_highlighted_18.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_highlighted_19.ref_number) texture.level_highlighted_19.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_highlighted_20.ref_number) texture.level_highlighted_20.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_highlighted_21.ref_number) texture.level_highlighted_21.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_highlighted_22.ref_number) texture.level_highlighted_22.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_highlighted_23.ref_number) texture.level_highlighted_23.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_highlighted_24.ref_number) texture.level_highlighted_24.draw(x,y,z,w,h,angle);

    if (texture_number == texture.level_preview_00.ref_number) texture.level_preview_00.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_preview_01.ref_number) texture.level_preview_01.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_preview_02.ref_number) texture.level_preview_02.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_preview_03.ref_number) texture.level_preview_03.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_preview_04.ref_number) texture.level_preview_04.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_preview_05.ref_number) texture.level_preview_05.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_preview_06.ref_number) texture.level_preview_06.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_preview_07.ref_number) texture.level_preview_07.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_preview_08.ref_number) texture.level_preview_08.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_preview_09.ref_number) texture.level_preview_09.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_preview_10.ref_number) texture.level_preview_10.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_preview_11.ref_number) texture.level_preview_11.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_preview_12.ref_number) texture.level_preview_12.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_preview_13.ref_number) texture.level_preview_13.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_preview_14.ref_number) texture.level_preview_14.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_preview_15.ref_number) texture.level_preview_15.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_preview_16.ref_number) texture.level_preview_16.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_preview_17.ref_number) texture.level_preview_17.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_preview_18.ref_number) texture.level_preview_18.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_preview_19.ref_number) texture.level_preview_19.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_preview_20.ref_number) texture.level_preview_20.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_preview_21.ref_number) texture.level_preview_21.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_preview_22.ref_number) texture.level_preview_22.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_preview_23.ref_number) texture.level_preview_23.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_preview_24.ref_number) texture.level_preview_24.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_preview_locked.ref_number) texture.level_preview_locked.draw(x,y,z,w,h,angle);

    if (texture_number == texture.explosion_00.ref_number) texture.explosion_00.draw(x,y,z,w,h,angle);
    if (texture_number == texture.explosion_01.ref_number) texture.explosion_01.draw(x,y,z,w,h,angle);
    if (texture_number == texture.explosion_02.ref_number) texture.explosion_02.draw(x,y,z,w,h,angle);
    if (texture_number == texture.explosion_03.ref_number) texture.explosion_03.draw(x,y,z,w,h,angle);

    if (texture_number == texture.health_bar.ref_number) texture.health_bar.draw(x,y,z,w,h,angle);

    if (texture_number == texture.weapon_000.ref_number) texture.weapon_000.draw(x,y,z,w,h,angle);
    if (texture_number == texture.weapon_001.ref_number) texture.weapon_001.draw(x,y,z,w,h,angle);
    if (texture_number == texture.weapon_002.ref_number) texture.weapon_002.draw(x,y,z,w,h,angle);
    if (texture_number == texture.weapon_003.ref_number) texture.weapon_003.draw(x,y,z,w,h,angle);
    if (texture_number == texture.weapon_004.ref_number) texture.weapon_004.draw(x,y,z,w,h,angle);
    if (texture_number == texture.weapon_005.ref_number) texture.weapon_005.draw(x,y,z,w,h,angle);

    if (texture_number == texture.shield_000.ref_number) texture.shield_000.draw(x,y,z,w,h,angle);
    if (texture_number == texture.shield_001.ref_number) texture.shield_001.draw(x,y,z,w,h,angle);
    if (texture_number == texture.shield_002.ref_number) texture.shield_002.draw(x,y,z,w,h,angle);
    if (texture_number == texture.shield_003.ref_number) texture.shield_003.draw(x,y,z,w,h,angle);
    if (texture_number == texture.shield_004.ref_number) texture.shield_004.draw(x,y,z,w,h,angle);

    if (texture_number == texture.projectile_000.ref_number) texture.projectile_000.draw(x,y,z,w,h,angle);
    if (texture_number == texture.projectile_001.ref_number) texture.projectile_001.draw(x,y,z,w,h,angle);
    if (texture_number == texture.projectile_002.ref_number) texture.projectile_002.draw(x,y,z,w,h,angle);
    if (texture_number == texture.projectile_003.ref_number) texture.projectile_003.draw(x,y,z,w,h,angle);
    if (texture_number == texture.projectile_004.ref_number) texture.projectile_004.draw(x,y,z,w,h,angle);
    if (texture_number == texture.projectile_005.ref_number) texture.projectile_005.draw(x,y,z,w,h,angle);
    if (texture_number == texture.projectile_006.ref_number) texture.projectile_006.draw(x,y,z,w,h,angle);
    if (texture_number == texture.projectile_007.ref_number) texture.projectile_007.draw(x,y,z,w,h,angle);
    if (texture_number == texture.projectile_008.ref_number) texture.projectile_008.draw(x,y,z,w,h,angle);
    if (texture_number == texture.projectile_009.ref_number) texture.projectile_009.draw(x,y,z,w,h,angle);
    if (texture_number == texture.projectile_010.ref_number) texture.projectile_010.draw(x,y,z,w,h,angle);
    if (texture_number == texture.projectile_011.ref_number) texture.projectile_011.draw(x,y,z,w,h,angle);
    if (texture_number == texture.projectile_012.ref_number) texture.projectile_012.draw(x,y,z,w,h,angle);
    if (texture_number == texture.projectile_013.ref_number) texture.projectile_013.draw(x,y,z,w,h,angle);
    if (texture_number == texture.projectile_014.ref_number) texture.projectile_014.draw(x,y,z,w,h,angle);
    if (texture_number == texture.projectile_015.ref_number) texture.projectile_015.draw(x,y,z,w,h,angle);
    if (texture_number == texture.projectile_016.ref_number) texture.projectile_016.draw(x,y,z,w,h,angle);
    if (texture_number == texture.projectile_017.ref_number) texture.projectile_017.draw(x,y,z,w,h,angle);
    if (texture_number == texture.projectile_018.ref_number) texture.projectile_018.draw(x,y,z,w,h,angle);
    if (texture_number == texture.projectile_019.ref_number) texture.projectile_019.draw(x,y,z,w,h,angle);
    if (texture_number == texture.projectile_020.ref_number) texture.projectile_020.draw(x,y,z,w,h,angle);
    if (texture_number == texture.projectile_021.ref_number) texture.projectile_021.draw(x,y,z,w,h,angle);
    if (texture_number == texture.projectile_022.ref_number) texture.projectile_022.draw(x,y,z,w,h,angle);
    if (texture_number == texture.projectile_023.ref_number) texture.projectile_023.draw(x,y,z,w,h,angle);
    if (texture_number == texture.projectile_024.ref_number) texture.projectile_024.draw(x,y,z,w,h,angle);
    if (texture_number == texture.projectile_025.ref_number) texture.projectile_025.draw(x,y,z,w,h,angle);
    if (texture_number == texture.projectile_026.ref_number) texture.projectile_026.draw(x,y,z,w,h,angle);
    if (texture_number == texture.projectile_027.ref_number) texture.projectile_027.draw(x,y,z,w,h,angle);
    if (texture_number == texture.projectile_028.ref_number) texture.projectile_028.draw(x,y,z,w,h,angle);
    if (texture_number == texture.projectile_029.ref_number) texture.projectile_029.draw(x,y,z,w,h,angle);
    if (texture_number == texture.projectile_030.ref_number) texture.projectile_030.draw(x,y,z,w,h,angle);
    if (texture_number == texture.projectile_031.ref_number) texture.projectile_031.draw(x,y,z,w,h,angle);

    if (texture_number == texture.ship_000.ref_number) texture.ship_000.draw(x,y,z,w,h,angle);
    if (texture_number == texture.ship_001.ref_number) texture.ship_001.draw(x,y,z,w,h,angle);
    if (texture_number == texture.ship_002.ref_number) texture.ship_002.draw(x,y,z,w,h,angle);
    if (texture_number == texture.ship_003.ref_number) texture.ship_003.draw(x,y,z,w,h,angle);
    if (texture_number == texture.ship_004.ref_number) texture.ship_004.draw(x,y,z,w,h,angle);
    if (texture_number == texture.ship_005.ref_number) texture.ship_005.draw(x,y,z,w,h,angle);
    if (texture_number == texture.ship_006.ref_number) texture.ship_006.draw(x,y,z,w,h,angle);
    if (texture_number == texture.ship_007.ref_number) texture.ship_007.draw(x,y,z,w,h,angle);
    if (texture_number == texture.ship_008.ref_number) texture.ship_008.draw(x,y,z,w,h,angle);
    if (texture_number == texture.ship_009.ref_number) texture.ship_009.draw(x,y,z,w,h,angle);
    if (texture_number == texture.ship_010.ref_number) texture.ship_010.draw(x,y,z,w,h,angle);
    if (texture_number == texture.ship_011.ref_number) texture.ship_011.draw(x,y,z,w,h,angle);
    if (texture_number == texture.ship_012.ref_number) texture.ship_012.draw(x,y,z,w,h,angle);
    if (texture_number == texture.ship_013.ref_number) texture.ship_013.draw(x,y,z,w,h,angle);
    if (texture_number == texture.ship_014.ref_number) texture.ship_014.draw(x,y,z,w,h,angle);
    if (texture_number == texture.ship_015.ref_number) texture.ship_015.draw(x,y,z,w,h,angle);
    if (texture_number == texture.ship_016.ref_number) texture.ship_016.draw(x,y,z,w,h,angle);
    if (texture_number == texture.ship_017.ref_number) texture.ship_017.draw(x,y,z,w,h,angle);
    if (texture_number == texture.ship_018.ref_number) texture.ship_018.draw(x,y,z,w,h,angle);
    if (texture_number == texture.ship_019.ref_number) texture.ship_019.draw(x,y,z,w,h,angle);
    if (texture_number == texture.ship_020.ref_number) texture.ship_020.draw(x,y,z,w,h,angle);
    if (texture_number == texture.ship_021.ref_number) texture.ship_021.draw(x,y,z,w,h,angle);
    if (texture_number == texture.ship_022.ref_number) texture.ship_022.draw(x,y,z,w,h,angle);
    if (texture_number == texture.ship_023.ref_number) texture.ship_023.draw(x,y,z,w,h,angle);
    if (texture_number == texture.ship_024.ref_number) texture.ship_024.draw(x,y,z,w,h,angle);
    if (texture_number == texture.ship_025.ref_number) texture.ship_025.draw(x,y,z,w,h,angle);

    if (texture_number == texture.thruster_000.ref_number) texture.thruster_000.draw(x,y,z,w,h,angle);
    if (texture_number == texture.thruster_001.ref_number) texture.thruster_001.draw(x,y,z,w,h,angle);
    if (texture_number == texture.thruster_002.ref_number) texture.thruster_002.draw(x,y,z,w,h,angle);

    if (texture_number == texture.selection_box.ref_number) texture.selection_box.draw(x,y,z,w,h,angle);
    if (texture_number == texture.none.ref_number) texture.none.draw(x,y,z,w,h,angle);
    if (texture_number == texture.locked.ref_number) texture.locked.draw(x,y,z,w,h,angle);
    if (texture_number == texture.weapon_bar.ref_number) texture.weapon_bar.draw(x,y,z,w,h,angle);
    if (texture_number == texture.shield_bar.ref_number) texture.shield_bar.draw(x,y,z,w,h,angle);
    if (texture_number == texture.thruster_bar.ref_number) texture.thruster_bar.draw(x,y,z,w,h,angle);
    if (texture_number == texture.game_paused.ref_number) texture.game_paused.draw(x,y,z,w,h,angle);
    if (texture_number == texture.game_saved.ref_number) texture.game_saved.draw(x,y,z,w,h,angle);
    if (texture_number == texture.game_loaded.ref_number) texture.game_loaded.draw(x,y,z,w,h,angle);

    if (texture_number == texture.health_powerup.ref_number) texture.health_powerup.draw(x,y,z,w,h,angle);
    if (texture_number == texture.shield_lvlup_powerup.ref_number) texture.shield_lvlup_powerup.draw(x,y,z,w,h,angle);
    if (texture_number == texture.shield_new_powerup.ref_number) texture.shield_new_powerup.draw(x,y,z,w,h,angle);
    if (texture_number == texture.thruster_lvlup_powerup.ref_number) texture.thruster_lvlup_powerup.draw(x,y,z,w,h,angle);
    if (texture_number == texture.thruster_new_powerup.ref_number) texture.thruster_new_powerup.draw(x,y,z,w,h,angle);
    if (texture_number == texture.weapon_lvlup_powerup.ref_number) texture.weapon_lvlup_powerup.draw(x,y,z,w,h,angle);
    if (texture_number == texture.weapon_new_powerup.ref_number) texture.weapon_new_powerup.draw(x,y,z,w,h,angle);

    if (texture_number == texture.grey_star.ref_number) texture.grey_star.draw(x,y,z,w,h,angle);
    if (texture_number == texture.bronze_star.ref_number) texture.bronze_star.draw(x,y,z,w,h,angle);
    if (texture_number == texture.silver_star.ref_number) texture.silver_star.draw(x,y,z,w,h,angle);
    if (texture_number == texture.gold_star.ref_number) texture.gold_star.draw(x,y,z,w,h,angle);
    if (texture_number == texture.kills_achievement.ref_number) texture.kills_achievement.draw(x,y,z,w,h,angle);
    if (texture_number == texture.score_achievement.ref_number) texture.score_achievement.draw(x,y,z,w,h,angle);

    if (texture_number == texture.actinium_shields.ref_number) texture.actinium_shields.draw(x,y,z,w,h,angle);
    if (texture_number == texture.blasters.ref_number) texture.blasters.draw(x,y,z,w,h,angle);
    if (texture_number == texture.burst_lasers.ref_number) texture.burst_lasers.draw(x,y,z,w,h,angle);
    if (texture_number == texture.chain_guns.ref_number) texture.chain_guns.draw(x,y,z,w,h,angle);
    if (texture_number == texture.convolution_thrusters.ref_number) texture.convolution_thrusters.draw(x,y,z,w,h,angle);
    if (texture_number == texture.health.ref_number) texture.health.draw(x,y,z,w,h,angle);
    if (texture_number == texture.ion_cannons.ref_number) texture.ion_cannons.draw(x,y,z,w,h,angle);
    if (texture_number == texture.iridium_shileds.ref_number) texture.iridium_shileds.draw(x,y,z,w,h,angle);
    if (texture_number == texture.maelstrom_thrusters.ref_number) texture.maelstrom_thrusters.draw(x,y,z,w,h,angle);
    if (texture_number == texture.plasma_rockets.ref_number) texture.plasma_rockets.draw(x,y,z,w,h,angle);
    if (texture_number == texture.rail_turrets.ref_number) texture.rail_turrets.draw(x,y,z,w,h,angle);
    if (texture_number == texture.rubidium_shields.ref_number) texture.rubidium_shields.draw(x,y,z,w,h,angle);
    if (texture_number == texture.seismic_thrusters.ref_number) texture.seismic_thrusters.draw(x,y,z,w,h,angle);
    if (texture_number == texture.shield_level_up.ref_number) texture.shield_level_up.draw(x,y,z,w,h,angle);
    if (texture_number == texture.tantalum_shields.ref_number) texture.tantalum_shields.draw(x,y,z,w,h,angle);
    if (texture_number == texture.terbium_shields.ref_number) texture.terbium_shields.draw(x,y,z,w,h,angle);
    if (texture_number == texture.thrusters_level_up.ref_number) texture.thrusters_level_up.draw(x,y,z,w,h,angle);
    if (texture_number == texture.vortex_thrusters.ref_number) texture.vortex_thrusters.draw(x,y,z,w,h,angle);
    if (texture_number == texture.weapon_level_up.ref_number) texture.weapon_level_up.draw(x,y,z,w,h,angle);

    if (texture_number == texture.game_over.ref_number) texture.game_over.draw(x,y,z,w,h,angle);
    if (texture_number == texture.logo_red.ref_number) texture.logo_red.draw(x,y,z,w,h,angle);
    if (texture_number == texture.explosion_001.ref_number) texture.explosion_001.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_completed.ref_number) texture.level_completed.draw(x,y,z,w,h,angle);
    if (texture_number == texture.new_level_unlocked.ref_number) texture.new_level_unlocked.draw(x,y,z,w,h,angle);
    if (texture_number == texture.thruster_003.ref_number) texture.thruster_003.draw(x,y,z,w,h,angle);
    if (texture_number == texture.coin_powerup.ref_number) texture.coin_powerup.draw(x,y,z,w,h,angle);
    if (texture_number == texture.wexp_powerup.ref_number) texture.wexp_powerup.draw(x,y,z,w,h,angle);
    if (texture_number == texture.credits_00.ref_number) texture.credits_00.draw(x,y,z,w,h,angle);
    if (texture_number == texture.level_progress_bar.ref_number) texture.level_progress_bar.draw(x,y,z,w,h,angle);
    if (texture_number == texture.bomb_powerup.ref_number) texture.bomb_powerup.draw(x,y,z,w,h,angle);
    if (texture_number == texture.sideship_00.ref_number) texture.sideship_00.draw(x,y,z,w,h,angle);
    if (texture_number == texture.sideship_01.ref_number) texture.sideship_01.draw(x,y,z,w,h,angle);
    if (texture_number == texture.sideship_02.ref_number) texture.sideship_02.draw(x,y,z,w,h,angle);
    if (texture_number == texture.sideship_03.ref_number) texture.sideship_03.draw(x,y,z,w,h,angle);
    if (texture_number == texture.powerup_sideship_00.ref_number) texture.powerup_sideship_00.draw(x,y,z,w,h,angle);
    if (texture_number == texture.powerup_sideship_01.ref_number) texture.powerup_sideship_01.draw(x,y,z,w,h,angle);
    if (texture_number == texture.powerup_sideship_02.ref_number) texture.powerup_sideship_02.draw(x,y,z,w,h,angle);
    if (texture_number == texture.powerup_sideship_03.ref_number) texture.powerup_sideship_03.draw(x,y,z,w,h,angle);
    if (texture_number == texture.touchscreen_arrow.ref_number) texture.touchscreen_arrow.draw(x,y,z,w,h,angle);
    if (texture_number == texture.touchscreen_button.ref_number) texture.touchscreen_button.draw(x,y,z,w,h,angle);

    if (texture_number == texture.menu_background_002.ref_number) texture.menu_background_002.draw(x,y,z,w,h,angle);
    if (texture_number == texture.menu_background_003.ref_number) texture.menu_background_003.draw(x,y,z,w,h,angle);
    if (texture_number == texture.red_button.ref_number) texture.red_button.draw(x,y,z,w,h,angle);
    if (texture_number == texture.red_button_highlighted.ref_number) texture.red_button_highlighted.draw(x,y,z,w,h,angle);
    if (texture_number == texture.green_button.ref_number) texture.green_button.draw(x,y,z,w,h,angle);
    if (texture_number == texture.green_button_highlighted.ref_number) texture.green_button_highlighted.draw(x,y,z,w,h,angle);
    if (texture_number == texture.blue_button.ref_number) texture.blue_button.draw(x,y,z,w,h,angle);
    if (texture_number == texture.blue_button_highlighted.ref_number) texture.blue_button_highlighted.draw(x,y,z,w,h,angle);
    if (texture_number == texture.arrow_button_normal.ref_number) texture.arrow_button_normal.draw(x,y,z,w,h,angle);
    if (texture_number == texture.arrow_button_highlighted.ref_number) texture.arrow_button_highlighted.draw(x,y,z,w,h,angle);
    if (texture_number == texture.arrow_button_disabled.ref_number) texture.arrow_button_disabled.draw(x,y,z,w,h,angle);
    if (texture_number == texture.slider_normal.ref_number) texture.slider_normal.draw(x,y,z,w,h,angle);
    if (texture_number == texture.slider_highlighted.ref_number) texture.slider_highlighted.draw(x,y,z,w,h,angle);
    if (texture_number == texture.resolution_icon.ref_number) texture.resolution_icon.draw(x,y,z,w,h,angle);


    return(true);
};




