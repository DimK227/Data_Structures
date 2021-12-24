#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"


listptr LstCreate()	//This function creates an empty list
{
	return NULL;
}

listptr LstInsert(listptr list,ListItem item)		//This function inserts a node at the end of a list
{
	listptr temp=list,newnode;
	//Create the node
	newnode=malloc(sizeof(struct listnode));
  newnode->item = malloc(strlen(item)+1 * (sizeof(char)));
  strcpy(newnode->item, item);
	newnode->next=NULL;
	//Node is created
	if (temp==NULL) {	//If the list is empty just insert the node
		temp=newnode;
		return temp;
	}
	while(list->next!=NULL) {
	   list=list->next;
	}
	list->next=newnode;	//Insert it
	return temp;
}

listptr LstInsertAtStart(listptr list, ListItem item)
{
  listptr newnode=malloc(sizeof(struct listnode));
  newnode->item = malloc(strlen(item)+1 * (sizeof(char)));
  strcpy(newnode->item, item);
	newnode->next=list;
  list = newnode;
  return list;

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


void LstPrint(listptr list)
{
  int i;
  listptr temp = list;
  while (temp!=NULL) {
    if (temp->next!=NULL) printf("%s->", temp->item);
    else printf("%s", temp->item);
    temp = temp->next;
  }
  printf("->NULL\n");

}

int LstSearch(listptr list,char *item, ListItem *pitem)		//This function searches for a key in a list and if it exists copies the item to the pitem
{
	listptr temp=list;
	while (temp!=NULL) {
		if (strcmp(temp->item,item)==0) {		//If we find it
			(*pitem)=temp->item;		//Copy
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
    if (strcmp(list->item,node)==0) {  	//If the node that we are looking for is at the start
      templist=list;
      list=list->next;
      free(templist);
      return list;
   }
   else {
      while (strcmp(list->item,node)!=0) {    	//I go at the end of the list saving the node before the last one
          templist=list;
          list=list->next;
          if (list==NULL) {
              printf("There is no node named %s\n",node); 	//That means that the  node  that we want to delete does not exist
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
       free(current->item);
       free(current);		//Delete the current node
       current = next;
   }
   *list = NULL;
}
