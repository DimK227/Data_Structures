#pragma once
#include "BT.h"

typedef int CBTItem;
typedef BTNode CBTNode;
typedef CBTNode CBTTree;



CBTNode CBTCreate();
int CBTHeight(CBTTree tree);
int CBTSize(CBTTree tree);
CBTItem CBTGetItem(CBTTree tree,CBTNode node);
CBTNode CBTGetRoot(CBTTree tree);
CBTNode CBTGetParent(CBTTree tree,CBTNode node);
CBTNode CBTGetChildLeft(CBTTree tree,CBTNode node);
CBTNode CBTGetChildRight(CBTTree tree,CBTNode node);
int CBTIsNil(CBTNode node);
CBTNode CBTInsertLast(CBTTree tree, CBTItem item);
CBTNode CBTGetLast(CBTTree tree);
CBTNode CBTRemoveLast(CBTTree tree);
void CBTChange(CBTTree tree, CBTNode node, CBTItem item);
void CBTPostOrder(CBTTree tree,FunPtr visit);
void CBTPreOrder(CBTTree tree,FunPtr visit);
void CBTInOrder(CBTTree tree,FunPtr visit);
void CBTLevelOrder(CBTTree tree,FunPtr visit);
void CBTDestroy(CBTTree tree);
