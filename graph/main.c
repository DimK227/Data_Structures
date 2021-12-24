#include <stdio.h>
#include <string.h>
#include "graph.h"




int main()
{
	UGGraph graph;
	UGItem item;
	AdjList list;
	char *vertex,*vertex1,*vertex2;
	graph=UGCreate(20);
	item.list=NULL;
	graph=UGAddVertex(graph,"Athina",item);
	graph=UGAddVertex(graph,"Thessaloniki",item);
	graph=UGAddVertex(graph,"Patra",item);
	graph=UGAddEdge(graph,"Athina","Thessaloniki");
	graph=UGAddEdge(graph,"Athina","Patra");
	graph=UGAddEdge(graph,"Thessaloniki","Patra");

	graph=UGAddVertex(graph,"Hraklio",item);
        graph=UGAddVertex(graph,"Larisa",item);
        graph=UGAddVertex(graph,"Volos",item);
	graph=UGAddEdge(graph,"Hraklio","Larisa");
	graph=UGAddEdge(graph,"Hraklio","Volos");
	graph=UGAddEdge(graph,"Volos","Larisa");
								//Inserts vertices and their edges
	graph=UGAddVertex(graph,"Ioannina",item);
	graph=UGAddVertex(graph,"Trikala",item);
	graph=UGAddVertex(graph,"Xalkida",item);
	graph=UGAddEdge(graph,"Ioannina","Trikala");
	graph=UGAddEdge(graph,"Ioannina","Xalkida");
	graph=UGAddEdge(graph,"Trikala","Xalkida");

	graph=UGAddEdge(graph,"Thessaloniki","Larisa");
	graph=UGAddEdge(graph,"Hraklio","Patra");
	graph=UGAddEdge(graph,"Xalkida","Volos");
        graph=UGAddEdge(graph,"Athina","Ioannina");

	graph=UGAddVertex(graph,"Serres",item);

	Print(graph);					//Print the graph
	vertex="Patra";
	printf("\n\nThe adjacent list of %s is ",vertex); LstPrint(UGGetAdjacent(graph,vertex));	//The vertices thar are linked with vertex are....

	vertex1="Athina";
	vertex2="Serres";
        list=UGShortestPath(graph,vertex1,vertex2);							//Get the shortest path from vertex1 to vertex2
	if (list!=NULL) {printf("The shortest path from %s to %s is ",vertex1,vertex2); LstPrint(list);}
	else printf("\n\nThere is no path from %s to %s\n",vertex1,vertex2);

	vertex1="Athina";
        vertex2="Volos";
        list=UGShortestPath(graph,vertex1,vertex2);							//Get the shortest path from vertex1 to vertex2
        if (list!=NULL) {printf("The shortest path from %s to %s is ",vertex1,vertex2); LstPrint(list);}
        else printf("\n\nThere is no path from %s to %s\n",vertex1,vertex2);

	vertex="Athina";
	graph=UGRemoveVertex(graph,vertex);			//Remove
	printf("\n\nAfter the removal of %s graph is\n\n",vertex); Print(graph);

	vertex1="Athina";
        vertex2="Volos";
	list=UGShortestPath(graph,vertex1,vertex2);								//Get the shortest path from vertex1 to vertex2
        if (list!=NULL) {printf("The shortest path from %s to %s is ",vertex1,vertex2); LstPrint(list);}
        else printf("\n\nThere is no path from %s to %s\n",vertex1,vertex2);

	vertex1="Larisa";
        vertex2="Ioannina";
        list=UGShortestPath(graph,vertex1,vertex2);								//Get the shortest path from vertex1 to vertex2
        if (list!=NULL) {printf("The shortest path from %s to %s is ",vertex1,vertex2); LstPrint(list);}
        else printf("\n\nThere is no path from %s to %s\n",vertex1,vertex2);

	UGDestroy(graph);
}
