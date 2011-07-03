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


#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{

	//Date Version Types
	static const char DATE[] = "01";
	static const char MONTH[] = "01";
	static const char YEAR[] = "2011";
	static const char UBUNTU_VERSION_STYLE[] = "0.16";

	//Software Status
	static const char STATUS[] = "Beta";
	static const char STATUS_SHORT[] = "b";

	//Standard Version Type
	static const long MAJOR = 0;
	static const long MINOR = 0;
	static const long BUILD = 0;
	static const long REVISION = 16;

	//Miscellaneous Version Types
	static const long BUILDS_COUNT = 1362;
	#define RC_FILEVERSION 0,0,0,12
	#define RC_FILEVERSION_STRING "0, 0, 0, 12\0"
	static const char FULLVERSION_STRING[] = "0.0.0.16";

	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY = 0;


}
#endif //VERSION_H
