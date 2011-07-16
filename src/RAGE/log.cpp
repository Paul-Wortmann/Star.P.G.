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
 * @author Paul Wortmann
 * @license GPL
 * @date 2011-07-17
 */

#include <fstream>
#include <stdio.h>
#include "log.hpp"

log_file_class::log_file_class(void)
{

};

log_file_class::~log_file_class(void)
{

};

bool log_file_class::File_Set(const char *Log_File)
{
    log_file_class::Log_File = Log_File;
    return(true);
};

bool log_file_class::File_Clear(void)
{
    std::fstream logfile(log_file_class::Log_File,std::ios::out|std::ios::binary|std::ios::trunc);
    if (logfile.is_open()) logfile.close();
    else return(false);
    return(true);
};

bool log_file_class::File_Delete(void)
{
  if( remove(log_file_class::Log_File) != 0 ) return(false);
  else return(true);
};

bool log_file_class::File_Write(const char  log_data[])
{
    std::fstream logfile(log_file_class::Log_File,std::ios::out|std::ios::app);
    if (logfile.is_open())
    {
        logfile << log_data;
        logfile << "\n";
        logfile.close();
    }
    else return(false);
    return(true);
};

bool log_file_class::File_Write(std::string log_data)
{
    std::fstream logfile(log_file_class::Log_File,std::ios::out|std::ios::app);
    if (logfile.is_open())
    {
        logfile << log_data;
        logfile << "\n";
        logfile.close();
    }
    else return(false);
    return(true);
};

bool log_file_class::File_Write(std::string log_data, int   log_data_int)
{
    std::fstream logfile(log_file_class::Log_File,std::ios::out|std::ios::app);
    if (logfile.is_open())
    {
        logfile << log_data;
        logfile << log_data_int;
        logfile << "\n";
        logfile.close();
    }
    else return(false);
    return(true);
};

bool log_file_class::File_Write(std::string log_data, float log_data_float)
{
    std::fstream logfile(log_file_class::Log_File,std::ios::out|std::ios::app);
    if (logfile.is_open())
    {
        logfile << log_data;
        logfile << log_data_float;
        logfile << "\n";
        logfile.close();
    }
    else return(false);
    return(true);
};

bool log_file_class::File_Write(std::string log_data, bool  log_data_bool)
{
    std::fstream logfile(log_file_class::Log_File,std::ios::out|std::ios::app);
    if (logfile.is_open())
    {
        logfile << log_data;
        if(log_data_bool) logfile << "TRUE";
        else logfile << "FALSE";
        logfile << "\n";
        logfile.close();
    }
    else return(false);
    return(true);
};

bool log_file_class::File_Write(int   log_data)
{
    std::fstream logfile(log_file_class::Log_File,std::ios::out|std::ios::app);
    if (logfile.is_open())
    {
        logfile << log_data;
        logfile << "\n";
        logfile.close();
    }
    else return(false);
    return(true);
};

bool log_file_class::File_Write(float log_data)
{
    std::fstream logfile(log_file_class::Log_File,std::ios::out|std::ios::app);
    if (logfile.is_open())
    {
        logfile << log_data;
        logfile << "\n";
        logfile.close();
    }
    else return(false);
    return(true);
};

bool log_file_class::File_Write(bool  log_data)
{
    std::fstream logfile(log_file_class::Log_File,std::ios::out|std::ios::app);
    if (logfile.is_open())
    {
        if(log_data) logfile << "TRUE";
        else logfile << "FALSE";
        logfile << "\n";
        logfile.close();
    }
    else return(false);
    return(true);
};

bool log_file_class::File_Write(std::string log_data_1, std::string log_data_2)
{
    std::fstream logfile(log_file_class::Log_File,std::ios::out|std::ios::app);
    if (logfile.is_open())
    {
        logfile << log_data_1;
        logfile << log_data_2;
        logfile << "\n";
        logfile.close();
    }
    else return(false);
    return(true);
};

bool log_file_class::File_Write(std::string log_data_1, const char log_data_2[])
{
    std::fstream logfile(log_file_class::Log_File,std::ios::out|std::ios::app);
    if (logfile.is_open())
    {
        logfile << log_data_1;
        logfile << log_data_2;
        logfile << "\n";
        logfile.close();
    }
    else return(false);
    return(true);
};

