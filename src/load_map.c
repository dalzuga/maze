#include "../headers/demo.h"

void load_map(GameMap *map)
{
	#define LINE_BUFFER 128
	int linelen;
	char **line;
	FILE *f = fopen("../maps/map_2A_12x12.map", "r");

	while(1)
	{
		linelen = getline(line, LINE_BUFFER, f);
	}

	if (0)
		printf("%p\n", (void *) map);
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
