all: main

main: main.o my_sort.o
	gcc $^ -o $@ 

# main.o: main.h stack.h maze.h
# stack.o: main.h stack.h
# maze.o: maze.h main.h

clean:
	@echo "cleanning project"
	-rm main *.o *.d
	@echo "clean completed"

.PHONY: clean

sources = main.c my_sort.c

include $(sources:.c=.d)

%.d: %.c
	set -e; rm -f $@; \
	$(CC) -MM $(CPPFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$
