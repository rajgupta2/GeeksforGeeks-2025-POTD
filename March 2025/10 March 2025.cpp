/*
Given two strings s1 and s2. Return the minimum number of operations required to convert s1 to s2.
The possible operations are permitted:
Insert a character at any position of the string.
Remove any character from the string.
Replace any character from the string with any other character.
*/
class Solution {
    public:
      // Function to compute the edit distance between two strings
      int editDistance(string& s1, string& s2) {
          // code here
          int m = s1.length();
      int n = s2.length();

      // Create a table to store results of subproblems
      vector<vector<int>> dp(m + 1, vector<int>(n + 1));

      // Fill the known entries in dp[][]
      // If one string is empty, then answer
      // is length of the other string
      for (int i = 0; i <= m; i++)
          dp[i][0] = i;
      for (int j = 0; j <= n; j++)
          dp[0][j] = j;

      // Fill the rest of dp[][]
      for (int i = 1; i <= m; i++) {
          for (int j = 1; j <= n; j++) {
              if (s1[i - 1] == s2[j - 1])
                  dp[i][j] = dp[i - 1][j - 1];
              else
                  dp[i][j] = 1 + min({dp[i][j - 1],
                                   dp[i - 1][j],
                                   dp[i - 1][j - 1]});
          }
      }

      return dp[m][n];
      }
  };