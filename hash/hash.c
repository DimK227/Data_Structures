#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

//SEPERATE CHAINING IMPLEMENTATION


HTHash HTCreate(int max)		//This  function creates a hash table
{
	HTHash table;
	int i;
	table.hash=malloc(sizeof(HTElement)*max);		//Create the array
	table.max=max;
	for (i=0; i<max; i++) table.hash[i]=LstCreate();	//Create the empty lists
	return table;
}


int HTSize(HTHash hash)			//This function counts the elements of a hash table
{
	int i,cnt=0;
	for (i=0; i<hash.max; i++) {
		cnt=cnt+LstCount(hash.hash[i]);	//Count the nodes of every element-list
	}
	return cnt;
}

int HTGet(HTHash hash,HTItem item, HTItem *pitem)		//This function checks if a key exists in a hash table and if so  it copies the item to pitem
{
	int index=HashCode(item,hash.max);			//Hash the key in order to find the index
	return LstSearch(hash.hash[index],item,pitem);	//Check if it exists in the list
}

HTHash HTInsert(HTHash hash, HTItem item)	//This function inserts a key with its item in a hash table
{
	float LoadFactor = 0.0;
	int index=HashCode(item,hash.max);			//Hash the key in order to find th true index
	hash.hash[index]=LstInsert(hash.hash[index],item);	//Insert the key in the list
	LoadFactor = (1.0 * HTSize(hash))/hash.max;		//Compute the load factor
	if (LoadFactor > 0.75) {			//See if the hash table must be reharshed
		printf("Going to reharsh\n");
		hash = Rehash(hash);			//Reharsh
	}
	return hash;
}

HTHash Rehash(HTHash hash)
{
	int i;
	HTHash newhash;
	newhash=HTCreate(2*hash.max);		//Create the new hash table
	for (i=0; i<hash.max; i++) {
		while(hash.hash[i]) {		//While the element of the array(the list) is not NULL
			newhash=HTInsert(newhash,(hash.hash[i])->item);	//Copy the elemnents from the old hash table to the new one
			hash.hash[i]=(hash.hash[i])->next;		//Go to the next node of the list
		}
	}
	return newhash;
}

HTHash HTRemove(HTHash hash, HTItem item)		//This function deletes an element of a hash table
{
	int index=HashCode(item,hash.max);		//Hash the key in order to find the true index
	hash.hash[index]=LstDelete(hash.hash[index],item);		//Delete it
	return hash;

}

void HTVisit(HTHash hash, FunPtr visit)	//This function visits a hash table
{
	printf("Let's visit our hash table\n");
	int i;
	visit=&VisitElement;
	HTElement temp;
	for (i=0; i<hash.max; i++) {
		temp=hash.hash[i];		//Save the head of the list
		while (hash.hash[i]) {
			visit(hash,hash.hash[i]->item);	//Visit the node
			hash.hash[i]=hash.hash[i]->next;	//Go to the next node
		}
		hash.hash[i]=temp;		//Now hash[i] points again in the had of the list
	}
}

void VisitElement(HTHash hash, HTItem item)	//This function visits so as to print  an element of a hash table
{
	printf("%s\n",item);	//Print it
}

void HTDestroy(HTHash hash)		//This function destroys a hash table by freeing all the memory
{
	int i;
	for (i=0; i<hash.max; i++) {
		LstDestroy(&(hash.hash[i]));	//Free all the lists
	}
	free(hash.hash);		//Free the array
}



int HashCode (char *key,int max)		//This function hashes a key and returns an array's index
{
	int h=0, a=33;
  	for (; *key!='\0'; key++) h=(a*h + *key) % max;
  	return h;
}
