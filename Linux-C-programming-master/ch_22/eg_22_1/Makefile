all: main

main: main.o stack.o maze.o
	gcc $^ -o $@ 

# main.o: main.h stack.h maze.h
# stack.o: main.h stack.h
# maze.o: maze.h main.h

clean:
	@echo "cleanning project"
	-rm main *.o
	@echo "clean completed"

.PHONY: clean

sources = main.c stack.c maze.c

include $(sources:.c=.d)

%.d: %.c
	set -e; rm -f $@; \
	$(CC) -MM $(CPPFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$
