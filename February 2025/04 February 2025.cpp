
/*
Diameter of a Binary Tree
*/
class Solution {
  public:
    int Height(Node* root,int &maxi){
        if(root==nullptr) return 0;
        int LH=Height(root->left,maxi);
        int RH=Height(root->right,maxi);

        maxi=max(maxi,LH+RH);
        return 1+max(LH,RH);
    }
    int diameter(Node* node) {
        // Your code here
        int maxi=INT_MIN;
        Height(node,maxi);
        return maxi;
    }
};