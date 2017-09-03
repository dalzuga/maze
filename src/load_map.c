#include "../headers/demo.h"

/* assumes file ends with a new line */
int load_map(MazeStruct *maze, GameMap *map)
{
	ssize_t n;
	size_t linelen;
	char *line;
	FILE *f;

	linelen = 0;
	n = 0;
	line = NULL;
	f = fopen("maps/map_2A_12x12.map", "r");

	while(1)
	{
		n = getline(&line, &linelen, f);

		printf("line: %s\n", line);

		if (n == -1)
		{
			break;
		}
	}

	free(line);

	return (0);

	if (0)
	{
		printf("%p\n", (void *) map);
		printf("%p\n", (void *) &linelen);
		printf("%p\n", (void *) &maze);
	}
}

void default_map(GameMap *map)
{
	map->array[2][3] = 1;
	map->array[2][4] = 1;
	map->array[2][5] = 1;
	map->array[2][6] = 1;

	map->array[8][14] = 1;
	map->array[8][15] = 1;
	map->array[8][16] = 1;

	map->array[3][9] = 1;
	map->array[4][9] = 1;
	map->array[5][9] = 1;

	map->array[6][3] = 1;
	map->array[6][4] = 1;
	map->array[6][5] = 1;
}
