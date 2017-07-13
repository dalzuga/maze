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
	int Dx, dy, Px, Py, Ya, Xa, c, i, j;

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
			/*
			 * get the distance `dy` to the horizontal block edge
			 *
			 * +--+------+ <--- horizontal edge
			 * |  |      |
			 * |  |      |
			 * |  P      |
			 * |         |
			 * +---------+
			 */

			dy = (64) * (Py/64) - Py;
			/* `Ya` signed vertical direction */
			Ya = -64;
		}
		/* down */
		else		/* if (90 <= ap && ap < 270) */
		{
			dy = (64) * (Py/64 + 1) - Py;
			Ya = 64;
		}

		/*
		 * obtain `Dx`, inside distance to the vertical edge
		 *
		 * +---------+
		 * |         |
		 * |         |
		 * |  P------+
		 * |         |
		 * +---------+
		 */

		/************************************************
                 * Dx = fabs(dy * tan(ap * M_PI / 180));        *
                 ************************************************/

		/* Xa - horizontal distance of the ray for each block */
		Xa = fabs(Ya * tan(ap * M_PI / 180));

		/* put the proper signs on `Xa` component, calc `Dx` */
		if (ap < 180)
		{
			/* Dx = 64 - (Px % 64); */
			Dx = 64 * (Px/64 + 1) - Px;
		}
		if (ap > 180)
		{
			Xa = -Xa;
			/* Dx = -(Px % 64); */
			Dx = 64 * (Px/64) - Px - 1;
		}

		/* `c` is the number of blocks crossed */
		for (c = 0; ; c++)
		{
			i = Px + Dx + c * Xa;
			printf("Px + Dx + c * Xa: %d\n", i);
			j = Py + dy + c * Ya;

			printf("checking - [j][i]: [%d][%d]\t\t", j/64, i/64);
			printf("c: %d\t\ti:%d\tj:%d\n", c, i, j);

			if (i/64 < 1 || i/64 > map->cols - 2)
			{
				printf("vertical border exceeded.\n");
				/*
                                 * printf("rolling back c...\n");
				 * c = c - 1;
				 * printf("c is now... c: %d\n", c);
                                 */
				break;
			}

			usleep(200000);
			if (map->array[j/64][i/64] == 1)
			{
				printf("boom! [j][i]: [%d][%d]\n", j/64, i/64);
				printf("j, i: %d, %d\n", j, i);
				rcprint_map(map, p, j/64, i/64);
				usleep(2500000);
				break;
			}

			if (j/64 < 1 || j/64 > map->rows - 2)
			{
				printf("map->rows - 2: %d\n", map->rows - 2);

				printf("j is: %d\t\tj/64 is: %d\n", j, j/64);
				printf("horizontal border exceeded.\n");
				/*
                                 * printf("rolling back c...\n");
				 * c = c - 1;
				 * printf("c is now... c: %d\n", c);
                                 */
				break;
			}
		}

		/* bring back `i` if it's outside the map's boundary */
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
	}

	if (DEBUG == 2)
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
		rcprint_map(map, p, j/64, i/64);
	}

	return (ap);
}

/**
 * special_dhi - calculates distance when angle is on an axis
 */
int special_dhi(GameMap *map, GamePlayer *p, double angle, int ppcs4715)
{
	int Px, Py, i, j, dist;

	Py = p->py;
	Px = p->px;
	dist = -999999;

	switch ((int) angle)
	{
	case 0:
		i = Px;
		j = 64 - 1;
		dist = (map->rows * 64 - Py - 1);
		break;
	case 90:
		i = (map->cols - 1) * 64;
		j = Py;
		dist = (map->cols * 64 - Px - 1);
		break;
	case 180:
		i = Px;
		j = (map->rows - 1) * 64;
		dist = (Py - map->rows * 64);
		break;
	case 270:
		i = 64 - 1;
		j = Py;
		dist = (Px - map->cols * 64);
		break;
	}

	if (DEBUG == 2)
	{
		printf("----------11-1-SPECIAL--------\n");
		printf("(i, j): (%d, %d)\t\t", i, j);
		printf("(i/64, j/64): (%d, %d)\n", i/64, j/64);
		printf("player_pos: (%d, %d)\t\t", Px, Py);
		printf("ap: %f\n", angle);
		printf("\t\tppcs4715: %d\n", ppcs4715);
		rcprint_map(map, p, j/64, i/64);
	}

	return (dist);
}
