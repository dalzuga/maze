#include "../headers/demo.h"

/**
 * special_where - determine where we are in the world
 *
 * @instance: SDL window and renderer instance
 * @map: address of map
 * @p: address of player
 *
 * Return: 0 if our location is valid, 1 otherwise.
 */
int special_where(SDL_Instance instance, int **map, GamePlayer *p)
{
	int Px, Py;

	Px = p->x;
	Py = p->y;

	if (map[Px / 64][Py / 64] == 1)
	{
		/* we are inside a block */
		return (1);
	}

	if (((Px / 64) >= map->rows) || ((Py / 64) >= map->cols))
	{
		/* we are outside the map */
		return (1);
	}

	if (map[Px / 64][Py / 64] == 0)
	{
		/* we are at a valid location in the map */
		return (0);
	}
}
