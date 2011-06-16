all: main

clear:
	rm *.o
	rm bitcell 

#bitcell

main: main.o
	gcc main.o -o "bitcell" -g

main.o: main.c
	gcc -c main.c -g
