#include "demo.h"

/**
 *
 *
 */
void draw_game()
{
	/* declarations */
	int **map;
	GamePlayer *p;
	/* end declarations */

	/* inits */
	map = NULL;
	p = NULL;
	/* end inits */

	start_position(map, p);

	free(map);
	free(p);
}

/**
 * start_position - allocates a map and player, both must be freed.
 * @map - map
 * @p - player
 *
 * Return: Nothing.
 */
void start_position(int **map, GamePlayer *p)
{
	map = make_map(4, 4);
	map[1][1] = 1;
	map[1][2] = 1;
	map[2][2] = 1;
	_print_map(map, 4, 4);

	p = malloc(sizeof(GamePlayer));
	if (p == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	p->x = 1;
	p->y = 1;
	p->theta = 45;
}
