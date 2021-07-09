#include <bits/stdc++.h>
#include "tree.h"
using namespace std;

bool find(TreeNode *root, int val) {

    if(!root)
        return false;
    
    if(root->data == val)
        return true;
    if(find(root->left, val))
        return true;
    if(find(root->right, val))
        return true;

    return false;
}

TreeNode* lcaUtil(TreeNode* root, int val1, int val2, bool& vis1, bool& vis2) {

    if(!root)
        return root;
    if(root->data == val1) {
        vis1 = true;
        return root;
    }
    if(root->data == val2) {
        vis2 = true;
        return root;
    }

    TreeNode *left = lcaUtil(root->left, val1, val2, vis1, vis2);
    TreeNode *right = lcaUtil(root->right, val1, val2, vis1, vis2);
    
    if(!left && !right)
        return NULL;
    if(left && right)
        return root;
    if(left)
        return left;
    return right;
}

TreeNode* lca(TreeNode *root, int val1, int val2) {

    bool vis1 = false, vis2 = false;
    
    TreeNode *rel = lcaUtil(root, val1, val2, vis1, vis2);

    if((vis1 && vis2) || (vis1 && find(root, val2)) || (vis2 && find(root, val1)))
        return rel;
    return NULL;
}

int main() {

    int arr[] = {2, 3, 10, -1, 4, 9, 11, 7, 1, -1, -1, 8, -1, -1, -1, -1, -1, 6, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    TreeNode *root = arrayToTree(arr, n);

    TreeNode *rel = lca(root, 9, 16);
    if(rel)
        cout << rel->data << "\n";
    else
        cout << "Node(s) Not Present\n";

    return 0;
}