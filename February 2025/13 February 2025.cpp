/*
Pair Sum in BST
Given a Binary Search Tree(BST) and a target. Check whether there's a pair of Nodes in the BST with value summing up to the target.
*/
class Solution {
    public:
      bool preOrder(Node * root, int target , unordered_set<int> &st){
          if(!root) return false;
          if(st.find(target-root->data)!=st.end()) return true;
          st.insert(root->data);
          return preOrder(root->left,target,st) || preOrder(root->right,target,st);
      }
      bool findTarget(Node *root, int target) {
          // your code here.
          unordered_set<int> st;
          return preOrder(root,target,st);
      }
  };