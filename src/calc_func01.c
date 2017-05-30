#include "../headers/demo.h"

/**
 * calc_func01 - calculate how far the ray cast travels until it meets a wall.
 *
 * @map: address of map
 * @p: address of player
 * @i: specific ray within projection plane
 *
 * Return: length of the ray-line.
 */
double calc_func01(int **map __attribute__ ((unused)), GamePlayer *p, int i)
{
	/* declarations + inits */
	double rclen = -1, dvi = -1, dhi = -1;
	int px = -1, py = -1;
	double beta = (double) FOV_ANGLE * i / (double) X_RES;
	double theta = p->theta - FOV_ANGLE / 2;

	/* inits */
	calc_pxpy(p, &px, &py);

	dvi = calc_dvi(map, p, beta, &px, &py);
	dhi = calc_dhi(map, p, beta, &px, &py);

	if (DEBUG == 1)
	{
		printf("---------------3--------------\n");
		printf("player position on map: (%d, %d), absolute: (%d, %d), \
p->theta: %d\n", p->x, p->y, px, py, p->theta);
		printf("cos((theta + beta) * M_PI / 180): %f\n",
		       cos((theta + beta) * M_PI / 180));
		printf("theta + beta: %f, cos(theta + beta): %f, rclen: %f\n",
		       theta + beta, cos((theta + beta) * M_PI / 180), rclen);
		printf("beta - FOV_ANGLE / 2: %f\n", beta - FOV_ANGLE / 2);
	}

	return (fmin(dvi, dhi));
}
