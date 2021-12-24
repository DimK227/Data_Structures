#include <stdio.h>
#include "bloom.h"


int main()
{
  bloomfilter bloom_filter = BFcreate(200);
  BfItem item = "El Arabi";
  if (Exists_In_BloomFilter(bloom_filter,item)) printf("%s probably exists in our bloom filter\n", item);
  else printf("%s does not exist in our bloom filter (100%%)\n", item);
  printf("Inserting %s in our bloom filter\n",item);
  bloom_filter = BFinsert(bloom_filter, item);
  if (Exists_In_BloomFilter(bloom_filter,item)) printf("%s probably exists in our bloom filter\n", item);
  else printf("%s does not exist in our bloom filter (100%%)\n", item);

  item = "Akpom";
  if (Exists_In_BloomFilter(bloom_filter,item)) printf("%s probably exists in our bloom filter\n", item);
  else printf("%s does not exist in our bloom filter (100%%)\n", item);

  item = "Carlitos";
  if (Exists_In_BloomFilter(bloom_filter,item)) printf("%s probably exists in our bloom filter\n", item);
  else printf("%s does not exist in our bloom filter (100%%)\n", item);

  item = "Araujo";
  if (Exists_In_BloomFilter(bloom_filter,item)) printf("%s probably exists in our bloom filter\n", item);
  else printf("%s does not exist in our bloom filter (100%%)\n", item);

  item = "Tiquinho";
  printf("Inserting %s in our bloom filter\n",item);
  bloom_filter = BFinsert(bloom_filter, item);
  if (Exists_In_BloomFilter(bloom_filter,item)) printf("%s probably exists in our bloom filter\n", item);
  else printf("%s does not exist in our bloom filter (100%%)\n", item);

  BFDestroy(bloom_filter);

}
