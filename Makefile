CC=g++
CFLAGS=-g -Wall
OBJS=main.o A_Star.o visual.o linuxfunc.o
TARGET=a.out

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)

main.o: A_Star.h main.cpp
A_Star.o: visual.h A_Star.h A_Star.cpp
visual.o: linuxfunc.h visual.h visual.cpp
linuxfunc.o: linuxfunc.h linuxfunc.cpp

clean:
	rm -f *.o
	rm -f $(TARGET)

#$(TARGET): $(OBJS)
#$(CC) -o $@ $(OBJS)

