#include <bits/stdc++.h>
#include "tree.h"
using namespace std;

int getHeight(TreeNode *root) {

    int l = 0, r = 0;
    if(root->left)
        l = getHeight(root->left);
    if(l == -1)
        return -1;
    if(root->right)
        r = getHeight(root->right);
    if(r == -1)
        return -1;

    if(abs(l-r) > 1)
        return -1;

    return 1 + max(l, r);
}

bool isBalanced(TreeNode *root) {

    if(!root)
        return true;

    if(getHeight(root) != -1)
        return true;
    return false;
}

int main() {

    int arr[] = {2, 3, 1, -1, 4, 9, 11, 7, 1, -1, -1, 3, -1, -1, -1, -1, -1, 6, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    TreeNode *root = arrayToTree(arr, n);

    if(isBalanced(root))
        cout << "Balanced\n";
    else
        cout << "Not-Balanced\n";

    return 0;
}