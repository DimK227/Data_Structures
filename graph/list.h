#define MAXSIZE 30	//This is the max size of  strings
typedef struct listnode *listptr;


typedef union {
	listptr list;
	char *string;
	int integer;
}LLitem;

typedef LLitem ListItem;

struct element {
	char *key;
	ListItem item;
};

struct listnode{
        struct element info;
        listptr next;
};

listptr LstCreate();
listptr LstInsert(listptr list,char *key,ListItem item);
void LstInsertStart(listptr *list,char *key);
int LstCount(listptr list);
int LstSearch(listptr list,char *key,ListItem *pitem);
listptr LstDelete(listptr list, char *node);
void LstDestroy(listptr *list);
void LstPrint(listptr list);
