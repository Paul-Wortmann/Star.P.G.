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
 * @date 2011-09-03
 */

#include "in_game_messages.hpp"
#include "RAGE/rage.hpp"
#include "load_resources.hpp"
#include "game.hpp"

extern  texture_type             texture;
extern  game_type                game_o;

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
    if (in_game_message_class::image == 288) texture.game_paused.draw          ( 0.0f, 0.0f, 0.0001f, 1.0f, 0.5f,0.0f,in_game_message_class::alpha);
    if (in_game_message_class::image == 289) texture.game_saved.draw           ( 0.0f, 0.0f, 0.0001f, 1.0f, 0.5f,0.0f,in_game_message_class::alpha);
    if (in_game_message_class::image == 290) texture.game_loaded.draw          ( 0.0f, 0.0f, 0.0001f, 1.0f, 0.5f,0.0f,in_game_message_class::alpha);
    if (in_game_message_class::image == 309) texture.score_achievement.draw    ( 0.0f, 0.0f, 0.0001f, 1.0f, 0.5f,0.0f,in_game_message_class::alpha);
    if (in_game_message_class::image == 308) texture.kills_achievement.draw    ( 0.0f, 0.0f, 0.0001f, 1.0f, 0.5f,0.0f,in_game_message_class::alpha);
    if (in_game_message_class::image == 310) texture.actinium_shields.draw     ( 0.0f, 0.0f, 0.0001f, 1.0f, 0.5f,0.0f,in_game_message_class::alpha);
    if (in_game_message_class::image == 311) texture.blasters.draw             ( 0.0f, 0.0f, 0.0001f, 1.0f, 0.5f,0.0f,in_game_message_class::alpha);
    if (in_game_message_class::image == 312) texture.burst_lasers.draw         ( 0.0f, 0.0f, 0.0001f, 1.0f, 0.5f,0.0f,in_game_message_class::alpha);
    if (in_game_message_class::image == 313) texture.chain_guns.draw           ( 0.0f, 0.0f, 0.0001f, 1.0f, 0.5f,0.0f,in_game_message_class::alpha);
    if (in_game_message_class::image == 314) texture.convolution_thrusters.draw( 0.0f, 0.0f, 0.0001f, 1.0f, 0.5f,0.0f,in_game_message_class::alpha);
    if (in_game_message_class::image == 315) texture.health.draw               ( 0.0f, 0.0f, 0.0001f, 1.0f, 0.5f,0.0f,in_game_message_class::alpha);
    if (in_game_message_class::image == 316) texture.ion_cannons.draw          ( 0.0f, 0.0f, 0.0001f, 1.0f, 0.5f,0.0f,in_game_message_class::alpha);
    if (in_game_message_class::image == 317) texture.iridium_shileds.draw      ( 0.0f, 0.0f, 0.0001f, 1.0f, 0.5f,0.0f,in_game_message_class::alpha);
    if (in_game_message_class::image == 318) texture.maelstrom_thrusters.draw  ( 0.0f, 0.0f, 0.0001f, 1.0f, 0.5f,0.0f,in_game_message_class::alpha);
    if (in_game_message_class::image == 319) texture.plasma_rockets.draw       ( 0.0f, 0.0f, 0.0001f, 1.0f, 0.5f,0.0f,in_game_message_class::alpha);
    if (in_game_message_class::image == 320) texture.rail_turrets.draw         ( 0.0f, 0.0f, 0.0001f, 1.0f, 0.5f,0.0f,in_game_message_class::alpha);
    if (in_game_message_class::image == 321) texture.rubidium_shields.draw     ( 0.0f, 0.0f, 0.0001f, 1.0f, 0.5f,0.0f,in_game_message_class::alpha);
    if (in_game_message_class::image == 322) texture.seismic_thrusters.draw    ( 0.0f, 0.0f, 0.0001f, 1.0f, 0.5f,0.0f,in_game_message_class::alpha);
    if (in_game_message_class::image == 323) texture.shield_level_up.draw      ( 0.0f, 0.0f, 0.0001f, 1.0f, 0.5f,0.0f,in_game_message_class::alpha);
    if (in_game_message_class::image == 324) texture.tantalum_shields.draw     ( 0.0f, 0.0f, 0.0001f, 1.0f, 0.5f,0.0f,in_game_message_class::alpha);
    if (in_game_message_class::image == 325) texture.terbium_shields.draw      ( 0.0f, 0.0f, 0.0001f, 1.0f, 0.5f,0.0f,in_game_message_class::alpha);
    if (in_game_message_class::image == 326) texture.thrusters_level_up.draw   ( 0.0f, 0.0f, 0.0001f, 1.0f, 0.5f,0.0f,in_game_message_class::alpha);
    if (in_game_message_class::image == 327) texture.vortex_thrusters.draw     ( 0.0f, 0.0f, 0.0001f, 1.0f, 0.5f,0.0f,in_game_message_class::alpha);
    if (in_game_message_class::image == 328) texture.weapon_level_up.draw      ( 0.0f, 0.0f, 0.0001f, 1.0f, 0.5f,0.0f,in_game_message_class::alpha);
    if (in_game_message_class::image == 333) texture.level_completed.draw      ( 0.0f, 0.0f, 0.0001f, 1.0f, 0.5f,0.0f,in_game_message_class::alpha);
};

void  in_game_message_class::process(void)
{
   if (in_game_message_class::active)
   {
      in_game_message_class::alpha  -= 0.025f;
      if (in_game_message_class::alpha <= 0) in_game_message_class::kill();
   }
};


