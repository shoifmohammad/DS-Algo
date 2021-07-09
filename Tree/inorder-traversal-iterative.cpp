#include <bits/stdc++.h>
#include "tree.h"
using namespace std;

void inorderIterative(TreeNode *root) {

    if(!root)
        return;

    stack<TreeNode*> st;
    TreeNode *curr = root;
    while(!st.empty() || curr) {
        if(curr) {
            st.push(curr);
            curr = curr->left;
        }
        else {
            curr = st.top();
            st.pop();
            cout << curr->data << " ";
            curr = curr->right;
        }
    }
    cout << "\n";
}

int main() {

    int arr[] = {2, 3, 1, -1, 4, 9, 11, 7, 1, -1, -1, 3, -1, -1, -1, -1, -1, 6, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    TreeNode *root = arrayToTree(arr, n);

    inorderIterative(root);

    return 0;
}