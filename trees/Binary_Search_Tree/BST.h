#include "BT.h"
#pragma once
#define maxelem 100
typedef int BSTItem;
typedef int BSTKeyType;

typedef int (*CompareFunc)(BSTKeyType a, BSTKeyType b);


typedef BTNode BSTNode;


typedef struct {
	BSTNode tree;
	BSTKeyType key[maxelem*maxelem];		//The key of each node will be in this array
}BSTTree;




BSTTree BSTCreate();
BSTTree BSTInsert(BSTTree tree, BSTItem item, BSTKeyType key,CompareFunc Compare);
BSTTree BSTRemove(BSTTree tree, BSTKeyType key,CompareFunc Compare);
void swap(BSTKeyType *a,  BSTKeyType *b);
BSTNode  minValueNode(BSTTree tree,BSTNode  node, int *index);
BSTNode  maxValueNode(BSTTree tree,BSTNode  node, int *index);
int BSTsearch(BSTTree tree,int key, CompareFunc Compare);
void BSTDestroy(BSTTree tree);
int FindMaxIndex(BSTTree tree);
