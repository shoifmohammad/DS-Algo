#include <bits/stdc++.h>
#include "tree.h"
using namespace std;

vector<int> leftView(TreeNode *root) {

    if(!root)
        return {};

    queue<TreeNode*> q;
    q.push(root);
    vector<int> rel;

    while(!q.empty()) {
        int len = q.size();
        for(int i=0; i<len; i++) {
            TreeNode *temp = q.front();
            q.pop();
            if(i == 0)
                rel.push_back(temp->data);
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }

    return rel;
}

int main() {

    int arr[] = {2, 3, 1, -1, 4, 9, 11, 7, 1, -1, -1, 3, -1, -1, -1, -1, -1, 6, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    TreeNode *root = arrayToTree(arr, n);

    vector<int> rel = leftView(root);
    for(int k: rel)
        cout << k << " ";
    cout << "\n";

    return 0;
}