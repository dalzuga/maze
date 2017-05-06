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
	double alpha;
	int pix, Ax, piy;

	/* inits */
	theta = p->theta % 360;
	pix = 0;
	alpha = 0;

	if (DEBUG == 2)
	{
		printf("---------------2--1--------------\n");
		printf("%p\n", (void *) map);
		printf("%p\n", (void *) p);
		printf("%p\n", (void *) &beta);
		printf("%p\n", (void *) px);
		printf("%p\n", (void *) py);
	}

	alpha = (90 - ( (double) theta + beta ));

	pix = get_pix(map, p, px);
	Ax = SQRT_BLOCK_UNITS;

	/* calculate piy and Ay */
	piy = pix * tan(alpha * M_PI / 180);

	if (DEBUG == 1)
	{
		printf("---------------7--------------\n");
		printf("alpha (degrees): %f\n", alpha);
		printf("pix: %d, piy: %d\n", pix, piy);
		printf("Ax: %d\n", Ax);
	}

	/* if ( (theta < 90) || (theta > 270) ) /\* facing up *\/ */
	/* { */

	/* } */
	/* else if ( (theta > 90) && (theta < 270) ) /\* facing down *\/ */
	/* { */

	/* } */
	/* else */
	/* { */
	/* 	/\* special case: theta is 0, 90, 180, or 270 *\/ */
	/* } */

	return (0);
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
	if (DEBUG == 2)
	{
		printf("---------------2--1--------------\n");
		printf("%p\n", (void *) map);
		printf("%p\n", (void *) p);
		printf("%p\n", (void *) &beta);
		printf("%p\n", (void *) px);
		printf("%p\n", (void *) py);
	}

	return (0);
}

/**
 *
 *
 */
int get_piy(int **map, GamePlayer *p, int *px, int *py)
{
	if (DEBUG == 2)
	{
		printf("---------------2--1--------------\n");
		printf("%p\n", (void *) map);
		printf("%p\n", (void *) p);
		printf("%p\n", (void *) px);
		printf("%p\n", (void *) py);
	}

	return (0);
}
