#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<pair<int, int>> adj[], int s, int d, int wt) {
    adj[s].push_back({d, wt});
    adj[d].push_back({s, wt});
}

struct Node {
    
    int value;
    int index;

    Node(int val, int idx) {
        value = val;
        index = idx;
    }

    bool operator<(const Node& node) const{
        if(this->value == node.value)
            return this->index < node.index;
        return this->value < node.value;
    }
};

void dijkstraPath(vector<pair<int, int>> adj[], int v, vector<int>& dist, int src) {

    vector<bool> explored(v, false);
    set<Node> st;

    dist[src] = 0;
    for(int i=0; i<v; i++) {
        if(i != src)
            st.insert(Node(INT_MAX, i));
    }
    st.insert(Node(0, src));

    for(int i=0; i<v; i++) {
        
        auto it = st.begin();
        Node temp = *it;
        st.erase(it);
        
        int idx = temp.index;
        explored[idx] = true;

        for(pair<int, int> p: adj[idx]) {
            if(!explored[p.first] && p.second+dist[idx] < dist[p.first]) {
                it = st.find(Node(dist[p.first], p.first));
                Node t = *it;
                st.erase(it);
                dist[p.first] = p.second+dist[idx];
                st.insert(Node(dist[p.first], p.first));
            }
        }
    }
}

int main() {

    int v = 5;
    vector<pair<int, int>> adj[v];
    addEdge(adj, 0, 1, 2);
    addEdge(adj, 1, 2, 3);
    addEdge(adj, 0, 3, 6);
    addEdge(adj, 1, 3, 8);
    addEdge(adj, 1, 4, 1);
    addEdge(adj, 2, 4, 1);

    int source = 2;
    vector<int> dist(v, INT_MAX);
    dijkstraPath(adj, v, dist, source);
    
    for(int i=0; i<v; i++)
        cout << dist[i] << " ";
    cout << "\n";

    return 0;
}