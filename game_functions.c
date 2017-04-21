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

	start_position(&map, p);
	_print_map(map, 4, 4);

	/*
	 * TODO - need to code free_map() to free the map here
	 */

	free(p);
}

/**
 * start_position - allocates a map and player. Both must be freed by the user
 * of this function.
 *
 * @map - map
 * @p - player
 *
 * Return: Nothing.
 */
void start_position(int ***map, GamePlayer *p)
{
	*map = make_map(4, 4);
	(*map)[1][1] = 1;
	(*map)[1][2] = 1;
	(*map)[2][2] = 1;

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
