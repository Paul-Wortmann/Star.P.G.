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

#include "particles.hpp"
#include "core.hpp"

extern  game_class game;

void  particle_class::init(void)
{
    particle_class::active          = false;
    particle_class::pos_x           = 0.0f;
    particle_class::pos_y           = 0.0f;
    particle_class::pos_z           = 0.0f;
    particle_class::velocity_max    = 0.0f;
    particle_class::velocity_x      = 0.0f;
    particle_class::velocity_y      = 0.0f;
    particle_class::velocity_z      = 0.0f;
    particle_class::acceleration_x  = 0.0f;
    particle_class::acceleration_y  = 0.0f;
    particle_class::acceleration_z  = 0.0f;
    particle_class::direction       = 0.0f;
    particle_class::force_x         = 0.0f;
    particle_class::force_y         = 0.0f;
    particle_class::force_z         = 0.0f;
    particle_class::color_r         = 1.0f;
    particle_class::color_g         = 1.0f;
    particle_class::color_b         = 1.0f;
    particle_class::TTL             = 1.0f;
    particle_class::TTL_rate        = 0.0025f;
};

void  particle_class::process(void)
{
    if(particle_class::active)
    {
        particle_class::TTL -= particle_class::TTL_rate;
        if (particle_class::TTL < 0.0f) particle_class::active = false;
        if(particle_class::active)
        {
            particle_class::velocity_x += particle_class::acceleration_x;
            particle_class::velocity_y += particle_class::acceleration_y;
            particle_class::velocity_z += particle_class::acceleration_z;
            if (particle_class::velocity_x > particle_class::velocity_max) particle_class::velocity_x = particle_class::velocity_max;
            if (particle_class::velocity_y > particle_class::velocity_max) particle_class::velocity_y = particle_class::velocity_max;
            if (particle_class::velocity_z > particle_class::velocity_max) particle_class::velocity_z = particle_class::velocity_max;
            particle_class::velocity_x += particle_class::force_x;
            particle_class::velocity_y += particle_class::force_y;
            particle_class::velocity_z += particle_class::force_z;
            particle_class::pos_x       = game.physics.move_speed_angle_2D_x(particle_class::pos_x,particle_class::velocity_x,particle_class::direction);
            particle_class::pos_y       = game.physics.move_speed_angle_2D_y(particle_class::pos_y,particle_class::velocity_y,particle_class::direction);
        }
    }
};

void  emitter_class::init(void)
{
    for (int particle_count = 0; particle_count < MAX_PARTICLES; particle_count++)
    {
        emitter_class::particle[particle_count].init();
    }
    emitter_class::active                = false;
    emitter_class::always_on             = false;
    emitter_class::image_reference       = 0;
    emitter_class::width                 = 0.0f;
    emitter_class::height                = 0.0f;
    emitter_class::pos_x                 = 0.0f;
    emitter_class::pos_y                 = 0.0f;
    emitter_class::pos_z                 = 0.0f;
    emitter_class::velocity_max          = 0.0f;
    emitter_class::acceleration_x        = 0.0f;
    emitter_class::acceleration_y        = 0.0f;
    emitter_class::acceleration_z        = 0.0f;
    emitter_class::direction             = 0.0f;
    emitter_class::force_x               = 0.0f;
    emitter_class::force_y               = 0.0f;
    emitter_class::force_z               = 0.0f;
    emitter_class::color_start_r         = 0.0f;
    emitter_class::color_start_g         = 0.0f;
    emitter_class::color_start_b         = 0.0f;
    emitter_class::color_stop_r          = 0.0f;
    emitter_class::color_stop_g          = 0.0f;
    emitter_class::color_stop_b          = 0.0f;
    emitter_class::spawn_frequency       = 0.0f;
    emitter_class::spawn_frequency_count = 0.0f;
    emitter_class::particle_TTL_rate     = 0.0f;
};

void  emitter_class::process(void)
{
    if (emitter_class::active)
    {
        if (!emitter_class::always_on)
        {
            emitter_class::TTL_count++;
            if (emitter_class::TTL_count > TTL) emitter_class::active = false;
        }
        for (int particle_count = 0; particle_count < MAX_PARTICLES; particle_count++)
        {
            emitter_class::particle[particle_count].process();
            emitter_class::particle[particle_count].color_r += ((emitter_class::color_start_r - emitter_class::color_stop_r) * (1.0f / emitter_class::particle_TTL_rate));
            emitter_class::particle[particle_count].color_g += ((emitter_class::color_start_g - emitter_class::color_stop_g) * (1.0f / emitter_class::particle_TTL_rate));
            emitter_class::particle[particle_count].color_b += ((emitter_class::color_start_b - emitter_class::color_stop_b) * (1.0f / emitter_class::particle_TTL_rate));
        }
        emitter_class::spawn_frequency_count++;
        if (emitter_class::spawn_frequency_count > emitter_class::spawn_frequency)
        {
            emitter_class::spawn_frequency_count = 0;
            bool spawned = false;
            for (int particle_count = 0; particle_count < MAX_PARTICLES; particle_count++)
            {
                if (!spawned)
                {
                    if (!emitter_class::particle[particle_count].active)
                    {
                        spawned = true;
                        emitter_class::particle[particle_count].active         = true;
                        emitter_class::particle[particle_count].pos_x          = emitter_class::pos_x; // add random!!! 1%?
                        emitter_class::particle[particle_count].pos_y          = emitter_class::pos_y; // add random!!! 1%?
                        emitter_class::particle[particle_count].pos_z          = emitter_class::pos_z; // add random!!! 1%?
                        emitter_class::particle[particle_count].velocity_max   = emitter_class::velocity_max; // add random!!! 1%?
                        emitter_class::particle[particle_count].acceleration_x = emitter_class::acceleration_x; // add random!!! 5%?
                        emitter_class::particle[particle_count].acceleration_y = emitter_class::acceleration_y; // add random!!! 5%?
                        emitter_class::particle[particle_count].acceleration_z = emitter_class::acceleration_z; // add random!!! 5%?
                        emitter_class::particle[particle_count].force_x        = emitter_class::force_x;
                        emitter_class::particle[particle_count].force_y        = emitter_class::force_y;
                        emitter_class::particle[particle_count].force_z        = emitter_class::force_z;
                        emitter_class::particle[particle_count].color_r        = emitter_class::color_start_r;
                        emitter_class::particle[particle_count].color_g        = emitter_class::color_start_g;
                        emitter_class::particle[particle_count].color_b        = emitter_class::color_start_b;
                        emitter_class::particle[particle_count].direction      = emitter_class::direction; // add random!!! 5%?
                        emitter_class::particle[particle_count].TTL_rate       = emitter_class::particle_TTL_rate; // add random 5%?
                    }
                }
            }
        }
    }
};

void  emitter_class::draw(void)
{
    if (emitter_class::active)
    {
        for (int particle_count = 0; particle_count < MAX_PARTICLES; particle_count++)
        {
            if (emitter_class::image_reference == 0)
//            draw(true,emitter_class::particle[particle_count].pos_x,emitter_class::particle[particle_count].pos_y,emitter_class::particle[particle_count].pos_z,emitter_class::width,emitter_class::height,0.0f,emitter_class::particle[particle_count].color_r,emitter_class::particle[particle_count].color_g,emitter_class::particle[particle_count].color_b,emitter_class::particle[particle_count].TTL);
        }
    }
};














