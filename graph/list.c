#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"


listptr LstCreate()	//This function creates an empty list
{
	return NULL;
}

listptr LstInsert(listptr list,char *key,ListItem item)		//This function inserts a node at the end of a list
{
	listptr temp=list,newnode;
	//Create the node
	newnode=malloc(sizeof(struct listnode));
	(newnode->info).key=malloc(MAXSIZE*sizeof(char));
	strcpy((newnode->info).key,key);
	(newnode->info).item=item;
	newnode->next=NULL;
	//Node is created
	if (temp==NULL) {	//If the list is empty just insert the node
		temp=newnode;
		return temp;
	}
	else {				//Else go to the end
		if (strcmp((list->info).key,key)==0) {          //If a node has the same key  with the new node replace the old one
                    (list->info).item=item;
                    return temp;
                }
		while(list->next!=NULL) {
			 if (strcmp((list->info).key,key)==0) {		//If a node has the same key  with the new node replace the old one
				(list->info).item=item;
				return temp;
			}
			else list=list->next;
		}
		if (strcmp((list->info).key,key)==0) {          //If a node has the same key  with the new node replace the old one
                    (list->info).item=item;
                    return temp;
                }

		list->next=newnode;	//Insert it
		return temp;
	}
}



void LstInsertStart(listptr *list,char *key)
{
	listptr newnode;
	newnode=malloc(sizeof(struct listnode));
	(newnode->info).key=key;
	newnode->next=*list;
	*list=newnode;
}



int LstCount(listptr list)		//This function counts the node of a list
{
	int cnt=0;
	listptr temp=list;
	while (temp!=NULL) {
		temp=temp->next;
		cnt++;
	}
	return cnt;
}

int LstSearch(listptr list,char *key, ListItem *pitem)		//This function searches for a key in a list and if it exists copies the item to the pitem
{
	listptr temp=list;
	while (temp!=NULL) {
		if (strcmp((temp->info).key,key)==0) {		//If we find it
			(*pitem)=(temp->info).item;		//Copy
			return 1;				//Return TRUE
		}
		temp=temp->next;
	}
	return 0;

}

listptr LstDelete(listptr list, char *node)  	//This function deletes a node
{
    listptr dummy,templist=list;
    dummy=list;					//Dummy points to the start of the list
    if (strcmp((list->info).key,node)==0) {  	//If the node that we are looking for is at the start
                templist=list;
                list=list->next;
                free(templist);
                return list;
   }
   else {
                while (strcmp((list->info).key,node)!=0) {    	//I go at the end of the list saving the node before the last one
                        templist=list;
                        list=list->next;
                        if (list==NULL) {
                                printf("There is no node with code %s\n",node); 	//That means that the  node  that we want to delete does not exist
                                return dummy;
                           }
                }
                list=list->next;
                free(templist->next);
        	templist->next=list;
        	return dummy;
  }

}



void LstDestroy(listptr *list)			//This function destroys a list by freeing all the memory
{

   listptr current = *list;
   listptr next;
   while (current != NULL){
       next = current->next;	//Save the next node
       free(current);		//Delete the current node
       current = next;
   }
   *list = NULL;
}

void LstPrint(listptr list)
{
    while (list != NULL) {
    	if (list->next!=NULL)	printf("%s--> ", (list->info).key);
	else printf("%s ",(list->info).key);
    	list = list->next;
  }
  printf("\n");
}
