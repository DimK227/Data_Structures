#include <stdio.h>
#include <stdlib.h>
#include "BT.h"


struct tnode {
  BTItem data;
  BTNode left;                  //Points to the left child
  BTNode right;                 //Points to the right child
  BTNode parent;
};

BTNode BTCreate()
{
	return NULL;
}

int BTHeight(BTTree tree)		//This function computes the height of a tree
{
  int n1, n2;
  if (tree == NULL)  return 0;             //Base case
  n1 = BTHeight(tree->left);        	  // Compute height of left subtree
  n2 = BTHeight(tree->right);      		 // Compute height of right subtree
  return (n1 > n2) ? n1+1 : n2+1; 	    // Return maximun of height of left and right subtrees
}

int BTSize(BTTree tree)		//This function counts the nodes of a tree
{
    int count = 0;
    if (tree==NULL) return 0;				//base case
    if (tree->left != NULL) count += BTSize(tree->left);		//Count the nodes in the left subtree
    if (tree->right != NULL) count += BTSize(tree->right);		//Count the nodes in the right subtree
    return count+1;				//+1 is because of the root
}

BTNode BTGetRoot(BTTree tree)	//This function returns the root of a tree
{
	return tree;
}


BTNode BTGetParent(BTTree tree,BTNode node)
{
	if (tree==NULL) return NULL;
        if (node!=NULL) return node->parent;
        else exit(-1);
}

BTNode BTGetChildLeft(BTTree tree,BTNode node)	//This function returns the left child of a node
{
	if (node==NULL||tree==NULL) return NULL;
        return node->left;

}

BTNode BTGetChildRight(BTTree tree,BTNode node)	//This function returns the right child of a node
{
	if (node==NULL||tree==NULL) return NULL;
	return node->right;
}

int BTIsNil(BTNode node)	//This function checks if a tree is empty
{
	if (node==NULL) return 1;
	else return 0;
}

BTItem BTGetItem(BTTree tree,BTNode node)	//This function returns the value of a node
{
	if (tree==NULL) {				//If tree is NULL terminate the program;
		printf("The tree is NULL and the program just got terminated\n");
		exit(-1);
	}
	else return node->data;
}

BTNode BTInsertRoot(BTTree tree,BTItem item)	//This function Inserts a root in an empty tree
{
	BTNode root;
	if (tree!=NULL){				//If it is not empty return the same tree
		printf("Tree is not empy\n");
		return tree;
	}
	root=malloc(sizeof(struct tnode));
	root->left=NULL;
	root->parent=NULL;
								//Create the root
	root->right=NULL;
	root->data=item;
	return root;
}



void BTInsertLeft(BTTree tree, BTNode node, BTItem item)		//This function inserts a node as left child of another node
{
	BTNode newnode;

	if (node->left!=NULL){
		 return;		//If node has a left child just return this in order not to change anything
	}
	else {
		newnode=malloc(sizeof(struct tnode));
		newnode->left=NULL;
		newnode->parent=node;
								//Create the node
		newnode->right=NULL;
		newnode->data=item;
		node->left =newnode;
	}
}

void BTInsertRight(BTTree tree, BTNode node, BTItem item)		//This function inserts a node as right child of another node
{
	BTNode newnode;
	if (node->right!=NULL) return;								//If node has a right child just return this in order not to change anything
	else {
		newnode=malloc(sizeof(struct tnode));
		newnode->left=NULL;
		newnode->parent=node;
								//Create the node
		newnode->right=NULL;
		newnode->data=item;
		node->right =newnode;
	}
}


BTNode BTRemove(BTTree tree,BTNode node)			//This function removes a leaf
{
	BTNode temp=node;
	BTItem value=node->data;
	if (node->left!=NULL || node->right!=NULL) {		//Check wether it is leaf or not
		printf("node it is not a leaf-I cannot delete it");
		return tree;
	}
	else {
    if (node->parent == NULL){                      //If we are in the root
      free(node);
      printf("A node with value "); printf(printype,value); printf(" has just been deleted\n");
      return NULL;
    }
		if (node->parent->left==node) {			//Check if the left child of the father it is father's node
			node->parent->left=NULL;
			free(temp);
		}
		else {								//Check if the right child of the father it is father's node
			node->parent->right=NULL;
			free(temp);
		}
		printf("A node with value "); printf(printype,value); printf(" has just been deleted\n");
	}
}

void BTChange(BTTree tree, BTNode node, BTItem item)			//This function changes the data part of a node
{
	node->data=item;
}

void VisitTheNode(BTNode node)				//This function visits a node in order to print it
{
	printf(printype,node->data); printf(" 	");
}

void BTPostOrder(BTNode node,FunPtr visit) 	//This function prints a tree in a postorder way
{
     if (node == NULL) return;			//Base case

     BTPostOrder(node->left,visit); 		// First recur on left subtree

     BTPostOrder(node->right,visit); 		// Then recur on right subtree

     visit(node); 		//Now deal with the node
}


void BTInOrder(BTNode node,FunPtr visit) 	//This function prints a tree in a inorder way
{
     if (node == NULL) return; 			//Base case

     BTInOrder(node->left,visit); 			// First recur on left subtree

     visit(node);   		//  Deal with the node

     BTInOrder(node->right,visit); 		//Now recur on right subtree
}


void BTPreOrder(BTNode node,FunPtr visit) 	//This function prints a tree in a preorder way
{
     if (node == NULL) return; 			//Base case

     visit(node);   		//  Deal with the node

     BTPreOrder(node->left,visit);   		// Then recur on left subtree

     BTPreOrder(node->right,visit); 		//Now recur on right subtree
}

void BTLevelOrder(BTTree tree,FunPtr visit) 	//This function prints a tree in a levelorder way
{
    int h,i;
    h = BTHeight(tree);
    for (i=1; i<=h; i++) PrintLevel(tree,i,1,visit); 	//For each level
}
void PrintLevel(BTNode node, int level, int k,FunPtr visit)		//This function prints a level of a tree
{
    if (node == NULL) return; 						//Base case
    else if (level == k) visit(node);				//If we "arrive" in the level that we want to print
    else  {
        PrintLevel(node->left,level, k+1, visit);
        												//Go to other level
        PrintLevel(node->right,level, k+1, visit);
    }
}

void BTDestroy(BTTree tree)			//This function frees all nodes in a binary tree
{

    if (tree==NULL) return;			//Base case
    BTDestroy(tree->left);		//Recur on left subtree
    BTDestroy(tree->right);			//Recur on right subtree
    free(tree);			//Free the node
}
