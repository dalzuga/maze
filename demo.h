#ifndef _DEMO_H_
#define _DEMO_H_

#include <SDL2/SDL.h>
#define DEBUG 1
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

void draw_stuff(SDL_Instance);
int init_instance(SDL_Instance *);
int poll_events(void);
void draw_map();
int **make_map(int rows, int cols);
void init_map(int **map, int rows, int cols);

/* print_map - prints a map */
void print_map(int **map, int rows, int cols);

/* _print_map - calls print_map if debugging is on. */
void _print_map(int **map, int rows, int cols);

/* start_position - allocates a map and player, both must be freed. */
void start_position(int **map, GamePlayer *p);

#endif
