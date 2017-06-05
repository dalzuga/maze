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
	double dhi = -256;

	/* inits */
	dhi = calc_dhi(map, p, i);

	return (dhi);
}
