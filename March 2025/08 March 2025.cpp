/*
Longest Palindrome in a String
Given a string s, your task is to find the longest palindromic substring within s.

A substring is a contiguous sequence of characters within a string, defined as s[i...j] where 0 ≤ i ≤ j < len(s).

A palindrome is a string that reads the same forward and backward. More formally, s is a palindrome if reverse(s) == s.

Note: If there are multiple palindromic substrings with the same length, return the first occurrence of the longest palindromic substring from left to right.
*/
class Solution
{
public:
    string longestPalindrome(string &s)
    {
        // code here
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        int start = 0, maxLen = 1;

        // All substrings of length 1 are palindromes
        for (int i = 0; i < n; ++i)
            dp[i][i] = true;

        // Check for sub-string of length 2
        for (int i = 0; i < n - 1; ++i)
        {
            if (s[i] == s[i + 1])
            {
                dp[i][i + 1] = true;
                if (maxLen < 2)
                {
                    start = i;
                    maxLen = 2;
                }
            }
        }

        // Check for lengths greater than 2
        for (int k = 3; k <= n; ++k)
        {
            for (int i = 0; i < n - k + 1; ++i)
            {
                int j = i + k - 1;

                if (dp[i + 1][j - 1] && s[i] == s[j])
                {
                    dp[i][j] = true;

                    if (k > maxLen)
                    {
                        start = i;
                        maxLen = k;
                    }
                }
            }
        }

        return s.substr(start, maxLen);
    }
};