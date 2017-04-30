#include "../headers/demo.h"

int main(void)
{
	SDL_Instance instance;

	if (init_instance(&instance) != 0)
		return (1);

	if (check_edge_cases() != 0)
	{
		return (2);
	}

	game_start(instance);

	SDL_DestroyRenderer(instance.renderer);
	SDL_DestroyWindow(instance.window);
	SDL_Quit();

	return (0);
}

int check_edge_cases(void)
{
	if (X_RES <= 0 || Y_RES <= 0)
	{
		printf("Wrong resolution.\n");
		return (1);
	}

	if (FOV_ANGLE <= 0 || SQRT_BLOCK_UNITS <= 0 || WALL_HEIGHT <= 0)
	{
		printf("Wrong game parameters.\n");
		return (1);
	}

	return (0);
}
