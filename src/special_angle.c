#include "../headers/demo.h"

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
		for (c = 0; ; c++)
		{
			j = Py - 64 * c;

			/* border safety */
			if (j/64 != 0 && j/64 != map->rows)
			{
				break;
			}

			/* hit wall */
			if (map->array[j / 64][Px / 64] == 1)
			{
				break;
			}
		}

		dy = calc_dy(p, angle);

		dist = Py - (j + dy + 64);
	}
	else if (angle == 90)
	{
		for (c = 0; ; c++)
		{
			i = Px + 64 * c;

			/* border safety */
			if (i/64 == 0 || i/64 == map->cols)
			{
				break;
			}

			/* hit wall */
			if (map->array[Py / 64][i / 64] == 1)
			{
				break;
			}
		}

		Dx = calc_dx(p, angle);

		dist = (i + Dx - 64) - Px;
	}
	else if (angle == 180)
	{
		for (c = 0; ; c++)
		{
			j = Py + 64 * c;

			/* border safety */
			if (j/64 == 0 || j/64 == map->rows)
			{
				break;
			}

			/* hit wall */
			if (map->array[j / 64][Px / 64] == 1)
			{
				break;
			}
		}

		dy = calc_dy(p, angle);

		dist = (j + dy - 64) - Py;

	}
	else /* (angle == 270) */
	{
		for (c = 0; i/64 != 0 && i/64 != map->cols; c++)
		{
			i = Px - 64 * c;

			/* border safety */
			if (i/64 != 0 && i/64 != map->cols)
			{
				break;
			}

			/* hit wall */
			if (map->array[Py / 64][i / 64] == 1)
			{
				break;
			}
		}

		Dx = calc_dx(p, angle);

		dist = Px - (i + Dx + 64);
	}

	if (DEBUG >= 2)
	{
		printf("----------11-1-SPECIAL--------\n");
		printf("map size: [%d, %d]\t\t", map->cols, map->rows);
		printf("(%d, %d)\n", map->cols * BLOCK_UNITS, map->rows * 64);
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
		rcprint_map(map, p, j/64, i/64);
	}

	return (dist);
}
