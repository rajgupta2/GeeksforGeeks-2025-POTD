//Missing in Array
class Solution {
    public:
      int missingNum(vector<int>& arr) {
          // code here
            int n=arr.size();
            int ans=0;
            for(int i=0;i<n;i++){
                ans=ans^arr[i]^(i+1);
            }
            return ans^(n+1);
      }
  };