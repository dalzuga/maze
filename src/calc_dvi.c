#include "../headers/demo.h"

/**
 * calc_dvi - finds the closest vertical wall (y == C) hit by the ray
 *
 */
double calc_dvi(GameMap *map, GamePlayer *p, double alpha, double tplusb)
{
	/* declarations */
	double dist;

	dist = calc_vblock(map, p, alpha, tplusb);

	return fabs(dist);
}

/**
 * calc_vblock - finds the closest vertical wall (y == C) hit by the ray
 *
 */
double calc_vblock(GameMap *map, GamePlayer *p, double alpha, double tplusb)
{
	/* declarations */
	double dist;
	int pix, Ax, piy, Ay, coeff;

	/* inits */
	dist = 0;
	pix = Ax = piy = Ay = 0;

	pix = get_pix(map, p, alpha);
	Ax = BLOCK_UNITS;

	/* calculate piy and Ay */
	piy = pix * tan(alpha * M_PI / 180);
	Ay = Ax * tan(alpha * M_PI / 180);

	coeff = calc_coeffAx(map, p, alpha, tplusb);

	 if (tplusb >= 0)
	 {
		 dist = (pix + (coeff) * Ax) / cos(alpha * M_PI / 180);
	}

	dist = (pix + coeff * Ax) / cos(alpha * M_PI / 180);

	return (fabs(dist));
}

/**
 * calc_coeffAx - calculate coefficient of Ax, which tells us how many blocks we
 * are away from the wall.
 */
int calc_coeffAx(GameMap *map, GamePlayer *p, double alpha, double tplusb)
{
	int c;

	if (tplusb >= 0)
	{
		c = map->cols - 2 - p->x;
		printf("-----------------------------------------\n");
		printf("c: %d, alpha: %f\n", c, alpha);
		printf("------------------------------------------\n");
		return (c);
	}

	c = (p->x - 1);
	printf("-----------------------------------------\n");
	printf("c: %d, alpha: %f\n", c, alpha);
	printf("------------------------------------------\n");
	return (c);
}

/**
 *
 *
 */
int get_pix(GameMap *map __attribute__((unused)), GamePlayer *p, double alpha)
{
	int pix;

	pix = calc_pix(map, p, alpha);
	return (pix);
}

/**
 * calc_pix - calculates pix
 *
 */
int calc_pix(GameMap *map __attribute__((unused)), GamePlayer *p, double alpha)
{
	int edge_x, pix;

	alpha = calc_quad01(alpha);

	if (alpha >= 0 && alpha <= 180) /* quadrants I, II */
	{
		/* get x-coordinate of right edge of block */
		edge_x = (p->y + 1) * BLOCK_UNITS;
		/* get the distance from player to right edge of block */
		pix = p->px - edge_x;
	}
	else
	{
		/* get x-coordinate of left edge of block */
		edge_x = (p->y) * BLOCK_UNITS; /* quadrants III, IV */
		/* get the distance from player to right edge of block */
		pix = p->px - edge_x;
	}

	if (DEBUG == 1)
	{
		printf("---------------6--------------\n");
		printf("edge_x: %d, alpha: %f\n", edge_x, alpha);
		printf("pix: %d\n", pix);
	}

	return (pix);
}
