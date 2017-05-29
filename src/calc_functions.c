#include "../headers/demo.h"

/**
 * calc_rclen - calculate how far the ray cast travels until it meets a wall.
 *
 * @map: address of map
 * @p: address of player
 */
double calc_rclen(int **map, GamePlayer *p)
{
	/* declarations */
	double rclen = -1;
	int px = -1, py = -1;

	/* inits */
	calc_pxpy(&px, &py);

	
}

/**
 * calc_pxpy - calculates player position in the center of the
 * player's block. This is necessary because we are using finer resolution to
 * position player inside the block itself.
 *
 *
 */
void calc_pxpy(int *px, int *py)
{
	px = (p->x + 1) * BLOCK_UNITS - BLOCK_UNITS / 2;
	py = (p->y + 1) * BLOCK_UNITS - BLOCK_UNITS / 2;

	if (DEBUG == 1)
	{
		printf("---------------2--------------\n");
		printf("p->x: %d, px: %d, ", p->x, *px);
		printf("p->y: %d, py: %d\n", p->y, *py);
	}
}
