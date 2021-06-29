#include <bits/stdc++.h>
using namespace std;

class Graph {
    
    private:
        int vertices;
        vector<int>* adj;
    
        void bfsHelper(vector<bool>& vis, int src) {
    
            queue<int> q;
            q.push(src);
            vis[src] = true;
            
            while(!q.empty()) {
                int s = q.front();
                cout << s << " ";
                q.pop();
                for(int d: adj[s]) {
                    if(!vis[d]) {
                        q.push(d);
                        vis[d] = true;
                    }
                }
            }
        }

        void dfsHelper(vector<bool>& vis, int s) {

            vis[s] = true;
            cout << s << " ";
            for(int d: adj[s]) {
                if(!vis[d])
                    dfsHelper(vis, d);
            }
        }

    public:
        Graph(int v) {
            vertices = v;
            adj = new vector<int> [v];
        }

        void addUndirectedEdge(int u, int v) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        void addDirectedEdge(int u, int v) {
            adj[u].push_back(v);
        }

        void printGraph() {

            for(int i=0; i<vertices; i++) {
                cout << i << " -> ";
                for(int k: adj[i])
                    cout << k << " ";
                cout << "\n";
            }
        }

        void BFS() {

            vector<bool> vis(vertices, false);
            for(int i=0; i<vertices; i++) {
                if(!vis[i])
                    bfsHelper(vis, i);
            }
            cout << "\n";
        }

        void DFS() {

            vector<bool> vis(vertices, false);
            for(int i=0; i<vertices; i++) {
                if(!vis[i])
                    dfsHelper(vis, i);
            }
            cout << "\n";
        }
};