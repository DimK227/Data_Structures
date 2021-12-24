#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "BST.h"

 int Compare(BSTKeyType a, BSTKeyType b)
{
        if (a==b) return 0;
        else if (a>b)return 1;
        else return -1;
}


int main ()
{
	BSTTree tree;
	int i;
	BSTItem item,item1;
	tree=BSTCreate();			//Create the tree
	srand(time(NULL));
	for (i=1; i<=5; i++) {
    //item = 6;
		item=rand()%11;
		if (i==3) item1=item;			//Fill he BST with random numbers
		tree=BSTInsert(tree,item,item,Compare);
		printf(printype,item);printf(" has just been inserted\n");
	}
  item = rand()%11;
  if (BSTsearch(tree, item,Compare)) printf("%d exists in our binary search tree\n", item);
  else printf("%d doesn't exist in our tree\n", item);
	tree=BSTRemove(tree,item1,Compare);		//Remove a node
	BSTDestroy(tree);
}
