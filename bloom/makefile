bloom_test: main.o bloom.o
	gcc main.o bloom.o -o bloom_test
main.o: main.c
	gcc -c main.c
bloom.o: bloom.c
	gcc -c bloom.c
clean:
	rm bloom_test bloom.o main.o
run:
	@./bloom_test 
