#include "../headers/demo.h"

/**
 * special_angle - calculates distance when angle is on an axis
 */
int special_angle(GameMap *map, GamePlayer *p, double angle, int ppcs4715)
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
		for (c = 0; ; c++)
		{
			j = Py - BLOCK_UNITS * c;

			/* border safety */
			if (j/BLOCK_UNITS == 0 || j/BLOCK_UNITS == map->rows)
			{
				break;
			}

			/* hit wall */
			if (map->array[j / BLOCK_UNITS][Px / BLOCK_UNITS] == 1)
			{
				break;
			}
		}

		dy = calc_dy(p, angle);

		dist = Py - (j + dy + BLOCK_UNITS);
	}
	else if (angle == 90)
	{
		for (c = 0; ; c++)
		{
			i = Px + BLOCK_UNITS * c;

			/* border safety */
			if (i/BLOCK_UNITS == 0 || i/BLOCK_UNITS == map->cols)
			{
				break;
			}

			/* hit wall */
			if (map->array[Py / BLOCK_UNITS][i / BLOCK_UNITS] == 1)
			{
				break;
			}
		}

		Dx = calc_dx(p, angle);

		dist = (i + Dx - BLOCK_UNITS) - Px;
	}
	else if (angle == 180)
	{
		for (c = 0; ; c++)
		{
			j = Py + BLOCK_UNITS * c;

			/* border safety */
			if (j/BLOCK_UNITS == 0 || j/BLOCK_UNITS == map->rows)
			{
				break;
			}

			/* hit wall */
			if (map->array[j / BLOCK_UNITS][Px / BLOCK_UNITS] == 1)
			{
				break;
			}
		}

		dy = calc_dy(p, angle);

		dist = (j + dy - BLOCK_UNITS) - Py;

	}
	else /* (angle == 270) */
	{
		for (c = 0; i/BLOCK_UNITS != 0 && i/BLOCK_UNITS != map->cols; c++)
		{
			i = Px - BLOCK_UNITS * c;

			/* border safety */
			if (i/BLOCK_UNITS == 0 || i/BLOCK_UNITS == map->cols)
			{
				break;
			}

			/* hit wall */
			if (map->array[Py / BLOCK_UNITS][i / BLOCK_UNITS] == 1)
			{
				break;
			}
		}

		Dx = calc_dx(p, angle);

		dist = Px - (i + Dx + BLOCK_UNITS);
	}

	if (DEBUG >= 2)
	{
		printf("----------11-1-SPECIAL--------\n");
		printf("map size: [%d, %d]\t\t", map->cols, map->rows);
		printf("(%d, %d)\n",
		       map->cols * BLOCK_UNITS, map->rows * BLOCK_UNITS);
		printf("(i, j): (%d, %d)\t\t", i, j);
		printf("(i/%d, j/%d): (%d, %d)\n", BLOCK_UNITS, BLOCK_UNITS,
		       i/BLOCK_UNITS, j/BLOCK_UNITS);
		printf("player_pos: (%d, %d)\t\t", Px, Py);
		printf("player_pos: [%d, %d]\t\t",
		       Px/BLOCK_UNITS, Py/BLOCK_UNITS);
		printf("ap: %f\n", angle);
		printf("c: %d\t\t", c);
		printf("ppcs4715: %d\n", ppcs4715);
		printf("dist: %d\n", dist);
		rcprint_map(map, p, j/BLOCK_UNITS, i/BLOCK_UNITS);
	}

	return (dist);
}
