Project ("Star.P.G.")
cmake_minimum_required (VERSION 2.8)

Set (PACKAGE "STAR_P_G")
Set (VERSION "1.01")


# Default definitions
if (NOT MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wunused -Wshadow -Woverloaded-virtual -Wunreachable-code")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-math-errno -fno-exceptions -ffast-math")
  set(CMAKE_LD_FLAGS "-fwhole-program")
endif (NOT MSVC)

if (CMAKE_CXX_COMPILER MATCHES "clang")
  # clang needs lstdc++ linked explicitly:
  set(CMAKE_LD_FLAGS "${CMAKE_LD_FLAGS} -lstdc++")
elseif (NOT MSVC)
  # assume gcc:
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-enforce-eh-specs")
endif ()

if(CMAKE_BUILD_TYPE STREQUAL "Release")
  set(CMAKE_CXX_FLAGS_RELEASE "-O2 -g0")
elseif(CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo")
  set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g")
elseif(CMAKE_BUILD_TYPE STREQUAL "MinSizeRel")
  set(CMAKE_CXX_FLAGS_MINSIZEREL "-Os -g0")
elseif(CMAKE_BUILD_TYPE STREQUAL "Debug")
  set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g3 -pg")
  set(CMAKE_EXE_LINKER_FLAGS_DEBUG "-pg")
  set(CMAKE_SHARED_LINKER_FLAGS_DEBUG "-pg")
  set(CMAKE_MODULE_LINKER_FLAGS_DEBUG "-pg")
endif()

set(BINDIR  "games"             CACHE STRING "Directory from CMAKE_INSTALL_PREFIX where game executable will be installed.")
set(DATADIR "share/games/star_p_g" CACHE STRING "Directory from CMAKE_INSTALL_PREFIX where game data files will be installed.")

If(NOT IS_ABSOLUTE "${DATADIR}")
	add_definitions(-DDATA_INSTALL_DIR="${CMAKE_INSTALL_PREFIX}/${DATADIR}")
Else(NOT IS_ABSOLUTE "${DATADIR}")
	add_definitions(-DDATA_INSTALL_DIR="${DATADIR}")
EndIf(NOT IS_ABSOLUTE "${DATADIR}")

# Detect missing dependencies

Include(FindPkgConfig)

PKG_SEARCH_MODULE(SDL REQUIRED sdl)
If (NOT SDL_FOUND)
    Message (ERROR "Couldn't find SDL development files. On Debian-based systems (such as Ubuntu) you should install the 'libsdl-dev' package.")
Else (NOT SDL_FOUND)
    INCLUDE_DIRECTORIES(${SDL_INCLUDE_DIRS})
EndIf (NOT SDL_FOUND)

PKG_SEARCH_MODULE(SDLIMAGE REQUIRED SDL_image)
If (NOT SDLIMAGE_FOUND)
    Message (ERROR "Couldn't find SDL-image development files. On Debian-based systems (such as Ubuntu) you should install the 'libsdl-image1.2-dev' package.")
Else (NOT SDLIMAGE_FOUND)
    INCLUDE_DIRECTORIES(${SDLIMAGE_INCLUDE_DIRS})
EndIf (NOT SDLIMAGE_FOUND)

PKG_SEARCH_MODULE(SDLMIXER REQUIRED SDL_mixer)
If (NOT SDLMIXER_FOUND)
    Message (ERROR "Couldn't find SDL-mixer development files. On Debian-based systems (such as Ubuntu) you should install the 'libsdl-mixer1.2-dev' package.")
Else (NOT SDLMIXER_FOUND)
    INCLUDE_DIRECTORIES(${SDLMIXER_INCLUDE_DIRS})
EndIf (NOT SDLMIXER_FOUND)

 PKG_SEARCH_MODULE(SDLNET REQUIRED SDL_net)
 If (NOT SDLNET_FOUND)
     Message (ERROR "Couldn't find SDL_net development files. On Debian-based systems (such as Ubuntu) you should install the 'libsdl-net-dev1.2' package.")
 Else (NOT SDLNET_FOUND)
     INCLUDE_DIRECTORIES(${SDLNET_INCLUDE_DIRS})
 EndIf (NOT SDLNET_FOUND)

Find_Package (SDL_ttf REQUIRED)
If (NOT SDLTTF_FOUND)
    Message (ERROR "Couldn't find SDL-ttf development files. On Debian-based systems (such as Ubuntu) you should install the 'libsdl-ttf2.0-dev' package.")
Else (NOT SDLTTF_FOUND)
	  Include_Directories (${SDLTTF_INCLUDE_DIR})
EndIf (NOT SDLTTF_FOUND)

#PKG_SEARCH_MODULE(PHYSFS REQUIRED PhysFS)
#If (NOT PHYSFS_FOUND)
#    Message (ERROR "Couldn't find PhysicsFS development files. On Debian-based systems (such as Ubuntu) you should install the 'libphysfs-dev' package.")
#Else (NOT PHYSFS_FOUND)
#    INCLUDE_DIRECTORIES(${PHYSFS_INCLUDE_DIRS})
#EndIf (NOT PHYSFS_FOUND)

find_package(PhysFS REQUIRED)
if (PHYSFS_FOUND)
  INCLUDE_DIRECTORIES(${PHYSFS_INCLUDE_DIR})
  link_directories(${PHYSFS_LIBRARY})
Else (PHYSFS_FOUND)
   Message (FATAL_ERROR "Couldn't find libphysfs development files. On Debian-based systems (such as Ubuntu) you should install the 'libphysfs-dev' package.")
endif (PHYSFS_FOUND)

find_package(OpenGL REQUIRED)
if (OPENGL_FOUND)
  INCLUDE_DIRECTORIES(${OPENGL_INCLUDE_DIR})
  link_directories(${OPENGL_LIBRARIES})
Else (OPENGL_FOUND)
  Message (FATAL_ERROR "Couldn't find OpenGl development files. On Debian-based systems (such as Ubuntu) you should install the OpenGL development package.")
endif (OPENGL_FOUND)

PKG_SEARCH_MODULE(GLEW REQUIRED glew)
If (NOT GLEW_FOUND)
    Message (ERROR "Couldn't find glew development files. On Debian-based systems (such as Ubuntu) you should install the 'libglew-dev' package.")
Else (NOT GLEW_FOUND)
    INCLUDE_DIRECTORIES(${GLEW_INCLUDE_DIRS})
    #link_directories(${GLEW_LIBRARIES})
EndIf (NOT GLEW_FOUND)

include_directories(/usr/include)

# Sources

Set (STAR_P_G_SOURCES
	./src/core/background.cpp
	./src/core/config.cpp
	./src/core/core.cpp
	./src/core/font.cpp
	./src/core/graphics.cpp
	./src/core/io.cpp
	./src/core/log.cpp
	./src/core/menu.cpp
	./src/core/music.cpp
	./src/core/network.cpp
	./src/core/particles.cpp
	./src/core/physics.cpp
	./src/core/savegame.cpp
	./src/core/sound.cpp
	./src/core/textures.cpp
	./src/core/timer.cpp
	./src/achievements.cpp
	./src/bullets.cpp
	./src/debris.cpp
	./src/explosions.cpp
	./src/game.cpp
	./src/in_game_messages.cpp
	./src/language.cpp
	./src/levels.cpp
	./src/load_resources.cpp
	./src/main.cpp
	./src/menu_system.cpp
	./src/misc.cpp
	./src/NPC.cpp
	./src/PC.cpp
	./src/powerups.cpp
	./src/projectiles.cpp
	./src/save_data.cpp
	./src/screen_rumble.cpp
	./src/shields.cpp
	./src/support_ships.cpp
	./src/thrusters.cpp
	./src/waves.cpp
)

# Add icon and file info to executable for Windows systems
IF (WIN32)
  SET(STAR_P_G_SOURCES
    ${STAR_P_G_SOURCES}
    ./source/icon.rc
    )
ENDIF (WIN32)

Add_Executable (star_p_g ${STAR_P_G_SOURCES})

link_directories( /path/to/PHYSFSlibs/)

Target_Link_Libraries (star_p_g ${CMAKE_LD_FLAGS}  ${PHYSFS_LIBRARY} ${SDL_LIBRARIES} ${SDLIMAGE_LIBRARIES} ${SDLMIXER_LIBRARIES} ${SDLTTF_LIBRARIES} ${SDLNET_LIBRARIES} ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES})


