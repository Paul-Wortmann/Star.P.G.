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

#include "core/core.hpp"
#include "achievements.hpp"
#include "load_resources.hpp"
#include "game.hpp"
#include "misc.hpp"

extern  sound_type       sound;
extern  music_type       music;
extern  texture_type     texture;
extern  game_type        game_o;
extern  game_class       game;

void init_achievements(void)
{
    game_o.achivement.score                  = 0;
    game_o.achivement.kills                  = 0;
    game_o.achivement.score_level_1          = 625;
    game_o.achivement.score_level_2          = 1250;
    game_o.achivement.score_level_3          = 2500;
    game_o.achivement.score_level_4          = 5000;
    game_o.achivement.score_level_5          = 10000;
    game_o.achivement.score_level_6          = 20000;
    game_o.achivement.score_level_7          = 40000;
    game_o.achivement.kills_level_1          = 128;
    game_o.achivement.kills_level_2          = 256;
    game_o.achivement.kills_level_3          = 512;
    game_o.achivement.kills_level_4          = 1024;
    game_o.achivement.kills_level_5          = 2048;
    game_o.achivement.kills_level_6          = 4096;
    game_o.achivement.kills_level_7          = 8192;
};

void achievement_score_process(void)
{
   if (game_o.a_score.active) game_o.a_score.process();
   if ((game_o.score >= game_o.achivement.score_level_1) && (game_o.achivement.score < 1))
   {
      game_o.achivement.score = 1;
      game_o.a_score.spawn();
   };
   if ((game_o.score >= game_o.achivement.score_level_2) && (game_o.achivement.score < 2))
   {
      game_o.achivement.score = 2;
      game_o.a_score.spawn();
   };
   if ((game_o.score >= game_o.achivement.score_level_3) && (game_o.achivement.score < 3))
   {
      game_o.achivement.score = 3;
      game_o.a_score.spawn();
   };
   if ((game_o.score >= game_o.achivement.score_level_4) && (game_o.achivement.score < 4))
   {
      game_o.achivement.score = 4;
      game_o.a_score.spawn();
   };
   if ((game_o.score >= game_o.achivement.score_level_5) && (game_o.achivement.score < 5))
   {
      game_o.achivement.score = 5;
      game_o.a_score.spawn();
   };
   if ((game_o.score >= game_o.achivement.score_level_6) && (game_o.achivement.score < 6))
   {
      game_o.achivement.score = 6;
      game_o.a_score.spawn();
   };
   if ((game_o.score >= game_o.achivement.score_level_7) && (game_o.achivement.score < 7))
   {
      game_o.achivement.score = 7;
      game_o.a_score.spawn();
   };
};


void achievement_kills_process(void)
{
   if (game_o.a_kills.active) game_o.a_kills.process();
   if ((game_o.kills >= game_o.achivement.kills_level_1) && (game_o.achivement.kills < 1))
   {
      game_o.achivement.kills = 1;
      game_o.a_kills.spawn();
   };
   if ((game_o.kills >= game_o.achivement.kills_level_2) && (game_o.achivement.kills < 2))
   {
      game_o.achivement.kills = 2;
      game_o.a_kills.spawn();
   };
   if ((game_o.kills >= game_o.achivement.kills_level_3) && (game_o.achivement.kills < 3))
   {
      game_o.achivement.kills = 3;
      game_o.a_kills.spawn();
   };
   if ((game_o.kills >= game_o.achivement.kills_level_4) && (game_o.achivement.kills < 4))
   {
      game_o.achivement.kills = 4;
      game_o.a_kills.spawn();
   };
   if ((game_o.kills >= game_o.achivement.kills_level_5) && (game_o.achivement.kills < 5))
   {
      game_o.achivement.kills = 5;
      game_o.a_kills.spawn();
   };
   if ((game_o.kills >= game_o.achivement.kills_level_6) && (game_o.achivement.kills < 6))
   {
      game_o.achivement.kills = 6;
      game_o.a_kills.spawn();
   };
   if ((game_o.kills >= game_o.achivement.kills_level_7) && (game_o.achivement.kills < 7))
   {
      game_o.achivement.kills = 7;
      game_o.a_kills.spawn();
   };
};

