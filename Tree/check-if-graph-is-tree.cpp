#include <bits/stdc++.h>
#include "tree.h"
using namespace std;

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool isCyclic(vector<int> adj[], bool vis[], int src, int parent) {

    vis[src] = true;

    for(int k: adj[src]) {
        if(!vis[k]) {
            if(isCyclic(adj, vis, k, src))
                return true;
        }
        else if(k != parent)
            return true;
    }

    return false;
}

bool isTree(vector<int> adj[], int v) {

    bool vis[v];
    for(int i=0; i<v; i++)
        vis[i] = false;

    if(isCyclic(adj, vis, 0, -1))
        return false;

    for(int i=0; i<v; i++) {
        if(!vis[i])
            return false;
    }

    return true;
}

int main() {

    int v = 5;
    vector<int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 3);
    addEdge(adj, 0, 2);
    addEdge(adj, 3, 4);
    // addEdge(adj, 1, 2);

    if(isTree(adj, v))
        cout << "Tree\n";
    else
        cout << "Not-Tree\n";
    
    return 0;
}