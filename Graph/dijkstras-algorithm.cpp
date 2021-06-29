#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>>& graph, int s, int d, int wt) {
    graph[s][d] = wt;
    graph[d][s] = wt;
}

void dijkstraPath(vector<vector<int>>& graph, int v, int dist[], int src) {

    bool finalized[v];
    for(int i=0; i<v; i++) {
        finalized[i] = false;
        dist[i] = INT_MAX;
    }
    dist[src] = 0;

    for(int iteration=0; iteration<v-1; iteration++) {
        
        int u = -1;
        for(int i=0; i<v; i++) {
            if(!finalized[i] && (u == -1 || dist[i] < dist[u]))
                u = i;
        }

        finalized[u] = true;
        for(int i=0; i<v; i++) {
            if(!finalized[i] && graph[u][i])
                dist[i] = min(dist[i], dist[u]+graph[u][i]);
        }
    }
}

int main() {

    int v = 5;
    vector<vector<int>> graph(v, vector<int>(v, 0));
    addEdge(graph, 0, 1, 2);
    addEdge(graph, 1, 2, 3);
    addEdge(graph, 0, 3, 6);
    addEdge(graph, 1, 3, 8);
    addEdge(graph, 1, 4, 1);
    addEdge(graph, 2, 4, 1);

    int dist[v];
    int source = 2;
    dijkstraPath(graph, v, dist, source);
    
    for(int i=0; i<v; i++)
        cout << dist[i] << " ";
    cout << "\n";

    return 0;
}