OBJS = 
CC = g++
CFLAGS = -Wall -c 
LFLAGS = -Wall
SOURCES = main.cpp shapes.cpp drawing.cpp
HEADERS = shapes.h drawing.h

all: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o glutExample

main.o : 
	$(CC) $(CFLAGS) 

drawing.o :
	$(CC) $(CFLAGS)

shapes.o :
	$(CC) $(CFLAGS)

clean: 
	\rm

tar:
	tar cfv lab2.tar makefile