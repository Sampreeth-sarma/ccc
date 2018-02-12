#include <iostream>
#include "Graph.h"


using namespace std;

int main()
{
    Graph *g = createGraph(6);
    insertEdge(g, 0, 1);
    insertEdge(g, 0, 3);
    insertEdge(g, 2, 5);
    insertEdge(g, 3, 1);
    insertEdge(g, 3, 4);
    insertEdge(g, 4, 1);
    insertEdge(g, 5, 2);
    printGraph(g);
    return 0;
}
