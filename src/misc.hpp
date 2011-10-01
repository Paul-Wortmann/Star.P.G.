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

#ifndef MISC_H
#define MISC_H

int         seed_rand(void);
double      random_double(void);
int         random(int range);
int         random_dec(void);
int         random_cen(void);
int         random_int(void);
float       random_GLcoord(void);
std::string const_char_to_string(const char *const_char_in);
std::string int_to_string(int int_in);
bool        file_exists(const char* file_name);
int         round_double(double x);
int         nextpoweroftwo(int x);

#endif //MISC_H


