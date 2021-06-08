#include <bits/stdc++.h>
using namespace std;

struct HeapNode {
    int val;
    int row;
    int col;
    HeapNode(int v, int r, int c) {
        val = v;
        row = r;
        col = c;
    }
};

struct compare{
    bool operator()(HeapNode a, HeapNode b) {
        return a.val > b.val;
    }
};

pair<int,int> findSmallestRange(vector<vector<int>>& arr) {

    int range = INT_MAX, mn = INT_MAX, mx = INT_MIN, beg, end;
    priority_queue<HeapNode, vector<HeapNode>, compare> pq;
    
    int k = arr.size();
    for(int i=0; i<k; i++) {
        if(arr[i].size()) {
            HeapNode node(arr[i][0], i, 0);
            mx = max(mx, arr[i][0]);
            pq.push(node);
        }
    }
    
    while(true) {
        HeapNode temp = pq.top();
        pq.pop();
        
        mn = temp.val;
        if(mx-mn < range) {
            range = mx-mn;
            beg = mn;
            end = mx;
        }
        
        int r = temp.row, c = temp.col;
        if(c+1 < arr[r].size()) {
            temp.val = arr[r][c+1];
            temp.col = c+1;
            mx = max(mx, temp.val);
            pq.push(temp);
        }
        else {
            break;
        }
    }
    
    return {beg, end};
}

int main() {

    vector<vector<int>> v = {
                            {1, 3, 5, 7, 9},
                            {0, 2, 4},
                            {2, 3, 5, 7, 11},
                            {3, 5, 8, 23}
                        };

    pair<int, int> limit = findSmallestRange(v);
    cout << "[" << limit.first << ", " << limit.second << "]\n";

    return 0;
}