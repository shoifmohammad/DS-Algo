#include <bits/stdc++.h>
#include "tree.h"
using namespace std;

int traverse(TreeNode *root, int& sum) {
    
    int l = 0, r = 0, sum1 = 0, sum2 = 0;

    if(root->left)
        l = traverse(root->left, sum1);
    if(root->right)
        r = traverse(root->right, sum2);
    
    if(l == r)
        sum = root->data + max(sum1, sum2);
    else if(l > r)
        sum = root->data + sum1;
    else
        sum = root->data + sum2;
    
    return 1+max(l, r);    
}

int longestPathSum(TreeNode *root) {

    if(!root)
        return 0;
    
    int sum = 0;
    int garbage = traverse(root, sum);
    
    return sum;
}

int main() {

    int arr[] = {2, 3, 1, -1, 4, 9, 11, 7, 1, -1, -1, 3, -1, -1, -1, -1, -1, 6, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    TreeNode *root = arrayToTree(arr, n);

    cout << longestPathSum(root) << "\n";

    return 0;
}