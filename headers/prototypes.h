int check_edge_cases(void);
void game_start(SDL_Instance instance);
void start_position(int ***map, GamePlayer **p);
int poll_events(void);
int proj_start(SDL_Instance instance, int **map, GamePlayer *p);
int proj_fill(SDL_Instance instance);
int special_where(SDL_Instance instance, int **map, GamePlayer *p);
