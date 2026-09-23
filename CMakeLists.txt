# ===========================================================================
#  Star.P.G. — CMake build (SDL2)
# ===========================================================================
cmake_minimum_required(VERSION 3.10)

project(Star.P.G. VERSION 1.01 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ---------------------------------------------------------------------------
#  Compiler flags
# ---------------------------------------------------------------------------
if(NOT MSVC)
    add_compile_options(
        -Wall
        -Wextra
        -Wunused
        -Wshadow
        -Woverloaded-virtual
        -Wunreachable-code
        -fno-math-errno
        -fno-exceptions
        -ffast-math
    )
    if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        add_compile_options(-fno-enforce-eh-specs)
    endif()
endif()

# ---------------------------------------------------------------------------
#  Install locations (used by the optional install() rules at the bottom)
# ---------------------------------------------------------------------------
set(BINDIR  "games"                CACHE STRING
    "Directory from CMAKE_INSTALL_PREFIX where the game executable is installed.")
set(DATADIR "share/games/star_p_g" CACHE STRING
    "Directory from CMAKE_INSTALL_PREFIX where the game data files are installed.")

if(NOT IS_ABSOLUTE "${DATADIR}")
    add_definitions(-DDATA_INSTALL_DIR="${CMAKE_INSTALL_PREFIX}/${DATADIR}")
else()
    add_definitions(-DDATA_INSTALL_DIR="${DATADIR}")
endif()

# ---------------------------------------------------------------------------
#  Dependencies
#
#  SDL2 and its sibling libraries all ship pkg-config .pc files on every
#  mainstream platform (Linux, BSD, macOS via Homebrew/MacPorts, MSYS2,
#  MinGW-w64), so pkg-config is the most portable way to find them.
# ---------------------------------------------------------------------------
find_package(PkgConfig REQUIRED)

pkg_check_modules(SDL2       REQUIRED sdl2)
pkg_check_modules(SDL2_IMAGE REQUIRED SDL2_image)
pkg_check_modules(SDL2_MIXER REQUIRED SDL2_mixer)
pkg_check_modules(SDL2_NET   REQUIRED SDL2_net)
pkg_check_modules(SDL2_TTF   REQUIRED SDL2_ttf)

if(NOT SDL2_FOUND)
    message(FATAL_ERROR
        "Couldn't find SDL2 development files. On Debian/Ubuntu install "
        "'libsdl2-dev'; on Fedora 'SDL2-devel'; on Arch 'sdl2'.")
endif()

if(NOT SDL2_IMAGE_FOUND)
    message(FATAL_ERROR
        "Couldn't find SDL2_image development files. On Debian/Ubuntu install "
        "'libsdl2-image-dev'; on Fedora 'SDL2_image-devel'; on Arch 'sdl2_image'.")
endif()

if(NOT SDL2_MIXER_FOUND)
    message(FATAL_ERROR
        "Couldn't find SDL2_mixer development files. On Debian/Ubuntu install "
        "'libsdl2-mixer-dev'; on Fedora 'SDL2_mixer-devel'; on Arch 'sdl2_mixer'.")
endif()

if(NOT SDL2_NET_FOUND)
    message(FATAL_ERROR
        "Couldn't find SDL2_net development files. On Debian/Ubuntu install "
        "'libsdl2-net-dev'; on Fedora 'SDL2_net-devel'; on Arch 'sdl2_net'.")
endif()

if(NOT SDL2_TTF_FOUND)
    message(FATAL_ERROR
        "Couldn't find SDL2_ttf development files. On Debian/Ubuntu install "
        "'libsdl2-ttf-dev'; on Fedora 'SDL2_ttf-devel'; on Arch 'sdl2_ttf'.")
endif()

# OpenGL — for the fixed-function rendering used throughout the game
find_package(OpenGL REQUIRED)
if(NOT OPENGL_FOUND)
    message(FATAL_ERROR
        "Couldn't find OpenGL development files. On Debian/Ubuntu install "
        "'libgl1-mesa-dev'; on Fedora 'mesa-libGL-devel'.")
endif()

# GLEW — used for extension loading
pkg_check_modules(GLEW REQUIRED glew)
if(NOT GLEW_FOUND)
    message(FATAL_ERROR
        "Couldn't find GLEW development files. On Debian/Ubuntu install "
        "'libglew-dev'; on Fedora 'glew-devel'.")
endif()

# PhysFS — currently unused by the source tree (main.cpp has the calls
# commented out). Detected opportunistically; the build does not depend on it.
pkg_check_modules(PHYSFS physfs)

# ---------------------------------------------------------------------------
#  Sources
# ---------------------------------------------------------------------------
set(STAR_P_G_SOURCES
    src/core/background.cpp
    src/core/config.cpp
    src/core/core.cpp
    src/core/font.cpp
    src/core/graphics.cpp
    src/core/io.cpp
    src/core/log.cpp
    src/core/menu.cpp
    src/core/music.cpp
    src/core/network.cpp
    src/core/particles.cpp
    src/core/physics.cpp
    src/core/savegame.cpp
    src/core/sound.cpp
    src/core/textures.cpp
    src/core/timer.cpp
    src/achievements.cpp
    src/debris.cpp
    src/explosions.cpp
    src/game.cpp
    src/in_game_messages.cpp
    src/language.cpp
    src/levels.cpp
    src/load_resources.cpp
    src/main.cpp
    src/menu_system.cpp
    src/misc.cpp
    src/NPC.cpp
    src/PC.cpp
    src/powerups.cpp
    src/projectiles.cpp
    src/save_data.cpp
    src/screen_rumble.cpp
    src/shields.cpp
    src/support_ships.cpp
    src/thrusters.cpp
    src/waves.cpp
)

# Windows icon + version resource
if(WIN32)
    list(APPEND STAR_P_G_SOURCES src/icon.rc)
endif()

# ---------------------------------------------------------------------------
#  Target
# ---------------------------------------------------------------------------
add_executable(star_p_g ${STAR_P_G_SOURCES})

# --- include paths ---------------------------------------------------------
target_include_directories(star_p_g PRIVATE
    ${SDL2_INCLUDE_DIRS}
    ${SDL2_IMAGE_INCLUDE_DIRS}
    ${SDL2_MIXER_INCLUDE_DIRS}
    ${SDL2_NET_INCLUDE_DIRS}
    ${SDL2_TTF_INCLUDE_DIRS}
    ${GLEW_INCLUDE_DIRS}
    ${OPENGL_INCLUDE_DIRS}
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# --- library search paths (mostly needed on Windows / non-standard prefixes)
target_link_directories(star_p_g PRIVATE
    ${SDL2_LIBRARY_DIRS}
    ${SDL2_IMAGE_LIBRARY_DIRS}
    ${SDL2_MIXER_LIBRARY_DIRS}
    ${SDL2_NET_LIBRARY_DIRS}
    ${SDL2_TTF_LIBRARY_DIRS}
    ${GLEW_LIBRARY_DIRS}
    ${OPENGL_LIBRARY_DIRS}
)

# --- link ------------------------------------------------------------------
target_link_libraries(star_p_g PRIVATE
    ${SDL2_LIBRARIES}
    ${SDL2_IMAGE_LIBRARIES}
    ${SDL2_MIXER_LIBRARIES}
    ${SDL2_NET_LIBRARIES}
    ${SDL2_TTF_LIBRARIES}
    ${GLEW_LIBRARIES}
    ${OPENGL_LIBRARIES}
)

# Optional: link PhysFS only if it was actually found
if(PHYSFS_FOUND)
    target_include_directories(star_p_g PRIVATE ${PHYSFS_INCLUDE_DIRS})
    target_link_libraries(star_p_g PRIVATE ${PHYSFS_LIBRARIES})
    target_compile_definitions(star_p_g PRIVATE HAVE_PHYSFS=1)
endif()

# ---------------------------------------------------------------------------
#  Install rules (optional — comment out if you don't `make install`)
# ---------------------------------------------------------------------------
install(TARGETS star_p_g
        RUNTIME DESTINATION ${BINDIR})

install(DIRECTORY data
        DESTINATION ${DATADIR}
        OPTIONAL)

install(DIRECTORY save
        DESTINATION ${DATADIR}
        OPTIONAL)
        
