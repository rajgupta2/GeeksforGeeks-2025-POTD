/*
Jump Game – Minimum Jumps to Reach End
Given an array arr[] of non-negative numbers. Each number tells you the maximum number of steps you can jump forward from that position.
For example:
If arr[i] = 3, you can jump to index i + 1, i + 2, or i + 3 from position i.
If arr[i] = 0, you cannot jump forward from that position.
Your task is to find the minimum number of jumps needed to move from the first position in the array to the last position.
*/
class Solution {
    public:
      int minJumps(vector<int>& arr) {
          // code here
              int n = arr.size();

      // array to memoize values
      vector<int> dp(n, INT_MAX);
      dp[n - 1] = 0;

      for (int i = n - 2; i >= 0; i--) {
          for (int j = i + 1; j <= i + arr[i] && j < n; j++) {
              if (dp[j] != INT_MAX) {
                  dp[i] = min(dp[i], 1 + dp[j]);
              }
          }
      }

      // If end cannot be reached.
      if (dp[0] == INT_MAX)
          return -1;

      return dp[0];
      }
  };