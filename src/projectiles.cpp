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

#include "projectiles.hpp"
#include "game.hpp"

extern   game_type game_o;

void projectile_class::init(void)
{
    projectile_class::name          = L"data_not_set";
    projectile_class::active        = false;
    projectile_class::level         = 0;
    projectile_class::experience    = 0;
    projectile_class::level_1       = 1024.0f;
    projectile_class::level_2       = 2048.0f;
    projectile_class::level_3       = 4096.0f;
    projectile_class::image         = 222;
    projectile_class::sound         = 7;
    projectile_class::damage        = 2.5f;
    projectile_class::speed         = 0.003f;
    projectile_class::health        = 10.0f;
    projectile_class::rate_of_fire  = 25;
    projectile_class::movement      = 3;
    projectile_class::wave_size     = 0.125f;
    projectile_class::wave_velocity = 0.00015f;
    projectile_class::size          = 0.075f;
};

void projectile_class::init(std::wstring name,bool active,int exp,int lvl,float l1,float l2,float l3,float l4,float l5,float l6,int img,int snd,float dmg,float spd,float hlth,int rof,int mov,float ws,float wv,float s)
{
    projectile_class::name          = name;
    projectile_class::active        = active;
    projectile_class::level         = lvl;
    projectile_class::experience    = exp;
    projectile_class::level_1       = l1;
    projectile_class::level_2       = l2;
    projectile_class::level_3       = l3;
    projectile_class::level_4       = l4;
    projectile_class::level_5       = l5;
    projectile_class::level_6       = l6;
    projectile_class::image         = img;
    projectile_class::sound         = snd;
    projectile_class::damage        = dmg;
    projectile_class::speed         = spd;
    projectile_class::health        = hlth;
    projectile_class::rate_of_fire  = rof;
    projectile_class::movement      = mov;
    projectile_class::wave_size     = ws;
    projectile_class::wave_velocity = wv;
    projectile_class::size          = s;
};

void projectile_class::init(bool active,int exp,int lvl)
{
    projectile_class::active        = active;
    projectile_class::level         = lvl;
    projectile_class::experience    = exp;
};

void init_projectiles(bool re_init)
{
    if (re_init)
    {
        for (int count = 0; count <= MAX_PROJECTILES; count++)
        {
            game_o.projectile[count].init(false,0,0);
        }
        game_o.projectile[ 0].active            = true;
    }
    else
    {
    //game_o.projectile[ 0].init(L"Blasters",true,0,0,1024.0f,2048.0f,4096.0f,8192.0f,16384.0f,32768.0f,222,7,2.5f,0.003f,10.0f,25,3,0.125f,0.00015f,0.075f);

   game_o.projectile[ 0].name          = L"Blasters";
   game_o.projectile[ 0].active        = true;
   game_o.projectile[ 0].level         = 0;
   game_o.projectile[ 0].experience    = 0;
   game_o.projectile[ 0].level_1       = 1024.0f;
   game_o.projectile[ 0].level_2       = 2048.0f;
   game_o.projectile[ 0].level_3       = 4096.0f;
   game_o.projectile[ 0].image         = 222;
   game_o.projectile[ 0].sound         = 7;
   game_o.projectile[ 0].damage        = 2.5f;
   game_o.projectile[ 0].speed         = 0.003f;
   game_o.projectile[ 0].health        = 10;
   game_o.projectile[ 0].rate_of_fire  = 25;
   game_o.projectile[ 0].movement      = 3;
   game_o.projectile[ 0].wave_size     = 0.125f;
   game_o.projectile[ 0].wave_velocity = 0.00015f;
   game_o.projectile[ 0].size          = 0.075f;

   game_o.projectile[ 1].name          = L"Chain Guns";
   game_o.projectile[ 1].active        = false;
   game_o.projectile[ 1].level         = 0;
   game_o.projectile[ 1].experience    = 0;
   game_o.projectile[ 1].level_1       = 2048.0f;
   game_o.projectile[ 1].level_2       = 4096.0f;
   game_o.projectile[ 1].level_3       = 8192.0f;
   game_o.projectile[ 1].image         = 223;
   game_o.projectile[ 1].sound         = 8;
   game_o.projectile[ 1].damage        = 4;
   game_o.projectile[ 1].speed         = 0.015f;
   game_o.projectile[ 1].health        = 10;
   game_o.projectile[ 1].rate_of_fire  = 23;
   game_o.projectile[ 1].movement      = 2;
   game_o.projectile[ 1].wave_size     = 0.125f;
   game_o.projectile[ 1].wave_velocity = 0.0035f;
   game_o.projectile[ 1].size          = 0.05f;

   game_o.projectile[ 2].name          = L"Burst Lasers";
   game_o.projectile[ 2].active        = false;
   game_o.projectile[ 2].level         = 0;
   game_o.projectile[ 2].experience    = 0;
   game_o.projectile[ 2].level_1       = 4096.0f;
   game_o.projectile[ 2].level_2       = 8192.0f;
   game_o.projectile[ 2].level_3       = 16384.0f;
   game_o.projectile[ 2].image         = 224;
   game_o.projectile[ 2].sound         = 9;
   game_o.projectile[ 2].damage        = 7;
   game_o.projectile[ 2].speed         = 0.005f;
   game_o.projectile[ 2].health        = 10;
   game_o.projectile[ 2].rate_of_fire  = 21;
   game_o.projectile[ 2].movement      = 0;
   game_o.projectile[ 2].wave_size     = 0.125f;
   game_o.projectile[ 2].wave_velocity = 0.00015f;
   game_o.projectile[ 2].size          = 0.05f;

   game_o.projectile[ 3].name          = L"Rail Turrets";
   game_o.projectile[ 3].active        = false;
   game_o.projectile[ 3].level         = 0;
   game_o.projectile[ 3].experience    = 0;
   game_o.projectile[ 3].level_1       = 8192.0f;
   game_o.projectile[ 3].level_2       = 16384.0f;
   game_o.projectile[ 3].level_3       = 32768.0f;
   game_o.projectile[ 3].image         = 225;
   game_o.projectile[ 3].sound         = 10;
   game_o.projectile[ 3].damage        = 8;
   game_o.projectile[ 3].speed         = 0.02f;
   game_o.projectile[ 3].health        = 10;
   game_o.projectile[ 3].rate_of_fire  = 19;
   game_o.projectile[ 3].movement      = 0;
   game_o.projectile[ 3].wave_size     = 0.125f;
   game_o.projectile[ 3].wave_velocity = 0.0035f;
   game_o.projectile[ 3].size          = 0.05f;

   game_o.projectile[ 4].name          = L"Plasma Rockets";
   game_o.projectile[ 4].active        = false;
   game_o.projectile[ 4].level         = 0;
   game_o.projectile[ 4].experience    = 0;
   game_o.projectile[ 4].level_1       = 16384.0f;
   game_o.projectile[ 4].level_2       = 32768.0f;
   game_o.projectile[ 4].level_3       = 65536.0f;
   game_o.projectile[ 4].image         = 226;
   game_o.projectile[ 4].sound         = 11;
   game_o.projectile[ 4].damage        = 9;
   game_o.projectile[ 4].speed         = 0.025f;
   game_o.projectile[ 4].health        = 10;
   game_o.projectile[ 4].rate_of_fire  = 17;
   game_o.projectile[ 4].movement      = 1;
   game_o.projectile[ 4].wave_size     = 0.125f;
   game_o.projectile[ 4].wave_velocity = 0.0035f;
   game_o.projectile[ 4].size          = 0.05f;

   game_o.projectile[ 5].name          = L"Ion Cannons";
   game_o.projectile[ 5].active        = false;
   game_o.projectile[ 5].level         = 0;
   game_o.projectile[ 5].experience    = 0;
   game_o.projectile[ 5].level_1       = 32768.0f;
   game_o.projectile[ 5].level_2       = 65536.0f;
   game_o.projectile[ 5].level_3       = 131072.0f;
   game_o.projectile[ 5].image         = 227;
   game_o.projectile[ 5].sound         = 12;
   game_o.projectile[ 5].damage        = 10;
   game_o.projectile[ 5].speed         = 0.03f;
   game_o.projectile[ 5].health        = 10;
   game_o.projectile[ 5].rate_of_fire  = 15;
   game_o.projectile[ 5].movement      = 0;
   game_o.projectile[ 5].wave_size     = 0.125f;
   game_o.projectile[ 5].wave_velocity = 0.0035f;
   game_o.projectile[ 5].size          = 0.05f;

   game_o.projectile[ 6].name          = L"Enemy Weapon";
   game_o.projectile[ 6].active        = false;
   game_o.projectile[ 6].level         = 0;
   game_o.projectile[ 6].experience    = 0;
   game_o.projectile[ 6].level_1       = 0.0f;
   game_o.projectile[ 6].level_2       = 0.0f;
   game_o.projectile[ 6].level_3       = 0.0f;
   game_o.projectile[ 6].image         = 228;
   game_o.projectile[ 6].sound         = 23;
   game_o.projectile[ 6].damage        = 0.0125f;
   game_o.projectile[ 6].speed         = 0.0075f;
   game_o.projectile[ 6].health        = 5;
   game_o.projectile[ 6].rate_of_fire  = 5;
   game_o.projectile[ 6].movement      = 0;
   game_o.projectile[ 6].wave_size     = 0.125f;
   game_o.projectile[ 6].wave_velocity = 0.0035f;
   game_o.projectile[ 6].size          = 0.05f;

   game_o.projectile[ 7].name          = L"Enemy Weapon";
   game_o.projectile[ 7].active        = false;
   game_o.projectile[ 7].level         = 0;
   game_o.projectile[ 7].experience    = 0;
   game_o.projectile[ 7].level_1       = 0.0f;
   game_o.projectile[ 7].level_2       = 0.0f;
   game_o.projectile[ 7].level_3       = 0.0f;
   game_o.projectile[ 7].image         = 229;
   game_o.projectile[ 7].sound         = 24;
   game_o.projectile[ 7].damage        = 0.025f;
   game_o.projectile[ 7].speed         = 0.0080f;
   game_o.projectile[ 7].health        = 5;
   game_o.projectile[ 7].rate_of_fire  = 5;
   game_o.projectile[ 7].movement      = 0;
   game_o.projectile[ 7].wave_size     = 0.125f;
   game_o.projectile[ 7].wave_velocity = 0.0035f;
   game_o.projectile[ 7].size          = 0.05f;

   game_o.projectile[ 8].name          = L"Enemy Weapon";
   game_o.projectile[ 8].active        = false;
   game_o.projectile[ 8].level         = 0;
   game_o.projectile[ 8].experience    = 0;
   game_o.projectile[ 8].level_1       = 0.0f;
   game_o.projectile[ 8].level_2       = 0.0f;
   game_o.projectile[ 8].level_3       = 0.0f;
   game_o.projectile[ 8].image         = 230;
   game_o.projectile[ 8].sound         = 25;
   game_o.projectile[ 8].damage        = 0.0375f;
   game_o.projectile[ 8].speed         = 0.0075f;
   game_o.projectile[ 8].health        = 5;
   game_o.projectile[ 8].rate_of_fire  = 5;
   game_o.projectile[ 8].movement      = 0;
   game_o.projectile[ 8].wave_size     = 0.125f;
   game_o.projectile[ 8].wave_velocity = 0.0035f;
   game_o.projectile[ 8].size          = 0.05f;

   game_o.projectile[ 9].name          = L"Enemy Weapon";
   game_o.projectile[ 9].active        = false;
   game_o.projectile[ 9].level         = 0;
   game_o.projectile[ 9].experience    = 0;
   game_o.projectile[ 9].level_1       = 0.0f;
   game_o.projectile[ 9].level_2       = 0.0f;
   game_o.projectile[ 9].level_3       = 0.0f;
   game_o.projectile[ 9].image         = 231;
   game_o.projectile[ 9].sound         = 26;
   game_o.projectile[ 9].damage        = 0.05f;
   game_o.projectile[ 9].speed         = 0.0075f;
   game_o.projectile[ 9].health        = 10;
   game_o.projectile[ 9].rate_of_fire  = 5;
   game_o.projectile[ 9].movement      = 2;
   game_o.projectile[ 9].wave_size     = 0.125f;
   game_o.projectile[ 9].wave_velocity = 0.0035f;
   game_o.projectile[ 9].size          = 0.05f;

   game_o.projectile[10].name          = L"Enemy Weapon";
   game_o.projectile[10].active        = false;
   game_o.projectile[10].level         = 0;
   game_o.projectile[10].experience    = 0;
   game_o.projectile[10].level_1       = 0.0f;
   game_o.projectile[10].level_2       = 0.0f;
   game_o.projectile[10].level_3       = 0.0f;
   game_o.projectile[10].image         = 232;
   game_o.projectile[10].sound         = 27;
   game_o.projectile[10].damage        = 0.0625f;
   game_o.projectile[10].speed         = 0.0075f;
   game_o.projectile[10].health        = 5;
   game_o.projectile[10].rate_of_fire  = 5;
   game_o.projectile[10].movement      = 2;
   game_o.projectile[10].wave_size     = 0.125f;
   game_o.projectile[10].wave_velocity = 0.0035f;
   game_o.projectile[10].size          = 0.05f;

   game_o.projectile[11].name          = L"Enemy Weapon";
   game_o.projectile[11].active        = false;
   game_o.projectile[11].level         = 0;
   game_o.projectile[11].experience    = 0;
   game_o.projectile[11].level_1       = 0.0f;
   game_o.projectile[11].level_2       = 0.0f;
   game_o.projectile[11].level_3       = 0.0f;
   game_o.projectile[11].image         = 233;
   game_o.projectile[11].sound         = 28;
   game_o.projectile[11].damage        = 0.075f;
   game_o.projectile[11].speed         = 0.0075f;
   game_o.projectile[11].health        = 5;
   game_o.projectile[11].rate_of_fire  = 5;
   game_o.projectile[11].movement      = 2;
   game_o.projectile[11].wave_size     = 0.085f;
   game_o.projectile[11].wave_velocity = 0.0065f;
   game_o.projectile[11].size          = 0.05f;

   game_o.projectile[12].name          = L"Enemy Weapon";
   game_o.projectile[12].active        = false;
   game_o.projectile[12].level         = 0;
   game_o.projectile[12].experience    = 0;
   game_o.projectile[12].level_1       = 0.0f;
   game_o.projectile[12].level_2       = 0.0f;
   game_o.projectile[12].level_3       = 0.0f;
   game_o.projectile[12].image         = 234;
   game_o.projectile[12].sound         = 29;
   game_o.projectile[12].damage        = 0.0875f;
   game_o.projectile[12].speed         = 0.0075f;
   game_o.projectile[12].health        = 5;
   game_o.projectile[12].rate_of_fire  = 5;
   game_o.projectile[12].movement      = 2;
   game_o.projectile[12].wave_size     = 0.125f;
   game_o.projectile[12].wave_velocity = 0.0035f;
   game_o.projectile[12].size          = 0.05f;

   game_o.projectile[13].name          = L"Enemy Weapon";
   game_o.projectile[13].active        = false;
   game_o.projectile[13].level         = 0;
   game_o.projectile[13].experience    = 0;
   game_o.projectile[13].level_1       = 0.0f;
   game_o.projectile[13].level_2       = 0.0f;
   game_o.projectile[13].level_3       = 0.0f;
   game_o.projectile[13].image         = 235;
   game_o.projectile[13].sound         = 30;
   game_o.projectile[13].damage        = 0.500f;
   game_o.projectile[13].speed         = 0.0175f;
   game_o.projectile[13].health        = 25;
   game_o.projectile[13].rate_of_fire  = 5;
   game_o.projectile[13].movement      = 2;
   game_o.projectile[13].wave_size     = 0.125f;
   game_o.projectile[13].wave_velocity = 0.0035f;
   game_o.projectile[13].size          = 0.05f;

   game_o.projectile[14].name          = L"Enemy Weapon";
   game_o.projectile[14].active        = false;
   game_o.projectile[14].level         = 0;
   game_o.projectile[14].experience    = 0;
   game_o.projectile[14].level_1       = 0.0f;
   game_o.projectile[14].level_2       = 0.0f;
   game_o.projectile[14].level_3       = 0.0f;
   game_o.projectile[14].image         = 236;
   game_o.projectile[14].sound         = 31;
   game_o.projectile[14].damage        = 0.1125f;
   game_o.projectile[14].speed         = 0.0075f;
   game_o.projectile[14].health        = 5;
   game_o.projectile[14].rate_of_fire  = 5;
   game_o.projectile[14].movement      = 0;
   game_o.projectile[14].wave_size     = 0.125f;
   game_o.projectile[14].wave_velocity = 0.0035f;
   game_o.projectile[14].size          = 0.05f;

   game_o.projectile[15].name          = L"Enemy Weapon";
   game_o.projectile[15].active        = false;
   game_o.projectile[15].level         = 0;
   game_o.projectile[15].experience    = 0;
   game_o.projectile[15].level_1       = 0.0f;
   game_o.projectile[15].level_2       = 0.0f;
   game_o.projectile[15].level_3       = 0.0f;
   game_o.projectile[15].image         = 237;
   game_o.projectile[15].sound         = 32;
   game_o.projectile[15].damage        = 0.125f;
   game_o.projectile[15].speed         = 0.0075f;
   game_o.projectile[15].health        = 5;
   game_o.projectile[15].rate_of_fire  = 5;
   game_o.projectile[15].movement      = 1;
   game_o.projectile[15].wave_size     = 0.125f;
   game_o.projectile[15].wave_velocity = 0.0035f;
   game_o.projectile[15].size          = 0.05f;

   game_o.projectile[16].name          = L"Enemy Weapon";
   game_o.projectile[16].active        = false;
   game_o.projectile[16].level         = 0;
   game_o.projectile[16].experience    = 0;
   game_o.projectile[16].level_1       = 0.0f;
   game_o.projectile[16].level_2       = 0.0f;
   game_o.projectile[16].level_3       = 0.0f;
   game_o.projectile[16].image         = 238;
   game_o.projectile[16].sound         = 33;
   game_o.projectile[16].damage        = 0.1375f;
   game_o.projectile[16].speed         = 0.0075f;
   game_o.projectile[16].health        = 5;
   game_o.projectile[16].rate_of_fire  = 5;
   game_o.projectile[16].movement      = 0;
   game_o.projectile[16].wave_size     = 0.125f;
   game_o.projectile[16].wave_velocity = 0.0035f;
   game_o.projectile[16].size          = 0.05f;

   game_o.projectile[17].name          = L"Enemy Weapon";
   game_o.projectile[17].active        = false;
   game_o.projectile[17].level         = 0;
   game_o.projectile[17].experience    = 0;
   game_o.projectile[17].level_1       = 0.0f;
   game_o.projectile[17].level_2       = 0.0f;
   game_o.projectile[17].level_3       = 0.0f;
   game_o.projectile[17].image         = 239;
   game_o.projectile[17].sound         = 34;
   game_o.projectile[17].damage        = 0.75f;
   game_o.projectile[17].speed         = 0.0175f;
   game_o.projectile[17].health        = 5;
   game_o.projectile[17].rate_of_fire  = 5;
   game_o.projectile[17].movement      = 1;
   game_o.projectile[17].wave_size     = 0.125f;
   game_o.projectile[17].wave_velocity = 0.0035f;
   game_o.projectile[17].size          = 0.05f;

   game_o.projectile[18].name          = L"Enemy Weapon";
   game_o.projectile[18].active        = false;
   game_o.projectile[18].level         = 0;
   game_o.projectile[18].experience    = 0;
   game_o.projectile[18].level_1       = 0.0f;
   game_o.projectile[18].level_2       = 0.0f;
   game_o.projectile[18].level_3       = 0.0f;
   game_o.projectile[18].image         = 240;
   game_o.projectile[18].sound         = 35;
   game_o.projectile[18].damage        = 0.1625f;
   game_o.projectile[18].speed         = 0.0075f;
   game_o.projectile[18].health        = 5;
   game_o.projectile[18].rate_of_fire  = 5;
   game_o.projectile[18].movement      = 1;
   game_o.projectile[18].wave_size     = 0.125f;
   game_o.projectile[18].wave_velocity = 0.0035f;
   game_o.projectile[18].size          = 0.05f;

   game_o.projectile[19].name          = L"Enemy Weapon";
   game_o.projectile[19].active        = false;
   game_o.projectile[19].level         = 0;
   game_o.projectile[19].experience    = 0;
   game_o.projectile[19].level_1       = 0.0f;
   game_o.projectile[19].level_2       = 0.0f;
   game_o.projectile[19].level_3       = 0.0f;
   game_o.projectile[19].image         = 241;
   game_o.projectile[19].sound         = 36;
   game_o.projectile[19].damage        = 0.175f;
   game_o.projectile[19].speed         = 0.0075f;
   game_o.projectile[19].health        = 5;
   game_o.projectile[19].rate_of_fire  = 5;
   game_o.projectile[19].movement      = 0;
   game_o.projectile[19].wave_size     = 0.125f;
   game_o.projectile[19].wave_velocity = 0.0035f;
   game_o.projectile[19].size          = 0.05f;

   game_o.projectile[20].name          = L"Enemy Weapon";
   game_o.projectile[20].active        = false;
   game_o.projectile[20].level         = 0;
   game_o.projectile[20].experience    = 0;
   game_o.projectile[20].level_1       = 0.0f;
   game_o.projectile[20].level_2       = 0.0f;
   game_o.projectile[20].level_3       = 0.0f;
   game_o.projectile[20].image         = 242;
   game_o.projectile[20].sound         = 37;
   game_o.projectile[20].damage        = 0.1875f;
   game_o.projectile[20].speed         = 0.0075f;
   game_o.projectile[20].health        = 5;
   game_o.projectile[20].rate_of_fire  = 5;
   game_o.projectile[20].movement      = 0;
   game_o.projectile[20].wave_size     = 0.125f;
   game_o.projectile[20].wave_velocity = 0.0035f;
   game_o.projectile[20].size          = 0.05f;

   game_o.projectile[21].name          = L"Enemy Weapon";
   game_o.projectile[21].active        = false;
   game_o.projectile[21].level         = 0;
   game_o.projectile[21].experience    = 0;
   game_o.projectile[21].level_1       = 0.0f;
   game_o.projectile[21].level_2       = 0.0f;
   game_o.projectile[21].level_3       = 0.0f;
   game_o.projectile[21].image         = 243;
   game_o.projectile[21].sound         = 38;
   game_o.projectile[21].damage        = 0.86f;
   game_o.projectile[21].speed         = 0.0225f;
   game_o.projectile[21].health        = 5;
   game_o.projectile[21].rate_of_fire  = 3;
   game_o.projectile[21].movement      = 3;
   game_o.projectile[21].wave_size     = 0.125f;
   game_o.projectile[21].wave_velocity = 0.0035f;
   game_o.projectile[21].size          = 0.05f;

   game_o.projectile[22].name          = L"Enemy Weapon";
   game_o.projectile[22].active        = false;
   game_o.projectile[22].level         = 0;
   game_o.projectile[22].experience    = 0;
   game_o.projectile[22].level_1       = 0.0f;
   game_o.projectile[22].level_2       = 0.0f;
   game_o.projectile[22].level_3       = 0.0f;
   game_o.projectile[22].image         = 244;
   game_o.projectile[22].sound         = 39;
   game_o.projectile[22].damage        = 0.2125f;
   game_o.projectile[22].speed         = 0.0075f;
   game_o.projectile[22].health        = 5;
   game_o.projectile[22].rate_of_fire  = 5;
   game_o.projectile[22].movement      = 0;
   game_o.projectile[22].wave_size     = 0.125f;
   game_o.projectile[22].wave_velocity = 0.0035f;
   game_o.projectile[22].size          = 0.05f;

   game_o.projectile[23].name          = L"Enemy Weapon";
   game_o.projectile[23].active        = false;
   game_o.projectile[23].level         = 0;
   game_o.projectile[23].experience    = 0;
   game_o.projectile[23].level_1       = 0.0f;
   game_o.projectile[23].level_2       = 0.0f;
   game_o.projectile[23].level_3       = 0.0f;
   game_o.projectile[23].image         = 245;
   game_o.projectile[23].sound         = 40;
   game_o.projectile[23].damage        = 0.225f;
   game_o.projectile[23].speed         = 0.0075f;
   game_o.projectile[23].health        = 5;
   game_o.projectile[23].rate_of_fire  = 5;
   game_o.projectile[23].movement      = 0;
   game_o.projectile[23].wave_size     = 0.125f;
   game_o.projectile[23].wave_velocity = 0.0035f;
   game_o.projectile[23].size          = 0.05f;

   game_o.projectile[24].name          = L"Enemy Weapon";
   game_o.projectile[24].active        = false;
   game_o.projectile[24].level         = 0;
   game_o.projectile[24].experience    = 0;
   game_o.projectile[24].level_1       = 0.0f;
   game_o.projectile[24].level_2       = 0.0f;
   game_o.projectile[24].level_3       = 0.0f;
   game_o.projectile[24].image         = 246;
   game_o.projectile[24].sound         = 41;
   game_o.projectile[24].damage        = 0.2375f;
   game_o.projectile[24].speed         = 0.0075f;
   game_o.projectile[24].health        = 5;
   game_o.projectile[24].rate_of_fire  = 5;
   game_o.projectile[24].movement      = 0;
   game_o.projectile[24].wave_size     = 0.125f;
   game_o.projectile[24].wave_velocity = 0.0035f;
   game_o.projectile[24].size          = 0.05f;

   game_o.projectile[25].name          = L"Enemy Weapon";
   game_o.projectile[25].active        = false;
   game_o.projectile[25].level         = 0;
   game_o.projectile[25].experience    = 0;
   game_o.projectile[25].level_1       = 0.0f;
   game_o.projectile[25].level_2       = 0.0f;
   game_o.projectile[25].level_3       = 0.0f;
   game_o.projectile[25].image         = 247;
   game_o.projectile[25].sound         = 42;
   game_o.projectile[25].damage        = 0.25f;
   game_o.projectile[25].speed         = 0.0075f;
   game_o.projectile[25].health        = 5;
   game_o.projectile[25].rate_of_fire  = 5;
   game_o.projectile[25].movement      = 0;
   game_o.projectile[25].wave_size     = 0.125f;
   game_o.projectile[25].wave_velocity = 0.0035f;
   game_o.projectile[25].size          = 0.05f;

   game_o.projectile[26].name          = L"Enemy Weapon";
   game_o.projectile[26].active        = false;
   game_o.projectile[26].level         = 0;
   game_o.projectile[26].experience    = 0;
   game_o.projectile[26].level_1       = 0.0f;
   game_o.projectile[26].level_2       = 0.0f;
   game_o.projectile[26].level_3       = 0.0f;
   game_o.projectile[26].image         = 248;
   game_o.projectile[26].sound         = 43;
   game_o.projectile[26].damage        = 0.2625f;
   game_o.projectile[26].speed         = 0.0075f;
   game_o.projectile[26].health        = 5;
   game_o.projectile[26].rate_of_fire  = 5;
   game_o.projectile[26].movement      = 0;
   game_o.projectile[26].wave_size     = 0.125f;
   game_o.projectile[26].wave_velocity = 0.0035f;
   game_o.projectile[26].size          = 0.05f;

   game_o.projectile[27].name          = L"Enemy Weapon";
   game_o.projectile[27].active        = false;
   game_o.projectile[27].level         = 0;
   game_o.projectile[27].experience    = 0;
   game_o.projectile[27].level_1       = 0.0f;
   game_o.projectile[27].level_2       = 0.0f;
   game_o.projectile[27].level_3       = 0.0f;
   game_o.projectile[27].image         = 249;
   game_o.projectile[27].sound         = 44;
   game_o.projectile[27].damage        = 0.275f;
   game_o.projectile[27].speed         = 0.0075f;
   game_o.projectile[27].health        = 5;
   game_o.projectile[27].rate_of_fire  = 5;
   game_o.projectile[27].movement      = 0;
   game_o.projectile[27].wave_size     = 0.125f;
   game_o.projectile[27].wave_velocity = 0.0035f;
   game_o.projectile[27].size          = 0.05f;

   game_o.projectile[28].name          = L"Enemy Weapon";
   game_o.projectile[28].active        = false;
   game_o.projectile[28].level         = 0;
   game_o.projectile[28].experience    = 0;
   game_o.projectile[28].level_1       = 0.0f;
   game_o.projectile[28].level_2       = 0.0f;
   game_o.projectile[28].level_3       = 0.0f;
   game_o.projectile[28].image         = 250;
   game_o.projectile[28].sound         = 45;
   game_o.projectile[28].damage        = 0.2875f;
   game_o.projectile[28].speed         = 0.0075f;
   game_o.projectile[28].health        = 5;
   game_o.projectile[28].rate_of_fire  = 5;
   game_o.projectile[28].movement      = 0;
   game_o.projectile[28].wave_size     = 0.125f;
   game_o.projectile[28].wave_velocity = 0.0035f;
   game_o.projectile[28].size          = 0.05f;

   game_o.projectile[29].name          = L"Enemy Weapon";
   game_o.projectile[29].active        = false;
   game_o.projectile[29].level         = 0;
   game_o.projectile[29].experience    = 0;
   game_o.projectile[29].level_1       = 0.0f;
   game_o.projectile[29].level_2       = 0.0f;
   game_o.projectile[29].level_3       = 0.0f;
   game_o.projectile[29].image         = 251;
   game_o.projectile[29].sound         = 46;
   game_o.projectile[29].damage        = 0.3f;
   game_o.projectile[29].speed         = 0.0075f;
   game_o.projectile[29].health        = 5;
   game_o.projectile[29].rate_of_fire  = 5;
   game_o.projectile[29].movement      = 0;
   game_o.projectile[29].wave_size     = 0.125f;
   game_o.projectile[29].wave_velocity = 0.0035f;
   game_o.projectile[29].size          = 0.05f;

   game_o.projectile[30].name          = L"Enemy Weapon";
   game_o.projectile[30].active        = false;
   game_o.projectile[30].level         = 0;
   game_o.projectile[30].experience    = 0;
   game_o.projectile[30].level_1       = 0.0f;
   game_o.projectile[30].level_2       = 0.0f;
   game_o.projectile[30].level_3       = 0.0f;
   game_o.projectile[30].image         = 252;
   game_o.projectile[30].sound         = 47;
   game_o.projectile[30].damage        = 0.3125f;
   game_o.projectile[30].speed         = 0.0175f;
   game_o.projectile[30].health        = 5;
   game_o.projectile[30].rate_of_fire  = 2;
   game_o.projectile[30].movement      = 1;
   game_o.projectile[30].wave_size     = 0.125f;
   game_o.projectile[30].wave_velocity = 0.0035f;
   game_o.projectile[30].size          = 0.05f;

   game_o.projectile[31].name          = L"Side-ship Weapon 1"; //loads of small homing bullets!!!
   game_o.projectile[31].active        = false;
   game_o.projectile[31].level         = 0;
   game_o.projectile[31].experience    = 0;
   game_o.projectile[31].level_1       = 32768.0f;
   game_o.projectile[31].level_2       = 65536.0f;
   game_o.projectile[31].level_3       = 131072.0f;
   game_o.projectile[31].image         = 226;
   game_o.projectile[31].sound         = 12;
   game_o.projectile[31].damage        = 1.0f;
   game_o.projectile[31].speed         = 0.025f;
   game_o.projectile[31].health        = 1;
   game_o.projectile[31].rate_of_fire  = 25;
   game_o.projectile[31].movement      = 1;
   game_o.projectile[31].wave_size     = 0.125f;
   game_o.projectile[31].wave_velocity = 0.0035f;
   game_o.projectile[31].size          = 0.025f;

   game_o.projectile[32].name          = L"Side-ship Weapon 2";
   game_o.projectile[32].active        = false;
   game_o.projectile[32].level         = 0;
   game_o.projectile[32].experience    = 0;
   game_o.projectile[32].level_1       = 16384.0f;
   game_o.projectile[32].level_2       = 32768.0f;
   game_o.projectile[32].level_3       = 65536.0f;
   game_o.projectile[32].image         = 226;
   game_o.projectile[32].sound         = 11;
   game_o.projectile[32].damage        = 9;
   game_o.projectile[32].speed         = 0.025f;
   game_o.projectile[32].health        = 10;
   game_o.projectile[32].rate_of_fire  = 17;
   game_o.projectile[32].movement      = 2;
   game_o.projectile[32].wave_size     = 0.125f;
   game_o.projectile[32].wave_velocity = 0.0035f;
   game_o.projectile[32].size          = 0.05f;

   game_o.projectile[33].name          = L"Side-ship Weapon 3";
   game_o.projectile[33].active        = false;
   game_o.projectile[33].level         = 0;
   game_o.projectile[33].experience    = 0;
   game_o.projectile[33].level_1       = 0.0f;
   game_o.projectile[33].level_2       = 0.0f;
   game_o.projectile[33].level_3       = 0.0f;
   game_o.projectile[33].image         = 234;
   game_o.projectile[33].sound         = 29;
   game_o.projectile[33].damage        = 0.0875f;
   game_o.projectile[33].speed         = 0.0075f;
   game_o.projectile[33].health        = 5;
   game_o.projectile[33].rate_of_fire  = 5;
   game_o.projectile[33].movement      = 0;
   game_o.projectile[33].wave_size     = 0.125f;
   game_o.projectile[33].wave_velocity = 0.0035f;
   game_o.projectile[33].size          = 0.05f;

   game_o.projectile[34].name          = L"Side-ship Weapon 4";
   game_o.projectile[34].active        = false;
   game_o.projectile[34].level         = 0;
   game_o.projectile[34].experience    = 0;
   game_o.projectile[34].level_1       = 0.0f;
   game_o.projectile[34].level_2       = 0.0f;
   game_o.projectile[34].level_3       = 0.0f;
   game_o.projectile[34].image         = 230;
   game_o.projectile[34].sound         = 25;
   game_o.projectile[34].damage        = 0.0375f;
   game_o.projectile[34].speed         = 0.0075f;
   game_o.projectile[34].health        = 5;
   game_o.projectile[34].rate_of_fire  = 5;
   game_o.projectile[34].movement      = 0;
   game_o.projectile[34].wave_size     = 0.125f;
   game_o.projectile[34].wave_velocity = 0.0035f;
   game_o.projectile[34].size          = 0.05f;
    }
};




