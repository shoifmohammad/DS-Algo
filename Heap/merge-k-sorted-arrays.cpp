#include <bits/stdc++.h>
using namespace std;

struct content {
    int val, row, col;
    content(int v, int r, int c) {
        val = v;
        row = r;
        col = c;
    }
};

struct comparator {
    bool operator()(content c1, content c2) {
        return c1.val > c2.val;
    }
};

vector<int> mergeKsortedArray(vector<vector<int>>& v) {

    priority_queue<content, vector<content>, comparator> pq;

    int n = v.size();
    vector<int> rel;
    for(int i=0; i<n; i++) {
        if(v[i].size()) {
            content t(v[i][0], i, 0);
            pq.push(t);
        }
    }
    while(!pq.empty()) {
        content t = pq.top();
        pq.pop();
        rel.push_back(t.val);
        int r = t.row, c = t.col;
        if(c+1 < v[r].size()) {
            content temp(v[r][c+1], r, c+1);
            pq.push(temp);
        }
    }

    return rel;
}

int main() {

    vector<vector<int>> v = {
                            {2, 4, 7},
                            {},
                            {1, 6, 9, 11},
                            {3, 8}
                        };

    vector<int> mergedArray = mergeKsortedArray(v);
    for(int k: mergedArray)
        cout << k << " ";
    cout << "\n";

    return 0;
}