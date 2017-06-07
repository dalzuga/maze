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
	int dy, Py, Ya, c, i, j, deltaY;

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
		deltaY = dy + c * Ya;
		j = (Py + deltaY) / 64;

		if (j < 0 || j > map->rows)
		{
			c = c - 2;
			break;
		}
	}

	deltaY = dy + c * Ya;
	i = (p->px + (deltaY / tan(ap))) / 64;
	j = Py + deltaY / 64;

	if (DEBUG == 2)
	{
		printf("-------------11-1-------------\n");
		printf("(i, j): (%d, %d)\t\t", i, j);
		printf("deltaY: %d\n", deltaY);
		printf("dy: %d\n", dy);
		printf("c: %d\n", c);
	}

	if (DEBUG == 2)
	{
		printf("-------------9--1-------------\n");
		By = Py + dy;
		printf("By: %d\t\t", By);
		printf("Zy: %d\t\t", Py + dy + c * Ya);
		printf("ap: %f\n", ap);

		printf("map_size: (%d, %d)\t", map->cols, map->rows);
		printf("player_pos: (%d, %d)\n", p->px, p->py);
	}

	return (ap);
}
