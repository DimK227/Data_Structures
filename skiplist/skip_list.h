#pragma once


typedef struct skiplistnode *SkipListptr;
typedef char *SkipListItem;
#define MAX_LEVEL 13

struct skiplistnode{
    SkipListItem item;
    SkipListptr next;
    SkipListptr down;
};


typedef struct {
  SkipListptr *heads;
}skiplist;

skiplist *SkipLstCreate();
SkipListptr *SkipLstInsert(SkipListptr *heads, SkipListItem item);
SkipListptr *SkipLstDelete(SkipListptr *heads, SkipListItem item);
int Exists_In_SkipList(SkipListptr *heads, SkipListItem item);
void SkipListDestroy(SkipListptr *list);
void SkipListPrintFirstLevel(SkipListptr *list);
void SkipListPrint(SkipListptr *list);
