CFLAGS = -O2 -Wall -Wextra -ansi -pedantic

default:
	g++ $(CFLAGS) -c *.cpp
	rm -f *.o

