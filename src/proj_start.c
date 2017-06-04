#include "../headers/demo.h"

/**
 * proj_start - paints the environment from the player's POV
 *
 * @instance: SDL window and renderer instance
 * @map: address of map
 * @p: address of player
 *
 */
void proj_start(SDL_Instance instance, int **map, GamePlayer *p)
{
	int i, Px, Py, dhi;
	double ap; /* alpha prime */

	Px = p->x;
	Py = p->y;
	ap = (double) p->theta;

	for (i = 0; i < X_RES; i++)
	{
		ap += i / FOV_ANGLE;
		if (map[Px / 64][Py / 64] != 1)
		{
			proj_d(instance, i, Y_RES);
		}
		else
		{
			if (special_case() == 0)
			{
				dhi = get_dhi(instance, p, map, ap);
				proj_i(instance, i, dhi);
			}
		}

		printf("dhi: %d\n", dhi);
	}

}
