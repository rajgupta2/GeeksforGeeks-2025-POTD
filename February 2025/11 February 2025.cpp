/*
Check for BST
Given the root of a binary tree. Check whether it is a BST or not.
Note: We are considering that BSTs can not contain duplicate Nodes.
A BST is defined as follows:
The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
*/
class Solution {
    public:
      // Function to check whether a Binary Tree is BST or not.
      bool isBST(Node* root,int mini, int maxi){

          if(!root) return true;

          if(root->data<mini || root->data>maxi) return false;
          return isBST(root->left,mini,min(root->data,maxi)) &&
          isBST(root->right,max(mini,root->data),maxi);
      }
      bool isBST(Node* root) {
          // Your code here
          return isBST(root,INT_MIN,INT_MAX);
      }
  };