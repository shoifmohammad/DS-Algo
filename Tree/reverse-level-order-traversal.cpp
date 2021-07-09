#include <bits/stdc++.h>
#include "tree.h"
using namespace std;

void recursion(queue<TreeNode*>& q, vector<int>& rel) {
    
    if(q.empty())
        return;
        
    vector<int> v;
    TreeNode *temp;
    int len = q.size();

    for(int i=0; i<len; i++) {
        temp = q.front();
        q.pop();
        v.push_back(temp->data);
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
    
    recursion(q, rel);
    for(int k: v)
        rel.push_back(k);
}

vector<int> reverseLevelOrder(TreeNode *root) {

    if(!root)
        return {};
        
    vector<int> rel;
    queue<TreeNode*> q;
    q.push(root);
    
    recursion(q, rel);
    
    return rel;
}

int main() {

    int arr[] = {2, 3, 1, -1, 4, 9, 11, 7, 1, -1, -1, 3, -1, -1, -1, -1, -1, 6, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    TreeNode *root = arrayToTree(arr, n);

    vector<int> rel = reverseLevelOrder(root);
    for(int k: rel)
        cout << k << " ";
    cout << "\n";

    return 0;
}