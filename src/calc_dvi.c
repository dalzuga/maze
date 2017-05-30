#include "../headers/demo.h"

/**
 * calc_dvi - finds the closest horizontal wall (y == C) hit by the ray
 *
 */
double calc_dvi(int **map, GamePlayer *p, double beta)
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
int get_pix(int **map __attribute__((unused)), GamePlayer *p)
{
	int edge_x;

	edge_x = 0;

	/* get x-coordinate of right edge of block */
	edge_x = p->y + 1 * BLOCK_UNITS;

	if (DEBUG == 1)
	{
		printf("---------------6--------------\n");
		printf("edge_x: %d\n", edge_x);
	}

	/* return the distance from player to right edge of block */
	return (p->px - edge_x);
}
