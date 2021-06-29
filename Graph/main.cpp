#include <bits/stdc++.h>
#include "graph.h"
using namespace std;

int main() {

    Graph graph(7);
    
    graph.addUndirectedEdge(0, 5);
    graph.addUndirectedEdge(0, 2);
    graph.addUndirectedEdge(1, 5);
    graph.addUndirectedEdge(3, 5);
    graph.addUndirectedEdge(5, 6);
    graph.addUndirectedEdge(3, 4);
    graph.addUndirectedEdge(4, 6);

    graph.printGraph();
    graph.BFS();
    graph.DFS();

    return 0;
}