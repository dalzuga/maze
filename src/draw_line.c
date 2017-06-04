/**
 * draw_line - draws a line on SDL window.
 *
 */
int draw_line(SDL_Instance instance, int col, int height)
{
	int top = 0;
	int bottom = height;

	SDL_RenderDrawLine(instance.renderer, i, top, i, bottom);

	return (0);
}
