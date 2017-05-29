all: src/*.c
	gcc -g -Wall -Werror -Wextra -pedantic src/*.c -lm -I/usr/include/SDL2 -D_REENTRANT -L/usr/lib/x86_64-linux-gnu -lSDL2 -lSDL2_ttf

clean:
	rm a.out
