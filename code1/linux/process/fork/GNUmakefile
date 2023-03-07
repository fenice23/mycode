env:env.o
	gcc $^ -o $@
env.o:env.s
	gcc -c $^ -o $@
env.s:env.i
	gcc -S $^ -o $@
env.i:env.c
	gcc -E $^ -o $@
.PHONY:clean
clean:
	rm -rf env.o env.i env.s env
