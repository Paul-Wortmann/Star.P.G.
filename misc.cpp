#include <time.h>
#include <stdlib.h>


int seed_rand(void)
{
   srand(time(0));
}

double random_double(void)
{
  double temp_d = 0;
  
       do
       {
       temp_d = rand()%100;
       temp_d = 0.95 - (temp_d /50.9);
       }
       while ((temp_d > 2) and (temp_d < -2));
       return temp_d;
}

int random_int(void)
{
   return(rand()%65535);
}

int    random(int range)
{
   return(rand()%range);
}

int random_dec(void)
{
   return(rand()%10);
}

int random_cen(void)
{
   return(rand()%100);
}

float   random_GLcoord(void)
{
  double temp_f = 0;
  
       do
       {
       temp_f = rand()%100;
       temp_f = (0.95 - (temp_f /50.9))/2;
       }
       while ((temp_f > 1) and (temp_f < -1));
       return temp_f;
}


int convert_res_to_gl (int pos_x,int pos_y,int res_x,int res_y)
{
   float gl_x = ((pos_x / res_x) * 2) - 1;
   float gl_y = ((pos_y / res_y) * 2) - 1;
}
