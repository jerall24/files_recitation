all: main

main:
	clang main.c -o main

clean:
	rm -rf *.o

clobber: clean
	rm -rf main
