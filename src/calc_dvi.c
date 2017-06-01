#include "../headers/demo.h"

/**
 * calc_dvi - finds the closest vertical wall (y == C) hit by the ray
 *
 */
double calc_dvi(GameMap *map, GamePlayer *p, double alpha)
{
	/* declarations */
	double dist;

	dist = calc_vblock(map, p, alpha);

	return fabs(dist);
}

/**
 * calc_vblock - finds the closest vertical wall (y == C) hit by the ray
 *
 */
double calc_vblock(GameMap *map, GamePlayer *p, double alpha)
{
	/* declarations */
	double dist;
	int pix, Ax, piy, Ay;

	/* inits */
	dist = 0;
	pix = Ax = piy = Ay = 0;

	pix = get_pix(map, p, alpha);
	Ax = BLOCK_UNITS;

	/* calculate piy and Ay */
	piy = pix * tan(alpha * M_PI / 180);
	Ay = Ax * tan(alpha * M_PI / 180);

	dist = (pix + (map->cols - 2) * Ax) / cos(alpha * M_PI / 180);

	return (fabs(dist));
}

/**
 *
 *
 */
int get_pix(GameMap *map __attribute__((unused)), GamePlayer *p, double alpha)
{
	int pix;

	pix = calc_pix(map, p, alpha);
	return (pix);
}
