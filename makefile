FLAG = -g -Wall 

all: main.o functions.o stringProg


main.o: main.c 
	gcc $(FLAG) -c main.c

functions.o: functions.c 
	gcc $(FLAG) -c functions.c 

stringProg: main.o functions.o
	gcc $(FLAG) -o stringProg main.o functions.o

.PHONY: clean all
	
clean:
	rm -f *.o stringProg main