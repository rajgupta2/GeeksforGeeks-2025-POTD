/*
Height of Binary Tree
Given a binary tree, find its height.
The height of a tree is defined as the number of edges on the longest path from the root to a leaf node. A leaf node is a node that does not have any children.
Root is at height 0;
*/
class Solution {
  public:
    // Function to find the height of a binary tree.
    int height(Node* node) {
        // code here
        if(node==nullptr) return 0;
        if(!node->left && !node->right) return 0;
        return 1+max(height(node->left),height(node->right));
    }
};