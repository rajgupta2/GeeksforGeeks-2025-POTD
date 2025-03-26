/*
Word Break
You are given a string s and a list dictionary[] of words. Your task is to determine whether the string s can be formed by concatenating one or more words from the dictionary[].

Note: From dictionary[], any word can be taken any number of times and in any order.
*/
class Solution {
    public:
      bool wordBreak(string &s, vector<string> &dictionary) {
          // code here
          int n = s.size();
      vector<bool> dp(n + 1, 0);
      dp[0] = 1;

      // Traverse through the given string
      for (int i = 1; i <= n; i++)
      {

          // Traverse through the dictionary words
          for (string &w : dictionary)
          {

              // Check if current word is present
              // the prefix before the word is also
              // breakable
              int start = i - w.size();
              if (start >= 0 && dp[start] && s.substr(start, w.size()) == w)
              {
                  dp[i] = 1;
                  break;
              }
          }
      }
      return dp[n];
      }
  };