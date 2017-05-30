#include "../headers/demo.h"

/**
 * calc_dhi - finds the closest horizontal wall (y == C) hit by the ray
 *
 */
double calc_dhi(int **map, GamePlayer *p, double beta)
{
	/* declarations */
	int theta;
	double alpha, dist;
	int pix, Ax, piy, Ay;

	/* inits */
	theta = p->theta - FOV_ANGLE / 2;
	alpha = dist = 0;
	piy = Ax = pix = Ay = 0;

	if (DEBUG == 2)
	{
		printf("---------------2--2--------------\n");
		printf("%p\n", (void *) map);
		/* printf("%p\n", (void *) p->px); */
	}

	if ((theta + beta) < 0)
	{
		alpha = 90 + ((double) theta + beta);
	}

	alpha = (90 - ( (double) theta + beta ));

	piy = get_piy(map, p);
	Ay = BLOCK_UNITS;

	/* calculate pix and Ax */
	pix = piy / tan(alpha * M_PI / 180);
	Ax = Ay / tan(alpha * M_PI / 180);

	/* /\* delete *\/ */
	/* calc_pixax(map, p, i, alpha, piy); */
	/* /\* end delete *\/ */

	dist = (piy + Ay) / sin(alpha * M_PI / 180);

	return fabs(dist);
}

/**
 *
 *
 */
int get_piy(int **map __attribute__((unused)), GamePlayer *p)
{
	int edge_y;

	edge_y = 0;

	/* get x-coordinate of right edge of block */
	edge_y = p->x + 1 * BLOCK_UNITS;

	if (DEBUG == 1)
	{
		printf("---------------8--------------\n");
		printf("edge_y: %d\n", edge_y);
	}

	/* return the distance from player to right edge of block */
	return (p->py - edge_y);
}
