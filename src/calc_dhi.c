#include "../headers/demo.h"

/**
 * calc_dhi - finds the closest horizontal wall (x == C) hit by the ray
 *
 */
double calc_dhi(GameMap *map, GamePlayer *p, int ppcs4715)
{
	/* declarations */
	double ap;
	int By __attribute__((unused));
	int dy, Py, Ya, c, j;

	/* inits */
	ap = p->theta + (double) ppcs4715 / X_RES * FOV_ANGLE;
	ap = calc_mod360(ap);

	Py = p->py;
	/* end inits */

	if (0 <= ap && ap < 90)
	{
		dy = (64) * (Py/64) - Py - 1;
		Ya = -64;
	}
	else if (90 <= ap && ap < 180)
	{
		dy = (64) * (Py/64 + 1) - Py;
		Ya = 64;
	}
	else if (180 <= ap && ap < 270)
	{
		dy = (64) * (Py/64 + 1) - Py;
		Ya = 64;
	}
	else
	{
		dy = (64) * (Py/64) - Py - 1;
		Ya = -64;
	}

	for (c = 0; ; c++)
	{
		j = (Py + dy + c * Ya) / 64;
		if (j < 0 || j > map->rows)
		{
			c = c - 2;
			break;
		}
	}

	if (DEBUG == 1)
	{
		printf("-------------9--1-------------\n");
		By = Py + dy;
		printf("By: %d\n", By);
		printf("Zy: %d\n", Py + dy + c * Ya);

		printf("map_size: (%d, %d),", map->cols, map->rows);
		printf("player_pos: (%d, %d)\n", p->px, p->py);
		printf("c: %d\n", c);
	}

	return (ap);
}
