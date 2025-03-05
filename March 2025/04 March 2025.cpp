/*
Longest Increasing Subsequence
Given an array arr[] of non-negative integers, the task is to find the length of the Longest Strictly Increasing Subsequence (LIS).

A subsequence is strictly increasing if each element in the subsequence is strictly less than the next element.*/
class Solution {
    public:
      int lis(vector<int>& arr) {
          // code here
          int n = arr.size();
      vector<int> lis(n, 1);

      // Compute optimized LIS values in
      // bottom-up manner
      for (int i = 1; i < n; i++) {
          for (int prev = 0; prev < i; prev++) {
              if (arr[i] > arr[prev] && lis[i] < lis[prev] + 1) {
                  lis[i] = lis[prev] + 1;
              }
          }
      }

      // Return maximum value in lis
      return *max_element(lis.begin(), lis.end());
      }
  };