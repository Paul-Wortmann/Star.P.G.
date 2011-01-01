#include <SDL/SDL_mixer.h>

const int MAX_MUSIC = 16;
struct music_type
{
   Mix_Music *music;
};

int init_music(void);
int load_music(void);
int kill_music(void);
int play_music(int music_num);
