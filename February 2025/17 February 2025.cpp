/*
k largest elements
Given an array arr[] of positive integers and an integer k, Your task is to return k largest elements in decreasing order.
*/
class Solution {
    public:
      vector<int> kLargest(vector<int>& arr, int k) {
          // Your code here
          vector<int> ans;
          int n=arr.size();
          if(k==0 || arr.size()==0) return ans;
          priority_queue<int> pq;
          for(int i=0;i<n;i++){
              pq.push(arr[i]);
          }
          for(int i=0;i<k;i++){
              ans.push_back(pq.top());
              pq.pop();
          }
          return ans;
      }
  };