
#include "graphics.h"

int   gl_to_res(float gl_coord, int max_res)
{
   return((gl_coord+1)*(max_res / 2));
}



float res_to_gl(int  res_coord, int max_res)
{
   return(((res_coord / 2) / (max_res / 2)) -1);
}
