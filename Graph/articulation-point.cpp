#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int s, int d) {
    adj[s].push_back(d);
    adj[d].push_back(s);
}

void articulationPointsRec(vector<int> adj[], bool vis[], bool points[], int parent[], int disc[], int low[], int& time, int u) {

    int children = 0;
    low[u] = time;
    disc[u] = time;
    time++;
    vis[u] = true;

    for(int v: adj[u]) {
        
        if(!vis[v]) {
            children++;
            parent[v] = u;
            articulationPointsRec(adj, vis, points, parent, disc, low, time, v);

            low[u] = min(low[u], low[v]);
            if(parent[u] != -1 && low[v] >= disc[u])
                points[u] = true;
        }
        else if(parent[u] != v) {
            low[u] = min(low[u], disc[v]);
        }
    }

    if(parent[u] == -1 && children>1)
        points[u] = true;
}

void articulationPoints(vector<int> adj[], int v) {

    int disc[v], low[v], parent[v];
    bool vis[v], points[v];

    for(int i=0; i<v; i++) {
        parent[i] = -1;
        vis[i] = false;
        points[i] = false;
    }

    int time = 1;
    for(int i=0; i<v; i++) {
        if(!vis[i])
            articulationPointsRec(adj, vis, points, parent, disc, low, time, i);
    }

    for(int i=0; i<v; i++) {
        if(points[i])
            cout << i << " ";
    }
    cout << "\n";
}

int main() {

    int v = 5;
    vector<int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 1);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);

    articulationPoints(adj, v);

    return 0;
}