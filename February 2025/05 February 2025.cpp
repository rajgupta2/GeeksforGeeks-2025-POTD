/*
Mirror Tree
Given a binary tree, convert the binary tree to its Mirror tree.
Mirror of a Binary Tree T is another Binary Tree M(T) with left and right children of all non-leaf nodes interchanged.
*/
class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
         //swap life and right node and call for their respective one
        if(node==nullptr) return;
        if(!node->left && !node->right) return;

        Node *temp=node->left;
        node->left=node->right;
        node->right=temp;
        mirror(node->left);
        mirror(node->right);

    }
};