/*
Longest Subarray with Sum K
Given an array arr[] containing integers and an integer k, your task is to find the length of the longest subarray where the sum of its elements is equal to the given value k. If there is no subarray with sum equal to k, return 0.
*/
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        int maxi=0,sum=0;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum==k) maxi=max(maxi,i+1);
            if(mp.find(sum-k)!=mp.end()){
                int num=i-mp[sum-k];
                maxi=max(maxi,num);
            }
            if(mp.find(sum)==mp.end()) mp[sum]=i;
        }
        return maxi;
    }
};