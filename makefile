all: songs.c songs.h music_library.c main.c
	gcc main.c

run: all
	./a.out

clean:
	rm *.out
	rm *~
