Star.P.G.
---------
A clasic side scrolling shooter, with added RPG elements.
www.physhexgames.co.nr
paul.wortmann@gmail.com / physhex@gmail.com


Keys:
-----

"Left"    ->    Move starship left.
"Right"   ->    Move starship right.
"Up"      ->    Move starship up.
"Down"    ->    Move starship down.
"Space"   ->    Fire weapon.
"P"       ->    Pause / Resume.
"ESC"	  ->    Menu, Quit.

---------------------------------------- Change log ---------------------------------------
V0.13 - (xx-xx-2011)
Fixed bug in save/load game 4.
Many tweaks and bug fixes.
Fixed background bug.
Added spawn formations.
LOC - 9131

V0.12 - (09-01-2011)
Player death screen.
End of level stats screen.
Victory conditions.
25/25 ships completed.
30/30 projectiles completed.
Thruster and shield systems integrated.
Game music added, in-game and menu.
Many tweaks and bug fixes.
LOC - 8049

V0.11 - (01-01-2011)
Improved starship custimization.
FPS counter.
More on-screen information.
Many tweaks  and bug fixes.
Achievement system implemented.
All 25 levels completed.
Multiple enemy movement modes.
Menu and code improvements.
LOC - 6201

V0.10 - (10-10-2010)
Customization of starship, experience based weapons.
Save and Load game implemented.
System log implemented.
Pause/Resume game implemented.
Collision detection improved.
Powerups implemented.
LOC - 4828

V0.03 - (23-09-2010)
Fixed overlay texture rendering bug.
Added stackable health bars for NPCs.
Improved rendering system.

v0.02 - (21-09-2010)
Game mechanics created.
Weapon system and explosions created.
Added NPCs and score.

v0.01 - (19-09-2010)
Initial release.
Menu textures created. 
Menu system created.
Parallax backgrounds.
Sound and music system.

------------------------------------- Credits / Info -----------------------------------------

---------------------------------------------------
  Design, programming and almost everything else...
---------------------------------------------------
www.physhexgames.co.nr
Paul Wortmann paul.wortmann@gmail.com / physhex@gmail.com

---------------------
  Beta testers
---------------------
Ded
Cantide

---------------------
  Graphics
---------------------
Buttons generated with http://cooltext.com/
Most backgrounds were renderd with Genetica Viewer 3.51.2181 Copyright (c) 2006-2010 Spiral Graphics Inc.
Many graphics were created and/or modified with GIMP. (http://www.gimp.org/)

---------
  Sound
---------

---------
  Music
---------
level_00.s3m from http://virt.vgmix.com (v-blast.s3m)
level_01.s3m from http://virt.vgmix.com (v-bogey.s3m)
level_02.s3m from http://virt.vgmix.com (v-falcon.s3m)
level_03.s3m from http://virt.vgmix.com (v-ptime.s3m)
level_04.s3m from http://virt.vgmix.com (v-option.s3m)
level_05.s3m from http://virt.vgmix.com (v-shock.s3m)
level_06.s3m from http://www.lpchip.com/home/ (JimTonic.s3m)
level_07.it  from http://www.lpchip.com/home/ (baseline.it)
level_08.s3m from http://modarchive.org (alpha_c_-_rat_race.it)
level_09.s3m from http://modarchive.org (ko0x_alpha-c_-_march_of_the_ants.it)
level_10.s3m from http://modarchive.org (alpha_c_-_the_martian_groove.it)
level_11.s3m from http://modarchive.org (dear_daisy.it)
level_12.mod from http://www.scene.org (SD10-Untitled_Chip4.mod)
level_13.mod from http://www.scene.org (SD10-Untitled_Chip5.mod)
level_14.mod from http://www.scene.org (SD10-Untitled_Chip6.mod)
level_15.mod from http://www.scene.org (SD10-Untitled_Chip7.mod)
level_16.mod from http://www.scene.org (AnarchyMenu1.mod)
level_17.mod from http://www.scene.org (Beachhead_2.mod)
level_18.mod from http://www.scene.org (4-Mats_Madness.mod)
level_19.mod from http://www.scene.org (Menu_Loader.mod)
level_20.mod from http://www.scene.org (FartingKippers_Ahoy.mod)
level_21.mod from http://www.scene.org (LMM.mod)
level_22.mod from http://www.scene.org (Madness.mod)
level_23.mod from http://www.scene.org (Madness_2.mod)
level_24.mod from http://www.scene.org (Dna-dream.mod)
level_25.mod from http://www.scene.org (Electric_Revenge.mod)

level_pd.mod from http://www.scene.org (Chip_Shop.mod)
level_nl.mod from http://www.scene.org (Cardiaxx-HiScore.mod)
menu_00.it   from http://www.lpchip.com/home/ (Wisdom of Purety - Looped.it)


3rd party API's.
---------------------------
SDL         - http://www.libsdl.org/
FreeType    - http://www.freetype.org/
PhysicsFS   - http://icculus.org/physfs/

Mikmod      - http://mikmod.raphnet.net/
Libtiff     - http://www.libtiff.org/
Libpng      - http://www.libpng.org/
Smpeg       - http://www.lokigames.com/development/smpeg.php3

3rd party copyright notice.
---------------------------

Some of the resources are derived from works found on the internet. 
To the best of my knowledge these resources are either in the public domain, or have a licence permitting there use in such a project.
If however I am in error, please contact me (paul.wortmann@gmail.com) and I will remove the resource from this game imidiatly!

Legal
-----
This is an open-source, non-comercial application. (if you paid for it get a refund!)
You are free to copy and share this application under the GPL v2.0 (the file gpl.txt has been included)
Please note that the music was not created by me, not the included API's, and I do not hold the copyright to them.

/* Copyright (C) 2011 PhysHex Games.
 * This file is part of Star.P.G.
 *
 * Star.P.G. is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * Star.P.G. is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Star.P.G. If not, see <http://www.gnu.org/licenses/>.
 */
