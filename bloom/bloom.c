#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bloom.h"



bloomfilter BFcreate(int size)		//This function creates a bloom filter
{

	bloomfilter bloom_filter;
	bloom_filter.bf.array = malloc(size);
	bloom_filter.bf.size = size;
	if (bloom_filter.bf.array == NULL){
		printf("malloc failed\n");
		exit(-1);
	}
	else return bloom_filter;
}

bloomfilter BFinsert(bloomfilter bloom_filter, char *item)	//This function inserts item in the bloom_filter
{
	int i;
	int bit;

	for (i=0; i<K; i++) {
		bit = hash_i(item,i)%(bloom_filter.bf.size*8);		//Find the right bit
	  	EnableBit(&bloom_filter.bf.array[0],bit);				//Enable it
	}
	return bloom_filter;
}

int Exists_In_BloomFilter(bloomfilter bloom_filter, BfItem item)		//This function checks if item exists in a bloom filter (Note: There is always the case of false poistive result)
{
	int i;
	int bit;
	for (i=0; i<K; i++) {
			bit = hash_i(item,i)%(bloom_filter.bf.size*8);			//Find the right bit
			if (IsZero(bloom_filter.bf.array,bit)) return 0;		//Check if it is zero and if so item does not exist for sure
	}
	return 1;			//The item MIGHT exists
}

void EnableBit(int *array,  int k)			//This functions turns into 1 the kth bit of array
{
		int s = sizeof(int)*8;		//s is the number of bits that each element of array has
    int i = k/s;        //Take the index that kth bit exists in the array
    int pos = k%s;      //Take the exact bit position in array[i]

    unsigned int new = 1;   // flag = 0000.....00001

    new = new << pos;      // flag = 0000...010...000   (shifted k positions)

    array[i] = array[i] | new;      // Enable the bit at the kth position in array[i]
}

int IsZero(int array[],  int k)		//This function checks if kth bit of array is 0
{
    return ((array[k/32] & (1 << (k%32) )) == 0);
}


unsigned long djb2(unsigned char *str)
{
	 unsigned long hash = 5381;
	 int c;
	 while (c = *str++) {
		   hash = ((hash << 5) + hash) + c;
	 }
	 return hash;
}


unsigned long sdbm(unsigned char *str)
{
	 unsigned long hash = 0;
	 int c;
	  while (c = *str++) {
		    hash = c + (hash << 6) + (hash << 16) - hash;
	  }

	 return hash;
}

unsigned long hash_i(unsigned char *str, unsigned int i)
{
	return djb2(str) + i*sdbm(str) + i*i;
}

void BFDestroy(bloomfilter bloom_filter)
{
	free(bloom_filter.bf.array);
}
