#include <bits/stdc++.h>
#include "tree.h"
using namespace std;

void postorderIterative(TreeNode *root) {

    if(!root)
        return;

    stack<TreeNode*> st;
    st.push(root);
    stack<int> output;
    
    while(!st.empty()) {
        TreeNode *curr = st.top();
        st.pop();
        output.push(curr->data);

        if(curr->left)
            st.push(curr->left);
        if(curr->right)
            st.push(curr->right);
    }

    while(!output.empty()) {
        cout << output.top() << " ";
        output.pop();
    }
    cout << "\n";
}

int main() {

    int arr[] = {2, 3, 1, -1, 4, 9, 11, 7, 1, -1, -1, 3, -1, -1, -1, -1, -1, 6, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    TreeNode *root = arrayToTree(arr, n);

    postorderIterative(root);

    return 0;
}