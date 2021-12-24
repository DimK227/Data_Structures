#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "BH.h"



BHTree BHCreate()	//This function creates a heap
{
	BHTree heap;
	heap.heap=CBTCreate();
	return heap;
}

int BHIsEmpty(BHTree heap)		//This function checks if a heap is empty
{
	return CBTIsNil(heap.heap);
}

int BHGetMaxPriority(BHTree heap)		//This function returns the max priority
{
	return heap.priority[1];	//It is always at the root
}

BHItem BHGetMaxItem(BHTree heap)		//This function returns the item with the highest priority
{
	BHNode node;
        node=CBTGetRoot(heap.heap);		//Get the root
	return CBTGetItem(heap.heap,node);		//Return the item
}

BHTree BHHeapify(int n, int priorities[], BHItem items[])	//This function inserts items along with their priorities from an array in a heap
{
  int i;
  BHNode node;
	BHTree heap=BHCreate();			//Create the heap
  Funptr visit=&VisitNode;			//Pointer to function
	if (n>maxelem) {
		printf("Sorry no space\n");
		exit(-1);
	}
  for (i=0; i<n; i++) {
      heap.heap=CBTInsertLast(heap.heap,items[i]);
			//Insert the data and the priority
      heap.priority[i+1]=priorities[i];
  }
  heap=HeapifyReverse(heap,visit);
	return heap;
}

BHTree HeapifyReverse(BHTree heap,Funptr visit)   //This function gives a node in order to visit it ang heapify down it
{
    int h,i;
    h = CBTHeight(heap.heap);
    for (i=h-1; i>=1; i--){
	 heap=HeapifyLevel(heap,heap.heap,i,1,1,visit);	//For each level
    }
    return heap;
}

BHTree HeapifyLevel(BHTree heap,BHNode node, int level,int index, int k,Funptr visit)           //This function heapifies a level of a tree
{
    if (node == NULL) return heap;                                           //Base case
    else if (level == k){
	 		if (heap.heap==node) node=CBTGetRoot(heap.heap);	//This one is only useful for the ArrayImplementation because the root is at heap.heap[1] and not heap.heap
	 		heap=visit(heap,node,index);                           //If we "arrive" in the level that we want to print
	 		return heap;
    }
    else  {
        heap=HeapifyLevel(heap,CBTGetChildLeft(heap.heap,node),level,2*index, k+1, visit);
                                                                                                        //Go to other level
        heap=HeapifyLevel(heap,CBTGetChildRight(heap.heap,node),level,2*index+1, k+1, visit);
    }
    return heap;
}




BHTree VisitNode(BHTree heap,BHNode node,int index)                             //This function visits a node in order to heapify down it
{
       heap=HeapifyDown(heap,node,index);
       return heap;
}


BHTree HeapifyDown(BHTree heap,BHNode node,int index)				//This function heapifies a tree
{	int i;
	BHItem temp1,temp2;
        if ((CBTGetChildLeft(heap.heap,node)==NULL && CBTGetChildRight(heap.heap,node)==NULL) || 2*index > CBTSize(heap.heap)) return heap;		//If we are in a leaf we are done
        else if (CBTGetChildLeft(heap.heap,node)!=NULL && CBTGetChildRight(heap.heap,node)!=NULL) {		//If node has 2 childs
            if (heap.priority[index] >= heap.priority[2*index] && heap.priority[index] >= heap.priority[2*index + 1])  return heap; //If its priority is higher than its both childern's priority we are done
            else {
								cnt++;
			//Find the child with the smaller priority and swap their data and their priority
                if (heap.priority[2*index] >= heap.priority[2*index+1]) {
									temp1=CBTGetItem(heap.heap,node);temp2=CBTGetItem(heap.heap,CBTGetChildLeft(heap.heap,node));
									CBTChange(heap.heap,node,temp2); CBTChange(heap.heap,CBTGetChildLeft(heap.heap,node),temp1);
                	swap(&(heap.priority[index]),&(heap.priority[2*index]));
                	heap=HeapifyDown(heap,CBTGetChildLeft(heap.heap,node),2*index);
									return heap;
                }
                else {
                    temp1=CBTGetItem(heap.heap,node);temp2=CBTGetItem(heap.heap,CBTGetChildRight(heap.heap,node));
                    CBTChange(heap.heap,node,temp2); CBTChange(heap.heap,CBTGetChildRight(heap.heap,node),temp1);
                    swap(&(heap.priority[index]),&(heap.priority[2*index+1]));
                    heap=HeapifyDown(heap,CBTGetChildRight(heap.heap,node),2*index + 1);		//Recur
										return heap;
                }
            }
        }
        else if (CBTGetChildLeft(heap.heap,node)!=NULL && CBTGetChildRight(heap.heap,node)==NULL) {		//If it only has left child
                if (heap.priority[index] >= heap.priority[2*index]) return heap;	//If it has bigger priority than the child we are done
                else{		//else swap the data and the priority
                    temp1=CBTGetItem(heap.heap,node); temp2=CBTGetItem(heap.heap,CBTGetChildLeft(heap.heap,node));
                    CBTChange(heap.heap,node,temp2); CBTChange(heap.heap,CBTGetChildLeft(heap.heap,node),temp1);
                    swap(&(heap.priority[index]),&(heap.priority[2*index]));
                    heap=HeapifyDown(heap,CBTGetChildLeft(heap.heap,node),2*index + 1);
			    					return heap;
              }
        }
}

BHTree HeapifyUp(BHTree heap,BHNode node, int index)
{
	BHItem temp1,temp2;
 	if (heap.priority[index] <= heap.priority[index/2] || index<=1) return heap;		//If the node's priority is less than its parent's priority we are done
        else {
		cnt++;
		temp1=CBTGetItem(heap.heap,node); temp2=CBTGetItem(heap.heap,CBTGetParent(heap.heap,node));
		CBTChange(heap.heap,node,temp2); CBTChange(heap.heap,CBTGetParent(heap.heap,node),temp1);							//Else swap the data and the priority
                swap(&(heap.priority[index]),&(heap.priority[index/2]));
                node=CBTGetParent(heap.heap,node);					//Continue with the parent
                heap=HeapifyUp(heap,node,index/2);					//Reccur
		return heap;
        }
	return heap;
}



BHTree BHRemove(BHTree heap)		//This function removes the node with the highest priority (a.k.a the root)
{
	BHNode node;
	node=CBTGetLast(heap.heap);	//Get the last node
	CBTChange(heap.heap,CBTGetRoot(heap.heap),CBTGetItem(heap.heap,node));
								//And put it at the root changing the old root's data and priority
	heap.priority[1]=heap.priority[CBTSize(heap.heap)];	//The size of the tree is the index which the last node has
	if (CBTRemoveLast(heap.heap) == NULL) heap.heap = NULL;		//Now delete the last node bacause it is at the root now
	heap=HeapifyDown(heap,heap.heap,1);			//Heapify the tree
	return heap;
}

BHTree BHInsert(BHTree heap, int priority, BHItem item)		//This function inserts a node in heap
{
	BHNode node;
	heap.heap=CBTInsertLast(heap.heap,item);	//Insert it at the end
	heap.priority[CBTSize(heap.heap)]=priority;	//Put the priority in the right spot of the array
	node=CBTGetLast(heap.heap);			//Take the node that has just been inserted
	//printf("prin\n");
	heap=HeapifyUp(heap,node,CBTSize(heap.heap));	//Heapify the tree
	//printf("meta\n");
	return heap;
}

BHTree BHNaiveHeapify(int n, int priorities[], BHItem items[])		//This function creates a new heap by adding elements one by one into it
{
	int i;
	BHTree heap;
	heap=BHCreate();			//Create it
	for (i=0; i<n; i++) {
		heap=BHInsert(heap,priorities[i],items[i]);	//Insert the item
	}
	return heap;

}

BHTree BHNaiveHeapifyRnd(int n, int priorities[], BHItem items[]) 	//This function creates a new heap by adding elements one by one in a random way into it
{
	int i,k;
	BHTree heap;
	BHItem item;
	srand(time(NULL));
	heap=BHCreate();			//Create the heap
	k=rand()%(n+1);
	for (i=0; i<k; i++) {
		item=rand()%(n+1);
		swap(&(items[item]),&(items[i]));		//swap 2 random elements k times in order to randomize the array
		swap(&(priorities[item]),&(priorities[i]));
	}
	for (i=0; i<n; i++) {
		heap=BHInsert(heap,priorities[i],items[i]);	//Insert the items
	}
	return heap;
}


void BHDestroy(BHTree heap)	//This function destroys a tree
{
	CBTDestroy(heap.heap);
}


void swap(BHItem *a, BHItem *b)		//This function swaps two items
{
   BHItem  t;
   t  = *b;
   *b = *a;
   *a = t;
}
