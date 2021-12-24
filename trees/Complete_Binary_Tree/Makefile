CompleteBinaryTree_test: main.o BT.o CBT.o
	gcc main.o BT.o CBT.o -o CompleteBinaryTree_test
main.o: main.c
	gcc -c main.c
BT.o: BT.c
	gcc -c BT.c
CBT.o: CBT.c
	gcc -c CBT.c
clean:
	rm CompleteBinaryTree_test main.o BT.o CBT.o
run:
	@./CompleteBinaryTree_test
