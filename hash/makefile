hash_test: main.o hash.o list.o
	gcc main.o list.o hash.o -o hash_test
main.o: main.c
	gcc -c main.c
hash.o: hash.c
	gcc -c hash.c
list.o: list.c
	gcc -c list.c
clean:
	rm hash_test list.o main.o hash.o
run:
	@./hash_test
