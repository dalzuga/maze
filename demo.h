#ifndef _DEMO_H_
#define _DEMO_H_

#include <SDL2/SDL.h>
#define DEBUG 1
typedef struct SDL_Instance
{
  SDL_Window *window;
  SDL_Renderer *renderer;
} SDL_Instance;

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

#endif
