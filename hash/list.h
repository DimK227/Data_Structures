typedef struct listnode *listptr;

typedef char * ListItem;

struct listnode{
        ListItem item;
        listptr next;
};



listptr LstCreate();
listptr LstInsert(listptr list,ListItem item);
listptr LstInsertAtStart(listptr list, ListItem item);
int LstCount(listptr list);
int LstSearch(listptr list,char *key,ListItem *pitem);
listptr LstDelete(listptr list, char *node);
void LstPrint(listptr list);
void LstDestroy(listptr *list);
