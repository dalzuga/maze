#include "../headers/demo.h"

/**
 * calc_dhi - finds the closest horizontal wall (y == C) hit by the ray
 *
 */
double calc_dhi(GameMap *map __attribute__ ((unused)), GamePlayer *p, int ppcs4715)
{
	/* declarations */
	double ap;
	int dy;
	int Px, Py, c, i, j;
	int Ya;
	int flag;

	/* inits */
	ap = p->theta + (double) ppcs4715 / X_RES * FOV_ANGLE;
	ap = calc_mod360(ap);
	Py = p->py;
	Px = p->px;
	flag = 0;
	/* end inits */

	if (axis_angle(ap))	/* special cases: 0, 90, 180, 270 */
	{
		return (special_dhi(map, p, ap, ppcs4715));
	}

	dy = calc_dy(p, ap);
	Ya = calc_Ya(ap);

	printf("##########################\n");
	printf("dy: %d\n", dy);
	printf("##########################\n");

	j = Py + dy;
	i = Px + dy * tan(ap * M_PI / 180);

	for (c = 1; ; c++)
	{
		if (i <= 0 || i >= map->cols * 64)
		{
			flag = 2;
			break;
		}

		if (j == 0)
		{
			flag = 1;
			break;
		}

		j = Py + dy + c * Ya;
		i = Px + (Py - j) * tan(ap * M_PI / 180);

		/* 
                 * /\* going up *\/
		 * if (map->array[(j - 1) / 64][i/64] == 1)
		 * {
		 * 	flag = 3;
		 * 	break;
		 * }
                 */
	}

	if (DEBUG >= 2)
	{
		printf("-----------11-1--dhi----------\n");
		printf("map size: [%d, %d]\t\t", map->cols, map->rows);
		printf("(%d, %d)\n", map->cols * BLOCK_UNITS, map->rows * 64);
		printf("player_pos:\t(%d, %d)\t", Px, Py);
		printf("player_pos: [%d, %d]\n", Px/64, Py/64);
		printf("(i, j):\t(%d, %d)\t", i, j);
		printf("(i/64, j/64): [%d, %d]\t", i/64, j/64);
		printf("ap: %f\n", ap);
		printf("c: %d\t\t", c);
		printf("ppcs4715: %d\n", ppcs4715);
		rcprint_map(map, p, j/64, i/64);

		switch (flag)
		{
		case 0:
		  break;
		case 1:
		  printf("j == 0\n");
		  break;
		case 2:
		  printf("i <= 0 || i >= map->cols * 64\n");
		  break;
		case 3:
		  printf("upper hit\n");
		  break;
		case 4:
		  printf("lower hit\n");
		  break;
		}
		flag = 0;
	}

	return (dy);
}

int calc_dy(GamePlayer *p, double ap)
{
	int dy;
	int Py;

	Py = p->py;

	if (ap < 90 || ap > 270) /* up */
	{
		dy = (Py/64 * 64) - Py;
	}
	else 			/* down */
	{
		dy = (Py/64 + 1) * 64 - Py;
	}

	return (dy);
}

int calc_Ya(double ap)
{
	if (ap < 90 || ap > 270) /* up */
	{
		return (-64);
	}

	/* down */
	return (64);
}
