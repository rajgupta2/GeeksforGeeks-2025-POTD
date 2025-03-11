/*
Ways to Reach the n'th Stair
There are n stairs, a person standing at the bottom wants to reach the top. The person can climb either 1 stair or 2 stairs at a time. Your task is to count the number of ways, the person can reach the top (order does matter).
*/
class Solution {
    public:
      int countWays(int n) {
          // your code here
          vector<int> dp(n+1,-1);
          dp[0]=1;
          for(int i=1;i<=n;i++)
              dp[i]=dp[i-1]+ ((i-2>=0)? dp[i-2]:0);
          return dp[n];
      }
};