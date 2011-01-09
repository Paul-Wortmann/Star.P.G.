
const int MAX_NPCS        = 32;
const int MAX_PROJECTILES = 32;
const int MAX_SHIELDS     = 5;
const int MAX_THRUSTERS   = 4;
const int MAX_BULLETS     = 96;
const int MAX_EXPLOSIONS  = 32;
const int MAX_ENEMYS      = 32;
const int MAX_BACKGROUNDS = 4;
const int MAX_LEVELS      = 25;
const int MAX_WAVES       = 32;
const int MAX_POWERUPS    = 8;

struct wave_type
{
   bool  active;
   int   npc_type;
   int   target_kills;
   int   count_kills;
   int   target_spawned;
   int   count_spawned;
   int   spawn_pattern;
};

struct explosion_type
{
   bool  active;
   int   frame;
   int   image;
   int   sound;
   float x_pos;
   float y_pos;
   float width;
   float hight;
   float size;
};

struct powerup_type
{
   bool  active;
   int   image;
   int   sound;
   float x_pos;
   float y_pos;
   float width;
   float hight;
   float speed;
   int   spawn_rate;
};

struct bullet_type
{
   int   warhead; //projectile
   bool  active;
   int   location;
   float x_pos;
   float y_pos;
   float x_speed;
   float y_speed;
   float width;
   float hight;
};

struct projectile_type
{
   char     name[16];
   bool     active;
   int      level;
   float    experience;
   float    level_1;
   float    level_2;
   float    level_3;
   int      image;
   int      sound;
   float    damage;
   float    health;
   float    speed;
   int      rate_of_fire;
};

struct bkground_scroll_type
{
   int   image;
   int   x_dir;
   int   y_dir;
   float x_pos;
   float y_pos;
   float scroll_rate;
};

struct player_type
{
   int   front_weapon;
   int   side_weapon;
   int   front_shield;
   int   thrusters;
   float x_pos;
   float y_pos;
   float width;
   float hight;
   float health;
   float health_regen_rate;
   float max_health;
   int   image;
   bullet_type          bullet[MAX_BULLETS];
};

struct shield_type
{
   char  name[24];
   bool  active;
   int   level;
   float experience;
   int   image;
   float absorption;
};

struct thruster_type
{
   char  name[24];
   bool  active;
   int   level;
   float experience;
   int   image;
   float thrust;
};

struct enemy_type
{
   int   image;
   int   sound;
   float health;
   float speed;
   int   movement;
   int   weapon;
   int   projectiles;
   float size_w;
   float size_h;
};

struct npc_type
{
   bool  active;
   int   type_npc;
   int   weapon;
   int   projectiles;
   float x_pos;
   float y_pos;
   float health;
   float width;
   float hight;
   float x_speed;
   float y_speed;
   int   movement;
   int   x_direction;
   int   y_direction;
   bullet_type          bullet[MAX_BULLETS];
};

struct active_npc_type
{
   bool active;
   int  number;
};

struct fade_logo_type
{
   bool  active;
   float alpha;
};

struct achivement_type
{
   int score;
   int score_level_1;
   int score_level_2;
   int score_level_3;
   int score_level_4;
   int score_level_5;
   int kills;
   int kills_level_1;
   int kills_level_2;
   int kills_level_3;
   int kills_level_4;
   int kills_level_5;
};

struct game_type
{
   bool                 game_paused;
   bool                 game_active;
   bool                 game_resume;
   bool                 menu_active;
   bool                 pdie_active;
   bool                 nlvl_active;
   int                  exp_rate;
   int                  FPS;
   int                  level_locked[MAX_LEVELS];
   int                  level;
   int                  level_npc_type;
   bool                 level_boss_level;
   int                  score;
   int                  kills;
   int                  level_kills;
   int                  level_spawened;
   int                  level_score;
   int                  victory_kills;
   int                  victory_spawened;
   int                  victory_score;
   float                speed;
   int                  fw_rof_count;
   int                  sw_rof_count;
   int                  npc_spawn_rate;
   int                  npc_projectile_spawn_rate;
   int                  music_track;
   int                  menu_music_track;
   int                  pdie_music_track;
   int                  nlvl_music_track;
   wave_type            wave[MAX_WAVES];
   player_type          player;
   enemy_type           enemy[MAX_ENEMYS];
   npc_type             npc[MAX_NPCS];
   projectile_type      projectile[MAX_PROJECTILES];
   shield_type          shield[MAX_SHIELDS];
   thruster_type        thruster[MAX_THRUSTERS];
   explosion_type       explosion[MAX_EXPLOSIONS];
   bkground_scroll_type background_scroll[MAX_BACKGROUNDS];
   powerup_type         powerup[MAX_POWERUPS];
   int                  active_npc_count;
   active_npc_type      active_npc[MAX_NPCS];
   achivement_type      achivement;
   fade_logo_type       paused;
   fade_logo_type       loaded;
   fade_logo_type       saved;
   fade_logo_type       a_score;
   fade_logo_type       a_kills;
   fade_logo_type       p_actinium_shields;
   fade_logo_type       p_blasters;
   fade_logo_type       p_burst_lasers;
   fade_logo_type       p_chain_guns;
   fade_logo_type       p_convolution_thrusters;
   fade_logo_type       p_health;
   fade_logo_type       p_ion_cannons;
   fade_logo_type       p_iridium_shileds;
   fade_logo_type       p_maelstrom_thrusters;
   fade_logo_type       p_plasma_rockets;
   fade_logo_type       p_rail_turrets;
   fade_logo_type       p_rubidium_shields;
   fade_logo_type       p_seismic_thrusters;
   fade_logo_type       p_shield_level_up;
   fade_logo_type       p_tantalum_shields;
   fade_logo_type       p_terbium_shields;
   fade_logo_type       p_thrusters_level_up;
   fade_logo_type       p_vortex_thrusters;
   fade_logo_type       p_weapon_level_up;
};

int   init_waves     (void);
int   init_game      (void);
bool  level_completed(void);
int   process_game   (void);
int   process_ball   (void);
int   display_game   (void);
int   init_player    (void);
float thruster_offset(void);
int   process_player (int command);

int spawn_player_bullet_num(int player_bullet_num, int location);
int spawn_player_bullet(int position);
int kill_player_bullet(int player_bullet_num);
int init_player_bullets(void);
int proccess_player_bullets(void);

int spawn_explosion(float x_position, float y_position, float size);
int kill_explosion(int explosion_num);
int init_explosions(void);
int proccess_explosions(void);

int spawn_npc(float x_position, float y_position, int type_npc);
int kill_npc(int npc_num);
int init_npcs(int type_npc);
int proccess_npcs(void);

int spawn_npc_bullet_num(int npc_num, int npc_bullet_num, int location);
int spawn_npc_bullet(int npc_num, int location);
int kill_npc_bullet(int npc_num, int npc_bullet_num);
int init_npc_bullets(void);
int proccess_npc_bullets(void);

int init_active_npcs(void);
int check_active_npcs(void);
int sort_active_npcs(void);
int add_active_npc  (int npc_num);
int del_active_npc  (int npc_num);

int kill_paused(void);
int spawn_paused(void);
int display_paused(void);
int process_paused(void);

int kill_loaded(void);
int spawn_loaded(void);
int display_loaded(void);
int process_loaded(void);

int kill_saved(void);
int spawn_saved(void);
int display_saved(void);
int process_saved(void);

int spawn_powerup(float x_position, float y_position, int type_powerup);
int kill_powerup(int type_powerup);
int init_powerups(void);
int proccess_powerups(void);

int kill_a_score(void);
int spawn_a_score(void);
int display_a_score(void);
int process_a_score(void);

int kill_a_kills(void);
int spawn_a_kills(void);
int display_a_kills(void);
int process_a_kills(void);

int kill_p_actinium_shields(void);
int spawn_p_actinium_shields(void);
int display_p_actinium_shields(void);
int process_p_actinium_shields(void);

int kill_p_blasters(void);
int spawn_p_blasters(void);
int display_p_blasters(void);
int process_p_blasters(void);

int kill_p_burst_lasers(void);
int spawn_p_burst_lasers(void);
int display_p_burst_lasers(void);
int process_p_burst_lasers(void);

int kill_p_chain_guns(void);
int spawn_p_chain_guns(void);
int display_p_chain_guns(void);
int process_p_chain_guns(void);

int kill_p_convolution_thrusters(void);
int spawn_p_convolution_thrusters(void);
int display_p_convolution_thrusters(void);
int process_p_convolution_thrusters(void);

int kill_p_health(void);
int spawn_p_health(void);
int display_p_health(void);
int process_p_health(void);

int kill_p_ion_cannons(void);
int spawn_p_ion_cannons(void);
int display_p_ion_cannons(void);
int process_p_ion_cannons(void);

int kill_p_iridium_shileds(void);
int spawn_p_iridium_shileds(void);
int display_p_iridium_shileds(void);
int process_p_iridium_shileds(void);

int kill_p_maelstrom_thrusters(void);
int spawn_p_maelstrom_thrusters(void);
int display_p_maelstrom_thrusters(void);
int process_p_maelstrom_thrusters(void);

int kill_p_plasma_rockets(void);
int spawn_p_plasma_rockets(void);
int display_p_plasma_rockets(void);
int process_p_plasma_rockets(void);

int kill_p_rail_turrets(void);
int spawn_p_rail_turrets(void);
int display_p_rail_turrets(void);
int process_p_rail_turrets(void);

int kill_p_rubidium_shields(void);
int spawn_p_rubidium_shields(void);
int display_p_rubidium_shields(void);
int process_p_rubidium_shields(void);

int kill_p_seismic_thrusters(void);
int spawn_p_seismic_thrusters(void);
int display_p_seismic_thrusters(void);
int process_p_seismic_thrusters(void);

int kill_p_shield_level_up(void);
int spawn_p_shield_level_up(void);
int display_p_shield_level_up(void);
int process_p_shield_level_up(void);

int kill_p_tantalum_shields(void);
int spawn_p_tantalum_shields(void);
int display_p_tantalum_shields(void);
int process_p_tantalum_shields(void);

int kill_p_terbium_shields(void);
int spawn_p_terbium_shields(void);
int display_p_terbium_shields(void);
int process_p_terbium_shields(void);

int kill_p_thrusters_level_up(void);
int spawn_p_thrusters_level_up(void);
int display_p_thrusters_level_up(void);
int process_p_thrusters_level_up(void);

int kill_p_vortex_thrusters(void);
int spawn_p_vortex_thrusters(void);
int display_p_vortex_thrusters(void);
int process_p_vortex_thrusters(void);

int kill_p_weapon_level_up(void);
int spawn_p_weapon_level_up(void);
int display_p_weapon_level_up(void);
int process_p_weapon_level_up(void);
