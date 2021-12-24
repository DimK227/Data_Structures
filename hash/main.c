#include <stdio.h>
#include "hash.h"


int main()
{
  HTHash hash_table;
  HTItem item;
  hash_table = HTCreate(7);     //Create hash table
  printf("The total number of items in our hash table is %d\n",HTSize(hash_table));
  //Test the code by inserting, deleting, counting, visiting and searhing
  item = "The Godfather";
  printf("Inserting %s in our hash table\n",item );
  hash_table = HTInsert(hash_table,item);
  item = "James Bond";
  printf("Inserting %s in our hash table\n",item );
  hash_table = HTInsert(hash_table,item);
  item = "Titanic";
  printf("Inserting %s in our hash table\n",item );
  hash_table = HTInsert(hash_table,item);
  item = "Goodfellas";
  printf("Inserting %s in our hash table\n",item );
  hash_table = HTInsert(hash_table,item);
  item = "Dances with the wolves";
  printf("Inserting %s in our hash table\n",item );
  hash_table = HTInsert(hash_table,item);
  item = "Spiderman";
  printf("Inserting %s in our hash table\n",item );
  hash_table = HTInsert(hash_table,item);

  FunPtr visit;
  HTVisit(hash_table,visit);
  printf("The total number of items in our hash table is %d\n",HTSize(hash_table));
  item = "Titanic";
  printf("Deleting %s from our hash table\n",item );
  hash_table = HTRemove(hash_table, item);
  HTVisit(hash_table,visit);
  printf("The total number of items in our hash table is %d\n",HTSize(hash_table));

  item = "Batman";
  HTItem item2;
  printf("Searching for %s\n", item);
  if (HTGet(hash_table, item, &item2)) printf("%s exists in our hash table\n",item);
  else printf("%s does not exist in our hash table\n",item );

  item = "Spiderman";
  printf("Searching for %s\n", item);
  if (HTGet(hash_table, item, &item2)) printf("%s exists in our hash table\n",item);
  else printf("%s does not exist in our hash table\n",item );
}
