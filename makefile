ifdef CLA

endif

all: directory.o
	gcc -o program directory.o

directory.o: directory.c
	gcc -c directory.c

run:
	./program $(CLA)

clean:
	rm *.o
	rm *~
