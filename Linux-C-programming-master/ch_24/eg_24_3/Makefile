CC = gcc
CFLAGS = -Wall
LDFLAGS = 
OBJFILES = stack.o main.o
TARGET = stacktest


all: main

main: main.o para_allocator.o
	gcc $^ -o $@ 

# main.o: main.h stack.h maze.h
# stack.o: main.h stack.h
# maze.o: maze.h main.h

clean:
	@echo "cleanning project"
	-rm main *.o
	@echo "clean completed"

.PHONY: clean

sources = main.c para_allocator.c

include $(sources:.c=.d)

%.d: %.c
	set -e; rm -f $@; \
	$(CC) -MM $(CPPFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$
