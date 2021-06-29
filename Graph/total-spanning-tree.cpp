#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void getCofactorMatrix(vector<vector<int>>& mat, vector<vector<int>>& temp, int p, int q, int n) {

    int i=0, j=0;
    for(int r=0; r<n; r++) {
        for(int c=0; c<n; c++) {
            if(r==p || c==q)
                continue;
            temp[i][j++] = mat[r][c];
            if(j == n-1) {
                j=0;
                i++;
            }
        }
    }
}
int determinant(vector<vector<int>>& mat, int n) {

    if(n == 1)
        return mat[0][0];

    int det = 0, sign = 1;
    vector<vector<int>> temp(n-1, vector<int>(n-1));

    for(int idx=0; idx<n; idx++) {
        getCofactorMatrix(mat, temp, 0, idx, n);
        det += sign*mat[0][idx]*determinant(temp, n-1);
        sign *= -1;
    }

    return det;
}

int spanningTrees(vector<int> adj[], int v) {

    vector<vector<int>> graph(v, vector<int>(v, -1));
    for(int i=0; i<v; i++)
        graph[i][i] = adj[i].size();

    vector<vector<int>> mat(v-1, vector<int>(v-1));
    for(int i=1; i<v; i++) {
        for(int j=1; j<v; j++) {
            mat[i-1][j-1] = graph[i][j];
        }
    }

    return determinant(mat, v-1);
}

int main() {

    int v=4;
    vector<int> adj[v];
    addEdge(adj, 0, 3);
    addEdge(adj, 1, 2);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);

    cout << spanningTrees(adj, v) << "\n";

    return 0;
}