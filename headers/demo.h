#ifndef _DEMO_H_
#define _DEMO_H_

#include <SDL2/SDL.h>
#include <unistd.h>
#include <math.h>

#define DEBUG 1
#define SCALE_X 1
#define SCALE_Y 1
#define X_RES 320 * SCALE_X
#define Y_RES 240 * SCALE_Y
#define FIELD_ANGLE 60
#define BLOCK_UNITS SQRT_BLOCK_UNITS * SQRT_BLOCK_UNITS
#define SQRT_BLOCK_UNITS 64
#define SQRT_BLOCK_UNITS_HALF SQRT_BLOCK_UNITS / 2
#define WALL_HEIGHT 64
#define PLAYER_HEIGHT WALL_HEIGHT / 2
#define Y_CENTER SQRT_BLOCK_UNITS / 2

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
} GamePlayer;

int init_instance(SDL_Instance *);
void draw_stuff(SDL_Instance);
int poll_events(void);
void draw_map();
int **make_map(int rows, int cols);
void init_map(int **map, int rows, int cols);

/*  */
void draw_game(SDL_Instance instance, int **map, GamePlayer *p);

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

/* paint_calculations - gets necessary calculations */
void paint_calculations(int **map __attribute__((unused)), GamePlayer *p);

/* paint_walls - paints the walls */
void paint_walls(SDL_Instance instance __attribute__ ((unused)),
		 int **map __attribute__ ((unused)),
		 GamePlayer *p __attribute__((unused)));

/* paint_projection - paints the walls */
void paint_projection(SDL_Instance instance, int **map, GamePlayer *p);

/* calculate_dslice - calculate distance to wall slice */
int calculate_dslice(int **map __attribute__ ((unused)),
		     GamePlayer *p, int beta,
		     int *px __attribute__((unused)),
		     int *py __attribute__((unused)));

/*  */
int calculate_pposition(int **map __attribute__ ((unused)),
			GamePlayer *p, int *px, int *py);

#endif
