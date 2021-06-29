#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<pair<int, int>> adj[], int s, int d, int wt) {
    adj[s].push_back({d, wt});
}

void topologicalSort(vector<pair<int, int>> adj[], int topoSort[], int v) {

    int indegree[v];
    for(int i=0; i<v; i++)
        indegree[i] = 0;
    
    for(int i=0; i<v; i++) {
        for(auto p: adj[i]) {
            indegree[p.first]++;
        }
    }

    queue<int> q;
    for(int i=0; i<v; i++) {
        if(indegree[i] == 0)
            q.push(i);
    }

    int pos = 0;
    while (q.size()) {
        int t = q.front();
        q.pop();
        topoSort[pos++] = t;
        for(auto p: adj[t]) {
            int k = p.first;
            indegree[k]--;
            if(indegree[k] == 0)
                q.push(k);
        }
    }
}

void shortestPath(vector<pair<int, int>> adj[], int v, int dist[], int src) {

    int topoSort[v];
    topologicalSort(adj, topoSort, v);

    for(int i=0; i<v; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    for(int i=0; i<v; i++) {
        if(dist[topoSort[i]] != INT_MAX) {
            for(auto p: adj[topoSort[i]]) {
                int d = p.first;
                dist[d] = min(dist[d], p.second + dist[topoSort[i]]);
            }
        }
    }
}

int main() {

    int v = 6;
    vector<pair<int, int>> adj[v];
    addEdge(adj, 0, 1, 2);
    addEdge(adj, 0, 4, 1);
    addEdge(adj, 1, 2, 3);
    addEdge(adj, 4, 2, 2);
    addEdge(adj, 2, 3, 6);
    // addEdge(adj, 4, 5, 4);
    addEdge(adj, 5, 3, 1);

    int dist[v], source = 0;
    shortestPath(adj, v, dist, source);

    for(int i=0; i<v; i++) {
        if(dist[i] == INT_MAX)
            cout << "INF ";
        else
            cout << dist[i] << " ";
    }
    cout << "\n";

    return 0;
}