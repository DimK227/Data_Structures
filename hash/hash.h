#pragma once
#include "list.h"


typedef struct {
	listptr *hash;		//The hash table will contain lists
	int max;
}HTHash;

typedef listptr HTElement;		//Each element will be a lists
typedef ListItem HTItem;

typedef void (*FunPtr)(HTHash hash,HTItem item);	//Pointer to function

HTHash HTCreate(int max);
int HTSize(HTHash hash);
int  HTGet(HTHash hash,HTItem item, HTItem *pitem);
HTHash HTInsert(HTHash hash, HTItem item);
HTHash Rehash(HTHash hash);
HTHash HTRemove(HTHash hash, HTItem item);
void HTDestroy(HTHash hash);
void HTVisit(HTHash hash, FunPtr visit);
void VisitElement(HTHash hash, HTItem item);
int HashCode (char *key,int max);
