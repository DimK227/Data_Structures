BinaryHeap_test: main.o BT.o CBT.o BH.o
	gcc main.o BT.o CBT.o BH.o -o BinaryHeap_test
main.o: main.c
	gcc -c main.c
BT.o: BT.c
	gcc -c BT.c
CBT.o: CBT.c
	gcc -c CBT.c
BH.o: BH.c
	gcc -c BH.c
clean:
	rm BinaryHeap_test main.o BT.o CBT.o BH.o
run:
	@./BinaryHeap_test
