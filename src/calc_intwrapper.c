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
	double dvi = -1, dhi = -1;
	double beta = (double) FOV_ANGLE * i / (double) X_RES;

	/* inits */
	calc_pxpy(p);

	dvi = calc_dvi(map, p, beta);
	dhi = calc_dhi(map, p, beta);

	return (fmin(dvi, dhi));
}
