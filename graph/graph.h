#include "hash.h"

typedef HTItem UGItem;
typedef HTHash UGGraph;
typedef HTElement AdjList;

UGGraph UGCreate(int n);
UGGraph UGAddVertex(UGGraph graph,char *vertex,UGItem item);
void Print(UGGraph graph);
UGGraph UGRemoveVertex(UGGraph graph,char *vertex);
UGGraph UGAddEdge(UGGraph graph,char *vertex1,char *vertex2);
AdjList UGGetAdjacent(UGGraph graph,char *vertex);
void UGDestroy(UGGraph graph);
AdjList UGShortestPath(UGGraph graph,char *vertex1,char *vertex2);
char *VertexWithMinDist(HTHash dist,HTHash W,int *min);
