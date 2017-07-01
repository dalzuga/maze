#ifndef _DEMO_H_
#define _DEMO_H_

#include <SDL2/SDL.h>
#include <unistd.h>
#include <math.h>
#include "prototypes.h"

#define DEBUG 0
#define X_RES 320
#define Y_RES 240
#define FOV_ANGLE 60

typedef struct GameMap
{
  int **map;
  int rows;
  int cols;
} GameMap;

typedef struct GamePlayer
{
  int theta;
  int x;
  int y;
} GamePlayer;

#endif
