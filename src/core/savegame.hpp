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

#ifndef SAVEGAME_H
#define SAVEGAME_H

class save_game_class
{
    private:
        std::string save_file_name;
    public:
              save_game_class(void);
             ~save_game_class(void);
        void  Assign_File(std::string file_name);
        bool  Save(void);
        bool  Load(void);
        bool  Delete(void);
        bool  File_Exists(void);
};

#endif //SAVEGAME_H
