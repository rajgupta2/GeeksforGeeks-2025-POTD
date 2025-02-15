/*
Lowest Common Ancestor in a BST
Given a Binary Search Tree (with all values unique) and two nodes n1 and n2 (n1 != n2). You may assume that both nodes exist in the tree. Find the Lowest Common Ancestor (LCA) of the given two nodes in the BST.
LCA between two nodes n1 and n2 is defined as the lowest node that has both n1 and n2 as descendants (where we allow a node to be a descendant of itself).
*/
class Solution {
    public:
      void addAllParents(Node* root,Node* p,unordered_map<Node*,Node*> &parent){
          if(!root) return;
          parent[root]=p;
          addAllParents(root->left,root,parent);
          addAllParents(root->right,root,parent);
      }
      Node* LCA(Node* root, Node* n1, Node* n2) {
          // code here
          while (root) {
              if (n1->data < root->data && n2->data < root->data) {
                  root = root->left;
              } else if (n1->data > root->data && n2->data > root->data) {
                  root = root->right;
              } else {
                  return root;
              }
          }
          return nullptr;
      }
  };