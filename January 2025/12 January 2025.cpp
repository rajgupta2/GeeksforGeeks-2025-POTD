/*
Trapping Rain Water
Given an array arr[] with non-negative integers representing the height of blocks. If the width of each block is 1, compute how much water can be trapped between the blocks during the rainy season.
*/
class Solution
{
public:
    int maxWater(vector<int> &arr)
    {
        int n = arr.size();

        vector<int> left(n);

        vector<int> right(n);

        int res = 0;

        left[0] = arr[0];
        for (int i = 1; i < n; i++)
            left[i] = max(left[i - 1], arr[i]);

        right[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
            right[i] = max(right[i + 1], arr[i]);

        for (int i = 1; i < n - 1; i++)
        {
            int minOf2 = min(left[i - 1], right[i + 1]);
            if (minOf2 > arr[i])
            {
                res += minOf2 - arr[i];
            }
        }

        return res;
    }
};