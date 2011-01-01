
struct background_scroll_type
{
   int   x_dir;
   int   y_dir;
   float x_pos;
   float y_pos;
   float scroll_rate;
};

struct menu_type
{
  background_scroll_type background_scroll[2];
  int possition;
  int possition_max;
  int level;
  int level_no;
};

int diplay_menu (void);
int process_menu(void);
int init_menu   (void);
