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
	ap = (double) 0;

	for (i = 0; i < X_RES; i++)
	{
		dhi = get_dhi(Px, Py, dy, Ya, ap);
		printf("i: %d\tdhi: %d\n", i, dhi);
		ap += (double) i / (double) FOV_ANGLE;
	}

}
