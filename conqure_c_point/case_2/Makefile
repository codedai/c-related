all: main

main: main.o add_word.o dump_word.o finalize.o initialize.o get_word.o 
	gcc $^ -o $@ 

# main.o: main.h stack.h maze.h
# stack.o: main.h stack.h
# maze.o: maze.h main.h

clean:
	@echo "cleanning project"
	-rm main *.o *.d
	@echo "clean completed"

.PHONY: clean

sources = main.c add_word.c dump_word.c finalize.c initialize.c get_word.c

include $(sources:.c=.d)

%.d: %.c
	set -e; rm -f $@; \
	gcc -MM $(CPPFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$
