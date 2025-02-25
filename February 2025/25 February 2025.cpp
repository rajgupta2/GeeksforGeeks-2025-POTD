/*
Histogram Max Rectangular Area
You are given a histogram represented by an array arr, where each element of the array denotes the height of the bars in the histogram. All bars have the same width of 1 unit.
Your task is to find the largest rectangular area possible in the given histogram, where the rectangle can be formed using a number of contiguous bars.
*/
class Solution
{
public:
    int getMaxArea(vector<int> &arr)
    {
        // Your code here
        int n = arr.size();
        stack<int> s;
        int res = 0;
        int tp, curr;
        for (int i = 0; i < n; i++)
        {

            while (!s.empty() && arr[s.top()] >= arr[i])
            {

                // The popped item is to be considered as the
                // smallest element of the Histogram
                tp = s.top();
                s.pop();

                // For the popped item previous smaller element is
                // just below it in the stack (or current stack top)
                // and next smaller element is i
                int width = s.empty() ? i : i - s.top() - 1;

                res = max(res, arr[tp] * width);
            }
            s.push(i);
        }

        // For the remaining items in the stack, next smaller does
        // not exist. Previous smaller is the item just below in
        // stack.
        while (!s.empty())
        {
            tp = s.top();
            s.pop();
            curr = arr[tp] * (s.empty() ? n : n - s.top() - 1);
            res = max(res, curr);
        }

        return res;
    }
};