#include "../headers/demo.h"

/**
 * calc_rclen - calculate how far the ray cast travels until it meets a wall.
 *
 * @map: address of map
 * @p: address of player
 *
 * Return: length of the ray-line.
 */
double calc_rclen(int **map __attribute__ ((unused)), GamePlayer *p, int i)
{
	/* declarations + inits */
	double rclen = -1;
	int px = -1, py = -1;
	double beta = (double) FOV_ANGLE * i / (double) X_RES;
	double theta = p->theta - FOV_ANGLE / 2;

	/* inits */
	calc_pxpy(p, &px, &py);

	rclen = py / cos(theta + beta);

	if (DEBUG == 1)
	{
		printf("---------------3--------------\n");
		printf("player position on map: (%d, %d), absolute: (%d, %d), \
p->theta (degrees): %f\n", p->x, p->y, px, py, p->theta * M_PI / 180);
		/* printf("cos((theta + beta) * 180 / M_PI): %f\n", */
		/*        cos((theta + beta) * 180 / M_PI)); */
		printf("theta + beta (degrees): %f, cos(theta + beta): %f, \
rclen: %f\n", (theta + beta) * 180 / M_PI, cos(theta + beta), rclen);
		printf("(beta - FOV_ANGLE) / 2 (degrees): %f\n", \
		       (beta - FOV_ANGLE / 2) * 180 / M_PI);
	}

	/* correct for spherical distortion */
	rclen = rclen * cos(beta - FOV_ANGLE / 2);

	return (rclen);
}

/**
 * calc_pxpy - calculates player position in the center of the
 * player's block. This is necessary because we are using finer resolution to
 * position player inside the block itself.
 *
 *
 */
void calc_pxpy(GamePlayer *p, int *px, int *py)
{
	*px = (p->x + 1) * BLOCK_UNITS - BLOCK_UNITS / 2;
	*py = (p->y + 1) * BLOCK_UNITS - BLOCK_UNITS / 2;

	if (DEBUG == 1)
	{
		printf("---------------2--------------\n");
		printf("p->x: %d, px: %d, ", p->x, *px);
		printf("p->y: %d, py: %d\n", p->y, *py);
	}
}
