#include "../headers/demo.h"

/**
 * calc_dvi - finds the closest vertical wall (y == C) hit by the ray
 *
 */
double calc_dvi(GameMap *map, GamePlayer *p, double alpha)
{
	/* declarations */
	double dist;

	dist = calc_vblock(map, p, alpha);

	return fabs(dist);
}

/**
 * calc_vblock - finds the closest vertical wall (y == C) hit by the ray
 *
 */
double calc_vblock(GameMap *map, GamePlayer *p, double alpha)
{
	/* declarations */
	double dist;
	int pix, Ax, piy, Ay;

	/* inits */
	dist = 0;
	piy = Ax = pix = Ay = 0;

	piy = get_piy(map, p);
	Ay = BLOCK_UNITS;

	/* calculate pix and Ax */
	pix = piy / tan(alpha * M_PI / 180);
	Ax = Ay / tan(alpha * M_PI / 180);

	dist = (piy + (map->cols - 2) * Ay) / sin(alpha * M_PI / 180);

	return (fabs(dist));
}

/**
 *
 *
 */
int get_pix(GameMap *map __attribute__((unused)), GamePlayer *p)
{
	int edge_x;

	edge_x = 0;

	/* get x-coordinate of right edge of block */
	edge_x = (p->y + 1) * BLOCK_UNITS;

	if (DEBUG == 1)
	{
		printf("---------------6--------------\n");
		printf("edge_x: %d\n", edge_x);
	}

	/* return the distance from player to right edge of block */
	return (p->px - edge_x);
}
