all: prog

prog: main.o function.o formuls.o
	g++ -o min_dist main.o function.o formuls.o

main.o: main.c
	g++ -c main.c

function.o: function.c 
	g++ -c function.c 

formuls.o: formuls.c
	g++ -c formuls.c  
