#include "../headers/demo.h"

/**
 * calc_quadrants - calculates alpha based on quadrant
 *
 */
double calc_quadrants(double beta, double theta)
{
	/* declaration */
	double tplusb = calc_quad01(beta + theta);

	if (tplusb > 0 && tplusb < 90) /* quadrant I */
	{
		return (90 - tplusb);
	}
	else if (tplusb > 90 && tplusb < 180) /* quadrant II */
	{
		return (tplusb - 90);
	}
	else if (tplusb < -90) /* quadrant III */
	{
		return ((-1) * (tplusb + 90));
	}
	else if (tplusb < 0 && tplusb > -90) /* quadrant IV */
	{
		return (tplusb + 90);
	}

	return (0); 		/* alpha is 0 if we're on an axis */
}

/**
 * calc_quad01 - special modding function, guarantees range (-180, 180]
 *
 */
double calc_quad01(double tplusb)
{
	while (tplusb <= -180)
	{
		tplusb += 360;
	}

	while (tplusb >= 180)
	{
		tplusb -= 360;
	}

	return (tplusb);
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
		return (pix);
	}

	/* get x-coordinate of left edge of block */
	edge_x = (p->y) * BLOCK_UNITS; /* quadrants III, IV */
	/* get the distance from player to right edge of block */
	pix = p->px - edge_x;

	if (DEBUG == 1)
	{
		printf("---------------6--------------\n");
		printf("edge_x: %d, alpha: %f\n", edge_x, alpha);
		printf("pix: %d\n", pix);
	}

	return (pix);
}
