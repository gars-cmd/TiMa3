FLAG = -Wall -g 

all: main function stringProg

main: main.c functions.h
	gcc $(FLAG) -c main.c
	
function: functions.c functions.h
	gcc $(FLAG) -c functions.c 

stringProg: main function
	gcc $(FLAG) -o stringProg main.o functions.o

clean:
	rm -f *.o stringProg