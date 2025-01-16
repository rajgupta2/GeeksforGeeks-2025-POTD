/*
Largest subarray of 0's and 1's
Given an array arr of 0s and 1s. Find and return the length of the longest subarray with equal number of 0s and 1s.
*/
class Solution {
  public:
    int maxLen(vector<int> &arr) {
      //If we consider every 0 as -1, then this problem become same as the longest subarray with 0 sum problem.
      int sum=0;
      unordered_map<int,int> mp;
      int res=0;
      for(int i=0;i<arr.size();i++){
          sum+=(arr[i]==0)?-1:1;
          if(sum==0) res=i+1;

          if(mp.find(sum)!=mp.end()){
              res=max(res,i-mp[sum]);
          }else{
              mp[sum]=i;
          }
      }
      return res;
    }
};
