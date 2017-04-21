all: main.c init_instance.c draw_functions.c map_functions.c game_functions.c
	gcc -Wall -Werror -Wextra -pedantic main.c init_instance.c draw_functions.c map_functions.c game_functions.c -g -I/usr/include/SDL2 -D_REENTRANT -L/usr/lib/x86_64-linux-gnu -lSDL2
