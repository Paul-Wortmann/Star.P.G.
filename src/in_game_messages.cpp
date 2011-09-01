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
 * @date 2011-08-30
 */

#include "in_game_messages.hpp"
#include "RAGE/rage.hpp"
#include "load_resources.hpp"
#include "game.hpp"

extern  game_type  game_o;

void  init_in_game_message_class  (void)
{
    game_o.paused.init(288);
    game_o.saved.init(289);
    game_o.loaded.init(290);
    game_o.a_score.init(309);
    game_o.a_kills.init(308);
    game_o.p_actinium_shields.init(310);
    game_o.p_blasters.init(311);
    game_o.p_burst_lasers.init(312);
    game_o.p_chain_guns.init(313);
    game_o.p_convolution_thrusters.init(314);
    game_o.p_health.init(315);
    game_o.p_ion_cannons.init(316);
    game_o.p_iridium_shileds.init(317);
    game_o.p_maelstrom_thrusters.init(318);
    game_o.p_plasma_rockets.init(319);
    game_o.p_rail_turrets.init(320);
    game_o.p_rubidium_shields.init(321);
    game_o.p_seismic_thrusters.init(322);
    game_o.p_shield_level_up.init(323);
    game_o.p_tantalum_shields.init(324);
    game_o.p_terbium_shields.init(325);
    game_o.p_thrusters_level_up.init(326);
    game_o.p_vortex_thrusters.init(327);
    game_o.p_weapon_level_up.init(328);
    game_o.d_level_end.init(333);
};

void  in_game_message_class::set_image  (int image_ref)
{
    in_game_message_class::image  = image_ref;
};

void  in_game_message_class::init  (int image_ref)
{
    in_game_message_class::active = false;
    in_game_message_class::alpha  = 3.0f;
    in_game_message_class::count  = 0.00125f;
    in_game_message_class::image  = image_ref;
};

void  in_game_message_class::init  (void)
{
    in_game_message_class::active = false;
    in_game_message_class::alpha  = 3.0f;
    in_game_message_class::count  = 0.00125f;
};

void  in_game_message_class::kill  (void)
{
    in_game_message_class::active = false;
};

void  in_game_message_class::spawn (void)
{
    in_game_message_class::active = true;
    in_game_message_class::alpha  = 3.0f;
    in_game_message_class::count  = 0.00125f;
};

void  in_game_message_class::draw  (void)
{
    bind_texture(in_game_message_class::image);
    glLoadIdentity();
    glBegin( GL_QUADS );
    glColor4f (1.0f, 1.0f, 1.0f,in_game_message_class::alpha);
    glTexCoord2i( 0, 1 );glVertex3f(-0.5f,-0.250f, 0.0001f);
    glTexCoord2i( 0, 0 );glVertex3f(-0.5f, 0.250f, 0.0001f);
    glTexCoord2i( 1, 0 );glVertex3f( 0.5f, 0.250f, 0.0001f);
    glTexCoord2i( 1, 1 );glVertex3f( 0.5f,-0.250f, 0.0001f);
    glColor4f (1.0f, 1.0f, 1.0f,1.0f);
    glEnd();
};

void  in_game_message_class::process(void)
{
   if (in_game_message_class::active)
   {
      in_game_message_class::alpha  -= 0.025f;
      if (in_game_message_class::alpha <= 0) in_game_message_class::kill();
   }
};


