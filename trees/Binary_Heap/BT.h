#pragma once


typedef struct tnode *BTNode;	//Pointer to a tree's node
typedef int BTItem;			//The data type of the tree's nodes
static char *printype="%d";		//You can change it into whatever you want!
typedef void (*FunPtr)(BTNode a);
void VisitTheNode(BTNode node);
typedef BTNode BTTree;

BTNode BTCreate();
int BTHeight(BTTree tree);
int BTSize (BTTree tree);
BTNode BTGetRoot(BTTree tree);
BTNode BTGetParent(BTTree tree,BTNode node);
BTNode BTGetChildLeft(BTTree tree,BTNode node);
BTNode BTGetChildRight(BTTree tree,BTNode node);
int BTIsNil(BTNode node);
BTItem BTGetItem(BTTree tree,BTNode node);
BTNode BTInsertRoot(BTTree tree,BTItem item);
void BTInsertLeft(BTTree tree, BTNode node, BTItem item);
void BTInsertRight(BTTree tree, BTNode node, BTItem item);
BTNode BTRemove(BTTree tree,BTNode node);
void BTChange(BTTree tree, BTNode node, BTItem item);
void BTDestroy(BTTree tree);
void BTPostOrder(BTTree node,FunPtr visit);
void BTInOrder(BTTree node,FunPtr visit);
void BTPreOrder(BTTree node,FunPtr visit);
void BTLevelOrder(BTTree tree,FunPtr visit);
void PrintLevel(BTTree root, int level, int k, FunPtr visit);
