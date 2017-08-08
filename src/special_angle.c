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
