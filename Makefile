CC = gcc
CFLAGS = -g
TARGET = main
SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)
DEPS=matrixMaths.h

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<;

%.exe: $(OBJECTS)
	$(CC) $^ -o $@;

.PHONY: all clean

all: build/$(TARGET).exe

clean:
	rm -f *.o
