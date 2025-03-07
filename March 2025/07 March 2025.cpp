/*
Longest Palindromic Subsequence
Given a string s, return the length of the longest palindromic subsequence.
A subsequence is a sequence that can be derived from the given sequence by deleting some or no elements without changing the order of the remaining elements.
A palindromic sequence is a sequence that reads the same forward and backward.
*/
class Solution {
    public:
      int longestPalinSubseq(string &s) {
          // code here
          int n = s.length();

      // Create a DP table
      vector<vector<int>> dp(n, vector<int>(n));

      // Build the DP table for all the substrings
      for (int i = n - 1; i >= 0; i--) {
          for (int j = i; j < n; j++) {

              // If there is only one character
              if(i == j){
                  dp[i][j] = 1;
                  continue;
              }

              // If characters at position i and j are the same
              if (s[i] == s[j]) {
                  if(i + 1 == j) dp[i][j] = 2;
                  else dp[i][j] = dp[i + 1][j - 1] + 2;
              }
              else {

                  // Otherwise, take the maximum length
                  // from either excluding i or j
                  dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
              }
          }
      }

      // The final answer is stored in dp[0][n-1]
      return dp[0][n - 1];
      }
  };