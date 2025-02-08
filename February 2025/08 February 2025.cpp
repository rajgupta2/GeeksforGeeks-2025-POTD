/*
Tree Boundary Traversal
Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order:
*/
class Solution {
  public:
    bool isLeave(Node *curr){
        if(curr->left==nullptr && curr->right==nullptr)
        return true;
        return false;
    }
    void addLeftBoundary(Node* root,vector<int> &ans){
        Node * curr=root->left;
        while(curr!=nullptr){
            if(!isLeave(curr))
            ans.push_back(curr->data);
            if(curr->left) curr=curr->left;
            else curr=curr->right;
        }
    }
    void addLeafNodes(Node* curr,vector<int> &ans){
        if(curr==nullptr) return;
        addLeafNodes(curr->left,ans);
        if(isLeave(curr))
            ans.push_back(curr->data);
        addLeafNodes(curr->right,ans);
    }
    void addRightBoundary(Node* root,vector<int> &ans){
        Node * curr=root->right;
        vector<int> res;
        while(curr!=nullptr){
            if(!isLeave(curr))
            res.push_back(curr->data);
            if(curr->right) curr=curr->right;
            else curr=curr->left;
        }
        for(int i=1;i<=res.size();i++){
            ans.push_back(res[res.size()-i]);
        }
    }
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> ans;
        if(!root) return ans;
        if(!isLeave(root)) ans.push_back(root->data);
        addLeftBoundary(root,ans);
        addLeafNodes(root,ans);
        addRightBoundary(root,ans);
        return ans;
    }
};