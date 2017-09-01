#ifndef _DEMO_H_
#define _DEMO_H_

#include <SDL2/SDL.h>
#include <unistd.h>
#include <math.h>

#define DEBUG 0
#define DEBUG_SLEEP 450000	/* 450ms */
#define FRAME_SLEEP 33000 	/* 33ms */
#define SCALE 5
#define X_RES (320 * SCALE)
#define Y_RES (240 * SCALE)
#define FOV_ANGLE 60
#define BLOCK_UNITS (64)
#define WALL_HEIGHT BLOCK_UNITS
#define PLAYER_HEIGHT (WALL_HEIGHT / 2)
#define ANGLE_FACTOR 2
#define STEP_FACTOR 10
#define MAP_ROWS 12
#define MAP_COLS 30
#define START_X (4 * BLOCK_UNITS + 20)
#define START_Y (4 * BLOCK_UNITS + 40)
#define START_THETA 0

#define cprintf(bg, c, f, s) printf("\033[%d;%dm" f "\033[0m", bg, c, s)

typedef struct SDL_Instance
{
  SDL_Window *window;
  SDL_Renderer *renderer;
} SDL_Instance;

typedef struct GamePlayer
{
  int x;			/* player x-position */
  int y;			/* player y-position */
  int theta; 			/* angle between 0 and 359 degrees */
  double dpp;			/* distance to projection plane */
  int px;
  int py;
} GamePlayer;

typedef struct GameMap
{
  int **array;
  int rows;
  int cols;
} GameMap;

typedef struct MazeStruct
{
  SDL_Instance instance;
  GameMap *map;
  GamePlayer *p;
} MazeStruct;

typedef struct fnScanCode
{
  unsigned int code;
  int (*fp)(MazeStruct *maze);
} fnScanCode;

int init_instance(SDL_Instance *);
void draw_stuff(SDL_Instance);
void draw_column(MazeStruct *maze, int x, int top, int bottom);
int poll_events(MazeStruct *maze);

/* make_map - creates a map on the heap */
GameMap *make_map(int rows, int cols);

/* init_map - initializes a map with borders made of blocks */
void init_map(GameMap *map);

/* check_edge_cases - check game parameters before running */
int check_edge_cases(void);

/* game_main - entry point for the game engine */
void game_main(MazeStruct *maze);

/* _print_map - calls print_map if debugging is on. */
void _print_map(GameMap *map, GamePlayer *p);

/* print_map - prints a map */
void print_map(GameMap *map, GamePlayer *p);

/* rcprint_map - prints a map with ray hitting wall */
void rcprint_map(GameMap *map, GamePlayer *p, int x, int y);

/* game_init_params - allocates and inits a map and player, both must be freed. */
void game_init_params(GameMap **map, GamePlayer **p);

/*  */
int get_pix(GameMap *map, GamePlayer *p);

/*  */
int get_piy(GameMap *map __attribute__((unused)), GamePlayer *p);

/*
 * calc_pxpy - calculates player position in the center of the
 * player's block. This is necessary because we are using finer resolution to
 * position player inside the block itself.
 *
 */
void calc_pxpy(GamePlayer *p);

/* game_engine - entry point for the game engine */
void game_engine(MazeStruct *maze);

/* grame_frame draws the game on the projection plane (monitor) */
void game_frame(MazeStruct *maze);

/* set_wcolor - sets the wall color */
void set_wcolor(SDL_Instance instance, int r, int g, int b);

/* calc_rclen - finds the length of the ray until it hits a wall */
double calc_rclen(MazeStruct *maze, int ppcs4715);

/* calc_func01 - calculate how far the ray cast travels until it meets a wall */
double calc_func01(GameMap *map __attribute__ ((unused)), GamePlayer *p, int i);

/* calc_func02 - calculate how far the ray cast travels until it meets a wall */
double calc_func02(GameMap *map __attribute__ ((unused)), GamePlayer *p, int i);

/* calc_dvi - finds the closest vertical wall (x == C) hit by the ray */
double calc_dvi(GameMap *map, GamePlayer *p, int ppcs4715);

/* _calc_dvi - debug wrapper to call calc_dvi */
double _calc_dvi(GameMap *map, GamePlayer *p, int ppcs4715);

/* _calc_dhi - debug wrapper to call calc_dhi */
double _calc_dhi(GameMap *map, GamePlayer *p, int ppcs4715);

/* calc_dhi - finds the closest horizontal wall (y == C) hit by the ray */
double calc_dhi(GameMap *map, GamePlayer *p, int i);

/* calc_rcwrapper - wrapper to calculate intersects */
double calc_intwrapper(GameMap *map, GamePlayer *p, int i);

/* calc_alpha - calculates angle alpha */
double calc_alpha(GameMap *map, GamePlayer *p, int i);

/* calc_quadrants - calculates alpha based on quadrant */
double calc_quadrants(double beta, double theta);

/* calc_quad01 - special modding function, guarantees range (-180, 180] */
double calc_quad01(double tplusb);

/* calc_vblock - finds the closest vertical wall (y == C) hit by the ray */
double calc_vblock(GameMap *map, GamePlayer *p, double alpha);

/* calc_hblock - finds the closest horizontal wall (y == C) hit by the ray */
double calc_hblock(GameMap *map, GamePlayer *p, double alpha);

/* calc_mod360 - special modding function, guarantees range [0, 360) */
double calc_mod360(double angle);

/* axis_angle - if the angle is on an axis */
int axis_angle(double angle);

/* special_angle - calculates distance when angle is on an axis */
int special_angle(GameMap *map, GamePlayer *p, double angle, int ppcs4715);

/* init_main - initialize all members of MazeStruct */
void init_main(MazeStruct *maze);

void exit_function(MazeStruct *maze);

int calc_dy(GamePlayer *p, double ap);

int calc_Ya(double ap);

int calc_dx(GamePlayer *p, double ap);

int calc_Xa(double ap);

int keypress(MazeStruct *, SDL_KeyboardEvent key);

int fn_29(MazeStruct *);

int fn_51(MazeStruct *);

int fn_52(MazeStruct *);

int fn_4f(MazeStruct *);

int fn_50(MazeStruct *);

int fn_04(MazeStruct *);

int fn_07(MazeStruct *);

int fn_16(MazeStruct *);

int fn_1a(MazeStruct *);

void step_up(MazeStruct *maze);

void step_down(MazeStruct *maze);

void step_left(MazeStruct *maze);

void step_right(MazeStruct *maze);

void step_fwd(MazeStruct *maze);

void step_rwd(MazeStruct *maze);

void keystates(MazeStruct *maze);

int check_blocks(MazeStruct *maze, int i, int j);

int check_map_bounds(MazeStruct *maze, int i, int j);

#endif
