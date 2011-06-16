all: main

clear:
	rm *.o
	rm *.elf
	rm bitcell 

#bitcell

main: main.o
	gcc main.o -o "bitcell" -g


spe.elf:  spe.c
	spu-gcc spe.c -o spe.elf

main.o: main.c
	gcc -lspe2 main.c -o main.elf
