#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
#include "LLNode.h"

typedef struct g
{
    int nv,ne;
    LLNode **adjList;
}Graph;

Graph* createGraph(int);
void insertEdge(Graph* g, int s, int d);
void printGraph(Graph* g);

#endif // GRAPH_H_INCLUDED
