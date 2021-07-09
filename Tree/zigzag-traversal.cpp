#include <bits/stdc++.h>
#include "tree.h"
using namespace std;

vector<int> zigzagTraversal(TreeNode *root) {

    if(!root)
        return {};

    deque<TreeNode*> dq;
    dq.push_front(root);
    vector<int> rel;

    int level = 0;
    TreeNode *temp;
    while(!dq.empty()) {
        int len = dq.size();
        if(level == 0) {
            for(int i=0; i<len; i++) {
                temp = dq.front();
                dq.pop_front();
                rel.push_back(temp->data);
                if(temp->left)
                    dq.push_back(temp->left);
                if(temp->right)
                    dq.push_back(temp->right);
            }
        }
        else {
            for(int i=0; i<len; i++) {
                temp = dq.back();
                dq.pop_back();
                rel.push_back(temp->data);
                if(temp->right)
                    dq.push_front(temp->right);
                if(temp->left)
                    dq.push_front(temp->left);
            }
        }
        level = 1-level;
    }

    return rel;
}

int main() {

    int arr[] = {2, 3, 1, -1, 4, 9, 11, 7, 1, -1, -1, 3, -1, -1, -1, -1, -1, 6, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    TreeNode *root = arrayToTree(arr, n);

    vector<int> rel = zigzagTraversal(root);
    for(int k: rel)
        cout << k << " ";
    cout << "\n";

    return 0;
}