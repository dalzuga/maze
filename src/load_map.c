#include "../headers/demo.h"

/* assumes file ends with a new line */
int load_map(MazeStruct *maze, GameMap *map)
{
	ssize_t r;
	size_t buflen;
	char *line;
	FILE *f;
	int i;

	buflen = 0;
	r = 0;
	line = NULL;
	f = fopen("maps/map_2A_12x12.map", "r");

	for (i = 0; ; i++)
	{
		r = getline(&line, &buflen, f);

		if (r == -1)
		{
			break;
		}

		printf("line: %s", line);
		printf("r: %ld\n", r);
		printf("strlen(line) - 1: %ld\n", strlen(line) - 1);
		printf("buflen: %ld\n", buflen);
	}

	free(line);

	return (0);

	if (0)
	{
		printf("%p\n", (void *) map);
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
