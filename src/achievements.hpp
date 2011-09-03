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
 * @date 2011-09-03
 */

#ifndef ACHIEVEMENTS_H
#define ACHIEVEMENTS_H

struct achivement_type
{
   int score;
   int score_level_1;
   int score_level_2;
   int score_level_3;
   int score_level_4;
   int score_level_5;
   int score_level_6;
   int score_level_7;
   int kills;
   int kills_level_1;
   int kills_level_2;
   int kills_level_3;
   int kills_level_4;
   int kills_level_5;
   int kills_level_6;
   int kills_level_7;
};

void init_achievements(void);
void achievement_score_process(void);
void achievement_kills_process(void);

#endif //ACHIEVEMENTS_H


