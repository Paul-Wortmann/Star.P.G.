/**
 * Copyright (C) 2010-2012 Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
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

#ifndef NPC_H
#define NPC_H

#include "bullets.hpp"

const int   MAX_ENEMYS                   = 32;
const int   MAX_NPCS                     = 32;

class enemy_class
{
    public:
        std::string   name;
        int           image;
        int           sound;
        float         health;
        float         speed;
        float         max_speed;
        float         acceleration;
        float         start_angle;
        int           movement;
        int           weapon_1;
        int           weapon_2;
        int           projectiles;
        float         width;
        float         height;
        void          load(std::string file_name);
};

struct npc_type
{
    bool          active;
    int           damaged;
    int           type_npc;
    int           weapon_1;
    int           weapon_2;
    int           projectiles;
    float         x_pos;
    float         y_pos;
    int           formation_wave_no;
    float         formation_wave_size;
    float         formation_wave_axis;
    float         formation_target;
    int           formation_type;
    float         formation_ofset_x;
    float         formation_ofset_y;
    float         health;
    float         width;
    float         height;
    float         x_speed;
    float         y_speed;
    float         max_speed;
    float         acceleration;
    float         angle;
    int           movement;
    int           x_direction;
    int           y_direction;
    bullet_type   bullet [MAX_BULLETS];
    bullet_type   bullet2[MAX_BULLETS];
};

struct active_npc_type
{
   bool          active;
   int           number;
};

void init_enemies         (bool re_init);
int  kill_active_npcs     (void);
int  init_active_npcs     (void);
int  check_active_npcs    (void);
int  sort_active_npcs     (void);
int  add_active_npc       (int npc_num);
int  del_active_npc       (int npc_num);
int  spawn_npc            (float x_position, float y_position, int type_npc, int type_formation, float x_formation_ofset, float y_formation_ofset);
int  kill_npc             (int npc_num);
int  init_npcs            (int type_npc);
int  proccess_npcs        (void);
int  spawn_npc_bullet_num (int npc_num, int weapon, int npc_bullet_num, int location);
int  spawn_npc_bullet     (int npc_num, int weapon, int location);
int  kill_npc_bullet      (int npc_num, int weapon, int npc_bullet_num);
int  init_npc_bullets     (void);
int  proccess_npc_bullets (void);
int  init_npc_bullets2    (void);
int  proccess_npc_bullets2(void);
void draw_npcs            (void);

#endif //NPC_H

