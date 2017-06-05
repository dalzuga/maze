#include "../headers/demo.h"

/**
 * proj_start - paints the environment from the player's POV
 *
 * @instance: SDL window and renderer instance
 * @map: address of map
 * @p: address of player
 *
 * Return: 0 on success, 1 otherwise;
 */
int proj_start()
{
	int i, Px, Py, dhi;
	double ap; /* alpha prime */

	/* inits */
	Px = p->x;
	Py = p->y;
	ap = (double) p->theta - FOV_ANGLE / 2;

	for (i = 0; i < X_RES; i++)
	{
		dhi = get_dhi(map, p, ap);
		printf("i: %d\tdhi: %d\n", i, dhi);
		ap += (double) i / (double) FOV_ANGLE;
	}

}
