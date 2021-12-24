#include <stdio.h>
#include "BT.h"

int main()
{
    BTNode node;
    BTTree tree;
    int h,s;
    BTItem value,item;
    FunPtr visit;
    visit=&VisitTheNode;
    tree=BTCreate();                                                                //Create a NULL tree
    h=BTHeight(tree);                                                               //Compute the height of the tree
    printf("The height of the tree is %d\n",h);
    s=BTSize(tree);                                                                 //Count the elemnents of a tree
    printf("The tree has %d nodes\n",s);
    node=BTGetRoot(tree);                                                           //Get the root
    if (node!=NULL) printf("I just got the root of the tree\n");
    else printf("The tree is empty\n");
    node=BTGetParent(tree,node);                                            //Get the parent
    if (node==NULL) printf("No parents\n");
    else printf("I just got the parent of node\n");
    node=BTGetChildLeft(tree, node);                                                                        //Get the left child
    if (node==NULL) printf("There is no left child\n");
    else printf("I just got the left child of the node\n");
    node=BTGetChildRight(tree, node);                                                               //Get the right child
    if (node==NULL) printf("There is no right child\n");
    else printf("I just right child of the node\n");
    printf("The node is%s nil\n", BTIsNil(node) ? "" : " not");                                 //Check if tree is empty
    item=7;
    tree=BTInsertRoot(tree, item);                                                                  //Insert the item as a root
    printf("The %d is the root of the tree\n",item);
    item=9;
    node=BTGetRoot(tree);
    if (node!=NULL) printf("I just got the root of the tree\n");
    else printf("The tree is empty\n");                                                             //Get the root in order to insert its children
    BTInsertLeft(tree, node, item);                                                                 //Insert a left child
    printf(printype,item); printf(" has been inserted as the left child of node\n");
    item=10;
    BTInsertRight(tree, node, item);                                                                //Insert a right child
    printf(printype,item); printf(" has been inserted as the right child of node\n");
    item=15;
    node=BTGetChildRight(tree, node);                                                               //Get the right child in order to inserts children its left child
    BTInsertLeft(tree, node, item);                                                                 //Insert a left child
    printf(printype,item); printf(" has been inserted as the left child of node\n");
    item=20;
    BTInsertRight(tree, node, item);                                                                //Insert a right child
    printf(printype,item); printf(" has been inserted as the right child of node\n");
    item=11;
    node=BTGetRoot(tree);
    if (node!=NULL) printf("I just got the root of the tree\n");
    else printf("The tree is empty\n");                                                             //Get root
    node=BTGetChildLeft(tree, node);                                                                //Get the left child of the root in order to insert children
    BTInsertLeft(tree, node, item);                                                                 //Insert a left child
    printf(printype,item); printf(" has been inserted as the left child of node\n");
    BTInsertRight(tree, node, item);                                                                //Insert a right child
    printf(printype,item); printf(" has been inserted as the right child of node\n");
    value=BTGetItem(tree, node);                                                                    //Get the value of node
    printf("The item of the node is "); printf(printype,value); printf("\n");                       //Print it
    node=BTGetChildLeft(tree, node);                                                                //Get the left child in order to find its father
    if (node==NULL) printf("There is no left child\n");
    else printf("I just got the left child of the node\n");
    node=BTGetParent(tree,node);                                                                                    //Get the parent of node
    if (node==NULL) printf("No parents\n");
    else {
    printf("I just got the parent of node which is ");      printf(printype,value); printf("\n");
    }
    h=BTHeight(tree);                                                                                               //Compute the height of the tree
    printf("The height of the tree is %d\n",h);
    s=BTSize(tree);                                                                                                 //Count the elemnents of a tree
    printf("The tree has %d nodes\n",s);
    node=BTGetChildLeft(tree, node);                                                                            //Get a child in order to delete it
    if (BTRemove(tree,node) == NULL) tree = NULL;                                                                                            //Delete it
    node=BTGetRoot(tree);                                                                                           //Get the root
    if (node!=NULL) printf("I just got the root of the tree\n");
    else printf("The tree is empty\n");
    node=BTGetChildLeft(tree, node);                                                                                //Get the left child
    item=100;
    BTChange(tree, node, item);
    printf("The tree is printed using in a postorder way: "); BTPostOrder(tree,visit); printf("\n");
    printf("The tree is printed using in a preorder way:  "); BTPreOrder(tree,visit); printf("\n");
    printf("The tree is printed using in a inorder way:   "); BTInOrder(tree,visit); printf("\n");
    printf("The tree is printed using in a levelorder way:"); BTLevelOrder(tree,visit);printf("\n");
    BTDestroy(tree);                                                                                                //Destroy the tree;
    return 0;
}
