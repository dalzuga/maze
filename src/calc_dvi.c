#include "../headers/demo.h"

/**
 * calc_dvi - finds the closest horizontal wall (y == C) hit by the ray
 *
 */
double calc_dvi(GameMap *map, GamePlayer *p, int ppcs4715)
{
	/* declarations */
	double ap;
	int dx;
	int Px, Py, c, i, j;
	int Xa;
	/* int flag; */
	int dist;

	/* inits */
	ap = p->theta + (double) ppcs4715 / X_RES * FOV_ANGLE;
	ap = calc_mod360(ap);
	Py = p->py;
	Px = p->px;
	/* flag = 0; */
	dist = 0;
	/* end inits */

	if (axis_angle(ap))	/* special cases: 0, 90, 180, 270 */
	{
		return (special_dhi(map, p, ap, ppcs4715));
	}

	dx = calc_dx(p, ap);
	Xa = calc_Xa(ap);

	i = Px + dx;

	if (ap < 90)
	{
		j = Py - (i - Px) / tan(ap * M_PI / 180);
		dist = (int) (i - Px) / sin(ap * M_PI / 180);
	}
	else if (ap < 180)
	{
		j = Py + (i - Px) * tan((ap - 90) * M_PI / 180);
		dist = (int) (i - Px) / cos((ap - 90) * M_PI / 180);
	}
	else if (ap < 270)
	{
		j = Py + (Px - i) / tan((ap - 180) * M_PI / 180);
		dist = (int) (Px - i) / sin((ap - 180) * M_PI / 180);
	}
	else
	{
		j = Py - (Px - i) * tan((ap - 270) * M_PI / 180);
		dist = (int) (Px - i) / cos((ap - 270) * M_PI / 180);
	}

	for (c = 1; ; c++)
	{
		if (j <= 0 || j >= map->rows * 64)
		{
			/* flag = 1; */
			break;
		}

		if (i == 0)
		{
			/* flag = 2; */
			break;
		}

		if (i == map->rows * 64)
		{
			/* flag = 3; */
			break;
		}

		if (ap > 180) /* left */
		{
			/* check left side of border */
			if (map->array[j/64][(i - 1)/64] == 1)
			{
				/* flag = 4; */
				break;
			}
		}
		else		/* right */
		{
			/* check right side of border */
			if (map->array[j/64][i/64] == 1)
			{
				/* flag = 5; */
				break;
			}
		}

		i = Px + dx + c * Xa;

		if (ap < 90)
		{
			j = Py - (i - Px) / tan(ap * M_PI / 180);
			dist = (int) (i - Px) / sin(ap * M_PI / 180);
		}
		else if (ap < 180)
		{
			j = Py + (i - Px) * tan((ap - 90) * M_PI / 180);
			dist = (int) (i - Px) / cos((ap - 90) * M_PI / 180);
		}
		else if (ap < 270)
		{
			j = Py + (Px - i) / tan((ap - 180) * M_PI / 180);
			dist = (int) (Px - i) / sin((ap - 180) * M_PI / 180);
		}
		else
		{
			j = Py - (Px - i) * tan((ap - 270) * M_PI / 180);
			dist = (int) (Px - i) / cos((ap - 270) * M_PI / 180);
		}
	}

	if (DEBUG >= 2)
	{
		printf("-----------11-1--dvi----------\n");
		printf("map size: [%d, %d]\t\t", map->cols, map->rows);
		printf("(%d, %d)\n", map->cols * BLOCK_UNITS, map->rows * 64);
		printf("player_pos:\t(%d, %d)\t", Px, Py);
		printf("player_pos: [%d, %d]\n", Px/64, Py/64);
		printf("(i, j):\t(%d, %d)\t", i, j);
		printf("(i/64, j/64): [%d, %d]\t", i/64, j/64);
		printf("ap: %f\n", ap);
		printf("c: %d\t\t", c);
		printf("ppcs4715: %d\n", ppcs4715);
		printf("dist: %d\n", dist);
		rcprint_map(map, p, j/64, i/64);
	}

	return (dist);
}

/**
 * _calc_dvi - debug wrapper to call calc_dvi
 *
 */
double _calc_dvi(GameMap *map, GamePlayer *p, int ppcs4715)
{
	return (calc_dvi(map, p, ppcs4715));
}

int calc_dx(GamePlayer *p, double ap)
{
	int dx;
	int Px;

	Px = p->px;

	if (ap < 180) 		/* right */
	{
		dx = (Px/64 + 1) * 64 - Px;
	}
	else			/* left */
	{
		dx = (Px/64 * 64) - Px;
	}

	return (dx);
}

int calc_Xa(double ap)
{
	if (ap > 180) 		/* left */
	{
		return (-64);
	}

	/* right */
	return (64);
}
