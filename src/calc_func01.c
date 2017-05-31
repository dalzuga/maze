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
	double rclen = -1;
	double beta = (double) FOV_ANGLE * i / (double) X_RES;

	/* inits */
	rclen = calc_func02(map, p, i);

	/* correct for spherical distortion */
	rclen = rclen * cos((beta - FOV_ANGLE / 2) * M_PI / 180);

	return (rclen);
}
