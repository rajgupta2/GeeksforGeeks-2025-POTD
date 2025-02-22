/*
Longest valid Parentheses
Given a string s consisting of opening and closing parenthesis '(' and ')'. Find the length of the longest valid parenthesis substring.
A parenthesis string is valid if:
For every opening parenthesis, there is a closing parenthesis.
The closing parenthesis must be after its opening parenthesis.
*/
class Solution {
    public:
      int maxLength(string& s) {
          // code here
          int maxLen = 0;

      // Left to Right Traversal
      int open = 0, close = 0;
      for (char ch : s) {
          if (ch == '(') {
              open++;
          }
          else if (ch == ')') {
              close++;
          }

          if (open == close) {
              maxLen = max(maxLen, 2 * close);
          }
          else if (close > open) {
              open = close = 0;
          }
      }

      // Right to Left Traversal
      open = close = 0;
      for (int i = s.size() - 1; i >= 0; i--) {
          if (s[i] == '(') {
              open++;
          }
          else if (s[i] == ')') {
              close++;
          }

          if (open == close) {
              maxLen = max(maxLen, 2 * open);
          }
          else if (open > close) {
              open = close = 0;
          }
      }

      return maxLen;
      }
  };