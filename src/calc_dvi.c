#include "../headers/demo.h"

/**
 * calc_dvi - finds the vertical wall (x == C) hit by the ray
 *
 */
double calc_dvi(GameMap *map, GamePlayer *p, int ppcs4715)
{
	/* declarations */
	double ap;
	int Ax __attribute__((unused));
	int dx, Px, Xa, c, i;

	/* inits */
	ap = p->theta + (double) ppcs4715 / X_RES * FOV_ANGLE;
	ap = calc_mod360(ap);

	Py = p->py;
	/* end inits */

	if (0 <= ap && ap < 90)
	{
		dx = 64 * (Px/64 + 1) - Px;
		Xa = 64;
	}
	else if (90 <= ap && ap < 180)
	{
		dx = 64 * (Px/64 + 1) - Px;
		Xa = 64;
	}
	else if (180 <= ap && ap < 270)
	{
		dx = 64 * (Px/64) - Px - 1;
		Xa = -64;
	}
	else
	{
		dx = 64 * (Px/64) - Px - 1;
		Xa = -64;
	}

	for (c = 0; ; c++)
	{
		j = (Px + dx + c * Xa) / 64;
		if (j < 0 || j > map->cols)
		{
			c = c - 2;
			break;
		}
	}

	if (DEBUG == 1)
	{
		printf("----------9--2----------\n");
		Ax = Px + dx;
		printf("Ax: %d\n", Ax);
		printf("Zx: %d\n", Px + dx + c * Xa);

		printf("map_size: (%d, %d)\n", map->cols, map->rows);
		printf("c: %d\n", c);
	}

	return (ap);
}
