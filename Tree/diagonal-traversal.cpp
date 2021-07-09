#include <bits/stdc++.h>
#include "tree.h"
using namespace std;

vector<int> diagonalTraversal(TreeNode *root) {

    if(!root)
        return {};

    queue<TreeNode*> q;
    TreeNode *curr = root, *temp;
    while(curr) {
        q.push(curr);
        curr = curr->right;
    }
    
    vector<int> rel;
    while(!q.empty()) {
        curr = q.front();
        rel.push_back(curr->data);
        q.pop();
        temp = curr->left;
        while(temp) {
            q.push(temp);
            temp = temp->right;
        }
    }
    
    return rel;
}

int main() {

    int arr[] = {2, 3, 1, -1, 4, 9, 11, 7, 1, -1, -1, 3, -1, -1, -1, -1, -1, 6, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    TreeNode *root = arrayToTree(arr, n);

    vector<int> rel = diagonalTraversal(root);
    for(int k: rel)
        cout << k << " ";
    cout << "\n";

    return 0;
}