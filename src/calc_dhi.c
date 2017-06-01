#include "../headers/demo.h"

/**
 * calc_dhi - finds the closest horizontal wall (x == C) hit by the ray
 *
 */
double calc_dhi(GameMap *map, GamePlayer *p, double alpha)
{
	/* declarations */
	double dist;

	dist = calc_hblock(map, p, alpha);

	return (fabs(dist));
}

/**
 * calc_hblock - finds the closest horizontal wall (y == C) hit by the ray
 *
 */
double calc_hblock(GameMap *map, GamePlayer *p, double alpha)
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

	if (alpha <= 0)
	{
		dist = (piy + (map->rows - 2) * Ay) / sin(alpha * M_PI / 180);
	}

	dist = (piy + (3) * Ay) / sin(alpha * M_PI / 180);

	return (fabs(dist));
}

/**
 *
 *
 */
int get_piy(GameMap *map __attribute__((unused)), GamePlayer *p)
{
	int edge_y;

	edge_y = 0;

	/* get y-coordinate of top edge of block */
	edge_y = (p->x + 1) * BLOCK_UNITS;

	if (DEBUG == 1)
	{
		printf("---------------8--------------\n");
		printf("edge_y: %d\n", edge_y);
	}

	/* return the distance from player to right edge of block */
	return (p->py - edge_y);
}
