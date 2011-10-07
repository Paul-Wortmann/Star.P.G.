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
#include "../load_resources.hpp"

extern  texture_type      texture;
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
            particle_class::velocity_x += particle_class::force_x;
            particle_class::velocity_y += particle_class::force_y;
            particle_class::velocity_z += particle_class::force_z;
            if (particle_class::velocity_x > particle_class::velocity_max   ) particle_class::velocity_x = particle_class::velocity_max;
            if (particle_class::velocity_x < particle_class::velocity_max*-1) particle_class::velocity_x = particle_class::velocity_max*-1;
            if (particle_class::velocity_y > particle_class::velocity_max   ) particle_class::velocity_y = particle_class::velocity_max;
            if (particle_class::velocity_y < particle_class::velocity_max*-1) particle_class::velocity_y = particle_class::velocity_max*-1;
            if (particle_class::velocity_z > particle_class::velocity_max   ) particle_class::velocity_z = particle_class::velocity_max;
            if (particle_class::velocity_z < particle_class::velocity_max*-1) particle_class::velocity_z = particle_class::velocity_max*-1;
            particle_class::pos_x       = game.physics.move_speed_angle_2D_x(particle_class::pos_x,particle_class::velocity_x,game.physics.degrees_to_radians(particle_class::direction));
            particle_class::pos_y       = game.physics.move_speed_angle_2D_y(particle_class::pos_y,particle_class::velocity_y,game.physics.degrees_to_radians(particle_class::direction));
            /*
            // uncomment to have particles move in a circle / blow in a direction.
            // can go the other direction if you change ++ to --
            particle_class::direction++;
            if (particle_class::direction > 360) particle_class::direction = 0;
            */
        }
    }
};

void emitter_class::set_emitter_pos      (float x  , float y  , float z  )
{
    emitter_class::pos_x                 = x;
    emitter_class::pos_y                 = y;
    emitter_class::pos_z                 = z;
};

void emitter_class::set_emitter_state    (bool  active, bool always_on, int ttl)
{
    emitter_class::active                = active;
    emitter_class::always_on             = always_on;
    emitter_class::TTL                   = ttl;
};

void emitter_class::set_emitter_image    (int i_ref, float w  , float h  )
{
    emitter_class::image_reference       = i_ref;
    emitter_class::image_width           = w;
    emitter_class::image_height          = h;
};

void emitter_class::set_emitter_movement (float vm , float ax , float ay , float az , float dr , int   sr , float fx , float fy , float fz )
{
    emitter_class::velocity_max          = vm;
    emitter_class::acceleration_x        = ax;
    emitter_class::acceleration_y        = ay;
    emitter_class::acceleration_z        = az;
    emitter_class::direction             = dr;
    emitter_class::spray_radius          = sr;
    emitter_class::force_x               = fx;
    emitter_class::force_y               = fy;
    emitter_class::force_z               = fz;
};

void emitter_class::set_emitter_rates    (int   sf , int   sfc, float pr , int sq)
{
    emitter_class::spawn_frequency       = sf;
    emitter_class::spawn_frequency_count = sfc;
    emitter_class::particle_TTL_rate     = pr;
    emitter_class::spawn_quantity        = sq;
};

void emitter_class::set_emitter_color    (float csr, float csg, float csb, float cer, float ceg, float ceb)
{
    float pr = emitter_class::particle_TTL_rate;
    emitter_class::color_start_r         = csr;
    emitter_class::color_start_g         = csg;
    emitter_class::color_start_b         = csb;
    emitter_class::color_end_r           = cer;
    emitter_class::color_end_g           = ceg;
    emitter_class::color_end_b           = ceb;
    emitter_class::color_rate_r          = (csr - cer) / (1.0f / pr);
    emitter_class::color_rate_g          = (csg - ceg) / (1.0f / pr);
    emitter_class::color_rate_b          = (csb - ceb) / (1.0f / pr);
};

void emitter_class::set_emitter_velocity (float vx , float vy , float vz )
{
    emitter_class::velocity_x            = vx;
    emitter_class::velocity_y            = vy;
    emitter_class::velocity_z            = vz;
};

void emitter_class::set_emitter_size     (float sx , float sy , float sz )
{
    emitter_class::size_x = sx;
    emitter_class::size_y = sy;
    emitter_class::size_z = sz;
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
    emitter_class::image_width           = 0.0f;
    emitter_class::image_height          = 0.0f;
    emitter_class::pos_x                 = 0.0f;
    emitter_class::pos_y                 = 0.0f;
    emitter_class::pos_z                 = 0.0f;
    emitter_class::size_x                = 0.0f;
    emitter_class::size_y                = 0.0f;
    emitter_class::size_z                = 0.0f;
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
    emitter_class::color_end_r           = 0.0f;
    emitter_class::color_end_g           = 0.0f;
    emitter_class::color_end_b           = 0.0f;
    emitter_class::spawn_frequency       = 0.0f;
    emitter_class::spawn_frequency_count = 0.0f;
    emitter_class::spawn_quantity        = 16;
    emitter_class::particle_TTL_rate     = 0.0f;
    emitter_class::color_rate_r          = 0.0f;
    emitter_class::color_rate_g          = 0.0f;
    emitter_class::color_rate_b          = 0.0f;
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
        else emitter_class::active = true;
        emitter_class::spawn_frequency_count++;
        if (emitter_class::spawn_frequency_count > emitter_class::spawn_frequency)
        {
            emitter_class::spawn_frequency_count = 0;
            int spawned = emitter_class::spawn_quantity;
            for (int particle_count = 0; particle_count < MAX_PARTICLES; particle_count++)
            {
                if (spawned > 0)
                {
                    if (!emitter_class::particle[particle_count].active)
                    {
                        spawned--;
                        emitter_class::particle[particle_count].active         = true;
                        float rx = emitter_class::size_x;
                              rx = (rx*rand()/(RAND_MAX + 1.0)) - (rx/2);
                        float ry = emitter_class::size_y;
                              ry = (ry*rand()/(RAND_MAX + 1.0)) - (ry/2);
                        float rz = emitter_class::size_z;
                              rz = (rz*rand()/(RAND_MAX + 1.0)) - (rz/2);
                        emitter_class::particle[particle_count].pos_x          = emitter_class::pos_x + rx + ((rand()% 200)/10000); // add random!!! 1%?
                        emitter_class::particle[particle_count].pos_y          = emitter_class::pos_y + ry + ((rand()% 200)/10000); // add random!!! 1%?
                        emitter_class::particle[particle_count].pos_z          = emitter_class::pos_z + rz + ((rand()% 200)/10000); // add random!!! 1%?
                        emitter_class::particle[particle_count].velocity_max   = emitter_class::velocity_max + ((rand()% 100)/10000); // add random!!! 1%?
                        emitter_class::particle[particle_count].velocity_x     = emitter_class::velocity_x + ((rand()% 500)/10000); // add random!!! 5%?
                        emitter_class::particle[particle_count].velocity_y     = emitter_class::velocity_y + ((rand()% 500)/10000); // add random!!! 5%?
                        emitter_class::particle[particle_count].velocity_z     = emitter_class::velocity_z + ((rand()% 500)/10000); // add random!!! 5%?
                        emitter_class::particle[particle_count].acceleration_x = emitter_class::acceleration_x + ((rand()% 500)/10000); // add random!!! 5%?
                        emitter_class::particle[particle_count].acceleration_y = emitter_class::acceleration_y + ((rand()% 500)/10000); // add random!!! 5%?
                        emitter_class::particle[particle_count].acceleration_z = emitter_class::acceleration_z + ((rand()% 500)/10000); // add random!!! 5%?
                        emitter_class::particle[particle_count].force_x        = emitter_class::force_x;
                        emitter_class::particle[particle_count].force_y        = emitter_class::force_y;
                        emitter_class::particle[particle_count].force_z        = emitter_class::force_z;
                        emitter_class::particle[particle_count].color_r        = emitter_class::color_start_r;
                        emitter_class::particle[particle_count].color_g        = emitter_class::color_start_g;
                        emitter_class::particle[particle_count].color_b        = emitter_class::color_start_b;
                        int sr = emitter_class::spray_radius;
                        emitter_class::particle[particle_count].direction      = emitter_class::direction - (sr/2) + (int)(sr*rand()/(RAND_MAX + 1.0)); // add random!!! 5%?
                        if (emitter_class::particle[particle_count].direction <   0) emitter_class::particle[particle_count].direction += 360;
                        if (emitter_class::particle[particle_count].direction > 360) emitter_class::particle[particle_count].direction -= 360;
                        emitter_class::particle[particle_count].TTL_rate       = emitter_class::particle_TTL_rate + ((rand()% 100)/10000); // add random 5%?
                        emitter_class::particle[particle_count].TTL            = 1.0f;
                    }
                }
            }
        }
    }
    for (int particle_count = 0; particle_count < MAX_PARTICLES; particle_count++)
    {
        if (emitter_class::particle[particle_count].active)
        {
            emitter_class::particle[particle_count].process();
            emitter_class::particle[particle_count].color_r -= emitter_class::color_rate_r;
            emitter_class::particle[particle_count].color_g -= emitter_class::color_rate_g;
            emitter_class::particle[particle_count].color_b -= emitter_class::color_rate_b;
        }
    }
};

void  emitter_class::draw(void)
{
    if (emitter_class::active)
    {
        for (int particle_count = 0; particle_count < MAX_PARTICLES; particle_count++)
        {
            if (emitter_class::particle[particle_count].active)
            {
                if (emitter_class::image_reference == texture.particle_000.ref_number) texture.particle_000.draw(true,emitter_class::particle[particle_count].pos_x,emitter_class::particle[particle_count].pos_y,emitter_class::particle[particle_count].pos_z,emitter_class::image_width,emitter_class::image_height,0.0f,emitter_class::particle[particle_count].color_r,emitter_class::particle[particle_count].color_g,emitter_class::particle[particle_count].color_b,emitter_class::particle[particle_count].TTL);
                if (emitter_class::image_reference == texture.particle_001.ref_number) texture.particle_001.draw(true,emitter_class::particle[particle_count].pos_x,emitter_class::particle[particle_count].pos_y,emitter_class::particle[particle_count].pos_z,emitter_class::image_width,emitter_class::image_height,0.0f,emitter_class::particle[particle_count].color_r,emitter_class::particle[particle_count].color_g,emitter_class::particle[particle_count].color_b,emitter_class::particle[particle_count].TTL);
                if (emitter_class::image_reference == texture.particle_002.ref_number) texture.particle_002.draw(true,emitter_class::particle[particle_count].pos_x,emitter_class::particle[particle_count].pos_y,emitter_class::particle[particle_count].pos_z,emitter_class::image_width,emitter_class::image_height,0.0f,emitter_class::particle[particle_count].color_r,emitter_class::particle[particle_count].color_g,emitter_class::particle[particle_count].color_b,emitter_class::particle[particle_count].TTL);
                if (emitter_class::image_reference == texture.particle_003.ref_number) texture.particle_003.draw(true,emitter_class::particle[particle_count].pos_x,emitter_class::particle[particle_count].pos_y,emitter_class::particle[particle_count].pos_z,emitter_class::image_width,emitter_class::image_height,0.0f,emitter_class::particle[particle_count].color_r,emitter_class::particle[particle_count].color_g,emitter_class::particle[particle_count].color_b,emitter_class::particle[particle_count].TTL);
                if (emitter_class::image_reference == texture.particle_004.ref_number) texture.particle_004.draw(true,emitter_class::particle[particle_count].pos_x,emitter_class::particle[particle_count].pos_y,emitter_class::particle[particle_count].pos_z,emitter_class::image_width,emitter_class::image_height,0.0f,emitter_class::particle[particle_count].color_r,emitter_class::particle[particle_count].color_g,emitter_class::particle[particle_count].color_b,emitter_class::particle[particle_count].TTL);
                if (emitter_class::image_reference == texture.particle_005.ref_number) texture.particle_005.draw(true,emitter_class::particle[particle_count].pos_x,emitter_class::particle[particle_count].pos_y,emitter_class::particle[particle_count].pos_z,emitter_class::image_width,emitter_class::image_height,0.0f,emitter_class::particle[particle_count].color_r,emitter_class::particle[particle_count].color_g,emitter_class::particle[particle_count].color_b,emitter_class::particle[particle_count].TTL);
                if (emitter_class::image_reference == texture.particle_006.ref_number) texture.particle_006.draw(true,emitter_class::particle[particle_count].pos_x,emitter_class::particle[particle_count].pos_y,emitter_class::particle[particle_count].pos_z,emitter_class::image_width,emitter_class::image_height,0.0f,emitter_class::particle[particle_count].color_r,emitter_class::particle[particle_count].color_g,emitter_class::particle[particle_count].color_b,emitter_class::particle[particle_count].TTL);
                if (emitter_class::image_reference == texture.particle_007.ref_number) texture.particle_007.draw(true,emitter_class::particle[particle_count].pos_x,emitter_class::particle[particle_count].pos_y,emitter_class::particle[particle_count].pos_z,emitter_class::image_width,emitter_class::image_height,0.0f,emitter_class::particle[particle_count].color_r,emitter_class::particle[particle_count].color_g,emitter_class::particle[particle_count].color_b,emitter_class::particle[particle_count].TTL);
                if (emitter_class::image_reference == texture.particle_008.ref_number) texture.particle_008.draw(true,emitter_class::particle[particle_count].pos_x,emitter_class::particle[particle_count].pos_y,emitter_class::particle[particle_count].pos_z,emitter_class::image_width,emitter_class::image_height,0.0f,emitter_class::particle[particle_count].color_r,emitter_class::particle[particle_count].color_g,emitter_class::particle[particle_count].color_b,emitter_class::particle[particle_count].TTL);
                if (emitter_class::image_reference == texture.particle_009.ref_number) texture.particle_009.draw(true,emitter_class::particle[particle_count].pos_x,emitter_class::particle[particle_count].pos_y,emitter_class::particle[particle_count].pos_z,emitter_class::image_width,emitter_class::image_height,0.0f,emitter_class::particle[particle_count].color_r,emitter_class::particle[particle_count].color_g,emitter_class::particle[particle_count].color_b,emitter_class::particle[particle_count].TTL);
                if (emitter_class::image_reference == texture.particle_010.ref_number) texture.particle_010.draw(true,emitter_class::particle[particle_count].pos_x,emitter_class::particle[particle_count].pos_y,emitter_class::particle[particle_count].pos_z,emitter_class::image_width,emitter_class::image_height,0.0f,emitter_class::particle[particle_count].color_r,emitter_class::particle[particle_count].color_g,emitter_class::particle[particle_count].color_b,emitter_class::particle[particle_count].TTL);
                if (emitter_class::image_reference == texture.particle_011.ref_number) texture.particle_011.draw(true,emitter_class::particle[particle_count].pos_x,emitter_class::particle[particle_count].pos_y,emitter_class::particle[particle_count].pos_z,emitter_class::image_width,emitter_class::image_height,0.0f,emitter_class::particle[particle_count].color_r,emitter_class::particle[particle_count].color_g,emitter_class::particle[particle_count].color_b,emitter_class::particle[particle_count].TTL);
                if (emitter_class::image_reference == texture.particle_012.ref_number) texture.particle_012.draw(true,emitter_class::particle[particle_count].pos_x,emitter_class::particle[particle_count].pos_y,emitter_class::particle[particle_count].pos_z,emitter_class::image_width,emitter_class::image_height,0.0f,emitter_class::particle[particle_count].color_r,emitter_class::particle[particle_count].color_g,emitter_class::particle[particle_count].color_b,emitter_class::particle[particle_count].TTL);
                if (emitter_class::image_reference == texture.particle_013.ref_number) texture.particle_013.draw(true,emitter_class::particle[particle_count].pos_x,emitter_class::particle[particle_count].pos_y,emitter_class::particle[particle_count].pos_z,emitter_class::image_width,emitter_class::image_height,0.0f,emitter_class::particle[particle_count].color_r,emitter_class::particle[particle_count].color_g,emitter_class::particle[particle_count].color_b,emitter_class::particle[particle_count].TTL);
                if (emitter_class::image_reference == texture.particle_014.ref_number) texture.particle_014.draw(true,emitter_class::particle[particle_count].pos_x,emitter_class::particle[particle_count].pos_y,emitter_class::particle[particle_count].pos_z,emitter_class::image_width,emitter_class::image_height,0.0f,emitter_class::particle[particle_count].color_r,emitter_class::particle[particle_count].color_g,emitter_class::particle[particle_count].color_b,emitter_class::particle[particle_count].TTL);
                if (emitter_class::image_reference == texture.particle_015.ref_number) texture.particle_015.draw(true,emitter_class::particle[particle_count].pos_x,emitter_class::particle[particle_count].pos_y,emitter_class::particle[particle_count].pos_z,emitter_class::image_width,emitter_class::image_height,0.0f,emitter_class::particle[particle_count].color_r,emitter_class::particle[particle_count].color_g,emitter_class::particle[particle_count].color_b,emitter_class::particle[particle_count].TTL);
            }
        };
    };
};

void init_emitters(void)
{
    for (int emitter_count = 0; emitter_count < MAX_EMITTERS; emitter_count++)
    {
        if (game.emitter[emitter_count].active)
        {
            game.emitter[emitter_count].init();
        }
    }
};

void proc_emitters(void)
{
    for (int emitter_count = 0; emitter_count < MAX_EMITTERS; emitter_count++)
    {
        if (game.emitter[emitter_count].active)
        {
            game.emitter[emitter_count].process();
        }
    }
};

void draw_emitters(void)
{
    for (int emitter_count = 0; emitter_count < MAX_EMITTERS; emitter_count++)
    {
        if (game.emitter[emitter_count].active)
        {
            game.emitter[emitter_count].draw();
        }
    }
};

int spawn_emitter(void)
{
    bool spawned     = false;
    int  emitter_ref = 0;
    for (int emitter_count = 0; emitter_count < MAX_EMITTERS; emitter_count++)
    {
        if (!game.emitter[emitter_count].active)
        {
            spawned = true;
            emitter_ref = emitter_count;
            game.emitter[emitter_count].active = true;
        }
    }
    return(emitter_ref);
};

void set_emitter_pos(int emitter_num, float x, float y, float z)
{
    game.emitter[emitter_num].pos_x                 = x;
    game.emitter[emitter_num].pos_y                 = y;
    game.emitter[emitter_num].pos_z                 = z;
};

void set_emitter_state(int emitter_num, bool active, bool always_on, int ttl)
{
    game.emitter[emitter_num].active                = active;
    game.emitter[emitter_num].always_on             = always_on;
    game.emitter[emitter_num].TTL                   = ttl;
};

void set_emitter_image(int emitter_num, int i_ref, float w, float h)
{
    game.emitter[emitter_num].image_reference       = i_ref;
    game.emitter[emitter_num].image_width           = w;
    game.emitter[emitter_num].image_height          = h;
};

void set_emitter_movement(int emitter_num, float vm, float ax, float ay, float az, float dr, int   sr, float fx, float fy, float fz)
{
    game.emitter[emitter_num].velocity_max          = vm;
    game.emitter[emitter_num].acceleration_x        = ax;
    game.emitter[emitter_num].acceleration_y        = ay;
    game.emitter[emitter_num].acceleration_z        = az;
    game.emitter[emitter_num].direction             = dr;
    game.emitter[emitter_num].spray_radius          = sr;
    game.emitter[emitter_num].force_x               = fx;
    game.emitter[emitter_num].force_y               = fy;
    game.emitter[emitter_num].force_z               = fz;
};

void set_emitter_rates(int emitter_num, int sf, int sfc, float pr, int sq)
{
    game.emitter[emitter_num].spawn_frequency       = sf;
    game.emitter[emitter_num].spawn_frequency_count = sfc;
    game.emitter[emitter_num].particle_TTL_rate     = pr;
    game.emitter[emitter_num].spawn_quantity        = sq;
};

void set_emitter_color(int emitter_num, float csr, float csg, float csb, float cer, float ceg, float ceb)
{
    float pr = game.emitter[emitter_num].particle_TTL_rate;
    game.emitter[emitter_num].color_start_r         = csr;
    game.emitter[emitter_num].color_start_g         = csg;
    game.emitter[emitter_num].color_start_b         = csb;
    game.emitter[emitter_num].color_end_r           = cer;
    game.emitter[emitter_num].color_end_g           = ceg;
    game.emitter[emitter_num].color_end_b           = ceb;
    game.emitter[emitter_num].color_rate_r          = (csr - cer) / (1.0f / pr);
    game.emitter[emitter_num].color_rate_g          = (csg - ceg) / (1.0f / pr);
    game.emitter[emitter_num].color_rate_b          = (csb - ceb) / (1.0f / pr);
};

void set_emitter_velocity (int emitter_num, float vx , float vy , float vz )
{
    game.emitter[emitter_num].velocity_x = vx;
    game.emitter[emitter_num].velocity_y = vy;
    game.emitter[emitter_num].velocity_z = vz;
};







