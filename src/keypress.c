#include "../headers/demo.h"

int keypress(MazeStruct *maze, SDL_KeyboardEvent key)
{
	/* declarations + inits */
	int i, r;
	fnScanCode array[] =
	{
	  {0x29, fn_29},
	  {0x51, fn_51},
	  {0x52, fn_52},
	  {0x4f, fn_4f},
	  {0x50, fn_50},
	  {0, 0}
	};

	/* inits */
	i = 0;
	r = 0;

	while (array[i].code)
	{
		if (DEBUG >= 1)
		{
			printf("array[i].code: 0x%x\n", array[i].code);
		}

		if (key.keysym.scancode == array[i].code)
		{
			r = array[i].fp(maze);
			break;
		}

		i++;
	}

	return (r);
}

int fn_29(MazeStruct *maze __attribute__ ((unused)))
{
	printf("exit\n");
	return (1);
}

int fn_51(MazeStruct *maze __attribute__ ((unused)))
{
	printf("down arrow key\n");
	return (0);
}

int fn_52(MazeStruct *maze __attribute__ ((unused)))
{
	printf("up arrow key\n");
	return (0);
}

int fn_4f(MazeStruct *maze __attribute__ ((unused)))
{
	printf("right arrow key\n");
	return (0);
}

int fn_50(MazeStruct *maze __attribute__ ((unused)))
{
	printf("left arrow key\n");
	return (0);
}
