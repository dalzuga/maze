/**
 * draw_line - draws a line on SDL window.
 *
 */
int draw_line(SDL_Instance instance, int col, int height)
{
	int top = Y_RES / 2 + height / 2;
	int bottom = Y_RES / 2 - height / 2;

	SDL_RenderDrawLine(instance.renderer, i, top, i, bottom);

	return (0);
}
