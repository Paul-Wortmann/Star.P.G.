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
    texture.res_1024x768.load("data/textures/menu/1024x768.png",texture_count);texture_count++;
    texture.res_1024x768_highlighted.load("data/textures/menu/1024x768_highlighted.png",texture_count);texture_count++;
    texture.res_1280x1024.load("data/textures/menu/1280x1024.png",texture_count);texture_count++;
    texture.res_1280x1024_highlighted.load("data/textures/menu/1280x1024_highlighted.png",texture_count);texture_count++;
    texture.res_1366x768.load("data/textures/menu/1366x768.png",texture_count);texture_count++;
    texture.res_1366x768_highlighted.load("data/textures/menu/1366x768_highlighted.png",texture_count);texture_count++;
    texture.res_1440x900.load("data/textures/menu/1440x900.png",texture_count);texture_count++;
    texture.res_1440x900_highlighted.load("data/textures/menu/1440x900_highlighted.png",texture_count);texture_count++;
    texture.res_1680x1050.load("data/textures/menu/1680x1050.png",texture_count);texture_count++;
    texture.res_1680x1050_highlighted.load("data/textures/menu/1680x1050_highlighted.png",texture_count);texture_count++;
    texture.res_1920x1080.load("data/textures/menu/1920x1080.png",texture_count);texture_count++;
    texture.res_1920x1080_highlighted.load("data/textures/menu/1920x1080_highlighted.png",texture_count);texture_count++;
    texture.res_640x480.load("data/textures/menu/640x480.png",texture_count);texture_count++;
    texture.res_640x480_highlighted.load("data/textures/menu/640x480_highlighted.png",texture_count);texture_count++;
    texture.res_800x600.load("data/textures/menu/800x600.png",texture_count);texture_count++;
    texture.res_800x600_highlighted.load("data/textures/menu/800x600_highlighted.png",texture_count);texture_count++;
    texture.bar_001.load("data/textures/menu/bar_001.png",texture_count);texture_count++;
    texture.bar_001_highlighted.load("data/textures/menu/bar_001_highlighted.png",texture_count);texture_count++;
    texture.bar_002.load("data/textures/menu/bar_002.png",texture_count);texture_count++;
    texture.bar_002_highlighted.load("data/textures/menu/bar_002_highlighted.png",texture_count);texture_count++;
    texture.customize_starship.load("data/textures/menu/customize_starship.png",texture_count);texture_count++;
    texture.customize_starship_highlighted.load("data/textures/menu/customize_starship_highlighted.png",texture_count);texture_count++;
    texture.front_weapon.load("data/textures/menu/front_weapon.png",texture_count);texture_count++;
    texture.front_weapon_highlighted.load("data/textures/menu/front_weapon_highlighted.png",texture_count);texture_count++;
    texture.fullscreen.load("data/textures/menu/fullscreen.png",texture_count);texture_count++;
    texture.fullscreen_highlighted.load("data/textures/menu/fullscreen_highlighted.png",texture_count);texture_count++;
    texture.game_menu.load("data/textures/menu/game_menu.png",texture_count);texture_count++;
    texture.game_menu_highlighted.load("data/textures/menu/game_menu_highlighted.png",texture_count);texture_count++;
    texture.load_game.load("data/textures/menu/load_game.png",texture_count);texture_count++;
    texture.load_game_highlighted.load("data/textures/menu/load_game_highlighted.png",texture_count);texture_count++;
    texture.logo.load("data/textures/menu/logo.png",texture_count);texture_count++;
    texture.main_menu.load("data/textures/menu/main_menu.png",texture_count);texture_count++;
    texture.main_menu_highlighted.load("data/textures/menu/main_menu_highlighted.png",texture_count);texture_count++;
    texture.music_volume.load("data/textures/menu/music_volume.png",texture_count);texture_count++;
    texture.music_volume_highlighted.load("data/textures/menu/music_volume_highlighted.png",texture_count);texture_count++;
    texture.new_game.load("data/textures/menu/new_game.png",texture_count);texture_count++;
    texture.new_game_highlighted.load("data/textures/menu/new_game_highlighted.png",texture_count);texture_count++;
    texture.off.load("data/textures/menu/off.png",texture_count);texture_count++;
    texture.off_highlighted.load("data/textures/menu/off_highlighted.png",texture_count);texture_count++;
    texture.on.load("data/textures/menu/on.png",texture_count);texture_count++;
    texture.on_highlighted.load("data/textures/menu/on_highlighted.png",texture_count);texture_count++;
    texture.options.load("data/textures/menu/options.png",texture_count);texture_count++;
    texture.options_highlighted.load("data/textures/menu/options_highlighted.png",texture_count);texture_count++;
    texture.options_menu.load("data/textures/menu/options_menu.png",texture_count);texture_count++;
    texture.options_menu_highlighted.load("data/textures/menu/options_menu_highlighted.png",texture_count);texture_count++;
    texture.quit_game.load("data/textures/menu/quit_game.png",texture_count);texture_count++;
    texture.quit_game_highlighted.load("data/textures/menu/quit_game_highlighted.png",texture_count);texture_count++;
    texture.resolution.load("data/textures/menu/resolution.png",texture_count);texture_count++;
    texture.resolution_highlighted.load("data/textures/menu/resolution_highlighted.png",texture_count);texture_count++;
    texture.resume_game.load("data/textures/menu/resume_game.png",texture_count);texture_count++;
    texture.resume_game_highlighted.load("data/textures/menu/resume_game_highlighted.png",texture_count);texture_count++;
    texture.save_game.load("data/textures/menu/save_game.png",texture_count);texture_count++;
    texture.save_game_highlighted.load("data/textures/menu/save_game_highlighted.png",texture_count);texture_count++;
    texture.shield.load("data/textures/menu/shield.png",texture_count);texture_count++;
    texture.shield_highlighted.load("data/textures/menu/shield_highlighted.png",texture_count);texture_count++;
    texture.side_weapon.load("data/textures/menu/side_weapon.png",texture_count);texture_count++;
    texture.side_weapon_highlighted.load("data/textures/menu/side_weapon_highlighted.png",texture_count);texture_count++;
    texture.sound_volume.load("data/textures/menu/sound_volume.png",texture_count);texture_count++;
    texture.sound_volume_highlighted.load("data/textures/menu/sound_volume_highlighted.png",texture_count);texture_count++;
    texture.star_map.load("data/textures/menu/star_map.png",texture_count);texture_count++;
    texture.star_map_highlighted.load("data/textures/menu/star_map_highlighted.png",texture_count);texture_count++;
    texture.thrusters.load("data/textures/menu/thrusters.png",texture_count);texture_count++;
    texture.thrusters_highlighted.load("data/textures/menu/thrusters_highlighted.png",texture_count);texture_count++;

    texture.menu_background_000.load("data/textures/backgrounds/menu_background_000.png",texture_count);texture_count++;
    texture.menu_background_001.load("data/textures/backgrounds/menu_background_001.png",texture_count);texture_count++;
    texture.background_000.load("data/textures/backgrounds/background_000.png",texture_count);texture_count++;
    texture.background_001.load("data/textures/backgrounds/background_001.png",texture_count);texture_count++;
    texture.background_002.load("data/textures/backgrounds/background_002.png",texture_count);texture_count++;
    texture.background_003.load("data/textures/backgrounds/background_003.png",texture_count);texture_count++;
    texture.background_004.load("data/textures/backgrounds/background_004.png",texture_count);texture_count++;
    texture.background_005.load("data/textures/backgrounds/background_005.png",texture_count);texture_count++;
    texture.background_006.load("data/textures/backgrounds/background_006.png",texture_count);texture_count++;
    texture.background_007.load("data/textures/backgrounds/background_007.png",texture_count);texture_count++;
    texture.background_008.load("data/textures/backgrounds/background_008.png",texture_count);texture_count++;
    texture.background_009.load("data/textures/backgrounds/background_009.png",texture_count);texture_count++;
    texture.background_010.load("data/textures/backgrounds/background_010.png",texture_count);texture_count++;
    texture.background_011.load("data/textures/backgrounds/background_011.png",texture_count);texture_count++;
    texture.background_012.load("data/textures/backgrounds/background_012.png",texture_count);texture_count++;
    texture.background_013.load("data/textures/backgrounds/background_013.png",texture_count);texture_count++;
    texture.background_014.load("data/textures/backgrounds/background_014.png",texture_count);texture_count++;
    texture.background_015.load("data/textures/backgrounds/background_015.png",texture_count);texture_count++;
    texture.background_016.load("data/textures/backgrounds/background_016.png",texture_count);texture_count++;
    texture.background_017.load("data/textures/backgrounds/background_017.png",texture_count);texture_count++;
    texture.background_018.load("data/textures/backgrounds/background_018.png",texture_count);texture_count++;
    texture.background_019.load("data/textures/backgrounds/background_019.png",texture_count);texture_count++;
    texture.background_020.load("data/textures/backgrounds/background_020.png",texture_count);texture_count++;
    texture.background_021.load("data/textures/backgrounds/background_021.png",texture_count);texture_count++;
    texture.background_022.load("data/textures/backgrounds/background_022.png",texture_count);texture_count++;
    texture.background_023.load("data/textures/backgrounds/background_023.png",texture_count);texture_count++;
    texture.background_024.load("data/textures/backgrounds/background_024.png",texture_count);texture_count++;
    texture.background_025.load("data/textures/backgrounds/background_025.png",texture_count);texture_count++;
    texture.background_026.load("data/textures/backgrounds/background_026.png",texture_count);texture_count++;
    texture.background_027.load("data/textures/backgrounds/background_027.png",texture_count);texture_count++;
    texture.background_028.load("data/textures/backgrounds/background_028.png",texture_count);texture_count++;
    texture.background_029.load("data/textures/backgrounds/background_029.png",texture_count);texture_count++;
    texture.background_030.load("data/textures/backgrounds/background_030.png",texture_count);texture_count++;
    texture.background_031.load("data/textures/backgrounds/background_031.png",texture_count);texture_count++;

    texture.level_00.load("data/textures/levels/level_00.png",texture_count);texture_count++;
    texture.level_01.load("data/textures/levels/level_01.png",texture_count);texture_count++;
    texture.level_02.load("data/textures/levels/level_02.png",texture_count);texture_count++;
    texture.level_03.load("data/textures/levels/level_03.png",texture_count);texture_count++;
    texture.level_04.load("data/textures/levels/level_04.png",texture_count);texture_count++;
    texture.level_05.load("data/textures/levels/level_05.png",texture_count);texture_count++;
    texture.level_06.load("data/textures/levels/level_06.png",texture_count);texture_count++;
    texture.level_07.load("data/textures/levels/level_07.png",texture_count);texture_count++;
    texture.level_08.load("data/textures/levels/level_08.png",texture_count);texture_count++;
    texture.level_09.load("data/textures/levels/level_09.png",texture_count);texture_count++;
    texture.level_10.load("data/textures/levels/level_10.png",texture_count);texture_count++;
    texture.level_11.load("data/textures/levels/level_11.png",texture_count);texture_count++;
    texture.level_12.load("data/textures/levels/level_12.png",texture_count);texture_count++;
    texture.level_13.load("data/textures/levels/level_13.png",texture_count);texture_count++;
    texture.level_14.load("data/textures/levels/level_14.png",texture_count);texture_count++;
    texture.level_15.load("data/textures/levels/level_15.png",texture_count);texture_count++;
    texture.level_16.load("data/textures/levels/level_16.png",texture_count);texture_count++;
    texture.level_17.load("data/textures/levels/level_17.png",texture_count);texture_count++;
    texture.level_18.load("data/textures/levels/level_18.png",texture_count);texture_count++;
    texture.level_19.load("data/textures/levels/level_19.png",texture_count);texture_count++;
    texture.level_20.load("data/textures/levels/level_20.png",texture_count);texture_count++;
    texture.level_21.load("data/textures/levels/level_21.png",texture_count);texture_count++;
    texture.level_22.load("data/textures/levels/level_22.png",texture_count);texture_count++;
    texture.level_23.load("data/textures/levels/level_23.png",texture_count);texture_count++;
    texture.level_24.load("data/textures/levels/level_24.png",texture_count);texture_count++;

    texture.level_highlighted_00.load("data/textures/levels/level_highlighted_00.png",texture_count);texture_count++;
    texture.level_highlighted_01.load("data/textures/levels/level_highlighted_01.png",texture_count);texture_count++;
    texture.level_highlighted_02.load("data/textures/levels/level_highlighted_02.png",texture_count);texture_count++;
    texture.level_highlighted_03.load("data/textures/levels/level_highlighted_03.png",texture_count);texture_count++;
    texture.level_highlighted_04.load("data/textures/levels/level_highlighted_04.png",texture_count);texture_count++;
    texture.level_highlighted_05.load("data/textures/levels/level_highlighted_05.png",texture_count);texture_count++;
    texture.level_highlighted_06.load("data/textures/levels/level_highlighted_06.png",texture_count);texture_count++;
    texture.level_highlighted_07.load("data/textures/levels/level_highlighted_07.png",texture_count);texture_count++;
    texture.level_highlighted_08.load("data/textures/levels/level_highlighted_08.png",texture_count);texture_count++;
    texture.level_highlighted_09.load("data/textures/levels/level_highlighted_09.png",texture_count);texture_count++;
    texture.level_highlighted_10.load("data/textures/levels/level_highlighted_10.png",texture_count);texture_count++;
    texture.level_highlighted_11.load("data/textures/levels/level_highlighted_11.png",texture_count);texture_count++;
    texture.level_highlighted_12.load("data/textures/levels/level_highlighted_12.png",texture_count);texture_count++;
    texture.level_highlighted_13.load("data/textures/levels/level_highlighted_13.png",texture_count);texture_count++;
    texture.level_highlighted_14.load("data/textures/levels/level_highlighted_14.png",texture_count);texture_count++;
    texture.level_highlighted_15.load("data/textures/levels/level_highlighted_15.png",texture_count);texture_count++;
    texture.level_highlighted_16.load("data/textures/levels/level_highlighted_16.png",texture_count);texture_count++;
    texture.level_highlighted_17.load("data/textures/levels/level_highlighted_17.png",texture_count);texture_count++;
    texture.level_highlighted_18.load("data/textures/levels/level_highlighted_18.png",texture_count);texture_count++;
    texture.level_highlighted_19.load("data/textures/levels/level_highlighted_19.png",texture_count);texture_count++;
    texture.level_highlighted_20.load("data/textures/levels/level_highlighted_20.png",texture_count);texture_count++;
    texture.level_highlighted_21.load("data/textures/levels/level_highlighted_21.png",texture_count);texture_count++;
    texture.level_highlighted_22.load("data/textures/levels/level_highlighted_22.png",texture_count);texture_count++;
    texture.level_highlighted_23.load("data/textures/levels/level_highlighted_23.png",texture_count);texture_count++;
    texture.level_highlighted_24.load("data/textures/levels/level_highlighted_24.png",texture_count);texture_count++;

    texture.level_preview_00.load("data/textures/levels/level_preview_00.png",texture_count);texture_count++;
    texture.level_preview_01.load("data/textures/levels/level_preview_01.png",texture_count);texture_count++;
    texture.level_preview_02.load("data/textures/levels/level_preview_02.png",texture_count);texture_count++;
    texture.level_preview_03.load("data/textures/levels/level_preview_03.png",texture_count);texture_count++;
    texture.level_preview_04.load("data/textures/levels/level_preview_04.png",texture_count);texture_count++;
    texture.level_preview_05.load("data/textures/levels/level_preview_05.png",texture_count);texture_count++;
    texture.level_preview_06.load("data/textures/levels/level_preview_06.png",texture_count);texture_count++;
    texture.level_preview_07.load("data/textures/levels/level_preview_07.png",texture_count);texture_count++;
    texture.level_preview_08.load("data/textures/levels/level_preview_08.png",texture_count);texture_count++;
    texture.level_preview_09.load("data/textures/levels/level_preview_09.png",texture_count);texture_count++;
    texture.level_preview_10.load("data/textures/levels/level_preview_10.png",texture_count);texture_count++;
    texture.level_preview_11.load("data/textures/levels/level_preview_11.png",texture_count);texture_count++;
    texture.level_preview_12.load("data/textures/levels/level_preview_12.png",texture_count);texture_count++;
    texture.level_preview_13.load("data/textures/levels/level_preview_13.png",texture_count);texture_count++;
    texture.level_preview_14.load("data/textures/levels/level_preview_14.png",texture_count);texture_count++;
    texture.level_preview_15.load("data/textures/levels/level_preview_15.png",texture_count);texture_count++;
    texture.level_preview_16.load("data/textures/levels/level_preview_16.png",texture_count);texture_count++;
    texture.level_preview_17.load("data/textures/levels/level_preview_17.png",texture_count);texture_count++;
    texture.level_preview_18.load("data/textures/levels/level_preview_18.png",texture_count);texture_count++;
    texture.level_preview_19.load("data/textures/levels/level_preview_19.png",texture_count);texture_count++;
    texture.level_preview_20.load("data/textures/levels/level_preview_20.png",texture_count);texture_count++;
    texture.level_preview_21.load("data/textures/levels/level_preview_21.png",texture_count);texture_count++;
    texture.level_preview_22.load("data/textures/levels/level_preview_22.png",texture_count);texture_count++;
    texture.level_preview_23.load("data/textures/levels/level_preview_23.png",texture_count);texture_count++;
    texture.level_preview_24.load("data/textures/levels/level_preview_24.png",texture_count);texture_count++;
    texture.level_preview_locked.load("data/textures/levels/level_preview_locked.png",texture_count);texture_count++;

    texture.save_game_00.load("data/textures/menu/save_game_00.png",texture_count);texture_count++;
    texture.save_game_01.load("data/textures/menu/save_game_01.png",texture_count);texture_count++;
    texture.save_game_02.load("data/textures/menu/save_game_02.png",texture_count);texture_count++;
    texture.save_game_03.load("data/textures/menu/save_game_03.png",texture_count);texture_count++;
    texture.save_game_04.load("data/textures/menu/save_game_04.png",texture_count);texture_count++;
    texture.save_game_05.load("data/textures/menu/save_game_05.png",texture_count);texture_count++;
    texture.save_game_highlighted_00.load("data/textures/menu/save_game_highlighted_00.png",texture_count);texture_count++;
    texture.save_game_highlighted_01.load("data/textures/menu/save_game_highlighted_01.png",texture_count);texture_count++;
    texture.save_game_highlighted_02.load("data/textures/menu/save_game_highlighted_02.png",texture_count);texture_count++;
    texture.save_game_highlighted_03.load("data/textures/menu/save_game_highlighted_03.png",texture_count);texture_count++;
    texture.save_game_highlighted_04.load("data/textures/menu/save_game_highlighted_04.png",texture_count);texture_count++;
    texture.save_game_highlighted_05.load("data/textures/menu/save_game_highlighted_05.png",texture_count);texture_count++;

    texture.explosion_00.load("data/textures/explosions/explosion_00/explosion_00.png",texture_count);texture_count++;
    texture.explosion_01.load("data/textures/explosions/explosion_00/explosion_01.png",texture_count);texture_count++;
    texture.explosion_02.load("data/textures/explosions/explosion_00/explosion_02.png",texture_count);texture_count++;
    texture.explosion_03.load("data/textures/explosions/explosion_00/explosion_03.png",texture_count);texture_count++;
    texture.explosion_04.load("data/textures/explosions/explosion_00/explosion_04.png",texture_count);texture_count++;
    texture.explosion_05.load("data/textures/explosions/explosion_00/explosion_05.png",texture_count);texture_count++;
    texture.explosion_06.load("data/textures/explosions/explosion_00/explosion_06.png",texture_count);texture_count++;
    texture.explosion_07.load("data/textures/explosions/explosion_00/explosion_07.png",texture_count);texture_count++;
    texture.explosion_08.load("data/textures/explosions/explosion_00/explosion_08.png",texture_count);texture_count++;
    texture.explosion_09.load("data/textures/explosions/explosion_00/explosion_09.png",texture_count);texture_count++;
    texture.explosion_10.load("data/textures/explosions/explosion_00/explosion_10.png",texture_count);texture_count++;
    texture.explosion_11.load("data/textures/explosions/explosion_00/explosion_11.png",texture_count);texture_count++;
    texture.explosion_12.load("data/textures/explosions/explosion_00/explosion_12.png",texture_count);texture_count++;
    texture.explosion_13.load("data/textures/explosions/explosion_00/explosion_13.png",texture_count);texture_count++;
    texture.explosion_14.load("data/textures/explosions/explosion_00/explosion_14.png",texture_count);texture_count++;
    texture.explosion_15.load("data/textures/explosions/explosion_00/explosion_15.png",texture_count);texture_count++;
    texture.explosion_16.load("data/textures/explosions/explosion_00/explosion_16.png",texture_count);texture_count++;
    texture.explosion_17.load("data/textures/explosions/explosion_00/explosion_17.png",texture_count);texture_count++;
    texture.explosion_18.load("data/textures/explosions/explosion_00/explosion_18.png",texture_count);texture_count++;
    texture.explosion_19.load("data/textures/explosions/explosion_00/explosion_19.png",texture_count);texture_count++;
    texture.explosion_20.load("data/textures/explosions/explosion_00/explosion_20.png",texture_count);texture_count++;
    texture.explosion_21.load("data/textures/explosions/explosion_00/explosion_21.png",texture_count);texture_count++;
    texture.explosion_22.load("data/textures/explosions/explosion_00/explosion_22.png",texture_count);texture_count++;
    texture.explosion_23.load("data/textures/explosions/explosion_00/explosion_23.png",texture_count);texture_count++;
    texture.explosion_24.load("data/textures/explosions/explosion_00/explosion_24.png",texture_count);texture_count++;

    texture.health_bar.load("data/textures/misc/health_bar.png",texture_count);texture_count++;

    texture.weapon_000.load("data/textures/weapons/weapon_000.png",texture_count);texture_count++;
    texture.weapon_001.load("data/textures/weapons/weapon_001.png",texture_count);texture_count++;
    texture.weapon_002.load("data/textures/weapons/weapon_002.png",texture_count);texture_count++;
    texture.weapon_003.load("data/textures/weapons/weapon_003.png",texture_count);texture_count++;
    texture.weapon_004.load("data/textures/weapons/weapon_004.png",texture_count);texture_count++;
    texture.weapon_005.load("data/textures/weapons/weapon_005.png",texture_count);texture_count++;

    texture.shield_000.load("data/textures/shields/shield_000.png",texture_count);texture_count++;
    texture.shield_001.load("data/textures/shields/shield_001.png",texture_count);texture_count++;
    texture.shield_002.load("data/textures/shields/shield_002.png",texture_count);texture_count++;
    texture.shield_003.load("data/textures/shields/shield_003.png",texture_count);texture_count++;
    texture.shield_004.load("data/textures/shields/shield_004.png",texture_count);texture_count++;

    texture.projectile_000.load("data/textures/projectiles/projectile_000.png",texture_count);texture_count++;
    texture.projectile_001.load("data/textures/projectiles/projectile_001.png",texture_count);texture_count++;
    texture.projectile_002.load("data/textures/projectiles/projectile_002.png",texture_count);texture_count++;
    texture.projectile_003.load("data/textures/projectiles/projectile_003.png",texture_count);texture_count++;
    texture.projectile_004.load("data/textures/projectiles/projectile_004.png",texture_count);texture_count++;
    texture.projectile_005.load("data/textures/projectiles/projectile_005.png",texture_count);texture_count++;
    texture.projectile_006.load("data/textures/projectiles/projectile_006.png",texture_count);texture_count++;
    texture.projectile_007.load("data/textures/projectiles/projectile_007.png",texture_count);texture_count++;
    texture.projectile_008.load("data/textures/projectiles/projectile_008.png",texture_count);texture_count++;
    texture.projectile_009.load("data/textures/projectiles/projectile_009.png",texture_count);texture_count++;
    texture.projectile_010.load("data/textures/projectiles/projectile_010.png",texture_count);texture_count++;
    texture.projectile_011.load("data/textures/projectiles/projectile_011.png",texture_count);texture_count++;
    texture.projectile_012.load("data/textures/projectiles/projectile_012.png",texture_count);texture_count++;
    texture.projectile_013.load("data/textures/projectiles/projectile_013.png",texture_count);texture_count++;
    texture.projectile_014.load("data/textures/projectiles/projectile_014.png",texture_count);texture_count++;
    texture.projectile_015.load("data/textures/projectiles/projectile_015.png",texture_count);texture_count++;
    texture.projectile_016.load("data/textures/projectiles/projectile_016.png",texture_count);texture_count++;
    texture.projectile_017.load("data/textures/projectiles/projectile_017.png",texture_count);texture_count++;
    texture.projectile_018.load("data/textures/projectiles/projectile_018.png",texture_count);texture_count++;
    texture.projectile_019.load("data/textures/projectiles/projectile_019.png",texture_count);texture_count++;
    texture.projectile_020.load("data/textures/projectiles/projectile_020.png",texture_count);texture_count++;
    texture.projectile_021.load("data/textures/projectiles/projectile_021.png",texture_count);texture_count++;
    texture.projectile_022.load("data/textures/projectiles/projectile_022.png",texture_count);texture_count++;
    texture.projectile_023.load("data/textures/projectiles/projectile_023.png",texture_count);texture_count++;
    texture.projectile_024.load("data/textures/projectiles/projectile_024.png",texture_count);texture_count++;
    texture.projectile_025.load("data/textures/projectiles/projectile_025.png",texture_count);texture_count++;
    texture.projectile_026.load("data/textures/projectiles/projectile_026.png",texture_count);texture_count++;
    texture.projectile_027.load("data/textures/projectiles/projectile_027.png",texture_count);texture_count++;
    texture.projectile_028.load("data/textures/projectiles/projectile_028.png",texture_count);texture_count++;
    texture.projectile_029.load("data/textures/projectiles/projectile_029.png",texture_count);texture_count++;
    texture.projectile_030.load("data/textures/projectiles/projectile_030.png",texture_count);texture_count++;

    texture.ship_000.load("data/textures/ships/ship_000.png",texture_count);texture_count++;
    texture.ship_001.load("data/textures/ships/ship_001.png",texture_count);texture_count++;
    texture.ship_002.load("data/textures/ships/ship_002.png",texture_count);texture_count++;
    texture.ship_003.load("data/textures/ships/ship_003.png",texture_count);texture_count++;
    texture.ship_004.load("data/textures/ships/ship_004.png",texture_count);texture_count++;
    texture.ship_005.load("data/textures/ships/ship_005.png",texture_count);texture_count++;
    texture.ship_006.load("data/textures/ships/ship_006.png",texture_count);texture_count++;
    texture.ship_007.load("data/textures/ships/ship_007.png",texture_count);texture_count++;
    texture.ship_008.load("data/textures/ships/ship_008.png",texture_count);texture_count++;
    texture.ship_009.load("data/textures/ships/ship_009.png",texture_count);texture_count++;
    texture.ship_010.load("data/textures/ships/ship_010.png",texture_count);texture_count++;
    texture.ship_011.load("data/textures/ships/ship_011.png",texture_count);texture_count++;
    texture.ship_012.load("data/textures/ships/ship_012.png",texture_count);texture_count++;
    texture.ship_013.load("data/textures/ships/ship_013.png",texture_count);texture_count++;
    texture.ship_014.load("data/textures/ships/ship_014.png",texture_count);texture_count++;
    texture.ship_015.load("data/textures/ships/ship_015.png",texture_count);texture_count++;
    texture.ship_016.load("data/textures/ships/ship_016.png",texture_count);texture_count++;
    texture.ship_017.load("data/textures/ships/ship_017.png",texture_count);texture_count++;
    texture.ship_018.load("data/textures/ships/ship_018.png",texture_count);texture_count++;
    texture.ship_019.load("data/textures/ships/ship_019.png",texture_count);texture_count++;
    texture.ship_020.load("data/textures/ships/ship_020.png",texture_count);texture_count++;
    texture.ship_021.load("data/textures/ships/ship_021.png",texture_count);texture_count++;
    texture.ship_022.load("data/textures/ships/ship_022.png",texture_count);texture_count++;
    texture.ship_023.load("data/textures/ships/ship_023.png",texture_count);texture_count++;
    texture.ship_024.load("data/textures/ships/ship_024.png",texture_count);texture_count++;
    texture.ship_025.load("data/textures/ships/ship_025.png",texture_count);texture_count++;

    texture.thruster_000.load("data/textures/thrusters/thruster_000.png",texture_count);texture_count++;
    texture.thruster_001.load("data/textures/thrusters/thruster_001.png",texture_count);texture_count++;
    texture.thruster_002.load("data/textures/thrusters/thruster_002.png",texture_count);texture_count++;

    texture.selection_box.load("data/textures/misc/selection_box.png",texture_count);texture_count++;
    texture.none.load("data/textures/misc/none.png",texture_count);texture_count++;
    texture.locked.load("data/textures/misc/locked.png",texture_count);texture_count++;
    texture.weapon_bar.load("data/textures/misc/weapon_bar.png",texture_count);texture_count++;
    texture.shield_bar.load("data/textures/misc/shield_bar.png",texture_count);texture_count++;
    texture.thruster_bar.load("data/textures/misc/thruster_bar.png",texture_count);texture_count++;
    texture.game_paused.load("data/textures/misc/game_paused.png",texture_count);texture_count++;
    texture.game_saved.load("data/textures/misc/game_saved.png",texture_count);texture_count++;
    texture.game_loaded.load("data/textures/misc/game_loaded.png",texture_count);texture_count++;

    texture.health_powerup.load("data/textures/powerups/health_powerup.png",texture_count);texture_count++;
    texture.shield_lvlup_powerup.load("data/textures/powerups/shield_lvlup_powerup.png",texture_count);texture_count++;
    texture.shield_new_powerup.load("data/textures/powerups/shield_new_powerup.png",texture_count);texture_count++;
    texture.thruster_lvlup_powerup.load("data/textures/powerups/thruster_lvlup_powerup.png",texture_count);texture_count++;
    texture.thruster_new_powerup.load("data/textures/powerups/thruster_new_powerup.png",texture_count);texture_count++;
    texture.weapon_lvlup_powerup.load("data/textures/powerups/weapon_lvlup_powerup.png",texture_count);texture_count++;
    texture.weapon_new_powerup.load("data/textures/powerups/weapon_new_powerup.png",texture_count);texture_count++;

    texture.achievements.load("data/textures/menu/achievements.png",texture_count);texture_count++;
    texture.achievements_highlighted.load("data/textures/menu/achievements_highlighted.png",texture_count);texture_count++;
    texture.score.load("data/textures/menu/score.png",texture_count);texture_count++;
    texture.score_highlighted.load("data/textures/menu/score_highlighted.png",texture_count);texture_count++;
    texture.kills.load("data/textures/menu/kills.png",texture_count);texture_count++;
    texture.kills_highlighted.load("data/textures/menu/kills_highlighted.png",texture_count);texture_count++;
    texture.grey_star.load("data/textures/menu/grey_star.png",texture_count);texture_count++;
    texture.bronze_star.load("data/textures/menu/bronze_star.png",texture_count);texture_count++;
    texture.silver_star.load("data/textures/menu/silver_star.png",texture_count);texture_count++;
    texture.gold_star.load("data/textures/menu/gold_star.png",texture_count);texture_count++;

    texture.kills_achievement.load("data/textures/misc/kills_achievement.png",texture_count);texture_count++;
    texture.score_achievement.load("data/textures/misc/score_achievement.png",texture_count);texture_count++;
    texture.actinium_shields.load("data/textures/misc/actinium_shields.png",texture_count);texture_count++;
    texture.blasters.load("data/textures/misc/blasters.png",texture_count);texture_count++;
    texture.burst_lasers.load("data/textures/misc/burst_lasers.png",texture_count);texture_count++;
    texture.chain_guns.load("data/textures/misc/chain_guns.png",texture_count);texture_count++;
    texture.convolution_thrusters.load("data/textures/misc/convolution_thrusters.png",texture_count);texture_count++;

    texture.health.load("data/textures/misc/health.png",texture_count);texture_count++;
    texture.ion_cannons.load("data/textures/misc/ion_cannons.png",texture_count);texture_count++;
    texture.iridium_shileds.load("data/textures/misc/iridium_shileds.png",texture_count);texture_count++;
    texture.maelstrom_thrusters.load("data/textures/misc/maelstrom_thrusters.png",texture_count);texture_count++;
    texture.plasma_rockets.load("data/textures/misc/plasma_rockets.png",texture_count);texture_count++;
    texture.rail_turrets.load("data/textures/misc/rail_turrets.png",texture_count);texture_count++;
    texture.rubidium_shields.load("data/textures/misc/rubidium_shields.png",texture_count);texture_count++;
    texture.seismic_thrusters.load("data/textures/misc/seismic_thrusters.png",texture_count);texture_count++;
    texture.shield_level_up.load("data/textures/misc/shield_level_up.png",texture_count);texture_count++;
    texture.tantalum_shields.load("data/textures/misc/tantalum_shields.png",texture_count);texture_count++;
    texture.terbium_shields.load("data/textures/misc/terbium_shields.png",texture_count);texture_count++;
    texture.thrusters_level_up.load("data/textures/misc/thrusters_level_up.png",texture_count);texture_count++;
    texture.vortex_thrusters.load("data/textures/misc/vortex_thrusters.png",texture_count);texture_count++;
    texture.weapon_level_up.load("data/textures/misc/weapon_level_up.png",texture_count);texture_count++;

    texture.game_over.load("data/textures/menu/game_over.png",texture_count);texture_count++;
    texture.logo_red.load("data/textures/menu/logo_red.png",texture_count);texture_count++;
    texture.press_enter_for_the_main_menu.load("data/textures/menu/press_enter_for_the_main_menu.png",texture_count);texture_count++;
    texture.explosion_001.load("data/textures/misc/explosion_001.png",texture_count);texture_count++;
    texture.level_completed.load("data/textures/menu/level_completed.png",texture_count);texture_count++;
    texture.enter_for_next_level.load("data/textures/menu/enter_for_next_level.png",texture_count);texture_count++;
    texture.new_level_unlocked.load("data/textures/menu/new_level_unlocked.png",texture_count);texture_count++;

    texture.thruster_003.load("data/textures/thrusters/thruster_003.png",texture_count);texture_count++;
    texture.coin_powerup.load("data/textures/powerups/coin_powerup.png",texture_count);texture_count++;
    texture.wexp_powerup.load("data/textures/powerups/wexp_powerup.png",texture_count);texture_count++;
    texture.credits_00.load("data/textures/misc/credits_00.png",texture_count);texture_count++;
    texture.level_progress_bar.load("data/textures/misc/level_progress_bar.png",texture_count);texture_count++;
    texture.bomb_powerup.load("data/textures/powerups/bomb_powerup.png",texture_count);texture_count++;
    texture.sideship_00.load("data/textures/ships/sideship_00.png",texture_count);texture_count++;
    texture.sideship_01.load("data/textures/ships/sideship_01.png",texture_count);texture_count++;
    texture.sideship_02.load("data/textures/ships/sideship_02.png",texture_count);texture_count++;
    texture.sideship_03.load("data/textures/ships/sideship_03.png",texture_count);texture_count++;
    texture.powerup_sideship_00.load("data/textures/powerups/powerup_sideship_00.png",texture_count);texture_count++;
    texture.powerup_sideship_01.load("data/textures/powerups/powerup_sideship_01.png",texture_count);texture_count++;
    texture.powerup_sideship_02.load("data/textures/powerups/powerup_sideship_02.png",texture_count);texture_count++;
    texture.powerup_sideship_03.load("data/textures/powerups/powerup_sideship_03.png",texture_count);texture_count++;
    texture.touchscreen_arrow.load("data/textures/misc/touchscreen_arrow.png",texture_count);texture_count++;
    texture.touchscreen_button.load("data/textures/misc/touchscreen_button.png",texture_count);texture_count++;

    texture.explosion_101.load("data/textures/explosions/explosion_01/explosion_01.png",texture_count);texture_count++;
    texture.explosion_102.load("data/textures/explosions/explosion_01/explosion_02.png",texture_count);texture_count++;
    texture.explosion_103.load("data/textures/explosions/explosion_01/explosion_03.png",texture_count);texture_count++;
    texture.explosion_104.load("data/textures/explosions/explosion_01/explosion_04.png",texture_count);texture_count++;
    texture.explosion_105.load("data/textures/explosions/explosion_01/explosion_05.png",texture_count);texture_count++;
    texture.explosion_106.load("data/textures/explosions/explosion_01/explosion_06.png",texture_count);texture_count++;
    texture.explosion_107.load("data/textures/explosions/explosion_01/explosion_07.png",texture_count);texture_count++;
    texture.explosion_108.load("data/textures/explosions/explosion_01/explosion_08.png",texture_count);texture_count++;
    texture.explosion_109.load("data/textures/explosions/explosion_01/explosion_09.png",texture_count);texture_count++;
    texture.explosion_110.load("data/textures/explosions/explosion_01/explosion_10.png",texture_count);texture_count++;
    texture.explosion_111.load("data/textures/explosions/explosion_01/explosion_11.png",texture_count);texture_count++;
    texture.explosion_112.load("data/textures/explosions/explosion_01/explosion_12.png",texture_count);texture_count++;
    texture.explosion_113.load("data/textures/explosions/explosion_01/explosion_13.png",texture_count);texture_count++;
    texture.explosion_114.load("data/textures/explosions/explosion_01/explosion_14.png",texture_count);texture_count++;
    texture.explosion_115.load("data/textures/explosions/explosion_01/explosion_15.png",texture_count);texture_count++;
    texture.explosion_116.load("data/textures/explosions/explosion_01/explosion_16.png",texture_count);texture_count++;
    texture.explosion_117.load("data/textures/explosions/explosion_01/explosion_17.png",texture_count);texture_count++;
    texture.explosion_118.load("data/textures/explosions/explosion_01/explosion_18.png",texture_count);texture_count++;
    texture.explosion_119.load("data/textures/explosions/explosion_01/explosion_19.png",texture_count);texture_count++;
    texture.explosion_120.load("data/textures/explosions/explosion_01/explosion_20.png",texture_count);texture_count++;
    texture.explosion_121.load("data/textures/explosions/explosion_01/explosion_21.png",texture_count);texture_count++;
    texture.explosion_122.load("data/textures/explosions/explosion_01/explosion_22.png",texture_count);texture_count++;
    texture.explosion_123.load("data/textures/explosions/explosion_01/explosion_23.png",texture_count);texture_count++;
    texture.explosion_124.load("data/textures/explosions/explosion_01/explosion_24.png",texture_count);texture_count++;

    texture.explosion_201.load("data/textures/explosions/explosion_02/explosion_01.png",texture_count);texture_count++;
    texture.explosion_202.load("data/textures/explosions/explosion_02/explosion_02.png",texture_count);texture_count++;
    texture.explosion_203.load("data/textures/explosions/explosion_02/explosion_03.png",texture_count);texture_count++;
    texture.explosion_204.load("data/textures/explosions/explosion_02/explosion_04.png",texture_count);texture_count++;
    texture.explosion_205.load("data/textures/explosions/explosion_02/explosion_05.png",texture_count);texture_count++;
    texture.explosion_206.load("data/textures/explosions/explosion_02/explosion_06.png",texture_count);texture_count++;
    texture.explosion_207.load("data/textures/explosions/explosion_02/explosion_07.png",texture_count);texture_count++;
    texture.explosion_208.load("data/textures/explosions/explosion_02/explosion_08.png",texture_count);texture_count++;
    texture.explosion_209.load("data/textures/explosions/explosion_02/explosion_09.png",texture_count);texture_count++;
    texture.explosion_210.load("data/textures/explosions/explosion_02/explosion_10.png",texture_count);texture_count++;
    texture.explosion_211.load("data/textures/explosions/explosion_02/explosion_11.png",texture_count);texture_count++;
    texture.explosion_212.load("data/textures/explosions/explosion_02/explosion_12.png",texture_count);texture_count++;
    texture.explosion_213.load("data/textures/explosions/explosion_02/explosion_13.png",texture_count);texture_count++;
    texture.explosion_214.load("data/textures/explosions/explosion_02/explosion_14.png",texture_count);texture_count++;
    texture.explosion_215.load("data/textures/explosions/explosion_02/explosion_15.png",texture_count);texture_count++;
    texture.explosion_216.load("data/textures/explosions/explosion_02/explosion_16.png",texture_count);texture_count++;
    texture.explosion_217.load("data/textures/explosions/explosion_02/explosion_17.png",texture_count);texture_count++;
    texture.explosion_218.load("data/textures/explosions/explosion_02/explosion_18.png",texture_count);texture_count++;
    texture.explosion_219.load("data/textures/explosions/explosion_02/explosion_19.png",texture_count);texture_count++;
    texture.explosion_220.load("data/textures/explosions/explosion_02/explosion_20.png",texture_count);texture_count++;
    texture.explosion_221.load("data/textures/explosions/explosion_02/explosion_21.png",texture_count);texture_count++;
    texture.explosion_222.load("data/textures/explosions/explosion_02/explosion_22.png",texture_count);texture_count++;
    texture.explosion_223.load("data/textures/explosions/explosion_02/explosion_23.png",texture_count);texture_count++;
    texture.explosion_224.load("data/textures/explosions/explosion_02/explosion_24.png",texture_count);texture_count++;
    texture.explosion_225.load("data/textures/explosions/explosion_02/explosion_25.png",texture_count);texture_count++;
    texture.explosion_226.load("data/textures/explosions/explosion_02/explosion_26.png",texture_count);texture_count++;
    texture.explosion_227.load("data/textures/explosions/explosion_02/explosion_27.png",texture_count);texture_count++;
    texture.explosion_228.load("data/textures/explosions/explosion_02/explosion_28.png",texture_count);texture_count++;
    texture.explosion_229.load("data/textures/explosions/explosion_02/explosion_29.png",texture_count);texture_count++;
    texture.explosion_230.load("data/textures/explosions/explosion_02/explosion_30.png",texture_count);texture_count++;

    texture.menu_background_002.load("data/textures/menu/menu_background_00.png",texture_count);texture_count++;
    texture.menu_background_003.load("data/textures/menu/menu_background_01.png",texture_count);texture_count++;
    texture.red_button.load("data/textures/menu/red_button.png",texture_count);texture_count++;
    texture.red_button_highlighted.load("data/textures/menu/red_button_highlighted.png",texture_count);texture_count++;
    texture.green_button.load("data/textures/menu/green_button.png",texture_count);texture_count++;
    texture.green_button_highlighted.load("data/textures/menu/green_button_highlighted.png",texture_count);texture_count++;
    texture.blue_button.load("data/textures/menu/blue_button.png",texture_count);texture_count++;
    texture.blue_button_highlighted.load("data/textures/menu/blue_button_highlighted.png",texture_count);texture_count++;
    texture.arrow_button_normal.load("data/textures/menu/arrow_normal.png",texture_count);texture_count++;
    texture.arrow_button_highlighted.load("data/textures/menu/arrow_highlighted.png",texture_count);texture_count++;
    texture.arrow_button_disabled.load("data/textures/menu/arrow_disabled.png",texture_count);texture_count++;
    texture.slider_normal.load("data/textures/menu/slider_normal.png",texture_count);texture_count++;
    texture.slider_highlighted.load("data/textures/menu/slider_highlighted.png",texture_count);texture_count++;
    texture.resolution_icon.load("data/textures/menu/resolution_icon.png",texture_count);texture_count++;
    texture.projectile_031.load("data/textures/projectiles/projectile_031.png",texture_count);texture_count++;
    game.log.File_Write("Texture files loaded -> ",texture_count);
    return(true);
};

bool bind_texture(int texture_number)
{
    if (texture_number ==   0) glBindTexture( GL_TEXTURE_2D, texture.res_1024x768.data[0 /*replace_me.frame*/]);
    if (texture_number ==   1) glBindTexture( GL_TEXTURE_2D, texture.res_1024x768_highlighted.data[0 /*replace_me.frame*/]);
    if (texture_number ==   2) glBindTexture( GL_TEXTURE_2D, texture.res_1280x1024.data[0 /*replace_me.frame*/]);
    if (texture_number ==   3) glBindTexture( GL_TEXTURE_2D, texture.res_1280x1024_highlighted.data[0 /*replace_me.frame*/]);
    if (texture_number ==   4) glBindTexture( GL_TEXTURE_2D, texture.res_1366x768.data[0 /*replace_me.frame*/]);
    if (texture_number ==   5) glBindTexture( GL_TEXTURE_2D, texture.res_1366x768_highlighted.data[0 /*replace_me.frame*/]);
    if (texture_number ==   6) glBindTexture( GL_TEXTURE_2D, texture.res_1440x900.data[0 /*replace_me.frame*/]);
    if (texture_number ==   7) glBindTexture( GL_TEXTURE_2D, texture.res_1440x900_highlighted.data[0 /*replace_me.frame*/]);
    if (texture_number ==   8) glBindTexture( GL_TEXTURE_2D, texture.res_1680x1050.data[0 /*replace_me.frame*/]);
    if (texture_number ==   9) glBindTexture( GL_TEXTURE_2D, texture.res_1680x1050_highlighted.data[0 /*replace_me.frame*/]);
    if (texture_number ==  10) glBindTexture( GL_TEXTURE_2D, texture.res_1920x1080.data[0 /*replace_me.frame*/]);
    if (texture_number ==  11) glBindTexture( GL_TEXTURE_2D, texture.res_1920x1080_highlighted.data[0 /*replace_me.frame*/]);
    if (texture_number ==  12) glBindTexture( GL_TEXTURE_2D, texture.res_640x480.data[0 /*replace_me.frame*/]);
    if (texture_number ==  13) glBindTexture( GL_TEXTURE_2D, texture.res_640x480_highlighted.data[0 /*replace_me.frame*/]);
    if (texture_number ==  14) glBindTexture( GL_TEXTURE_2D, texture.res_800x600.data[0 /*replace_me.frame*/]);
    if (texture_number ==  15) glBindTexture( GL_TEXTURE_2D, texture.res_800x600_highlighted.data[0 /*replace_me.frame*/]);
    if (texture_number ==  16) glBindTexture( GL_TEXTURE_2D, texture.bar_001.data[0 /*replace_me.frame*/]);
    if (texture_number ==  17) glBindTexture( GL_TEXTURE_2D, texture.bar_001_highlighted.data[0 /*replace_me.frame*/]);
    if (texture_number ==  18) glBindTexture( GL_TEXTURE_2D, texture.bar_002.data[0 /*replace_me.frame*/]);
    if (texture_number ==  19) glBindTexture( GL_TEXTURE_2D, texture.bar_002_highlighted.data[0 /*replace_me.frame*/]);
    if (texture_number ==  20) glBindTexture( GL_TEXTURE_2D, texture.customize_starship.data[0 /*replace_me.frame*/]);
    if (texture_number ==  21) glBindTexture( GL_TEXTURE_2D, texture.customize_starship_highlighted.data[0 /*replace_me.frame*/]);
    if (texture_number ==  22) glBindTexture( GL_TEXTURE_2D, texture.front_weapon.data[0 /*replace_me.frame*/]);
    if (texture_number ==  23) glBindTexture( GL_TEXTURE_2D, texture.front_weapon_highlighted.data[0 /*replace_me.frame*/]);
    if (texture_number ==  24) glBindTexture( GL_TEXTURE_2D, texture.fullscreen.data[0 /*replace_me.frame*/]);
    if (texture_number ==  25) glBindTexture( GL_TEXTURE_2D, texture.fullscreen_highlighted.data[0 /*replace_me.frame*/]);
    if (texture_number ==  26) glBindTexture( GL_TEXTURE_2D, texture.game_menu.data[0 /*replace_me.frame*/]);
    if (texture_number ==  27) glBindTexture( GL_TEXTURE_2D, texture.game_menu_highlighted.data[0 /*replace_me.frame*/]);
    if (texture_number ==  28) glBindTexture( GL_TEXTURE_2D, texture.load_game.data[0 /*replace_me.frame*/]);
    if (texture_number ==  29) glBindTexture( GL_TEXTURE_2D, texture.load_game_highlighted.data[0 /*replace_me.frame*/]);
    if (texture_number ==  30) glBindTexture( GL_TEXTURE_2D, texture.logo.data[0 /*replace_me.frame*/]);
    if (texture_number ==  31) glBindTexture( GL_TEXTURE_2D, texture.main_menu.data[0 /*replace_me.frame*/]);
    if (texture_number ==  32) glBindTexture( GL_TEXTURE_2D, texture.main_menu_highlighted.data[0 /*replace_me.frame*/]);
    if (texture_number ==  33) glBindTexture( GL_TEXTURE_2D, texture.music_volume.data[0 /*replace_me.frame*/]);
    if (texture_number ==  34) glBindTexture( GL_TEXTURE_2D, texture.music_volume_highlighted.data[0 /*replace_me.frame*/]);
    if (texture_number ==  35) glBindTexture( GL_TEXTURE_2D, texture.new_game.data[0 /*replace_me.frame*/]);
    if (texture_number ==  36) glBindTexture( GL_TEXTURE_2D, texture.new_game_highlighted.data[0 /*replace_me.frame*/]);
    if (texture_number ==  37) glBindTexture( GL_TEXTURE_2D, texture.off.data[0 /*replace_me.frame*/]);
    if (texture_number ==  38) glBindTexture( GL_TEXTURE_2D, texture.off_highlighted.data[0 /*replace_me.frame*/]);
    if (texture_number ==  39) glBindTexture( GL_TEXTURE_2D, texture.on.data[0 /*replace_me.frame*/]);
    if (texture_number ==  40) glBindTexture( GL_TEXTURE_2D, texture.on_highlighted.data[0 /*replace_me.frame*/]);
    if (texture_number ==  41) glBindTexture( GL_TEXTURE_2D, texture.options.data[0 /*replace_me.frame*/]);
    if (texture_number ==  42) glBindTexture( GL_TEXTURE_2D, texture.options_highlighted.data[0 /*replace_me.frame*/]);
    if (texture_number ==  43) glBindTexture( GL_TEXTURE_2D, texture.options_menu.data[0 /*replace_me.frame*/]);
    if (texture_number ==  44) glBindTexture( GL_TEXTURE_2D, texture.options_menu_highlighted.data[0 /*replace_me.frame*/]);
    if (texture_number ==  45) glBindTexture( GL_TEXTURE_2D, texture.quit_game.data[0 /*replace_me.frame*/]);
    if (texture_number ==  46) glBindTexture( GL_TEXTURE_2D, texture.quit_game_highlighted.data[0 /*replace_me.frame*/]);
    if (texture_number ==  47) glBindTexture( GL_TEXTURE_2D, texture.resolution.data[0 /*replace_me.frame*/]);
    if (texture_number ==  48) glBindTexture( GL_TEXTURE_2D, texture.resolution_highlighted.data[0 /*replace_me.frame*/]);
    if (texture_number ==  49) glBindTexture( GL_TEXTURE_2D, texture.resume_game.data[0 /*replace_me.frame*/]);
    if (texture_number ==  50) glBindTexture( GL_TEXTURE_2D, texture.resume_game_highlighted.data[0 /*replace_me.frame*/]);
    if (texture_number ==  51) glBindTexture( GL_TEXTURE_2D, texture.save_game.data[0 /*replace_me.frame*/]);
    if (texture_number ==  52) glBindTexture( GL_TEXTURE_2D, texture.save_game_highlighted.data[0 /*replace_me.frame*/]);
    if (texture_number ==  53) glBindTexture( GL_TEXTURE_2D, texture.shield.data[0 /*replace_me.frame*/]);
    if (texture_number ==  54) glBindTexture( GL_TEXTURE_2D, texture.shield_highlighted.data[0 /*replace_me.frame*/]);
    if (texture_number ==  55) glBindTexture( GL_TEXTURE_2D, texture.side_weapon.data[0 /*replace_me.frame*/]);
    if (texture_number ==  56) glBindTexture( GL_TEXTURE_2D, texture.side_weapon_highlighted.data[0 /*replace_me.frame*/]);
    if (texture_number ==  57) glBindTexture( GL_TEXTURE_2D, texture.sound_volume.data[0 /*replace_me.frame*/]);
    if (texture_number ==  58) glBindTexture( GL_TEXTURE_2D, texture.sound_volume_highlighted.data[0 /*replace_me.frame*/]);
    if (texture_number ==  59) glBindTexture( GL_TEXTURE_2D, texture.star_map.data[0 /*replace_me.frame*/]);
    if (texture_number ==  60) glBindTexture( GL_TEXTURE_2D, texture.star_map_highlighted.data[0 /*replace_me.frame*/]);
    if (texture_number ==  61) glBindTexture( GL_TEXTURE_2D, texture.thrusters.data[0 /*replace_me.frame*/]);
    if (texture_number ==  62) glBindTexture( GL_TEXTURE_2D, texture.thrusters_highlighted.data[0 /*replace_me.frame*/]);

    if (texture_number ==  63) glBindTexture( GL_TEXTURE_2D, texture.menu_background_000.data[0 /*replace_me.frame*/]);
    if (texture_number ==  64) glBindTexture( GL_TEXTURE_2D, texture.menu_background_001.data[0 /*replace_me.frame*/]);
    if (texture_number ==  65) glBindTexture( GL_TEXTURE_2D, texture.background_000.data[0 /*replace_me.frame*/]);
    if (texture_number ==  66) glBindTexture( GL_TEXTURE_2D, texture.background_001.data[0 /*replace_me.frame*/]);
    if (texture_number ==  67) glBindTexture( GL_TEXTURE_2D, texture.background_002.data[0 /*replace_me.frame*/]);
    if (texture_number ==  68) glBindTexture( GL_TEXTURE_2D, texture.background_003.data[0 /*replace_me.frame*/]);
    if (texture_number ==  69) glBindTexture( GL_TEXTURE_2D, texture.background_004.data[0 /*replace_me.frame*/]);
    if (texture_number ==  70) glBindTexture( GL_TEXTURE_2D, texture.background_005.data[0 /*replace_me.frame*/]);
    if (texture_number ==  71) glBindTexture( GL_TEXTURE_2D, texture.background_006.data[0 /*replace_me.frame*/]);
    if (texture_number ==  72) glBindTexture( GL_TEXTURE_2D, texture.background_007.data[0 /*replace_me.frame*/]);
    if (texture_number ==  73) glBindTexture( GL_TEXTURE_2D, texture.background_008.data[0 /*replace_me.frame*/]);
    if (texture_number ==  74) glBindTexture( GL_TEXTURE_2D, texture.background_009.data[0 /*replace_me.frame*/]);
    if (texture_number ==  75) glBindTexture( GL_TEXTURE_2D, texture.background_010.data[0 /*replace_me.frame*/]);
    if (texture_number ==  76) glBindTexture( GL_TEXTURE_2D, texture.background_011.data[0 /*replace_me.frame*/]);
    if (texture_number ==  77) glBindTexture( GL_TEXTURE_2D, texture.background_012.data[0 /*replace_me.frame*/]);
    if (texture_number ==  78) glBindTexture( GL_TEXTURE_2D, texture.background_013.data[0 /*replace_me.frame*/]);
    if (texture_number ==  79) glBindTexture( GL_TEXTURE_2D, texture.background_014.data[0 /*replace_me.frame*/]);
    if (texture_number ==  80) glBindTexture( GL_TEXTURE_2D, texture.background_015.data[0 /*replace_me.frame*/]);
    if (texture_number ==  81) glBindTexture( GL_TEXTURE_2D, texture.background_016.data[0 /*replace_me.frame*/]);
    if (texture_number ==  82) glBindTexture( GL_TEXTURE_2D, texture.background_017.data[0 /*replace_me.frame*/]);
    if (texture_number ==  83) glBindTexture( GL_TEXTURE_2D, texture.background_018.data[0 /*replace_me.frame*/]);
    if (texture_number ==  84) glBindTexture( GL_TEXTURE_2D, texture.background_019.data[0 /*replace_me.frame*/]);
    if (texture_number ==  85) glBindTexture( GL_TEXTURE_2D, texture.background_020.data[0 /*replace_me.frame*/]);
    if (texture_number ==  86) glBindTexture( GL_TEXTURE_2D, texture.background_021.data[0 /*replace_me.frame*/]);
    if (texture_number ==  87) glBindTexture( GL_TEXTURE_2D, texture.background_022.data[0 /*replace_me.frame*/]);
    if (texture_number ==  88) glBindTexture( GL_TEXTURE_2D, texture.background_023.data[0 /*replace_me.frame*/]);
    if (texture_number ==  89) glBindTexture( GL_TEXTURE_2D, texture.background_024.data[0 /*replace_me.frame*/]);
    if (texture_number ==  90) glBindTexture( GL_TEXTURE_2D, texture.background_025.data[0 /*replace_me.frame*/]);
    if (texture_number ==  91) glBindTexture( GL_TEXTURE_2D, texture.background_026.data[0 /*replace_me.frame*/]);
    if (texture_number ==  92) glBindTexture( GL_TEXTURE_2D, texture.background_027.data[0 /*replace_me.frame*/]);
    if (texture_number ==  93) glBindTexture( GL_TEXTURE_2D, texture.background_028.data[0 /*replace_me.frame*/]);
    if (texture_number ==  94) glBindTexture( GL_TEXTURE_2D, texture.background_029.data[0 /*replace_me.frame*/]);
    if (texture_number ==  95) glBindTexture( GL_TEXTURE_2D, texture.background_030.data[0 /*replace_me.frame*/]);
    if (texture_number ==  96) glBindTexture( GL_TEXTURE_2D, texture.background_031.data[0 /*replace_me.frame*/]);

    if (texture_number ==  97) glBindTexture( GL_TEXTURE_2D, texture.level_00.data[0 /*replace_me.frame*/]);
    if (texture_number ==  98) glBindTexture( GL_TEXTURE_2D, texture.level_01.data[0 /*replace_me.frame*/]);
    if (texture_number ==  99) glBindTexture( GL_TEXTURE_2D, texture.level_02.data[0 /*replace_me.frame*/]);
    if (texture_number == 100) glBindTexture( GL_TEXTURE_2D, texture.level_03.data[0 /*replace_me.frame*/]);
    if (texture_number == 101) glBindTexture( GL_TEXTURE_2D, texture.level_04.data[0 /*replace_me.frame*/]);
    if (texture_number == 102) glBindTexture( GL_TEXTURE_2D, texture.level_05.data[0 /*replace_me.frame*/]);
    if (texture_number == 103) glBindTexture( GL_TEXTURE_2D, texture.level_06.data[0 /*replace_me.frame*/]);
    if (texture_number == 104) glBindTexture( GL_TEXTURE_2D, texture.level_07.data[0 /*replace_me.frame*/]);
    if (texture_number == 105) glBindTexture( GL_TEXTURE_2D, texture.level_08.data[0 /*replace_me.frame*/]);
    if (texture_number == 106) glBindTexture( GL_TEXTURE_2D, texture.level_09.data[0 /*replace_me.frame*/]);
    if (texture_number == 107) glBindTexture( GL_TEXTURE_2D, texture.level_10.data[0 /*replace_me.frame*/]);
    if (texture_number == 108) glBindTexture( GL_TEXTURE_2D, texture.level_11.data[0 /*replace_me.frame*/]);
    if (texture_number == 109) glBindTexture( GL_TEXTURE_2D, texture.level_12.data[0 /*replace_me.frame*/]);
    if (texture_number == 110) glBindTexture( GL_TEXTURE_2D, texture.level_13.data[0 /*replace_me.frame*/]);
    if (texture_number == 111) glBindTexture( GL_TEXTURE_2D, texture.level_14.data[0 /*replace_me.frame*/]);
    if (texture_number == 112) glBindTexture( GL_TEXTURE_2D, texture.level_15.data[0 /*replace_me.frame*/]);
    if (texture_number == 113) glBindTexture( GL_TEXTURE_2D, texture.level_16.data[0 /*replace_me.frame*/]);
    if (texture_number == 114) glBindTexture( GL_TEXTURE_2D, texture.level_17.data[0 /*replace_me.frame*/]);
    if (texture_number == 115) glBindTexture( GL_TEXTURE_2D, texture.level_18.data[0 /*replace_me.frame*/]);
    if (texture_number == 116) glBindTexture( GL_TEXTURE_2D, texture.level_19.data[0 /*replace_me.frame*/]);
    if (texture_number == 117) glBindTexture( GL_TEXTURE_2D, texture.level_20.data[0 /*replace_me.frame*/]);
    if (texture_number == 118) glBindTexture( GL_TEXTURE_2D, texture.level_21.data[0 /*replace_me.frame*/]);
    if (texture_number == 119) glBindTexture( GL_TEXTURE_2D, texture.level_22.data[0 /*replace_me.frame*/]);
    if (texture_number == 120) glBindTexture( GL_TEXTURE_2D, texture.level_23.data[0 /*replace_me.frame*/]);
    if (texture_number == 121) glBindTexture( GL_TEXTURE_2D, texture.level_24.data[0 /*replace_me.frame*/]);

    if (texture_number == 122) glBindTexture( GL_TEXTURE_2D, texture.level_highlighted_00.data[0 /*replace_me.frame*/]);
    if (texture_number == 123) glBindTexture( GL_TEXTURE_2D, texture.level_highlighted_01.data[0 /*replace_me.frame*/]);
    if (texture_number == 124) glBindTexture( GL_TEXTURE_2D, texture.level_highlighted_02.data[0 /*replace_me.frame*/]);
    if (texture_number == 125) glBindTexture( GL_TEXTURE_2D, texture.level_highlighted_03.data[0 /*replace_me.frame*/]);
    if (texture_number == 126) glBindTexture( GL_TEXTURE_2D, texture.level_highlighted_04.data[0 /*replace_me.frame*/]);
    if (texture_number == 127) glBindTexture( GL_TEXTURE_2D, texture.level_highlighted_05.data[0 /*replace_me.frame*/]);
    if (texture_number == 128) glBindTexture( GL_TEXTURE_2D, texture.level_highlighted_06.data[0 /*replace_me.frame*/]);
    if (texture_number == 129) glBindTexture( GL_TEXTURE_2D, texture.level_highlighted_07.data[0 /*replace_me.frame*/]);
    if (texture_number == 130) glBindTexture( GL_TEXTURE_2D, texture.level_highlighted_08.data[0 /*replace_me.frame*/]);
    if (texture_number == 131) glBindTexture( GL_TEXTURE_2D, texture.level_highlighted_09.data[0 /*replace_me.frame*/]);
    if (texture_number == 132) glBindTexture( GL_TEXTURE_2D, texture.level_highlighted_10.data[0 /*replace_me.frame*/]);
    if (texture_number == 133) glBindTexture( GL_TEXTURE_2D, texture.level_highlighted_11.data[0 /*replace_me.frame*/]);
    if (texture_number == 134) glBindTexture( GL_TEXTURE_2D, texture.level_highlighted_12.data[0 /*replace_me.frame*/]);
    if (texture_number == 135) glBindTexture( GL_TEXTURE_2D, texture.level_highlighted_13.data[0 /*replace_me.frame*/]);
    if (texture_number == 136) glBindTexture( GL_TEXTURE_2D, texture.level_highlighted_14.data[0 /*replace_me.frame*/]);
    if (texture_number == 137) glBindTexture( GL_TEXTURE_2D, texture.level_highlighted_15.data[0 /*replace_me.frame*/]);
    if (texture_number == 138) glBindTexture( GL_TEXTURE_2D, texture.level_highlighted_16.data[0 /*replace_me.frame*/]);
    if (texture_number == 139) glBindTexture( GL_TEXTURE_2D, texture.level_highlighted_17.data[0 /*replace_me.frame*/]);
    if (texture_number == 140) glBindTexture( GL_TEXTURE_2D, texture.level_highlighted_18.data[0 /*replace_me.frame*/]);
    if (texture_number == 141) glBindTexture( GL_TEXTURE_2D, texture.level_highlighted_19.data[0 /*replace_me.frame*/]);
    if (texture_number == 142) glBindTexture( GL_TEXTURE_2D, texture.level_highlighted_20.data[0 /*replace_me.frame*/]);
    if (texture_number == 143) glBindTexture( GL_TEXTURE_2D, texture.level_highlighted_21.data[0 /*replace_me.frame*/]);
    if (texture_number == 144) glBindTexture( GL_TEXTURE_2D, texture.level_highlighted_22.data[0 /*replace_me.frame*/]);
    if (texture_number == 145) glBindTexture( GL_TEXTURE_2D, texture.level_highlighted_23.data[0 /*replace_me.frame*/]);
    if (texture_number == 146) glBindTexture( GL_TEXTURE_2D, texture.level_highlighted_24.data[0 /*replace_me.frame*/]);

    if (texture_number == 147) glBindTexture( GL_TEXTURE_2D, texture.level_preview_00.data[0 /*replace_me.frame*/]);
    if (texture_number == 148) glBindTexture( GL_TEXTURE_2D, texture.level_preview_01.data[0 /*replace_me.frame*/]);
    if (texture_number == 149) glBindTexture( GL_TEXTURE_2D, texture.level_preview_02.data[0 /*replace_me.frame*/]);
    if (texture_number == 150) glBindTexture( GL_TEXTURE_2D, texture.level_preview_03.data[0 /*replace_me.frame*/]);
    if (texture_number == 151) glBindTexture( GL_TEXTURE_2D, texture.level_preview_04.data[0 /*replace_me.frame*/]);
    if (texture_number == 152) glBindTexture( GL_TEXTURE_2D, texture.level_preview_05.data[0 /*replace_me.frame*/]);
    if (texture_number == 153) glBindTexture( GL_TEXTURE_2D, texture.level_preview_06.data[0 /*replace_me.frame*/]);
    if (texture_number == 154) glBindTexture( GL_TEXTURE_2D, texture.level_preview_07.data[0 /*replace_me.frame*/]);
    if (texture_number == 155) glBindTexture( GL_TEXTURE_2D, texture.level_preview_08.data[0 /*replace_me.frame*/]);
    if (texture_number == 156) glBindTexture( GL_TEXTURE_2D, texture.level_preview_09.data[0 /*replace_me.frame*/]);
    if (texture_number == 157) glBindTexture( GL_TEXTURE_2D, texture.level_preview_10.data[0 /*replace_me.frame*/]);
    if (texture_number == 158) glBindTexture( GL_TEXTURE_2D, texture.level_preview_11.data[0 /*replace_me.frame*/]);
    if (texture_number == 159) glBindTexture( GL_TEXTURE_2D, texture.level_preview_12.data[0 /*replace_me.frame*/]);
    if (texture_number == 160) glBindTexture( GL_TEXTURE_2D, texture.level_preview_13.data[0 /*replace_me.frame*/]);
    if (texture_number == 161) glBindTexture( GL_TEXTURE_2D, texture.level_preview_14.data[0 /*replace_me.frame*/]);
    if (texture_number == 162) glBindTexture( GL_TEXTURE_2D, texture.level_preview_15.data[0 /*replace_me.frame*/]);
    if (texture_number == 163) glBindTexture( GL_TEXTURE_2D, texture.level_preview_16.data[0 /*replace_me.frame*/]);
    if (texture_number == 164) glBindTexture( GL_TEXTURE_2D, texture.level_preview_17.data[0 /*replace_me.frame*/]);
    if (texture_number == 165) glBindTexture( GL_TEXTURE_2D, texture.level_preview_18.data[0 /*replace_me.frame*/]);
    if (texture_number == 166) glBindTexture( GL_TEXTURE_2D, texture.level_preview_19.data[0 /*replace_me.frame*/]);
    if (texture_number == 167) glBindTexture( GL_TEXTURE_2D, texture.level_preview_20.data[0 /*replace_me.frame*/]);
    if (texture_number == 168) glBindTexture( GL_TEXTURE_2D, texture.level_preview_21.data[0 /*replace_me.frame*/]);
    if (texture_number == 169) glBindTexture( GL_TEXTURE_2D, texture.level_preview_22.data[0 /*replace_me.frame*/]);
    if (texture_number == 170) glBindTexture( GL_TEXTURE_2D, texture.level_preview_23.data[0 /*replace_me.frame*/]);
    if (texture_number == 171) glBindTexture( GL_TEXTURE_2D, texture.level_preview_24.data[0 /*replace_me.frame*/]);
    if (texture_number == 172) glBindTexture( GL_TEXTURE_2D, texture.level_preview_locked.data[0 /*replace_me.frame*/]);

    if (texture_number == 173) glBindTexture( GL_TEXTURE_2D, texture.save_game_00.data[0 /*replace_me.frame*/]);
    if (texture_number == 174) glBindTexture( GL_TEXTURE_2D, texture.save_game_01.data[0 /*replace_me.frame*/]);
    if (texture_number == 175) glBindTexture( GL_TEXTURE_2D, texture.save_game_02.data[0 /*replace_me.frame*/]);
    if (texture_number == 176) glBindTexture( GL_TEXTURE_2D, texture.save_game_03.data[0 /*replace_me.frame*/]);
    if (texture_number == 177) glBindTexture( GL_TEXTURE_2D, texture.save_game_04.data[0 /*replace_me.frame*/]);
    if (texture_number == 178) glBindTexture( GL_TEXTURE_2D, texture.save_game_05.data[0 /*replace_me.frame*/]);
    if (texture_number == 179) glBindTexture( GL_TEXTURE_2D, texture.save_game_highlighted_00.data[0 /*replace_me.frame*/]);
    if (texture_number == 180) glBindTexture( GL_TEXTURE_2D, texture.save_game_highlighted_01.data[0 /*replace_me.frame*/]);
    if (texture_number == 181) glBindTexture( GL_TEXTURE_2D, texture.save_game_highlighted_02.data[0 /*replace_me.frame*/]);
    if (texture_number == 182) glBindTexture( GL_TEXTURE_2D, texture.save_game_highlighted_03.data[0 /*replace_me.frame*/]);
    if (texture_number == 183) glBindTexture( GL_TEXTURE_2D, texture.save_game_highlighted_04.data[0 /*replace_me.frame*/]);
    if (texture_number == 184) glBindTexture( GL_TEXTURE_2D, texture.save_game_highlighted_05.data[0 /*replace_me.frame*/]);

    if (texture_number == 185) glBindTexture( GL_TEXTURE_2D, texture.explosion_00.data[0 /*replace_me.frame*/]);
    if (texture_number == 186) glBindTexture( GL_TEXTURE_2D, texture.explosion_01.data[0 /*replace_me.frame*/]);
    if (texture_number == 187) glBindTexture( GL_TEXTURE_2D, texture.explosion_02.data[0 /*replace_me.frame*/]);
    if (texture_number == 188) glBindTexture( GL_TEXTURE_2D, texture.explosion_03.data[0 /*replace_me.frame*/]);
    if (texture_number == 189) glBindTexture( GL_TEXTURE_2D, texture.explosion_04.data[0 /*replace_me.frame*/]);
    if (texture_number == 190) glBindTexture( GL_TEXTURE_2D, texture.explosion_05.data[0 /*replace_me.frame*/]);
    if (texture_number == 191) glBindTexture( GL_TEXTURE_2D, texture.explosion_06.data[0 /*replace_me.frame*/]);
    if (texture_number == 192) glBindTexture( GL_TEXTURE_2D, texture.explosion_07.data[0 /*replace_me.frame*/]);
    if (texture_number == 193) glBindTexture( GL_TEXTURE_2D, texture.explosion_08.data[0 /*replace_me.frame*/]);
    if (texture_number == 194) glBindTexture( GL_TEXTURE_2D, texture.explosion_09.data[0 /*replace_me.frame*/]);
    if (texture_number == 195) glBindTexture( GL_TEXTURE_2D, texture.explosion_10.data[0 /*replace_me.frame*/]);
    if (texture_number == 196) glBindTexture( GL_TEXTURE_2D, texture.explosion_11.data[0 /*replace_me.frame*/]);
    if (texture_number == 197) glBindTexture( GL_TEXTURE_2D, texture.explosion_12.data[0 /*replace_me.frame*/]);
    if (texture_number == 198) glBindTexture( GL_TEXTURE_2D, texture.explosion_13.data[0 /*replace_me.frame*/]);
    if (texture_number == 199) glBindTexture( GL_TEXTURE_2D, texture.explosion_14.data[0 /*replace_me.frame*/]);
    if (texture_number == 200) glBindTexture( GL_TEXTURE_2D, texture.explosion_15.data[0 /*replace_me.frame*/]);
    if (texture_number == 201) glBindTexture( GL_TEXTURE_2D, texture.explosion_16.data[0 /*replace_me.frame*/]);
    if (texture_number == 202) glBindTexture( GL_TEXTURE_2D, texture.explosion_17.data[0 /*replace_me.frame*/]);
    if (texture_number == 203) glBindTexture( GL_TEXTURE_2D, texture.explosion_18.data[0 /*replace_me.frame*/]);
    if (texture_number == 204) glBindTexture( GL_TEXTURE_2D, texture.explosion_19.data[0 /*replace_me.frame*/]);
    if (texture_number == 205) glBindTexture( GL_TEXTURE_2D, texture.explosion_20.data[0 /*replace_me.frame*/]);
    if (texture_number == 206) glBindTexture( GL_TEXTURE_2D, texture.explosion_21.data[0 /*replace_me.frame*/]);
    if (texture_number == 207) glBindTexture( GL_TEXTURE_2D, texture.explosion_22.data[0 /*replace_me.frame*/]);
    if (texture_number == 208) glBindTexture( GL_TEXTURE_2D, texture.explosion_23.data[0 /*replace_me.frame*/]);
    if (texture_number == 209) glBindTexture( GL_TEXTURE_2D, texture.explosion_24.data[0 /*replace_me.frame*/]);

    if (texture_number == 210) glBindTexture( GL_TEXTURE_2D, texture.health_bar.data[0 /*replace_me.frame*/]);

    if (texture_number == 211) glBindTexture( GL_TEXTURE_2D, texture.weapon_000.data[0 /*replace_me.frame*/]);
    if (texture_number == 212) glBindTexture( GL_TEXTURE_2D, texture.weapon_001.data[0 /*replace_me.frame*/]);
    if (texture_number == 213) glBindTexture( GL_TEXTURE_2D, texture.weapon_002.data[0 /*replace_me.frame*/]);
    if (texture_number == 214) glBindTexture( GL_TEXTURE_2D, texture.weapon_003.data[0 /*replace_me.frame*/]);
    if (texture_number == 215) glBindTexture( GL_TEXTURE_2D, texture.weapon_004.data[0 /*replace_me.frame*/]);
    if (texture_number == 216) glBindTexture( GL_TEXTURE_2D, texture.weapon_005.data[0 /*replace_me.frame*/]);

    if (texture_number == 217) glBindTexture( GL_TEXTURE_2D, texture.shield_000.data[0 /*replace_me.frame*/]);
    if (texture_number == 218) glBindTexture( GL_TEXTURE_2D, texture.shield_001.data[0 /*replace_me.frame*/]);
    if (texture_number == 219) glBindTexture( GL_TEXTURE_2D, texture.shield_002.data[0 /*replace_me.frame*/]);
    if (texture_number == 220) glBindTexture( GL_TEXTURE_2D, texture.shield_003.data[0 /*replace_me.frame*/]);
    if (texture_number == 221) glBindTexture( GL_TEXTURE_2D, texture.shield_004.data[0 /*replace_me.frame*/]);

    if (texture_number == 222) glBindTexture( GL_TEXTURE_2D, texture.projectile_000.data[0 /*replace_me.frame*/]);
    if (texture_number == 223) glBindTexture( GL_TEXTURE_2D, texture.projectile_001.data[0 /*replace_me.frame*/]);
    if (texture_number == 224) glBindTexture( GL_TEXTURE_2D, texture.projectile_002.data[0 /*replace_me.frame*/]);
    if (texture_number == 225) glBindTexture( GL_TEXTURE_2D, texture.projectile_003.data[0 /*replace_me.frame*/]);
    if (texture_number == 226) glBindTexture( GL_TEXTURE_2D, texture.projectile_004.data[0 /*replace_me.frame*/]);
    if (texture_number == 227) glBindTexture( GL_TEXTURE_2D, texture.projectile_005.data[0 /*replace_me.frame*/]);
    if (texture_number == 228) glBindTexture( GL_TEXTURE_2D, texture.projectile_006.data[0 /*replace_me.frame*/]);
    if (texture_number == 229) glBindTexture( GL_TEXTURE_2D, texture.projectile_007.data[0 /*replace_me.frame*/]);
    if (texture_number == 230) glBindTexture( GL_TEXTURE_2D, texture.projectile_008.data[0 /*replace_me.frame*/]);
    if (texture_number == 231) glBindTexture( GL_TEXTURE_2D, texture.projectile_009.data[0 /*replace_me.frame*/]);
    if (texture_number == 232) glBindTexture( GL_TEXTURE_2D, texture.projectile_010.data[0 /*replace_me.frame*/]);
    if (texture_number == 233) glBindTexture( GL_TEXTURE_2D, texture.projectile_011.data[0 /*replace_me.frame*/]);
    if (texture_number == 234) glBindTexture( GL_TEXTURE_2D, texture.projectile_012.data[0 /*replace_me.frame*/]);
    if (texture_number == 235) glBindTexture( GL_TEXTURE_2D, texture.projectile_013.data[0 /*replace_me.frame*/]);
    if (texture_number == 236) glBindTexture( GL_TEXTURE_2D, texture.projectile_014.data[0 /*replace_me.frame*/]);
    if (texture_number == 237) glBindTexture( GL_TEXTURE_2D, texture.projectile_015.data[0 /*replace_me.frame*/]);
    if (texture_number == 238) glBindTexture( GL_TEXTURE_2D, texture.projectile_016.data[0 /*replace_me.frame*/]);
    if (texture_number == 239) glBindTexture( GL_TEXTURE_2D, texture.projectile_017.data[0 /*replace_me.frame*/]);
    if (texture_number == 240) glBindTexture( GL_TEXTURE_2D, texture.projectile_018.data[0 /*replace_me.frame*/]);
    if (texture_number == 241) glBindTexture( GL_TEXTURE_2D, texture.projectile_019.data[0 /*replace_me.frame*/]);
    if (texture_number == 242) glBindTexture( GL_TEXTURE_2D, texture.projectile_020.data[0 /*replace_me.frame*/]);
    if (texture_number == 243) glBindTexture( GL_TEXTURE_2D, texture.projectile_021.data[0 /*replace_me.frame*/]);
    if (texture_number == 244) glBindTexture( GL_TEXTURE_2D, texture.projectile_022.data[0 /*replace_me.frame*/]);
    if (texture_number == 245) glBindTexture( GL_TEXTURE_2D, texture.projectile_023.data[0 /*replace_me.frame*/]);
    if (texture_number == 246) glBindTexture( GL_TEXTURE_2D, texture.projectile_024.data[0 /*replace_me.frame*/]);
    if (texture_number == 247) glBindTexture( GL_TEXTURE_2D, texture.projectile_025.data[0 /*replace_me.frame*/]);
    if (texture_number == 248) glBindTexture( GL_TEXTURE_2D, texture.projectile_026.data[0 /*replace_me.frame*/]);
    if (texture_number == 249) glBindTexture( GL_TEXTURE_2D, texture.projectile_027.data[0 /*replace_me.frame*/]);
    if (texture_number == 250) glBindTexture( GL_TEXTURE_2D, texture.projectile_028.data[0 /*replace_me.frame*/]);
    if (texture_number == 251) glBindTexture( GL_TEXTURE_2D, texture.projectile_029.data[0 /*replace_me.frame*/]);
    if (texture_number == 252) glBindTexture( GL_TEXTURE_2D, texture.projectile_030.data[0 /*replace_me.frame*/]);

    if (texture_number == 253) glBindTexture( GL_TEXTURE_2D, texture.ship_000.data[0 /*replace_me.frame*/]);
    if (texture_number == 254) glBindTexture( GL_TEXTURE_2D, texture.ship_001.data[0 /*replace_me.frame*/]);
    if (texture_number == 255) glBindTexture( GL_TEXTURE_2D, texture.ship_002.data[0 /*replace_me.frame*/]);
    if (texture_number == 256) glBindTexture( GL_TEXTURE_2D, texture.ship_003.data[0 /*replace_me.frame*/]);
    if (texture_number == 257) glBindTexture( GL_TEXTURE_2D, texture.ship_004.data[0 /*replace_me.frame*/]);
    if (texture_number == 258) glBindTexture( GL_TEXTURE_2D, texture.ship_005.data[0 /*replace_me.frame*/]);
    if (texture_number == 259) glBindTexture( GL_TEXTURE_2D, texture.ship_006.data[0 /*replace_me.frame*/]);
    if (texture_number == 260) glBindTexture( GL_TEXTURE_2D, texture.ship_007.data[0 /*replace_me.frame*/]);
    if (texture_number == 261) glBindTexture( GL_TEXTURE_2D, texture.ship_008.data[0 /*replace_me.frame*/]);
    if (texture_number == 262) glBindTexture( GL_TEXTURE_2D, texture.ship_009.data[0 /*replace_me.frame*/]);
    if (texture_number == 263) glBindTexture( GL_TEXTURE_2D, texture.ship_010.data[0 /*replace_me.frame*/]);
    if (texture_number == 264) glBindTexture( GL_TEXTURE_2D, texture.ship_011.data[0 /*replace_me.frame*/]);
    if (texture_number == 265) glBindTexture( GL_TEXTURE_2D, texture.ship_012.data[0 /*replace_me.frame*/]);
    if (texture_number == 266) glBindTexture( GL_TEXTURE_2D, texture.ship_013.data[0 /*replace_me.frame*/]);
    if (texture_number == 267) glBindTexture( GL_TEXTURE_2D, texture.ship_014.data[0 /*replace_me.frame*/]);
    if (texture_number == 268) glBindTexture( GL_TEXTURE_2D, texture.ship_015.data[0 /*replace_me.frame*/]);
    if (texture_number == 269) glBindTexture( GL_TEXTURE_2D, texture.ship_016.data[0 /*replace_me.frame*/]);
    if (texture_number == 270) glBindTexture( GL_TEXTURE_2D, texture.ship_017.data[0 /*replace_me.frame*/]);
    if (texture_number == 271) glBindTexture( GL_TEXTURE_2D, texture.ship_018.data[0 /*replace_me.frame*/]);
    if (texture_number == 272) glBindTexture( GL_TEXTURE_2D, texture.ship_019.data[0 /*replace_me.frame*/]);
    if (texture_number == 273) glBindTexture( GL_TEXTURE_2D, texture.ship_020.data[0 /*replace_me.frame*/]);
    if (texture_number == 274) glBindTexture( GL_TEXTURE_2D, texture.ship_021.data[0 /*replace_me.frame*/]);
    if (texture_number == 275) glBindTexture( GL_TEXTURE_2D, texture.ship_022.data[0 /*replace_me.frame*/]);
    if (texture_number == 276) glBindTexture( GL_TEXTURE_2D, texture.ship_023.data[0 /*replace_me.frame*/]);
    if (texture_number == 277) glBindTexture( GL_TEXTURE_2D, texture.ship_024.data[0 /*replace_me.frame*/]);
    if (texture_number == 278) glBindTexture( GL_TEXTURE_2D, texture.ship_025.data[0 /*replace_me.frame*/]);

    if (texture_number == 279) glBindTexture( GL_TEXTURE_2D, texture.thruster_000.data[0 /*replace_me.frame*/]);
    if (texture_number == 280) glBindTexture( GL_TEXTURE_2D, texture.thruster_001.data[0 /*replace_me.frame*/]);
    if (texture_number == 281) glBindTexture( GL_TEXTURE_2D, texture.thruster_002.data[0 /*replace_me.frame*/]);

    if (texture_number == 282) glBindTexture( GL_TEXTURE_2D, texture.selection_box.data[0 /*replace_me.frame*/]);
    if (texture_number == 283) glBindTexture( GL_TEXTURE_2D, texture.none.data[0 /*replace_me.frame*/]);
    if (texture_number == 284) glBindTexture( GL_TEXTURE_2D, texture.locked.data[0 /*replace_me.frame*/]);
    if (texture_number == 285) glBindTexture( GL_TEXTURE_2D, texture.weapon_bar.data[0 /*replace_me.frame*/]);
    if (texture_number == 286) glBindTexture( GL_TEXTURE_2D, texture.shield_bar.data[0 /*replace_me.frame*/]);
    if (texture_number == 287) glBindTexture( GL_TEXTURE_2D, texture.thruster_bar.data[0 /*replace_me.frame*/]);
    if (texture_number == 288) glBindTexture( GL_TEXTURE_2D, texture.game_paused.data[0 /*replace_me.frame*/]);
    if (texture_number == 289) glBindTexture( GL_TEXTURE_2D, texture.game_saved.data[0 /*replace_me.frame*/]);
    if (texture_number == 290) glBindTexture( GL_TEXTURE_2D, texture.game_loaded.data[0 /*replace_me.frame*/]);

    if (texture_number == 291) glBindTexture( GL_TEXTURE_2D, texture.health_powerup.data[0 /*replace_me.frame*/]);
    if (texture_number == 292) glBindTexture( GL_TEXTURE_2D, texture.shield_lvlup_powerup.data[0 /*replace_me.frame*/]);
    if (texture_number == 293) glBindTexture( GL_TEXTURE_2D, texture.shield_new_powerup.data[0 /*replace_me.frame*/]);
    if (texture_number == 294) glBindTexture( GL_TEXTURE_2D, texture.thruster_lvlup_powerup.data[0 /*replace_me.frame*/]);
    if (texture_number == 295) glBindTexture( GL_TEXTURE_2D, texture.thruster_new_powerup.data[0 /*replace_me.frame*/]);
    if (texture_number == 296) glBindTexture( GL_TEXTURE_2D, texture.weapon_lvlup_powerup.data[0 /*replace_me.frame*/]);
    if (texture_number == 297) glBindTexture( GL_TEXTURE_2D, texture.weapon_new_powerup.data[0 /*replace_me.frame*/]);

    if (texture_number == 298) glBindTexture( GL_TEXTURE_2D, texture.achievements.data[0 /*replace_me.frame*/]);
    if (texture_number == 299) glBindTexture( GL_TEXTURE_2D, texture.achievements_highlighted.data[0 /*replace_me.frame*/]);
    if (texture_number == 300) glBindTexture( GL_TEXTURE_2D, texture.score.data[0 /*replace_me.frame*/]);
    if (texture_number == 301) glBindTexture( GL_TEXTURE_2D, texture.score_highlighted.data[0 /*replace_me.frame*/]);
    if (texture_number == 302) glBindTexture( GL_TEXTURE_2D, texture.kills.data[0 /*replace_me.frame*/]);
    if (texture_number == 303) glBindTexture( GL_TEXTURE_2D, texture.kills_highlighted.data[0 /*replace_me.frame*/]);
    if (texture_number == 304) glBindTexture( GL_TEXTURE_2D, texture.grey_star.data[0 /*replace_me.frame*/]);
    if (texture_number == 305) glBindTexture( GL_TEXTURE_2D, texture.bronze_star.data[0 /*replace_me.frame*/]);
    if (texture_number == 306) glBindTexture( GL_TEXTURE_2D, texture.silver_star.data[0 /*replace_me.frame*/]);
    if (texture_number == 307) glBindTexture( GL_TEXTURE_2D, texture.gold_star.data[0 /*replace_me.frame*/]);

    if (texture_number == 308) glBindTexture( GL_TEXTURE_2D, texture.kills_achievement.data[0 /*replace_me.frame*/]);
    if (texture_number == 309) glBindTexture( GL_TEXTURE_2D, texture.score_achievement.data[0 /*replace_me.frame*/]);
    if (texture_number == 310) glBindTexture( GL_TEXTURE_2D, texture.actinium_shields.data[0 /*replace_me.frame*/]);
    if (texture_number == 311) glBindTexture( GL_TEXTURE_2D, texture.blasters.data[0 /*replace_me.frame*/]);
    if (texture_number == 312) glBindTexture( GL_TEXTURE_2D, texture.burst_lasers.data[0 /*replace_me.frame*/]);
    if (texture_number == 313) glBindTexture( GL_TEXTURE_2D, texture.chain_guns.data[0 /*replace_me.frame*/]);
    if (texture_number == 314) glBindTexture( GL_TEXTURE_2D, texture.convolution_thrusters.data[0 /*replace_me.frame*/]);
    if (texture_number == 315) glBindTexture( GL_TEXTURE_2D, texture.health.data[0 /*replace_me.frame*/]);
    if (texture_number == 316) glBindTexture( GL_TEXTURE_2D, texture.ion_cannons.data[0 /*replace_me.frame*/]);
    if (texture_number == 317) glBindTexture( GL_TEXTURE_2D, texture.iridium_shileds.data[0 /*replace_me.frame*/]);
    if (texture_number == 318) glBindTexture( GL_TEXTURE_2D, texture.maelstrom_thrusters.data[0 /*replace_me.frame*/]);
    if (texture_number == 319) glBindTexture( GL_TEXTURE_2D, texture.plasma_rockets.data[0 /*replace_me.frame*/]);
    if (texture_number == 320) glBindTexture( GL_TEXTURE_2D, texture.rail_turrets.data[0 /*replace_me.frame*/]);
    if (texture_number == 321) glBindTexture( GL_TEXTURE_2D, texture.rubidium_shields.data[0 /*replace_me.frame*/]);
    if (texture_number == 322) glBindTexture( GL_TEXTURE_2D, texture.seismic_thrusters.data[0 /*replace_me.frame*/]);
    if (texture_number == 323) glBindTexture( GL_TEXTURE_2D, texture.shield_level_up.data[0 /*replace_me.frame*/]);
    if (texture_number == 324) glBindTexture( GL_TEXTURE_2D, texture.tantalum_shields.data[0 /*replace_me.frame*/]);
    if (texture_number == 325) glBindTexture( GL_TEXTURE_2D, texture.terbium_shields.data[0 /*replace_me.frame*/]);
    if (texture_number == 326) glBindTexture( GL_TEXTURE_2D, texture.thrusters_level_up.data[0 /*replace_me.frame*/]);
    if (texture_number == 327) glBindTexture( GL_TEXTURE_2D, texture.vortex_thrusters.data[0 /*replace_me.frame*/]);
    if (texture_number == 328) glBindTexture( GL_TEXTURE_2D, texture.weapon_level_up.data[0 /*replace_me.frame*/]);

    if (texture_number == 329) glBindTexture( GL_TEXTURE_2D, texture.game_over.data[0 /*replace_me.frame*/]);
    if (texture_number == 330) glBindTexture( GL_TEXTURE_2D, texture.logo_red.data[0 /*replace_me.frame*/]);
    if (texture_number == 331) glBindTexture( GL_TEXTURE_2D, texture.press_enter_for_the_main_menu.data[0 /*replace_me.frame*/]);
    if (texture_number == 332) glBindTexture( GL_TEXTURE_2D, texture.explosion_001.data[0 /*replace_me.frame*/]);
    if (texture_number == 333) glBindTexture( GL_TEXTURE_2D, texture.level_completed.data[0 /*replace_me.frame*/]);
    if (texture_number == 334) glBindTexture( GL_TEXTURE_2D, texture.enter_for_next_level.data[0 /*replace_me.frame*/]);
    if (texture_number == 335) glBindTexture( GL_TEXTURE_2D, texture.new_level_unlocked.data[0 /*replace_me.frame*/]);
    if (texture_number == 336) glBindTexture( GL_TEXTURE_2D, texture.thruster_003.data[0 /*replace_me.frame*/]);
    if (texture_number == 337) glBindTexture( GL_TEXTURE_2D, texture.coin_powerup.data[0 /*replace_me.frame*/]);
    if (texture_number == 338) glBindTexture( GL_TEXTURE_2D, texture.wexp_powerup.data[0 /*replace_me.frame*/]);
    if (texture_number == 339) glBindTexture( GL_TEXTURE_2D, texture.credits_00.data[0 /*replace_me.frame*/]);
    if (texture_number == 340) glBindTexture( GL_TEXTURE_2D, texture.level_progress_bar.data[0 /*replace_me.frame*/]);
    if (texture_number == 341) glBindTexture( GL_TEXTURE_2D, texture.bomb_powerup.data[0 /*replace_me.frame*/]);
    if (texture_number == 242) glBindTexture( GL_TEXTURE_2D, texture.sideship_00.data[0 /*replace_me.frame*/]);
    if (texture_number == 243) glBindTexture( GL_TEXTURE_2D, texture.sideship_01.data[0 /*replace_me.frame*/]);
    if (texture_number == 244) glBindTexture( GL_TEXTURE_2D, texture.sideship_02.data[0 /*replace_me.frame*/]);
    if (texture_number == 245) glBindTexture( GL_TEXTURE_2D, texture.sideship_03.data[0 /*replace_me.frame*/]);
    if (texture_number == 346) glBindTexture( GL_TEXTURE_2D, texture.powerup_sideship_00.data[0 /*replace_me.frame*/]);
    if (texture_number == 347) glBindTexture( GL_TEXTURE_2D, texture.powerup_sideship_01.data[0 /*replace_me.frame*/]);
    if (texture_number == 348) glBindTexture( GL_TEXTURE_2D, texture.powerup_sideship_02.data[0 /*replace_me.frame*/]);
    if (texture_number == 349) glBindTexture( GL_TEXTURE_2D, texture.powerup_sideship_03.data[0 /*replace_me.frame*/]);
    if (texture_number == 350) glBindTexture( GL_TEXTURE_2D, texture.touchscreen_arrow.data[0 /*replace_me.frame*/]);
    if (texture_number == 351) glBindTexture( GL_TEXTURE_2D, texture.touchscreen_button.data[0 /*replace_me.frame*/]);

    if (texture_number == 352) glBindTexture( GL_TEXTURE_2D, texture.explosion_101.data[0 /*replace_me.frame*/]);
    if (texture_number == 353) glBindTexture( GL_TEXTURE_2D, texture.explosion_102.data[0 /*replace_me.frame*/]);
    if (texture_number == 354) glBindTexture( GL_TEXTURE_2D, texture.explosion_103.data[0 /*replace_me.frame*/]);
    if (texture_number == 355) glBindTexture( GL_TEXTURE_2D, texture.explosion_104.data[0 /*replace_me.frame*/]);
    if (texture_number == 356) glBindTexture( GL_TEXTURE_2D, texture.explosion_105.data[0 /*replace_me.frame*/]);
    if (texture_number == 357) glBindTexture( GL_TEXTURE_2D, texture.explosion_106.data[0 /*replace_me.frame*/]);
    if (texture_number == 358) glBindTexture( GL_TEXTURE_2D, texture.explosion_107.data[0 /*replace_me.frame*/]);
    if (texture_number == 359) glBindTexture( GL_TEXTURE_2D, texture.explosion_108.data[0 /*replace_me.frame*/]);
    if (texture_number == 360) glBindTexture( GL_TEXTURE_2D, texture.explosion_109.data[0 /*replace_me.frame*/]);
    if (texture_number == 361) glBindTexture( GL_TEXTURE_2D, texture.explosion_110.data[0 /*replace_me.frame*/]);
    if (texture_number == 362) glBindTexture( GL_TEXTURE_2D, texture.explosion_111.data[0 /*replace_me.frame*/]);
    if (texture_number == 363) glBindTexture( GL_TEXTURE_2D, texture.explosion_112.data[0 /*replace_me.frame*/]);

    if (texture_number == 364) glBindTexture( GL_TEXTURE_2D, texture.explosion_201.data[0 /*replace_me.frame*/]);
    if (texture_number == 365) glBindTexture( GL_TEXTURE_2D, texture.explosion_202.data[0 /*replace_me.frame*/]);
    if (texture_number == 366) glBindTexture( GL_TEXTURE_2D, texture.explosion_203.data[0 /*replace_me.frame*/]);
    if (texture_number == 367) glBindTexture( GL_TEXTURE_2D, texture.explosion_204.data[0 /*replace_me.frame*/]);
    if (texture_number == 368) glBindTexture( GL_TEXTURE_2D, texture.explosion_205.data[0 /*replace_me.frame*/]);
    if (texture_number == 369) glBindTexture( GL_TEXTURE_2D, texture.explosion_206.data[0 /*replace_me.frame*/]);
    if (texture_number == 370) glBindTexture( GL_TEXTURE_2D, texture.explosion_207.data[0 /*replace_me.frame*/]);
    if (texture_number == 371) glBindTexture( GL_TEXTURE_2D, texture.explosion_208.data[0 /*replace_me.frame*/]);
    if (texture_number == 372) glBindTexture( GL_TEXTURE_2D, texture.explosion_209.data[0 /*replace_me.frame*/]);
    if (texture_number == 373) glBindTexture( GL_TEXTURE_2D, texture.explosion_210.data[0 /*replace_me.frame*/]);
    if (texture_number == 374) glBindTexture( GL_TEXTURE_2D, texture.explosion_211.data[0 /*replace_me.frame*/]);
    if (texture_number == 375) glBindTexture( GL_TEXTURE_2D, texture.explosion_212.data[0 /*replace_me.frame*/]);
    if (texture_number == 376) glBindTexture( GL_TEXTURE_2D, texture.explosion_213.data[0 /*replace_me.frame*/]);
    if (texture_number == 377) glBindTexture( GL_TEXTURE_2D, texture.explosion_214.data[0 /*replace_me.frame*/]);
    if (texture_number == 378) glBindTexture( GL_TEXTURE_2D, texture.explosion_215.data[0 /*replace_me.frame*/]);
    if (texture_number == 379) glBindTexture( GL_TEXTURE_2D, texture.explosion_216.data[0 /*replace_me.frame*/]);
    if (texture_number == 380) glBindTexture( GL_TEXTURE_2D, texture.explosion_217.data[0 /*replace_me.frame*/]);
    if (texture_number == 381) glBindTexture( GL_TEXTURE_2D, texture.explosion_218.data[0 /*replace_me.frame*/]);
    if (texture_number == 382) glBindTexture( GL_TEXTURE_2D, texture.explosion_219.data[0 /*replace_me.frame*/]);
    if (texture_number == 383) glBindTexture( GL_TEXTURE_2D, texture.explosion_220.data[0 /*replace_me.frame*/]);
    if (texture_number == 384) glBindTexture( GL_TEXTURE_2D, texture.explosion_221.data[0 /*replace_me.frame*/]);
    if (texture_number == 385) glBindTexture( GL_TEXTURE_2D, texture.explosion_222.data[0 /*replace_me.frame*/]);
    if (texture_number == 386) glBindTexture( GL_TEXTURE_2D, texture.explosion_223.data[0 /*replace_me.frame*/]);
    if (texture_number == 387) glBindTexture( GL_TEXTURE_2D, texture.explosion_224.data[0 /*replace_me.frame*/]);
    if (texture_number == 388) glBindTexture( GL_TEXTURE_2D, texture.explosion_225.data[0 /*replace_me.frame*/]);
    if (texture_number == 389) glBindTexture( GL_TEXTURE_2D, texture.explosion_226.data[0 /*replace_me.frame*/]);
    if (texture_number == 390) glBindTexture( GL_TEXTURE_2D, texture.explosion_227.data[0 /*replace_me.frame*/]);
    if (texture_number == 391) glBindTexture( GL_TEXTURE_2D, texture.explosion_228.data[0 /*replace_me.frame*/]);
    if (texture_number == 392) glBindTexture( GL_TEXTURE_2D, texture.explosion_229.data[0 /*replace_me.frame*/]);
    if (texture_number == 393) glBindTexture( GL_TEXTURE_2D, texture.explosion_230.data[0 /*replace_me.frame*/]);

    if (texture_number == 394) glBindTexture( GL_TEXTURE_2D, texture.menu_background_002.data[0 /*replace_me.frame*/]);
    if (texture_number == 395) glBindTexture( GL_TEXTURE_2D, texture.menu_background_003.data[0 /*replace_me.frame*/]);
    if (texture_number == 396) glBindTexture( GL_TEXTURE_2D, texture.red_button.data[0 /*replace_me.frame*/]);
    if (texture_number == 397) glBindTexture( GL_TEXTURE_2D, texture.red_button_highlighted.data[0 /*replace_me.frame*/]);
    if (texture_number == 398) glBindTexture( GL_TEXTURE_2D, texture.green_button.data[0 /*replace_me.frame*/]);
    if (texture_number == 399) glBindTexture( GL_TEXTURE_2D, texture.green_button_highlighted.data[0 /*replace_me.frame*/]);
    if (texture_number == 400) glBindTexture( GL_TEXTURE_2D, texture.blue_button.data[0 /*replace_me.frame*/]);
    if (texture_number == 401) glBindTexture( GL_TEXTURE_2D, texture.blue_button_highlighted.data[0 /*replace_me.frame*/]);
    if (texture_number == 402) glBindTexture( GL_TEXTURE_2D, texture.arrow_button_normal.data[0 /*replace_me.frame*/]);
    if (texture_number == 403) glBindTexture( GL_TEXTURE_2D, texture.arrow_button_highlighted.data[0 /*replace_me.frame*/]);
    if (texture_number == 404) glBindTexture( GL_TEXTURE_2D, texture.arrow_button_disabled.data[0 /*replace_me.frame*/]);
    if (texture_number == 405) glBindTexture( GL_TEXTURE_2D, texture.slider_normal.data[0 /*replace_me.frame*/]);
    if (texture_number == 406) glBindTexture( GL_TEXTURE_2D, texture.slider_highlighted.data[0 /*replace_me.frame*/]);
    if (texture_number == 407) glBindTexture( GL_TEXTURE_2D, texture.resolution_icon.data[0 /*replace_me.frame*/]);
    if (texture_number == 408) glBindTexture( GL_TEXTURE_2D, texture.projectile_031.data[0 /*replace_me.frame*/]);
    return(true);
};


bool bind_texture(texture_class bind_me)
{
    glBindTexture( GL_TEXTURE_2D, bind_me.data[0 /*replace_me.frame*/]);
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
    loading_screen.load(file_name,0);
    loading_screen.draw(0.0f,0.0f,0.9f,2.0f,2.0f);
    SDL_GL_SwapBuffers();
    return(true);
};







