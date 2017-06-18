#ifndef _DEMO_H_
#define _DEMO_H_

#include <SDL2/SDL.h>
#include <unistd.h>
#include <math.h>

#define DEBUG 2
#define DEBUG_SLEEP 100000
#define FRAME_SLEEP 30000 	/* 30ms */
#define X_RES 320
#define Y_RES 240
#define FOV_ANGLE 60
#define BLOCK_UNITS 64
#define WALL_HEIGHT BLOCK_UNITS
#define PLAYER_HEIGHT WALL_HEIGHT / 2
#define ANGLE_STEP 1
#define MAP_ROWS 10
#define MAP_COLS 30
#define START_X 198
#define START_Y (198 + 96)
#define START_THETA 0

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

int init_instance(SDL_Instance *);
void draw_stuff(SDL_Instance);
int poll_events(void);

/* make_map - creates a map on the heap */
GameMap *make_map(int rows, int cols);

/* init_map - initializes a map with borders made of blocks */
void init_map(GameMap *map);

/* check_edge_cases - check game parameters before running */
int check_edge_cases(void);

/* game_start - entry point for the game engine */
void game_start(SDL_Instance instance);

/* _print_map - calls print_map if debugging is on. */
void _print_map(GameMap *map, GamePlayer *p);

/* print_map - prints a map */
void print_map(GameMap *map, GamePlayer *p);

/* start_position - allocates a map and player, both must be freed. */
void start_position(GameMap **map, GamePlayer **p);

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

/* game_func01 - entry point for the game engine */
void game_func01(SDL_Instance instance, GameMap *map, GamePlayer *p);

/* draws the game on the projection plane (monitor) */
void game_func02(SDL_Instance instance, GameMap *map, GamePlayer *p);

/* game_func03 - sets the wall color */
void game_func03(SDL_Instance instance);

/* calc_func01 - calculate how far the ray cast travels until it meets a wall */
double calc_func01(GameMap *map __attribute__ ((unused)), GamePlayer *p, int i);

/* calc_func02 - calculate how far the ray cast travels until it meets a wall */
double calc_func02(GameMap *map __attribute__ ((unused)), GamePlayer *p, int i);

/* calc_dvi - finds the closest vertical wall (x == C) hit by the ray */
double calc_dvi(GameMap *map, GamePlayer *p, int ppcs4715);

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

/* special_dhi - calculates distance when angle is on an axis */
int special_dhi(GameMap *map, GamePlayer *p, double angle, int ppcs4715);

#endif
