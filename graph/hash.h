#pragma once
#include "list.h"

typedef struct {
	listptr *hash;		//The hash table will contain lists
	int max;

}HTHash;
typedef listptr HTElement;		//Each element will be a lists
typedef ListItem HTItem;


typedef void (*FunPtr)(HTHash hash,char *key,HTItem item);	//Pointer to function

HTHash HTCreate(int max);
int HTSize(HTHash hash);
int  HTGet(HTHash hash,char *key, HTItem *pitem);
HTHash HTInsert(HTHash hash,char *key, HTItem item);
HTHash Reharsh(HTHash hash);
HTHash HTRemove(HTHash hash, char *key);
void HTDestroy(HTHash hash);
void HTVisit(HTHash hash, FunPtr visit);
void VisitElement(HTHash hash, char *key, HTItem item);
int HashCode (char *key,int max);
