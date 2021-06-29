#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int s, int d) {
    adj[s].push_back(d);
}

void topologicalSort(vector<int> adj[], int v) {

    int indegree[v];
    for(int i=0; i<v; i++)
        indegree[i] = 0;
    
    for(int i=0; i<v; i++) {
        for(int k: adj[i]) {
            indegree[k]++;
        }
    }

    queue<int> q;
    for(int i=0; i<v; i++) {
        if(indegree[i] == 0)
            q.push(i);
    }

    while (q.size()) {
        int t = q.front();
        q.pop();
        cout << t << " ";
        for(int k: adj[t]) {
            indegree[k]--;
            if(indegree[k] == 0)
                q.push(k);
        }
    }

    cout << "\n";
}

int main() {

    int v = 6;
    vector<int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 3, 5);

    topologicalSort(adj, v);

    return 0;
}