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
	ap = (double) p->theta - FOV_ANGLE / 2;

	if (special_where(instance, map, p) == 1)
	{
		proj_fill(instance);
		return (1);
	}

	for (i = 0; i < X_RES; i++)
	{
		get_dhi(map, p, ap);
		ap += (double) i / (double) FOV_ANGLE;
	}

}

int proj_fill(SDL_Instance instance)
{
	int i;

	for (i = 0; i < X_RES; i++)
	{
		draw_line(instance, i, X_RES);
	}
}
