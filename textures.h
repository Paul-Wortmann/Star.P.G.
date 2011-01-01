#include <gl/gl.h>

const int MAX_TEXTURES = 340;
struct texture_type
{
   GLuint texture;
};

int init_textures(void);
int load_texture (int texture_number, const char File_Name[]);
int load_textures(void);
int kill_textures(void);
