#include "../headers/demo.h"

/**
 * proj_start - paints the environment from the player's POV
 *
 * @instance: SDL window and renderer instance
 * @map: address of map
 * @p: address of player
 *
 */
int proj_start(SDL_Instance instance, int **map, GamePlayer *p)
{
	int i, Px, Py, dhi;
	double ap; /* alpha prime */

	Px = p->x;
	Py = p->y;
	ap = (double) p->theta;

	if (special_case(instance, ap) == 1)
	{
		return (0);
	}

	for (i = 0; i < X_RES; i++)
	{
		ap += (double) i / (double) FOV_ANGLE;
		if (map[Px / 64][Py / 64] != 0)
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

int special_case(SDL_Instance instance, GameMap *map, GamePlayer *p, double *ap)
{
	int i;

	if (!(ap == 0 || ap == 90 || ap == 180 || ap == 270))
	{
		/* if not special case */
		return (0);
	}

	for (i = 0

	return (1);
}
