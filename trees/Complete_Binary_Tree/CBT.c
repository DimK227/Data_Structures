#include <stdio.h>
#include "CBT.h"


CBTNode CBTCreate()		//This function createw a NULL complete binary tree
{
	return BTCreate();
}

int CBTHeight(CBTNode tree)		//This  function  computes the height of a complete binary tree
{
	return BTHeight(tree);
}

int CBTSize(CBTNode tree)		//This function counts the nodes of a complete binary tree
{
	return BTSize(tree);
}

CBTItem CBTGetItem(CBTNode tree,CBTNode node)		//THis function returns the value of a node
{
	return BTGetItem(tree,node);
}

CBTNode CBTGetRoot(CBTNode tree)		//This function returns the root of a complete binary tree
{
	return BTGetRoot(tree);
}

CBTNode CBTGetParent(CBTNode tree,CBTNode node)		//This function returns the parent of  a node
{
	return BTGetParent(tree,node);
}

CBTNode CBTGetChildLeft(CBTNode tree,CBTNode node)		//This function gets the left chilf of a node
{
	return BTGetChildLeft(tree,node);
}

CBTNode CBTGetChildRight(CBTNode tree,CBTNode node)              //This function gets the left chilf of a node
{
        return BTGetChildRight(tree,node);
}

int CBTIsNil(CBTNode node)				//This function checks if a node is EMPTY
{
	return BTIsNil(node);
}




CBTNode CBTInsertLast(CBTNode tree, CBTItem item)	//This function inserts a node in a complete binary tree
{
	CBTNode node,node1,node2,node3,node4;
	int cl,cr,cl2,cr2;
	if (CBTGetRoot(tree)==NULL) {			//If the tree is NULL insert it as a root
		tree=BTInsertRoot(tree,item);
		return tree;
	}
	else {
		node=CBTGetRoot(tree);
		while(1) {
			if (CBTGetChildLeft(tree,node)==NULL && CBTGetChildRight(tree,node)==NULL) {	//If the node has no children insert left
					BTInsertLeft(tree,node,item);
					return tree;
					break;
			}
			else if (CBTGetChildLeft(tree,node)!=NULL && CBTGetChildRight(tree,node)==NULL){	//Else if it has only left child insert right
					BTInsertRight(tree,node,item);
					return tree;
					break;
			}
			else {
				cl=0;
				cr=0;
				cl2=0;
				cr2=0;
				node1=node;
				node2=node;
				node3=node;
				while ((node1=CBTGetChildLeft(tree,node1))!=NULL) cl++;		//cl counts the  most left nodes of the left subtree
				while ((node2=CBTGetChildRight(tree,node2))!=NULL) cr++;	//cr counts the most right nodes of the right subtree
				node3=CBTGetChildLeft(tree,node);
				node4=node3;
				while ((node3=CBTGetChildLeft(tree,node3))!=NULL) cl2++;	//cl2 counts the most left nodes of the left child's subtree
				while ((node4=CBTGetChildRight(tree,node4))!=NULL) cr2++;	//cr2 counts the most right nodes of the leftt child's subtree
				if (cl2!=cr2 || cl==cr) {					//If cl2!=cr2 the left subtree is not  full so go left-If cl2==cr2 the tree is full so go left
					node=CBTGetChildLeft(tree,node);
				}
				else {								//Else go right
					node=CBTGetChildRight(tree,node);
				}
			}
		}
	}
}


CBTNode CBTGetLast(CBTNode tree)				//This function returns the last node of a complete binary tree
{
	int cl,cr,cl2,cr2,cl3,cr3;
	CBTNode node,node1,node2,node3,node4,node5,node6;
    	if (CBTGetChildRight(tree,tree)==NULL && CBTGetChildLeft(tree,tree)==NULL) return tree;		//If the tree has no children return the root
		else {
			node=CBTGetRoot(tree);
			cl=0;
			cr=0;
			cl2=0;
			cr2=0;
			cl3=0;
			cr3=0;
			node1=node;
			node2=node;
			node3=node;
			while ((node1=CBTGetChildLeft(tree,node1))!=NULL) cl++;		//cl counts the  most left nodes of the left subtree
			while ((node2=CBTGetChildRight(tree,node2))!=NULL) cr++;	//cr counts the most right nodes of the right subtree
			node3=CBTGetChildLeft(tree,node);
			node5=CBTGetChildRight(tree,node);
			node6=node5;
			node4=node3;
			while ((node3=CBTGetChildLeft(tree,node3))!=NULL) cl2++;	//cl2 counts the most left nodes of the left child's subtree
			while ((node4=CBTGetChildRight(tree,node4))!=NULL) cr2++;	//cr2 counts the most right nodes of the left child's subtree

			while ((node5=CBTGetChildLeft(tree,node5))!=NULL) cl3++;	//cr2 counts the most rightt nodes of the right child's subtree

			while ((node6=CBTGetChildRight(tree,node6))!=NULL) cr3++;	//cr3 counts the most right nodes of the right child's subtree

			if ((cl2==cr2 && cl3!=cr3 ) || cr==cl) {			//If cl2==cr2 && cl3!=cr3 the left subtree is full and the right is not so go right-If cr==cl the tree is full so go right
				return CBTGetLast(CBTGetChildRight(tree,tree));
			}
			else {								//Else go left
				return CBTGetLast(CBTGetChildLeft(tree,tree));
			}
		}
}



CBTNode CBTRemoveLast(CBTNode tree)		//This function Removes the last node of a complete binary tree
{
	if (BTRemove(tree,CBTGetLast(tree)) == NULL) return NULL;

}

void CBTChange(CBTNode tree, CBTNode node, CBTItem item)	//This function change the data of a node in a complete binary tree
{
	BTChange(tree,node,item);
}

void CBTPostOrder(CBTNode tree,FunPtr visit)		//This function prints a complete binary tree in a postorder way
{
	BTPostOrder(tree,visit);
}

void CBTPreOrder(CBTNode tree,FunPtr visit)		 //This function prints a complete binary tree in a preorder way
{
        BTPreOrder(tree,visit);
}

void CBTInOrder(CBTNode tree,FunPtr visit)		//This function prints a complete binary tree in a inorder way
{
        BTInOrder(tree,visit);
}

void CBTLevelOrder(CBTNode tree,FunPtr visit)		//This function prints a complete binary tree in a levelorder way
{
        BTLevelOrder(tree,visit);
}

void CBTDestroy(CBTNode tree)				 //This function destroys a complete binary tree
{
	BTDestroy(tree);
}
