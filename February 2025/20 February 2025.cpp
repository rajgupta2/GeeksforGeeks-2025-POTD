/*
Find median in a stream
Given a data stream arr[] where integers are read sequentially, the task is to determine the median of the elements encountered so far after each new integer is read.

There are two cases for median on the basis of data set size.

1. If the data set has an odd number then the middle one will be consider as median.
2. If the data set has an even number then there is no distinct middle value and the median will be the arithmetic mean of the two middle values.
*/
class Solution
{
public:
    string findDifferentBinaryString(vector<string> &nums)
    {
        unordered_set<int> integers;
        for (string num : nums)
        {
            integers.insert(stoi(num, 0, 2));
        }

        int ans = stoi(nums[0], 0, 2);
        int n = nums.size();

        while (integers.find(ans) != integers.end())
        {
            ans = rand() % (int)pow(2, n);
        }

        return bitset<16>(ans).to_string().substr(16 - n);
    }
};