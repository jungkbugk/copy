

copy : copy.o
	gcc -o copy copy.c

clean : 
	rm -rf copy.o

.PHONY : copy.o
