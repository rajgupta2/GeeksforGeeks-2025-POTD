/*
Min Cost Climbing Stairs
Given an array of integers cost[] where cost[i] is the cost of the ith step on a staircase. Once the cost is paid, you can either climb one or two steps. Return the minimum cost to reach the top of the floor.
Assume 0-based Indexing. You can either start from the step with index 0, or the step with index 1.
*/
class Solution {
    public:

      int minCostClimbingStairs(vector<int>& cost) {
          // Write your code here
              int n = cost.size();

      if (n==1) return cost[0];

      vector<int> dp(n);
      dp[0] = cost[0];
      dp[1] = cost[1];

      for (int i=2; i<n; i++) {
          dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
      }

      // Return minimum of cost to
      // climb (n-1)th stair and
      // cost to reach (n-2)th stair
      return min(dp[n-1], dp[n-2]);

      }
  };