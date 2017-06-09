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
	int Dx, dy, Px, Py, Ya, Xa, c, i, j;

	/* inits */
	ap = p->theta + (double) ppcs4715 / X_RES * FOV_ANGLE;
	ap = calc_mod360(ap);

	Py = p->py;
	Px = p->px;
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
		j = Py + dy + c * Ya;

		if ((j/64) < 0 || (j/64) > map->rows)
		{
			c = c - 2;
			break;
		}
	}

	Dx = fabs(dy / tan(ap * M_PI / 180));
	Xa = fabs(Ya / tan(ap * M_PI / 180));

	if (ap < 180)
	{
		i = Px + Dx + c * Xa;
		printf("i: %d\n", i);
	}
	else if (ap > 180)
	{
		i = Px - Dx - c * Xa;
	}
	else
	{
		i = Px;
	}

	j = Py + dy + c * Ya;

	if (DEBUG == 2)
	{
		printf("-------------11-1-------------\n");
		printf("(i, j): (%d, %d)\t\t", i, j);
		printf("(i/64, j/64): (%d, %d)\n", i/64, j/64);
		printf("player_pos: (%d, %d)\t\t", Px, Py);
		printf("ap: %f\n", ap);
		printf("ppcs4715: %d\n", ppcs4715);
	}

	return (ap);
}
