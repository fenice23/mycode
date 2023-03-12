exit:exit.o
	gcc $^ -o $@
exit.o:exit.s
	gcc -c $^ -o $@
exit.s:exit.i
	gcc -S $^ -o $@
exit.i:exit.c
	gcc -E $^ -o $@
.PHONY:clean
clean:
	rm -f exit exit.o exit.s exit.i
