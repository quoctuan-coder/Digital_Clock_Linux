all:
	gcc -c Digital_Clock.c
	gcc -c main.c
	gcc main.o Digital_Clock.o -o main

.PHONY: clean
clean:
	rm -f *.o