CFLAGS = -O2 -Wall -Wextra -ansi -pedantic

default:
	g++ $(CFLAGS) -c *.cpp
	g++ -o main *.o
	rm -f *.o

