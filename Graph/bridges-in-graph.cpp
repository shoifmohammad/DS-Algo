#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int s, int d) {
    adj[s].push_back(d);
    adj[d].push_back(s);
}

void bridgeEdgesRec(vector<int> adj[], bool vis[], int parent[], int disc[], int low[], int& time, int u) {

    low[u] = time;
    disc[u] = time;
    time++;
    vis[u] = true;

    for(int v: adj[u]) {
        
        if(!vis[v]) {
            parent[v] = u;
            bridgeEdgesRec(adj, vis, parent, disc, low, time, v);

            low[u] = min(low[u], low[v]);
            if(low[v] > disc[u])
                cout << u << " — " << v << "\n";
        }
        else if(parent[u] != v) {
            low[u] = min(low[u], disc[v]);
        }
    }
}

void bridgeEdges(vector<int> adj[], int v) {

    int disc[v], low[v], parent[v];
    bool vis[v];

    for(int i=0; i<v; i++) {
        parent[i] = -1;
        vis[i] = false;
    }

    int time = 1;
    for(int i=0; i<v; i++) {
        if(!vis[i])
            bridgeEdgesRec(adj, vis, parent, disc, low, time, i);
    }
}

int main() {

    int v = 5;
    vector<int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 1);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);

    bridgeEdges(adj, v);

    return 0;
}