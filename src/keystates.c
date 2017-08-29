#include "../headers/demo.h"

void keystates()
{
	const Uint8* currkc = SDL_GetKeyboardState( NULL );

	printf("---keystates---\n\t\t\taddress: %p\n", (void *) currkc);
}
