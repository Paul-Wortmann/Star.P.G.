/* Copyright (C) 2011 Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
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
 */

#include <gl/gl.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "textures.h"
#include "config.h"

#define GL_BGR  0x80E0
#define GL_BGRA 0x80E1
texture_type texture[MAX_TEXTURES];
extern const char App_Logf[] = "Star.P.G..log";

int init_textures(void)
{
   for(int count = 0; count < MAX_TEXTURES; count++)
   {
      texture[count].texture = texture[count].texture;
   }
   return(0);
};

int kill_textures(void)
{
   for(int count = 0; count < MAX_TEXTURES; count++)
   {
      glDeleteTextures(1, &texture[count].texture);
   }
   return(0);
};

int load_textures(void)
{
   load_texture (  0, "data/images/menu/1024x768.png");
   load_texture (  1, "data/images/menu/1024x768_highlighted.png");
   load_texture (  2, "data/images/menu/1280x1024.png");
   load_texture (  3, "data/images/menu/1280x1024_highlighted.png");
   load_texture (  4, "data/images/menu/1366x768.png");
   load_texture (  5, "data/images/menu/1366x768_highlighted.png");
   load_texture (  6, "data/images/menu/1440x900.png");
   load_texture (  7, "data/images/menu/1440x900_highlighted.png");
   load_texture (  8, "data/images/menu/1680x1050.png");
   load_texture (  9, "data/images/menu/1680x1050_highlighted.png");
   load_texture ( 10, "data/images/menu/1920x1080.png");
   load_texture ( 11, "data/images/menu/1920x1080_highlighted.png");
   load_texture ( 12, "data/images/menu/640x480.png");
   load_texture ( 13, "data/images/menu/640x480_highlighted.png");
   load_texture ( 14, "data/images/menu/800x600.png");
   load_texture ( 15, "data/images/menu/800x600_highlighted.png");
   load_texture ( 16, "data/images/menu/bar_001.png");
   load_texture ( 17, "data/images/menu/bar_001_highlighted.png");
   load_texture ( 18, "data/images/menu/bar_002.png");
   load_texture ( 19, "data/images/menu/bar_002_highlighted.png");
   load_texture ( 20, "data/images/menu/customize_starship.png");
   load_texture ( 21, "data/images/menu/customize_starship_highlighted.png");
   load_texture ( 22, "data/images/menu/front_weapon.png");
   load_texture ( 23, "data/images/menu/front_weapon_highlighted.png");
   load_texture ( 24, "data/images/menu/fullscreen.png");
   load_texture ( 25, "data/images/menu/fullscreen_highlighted.png");
   load_texture ( 26, "data/images/menu/game_menu.png");
   load_texture ( 27, "data/images/menu/game_menu_highlighted.png");
   load_texture ( 28, "data/images/menu/load_game.png");
   load_texture ( 29, "data/images/menu/load_game_highlighted.png");
   load_texture ( 30, "data/images/menu/logo.png");
   load_texture ( 31, "data/images/menu/main_menu.png");
   load_texture ( 32, "data/images/menu/main_menu_highlighted.png");
   load_texture ( 33, "data/images/menu/music_volume.png");
   load_texture ( 34, "data/images/menu/music_volume_highlighted.png");
   load_texture ( 35, "data/images/menu/new_game.png");
   load_texture ( 36, "data/images/menu/new_game_highlighted.png");
   load_texture ( 37, "data/images/menu/off.png");
   load_texture ( 38, "data/images/menu/off_highlighted.png");
   load_texture ( 39, "data/images/menu/on.png");
   load_texture ( 40, "data/images/menu/on_highlighted.png");
   load_texture ( 41, "data/images/menu/options.png");
   load_texture ( 42, "data/images/menu/options_highlighted.png");
   load_texture ( 43, "data/images/menu/options_menu.png");
   load_texture ( 44, "data/images/menu/options_menu_highlighted.png");
   load_texture ( 45, "data/images/menu/quit_game.png");
   load_texture ( 46, "data/images/menu/quit_game_highlighted.png");
   load_texture ( 47, "data/images/menu/resolution.png");
   load_texture ( 48, "data/images/menu/resolution_highlighted.png");
   load_texture ( 49, "data/images/menu/resume_game.png");
   load_texture ( 50, "data/images/menu/resume_game_highlighted.png");
   load_texture ( 51, "data/images/menu/save_game.png");
   load_texture ( 52, "data/images/menu/save_game_highlighted.png");
   load_texture ( 53, "data/images/menu/shield.png");
   load_texture ( 54, "data/images/menu/shield_highlighted.png");
   load_texture ( 55, "data/images/menu/side_weapon.png");
   load_texture ( 56, "data/images/menu/side_weapon_highlighted.png");
   load_texture ( 57, "data/images/menu/sound_volume.png");
   load_texture ( 58, "data/images/menu/sound_volume_highlighted.png");
   load_texture ( 59, "data/images/menu/star_map.png");
   load_texture ( 60, "data/images/menu/star_map_highlighted.png");
   load_texture ( 61, "data/images/menu/thrusters.png");
   load_texture ( 62, "data/images/menu/thrusters_highlighted.png");

   load_texture ( 63, "data/images/backgrounds/menu_background_000.png");
   load_texture ( 64, "data/images/backgrounds/menu_background_001.png");
   load_texture ( 65, "data/images/backgrounds/background_000.png");
   load_texture ( 66, "data/images/backgrounds/background_001.png");
   load_texture ( 67, "data/images/backgrounds/background_002.png");
   load_texture ( 68, "data/images/backgrounds/background_003.png");
   load_texture ( 69, "data/images/backgrounds/background_004.png");
   load_texture ( 70, "data/images/backgrounds/background_005.png");
   load_texture ( 71, "data/images/backgrounds/background_006.png");
   load_texture ( 72, "data/images/backgrounds/background_007.png");
   load_texture ( 73, "data/images/backgrounds/background_008.png");
   load_texture ( 74, "data/images/backgrounds/background_009.png");
   load_texture ( 75, "data/images/backgrounds/background_010.png");
   load_texture ( 76, "data/images/backgrounds/background_011.png");
   load_texture ( 77, "data/images/backgrounds/background_012.png");
   load_texture ( 78, "data/images/backgrounds/background_013.png");
   load_texture ( 79, "data/images/backgrounds/background_014.png");
   load_texture ( 80, "data/images/backgrounds/background_015.png");
   load_texture ( 81, "data/images/backgrounds/background_016.png");
   load_texture ( 82, "data/images/backgrounds/background_017.png");
   load_texture ( 83, "data/images/backgrounds/background_018.png");
   load_texture ( 84, "data/images/backgrounds/background_019.png");
   load_texture ( 85, "data/images/backgrounds/background_020.png");
   load_texture ( 86, "data/images/backgrounds/background_021.png");
   load_texture ( 87, "data/images/backgrounds/background_022.png");
   load_texture ( 88, "data/images/backgrounds/background_023.png");
   load_texture ( 89, "data/images/backgrounds/background_024.png");
   load_texture ( 90, "data/images/backgrounds/background_025.png");
   load_texture ( 91, "data/images/backgrounds/background_026.png");
   load_texture ( 92, "data/images/backgrounds/background_027.png");
   load_texture ( 93, "data/images/backgrounds/background_028.png");
   load_texture ( 94, "data/images/backgrounds/background_029.png");
   load_texture ( 95, "data/images/backgrounds/background_030.png");
   load_texture ( 96, "data/images/backgrounds/background_031.png");

   load_texture ( 97, "data/images/levels/level_00.png");
   load_texture ( 98, "data/images/levels/level_01.png");
   load_texture ( 99, "data/images/levels/level_02.png");
   load_texture (100, "data/images/levels/level_03.png");
   load_texture (101, "data/images/levels/level_04.png");
   load_texture (102, "data/images/levels/level_05.png");
   load_texture (103, "data/images/levels/level_06.png");
   load_texture (104, "data/images/levels/level_07.png");
   load_texture (105, "data/images/levels/level_08.png");
   load_texture (106, "data/images/levels/level_09.png");
   load_texture (107, "data/images/levels/level_10.png");
   load_texture (108, "data/images/levels/level_11.png");
   load_texture (109, "data/images/levels/level_12.png");
   load_texture (110, "data/images/levels/level_13.png");
   load_texture (111, "data/images/levels/level_14.png");
   load_texture (112, "data/images/levels/level_15.png");
   load_texture (113, "data/images/levels/level_16.png");
   load_texture (114, "data/images/levels/level_17.png");
   load_texture (115, "data/images/levels/level_18.png");
   load_texture (116, "data/images/levels/level_19.png");
   load_texture (117, "data/images/levels/level_20.png");
   load_texture (118, "data/images/levels/level_21.png");
   load_texture (119, "data/images/levels/level_22.png");
   load_texture (120, "data/images/levels/level_23.png");
   load_texture (121, "data/images/levels/level_24.png");

   load_texture (122, "data/images/levels/level_highlighted_00.png");
   load_texture (123, "data/images/levels/level_highlighted_01.png");
   load_texture (124, "data/images/levels/level_highlighted_02.png");
   load_texture (125, "data/images/levels/level_highlighted_03.png");
   load_texture (126, "data/images/levels/level_highlighted_04.png");
   load_texture (127, "data/images/levels/level_highlighted_05.png");
   load_texture (128, "data/images/levels/level_highlighted_06.png");
   load_texture (129, "data/images/levels/level_highlighted_07.png");
   load_texture (130, "data/images/levels/level_highlighted_08.png");
   load_texture (131, "data/images/levels/level_highlighted_09.png");
   load_texture (132, "data/images/levels/level_highlighted_10.png");
   load_texture (133, "data/images/levels/level_highlighted_11.png");
   load_texture (134, "data/images/levels/level_highlighted_12.png");
   load_texture (135, "data/images/levels/level_highlighted_13.png");
   load_texture (136, "data/images/levels/level_highlighted_14.png");
   load_texture (137, "data/images/levels/level_highlighted_15.png");
   load_texture (138, "data/images/levels/level_highlighted_16.png");
   load_texture (139, "data/images/levels/level_highlighted_17.png");
   load_texture (140, "data/images/levels/level_highlighted_18.png");
   load_texture (141, "data/images/levels/level_highlighted_19.png");
   load_texture (142, "data/images/levels/level_highlighted_20.png");
   load_texture (143, "data/images/levels/level_highlighted_21.png");
   load_texture (144, "data/images/levels/level_highlighted_22.png");
   load_texture (145, "data/images/levels/level_highlighted_23.png");
   load_texture (146, "data/images/levels/level_highlighted_24.png");

   load_texture (147, "data/images/levels/level_preview_00.png");
   load_texture (148, "data/images/levels/level_preview_01.png");
   load_texture (149, "data/images/levels/level_preview_02.png");
   load_texture (150, "data/images/levels/level_preview_03.png");
   load_texture (151, "data/images/levels/level_preview_04.png");
   load_texture (152, "data/images/levels/level_preview_05.png");
   load_texture (153, "data/images/levels/level_preview_06.png");
   load_texture (154, "data/images/levels/level_preview_07.png");
   load_texture (155, "data/images/levels/level_preview_08.png");
   load_texture (156, "data/images/levels/level_preview_09.png");
   load_texture (157, "data/images/levels/level_preview_10.png");
   load_texture (158, "data/images/levels/level_preview_11.png");
   load_texture (159, "data/images/levels/level_preview_12.png");
   load_texture (160, "data/images/levels/level_preview_13.png");
   load_texture (161, "data/images/levels/level_preview_14.png");
   load_texture (162, "data/images/levels/level_preview_15.png");
   load_texture (163, "data/images/levels/level_preview_16.png");
   load_texture (164, "data/images/levels/level_preview_17.png");
   load_texture (165, "data/images/levels/level_preview_18.png");
   load_texture (166, "data/images/levels/level_preview_19.png");
   load_texture (167, "data/images/levels/level_preview_20.png");
   load_texture (168, "data/images/levels/level_preview_21.png");
   load_texture (169, "data/images/levels/level_preview_22.png");
   load_texture (170, "data/images/levels/level_preview_23.png");
   load_texture (171, "data/images/levels/level_preview_24.png");
   load_texture (172, "data/images/levels/level_preview_locked.png");

   load_texture (173, "data/images/menu/save_game_00.png");
   load_texture (174, "data/images/menu/save_game_01.png");
   load_texture (175, "data/images/menu/save_game_02.png");
   load_texture (176, "data/images/menu/save_game_03.png");
   load_texture (177, "data/images/menu/save_game_04.png");
   load_texture (178, "data/images/menu/save_game_05.png");
   load_texture (179, "data/images/menu/save_game_highlighted_00.png");
   load_texture (180, "data/images/menu/save_game_highlighted_01.png");
   load_texture (181, "data/images/menu/save_game_highlighted_02.png");
   load_texture (182, "data/images/menu/save_game_highlighted_03.png");
   load_texture (183, "data/images/menu/save_game_highlighted_04.png");
   load_texture (184, "data/images/menu/save_game_highlighted_05.png");

   load_texture (185, "data/images/explosions/explosion_00.png");
   load_texture (186, "data/images/explosions/explosion_01.png");
   load_texture (187, "data/images/explosions/explosion_02.png");
   load_texture (188, "data/images/explosions/explosion_03.png");
   load_texture (189, "data/images/explosions/explosion_04.png");
   load_texture (190, "data/images/explosions/explosion_05.png");
   load_texture (191, "data/images/explosions/explosion_06.png");
   load_texture (192, "data/images/explosions/explosion_07.png");
   load_texture (193, "data/images/explosions/explosion_08.png");
   load_texture (194, "data/images/explosions/explosion_09.png");
   load_texture (195, "data/images/explosions/explosion_10.png");
   load_texture (196, "data/images/explosions/explosion_11.png");
   load_texture (197, "data/images/explosions/explosion_12.png");
   load_texture (198, "data/images/explosions/explosion_13.png");
   load_texture (199, "data/images/explosions/explosion_14.png");
   load_texture (200, "data/images/explosions/explosion_15.png");
   load_texture (201, "data/images/explosions/explosion_16.png");
   load_texture (202, "data/images/explosions/explosion_17.png");
   load_texture (203, "data/images/explosions/explosion_18.png");
   load_texture (204, "data/images/explosions/explosion_19.png");
   load_texture (205, "data/images/explosions/explosion_20.png");
   load_texture (206, "data/images/explosions/explosion_21.png");
   load_texture (207, "data/images/explosions/explosion_22.png");
   load_texture (208, "data/images/explosions/explosion_23.png");
   load_texture (209, "data/images/explosions/explosion_24.png");

   load_texture (210, "data/images/misc/health_bar.png");

   load_texture (211, "data/images/weapons/weapon_000.png");
   load_texture (212, "data/images/weapons/weapon_001.png");
   load_texture (213, "data/images/weapons/weapon_002.png");
   load_texture (214, "data/images/weapons/weapon_003.png");
   load_texture (215, "data/images/weapons/weapon_004.png");
   load_texture (216, "data/images/weapons/weapon_005.png");

   load_texture (217, "data/images/shields/shield_000.png");
   load_texture (218, "data/images/shields/shield_001.png");
   load_texture (219, "data/images/shields/shield_002.png");
   load_texture (220, "data/images/shields/shield_003.png");
   load_texture (221, "data/images/shields/shield_004.png");

   load_texture (222, "data/images/projectiles/projectile_000.png");
   load_texture (223, "data/images/projectiles/projectile_001.png");
   load_texture (224, "data/images/projectiles/projectile_002.png");
   load_texture (225, "data/images/projectiles/projectile_003.png");
   load_texture (226, "data/images/projectiles/projectile_004.png");
   load_texture (227, "data/images/projectiles/projectile_005.png");
   load_texture (228, "data/images/projectiles/projectile_006.png");
   load_texture (229, "data/images/projectiles/projectile_007.png");
   load_texture (230, "data/images/projectiles/projectile_008.png");
   load_texture (231, "data/images/projectiles/projectile_009.png");
   load_texture (232, "data/images/projectiles/projectile_010.png");
   load_texture (233, "data/images/projectiles/projectile_011.png");
   load_texture (234, "data/images/projectiles/projectile_012.png");
   load_texture (235, "data/images/projectiles/projectile_013.png");
   load_texture (236, "data/images/projectiles/projectile_014.png");
   load_texture (237, "data/images/projectiles/projectile_015.png");
   load_texture (238, "data/images/projectiles/projectile_016.png");
   load_texture (239, "data/images/projectiles/projectile_017.png");
   load_texture (240, "data/images/projectiles/projectile_018.png");
   load_texture (241, "data/images/projectiles/projectile_019.png");
   load_texture (242, "data/images/projectiles/projectile_020.png");
   load_texture (243, "data/images/projectiles/projectile_021.png");
   load_texture (244, "data/images/projectiles/projectile_022.png");
   load_texture (245, "data/images/projectiles/projectile_023.png");
   load_texture (246, "data/images/projectiles/projectile_024.png");
   load_texture (247, "data/images/projectiles/projectile_025.png");
   load_texture (248, "data/images/projectiles/projectile_026.png");
   load_texture (249, "data/images/projectiles/projectile_027.png");
   load_texture (250, "data/images/projectiles/projectile_028.png");
   load_texture (251, "data/images/projectiles/projectile_029.png");
   load_texture (252, "data/images/projectiles/projectile_030.png");

   load_texture (253, "data/images/ships/ship_000.png");
   load_texture (254, "data/images/ships/ship_001.png");
   load_texture (255, "data/images/ships/ship_002.png");
   load_texture (256, "data/images/ships/ship_003.png");
   load_texture (257, "data/images/ships/ship_004.png");
   load_texture (258, "data/images/ships/ship_005.png");
   load_texture (259, "data/images/ships/ship_006.png");
   load_texture (260, "data/images/ships/ship_007.png");
   load_texture (261, "data/images/ships/ship_008.png");
   load_texture (262, "data/images/ships/ship_009.png");
   load_texture (263, "data/images/ships/ship_010.png");
   load_texture (264, "data/images/ships/ship_011.png");
   load_texture (265, "data/images/ships/ship_012.png");
   load_texture (266, "data/images/ships/ship_013.png");
   load_texture (267, "data/images/ships/ship_014.png");
   load_texture (268, "data/images/ships/ship_015.png");
   load_texture (269, "data/images/ships/ship_016.png");
   load_texture (270, "data/images/ships/ship_017.png");
   load_texture (271, "data/images/ships/ship_018.png");
   load_texture (272, "data/images/ships/ship_019.png");
   load_texture (273, "data/images/ships/ship_020.png");
   load_texture (274, "data/images/ships/ship_021.png");
   load_texture (275, "data/images/ships/ship_022.png");
   load_texture (276, "data/images/ships/ship_023.png");
   load_texture (277, "data/images/ships/ship_024.png");
   load_texture (278, "data/images/ships/ship_025.png");

   load_texture (279, "data/images/thrusters/thruster_000.png");
   load_texture (280, "data/images/thrusters/thruster_001.png");
   load_texture (281, "data/images/thrusters/thruster_002.png");

   load_texture (282, "data/images/misc/selection_box.png");
   load_texture (283, "data/images/misc/none.png");
   load_texture (284, "data/images/misc/locked.png");
   load_texture (285, "data/images/misc/weapon_bar.png");
   load_texture (286, "data/images/misc/shield_bar.png");
   load_texture (287, "data/images/misc/thruster_bar.png");
   load_texture (288, "data/images/misc/game_paused.png");
   load_texture (289, "data/images/misc/game_saved.png");
   load_texture (290, "data/images/misc/game_loaded.png");

   load_texture (291, "data/images/powerups/health_powerup.png");
   load_texture (292, "data/images/powerups/shield_lvlup_powerup.png");
   load_texture (293, "data/images/powerups/shield_new_powerup.png");
   load_texture (294, "data/images/powerups/thruster_lvlup_powerup.png");
   load_texture (295, "data/images/powerups/thruster_new_powerup.png");
   load_texture (296, "data/images/powerups/weapon_lvlup_powerup.png");
   load_texture (297, "data/images/powerups/weapon_new_powerup.png");

   load_texture (298, "data/images/menu/achievements.png");
   load_texture (299, "data/images/menu/achievements_highlighted.png");
   load_texture (300, "data/images/menu/score.png");
   load_texture (301, "data/images/menu/score_highlighted.png");
   load_texture (302, "data/images/menu/kills.png");
   load_texture (303, "data/images/menu/kills_highlighted.png");
   load_texture (304, "data/images/menu/grey_star.png");
   load_texture (305, "data/images/menu/bronze_star.png");
   load_texture (306, "data/images/menu/silver_star.png");
   load_texture (307, "data/images/menu/gold_star.png");
   load_texture (308, "data/images/misc/kills_achievement.png");
   load_texture (309, "data/images/misc/score_achievement.png");

   load_texture (310, "data/images/misc/actinium_shields.png");
   load_texture (311, "data/images/misc/blasters.png");
   load_texture (312, "data/images/misc/burst_lasers.png");
   load_texture (313, "data/images/misc/chain_guns.png");
   load_texture (314, "data/images/misc/convolution_thrusters.png");
   load_texture (315, "data/images/misc/health.png");
   load_texture (316, "data/images/misc/ion_cannons.png");
   load_texture (317, "data/images/misc/iridium_shileds.png");
   load_texture (318, "data/images/misc/maelstrom_thrusters.png");
   load_texture (319, "data/images/misc/plasma_rockets.png");
   load_texture (320, "data/images/misc/rail_turrets.png");
   load_texture (321, "data/images/misc/rubidium_shields.png");
   load_texture (322, "data/images/misc/seismic_thrusters.png");
   load_texture (323, "data/images/misc/shield_level_up.png");
   load_texture (324, "data/images/misc/tantalum_shields.png");
   load_texture (325, "data/images/misc/terbium_shields.png");
   load_texture (326, "data/images/misc/thrusters_level_up.png");
   load_texture (327, "data/images/misc/vortex_thrusters.png");
   load_texture (328, "data/images/misc/weapon_level_up.png");

   load_texture (329, "data/images/menu/game_over.png");
   load_texture (330, "data/images/menu/logo_red.png");
   load_texture (331, "data/images/menu/press_enter_for_the_main_menu.png");
   load_texture (332, "data/images/misc/explosion_001.png");
   load_texture (333, "data/images/menu/level_completed.png");
   load_texture (334, "data/images/menu/enter_for_next_level.png");
   load_texture (335, "data/images/menu/new_level_unlocked.png");
   load_texture (336, "data/images/thrusters/thruster_003.png");
   load_texture (337, "data/images/powerups/coin_powerup.png");
   load_texture (338, "data/images/powerups/wexp_powerup.png");
   load_texture (339, "data/images/misc/credits_00.png");

   return(0);
};

int load_texture (int texture_number, const char File_Name[])
{
   SDL_Surface *surface;
   GLenum       texture_format;
   GLint        nOfColors;

   if ((surface = IMG_Load(File_Name)))
   {
      if ((surface->w & (surface->w - 1)) != 0 );
      if ((surface->h & (surface->h - 1)) != 0 );
      nOfColors = surface->format->BytesPerPixel;
      if (nOfColors == 4)
      {
         if (surface->format->Rmask == 0x000000ff) texture_format = GL_RGBA;
         else texture_format = GL_BGRA;
      }
      else if (nOfColors == 3)
      {
         if (surface->format->Rmask == 0x000000ff) texture_format = GL_RGB;
         else texture_format = GL_BGR;
      }
      else   Log_File(App_Logf,"warning: the image is not truecolor..  this will probably break");
      glGenTextures( 1, &texture[texture_number].texture);
      glBindTexture( GL_TEXTURE_2D, texture[texture_number].texture);
      glEnable(GL_BLEND);
      glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
      glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
      glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
      glTexImage2D( GL_TEXTURE_2D, 0, nOfColors, surface->w, surface->h, 0, texture_format, GL_UNSIGNED_BYTE, surface->pixels );
   }
   else
   {
      Log_File(App_Logf,"SDL could not load image.");
//      Log_File(App_Logf,File_Name.);
      SDL_Quit();
      return 1;
   }
   if ( surface ) SDL_FreeSurface( surface );
}
