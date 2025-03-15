/*
Coin Change (Minimum Coins)
You are given an array coins[], where each element represents a coin of a different denomination, and a target value sum. You have an unlimited supply of each coin type {coins1, coins2, ..., coinsm}.
Your task is to determine the minimum number of coins needed to obtain the target sum. If it is not possible to form the sum using the given coins, return -1.
*/
class Solution {
    public:
    int minCoins(vector<int> &coins, int sum) {
        // code here
        vector<vector<int>> dp(coins.size(), vector<int>(sum+1, 0));

    for (int i=coins.size()-1; i>=0; i--) {
        for (int j=1; j<=sum; j++) {
            dp[i][j] = INT_MAX;
            int take = INT_MAX, noTake = INT_MAX;

            // If we take coins[i] coin
            if (j-coins[i]>=0) {
                take = dp[i][j-coins[i]];
                if (take != INT_MAX) take++;
            }

            if (i+1<coins.size())
            // not take the coin
                noTake = dp[i+1][j];

            dp[i][j] = min(take, noTake);
        }
    }

    if (dp[0][sum]!=INT_MAX) return dp[0][sum];
    return -1;
    }
};