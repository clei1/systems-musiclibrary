all: music_library.c music_library.h
	gcc -o music_library.o music_library.c

run: all
	./music_library.o

clean:
	rm *.out
	rm *~
