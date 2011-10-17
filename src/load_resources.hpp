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

#ifndef LOAD_RESOURCES_H
#define LOAD_RESOURCES_H

#include "core/core.hpp"
#include "core/sound.hpp"
#include "core/music.hpp"
#include "core/textures.hpp"
#include "core/font.hpp"

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
    sound_class explosion_006;
    sound_class explosion_007;
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
    sound_class powerup_08;
    sound_class powerup_09;
    sound_class powerup_10;
    sound_class powerup_11;
    sound_class powerup_12;
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

struct texture_type
{
    texture_class logo;

    texture_class menu_background_000;
    texture_class menu_background_001;
    texture_class background_000;
    texture_class background_001;
    texture_class background_002;
    texture_class background_003;
    texture_class background_004;
    texture_class background_005;
    texture_class background_006;
    texture_class background_007;
    texture_class background_008;
    texture_class background_009;
    texture_class background_010;
    texture_class background_011;
    texture_class background_012;
    texture_class background_013;
    texture_class background_014;
    texture_class background_015;
    texture_class background_016;
    texture_class background_017;
    texture_class background_018;
    texture_class background_019;
    texture_class background_020;
    texture_class background_021;
    texture_class background_022;
    texture_class background_023;
    texture_class background_024;
    texture_class background_025;
    texture_class background_026;
    texture_class background_027;
    texture_class background_028;
    texture_class background_029;
    texture_class background_030;
    texture_class background_031;

    texture_class level_00;
    texture_class level_01;
    texture_class level_02;
    texture_class level_03;
    texture_class level_04;
    texture_class level_05;
    texture_class level_06;
    texture_class level_07;
    texture_class level_08;
    texture_class level_09;
    texture_class level_10;
    texture_class level_11;
    texture_class level_12;
    texture_class level_13;
    texture_class level_14;
    texture_class level_15;
    texture_class level_16;
    texture_class level_17;
    texture_class level_18;
    texture_class level_19;
    texture_class level_20;
    texture_class level_21;
    texture_class level_22;
    texture_class level_23;
    texture_class level_24;

    texture_class level_highlighted_00;
    texture_class level_highlighted_01;
    texture_class level_highlighted_02;
    texture_class level_highlighted_03;
    texture_class level_highlighted_04;
    texture_class level_highlighted_05;
    texture_class level_highlighted_06;
    texture_class level_highlighted_07;
    texture_class level_highlighted_08;
    texture_class level_highlighted_09;
    texture_class level_highlighted_10;
    texture_class level_highlighted_11;
    texture_class level_highlighted_12;
    texture_class level_highlighted_13;
    texture_class level_highlighted_14;
    texture_class level_highlighted_15;
    texture_class level_highlighted_16;
    texture_class level_highlighted_17;
    texture_class level_highlighted_18;
    texture_class level_highlighted_19;
    texture_class level_highlighted_20;
    texture_class level_highlighted_21;
    texture_class level_highlighted_22;
    texture_class level_highlighted_23;
    texture_class level_highlighted_24;

    texture_class level_preview_00;
    texture_class level_preview_01;
    texture_class level_preview_02;
    texture_class level_preview_03;
    texture_class level_preview_04;
    texture_class level_preview_05;
    texture_class level_preview_06;
    texture_class level_preview_07;
    texture_class level_preview_08;
    texture_class level_preview_09;
    texture_class level_preview_10;
    texture_class level_preview_11;
    texture_class level_preview_12;
    texture_class level_preview_13;
    texture_class level_preview_14;
    texture_class level_preview_15;
    texture_class level_preview_16;
    texture_class level_preview_17;
    texture_class level_preview_18;
    texture_class level_preview_19;
    texture_class level_preview_20;
    texture_class level_preview_21;
    texture_class level_preview_22;
    texture_class level_preview_23;
    texture_class level_preview_24;
    texture_class level_preview_locked;

    texture_class explosion_00;
    texture_class explosion_01;
    texture_class explosion_02;
    texture_class explosion_03;

    texture_class health_bar;

    texture_class weapon_000;
    texture_class weapon_001;
    texture_class weapon_002;
    texture_class weapon_003;
    texture_class weapon_004;
    texture_class weapon_005;

    texture_class shield_000;
    texture_class shield_001;
    texture_class shield_002;
    texture_class shield_003;
    texture_class shield_004;

    texture_class projectile_000;
    texture_class projectile_001;
    texture_class projectile_002;
    texture_class projectile_003;
    texture_class projectile_004;
    texture_class projectile_005;
    texture_class projectile_006;
    texture_class projectile_007;
    texture_class projectile_008;
    texture_class projectile_009;
    texture_class projectile_010;
    texture_class projectile_011;
    texture_class projectile_012;
    texture_class projectile_013;
    texture_class projectile_014;
    texture_class projectile_015;
    texture_class projectile_016;
    texture_class projectile_017;
    texture_class projectile_018;
    texture_class projectile_019;
    texture_class projectile_020;
    texture_class projectile_021;
    texture_class projectile_022;
    texture_class projectile_023;
    texture_class projectile_024;
    texture_class projectile_025;
    texture_class projectile_026;
    texture_class projectile_027;
    texture_class projectile_028;
    texture_class projectile_029;
    texture_class projectile_030;
    texture_class projectile_031;

    texture_class ship_000;
    texture_class ship_001;
    texture_class ship_002;
    texture_class ship_003;
    texture_class ship_004;
    texture_class ship_005;
    texture_class ship_006;
    texture_class ship_007;
    texture_class ship_008;
    texture_class ship_009;
    texture_class ship_010;
    texture_class ship_011;
    texture_class ship_012;
    texture_class ship_013;
    texture_class ship_014;
    texture_class ship_015;
    texture_class ship_016;
    texture_class ship_017;
    texture_class ship_018;
    texture_class ship_019;
    texture_class ship_020;
    texture_class ship_021;
    texture_class ship_022;
    texture_class ship_023;
    texture_class ship_024;
    texture_class ship_025;

    texture_class thrusters_000;
    texture_class thrusters_001;
    texture_class thrusters_002;
    texture_class thrusters_003;

    texture_class selection_box;
    texture_class none;
    texture_class locked;
    texture_class weapon_bar;
    texture_class shield_bar;
    texture_class thruster_bar;
    texture_class game_paused;
    texture_class game_saved;
    texture_class game_loaded;

    texture_class health_powerup;
    texture_class shield_lvlup_powerup;
    texture_class shield_new_powerup;
    texture_class thruster_lvlup_powerup;
    texture_class thruster_new_powerup;
    texture_class weapon_lvlup_powerup;
    texture_class weapon_new_powerup;

    texture_class grey_star;
    texture_class bronze_star;
    texture_class silver_star;
    texture_class gold_star;
    texture_class kills_achievement;
    texture_class score_achievement;

    texture_class actinium_shields;
    texture_class blasters;
    texture_class burst_lasers;
    texture_class chain_guns;
    texture_class convolution_thrusters;
    texture_class health;
    texture_class ion_cannons;
    texture_class iridium_shileds;
    texture_class maelstrom_thrusters;
    texture_class plasma_rockets;
    texture_class rail_turrets;
    texture_class rubidium_shields;
    texture_class seismic_thrusters;
    texture_class shield_level_up;
    texture_class tantalum_shields;
    texture_class terbium_shields;
    texture_class thrusters_level_up;
    texture_class vortex_thrusters;
    texture_class weapon_level_up;

    texture_class game_over;
    texture_class logo_red;
    texture_class explosion_001;
    texture_class level_completed;
    texture_class new_level_unlocked;
    texture_class thruster_003;
    texture_class coin_powerup;
    texture_class wexp_powerup;
    texture_class credits_00;
    texture_class level_progress_bar;
    texture_class bomb_powerup;
    texture_class sideship_00;
    texture_class sideship_01;
    texture_class sideship_02;
    texture_class sideship_03;
    texture_class powerup_sideship_00;
    texture_class powerup_sideship_01;
    texture_class powerup_sideship_02;
    texture_class powerup_sideship_03;
    texture_class touchscreen_arrow;
    texture_class touchscreen_button;

    texture_class menu_background_002;
    texture_class menu_background_003;
    texture_class red_button;
    texture_class red_button_highlighted;
    texture_class green_button;
    texture_class green_button_highlighted;
    texture_class blue_button;
    texture_class blue_button_highlighted;
    texture_class arrow_button_normal;
    texture_class arrow_button_highlighted;
    texture_class arrow_button_disabled;
    texture_class slider_normal;
    texture_class slider_highlighted;
    texture_class resolution_icon;
    texture_class particle_000;
    texture_class particle_001;
    texture_class particle_002;
    texture_class particle_003;
    texture_class particle_004;
    texture_class particle_005;
    texture_class particle_006;
    texture_class particle_007;
    texture_class particle_008;
    texture_class particle_009;
    texture_class particle_010;
    texture_class particle_011;
    texture_class particle_012;
    texture_class particle_013;
    texture_class particle_014;
    texture_class particle_015;
};

struct font_type
{
    font_class font_1;
    font_class font_2;
};

bool load_resources(void);
bool load_sounds(void);
bool load_music(void);
bool load_textures(void);
bool proc_textures(void);
bool draw_texture(bool r, int texture_number, float x, float y, float z, float w, float h);
bool draw_texture(bool r, int texture_number, float x, float y, float z, float w, float h, float angle);
bool load_fonts(void);

bool loading_screen_display(std::string file_name);

#endif // LOAD_RESOURCES_H
















