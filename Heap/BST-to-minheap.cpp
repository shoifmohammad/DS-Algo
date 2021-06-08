#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

void inorder(TreeNode* root, vector<int>& arr) {
    
    if(!root)
        return;

    inorder(root->left, arr);
    arr.push_back(root->val);
    inorder(root->right, arr);
}

void preorder(TreeNode* root) {

    if(!root)
        return;

    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

void BSTtoMinHeap(TreeNode* root, vector<int>& arr, int& i) {
    
    if(!root)
        return;

    root->val = arr[i++];

    BSTtoMinHeap(root->left, arr, i);
    BSTtoMinHeap(root->right, arr, i);
}

void convertToMinHeap(TreeNode* root) {

    vector<int> arr;
    inorder(root, arr);

    int i=0;
    BSTtoMinHeap(root, arr, i);
}

int main() {

    TreeNode* root = new TreeNode(7);

    root->left = new TreeNode(3);
    root->right = new TreeNode(11);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(8);
    root->right->right = new TreeNode(12);

    convertToMinHeap(root);
    preorder(root);
    cout << "\n";

    return 0;
}