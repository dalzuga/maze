#include "../headers/demo.h"

void rspawn(MazeStruct *maze)
{
	GamePlayer *p;
	GameMap *map;
	int j, i, zeroes, r;

	p = maze->p;
	map = maze->map;

	zeroes = 0;
	for (j = 0; j < map->rows; j++)
	{
		for (i = 0; i < map->cols; i++)
		{
			if (map->array[j][i] == 0)
			{
				zeroes++;
			}
		}
	}

	srand(time(NULL));
	r = rand();
	r = (r % zeroes) + 1;

	printf("r: %d\n", r);
	printf("zeroes: %d\n", zeroes);

	zeroes = 0;
	for (j = 0; j < map->rows; j++)
	{
		for (i = 0; i < map->cols; i++)
		{
			if (map->array[j][i] == 0)
			{
				zeroes++;
			}
			if (zeroes == r)
			{
				break;
			}
		}

		if (zeroes == r)
		{
			break;
		}
	}

	p->py = BLOCK_UNITS * j + 32;
	p->px = BLOCK_UNITS * i + 32;
	p->theta = ( rand() % 8 ) * 45;

	printf("p->py: %d\n", p->py);
	printf("p->px: %d\n", p->px);
	printf("p->theta: %d\n", p->theta);
	print_map_p(maze->map, maze->p);
}
