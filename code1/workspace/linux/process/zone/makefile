zone:zone.o
	gcc $< -o $@
zone.o:zone.s
	gcc -c $< -o $@
zone.s:zone.i
	gcc -S $< -o $@
zone.i:zone.c
	gcc -E $< -o $@
.PHONY:clean
clean:
	rm -f zone zone.i zone.s zone.o

