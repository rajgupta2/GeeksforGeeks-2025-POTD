/*
Inorder Traversal
Given a Binary Tree, your task is to return its In-Order Traversal.
*/
class Solution {
  public:
    // Function to return a list containing the inorder traversal of the tree.
    void inOrder(Node* root,vector<int> &ans){
        if(root==nullptr) return;
        inOrder(root->left,ans);
        ans.push_back(root->data);
        inOrder(root->right,ans);
    }
    vector<int> inOrder(Node* root) {
        vector<int> ans;
        inOrder(root,ans);
        return ans;
    }
};