vfork:vfork.o
	gcc $^ -o $@
vfork.o:vfork.s
	gcc -c $^ -o $@
vfork.s:vfork.i
	gcc -S $^ -o $@
vfork.i:vfork.c
	gcc -E $^ -o $@
.PHONY:clean
clean:
	rm -f vfork vfork.i vfork.s vfork.o
