/*
Stock span problem
The stock span problem is a financial problem where we have a series of daily price quotes for a stock and we need to calculate the span of stock price for all days. The span arr[i] of the stocks price on a given day i is defined as the maximum number of consecutive days just before the given day, for which the price of the stock on the given day is less than or equal to its price on the current day.
*/
class Solution
{
public:
    vector<int> calculateSpan(vector<int> &arr)
    {
        // write code here
        int n = arr.size();
        vector<int> span(n);
        stack<int> stk;

        // Process each day's price
        for (int i = 0; i < n; i++)
        {

            // Remove elements from the stack while the current
            // price is greater than or equal to stack's top price
            while (!stk.empty() && arr[stk.top()] <= arr[i])
            {
                stk.pop();
            }

            // If stack is empty, all elements to the left are smaller
            // Else, top of the stack is the last greater element's index
            if (stk.empty())
            {
                span[i] = (i + 1);
            }
            else
            {
                span[i] = (i - stk.top());
            }

            // Push the current index to the stack
            stk.push(i);
        }

        return span;
    }
};