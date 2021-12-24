BinarySearchTree_test: main.o BT.o BST.o
	gcc main.o BT.o BST.o -o BinarySearchTree_test
main.o: main.c
	gcc -c main.c
BT.o: BT.c
	gcc -c BT.c
BST.o: BST.c
	gcc -c BST.c
clean:
	rm BinarySearchTree_test main.o BT.o BST.o
run:
	@./BinarySearchTree_test
