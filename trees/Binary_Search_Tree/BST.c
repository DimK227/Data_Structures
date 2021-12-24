#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "BST.h"


BSTTree BSTCreate()	//This function creates an emty BST
{
	BSTTree tree;
	tree.tree= BTCreate();
	return tree;
}




BSTTree BSTInsert(BSTTree tree, BSTItem item, BSTKeyType key,CompareFunc Compare)	//This function inserts an item in BST
{
	int cond;
	int index=1;
	BSTNode node;
  	if (BTGetRoot(tree.tree)==NULL) {					//If BST is empty put the item at the root
	    tree.tree = BTInsertRoot(tree.tree,item);
			tree.key[index]=key;						//index==1.Put the key as the first element
			return tree;
  	}
		else {

			node=BTGetRoot(tree.tree);				//node is the BST now
			while (1) {
				cond=Compare(key,tree.key[index]);			//Compare the key of the node that we want to insert with the current key
				if (cond>0){						//If it is bigger go right
					if (BTGetChildRight(tree.tree,node)==NULL) {	//If there is no right child insert it
						BTInsertRight(tree.tree,node,item);
						tree.key[2*index + 1]=key;		//Put the key in the right spot
						break;
					}
					else {
						node=BTGetChildRight(tree.tree,node);		//Else go right
						index=2*index + 1;				//Fix the index
					}
				}
				else if (cond<0) {					//If it smaller
					if (BTGetChildLeft(tree.tree,node)==NULL) {	//If there is no left child insert it
	            BTInsertLeft(tree.tree,node,item);
	          	tree.key[2*index]=key;			//Put the key in the right spot
	            break;
	        }
	        else {
						node=BTGetChildLeft(tree.tree,node);	//Else go left
						index=2*index;				//Deal with the index
					}
				}
				else return tree;				//If they are equal  we do not do anything
			}
	}
	return tree;
}



BSTTree BSTRemove(BSTTree tree, BSTKeyType key,CompareFunc Compare)		//This function removes a node with specific key of a BST
{
    int cond,index=1,index1;
    BSTNode node1,node;
    BSTItem item1,item2;
    if (BTGetRoot(tree.tree)==NULL) return tree;			//If it is empty do nothing
    else {
			node=BTGetRoot(tree.tree);
			while(1) {
				cond=Compare(key,tree.key[index]);		//Compare the key of the node that we want to insert with the current key
				if (cond>0) {					//If it is bigger
					node=BTGetChildRight(tree.tree,node);		//Go right
          index=2*index + 1;				//Deal with the index
				}
				else if (cond<0) {				//If it is smaller
					node=BTGetChildLeft(tree.tree,node);		//Go left
					index=2*index;					//Deal with the index
				}
				else {							//We found it!
					if (BTGetChildLeft(tree.tree,node)==NULL && BTGetChildRight(tree.tree,node)==NULL){	//If it is a leaf
				 		if (BTRemove(tree.tree,node) == NULL) tree.tree = NULL;					//That means that we want to delete the root which is the only node in the tree
				 		return tree;
					}

					else  {

						if (BTGetChildRight(tree.tree,node)!=NULL) {				//If it has right child
				 		  index1=2 *index + 1;
				 			node1=minValueNode(tree,BTGetChildRight(tree.tree,node),&index1); //node1 has the node with the smallest key of the right subtree
						}
						else {
						  index1=2*index;
							node1=maxValueNode(tree,BTGetChildLeft(tree.tree,node),&index1);	//node1 has the node with the biggest key of the left subtree
						}

						item1=BTGetItem(tree.tree,node); item2=BTGetItem(tree.tree,node1);		//item1 has the data of node and item2 the data of node1
          	BTChange(tree.tree,node,item2); BTChange(tree.tree,node1,item1);
						//Swap the data and the key. Now the node that we want to delete is in the node1's spot!
          	swap(&(tree.key[index]), &(tree.key[index1]));

						while (BTGetChildLeft(tree.tree,node1)!=NULL ||  BTGetChildRight(tree.tree,node1)!=NULL) {		//Stop when node1 becomes a leaf
							if (BTGetChildRight(tree.tree,node1)!=NULL) {							//If it has right child
								item1=BTGetItem(tree.tree,node1); item2=BTGetItem(tree.tree,BTGetChildRight(tree.tree,node1));
                BTChange(tree.tree,node1,item2); BTChange(tree.tree,BTGetChildRight(tree.tree,node1),item1);
								//Swap the data and the key and now node1 go right
                swap(&(tree.key[index1]), &(tree.key[2*index1 + 1]));
                node1=BTGetChildRight(tree.tree,node1);
                index1=2*index1 + 1;
							}
							else {
								item1=BTGetItem(tree.tree,node1); item2=BTGetItem(tree.tree,BTGetChildLeft(tree.tree,node1));
                BTChange(tree.tree,node1,item2); BTChange(tree.tree,BTGetChildLeft(tree.tree,node1),item1);
								//Swap the data and the key and now node1 go left
                swap(&(tree.key[index1]), &(tree.key[2*index1]));
            		node1=BTGetChildLeft(tree.tree,node1);
              	index1=2*index1;
							}
						}
						BTRemove(tree.tree,node1);				//Now the node1 (a.k.a the node that we want to delete is a leaf and so we can use the BTRemove
						tree.key[index1]=INT_MIN;				//Put the smallest number in the key array
						return tree;
					}
				}
     	}
   }
}


BSTNode  minValueNode(BSTTree tree,BSTNode  node, int *index)		//This function returns the final left child of a tree
{
    BSTNode current = node;
    while (BTGetChildLeft(tree.tree,current) != NULL){
        current = BTGetChildLeft(tree.tree,current);
				(*index)=2 * (*index);
    }
    return current;
}


BSTNode  maxValueNode(BSTTree tree,BSTNode  node, int *index)	//This function returns the final right child of a tree
{
    BSTNode current = node;
    while (BTGetChildRight(tree.tree,current) != NULL){
        current = BTGetChildRight(tree.tree,current);
        (*index)=2 * (*index) + 1;
    }
    return current;
}


void BSTDestroy(BSTTree tree)
{
	BTDestroy(tree.tree);
}


int FindMaxIndex(BSTTree tree)
{
	BSTNode node=tree.tree;

	int index=1;
	while (BTGetChildRight(tree.tree,node)!=NULL){
		 node=BTGetChildRight(tree.tree,node);		//It is the right-most node
		 index=2*index+1;
	}
	return index;
}

int BSTsearch(BSTTree tree,BSTKeyType key, CompareFunc Compare)
{
	int index = 1, cond;
	BSTNode node;
	if (BTGetRoot(tree.tree)==NULL) return 0;			//If it is empty do nothing
	else {
		node=BTGetRoot(tree.tree);
		while(1) {
			cond=Compare(key,tree.key[index]);		//Compare the key of the node that we want to insert with the current key
			if (cond>0) {					//If it is bigger
				node=BTGetChildRight(tree.tree,node);		//Go right
				index=2*index + 1;				//Deal with the index
			}
			else if (cond<0) {				//If it is smaller
				node=BTGetChildLeft(tree.tree,node);		//Go left
				index=2*index;					//Deal with the index
			}
			else {							//We found it!
				return 1;
			}
			if (node == NULL) return 0;		//It doesn't exist
		}
	}
}


void swap(BSTKeyType *a, BSTKeyType *b)		//This function swaps two items
{
   BSTKeyType  t;
   t  = *b;
   *b = *a;
   *a = t;
}
