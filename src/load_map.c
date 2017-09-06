#include "../headers/demo.h"

/* assumes file ends with a new line */
int load_map(MazeStruct *maze, GameMap *map)
{
	ssize_t r;
	size_t buflen;
	char *line;
	FILE *f;
	int i, cols, j;
	char *file1 = "maps/map_2A_12x12.map";

	buflen = 0;
	r = 0;
	line = NULL;
	f = fopen(file1, "r");

	for (i = 0; ; i++)
	{
		r = getline(&line, &buflen, f);

		if (r == -1)
		{
			break;
		}

		if (i == 0)
		{
			cols = r - 1;
		}
		else
		{
			if (cols != r - 1)
			{
				perror("Bad map");
				return (1);
			}
		}

		printf("line: %s", line);
		printf("r: %ld\n", r);
		printf("strlen(line) - 1: %ld\n", strlen(line) - 1);
		printf("buflen: %ld\n", buflen);
	}

	fclose(f);
	map = make_map(i, cols);

	f = fopen(file1, "r");

	for (i = 0; ; i++)
	{
		r = getline(&line, &buflen, f);

		if (r == -1)
		{
			break;
		}

		for (j = 0; j < (r - 1) ; j++)
		{
			/* ASCII convert from char to int */
			map->array[i][j] = (int) (line[j] - 48);
		}

		printf("line: %s", line);
		printf("r: %ld\n", r);
		printf("strlen(line) - 1: %ld\n", strlen(line) - 1);
		printf("buflen: %ld\n", buflen);
	}

	free(line);

	printf("---1---\n");
	print_map(map);
	printf("---1---\n");

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
