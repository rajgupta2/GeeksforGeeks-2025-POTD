/*
Stickler Thief II
You are given an array arr[] which represents houses arranged in a circle, where each house has a certain value. A thief aims to maximize the total stolen value without robbing two adjacent houses.
Determine the maximum amount the thief can steal.
*/
class Solution
{
public:
    int maxValTab(int x, int y, vector<int> &arr)
    {
        int n = arr.size();

        vector<int> dp(n);

        // For first house, taking is only option
        dp[x] = arr[x];

        // For second house, we can either take
        // from 1st or 2nd.
        dp[x + 1] = max(arr[x], arr[x + 1]);

        for (int j = x + 2; j <= y; j++)
        {
            int take = arr[j] + dp[j - 2];
            int noTake = dp[j - 1];

            dp[j] = max(take, noTake);
        }

        return dp[y];
    }

    // Function to calculate the maximum stolen value
    int maxValue(vector<int> &arr)
    {
        int n = arr.size();

        // Base cases
        if (n == 0)
            return 0;
        if (n == 1)
            return arr[0];

        int ans = 0;

        // Skipping last house
        ans = max(ans, maxValTab(0, n - 2, arr));

        // Skipping first house
        ans = max(ans, maxValTab(1, n - 1, arr));

        return ans;
    }
};