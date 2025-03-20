/*
Stock Buy and Sell – Max 2 Transactions Allowed
In daily share trading, a trader buys shares and sells them on the same day. If the trader is allowed to make at most 2 transactions in a day, find out the maximum profit that a share trader could have made.
You are given an array prices[] representing stock prices throughout the day. Note that the second transaction can only start after the first one is complete (buy->sell->buy->sell).
*/
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        // code here
        int n = prices.size();

        // Create profit vector and initialize it as 0
        vector<int> profit(n, 0);

        int maxPrice = prices[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {

            // maxPrice has maximum of price[i..n-1]
            maxPrice = max(maxPrice, prices[i]);

            // Update profit[i]
            profit[i] = max(profit[i + 1], maxPrice - prices[i]);
        }

        // Variable to store the maximum
        // profit using two transactions
        int res = 0;
        int minPrice = prices[0];
        for (int i = 1; i < n; i++)
        {

            // minPrice is the minimum price in price[0..i]
            minPrice = min(minPrice, prices[i]);

            // Calculate the maximum profit by adding
            // the profit of the first transaction
            res = max(res, profit[i] + (prices[i] - minPrice));
        }

        return res;
    }
};