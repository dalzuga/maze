all: src/main.c src/init_instance.c src/draw_functions.c src/map_functions.c src/game_functions.c src/paint_functions.c src/calculation_functions.c src/intersect_functions.c
	gcc -Wall -Werror -Wextra -pedantic -g src/main.c src/init_instance.c src/draw_functions.c src/map_functions.c src/game_functions.c src/paint_functions.c src/calculation_functions.c src/intersect_functions.c -lm -I/usr/include/SDL2 -D_REENTRANT -L/usr/lib/x86_64-linux-gnu -lSDL2 -lSDL2_ttf

clean:
	rm a.out
