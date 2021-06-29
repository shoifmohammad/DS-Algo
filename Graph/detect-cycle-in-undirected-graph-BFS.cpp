#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int s, int d) {
    adj[s].push_back(d);
    adj[d].push_back(s);
}

bool BFSrec(vector<int> adj[], int v, bool visited[], int s) {

    int parent[v];
    for(int i=0; i<v; i++)
        parent[i] = -1;

    queue<int> q;
    q.push(s);
    visited[s] = true;

    while(q.size()) {
        int t = q.front();
        q.pop();
        for(int k: adj[t]) {
            if(!visited[k]) {
                visited[k] = true;
                parent[k] = t;
                q.push(k);
            }
            else if(parent[t] != k) {
                return true;
            }
        }
    }

    return false;
}

bool hasCycle(vector<int> adj[], int v) {

    bool visited[v];
    for(int i=0; i<v; i++)
        visited[i] = false;

    for(int i=0; i<v; i++) {
        if(!visited[i]) {
            if(BFSrec(adj, v, visited, i))
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
    // addEdge(adj, 1, 4);
    // addEdge(adj, 2, 3);

    if(hasCycle(adj, v))
        cout << "YES";
    else
        cout << "NO";
    cout << "\n";

    return 0;
}