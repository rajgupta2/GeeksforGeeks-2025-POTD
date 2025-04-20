//Find Only Repetitive Element from 1 to n-1
class Solution {
    public:
      int findDuplicate(vector<int>& arr) {
          // code here
          int n=arr.size();
          int ans=0;
          for(int i=0;i<n;i++){
              ans=ans^arr[i]^i;
          }
          return ans;
      }
  };