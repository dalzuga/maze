#include "../headers/demo.h"

int keypress(SDL_KeyboardEvent key)
{
	/* declarations + inits */
	int i, r;
	fnScanCode array[] =
	{
	  {0x29, fn_29},
	  {0x81, fn_81},
	  {0, 0}
	};

	/* inits */
	i = 0;
	r = 0;

	while (array[i].code)
	{
		printf("2\n");
		sleep(1);
		printf("array[i].code: %d\n", array[i].code);

		if (key.keysym.scancode == array[i].code)
		{
			printf("3\n");
			r = array[i].fp();
			break;
		}

		i++;
	}

	printf("4\n");

	/* 
         * /\* If 'ESCAPE' is pressed *\/
	 * if (key.keysym.scancode == 0x29)
	 * 	return (1);
	 * 
	 * if (key.keysym.scancode == 0x81)
	 * {
	 * }
         */

	return (r);
}

int fn_29()
{
	printf("fn_29\n");
	return (1);
}

int fn_81()
{
	printf("down arrow key\n");
	return (0);
}
