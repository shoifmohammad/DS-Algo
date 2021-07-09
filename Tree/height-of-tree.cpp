#include <bits/stdc++.h>
#include "tree.h"
using namespace std;

int getHeight(TreeNode *root) {

    if(!root)
        return 0;
    return 1 + max(getHeight(root->left), getHeight(root->right));
}

int main() {

    int arr[] = {2, 3, 1, -1, 4, 9, 11, 7, 1, -1, -1, 3, -1, -1, -1, -1, -1, 6, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    TreeNode *root = arrayToTree(arr, n);

    cout << getHeight(root) << "\n";

    return 0;
}