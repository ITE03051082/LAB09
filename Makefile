all:	ser cli

ser:	ser.o doprocessing.o
	gcc -o ser ser.o doprocessing.o
cli:	cli.o
	gcc -o cli cli.o
clean:
	rm *.o
