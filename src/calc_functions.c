#include "../headers/demo.h"

/**
 * calc_rclen - calculate how far the ray cast travels until it meets a wall.
 *
 * @map: address of map
 * @p: address of player
 * @i: specific ray within projection plane
 *
 * Return: length of the ray-line.
 */
double calc_rclen(int **map __attribute__ ((unused)), GamePlayer *p, int i)
{
	/* declarations + inits */
	double rclen = -1;
	double beta = (double) FOV_ANGLE * i / (double) X_RES;

	/* inits */
	rclen = calc_func01(map, p, i);

	/* correct for spherical distortion */
	rclen = rclen * cos((beta - FOV_ANGLE / 2) * M_PI / 180);

	return (rclen);
}

/**
 * calc_pxpy - calculates player position in the center of the
 * player's block. This is necessary because we are using finer resolution to
 * position player inside the block itself.
 *
 *
 */
void calc_pxpy(GamePlayer *p, int *px, int *py)
{
	*px = (p->x + 1) * BLOCK_UNITS - BLOCK_UNITS / 2;
	*py = (p->y + 1) * BLOCK_UNITS - BLOCK_UNITS / 2;

	if (DEBUG == 1)
	{
		printf("---------------2--------------\n");
		printf("p->x: %d, px: %d, ", p->x, *px);
		printf("p->y: %d, py: %d\n", p->y, *py);
	}
}
