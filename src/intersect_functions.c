#include "../headers/demo.h"

/**
 * vertical_intersects - finds the closest vertical wall hit by the ray
 *
 */
double vertical_intersects(int **map, GamePlayer *p, double beta, int *px,
			   int *py)
{
	/* declarations */
	int theta;
	double alpha, dist;
	int pix, Ax, piy, Ay;

	/* inits */
	theta = p->theta % 360; /* this may not be necessary */
	alpha = dist = 0;
	pix = Ax = piy = Ay = 0;

	if (DEBUG == 2)
	{
		printf("---------------2--1--------------\n");
		printf("%p\n", (void *) map);
		printf("%p\n", (void *) py);
	}

	alpha = (90 - ( (double) theta + beta ));

	pix = get_pix(map, p, px);
	Ax = SQRT_BLOCK_UNITS;

	/* calculate piy and Ay */
	piy = pix * tan(alpha * M_PI / 180);
	Ay = Ax * tan(alpha * M_PI / 180);

	dist = pix / cos(alpha * M_PI / 180);

	if (DEBUG == 1)
	{
		printf("---------------7--------------\n");
		printf("alpha (degrees): %f\n", alpha);
		printf("pix: %d, piy: %d\n", pix, piy);
		printf("Ax: %d, Ay: %d\n", Ax, Ay);
		printf("Distance to vertical axis: %f\n", dist);
	}

	return (dist);
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
	edge_x = p->y + 1 * SQRT_BLOCK_UNITS;

	if (DEBUG == 1)
	{
		printf("---------------6--------------\n");
		printf("edge_x: %d\n", edge_x);
	}

	/* return the distance from player to right edge of block */
	return (*px - edge_x);
}

/**
 * horizontal_intersects - finds the closest horizontal wall hit by the ray
 *
 */
double horizontal_intersects(int **map, GamePlayer *p, double beta, int *px,
			     int *py)
{
	/* declarations */
	int theta;
	double alpha, dist;
	int pix, Ax, piy, Ay;

	/* inits */
	theta = p->theta % 360; /* this may not be necessary */
	alpha = dist = 0;
	pix = Ax = piy = Ay = 0;

	if (DEBUG == 2)
	{
		printf("---------------2--1--------------\n");
		printf("%p\n", (void *) map);
		printf("%p\n", (void *) px);
	}

	alpha = (90 - ( (double) theta + beta ));

	piy = get_piy(map, p, py);
	Ay = SQRT_BLOCK_UNITS;

	/* calculate piy and Ay */
	pix = piy / tan(alpha * M_PI / 180);
	Ax = Ay / tan(alpha * M_PI / 180);

	dist = piy / sin(alpha * M_PI / 180);

	if (DEBUG == 1)
	{
		printf("---------------9--------------\n");
		printf("alpha (degrees): %f\n", alpha);
		printf("pix: %d, piy: %d\n", pix, piy);
		printf("Ax: %d, Ay: %d\n", Ax, Ay);
		printf("Distance to horizontal axis: %f\n", dist);
	}

	return (dist);
}

/**
 *
 *
 */
int get_piy(int **map __attribute__((unused)), GamePlayer *p, int *py)
{
	int edge_y;

	edge_y = 0;

	/* get x-coordinate of right edge of block */
	edge_y = p->x + 1 * SQRT_BLOCK_UNITS;

	if (DEBUG == 1)
	{
		printf("---------------8--------------\n");
		printf("edge_y: %d\n", edge_y);
	}

	/* return the distance from player to right edge of block */
	return (*py - edge_y);
}
