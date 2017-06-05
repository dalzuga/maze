#include "../headers/demo.h"

/**
 * calc_dhi - finds the closest horizontal wall (x == C) hit by the ray
 *
 */
double calc_dhi(GameMap *map, GamePlayer *p, int i)
{
	/* declarations */
	double ap;
	int dy, Py, Ay, Ya, c, j, tmp;

	/* inits */
	ap = p->theta + (double) i / X_RES * FOV_ANGLE;
	ap = calc_mod360(ap);

	Py = p->py;
	dy = (64) * (Py/64) - Py - 1;
	Ay = Py + dy;
	Ya = -BLOCK_UNITS;

	printf("Ay: %d\n", Ay);

	for (c = 0; ; c++)
	{
		tmp = (Py + dy + c * Ya) / 64;
		if (tmp < 0 || tmp > map->rows)
		{
			break;
		}
		else
		{
			j = tmp;
		}
	}

	printf("map_size: (%d, %d)\n", map->cols, map->rows);
	printf("c: %d\n", c);
	printf("j: %d\n", j);

	return (ap);
}
