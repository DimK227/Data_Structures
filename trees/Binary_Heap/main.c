#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "BH.h"



int main()
{
	BHTree heap,heap2,heap3;
	int n=5;
	BHItem items[n],item;
	int priorities[n],i;
	cnt=0;
	srand(time(NULL));
	heap=BHCreate();
	heap2=BHCreate();
	heap3=BHCreate();
	printf("The heap is%s empty\n", BHIsEmpty(heap) ? "" : " not");
	for (i=0; i<n; i++) {
		items[i]=i;//tem;
		priorities[i]=i;//tem;
        }
	heap=BHHeapify(n,priorities,items);
	printf("The BHHeapify method did %d steps\n",cnt);
	cnt=0;
	heap2=BHNaiveHeapify(n,priorities,items);
	printf("The BHNaiveHeapify method did %d steps\n",cnt);
	cnt=0;
	heap3=BHNaiveHeapifyRnd(n,priorities,items);
        printf("The BHNaiveHeapifyRnd method did %d steps\n",cnt);
	//Items have been inserted
	for (i=1; i<=10; i++){
		//printf("i=%d\n",i);
		heap=BHInsert(heap,i*i,i*i);	//Insert more items-the priority will be just the i
	}
  	printf("The heap is%s empty\n", BHIsEmpty(heap) ? "" : " not");
 	printf("The highest priority is %d\n",BHGetMaxPriority(heap));	//Print the highest priority
 	printf("The node with the highest priority is "); printf(printype,BHGetMaxItem(heap));printf("\n");	//Print the item with the highest priority
	heap=BHRemove(heap);		//Remove the node with the highest priority
	BHDestroy(heap);	//Destroy the heap
	return 0;
}
