#pragma once
#include "CBT.h"

#define maxelem 10000

typedef int BHItem;
int cnt;

typedef CBTNode BHNode;


typedef struct heap {
	BHNode heap;
	int priority[maxelem];		//The priority of each node will be in an array
}BHTree;



typedef BHTree (*Funptr)(BHTree heap,BHNode a,int index);
BHTree BHCreate();
int BHIsEmpty(BHTree heap);
int BHGetMaxPriority(BHTree heap);
BHItem BHGetMaxItem(BHTree heap);
BHTree BHHeapify(int n, int priorities[], BHItem items[]);
BHTree HeapifyReverse(BHTree heap,Funptr visit);
BHTree HeapifyLevel(BHTree heap,BHNode node, int level,int index, int k,Funptr visit);
BHTree VisitNode(BHTree heap,BHNode node,int index);
BHTree HeapifyDown(BHTree heap,BHNode node,int index);
BHTree BHRemove(BHTree heap);
BHTree BHInsert(BHTree heap, int priority, BHItem item);
BHTree HeapifyUp(BHTree heap,BHNode node, int index);
void BHDestroy(BHTree heap);
void swap(BHItem *a, BHItem *b);
BHTree BHNaiveHeapify(int n, int priorities[], BHItem items[]);
BHTree BHNaiveHeapifyRnd(int n, int priorities[], BHItem items[]);
