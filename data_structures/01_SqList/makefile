target = app

src1 = $(wildcard ../Status/*.c)
src2 = $(wildcard ./*.c)
obj1 = $(patsubst %.c,%.o,$(src1))
obj2 = $(patsubst %.c,%.o,$(src2))
src = ../Status/

$(target):$(obj1) $(obj2)
	gcc $^ -o $@

%.o:$(src)%.c
	gcc -c $< -o $@

%.o:%c
	gcc -c%< -o $@

.PHONY:clean

clean:
	-rm $(target) $(obj1) $(obj2) -f

hello:
	echo "hello world"
