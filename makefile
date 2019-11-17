all: directory.o
	gcc -o program directory.o

directory.o: directory.c
	gcc -c directory.c

run:
	./program

clean:
	rm *.o
	rm *~
