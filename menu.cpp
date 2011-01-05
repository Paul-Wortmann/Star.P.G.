#include <gl/gl.h>
#include "menu.h"
#include "game.h"
#include "config.h"
#include "sounds.h"
#include "music.h"
#include "textures.h"
#include "levels.h"
#include "font.h"

extern config_data_type config_data;
extern sound_type sound[MAX_SOUNDS];
extern music_type music[MAX_MUSIC];
extern texture_type texture[MAX_TEXTURES];
extern game_type game;
       menu_type menu;

int process_menu(void)
{
// -------------------------   background 0  -----------------------------------
   if (menu.background_scroll[0].x_dir == 0)
   {
      menu.background_scroll[0].x_pos -= menu.background_scroll[0].scroll_rate;
      if (menu.background_scroll[0].x_pos < 0.0f) menu.background_scroll[0].x_dir = 1;
   }
   if (menu.background_scroll[0].x_dir == 1)
   {
      menu.background_scroll[0].x_pos += menu.background_scroll[0].scroll_rate;
      if (menu.background_scroll[0].x_pos > 1.0f) menu.background_scroll[0].x_dir = 0;
   }

   if (menu.background_scroll[0].y_dir == 0)
   {
      menu.background_scroll[0].y_pos -= menu.background_scroll[0].scroll_rate;
      if (menu.background_scroll[0].y_pos < 0.0f) menu.background_scroll[0].y_dir = 1;
   }
   if (menu.background_scroll[0].y_dir == 1)
   {
      menu.background_scroll[0].y_pos += menu.background_scroll[0].scroll_rate;
      if (menu.background_scroll[0].y_pos > 0.75f) menu.background_scroll[0].y_dir = 0;
   }
// -------------------------   background 1  -----------------------------------
   if (menu.background_scroll[1].x_dir == 0)
   {
      menu.background_scroll[1].x_pos -= menu.background_scroll[1].scroll_rate;
      if (menu.background_scroll[1].x_pos < 0.0f) menu.background_scroll[1].x_dir = 1;
   }
   if (menu.background_scroll[1].x_dir == 1)
   {
      menu.background_scroll[1].x_pos += menu.background_scroll[1].scroll_rate;
      if (menu.background_scroll[1].x_pos > 1.0f) menu.background_scroll[1].x_dir = 0;
   }

   if (menu.background_scroll[1].y_dir == 0)
   {
      menu.background_scroll[1].y_pos -= menu.background_scroll[1].scroll_rate;
      if (menu.background_scroll[1].y_pos < 0.0f) menu.background_scroll[1].y_dir = 1;
   }
   if (menu.background_scroll[1].y_dir == 1)
   {
      menu.background_scroll[1].y_pos += menu.background_scroll[1].scroll_rate;
      if (menu.background_scroll[1].y_pos > 0.75f) menu.background_scroll[1].y_dir = 0;
   }
   return(0);
};

int init_menu   (void)
{
   menu.level_no                          = 0;
   menu.possition                         = 0;
   menu.level                             = 0;
   menu.possition_max                     = 4;
   menu.background_scroll[0].x_dir        = 0;
   menu.background_scroll[0].y_dir        = 0;
   menu.background_scroll[0].x_pos        = 0.0f;
   menu.background_scroll[0].y_pos        = 0.0f;
   menu.background_scroll[0].scroll_rate  = 0.0005f;
   menu.background_scroll[1].x_dir        = 1;
   menu.background_scroll[1].y_dir        = 1;
   menu.background_scroll[1].x_pos        = 0.0f;
   menu.background_scroll[1].y_pos        = 0.0f;
   menu.background_scroll[1].scroll_rate  = 0.001f;
   return(0);
};

int diplay_menu (void)
{
/*-----------------------------------------------------------------------------*/
   if (menu.level == 0) //main_menu
   {
      glBindTexture( GL_TEXTURE_2D, texture[63].texture); //background 01
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-2.0f + menu.background_scroll[0].x_pos,-2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 0, 0 );glVertex3f(-2.0f + menu.background_scroll[0].x_pos, 2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 1, 0 );glVertex3f( 2.0f + menu.background_scroll[0].x_pos, 2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 1, 1 );glVertex3f( 2.0f + menu.background_scroll[0].x_pos,-2.0f + menu.background_scroll[0].y_pos, 0.15f );
      glEnd();

      glBindTexture( GL_TEXTURE_2D, texture[64].texture); //background 02
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-2.0f + menu.background_scroll[1].x_pos,-2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 0, 0 );glVertex3f(-2.0f + menu.background_scroll[1].x_pos, 2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 1, 0 );glVertex3f( 2.0f + menu.background_scroll[1].x_pos, 2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 1, 1 );glVertex3f( 2.0f + menu.background_scroll[1].x_pos,-2.0f + menu.background_scroll[1].y_pos, 0.1f );
      glEnd();

      glBindTexture( GL_TEXTURE_2D, texture[30].texture); //logo
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.9f, 0.75f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.9f, 1.0f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.9f, 1.0f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.9f, 0.75f, 0.0f );
      glEnd();

      if (menu.possition == 0) glBindTexture( GL_TEXTURE_2D, texture[36].texture); //new game highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[35].texture); //new game
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.4f, 0.4f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f, 0.6f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f, 0.6f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f, 0.4f, 0.0f );
      glEnd();

      if (menu.possition == 1) glBindTexture( GL_TEXTURE_2D, texture[50].texture); //resume game highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[49].texture); //resume game
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 1 );glVertex3f(-0.4f, 0.15f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f, 0.35f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f, 0.35f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f, 0.15f, 0.0f );
      glEnd();

      if (menu.possition == 2) glBindTexture( GL_TEXTURE_2D, texture[29].texture); //load game highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[28].texture); //load game
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 1 );glVertex3f(-0.4f,-0.1f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f, 0.1f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f, 0.1f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f,-0.1f, 0.0f );
      glEnd();

      if (menu.possition == 3) glBindTexture( GL_TEXTURE_2D, texture[44].texture); //options highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[43].texture); //options
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 1 );glVertex3f(-0.4f,-0.35f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f,-0.15f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f,-0.15f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f,-0.35f, 0.0f );
      glEnd();

      if (menu.possition == 4) glBindTexture( GL_TEXTURE_2D, texture[46].texture); //quit highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[45].texture); //quit
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.4f,-0.85f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f,-0.65f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f,-0.65f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f,-0.85f, 0.0f );
      glEnd();
   }
/*-----------------------------------------------------------------------------*/

   if (menu.level == 1) //game_menu
   {
      glBindTexture( GL_TEXTURE_2D, texture[63].texture); //background 01
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-2.0f + menu.background_scroll[0].x_pos,-2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 0, 0 );glVertex3f(-2.0f + menu.background_scroll[0].x_pos, 2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 1, 0 );glVertex3f( 2.0f + menu.background_scroll[0].x_pos, 2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 1, 1 );glVertex3f( 2.0f + menu.background_scroll[0].x_pos,-2.0f + menu.background_scroll[0].y_pos, 0.15f );
      glEnd();

      glBindTexture( GL_TEXTURE_2D, texture[64].texture); //background 02
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-2.0f + menu.background_scroll[1].x_pos,-2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 0, 0 );glVertex3f(-2.0f + menu.background_scroll[1].x_pos, 2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 1, 0 );glVertex3f( 2.0f + menu.background_scroll[1].x_pos, 2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 1, 1 );glVertex3f( 2.0f + menu.background_scroll[1].x_pos,-2.0f + menu.background_scroll[1].y_pos, 0.1f );
      glEnd();

      glBindTexture( GL_TEXTURE_2D, texture[27].texture); //logo - game menu
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.9f, 0.75f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.9f, 1.0f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.9f, 1.0f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.9f, 0.75f, 0.0f );
      glEnd();

      if (menu.possition == 0) glBindTexture( GL_TEXTURE_2D, texture[299].texture); //achievements highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[298].texture); //achievements
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.4f, 0.55f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f, 0.75f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f, 0.75f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f, 0.55f, 0.0f );
      glEnd();

      if (menu.possition == 1) glBindTexture( GL_TEXTURE_2D, texture[60].texture); //starmap highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[59].texture); //starmap
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.4f, 0.3f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f, 0.5f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f, 0.5f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f, 0.3f, 0.0f );
      glEnd();

      if (menu.possition == 2) glBindTexture( GL_TEXTURE_2D, texture[21].texture); //customize starship highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[20].texture); //customize starship
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 1 );glVertex3f(-0.4f, 0.05f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f, 0.25f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f, 0.25f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f, 0.05f, 0.0f );
      glEnd();

      if (menu.possition == 3) glBindTexture( GL_TEXTURE_2D, texture[50].texture); //resume game highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[49].texture); //resume game
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 1 );glVertex3f(-0.4f,-0.2f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f, 0.0f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f, 0.0f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f,-0.2f, 0.0f );
      glEnd();

      if (menu.possition == 4) glBindTexture( GL_TEXTURE_2D, texture[52].texture); //save game highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[51].texture); //save game
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 1 );glVertex3f(-0.4f,-0.45f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f,-0.25f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f,-0.25f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f,-0.45f, 0.0f );
      glEnd();

      if (menu.possition == 5) glBindTexture( GL_TEXTURE_2D, texture[29].texture); //load game highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[28].texture); //load game
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 1 );glVertex3f(-0.4f,-0.7f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f,-0.5f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f,-0.5f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f,-0.7f, 0.0f );
      glEnd();

      if (menu.possition == 6) glBindTexture( GL_TEXTURE_2D, texture[32].texture); //main menu highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[31].texture); //main menu
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.4f,-0.95f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f,-0.75f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f,-0.75f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f,-0.95f, 0.0f );
      glEnd();
   }
/*-----------------------------------------------------------------------------*/

   if (menu.level == 2) //options_menu
   {
      glBindTexture( GL_TEXTURE_2D, texture[63].texture); //background 01
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-2.0f + menu.background_scroll[0].x_pos,-2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 0, 0 );glVertex3f(-2.0f + menu.background_scroll[0].x_pos, 2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 1, 0 );glVertex3f( 2.0f + menu.background_scroll[0].x_pos, 2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 1, 1 );glVertex3f( 2.0f + menu.background_scroll[0].x_pos,-2.0f + menu.background_scroll[0].y_pos, 0.15f );
      glEnd();

      glBindTexture( GL_TEXTURE_2D, texture[64].texture); //background 02
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-2.0f + menu.background_scroll[1].x_pos,-2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 0, 0 );glVertex3f(-2.0f + menu.background_scroll[1].x_pos, 2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 1, 0 );glVertex3f( 2.0f + menu.background_scroll[1].x_pos, 2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 1, 1 );glVertex3f( 2.0f + menu.background_scroll[1].x_pos,-2.0f + menu.background_scroll[1].y_pos, 0.1f );
      glEnd();

      glBindTexture( GL_TEXTURE_2D, texture[44].texture); //logo
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.9f, 0.75f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.9f, 1.0f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.9f, 1.0f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.9f, 0.75f, 0.0f );
      glEnd();

      if (menu.possition == 0) glBindTexture( GL_TEXTURE_2D, texture[58].texture); //Sound Volume highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[57].texture); //Sound Volume
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.8f, 0.55f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.8f, 0.75f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.0f, 0.75f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.0f, 0.55f, 0.0f );
      glEnd();

      if (menu.possition == 0) glBindTexture( GL_TEXTURE_2D, texture[17].texture); //Sound Volume bar highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[16].texture); //Sound Volume bar
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f((config_data.Audio_Sound_Volume / 160.0f), 0.55f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f((config_data.Audio_Sound_Volume / 160.0f), 0.75f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.0f, 0.75f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.0f, 0.55f, 0.0f );
      glEnd();

      if (menu.possition == 1) glBindTexture( GL_TEXTURE_2D, texture[34].texture); //Music Volume highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[33].texture); //Music Volume
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 1 );glVertex3f(-0.8f, 0.30f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.8f, 0.50f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.0f, 0.50f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.0f, 0.30f, 0.0f );
      glEnd();

      if (menu.possition == 1) glBindTexture( GL_TEXTURE_2D, texture[17].texture); //Music Volume bar highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[16].texture); //Music Volume bar
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 1 );glVertex3f((config_data.Audio_Music_Volume / 160.0f), 0.30f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f((config_data.Audio_Music_Volume / 160.0f), 0.50f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.0f, 0.50f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.0f, 0.30f, 0.0f );
      glEnd();

      if (menu.possition == 2) glBindTexture( GL_TEXTURE_2D, texture[25].texture); //Fullscreen highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[24].texture); //Fullscreen
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 1 );glVertex3f(-0.8f, 0.05f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.8f, 0.25f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.0f, 0.25f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.0f, 0.05f, 0.0f );
      glEnd();

      if ((menu.possition == 2) && (config_data.Display_Fullscreen == false)) glBindTexture( GL_TEXTURE_2D, texture[38].texture); //Fullscreen off highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[37].texture); //Fullscreen off
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 1 );glVertex3f( 0.0f, 0.05f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.0f, 0.25f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f, 0.25f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f, 0.05f, 0.0f );
      glEnd();

      if ((menu.possition == 2) && (config_data.Display_Fullscreen == true)) glBindTexture( GL_TEXTURE_2D, texture[40].texture); //Fullscreen on highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[39].texture); //Fullscreen on
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 1 );glVertex3f( 0.4f, 0.05f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.4f, 0.25f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.8f, 0.25f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.8f, 0.05f, 0.0f );
      glEnd();

      if (menu.possition == 3) glBindTexture( GL_TEXTURE_2D, texture[48].texture); //Resolution highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[47].texture); //Resolution
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 1 );glVertex3f(-0.8f,-0.20f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.8f, 0.00f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.0f, 0.00f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.0f,-0.20f, 0.0f );
      glEnd();

      if ((menu.possition == 3) && (config_data.Display_resolution == 0)) glBindTexture( GL_TEXTURE_2D, texture[13].texture); //640x480 highlighted
      if ((menu.possition != 3) && (config_data.Display_resolution == 0)) glBindTexture( GL_TEXTURE_2D, texture[12].texture); //640x480 Resolution
      if ((menu.possition == 3) && (config_data.Display_resolution == 1)) glBindTexture( GL_TEXTURE_2D, texture[15].texture); //800x600 highlighted
      if ((menu.possition != 3) && (config_data.Display_resolution == 1)) glBindTexture( GL_TEXTURE_2D, texture[14].texture); //800x600 Resolution
      if ((menu.possition == 3) && (config_data.Display_resolution == 2)) glBindTexture( GL_TEXTURE_2D, texture[1].texture); //1024x768 highlighted
      if ((menu.possition != 3) && (config_data.Display_resolution == 2)) glBindTexture( GL_TEXTURE_2D, texture[0].texture); //1024x768 Resolution
      if ((menu.possition == 3) && (config_data.Display_resolution == 3)) glBindTexture( GL_TEXTURE_2D, texture[3].texture); //1280x1024 highlighted
      if ((menu.possition != 3) && (config_data.Display_resolution == 3)) glBindTexture( GL_TEXTURE_2D, texture[2].texture); //1280x1024 Resolution
      if ((menu.possition == 3) && (config_data.Display_resolution == 4)) glBindTexture( GL_TEXTURE_2D, texture[5].texture); //1366x768 highlighted
      if ((menu.possition != 3) && (config_data.Display_resolution == 4)) glBindTexture( GL_TEXTURE_2D, texture[4].texture); //1366x768 Resolution
      if ((menu.possition == 3) && (config_data.Display_resolution == 5)) glBindTexture( GL_TEXTURE_2D, texture[7].texture); //1440x900 highlighted
      if ((menu.possition != 3) && (config_data.Display_resolution == 5)) glBindTexture( GL_TEXTURE_2D, texture[6].texture); //1440x900 Resolution
      if ((menu.possition == 3) && (config_data.Display_resolution == 6)) glBindTexture( GL_TEXTURE_2D, texture[9].texture); //1680x1050 highlighted
      if ((menu.possition != 3) && (config_data.Display_resolution == 6)) glBindTexture( GL_TEXTURE_2D, texture[8].texture); //1680x1050 Resolution
      if ((menu.possition == 3) && (config_data.Display_resolution == 7)) glBindTexture( GL_TEXTURE_2D, texture[11].texture); //1920x1080 highlighted
      if ((menu.possition != 3) && (config_data.Display_resolution == 7)) glBindTexture( GL_TEXTURE_2D, texture[10].texture); //1920x1080 Resolution
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 1 );glVertex3f( 0.0f,-0.20f, 0.0f );
      glTexCoord2i( 0, 0 );glVertex3f( 0.0f, 0.00f, 0.0f );
      glTexCoord2i( 1, 0 );glVertex3f( 0.8f, 0.00f, 0.0f );
      glTexCoord2i( 1, 1 );glVertex3f( 0.8f,-0.20f, 0.0f );
      glEnd();

      if (menu.possition == 4) glBindTexture( GL_TEXTURE_2D, texture[32].texture); //main menu highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[31].texture); //main menu
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.4f,-0.95f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f,-0.75f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f,-0.75f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f,-0.95f, 0.0f );
      glEnd();
   }
/*-----------------------------------------------------------------------------*/

   if (menu.level == 3) //customize_starship_menu
   {
      float ship_pos_x =  0.0f;
      float ship_pos_y = -0.5f;

      glBindTexture( GL_TEXTURE_2D, texture[63].texture); //background 01
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-2.0f + menu.background_scroll[0].x_pos,-2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 0, 0 );glVertex3f(-2.0f + menu.background_scroll[0].x_pos, 2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 1, 0 );glVertex3f( 2.0f + menu.background_scroll[0].x_pos, 2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 1, 1 );glVertex3f( 2.0f + menu.background_scroll[0].x_pos,-2.0f + menu.background_scroll[0].y_pos, 0.15f );
      glEnd();

      glBindTexture( GL_TEXTURE_2D, texture[64].texture); //background 02
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-2.0f + menu.background_scroll[1].x_pos,-2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 0, 0 );glVertex3f(-2.0f + menu.background_scroll[1].x_pos, 2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 1, 0 );glVertex3f( 2.0f + menu.background_scroll[1].x_pos, 2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 1, 1 );glVertex3f( 2.0f + menu.background_scroll[1].x_pos,-2.0f + menu.background_scroll[1].y_pos, 0.1f );
      glEnd();

      glBindTexture( GL_TEXTURE_2D, texture[21].texture); //logo - customize startship menu
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.9f, 0.75f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.9f, 1.00f, 0.05f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.9f, 1.00f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.9f, 0.75f, 0.05f );
      glEnd();

      if (menu.possition == 0) glBindTexture( GL_TEXTURE_2D, texture[23].texture); //front weapon highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[22].texture); //front weapon
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-1.0f, 0.65f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f(-1.0f, 0.75f, 0.05f );
	  glTexCoord2i( 1, 0 );glVertex3f(-0.4f, 0.75f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f(-0.4f, 0.65f, 0.05f );
      glEnd();

      glBindTexture( GL_TEXTURE_2D, texture[283].texture); //weapon none
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f(-0.2f, 0.65f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f(-0.2f, 0.75f, 0.05f );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.3f, 0.75f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.3f, 0.65f, 0.05f );
      glEnd();

      if (game.player.front_weapon == -1)
      {
         glBindTexture( GL_TEXTURE_2D, texture[282].texture); //weapon none highlighted
         glLoadIdentity();
         glBegin( GL_QUADS );
	     glTexCoord2i( 1, 0 );glVertex3f(-0.2f, 0.65f, 0.04f );
	     glTexCoord2i( 1, 1 );glVertex3f(-0.2f, 0.75f, 0.04f );
	     glTexCoord2i( 0, 1 );glVertex3f(-0.3f, 0.75f, 0.04f );
	     glTexCoord2i( 0, 0 );glVertex3f(-0.3f, 0.65f, 0.04f );
         glEnd();
      }

      if (game.projectile[0].active) glBindTexture( GL_TEXTURE_2D, texture[game.projectile[0].image].texture); //weapon 0
      else glBindTexture( GL_TEXTURE_2D, texture[284].texture);
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f(-0.05f, 0.65f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f(-0.05f, 0.75f, 0.05f );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.15f, 0.75f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.15f, 0.65f, 0.05f );
      glEnd();

      if (game.player.front_weapon == 0)
      {
         glBindTexture( GL_TEXTURE_2D, texture[282].texture); //weapon 0 highlighted
         glLoadIdentity();
         glBegin( GL_QUADS );
	     glTexCoord2i( 1, 0 );glVertex3f(-0.05f, 0.65f, 0.04f );
	     glTexCoord2i( 1, 1 );glVertex3f(-0.05f, 0.75f, 0.04f );
   	     glTexCoord2i( 0, 1 );glVertex3f(-0.15f, 0.75f, 0.04f );
	     glTexCoord2i( 0, 0 );glVertex3f(-0.15f, 0.65f, 0.04f );
         glEnd();
      }

      if (game.projectile[1].active) glBindTexture( GL_TEXTURE_2D, texture[game.projectile[1].image].texture); //weapon 1
      else glBindTexture( GL_TEXTURE_2D, texture[284].texture);
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.10f, 0.65f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.10f, 0.75f, 0.05f );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.00f, 0.75f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.00f, 0.65f, 0.05f );
      glEnd();

      if (game.player.front_weapon == 1)
      {
         glBindTexture( GL_TEXTURE_2D, texture[282].texture); //weapon 1 highlighted
         glLoadIdentity();
         glBegin( GL_QUADS );
   	     glTexCoord2i( 1, 0 );glVertex3f( 0.10f, 0.65f, 0.04f );
	     glTexCoord2i( 1, 1 );glVertex3f( 0.10f, 0.75f, 0.04f );
	     glTexCoord2i( 0, 1 );glVertex3f( 0.00f, 0.75f, 0.04f );
	     glTexCoord2i( 0, 0 );glVertex3f( 0.00f, 0.65f, 0.04f );
         glEnd();
      }

      if (game.projectile[2].active) glBindTexture( GL_TEXTURE_2D, texture[game.projectile[2].image].texture); //weapon 2
      else glBindTexture( GL_TEXTURE_2D, texture[284].texture);
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.25f, 0.65f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.25f, 0.75f, 0.05f );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.15f, 0.75f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.15f, 0.65f, 0.05f );
      glEnd();

      if (game.player.front_weapon == 2)
      {
         glBindTexture( GL_TEXTURE_2D, texture[282].texture); //weapon 2 highlighted
         glLoadIdentity();
         glBegin( GL_QUADS );
	     glTexCoord2i( 1, 0 );glVertex3f( 0.25f, 0.65f, 0.04f );
	     glTexCoord2i( 1, 1 );glVertex3f( 0.25f, 0.75f, 0.04f );
	     glTexCoord2i( 0, 1 );glVertex3f( 0.15f, 0.75f, 0.04f );
	     glTexCoord2i( 0, 0 );glVertex3f( 0.15f, 0.65f, 0.04f );
         glEnd();
      }

      if (game.projectile[3].active) glBindTexture( GL_TEXTURE_2D, texture[game.projectile[3].image].texture); //weapon 3
      else glBindTexture( GL_TEXTURE_2D, texture[284].texture);
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.40f, 0.65f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.40f, 0.75f, 0.05f );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.30f, 0.75f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.30f, 0.65f, 0.05f );
      glEnd();

      if (game.player.front_weapon == 3)
      {
         glBindTexture( GL_TEXTURE_2D, texture[282].texture); //weapon 3 highlighted
         glLoadIdentity();
         glBegin( GL_QUADS );
	     glTexCoord2i( 1, 0 );glVertex3f( 0.40f, 0.65f, 0.04f );
	     glTexCoord2i( 1, 1 );glVertex3f( 0.40f, 0.75f, 0.04f );
	     glTexCoord2i( 0, 1 );glVertex3f( 0.30f, 0.75f, 0.04f );
	     glTexCoord2i( 0, 0 );glVertex3f( 0.30f, 0.65f, 0.04f );
         glEnd();
      }

      if (game.projectile[4].active) glBindTexture( GL_TEXTURE_2D, texture[game.projectile[4].image].texture); //weapon 4
      else glBindTexture( GL_TEXTURE_2D, texture[284].texture);
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.55f, 0.65f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.55f, 0.75f, 0.05f );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.45f, 0.75f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.45f, 0.65f, 0.05f );
      glEnd();

      if (game.player.front_weapon == 4)
      {
         glBindTexture( GL_TEXTURE_2D, texture[282].texture); //weapon 4 highlighted
         glLoadIdentity();
         glBegin( GL_QUADS );
	     glTexCoord2i( 1, 0 );glVertex3f( 0.55f, 0.65f, 0.04f );
	     glTexCoord2i( 1, 1 );glVertex3f( 0.55f, 0.75f, 0.04f );
	     glTexCoord2i( 0, 1 );glVertex3f( 0.45f, 0.75f, 0.04f );
	     glTexCoord2i( 0, 0 );glVertex3f( 0.45f, 0.65f, 0.04f );
         glEnd();
      }

      if (game.projectile[5].active) glBindTexture( GL_TEXTURE_2D, texture[game.projectile[5].image].texture); //weapon 5
      else glBindTexture( GL_TEXTURE_2D, texture[284].texture);
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.70f, 0.65f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.70f, 0.75f, 0.05f );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.60f, 0.75f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.60f, 0.65f, 0.05f );
      glEnd();

      if (game.player.front_weapon == 5)
      {
         glBindTexture( GL_TEXTURE_2D, texture[282].texture); //weapon 5 highlighted
         glLoadIdentity();
         glBegin( GL_QUADS );
	     glTexCoord2i( 1, 0 );glVertex3f( 0.70f, 0.65f, 0.04f );
	     glTexCoord2i( 1, 1 );glVertex3f( 0.70f, 0.75f, 0.04f );
	     glTexCoord2i( 0, 1 );glVertex3f( 0.60f, 0.75f, 0.04f );
	     glTexCoord2i( 0, 0 );glVertex3f( 0.60f, 0.65f, 0.04f );
         glEnd();
      }

      if (menu.possition == 1) glBindTexture( GL_TEXTURE_2D, texture[56].texture); //side weapon highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[55].texture); //side weapon
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-1.0f, 0.50f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f(-1.0f, 0.60f, 0.05f );
	  glTexCoord2i( 1, 0 );glVertex3f(-0.4f, 0.60f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f(-0.4f, 0.50f, 0.05f );
      glEnd();

      glBindTexture( GL_TEXTURE_2D, texture[283].texture); //weapon none
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f(-0.2f, 0.50f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f(-0.2f, 0.60f, 0.05f );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.3f, 0.60f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.3f, 0.50f, 0.05f );
      glEnd();

      if (game.player.side_weapon == -1)
      {
         glBindTexture( GL_TEXTURE_2D, texture[282].texture); //weapon none highlighted
         glLoadIdentity();
         glBegin( GL_QUADS );
	     glTexCoord2i( 1, 0 );glVertex3f(-0.2f, 0.50f, 0.04f );
	     glTexCoord2i( 1, 1 );glVertex3f(-0.2f, 0.60f, 0.04f );
	     glTexCoord2i( 0, 1 );glVertex3f(-0.3f, 0.60f, 0.04f );
	     glTexCoord2i( 0, 0 );glVertex3f(-0.3f, 0.50f, 0.04f );
         glEnd();
      }

      if (game.projectile[0].active) glBindTexture( GL_TEXTURE_2D, texture[game.projectile[0].image].texture); //weapon 0
      else glBindTexture( GL_TEXTURE_2D, texture[284].texture);
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f(-0.05f, 0.50f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f(-0.05f, 0.60f, 0.05f );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.15f, 0.60f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.15f, 0.50f, 0.05f );
      glEnd();

      if (game.player.side_weapon == 0)
      {
         glBindTexture( GL_TEXTURE_2D, texture[282].texture); //weapon 0 highlighted
         glLoadIdentity();
         glBegin( GL_QUADS );
	     glTexCoord2i( 1, 0 );glVertex3f(-0.05f, 0.50f, 0.04f );
	     glTexCoord2i( 1, 1 );glVertex3f(-0.05f, 0.60f, 0.04f );
	     glTexCoord2i( 0, 1 );glVertex3f(-0.15f, 0.60f, 0.04f );
	     glTexCoord2i( 0, 0 );glVertex3f(-0.15f, 0.50f, 0.04f );
         glEnd();
      }

      if (game.projectile[1].active) glBindTexture( GL_TEXTURE_2D, texture[game.projectile[1].image].texture); //weapon 1
      else glBindTexture( GL_TEXTURE_2D, texture[284].texture);
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.10f, 0.50f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.10f, 0.60f, 0.05f );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.00f, 0.60f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.00f, 0.50f, 0.05f );
      glEnd();

      if (game.player.side_weapon == 1)
      {
         glBindTexture( GL_TEXTURE_2D, texture[282].texture); //weapon 1 highlighted
         glLoadIdentity();
         glBegin( GL_QUADS );
	     glTexCoord2i( 1, 0 );glVertex3f( 0.10f, 0.50f, 0.04f );
	     glTexCoord2i( 1, 1 );glVertex3f( 0.10f, 0.60f, 0.04f );
	     glTexCoord2i( 0, 1 );glVertex3f( 0.00f, 0.60f, 0.04f );
	     glTexCoord2i( 0, 0 );glVertex3f( 0.00f, 0.50f, 0.04f );
         glEnd();
      }

      if (game.projectile[2].active) glBindTexture( GL_TEXTURE_2D, texture[game.projectile[2].image].texture); //weapon 2
      else glBindTexture( GL_TEXTURE_2D, texture[284].texture);
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.25f, 0.50f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.25f, 0.60f, 0.05f );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.15f, 0.60f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.15f, 0.50f, 0.05f );
      glEnd();

      if (game.player.side_weapon == 2)
      {
         glBindTexture( GL_TEXTURE_2D, texture[282].texture); //weapon 2 highlighted
         glLoadIdentity();
         glBegin( GL_QUADS );
	     glTexCoord2i( 1, 0 );glVertex3f( 0.25f, 0.50f, 0.04f );
	     glTexCoord2i( 1, 1 );glVertex3f( 0.25f, 0.60f, 0.04f );
	     glTexCoord2i( 0, 1 );glVertex3f( 0.15f, 0.60f, 0.04f );
	     glTexCoord2i( 0, 0 );glVertex3f( 0.15f, 0.50f, 0.04f );
         glEnd();
      }

      if (game.projectile[3].active) glBindTexture( GL_TEXTURE_2D, texture[game.projectile[3].image].texture); //weapon 3
      else glBindTexture( GL_TEXTURE_2D, texture[284].texture);
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.40f, 0.50f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.40f, 0.60f, 0.05f );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.30f, 0.60f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.30f, 0.50f, 0.05f );
      glEnd();

      if (game.player.side_weapon == 3)
      {
         glBindTexture( GL_TEXTURE_2D, texture[282].texture); //weapon 3 highlighted
         glLoadIdentity();
         glBegin( GL_QUADS );
	     glTexCoord2i( 1, 0 );glVertex3f( 0.40f, 0.50f, 0.04f );
	     glTexCoord2i( 1, 1 );glVertex3f( 0.40f, 0.60f, 0.04f );
	     glTexCoord2i( 0, 1 );glVertex3f( 0.30f, 0.60f, 0.04f );
	     glTexCoord2i( 0, 0 );glVertex3f( 0.30f, 0.50f, 0.04f );
         glEnd();
      }

      if (game.projectile[4].active) glBindTexture( GL_TEXTURE_2D, texture[game.projectile[4].image].texture); //weapon 4
      else glBindTexture( GL_TEXTURE_2D, texture[284].texture);
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.55f, 0.50f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.55f, 0.60f, 0.05f );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.45f, 0.60f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.45f, 0.50f, 0.05f );
      glEnd();

      if (game.player.side_weapon == 4)
      {
         glBindTexture( GL_TEXTURE_2D, texture[282].texture); //weapon 4 highlighted
         glLoadIdentity();
         glBegin( GL_QUADS );
	     glTexCoord2i( 1, 0 );glVertex3f( 0.55f, 0.50f, 0.04f );
	     glTexCoord2i( 1, 1 );glVertex3f( 0.55f, 0.60f, 0.04f );
	     glTexCoord2i( 0, 1 );glVertex3f( 0.45f, 0.60f, 0.04f );
	     glTexCoord2i( 0, 0 );glVertex3f( 0.45f, 0.50f, 0.04f );
         glEnd();
      }

      if (game.projectile[5].active) glBindTexture( GL_TEXTURE_2D, texture[game.projectile[5].image].texture); //weapon 5
      else glBindTexture( GL_TEXTURE_2D, texture[284].texture);
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.70f, 0.50f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.70f, 0.60f, 0.05f );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.60f, 0.60f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.60f, 0.50f, 0.05f );
      glEnd();

      if (game.player.side_weapon == 5)
      {
         glBindTexture( GL_TEXTURE_2D, texture[282].texture); //weapon 5 highlighted
         glLoadIdentity();
         glBegin( GL_QUADS );
	     glTexCoord2i( 1, 0 );glVertex3f( 0.70f, 0.50f, 0.04f );
	     glTexCoord2i( 1, 1 );glVertex3f( 0.70f, 0.60f, 0.04f );
	     glTexCoord2i( 0, 1 );glVertex3f( 0.60f, 0.60f, 0.04f );
	     glTexCoord2i( 0, 0 );glVertex3f( 0.60f, 0.50f, 0.04f );
         glEnd();
      }

      if (menu.possition == 2) glBindTexture( GL_TEXTURE_2D, texture[54].texture); //shield highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[53].texture); //shield
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-1.0f, 0.35f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f(-1.0f, 0.45f, 0.05f );
	  glTexCoord2i( 1, 0 );glVertex3f(-0.4f, 0.45f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f(-0.4f, 0.35f, 0.05f );
      glEnd();

      glBindTexture( GL_TEXTURE_2D, texture[283].texture); //shield none
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f(-0.2f, 0.35f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f(-0.2f, 0.45f, 0.05f );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.3f, 0.45f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.3f, 0.35f, 0.05f );
      glEnd();

      if (game.player.front_shield == -1)
      {
         glBindTexture( GL_TEXTURE_2D, texture[282].texture); //shield none highlighted
         glLoadIdentity();
         glBegin( GL_QUADS );
	     glTexCoord2i( 1, 0 );glVertex3f(-0.2f, 0.35f, 0.04f );
	     glTexCoord2i( 1, 1 );glVertex3f(-0.2f, 0.45f, 0.04f );
	     glTexCoord2i( 0, 1 );glVertex3f(-0.3f, 0.45f, 0.04f );
	     glTexCoord2i( 0, 0 );glVertex3f(-0.3f, 0.35f, 0.04f );
         glEnd();
      }

      if (game.shield[0].active) glBindTexture( GL_TEXTURE_2D, texture[game.shield[0].image].texture); //shield 0
      else glBindTexture( GL_TEXTURE_2D, texture[284].texture);
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f(-0.05f, 0.35f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f(-0.05f, 0.45f, 0.05f );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.15f, 0.45f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.15f, 0.35f, 0.05f );
      glEnd();

      if (game.player.front_shield == 0)
      {
         glBindTexture( GL_TEXTURE_2D, texture[282].texture); //shield 0 highlighted
         glLoadIdentity();
         glBegin( GL_QUADS );
	     glTexCoord2i( 1, 0 );glVertex3f(-0.05f, 0.35f, 0.04f );
	     glTexCoord2i( 1, 1 );glVertex3f(-0.05f, 0.45f, 0.04f );
	     glTexCoord2i( 0, 1 );glVertex3f(-0.15f, 0.45f, 0.04f );
	     glTexCoord2i( 0, 0 );glVertex3f(-0.15f, 0.35f, 0.04f );
         glEnd();
      }

      if (game.shield[1].active) glBindTexture( GL_TEXTURE_2D, texture[game.shield[1].image].texture); //shield 1
      else glBindTexture( GL_TEXTURE_2D, texture[284].texture);
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.10f, 0.35f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.10f, 0.45f, 0.05f );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.00f, 0.45f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.00f, 0.35f, 0.05f );
      glEnd();

      if (game.player.front_shield == 1)
      {
         glBindTexture( GL_TEXTURE_2D, texture[282].texture); //shield 1 highlighted
         glLoadIdentity();
         glBegin( GL_QUADS );
	     glTexCoord2i( 1, 0 );glVertex3f( 0.10f, 0.35f, 0.04f );
	     glTexCoord2i( 1, 1 );glVertex3f( 0.10f, 0.45f, 0.04f );
	     glTexCoord2i( 0, 1 );glVertex3f( 0.00f, 0.45f, 0.04f );
	     glTexCoord2i( 0, 0 );glVertex3f( 0.00f, 0.35f, 0.04f );
         glEnd();
      }

      if (game.shield[2].active) glBindTexture( GL_TEXTURE_2D, texture[game.shield[2].image].texture); //shield 2
      else glBindTexture( GL_TEXTURE_2D, texture[284].texture);
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.25f, 0.35f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.25f, 0.45f, 0.05f );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.15f, 0.45f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.15f, 0.35f, 0.05f );
      glEnd();

      if (game.player.front_shield == 2)
      {
         glBindTexture( GL_TEXTURE_2D, texture[282].texture); //shield 2 highlighted
         glLoadIdentity();
         glBegin( GL_QUADS );
         glTexCoord2i( 1, 0 );glVertex3f( 0.25f, 0.35f, 0.04f );
         glTexCoord2i( 1, 1 );glVertex3f( 0.25f, 0.45f, 0.04f );
         glTexCoord2i( 0, 1 );glVertex3f( 0.15f, 0.45f, 0.04f );
         glTexCoord2i( 0, 0 );glVertex3f( 0.15f, 0.35f, 0.04f );
         glEnd();
      }

      if (game.shield[3].active) glBindTexture( GL_TEXTURE_2D, texture[game.shield[3].image].texture); //shield 3
      else glBindTexture( GL_TEXTURE_2D, texture[284].texture);
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.40f, 0.35f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.40f, 0.45f, 0.05f );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.30f, 0.45f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.30f, 0.35f, 0.05f );
      glEnd();

      if (game.player.front_shield == 3)
      {
         glBindTexture( GL_TEXTURE_2D, texture[282].texture); //shield 3 highlighted
         glLoadIdentity();
         glBegin( GL_QUADS );
	     glTexCoord2i( 1, 0 );glVertex3f( 0.40f, 0.35f, 0.04f );
	     glTexCoord2i( 1, 1 );glVertex3f( 0.40f, 0.45f, 0.04f );
	     glTexCoord2i( 0, 1 );glVertex3f( 0.30f, 0.45f, 0.04f );
 	     glTexCoord2i( 0, 0 );glVertex3f( 0.30f, 0.35f, 0.04f );
         glEnd();
      }

      if (game.shield[4].active) glBindTexture( GL_TEXTURE_2D, texture[game.shield[4].image].texture); //shield 4
      else glBindTexture( GL_TEXTURE_2D, texture[284].texture);
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.55f, 0.35f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.55f, 0.45f, 0.05f );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.45f, 0.45f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.45f, 0.35f, 0.05f );
      glEnd();

      if (game.player.front_shield == 4)
      {
         glBindTexture( GL_TEXTURE_2D, texture[282].texture); //shield 4 highlighted
         glLoadIdentity();
         glBegin( GL_QUADS );
	     glTexCoord2i( 1, 0 );glVertex3f( 0.55f, 0.35f, 0.04f );
	     glTexCoord2i( 1, 1 );glVertex3f( 0.55f, 0.45f, 0.04f );
	     glTexCoord2i( 0, 1 );glVertex3f( 0.45f, 0.45f, 0.04f );
	     glTexCoord2i( 0, 0 );glVertex3f( 0.45f, 0.35f, 0.04f );
         glEnd();
      }

      if (menu.possition == 3) glBindTexture( GL_TEXTURE_2D, texture[62].texture); //thrusters highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[61].texture); //thrusters
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-1.0f, 0.20f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f(-1.0f, 0.30f, 0.05f );
	  glTexCoord2i( 1, 0 );glVertex3f(-0.4f, 0.30f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f(-0.4f, 0.20f, 0.05f );
      glEnd();

      glBindTexture( GL_TEXTURE_2D, texture[283].texture); //thrusters none
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f(-0.2f, 0.20f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f(-0.2f, 0.30f, 0.05f );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.3f, 0.30f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.3f, 0.20f, 0.05f );
      glEnd();

      if (game.player.thrusters == -1)
      {
         glBindTexture( GL_TEXTURE_2D, texture[282].texture); //thrusters none highlighted
         glLoadIdentity();
         glBegin( GL_QUADS );
	     glTexCoord2i( 1, 0 );glVertex3f(-0.2f, 0.20f, 0.04f );
	     glTexCoord2i( 1, 1 );glVertex3f(-0.2f, 0.30f, 0.04f );
	     glTexCoord2i( 0, 1 );glVertex3f(-0.3f, 0.30f, 0.04f );
	     glTexCoord2i( 0, 0 );glVertex3f(-0.3f, 0.20f, 0.04f );
         glEnd();
      }

      if (game.thruster[0].active) glBindTexture( GL_TEXTURE_2D, texture[game.thruster[0].image].texture); //thrusters 0
      else glBindTexture( GL_TEXTURE_2D, texture[284].texture);
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f(-0.05f, 0.20f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f(-0.05f, 0.30f, 0.05f );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.15f, 0.30f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.15f, 0.20f, 0.05f );
      glEnd();

      if (game.player.thrusters == 0)
      {
         glBindTexture( GL_TEXTURE_2D, texture[282].texture); //thrusters 0 highlighted
         glLoadIdentity();
         glBegin( GL_QUADS );
	     glTexCoord2i( 0, 0 );glVertex3f(-0.05f, 0.20f, 0.04f );
	     glTexCoord2i( 1, 0 );glVertex3f(-0.05f, 0.30f, 0.04f );
	     glTexCoord2i( 1, 1 );glVertex3f(-0.15f, 0.30f, 0.04f );
	     glTexCoord2i( 0, 1 );glVertex3f(-0.15f, 0.20f, 0.04f );
         glEnd();
      }

      if (game.thruster[1].active) glBindTexture( GL_TEXTURE_2D, texture[game.thruster[1].image].texture); //thrusters 1
      else glBindTexture( GL_TEXTURE_2D, texture[284].texture);
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.10f, 0.20f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.10f, 0.30f, 0.05f );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.00f, 0.30f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.00f, 0.20f, 0.05f );
      glEnd();

      if (game.player.thrusters == 1)
      {
         glBindTexture( GL_TEXTURE_2D, texture[282].texture); //thrusters 1 highlighted
         glLoadIdentity();
         glBegin( GL_QUADS );
	     glTexCoord2i( 0, 0 );glVertex3f( 0.10f, 0.20f, 0.04f );
	     glTexCoord2i( 1, 0 );glVertex3f( 0.10f, 0.30f, 0.04f );
	     glTexCoord2i( 1, 1 );glVertex3f( 0.00f, 0.30f, 0.04f );
	     glTexCoord2i( 0, 1 );glVertex3f( 0.00f, 0.20f, 0.04f );
         glEnd();
      }

      if (game.thruster[2].active) glBindTexture( GL_TEXTURE_2D, texture[game.thruster[2].image].texture); //thrusters 2
      else glBindTexture( GL_TEXTURE_2D, texture[284].texture);
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.251f, 0.20f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.251f, 0.30f, 0.05f );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.151f, 0.30f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.151f, 0.20f, 0.05f );
      glEnd();

      if (game.player.thrusters == 2)
      {
         glBindTexture( GL_TEXTURE_2D, texture[282].texture); //thrusters 2 highlighted
         glLoadIdentity();
         glBegin( GL_QUADS );
	     glTexCoord2i( 0, 0 );glVertex3f( 0.25f, 0.20f, 0.04f );
	     glTexCoord2i( 1, 0 );glVertex3f( 0.25f, 0.30f, 0.04f );
	     glTexCoord2i( 1, 1 );glVertex3f( 0.15f, 0.30f, 0.04f );
	     glTexCoord2i( 0, 1 );glVertex3f( 0.15f, 0.20f, 0.04f );
         glEnd();
      }

      if (game.player.thrusters > -1)
      {
         glBindTexture( GL_TEXTURE_2D, texture[game.thruster[game.player.thrusters].image].texture); //player starship thrusters
         glLoadIdentity();
         glBegin( GL_QUADS );
         glTexCoord2i( 0, 0 );glVertex3f(ship_pos_x+(game.player.width)-0.379f,ship_pos_y-(game.player.hight), 0.035f );
         glTexCoord2i( 1, 0 );glVertex3f(ship_pos_x+(game.player.width)-0.379f,ship_pos_y+(game.player.hight), 0.035f );
         glTexCoord2i( 1, 1 );glVertex3f(ship_pos_x-(game.player.width)-0.379f,ship_pos_y+(game.player.hight), 0.035f );
         glTexCoord2i( 0, 1 );glVertex3f(ship_pos_x-(game.player.width)-0.379f,ship_pos_y-(game.player.hight), 0.035f );
         glEnd();
      }

      glBindTexture( GL_TEXTURE_2D, texture[game.player.image].texture); //player starship
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 0 );glVertex3f(ship_pos_x+(game.player.width),ship_pos_y-(game.player.hight), 0.03f );
      glTexCoord2i( 1, 0 );glVertex3f(ship_pos_x+(game.player.width),ship_pos_y+(game.player.hight), 0.03f );
      glTexCoord2i( 1, 1 );glVertex3f(ship_pos_x-(game.player.width),ship_pos_y+(game.player.hight), 0.03f );
      glTexCoord2i( 0, 1 );glVertex3f(ship_pos_x-(game.player.width),ship_pos_y-(game.player.hight), 0.03f );
      glEnd();

      if (game.player.front_weapon > -1)
      {
         glBindTexture( GL_TEXTURE_2D, texture[game.player.front_weapon+211].texture); //player starship front weapon
         glLoadIdentity();
         glBegin( GL_QUADS );
         glTexCoord2i( 0, 0 );glVertex3f(ship_pos_x+(game.player.width/3)+0.124f,ship_pos_y-(game.player.hight/3), 0.025f );
         glTexCoord2i( 1, 0 );glVertex3f(ship_pos_x+(game.player.width/3)+0.124f,ship_pos_y+(game.player.hight/3), 0.025f );
         glTexCoord2i( 1, 1 );glVertex3f(ship_pos_x-(game.player.width/3)+0.174f,ship_pos_y+(game.player.hight/3), 0.025f );
         glTexCoord2i( 0, 1 );glVertex3f(ship_pos_x-(game.player.width/3)+0.174f,ship_pos_y-(game.player.hight/3), 0.025f );
         glEnd();
      }

      if (game.player.side_weapon > -1)
      {
         glBindTexture( GL_TEXTURE_2D, texture[game.player.side_weapon+211].texture); //player starship side weapons
         glLoadIdentity();
         glBegin( GL_QUADS );
         glTexCoord2i( 0, 0 );glVertex3f(ship_pos_x+(game.player.width/3)+0.134f,ship_pos_y-(game.player.hight/3)+0.150f, 0.025f );
         glTexCoord2i( 1, 0 );glVertex3f(ship_pos_x+(game.player.width/3)+0.134f,ship_pos_y+(game.player.hight/3)+0.150f, 0.025f );
         glTexCoord2i( 1, 1 );glVertex3f(ship_pos_x-(game.player.width/3)+0.134f,ship_pos_y+(game.player.hight/3)+0.150f, 0.025f );
         glTexCoord2i( 0, 1 );glVertex3f(ship_pos_x-(game.player.width/3)+0.134f,ship_pos_y-(game.player.hight/3)+0.150f, 0.025f );
         glEnd();
         glBegin( GL_QUADS );
         glTexCoord2i( 0, 0 );glVertex3f(ship_pos_x+(game.player.width/3)+0.134f,ship_pos_y-(game.player.hight/3)-0.150f, 0.025f );
         glTexCoord2i( 1, 0 );glVertex3f(ship_pos_x+(game.player.width/3)+0.134f,ship_pos_y+(game.player.hight/3)-0.150f, 0.025f );
         glTexCoord2i( 1, 1 );glVertex3f(ship_pos_x-(game.player.width/3)+0.134f,ship_pos_y+(game.player.hight/3)-0.150f, 0.025f );
         glTexCoord2i( 0, 1 );glVertex3f(ship_pos_x-(game.player.width/3)+0.134f,ship_pos_y-(game.player.hight/3)-0.150f, 0.025f );
         glEnd();
      }

      if (game.player.front_shield > -1)
      {
         glBindTexture( GL_TEXTURE_2D, texture[game.shield[game.player.front_shield].image].texture); //player starship shield
         glLoadIdentity();
         glBegin( GL_QUADS );
         glTexCoord2i( 1, 0 );glVertex3f(ship_pos_x+(game.player.width*1.5),ship_pos_y-(game.player.hight*1.5), 0.02f );
         glTexCoord2i( 1, 1 );glVertex3f(ship_pos_x+(game.player.width*1.5),ship_pos_y+(game.player.hight*1.5), 0.02f );
         glTexCoord2i( 0, 1 );glVertex3f(ship_pos_x-(game.player.width*1.5),ship_pos_y+(game.player.hight*1.5), 0.02f );
         glTexCoord2i( 0, 0 );glVertex3f(ship_pos_x-(game.player.width*1.5),ship_pos_y-(game.player.hight*1.5), 0.02f );
         glEnd();
      }

      if (menu.possition == 4) glBindTexture( GL_TEXTURE_2D, texture[27].texture); //game menu highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[26].texture); //game menu
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.4f,-1.0f, 0.05f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f,-0.8f, 0.05f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f,-0.8f, 0.05f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f,-1.0f, 0.05f );
      glEnd();

      if ((menu.possition == 0) && (game.player.front_weapon >= 0)) //front weapon
      {
          font_print(128,128,192,-1.0f,-0.000f,game.projectile[game.player.front_weapon].name,0.0f);
          font_print(128,128,192,-1.0f,-0.075f,"Level            - %1.0f", game.projectile[game.player.front_weapon].level);
          font_print(128,128,192,-1.0f,-0.150f,"Experience  - %1.0f", game.projectile[game.player.front_weapon].experience);
          if (game.projectile[game.player.front_weapon].level == 0) font_print(128,128,192,-1.0f,-0.225f,"Next level    - %1.0f", game.projectile[game.player.front_weapon].level_1);
          if (game.projectile[game.player.front_weapon].level == 1) font_print(128,128,192,-1.0f,-0.225f,"Next level    - %1.0f", game.projectile[game.player.front_weapon].level_2);
          if (game.projectile[game.player.front_weapon].level == 2) font_print(128,128,192,-1.0f,-0.225f,"Next level    - %1.0f", game.projectile[game.player.front_weapon].level_3);
          if (game.projectile[game.player.front_weapon].level >= 3) font_print(128,128,192,-1.0f,-0.225f,"Next level    - Max", 0.0f);
          font_print(128,128,192,-1.0f,-0.300f,"Damage       - %1.0f", game.projectile[game.player.front_weapon].damage);
          font_print(128,128,192,-1.0f,-0.375f,"Speed          - %1.0f", game.projectile[game.player.front_weapon].speed);
          font_print(128,128,192,-1.0f,-0.450f,"Health         - %1.0f", game.projectile[game.player.front_weapon].health);
          font_print(128,128,192,-1.0f,-0.525f,"Rate of Fire - %1.0f", game.projectile[game.player.front_weapon].rate_of_fire);
      }
      if ((menu.possition == 1) && (game.player.side_weapon >= 0)) //side weapon
      {
          font_print(128,128,192,-1.0f,-0.000f,game.projectile[game.player.side_weapon].name,0.0f);
          font_print(128,128,192,-1.0f,-0.075f,"Level            - %1.0f", game.projectile[game.player.side_weapon].level);
          font_print(128,128,192,-1.0f,-0.150f,"Experience  - %1.0f", game.projectile[game.player.side_weapon].experience);
          if (game.projectile[game.player.side_weapon].level == 0) font_print(128,128,192,-1.0f,-0.225f,"Next level    - %1.0f", game.projectile[game.player.side_weapon].level_1);
          if (game.projectile[game.player.side_weapon].level == 1) font_print(128,128,192,-1.0f,-0.225f,"Next level    - %1.0f", game.projectile[game.player.side_weapon].level_2);
          if (game.projectile[game.player.side_weapon].level == 2) font_print(128,128,192,-1.0f,-0.225f,"Next level    - %1.0f", game.projectile[game.player.side_weapon].level_3);
          if (game.projectile[game.player.side_weapon].level >= 3) font_print(128,128,192,-1.0f,-0.225f,"Next level    - Max", 0.0f);
          font_print(128,128,192,-1.0f,-0.300f,"Damage       - %1.0f", game.projectile[game.player.side_weapon].damage);
          font_print(128,128,192,-1.0f,-0.375f,"Speed          - %1.0f", game.projectile[game.player.side_weapon].speed);
          font_print(128,128,192,-1.0f,-0.450f,"Health         - %1.0f", game.projectile[game.player.side_weapon].health);
          font_print(128,128,192,-1.0f,-0.525f,"Rate of Fire - %1.0f", game.projectile[game.player.side_weapon].rate_of_fire);
      }
      if ((menu.possition == 2) && (game.player.front_shield >= 0)) //front shield
      {
          font_print(128,128,192,-1.0f,-0.000f,game.shield[game.player.front_shield].name,0.0f);
          font_print(128,128,192,-1.0f,-0.075f,"Level            - %1.0f", game.shield[game.player.front_shield].level);
          font_print(128,128,192,-1.0f,-0.150f,"Experience  - %1.0f", game.shield[game.player.front_shield].experience);
          font_print(128,128,192,-1.0f,-0.255f,"Absorption  - %1.0f", game.shield[game.player.front_shield].absorption);
      }
      if ((menu.possition == 3) && (game.player.thrusters >= 0)) //thrusters
      {
          font_print(128,128,192,-1.0f,-0.00f,game.thruster[game.player.thrusters].name,0.0f);
          font_print(128,128,192,-1.0f,-0.075f,"Level            - %1.0f", game.thruster[game.player.thrusters].level);
          font_print(128,128,192,-1.0f,-0.150f,"Experience  - %1.0f", game.thruster[game.player.thrusters].experience);
          font_print(128,128,192,-1.0f,-0.255f,"Thrust      - %1.0f", game.thruster[game.player.thrusters].thrust);
      }
   }
/*-----------------------------------------------------------------------------*/

   if (menu.level == 4) //starmap_menu
   {
      glBindTexture( GL_TEXTURE_2D, texture[63].texture); //background 01
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-2.0f + menu.background_scroll[0].x_pos,-2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 0, 0 );glVertex3f(-2.0f + menu.background_scroll[0].x_pos, 2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 1, 0 );glVertex3f( 2.0f + menu.background_scroll[0].x_pos, 2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 1, 1 );glVertex3f( 2.0f + menu.background_scroll[0].x_pos,-2.0f + menu.background_scroll[0].y_pos, 0.15f );
      glEnd();

      glBindTexture( GL_TEXTURE_2D, texture[64].texture); //background 02
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-2.0f + menu.background_scroll[1].x_pos,-2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 0, 0 );glVertex3f(-2.0f + menu.background_scroll[1].x_pos, 2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 1, 0 );glVertex3f( 2.0f + menu.background_scroll[1].x_pos, 2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 1, 1 );glVertex3f( 2.0f + menu.background_scroll[1].x_pos,-2.0f + menu.background_scroll[1].y_pos, 0.1f );
      glEnd();

      glBindTexture( GL_TEXTURE_2D, texture[60].texture); //logo - star map menu
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.9f, 0.75f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.9f, 1.0f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.9f, 1.0f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.9f, 0.75f, 0.0f );
      glEnd();

      if (menu.possition == 0) glBindTexture( GL_TEXTURE_2D, texture[122+menu.level_no].texture); //level choice 0 highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[97+menu.level_no].texture); //level choice 0
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.95f, 0.4f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.95f, 0.6f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f(-0.35f, 0.6f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f(-0.35f, 0.4f, 0.0f );
      glEnd();

      if (game.level_locked[menu.level_no]) glBindTexture( GL_TEXTURE_2D, texture[172].texture); //level choice 0 game screen preview
      else glBindTexture( GL_TEXTURE_2D, texture[147+menu.level_no].texture); //level choice 0 game screen preview
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f(-0.35f, 0.3f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f(-0.35f,-0.3f, 0.0f );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.95f,-0.3f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.95f, 0.3f, 0.0f );
      glEnd();

      if (menu.possition == 1) glBindTexture( GL_TEXTURE_2D, texture[123+menu.level_no].texture); //level choice 1 highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[98+menu.level_no].texture); //level choice 1
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.3f, 0.4f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.3f, 0.6f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.3f, 0.6f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.3f, 0.4f, 0.0f );
      glEnd();

      if (game.level_locked[menu.level_no+1]) glBindTexture( GL_TEXTURE_2D, texture[172].texture); //level choice 1 game screen preview
      else glBindTexture( GL_TEXTURE_2D, texture[148+menu.level_no].texture); //level choice 1 game screen preview
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.30f, 0.3f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.30f,-0.3f, 0.0f );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.30f,-0.3f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.30f, 0.3f, 0.0f );
      glEnd();

      if (menu.possition == 2) glBindTexture( GL_TEXTURE_2D, texture[124+menu.level_no].texture); //level choice 2 highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[99+menu.level_no].texture); //level choice 2
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.35f, 0.4f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.35f, 0.6f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.95f, 0.6f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.95f, 0.4f, 0.0f );
      glEnd();

      if (game.level_locked[menu.level_no+2]) glBindTexture( GL_TEXTURE_2D, texture[172].texture); //level choice 2 game screen preview
      else glBindTexture( GL_TEXTURE_2D, texture[149+menu.level_no].texture); //level choice 2 game screen preview
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.95f, 0.3f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.95f,-0.3f, 0.0f );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.35f,-0.3f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.35f, 0.3f, 0.0f );
      glEnd();

      if (menu.possition == 3) glBindTexture( GL_TEXTURE_2D, texture[27].texture); //game menu highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[26].texture); //game menu
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.4f,-0.85f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f,-0.65f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f,-0.65f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f,-0.85f, 0.0f );
      glEnd();
   }

/*-----------------------------------------------------------------------------*/
   if (menu.level == 5) //Save Game
   {
      glBindTexture( GL_TEXTURE_2D, texture[63].texture); //background 01
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-2.0f + menu.background_scroll[0].x_pos,-2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 0, 0 );glVertex3f(-2.0f + menu.background_scroll[0].x_pos, 2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 1, 0 );glVertex3f( 2.0f + menu.background_scroll[0].x_pos, 2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 1, 1 );glVertex3f( 2.0f + menu.background_scroll[0].x_pos,-2.0f + menu.background_scroll[0].y_pos, 0.15f );
      glEnd();

      glBindTexture( GL_TEXTURE_2D, texture[64].texture); //background 02
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-2.0f + menu.background_scroll[1].x_pos,-2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 0, 0 );glVertex3f(-2.0f + menu.background_scroll[1].x_pos, 2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 1, 0 );glVertex3f( 2.0f + menu.background_scroll[1].x_pos, 2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 1, 1 );glVertex3f( 2.0f + menu.background_scroll[1].x_pos,-2.0f + menu.background_scroll[1].y_pos, 0.1f );
      glEnd();

      glBindTexture( GL_TEXTURE_2D, texture[52].texture); //logo - save game menu
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.9f, 0.75f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.9f, 1.0f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.9f, 1.0f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.9f, 0.75f, 0.0f );
      glEnd();

      if (menu.possition == 0) glBindTexture( GL_TEXTURE_2D, texture[179].texture); //game 0 highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[173].texture); //game 0
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.4f, 0.4f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f, 0.6f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f, 0.6f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f, 0.4f, 0.0f );
      glEnd();

      if (menu.possition == 1) glBindTexture( GL_TEXTURE_2D, texture[180].texture); //game 1 highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[174].texture); //game 1
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 1 );glVertex3f(-0.4f, 0.15f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f, 0.35f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f, 0.35f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f, 0.15f, 0.0f );
      glEnd();

      if (menu.possition == 2) glBindTexture( GL_TEXTURE_2D, texture[181].texture); //game 2 highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[175].texture); //game 2
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 1 );glVertex3f(-0.4f,-0.1f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f, 0.1f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f, 0.1f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f,-0.1f, 0.0f );
      glEnd();

      if (menu.possition == 3) glBindTexture( GL_TEXTURE_2D, texture[182].texture); //game 3 highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[176].texture); //game 3
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 1 );glVertex3f(-0.4f,-0.35f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f,-0.15f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f,-0.15f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f,-0.35f, 0.0f );
      glEnd();

      if (menu.possition == 4) glBindTexture( GL_TEXTURE_2D, texture[183].texture); //game 4 highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[177].texture); //game 4
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 1 );glVertex3f(-0.4f,-0.6f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f,-0.4f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f,-0.4f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f,-0.6f, 0.0f );
      glEnd();

      if (menu.possition == 5) glBindTexture( GL_TEXTURE_2D, texture[27].texture); //game menu highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[26].texture); //game menu
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.4f,-0.85f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f,-0.65f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f,-0.65f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f,-0.85f, 0.0f );
      glEnd();
   }

/*-----------------------------------------------------------------------------*/
   if (menu.level == 6) //Load Game
   {
      glBindTexture( GL_TEXTURE_2D, texture[63].texture); //background 01
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-2.0f + menu.background_scroll[0].x_pos,-2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 0, 0 );glVertex3f(-2.0f + menu.background_scroll[0].x_pos, 2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 1, 0 );glVertex3f( 2.0f + menu.background_scroll[0].x_pos, 2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 1, 1 );glVertex3f( 2.0f + menu.background_scroll[0].x_pos,-2.0f + menu.background_scroll[0].y_pos, 0.15f );
      glEnd();

      glBindTexture( GL_TEXTURE_2D, texture[64].texture); //background 02
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-2.0f + menu.background_scroll[1].x_pos,-2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 0, 0 );glVertex3f(-2.0f + menu.background_scroll[1].x_pos, 2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 1, 0 );glVertex3f( 2.0f + menu.background_scroll[1].x_pos, 2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 1, 1 );glVertex3f( 2.0f + menu.background_scroll[1].x_pos,-2.0f + menu.background_scroll[1].y_pos, 0.1f );
      glEnd();

      glBindTexture( GL_TEXTURE_2D, texture[29].texture); //logo - load game menu
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.9f, 0.75f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.9f, 1.0f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.9f, 1.0f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.9f, 0.75f, 0.0f );
      glEnd();

      if (menu.possition == 0) glBindTexture( GL_TEXTURE_2D, texture[179].texture); //game 0 highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[173].texture); //game 0
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.4f, 0.4f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f, 0.6f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f, 0.6f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f, 0.4f, 0.0f );
      glEnd();

      if (menu.possition == 1) glBindTexture( GL_TEXTURE_2D, texture[180].texture); //game 1 highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[174].texture); //game 1
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 1 );glVertex3f(-0.4f, 0.15f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f, 0.35f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f, 0.35f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f, 0.15f, 0.0f );
      glEnd();

      if (menu.possition == 2) glBindTexture( GL_TEXTURE_2D, texture[181].texture); //game 2 highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[175].texture); //game 2
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 1 );glVertex3f(-0.4f,-0.1f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f, 0.1f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f, 0.1f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f,-0.1f, 0.0f );
      glEnd();

      if (menu.possition == 3) glBindTexture( GL_TEXTURE_2D, texture[182].texture); //game 3 highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[176].texture); //game 3
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 1 );glVertex3f(-0.4f,-0.35f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f,-0.15f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f,-0.15f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f,-0.35f, 0.0f );
      glEnd();

      if (menu.possition == 4) glBindTexture( GL_TEXTURE_2D, texture[183].texture); //game 4 highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[177].texture); //game 4
      glLoadIdentity();
      glBegin( GL_QUADS );
      glTexCoord2i( 0, 1 );glVertex3f(-0.4f,-0.6f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f,-0.4f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f,-0.4f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f,-0.6f, 0.0f );
      glEnd();

      if (menu.possition == 5) glBindTexture( GL_TEXTURE_2D, texture[27].texture); //game menu highlighted
      else                    glBindTexture( GL_TEXTURE_2D, texture[26].texture); //game menu
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.4f,-0.85f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f,-0.65f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f,-0.65f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f,-0.85f, 0.0f );
      glEnd();
   }
/*-----------------------------------------------------------------------------*/
   if (menu.level == 7) //Achievements
   {
      glBindTexture( GL_TEXTURE_2D, texture[63].texture); //background 01
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-2.0f + menu.background_scroll[0].x_pos,-2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 0, 0 );glVertex3f(-2.0f + menu.background_scroll[0].x_pos, 2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 1, 0 );glVertex3f( 2.0f + menu.background_scroll[0].x_pos, 2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 1, 1 );glVertex3f( 2.0f + menu.background_scroll[0].x_pos,-2.0f + menu.background_scroll[0].y_pos, 0.15f );
      glEnd();

      glBindTexture( GL_TEXTURE_2D, texture[64].texture); //background 02
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-2.0f + menu.background_scroll[1].x_pos,-2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 0, 0 );glVertex3f(-2.0f + menu.background_scroll[1].x_pos, 2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 1, 0 );glVertex3f( 2.0f + menu.background_scroll[1].x_pos, 2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 1, 1 );glVertex3f( 2.0f + menu.background_scroll[1].x_pos,-2.0f + menu.background_scroll[1].y_pos, 0.1f );
      glEnd();

      glBindTexture( GL_TEXTURE_2D, texture[299].texture); //logo - Achievements
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.9f, 0.75f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.9f, 1.0f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.9f, 1.0f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.9f, 0.75f, 0.0f );
      glEnd();

      glBindTexture( GL_TEXTURE_2D, texture[301].texture); //score
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.95f, 0.55f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.95f, 0.75f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f(-0.25f, 0.75f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f(-0.25f, 0.55f, 0.0f );
      glEnd();

      if (game.achivement.score >= 1) glBindTexture( GL_TEXTURE_2D, texture[305].texture); //score - star 1 (bronze)
      else                            glBindTexture( GL_TEXTURE_2D, texture[304].texture); //score - star 1 (grey)
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.25f, 0.55f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.25f, 0.75f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f(-0.05f, 0.75f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f(-0.05f, 0.55f, 0.0f );
      glEnd();

      if (game.achivement.score >= 2) glBindTexture( GL_TEXTURE_2D, texture[306].texture); //score - star 2 (silver)
      else                            glBindTexture( GL_TEXTURE_2D, texture[304].texture); //score - star 2 (grey)
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.00f, 0.55f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.00f, 0.75f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.20f, 0.75f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.20f, 0.55f, 0.0f );
      glEnd();

      if (game.achivement.score >= 3) glBindTexture( GL_TEXTURE_2D, texture[307].texture); //score - star 3 (gold)
      else                            glBindTexture( GL_TEXTURE_2D, texture[304].texture); //score - star 3 (grey)
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.25f, 0.55f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.25f, 0.75f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.45f, 0.75f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.45f, 0.55f, 0.0f );
      glEnd();

      if (game.achivement.score >= 4) glBindTexture( GL_TEXTURE_2D, texture[307].texture); //score - star 4 (gold)
      else                            glBindTexture( GL_TEXTURE_2D, texture[304].texture); //score - star 4 (grey)
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.50f, 0.55f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.50f, 0.75f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.70f, 0.75f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.70f, 0.55f, 0.0f );
      glEnd();

      if (game.achivement.score >= 5) glBindTexture( GL_TEXTURE_2D, texture[307].texture); //score - star 5 (gold)
      else                            glBindTexture( GL_TEXTURE_2D, texture[304].texture); //score - star 5 (grey)
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.75f, 0.55f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.75f, 0.75f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.95f, 0.75f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.95f, 0.55f, 0.0f );
      glEnd();

      glBindTexture( GL_TEXTURE_2D, texture[303].texture); //kills
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.95f, 0.10f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.95f, 0.30f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f(-0.25f, 0.30f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f(-0.25f, 0.10f, 0.0f );
      glEnd();

      if (game.achivement.kills >= 1) glBindTexture( GL_TEXTURE_2D, texture[305].texture); //score - star 1 (bronze)
      else                            glBindTexture( GL_TEXTURE_2D, texture[304].texture); //score - star 1 (grey)
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.25f, 0.10f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.25f, 0.30f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f(-0.05f, 0.30f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f(-0.05f, 0.10f, 0.0f );
      glEnd();

      if (game.achivement.kills >= 2) glBindTexture( GL_TEXTURE_2D, texture[306].texture); //score - star 2 (silver)
      else                            glBindTexture( GL_TEXTURE_2D, texture[304].texture); //score - star 2 (grey)
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.00f, 0.10f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.00f, 0.30f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.20f, 0.30f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.20f, 0.10f, 0.0f );
      glEnd();

      if (game.achivement.kills >= 3) glBindTexture( GL_TEXTURE_2D, texture[307].texture); //score - star 3 (gold)
      else                            glBindTexture( GL_TEXTURE_2D, texture[304].texture); //score - star 3 (grey)
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.25f, 0.10f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.25f, 0.30f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.45f, 0.30f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.45f, 0.10f, 0.0f );
      glEnd();

      if (game.achivement.kills >= 4) glBindTexture( GL_TEXTURE_2D, texture[307].texture); //score - star 4 (gold)
      else                            glBindTexture( GL_TEXTURE_2D, texture[304].texture); //score - star 4 (grey)
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.50f, 0.10f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.50f, 0.30f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.70f, 0.30f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.70f, 0.10f, 0.0f );
      glEnd();

      if (game.achivement.kills >= 5) glBindTexture( GL_TEXTURE_2D, texture[307].texture); //score - star 5 (gold)
      else                            glBindTexture( GL_TEXTURE_2D, texture[304].texture); //score - star 5 (grey)
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f( 0.75f, 0.10f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f( 0.75f, 0.30f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.95f, 0.30f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.95f, 0.10f, 0.0f );
      glEnd();

      if (menu.possition == 0) glBindTexture( GL_TEXTURE_2D, texture[27].texture); //game menu highlighted
      else                     glBindTexture( GL_TEXTURE_2D, texture[26].texture); //game menu
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.4f,-0.95f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f,-0.75f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f,-0.75f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f,-0.95f, 0.0f );
      glEnd();
   }
/*-----------------------------------------------------------------------------*/
   if (menu.level == 8) //Player death screen
   {
      glBindTexture( GL_TEXTURE_2D, texture[84].texture); //background 01
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-2.0f + menu.background_scroll[0].x_pos,-2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 0, 0 );glVertex3f(-2.0f + menu.background_scroll[0].x_pos, 2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 1, 0 );glVertex3f( 2.0f + menu.background_scroll[0].x_pos, 2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 1, 1 );glVertex3f( 2.0f + menu.background_scroll[0].x_pos,-2.0f + menu.background_scroll[0].y_pos, 0.15f );
      glEnd();

      glBindTexture( GL_TEXTURE_2D, texture[73].texture); //background 02
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-2.0f + menu.background_scroll[1].x_pos,-2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 0, 0 );glVertex3f(-2.0f + menu.background_scroll[1].x_pos, 2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 1, 0 );glVertex3f( 2.0f + menu.background_scroll[1].x_pos, 2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 1, 1 );glVertex3f( 2.0f + menu.background_scroll[1].x_pos,-2.0f + menu.background_scroll[1].y_pos, 0.1f );
      glEnd();

      glBindTexture( GL_TEXTURE_2D, texture[330].texture); //logo
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.9f, 0.75f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.9f, 1.0f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.9f, 1.0f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.9f, 0.75f, 0.0f );
      glEnd();

      glBindTexture( GL_TEXTURE_2D, texture[329].texture); //Game Over
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.4f, 0.55f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.4f, 0.75f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.4f, 0.75f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.4f, 0.55f, 0.0f );
      glEnd();

      glBindTexture( GL_TEXTURE_2D, texture[332].texture); //explosion
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.6f,-0.70f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.6f, 0.50f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.6f, 0.50f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.6f,-0.70f, 0.0f );
      glEnd();

      glBindTexture( GL_TEXTURE_2D, texture[331].texture); //Press any key to return to the main menu
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.8f,-0.95f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.8f,-0.75f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.8f,-0.75f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.8f,-0.95f, 0.0f );
      glEnd();
   }
/*-----------------------------------------------------------------------------*/
   if (menu.level == 9) //Next level screen
   {
      int level_t = game.level + 1;
      if (level_t > 24) level_t = 24;
      glBindTexture( GL_TEXTURE_2D, texture[63].texture); //background 01
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-2.0f + menu.background_scroll[0].x_pos,-2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 0, 0 );glVertex3f(-2.0f + menu.background_scroll[0].x_pos, 2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 1, 0 );glVertex3f( 2.0f + menu.background_scroll[0].x_pos, 2.0f + menu.background_scroll[0].y_pos, 0.15f );
	  glTexCoord2i( 1, 1 );glVertex3f( 2.0f + menu.background_scroll[0].x_pos,-2.0f + menu.background_scroll[0].y_pos, 0.15f );
      glEnd();

      glBindTexture( GL_TEXTURE_2D, texture[64].texture); //background 02
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-2.0f + menu.background_scroll[1].x_pos,-2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 0, 0 );glVertex3f(-2.0f + menu.background_scroll[1].x_pos, 2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 1, 0 );glVertex3f( 2.0f + menu.background_scroll[1].x_pos, 2.0f + menu.background_scroll[1].y_pos, 0.1f );
	  glTexCoord2i( 1, 1 );glVertex3f( 2.0f + menu.background_scroll[1].x_pos,-2.0f + menu.background_scroll[1].y_pos, 0.1f );
      glEnd();

      glBindTexture( GL_TEXTURE_2D, texture[30].texture); //logo
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.9f, 0.75f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.9f, 1.0f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.9f, 1.0f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.9f, 0.75f, 0.0f );
      glEnd();

      glBindTexture( GL_TEXTURE_2D, texture[333].texture); //Congratulations
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.5f, 0.55f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.5f, 0.75f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.5f, 0.75f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.5f, 0.55f, 0.0f );
      glEnd();

      if (game.level_locked[level_t])
      {
         glBindTexture( GL_TEXTURE_2D, texture[335].texture); //level unlocked
         glLoadIdentity();
         glBegin( GL_QUADS );
	     glTexCoord2i( 0, 1 );glVertex3f(-0.5f, 0.35f, 0.0f );
	     glTexCoord2i( 0, 0 );glVertex3f(-0.5f, 0.55f, 0.0f );
	     glTexCoord2i( 1, 0 );glVertex3f( 0.5f, 0.55f, 0.0f );
   	     glTexCoord2i( 1, 1 );glVertex3f( 0.5f, 0.35f, 0.0f );
         glEnd();
      }

      glBindTexture( GL_TEXTURE_2D, texture[147+level_t].texture); //next level game screen preview
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.5f,-0.70f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.5f, 0.30f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.5f, 0.30f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.5f,-0.70f, 0.0f );
      glEnd();

      glBindTexture( GL_TEXTURE_2D, texture[334].texture); //Press any key to continue
      glLoadIdentity();
      glBegin( GL_QUADS );
	  glTexCoord2i( 0, 1 );glVertex3f(-0.8f,-0.95f, 0.0f );
	  glTexCoord2i( 0, 0 );glVertex3f(-0.8f,-0.75f, 0.0f );
	  glTexCoord2i( 1, 0 );glVertex3f( 0.8f,-0.75f, 0.0f );
	  glTexCoord2i( 1, 1 );glVertex3f( 0.8f,-0.95f, 0.0f );
      glEnd();

      font_print(128,128,192,-1.00f,-0.00f,"Level score - %1.0f", game.level_score);
      font_print(128,128,192,-1.00f,-0.10f,"Total score - %1.0f", game.score);
      font_print(128,128,192,-1.00f,-0.20f,"Level kills - %1.0f", game.level_kills);
      font_print(128,128,192,-1.00f,-0.30f,"Total kills - %1.0f", game.kills);
//      font_print(128,128,192,-1.00f,-0.40f,"Kill rate   - %1.0f %",((game.level_kills*100.0f)/(game.level_spawened*100.0f)));
   }
   return(0);
};
