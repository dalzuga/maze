#include "../headers/demo.h"

/**
 * calc_dhi - finds the closest horizontal wall (y == C) hit by the ray
 *
 */
double calc_dhi(GameMap *map, GamePlayer *p, int ppcs4715)
{
	/* declarations */
	double ap;
	int dy;
	int Px, Py, Ya, Xa, c, i, j;
	int total_y, dist_dhi;

	/* inits */
	dy = 0;
	ap = p->theta + (double) ppcs4715 / X_RES * FOV_ANGLE;
	ap = calc_mod360(ap);
	Py = p->py;
	Px = p->px;
	/* end inits */

	if (axis_angle(ap))	/* special cases: 0, 90, 180, 270 */
	{
		return (special_dhi(map, p, ap, ppcs4715));
	}

	/* `Ya` signed vertical direction */
	/* down */
	if (90 <= ap && ap < 270)
	{
		Ya = 64;
		dy = (Py/64 + 1) * 64 - Py; /* be on the bottom edge (neg) */
	}
	/* up */
	else /* guaranteed --> (0 <= ap && ap < 90) || (270 < ap && ap < 360) */
	{
		Ya = -64;
		dy = Py - (Py/64) * 64; /* be on the top edge (positive) */
	}

	/* Xa - horizontal distance of the ray for each block */
	Xa = fabs(Ya / tan(ap * M_PI / 180));

	/* put the proper signs on `Xa` component */
	/* right */
	if (ap < 180)
	{
	}
	/* left */
	else /* guaranteed --> (ap > 180) */
	{
		Xa = -Xa;
	}

	/* `c` is the number of blocks crossed */
	for (c = 0; ; c++)
	{
		j = Py + dy + c * Ya;
		i = Px - (j - Py) / tan(ap * M_PI / 180);

		/*
                 * check for left and right overrun
		 * highlight the "escape" cell
                 */
		if (i/64 < 1 || i/64 > map->cols - 2)
		{
			/* calculate the distance */
			/* down */
			if (90 <= ap && ap < 270)
			{
				total_y = j/64 * 64 - Py;
			}
			/* up */
			else
			{
				total_y = (j/64 + 1) * 64 - Py;
			}

			/*
                         * left boundary overrun, bring `i` back
			 * (left)
                         */
			if (i/64 < 1)
			{
				i = 0;
			}
			/*
                         * right boundary overrun, bring `i` back
			 * (right)
                         */
			else
			{
				i = (map->cols - 1) * 64;
			}

			/* 
                         * if (DEBUG >= 2)
			 * {
			 * 	print_map(map, p);
			 * 	rcprint_map(map, p, j/64, i/64);
			 * 	printf("vertical border exceeded.\n");
			 * }
                         */
			break;
		}

		/*
                 * check for top and bottom overrun
		 * highlight the "escape" cell
                 */
		if (j/64 < 1 || j/64 > map->rows - 2)
		{
			/* calculate the distance */
			/* down */
			if (90 <= ap && ap < 270)
			{
				total_y = j/64 * 64 - Py;
			}
			/* up */
			else
			{
				total_y = (j/64 + 1) * 64 - Py;
			}

			/*
                         * top boundary overrun, bring `j` back
                         */
			if (j/64 < 1)
			{
				j = 0;
			}
			/*
                         * bottom boundary overrun, bring `j` back
                         */
			else
			{
				j = (map->rows - 1) * 64;
			}

			/* 
                         * if (DEBUG >= 2)
			 * {
			 * 	print_map(map, p);
			 * 	rcprint_map(map, p, j/64, i/64);
			 * 	printf("horizontal border exceeded.\n");
			 * }
                         */
			break;
		}

		if (map->array[j/64][i/64] == 1)
		{
			/* calculate the (absolute) distance */
			/* down */
			if (90 <= ap && ap < 270)
			{
				total_y = j/64 * 64 - Py;
			}
			/* up */
			else
			{
				total_y = (j/64 + 1) * 64 - Py;
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

	dist_dhi = total_y / cos(ap * M_PI / 180);

	if (DEBUG >= 2)
	{
		printf("-----------11-1--dhi----------\n");
		printf("(i, j): (%d, %d)\t\t", i, j);
		printf("(i/64, j/64): (%d, %d)\n", i/64, j/64);
		printf("player_pos: (%d, %d)\t\t", Px, Py);
		printf("player_pos: [%d, %d]\t\t", Px/64, Py/64);
		printf("ap: %f\n", ap);
		printf("c: %d\t\t", c);
		printf("ppcs4715: %d\n", ppcs4715);
		printf("Ya: %d\t\t", Ya);
		printf("Xa: %d\n", Xa);
		printf("total_y: %d\n", total_y);
		printf("dist_dhi: %d\n", dist_dhi);
		print_map(map, p);
		rcprint_map(map, p, j/64, i/64);
	}

	return (dist_dhi);
}

/**
 * _calc_dhi - debug wrapper to call calc_dhi
 *
 */
double _calc_dhi(GameMap *map, GamePlayer *p, int ppcs4715)
{
	return (calc_dhi(map, p, ppcs4715));
}

/**
 * special_dhi - calculates distance when angle is on an axis
 */
int special_dhi(GameMap *map, GamePlayer *p, double angle, int ppcs4715)
{
	/* declarations */
	int Dx, dy, Px, Py, c, i, j, dist;

	/* inits */
	Dx = dy = 0;
	Py = p->py;
	Px = p->px;
	i = Px;
	j = Py;


	/* up */
	if (angle == 0)
	{
		/* displacement to top of map cell */
		dy = (Py/64) * (64) - Py;

		for (c = 0; ; c++)
		{
			/* subtract 64 * c */
			j = Py - (64) * c;
			if (map->array[j/64][i/64] == 1)
			{
				break;
			}
		}
	}
	/* right */
	else if (angle == 90)
	{
		/* displacement to right of map cell */
		Dx = (Px/64 + 1) * (64) - Px;

		for (c = 0; ; c++)
		{
			/* add 64 * c */
			i = Px + (64) * c;

			if (map->array[j/64][i/64] == 1)
			{
				break;
			}
		}
	}
	/* down */
	else if (angle == 180)
	{
		/* displacement to bottom of map cell */
		dy = (Py/64 + 1) * (64) - Py;

		for (c = 0; ; c++)
		{
			/* add 64 * c */
			j = Py + (64) * c;

			if (map->array[j/64][i/64] == 1)
			{
				break;
			}
		}
	}
	/* left */
	else			/* guaranteed --> (angle == 270) */
	{
		/* displacement to left of map cell */
		Dx = (Px/64) * 64 - Px;

		for (c = 0; ; c++)
		{
			/* subtract 64 * c */
			i = Px - (64) * c;

			if (map->array[j/64][i/64] == 1)
			{
				break;
			}
		}
	}

	/* calculate the distance */
	/* up-down */
	if (angle == 0 || angle == 180)
	{
		dist = dy + abs(j - Py);
	}
	/* left-right */
	else
	{
		dist = Dx + abs(i - Px);
	}

	/* adjust distance for positive direction */
	if (angle == 90)
	{
		dist -= 64;
	}
	else if (angle == 180)
	{
		dist -= 64;
	}

	if (DEBUG >= 2)
	{
		print_map(map, p);
		rcprint_map(map, p, j/64, i/64);
		printf("----------11-1-SPECIAL--------\n");
		printf("(i, j): (%d, %d)\t\t", i, j);
		printf("(i/64, j/64): (%d, %d)\n", i/64, j/64);
		printf("player_pos: (%d, %d)\t\t", Px, Py);
		printf("player_pos: [%d, %d]\t\t", Px/64, Py/64);
		/* 
                 * printf("(i, j): (%d, %d)\t\t", i, j);
		 * printf("(i/64, j/64): (%d, %d)\n", i/64, j/64);
		 * printf("player_pos: (%d, %d)\t\t", Px, Py);
                 */
		printf("ap: %f\n", angle);
		printf("c: %d\t\t", c);
		printf("ppcs4715: %d\n", ppcs4715);
		printf("dist: %d\n", dist);
	}

	return (dist);

}
