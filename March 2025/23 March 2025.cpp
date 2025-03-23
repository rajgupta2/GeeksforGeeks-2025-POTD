/*
Total Decoding Messages
A message containing letters A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26

You are given a string digits. You have to determine the total number of ways that message can be decoded.
*/
class Solution
{
public:
    int countWays(string &digits)
    {
        int n = digits.length();

        // Create a dp array initialized to 0, with size n + 1.
        vector<int> dp(n + 1, 0);

        // Base case: An empty string has one valid decoding.
        dp[n] = 1;

        // Iterate from the end of the string to the beginning.
        for (int i = n - 1; i >= 0; i--)
        {

            // Single-digit decoding: check if current
            // digit is not '0'.
            if (digits[i] != '0')
            {
                dp[i] = dp[i + 1];
            }

            // Two-digit decoding: check if next two digits are valid.
            if ((i + 1 < n) &&
                ((digits[i] == '1' && digits[i + 1] <= '9') || (digits[i] == '2' && digits[i + 1] <= '6')))
            {
                dp[i] += dp[i + 2];
            }
        }

        return dp[0];
    }
};