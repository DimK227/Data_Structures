#include <stdio.h>
#include <stdlib.h>
#include "skip_list.h"


int main()
{
  skiplist *skip_list;
  skip_list = SkipLstCreate();
  SkipListItem item = "Vaclik";
  printf("Inserting %s in our skip list\n",item );
  skip_list->heads = SkipLstInsert(skip_list->heads, item);
  if (Exists_In_SkipList(skip_list->heads,item)) printf("%s exists in our skip list\n",item);
  else printf("%s does not exist in our skip list\n",item);

  item = "Pasxalakis";
  if (Exists_In_SkipList(skip_list->heads,item)) printf("%s exists in our skip list\n",item);
  else printf("%s does not exist in our skip list\n",item);

  item = "Brinioli";
  if (Exists_In_SkipList(skip_list->heads,item)) printf("%s exists in our skip list\n",item);
  else printf("%s does not exist in our skip list\n",item);

  item = "Stankovic";
  if (Exists_In_SkipList(skip_list->heads,item)) printf("%s exists in our skip list\n",item);
  else printf("%s does not exist in our skip list\n",item);

  item = "Tzolakis";
  printf("Inserting %s in our skip list\n",item );
  skip_list->heads = SkipLstInsert(skip_list->heads, item);
  if (Exists_In_SkipList(skip_list->heads,item)) printf("%s exists in our skip list\n",item);
  else printf("%s does not exist in our skip list\n",item);

  item = "Karargyris";
  printf("Inserting %s in our skip list\n",item );
  skip_list->heads = SkipLstInsert(skip_list->heads, item);
  if (Exists_In_SkipList(skip_list->heads,item)) printf("%s exists in our skip list\n",item);
  else printf("%s does not exist in our skip list\n",item);

  item = "Kristinson";
  printf("Inserting %s in our skip list\n",item );
  skip_list->heads = SkipLstInsert(skip_list->heads, item);
  if (Exists_In_SkipList(skip_list->heads,item)) printf("%s exists in our skip list\n",item);
  else printf("%s does not exist in our skip list\n",item);

  item = "Nikopolidis";
  printf("Inserting %s in our skip list\n",item );
  skip_list->heads = SkipLstInsert(skip_list->heads, item);
  if (Exists_In_SkipList(skip_list->heads,item)) printf("%s exists in our skip list\n",item);
  else printf("%s does not exist in our skip list\n",item);

  item = "Sa";
  printf("Inserting %s in our skip list\n",item );
  skip_list->heads = SkipLstInsert(skip_list->heads, item);
  if (Exists_In_SkipList(skip_list->heads,item)) printf("%s exists in our skip list\n",item);
  else printf("%s does not exist in our skip list\n",item);

  item = "Nikopolidis";
  printf("Deleting %s in our skip list\n",item );
  skip_list->heads = SkipLstDelete(skip_list->heads, item);
  if (Exists_In_SkipList(skip_list->heads,item)) printf("%s exists in our skip list\n",item);
  else printf("%s does not exist in our skip list\n",item);

  SkipListDestroy(skip_list->heads);

}
