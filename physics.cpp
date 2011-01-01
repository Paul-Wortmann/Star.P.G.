#include "physics.h"

bool box_collision   (float a_x, float a_y, float a_w, float a_h, float b_x, float b_y, float b_w, float b_h)
{
if (((a_x-(a_w/2) < b_x+(b_w/2)) && (b_x+(b_w/2) > a_x-(a_w/2))) && ((b_x-(b_w/2) < a_x+(a_w/2)) && (a_x+(a_w/2) > b_x-(b_w/2))) 
 && ((a_y-(a_h/2) < b_y+(b_h/2)) && (b_y+(b_h/2) > a_y-(a_h/2))) && ((b_y-(b_h/2) < a_y+(a_h/2)) && (a_y+(a_h/2) > b_y-(b_h/2)))) return(true);
else return(false);
}

bool circle_collision(float a_x, float a_y, float a_r, float b_x, float b_y, float b_r)
{
   return(0);
};



