// Unique Number II
class Solution
{
public:
    vector<int> singleNum(const vector<int> &arr)
    {
        unordered_map<int, int> freq;

        // Count the frequency of each element
        for (int x : arr)
        {
            freq[x]++;
        }

        vector<int> res;

        // Collect numbers that appear exactly once
        for (const auto &p : freq)
        {
            if (p.second == 1)
            {
                res.push_back(p.first);
            }
        }

        if (res[0] > res[1])
        {
            swap(res[0], res[1]);
        }
        return res;
    }
};