#ifndef _DEMO_H_
#define _DEMO_H_

#include <SDL2/SDL.h>
#include <unistd.h>
#include <math.h>

#define DEBUG 1
#define SLEEP_TIME 5000
#define X_RES 320
#define Y_RES 240
#define FOV_ANGLE 60
#define BLOCK_UNITS 64
#define WALL_HEIGHT BLOCK_UNITS
#define PLAYER_HEIGHT WALL_HEIGHT / 2

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
} GamePlayer;

int init_instance(SDL_Instance *);
void draw_stuff(SDL_Instance);
int poll_events(void);
void draw_map();
int **make_map(int rows, int cols);
void init_map(int **map, int rows, int cols);

/*  */
void draw_game(SDL_Instance instance, int **map, GamePlayer *p);

/*  */
int check_edge_cases(void);

/* game_start - entry point for the game engine */
void game_start(SDL_Instance instance);

/* _print_map - calls print_map if debugging is on. */
void _print_map(int **map, int rows, int cols);

/* print_map - prints a map */
void print_map(int **map, int rows, int cols);

/* start_position - allocates a map and player, both must be freed. */
void start_position(int ***map, GamePlayer **p);

/* paint_environment - paints the environment from the player's POV */
void paint_environment(SDL_Instance instance, int **map, GamePlayer *p);

/* print_calculations - gets necessary calculations */
void print_calculations(int **map __attribute__((unused)), GamePlayer *p);

/* paint_walls - paints the walls */
void paint_walls(SDL_Instance instance __attribute__ ((unused)),
		 int **map __attribute__ ((unused)),
		 GamePlayer *p __attribute__((unused)));

/* paint_projection - paints the walls */
void paint_projection(SDL_Instance instance, int **map, GamePlayer *p);

/* calculate_dslice - calculate distance to wall slice */
double calculate_dslice(int **map __attribute__ ((unused)),
		     GamePlayer *p, int i,
		     int *px __attribute__((unused)),
		     int *py __attribute__((unused)));

/*  */
int calculate_pposition(int **map __attribute__ ((unused)),
			GamePlayer *p, int *px, int *py);

/* calculate_block - inverse of calculate_pposition */

void calculate_block(int px, int py);

/* vertical_intersects - finds the closest vertical wall hit by the ray */
double vertical_intersects(int **map, GamePlayer *p, double beta, int *px,
			   int *py);

/*  */
int get_pix(int **map, GamePlayer *p, int *px);

/* horizontal_intersects - finds the closest horizontal wall hit by the ray */
double horizontal_intersects(int **map, GamePlayer *p, double beta, int *px,
			     int *py);

/*  */
int get_piy(int **map __attribute__((unused)), GamePlayer *p, int *py);

/* calc_rclen - calculate how far the ray cast travels until it meets a wall. */
double calc_rclen(int **map, GamePlayer *p, int i);

/*
 * calc_pxpy - calculates player position in the center of the
 * player's block. This is necessary because we are using finer resolution to
 * position player inside the block itself.
 *
 */
void calc_pxpy(GamePlayer *p, int *px, int *py);

/* game_func01 - entry point for the game engine */
void game_func01(SDL_Instance instance, int **map, GamePlayer *p);

/* draws the game on the projection plane (monitor) */
void game_func02(SDL_Instance instance, int **map, GamePlayer *p);

/* game_func03 - sets the wall color */
void game_func03(SDL_Instance instance);

#endif
