/*
Partition Equal Subset Sum
Given an array arr[], determine if it can be partitioned into two subsets such that the sum of elements in both parts is the same.
Note: Each element must be in exactly one subset.
*/
class Solution {
    public:
      bool isFind(int n,vector<int> &arr, int sum,vector<vector<int>> &dp){

          if(sum<0) return false;
          if(sum==0) return true;
          if(n<0) return false;
          if(dp[n][sum]!=-1) return dp[n][sum];

          return isFind(n-1,arr,sum-arr[n],dp)||isFind(n-1,arr,sum,dp);
      }
      bool equalPartition(vector<int>& arr) {
          // code here
          int sum=0;
          for(auto x:arr){
              sum+=x;
          }
          if(sum%2!=0) return false;
          vector<vector<int>> dp(arr.size(),vector<int>(sum/2+1, -1));
          return isFind(arr.size()-1,arr,sum/2,dp);
      }
  };