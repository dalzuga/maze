#include "../headers/demo.h"

/**
 * calc_dvi - finds the closest horizontal wall (y == C) hit by the ray
 *
 */
double calc_dvi(GameMap *map, GamePlayer *p, int ppcs4715)
{
	/* declarations */
	double ap;
	int By __attribute__((unused));
	int Px, Py, Ya, Xa, c, i, j;
	int total_x, dist_dvi;

	/* inits */
	ap = p->theta + (double) ppcs4715 / X_RES * FOV_ANGLE;
	ap = calc_mod360(ap);

	if (axis_angle(ap))	/* special cases: 0, 90, 180, 270 */
	{
		return (special_dhi(map, p, ap, ppcs4715));
	}

	Py = p->py;
	Px = p->px;
	/* end inits */

	/* `Xa` signed horizontal direction */
	/* right */
	if (ap < 180)
	{
		Xa = 64;
	}
	/* left */
	else			/* guaranteed --> (ap > 180) */
	{
		Xa = -64;
	}

	/* Ya - vertical distance of the ray for each block */
	Ya = fabs(Xa / tan(ap * M_PI / 180));

	/* put the proper signs on `Ya` component */
	/* down */
	if (90 < ap && ap < 270)
	{
	}
	/* up */
	else 			/* guaranteed --> ap < 90 || ap > 270  */
	{
		Ya = -Ya;
	}

	/* `c` is the number of blocks crossed */
	for (c = 0; ; c++)
	{
		i = Px + c * Xa;
		j = Py + c * Ya;

		if (j/64 < 1 || j/64 > map->rows - 2)
		{
			c = c - 1;

			/* bring back `j` since it's outside the map boundary */
			/* down */
			if (90 < ap && ap < 270)
			{
				if (j > map->rows * 64)
				{
					j = (map->rows - 1) * 64;
				}
			}
			/* up */
			else if (ap < 90 || ap > 270)
			{
				if (j < 64)
				{
					j = 64 - 1;
				}
			}
			else	/* this shouldn't happen */
			{
				j = Py;
			}

			if (DEBUG >= 3)
			{
				print_map(map, p);
				rcprint_map(map, p, j/64, i/64);
				printf("horizontal border exceeded.\n");
			}
			break;
		}

		if (i/64 < 1 || i/64 > map->cols - 2)
		{
			if (DEBUG >= 3)
			{
				print_map(map, p);
				rcprint_map(map, p, j/64, i/64);
				printf("vertical border exceeded.\n");
			}
			break;
		}

		if (map->array[j/64][i/64] == 1)
		{
			if (DEBUG >= 2)
			{
				print_map(map, p);
				rcprint_map(map, p, j/64, i/64);
			}
			break;
		}
	}

	/* calculate the distance */
	total_x = (i/64) * 64 - Px;
	dist_dvi = total_x / sin(ap * M_PI / 180);

	if (DEBUG >= 2)
	{
		printf("-------------11-1-------------\n");
		printf("(i, j): (%d, %d)\t\t", i, j);
		printf("(i/64, j/64): (%d, %d)\n", i/64, j/64);
		printf("player_pos: (%d, %d)\t\t", Px, Py);
		printf("player_pos: [%d, %d]\t\t", Px/64, Py/64);
		printf("ap: %f\n", ap);
		printf("c: %d\t\t", c);
		printf("ppcs4715: %d\n", ppcs4715);
		printf("Ya: %d\t\t", Ya);
		printf("Xa: %d\n", Xa);
		printf("total_x: %d\n", total_x);
		printf("dist_dvi: %d\n", dist_dvi);
	}

	return (dist_dvi);
}

/**
 * _calc_dvi - debug wrapper to call calc_dvi
 *
 */
double _calc_dvi(GameMap *map, GamePlayer *p, int ppcs4715)
{
	return (calc_dvi(map, p, ppcs4715));
}
