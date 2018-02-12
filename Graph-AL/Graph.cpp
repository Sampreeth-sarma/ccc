#include "Graph.h"
#include<stdlib.h>
#include <stdio.h>

Graph* createGraph(int nv)
{
    int i;
    Graph* g=(Graph*)malloc(sizeof(Graph));
    g->nv=nv;
    g->ne=0;
    g->adjList=(LLNode**)malloc(sizeof(LLNode*)*nv);
    for(i=0; i<nv; i++)
        g->adjList[i]=NULL;
    return g;
}
void insertEdge(Graph* g, int s, int d){
    g->adjList[s]=insertInBegin(g->adjList[s],d);

}

void printGraph(Graph* g)
{
    for(int i=0;i<g->nv;i++){
        printf("%d : ", i);
        traverse(g->adjList[i]);
        printf("\n");
    }
}
