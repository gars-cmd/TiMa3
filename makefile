FLAG = -g -Wall 

all: main function stringProg

main: main.c 
	gcc $(FLAG) -c main.c
	
function: functions.c 
	gcc $(FLAG) -c functions.c 

stringProg: main function
	gcc $(FLAG) -o stringProg main.o functions.o

clean:
	rm -f *.o stringProg main