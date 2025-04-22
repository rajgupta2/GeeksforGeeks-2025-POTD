//find unique one
class Solution {
    public:
      int findUnique(vector<int> &arr) {
          // code here
          int ans=0;
          for(auto x:arr){
              ans^=x;
          }
          return ans;
      }
  };