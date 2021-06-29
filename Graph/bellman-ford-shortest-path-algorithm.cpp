#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>>& edges, int s, int d, int wt) {
    edges.push_back({s, d, wt});
}

bool bellmanFord(vector<vector<int>>& edges, vector<int>& dist, int v, int src) {

    dist[src] = 0;
    for(int iteration=0; iteration<v-1; iteration++) {
        for(vector<int> vect: edges) {
            int u = vect[0], v = vect[1], wt = vect[2];
            if(dist[u] != INT_MAX) {
                if(dist[v] > dist[u] + wt) {
                    dist[v] = dist[u] + wt;
                }
            }
        }
    }

    for(vector<int> vect: edges) {
        int u = vect[0], v = vect[1], wt = vect[2];
        if(dist[u] != INT_MAX) {
            if(dist[v] > dist[u] + wt) {
                return true;
            }
        }
    }

    return false;
}

int main() {

    int v = 4;
    vector<vector<int>> edges;
    addEdge(edges, 0, 1, 4);
    addEdge(edges, 0, 2, 8);
    addEdge(edges, 1, 2, -6);
    addEdge(edges, 3, 1, 3);
    addEdge(edges, 2, 3, 2);

    int source = 0;
    vector<int> dist(v, INT_MAX);
    if(bellmanFord(edges, dist, v, source)) {
        cout << "Negative weight cycle detected\n";
    }
    else {
        for(int i=0; i<v; i++)
            cout << dist[i] << " ";
        cout << "\n";
    }

    return 0;
}