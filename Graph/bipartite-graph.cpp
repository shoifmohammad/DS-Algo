#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int s, int d) {
    adj[s].push_back(d);
    adj[d].push_back(s);
}

bool isBipartiteRecursion(vector<int> adj[], int color[], int src) {

    queue<int> q;
    q.push(src);
    color[src] = 1;

    while(!q.empty()) {
        
        int s = q.front();
        q.pop();
        for(int d: adj[s]) {
            if(color[d] == 0) {
                color[d] = -1*color[s];
                q.push(d);
            }
            else if(color[d] == color[s])
                return false;
        }
    }

    return true;
}

bool isBipartite(vector<int> adj[], int v) {

    int color[v];
    for(int i=0; i<v; i++)
        color[i] = 0;
    
    for(int i=0; i<v; i++) {
        if(color[i] == 0)
            if(!isBipartiteRecursion(adj, color, i))
                return false;
    }

    return true;
}

int main() {

    int v=4;
    vector<int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 0, 3);

    if(isBipartite(adj, v))
        cout << "Bipartite\n";
    else
        cout << "Not Bipartite\n";

    return 0;
}