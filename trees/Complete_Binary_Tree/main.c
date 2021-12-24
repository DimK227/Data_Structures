#include <stdio.h>
#include "CBT.h"


int main()
{
	CBTNode tree,node;
	FunPtr visit;
	CBTItem item,value;
	int i;
	visit=&VisitTheNode;
	tree=CBTCreate();						//Create the tree
	for (i=1; i<=15; i++) tree=CBTInsertLast(tree,i);		//Fill the tree
	printf("Nodes have been inserted to the tree\n");
	printf("The tree has %d nodes\n",CBTSize(tree));		//Find the number of the nodes
	printf("The height of the tree is %d\n",CBTHeight(tree));	//Find the height of the tree
	node=CBTGetRoot(tree);						//Get the root
	if (node==NULL) printf("No root-tree is empty\n");
	else printf("I just got the root of a tree\n");
	node=CBTGetParent(tree,node);					//Get the parent
	if (node==NULL) printf("Node is the root so it has not parents\n");
	else  printf("I just got the parent of the tree of a tree\n");
	node=CBTGetRoot(tree);
	node=CBTGetChildLeft(tree,node);				//Get the left child
	if (node==NULL) printf("Node has not left child\n");
  else  printf("I just got the left child of node\n");
	node=CBTGetChildRight(tree,node);				//Get the right child
  if (node==NULL) printf("Node has not right child\n");
  else  printf("I just got the right child of node\n");
	node=CBTGetParent(tree,node);					//Get the parent
  if (node==NULL) printf("Node is the root so it has not parents\n");
  else printf("I just got the parent of node\n");
	printf("The node is%s nil\n", CBTIsNil(node) ? "" : " not");//Check if node is empty
	printf("The data of node is "); printf(printype,CBTGetItem(tree,node));printf("\n");
	if (CBTRemoveLast(tree) == NULL) tree=NULL;					 //Delete the last node
	node=CBTGetLast(tree);					//Get the last node
	CBTChange(tree,node,100);				//Change the node's data
	printf("The tree is printed using in a postorder way :	"); CBTPostOrder(tree,visit); printf("\n");
  printf("The tree is printed using in a preorder way  :	"); CBTPreOrder(tree,visit);  printf("\n");
                                                                                                                        //Print the trees in multiple ways
  printf("The tree is printed using in a inorder way   :	"); CBTInOrder(tree,visit);   printf("\n");
  printf("The tree is printed using in a levelorder way:	"); CBTLevelOrder(tree,visit);printf("\n");
	CBTDestroy(tree);					//Destroy the tree
	return 0;
}
