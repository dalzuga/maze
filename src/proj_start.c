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
int proj_start(SDL_Instance instance, int **map, GamePlayer *p)
{
	int i, Px, Py, dhi;
	double ap; /* alpha prime */

	/* inits */
	Px = p->x;
	Py = p->y;
	ap = (double) p->theta;

	if (special_where(instance, map, p) == 1)
	{
		return (1);
	}

	for (i = 0; i < X_RES; i++)
	{
		ap += (double) i / (double) FOV_ANGLE;
		if (special_case() == 0)
		{
			dhi = get_dhi(instance, p, map, ap);
			proj_i(instance, i, dhi);
		}

		printf("dhi: %d\n", dhi);
	}

}
