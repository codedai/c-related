target = app

src2 = $(wildcard ./*.c)
obj2 = $(patsubst %.c,%.o,$(src2))

$(target):$(obj1) $(obj2)
	gcc $^ -o $@

%.o:%c
	gcc -c%< -o $@

.PHONY:clean

clean:
	-rm $(target) $(obj2) -f

hello:
	echo "hello world"
