#include "../headers/demo.h"

int keypress(MazeStruct *maze, SDL_KeyboardEvent key)
{
	/* declarations + inits */
	int i, r;
	fnScanCode array[] =
	{
		{0x29, fn_29},	/* 'esc' key */
		/*
                 * {0x51, fn_51},	/\* key down *\/
		 * {0x52, fn_52},	/\* key up *\/
		 * {0x4f, fn_4f},	/\* key right *\/
		 * {0x50, fn_50},	/\* key left *\/
		 * {0x04, fn_04},	/\* 'a' key *\/
		 * {0x07, fn_07},	/\* 'd' key *\/
		 * {0x16, fn_16},	/\* 's' key *\/
		 * {0x1a, fn_1a},	/\* 'w' key *\/
                 */
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
	step_rwd(maze);

	if (DEBUG == 5)
	{
		printf("down arrow key\n");
	}
	return (0);
}

int fn_52(MazeStruct *maze __attribute__ ((unused)))
{
	step_fwd(maze);

	if (DEBUG == 5)
	{
		printf("up arrow key\n");
	}
	return (0);
}

int fn_4f(MazeStruct *maze __attribute__ ((unused)))
{
	maze->p->theta = (maze->p->theta + 1 * ANGLE_FACTOR) % 360;

	if (DEBUG == 5)
	{
		printf("right arrow key\n");
	}
	return (0);
}

int fn_50(MazeStruct *maze __attribute__ ((unused)))
{
	maze->p->theta = (maze->p->theta - 1 * ANGLE_FACTOR) % 360;

	if (DEBUG == 5)
	{
		printf("left arrow key\n");
	}
	return (0);
}

int fn_04(MazeStruct *maze)
{
	step_left(maze);

	printf("'a' key\n");
	return (0);
}

int fn_07(MazeStruct *maze)
{
	step_right(maze);

	printf("'d' key\n");
	return (0);
}

int fn_16(MazeStruct *maze)
{
	step_down(maze);

	printf("'s' key\n");
	return (0);
}

int fn_1a(MazeStruct *maze)
{
	step_up(maze);

	printf("'w' key\n");
	return (0);
}
