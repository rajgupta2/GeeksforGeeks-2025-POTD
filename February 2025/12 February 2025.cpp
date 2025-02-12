/*
k-th Smallest in BST
Given a BST and an integer k, the task is to find the kth smallest element in the BST. If there is no kth smallest element present then return -1.
*/
class Solution {
    public:
      // Return the Kth smallest element in the given BST
      void inOrder(Node *root,int k,int &iM,int &found){
          if(!root) return;
          inOrder(root->left,k,iM,found);
          iM++;
          if(iM==k){
              found=root->data;
          }
          if(found!=-1) return;
          inOrder(root->right,k,iM,found);
      }
      int kthSmallest(Node *root, int k) {
          //Traverse inorder traversal and find out the kth smallest element
          int found=-1;
          int iM=0;
          inOrder(root,k,iM,found);
          return found;
      }
  };