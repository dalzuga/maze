#ifndef _DEMO_H_
#define _DEMO_H_

#include <SDL2/SDL.h>
#include <unistd.h>
#include <math.h>
#include "prototypes.h"

#define DEBUG 0
#define DEBUG_SLEEP 5000
#define FRAME_SLEEP 30000 	/* 30ms */
#define X_RES 320
#define Y_RES 240
#define FOV_ANGLE 60
#define BLOCK_UNITS 64
#define WALL_HEIGHT BLOCK_UNITS
#define PLAYER_HEIGHT WALL_HEIGHT / 2
#define ANGLE_STEP 1
#define MAP_ROWS 4
#define MAP_COLS 10

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

#endif
