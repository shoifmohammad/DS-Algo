#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int s, int d) {
    adj[s].push_back(d);
}

void dfsREC(vector<int> adj[], bool vis[], bool tree[], int disc[], int low[], int& time, stack<int>& st, int u) {

    low[u] = time;
    disc[u] = time;
    time++;
    vis[u] = true;
    tree[u] = true;
    st.push(u);

    for(int v: adj[u]) {
        if(!vis[v]) {
            dfsREC(adj, vis, tree, disc, low, time, st, v);
            low[u] = min(low[u], low[v]);
        }
        else if(tree[v]) {
            low[u] = min(low[u], disc[v]);
        }
    }

    if(low[u] == disc[u]) {
        while(st.top() != u) {
            cout << st.top() << " ";
            st.pop();
        }
        cout << st.top() << "\n";
        st.pop();
    }

    tree[u] = false;
}

void tarjan(vector<int> adj[], int v) {

    bool vis[v], tree[v];
    int disc[v], low[v];
    stack<int> st;
    int time = 1;

    for(int i=0; i<v; i++) {
        vis[i] = false;
        tree[i] = false;
    }

    for(int i=0; i<v; i++) {
        if(!vis[i])
            dfsREC(adj, vis, tree, disc, low, time, st, i);
    }
}

int main() {

    int v = 7;
    vector<int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 1);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 2);
    addEdge(adj, 5, 6);
    addEdge(adj, 6, 5);

    tarjan(adj, v);

    return 0;
}