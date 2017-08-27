#include "../headers/demo.h"

int keypress(SDL_KeyboardEvent key)
{
	/* declarations + inits */
	int i, r;
	fnScanCode array[] =
	{
	  {0x29, fn_29},
	  {0x51, fn_51},
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
			r = array[i].fp();
			break;
		}

		i++;
	}

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

int fn_51()
{
	printf("down arrow key\n");
	return (0);
}
