#main:a.o b.o
	#gcc a.o b.o -o main
#a.o:a.s
#	gcc -c a.s -o a.o
#a.s:a.i
#	gcc -S a.i -o a.s
#a.i:a.c
#	gcc -E a.c -o a.i
#b.o:b.s
#	gcc -c b.s -o b.o
#b.s:b.i
#	gcc -S b.i -o b.s
#b.i:b.c
#	gcc -E b.c -o b.i
#.PHONY:clean
#clean:
#	rm -f a.o b.o a.s b.s a.i b.i main

#main:a.o b.o
#	gcc $^ -o $@
#%.o:%.c
#	gcc -c $< -o $@
#.PHONY:clean
#clean:
#	rm -f a.o b.o main

src=$(wildcard ./*.c)
obj=$(patsubst %.c, %.o, $(src))
main:$(obj)
	gcc $^ -o $@
%.o:%.c
	gcc -c $< -o $@
.PHONY:clean
clean:
	rm -rf main $(obj)
