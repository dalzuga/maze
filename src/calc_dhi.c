#include "../headers/demo.h"

/**
 * calc_dhi - finds the closest horizontal wall (y == C) hit by the ray
 *
 * @map: the map
 * @p: the player
 * @ppcs4715: projector plane cross-section (the vertical column being rendered)
 *
 * Return: the distance to the closest horizontal grid wall.
 */
double calc_dhi(GameMap *map, GamePlayer *p, int ppcs4715)
{
	/* declarations */
	double ap;
	int dy;
	int Px, Py, c, i, j;
	int Ya;
	double dist;

	/* inits */
	ap = p->theta + (double) ppcs4715 / X_RES * FOV_ANGLE;
	ap = calc_mod360(ap);
	Py = p->py;
	Px = p->px;
	dist = 0;
	/* end inits */

	dy = calc_dy(p, ap);
	Ya = calc_Ya(ap);

	j = Py + dy;

	if (ap < 90)
	{
		i = Px + fabs(dy) * tan(ap * M_PI / 180);
		dist = (Py - j) / cos(ap * M_PI / 180);
	}
	else if (ap < 180)
	{
		i = Px + fabs(dy) / tan((ap - 90) * M_PI / 180);
		dist = (j - Py) / sin((ap - 90) * M_PI / 180);
	}
	else if (ap < 270)
	{
		i = Px - fabs(dy) * tan((ap - 180) * M_PI / 180);
		dist = (j - Py) / cos((ap - 180) * M_PI / 180);
	}
	else
	{
		i = Px - fabs(dy) / tan((ap - 270) * M_PI / 180);
		dist = (Py - j) / sin((ap - 270) * M_PI / 180);
	}

	for (c = 1; ; c++)
	{
		if (i <= 0 || i >= map->cols * BLOCK_UNITS)
		{
			break;
		}

		if (j == 0)
		{
			break;
		}

		if (j == map->rows * BLOCK_UNITS)
		{
			break;
		}

		if (ap < 90 || ap > 270) /* up */
		{
			/* check upper side of border */
			if (map->array[(j - 1) / BLOCK_UNITS][i/BLOCK_UNITS] == 1)
			{
				break;
			}
		}
		else		/* down */
		{
			/* check lower side of border */
			if (map->array[j/BLOCK_UNITS][i/BLOCK_UNITS] == 1)
			{
				break;
			}
		}

		j = Py + dy + c * Ya;
		if (ap < 90)
		{
			i = Px + fabs(Py - j) * tan(ap * M_PI / 180);
			dist = (Py - j) / cos(ap * M_PI / 180);
		}
		else if (ap < 180)
		{
			i = Px + fabs(Py - j) / tan((ap - 90) * M_PI / 180);
			dist = (j - Py) / sin((ap - 90) * M_PI / 180);
		}
		else if (ap < 270)
		{
			i = Px - fabs(Py - j) * tan((ap - 180) * M_PI / 180);
			dist = (j - Py) / cos((ap - 180) * M_PI / 180);
		}
		else
		{
			i = Px - fabs(j - Py) / tan((ap - 270) * M_PI / 180);
			dist = (Py - j) / sin((ap - 270) * M_PI / 180);
		}
	}

	return (dist);
}

/**
 * calc_dy - calculate the vertical player offset within the grid block
 *
 * @p: the player
 * @ap: a copy of the angle
 *
 * Return: the vertical distance.
 */
int calc_dy(GamePlayer *p, double ap)
{
	int dy;
	int Py;

	Py = p->py;

	if (ap < 90 || ap > 270) /* up */
	{
		dy = (Py/BLOCK_UNITS * BLOCK_UNITS) - Py;
	}
	else 			/* down */
	{
		dy = (Py/BLOCK_UNITS + 1) * BLOCK_UNITS - Py;
	}

	return (dy);
}

/**
 * calc_Ya - calculate vertical direction.
 *
 * @ap: a copy of the angle
 *
 * Return: the signed vertical direction.
 */
int calc_Ya(double ap)
{
	if (ap < 90 || ap > 270) /* up */
	{
		return (-BLOCK_UNITS);
	}

	/* down */
	return (BLOCK_UNITS);
}
