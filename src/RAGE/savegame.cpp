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
 * @author Paul Wortmann
 * @license GPL
 */


#include <fstream>
#include "savegame.hpp"
#include "rage.hpp"
#include "../save_data.hpp"

extern game_class game;
extern save_data_type save_data;

save_game_class::save_game_class(void)
{

};

save_game_class::~save_game_class(void)
{

};

bool save_game_class::Assign_File(std::string file_name)
{
    save_game_class::save_file_name = file_name;
};

bool save_game_class::Save(void)
{
    update_save_data();
    std::fstream savegamefile(save_game_class::save_file_name.c_str(),std::ios::out|std::ios::binary|std::ios::trunc);
    if (savegamefile.is_open())
    {
        savegamefile.write(reinterpret_cast<char*>(&save_data), sizeof(save_data));
        savegamefile.close();
    }
    else return(false);
    return(true);
};

bool save_game_class::Load(void)
{
    std::fstream savegamefile(save_game_class::save_file_name.c_str(),std::ios::in|std::ios::binary);
    if (savegamefile.is_open())
    {
        savegamefile.read(reinterpret_cast<char*>(&save_data), sizeof(save_data));
        savegamefile.close();
        update_game_data();
    }
    else return(false);
    return(true);
};

bool  save_game_class::Delete(void)
{
  if( remove(save_game_class::save_file_name.c_str()) != 0 ) return(false);
  else return(true);
};






