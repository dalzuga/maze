#include "../headers/demo.h"

/**
 * game_main - entry point for the game engine
 *
 * @maze: pointer to the maze struct
 *
 * Return: Nothing.
 */
void game_main(MazeStruct *maze)
{
	game_engine(maze);

	/*
	 * TODO - need to code free_map() to free the map here
	 */

	free(maze->p);		/* frees the player */
}
