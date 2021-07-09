#include <bits/stdc++.h>
#include "tree.h"
using namespace std;

int largestSubtreeSumUtil(TreeNode *root, int& maxSum) {

    if(!root)
        return 0;
    
    int sum = root->data + largestSubtreeSumUtil(root->left, maxSum) + largestSubtreeSumUtil(root->right, maxSum);
    maxSum = max(maxSum, sum);

    return sum;
}

int largestSubtreeSum(TreeNode *root) {

    if(!root)
        return 0;
    
    int maxSum = INT_MIN;
    largestSubtreeSumUtil(root, maxSum);

    return maxSum;
}

int main() {

    int arr[] = {2, 3, -100, -1, 4, 9, 11, 7, 1, -1, -1, 3, -1, -1, -1, -1, -1, 6, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    TreeNode *root = arrayToTree(arr, n);

    cout << largestSubtreeSum(root) << "\n";

    return 0;
}