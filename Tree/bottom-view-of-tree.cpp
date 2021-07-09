#include <bits/stdc++.h>
#include "tree.h"
using namespace std;

vector<int> topView(TreeNode *root) {

    if(!root)
        return {};

    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    map<int, int> mp;
    vector<int> rel;

    while (!q.empty()) {
        
        auto p = q.front();
        q.pop();
        TreeNode *temp = p.first;
        int idx = p.second;

        if(mp.find(idx) == mp.end())
            mp.insert({idx, temp->data});
        else
            mp[idx] = temp->data;

        if(temp->left)
            q.push({temp->left, idx-1});
        if(temp->right)
            q.push({temp->right, idx+1});
    }
    
    for(auto p: mp) {
        rel.push_back(p.second);
    }
    return rel;
}

int main() {

    int arr[] = {2, 3, 1, -1, 4, 9, 11, 7, 1, -1, -1, 3, -1, -1, -1, -1, -1, 6, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    TreeNode *root = arrayToTree(arr, n);

    vector<int> rel = topView(root);
    for(int k: rel)
        cout << k << " ";
    cout << "\n";

    return 0;
}