all:fork testgdb exec
testgdb:gdb.c
	gcc $^ -o $@ -g
fork:fork.c
	gcc $^ -o $@ -g
exec:exec.c
	gcc $^ -o $@ -g
.PHONY:clean
clean:
	rm -rf testgdb fork exec
