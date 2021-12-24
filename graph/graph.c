#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "graph.h"

UGGraph UGCreate(int n)		//This function creates a graph
{
	return HTCreate(n);
}

UGGraph UGAddVertex(UGGraph graph,char *vertex,UGItem item)	//This function adds a vertex in a graph
{
	graph=HTInsert(graph,vertex,item);
	return graph;
}

UGGraph UGRemoveVertex(UGGraph graph,char *vertex)	//This function removes a vertex from a graph
{
	int i;
	AdjList temp;
	UGItem item;
	item.list=NULL;
	graph=HTRemove(graph,vertex);		//At first remove the vertex
	for (i=0; i<graph.max; i++) {
		temp=graph.hash[i];		//Save the start
		while (graph.hash[i]) {
			if (LstSearch((graph.hash[i]->info).item.list,vertex,&item)==1) (graph.hash[i]->info).item.list=LstDelete((graph.hash[i]->info).item.list,vertex);	//And then remove all its edges
			graph.hash[i]=graph.hash[i]->next;
		}
		graph.hash[i]=temp;		//Do it as before in order to point at the start
	}
	return graph;

}

UGGraph UGAddEdge(UGGraph graph,char *vertex1,char *vertex2)	//This function adds an edge between 2 vertices
{
	UGItem item;
	item.list=LstCreate();
	item.list= UGGetAdjacent(graph,vertex1);			//List is the list of verices who are linked with vertex1
	LstInsertStart(&item.list,vertex2);			//Insert in it the vertex2
	graph=HTInsert(graph,vertex1,item);		//Now vertex1 is linked eith vertex2
	item.list= UGGetAdjacent(graph,vertex2);			//Now list is the list of verices who are linked with vertex2
        LstInsertStart(&item.list,vertex1);			//Insert in it the vertex1
        graph=HTInsert(graph,vertex2,item);		//Now vertex2 is linked eith vertex1
	return graph;
}

AdjList UGGetAdjacent(UGGraph graph,char *vertex)	//This function returns a list of the vertices thar are linked with vertex1
{
	UGItem item;
	item.list=LstCreate();			//Create the list
	HTGet(graph,vertex,&item);		//Get the list
	return item.list;				//Return it
}

void Print(UGGraph graph)			//This function prints a graph
{
	FunPtr visit;
	HTVisit(graph,visit);
}

void UGDestroy(UGGraph graph)			//This function destroys a graph
{
	HTDestroy(graph);
}

AdjList UGShortestPath(UGGraph graph,char *vertex1,char *vertex2)	//This function finds the shortest path between two vertices using Dijkstra algorithm
{
	int i,min,n=graph.max,alt;
	HTItem item,item1;
	HTHash W=HTCreate(n);
	HTHash dist=HTCreate(n);					//Create 3 hash tables to use in Dijkstra algorithm
	HTHash prev=HTCreate(n);
	AdjList temp,list=LstCreate(),list2=LstCreate();
	char *u,*v,*vertex;
	//For each vertex in the graph initialize the dist, prev and W
	for (i=0; i<graph.max; i++){
		temp=graph.hash[i];
		while (graph.hash[i]) {
			item1.integer=INT_MAX;			//Infinity
			dist=HTInsert(dist,((graph.hash[i])->info).key,item1);
			item1.string=NULL;
			prev=HTInsert(prev,((graph.hash[i])->info).key,item1);
			item1.integer=0;
			W=HTInsert(W,((graph.hash[i])->info).key,item1);
			graph.hash[i]=graph.hash[i]->next;
		}
		graph.hash[i]=temp;
	}
	//The hash tables were initialized
	dist=HTInsert(dist,vertex1,item1);	//Put in the source-vertex aka vertex1 as a distance 0
	while(1) {
		u=VertexWithMinDist(dist,W,&min);	//Take the vertex with minimum dist
		if (min==INT_MAX) return NULL;		//If the minimum distance is Infinity  there is no path
		item1.integer=1;
		W=HTInsert(W,u,item1);			//Insert 1 in W[u]
		if (strcmp(u,vertex2)==0) break;	//If u is the destination-vertex aka vertex 2 break the loop as we have the path
		list=UGGetAdjacent(graph,u);		//Get the vertcises that are linked with with u
		while (list!=NULL) {
			v=(list->info).key;
			HTGet(W,v,&item1);
			if (item1.integer==1) {
				list=list->next;
				continue;
			}
								//Implement the Dijkstra algorithm
			HTGet(dist,u,&item1);
			alt=item1.integer + 1;
			HTGet(dist,v,&item1);
			if (alt < item1.integer) {
				item1.integer=alt;
				dist=HTInsert(dist,v,item1);
				item1.string=u;
				prev=HTInsert(prev,v,item1);
			}
			list=list->next;
		}
	}
	vertex=vertex2;
	LstInsertStart(&list2,vertex);
	while(strcmp(vertex,vertex1)!=0) {
		HTGet(prev,vertex,&item);
		LstInsertStart(&list2,item.string);		//Now just put the elemnts in a list
		vertex=item.string;
	}
	return list2;
}


char *VertexWithMinDist(HTHash dist,HTHash W,int *min)		//This function returns the vertex with minimum dist[vertex], among those with W[vertex] = 0
{
	char *vertex;
	int i;
	*min=INT_MAX;			//Infinity
	HTItem item1,item2;
	AdjList temp;
	for (i=0; i<dist.max; i++) {
		temp=dist.hash[i];			//Save
		while(dist.hash[i]) {
			HTGet(dist,((dist.hash[i])->info).key,&item1);
			HTGet(W,((dist.hash[i])->info).key,&item2);
			if (item1.integer<*min && item2.integer==0 ) {		//If dist[vertex] is less than the current min and it W[vertex]=0
				*min=item1.integer;				//Change the min
				vertex=((dist.hash[i])->info).key;		//Vertex has now the vertex with the minimum dist
			}
			dist.hash[i]= dist.hash[i]->next;
		}
		 dist.hash[i]=temp;		//Fix the pointers
	}
	return vertex;
}
