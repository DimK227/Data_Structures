#pragma once

typedef char * BfItem;

typedef struct{
  int *array;
  int size;
}BloomFilter;

typedef struct {
  BloomFilter bf;
  BfItem item;
}bloomfilter;



#define K 16

bloomfilter BFcreate(int size);
bloomfilter BFinsert(bloomfilter bloom, char *item);
int Exists_In_BloomFilter(bloomfilter bloom_filter, BfItem item);
void  EnableBit(int *array,  int k);
int IsZero(int array[], int k);
unsigned long djb2(unsigned char *str);
unsigned long sdbm(unsigned char *str);
unsigned long hash_i(unsigned char *str, unsigned int i);
void BFDestroy(bloomfilter bloom_filter);
