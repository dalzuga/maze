#include "../headers/demo.h"

void keystates(MazeStruct *maze)
{
	/* from [[http://lazyfoo.net/tutorials/SDL/18_key_states/index.php]] */
	const Uint8* state = SDL_GetKeyboardState( NULL );
	int i;
	fnScanCode st_arr[] = 	/* key state array */
	{
		/* 
                 * {0x04, fn_04},	/\* 'a' key *\/
		 * {0x07, fn_07},	/\* 'd' key *\/
		 * {0x16, fn_16},	/\* 's' key *\/
		 * {0x1a, fn_1a},	/\* 'w' key *\/
		 * {0x51, fn_51},	/\* key down *\/
		 * {0x52, fn_52},	/\* key up *\/
		 * {0x4f, fn_4f},	/\* key right *\/
		 * {0x50, fn_50},	/\* key left *\/
                 */
		{0, 0}
	};

	i = 0;
	while (st_arr[i].code)
	{
		if (state[st_arr[i].code])
		{
			st_arr[i].fp(maze);
		}

		i++;
	}

}
