#include "../headers/demo.h"

/**
 * game_func02 - entry point for the game engine
 *
 * @instance: SDL window and renderer instance
 * @map: the current map
 * @p: the player struct
 *
 * Return: Nothing.
 */
void game_func02(SDL_Instance instance, int **map, GamePlayer *p)
{
	/* declarations */
	int i;
	double col_height;	/* column height */
	double rclen;		/* ray cast length */
	int top, bottom;

	rclen = calc_rclen();

	/* inits */
	col_height = WALL_HEIGHT * p->dpp / rclen;

	
}
