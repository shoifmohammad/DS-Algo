#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>>& graph, int s, int d, int wt) {
    graph[s][d] = wt;
    graph[d][s] = wt;
}

int primsMST(vector<vector<int>>& graph, int v) {

    bool MSTset[v];
    int key[v];
    for(int i=0; i<v; i++) {
        MSTset[i] = false;
        key[i] = INT_MAX;
    }
    key[0] = 0;

    int rel = 0;
    for(int iteration=0; iteration<v; iteration++) {
        
        int u = -1;
        for(int i=0; i<v; i++) {
            if(!MSTset[i] && (u == -1 || key[i] < key[u]))
                u = i;
        }

        MSTset[u] = true;
        rel += key[u];
        for(int i=0; i<v; i++) {
            if(!MSTset[i] && graph[u][i])
                key[i] = min(key[i], graph[u][i]);
        }
    }

    return rel; 
}

int main() {

    int v = 5;
    vector<vector<int>> graph(v, vector<int>(v, 0));
    addEdge(graph, 0, 1, 2);
    addEdge(graph, 1, 2, 3);
    addEdge(graph, 0, 3, 6);
    addEdge(graph, 1, 3, 8);
    addEdge(graph, 1, 4, 5);
    addEdge(graph, 2, 4, 7);

    cout << primsMST(graph, v) << "\n";

    return 0;
}