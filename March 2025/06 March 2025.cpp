/*
Longest Common Subsequence
Given two strings s1 and s2, return the length of their longest common subsequence (LCS). If there is no common subsequence, return 0.
A subsequence is a sequence that can be derived from the given string by deleting some or no elements without changing the order of the remaining elements. For example, "ABE" is a subsequence of "ABCDE".
*/
class Solution
{
public:
    int lcs(string &s1, string &s2)
    {
        // code here
        int m = s1.size();
        int n = s2.size();

        // Initializing a matrix of size (m+1)*(n+1)
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Building dp[m+1][n+1] in bottom-up fashion
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        // dp[m][n] contains length of LCS for s1[0..m-1]
        // and s2[0..n-1]
        return dp[m][n];
    }
};
