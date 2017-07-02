#include "../headers/demo.h"

/**
 * init function - allocates and initializes all the members of the maze struct
 * @maze - pointer to the maze struct
 */
void init_function(MazeStruct *maze)
{
	if (init_instance(&(maze->instance)) != 0)
		exit(1);

	if (check_edge_cases() != 0)
		exit(1);
}
