/*
Boolean Parenthesization
You are given a boolean expression s containing
    'T' ---> true
    'F' ---> false
and following operators between symbols
   &   ---> boolean AND
    |   ---> boolean OR
   ^   ---> boolean XOR
Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.

Note: The answer is guaranteed to fit within a 32-bit integer.
*/
class Solution
{
public:
    bool evaluate(int b1, int b2, char op)
    {
        if (op == '&')
        {
            return b1 & b2;
        }
        else if (op == '|')
        {
            return b1 | b2;
        }
        return b1 ^ b2;
    }

    // Function which returns the number of ways
    // s[i:j] evaluates to req.
    int countRecur(int i, int j, int req, string &s, vector<vector<vector<int>>> &memo)
    {

        // Base case:
        if (i == j)
        {
            return (req == (s[i] == 'T')) ? 1 : 0;
        }

        // If value is memoized
        if (memo[i][j][req] != -1)
            return memo[i][j][req];

        int ans = 0;
        for (int k = i + 1; k < j; k += 1)
        {

            // Count Ways in which left substring
            // evaluates to true and false.
            int leftTrue = countRecur(i, k - 1, 1, s, memo);
            int leftFalse = countRecur(i, k - 1, 0, s, memo);

            // Count Ways in which right substring
            // evaluates to true and false.
            int rightTrue = countRecur(k + 1, j, 1, s, memo);
            int rightFalse = countRecur(k + 1, j, 0, s, memo);

            // Check if the combinations results
            // to req.
            if (evaluate(1, 1, s[k]) == req)
            {
                ans += leftTrue * rightTrue;
            }
            if (evaluate(1, 0, s[k]) == req)
            {
                ans += leftTrue * rightFalse;
            }
            if (evaluate(0, 1, s[k]) == req)
            {
                ans += leftFalse * rightTrue;
            }
            if (evaluate(0, 0, s[k]) == req)
            {
                ans += leftFalse * rightFalse;
            }
        }

        return memo[i][j][req] = ans;
    }
    int countWays(string s)
    {
        int n = s.length();
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(n, vector<int>(2, -1)));
        return countRecur(0, n - 1, 1, s, memo);
    }
};