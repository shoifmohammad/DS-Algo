
//  Here code is implemented assuming heaps as max heap.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

int totalNodes(TreeNode* root) {
    
    if(!root)
        return 0;
    
    return 1+totalNodes(root->left)+totalNodes(root->right);
}

bool checkComplete(TreeNode* root, int idx, int total_nodes) {
    
    if(!root)
        return true;
    
    if(idx >= total_nodes)
        return false;
    
    return checkComplete(root->left, 2*idx+1, total_nodes) && checkComplete(root->right, 2*idx+2, total_nodes);
}

bool checkHeap(TreeNode* root) {

    if(!root->left && !root->right)
        return true;

    if(!root->right) {
        return root->val >= root->left->val;
    }
    else {
        if(root->val < root->left->val)
            return false;
        if(root->val < root->right->val)
            return false;
        return checkHeap(root->left) && checkHeap(root->right);
    }
}

bool isHeap(TreeNode* root) {

    if(!root)
        return true;
    int total_nodes = totalNodes(root);
    return checkComplete(root, 0, total_nodes) && checkHeap(root);
}

int main() {

    TreeNode *root = new TreeNode(6);
    
    root->left = new TreeNode(4);
    root->right = new TreeNode(2);                              /*              6             */
                                                                /*            /   \           */
    root->left->left = new TreeNode(3);                         /*           4     2          */
    root->left->right = new TreeNode(0);                        /*          / \   / \         */
                                                                /*         3   0 1  -1        */
    root->right->left = new TreeNode(1);                        /*        /                   */
    root->right->right = new TreeNode(-1);                      /*       -2                   */

    root->left->left->left = new TreeNode(-2);

    if(isHeap(root))
        cout << "Heap";
    else
        cout << "Not Heap";
    cout << "\n";

    return 0;
}