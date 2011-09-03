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

#ifndef LOG_H
#define LOG_H

#include <string>

class log_file_class
{
    private:
        const char *Log_File;
    public:
              log_file_class(void);
             ~log_file_class(void);
        bool File_Set(const char *Log_File);
        bool File_Clear(void);
        bool File_Delete(void);
        bool File_Write(const char  log_data[]);
        bool File_Write(std::string log_data);
        bool File_Write(std::string log_data, int   log_data_int);
        bool File_Write(std::string log_data, float log_data_float);
        bool File_Write(std::string log_data, bool  log_data_bool);
        bool File_Write(int   log_data);
        bool File_Write(float log_data);
        bool File_Write(bool  log_data);
        bool File_Write(std::string log_data_1, std::string log_data_2);
        bool File_Write(std::string log_data_1, const char log_data_2[]);
};

#endif //LOG_H
