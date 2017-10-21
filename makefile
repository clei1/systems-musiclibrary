all: songs.c songs.h
	gcc -o songs.o songs.c

run: all
	./songs.o

clean:
	rm *.o*
	rm *~
