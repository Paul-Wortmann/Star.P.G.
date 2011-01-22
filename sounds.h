#include <SDL/SDL_mixer.h>

const int MAX_SOUNDS = 64;
struct sound_type
{
   bool active;
   int channel;
   Mix_Chunk *sound;
};

int init_sounds(void);
int load_sounds(void);
int kill_sounds(void);
int play_sound (int sound_num);
