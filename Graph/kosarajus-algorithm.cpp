#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int s, int d) {
    adj[s].push_back(d);
}

void getFinishedOrderRec(vector<int> adj[], vector<bool>& vis, int s, stack<int>& st) {

    vis[s] = true;
    for(int d: adj[s]) {
        if(!vis[d])
            getFinishedOrderRec(adj, vis, d, st);
    }
    st.push(s);
}

stack<int> getFinishedOrder(vector<int> adj[], int v) {
    
    vector<bool> vis(v, false);
    stack<int> st;

    for(int i=0; i<v; i++) {
        if(!vis[i])
            getFinishedOrderRec(adj, vis, i, st);
    }

    return st;
}

void reverseGraph(vector<int> adj[], vector<int> rev[], int v) {

    for(int i=0; i<v; i++) {
        for(int j: adj[i])
            addEdge(rev, j, i);
    }
}

void dfs(vector<int> adj[], vector<bool>& vis, int s) {

    vis[s] = true;
    cout << s << " ";
    for(int d: adj[s]) {
        if(!vis[d])
            dfs(adj, vis, d);
    }
}

void kosaraju(vector<int> adj[], int v) {

    stack<int> order = getFinishedOrder(adj, v);
    vector<int> rev[v];
    reverseGraph(adj, rev, v);

    vector<bool> vis(v, false);
    while (!order.empty()) {
        int t = order.top();
        order.pop();
        if(!vis[t]) {
            dfs(rev, vis, t);
            cout << "\n";
        }
    }
}

int main() {

    int v = 6;
    vector<int> adj[v];
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 1);
    addEdge(adj, 1, 0);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 3);
    // addEdge(adj, 4, 5);

    kosaraju(adj, v);

    return 0;
}