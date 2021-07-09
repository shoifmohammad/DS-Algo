#include <bits/stdc++.h>
using namespace std;

class TreeNode {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() {}
        TreeNode(int val){
            data = val;
            left = NULL;
            right = NULL;
        }
};

void inorder(TreeNode *root) {

    if(!root)
        return;
    
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(TreeNode *root) {

    if(!root)
        return;
    
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(TreeNode *root) {

    if(!root)
        return;
    
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

TreeNode *arrayToTree(int arr[], int n) {

    if(n == 0 || arr[0] == -1)
        return NULL;

    TreeNode *root = new TreeNode(arr[0]);

    queue<TreeNode*> q;
    q.push(root);

    int i=1;
    while(!q.empty() && i<n) {

        TreeNode *temp = q.front();
        q.pop();

        if(arr[i] != -1) {
            temp->left = new TreeNode(arr[i]);
            q.push(temp->left);
        }

        i++;
        if(i>=n)
            break;
        
        if(arr[i] != -1) {
            temp->right = new TreeNode(arr[i]);
            q.push(temp->right);
        }
        i++;
    }

    return root;
}