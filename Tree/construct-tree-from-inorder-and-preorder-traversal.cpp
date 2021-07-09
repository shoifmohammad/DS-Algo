#include <bits/stdc++.h>
#include "tree.h"
using namespace std;

TreeNode* constructTreeUtil(int in[], int pre[], int& pre_index, int start, int end) {

    if(start > end)
        return NULL;
    
    TreeNode *root = new TreeNode(pre[pre_index++]);

    int in_index;
    for(int i=start; i<=end; i++) {
        if(in[i] == root->data) {
            in_index = i;
            break;
        }
    }

    root->left = constructTreeUtil(in, pre, pre_index, start, in_index-1);
    root->right = constructTreeUtil(in, pre, pre_index, in_index+1, end);

    return root;
}

TreeNode* constructTree(int in[], int pre[], int n) {

    int pre_index = 0;
    return constructTreeUtil(in, pre, pre_index, 0, n-1);
}

int main() {

    int in[] = {3, 7, 4, 1, 2, 9, 1, 6, 3, 4, 11};
    int pre[] = {2, 3, 4, 7, 1, 1, 9, 11, 3, 6, 4};
    int n = sizeof(in)/sizeof(in[0]);

    TreeNode *root = constructTree(in, pre, n);
    inorder(root);
    cout << "\n";

    return 0;
}