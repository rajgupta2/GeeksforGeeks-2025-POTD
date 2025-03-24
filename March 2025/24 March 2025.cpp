/*
Matrix Chain Multiplication
Given an array arr[] which represents the dimensions of a sequence of matrices where the ith matrix has the dimensions (arr[i-1] x arr[i]) for i>=1, find the most efficient way to multiply these matrices together. The efficient way is the one that involves the least number of multiplications.
*/
class Solution {
    public:
      int matrixMultiplication(vector<int> &arr) {
          // code here
              int n = arr.size();

      // Create a 2D DP array to store the minimum
      // multiplication costs
      vector<vector<int>> dp(n, vector<int>(n, 0));

      // Fill the DP array.
      // Here, len is the chain length
      for (int len = 2; len < n; len++)
      {
          for (int i = 0; i < n - len; i++)
          {
              int j = i + len;
              dp[i][j] = INT_MAX;

              for (int k = i + 1; k < j; k++)
              {
                  int cost = dp[i][k] + dp[k][j] + arr[i] * arr[k] * arr[j];
                  dp[i][j] = min(dp[i][j], cost);
              }
          }
      }

      // The minimum cost is stored in dp[0][n-1]
      return dp[0][n - 1];
      }
  };