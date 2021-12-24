binarytree_test: main.o BT.o
	gcc main.o BT.o -o binarytree_test
main.o: main.c
	gcc -c main.c
BT.o: BT.c
	gcc -c BT.c
clean:
	rm binarytree_test main.o BT.o
run:
	@./binarytree_test
