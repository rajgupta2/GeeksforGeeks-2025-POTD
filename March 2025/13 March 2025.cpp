/*
0 - 1 Knapsack Problem
Given n items, each with a specific weight and value, and a knapsack with a capacity of W, the task is to put the items in the knapsack such that the sum of weights of the items <= W and the sum of values associated with them is maximized.
Note: You can either place an item entirely in the bag or leave it out entirely. Also, each item is available in single quantity.
*/
class Solution {
    public:
      int knapsack(int W, vector<int> &val, vector<int> &wt) {
          // code here
          int n = wt.size();
      vector<vector<int>> dp(n + 1, vector<int>(W + 1));

      // Build table dp[][] in bottom-up manner
      for (int i = 0; i <= n; i++) {
          for (int j = 0; j <= W; j++) {

              // If there is no item or the knapsack's capacity is 0
              if (i == 0 || j == 0)
                  dp[i][j] = 0;
              else {
                  int pick = 0;

                  // Pick ith item if it does not exceed the capacity of knapsack
                  if(wt[i - 1] <= j)
                      pick = val[i - 1] + dp[i - 1][j - wt[i - 1]];

                  // Don't pick the ith item
                  int notPick = dp[i - 1][j];

                  dp[i][j] = max(pick, notPick);
              }
          }
      }
      return dp[n][W];
      }
  };