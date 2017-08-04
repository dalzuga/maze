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
	int Px, Py, Ya, Xa, c, i, j;
	int total_x, dist_dvi;

	/* inits */
	dx = 0;
	ap = p->theta + (double) ppcs4715 / X_RES * FOV_ANGLE;
	ap = calc_mod360(ap);
	Py = p->py;
	Px = p->px;
	/* end inits */

	if (axis_angle(ap))	/* special cases: 0, 90, 180, 270 */
	{
		return (special_dhi(map, p, ap, ppcs4715));
	}

	/* `Xa` signed horizontal direction */
	/* right */
	if (ap < 180)
	{
		Xa = 64;
		dx = (Px/64 + 1) * 64 - Px; /* be on the right edge */
	}
	/* left */
	else			/* guaranteed --> (ap > 180) */
	{
		Xa = -64;
		dx = Px - (Px/64) * 64; /* be on the left edge */
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
		i = Px + dx + c * Xa;
		j = Py - (i - Px) / tan(ap * M_PI / 180);

		/*
                 * check for top and bottom overrun
		 * highlight the "escape" cell
                 */
		if (j/64 < 1 || j/64 > map->rows - 2)
		{
			/* calculate the distance */
			/* right */
			if (ap < 180)
			{
				total_x = i/64 * 64 - Px;
			}
			/* left */
			else
			{
				total_x = (i/64 + 1) * 64 - Px;
			}

			/*
                         * top boundary overrun, bring `j` back
			 * (up)
                         */
			if (j/64 < 1)
			{
				j = 0;
			}
			/*
                         * bottom boundary overrun, bring `j` back
			 * (down)
                         */
			else
			{
				j = (map->rows - 1) * 64;
			}

			/* 
                         * if (DEBUG >= 3)
			 * {
			 * 	print_map(map, p);
			 * 	rcprint_map(map, p, j/64, i/64);
			 * 	printf("horizontal border exceeded.\n");
			 * }
                         */
			break;
		}

		/*
		 * check for left and right overrun
		 * highlight the "escape" cell
		 */
		if (i/64 < 1 || i/64 > map->cols - 2)
		{
			/* calculate the distance */
			/* right */
			if (ap < 180)
			{
				total_x = i/64 * 64 - Px;
			}
			/* left */
			else
			{
				total_x = (i/64 + 1) * 64 - Px;
			}

			/*
                         * left boundary overrun, bring `i` back
                         */
			if (i/64 < 1)
			{
				i = 0;
			}
			/*
                         * right boundary overrun, bring `i` back
                         */
			else
			{
				i = (map->cols - 1) * 64;
			}

			/* 
                         * if (DEBUG >= 3)
			 * {
			 * 	print_map(map, p);
			 * 	rcprint_map(map, p, j/64, i/64);
			 * 	printf("vertical border exceeded.\n");
			 * }
                         */
			break;
		}

		if (map->array[j/64][i/64] == 1)
		{
			/* calculate the (absolute) distance */
			/* right */
			if (ap < 180)
			{
				total_x = i/64 * 64 - Px;
			}
			/* left */
			else
			{
				total_x = (i/64 + 1) * 64 - Px;
			}

			/* 
                         * if (DEBUG >= 2)
			 * {
			 * 	print_map(map, p);
			 * 	rcprint_map(map, p, j/64, i/64);
			 * }
                         */
			break;
		}
	}

	dist_dvi = total_x / sin(ap * M_PI / 180);

	if (DEBUG >= 2)
	{
		printf("-----------11-1--dvi----------\n");
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
		print_map(map, p);
		rcprint_map(map, p, j/64, i/64);
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
