/*
Maximum path sum from any node
Given a binary tree, the task is to find the maximum path sum. The path may start and end at any node in the tree
*/
class Solution {
    public:
      int findMaxSum(Node *root, int &res){
         if(root==nullptr) return 0;
         int L=max(0,findMaxSum(root->left,res));
         int R=max(0,findMaxSum(root->right,res));
         res=max(res,L + R + root->data);
         return root->data + max(L,R);
      }
      int findMaxSum(Node *root) {
          if(!root) return 0;
         int res=root->data;
         findMaxSum(root,res);
         return res;
      }
  };