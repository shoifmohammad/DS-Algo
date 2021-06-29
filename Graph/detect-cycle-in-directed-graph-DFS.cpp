#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int s, int d) {
    adj[s].push_back(d);
}

bool DFSrec(vector<int> adj[], bool visited[], bool tree[], int s) {

    visited[s] = true;
    tree[s] = true;
    for(int d: adj[s]) {
        if(!visited[d]) {
            if(DFSrec(adj, visited, tree, d))
                return true;
        }
        else if(tree[d]) {
            return true;
        }
    }

    tree[s] = false;
    return false;
}

bool hasCycle(vector<int> adj[], int v) {

    bool visited[v], tree[v];
    for(int i=0; i<v; i++) {
        tree[i] = false;
        visited[i] = false;
    }

    for(int i=0; i<v; i++) {
        if(!visited[i] && DFSrec(adj, visited, tree, i))
            return true;
    }
    return false;
}

int main() {

    int v = 4;
    vector<int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 2, 1);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);

    if(hasCycle(adj, v))
        cout << "YES";
    else
        cout << "NO";
    cout << "\n";

    return 0;
}