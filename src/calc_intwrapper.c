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
double calc_intwrapper(GameMap *map, GamePlayer *p, int i)
{
	/* declarations + inits */
	double dvi = -1, dhi = -1, alpha = -1;
	double beta, theta, tplusb;

	beta = (double) FOV_ANGLE * i / (double) X_RES;
	theta = (double) p->theta - FOV_ANGLE / 2;
	tplusb = calc_quad01(beta + theta);

	if (tplusb == 0)
	{
		return (get_piy(map, p));
	}
	if (tplusb == 90)
	{
		return (get_pix(map, p));
	}
	if (tplusb == 180)
	{
		return (get_piy(map, p));
	}
	if (tplusb == -90)
	{
		return (get_pix(map, p));
	}

	/* inits */
	alpha = calc_alpha(map, p, i);

	dvi = calc_dvi(map, p, alpha);
	dhi = calc_dhi(map, p, alpha);

	return (fmin(dvi, dhi));
}

/**
 * calc_alpha - calculates angle alpha
 *
 */
double calc_alpha(GameMap *map, GamePlayer *p, int i)
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
