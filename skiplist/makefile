skiplist_test: main.o skip_list.o
	gcc main.o skip_list.o -o skiplist_test
main.o: main.c
	gcc -c main.c
skip_list.o: skip_list.c
	gcc -c skip_list.c
clean:
	rm skiplist_test skip_list.o main.o
run:
	@./skiplist_test
