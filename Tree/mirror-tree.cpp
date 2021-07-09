#include <bits/stdc++.h>
#include "tree.h"
using namespace std;

void mirror(TreeNode* root) {
    
    if(!root)
        return;
        
    mirror(root->left);
    mirror(root->right);
    
    TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;
}

int main() {

    int arr[] = {2, 3, 1, -1, 4, 9, 11, 7, 1, -1, -1, 3, -1, -1, -1, -1, -1, 6, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    TreeNode *root = arrayToTree(arr, n);

    mirror(root);
    inorder(root);

    return 0;
}