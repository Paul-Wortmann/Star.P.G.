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

#include "in_game_messages.hpp"
#include "core/core.hpp"
#include "load_resources.hpp"
#include "game.hpp"

extern  texture_type             texture;
extern  game_type                game_o;

void  init_in_game_message_class  (void)
{
    game_o.paused.init                 (texture.game_paused.ref_number);
    game_o.saved.init                  (texture.game_saved.ref_number);
    game_o.loaded.init                 (texture.game_loaded.ref_number);
    game_o.a_score.init                (texture.score_achievement.ref_number);
    game_o.a_kills.init                (texture.kills_achievement.ref_number);
    game_o.p_actinium_shields.init     (texture.actinium_shields.ref_number);
    game_o.p_blasters.init             (texture.blasters.ref_number);
    game_o.p_burst_lasers.init         (texture.burst_lasers.ref_number);
    game_o.p_chain_guns.init           (texture.chain_guns.ref_number);
    game_o.p_convolution_thrusters.init(texture.convolution_thrusters.ref_number);
    game_o.p_health.init               (texture.health.ref_number);
    game_o.p_ion_cannons.init          (texture.ion_cannons.ref_number);
    game_o.p_iridium_shileds.init      (texture.iridium_shileds.ref_number);
    game_o.p_maelstrom_thrusters.init  (texture.maelstrom_thrusters.ref_number);
    game_o.p_plasma_rockets.init       (texture.plasma_rockets.ref_number);
    game_o.p_rail_turrets.init         (texture.rail_turrets.ref_number);
    game_o.p_rubidium_shields.init     (texture.rubidium_shields.ref_number);
    game_o.p_seismic_thrusters.init    (texture.seismic_thrusters.ref_number);
    game_o.p_shield_level_up.init      (texture.shield_level_up.ref_number);
    game_o.p_tantalum_shields.init     (texture.tantalum_shields.ref_number);
    game_o.p_terbium_shields.init      (texture.terbium_shields.ref_number);
    game_o.p_thrusters_level_up.init   (texture.thrusters_level_up.ref_number);
    game_o.p_vortex_thrusters.init     (texture.vortex_thrusters.ref_number);
    game_o.p_weapon_level_up.init      (texture.weapon_level_up.ref_number);
    game_o.d_level_end.init            (texture.level_completed.ref_number);
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
    if (in_game_message_class::image == texture.game_paused.ref_number)           texture.game_paused.draw          (false, 0.0f, 0.0f, 0.0001f, 1.0f, 0.5f,0.0f,in_game_message_class::alpha);
    if (in_game_message_class::image == texture.game_saved.ref_number)            texture.game_saved.draw           (false, 0.0f, 0.0f, 0.0001f, 1.0f, 0.5f,0.0f,in_game_message_class::alpha);
    if (in_game_message_class::image == texture.game_loaded.ref_number)           texture.game_loaded.draw          (false, 0.0f, 0.0f, 0.0001f, 1.0f, 0.5f,0.0f,in_game_message_class::alpha);
    if (in_game_message_class::image == texture.score_achievement.ref_number)     texture.score_achievement.draw    (false, 0.0f, 0.0f, 0.0001f, 1.0f, 0.5f,0.0f,in_game_message_class::alpha);
    if (in_game_message_class::image == texture.kills_achievement.ref_number)     texture.kills_achievement.draw    (false, 0.0f, 0.0f, 0.0001f, 1.0f, 0.5f,0.0f,in_game_message_class::alpha);
    if (in_game_message_class::image == texture.actinium_shields.ref_number)      texture.actinium_shields.draw     (false, 0.0f, 0.0f, 0.0001f, 1.0f, 0.5f,0.0f,in_game_message_class::alpha);
    if (in_game_message_class::image == texture.blasters.ref_number)              texture.blasters.draw             (false, 0.0f, 0.0f, 0.0001f, 1.0f, 0.5f,0.0f,in_game_message_class::alpha);
    if (in_game_message_class::image == texture.burst_lasers.ref_number)          texture.burst_lasers.draw         (false, 0.0f, 0.0f, 0.0001f, 1.0f, 0.5f,0.0f,in_game_message_class::alpha);
    if (in_game_message_class::image == texture.chain_guns.ref_number)            texture.chain_guns.draw           (false, 0.0f, 0.0f, 0.0001f, 1.0f, 0.5f,0.0f,in_game_message_class::alpha);
    if (in_game_message_class::image == texture.convolution_thrusters.ref_number) texture.convolution_thrusters.draw(false, 0.0f, 0.0f, 0.0001f, 1.0f, 0.5f,0.0f,in_game_message_class::alpha);
    if (in_game_message_class::image == texture.health.ref_number)                texture.health.draw               (false, 0.0f, 0.0f, 0.0001f, 1.0f, 0.5f,0.0f,in_game_message_class::alpha);
    if (in_game_message_class::image == texture.ion_cannons.ref_number)           texture.ion_cannons.draw          (false, 0.0f, 0.0f, 0.0001f, 1.0f, 0.5f,0.0f,in_game_message_class::alpha);
    if (in_game_message_class::image == texture.iridium_shileds.ref_number)       texture.iridium_shileds.draw      (false, 0.0f, 0.0f, 0.0001f, 1.0f, 0.5f,0.0f,in_game_message_class::alpha);
    if (in_game_message_class::image == texture.maelstrom_thrusters.ref_number)   texture.maelstrom_thrusters.draw  (false, 0.0f, 0.0f, 0.0001f, 1.0f, 0.5f,0.0f,in_game_message_class::alpha);
    if (in_game_message_class::image == texture.plasma_rockets.ref_number)        texture.plasma_rockets.draw       (false, 0.0f, 0.0f, 0.0001f, 1.0f, 0.5f,0.0f,in_game_message_class::alpha);
    if (in_game_message_class::image == texture.rail_turrets.ref_number)          texture.rail_turrets.draw         (false, 0.0f, 0.0f, 0.0001f, 1.0f, 0.5f,0.0f,in_game_message_class::alpha);
    if (in_game_message_class::image == texture.rubidium_shields.ref_number)      texture.rubidium_shields.draw     (false, 0.0f, 0.0f, 0.0001f, 1.0f, 0.5f,0.0f,in_game_message_class::alpha);
    if (in_game_message_class::image == texture.seismic_thrusters.ref_number)     texture.seismic_thrusters.draw    (false, 0.0f, 0.0f, 0.0001f, 1.0f, 0.5f,0.0f,in_game_message_class::alpha);
    if (in_game_message_class::image == texture.shield_level_up.ref_number)       texture.shield_level_up.draw      (false, 0.0f, 0.0f, 0.0001f, 1.0f, 0.5f,0.0f,in_game_message_class::alpha);
    if (in_game_message_class::image == texture.tantalum_shields.ref_number)      texture.tantalum_shields.draw     (false, 0.0f, 0.0f, 0.0001f, 1.0f, 0.5f,0.0f,in_game_message_class::alpha);
    if (in_game_message_class::image == texture.terbium_shields.ref_number)       texture.terbium_shields.draw      (false, 0.0f, 0.0f, 0.0001f, 1.0f, 0.5f,0.0f,in_game_message_class::alpha);
    if (in_game_message_class::image == texture.thrusters_level_up.ref_number)    texture.thrusters_level_up.draw   (false, 0.0f, 0.0f, 0.0001f, 1.0f, 0.5f,0.0f,in_game_message_class::alpha);
    if (in_game_message_class::image == texture.vortex_thrusters.ref_number)      texture.vortex_thrusters.draw     (false, 0.0f, 0.0f, 0.0001f, 1.0f, 0.5f,0.0f,in_game_message_class::alpha);
    if (in_game_message_class::image == texture.weapon_level_up.ref_number)       texture.weapon_level_up.draw      (false, 0.0f, 0.0f, 0.0001f, 1.0f, 0.5f,0.0f,in_game_message_class::alpha);
    if (in_game_message_class::image == texture.level_completed.ref_number)       texture.level_completed.draw      (false, 0.0f, 0.0f, 0.0001f, 1.0f, 0.5f,0.0f,in_game_message_class::alpha);
};

void  in_game_message_class::process(void)
{
   if (in_game_message_class::active)
   {
      in_game_message_class::alpha  -= 0.025f;
      if (in_game_message_class::alpha <= 0) in_game_message_class::kill();
   }
};


