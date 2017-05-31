#include "../headers/demo.h"

/**
 * calc_intwrapper - wrapper to calculate intersects
 *
 * @map: address of map
 * @p: address of player
 * @i: specific ray within projection plane
 *
 * Return: length of the ray-line.
 */
double calc_intwrapper(int **map, GamePlayer *p, int i)
{
	/* declarations + inits */
	double dvi = -1, dhi = -1, alpha = -1;

	/* inits */
	calc_pxpy(p);
	alpha = calc_alpha(map, p, i);

	dvi = calc_dvi(map, p, alpha);
	dhi = calc_dhi(map, p, alpha);

	return (fmin(dvi, dhi));
}

/**
 * calc_alpha - calculates angle alpha
 *
 */
double calc_alpha(int **map, GamePlayer *p, int i)
{
	double alpha, beta, theta;

	beta = (double) FOV_ANGLE * i / (double) X_RES;
	theta = (double) p->theta - FOV_ANGLE / 2;

	alpha = calc_quadrants(beta, theta);

	if (DEBUG == 1)
	{
		printf("---------------2--1--------------\n");
		printf("%p\n", (void *) map);
		printf("alpha: %f\n", alpha);
		/* printf("%p\n", (void *) p->py); */
	}

	return (alpha);
}

/**
 * calc_pxpy - calculates player position in the center of the player's
 * block. This is necessary because we are using finer resolution to position
 * player inside the block itself.
 *
 *
 */
void calc_pxpy(GamePlayer *p)
{
	p->px = (p->x + 1) * BLOCK_UNITS - BLOCK_UNITS / 2;
	p->py = (p->y + 1) * BLOCK_UNITS - BLOCK_UNITS / 2;

	if (DEBUG == 1)
	{
		printf("---------------2--------------\n");
		printf("p->x: %d, px: %d, ", p->x, p->px);
		printf("p->y: %d, py: %d\n", p->y, p->py);
	}
}
