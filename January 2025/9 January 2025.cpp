/*
Given an array arr[] containing only non-negative integers, your task is to find a continuous subarray (a contiguous sequence of elements) whose sum equals a specified value target. You need to return the 1-based indices of the leftmost and rightmost elements of this subarray. You need to find the first subarray whose sum is equal to the target.
Note: If no such array is possible then, return [-1].
*/
class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        int sum=0;
        //map of <sum, index>
        unordered_map<int,int> mp;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(sum==target) return {1,i+1};
            if(mp.find(sum-target)!=mp.end()) return {mp[sum-target]+1,i+1};
            mp[sum]=i+1;
        }
        return {-1};
    }
};