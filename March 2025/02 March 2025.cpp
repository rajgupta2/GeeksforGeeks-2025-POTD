/*
K Sized Subarray Maximum
Given an array arr[] of integers and an integer k, your task is to find the maximum value for each contiguous subarray of size k. The output should be an array of maximum values corresponding to each contiguous subarray.
*/
class Solution {
    public:
      vector<int> maxOfSubarrays(vector<int>& arr, int k) {
          // code here
          vector<int> ans;
          if(arr.size()<k) return ans;
          int maxi=INT_MIN;
          map<int,list<int>> mp;
          for(int i=0;i<k;i++){
              maxi=max(maxi,arr[i]);
              mp[arr[i]].push_back(i);
          }
          ans.push_back(mp.rbegin()->first);
          int left=0;
          int right=k;
          while(right<arr.size()){
              mp[arr[right]].push_back(right);
              right++;

              mp[arr[left]].pop_front();
              if(mp[arr[left]].size()==0) mp.erase(arr[left]);

              left++;
              ans.push_back(mp.rbegin()->first);
          }
          return ans;
      }
  };