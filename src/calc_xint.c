#include "../headers/demo.h"

/**
 * calc_dvi - finds the closest vertical wall (x == C) hit by the ray
 *
 */
double calc_dvi(int **map, GamePlayer *p, double beta, int *px, int *py)
{
	/* declarations */
	int theta;
	double alpha, dist;
	int pix, Ax, piy, Ay;

	/* inits */
	theta = p->theta - FOV_ANGLE / 2;
	alpha = dist = 0;
	pix = Ax = piy = Ay = 0;

	if (DEBUG == 2)
	{
		printf("---------------2--1--------------\n");
		printf("%p\n", (void *) map);
		printf("%p\n", (void *) py);
	}

	if ((theta + beta) < 0)
	{
		alpha = 90 + ((double) theta + beta);
	}

	alpha = (90 - ( (double) theta + beta ));

	pix = get_pix(map, p, px);
	Ax = BLOCK_UNITS;

	/* calculate piy and Ay */
	piy = pix * tan(alpha * M_PI / 180);
	Ay = Ax * tan(alpha * M_PI / 180);

	dist = (pix + Ax) / cos(alpha * M_PI / 180);

	return (fabs(dist));
}

/**
 *
 *
 */
int get_pix(int **map __attribute__((unused)), GamePlayer *p, int *px)
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
	return (*px - edge_x);
}
