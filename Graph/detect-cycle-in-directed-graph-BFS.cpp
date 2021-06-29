#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int s, int d) {
    adj[s].push_back(d);
}

bool hasCycle(vector<int> adj[], int v) {

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

    int count = 0;
    while (q.size()) {
        int t = q.front();
        q.pop();
        count++;
        for(int k: adj[t]) {
            indegree[k]--;
            if(indegree[k] == 0)
                q.push(k);
        }
    }

    return count != v;
}

int main() {

    int v = 6;
    vector<int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 3, 0);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 3, 5);

    if(hasCycle(adj, v))
        cout << "YES";
    else
        cout << "NO";
    cout << "\n";

    return 0;
}