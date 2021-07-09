/*  
    * Assume all node values to be positive.
    * Question link: https://practice.geeksforgeeks.org/problems/sum-tree/1#
*/

#include <bits/stdc++.h>
#include "tree.h"
using namespace std;

int getSum(TreeNode *root) {
        
    if(!root->left && !root->right)
        return root->data;
        
    int l = 0, r = 0;
    if(root->left)
        l = getSum(root->left);
    if(root->right)
        r = getSum(root->right);
    
    if(l == -1 || r == -1 || l+r != root->data)
        return -1;
        
    return l+r+root->data;
}

bool isSumTree(TreeNode *root) {

    if(!root)
        return true;
        
    if(getSum(root) != -1)
        return true;
    return false;
}

int main() {

    int arr[] = {62, 16, 15, -1, 8, 4, 7, -1, 8, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    TreeNode *root = arrayToTree(arr, n);

    if(isSumTree(root))
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}