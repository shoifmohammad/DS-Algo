#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int s, int d) {
    adj[s].push_back(d);
    adj[d].push_back(s);
}

bool DFSrec(vector<int> adj[], int s, bool visited[], int parent) {

    visited[s] = true;
    for(int d: adj[s]) {
        if(!visited[d]) {
            if(DFSrec(adj, d, visited, s))
                return true;
        }
        else if(d != parent)
            return true;
    }

    return false;
}

bool hasCycle(vector<int> adj[], int v) {

    bool visited[v];
    for(int i=0; i<v; i++)
        visited[i] = false;

    for(int i=0; i<v; i++) {
        if(!visited[i]) {
            if(DFSrec(adj, i, visited, -1))
                return true;
        }
    }

    return false;
}

int main() {

    int v = 6;
    vector<int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 5);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);

    if(hasCycle(adj, v))
        cout << "YES";
    else
        cout << "NO";
    cout << "\n";

    return 0;
}