CC=g++
CFLAGS=-g -Wall
OBJS=main.o visual.o linuxfunc.o
TARGET=a.out

$(TARGET): $(OBJS)
    $(CC) -o $@ $(OBJS)

main.o: visual.h main.cpp
visual.o: linuxfunc.h visual.h visual.cpp
linuxfunc.o: linuxfunc.h linuxfunc.cpp

clean:
    rm -f *.o
    rm -f $(TARGET)

$(TARGET): $(OBJS)
$(CC) -o $@ $(OBJS)
