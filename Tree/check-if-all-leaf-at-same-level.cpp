#include <bits/stdc++.h>
#include "tree.h"
using namespace std;

bool checkLeaves(TreeNode *root) {

    if(!root)
        return true;

    queue<TreeNode*> q;
    q.push(root);
    bool flag = false;

    while(!q.empty()) {
        if(flag)
            return false;
        int len = q.size();
        for(int i=0; i<len; i++) {
            TreeNode *temp = q.front();
            q.pop();
            if(temp->left == NULL && temp->right == NULL)
                flag = true;
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }

    return true;
}

int main() {

    int arr[] = {2, 3, 1, -1, 4, 9, 11, 7, 1, -1, -1, 3, -1, -1, -1, -1, -1, 6, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    TreeNode *root = arrayToTree(arr, n);

    if(checkLeaves(root))
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}