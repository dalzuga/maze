#include "../headers/demo.h"

/**
 * calc_func02 - calculate how far the ray cast travels until it meets a wall.
 *
 * @map: address of map
 * @p: address of player
 * @i: specific ray within projection plane
 *
 * Return: length of the ray-line.
 */
double calc_func02(int **map __attribute__ ((unused)), GamePlayer *p, int i)
{
	/* declarations + inits */
	double rclen = -1;
	double beta = (double) FOV_ANGLE * i / (double) X_RES;
	double theta = p->theta - FOV_ANGLE / 2;

	rclen = calc_intwrapper(map, p, i);

	if (DEBUG == 1)
	{
		printf("---------------3--------------\n");
		printf("player position on map: (%d, %d), absolute: (%d, %d), \
p->theta: %d\n", p->x, p->y, p->px, p->py, p->theta);
		printf("cos((theta + beta) * M_PI / 180): %f\n",
		       cos((theta + beta) * M_PI / 180));
		printf("theta + beta: %f, cos(theta + beta): %f, rclen: %f\n",
		       theta + beta, cos((theta + beta) * M_PI / 180), rclen);
		printf("beta - FOV_ANGLE / 2: %f\n", beta - FOV_ANGLE / 2);
	}

	return (rclen);
}
