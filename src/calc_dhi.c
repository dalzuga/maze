#include "../headers/demo.h"

/**
 * calc_dhi - finds the closest horizontal wall (y == C) hit by the ray
 *
 */
double calc_dhi(GameMap *map, GamePlayer *p, int ppcs4715)
{
	/* declarations */
	double ap;
	int By __attribute__((unused));
	int Px, Py, Ya, Xa, c, i, j;

	/* inits */
	ap = p->theta + (double) ppcs4715 / X_RES * FOV_ANGLE;
	ap = calc_mod360(ap);

	if (axis_angle(ap))	/* special cases: 0, 90, 180, 270 */
	{
		return (special_dhi(map, p, ap, ppcs4715));
	}
	else
	{
		Py = p->py;
		Px = p->px;
		/* end inits */

		/* up */
		if ((0 <= ap && ap < 90) || (270 < ap && ap < 360))
		{
			/* `Ya` signed vertical direction */
			Ya = -64;
		}
		/* down */
		else		/* if (90 <= ap && ap < 270) */
		{
			Ya = 64;
		}

		/* Xa - horizontal distance of the ray for each block */
		Xa = fabs(Ya * tan(ap * M_PI / 180));

		/* put the proper signs on `Xa` component */
		if (ap < 180)
		{
		}
		if (ap > 180)
		{
			Xa = -Xa;
		}

		/* `c` is the number of blocks crossed */
		for (c = 0; ; c++)
		{
			i = Px + c * Xa;
			if (DEBUG == 4)
				printf("Px + c * Xa: %d\n", i);
			j = Py + c * Ya;

			if (DEBUG >= 4)
			{
				printf("checking - [j][i]: [%d][%d]\t\t", j/64, i/64);
				printf("c: %d\t\ti:%d\tj:%d\n", c, i, j);
			}

			if (i/64 < 1 || i/64 > map->cols - 2)
			{
				/* bring back `i` since it's outside the map's boundary */
				if (ap < 180)
				{
					if (i > map->cols * 64)
					{
						i = (map->cols - 1) * 64;
					}
				}
				else if (ap > 180)
				{
					if (i < 64 - 1)
					{
						i = 64 - 1;
					}
				}
				else
				{
					i = Px;
				}

				if (DEBUG >= 3)
				{
					print_map(map, p);
					rcprint_map(map, p, j/64, i/64);
					printf("vertical border exceeded.\n");
				}
				break;
			}

			if (j/64 < 1 || j/64 > map->rows - 2)
			{
				if (DEBUG >= 3)
				{
					print_map(map, p);
					rcprint_map(map, p, j/64, i/64);
					printf("horizontal border exceeded.\n");
				}
				if (DEBUG >= 4)
				{
					printf("map->rows - 2: %d\n", map->rows - 2);
					printf("j is: %d\t\tj/64 is: %d\n", j, j/64);
				}
				break;
			}

			if (map->array[j/64][i/64] == 1)
			{
				if (DEBUG == 3)
				{
					printf("inside hit. [j][i]: [%d][%d]\n", j/64, i/64);
					printf("j, i: %d, %d\t\tc: %d\n", j, i, c);
				}
				if (DEBUG >= 2)
				{
					print_map(map, p);
					rcprint_map(map, p, j/64, i/64);
				}
				break;
			}
		}
	}

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
	}

	return (ap);
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
	else if (angle == 90)
	{
		/* displacement to right of map cell */
		Dx = (Px/64 + 1) - Px;

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
	else if (angle == 180)
	{
		/* displacement to bottom of map cell */
		dy = (Py/64 + 1) - Py;
		for (c = 0; ; c++)
		{
			/* add 64 * c */
			j = Px + (64) * c;

			if (map->array[j/64][i/64] == 1)
			{
				break;
			}
		}
	}
	else			/* if (angle == 270) */
	{
		/* displacement to left of map cell */
		Dx = (Px/64) - Px;

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
		dist = dy + abs(Py - j);
	/* left-right */
	else
		dist = Dx + abs(Px - i);

	if (DEBUG >= 2)
	{
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
		print_map(map, p);
		rcprint_map(map, p, j/64, i/64);
		exit(1);
	}

	return (dist);

}
