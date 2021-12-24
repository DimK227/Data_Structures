#include "list.h"
#include <stdio.h>


int main()
{
  listptr list = LstCreate();
  ListItem item;

  item = "El Arabi";
  printf("Inserting %s at the end of our list\n",item );
  list = LstInsert(list, item);
  item = "Rodriguez";
  printf("Inserting %s at the end of our list\n",item );
  list = LstInsert(list, item);
  item = "Masouras";
  printf("Inserting %s at the start of our list\n",item );
  list = LstInsertAtStart(list, item);
  item = "Camara";
  printf("Inserting %s at the start of our list\n",item );
  list = LstInsertAtStart(list, item);
  printf("Deleting %s from our list\n", item);
  list = LstDelete(list, item);
  LstPrint(list);
  item = "Fortounis";
  printf("Inserting %s at the start of our list\n",item );
  list = LstInsertAtStart(list, item);
  LstPrint(list);
  LstDestroy(&list);
}
