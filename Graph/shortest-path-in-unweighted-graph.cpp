#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int s, int d) {
    adj[s].push_back(d);
    adj[d].push_back(s);
}

void shortestPaths(vector<int> adj[], int v, int dist[], int src) {

    bool visited[v];
    for(int i=0; i<v; i++) {
        visited[i] = false;
        dist[i] = INT_MAX;
    }

    queue<int> q;
    q.push(src);
    visited[src] = true;
    dist[src] = 0;
    
    while(q.size()) {
        int t = q.front();
        q.pop();
        for(int k: adj[t]) {
            if(!visited[k]) {
                dist[k] = dist[t]+1;
                visited[k] = true;
                q.push(k);
            }
        }
    }
}

int main() {

    int v = 6;
    vector<int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 5);
    addEdge(adj, 1, 4);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);
    addEdge(adj, 5, 4);
    addEdge(adj, 5, 3);

    int dist[v];
    int source = 0;
    shortestPaths(adj, v, dist, source);

    for(int i=0; i<v; i++)
        cout << dist[i] << " ";
    cout << "\n";

    return 0;
}