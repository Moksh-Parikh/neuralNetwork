CC = gcc
CFLAGS = -g
TARGET = main
SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)

all: $(TARGET).exe

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<;

%.exe: $(OBJECTS)
	$(CC) $^ -o $@;
