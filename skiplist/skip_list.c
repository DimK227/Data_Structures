#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include "skip_list.h"




skiplist *SkipLstCreate()                    //This function creates a skip list
{
  skiplist *skip_list;
  skip_list = malloc(sizeof(skiplist));
  int i;
  skip_list->heads = malloc(sizeof(SkipListptr)*MAX_LEVEL);    //Create MAX_LEVEL possible empty levels. heads[0] points to the 0-level, heads[1] to the 1-level etc
  for (i=0; i<MAX_LEVEL; i++) {
    skip_list->heads[i] = NULL;
  }
  return skip_list;
}



SkipListptr *SkipLstInsert(SkipListptr *heads, SkipListItem item)    //This function insert an item in a linked list and save in this node the inormation of the corresponding record
{
  int i;
  SkipListptr *temp1 = heads,prev;
  SkipListptr array[MAX_LEVEL],temp2;
  for (i=0; i<MAX_LEVEL; i++) array[i] = NULL;      //Array[i] contains the spot that new node is going to be inserted in the i-level
  for (i=MAX_LEVEL-1; i>=0; i--) {                  //For each level find the spot
      temp2 = temp1[i];
      while (temp2!=NULL) {
          if (atoi(temp2->item) < atoi(item)) {
            array[i] = temp2;
          }
          temp2 = (temp2)->next;
      }
  }
  for (i=0; i<MAX_LEVEL; i++) {             //For each level
    int r = rand()%2;                       //Probability: 50%
    if ((array[i] == NULL && r==1)||(i==0 && array[i]==NULL)){  //If (it is going to be the first node of the level and r==1) or (it is the 0-level(everything goes there) and it is going to be the first node of the level)
      SkipListptr newnode = malloc(sizeof(struct skiplistnode));
      newnode->next = heads[i];
      heads[i] = newnode;                                      //Create the node
      heads[i]->item = malloc(strlen(item)+1);
      strcpy(heads[i]->item, item);
      if (i==0) heads[i]->down = NULL;                            //If it is the first level there is nothing down the new node
      else heads[i]->down = prev;                                 //Else down is the previous node that we inserted
      prev = heads[i];                                            //Update the previous node
    }
    else if ((r==1 || i==0) && array[i]!=NULL){                 //if (r==1 or it is the first level) AND the node will not be the first node of the level
      SkipListptr newnode = malloc(sizeof(struct skiplistnode));      //Create the node
      if (i!=0)newnode->down = array[i-1]->next;
      else if (i==0) newnode->down = NULL;
      newnode->next = array[i]->next;
      newnode->item = malloc(strlen(item)+1);
      strcpy(newnode->item, item);
      array[i]->next = newnode;
      prev = newnode;
    }
    else if (r == 0) break;   //If r==0 we don't insert the node in this level and so we stop the process of insertion
  }
  return temp1;
}



SkipListptr *SkipLstDelete(SkipListptr *heads, SkipListItem item)     //This function deletes the item from the skip list
{
  int found,i,f=0;
  SkipListptr *temp1 = heads,prev,node;
  SkipListptr prev2[MAX_LEVEL],array[MAX_LEVEL],temp2;    //array[i] contains the addresses od the node to be deleted in i-level and prev2[i] its revious
  for (i=0; i<MAX_LEVEL; i++) array[i] = NULL;
  for (i = MAX_LEVEL - 1; i>=0; i--) {                  //For each level
    if (heads[i]!=NULL){                                //If the i-level is not NULL
        temp2 = heads[i];
        prev = heads[i];
        if (strcmp(heads[i]->item,item) == 0) prev = heads[i-1];  //If the item is t=in the first place of the node its previous the first node at the level under it
        while (temp2!=NULL) {                //Traverse
          if (strcmp(temp2->item,item) == 0){                               //If we find the item
            array[i] = temp2;                                     //Save the address
            prev2[i] = prev;                                      //Save the previous
            found = 1;
            break;                                                //No need to check the other level because we have the address of the node in the highest level. So we can use down pointer
          }
          if (strcmp(temp2->item,item) == 1) {                      //If the current item is bigger than our item it means theat there is no id = item in this level so we go to the level under it
            temp2 = prev->down;
            break;
          }
          prev = temp2;
          temp2 = temp2->next;
        }
        if (found == 1) break;
      }
  }

  if (found == 1) {                                           //If we found the item
      SkipListptr temp4 = array[i],temp5 = array[i];        //array[i] has the address of the node to be deleted in the highest level
      int k = i;
      while (temp4!=NULL) {                               //Traverse
        if (strcmp(array[i]->item,heads[k]->item) == 0) {      //If the item is the first item in one level
          temp5 = heads[k];
          heads[k] = heads[k]->next;
          prev = heads[k];
          free(temp5);                                    //Delete it properly
          temp4 = temp4->down;
          array[i] = array[i]->down;                    //Go down
        }
        else {
          temp5 = temp4;
          prev2[i]->next = temp5->next;
          free(temp5);                            //Delete it properly
          temp4 = temp4->down;
          prev2[i] = prev2[i]->down;              //Go down
          array[i] = array[i]->down;
        }
        k--;
      }
  }
  return temp1;
}


int Exists_In_SkipList(SkipListptr *heads, SkipListItem item)        //This function checks if item exist in a skip list and if so gets the date
{
  SkipListptr temp2,prev;
  int i;
  for (i = MAX_LEVEL - 1; i>=0; i--) {                                      //For each level
    if (heads[i]!=NULL){                                                    //If the i-level is not NULL
        temp2 = heads[i];
        prev = heads[i];
        if (strcmp(heads[i]->item,item) == 0) prev = heads[i-1];
        while (temp2!=NULL) {
          if (strcmp(temp2->item,item) == 0)       {                  //If we find it
            return 1;
          }
          if (strcmp(temp2->item,item) == 1) {                             //We should go down
            temp2 = prev->down;
            break;
          }
          prev = temp2;
          temp2 = temp2->next;
        }
      }
  }
  return 0;
}

void SkipListPrintFirstLevel(SkipListptr *list)
{
  int i;
  SkipListptr temp;
  temp = list[0];
  while (temp!=NULL) {
    printf("%s\n", temp->item);
    temp = temp->next;
  }
  printf("\n");

}

void SkipListPrint(SkipListptr *list)
{
  int i;
  SkipListptr temp;
  for (i=MAX_LEVEL-1; i>=0; i--) {

      temp = list[i];
      while (temp!=NULL) {
        printf("%s", temp->item);
        temp = temp->next;
        if (temp!=NULL) printf("-->");
      }
      printf("\nLayer %d\n", i);
      printf("\n");
  }
}

void SkipListDestroy(SkipListptr *list)
{
  SkipListptr current = *list;
  SkipListptr next;
  while (current != NULL){
      next = current->next;	//Save the next node
      free(current->item);
      free(current);		//Delete the current node

      current = next;
  }
  *list = NULL;
}
