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

#ifndef PROJECTILES_H
#define PROJECTILES_H

#include <string>

const int   MAX_PROJECTILES = 48;

class projectile_class
{
    public:
    std::wstring name;
    bool         active;
    int          level;
    float        experience;
    float        level_1;
    float        level_2;
    float        level_3;
    float        level_4;
    float        level_5;
    float        level_6;
    int          image;
    float        width;
    float        height;
    int          sound;
    float        damage;
    float        health;
    float        speed;
    int          rate_of_fire;
    int          movement;
    float        wave_size;
    float        wave_velocity;

    void         init(void);
    void         init(std::wstring name,bool active,int exp,int lvl,float l1,float l2,float l3,float l4,float l5,float l6,int img,int snd,float dmg,float spd,float hlth,int rof,int mov,float ws,float wv,float s);
    void         init(bool active,int exp,int lvl);
    void         load(std::string file_name);
};

void init_projectiles(bool re_init);

#endif //PROJECTILES_H
