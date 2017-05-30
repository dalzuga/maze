#include "../headers/demo.h"

/**
 * calc_func01 - calculate how far the ray cast travels until it meets a wall.
 *
 * @map: address of map
 * @p: address of player
 * @i: specific ray within projection plane
 *
 * Return: length of the ray-line.
 */
double calc_func01(int **map __attribute__ ((unused)), GamePlayer *p, int i)
{
	/* declarations + inits */
	double rclen = -1, dvi = -1, dhi = -1;
	int px = -1, py = -1;
	double beta = (double) FOV_ANGLE * i / (double) X_RES;
	double theta = p->theta - FOV_ANGLE / 2;

	/* inits */
	calc_pxpy(p, &px, &py);

	dvi = calc_dvi(map, p, beta, &px, &py);
	dhi = calc_dhi(map, p, beta, &px, &py);

	if (DEBUG == 1)
	{
		printf("---------------3--------------\n");
		printf("player position on map: (%d, %d), absolute: (%d, %d), \
p->theta: %d\n", p->x, p->y, px, py, p->theta);
		printf("cos((theta + beta) * M_PI / 180): %f\n",
		       cos((theta + beta) * M_PI / 180));
		printf("theta + beta: %f, cos(theta + beta): %f, rclen: %f\n",
		       theta + beta, cos((theta + beta) * M_PI / 180), rclen);
		printf("beta - FOV_ANGLE / 2: %f\n", beta - FOV_ANGLE / 2);
	}

	return (fmin(dvi, dhi));

}

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

/**
 * calc_dhi - finds the closest horizontal wall (y == C) hit by the ray
 *
 */
double calc_dhi(int **map, GamePlayer *p, double beta, int *px, int *py)
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
		printf("---------------2--2--------------\n");
		printf("%p\n", (void *) map);
		printf("%p\n", (void *) px);
	}

	if ((theta + beta) < 0)
	{
		alpha = 90 + ((double) theta + beta);
	}

	alpha = (90 - ( (double) theta + beta ));

	piy = get_piy(map, p, py);
	Ay = BLOCK_UNITS;

	/* calculate piy and Ay */
	pix = piy / tan(alpha * M_PI / 180);
	Ax = Ay / tan(alpha * M_PI / 180);

	dist = (piy + Ay) / sin(alpha * M_PI / 180);

	if (DEBUG == 1)
	{
		printf("---------------9--------------\n");
		printf("alpha (degrees): %f\n", alpha);
		printf("pix: %d, piy: %d\n", pix, piy);
		printf("Ax: %d, Ay: %d\n", Ax, Ay);
		printf("Distance to horizontal axis: %f\n", dist);
	}

	return fabs(dist);
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
	edge_y = p->x + 1 * BLOCK_UNITS;

	if (DEBUG == 1)
	{
		printf("---------------8--------------\n");
		printf("edge_y: %d\n", edge_y);
	}

	/* return the distance from player to right edge of block */
	return (*py - edge_y);
}
