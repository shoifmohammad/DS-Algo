#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int s, int d) {
    adj[s].push_back(d);
}

void DFS(vector<int> adj[], bool visited[], int s, stack<int>& st) {

    visited[s] = true;
    for(int d: adj[s]) {
        if(!visited[d])
            DFS(adj, visited, d, st);
    }

    st.push(s);
}

void topologicalSort(vector<int> adj[], int v) {

    stack<int> st;
    bool visited[v];
    for(int i=0; i<v; i++)
        visited[i] = false;

    for(int i=0; i<v; i++) {
        if(!visited[i])
            DFS(adj, visited, i, st);
    }

    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
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