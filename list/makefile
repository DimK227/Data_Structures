list_test: main.o list.o
	gcc main.o list.o -o list_test
main.o: main.c
	gcc -c main.c
list.o: list.c
	gcc -c list.c
clean:
	rm list_test list.o main.o
run:
	@./list_test
