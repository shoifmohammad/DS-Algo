#include <bits/stdc++.h>
#include "tree.h"
using namespace std;

void leftNodes(TreeNode *root, vector<int>& v) {

    if(root->left) {
        v.push_back(root->data);
        leftNodes(root->left, v);
    }
    else if(root->right) {
        v.push_back(root->data);
        leftNodes(root->right, v);
    }
}

void rightNodes(TreeNode *root, vector<int>& v) {

    if(root->right) {
        rightNodes(root->right, v);
        v.push_back(root->data);
    }
    else if(root->left) {
        rightNodes(root->left, v);
        v.push_back(root->data);
    }
}

void leafNodes(TreeNode *root, vector<int>& v) {

    bool flag = true;
    if(root->left) {
        flag = false;
        leafNodes(root->left, v);
    }
    if(root->right) {
        flag = false;
        leafNodes(root->right, v);
    }

    if(flag)
        v.push_back(root->data);
}

vector<int> boundary(TreeNode *root) {

    if(!root)
        return {};

    vector<int> rel;
    
    rel.push_back(root->data);
    if(root->left) {
        leftNodes(root->left, rel);
        leafNodes(root->left, rel);
    }
    if(root->right) {
        leafNodes(root->right, rel);
        rightNodes(root->right, rel);
    }

    return rel;
}

int main() {

    int arr[] = {2, 3, 1, -1, 4, 9, 11, 7, 1, -1, -1, 3, -1, -1, -1, -1, -1, 6, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    TreeNode *root = arrayToTree(arr, n);

    vector<int> rel = boundary(root);
    for(int k: rel)
        cout << k << " ";
    cout << "\n";

    return 0;
}